#include <kernel/print.h>

#include <kernel/gdt.h>

void init(void) {
	initGDT();
	initTerminal();
}

void main(void) {
	init();
	print("welcome to sanity!\nWOW IM ON ANOTHER LINE :o");
}