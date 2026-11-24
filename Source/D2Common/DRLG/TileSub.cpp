#include "D2Common.h"
#include "D2DrlgMaps.h"
#include "D2TxtTables.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);              // 0x0067C590
void __fastcall DRLGGRID_FillNewCellFlags(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth); // 0x0067CCC0

// 0x006704E0
void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord)
{
    D2DrlgFileStrc** ppDrlgFile = &pLvlSubTxtRecord->pDrlgFile;
    if (!pLvlSubTxtRecord->pDrlgFile)
    {
        DRLGPRESET_LoadDrlgFile(ppDrlgFile, hArchive, pLvlSubTxtRecord->szFile);

        const int nWidth = (*ppDrlgFile)->nWidth + 1;
        const int nHeight = (*ppDrlgFile)->nHeight + 1;
        D2DrlgCoordStrc pDrlgCoord;
        pDrlgCoord.nPosX = 0;
        pDrlgCoord.nPosY = 0;
        pDrlgCoord.nWidth = nWidth;
        pDrlgCoord.nHeight = nHeight;

        D2_ASSERT((*ppDrlgFile)->nSubstGroups, 694);

        for (int i = 0; i < (*ppDrlgFile)->nWallLayers; ++i)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pWallGrid[i], (int*)(*ppDrlgFile)->pWallLayer[i], &pDrlgCoord, nWidth);
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pTileTypeGrid[i], (int*)pLvlSubTxtRecord->pDrlgFile->pTileTypeLayer[i], &pDrlgCoord, nWidth);
        }

        for (int i = 1; i < (*ppDrlgFile)->nWallLayers; ++i)
        {
            DRLGGRID_AlterAllGridFlags(&pLvlSubTxtRecord->pWallGrid[i], i << 18, 0);
        }

        if ((*ppDrlgFile)->nFloorLayers)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pFloorGrid, (int*)(*ppDrlgFile)->pFloorLayer[0], &pDrlgCoord, nWidth);
        }

        if ((*ppDrlgFile)->pShadowLayer)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pShadowGrid, (int*)(*ppDrlgFile)->pShadowLayer, &pDrlgCoord, nWidth);
        }
    }
}
