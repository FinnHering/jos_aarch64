//
// Created by root on 4/28/25.
//

#include <inc/elf/elf64/elf64.h>
#include <lib/mem.h>

uint8_t elf64_get_header(uint8_t data[64], ELF64_EHDR* hdr) {

    memcpy(hdr, data, 64);

    if (hdr->e_ident[0] != 'E' || hdr->e_ident[1] != 'L' || hdr->e_ident[2] != 'F') {
        return 1;
    }


    return 0;
}


