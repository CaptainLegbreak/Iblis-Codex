#pragma once
// D2Win: window controls, the font cache and sprite cache nodes.

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelFileStrc;
struct D2CharStrc;
struct D2CmpGfxHashEntryStrc;
struct D2FontStrc;
struct D2WinControlStrc;
struct D2FontCacheStrc;
struct D2SpriteCacheNodeStrc;

struct D2WinControlStrc
{
    int eType; // 0x00
    D2CelFileStrc* pCellFile; // 0x04
    unsigned int dwFlags; // 0x08
    int nImageX; // 0x0C
    int nImageY; // 0x10
    int nWidth; // 0x14
    int nHeight; // 0x18
    int unk0x1C[8]; // 0x1C
    D2WinControlStrc* pNext; // 0x3C
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile; // 0x00
    D2FontStrc* pFontInfo[2]; // 0x04
    D2CharStrc* pCharInfo; // 0x0C
    unsigned int dwShiftedTickCount; // 0x10
};

struct D2SpriteCacheNodeStrc
{
    void* pData; // 0x00
    unsigned int nSize; // 0x04
    D2CmpGfxHashEntryStrc* pRecord; // 0x08
    unsigned int dwFlags; // 0x0C
    unsigned int dwTick; // 0x10
    D2SpriteCacheNodeStrc* pNext; // 0x14
    D2SpriteCacheNodeStrc* pPrev; // 0x18
};

D2_CHECK_SIZE(D2WinControlStrc, 0x40);
D2_CHECK_SIZE(D2FontCacheStrc, 0x14);
D2_CHECK_SIZE(D2SpriteCacheNodeStrc, 0x1C);
