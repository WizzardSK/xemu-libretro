# The JIT runs on mborgerson's dsp56300 library, which comes prebuilt for
# Linux, Windows and macOS; on Android the C interpreter stands in for it
if host_os == 'android'
  dsp56300_emu_ffi = []
  dsp_jit_src = files('dsp_jit_stub.c')
else
  dsp56300_emu_ffi = dependency('dsp56300-emu-ffi', fallback: ['dsp56300', 'dsp56300_dep'])
  dsp_jit_src = files('dsp_jit.c')
endif

subdir('interp')

libdsp = static_library(
  'dsp',
  files(['dsp.c', 'dsp_c.c', 'dsp_dma.c']) + dsp_jit_src + genh,
  dependencies: [dsp56300_emu_ffi],
)

dsp = declare_dependency(
  objects: [
    libdsp.extract_all_objects(recursive: false),
    libdsp_cpu_interp.extract_all_objects(recursive: false),
  ],
  dependencies: [dsp56300_emu_ffi],
)

mcpx_ss.add(dsp, files('gp_ep.c'))
