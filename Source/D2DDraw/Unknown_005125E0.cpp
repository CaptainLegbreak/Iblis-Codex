#include "D2DDraw.h"
#include "D2DDrawTypes.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"
#include "D2DrlgMaps.h"

struct D2CoordPairStrc;
struct D2TileLightStrc;

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern int gaDDrawDebugFontGlyphOffsets_008812A8[96]; // 0x008812A8
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC
extern int gaDDrawDebugFontCharWidths_00881428[96]; // 0x00881428

struct D2CoordPairStrc
{
    int nX;
    int nY;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881280; // 0x00881280

struct D2TileLightStrc
{
    int nCorner[4];
};

int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0

int gaDDrawDebugFontCharWidths_00881428[96]; // 0x00881428

// 0x005125E0
static int __stdcall sub_005125E0_SoftDebugDrawChar(int nY, int nX, char ch)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaDDrawDebugFontCharWidths_00881428[ch];

    const unsigned char n = ch - 0x20;
    if (n <= 0x5F)
    {
        const unsigned char* pBits = gpDDrawDebugFontGlyphs_008815AC + gaDDrawDebugFontGlyphOffsets_008812A8[(char)n];
        unsigned char* pDst = gpScreenBuffer_007C9154 + gnScreenWidth_007C9138 * nY + nX;
        for (int nRow = 16; nRow; --nRow)
        {
            for (int nCol = 8; nCol; --nCol)
            {
                if (*pBits++)
                    *pDst = 0xFF;
                ++pDst;
            }
            pDst += gnScreenWidth_007C9138 - 8;
        }
        return gaDDrawDebugFontCharWidths_00881428[(char)n];
    }

    return gaDDrawDebugFontCharWidths_00881428[0];
}

// 0x00512680
void __fastcall sub_00512680_SoftDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    for (int i = 0; i < nLength; ++i)
    {
        nX += sub_005125E0_SoftDebugDrawChar(nY, nX, szText[i]);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 0x0C;
        }
    }
}

// 0x00512A50
void __fastcall sub_00512A50_DrawLine(D2CoordPairStrc* pFrom, D2CoordPairStrc* pTo, unsigned char nColor)
{
    const int nStartX = pTo->nX;
    const int nStartY = pTo->nY;
    int nDeltaX = pFrom->nX - nStartX;
    int nDeltaY = pFrom->nY - nStartY;
    if (!nDeltaX && !nDeltaY)
        return;

    const int nLengthSq = nDeltaX * nDeltaX + nDeltaY * nDeltaY;
    int nLength = 0;
    while (nLength * nLength < nLengthSq)
        ++nLength;

    const int nStepX = (nDeltaX << 16) / nLength;
    const int nStepY = (nDeltaY << 16) / nLength;
    int nFracX = 0;
    int nX = nStartX;
    int nFracY = 0;
    int nY = nStartY;
    int i = 0;

    while (!(nY >= 0 && nY < gnScreenHeight_007C913C && nX >= 0 && nX < gnScreenWidth_007C9138))
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nStep = nFracX / 0x10000;
            nX += nStep;
            nFracX -= nStep * 0x10000;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nStep = nFracY / 0x10000;
            nY += nStep;
            nFracY -= nStep * 0x10000;
        }

        if (i >= nLength)
            return;
        ++i;
    }

    unsigned char* pPixel = gpScreenBuffer_007C9154 + nY * gnScreenWidth_007C9138 + nX;
    *pPixel = nColor;

    for (++i; i < nLength; ++i)
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nStep = nFracX / 0x10000;
            nX += nStep;
            pPixel += nStep;
            nFracX -= nStep * 0x10000;
        }

        if (nX < 0 || nX >= gnScreenWidth_007C9138)
            return;

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nStep = nFracY / 0x10000;
            nY += nStep;
            pPixel += nStep * gnScreenWidth_007C9138;
            nFracY -= nStep * 0x10000;
        }

        if (nY < 0 || nY >= gnScreenHeight_007C913C)
            return;

        *pPixel = nColor;
    }
}

// 0x00512ED0
void __fastcall sub_00512ED0_ClearScreen(int bPartial)
{
    D2DDBltFxStrc tBltFx = { sizeof(D2DDBltFxStrc) };
    tBltFx.dwFillColor = 0;

    if (gpDDrawSurface_00881280)
    {
        long nResult = gpDDrawSurface_00881280->lpVtbl->Blt(gpDDrawSurface_00881280, 0, 0, 0, 0x400, &tBltFx);
        if (nResult)
        {
            if (nResult == 0x887601AE)
            {
                if (bPartial)
                {
                    memset(gpScreenBuffer_007C9154, 0, gnScreenWidth_007C9138 * (gnScreenHeight_007C913C - 47));
                }
                else
                {
                    memset(gpScreenBuffer_007C9154, 0, gnScreenWidth_007C9138 * gnScreenHeight_007C913C);
                }
            }
            else
            {
                sub_005103B0("Blit (screen clear) failed!", nResult);
            }
        }
    }
}

// 0x005130A0
int __fastcall sub_005130A0_DrawLitTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf, int nArg)
{
    int bResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
        int nLeft = -32;
        int nRight = gnScreenWidth_007C9138;
        const int nBottom = gnScreenHeight_007C913C + 32;
        switch (nHalf)
        {
        case 1:
            nRight -= gnScreenWidth_007C9138 / 2;
            break;
        case 2:
            nLeft = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            const int nPosX = pTile->pBlocks[i].nPosX + nX;
            const int nPosY = pTile->pBlocks[i].nPosY + nY;
            if (nPosX >= nLeft && nPosX < nRight && nPosY >= -32 && nPosY < nBottom)
            {
                const int nIndex = pTile->pBlocks[i].nPosX >> 5;
                D2GlideTileStrc* pBlock = i + pTile->pBlocks;
                D2TileLightStrc tLight;
                bResult = 1;
                tLight.nCorner[0] = pLight[4 * nIndex];
                tLight.nCorner[3] = pLight[4 * nIndex];
                tLight.nCorner[1] = pLight[4 * nIndex + 4];
                tLight.nCorner[2] = pLight[4 * nIndex + 4];
                gpTileDrawFunctions_007C914C->pfDrawLitBlock(pBlock->pData, nPosX, nPosY, &tLight, nArg);
            }
        }
    }

    return bResult;
}

// 0x005131B0
int __fastcall sub_005131B0_DrawTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf)
{
    int bResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
        int nLeft = -32;
        int nRight = gnScreenWidth_007C9138;
        const int nBottom = gnScreenHeight_007C913C + 32;
        switch (nHalf)
        {
        case 1:
            nRight -= gnScreenWidth_007C9138 / 2;
            break;
        case 2:
            nLeft = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            const int nPosX = pTile->pBlocks[i].nPosX + nX;
            const int nPosY = pTile->pBlocks[i].nPosY + nY;
            if (nPosX >= nLeft && nPosX < nRight && nPosY >= -32 && nPosY < nBottom)
            {
                const int nIndex = pTile->pBlocks[i].nPosX >> 5;
                D2GlideTileStrc* pBlock = i + pTile->pBlocks;
                D2TileLightStrc tLight;
                tLight.nCorner[3] = tLight.nCorner[0] = pLight[4 * nIndex];
                tLight.nCorner[2] = tLight.nCorner[1] = pLight[4 * nIndex + 4];
                bResult = 1;
                gpTileDrawFunctions_007C914C->pfDrawBlock(pBlock->pData, nPosX, nPosY, &tLight);
            }
        }
    }

    return bResult;
}
