#include "Storm.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"
#include "D2DrlgMaps.h"

struct D2CoordPairStrc;
struct D2TileLightStrc;

struct D2CoordPairStrc
{
    int nX;
    int nY;
};
extern unsigned char* gpSurfaceBits_007C9154; // 0x007C9154

struct D2TileLightStrc
{
    int nCorner[4];
};

int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0
extern int gnScreenHeight_007C913C; // 0x007C913C

// 0x006C8DA0
void __fastcall sub_006C8DA0_DrawLine(D2CoordPairStrc* pFrom, D2CoordPairStrc* pTo, unsigned char nColor)
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

    while (!(nY >= 0 && nY < gnSurfaceHeight_007C913C && nX >= 0 && nX < gnSurfaceWidth_007C9138))
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

    unsigned char* pPixel = gpSurfaceBits_007C9154 + nY * gnSurfaceWidth_007C9138 + nX;
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

        if (nX < 0 || nX >= gnSurfaceWidth_007C9138)
            return;

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nStep = nFracY / 0x10000;
            nY += nStep;
            pPixel += nStep * gnSurfaceWidth_007C9138;
            nFracY -= nStep * 0x10000;
        }

        if (nY < 0 || nY >= gnSurfaceHeight_007C913C)
            return;

        *pPixel = nColor;
    }
}

// 0x006C93A0
int __fastcall sub_006C93A0_DrawLitTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf, int nArg)
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

// 0x006C94B0
int __fastcall sub_006C94B0_DrawTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf)
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
