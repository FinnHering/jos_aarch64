//
// Created by Finn Hering on 16.04.25.
//

#ifndef EFI_H
#define EFI_H

#include <stdint.h>

// 1. define the primitives (See 2.3.1, Table 2.3)
typedef uint8_t BOOLEAN;

typedef int8_t INT8;
typedef uint8_t UINT8;

typedef int16_t INT16;
typedef uint16_t UINT16;

typedef int32_t INT32;
typedef uint32_t UINT32;

typedef int64_t INT64;
typedef uint64_t UINT64;

typedef struct INT128 {
    int64_t lo;
    int64_t hi;
} INT128;
typedef INT128 UINT128;

// In AARCH64 the "default" int is 64-Bit
typedef INT64 INTN;
typedef UINT64 UINTN;

typedef UINT8 CHAR8;
typedef UINT16 CHAR16;

typedef void VOID;

typedef UINT128 EFI_GUID;
typedef UINTN EFI_STATUS;



#endif //EFI_H
