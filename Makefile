LD = i686-elf-gcc
LDFLAGS = -ffreestanding -O2 -nostdlib

QEMU = qemu-system-i386

OBJS = bin/start.o

.PHONY: bin/kernel.bin clean test

bin/kernel.bin:
	$(MAKE) -C boot
	$(LD) -T link.ld -o bin/kernel.bin $(LDFLAGS) $(OBJS) -lgcc

bin/sanity.bin: bin/kernel.bin
	grub-file --is-x86-multiboot $<
	mkdir -p bin/iso/boot/grub
	cp $< bin/iso/boot/kernel.bin
	cp grub.cfg bin/iso/boot/grub/grub.cfg
	grub-mkrescue -o $@ bin/iso

clean:
	rm -rf bin/
	mkdir bin

test: bin/sanity.bin
	$(QEMU) -cdrom $<