//
// Created by root on 4/16/25.
//

#include <stddef.h>
#include <inc/efi/efi.h>
#include <lib/elf64.c>



void kernel_main(EFI_MEMORY_DESCRIPTOR *memMap, UINTN memMapSize, EFI_RUNTIME_SERVICES *rs) {
    rs->ResetSystem(
        EfiResetCold,
        EFI_SUCCESS,
        0,
        NULL
    );
}
