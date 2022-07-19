#include <lib/string.h>

size_t strlen(const char* string) {
	size_t len = 0;
	while (string[len]) {
        len++;
    }
	return len;
}

char* itoa(int value) {
    int digits = 0;
    int cpy = value;
    while (cpy / 10 != 0) {
        cpy = cpy / 10;
        digits++;        
    }
    static char str[64];
    digits++;
    str[digits] = '\0';
    cpy = value;
    int i = digits - 1;
    while (i >= 0) {
        str[i] = (cpy % 10) + '0';
        cpy = cpy / 10;
        i--;
    }
    return str;
}