#ifndef IDT
#define IDT

#include <stdint.h>

typedef struct {
    uint16_t isrLow;
    uint16_t kernelCS;
    uint8_t reserved;
    uint8_t attributes;
    uint16_t isrHigh;
} __attribute((packed)) idtEntry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtr_t;

void initIDT(void);

#endif