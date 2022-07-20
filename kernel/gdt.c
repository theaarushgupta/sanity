#include <kernel/gdt.h>

extern void gdtFlush(uint32_t);

gdtEntry_t entries[5];
gdtr_t ptr;

static void entry(
    int32_t num,
    uint32_t base,
    uint32_t limit,
    uint8_t access,
    uint8_t gran
) {
   entries[num].baseLow = (base & 0xFFFF);
   entries[num].baseMiddle = (base >> 16) & 0xFF;
   entries[num].baseHigh = (base >> 24) & 0xFF;
   entries[num].limitLow = (limit & 0xFFFF);
   entries[num].granularity = (limit >> 16) & 0x0F;
   entries[num].granularity |= gran & 0xF0;
   entries[num].access = access;
}

void initGDT(void) {
    ptr.limit = (sizeof(gdtEntry_t) * 5) - 1;
    ptr.base = (uint32_t)&entries;
    entry(0, 0, 0, 0, 0);
    entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
    gdtFlush((uint32_t)&ptr);
}