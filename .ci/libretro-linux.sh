#!/bin/bash
# The libretro core for Linux, as the buildbot's job builds it (.gitlab-ci.yml)
# in ubuntu:24.04; the GitLab preflight workflow runs the same script.
#
# One file is what the buildbot ships, so libslirp, which the GitHub builds
# put next to the core, is built here as a static library and linked in.
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
  libglib2.0-dev libx11-dev libegl-dev libgl-dev glslang-dev spirv-tools \
  libpipewire-0.3-dev
git config --global --add safe.directory '*'

multiarch=$(gcc -print-multiarch)

# libslirp 4.7.0, the version of Ubuntu 24.04's package
git clone --quiet --depth 1 -b v4.7.0 https://gitlab.freedesktop.org/slirp/libslirp.git /tmp/libslirp
meson setup /tmp/libslirp/build /tmp/libslirp --buildtype=release \
  --prefix=/usr/local --libdir=lib -Ddefault_library=static -Db_staticpic=true
ninja -C /tmp/libslirp/build install
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

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
