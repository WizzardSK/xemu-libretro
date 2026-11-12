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

static HANDLE prof_vcpu;           /* the vCPU thread (xemu_lr_prof_vcpu) */
static HANDLE prof_thread;
static volatile LONG prof_stop;
static GHashTable *prof_guest;     /* guest block phys addr -> count */
static GHashTable *prof_host;      /* (module index << 40 | offset) -> count */
static GPtrArray *prof_modules;    /* module names, index = slot */
static GArray *prof_bases;         /* module bases, same index */
static uint64_t prof_samples, prof_jit, prof_jit_unknown, prof_failed;
static int64_t prof_start_us, prof_end_us;

void xemu_lr_prof_vcpu(void)
{
    HANDLE h;

    if (DuplicateHandle(GetCurrentProcess(), GetCurrentThread(),
                        GetCurrentProcess(), &h,
                        THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT |
                        THREAD_QUERY_INFORMATION, FALSE, 0)) {
        prof_vcpu = h;
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

static DWORD WINAPI prof_fn(LPVOID arg)
{
    /* a 1 ms period; Sleep(1) may be 15.6 ms (Windows 10 1803 and later) */
    HANDLE timer = CreateWaitableTimerExW(NULL, NULL,
                                          CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,
                                          TIMER_ALL_ACCESS);
    LARGE_INTEGER due = { .QuadPart = -10000 };

    while (!prof_stop) {
        CONTEXT ctx = { .ContextFlags = CONTEXT_CONTROL };
        uintptr_t pc = 0;

        if (SuspendThread(prof_vcpu) != (DWORD)-1) {
            /* the context is only certain once the thread really stopped */
            if (GetThreadContext(prof_vcpu, &ctx)) {
                pc = (uintptr_t)ctx.Rip;
            }
            ResumeThread(prof_vcpu);
        }
        if (!pc) {
            prof_failed++;
        } else if (in_code_gen_buffer((void *)pc)) {
            /* looked up after the resume: the vCPU may hold the TB tree */
            TranslationBlock *tb = tcg_tb_lookup(pc);
            prof_jit++;
            if (tb) {
                prof_count(prof_guest, tb_page_addr0(tb));
            } else {
                prof_jit_unknown++;
            }
        } else {
            uintptr_t base;
            unsigned m = prof_module(pc, &base);
            prof_count(prof_host, (uint64_t)m << 40 | (pc - base));
        }
        prof_samples++;
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

void xemu_lr_prof_start(void)
{
    if (!prof_vcpu || prof_thread) {
        return;
    }
    prof_guest = g_hash_table_new(NULL, NULL);
    prof_host = g_hash_table_new(NULL, NULL);
    prof_modules = g_ptr_array_new_with_free_func(g_free);
    g_ptr_array_add(prof_modules, g_strdup("(no module)"));
    prof_bases = g_array_new(FALSE, TRUE, sizeof(uintptr_t));
    g_array_set_size(prof_bases, 1);
    prof_samples = prof_jit = prof_jit_unknown = prof_failed = 0;
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

static double pct(uint64_t n)
{
    return prof_samples ? 100.0 * n / prof_samples : 0;
}

void xemu_lr_prof_stop(XemuLrProfLog log, const char *dir)
{
    GArray *guest, *host;
    uint64_t *per_module;
    FILE *f = NULL;
    char *path = NULL;

    if (!prof_thread) {
        if (!prof_vcpu) {
            log("vCPU profile: no vCPU thread registered\n");
        }
        return;
    }
    prof_stop = 1;
    WaitForSingleObject(prof_thread, INFINITE);
    CloseHandle(prof_thread);
    prof_thread = NULL;
    prof_end_us = g_get_monotonic_time();

    guest = prof_sorted(prof_guest);
    host = prof_sorted(prof_host);
    per_module = g_new0(uint64_t, prof_modules->len);
    for (unsigned i = 0; i < host->len; i++) {
        ProfEntry *e = &g_array_index(host, ProfEntry, i);
        per_module[e->key >> 40] += e->count;
    }

    log("vCPU profile: %" PRIu64 " samples in %.1f s (%" PRIu64
        " unreadable)\n", prof_samples,
        (prof_end_us - prof_start_us) / 1e6, prof_failed);
    log("vCPU profile: translated guest code %.1f%% (%.1f%% in blocks "
        "already gone)\n", pct(prof_jit), pct(prof_jit_unknown));
    for (unsigned i = 0; i < prof_modules->len; i++) {
        if (per_module[i]) {
            log("vCPU profile: %s %.1f%%\n",
                (char *)g_ptr_array_index(prof_modules, i),
                pct(per_module[i]));
        }
    }
    for (unsigned i = 0; i < guest->len && i < 15; i++) {
        ProfEntry *e = &g_array_index(guest, ProfEntry, i);
        log("vCPU profile: guest block phys 0x%08" PRIx64 " %.2f%%\n",
            e->key, pct(e->count));
    }

    if (dir && *dir) {
        path = g_build_filename(dir, "xemu_profile.txt", NULL);
        f = fopen(path, "w");
    }
    if (f) {
        fprintf(f, "# xemu vCPU profile: %" PRIu64 " samples, %.1f s\n",
                prof_samples, (prof_end_us - prof_start_us) / 1e6);
        fprintf(f, "# jit %" PRIu64 " jit_unknown %" PRIu64
                " unreadable %" PRIu64 "\n",
                prof_jit, prof_jit_unknown, prof_failed);
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
        fclose(f);
        log("vCPU profile: every sample in %s\n", path);
    } else if (path) {
        log("vCPU profile: could not write %s\n", path);
    }

    g_free(path);
    g_free(per_module);
    g_array_free(guest, TRUE);
    g_array_free(host, TRUE);
    g_hash_table_destroy(prof_guest);
    g_hash_table_destroy(prof_host);
    g_ptr_array_free(prof_modules, TRUE);
    g_array_free(prof_bases, TRUE);
}

#else

void xemu_lr_prof_vcpu(void)
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
