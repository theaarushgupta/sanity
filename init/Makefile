CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ../include/

../bin/main.o: main.c ../include/kernel/print.h
	$(CC) $(CFLAGS) -c $< -o $@