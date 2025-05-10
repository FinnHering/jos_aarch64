//
// Created by root on 4/28/25.
//

#include <stdint.h>

void *memcpy(void *dest, const void * src, uint64_t n) {
    uint8_t* _dest = dest;
    const uint8_t* _src = src;


    for (uint64_t i = 0; i < n; i++) {
        _dest[i] = _src[i];
    }


    return dest;
}