#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define UNITFLAG_TARGETABLE 0x00000002
#define UNITFLAG_ISVALIDTARGET 0x00000008
#define MONMODE_DEATH 0
#define MONMODE_GETHIT 3
#define STAT_ITEM_ARMOR_PERCENT 16
#define STAT_SECONDARY_MINDAMAGE 23
#define STAT_SECONDARY_MAXDAMAGE 24
#define MONSTER_ROGUEHIRE 271
#define MISSILE_MONSTERCORPSEEXPLODE 117
#define MISSILE_BUGLIGHTNING 225
#define MISSILE_QUEENPOISONCLOUD 321
#define MISSILE_FROSTNOVA 119
#define MISSILE_CORPSEPOISONCLOUD 155
#define MISSILE_COLDUNIQUE 194
#define MONMODE_SKILL1 8
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_GOOD 2
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_MONUMOD 7
#define SKILL_SELF_RESURRECT 293
#define MONTYPEFLAG_RESURRECTED 8
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STATE_UNINTERRUPTABLE 54
#define UNITFLAG_NOXP 0x04000000
#define PARTYSCREENTYPE_HOSTILE 3
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;
struct D2ModeChangeStrc;
struct D2SeedStrc;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct D2UnitStrc;
struct D2DamageStrc;
struct D2MissileStrc;
struct D2GameStrc;
struct D2CoordStrc;
struct D2DataTablesStrc;
struct D2ClientStrc;




struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    unsigned char unk_74[0x34];
    int dwGameFrame;
};

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480
void __fastcall MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A0E80
void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A29A0
void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A3040
void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
extern const int gnBugLightningXOffsets_006E21A8[]; // 0x006E21A8
extern const int gnBugLightningYOffsets_006E2198[]; // 0x006E2198


struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned char nTypeFlag;
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0x122];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00561E70
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

typedef void(__fastcall* PartyCommandFunc)(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure);

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern PartyCommandFunc gpfPartyCommands_6FD28E60[10]; // 0x006E2218
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
void __fastcall sub_6FC7D260(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057E990
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x005A60E0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

enum D2C_M187TrapConstants
{
    STAT_LEVEL = 12,
    STAT_TOHIT = 19,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
    MONSTER_TRAP_FIREBOLT = 326,
    MONSTER_TRAP_HORZMISSILE = 327,
    MONSTER_TRAP_VERTMISSILE = 328,
    MONSTER_TRAP_POISONCLOUD = 329,
    MONSTER_TRAP_LIGHTNING = 330,
    MONSTER_TRAP_NOVA = 369,
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0059F8A0
void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_AllocMissileData(pMissile);
    pMissile->dwUnitId = nUnitGUID;
    pMissile->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_ISVALIDTARGET);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pMissile);
    sub_6FC35570(pGame, pMissile, 0, 0, 0);
}

// 0x005A11F0
void __fastcall MONSTERUNIQUE_UMod37_Fanatic(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && bUnique)
    {
        STATLIST_SetUnitStat(pUnit, STAT_ITEM_ARMOR_PERCENT, -70, 0);
        MONSTERUNIQUE_UMod16_Champion(pUnit, nUMod, bUnique);
    }
}

// 0x005A2840
void __fastcall MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);

    D2UnitStrc* pMissile = sub_6FD11420(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile)
    {
        return;
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = 0x6400;
    damage.dwFireDamage = 0x6400;
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 6, &damage, 0, 0, 0, 0x583);
}

// 0x005A2BA0
void __fastcall sub_6FC6CD30(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && (!pUnit || pUnit->dwAnimMode != MONMODE_GETHIT))
    {
        MONSTERUNIQUE_CastLightUniqueMissile(pGame, pUnit, nUMod, bUnique);
    }
}

// 0x005A2BD0
void __fastcall MONSTERUNIQUE_CastColdUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 2;
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    sub_6FD14170(pGame, pUnit, pUnit, MISSILE_COLDUNIQUE, 0, nLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
}

// 0x005A2C20
void __fastcall MONSTERUNIQUE_CastCorpsePoisonCloud(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    sub_6FD11420(pGame, MISSILE_CORPSEPOISONCLOUD, pUnit, 0, nLevel, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
}

// 0x005A2CC0
void __fastcall MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused)
{
    D2GameStrc* pGame = (D2GameStrc*)pGameArg;
    AIGENERAL_FreeMinionList(pUnit);
    AIGENERAL_SetOwnerData(pGame, pUnit, -1, 1, 0, 0);

    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }
}

// 0x005A2E00
void __fastcall sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage <= 0)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || pOwner->dwClassId != MONSTER_ROGUEHIRE)
    {
        return;
    }

    nMinDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MINDAMAGE, 0) << 8) - 256;
    nMaxDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MAXDAMAGE, 0) << 8) - 256;

    if (nMinDamage < 0)
    {
        nMinDamage = 0;
    }

    if (nMaxDamage < 0)
    {
        nMaxDamage = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_MINDAMAGE, nMinDamage, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXDAMAGE, nMaxDamage, 0);
}

// 0x005A2EE0
void __fastcall MONSTERUNIQUE_CastBugLightningMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_BUGLIGHTNING;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nX = gnBugLightningXOffsets_006E21A8[i] + nUnitX;
        const int nY = gnBugLightningYOffsets_006E2198[i] + nUnitY;

        for (int j = 0; j < 2; ++j)
        {
            missileParams.pInitArgs = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A30B0
void __fastcall sub_6FC6D440(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        MONSTERUNIQUE_ApplyElementalDamage(pGame, pUnit, nUMod, bUnique);
    }
}

#include "gen/data/Source/D2Game/MONSTER/MonsterUnique.inc"

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

// 0x005A30E0
void __fastcall MONSTERUNIQUE_StealBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < 30)
    {
        return;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || pTarget->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2InventoryStrc* pInventory = pTarget->pInventory;
    for (int i = 0; i < 16; ++i)
    {
        D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, i);
        if (pBeltItem)
        {
            if (pBeltItem->dwUnitType == UNIT_ITEM && pBeltItem->dwAnimMode == IMODE_INBELT && !INVENTORY_GetCursorItem(pInventory))
            {
                D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pBeltItem, pTarget, 1);
                D2CoordStrc pCoord;
                UNITS_GetCoords(pTarget, &pCoord);

                D2CoordStrc pReturnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pTarget), &pCoord, &pReturnCoords, 1, 1);
                D2_ASSERT(pRoom, 2762);

                ITEMS_SetItemFlag(pDupeItem, IFLAG_INSTORE, 1);
                D2GAME_DropItem_6FC52260(pGame, pTarget, pDupeItem, pRoom, pReturnCoords.nX, pReturnCoords.nY);
                const int nX = CLIENTS_GetUnitX(pBeltItem);
                sub_00561E70_RemoveFromBelt(pGame, pTarget, pBeltItem);
                sub_0055EDC0(pGame, pTarget, nX);
            }
            return;
        }
    }
}

// 0x005A3490
void __fastcall MONSTERUNIQUE_CastQueenPoisonCloudMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_QUEENPOISONCLOUD;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    const int nXOffsets[] = { 0, 1, 0, -1 };
    const int nYOffsets[] = { -1, 0, 1, 0 };

    for (int j = 0; j < 4; ++j)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nTargetX = nXOffsets[j] + nUnitX;
        const int nTargetY = nYOffsets[j] + nUnitY;

        for (int i = 0; i < 2; ++i)
        {
            missileParams.pInitArgs = i;
            missileParams.nTargetX = nTargetX;
            missileParams.nTargetY = nTargetY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A3840
void __fastcall sub_6FC6DD20(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_EVIL)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MONUMOD, 0);

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStatsTxtRecord->wAiParam[7][pGame->nDifficulty])
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
}

// 0x005A3910
void __fastcall sub_6FC6DDE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (!SUNIT_IsDead(pUnit) || STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_RESURRECTED)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
    {
        return;
    }

    if (COLLISION_CheckMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, COLLIDE_MASK_MONSTER_PATH))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
    else if (AIGENERAL_GetAiControlParam(pUnit, 1) < 2 && D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_SELF_RESURRECT, 0, 0, 0);
            if (pUnit)
            {
                pUnit->dwFlags &= 0xFBFDFFFF;
            }
            const int nParam = AIGENERAL_GetAiControlParam(pUnit, 1);
            AIGENERAL_SetAiControlParam(pUnit, 1, nParam + 1);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 51, 0, 0);
        }
    }
}

// 0x005A3A80
void __fastcall MONSTERUNIQUE_ApplyShatterState(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        STATES_ToggleState(pUnit, STATE_SHATTER, 1);
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A3AA0
void __fastcall sub_6FC6DFC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 3, 0, 0);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        sub_6FC7D260(pGame, pOwner, !pUnit ? -1 : pUnit->dwUnitId, 1);
        return;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

static __forceinline int MONSTERUNIQUE_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x005A3B50
void __fastcall MONSTERUNIQUE_SetTrapDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = 2;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (nLevelId)
    {
        nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
        nLevel = MAX(nLevel, 1);
    }

    const int nToHit = MIN(nLevel + 50, 90);
    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel, 0);
    STATLIST_SetUnitStat(pUnit, STAT_TOHIT, nToHit, 0);

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nUnitType == UNIT_MONSTER, 3138);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
    switch (MONSTERUNIQUE_GetClassIdInline(pUnit))
    {
    case MONSTER_TRAP_FIREBOLT:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    case MONSTER_TRAP_HORZMISSILE:
    case MONSTER_TRAP_VERTMISSILE:
    {
        const int nMinDamage = MIN(nLevel, (nLevel >> 1) + 1);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, nLevel, 0);
        break;
    }
    case MONSTER_TRAP_POISONCLOUD:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMINDAM, nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMAXDAM, 2 * nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONLENGTH, 2 * nLevel, 0);
        break;
    }
    case MONSTER_TRAP_LIGHTNING:
    case MONSTER_TRAP_NOVA:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    }
}

// 0x005A4EF0
void __fastcall sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame)
{
    if (pAttacker && pDefender && !UNIT_HasFlag(pDefender, UNITFLAG_NOXP))
    {
        SUNITDMG_DistributeExperience(pGame, pAttacker, pDefender);
    }
}

// 0x005A5490
void __fastcall sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DamageStrc damage = {};
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    }
}

// 0x005A5D50
void __fastcall sub_6FC7B3F0(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer2 == pPlayer1 || STATLIST_GetUnitBaseStat(pPlayer1, STAT_LEVEL, 0) < 9)
    {
        return;
    }

    FRIENDLY_OpenHostility(pGame, pPlayer2, pPlayer1);
    FRIENDLY_OpenHostility(pGame, pPlayer1, pPlayer2);

    SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 391)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer2 ? -1 : pPlayer2->dwUnitId, PARTYSCREENTYPE_HOSTILE);
}

// 0x005A6000
int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCallbackId, int nOtherPlayerGUID, int nParam)
{
    int bFailure = 0;
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOtherPlayerGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    if (gpfPartyCommands_6FD28E60[nCallbackId])
    {
        if (IsBadCodePtr((FARPROC)gpfPartyCommands_6FD28E60[nCallbackId]))
        {
            return 3;
        }

        gpfPartyCommands_6FD28E60[nCallbackId](pGame, pUnit, pOtherPlayer, nParam, &bFailure);
        if (bFailure)
        {
            return 3;
        }
    }

    return 0;
}

// 0x005A6130
int __fastcall sub_005A6130_AreUnitsFriendly(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nType1 = UNIT_INVALID;
    if (pUnit1)
    {
        nType1 = pUnit1->dwUnitType;
    }

    switch (nType1)
    {
    case UNIT_PLAYER:
        return !PLAYERLIST_CheckFlag(pUnit1, pUnit2, PLAYERLIST_FLAG_HOSTILE);

    case UNIT_MONSTER:
    {
        int nType2 = UNIT_INVALID;
        if (pUnit2)
        {
            nType2 = pUnit2->dwUnitType;
        }

        switch (nType2)
        {
        case UNIT_PLAYER:
            return !PLAYERLIST_CheckFlag(pUnit2, pUnit1, PLAYERLIST_FLAG_HOSTILE);

        case UNIT_MONSTER:
            return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
        }
        break;
    }
    }

    return 0;
}
