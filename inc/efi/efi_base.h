//
// Created by Finn Hering on 16.04.25.
//

#ifndef EFI_BASE_H
#define EFI_BASE_H

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifndef CONST
#define CONST
#endif

#ifndef EFIAPI
#define EFIAPI
#endif

#define EFI_FALSE (0 == 1)
#define EFI_TRUE (1 == 1)


#include <stdint.h>


#define EFI_SUCCESS 0
#define EFI_WARN_MASK 0
#define EFI_WARN_PIAS_MASK (0x2 << (EFI_WORD_SIZE - 4))
#define EFI_WARN_OEM_MASK (0x4 << (EFI_WORD_SIZE - 4))
#define EFI_ERR_MASK (0x8 << (EFI_WORD_SIZE - 4))
#define EFI_ERR_PIAS_MASK (0xa << (EFI_WORD_SIZE - 4))
#define EFI_ERR_OEM_MASK (0xc << (EFI_WORD_SIZE - 4))

#define EFI_LOAD_ERROR 1
#define EFI_INVALID_PARAMETER 2
#define EFI_UNSUPPORTED 3
#define EFI_BAD_BUFFER_SIZE 4
#define EFI_BUFFER_TOO_SMALL 5
#define EFI_NOT_READY 6
#define EFI_DEVICE_ERROR 7
#define EFI_WRITE_PROTECTED 8
#define EFI_OUT_OF_RESOURCES 9
#define EFI_VOLUME_CORRUPTED 10
#define EFI_VOLUME_FULL 11
#define EFI_NO_MEDIA 12
#define EFI_MEDIA_CHANGED 13
#define EFI_NOT_FOUND 14
#define EFI_ACCESS_DENIED 15
#define EFI_NO_RESPONSE 16
#define EFI_NO_MAPPING 17
#define EFI_TIMEOUT 18
#define EFI_NOT_STARTED 19
#define EFI_ALREADY_STARTED 20
#define EFI_ABORTED 21
#define EFI_ICMP_ERROR 22
#define EFI_TFTP_ERROR 23
#define EFI_PROTOCOL_ERROR 24
#define EFI_INCOMPATIBLE_VERSION 25
#define EFI_SECURITY_VIOLATION 26
#define EFI_CRC_ERROR 27
#define EFI_END_OF_MEDIA 28
#define EFI_END_OF_FILE 31
#define EFI_INVALID_LANGUAGE 32
#define EFI_COMPROMISED_DATA 33
#define EFI_IP_ADDRESS_CONFLICT 34
#define EFI_HTTP_ERROR 35

#define EFI_WARN_UNKNOWN_GLYPH 1
#define EFI_WARN_DELETE_FAILURE 2
#define EFI_WARN_WRITE_FAILURE 3
#define EFI_WARN_BUFFER_TOO_SMALL 4
#define EFI_WARN_STALE_DATA 5
#define EFI_WARN_FILE_SYSTEM 6
#define EFI_WARN_RESET_REQUIRED 7

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

typedef struct EFI_GUID {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

typedef UINTN EFI_STATUS;

typedef VOID *EFI_HANDLE;

typedef VOID *EFI_EVENT;

typedef UINT64 EFI_LBA;


//32byte buffer = 256bits = 2*128bits
typedef UINT8 EFI_MAC_ADDRESS[32];

typedef UINT32 EFI_IPV4_ADDRESS;
typedef UINT128 EFI_IPV6_ADDRESS;

typedef union {
    UINT32 Addr[4];
    EFI_IPV4_ADDRESS v4;
    EFI_IPV6_ADDRESS v6;
} EFI_IP_ADDRESS;


// System Table structures (chapter 4)

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION  ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION  ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION  ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION  ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION  ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION  ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION  ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION  ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION  ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION  ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION  ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION  ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION  ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION       EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION       EFI_2_100_SYSTEM_TABLE_REVISION


// Text input protocol


typedef struct {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;


#endif //EFI_BASE_H
