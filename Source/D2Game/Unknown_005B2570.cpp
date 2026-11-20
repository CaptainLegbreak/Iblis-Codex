#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"




struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
};


enum
{
};

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100
D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc* pMonCreate);                    // 0x005B2A00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

extern const D2CoordStrc gaMinionSpawnOffsets_006E2CF0[3][6];                                               // 0x006E2CF0

__forceinline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

__forceinline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2UnitStrc* sub_005B3090_SpawnAtPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.field_20 = -1;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B2570
int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags)
{
    if (!pUnit)
    {
        return 0;
    }

    if (nOffset < 0 || nOffset > 2)
    {
        nOffset = 0;
    }

    int bSpawned = 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nUnitGUID = pUnit->dwUnitId;
    const int nX = UNITS_GetUnitXPositionInline(pUnit);
    const int nY = UNITS_GetUnitYPositionInline(pUnit);
    int nDirection = SEED_RollRandomNumber(&pUnit->pSeed) % 6;

    for (int i = 0; i < nCount; ++i)
    {
        const int nSpawnX = nX + gaMinionSpawnOffsets_006E2CF0[nOffset][nDirection].nX;
        const int nSpawnY = nY + gaMinionSpawnOffsets_006E2CF0[nOffset][nDirection].nY;
        nDirection = (nDirection + 5) % 6;

        D2UnitStrc* pMinion = sub_005B3090_SpawnAtPosition(pGame, pRoom, nSpawnX, nSpawnY, nMonsterId, nAnimMode, nFlags);
        if (pMinion)
        {
            bSpawned = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nUnitGUID, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pUnit, pMinion);
        }
    }

    return bSpawned;
}

#include "gen/data/Source/D2Game/Unknown_005B2570.inc"
