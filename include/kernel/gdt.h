#ifndef GDT
#define GDT

#include <stdint.h>

typedef struct {
    uint16_t limitLow;
    uint16_t baseLow;
    uint8_t baseMiddle;
    uint8_t access;
    uint8_t granularity;
    uint8_t baseHigh;
} __attribute__((packed)) gdtEntry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdtr_t;

void initGDT(void);

#endif