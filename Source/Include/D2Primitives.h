#pragma once
// Bit buffers and file times shared across modules

#include "D2Check.h"
#include "D2Structs.h"

struct D2BitBufferStrc;
struct D2FileTimeStrc;

struct D2BitBufferStrc
{
    unsigned char* pBuffer; // 0x00
    int nBits; // 0x04
    int nPos; // 0x08
    int nPosBits; // 0x0C
    int bFull; // 0x10
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime; // 0x00
    unsigned long dwHighDateTime; // 0x04
};

D2_CHECK_SIZE(D2BitBufferStrc, 0x14);
D2_CHECK_SIZE(D2FileTimeStrc, 0x8);
