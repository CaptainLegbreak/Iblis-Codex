#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtItems.h"
#include "D2ItemsWorld.h"
#include "D2GameObjs.h"
#include "D2GameStrc.h"
#include "D2GameRecords.h"

struct D2ActiveRoomStrc;

struct D2RoomCoordListStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_OBJECT 2

#define OBJMODE_NEUTRAL 0

#define OBJMODE_OPERATING 1

#define EVENTTYPE_ENDANIM 1

#define EVENTTYPE_TRAP 4

#define UNITFLAG_TARGETABLE 2

#define MONSTER_FLYINGSCIMITAR 234

#define MONMODE_WALK 2

#define STAT_LEVEL 12

struct D2ObjectControlStrc;

union D2SeedStrc;

struct D2ObjectDataStrc;

struct D2MonRegDataStrc;

struct D2MonsterRegionStrc;

struct D2ObjOperateFnStrc;

struct D2MonStatsCountStrc;

struct D2StaticPathStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

typedef void (__fastcall* ObjTrapHandlerFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern ObjTrapHandlerFunction sgObjectTrapHandlers[]; // 0x00732CEC

extern D2MonStatsCountStrc* sgptDataTables; // 0x00744304

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0

int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp); // 0x005474C0

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pUnit, int nUnitId); // 0x00552AF0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90

D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0

D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill); // 0x00644360

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId); // 0x00558200

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

struct D2SfxStrc { D2GameStrc* pGame; D2UnitStrc* pObject; D2UnitStrc* pOwner; };

struct D2SfxArgStrc { int unk, nDamagePct, nRadius; };

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x006272B0

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pFind, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnTest, D2UnitFindArgStrc* pArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pFind); // 0x0065AA00

int __fastcall sub_00582710_IsLivingUnit(D2UnitStrc* unit, void* unused); // 0x00582710

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

// 0x00582250
static int __stdcall sub_00582250(D2ActiveRoomStrc* pRoom, int nMonsterId)
{
    if (nMonsterId == MONSTER_FLYINGSCIMITAR && pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == ACT_I)
    {
        return 0;
    }

    return 1;
}

// 0x00582280
static void D2GAME_SpawnTrapMonster_6FC75B40(D2ObjOperateFnStrc* pOp, int nMonsterId, int nAnimMode)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
        if (nMonsterId != MONSTER_FLYINGSCIMITAR || !pRoom || DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != ACT_I)
        {
            if (!sub_6FC6A150(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, (-1), 0)
                && !sub_6FC6A150(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, 1, 0))
            {
                sub_6FC6A150(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, 3, 0);
            }
        }
    }
}

// 0x005822F0
void __fastcall D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ObjOperateFnStrc op;
    op.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pUnit));
    op.hObject = pUnit;
    op.pGame = pGame;

    const int nMonsters = (SEED_RollRandomNumber_Inline(&op.pObjectregion->pSeed) & 1) + 1;

    const int nMonsterId = OBJRGN_GetTrapMonsterId(&op);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        for (int i = 0; i < nMonsters; ++i)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(&op, nMonsterId, 8);
        }
    }
}

// 0x00582510
static void __stdcall D2GAME_SetTrapCallback_6FC764B0(unsigned char bTrapType, D2ObjOperateFnStrc* pOp)
{
    if (bTrapType < gnObjectTrapHandlerCount_00732D14 && sgObjectTrapHandlers[bTrapType])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[bTrapType]), 0x56C);

        if (sgObjectTrapHandlers[bTrapType] == D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0
            && !sub_00582250(UNITS_GetRoom(pOp->hObject), OBJRGN_GetTrapMonsterId(pOp)))
        {
            return;
        }

        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_TRAP, pOp->pGame->dwGameFrame + 35, 0, 0);
        SUNIT_AttachSound(pOp->hObject, 13, 0);
    }
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00582DA0
void __fastcall sub_00582DA0_ExplosionEffect(D2SfxStrc* pSfx, D2SfxArgStrc* pArgs)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pSfx->pObject);
    int nX = CLIENTS_GetUnitX(pSfx->pObject);
    int nY = CLIENTS_GetUnitY(pSfx->pObject);
    D2UnitFindArgStrc arg;
    memset(&arg, 0, sizeof(arg));
    arg.nFlags = 0x583;
    arg.nX = nX;
    arg.nY = nY;
    arg.nSize = pArgs->nRadius;
    D2UnitFindDataStrc data;
    UNITFINDS_InitializeUnitFindData(pSfx->pGame->pMemoryPool, &data, pRoom, nX, nY, pArgs->nRadius, (void*)sub_00582710_IsLivingUnit, &arg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&data);
    for (int i = 0; i < data.nIndex; ++i)
    {
        D2UnitStrc* pUnit = data.pUnitsArray[i];
        if (pUnit && (pUnit->dwUnitType == 1 || pUnit->dwUnitType == 0) && !SUNIT_IsDead(pUnit))
        {
            int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
            STATLIST_AddUnitStat(pUnit, 6, (pArgs->nDamagePct * nLife / -100) << 8, 0);
        }
    }
    UNITFINDS_FreeUnitFindData(&data);
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            D2MissileStrc missile;
            memset(&missile, 0, sizeof(missile));
            missile.dwFlags = 3;
            missile.nX = CLIENTS_GetUnitX(pSfx->pObject);
            missile.nY = CLIENTS_GetUnitY(pSfx->pObject);
            missile.nTargetX = (i & 1) ? 5 * i : -5 * i;
            missile.nTargetY = (j & 1) ? 5 * j : -5 * j;
            missile.pOwner = pSfx->pOwner;
            missile.nMissile = 62;
            int nSkillLevel = STATLIST_UnitGetStatValue(pSfx->pOwner, 12, 0) / 5;
            if (nSkillLevel < 1) nSkillLevel = 1;
            else if (nSkillLevel > 8) nSkillLevel = 8;
            missile.nSkillLevel = nSkillLevel;
            MISSILES_CreateMissileFromParams(pSfx->pGame, &missile);
        }
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static __forceinline int CLIENTS_GetUnitX_Shrine(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitY_Shrine(D2UnitStrc* pUnit)
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

// 0x005830E0
void __fastcall D2GAME_SHRINES_Exploding_6FC770D0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nItemsToDrop = ITEMS_RollLimitedRandomNumber(&pOp->hObject->pSeed, pShrinesTxtRecord->dwArg1 - pShrinesTxtRecord->dwArg0) + pShrinesTxtRecord->dwArg0;
    for (int i = 0; i < nItemsToDrop; ++i)
    {
        const int nItemIndex = DATATBLS_GetItemIdFromItemCode(' mpo');

        D2_ASSERT(nItemIndex != -1, 2226);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hPlayer, &pCoord);
        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pOp->hPlayer), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = 0;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pOp->pGame;
            itemDrop.wItemFormat = pOp->pGame->wItemFormat;
            itemDrop.nId = nItemIndex;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pOp->hPlayer, 0);
            itemDrop.nQtyOverride = 1;

            D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pOp->pGame, &itemDrop, 0);

            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 1, 0);
            UNITROOM_RefreshUnit(pItem);

            if (pItem)
            {
                pItem->dwFlags |= 1;
            }
        }
    }

    int nXOffsets[] = { -6, -6, 0, 0, 6, 6 };
    int nYOffsets[] = { 6, -6, 6, -6, 6, -6 };

    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1312;
        missileParams.nX = CLIENTS_GetUnitX_Shrine(pOp->hObject);
        missileParams.nY = CLIENTS_GetUnitY_Shrine(pOp->hObject);
        missileParams.nTargetX = missileParams.nX + nXOffsets[i];
        missileParams.nTargetY = missileParams.nY + nYOffsets[i];
        missileParams.pOwner = pOp->hPlayer;
        missileParams.pOrigin = pOp->hObject;
        missileParams.nGfxArg = 1;
        missileParams.nMissile = 45;

        int nSkillLevel = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_LEVEL, 0) / 5;
        if (nSkillLevel < 1)
        {
            nSkillLevel = 1;
        }
        else if (nSkillLevel > 8)
        {
            nSkillLevel = 8;
        }
        missileParams.nSkillLevel = nSkillLevel;

        MISSILES_CreateMissileFromParams(pOp->pGame, &missileParams);
    }
}

// 0x00583410
void __fastcall D2GAME_SHRINES_Poison_6FC773B0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nItemsToDrop = ITEMS_RollLimitedRandomNumber(&pOp->hObject->pSeed, pShrinesTxtRecord->dwArg1 - pShrinesTxtRecord->dwArg0) + pShrinesTxtRecord->dwArg0;
    for (int i = 0; i < nItemsToDrop; ++i)
    {
        const int nItemIndex = DATATBLS_GetItemIdFromItemCode(' mpg');

        D2_ASSERT(nItemIndex != -1, 2292);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hPlayer, &pCoord);
        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pOp->hPlayer), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = 0;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pOp->pGame;
            itemDrop.wItemFormat = pOp->pGame->wItemFormat;
            itemDrop.nId = nItemIndex;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pOp->hPlayer, 0);
            itemDrop.nQtyOverride = 1;

            D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pOp->pGame, &itemDrop, 0);

            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 1, 0);
            UNITROOM_RefreshUnit(pItem);

            if (pItem)
            {
                pItem->dwFlags |= 1;
            }
        }
    }

    int nXOffsets[] = { -6, -6, 0, 0, 6, 6 };
    int nYOffsets[] = { 6, -6, 6, -6, 6, -6 };

    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1312;
        missileParams.nX = CLIENTS_GetUnitX_Shrine(pOp->hObject);
        missileParams.nY = CLIENTS_GetUnitY_Shrine(pOp->hObject);
        missileParams.nTargetX = missileParams.nX + nXOffsets[i];
        missileParams.nTargetY = missileParams.nY + nYOffsets[i];
        missileParams.pOwner = pOp->hPlayer;
        missileParams.pOrigin = pOp->hObject;
        missileParams.nGfxArg = 1;
        missileParams.nMissile = 48;

        int nSkillLevel = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_LEVEL, 0) / 5;
        if (nSkillLevel < 1)
        {
            nSkillLevel = 1;
        }
        else if (nSkillLevel > 8)
        {
            nSkillLevel = 8;
        }
        missileParams.nSkillLevel = nSkillLevel;

        MISSILES_CreateMissileFromParams(pOp->pGame, &missileParams);
    }
}

// 0x00583F10
int __fastcall OBJECTS_OperateFunction51_JungleStash(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_AIRESET, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[1] + 1, 0, 0);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
        OBJECTS_SetUnitIdInTimerArg(pOp->hObject, !pOp->hPlayer ? -1 : pOp->hPlayer->dwUnitId);
    }

    return 1;
}

// 0x00586410
int __fastcall OBJECTS_OperateFunction01_Casket(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x00586520
int __fastcall OBJECTS_OperateFunction68_EvilUrn(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 255 <= pObjectsTxtRecord->dwParm[7])
        {
            D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
            const int nMonCount = pMonsterRegion->nMonCount;
            for (int i = 0; i < nMonCount; ++i)
            {
                const int nMonsterId = pMonsterRegion->pMonData[i].nMonHcIdx;
                if (sub_0046C140_TestMonModeFlag(nMonsterId, MONMODE_WALK))
                {
                    MONSTERUNIQUE_SpawnUniqueGroup(pOp->pGame, UNITS_GetRoom(pOp->hObject), 0, nMonsterId, 1, 0, 0, 1);
                    break;
                }
            }
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005866C0
int __fastcall OBJECTS_OperateFunction03_Urn_Basket_Jar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005867A0
int __fastcall OBJECTS_OperateFunction14_Corpse(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005868A0
int __fastcall OBJECTS_OperateFunction05_Barrel(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

        if (pOp->hPlayer && pOp->hPlayer->dwUnitType == UNIT_PLAYER)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pOp->hPlayer, 1, -1);
            if (pSkill)
            {
                UNITS_SetTargetUnitForDynamicUnit(pOp->hPlayer, pOp->hObject);
                StartModeID(pOp->pGame, pOp->hPlayer, pSkill, SKILLS_GetSkillMode(pSkill), UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId, 0);
            }
        }

        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);
        UNITS_FreeCollisionPath(pOp->hObject);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    return 0;
}
