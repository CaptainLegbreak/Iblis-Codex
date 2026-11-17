extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
};

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCelFile;
    char unk0x38[0x04];
    D2CelStrc* pCel;
    unsigned int nDirection;
};

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);
extern CELDRAWFN gpfnCelDraw[];                                                                             // 0x006E3688

struct D2FindTileNodeStrc
{
    void* pTile;
    D2FindTileNodeStrc* pNext;
};

struct D2FindTileEntryStrc
{
    int nKey2;
    int nKey3;
    int nKey1;
    D2FindTileNodeStrc* pTileList;
    D2FindTileEntryStrc* pNext;
};

unsigned char __fastcall sub_0060CD70_WrapIndex(int a, int b, int c);                                       // 0x0060CD70

// 0x006014C0
void __stdcall sub_006014C0(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->nVersion == 6, 0x452);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x453);
    }

    D2_ASSERT(pBuffer, 0x456);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x459);

    nY += pCel->nYOffset;
    nX += pCel->nXOffset;
    int nRows = pCel->nHeight;
    int nSkipRows = 0;
    if (nY - nRows < 0)
    {
        nRows = nY + 1;
    }

    if (nRows <= 0)
    {
        return;
    }

    if (nY >= nHeight)
    {
        nSkipRows = nY - nHeight + 1;
        nRows -= nSkipRows;
        if (nRows <= 0)
        {
            return;
        }
        nY = nHeight - 1;
    }

    if (!nArg4 && !nArg5)
    {
        if (nX < 0 || nY < 0)
        {
            return;
        }
    }

    unsigned char* pDst = pBuffer + nY * nPitch + nX;
    int nFormat = 0;
    if (pCelFile)
    {
        nFormat = pCelFile->nFormat;
    }

    CELDRAWFN pfnDraw = gpfnCelDraw[nFormat];
    D2_ASSERT(pfnDraw, 0x481);
    pfnDraw(pCel, pDst, nX, nArg4, nArg5, nPitch, nSkipRows, nRows, nArg9, nArg10, nArg11);
}

// 0x0060D040
int __fastcall sub_0060D040(D2FindTileEntryStrc** ppTable, void** ppResults, unsigned int nMax, int nKey1, int nKey2, int nKey3)
{
    int bFound = 0;
    int nCount = 0;
    D2_ASSERT(ppTable, 0xCF);
    D2_ASSERT(ppResults, 0xD0);
    if (!nMax)
    {
        return 0;
    }

    D2FindTileEntryStrc* pEntry = ppTable[sub_0060CD70_WrapIndex(nKey3, nKey2, nKey1)];
    while (pEntry && !bFound)
    {
        if (pEntry->nKey3 == nKey3 && pEntry->nKey2 == nKey2 && pEntry->nKey1 == nKey1)
            bFound = 1;
        else
            pEntry = pEntry->pNext;
    }

    if (bFound)
    {
        unsigned int i = 0;
        for (D2FindTileNodeStrc* pNode = pEntry->pTileList; pNode && i < nMax; pNode = pNode->pNext)
        {
            ppResults[i] = pNode->pTile;
            nCount += 1;
            i += 1;
        }
    }

    return nCount;
}

#include "gen/data/Source/D2CMP/006014C0_sub_006014C0.inc"
