#include "D2Common.h"

struct D2DrlgCoordStrc { int nPosX; int nPosY; int nWidth; int nHeight; };
struct D2DrlgGridStrc { int* pCellsFlags; int* pCellsRowOffsets; int nWidth; int nHeight; int unk0x10; };
struct D2DrlgFileStrc
{
    char unk0x00[0x0C];
    int nWidth;
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    void* pFloorLayer[2];
    void* pShadowLayer;
    char unk0x48[0x04];
    int nSubstGroups;
};
struct D2LvlSubTxt
{
    char unk0x00[0x04];
    char szFile[0x4C];
    D2DrlgFileStrc* pDrlgFile;
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pFloorGrid;
    D2DrlgGridStrc pShadowGrid;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
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
