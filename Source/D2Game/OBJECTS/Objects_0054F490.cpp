#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_STONYFIELD 4
#define LEVEL_TRISTRAM 38
#define LEVEL_MOOMOOFARM 39
#define LEVEL_CANYONOFTHEMAGI 46
#define LEVEL_DURIELSLAIR 73
#define LEVEL_ARCANESANCTUARY 74
#define LEVEL_HARROGATH 109
#define LEVEL_FRIGIDHIGHLANDS 111
#define LEVEL_ARREATPLATEAU 112
#define LEVEL_TUNDRAWASTELANDS 117
#define LEVEL_NIHLATHAKSTEMPLE 121
#define LEVEL_HELL1 125
#define LEVEL_HELL2 126
#define LEVEL_HELL3 127
#define UNITFLAG_TARGETABLE 0x00000002
struct D2SeedStrc;
struct D2ObjectControlStrc;
struct D2ObjectDataStrc;
struct D2ObjInitFnStrc;
struct D2DrlgCoordsStrc;
struct D2CoordInitStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef D2UnitStrc* (__fastcall* PRESETSPAWNFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode);

extern PRESETSPAWNFN sgPresetStuff_00731D28[]; // 0x00731D28
extern int sgnPresetStuffCount_00731D4C; // 0x00731D4C

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};


struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};


struct D2ObjectsTxt
{
    char unk0x00[0xC4];
    unsigned char nSelectable[8];
    char unk0xCC[0x04];
    unsigned int dwSizeX;
    unsigned int dwSizeY;
    unsigned int dwFrameCnt[8];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};


D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall sub_00551150_SpawnFlies(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00551150

struct D2CoordInitStrc
{
    D2CoordStrc* pCoords;
    int nCount;
};

extern D2CoordInitStrc gaCoordInit_00731EB4[]; // 0x00731EB4
D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom); // 0x00550380

// 0x0054F490
D2UnitStrc* __fastcall OBJECTS_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId <= 573)
    {
        return 0;
    }

    const int nIndex = nClassId - 574;
    if (nIndex >= sgnPresetStuffCount_00731D4C)
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)sgPresetStuff_00731D28[nIndex]), 429);

    return sgPresetStuff_00731D28[nIndex](pGame, pRoom, nClassId, nX, nY, nMode);
}

#include "gen/data/Source/D2Game/OBJECTS/Objects_0054F490.inc"

static __forceinline unsigned __int64 ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0054FDB0
void __fastcall OBJECTS_InitFunction58_Fissure(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 8, pOp->pGame->dwGameFrame + (unsigned int)ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) % 250 + 25, 0, 0);
}

// 0x0054FE10
void __fastcall OBJECTS_InitFunction59_VileDogAfterglow(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 27, 0, 0);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
}

// 0x0054FE70
void __fastcall OBJECTS_InitFunction12_PermanentPortal(D2ObjInitFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        UNITS_BlockCollisionPath(pOp->pObject, pOp->pRoom, pOp->nX, pOp->nY);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    const int nTombLevelId = DUNGEON_GetHoradricStaffTombLevelId(pOp->pGame->pAct[1]);
    switch (nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        pOp->pObject->pObjectData->InteractType = LEVEL_MOOMOOFARM;
        return;

    case LEVEL_MOOMOOFARM:
        pOp->pObject->pObjectData->InteractType = LEVEL_ROGUEENCAMPMENT;
        return;

    case LEVEL_TRISTRAM:
        pOp->pObject->pObjectData->InteractType = LEVEL_STONYFIELD;
        return;

    case LEVEL_STONYFIELD:
        pOp->pObject->pObjectData->InteractType = LEVEL_TRISTRAM;
        return;

    case LEVEL_ARCANESANCTUARY:
        pOp->pObject->pObjectData->InteractType = LEVEL_CANYONOFTHEMAGI;
        return;

    case LEVEL_CANYONOFTHEMAGI:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARCANESANCTUARY;
        return;

    case LEVEL_DURIELSLAIR:
        pOp->pObject->pObjectData->InteractType = nTombLevelId;
        return;

    case LEVEL_NIHLATHAKSTEMPLE:
        pOp->pObject->pObjectData->InteractType = LEVEL_HARROGATH;
        return;

    case LEVEL_HARROGATH:
        pOp->pObject->pObjectData->InteractType = LEVEL_NIHLATHAKSTEMPLE;
        return;

    case LEVEL_HELL1:
        pOp->pObject->pObjectData->InteractType = LEVEL_FRIGIDHIGHLANDS;
        return;

    case LEVEL_HELL2:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARREATPLATEAU;
        return;

    case LEVEL_HELL3:
        pOp->pObject->pObjectData->InteractType = LEVEL_TUNDRAWASTELANDS;
        return;

    case LEVEL_FRIGIDHIGHLANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL1)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL1;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_ARREATPLATEAU:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL2)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL2;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_TUNDRAWASTELANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL3)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL3;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    default:
        if (nLevelId == nTombLevelId)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_DURIELSLAIR;
        }
        return;
    }
}

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
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

// 0x00550220
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc* pRoom, int nSizeY, D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, int nSizeX)
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

// 0x00551200
D2UnitStrc* __fastcall OBJECTS_PopulateFn7_RogueOnStick(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) % 100 > nProbability)
    {
        return 0;
    }

    const int nIndex = ITEMS_RollLimitedRandomNumber(&pObjectControl->pSeed, gnCoordInitCount_00731E64);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    int nTries = 8;
    D2UnitStrc* pObject = 0;
    D2CoordStrc base;
    while (1)
    {
        base.nX = drlgCoords.nSubtileX + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1);
        base.nY = drlgCoords.nSubtileY + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1);
        if (sub_00550220_CanPlaceObject(pRoom, 5, &drlgCoords, &base, 5) == 1)
        {
            break;
        }

        --nTries;
        if (nTries <= 0)
        {
            return 0;
        }
    }

    for (int j = 0; j < gaCoordInit_00731EB4[nIndex].nCount; ++j)
    {
        D2CoordStrc coord;
        coord.nX = base.nX + gaCoordInit_00731EB4[nIndex].pCoords[j].nX;
        coord.nY = base.nY + gaCoordInit_00731EB4[nIndex].pCoords[j].nY;
        if (sub_00550220_CanPlaceObject(pRoom, nSizeY, &drlgCoords, &coord, nSizeX) == 1)
        {
            const unsigned int nClassId = (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1) + 0x39;
            D2_ASSERT(nClassId <= 0x3A, 0x7DD);
            D2_ASSERT(pRoom, 0x7DE);
            pObject = SUNIT_AllocUnitData(2, nClassId, coord.nX, coord.nY, pGame, pRoom, 1, 0, 0);
            if (pObject)
            {
                sub_00551150_SpawnFlies(pGame, pObject);
            }
        }
    }

    return pObject;
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
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
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
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
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

int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 0);
    return 1;
}

int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 1);
    return 1;
}

static inline int OBJECTS_RollChance_Inline(D2SeedStrc* pSeed, unsigned short nProbability)
{
    if (OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability)
    {
        return 0;
    }

    return 1;
}

// 0x00551470
D2UnitStrc* __fastcall OBJECTS_PopulateFn3_CommonObjects(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2_ASSERT(nDensity <= 128, 0x864);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeY;
    int nSizeX;
    nSizeX = pObjectsTxtRecord->dwSizeX;
    nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (!OBJECTS_RollChance_Inline(&pObjectControl->pSeed, nProbability))
    {
        return 0;
    }
    int nCount = nDensity * (drlgCoords.nSubtileWidth * drlgCoords.nSubtileHeight >> 7) >> 8;
    D2UnitStrc* pObject = 0;
    for (; nCount > 0; --nCount)
    {
        pObject = OBJECTS_CreateObject(pGame, nObjectId, nSizeX, nSizeY, pRoom);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[pObject->dwAnimMode])
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
        }
    }
    return pObject;
}

// 0x00551580
D2UnitStrc* __fastcall OBJECTS_PopulateFn9_TrappedSoul(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2_ASSERT(nDensity <= 128, 0x893);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeY;
    int nSizeX;
    nSizeX = pObjectsTxtRecord->dwSizeX;
    nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2SeedStrc* pSeed;
    if (pRoom)
    {
        pSeed = &pRoom->pSeed;
    }
    else
    {
        pSeed = 0;
    }
    if (OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability)
    {
        return 0;
    }
    const int nMax = nDensity * (drlgCoords.nSubtileWidth * drlgCoords.nSubtileHeight >> 7) >> 8;
    for (int i = nMax; i > 0; --i)
    {
        D2UnitStrc* pObject = OBJECTS_CreateObject(pGame, nObjectId, nSizeX, nSizeY, pRoom);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[pObject->dwAnimMode])
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
            return pObject;
        }
    }
    return 0;
}
