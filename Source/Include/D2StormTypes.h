#pragma once
// Storm: memory manager heaps and blocks, error reports and other shared records.

#include "D2Check.h"
#include "D2Structs.h"

struct D2SMemBlockSigStrc;
struct D2SMemBlockStrc;
struct D2SMemLargeHeaderStrc;
struct D2SMemHeapStrc;
struct D2ErrorReportStrc;

typedef void (__stdcall* D2ErrorCallback)(D2ErrorReportStrc*);

struct D2SMemBlockSigStrc
{
    unsigned short wHeapHigh; // 0x00
    unsigned short wMagic; // 0x02
};

struct D2SMemBlockStrc
{
    unsigned short wSize; // 0x00
    unsigned char nPadding; // 0x02
    unsigned char nFlags; // 0x03
    union
    {
        D2SMemBlockSigStrc tSig; // 0x04
        D2SMemBlockStrc* pNextFree; // 0x04
    };
};

struct D2SMemLargeHeaderStrc
{
    unsigned int nSize; // 0x00
    D2SMemBlockStrc* pBlock; // 0x04
    D2SMemBlockStrc tBlock; // 0x08
};

struct D2SMemHeapStrc
{
    D2SMemHeapStrc* pNext; // 0x00
    unsigned int dwId; // 0x04
    int nLockIndex; // 0x08
    D2SMemBlockSigStrc tSig; // 0x0C
    int bReportLeak; // 0x10
    int nBlocks; // 0x14
    unsigned int nUsedBytes; // 0x18
    D2SMemBlockStrc* pFirst; // 0x1C
    D2SMemBlockStrc* pEnd; // 0x20
    unsigned int nFragments; // 0x24
    unsigned int nPageSize; // 0x28
    unsigned int nCommitted; // 0x2C
    unsigned int nReserved; // 0x30
    unsigned int nLargeBytes; // 0x34
    D2SMemBlockStrc* apFree[9]; // 0x38
    int nLine; // 0x5C
    char szFile[4]; // 0x60
};

struct D2ErrorReportStrc
{
    unsigned int error; // 0x00
    const char* context; // 0x04
    const char* message; // 0x08
    D2ErrorCallback callback; // 0x0C
};

D2_CHECK_SIZE(D2SMemBlockSigStrc, 0x4);
D2_CHECK_SIZE(D2SMemBlockStrc, 0x8);
D2_CHECK_SIZE(D2SMemLargeHeaderStrc, 0x10);
D2_CHECK_SIZE(D2SMemHeapStrc, 0x64);
D2_CHECK_SIZE(D2ErrorReportStrc, 0x10);
