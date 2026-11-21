#include "D2Structs.h"
#include "D2Game.h"
#include "D2Path.h"
#include "D2ItemsWorld.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameObjs.h"

// build: base-profile

struct D2GameStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const int s_anUnitListOffset_006E10E0[6]; // 0x006E10E0

#define UNIT_TILE 5

#define D2_MAYBE_UNUSED(x) (void)(x)

union D2SeedStrc;

struct D2LvlWarpTxt;

struct D2LvlWarpTxt { char unk0[0x14]; int nOffsetX; int nOffsetY; };

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0

D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc*,int,D2LvlWarpTxt**); // 0x006195A0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc*,D2CoordStrc*,int,unsigned int,int); // 0x0064E7B0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0

int __fastcall QUESTS_LevelWarpCheck(D2GameStrc*,D2UnitStrc*,int,int); // 0x00545B80

int __fastcall sub_6FCBDFE0(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0

void __fastcall sub_6FC817D0(D2GameStrc*,D2UnitStrc*,D2SkillStrc*,int,int,int,int); // 0x005809D0

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20

void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc*,unsigned char,unsigned char,int,unsigned char,unsigned short,unsigned short,unsigned char,unsigned char); // 0x0053B4B0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

D2UnitStrc* __fastcall OBJECTS_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054F490

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0

struct D2DynamicPathStrc;

struct D2ActiveRoomStrc;

struct D2ObjectsTxt;

struct D2DrlgActStrc;

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

#pragma function(memset)

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID);                     // 0x005348C0

void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0054F5D0

void __fastcall SUNIT_InitSeed(D2UnitStrc* ptUnit, D2SeedStrc* pSeed); // 0x00552DF0

void __fastcall sub_00552E90_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed); // 0x00552E90

int __fastcall sub_00552EE0(D2GameStrc* pGame, int nUnitType);                             // 0x00552EE0

void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate); // 0x00554850

void __fastcall sub_6FC4BE80(D2UnitStrc* pUnit, D2GameStrc* pGame, int nUnitGUID, D2ActiveRoomStrc* pRoom);  // 0x00555D20

void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250

void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID);                 // 0x0059F8A0

void __fastcall sub_005B1880(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                 // 0x005B1880

D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType);                                       // 0x00620290

void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit);                                                    // 0x00623520

void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem);                                      // 0x00627C90

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30

extern "C" void __stdcall PATH_SetUnitCollisionPattern(D2UnitStrc* pUnit, int nCollisionPattern);           // 0x00649190

int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560

static __forceinline D2UnitStrc** SUNIT_GetUnitList(D2GameStrc* pGame, int nUnitType, unsigned int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & 0x7F);
    return 0;
}

// 0x00553060
void __fastcall sub_00553060_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
        ppUnitList = (D2UnitStrc**)((char*)pGame + 0x1B20);
    else
        ppUnitList = SUNIT_GetUnitList(pGame, pUnit->dwUnitType, pUnit->dwUnitId);

    D2UnitStrc* i = *ppUnitList;
    D2UnitStrc* pPrevious = 0;
    while (i)
    {
        if (i->dwUnitId <= pUnit->dwUnitId)
        {
            if (i->dwUnitId == pUnit->dwUnitId)
            {
                char szMessage[256];
                D2_MAYBE_UNUSED(szMessage);
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x355);
                exit(-1);
            }
            break;
        }
        pPrevious = i;
        i = i->pListNext;
    }

    pUnit->pListNext = i;
    if (pPrevious)
        pPrevious->pListNext = pUnit;
    else
        *ppUnitList = pUnit;
}

static __forceinline int GetClassId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

// 0x005550B0
void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* ptGame,D2UnitStrc* hUnit,D2UnitStrc* pTile)
{
    D2_ASSERT(ptGame,329);
    D2_ASSERT(hUnit,330);
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pTile);
    int nLevel = GetClassId(pTile);
    D2LvlWarpTxt* pWarp;
    D2UnitStrc* pDestination = DUNGEON_GetWarpTileFromRoomAndSourceLevelId(pOldRoom,nLevel,&pWarp);
    if (!pDestination) return;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pDestination);
    D2CoordStrc point;
    point.nX = CLIENTS_GetUnitX(pDestination);
    point.nY = CLIENTS_GetUnitY(pDestination);
    D2_ASSERT(hUnit->dwUnitType == 0,348);
    D2ActiveRoomStrc* pFreeRoom = COLLISION_GetFreeCoordinates(pTargetRoom,&point,UNITS_GetUnitSizeX(hUnit),0x1C09,1);
    if (!pFreeRoom) return;
    int nOldLevel = DUNGEON_GetLevelIdFromRoom(pOldRoom);
    int nNewLevel = DUNGEON_GetLevelIdFromRoom(pFreeRoom);
    if (nNewLevel == 73 || nNewLevel == 128 || nNewLevel == 132 || nNewLevel == 118 || nNewLevel == 100)
        if (QUESTS_LevelWarpCheck(ptGame,hUnit,nOldLevel,nNewLevel)) return;
    int nX = point.nX;
    int nY = point.nY;
    if (sub_6FCBDFE0(ptGame,hUnit,pTargetRoom,nX,nY,0,0))
    {
        D2ClientStrc* pClient = UnitGetClient(hUnit,".\\UNIT\\SUnit.cpp",376);
        int nDestX = pWarp->nOffsetX + nX;
        int nDestY = pWarp->nOffsetY + nY;
        sub_6FC817D0(ptGame,hUnit,0,2,nDestX,nDestY,0);
        unsigned char nLife = UNITS_GetCurrentLifePercentage(hUnit);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient,0x0D,!hUnit ? 6 : hUnit->dwUnitType,!hUnit ? -1 : hUnit->dwUnitId,1,nDestX,nDestY,0,nLife);
    }
}

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

// 0x005557D0
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags)
{
    D2UnitStrc* pUnit = 0;

    switch (nUnitType)
    {
    case 2:
        if (nClassId > 573)
        {
            pUnit = OBJECTS_SpawnPresetObject(pGame, pRoom, nClassId, nX, nY, nMode);
            break;
        }
        if (nClassId == 573)
        {
            return 0;
        }

    default:
        pUnit = SUNIT_AllocUnitData(nUnitType, nClassId, nX, nY, pGame, pRoom, 1, nMode, 0);
        if (nUnitType == 4 && pUnit)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (!D2GAME_InitItemStats_6FC4E520(pGame, &pUnit, &itemDrop, 1))
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                return 0;
            }
        }
        if (pUnit)
        {
            pUnit->dwFlags |= 0x3000000;
        }
        return pUnit;

    case 1:
        pUnit = D2GAME_SpawnPresetMonster_6FC66560(pGame, pRoom, nClassId, nX, nY, nMode);
        break;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x3000000;
    }

    return pUnit;
}
