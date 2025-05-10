//
// Created by root on 4/28/25.
//

#ifndef ELF64_H
#define ELF64_H

#include <stdint.h>


/**
 * Parses ELF64 header from memory.
 * @param data Pointer to beginning of ELF64 data in memory
 * @return parsed ELF64 header
 */
ELF64_H elf64_get_header(uint8_t data[64]);

#endif //ELF64_H
