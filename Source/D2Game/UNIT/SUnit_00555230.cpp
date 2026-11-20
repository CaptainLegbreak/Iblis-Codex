#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2ObjectsTxt;
struct D2DrlgActStrc;
struct D2GameStrc;

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    char unk0x04[0x34];
};





enum D2C_M192SUnitAlloc
{
    PLRMODE_DEATH = 0,
    PLRMODE_DEAD = 17,
    MONSTATSFLAGINDEX_ENABLED = 25,
    MONSTATS2FLAGINDEX_DEADCOL = 0x13,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_INITSEEDSET = 0x00000010,
    UNITFLAGEX_ISEXPANSION = 0x02000000,
    UNITFLAGEX_SERVERUNIT = 0x04000000,
    COLLISION_PATTERN_SMALL_NO_PRESENCE = 5,
    COLLIDE_CORPSE = 0x8000,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma function(memset)

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID);                     // 0x005348C0
void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0054F5D0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed);                                       // 0x00552DF0
void __fastcall sub_00552E90_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed);                       // 0x00552E90
int __fastcall sub_00552EE0(D2GameStrc* pGame, int nUnitType);                             // 0x00552EE0
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate); // 0x00554850
void __fastcall sub_6FC4BE80(D2UnitStrc* pUnit, D2GameStrc* pGame, int nUnitGUID, D2ActiveRoomStrc* pRoom);  // 0x00555D20
void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250
void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID);                 // 0x0059F8A0
void __fastcall sub_005B1880(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                 // 0x005B1880
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType);                                       // 0x00620290
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit);                                                    // 0x00623520
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem);                                      // 0x00627C90
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
extern "C" void __stdcall PATH_SetUnitCollisionPattern(D2UnitStrc* pUnit, int nCollisionPattern);           // 0x00649190
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x00555230
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID)
{
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        if ((unsigned int)nClassId >= 7)
        {
            return 0;
        }
        break;

    case UNIT_MONSTER:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ENABLED >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ENABLED & 7]))
        {
            return 0;
        }
        break;
    }
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(pGame->pMemoryPool, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->pMemoryPool = pGame->pMemoryPool;
    pUnit->pGame = pGame;

    if (pGame->bExpansion)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_ISEXPANSION;
    }
    else
    {
        pUnit->dwFlagEx &= ~UNITFLAGEX_ISEXPANSION;
    }
    pUnit->dwFlagEx |= UNITFLAGEX_SERVERUNIT;

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];
    pUnit->pQuestEventList = 0;

    if (nUnitType)
    {
        SUNIT_InitSeed(pUnit, &pGame->pGameSeed);

        if (nUnitType == UNIT_ITEM)
        {
            ITEMS_AllocItemData(pGame->pMemoryPool, pUnit);
            sub_00552E90_InitItemSeeds(pUnit, &pGame->pGameSeed);
        }
    }

    pUnit->dwFlags |= UNITFLAG_INITSEEDSET;
    pUnit->dwNodeIndex = 11;

    int nUnitGUID;
    if (nUnitType == UNIT_MONSTER && (nAllocFlags & 2))
    {
        nUnitGUID = nOverrideUnitGUID;
    }
    else
    {
        nUnitGUID = sub_00552EE0(pGame, nUnitType);
    }

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        PLAYER_Create(pGame, pUnit, nUnitGUID);
        if (nMode != PLRMODE_DEAD)
        {
            sub_005B1880(pGame, pUnit, 0);
        }
        break;

    case UNIT_MONSTER:
        pUnit->dwAnimMode = nMode;
        MONSTER_Initialize(pGame, pRoom, pUnit, nUnitGUID);
        break;

    case UNIT_OBJECT:
        pUnit->pObjectData = (D2ObjectDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ObjectDataStrc), ".\\UNIT\\SUnit.cpp", 612, 0);
        memset(pUnit->pObjectData, 0, sizeof(D2ObjectDataStrc));
        pUnit->pObjectData->pObjectTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
        pUnit->dwAnimMode = nMode;
        UNITS_AllocStaticPath(pUnit);
        OBJECTS_InitHandler(pGame, pUnit, nUnitGUID, pRoom, nX, nY);
        break;

    case UNIT_ITEM:
        pUnit->dwAnimMode = nMode;
        UNITS_AllocStaticPath(pUnit);
        sub_6FC4BE80(pUnit, pGame, nUnitGUID, pRoom);
        break;

    case UNIT_MISSILE:
        pUnit->dwAnimMode = nMode;
        MISSILES_Initialize(pGame, pUnit, nUnitGUID);
        break;

    case UNIT_TILE:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= UNITFLAG_TARGETABLE;
        pUnit->dwUnitId = nUnitGUID;
        break;
    }

    if (nAllocFlags & 1)
    {
        SUNIT_Add(pUnit, nX, nY, pGame, pRoom, 1);

        switch (nUnitType)
        {
        case UNIT_PLAYER:
            if (pUnit->dwAnimMode == PLRMODE_DEAD || pUnit->dwAnimMode == PLRMODE_DEATH)
            {
                PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
                PATH_SetUnitCollisionPattern(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
            }
            break;

        case UNIT_MONSTER:
            if (MONSTERS_IsDead(pUnit) && !sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_DEADCOL))
            {
                PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
                PATH_SetUnitCollisionPattern(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
                return pUnit;
            }
            break;
        }
    }

    return pUnit;
}
