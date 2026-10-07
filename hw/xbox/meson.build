specific_ss.add(files(
	'acpi_xbox.c',
	'amd_smbus.c',
	# 'chihiro-usb.c',
	# 'chihiro.c',
	'eeprom_generation.c',
	'lpc47m157.c',
	'smbus_adm1032.c',
	'smbus_cx25871.c',
	'smbus_fs454.c',
	'smbus_xcalibur.c',
	'smbus_storage.c',
	'smbus_xbox_smc.c',
	'xbox.c',
	'xbox_pci.c',
	'xid.c',
	'xid-gamepad.c',
	))
# The Xbox Live Communicator plays and records through SDL, which the libretro
# core is built without
if not get_option('libretro')
	specific_ss.add(files('xblc.c'))
endif
subdir('nv2a')
subdir('mcpx')
