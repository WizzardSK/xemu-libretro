/*
 * vCPU sampling profiler for the Performance Overlay (NNshi).
 *
 * While the overlay is on, a thread stops the vCPU thread about 1000 times
 * a second for a moment and reads its host instruction pointer. A sample
 * in translated code is counted by the guest block it belongs to (its
 * physical address, as i386 blocks are PC-relative); any other sample by
 * the host module and the offset in it. When the overlay goes off, the
 * shares go to RetroArch's log and every bucket to system/xemu/
 * xemu_profile.txt, from which the core's offsets resolve to functions with
 * the unstripped build (llvm-symbolizer). The sampling itself slows the
 * vCPU a little: compare runs with the overlay on in both.
 *
 * Two more things go to the file. A sample in Windows (a wait or a system
 * call) is also counted by where in the core it came from: the first three
 * return addresses into the core's code on the vCPU stack, copied while the
 * thread is stopped (a heuristic: a stale value on the stack can win), so a
 * mutex wait shows who took the lock. And the guest code of the hottest
 * blocks, so they can be disassembled; a block's key is its offset in the
 * guest RAM blocks (ram_addr_t), read through qemu_map_ram_ptr.
 *
 * The GPU thread (nv2a.pfifo: the pushbuffer and the renderer, PGRAPH) is
 * sampled the same way in the same tick, counted apart: its share of the
 * time in the core, Windows and the GPU driver, with the same call chains
 * for its waits. It runs no translated code. It goes to the file as a
 * second section after the vCPU's, from "# xemu pfifo profile" on.
 *
 * Windows only: SuspendThread/GetThreadContext. Elsewhere the calls do
 * nothing and the log says so.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "ui/libretro-prof.h"

#if defined(_WIN32)
#include <windows.h>
#include "tcg/tcg.h"
#include "exec/translation-block.h"
#include "exec/cpu-common.h"
#include "system/memory.h"
#include "qemu/rcu.h"

/* One sampled thread and what was counted for it. */
typedef struct ProfTarget {
    const char *name;        /* "vCPU", "pfifo": the log and the file */
    HANDLE h;                /* registered by the thread itself */
    NT_TIB *tib;             /* its TIB, for the stack it is on */
    GHashTable *guest;       /* guest block phys addr -> count (vCPU) */
    GHashTable *host;        /* (module index << 40 | offset) -> count */
    GHashTable *via;         /* "off>off>off" core callers -> count */
    uint64_t samples, jit, jit_unknown, failed;
} ProfTarget;

static ProfTarget prof_vcpu = { .name = "vCPU" };
static ProfTarget prof_pfifo = { .name = "pfifo" };
static HANDLE prof_thread;
static volatile LONG prof_stop;
static GPtrArray *prof_modules;    /* module names, index = slot */
static GArray *prof_bases;         /* module bases, same index */
static GHashTable *prof_tbsize;    /* guest block phys addr -> guest size */
static uintptr_t prof_core, prof_text_lo, prof_text_hi; /* the core's .text */
static uint64_t prof_stack[512];
static int64_t prof_start_us, prof_end_us;

static void prof_register(ProfTarget *t)
{
    HANDLE h;

    if (DuplicateHandle(GetCurrentProcess(), GetCurrentThread(),
                        GetCurrentProcess(), &h,
                        THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT |
                        THREAD_QUERY_INFORMATION, FALSE, 0)) {
        t->tib = (NT_TIB *)NtCurrentTeb();
        t->h = h;
    }
}

void xemu_lr_prof_vcpu(void)
{
    prof_register(&prof_vcpu);
}

void xemu_lr_prof_pfifo(void)
{
    prof_register(&prof_pfifo);
}

/* The core's code section, for telling return addresses from the rest. */
static void prof_core_text(void)
{
    HMODULE m = NULL;
    const IMAGE_DOS_HEADER *dos;
    const IMAGE_NT_HEADERS *nt;
    const IMAGE_SECTION_HEADER *sec;

    if (prof_core ||
        !GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            (LPCWSTR)(void *)prof_core_text, &m) || !m) {
        return;
    }
    prof_core = (uintptr_t)m;
    dos = (const IMAGE_DOS_HEADER *)m;
    nt = (const IMAGE_NT_HEADERS *)((const char *)m + dos->e_lfanew);
    sec = IMAGE_FIRST_SECTION(nt);
    for (unsigned i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (sec[i].Characteristics & IMAGE_SCN_MEM_EXECUTE) {
            prof_text_lo = prof_core + sec[i].VirtualAddress;
            prof_text_hi = prof_text_lo + sec[i].Misc.VirtualSize;
            return;
        }
    }
}

static unsigned prof_module(uintptr_t pc, uintptr_t *base)
{
    HMODULE m = NULL;
    wchar_t wname[MAX_PATH];
    char name[MAX_PATH];
    const char *b;

    if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            (LPCWSTR)pc, &m) || !m) {
        *base = 0;
        return 0; /* slot 0: no module (anonymous memory) */
    }
    *base = (uintptr_t)m;
    for (unsigned i = 1; i < prof_bases->len; i++) {
        if (g_array_index(prof_bases, uintptr_t, i) == *base) {
            return i;
        }
    }
    if (!GetModuleFileNameW(m, wname, MAX_PATH) ||
        !WideCharToMultiByte(CP_UTF8, 0, wname, -1, name, sizeof(name),
                             NULL, NULL)) {
        snprintf(name, sizeof(name), "module@%p", (void *)m);
    }
    b = strrchr(name, '\\');
    g_ptr_array_add(prof_modules, g_strdup(b ? b + 1 : name));
    g_array_append_val(prof_bases, *base);
    return prof_bases->len - 1;
}

static void prof_count(GHashTable *t, uint64_t key)
{
    gpointer k = GSIZE_TO_POINTER((gsize)key);
    g_hash_table_insert(t, k, GSIZE_TO_POINTER(
        GPOINTER_TO_SIZE(g_hash_table_lookup(t, k)) + 1));
}

#ifndef CREATE_WAITABLE_TIMER_HIGH_RESOLUTION
#define CREATE_WAITABLE_TIMER_HIGH_RESOLUTION 0x00000002
#endif

static void prof_sample(ProfTarget *t)
{
    CONTEXT ctx = { .ContextFlags = CONTEXT_CONTROL };
    uintptr_t pc = 0;
    size_t words = 0;

    if (!t->h) {
        return;
    }
    if (SuspendThread(t->h) != (DWORD)-1) {
        /* the context is only certain once the thread really stopped */
        if (GetThreadContext(t->h, &ctx)) {
            pc = (uintptr_t)ctx.Rip;
            /* outside the core and the translated code: keep the top of
             * the stack, to find the core's call that led here */
            /* The stack it is on now: a coroutine runs on a fiber of
             * its own (QEMU's block layer, from the vCPU too), whose
             * bounds the thread's TIB holds while it runs. The bounds of
             * the thread's own stack, read once, let a sample in a
             * coroutine near its fiber stack's top copy past its end
             * (RalliSport 2 crashed there, NNshi). The copy does not
             * fault even so. */
            const uintptr_t top = (uintptr_t)t->tib->StackBase;
            const uintptr_t low = (uintptr_t)t->tib->StackLimit;
            SIZE_T got = 0;
            if ((pc < prof_core || pc >= prof_text_hi) &&
                !in_code_gen_buffer((void *)pc) && prof_text_lo &&
                ctx.Rsp >= low && ctx.Rsp < top) {
                words = MIN(ARRAY_SIZE(prof_stack), (top - ctx.Rsp) / 8);
                if (!ReadProcessMemory(GetCurrentProcess(),
                                       (LPCVOID)(uintptr_t)ctx.Rsp,
                                       prof_stack, words * 8, &got)) {
                    words = 0;
                }
            }
        }
        ResumeThread(t->h);
    }
    if (!pc) {
        t->failed++;
    } else if (in_code_gen_buffer((void *)pc)) {
        /* looked up after the resume: the vCPU may hold the TB tree */
        TranslationBlock *tb = tcg_tb_lookup(pc);
        t->jit++;
        if (tb) {
            gpointer k = GSIZE_TO_POINTER((gsize)tb_page_addr0(tb));
            prof_count(t->guest, (gsize)k);
            g_hash_table_insert(prof_tbsize, k,
                                GSIZE_TO_POINTER((gsize)tb->size));
        } else {
            t->jit_unknown++;
        }
    } else {
        uintptr_t base;
        unsigned m = prof_module(pc, &base);
        prof_count(t->host, (uint64_t)m << 40 | (pc - base));
        GString *chain = NULL;
        int hits = 0;
        for (size_t i = 0; i < words && hits < 3; i++) {
            if (prof_stack[i] >= prof_text_lo &&
                prof_stack[i] < prof_text_hi) {
                if (!chain) {
                    chain = g_string_new(NULL);
                }
                g_string_append_printf(chain, "%s0x%" PRIx64,
                                       hits ? ">" : "",
                                       (uint64_t)(prof_stack[i] -
                                                  prof_core));
                hits++;
            }
        }
        if (chain) {
            char *k = g_string_free(chain, FALSE);
            gpointer v = g_hash_table_lookup(t->via, k);
            g_hash_table_insert(t->via, k, GSIZE_TO_POINTER(
                GPOINTER_TO_SIZE(v) + 1));
        }
    }
    t->samples++;
}

static DWORD WINAPI prof_fn(LPVOID arg)
{
    /* a 1 ms period; Sleep(1) may be 15.6 ms (Windows 10 1803 and later) */
    HANDLE timer = CreateWaitableTimerExW(NULL, NULL,
                                          CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,
                                          TIMER_ALL_ACCESS);
    LARGE_INTEGER due = { .QuadPart = -10000 };

    while (!prof_stop) {
        prof_sample(&prof_vcpu);
        prof_sample(&prof_pfifo);
        if (timer && SetWaitableTimer(timer, &due, 0, NULL, NULL, FALSE)) {
            WaitForSingleObject(timer, INFINITE);
        } else {
            Sleep(1);
        }
    }
    if (timer) {
        CloseHandle(timer);
    }
    return 0;
}

static void prof_target_init(ProfTarget *t)
{
    t->guest = g_hash_table_new(NULL, NULL);
    t->host = g_hash_table_new(NULL, NULL);
    t->via = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    t->samples = t->jit = t->jit_unknown = t->failed = 0;
}

static void prof_target_free(ProfTarget *t)
{
    g_hash_table_destroy(t->guest);
    g_hash_table_destroy(t->host);
    g_hash_table_destroy(t->via);
}

void xemu_lr_prof_start(void)
{
    if (!prof_vcpu.h || prof_thread) {
        return;
    }
    prof_core_text();
    prof_target_init(&prof_vcpu);
    prof_target_init(&prof_pfifo);
    prof_tbsize = g_hash_table_new(NULL, NULL);
    prof_modules = g_ptr_array_new_with_free_func(g_free);
    g_ptr_array_add(prof_modules, g_strdup("(no module)"));
    prof_bases = g_array_new(FALSE, TRUE, sizeof(uintptr_t));
    g_array_set_size(prof_bases, 1);
    prof_stop = 0;
    prof_start_us = g_get_monotonic_time();
    prof_thread = CreateThread(NULL, 0, prof_fn, NULL, 0, NULL);
    if (prof_thread) {
        SetThreadPriority(prof_thread, THREAD_PRIORITY_TIME_CRITICAL);
    }
}

typedef struct ProfEntry {
    uint64_t key, count;
} ProfEntry;

static gint prof_cmp(gconstpointer a, gconstpointer b)
{
    const ProfEntry *x = a, *y = b;
    return x->count < y->count ? 1 : x->count > y->count ? -1 : 0;
}

static GArray *prof_sorted(GHashTable *t)
{
    GArray *a = g_array_new(FALSE, FALSE, sizeof(ProfEntry));
    GHashTableIter it;
    gpointer k, v;

    g_hash_table_iter_init(&it, t);
    while (g_hash_table_iter_next(&it, &k, &v)) {
        ProfEntry e = { GPOINTER_TO_SIZE(k), GPOINTER_TO_SIZE(v) };
        g_array_append_val(a, e);
    }
    g_array_sort(a, prof_cmp);
    return a;
}

static double pct(const ProfTarget *t, uint64_t n)
{
    return t->samples ? 100.0 * n / t->samples : 0;
}

/* One thread's shares to the log and, with f, its section of the file. */
static void prof_report(ProfTarget *t, XemuLrProfLog log, FILE *f)
{
    GArray *guest = prof_sorted(t->guest), *host = prof_sorted(t->host);
    uint64_t *per_module = g_new0(uint64_t, prof_modules->len);
    GHashTableIter it;
    gpointer k, v;

    for (unsigned i = 0; i < host->len; i++) {
        ProfEntry *e = &g_array_index(host, ProfEntry, i);
        per_module[e->key >> 40] += e->count;
    }

    log("%s profile: %" PRIu64 " samples in %.1f s (%" PRIu64
        " unreadable)\n", t->name, t->samples,
        (prof_end_us - prof_start_us) / 1e6, t->failed);
    if (t->jit) {
        log("%s profile: translated guest code %.1f%% (%.1f%% in blocks "
            "already gone)\n", t->name, pct(t, t->jit),
            pct(t, t->jit_unknown));
    }
    for (unsigned i = 0; i < prof_modules->len; i++) {
        if (per_module[i]) {
            log("%s profile: %s %.1f%%\n", t->name,
                (char *)g_ptr_array_index(prof_modules, i),
                pct(t, per_module[i]));
        }
    }
    for (unsigned i = 0; i < guest->len && i < 15; i++) {
        ProfEntry *e = &g_array_index(guest, ProfEntry, i);
        log("%s profile: guest block phys 0x%08" PRIx64 " %.2f%%\n",
            t->name, e->key, pct(t, e->count));
    }

    if (f) {
        fprintf(f, "# xemu %s profile: %" PRIu64 " samples, %.1f s\n",
                t->name, t->samples, (prof_end_us - prof_start_us) / 1e6);
        fprintf(f, "# jit %" PRIu64 " jit_unknown %" PRIu64
                " unreadable %" PRIu64 "\n",
                t->jit, t->jit_unknown, t->failed);
        for (unsigned i = 0; i < guest->len; i++) {
            ProfEntry *e = &g_array_index(guest, ProfEntry, i);
            fprintf(f, "guest 0x%08" PRIx64 " %" PRIu64 "\n", e->key,
                    e->count);
        }
        for (unsigned i = 0; i < host->len; i++) {
            ProfEntry *e = &g_array_index(host, ProfEntry, i);
            fprintf(f, "host %s 0x%" PRIx64 " %" PRIu64 "\n",
                    (char *)g_ptr_array_index(prof_modules, e->key >> 40),
                    e->key & ((1ULL << 40) - 1), e->count);
        }
        g_hash_table_iter_init(&it, t->via);
        while (g_hash_table_iter_next(&it, &k, &v)) {
            fprintf(f, "via xemu_libretro %s %" PRIu64 "\n", (char *)k,
                    (uint64_t)GPOINTER_TO_SIZE(v));
        }
        /* the hottest blocks' guest code (the block may have changed since) */
        for (unsigned i = 0; i < guest->len && i < 30; i++) {
            ProfEntry *e = &g_array_index(guest, ProfEntry, i);
            uint8_t code[256];
            size_t n = GPOINTER_TO_SIZE(g_hash_table_lookup(prof_tbsize,
                GSIZE_TO_POINTER((gsize)e->key)));
            n = MIN(MAX(n, 16), sizeof(code));
            WITH_RCU_READ_LOCK_GUARD() {
                memcpy(code, qemu_map_ram_ptr(NULL, e->key), n);
            }
            fprintf(f, "code 0x%08" PRIx64 " ", e->key);
            for (size_t j = 0; j < n; j++) {
                fprintf(f, "%02x", code[j]);
            }
            fprintf(f, "\n");
        }
    }

    g_free(per_module);
    g_array_free(guest, TRUE);
    g_array_free(host, TRUE);
}

void xemu_lr_prof_stop(XemuLrProfLog log, const char *dir)
{
    FILE *f = NULL;
    char *path = NULL;

    if (!prof_thread) {
        if (!prof_vcpu.h) {
            log("vCPU profile: no vCPU thread registered\n");
        }
        return;
    }
    prof_stop = 1;
    WaitForSingleObject(prof_thread, INFINITE);
    CloseHandle(prof_thread);
    prof_thread = NULL;
    prof_end_us = g_get_monotonic_time();

    if (dir && *dir) {
        path = g_build_filename(dir, "xemu_profile.txt", NULL);
        f = fopen(path, "w");
    }
    prof_report(&prof_vcpu, log, f);
    if (prof_pfifo.h) {
        prof_report(&prof_pfifo, log, f);
    } else {
        log("pfifo profile: no GPU thread registered\n");
    }
    if (f) {
        fclose(f);
        log("vCPU profile: every sample in %s\n", path);
    } else if (path) {
        log("vCPU profile: could not write %s\n", path);
    }

    g_free(path);
    prof_target_free(&prof_vcpu);
    prof_target_free(&prof_pfifo);
    g_hash_table_destroy(prof_tbsize);
    g_ptr_array_free(prof_modules, TRUE);
    g_array_free(prof_bases, TRUE);
}

#else

void xemu_lr_prof_vcpu(void)
{
}

void xemu_lr_prof_pfifo(void)
{
}

void xemu_lr_prof_start(void)
{
}

void xemu_lr_prof_stop(XemuLrProfLog log, const char *dir)
{
    (void)dir;
    log("vCPU profile: only in Windows builds\n");
}

#endif
