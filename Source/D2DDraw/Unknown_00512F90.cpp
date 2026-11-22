#include "D2DDraw.h"
#include "D2GlideTypes.h"
#include "D2DrlgMaps.h"

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0
int __cdecl DDRAW_GetBlendedShadows(); // 0x00512700

// 0x00512F90
int __fastcall sub_00512F90_DrawWallTile(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, void* pLight, int nScreenPanels)
{
    int bDrawn = 0;

    if (D2CMPTileValidate(pTile, 1, 0))
    {
        int nMinX = -32;
        int nMaxX = gnScreenWidth_007C9138;
        int nMaxY = gnScreenHeight_007C913C + 32;

        switch (nScreenPanels)
        {
        case 1:
            nMaxX -= gnScreenWidth_007C9138 / 2;
            break;
        case 2:
            nMinX = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
            const int nX = pBlock->nPosX + nPosX;
            const int nY = pTile->pBlocks[i].nPosY + nPosY;
            if (nX >= nMinX && nX < nMaxX && nY >= -32 && nY < nMaxY)
            {
                bDrawn = 1;
                if (DDRAW_GetBlendedShadows())
                    gpTileDrawFunctions_007C914C->pfDrawShadowBlock(pTile->pBlocks[i].pData, nX, nY, 0xC0);
                else
                    gpTileDrawFunctions_007C914C->pfDrawWallBlock(pTile->pBlocks[i].pData, nX, nY);
            }
        }
    }

    return bDrawn;
}
