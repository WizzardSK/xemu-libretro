#!/bin/bash
# The libretro core for Linux, as the buildbot's job builds it (.gitlab-ci.yml)
# in ubuntu:24.04; the GitLab preflight workflow runs the same script.
#
# One file is what the buildbot ships, so libslirp, which the GitHub builds
# put next to the core, is built here as a static library and linked in.
#
# So is GLib (glib, gobject, gmodule, gio, with PCRE2 and libffi from its own
# subprojects): RetroArch's AppImage carries an old GLib that is loaded before
# the system's, and a core using the system's newer one could not be loaded
# there ("undefined symbol: g_spawn_async_with_fds", issue 4). Linked in and
# hidden by the core's version script (-Wl,--exclude-libs,ALL), the core's
# GLib is its own whatever the frontend has loaded.
set -euxo pipefail

NUMPROC=${NUMPROC:-$(nproc)}
[ "$NUMPROC" -ge 1 ] || NUMPROC=1
export DEBIAN_FRONTEND=noninteractive

# upstream's build dependencies (debian/control), as the GitHub workflow
# installs them, without libslirp; cmake (for the CMake subprojects) and curl
# (meson fetches the DSP library with it) are on a GitHub runner already
apt-get -qy update
apt-get -qy install --no-install-recommends \
  build-essential git ca-certificates pkg-config ninja-build meson cmake curl \
  python3 python3-pip python3-tomli python3-yaml python3-venv \
  libepoxy-dev libpixman-1-dev libsdl2-dev libsamplerate0-dev zlib1g-dev libssl-dev \
  libpcap-dev libvulkan-dev libusb-1.0-0-dev libcurl4-openssl-dev \
  libx11-dev libegl-dev libgl-dev glslang-dev spirv-tools \
  libpipewire-0.3-dev
git config --global --add safe.directory '*'

multiarch=$(gcc -print-multiarch)


# GLib 2.80.0, the version of Ubuntu 24.04's package, static and position
# independent, only what QEMU needs
git clone --quiet --depth 1 -b 2.80.0 https://gitlab.gnome.org/GNOME/glib.git /tmp/glib
meson setup /tmp/glib/build /tmp/glib --buildtype=release \
  --prefix=/usr/local --libdir=lib -Ddefault_library=static -Db_staticpic=true \
  --force-fallback-for=libpcre2-8,libffi \
  -Dtests=false -Dintrospection=disabled -Dnls=disabled -Dlibmount=disabled \
  -Dselinux=disabled -Dxattr=false -Dlibelf=disabled -Dsysprof=disabled \
  -Dman-pages=disabled -Ddocumentation=false -Ddtrace=false -Dsystemtap=false \
  -Dglib_debug=disabled
ninja -C /tmp/glib/build install
# pkg-config hands out a static library's own dependencies (PCRE2, libffi,
# libm, threads) only with --static, which QEMU's meson does not ask for:
# make them the libraries' public ones
for pc in /usr/local/lib/pkgconfig/*.pc; do
  python3 - "$pc" <<'PCEOF'
import re, sys
p = sys.argv[1]; s = open(p).read()
for k in ('Libs', 'Requires'):
    m = re.search(r'^%s\.private:(.*)$' % k, s, re.M)
    if not m:
        continue
    s = re.sub(r'^%s\.private:.*\n' % k, '', s, flags=re.M)
    if re.search(r'^%s:' % k, s, re.M):
        s = re.sub(r'^(%s:.*)$' % k, lambda x: x.group(1) + ' ' + m.group(1).strip(), s, count=1, flags=re.M)
    else:
        s += '%s: %s\n' % (k, m.group(1).strip())
open(p, 'w').write(s)
PCEOF
done
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
pkg-config --libs glib-2.0 gio-2.0 gmodule-2.0 gobject-2.0

# libslirp 4.7.0, the version of Ubuntu 24.04's package, on that GLib
git clone --quiet --depth 1 -b v4.7.0 https://gitlab.freedesktop.org/slirp/libslirp.git /tmp/libslirp
meson setup /tmp/libslirp/build /tmp/libslirp --buildtype=release \
  --prefix=/usr/local --libdir=lib -Ddefault_library=static -Db_staticpic=true
ninja -C /tmp/libslirp/build install

# The core is a shared library, so QEMU's static libraries that go into it
# have to be position independent (b_staticpic).
LIBRARY_PATH=/usr/lib/$multiarch ./configure \
  --extra-cflags="-DXBOX=1 -Wno-error" \
  --target-list=i386-softmmu \
  -Dlibretro=true -Dpipewire=disabled \
  -Db_staticpic=true

ninja -C build -j "$NUMPROC" xemu_libretro.so
mv build/xemu_libretro.so xemu_libretro.so
strip --strip-unneeded xemu_libretro.so
ls -la xemu_libretro.so
# libslirp must be inside: no NEEDED entry for it
readelf -d xemu_libretro.so | grep NEEDED
! readelf -d xemu_libretro.so | grep -q 'NEEDED.*libslirp'
# GLib must be inside too, and none of its symbols left for the frontend's
# (a negated command does not stop the script under set -e: exit by hand)
if readelf -d xemu_libretro.so | grep -E 'NEEDED.*lib(glib|gio|gobject|gmodule)-2'; then exit 1; fi
if nm -D --undefined-only xemu_libretro.so | grep -E ' g_[a-z]'; then exit 1; fi
# and no window system's library: the frontend owns the window
! readelf -d xemu_libretro.so | grep -q 'NEEDED.*libX11'
