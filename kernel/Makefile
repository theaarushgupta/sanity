CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ../include/

../bin/print.o: print.c ../include/kernel/print.h
	$(CC) $(CFLAGS) -c $< -o $@