#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
typedef int BOOL;

struct D2DrlgStrc;






struct D2DrlgOutRectStrc
{
    int nX;
    int nY;
    int unk0x08;
    unsigned char nFlags;
    char pad0x0D[3];
    D2DrlgOutRectStrc* pBounds;
};

#define M303_OFFSET_CHECK(name, type, field, offset) typedef char name[((unsigned int)&((type*)0)->field == (offset)) ? 1 : -1]
M303_OFFSET_CHECK(M303_check_pOutdoors, D2DrlgLevelStrc, pOutdoors, 0x14);
M303_OFFSET_CHECK(M303_check_pLevelCoords, D2DrlgLevelStrc, pLevelCoords, 0x1C);
M303_OFFSET_CHECK(M303_check_pDrlg, D2DrlgLevelStrc, pDrlg, 0x1B4);
M303_OFFSET_CHECK(M303_check_pSeed, D2DrlgLevelStrc, pSeed, 0x1C4);
M303_OFFSET_CHECK(M303_check_nLevelId, D2DrlgLevelStrc, eLevelId, 0x1D0);
M303_OFFSET_CHECK(M303_check_nGridWidth, D2DrlgOutdoorInfoStrc, nGridWidth, 0x5C);
M303_OFFSET_CHECK(M303_check_nGridHeight, D2DrlgOutdoorInfoStrc, nGridHeight, 0x60);
M303_OFFSET_CHECK(M303_check_pVertex, D2DrlgOutdoorInfoStrc, pVertex, 0x64);
M303_OFFSET_CHECK(M303_check_nDirection, D2DrlgVertexStrc, nDirection, 0x08);
M303_OFFSET_CHECK(M303_check_nFlags, D2DrlgVertexStrc, dwFlags, 0x0C);
M303_OFFSET_CHECK(M303_check_pNext, D2DrlgVertexStrc, pNext, 0x10);
M303_OFFSET_CHECK(M303_check_pBounds, D2DrlgOutRectStrc, pBounds, 0x10);

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);       // 0x00674920
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel);                                   // 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                  // 0x00675770
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                           // 0x00675850
void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel);                                   // 0x00681420
void __stdcall sub_00680200_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel);                               // 0x00680200
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6); // 0x006744F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570
void __stdcall sub_0067FE90_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn);                             // 0x0067FE90

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static inline unsigned int SEED_RollRandomNumber_Wild(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

int DRLGOUTWILD_TestSpawnRiver(int nX, D2DrlgLevelStrc* pLevel); // 0x0067FC70
// 0x0067FFB0
static inline int sub_0067FFB0_IsRectAdjacent(D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther)
{
    D2DrlgOutRectStrc* pBounds = pRect->pBounds;
    if (pRect->nX < pBounds->nX && pOther->nY > pRect->nY && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    if (pRect->nY > pBounds->nY && pOther->nX > pRect->nX && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    return 0;
}

// 0x0067FFF0
static inline BOOL sub_0067FFF0_IsSpecialVertex(D2DrlgVertexStrc* pDrlgVertex)
{
    D2DrlgVertexStrc* pNext = pDrlgVertex->pNext;

    if (pDrlgVertex->nPosX < pDrlgVertex->pNext->nPosX && pNext->nPosY < pNext->pNext->nPosY && !(pDrlgVertex->dwFlags & 1) && !(pNext->dwFlags & 1))
    {
        return 1;
    }

    if (pDrlgVertex->nPosY > pDrlgVertex->pNext->nPosY && pNext->nPosX < pNext->pNext->nPosX && !(pDrlgVertex->dwFlags & 1) && !(pNext->dwFlags & 1))
    {
        return 1;
    }

    return 0;
}

// 0x00680040
static inline BOOL DRLGOUTWILD_IsVertexBlocking(D2DrlgVertexStrc* pDrlgVertex)
{
    D2DrlgVertexStrc* pNext = pDrlgVertex->pNext;

    if (pDrlgVertex->nPosY < pNext->nPosY)
    {
        return 1;
    }

    if (pDrlgVertex->nPosX > pNext->nPosX)
    {
        return 1;
    }

    if (pDrlgVertex->dwFlags & 1)
    {
        return 1;
    }

    if (pNext->dwFlags & 1)
    {
        return 1;
    }

    return 0;
}

static void sub_00680070_MarkVertexDirections(D2DrlgLevelStrc* pLevel);

// 0x00680070
static void sub_00680070_MarkVertexDirections(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pPreviousVertex = pVertex;
    BOOL bBreak = 0;

    while (pPreviousVertex->pNext != pVertex)
    {
        pPreviousVertex = pPreviousVertex->pNext;
    }

    do
    {
        if (sub_0067FFB0_IsRectAdjacent((D2DrlgOutRectStrc*)pVertex, (D2DrlgOutRectStrc*)pPreviousVertex))
        {
            D2DrlgVertexStrc* pFirstVertex = pVertex;
            D2DrlgVertexStrc* pSpecialVertex = 0;
            do
            {
                if (pVertex == pOutdoors->pVertex)
                {
                    bBreak = 1;
                }

                if (DRLGOUTWILD_IsVertexBlocking(pVertex))
                {
                    break;
                }

                if (sub_0067FFF0_IsSpecialVertex(pVertex))
                {
                    pSpecialVertex = pVertex;
                }

                pVertex = pVertex->pNext;
            }
            while (pVertex != pFirstVertex);

            if (pSpecialVertex)
            {
                D2DrlgVertexStrc* pTemp = pFirstVertex;
                for (; pTemp != pSpecialVertex; pTemp = pTemp->pNext)
                {
                    pTemp->nDirection = 1;
                }

                pTemp->nDirection = 1;
                pOutdoors->dwFlags |= 0x20;
            }
        }

        pPreviousVertex = pVertex;
        pVertex = pVertex->pNext;
    }
    while (!bBreak && pVertex != pOutdoors->pVertex);
}

void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel); // 0x006803D0
void __stdcall DRLGOUTWILD_SpawnCottage(int bExtraCottage, int nLvlPrestId, D2DrlgLevelStrc* pLevel); // 0x006804E0

void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel); // 0x00680580
// 0x006807F0
void __fastcall DRLGOUTWILD_InitAct1OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId != LEVEL_BLOODMOOR && pLevel->eLevelId != LEVEL_COLDPLAINS && pLevel->eLevelId != LEVEL_BURIALGROUNDS)
    {
        sub_00680070_MarkVertexDirections(pLevel);
    }

    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);

    if (pLevel->eLevelId >= LEVEL_BLOODMOOR && pLevel->eLevelId <= LEVEL_TAMOEHIGHLAND)
    {
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 0, 4);
        sub_00680200_SpawnRiverAndCliffCaves(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
        DRLGOUTWILD_SpawnTownTransitionsAndCaves(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
        DRLGOUTDOORS_SpawnAct1DirtPaths(pLevel);
    }

    if (pLevel->eLevelId == LEVEL_MOOMOOFARM)
    {
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 0, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
    }

    if (pLevel->eLevelId >= LEVEL_COLDPLAINS && pLevel->eLevelId <= LEVEL_BLACKMARSH)
    {
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
    }

    if (pLevel->eLevelId >= LEVEL_BLOODMOOR && pLevel->eLevelId <= LEVEL_TAMOEHIGHLAND)
    {
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
    }

    DRLGOUTWILD_SpawnSpecialPresets(pLevel);
}
