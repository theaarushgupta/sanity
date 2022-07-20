CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ../include/

AS = i686-elf-as
ASFLAGS =

all: ../bin/print.o ../bin/gdtasm.o ../bin/gdtc.o

../bin/print.o: print.c ../include/kernel/print.h
	$(CC) $(CFLAGS) -c $< -o $@

../bin/gdtc.o: gdt.c ../include/kernel/gdt.h
	$(CC) $(CFLAGS) -c $< -o $@

../bin/gdtasm.o: gdt.asm
	$(AS) $(ASFLAGS) -o $@ $^