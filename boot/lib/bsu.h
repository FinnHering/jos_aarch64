//
// Created by root on 5/10/25.
//

#ifndef BOOT_SERVICE_UTILITIES_H
#define BOOT_SERVICE_UTILITIES_H

#include "inc/efi/efi.h"

typedef struct PROTOCOL_HANDLE {
    EFI_GUID* guid;
    EFI_HANDLE* handle;
} PROTOCOL_HANDLE;

EFI_STATUS get_all_protocols(IN EFI_BOOT_SERVICES* boot_services, OUT PROTOCOL_HANDLE** protocols, OUT UINTN* count);


#endif //BOOT_SERVICE_UTILITIES_H
