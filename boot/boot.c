//
// Created by Finn Hering on 16.04.25.
//

#include <stddef.h>

#include "inc/efi/efi.h"
#include "lib/bsu.h"
#include "lib/print.h"

EFI_STATUS EFI_IMAGE_ENTRY_POINT(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable
) {
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World from Bootloader\n\r");
    SystemTable->BootServices->Stall(10000000);

    PROTOCOL_HANDLE* protocols;
    UINTN protocol_count;

    EFI_STATUS status = get_all_protocols(SystemTable->BootServices, &protocols, &protocol_count);

    CHAR16 status_txt[2] = {status, L'\0'};

    SystemTable->ConOut->OutputString(SystemTable->ConOut, status);

    int_to_dec_str(10);


    return EFI_SUCCESS;
}
