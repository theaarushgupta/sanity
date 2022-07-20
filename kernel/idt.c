#include <kernel/idt.h>

#include <stdbool.h>

extern void* isrStubTable[];

__attribute__((aligned(0x10)))
static idtEntry_t entries[256];
static idtr_t ptr;

static bool vectors[256];

__attribute__((noreturn))
void errorHandler(void) {
    __asm__ volatile("cli; hlt");
}

void entry(uint8_t num, void* isr, uint8_t flags) {
    entries[num].isrLow = (uint32_t)isr & 0xFFFF;
    entries[num].kernelCS = 0x08;
    entries[num].attributes = flags;
    entries[num].isrHigh = (uint32_t)isr >> 16;
    entries[num].reserved = 0;
}

void initIDT(void) {
    ptr.base = (uintptr_t)&entries[0];
    ptr.limit = (uint16_t)sizeof(idtEntry_t) * 256 - 1;
    for (uint8_t num = 0; num < 32; num++) {
        entry(num, isrStubTable[num], 0x8E);
        vectors[num] = true;
    }
    __asm__ volatile("lidt %0" : : "m"(ptr));
    __asm__ volatile("sti");
}