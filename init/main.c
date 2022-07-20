#include <kernel/print.h>

#include <kernel/gdt.h>
#include <kernel/idt.h>

void init(void) {
	initGDT();
	initIDT();
	initTerminal();
}

void main(void) {
	init();
	print("welcome to sanity!\nWOW IM ON ANOTHER LINE :o\n");
	print("this is a number: ");
	print(itoa(123));
	print("\ntime to raise an interrupt!");
	asm volatile ("int $0x3");
}