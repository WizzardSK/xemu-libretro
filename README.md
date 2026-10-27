# xemu libretro core

A [libretro](https://www.libretro.com/) core of [xemu](https://xemu.app), the original Xbox emulator, for RetroArch and other libretro frontends.

The emulator is upstream's: this repository follows [xemu-project/xemu](https://github.com/xemu-project/xemu) and adds the libretro frontend in `ui/libretro.c`. It holds the core only; upstream's standalone UI, packaging and CI are not part of it (the paths are listed in `.upstream-excluded`). The version the core reports is upstream's, with the upstream commit it is merged to (`upstream.version`). The core is currently on xemu 0.8.136-53, commit 478b4f4961 of 28 September 2026.

## Downloads

The core is built by libretro's buildbot for Windows and Linux (x86_64, aarch64), and is installed from RetroArch: Online Updater > Core Downloader. Every push to the `libretro` branch is also built in [Actions](https://github.com/WizzardSK/xemu-libretro/actions/workflows/libretro.yml), macOS (Apple Silicon, Intel) and Android (arm64-v8a, x86_64) included; the builds are the artifacts of a run, and downloading them needs a GitHub login.

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
| `xbox_hdd.qcow2` | optional: the hard disk. Without one the core writes the ready-made image it carries, [xemu-dashboard](https://github.com/xemu-project/xemu-dashboard)'s (MIT, an unsigned dashboard and no Microsoft software), the same one xemu offers |

The boot ROM and the BIOS are Microsoft's and have to be dumped from your own console; see xemu's [required files](https://xemu.app/docs/required-files/). Other names and locations can be set in the core options. The EEPROM (`xbox_eeprom.bin`) is created in the same folder when it is missing.

For Sega Chihiro games, these files go under `system/xemu/Chihiro/` (MAME's names; the boot ROM above is needed too, and the hard disk is written as for an Xbox):

| File | What it is |
|---|---|
| `chihiro_xbox_bios.bin` | the Chihiro BIOS, 512 KB |
| `fpr21042_m29w160et.bin` | the media board's flash, 2 MB |
| `ic10_g24lc64.bin`, `pc20_g24lc64.bin`, `ic11_24lc024.bin` | the EEPROMs of the I/O boards and the baseboard |
| `ver1305.bin` | optional: the network board's firmware, for linked cabinets |

## Content

Xbox games as `.iso` or `.xiso` (xemu's XISO format, as made by extract-xiso). Sega Chihiro games as `.bin` netboot images, as made by [Chihiro-netboot](https://github.com/Tovarichtch/chihiro-netboot): an image that is not an Xbox disc boots a Chihiro. The machine is built once per RetroArch start: to play a Chihiro game after an Xbox one, or the other way round, restart RetroArch. Another Chihiro game loads into the same machine, unless it is larger than the media board memory the first one was given (Gundam needs 1024 MB, the others fit 512 MB): then restart RetroArch. Chihiro games start in free play (Sega Chihiro > Free Play); with it off, Select inserts a coin.

## Chihiro controls

The cabinet's controls are on RetroArch's pads, by the game:

| | |
|---|---|
| Every game | Start = Start, Select = coin, L3 = service, R3 = test; player 2's Start and Select on port 2 |
| Gun games (House of the Dead III, Virtua Cop 3, Ghost Squad) | Sega Chihiro > Light Gun Aim on Analog Stick (the default): aim with the left stick or D-pad; trigger = R2, the gun's button = L2, pedal or fire rate = L, off the screen = R. On Mouse: aim with the mouse (or RetroArch's light gun) on the player's port; trigger = left button (gun trigger), the gun's button - House of the Dead III's pump reload, Virtua Cop 3's change weapon, Ghost Squad's action - = right button (gun Aux A), Virtua Cop 3's pedal and Ghost Squad's fire rate = middle button (gun Aux B), off the screen = gun Reload. Ghost Squad's card = X. Each player's aim is drawn over the picture, player 1 red and player 2 blue (Sega Chihiro > Crosshair) |
| Driving games (Crazy Taxi, OutRun 2, Maximum Tune) | steer = left stick or D-pad, gas = R2, brake = L2; OutRun 2: R/L = shift up/down, Y = view; Crazy Taxi: R = drive, L = reverse, B = jump; Maximum Tune: R/L = shift up/down, Y = view, A = intrude, X = card |
| Ollie King | swing = left stick or D-pad left/right, board front/rear = up/down, L/R = grabs |
| Gundam | left stick or D-pad = left stick, L2/L = its trigger/button; right stick = right stick, R2/R = its trigger/button; B = pedal, X = card |

The driving games' force feedback (OutRun 2, Maximum Tune) can rumble port 1's pad: Sega Chihiro > Force Feedback Rumble, at 100% by default (off in standalone), from 25 to 200% or off. A pad gives the knocks and vibrations; the wheel's centering and weight have nothing to act on. Controls > Rumble (Player 1) and (Player 2) turn a player's rumble off altogether, and Controls > Analog Dead Zone sets how far each player's sticks can move before the game sees it (10% by default).

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
