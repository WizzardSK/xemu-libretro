# Only the files the emulation itself reads; the standalone's UI images and
# fonts are not part of the core (.upstream-excluded).
pfiles = [
  'segaboot_logo.rgba',
  'segaboot_jingle.raw',
  'shader_seeds.bin',
]

libpfile_targets = []

foreach e : pfiles
  t = custom_target('@0@.[ch]'.format(e),
                    output: ['@0@.c'.format(e), '@0@.h'.format(e)],
                    input: files('@0@'.format(e)),
                    command: [packfile, '@INPUT@', '@OUTPUT0@', '@OUTPUT1@'])
  libpfile_targets += t[0]
  genh += t[1]
endforeach

libpfile = static_library('pdata', libpfile_targets,
                          name_suffix: 'fa')
common_ss.add(declare_dependency(link_whole: libpfile))
