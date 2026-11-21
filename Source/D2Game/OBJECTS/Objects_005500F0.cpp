#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2DataTbls.h"
#include "D2GameServer.h"
#include "D2LevelTxt.h"

#define OBJMODE_OPERATING 1

#define OBJMODE_OPENED 2

#define EVENTTYPE_PERIODICSTATS 9

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

union D2SeedStrc;

struct D2ObjectControlStrc;

struct D2ObjInitFnStrc;

struct D2DrlgCoordsStrc;

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack); // 0x00552200

struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
};

typedef int (__fastcall* OBJTHEMEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

struct D2ObjectPopulateStrc
{
    int bActive;
    OBJTHEMEFN pfPopulate;
};

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern D2ObjectPopulateStrc gObjectThemeTable_00731E68[7];                                            // 0x00731E68

extern OBJECTPOPULATEFN sgPopulateTable[10];                                          // 0x00731D00

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70

static __forceinline unsigned int ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005500F0
void __fastcall OBJECTS_InitFunction34_HellBrazierFire(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    if (ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) & 1)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
}

// 0x005501F0
void __fastcall OBJECTS_InitFunction51_TrappedSoul(D2ObjInitFnStrc* pOp)
{
    if ((pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPENED) || (pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPERATING))
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSTATS, pOp->pGame->dwGameFrame + 35, 0, 0);
    }
}

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && pDrlgCoords->nSubtileY + 2 < (unsigned short)pCoord->nY
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

// build: context sub_00550220_CanPlaceObject
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc* pRoom, int nSizeY, int nSizeX, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords)
{
    if (pDrlgCoords->nSubtileWidth < nSizeX + 2 || pDrlgCoords->nSubtileHeight < nSizeY + 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 1
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 1
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth - 2
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight - 2
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 7, nSizeY + 7, 0xC01)
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX, nSizeY, 0x3F11))
    {
        return 1;
    }
    return 0;
}

int __fastcall OBJECTS_SpawnBarrel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX + 1;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY + 1;
    int nCounter = 0;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(7);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    D2CoordStrc coord;

    int nClassId;

    for (unsigned int nX = pDrlgCoords->nSubtileX; nX < nXEnd; nX += 2)
    {
        unsigned int nY = pDrlgCoords->nSubtileY;
        if (nY < nYEnd)
        {
            coord.nX = nX;
            do
            {
                nClassId = ((OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 3) == 0) ? 11 : 7;
                coord.nY = nY;
                if (sub_005502F0_CanPlaceSmallObject(pRoom, pObjectsTxtRecord->dwSizeX, pObjectsTxtRecord->dwSizeY, &coord, pDrlgCoords) == 1)
                {
                    D2_ASSERT(pRoom, 2696);
                    SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
                    ++nCounter;
                    if (nCounter >= 32)
                    {
                        return 1;
                    }
                }
                nY += 2;
            }
            while (nY < nYEnd);
        }
    }

    return 1;
}

// 0x00552140
int __fastcall OBJECTS_SpawnRandomItemGrid(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileX + (pDrlgCoords->nSubtileWidth > 12 ? 12 : pDrlgCoords->nSubtileWidth);
    const unsigned int nYEnd = pDrlgCoords->nSubtileY + (pDrlgCoords->nSubtileHeight > 12 ? 12 : pDrlgCoords->nSubtileHeight);
    int nCounter = 0;

    for (unsigned int nX = pDrlgCoords->nSubtileX + 1; nX < nXEnd; nX += 2)
    {
        for (unsigned int nY = pDrlgCoords->nSubtileY + 1; nY < nYEnd; nY += 2)
        {
            D2CoordStrc coord;
            coord.nX = nX;
            coord.nY = nY;
            if (sub_005502F0_CanPlaceSmallObject(pRoom, 1, 1, &coord, pDrlgCoords) == 1)
            {
                ITEMS_DropRandomItemAtCoordinates(pGame, pRoom, &coord, 0);
                ++nCounter;
                if (nCounter >= 32)
                {
                    return 1;
                }
            }
        }
    }

    return 1;
}

// build: context OBJECTS_SpawnArmorStandOrWeaponRack
static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack)
{
    if (bWeaponRack >= gnArmorStandOrRackCount_00731EB0)
    {
        return;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    const int nRand = OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack]);
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth - pObjectsTxtRecord->dwSizeX + pDrlgCoords->nSubtileX;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight - pObjectsTxtRecord->dwSizeY + pDrlgCoords->nSubtileY;
    D2CoordStrc coord;

    if (nRand == 0)
    {
        const int nY = pDrlgCoords->nSubtileY + 1;
        unsigned int nX = pDrlgCoords->nSubtileX + pObjectsTxtRecord->dwSizeX;
        if (nX < nXEnd)
        {
            coord.nY = nY;
            do
            {
                coord.nX = nX;
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pObjectsTxtRecord->dwSizeX, &coord, pDrlgCoords) == 1)
                {
                    D2_ASSERT(pRoom, 2834);
                    SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
                }
                nX += 2 * pObjectsTxtRecord->dwSizeX;
            }
            while (nX < nXEnd);
        }
    }
    else
    {
        const int nX = pDrlgCoords->nSubtileX + 1;
        unsigned int nY = pDrlgCoords->nSubtileY + pObjectsTxtRecord->dwSizeY;
        if (nY < nYEnd)
        {
            coord.nX = nX;
            do
            {
                coord.nY = nY;
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pObjectsTxtRecord->dwSizeX, &coord, pDrlgCoords) == 1)
                {
                    D2_ASSERT(pRoom, 2853);
                    SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
                }
                nY += 2 * pObjectsTxtRecord->dwSizeY;
            }
            while (nY < nYEnd);
        }
    }
}

// 0x005523C0
int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 0);
    return 1;
}

// 0x005523E0
int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 1);
    return 1;
}

struct D2ActiveRoomStrc;

static __forceinline unsigned int OBJPOP_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int OBJPOP_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return OBJPOP_RollSeed_Inline(pSeed) % nMax;
    }

    return OBJPOP_RollSeed_Inline(pSeed) & (nMax - 1);
}

static int __stdcall sub_00552400_PopulateTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion)
{
    if (pObjectRegion->nPopulatedRooms < 10 * pObjectRegion->unk0x0C)
    {
        return 0;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    const int nRoll = OBJPOP_RollSeed_Inline(&pObjectControl->pSeed) % 100;

    int nProbability = 0;
    if (pObjectRegion->unk0x04 > pObjectRegion->nPopulatedRooms / 2)
    {
        nProbability = 5;
    }

    if (pObjectRegion->unk0x04 > pObjectRegion->nPopulatedRooms - pObjectRegion->nPopulatedRooms / 4)
    {
        nProbability += 5;
    }

    if (nRoll >= nProbability + 12)
    {
        return 0;
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    int nMax = 0;
    int nIndices[7] = {};
    for (int i = 0; i < 7; ++i)
    {
        if ((1 << i) & nThemes)
        {
            nIndices[nMax] = i + 1;
            ++nMax;
        }
    }

    const int nIndex = OBJPOP_RollLimited_Inline(&pObjectControl->pSeed, nMax);
    if (nIndex < nMax && nIndices[nIndex] < nMax && gObjectThemeTable_00731E68[nIndices[nIndex]].bActive && gObjectThemeTable_00731E68[nIndices[nIndex]].pfPopulate)
    {
        return gObjectThemeTable_00731E68[nIndices[nIndex]].pfPopulate(pGame, pRoom, &drlgCoords);
    }

    return 0;
}

// 0x00552560
static int __stdcall sub_00552560_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom)
{
    if (DUNGEON_HasWaypoint(pRoom))
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, nLevelId);
    if (!nLevelId)
    {
        return 0;
    }

    if (D2Common_10087(pRoom))
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    if (pObjectRegion->nPopulatedRooms == 0x7FFFFFFF)
    {
        pObjectRegion->nPopulatedRooms = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pGame->pAct[pObjectRegion->nAct], nLevelId);
    }

    pObjectRegion->unk0x04 += 1;

    if (pLevelsTxtRecord->dwThemes)
    {
        if (sub_00552400_PopulateTheme(pGame, pRoom, pLevelsTxtRecord->dwThemes, pObjectRegion) == 1)
        {
            return 0;
        }
    }

    return 1;
}

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0xBEC);

    if (!sub_00552560_CanPopulateRoom(pGame, pLevelsTxtRecord, pRoom))
    {
        return;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjGroup = pLevelsTxtRecord->nObjGroup[i];
        int nProbability = OBJPOP_RollSeed_Inline(pSeed) % 100;

        D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->unk0x04 << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines
            && DATATBLS_GetObjectsTxtRecord(nObjGroup)->nSubClass)
        {
            nProbability = 100;
        }

        if (nObjGroup && nProbability <= pLevelsTxtRecord->nObjPrb[i])
        {
            D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
            if (!pObjGroupTxtRecord)
            {
                return;
            }

            const int nRoll = OBJPOP_RollSeed_Inline(pSeed) % 100;
            int nAccumulatedProbability = 0;
            for (int j = 0; j < 8; ++j)
            {
                const unsigned int nObjectId = pObjGroupTxtRecord->dwId[j];
                if (!nObjectId)
                {
                    break;
                }

                nAccumulatedProbability += pObjGroupTxtRecord->nProbability[j];
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
                if (nRoll < nAccumulatedProbability && pObjectsTxtRecord->nGore <= gnObjectGoreLevel_00731BBC)
                {
                    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC43);
                    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC46);
                        const unsigned char nDensity = pObjGroupTxtRecord->nDensity[j];
                        D2_ASSERT(nDensity < 128, 0xC47);
                        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, nDensity, nObjectId, 100);
                    }
                    break;
                }
            }
        }
    }
}

#include "gen/data/Source/D2Game/OBJECTS/Objects_005500F0.inc"
