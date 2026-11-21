#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgTiles.h"



struct D2DrlgAnimTileGridStrc
{
    D2DrlgTileDataStrc** ppMapTileData;
    int nFrames;
    int nCurrentFrame;
    int nAnimationSpeed;
    D2DrlgAnimTileGridStrc* pNext;
};





extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

#define D2_ASSERTM(expr, msg, line) D2_ASSERT(expr, line)

char* __cdecl sub_00407310_Sprintf(char* szDest, const char* szFormat, ...);                                // 0x00407310

extern "C" const char gszDrlgAnimSourceFile[];                                                              // 0x006EEF08

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0
int __stdcall TileGetRarity(D2TileLibraryEntryStrc* hTile); // 0x00604C20
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType); // 0x0066DC50
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DF40
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

static void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgRoomStrc* pDrlgRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles, D2DrlgGridStrc* pDrlgGrid, int nUnused);
static inline int GetMapTileLayer(unsigned int nMapTileFlags) { return int((nMapTileFlags & 0x1C000) >> 14) - 1; }

// 0x0066D440
static void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgRoomStrc* pDrlgRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles, D2DrlgGridStrc* pDrlgGrid, int nUnused)
{
    (void)nUnused;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    if (!pTiles)
    {
        return;
    }

    if (nAnimationSpeed == 0)
    {
        nAnimationSpeed = 80;
    }

    D2TileLibraryEntryStrc* pTileLibraryEntries[40];

    for (int i = 0; i < nTiles; ++i)
    {
        D2DrlgTileDataStrc& pCurrentTileData = pTiles[i];
        if (pCurrentTileData.pTile && (D2CMP_10079_GetTileFlags(pCurrentTileData.pTile) & 0x100))
        {
            const int nGridIdx = GetMapTileLayer(pCurrentTileData.dwFlags);
            const unsigned int nPackedTileInformation = DRLGGRID_GetGridEntry(&pDrlgGrid[nGridIdx], pCurrentTileData.nPosX, pCurrentTileData.nPosY);
            unsigned char nStyle;
            unsigned char nSeq;
            if (nPackedTileInformation)
            {
                nStyle = (nPackedTileInformation >> 20) & 0x3F;
                nSeq = (unsigned char)(nPackedTileInformation >> 8);
            }
            else
            {
                nStyle = 0;
                nSeq = 0;
            }

            unsigned int nFrames = TileLibraryGetTiles(&pDrlgRoom->pTiles, pCurrentTileData.nTileType, nStyle, nSeq, pTileLibraryEntries, 40);

            D2DrlgAnimTileGridStrc* pDrlgAnimTileGrid = (D2DrlgAnimTileGridStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgAnimTileGridStrc), gszDrlgAnimSourceFile, 155, 0);
            memset(pDrlgAnimTileGrid, 0x00, sizeof(D2DrlgAnimTileGridStrc));
            pDrlgAnimTileGrid->nFrames = nFrames;
            pDrlgAnimTileGrid->nCurrentFrame = 0;
            pDrlgAnimTileGrid->ppMapTileData = (D2DrlgTileDataStrc**)FOG_AllocPool(pMemPool, nFrames * sizeof(D2DrlgTileDataStrc*), gszDrlgAnimSourceFile, 161, 0);
            memset(pDrlgAnimTileGrid->ppMapTileData, 0x00, nFrames * sizeof(D2DrlgTileDataStrc*));
            pDrlgAnimTileGrid->nAnimationSpeed = nAnimationSpeed;
            pDrlgAnimTileGrid->pNext = (D2DrlgAnimTileGridStrc*)pDrlgRoom->ptDrlgTiles->pAnimTiles;
            pDrlgRoom->ptDrlgTiles->pAnimTiles = pDrlgAnimTileGrid;

            unsigned int nEntryIndex;
            for (nEntryIndex = 0; nEntryIndex < nFrames; ++nEntryIndex)
            {
                if (TileGetRarity(pTileLibraryEntries[nEntryIndex]) == 0)
                {
                    break;
                }
            }
            char szBuffer[100] = {};
            D2_ASSERTM(nEntryIndex < nFrames, sub_00407310_Sprintf(szBuffer, "Animating tiles missing Rarity %d Tile - Style %d Seq %d", 0, nStyle, nSeq), 182);

            pCurrentTileData.pTile = pTileLibraryEntries[nEntryIndex];
            pDrlgAnimTileGrid->ppMapTileData[0] = &pCurrentTileData;

            int nX = pDrlgRoom->pDrlgCoord.nPosX + pCurrentTileData.nPosX;
            int nY = pDrlgRoom->pDrlgCoord.nPosY + pCurrentTileData.nPosY;

            for (unsigned int nRarity = 1; nRarity < nFrames; ++nRarity)
            {
                unsigned int nEntry;
                for (nEntry = 0; nEntry < nFrames; ++nEntry)
                {
                    if (TileGetRarity(pTileLibraryEntries[nEntry]) == nRarity)
                    {
                        break;
                    }
                }

                D2_ASSERTM(nEntry < nFrames, sub_00407310_Sprintf(szBuffer, "Animating tiles missing Rarity %d Tile - Style %d Seq %d", nRarity, nStyle, nSeq), 203);

                D2DrlgTileDataStrc* pNewTileData;
                if (pCurrentTileData.nTileType != 0)
                {
                    if (pCurrentTileData.nTileType != 13)
                    {
                        pNewTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry], pCurrentTileData.nTileType);
                    }
                    else
                    {
                        pNewTileData = DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry]);
                    }
                }
                else
                {
                    pNewTileData = DRLGROOMTILE_InitFloorTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry]);
                }

                pDrlgAnimTileGrid->ppMapTileData[nRarity] = pNewTileData;
                pNewTileData->dwFlags |= 8;
            }
        }
    }
}

// 0x0066D700
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgGridStrc* pWallGrid, int nWalls, D2DrlgGridStrc* pFloorGrid, int nFloors, D2DrlgGridStrc* pShadowGrid)
{
    D2DrlgTileGridStrc* pTileGrid = pRoom->ptDrlgTiles;
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pTiles.pWallTiles, pTileGrid->nWalls, pWallGrid, nWalls);
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pFloorTiles, pTileGrid->nFloors, pFloorGrid, nFloors);
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pRoofTiles, pTileGrid->nShadows, pShadowGrid, 1);
}

#include "gen/data/Source/D2Common/DRLG/DrlgAnim.inc"
struct D2TileLibraryEntryStrc;
