BOOT_CFLAGS := $(CFLAGS) -mno-red-zone  \
	-target aarch64-unknown-windows $(INC)

BOOT_LDFLAGS := $(LDFLAGS) -flavor link -subsystem:efi_application -entry:EFI_IMAGE_ENTRY_POINT

BOOT_SRCS := boot/boot.c boot/lib/bsu.c boot/lib/print.c

boot/%.o: boot/%.c
	$(CC) $(BOOT_CFLAGS) -c $< -o $@

boot/lib/%.o: boot/lib/%.c
	$(CC) $(BOOT_CFLAGS) -c $< -o $@

boot/bootAARCH64.efi: boot/boot.o boot/lib/bsu.o boot/lib/print.o
	$(LD) $(BOOT_LDFLAGS) $^ -out:$@

boot_clean:
	rm -f boot/bootAARCH64.efi boot/*.o boot/*.d

boot_all: boot/bootAARCH64.efi

