#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2CmpCache.h"

struct D2CmpBitCursorStrc;
struct D2CmpByteMapStrc;
struct D2CmpByteRunStrc;
struct D2DccFrameStrc;
struct D2DccDirStrc;
struct D2DccIterStrc;
struct D2BitBufferInitStrc;
struct D2SpritePixelsStrc;
struct D2SpriteCelStrc;
struct D2CmpTileFileHeaderStrc;
struct D2CmpTileHeaderTargetStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2BitBufferInitStrc
{
    unsigned char* pBuffer;
    unsigned char* pCurrent;
    int nBits;
    int nPos;
};

struct D2SpritePixelsStrc { int unknown00,width,height; char unknown0C[0x14]; unsigned char* pixels; int pitch; int topDown; };

struct D2SpriteCelStrc { int unknown00[7]; unsigned int dataSize; };

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0

#pragma pack(push, 1)
struct D2CmpTileFileHeaderStrc
{
    unsigned char nType;
    unsigned char nByte1;
    unsigned char nCount;
    int nDword3;
    int nDword7;
    int nUnk0x0B;
};

#pragma pack(pop)
struct D2CmpTileHeaderTargetStrc
{
    unsigned char bFlags;
    char pad0x01[3];
    int nByte1;
    int nDword7;
    int nZero0C;
    int f_10;
    int nCount;
    int nDword3;
    unsigned int adwData[33];
};

int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
int __fastcall sub_004068F0(void* pArg); // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

static int sub_0060B2B0_DccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt);

// 0x0060BF20
int __fastcall sub_0060BF20_LoadTileHeader(const char* szFile, D2CmpTileHeaderTargetStrc* pTarget)
{
    void* hFile;
    sub_004068E0(szFile, &hFile);
    if (!hFile)
    {
        return 0;
    }

    D2CmpTileFileHeaderStrc tHeader;
    int nRead;
    int bLoaded = 0;
    if (sub_00406900(hFile, &tHeader, sizeof(tHeader), &nRead, 0, 0, 0) && nRead == sizeof(tHeader) && tHeader.nType == 't')
    {
        pTarget->nByte1 = tHeader.nByte1;
        pTarget->nDword7 = tHeader.nDword7;
        pTarget->nZero0C = 0;
        pTarget->nCount = tHeader.nCount;
        pTarget->nDword3 = tHeader.nDword3;
        if (tHeader.nCount > 32)
        {
            tHeader.nCount = 32;
        }

        const int nSize = tHeader.nCount * sizeof(unsigned int);
        if (sub_00406900(hFile, pTarget->adwData, nSize, &nRead, 0, 0, 0) && nRead == nSize)
        {
            bLoaded = 1;
        }
    }

    if (!bLoaded)
    {
        sub_004068F0(hFile);
        return 0;
    }

    pTarget->adwData[tHeader.nCount] = sub_00406930(hFile, 0);
    sub_004068F0(hFile);
    pTarget->bFlags |= 2;
    return 1;
}
