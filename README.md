# xemu libretro core

A [libretro](https://www.libretro.com/) core of [xemu](https://xemu.app), the original Xbox emulator, for RetroArch and other libretro frontends.

The emulator is upstream's: this repository follows [xemu-project/xemu](https://github.com/xemu-project/xemu) and adds the libretro frontend in `ui/libretro.c`. It holds the core only; upstream's standalone UI, packaging and CI are not part of it (the paths are listed in `.upstream-excluded`). The version the core reports is upstream's, with the upstream commit it is merged to (`upstream.version`).

## Downloads

Builds for Windows, Linux (x86_64, aarch64), macOS (Apple Silicon, Intel) and Android (arm64-v8a, x86_64) are on the [Releases](https://github.com/WizzardSK/xemu-libretro/releases) page.

- **Linux:** `xemu_libretro.so` and `libslirp.so.0`; put both into RetroArch's `cores` folder. glibc builds, they do not load into a musl frontend.
- **macOS:** `xemu_libretro.dylib` and the folder `xemu_libretro_libs`; put both into RetroArch's `cores` folder.
- **Windows:** `xemu_libretro.dll`.
- **Android:** `xemu_libretro_android.so`, Android 10 or newer.

## Setup

Put these files into RetroArch's system directory, under `system/xemu/`:

| File | What it is |
|---|---|
| `mcpx_1.0.bin` | the MCPX boot ROM, 512 bytes, MD5 `d49c52a4102f6df7bcf8d0617ac475ed` |
| `Complex_4627v1.03.bin` | the flash BIOS, a 1 MB or 256 KB image |
| `xbox_hdd.qcow2` | the hard disk, for example [xemu's ready-made image](https://github.com/xemu-project/xemu-hdd-image/releases) |

The boot ROM and the BIOS are Microsoft's and have to be dumped from your own console; see xemu's [required files](https://xemu.app/docs/required-files/). Other names and locations can be set in the core options. The EEPROM (`xbox_eeprom.bin`) is created in the same folder when it is missing.

## Content

Xbox games as `.iso` or `.xiso` (xemu's XISO format, as made by extract-xiso).

## Video

The core renders with OpenGL or Vulkan, whichever RetroArch's video driver is (`glcore` or `vulkan`). On Android it is Vulkan only. On macOS it is OpenGL: MoltenVK has no geometry shaders, which xemu's Vulkan renderer needs, so use RetroArch's `glcore` driver there.

## Building

Linux, with upstream's build dependencies installed:

```
git clone https://github.com/WizzardSK/xemu-libretro.git
cd xemu-libretro
./configure --extra-cflags="-DXBOX=1 -Wno-error" --target-list=i386-softmmu \
    -Dlibretro=true -Dpipewire=disabled -Db_staticpic=true
ninja -C build xemu_libretro.so
```

The CI workflow `.github/workflows/libretro.yml` builds every platform, and shows each one's dependencies.

## License

GPL-2.0, as xemu and QEMU. See [LICENSE](LICENSE).
