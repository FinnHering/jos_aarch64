CC := clang
LD := lld
TOP = .
INC += -I. -I/inc/ -I/inc/efi/

LDFLAGS :=
CFLAGS := -ffreestanding -MMD -std=c99
CFLAGS += $(INC)

-include boot/boot.mk
-include kernel/kernel.mk

qemu-nox:
	qemu-system-aarch64 \
	  -drive if=none,format=raw,id=code,file=./rundir/code.fd,readonly=on \
	  -drive if=none,format=raw,id=vars,file=./rundir/vars.fd \
	  -net none \
	  -cpu max \
	  -machine virt,pflash0=code,pflash1=vars \
	  -drive format=raw,file=fat:rw:./rundir/ \
	  -device qemu-xhci \
	  -device usb-kbd \
	  -device virtio-gpu-pci \
	  -vga std \
	  -no-reboot

all: boot_all kernel_all
clean: boot_clean kernel_clean