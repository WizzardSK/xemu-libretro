#!/bin/bash
# The libretro core for Windows x64, as the buildbot's job builds it
# (.gitlab-ci.yml): cross-compiled in the MXE toolchain image upstream xemu
# uses for its Windows releases, as the GitHub workflow does; the GitLab
# preflight workflow runs the same script.
set -euxo pipefail

NUMPROC=${NUMPROC:-$(nproc)}
[ "$NUMPROC" -ge 1 ] || NUMPROC=1
CROSSPREFIX=x86_64-w64-mingw32.static-
git config --global --add safe.directory '*'

# The libretro build links glslang and SPIRV-Tools statically
# (cc.find_library(..., static: true) in meson.build), and the MXE image has
# neither, so they are built here.
git clone --quiet --depth 1 -b 15.4.0 https://github.com/KhronosGroup/glslang.git /tmp/glslang
(
  cd /tmp/glslang
  python3 update_glslang_sources.py
  ${CROSSPREFIX}cmake -S . -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/opt/glslang \
    -DBUILD_SHARED_LIBS=OFF \
    -DENABLE_OPT=ON \
    -DENABLE_GLSLANG_BINARIES=OFF \
    -DGLSLANG_TESTS=OFF \
    -DBUILD_TESTING=OFF \
    -DSPIRV_SKIP_TESTS=ON \
    -DSPIRV_SKIP_EXECUTABLES=ON \
    -DSPIRV_TOOLS_BUILD_STATIC=ON
  cmake --build build -j "$NUMPROC"
  cmake --install build
)
# SPIRV-Tools installs its static library as SPIRV-Tools-static when it builds
# both kinds; the build looks for SPIRV-Tools.
[ -f /opt/glslang/lib/libSPIRV-Tools.a ] || cp /opt/glslang/lib/libSPIRV-Tools-static.a /opt/glslang/lib/libSPIRV-Tools.a
# meson's find_library(static: true) only searches the compiler's own library
# directories, so the libraries go into the toolchain's own lib directory.
libdir=$(dirname "$(${CROSSPREFIX}gcc -print-file-name=libkernel32.a)")
cp -a /opt/glslang/lib/*.a "$libdir/"

# The DSP JIT's prebuilt library, which meson fetches with curl; the MXE image
# has no curl, so it is put where meson looks for it first
ver=$(sed -n "s/^project('dsp56300', version: '\(.*\)')/\1/p" subprojects/dsp56300/meson.build)
a=dsp56300-$ver-x86_64-pc-windows-gnu.tar.gz
python3 -c "import sys, urllib.request; urllib.request.urlretrieve(sys.argv[1], sys.argv[2])" \
  "https://github.com/mborgerson/dsp56300/releases/download/v$ver/$a" "subprojects/dsp56300/$a"

AR=${CROSSPREFIX}gcc-ar ./configure \
  --extra-cflags="-DXBOX=1 -Wno-error -I/opt/glslang/include" \
  --extra-ldflags="-L/opt/glslang/lib" \
  --target-list=i386-softmmu \
  --cross-prefix=$CROSSPREFIX --static \
  -Dlibretro=true

ninja -C build -j "$NUMPROC" xemu_libretro.dll
mv build/xemu_libretro.dll xemu_libretro.dll
${CROSSPREFIX}strip --strip-unneeded xemu_libretro.dll
ls -la xemu_libretro.dll
# What it needs at load time: Windows' own DLLs and nothing else.
${CROSSPREFIX}objdump -p xemu_libretro.dll | grep 'DLL Name' | sort -u
