CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I ../include/

../bin/string.o: string.c ../include/lib/string.h
	$(CC) $(CFLAGS) -c $< -o $@