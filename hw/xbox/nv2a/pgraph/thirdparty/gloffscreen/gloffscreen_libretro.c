/*
 *  Offscreen OpenGL abstraction layer -- libretro/WGL based
 *
 *  In libretro mode, RetroArch owns the primary GL context.
 *  This implementation creates shared WGL contexts for worker threads
 *  (like the PFIFO/PGRAPH thread) that need their own GL context.
 *
 *  Copyright (c) 2025
 *  SPDX-License-Identifier: MIT
 */

#ifdef LIBRETRO

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "gloffscreen.h"

#ifdef _WIN32
#include <windows.h>
#include <wingdi.h>

/* WGL function types */
typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTPROC)(HDC);
typedef BOOL  (WINAPI *PFNWGLDELETECONTEXTPROC)(HGLRC);
typedef BOOL  (WINAPI *PFNWGLMAKECURRENTPROC)(HDC, HGLRC);
typedef HGLRC (WINAPI *PFNWGLGETCURRENTCONTEXTPROC)(void);
typedef HDC   (WINAPI *PFNWGLGETCURRENTDCPROC)(void);
typedef BOOL  (WINAPI *PFNWGLSHARELISTSPROC)(HGLRC, HGLRC);

struct _GloContext {
    HWND   hwnd;
    HDC    hdc;
    HGLRC  hglrc;
};

/* WGL_ARB_create_context defines */
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001

typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int *);

/* Stored reference to RetroArch's GL context for sharing */
static HGLRC g_retroarch_hglrc = NULL;
static HDC   g_retroarch_hdc = NULL;
static volatile bool g_libretro_gl_ready = false;
static PFNWGLCREATECONTEXTATTRIBSARBPROC p_wglCreateContextAttribsARB = NULL;
static int g_ra_pixel_format = 0;
static bool g_wndclass_registered = false;
static bool g_standalone_gl_mode = false;
static GloContext *g_standalone_root_ctx = NULL;

/* Event for PFIFO thread to wait on */
static HANDLE g_gl_ready_event = NULL;

void libretro_gl_init_wait_event(void)
{
    if (!g_gl_ready_event) {
        g_gl_ready_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    }
}

void libretro_gl_prepare(void)
{
    g_retroarch_hglrc = wglGetCurrentContext();
    g_retroarch_hdc = wglGetCurrentDC();

    if (!p_wglCreateContextAttribsARB) {
        p_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)
            wglGetProcAddress("wglCreateContextAttribsARB");
    }

    if (g_retroarch_hdc) {
        g_ra_pixel_format = GetPixelFormat(g_retroarch_hdc);
    }

    g_libretro_gl_ready = true;
}

void libretro_gl_wake_pfifo(void)
{
    if (g_gl_ready_event) {
        SetEvent(g_gl_ready_event);
    }
}

void libretro_gl_wait_for_contexts(void)
{
    libretro_gl_init_wait_event();
    WaitForSingleObject(g_gl_ready_event, 30000);
}

void libretro_gl_signal_ready(void)
{
    libretro_gl_prepare();
    libretro_gl_wake_pfifo();
}

void libretro_gl_set_standalone_mode(void)
{
    g_standalone_gl_mode = true;
    g_libretro_gl_ready = true;
}

void libretro_gl_wait_ready(void)
{
    if (g_libretro_gl_ready) return;

    libretro_gl_init_wait_event();
    WaitForSingleObject(g_gl_ready_event, 30000);
}

bool libretro_gl_is_ready(void)
{
    return g_libretro_gl_ready;
}

/* Create an OpenGL core profile context, shared with RetroArch or standalone */
GloContext *glo_context_create(void)
{
    GloContext *context = (GloContext *)calloc(1, sizeof(GloContext));
    assert(context != NULL);

    libretro_gl_wait_ready();

    if (!g_wndclass_registered) {
        WNDCLASSA wc = {0};
        wc.lpfnWndProc = DefWindowProcA;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "XemuGloOffscreen";
        RegisterClassA(&wc);
        g_wndclass_registered = true;
    }

    context->hwnd = CreateWindowA("XemuGloOffscreen", "Offscreen",
                                   0, 0, 0, 1, 1,
                                   NULL, NULL, GetModuleHandle(NULL), NULL);
    if (!context->hwnd) {
        free(context);
        return NULL;
    }

    context->hdc = GetDC(context->hwnd);

    if (g_standalone_gl_mode) {
        PIXELFORMATDESCRIPTOR pfd = {0};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        int pf = ChoosePixelFormat(context->hdc, &pfd);
        SetPixelFormat(context->hdc, pf, &pfd);

        if (!p_wglCreateContextAttribsARB) {
            HGLRC tmp = wglCreateContext(context->hdc);
            wglMakeCurrent(context->hdc, tmp);
            p_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)
                wglGetProcAddress("wglCreateContextAttribsARB");
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tmp);
        }

        if (!p_wglCreateContextAttribsARB) {
            ReleaseDC(context->hwnd, context->hdc);
            DestroyWindow(context->hwnd);
            free(context);
            return NULL;
        }

        int attribs[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 0,
            WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
        };

        HGLRC share = g_standalone_root_ctx ? g_standalone_root_ctx->hglrc : NULL;
        context->hglrc = p_wglCreateContextAttribsARB(context->hdc, share, attribs);
        if (!context->hglrc) {
            ReleaseDC(context->hwnd, context->hdc);
            DestroyWindow(context->hwnd);
            free(context);
            return NULL;
        }

        if (!g_standalone_root_ctx) {
            g_standalone_root_ctx = context;
        }

        return context;
    }

    if (!g_retroarch_hglrc) {
        return context;
    }

    if (!p_wglCreateContextAttribsARB) {
        free(context);
        return NULL;
    }

    if (g_ra_pixel_format > 0) {
        PIXELFORMATDESCRIPTOR pfd = {0};
        pfd.nSize = sizeof(pfd);
        DescribePixelFormat(g_retroarch_hdc, g_ra_pixel_format, sizeof(pfd), &pfd);
        SetPixelFormat(context->hdc, g_ra_pixel_format, &pfd);
    } else {
        PIXELFORMATDESCRIPTOR pfd = {0};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        int pf = ChoosePixelFormat(context->hdc, &pfd);
        SetPixelFormat(context->hdc, pf, &pfd);
    }

    int attribs[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 0,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0
    };

    context->hglrc = p_wglCreateContextAttribsARB(context->hdc, g_retroarch_hglrc, attribs);
    if (!context->hglrc) {
        ReleaseDC(context->hwnd, context->hdc);
        DestroyWindow(context->hwnd);
        free(context);
        return NULL;
    }

    return context;
}

void glo_set_current(GloContext *context)
{
    if (context == NULL || context->hglrc == NULL) {
        wglMakeCurrent(NULL, NULL);
    } else {
        wglMakeCurrent(context->hdc, context->hglrc);
    }
}

void glo_context_destroy(GloContext *context)
{
    if (!context) return;
    if (context->hglrc) {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(context->hglrc);
    }
    if (context->hwnd) {
        ReleaseDC(context->hwnd, context->hdc);
        DestroyWindow(context->hwnd);
    }
    free(context);
}

#else /* !_WIN32 */

/*
 * Linux and the other non-Windows hosts. RetroArch's GL context there is EGL
 * (Wayland, KMS, and X11 with an EGL context driver) or GLX (X11). Whichever
 * is current when RetroArch calls context_reset is the one the worker
 * contexts are created to share with; with Vulkan in RetroArch there is none,
 * and the contexts are made on a surfaceless EGL display of their own.
 *
 * Worker contexts render into FBOs only, so they are made current without a
 * surface: EGL_KHR_surfaceless_context, or a 1x1 pbuffer where it is missing;
 * GLX always gets a 1x1 pbuffer.
 */

#include <pthread.h>
#include <time.h>
#include <epoxy/egl.h>
#include <epoxy/glx.h>

typedef enum { GLO_API_NONE, GLO_API_EGL, GLO_API_GLX } GloApi;

struct _GloContext {
    GloApi api;
    EGLContext egl_ctx;
    EGLSurface egl_surface;
    GLXContext glx_ctx;
    GLXPbuffer glx_pbuffer;
};

static GloApi g_api = GLO_API_NONE;
static EGLDisplay g_egl_dpy = EGL_NO_DISPLAY;
static EGLContext g_egl_share = EGL_NO_CONTEXT;
static EGLConfig g_egl_config = NULL;
static bool g_egl_surfaceless = false;
static Display *g_glx_dpy = NULL;
static GLXContext g_glx_share = NULL;
static GLXFBConfig g_glx_config = NULL;

static volatile bool g_libretro_gl_ready = false;
static bool g_standalone_gl_mode = false;
static GloContext *g_standalone_root_ctx = NULL;

static pthread_mutex_t g_ready_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t g_ready_cond = PTHREAD_COND_INITIALIZER;
static bool g_ready_signalled = false;

static void wait_ready_signal(void)
{
    struct timespec deadline;
    clock_gettime(CLOCK_REALTIME, &deadline);
    deadline.tv_sec += 30;
    pthread_mutex_lock(&g_ready_mutex);
    while (!g_ready_signalled) {
        if (pthread_cond_timedwait(&g_ready_cond, &g_ready_mutex, &deadline) != 0) {
            break;
        }
    }
    pthread_mutex_unlock(&g_ready_mutex);
}

void libretro_gl_init_wait_event(void)
{
}

/* The config of RetroArch's context, so the shared ones are compatible. */
static void egl_prepare_from_current(void)
{
    g_egl_dpy = eglGetCurrentDisplay();
    g_egl_share = eglGetCurrentContext();
    EGLint config_id = 0;
    eglQueryContext(g_egl_dpy, g_egl_share, EGL_CONFIG_ID, &config_id);
    const EGLint attribs[] = { EGL_CONFIG_ID, config_id, EGL_NONE };
    EGLint n = 0;
    if (!eglChooseConfig(g_egl_dpy, attribs, &g_egl_config, 1, &n) || n < 1) {
        g_egl_config = NULL; /* EGL_KHR_no_config_context below, if offered */
    }
    g_egl_surfaceless =
        epoxy_has_egl_extension(g_egl_dpy, "EGL_KHR_surfaceless_context");
    g_api = GLO_API_EGL;
}

static void glx_prepare_from_current(void)
{
    g_glx_dpy = glXGetCurrentDisplay();
    g_glx_share = glXGetCurrentContext();
    int fbconfig_id = 0;
    glXQueryContext(g_glx_dpy, g_glx_share, GLX_FBCONFIG_ID, &fbconfig_id);
    const int attribs[] = { GLX_FBCONFIG_ID, fbconfig_id, None };
    int n = 0;
    GLXFBConfig *configs = glXChooseFBConfig(g_glx_dpy, DefaultScreen(g_glx_dpy), attribs, &n);
    g_glx_config = (configs && n > 0) ? configs[0] : NULL;
    if (configs) {
        XFree(configs);
    }
    g_api = GLO_API_GLX;
}

/* RetroArch on Vulkan: a display of our own, without a window system. */
static bool egl_prepare_standalone(void)
{
    if (epoxy_has_egl_extension(EGL_NO_DISPLAY, "EGL_MESA_platform_surfaceless")) {
        g_egl_dpy = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, NULL);
    }
    if (g_egl_dpy == EGL_NO_DISPLAY) {
        g_egl_dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    }
    if (g_egl_dpy == EGL_NO_DISPLAY || !eglInitialize(g_egl_dpy, NULL, NULL)) {
        fprintf(stderr, "[xemu] gloffscreen: no EGL display for the GL contexts\n");
        return false;
    }
    const EGLint attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8,
        EGL_NONE
    };
    EGLint n = 0;
    if (!eglChooseConfig(g_egl_dpy, attribs, &g_egl_config, 1, &n) || n < 1) {
        g_egl_config = NULL;
    }
    g_egl_surfaceless = epoxy_has_egl_extension(g_egl_dpy, "EGL_KHR_surfaceless_context");
    g_egl_share = EGL_NO_CONTEXT;
    g_api = GLO_API_EGL;
    return true;
}

void libretro_gl_prepare(void)
{
    /* Asking EGL first is safe with GLX current: no EGL context then. */
    if (eglGetCurrentContext() != EGL_NO_CONTEXT) {
        egl_prepare_from_current();
    } else if (glXGetCurrentContext()) {
        glx_prepare_from_current();
    } else {
        fprintf(stderr, "[xemu] gloffscreen: no current GL context from the frontend\n");
        g_api = GLO_API_NONE;
    }
    g_libretro_gl_ready = true;
}

void libretro_gl_wake_pfifo(void)
{
    pthread_mutex_lock(&g_ready_mutex);
    g_ready_signalled = true;
    pthread_cond_broadcast(&g_ready_cond);
    pthread_mutex_unlock(&g_ready_mutex);
}

void libretro_gl_wait_for_contexts(void)
{
    wait_ready_signal();
}

void libretro_gl_signal_ready(void)
{
    libretro_gl_prepare();
    libretro_gl_wake_pfifo();
}

void libretro_gl_set_standalone_mode(void)
{
    g_standalone_gl_mode = true;
    egl_prepare_standalone();
    g_libretro_gl_ready = true;
}

void libretro_gl_wait_ready(void)
{
    if (g_libretro_gl_ready) return;
    wait_ready_signal();
}

bool libretro_gl_is_ready(void)
{
    return g_libretro_gl_ready;
}

static bool egl_create(GloContext *context, EGLContext share)
{
    eglBindAPI(EGL_OPENGL_API);
    const EGLint attribs[] = {
        EGL_CONTEXT_MAJOR_VERSION, 4,
        EGL_CONTEXT_MINOR_VERSION, 0,
        EGL_CONTEXT_OPENGL_PROFILE_MASK, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
        EGL_NONE
    };
    context->egl_ctx = eglCreateContext(g_egl_dpy, g_egl_config, share, attribs);
    if (context->egl_ctx == EGL_NO_CONTEXT) {
        fprintf(stderr, "[xemu] gloffscreen: eglCreateContext failed (0x%x)\n", eglGetError());
        return false;
    }
    context->egl_surface = EGL_NO_SURFACE;
    if (!g_egl_surfaceless && g_egl_config) {
        const EGLint pb[] = { EGL_WIDTH, 1, EGL_HEIGHT, 1, EGL_NONE };
        context->egl_surface = eglCreatePbufferSurface(g_egl_dpy, g_egl_config, pb);
    }
    context->api = GLO_API_EGL;
    return true;
}

static bool glx_create(GloContext *context, GLXContext share)
{
    if (!g_glx_config || !epoxy_has_glx_extension(g_glx_dpy, DefaultScreen(g_glx_dpy), "GLX_ARB_create_context")) {
        fprintf(stderr, "[xemu] gloffscreen: GLX_ARB_create_context is missing\n");
        return false;
    }
    const int attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
        GLX_CONTEXT_MINOR_VERSION_ARB, 0,
        GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
        None
    };
    context->glx_ctx = glXCreateContextAttribsARB(g_glx_dpy, g_glx_config, share, True, attribs);
    if (!context->glx_ctx) {
        fprintf(stderr, "[xemu] gloffscreen: glXCreateContextAttribsARB failed\n");
        return false;
    }
    const int pb[] = { GLX_PBUFFER_WIDTH, 1, GLX_PBUFFER_HEIGHT, 1, None };
    context->glx_pbuffer = glXCreatePbuffer(g_glx_dpy, g_glx_config, pb);
    context->api = GLO_API_GLX;
    return true;
}

/* An OpenGL 4.0 core profile context, shared with RetroArch's or, with
 * RetroArch on Vulkan, with the first one made here. */
GloContext *glo_context_create(void)
{
    GloContext *context = (GloContext *)calloc(1, sizeof(GloContext));
    assert(context != NULL);

    libretro_gl_wait_ready();

    bool ok = false;
    if (g_api == GLO_API_EGL) {
        EGLContext share = g_egl_share;
        if (g_standalone_gl_mode && g_standalone_root_ctx) {
            share = g_standalone_root_ctx->egl_ctx;
        }
        ok = egl_create(context, share);
    } else if (g_api == GLO_API_GLX) {
        ok = glx_create(context, g_glx_share);
    }
    if (!ok) {
        free(context);
        return NULL;
    }
    if (g_standalone_gl_mode && !g_standalone_root_ctx) {
        g_standalone_root_ctx = context;
    }
    return context;
}

void glo_set_current(GloContext *context)
{
    if (context == NULL) {
        if (g_api == GLO_API_EGL) {
            eglMakeCurrent(g_egl_dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        } else if (g_api == GLO_API_GLX) {
            glXMakeContextCurrent(g_glx_dpy, None, None, NULL);
        }
        return;
    }
    if (context->api == GLO_API_EGL) {
        eglMakeCurrent(g_egl_dpy, context->egl_surface, context->egl_surface, context->egl_ctx);
    } else if (context->api == GLO_API_GLX) {
        glXMakeContextCurrent(g_glx_dpy, context->glx_pbuffer, context->glx_pbuffer, context->glx_ctx);
    }
}

void glo_context_destroy(GloContext *context)
{
    if (!context) return;
    if (context->api == GLO_API_EGL) {
        if (eglGetCurrentContext() == context->egl_ctx) {
            eglMakeCurrent(g_egl_dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        }
        if (context->egl_surface != EGL_NO_SURFACE) {
            eglDestroySurface(g_egl_dpy, context->egl_surface);
        }
        eglDestroyContext(g_egl_dpy, context->egl_ctx);
    } else if (context->api == GLO_API_GLX) {
        if (glXGetCurrentContext() == context->glx_ctx) {
            glXMakeContextCurrent(g_glx_dpy, None, None, NULL);
        }
        if (context->glx_pbuffer) {
            glXDestroyPbuffer(g_glx_dpy, context->glx_pbuffer);
        }
        glXDestroyContext(g_glx_dpy, context->glx_ctx);
    }
    if (context == g_standalone_root_ctx) {
        g_standalone_root_ctx = NULL;
    }
    free(context);
}

#endif /* _WIN32 */
#endif /* LIBRETRO */
