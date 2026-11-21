#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
union D2SeedStrc;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;
struct D2ObjectControlStrc;







typedef bool (__fastcall* OBJRGN_SpawnCheckFn)(D2GameStrc* pGame, int nLevelId, int nX, int nY);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId); // 0x00547300
bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x005473A0
void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x00547400
D2UnitStrc* __stdcall sub_00550540_SpawnObjectInBox(D2GameStrc* pGame, int nObjectId, int nWidth, int nHeight, D2ActiveRoomStrc* pRoom, int nLevelId, OBJRGN_SpawnCheckFn pfnCheck); // 0x00550540
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900



D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800
extern int gnBarrelXOffsets_00731B7C[8]; // 0x00731B7C
extern int gnBarrelYOffsets_00731B9C[8]; // 0x00731B9C
static __declspec(noinline) int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY);
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
extern int gnObjectIds_00731D64[]; // 0x00731D64

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005516C0
D2UnitStrc* __fastcall sub_005516C0_SpawnWell(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nWellType, int nObjectId, unsigned short nChance)
{
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    if (OBJRGN_CanNotSpawnMoreWells(pGame, nLevelId))
    {
        return 0;
    }

    D2_ASSERT(nWellType <= 128, 0x8D0);

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    if (SEED_RollRandomNumber(pSeed) % 100 > nChance)
    {
        return 0;
    }

    D2UnitStrc* pUnit = sub_00550540_SpawnObjectInBox(pGame, nObjectId, 2 * nSizeX + 1, 2 * nSizeY + 1, pRoom, nLevelId, OBJRGN_CanSpawnWell);
    if (pUnit)
    {
        const int nMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pObjectsTxtRecord->nSelectable[nMode])
        {
            pUnit->dwFlags |= 2;
        }
        else
        {
            pUnit->dwFlags &= ~2;
        }

        OBJRGN_SetWellCoordinates(pGame, nLevelId, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit));
    }

    return pUnit;
}

static inline unsigned __int64 OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x005502F0
static int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 2
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX - nSizeX
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY - nSizeY
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if ((nMax - 1) & nMax) return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) % nMax;
    return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00551850
D2UnitStrc* __fastcall sub_00551850_PopulateBarrels(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(7);
    D2_ASSERT(bDensity <= 128, 0x955);
    int nCount = 0;
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    D2SeedStrc* pSeed = &pControl->pSeed;
    if ((unsigned int)OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability) return 0;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(hRoom, &bounds);
    int nClusters = ((bounds.nSubtileWidth * bounds.nSubtileHeight >> 7) * bDensity) >> 8;
    int nTries = 2 * nClusters;
    D2UnitStrc* pObject = 0;
    while (nClusters > 0 && nTries > 0)
    {
        int nClassId;
        if (OBJECTS_RollLimited_Inline(pSeed, 3))
            nClassId = 7;
        else
            nClassId = 11;
        D2CoordStrc base;
        base.nX = bounds.nSubtileX + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileWidth);
        base.nY = bounds.nSubtileY + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileHeight);
        D2CoordStrc coord;
        coord.nX = base.nX;
        coord.nY = base.nY;
        if (sub_005502F0_CanPlace(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY) == 1)
        {
            D2_ASSERT(hRoom, 0x98D);
            pObject = SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
            int nClusterSize = 1;
            ++nCount;
            if (nCount >= 8) return pObject;
            int bCanPlace = 1;
            pObject = 0;
            while (!OBJECTS_RollLimited_Inline(pSeed, nClusterSize >> 1) && bCanPlace)
            {
                int i = 0;
                bCanPlace = 0;
                while (!bCanPlace)
                {
                    if (i >= 15) break;
                    const unsigned int nDirection = (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & 7;
                    base.nX += pObjectsTxt->nXSpacing * gnBarrelXOffsets_00731B7C[nDirection];
                    base.nY += pObjectsTxt->nYSpacing * gnBarrelYOffsets_00731B9C[nDirection];
                    coord.nX = base.nX;
                    coord.nY = base.nY;
                    bCanPlace = sub_005502F0_CanPlace(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY);
                    ++i;
                }
                if (!bCanPlace) continue;
                int nNextClass;
                if ((unsigned int)OBJECTS_RollSeed_Inline(pSeed) & 3)
                    nNextClass = 7;
                else
                    nNextClass = 11;
                pObject = SUNIT_AllocUnitData(2, nNextClass, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
                ++nClusterSize;
                ++nCount;
                if (nCount >= 8) return pObject;
            }
            --nClusters;
        }
        --nTries;
    }
    return pObject;
}

static int gnObjectCount_00731D90; // 0x00731D90

// build: context OBJECTS_RollObjectIndex_Inline
static __forceinline unsigned int OBJECTS_RollObjectIndex_Inline(D2SeedStrc* pSeed)
{
    if (gnObjectCount_00731D90 <= 0) return 0;
    if ((gnObjectCount_00731D90 - 1) & gnObjectCount_00731D90) return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) % gnObjectCount_00731D90;
    return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & (gnObjectCount_00731D90 - 1);
}

// 0x00551C00
D2UnitStrc* __fastcall OBJECTS_PopulateFn5_Crate(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
    D2_ASSERT(bDensity <= 128, 0x9D7);
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    D2SeedStrc* pSeed = &pControl->pSeed;
    if ((unsigned int)OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability) return 0;
    int nCount = 0;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(hRoom, &bounds);
    int nClusters = ((bounds.nSubtileWidth * bounds.nSubtileHeight >> 7) * bDensity) >> 8;
    int nTries = 2 * nClusters;
    D2UnitStrc* pObject = 0;
    if (nClusters > 0)
    {
        int nLimit = 4 * nClusters;
        int bDone = 0;
        while (!bDone)
        {
            if (nTries <= 0)
                break;
        int nClassId = nObjectId;
        if (nObjectId != 46)
            nClassId = gnObjectIds_00731D64[OBJECTS_RollObjectIndex_Inline(pSeed)];
        D2CoordStrc base;
        base.nX = bounds.nSubtileX + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileWidth);
        base.nY = bounds.nSubtileY + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileHeight);
        D2CoordStrc coord;
        coord.nX = base.nX;
        coord.nY = base.nY;
        if (sub_005502F0_CanPlace(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY) == 1)
        {
            if (nClassId != 46)
                nClassId = gnObjectIds_00731D64[ITEMS_RollLimitedRandomNumber(pSeed, gnObjectCount_00731D90)];
            D2_ASSERT(hRoom, 0xA06);
            SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
            int nClusterSize = 1;
            int bCanPlace = 1;
            pObject = 0;
            while (!OBJECTS_RollLimited_Inline(pSeed, nClusterSize >> 1) && bCanPlace)
            {
                int i = 0;
                bCanPlace = 0;
                int nMax = 4;
                if (nLimit >= 4) nMax = nLimit;
                while (!bCanPlace)
                {
                    if (i >= nMax) break;
                    const unsigned int nDirection = (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & 7;
                    base.nX += pObjectsTxt->nXSpacing * gnBarrelXOffsets_00731B7C[nDirection];
                    base.nY += pObjectsTxt->nYSpacing * gnBarrelYOffsets_00731B9C[nDirection];
                    coord.nX = base.nX;
                    coord.nY = base.nY;
                    bCanPlace = sub_005502F0_CanPlace(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY);
                    ++i;
                }
                if (!bCanPlace) continue;
                pObject = SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
                if (pObject)
                {
                    ++nCount;
                    if (nCount >= 8) return pObject;
                }
                ++nClusterSize;
            }
            --nClusters;
            nLimit -= 4;
        }
            --nTries;
            if (nClusters <= 0)
                bDone = 1;
        }
    }
    return pObject;
}
