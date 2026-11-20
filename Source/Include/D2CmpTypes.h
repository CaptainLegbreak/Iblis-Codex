#pragma once
// D2CMP sprite, DC6, tile library and COF layouts

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelFileStrc;
struct D2CelStrc;
struct D2CmpDC6CelStrc;
struct D2CmpTileNodeStrc;
struct D2CofDataStrc;
struct D2SpriteCacheNodeStrc;
struct AsyncData;
struct D2CmpSpriteContextStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CmpTileBlockStrc;
struct D2CmpSpriteEntryStrc;
struct D2CmpDC6FrameStrc;
struct D2CmpSpriteFileStrc;
struct D2CmpLoadDescStrc;
struct D2CmpDC6HeaderStrc;
struct D2CmpTileLibraryStrc;
struct D2CmpTileStrc;
struct D2CmpSubTileRecordStrc;
struct D2CmpCelContextStrc;
struct D2CmpBitCursorStrc;
struct D2CofNodeStrc;
struct D2CofInfoStrc;

struct D2CmpSpriteContextStrc
{
    int nFrame; // 0x00
    unsigned int dwFlags; // 0x04
    int nType; // 0x08
    int nIndex; // 0x0C
    int nMode; // 0x10
    int nOverlay; // 0x14
    char szToken[4]; // 0x18
    char szComponent[4]; // 0x1C
    char szArmorType[4]; // 0x20
    char szMode[4]; // 0x24
    char szHitClass[4]; // 0x28
    const char* pName; // 0x2C
    int nFrames; // 0x30
    void* pCel; // 0x34
    int unk0x38; // 0x38
    void* pFrame; // 0x3C
    int nDirection; // 0x40
    unsigned int dwGfxFlags; // 0x44
};

struct D2CmpGfxHashEntryStrc
{
    unsigned int nIndex; // 0x00
    int nSub; // 0x04
    int nKey1; // 0x08
    int nKey2; // 0x0C
    int nKey3; // 0x10
    int nKey4; // 0x14
    int nKey5; // 0x18
    unsigned int nValue; // 0x1C
    int nArg; // 0x20
    D2SpriteCacheNodeStrc* pHolder; // 0x24
    D2CmpGfxHashEntryStrc* pPrev; // 0x28
    D2CmpGfxHashEntryStrc* pNext; // 0x2C
};

struct D2CmpTileBlockStrc
{
    int nValue10; // 0x00
    short nValue14; // 0x04
    unsigned short unk0x06; // 0x06
    int nHeight; // 0x08
    int nWidth; // 0x0C
    int unk0x10; // 0x10
    int nValue24; // 0x14
    int nValue28; // 0x18
    int nValue2C; // 0x1C
    int nValue30; // 0x20
    int unk0x24[8]; // 0x24
    unsigned short unk0x44; // 0x44
    unsigned char nFlags; // 0x46
    unsigned char unk0x47; // 0x47
    int unk0x48; // 0x48
    int nSubBytes; // 0x4C
    int nSubs; // 0x50
    D2CmpSubTileRecordStrc* pSubs; // 0x54
    char* pName; // 0x58
    void* pExtra; // 0x5C
};

struct D2CmpSpriteEntryStrc
{
    int nType; // 0x00
    int nArg04; // 0x04
    int nArg08; // 0x08
    int nArg0C; // 0x0C
    int nArg10; // 0x10
    int nArg14; // 0x14
    int nArg18; // 0x18
    int nArg1C; // 0x1C
    unsigned char nFlags; // 0x20
    unsigned char nFrames; // 0x21
    unsigned char nFirstFrame; // 0x22
    unsigned char nDirections; // 0x23
    unsigned char nFramesPerDirection; // 0x24
    unsigned char unk0x25; // 0x25
    unsigned short unk0x26; // 0x26
    int unk0x28; // 0x28
    int aOffsets[33]; // 0x2C
    AsyncData* pAsync; // 0xB0
    D2SpriteCacheNodeStrc* pHolder; // 0xB4
};

struct D2CmpDC6FrameStrc
{
    int unk0x00; // 0x00
    unsigned int nWidth; // 0x04
    unsigned int nHeight; // 0x08
    int nOffsetX; // 0x0C
    int nOffsetY_10; // 0x10
    int nOffsetY_14; // 0x14
    D2CmpDC6CelStrc* pCel; // 0x18
    int nLength; // 0x1C
    unsigned char pPixels[4]; // 0x20
};

struct D2CmpSpriteFileStrc
{
    unsigned int dwFlags; // 0x00
    int unk0x04[4]; // 0x04
    int nDirections; // 0x14
    int nFramesPerDirection; // 0x18
    unsigned int aOffsets[1]; // 0x1C
};

struct D2CmpLoadDescStrc
{
    void* pfnCallback; // 0x00
    D2CmpSpriteFileStrc* pFile; // 0x04
    unsigned char* pFlags; // 0x08
    int nFirstFrame; // 0x0C
    int nFrames; // 0x10
    int unk0x14[2]; // 0x14
};

struct D2CmpDC6HeaderStrc
{
    unsigned char nFlags; // 0x00
    unsigned char unk0x01; // 0x01
    unsigned char unk0x02; // 0x02
    unsigned char nDirections; // 0x03
    unsigned char nFrames; // 0x04
    unsigned char unk0x05; // 0x05
    unsigned short unk0x06; // 0x06
    int bFramesReady; // 0x08
    int aOffsets[1]; // 0x0C
    int unk0x10[2]; // 0x10
    D2CmpDC6FrameStrc* pFrames[1]; // 0x18
    int unk0x1C[29]; // 0x1C
    AsyncData* pAsync; // 0x90
};

struct D2CmpTileLibraryStrc
{
    int dwVersion; // 0x00
    unsigned int dwFlags; // 0x04
    char szName[260]; // 0x08
    int nBlocks; // 0x10C
    D2CmpTileBlockStrc* pBlocks; // 0x110
};

struct D2CmpTileStrc
{
    int nMinX; // 0x00
    int nMaxY; // 0x04
    int nMaxX; // 0x08
    int nMinY; // 0x0C
    int nValue10; // 0x10
    short nValue14; // 0x14
    unsigned short unk0x16; // 0x16
    int unk0x18[3]; // 0x18
    int nValue24; // 0x24
    int nValue28; // 0x28
    int nValue2C; // 0x2C
    int nValue30; // 0x30
    int nOwnerId; // 0x34
    int unk0x38[6]; // 0x38
    unsigned char unk0x50; // 0x50
    unsigned char nType; // 0x51
    unsigned short unk0x52; // 0x52
    int nCount; // 0x54
    D2CmpTileNodeStrc* pNodes; // 0x58
    D2CmpTileStrc* pNext; // 0x5C
};

struct D2CmpSubTileRecordStrc
{
    int unk0x00[2]; // 0x00
    unsigned short unk0x08; // 0x08
    unsigned short nLength; // 0x0A
    int unk0x0C; // 0x0C
    unsigned char* ptData; // 0x10
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame; // 0x00
    int unk0x04[12]; // 0x04
    D2CelFileStrc* pCelFile; // 0x34
    int unk0x38; // 0x38
    D2CelStrc* pCel; // 0x3C
    unsigned int nDirection; // 0x40
};

struct D2CmpBitCursorStrc
{
    unsigned int* pStart; // 0x00
    unsigned int* pData; // 0x04
    int nBits; // 0x08
    int nBitPos; // 0x0C
};

struct D2CofNodeStrc
{
    int nRefCount; // 0x00
    unsigned int nMode; // 0x04
    unsigned int nClass; // 0x08
    unsigned int dwWeaponClass; // 0x0C
    unsigned int dwCofSize; // 0x10
    D2CofDataStrc* pCofData; // 0x14
    D2CofNodeStrc* pNext; // 0x18
    D2CofNodeStrc* pPrev; // 0x1C
};

struct D2CofInfoStrc
{
    D2CofNodeStrc* pCofNode; // 0x00
    D2CofInfoStrc* pNext; // 0x04
};

D2_CHECK_SIZE(D2CmpSpriteContextStrc, 0x48);
D2_CHECK_SIZE(D2CmpGfxHashEntryStrc, 0x30);
D2_CHECK_SIZE(D2CmpTileBlockStrc, 0x60);
D2_CHECK_SIZE(D2CmpSpriteEntryStrc, 0xB8);
D2_CHECK_SIZE(D2CmpDC6FrameStrc, 0x24);
D2_CHECK_SIZE(D2CmpSpriteFileStrc, 0x20);
D2_CHECK_SIZE(D2CmpLoadDescStrc, 0x1C);
D2_CHECK_SIZE(D2CmpDC6HeaderStrc, 0x94);
D2_CHECK_SIZE(D2CmpTileLibraryStrc, 0x114);
D2_CHECK_SIZE(D2CmpTileStrc, 0x60);
D2_CHECK_SIZE(D2CmpSubTileRecordStrc, 0x14);
D2_CHECK_SIZE(D2CmpCelContextStrc, 0x44);
D2_CHECK_SIZE(D2CmpBitCursorStrc, 0x10);
D2_CHECK_SIZE(D2CofNodeStrc, 0x20);
D2_CHECK_SIZE(D2CofInfoStrc, 0x8);
