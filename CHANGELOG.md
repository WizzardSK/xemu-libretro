# Changelog of the libretro core

What changed in the libretro core of this fork, newest first. Changes that come with a merge of upstream xemu are in upstream's own history; a merge is noted here with the upstream version it brought in.

## Unreleased

- Internal Resolution Scale is Internal Resolution Scale (Restart), taken when the content starts: raised while running above the scale it started with, it made RetroArch rebuild its video context and the core crashed (NNshi).
- New category Controls, after Audio: Rumble (Player 1) and (Player 2), on by default, turn off everything that rumbles that player's pad, the Xbox games' and a Chihiro racing game's force feedback; Analog Dead Zone (Player 1) and (Player 2), 0 to 30%, 10% by default, for both sticks, Xbox and Chihiro alike, with the rest of the travel scaled up to full (OutRun 2 stopped at a drive board error when the stick moved during its test) (NNshi).
- New option Audio > Audio Thread (Restart), off by default: the sound goes to RetroArch's audio thread as the APU mixes it, as standalone plays it, so it keeps going while frames stall, as while shaders compile (NNshi).
- The core carries xemu-dashboard's pre-formatted hard disk (`xbox_hdd.qcow2`, 1.6 MB, MIT: an unsigned dashboard and no Microsoft software) and writes it to `system/xemu/` when there is no HDD, so only the boot ROM and the BIOS have to be supplied (NNshi).
- Options: new defaults, unlike standalone's: Skip Boot Animation on, System Aspect Ratio 16:9, Light Gun Aim Analog Stick, Force Feedback Rumble 100% and Vulkan Fast Paths No Pipeline Libraries (RalliSport Challenge 2 and Conker crash with them). The System category is System (Restart), as its options are taken when the content starts, and its options no longer say (Restart) each; Trim HDD on Close is no longer Experimental and comes last there. Shader Cache (OpenGL) is gone: OpenGL's shader cache is always on, as Vulkan's is (NNshi).
- Options: Display Filtering is gone, it set what only standalone's UI reads (RetroArch's own filtering is what applies). Shader Cache is Shader Cache (OpenGL), as only the OpenGL renderer has it to switch (Vulkan's modules are always kept on disk). System Memory, Network Backend, Skip Boot Animation, Hardware FPU Emulation and AV Pack say (Restart), as they are read when the content starts. New in Audio, with standalone's defaults: DSP JIT (off), HRTF (on) and Voice Processor Threads (Restart, Auto) (NNshi).
- New option Video > System Aspect Ratio (Restart): Dashboard (as before), 4:3, 16:9 or Letterbox, set in the emulated EEPROM's video settings at each start, so a game that supports widescreen runs in it without going to the dashboard; the EEPROM file keeps the dashboard's own setting. Aspect Ratio is now Core Aspect Ratio, after it; its Auto follows the setting (NNshi).
- Aspect Ratio Auto: 16:9 when Widescreen is on in the dashboard's video settings and the game is one that renders 16:9 then, 4:3 otherwise and always on a Chihiro. The core knows the games by their Title ID, from a list of 200 games (226 releases) with 16:9 support; before, Auto waited for the game to switch the AV pack to widescreen, which games hardly do, and stayed at 4:3. The log says which Title ID runs, whether it is on the list and what the dashboard is set to (NNshi).
- New option System > Trim HDD on Close (Experimental), off by default: when the game is closed, the hard disk's cache partitions X, Y and Z are emptied (games format them again when they need them) and the image is rewritten without unused space, so `xbox_hdd.qcow2` shrinks. It needs as much free space as the image's data for a moment, and is skipped while the image holds a savestate, which would keep the space and be lost by the rewrite (NNshi, Akrido).
- The machine is stopped while RetroArch's menu is open or the content is paused, as standalone's Pause does it, once no frame has been asked for 50 ms (about 3 frames), and started again with the next frame: the guest ran on without its vblank meanwhile, and a game could take its disc reads for failed when it came back (Akrido: Ninja Gaiden's dirty disc error after the menu).

## Test build 4 - 2026-10-25

- The core info file names the core "Microsoft - Xbox / Sega Chihiro (xemu)" (NNshi).
- Chihiro: the Chihiro options are in a category of their own, Sega Chihiro, the last one (NNshi).
- Chihiro gun games: new option Sega Chihiro > Light Gun Aim, Mouse or Analog Stick. With the mouse it aims, the left button fires, the right one is the gun's button (House of the Dead III's pump reload, Virtua Cop 3's change weapon, Ghost Squad's action) and the middle one Virtua Cop 3's pedal or Ghost Squad's fire rate, as standalone binds them; RetroArch's light gun still works. With the stick the left stick or D-pad aims, R2 fires, L2 is the gun's button, L the pedal or fire rate and R shoots off the screen. New option Sega Chihiro > Crosshair, on by default: each player's aim drawn over the picture, player 1 red and player 2 blue, where standalone shows the mouse cursor; with one mouse only player 1's (NNshi).
- Vulkan: new option Video > Vulkan Fast Paths (All by default, as standalone), to leave out the pipeline libraries or the dynamic states on a GPU that crashes with one of them (Akrido).
- Vulkan on RetroArch's device: the device is made with the extended dynamic states, vertex input dynamic state, graphics pipeline libraries, host query reset and shader demote where the GPU has them, as standalone's own device is. Without them the renderer's fast paths were off and every new state compiled a whole pipeline while drawing: shader stutters of up to two seconds where standalone barely hitched (NNshi).
- Chihiro: another Chihiro game loads without restarting RetroArch: its image goes into the media board's memory, the last game's backup is written to its save file, and the cabinet, board type, card readers and save file follow the new game. Only a game larger than the media board memory of the first one (Gundam after a 512 MB game) still asks for a restart; an Xbox game after a Chihiro one, or the other way round, too (NNshi).
- Chihiro: new option Sega Chihiro > Force Feedback Rumble, off by default as in standalone, or 25-200%: the drive board's force feedback in OutRun 2 and Maximum Tune rumbles port 1's pad, as standalone gives it to a gamepad (NNshi).
- Vulkan: the picture handed to RetroArch is taken once the game has handled the vblank of that run, which is where it points the display at the frame it just finished. Taken right away, it raced the game: about a quarter of the frames came twice and as many were skipped while the game itself ran at 60 (NNshi: OutRun 2 between 30 and 60 fps, 224 new pictures in 300 runs).
- The log's line every 300 runs has a second one: how many frames the game flipped, when it issued each flip after the vblank it waits for, how long it then waited, and how late the vblank came after RetroArch asked for the frame - for telling a slow game from a late vblank (NNshi: OutRun 2 at about 44 fps where standalone holds 60).
- The core is built on Tovarichtch's xemu fork (main and perf-experimental) in place of mainline xemu: Sega Chihiro emulation (an image that is not an Xbox disc boots a Chihiro), and the fork's tuned guest CPU and NV2A renderer. New options: System > CPU Boost (the fork's native SSE and wider jump cache, on by default) and Video > Smooth First Play (the shaders a game is known to use are compiled while it boots, on by default). The fork's GPU boost is always on in the core: the stock renderer it keeps for it being off has none of the core's frontend handover. The guest's vblank still comes with each retro_run, not from the fork's wall-clock timer, so RetroArch keeps pacing the frames; the fork's Real hardware speed is left off for the same reason (NNshi).
- Chihiro: the cabinet controls are on RetroArch's pads and light guns, per game (README, Chihiro controls), and the Chihiro files are read from `system/xemu/Chihiro/` under MAME's names (NNshi). Chihiro games load as `.bin` netboot images. The machine is built once per RetroArch start, so a Chihiro game after an Xbox one (or the other way round) is refused with a message to restart RetroArch. New option Sega Chihiro > Free Play, on by default (NNshi).
- Reduced Vulkan Buffers is gone: the fork's renderer keeps its inline vertex buffer at 16 MB on every card, smaller than the option's smallest; the depth/stencil conversion buffers still follow the resolution scale.

## Test build 3 - 2026-10-12

- The console's files are also found in `system/` itself, where an older core info file had them, and the BIOS also as `Complex_4627.bin`. `system/xemu/` and `Complex_4627v1.03.bin` stay the documented place and name (boardsofcanada).
- Reduced Vulkan Buffers (Video, on by default): the Vulkan renderer's buffer for inline vertex data is a tenth of xemu's size on every graphics card, as it already was on those with less than 4 GB - about 1.2 GB less video memory and as much less system memory (3.16 to 2.01 GB in NNshi's run, frame times unchanged). Off reserves xemu's size.
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
