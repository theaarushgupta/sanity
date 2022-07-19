#ifndef PRINT
#define PRINT

#include <stddef.h>
#include <stdint.h>

enum color {
	VGABLACK = 0,
	VGABLUE = 1,
	VGAGREEN = 2,
	VGACYAN = 3,
	VGARED = 4,
	VGAMAGENTA = 5,
	VGABROWN = 6,
	VGALIGHTGREY = 7,
	VGADARKGREY = 8,
	VGALIGHTBLUE = 9,
	VGALIGHTGREEN = 10,
	VGALIGHTCYAN = 11,
	VGALIGHTRED = 12,
	VGALIGHTMAGENTA = 13,
	VGALIGHTBROWN = 14,
	VGAWHITE = 15
};

static const size_t WIDTH = 80;
static const size_t HEIGHT = 25;

void initTerminal(void);
void print(const char* string);

#endif