nv2a_vsh_cpu_opts = cmake.subproject_options()
nv2a_vsh_cpu_opts.add_cmake_defines({
  'CMAKE_OSX_ARCHITECTURES': cmake_macos_arch,
  'nv2a_vsh_cpu_UNIT_TEST': 'OFF',
  })
# In a Linux libretro core, a shared library, this goes in position independent
if get_option('libretro') and host_os != 'windows'
  nv2a_vsh_cpu_opts.add_cmake_defines({'CMAKE_POSITION_INDEPENDENT_CODE': 'ON'})
  nv2a_vsh_cpu_opts.set_override_option('b_staticpic', 'true')
endif
nv2a_vsh_cpu_subproj = cmake.subproject('nv2a_vsh_cpu', options: nv2a_vsh_cpu_opts)
nv2a_vsh_cpu = declare_dependency(include_directories: nv2a_vsh_cpu_subproj.include_directories('nv2a_vsh_emulator'),
                                  link_with: [
                                    nv2a_vsh_cpu_subproj.target('nv2a_vsh_emulator'),
                                    nv2a_vsh_cpu_subproj.target('nv2a_vsh_cpu'),
                                    nv2a_vsh_cpu_subproj.target('nv2a_vsh_disassembler'),
                                    ])

if host_os == 'android'
  # Vulkan only there: no GL renderer for gloffscreen to serve
  libgloffscreen = static_library('libgloffscreen', sources: files('gloffscreen/common.c'))
elif get_option('libretro')
  libgloffscreen = static_library('libgloffscreen',
                            sources: files('gloffscreen/common.c', 'gloffscreen/gloffscreen_libretro.c'),
                            c_args: ['-DLIBRETRO=1'],
                            # CGL on macOS; EGL and GLX through epoxy on the
                            # other non-Windows hosts, X11 for the GLX config
                            # query
                            dependencies: host_os == 'windows' ? [] :
                              host_os == 'darwin' ? [epoxy, opengl] :
                              [epoxy, dependency('x11', required: true)])
else
  libgloffscreen = static_library('libgloffscreen',
                            sources: files('gloffscreen/common.c', 'gloffscreen/sdl.c'),
                            dependencies: sdl)
endif
gloffscreen = declare_dependency(link_with: libgloffscreen,
                           include_directories: ['gloffscreen'])
