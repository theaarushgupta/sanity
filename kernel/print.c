#include <kernel/print.h>

#include <lib/string.h>

size_t ROW;
size_t COLUMN;
uint8_t COLOR;
uint16_t* BUFFER;

static inline uint16_t entry(unsigned char c, uint8_t color) {
    return (uint16_t)c | (uint16_t)color << 8;
}

void initTerminal(void) {
    ROW = 0;
    COLUMN = 0;
    COLOR = VGALIGHTGREY | VGABLACK << 4;
    BUFFER = (uint16_t*)0xB8000;
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            const size_t index = y * WIDTH + x;
            BUFFER[index] = entry(' ', COLOR);
        }
    }
}

void print(const char* string) {
    for (size_t i = 0; i < strlen(string); i++) {
        const size_t index = ROW * WIDTH + COLUMN;
        BUFFER[index] = entry(string[i], COLOR);
        if (++COLUMN == WIDTH) {
            COLUMN = 0;
            if (++ROW == HEIGHT) {
                ROW = 0;
            }
        }
    }
}