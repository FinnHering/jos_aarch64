//
// Created by root on 5/10/25.
//

#include "bsu.h"

#include <stddef.h>


EFI_STATUS append(EFI_BOOT_SERVICES *boot_services, void **buffer, const void *val, UINTN val_size, UINTN buffer_size) {
    char *new_buffer;
    const EFI_STATUS s = boot_services->AllocatePool(EfiConventionalMemory, val_size * (buffer_size + 1),
                                                     (void **) &new_buffer);

    if (s != EFI_SUCCESS) return s;

    char *old_buffer = *buffer;

    for (int i = 0; i < val_size * buffer_size; i++) {
        new_buffer[i] = old_buffer[i];
    }

    const char *_val = val;
    for (int i = 0; i < val_size; i++) {
        new_buffer[buffer_size * val_size] = _val[i];
    }

    const EFI_STATUS dealloc_s = boot_services->FreePool(old_buffer);

    if (dealloc_s != EFI_SUCCESS) {
        *buffer = NULL;
        boot_services->FreePool(new_buffer);
        return dealloc_s;
    }

    *buffer = new_buffer;

    return EFI_SUCCESS;
}


EFI_STATUS get_all_protocols(IN EFI_BOOT_SERVICES *boot_services, OUT PROTOCOL_HANDLE **protocols, OUT UINTN *count) {
    // status variable used throughout this function
    EFI_STATUS status = EFI_SUCCESS;

    // Obtain all handles
    EFI_HANDLE *efi_handles = NULL;
    UINTN efi_handle_count = 0;
    status = boot_services->LocateHandleBuffer(
        AllHandles, // Look for all handles
        NULL, // Protocol to search for (we want all handles, so dont specify any)
        NULL, // Search criteria (doesnt matter for "AllHandles")
        &efi_handle_count, // Amount of handles returned
        &efi_handles
    );
    if (status != EFI_SUCCESS) return status;

    PROTOCOL_HANDLE *buff = NULL;
    UINTN buff_size = 0;


    for (int i = 0; i < efi_handle_count; i++) {
        EFI_GUID **guids = NULL;
        UINTN guid_count = 0;

        status = boot_services->ProtocolsPerHandle(efi_handles[i], &guids, &guid_count);

        if (status != EFI_SUCCESS) {
            goto handle_exception;
        }

        for (int j = 0; j < guid_count; j++) {
            PROTOCOL_HANDLE p = {
                guids[j],
                efi_handles[i]
            };

            status = append(boot_services, (void**)&buff, &p, sizeof p, buff_size);
            if (status != EFI_SUCCESS) {
                goto handle_exception;
            }

            buff_size++;

        }

        continue;

        handle_exception:
        {
            *protocols = NULL;
            *count = 0;

            if (guids != NULL) boot_services->FreePool(guids);

            return status;
        }


    }

    *protocols = buff;
    *count = buff_size;


    return EFI_SUCCESS;

}
