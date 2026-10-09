# Instructions for Autonomous Agents & AI Assistants

This file provides mandatory instructions and guidelines for autonomous AI agents, coding assistants, and models contributing code or creating pull requests for the xemu project.

---

## 1. Strict Adherence to Project Standards

All contributions must strictly comply with the guidelines defined in [CONTRIBUTING.md](CONTRIBUTING.md).

---

## 2. Mandatory Agent Declarations

When submitting code or opening a pull request generated with or assisted by an agent:

1. **PR Description Declaration**:
   - The pull request description **must** include an explicit declaration stating which AI agent and model were used to generate or assist with the change.
   - Example:
     ```markdown
     > **Agent Declaration**: This pull request was created with assistance from [Agent Name / Model Name].
     ```

---

## 3. Scoping & Granularity Guidelines

To produce high-quality, easily reviewable pull requests, agents must observe the following constraints:

- **Single Responsibility**: Each pull request must address exactly one bug fix, hardware improvement, or specific feature. Never bundle multiple independent bug fixes, features, or cleanups into a single commit or pull request. Break independent changes into separate, logically sequenced PRs.
- **Minimal Change**: Touch only the files and lines necessary to accomplish the stated task. Do not refactor surrounding functions or reorganize include headers unless explicitly requested.
- **Verify Against Upstream**: Always ensure the branch is rebased on the latest upstream `master` and that changes do not stomp on or duplicate existing open PRs.

---

## 4. Verification & Testing

- **Compilation**: Verify that all modified files compile without warnings or errors.
- **Emulation Accuracy**: Do not hallucinate register definitions, bitfields, or hardware behaviors. Cross-reference existing implementations under `hw/xbox/` or verified hardware documentation.
- **Test Coverage & Parity**: Whenever altering hardware emulation (NV2A, APU/DSP, MCPX, memory controller, etc.), provide or suggest a test XBE that can be run on both bare-metal Xbox hardware and xemu to validate behavior.

---

## 5. Agent Pre-Submission Checklist

Before finalizing any commit or pull request, ensure:
- [ ] Commit message uses `<subsystem>: <short description>` followed by a detailed explanatory body.
- [ ] `clang-format` is applied to new files, and existing code style is respected.
- [ ] No unrelated formatting or refactoring changes are included.
- [ ] The pull request description includes the agent/model declaration.
- [ ] Existing open pull requests have been searched to avoid duplicating work.

---

## Libretro pitfalls already hit in the other cores

Each of these was a bug in at least one of the cemu, rpcs3, vita3k or xenia cores. Check new code against them before asking testers.

- Audio: each retro_run hands the frontend exactly one frame's worth (sample rate / declared fps), never "whatever is queued". The game's audio thread waits once about 64 ms is queued; no bigger buffer on the core's side. Several streams (audio ports, clients, a music player) are mixed, not appended one after another, and each is taken in its own format and sample rate.
- Geometry: the size the frame is handed over at goes to the frontend: base geometry at load, SET_GEOMETRY when it changes, SET_SYSTEM_AV_INFO when it would exceed the max. The max has to cover the highest internal resolution.
- Pacing: the guest's vblank follows retro_run, and the core declares the guest's refresh rate; the frontend paces display and audio, the core does not sleep to pace itself.
- Files: everything the core writes goes under system/<core>/ (or saves/); nothing next to the RetroArch executable. The emulator's own log goes there too, and its warnings and errors also go to RetroArch's log.
- No window: the standalone's UI (on-screen keyboard, notifications, message boxes, profile dialogs) has no window in a core. Every path that reaches for the window or its UI thread needs a headless branch that answers the way the user most likely would.
- Unload: never end the process (no exit, no TerminateTitle-style shutdown). Stop and join every thread in upstream's order, and never wait without a timeout on a fence, event or thread the frontend has to drive. No vkQueueWaitIdle/vkDeviceWaitIdle while RetroArch holds its queue lock.
- Libraries that pin themselves (statically linked OpenSSL) keep the core loaded after dlclose; build them so they do not.
- No downloads at run time; data files ship with the core.
