extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szSubTileFile[];                                                                      // 0x006E61F8

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590

// 0x00606E40
void __fastcall sub_00606E40_BlitBlendMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x006072F0
void __fastcall sub_006072F0_BlitDoubleMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pOuter, const unsigned char* pInner)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pOuter[pInner[pSrc[6]]];
        case 6: pDst[5] = pOuter[pInner[pSrc[5]]];
        case 5: pDst[4] = pOuter[pInner[pSrc[4]]];
        case 4: pDst[3] = pOuter[pInner[pSrc[3]]];
        case 3: pDst[2] = pOuter[pInner[pSrc[2]]];
        case 2: pDst[1] = pOuter[pInner[pSrc[1]]];
        case 1: pDst[0] = pOuter[pInner[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pOuter[pInner[pSrc[7]]];
                pDst[6] = pOuter[pInner[pSrc[6]]];
                pDst[5] = pOuter[pInner[pSrc[5]]];
                pDst[4] = pOuter[pInner[pSrc[4]]];
                pDst[3] = pOuter[pInner[pSrc[3]]];
                pDst[2] = pOuter[pInner[pSrc[2]]];
                pDst[1] = pOuter[pInner[pSrc[1]]];
                pDst[0] = pOuter[pInner[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607680
void __fastcall sub_00607680_BlitMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607970
void __fastcall sub_00607970_BlitBlendMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607E20
void __fastcall sub_00607E20_BlitMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00608110
void __fastcall sub_00608110_BlitBlend(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

int gnRemapStart_008E9D48[80];                                                                              // 0x008E9D48
int gnRemapEnd_008E9E88[80];                                                                                // 0x008E9E88
int gnRemapOffsets_008E9FC8[80 * 80];                                                                       // 0x008E9FC8

// 0x00608C00
void __stdcall sub_00608C00_RemapRegion(unsigned char* pBuffer, int nPitch)
{
    unsigned char* pRow = pBuffer;
    int nBase = 0;
    for (int y = 0; y < 40; y++)
    {
        int nIndex = gnRemapStart_008E9D48[y] + nBase;
        unsigned char* p = pRow + gnRemapStart_008E9D48[y];
        unsigned char* pEnd = pRow + (gnRemapEnd_008E9E88[y] < 41 ? gnRemapEnd_008E9E88[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nIndex = gnRemapEnd_008E9E88[y] + nBase;
        p = pRow + gnRemapEnd_008E9E88[y];
        pEnd = pRow + (gnRemapStart_008E9D48[y] >= 40 ? gnRemapStart_008E9D48[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nBase += 80;
        pRow += nPitch;
    }

    pRow = pBuffer + 79 * nPitch;
    nBase = 79 * 80;
    for (int y = 79; y >= 40; y--)
    {
        int nIndex = gnRemapStart_008E9D48[y] + nBase;
        unsigned char* p = pRow + gnRemapStart_008E9D48[y];
        unsigned char* pEnd = pRow + (gnRemapEnd_008E9E88[y] < 41 ? gnRemapEnd_008E9E88[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nIndex = gnRemapEnd_008E9E88[y] + nBase;
        p = pRow + gnRemapEnd_008E9E88[y];
        pEnd = pRow + (gnRemapStart_008E9D48[y] >= 40 ? gnRemapStart_008E9D48[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nBase -= 80;
        pRow -= nPitch;
    }
}

struct D2CmpTileInfoStrc
{
    char data[25];
};

struct D2CmpTileStrc
{
    char unk0x00[0x10];
    int nValue10;
    short nValue14;
    short f_16;
    char unk0x18[0x0C];
    int nValue24;
    int nValue28;
    int nValue2C;
    int nValue30;
    int nOwnerId;
    D2CmpTileInfoStrc tInfo;
    unsigned char nType;
    char unk0x52[0x0A];
    D2CmpTileStrc* pNext;
};

struct D2CmpTileListStrc
{
    int unk0x00;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

D2CmpTileStrc* __cdecl sub_00609550_AllocTile();                                                            // 0x00609550

// 0x006096D0
D2CmpTileStrc* __stdcall sub_006096D0_AddTile(D2CmpTileListStrc* pList, short nValue16, short nValue14, int nValue24, int nValue28, int nValue2C, int nValue30, int nValue10, const D2CmpTileInfoStrc* pInfo)
{
    D2_ASSERT(pList, 0xA2);
    D2CmpTileStrc* pTile = sub_00609550_AllocTile();
    D2_ASSERT(pTile, 0xA6);
    pTile->pNext = pList->pFirst;
    pList->nCount++;
    pList->pFirst = pTile;
    pTile->f_16 = nValue16;
    pTile->nValue14 = nValue14;
    pTile->nValue24 = nValue24;
    pTile->nValue28 = nValue28;
    pTile->nValue2C = nValue2C;
    pTile->nValue30 = nValue30;
    pTile->nValue10 = nValue10;
    pTile->nOwnerId = pList->nId;
    pTile->nType = 2;
    pTile->tInfo = *pInfo;
    return pTile;
}

struct T00604AE0
{
    unsigned int nKey;
    char unk0x04[0x28];
    T00604AE0* pNext;
};

struct D2CelDataHashStrc
{
    int nCheck[0x200];
    T00604AE0* pBuckets[0x200];
};

// 0x0060AEB0
void __fastcall sub_0060AEB0_FreeEntry(D2CelDataHashStrc* pHash, T00604AE0* pEntry, void* pMemPool)
{
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}

// 0x0060AF00
void __fastcall sub_0060AF00_FreeAll(void* pMemPool, D2CelDataHashStrc* pHash)
{
    for (unsigned int i = 0; i < 0x200; i++)
    {
        T00604AE0* pEntry = pHash->pBuckets[i];
        while (pEntry)
        {
            T00604AE0* pNext = pEntry->pNext;
            sub_0060AEB0_FreeEntry(pHash, pEntry, pMemPool);
            pEntry = pNext;
        }
        D2_ASSERT(!pHash->nCheck[i], 0x5B);
    }
}

struct D2CmpBitCursorStrc
{
    int unk0x00;
    int* pData;
    int unk0x08;
    int f_C;

    void sub_0060B1A0_AdvanceBits(int nBits);
};

// 0x0060B1A0
void D2CmpBitCursorStrc::sub_0060B1A0_AdvanceBits(int nBits)
{
    int nPos = f_C + nBits;
    f_C = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060CD70
unsigned char __fastcall sub_0060CD70_WrapIndex(unsigned char a, unsigned char b, unsigned char c)
{
    unsigned char nResult = (unsigned char)(2 * a - c + b) % 128;
    D2_ASSERT(nResult < 128, 0x1E);
    return nResult;
}

// 0x0060D310
int __fastcall sub_0060D310_ScanRun(unsigned char nValue, const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x45);
    int nCount = 0;
    while (pData < pEnd && nValue == *pData && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && nValue == *pData)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

struct D2CmpSubTileBlockStrc
{
    char unk0x00[0x08];
    short nValue08;
    short nSize;
    int unk0x0C;
    unsigned char* pData;
};

// 0x0060D9C0
void __stdcall sub_0060D9C0_BuildDiamondBlock(D2CmpSubTileBlockStrc* pBlock, const unsigned char* pSrc)
{
    unsigned char* pDst = (unsigned char*)FOG_Alloc(0x100, szSubTileFile, 0x185, 0);
    D2_ASSERT(pDst, 0x186);
    unsigned char* pData = pDst;
    memset(pDst, 0, 0x100);
    int i = 0;
    int nOffset = 0xE;
    int nWidth = 4;
    for (; i < 15; i++)
    {
        memcpy(pDst, pSrc + nOffset, nWidth);
        pSrc += 0x20;
        pDst += nWidth;
        if (i < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }
    pBlock->nValue08 = 1;
    pBlock->nSize = 0x100;
    pBlock->pData = pData;
}

struct D2CmpStringStrc
{
    const char* szText;

    int sub_0060DD20_EqualsNoCase(const D2CmpStringStrc* pOther);
};

// 0x0060DD20
int D2CmpStringStrc::sub_0060DD20_EqualsNoCase(const D2CmpStringStrc* pOther)
{
    return !SStrCmpI(szText, pOther->szText, 0x7FFFFFFF);
}

#include "gen/data/Source/D2CMP/00606E40_sub_00606E40_BlitBlendMapped.inc"
