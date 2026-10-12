# Changelog of the libretro core

What changed in the libretro core of this fork, newest first. Changes that come with a merge of upstream xemu are in upstream's own history; a merge is noted here with the upstream version it brought in.

## Unreleased

- Linux: the core no longer links libX11, so it loads where X11 is absent. The one Xlib function the OpenGL renderer's GLX path called is found at run time, in the frontend's own libX11.
- Every 300 runs the core logs where a run's time went on the shared Vulkan device: how often it ran, how many of the pictures were another frame of the game's, and the time spent waiting for the renderer and in RetroArch's video and audio callbacks.
- A recipe for the libretro buildbot (`.gitlab-ci.yml`): Linux x64, Linux aarch64 and Windows x64, built by the scripts in `.ci/`; the Linux core there has libslirp linked in, as the buildbot ships one file. QEMU's own GitLab CI files are removed. A GitHub workflow replays the jobs in the same images.
- Vulkan on RetroArch's own device: the renderer draws on the device RetroArch makes with the core and each frame is handed over as an image, with no copy between two devices. The core's and RetroArch's frame times are no longer disconnected, and scrolling that was choppy on Vulkan is smooth (tested by NNshi).
- Graphics API option (Video): Vulkan by default, OpenGL as the fallback. Android always uses Vulkan, macOS always OpenGL.
- Aspect Ratio option (Video): Auto, 4:3 or 16:9. Auto follows the console's aspect line, as standalone does; 16:9 is for a game that renders widescreen but is shown squashed.
- Audio paces the core: RetroArch gets one frame of audio per run, and the sound chip waits once about 64 ms is queued.
- Rumble through RetroArch's rumble interface.
- Internal Resolution Scale works on OpenGL: the frame is handed over at the size it was rendered at. The largest picture RetroArch is told to expect follows the scale, so its shader passes are not sized for a resolution that is not in use.
- Closing content stops the emulated console and flushes its disk. Before, the console ran on and was cut off mid-write when RetroArch exited, which could break the hard disk image.
- Another game can be loaded without restarting RetroArch, on Vulkan: the emulated console stays built when content is closed, and the next game puts its disc in the drive, resets the console and starts it again (six games in a row without a crash, tested by NNshi). On OpenGL a second game is still refused with a message. Core options that need a restart, such as the memory size and Graphics API, keep the first game's values until RetroArch is restarted.
- Start Core without content boots the dashboard with an empty tray.
- The core's version names upstream's version and commit and this repository's.
- Vulkan starts on Linux and on GPUs with little memory: the surfaceless EGL display is made in a way libepoxy accepts, and the compute and vertex buffers are sized for the surface scale and the memory there is.
- CI uploads the Linux core unstripped as its own artifact, for profiling and backtraces.
- The core option texts can be translated through libretro's Crowdin project: the options header is on the standard template, with the `intl/` scripts and the upload and sync workflows. All texts are English until the first sync.
- Closing content or RetroArch no longer crashes. The core stays loaded once it has been loaded: QEMU's RCU, vCPU and nv2a threads, which upstream never joins, and its exit handlers ran on code that was no longer there once RetroArch unloaded the core.
- Redump ISOs load. A whole-disc image is attached from its game partition's offset (XGD1, XGD2 or XGD3), found by the XDVDFS volume descriptor; before, the guest was shown the disc's video partition.
- Disc images through the frontend's VFS: a `saf://` or `content://` path, as Android's Play Store RetroArch hands over, is read through RetroArch's VFS, Redump offset included.
- The core logs at start which commit of this repository it was built from.
- The core info file, matching the core, is in every build's zip.

## Test build 2 - 2026-10-07

- Merged up to upstream xemu 0.8.136-53 (478b4f4961), with its changes since February, among them the new DSP with a JIT for the audio processor; on Android, which upstream's prebuilt DSP library does not cover, the core uses the C interpreter. The core reports upstream's version.
- macOS cores, Apple Silicon and Intel. The renderer there is OpenGL, through contexts shared with RetroArch's: MoltenVK has no geometry shaders, which xemu's Vulkan renderer needs.
- The repository holds the core only: the standalone app's UI, packaging and CI are removed (`.upstream-excluded`), and the core is built without SDL. The Xbox Live Communicator headset is not emulated, as it needs SDL audio.
- Linux: the cores load again. The bundled libpcap needed RDMA and D-Bus libraries most systems lack; the core's networking is NAT or off, so the build is without libpcap and carries only libslirp.
- README for the core.

## Test build 1 - 2026-10-05

- The first builds of the core from CI: Windows x86_64, Linux x86_64 and aarch64 (glibc, with libslirp next to the core), Android arm64-v8a and x86_64 (Vulkan only, with build fixes from X-OG Mobile).
- The core needs `mcpx_1.0.bin`, `Complex_4627v1.03.bin` and `xbox_hdd.qcow2` in `system/xemu/`, and stops with a message naming the file that is missing.

## February 2026

- libretro support, by danprice142: the original port this fork builds on.
