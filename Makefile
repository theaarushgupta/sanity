CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I include/

AS = i686-elf-as
ASFLAGS =

LD = i686-elf-gcc
LDFLAGS = -ffreestanding -O2 -nostdlib

QEMU = qemu-system-i386

DEPS = bin/start.o

all: compile link checks image

bin:
	mkdir -p bin/

clean:
	rm -rf bin/

test: bin/sanity.bin
	$(QEMU) -cdrom bin/sanity.bin

compile: bin $(DEPS)

bin/start.o: boot/start.asm
	$(AS) $(ASFLAGS) -o bin/start.o $^

link: $(DEPS)
	$(LD) -T link.ld -o bin/kernel.bin $(LDFLAGS) $^ -lgcc

checks: bin/kernel.bin
	grub-file --is-x86-multiboot bin/kernel.bin

image: bin/kernel.bin
	mkdir -p bin/iso/boot/grub
	cp bin/kernel.bin bin/iso/boot/kernel.bin
	cp grub.cfg bin/iso/boot/grub/grub.cfg
	grub-mkrescue -o bin/sanity.bin bin/iso