CC := clang
LD := lld

CFLAGS := -ffreestanding -MMD -mno-red-zone -std=c99 \
	-target x86_64-unknown-windows

LDFLAGS := -flavor link -subsystem:efi_application -entry:efi_main

SRCS := boot/boot.c

boot/%.o: boot/%.c
	$(CC) $(CFLAGS) -c $< -o $@

boot/bootAARCH64.efi: boot/boot.o
	$(LD) $(LDFLAGS) $< -out:$@

clean:
	rm boot/bootAARCH64.efi boot/*.o boot/*.d

all: boot/bootAARCH64.efi