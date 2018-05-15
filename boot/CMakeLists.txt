add_custom_command(OUTPUT image.iso
	COMMAND mkdir -p isodir/boot/grub
	COMMAND cp $<TARGET_FILE:kernel.bin> isodir/boot
	COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/grub.cfg isodir/boot/grub
	COMMAND grub-mkrescue -o image.iso isodir
	COMMAND rm -Rf isodir
	DEPENDS kernel.bin grub.cfg
	VERBATIM)
add_custom_target("iso" ALL DEPENDS image.iso SOURCES grub.cfg)
