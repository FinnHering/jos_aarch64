
KERNEL_CFLAGS := $(CFLAGS) \
	-target aarch64-none-elf $(INC)

KERNEL_LDFLAGS := $(LDFLAGS) -flavor gnu -entry=kernel_main -T kernel/kernel.ld

KERNEL_SRCS := kernel/kernel.c

kernel/%.o: kernel/%.c
	$(CC) $(KERNEL_CFLAGS) -c $< -o $@

kernel_clean:
	rm -f kernel/kernel.elf kernel/*.o kernel/*.d

kernel/kernel.elf: kernel/kernel.o
	$(LD) $(KERNEL_LDFLAGS) -o $@ $<

kernel_all: kernel/kernel.elf

