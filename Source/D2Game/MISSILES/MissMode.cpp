#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_INVALID 6
#define PLAYERLIST_FLAG_HOSTILE 8
#define STAT_TOHIT 19
#define UNITFLAGEX_0x40000 0x40000
#define PATHTYPE_CHARGEDBOLT 10
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define MONMODE_NEUTRAL 1
#define STAT_MANA 8
#define QUEST_A5Q6_BAAL 36
#define STAT_HITPOINTS 6
#define STAT_DAMAGEPERCENT 25
#define STAT_COLDLENGTH 56
#define UNITFLAG_ISMERC 0x00000200
#define UNITFLAG_NOTC 0x00020000
struct D2MonsterDataStrc;
struct D2ModeChangeStrc;
struct D2MonStatsTxt;
struct D2MissilesTxt;
struct D2UnkFieldsStrc;
struct D2StaticPathStrc;
struct D2HitFunc22ParamStrc;
struct D2AuraCallbackStrc;
struct D2SeedStrc;
struct D2SkillsTxt;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x08];
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    union
    {
        D2SeedStrc tSeed;
        D2SeedStrc pSeed;
    };
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    int unk0x30[5];
    int nSeqCurrentFramePrecise;
    unsigned char unk_48[0x7C];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2MonsterDataStrc
{
    char pad0x00[0x16];
    unsigned short nTypeFlag;
};

struct D2GameStrc
{
    char pad0x00[0xA8];
    unsigned int dwGameFrame;
    char pad0xAC[0x1074];
    D2UnitStrc* pUnitList[5][128];
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
};

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

struct D2MonStatsTxt
{
    char pad0x00[0x02];
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2MissilesTxt
{
    int unk0x00;
    unsigned char nFlags[4];
    short unk0x08[2];
    short wSrvDoFunc;
    short wSrvHitFunc;
    unsigned char unk_10[0x14];
    short wHitSubMissile[4];
    unsigned char unk_2C[0xA];
    short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    unsigned char unk_6C[0xC];
    int dwDmgParam[2];
    char unk0x80[0x10];
    unsigned int dwDmgCalc;
    unsigned char unk_94[0xE4];
    unsigned char nAnimLen;
    unsigned char unk_179[0xD];
    unsigned char nCollideKill;
    char pad0x187[0x1D];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char pad0xA84[0xE0];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB6C - 4];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0xBA0 - 0xB98 - 4];
    int nSkillsTxtRecordCount;
};

struct D2UnkFieldsStrc
{
    char pad0x00[0x18];
    int nUnk0x18;
    int nUnk0x1C;
    unsigned char nUnk0x20;
};

enum D2MiscConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    MONMODE_DEATH = 0,
    MONMODE_GETHIT = 3,
    EVENTTYPE_MONUMOD = 7,
    SKILL_MONTELEPORT = 184,
    MONSTER_SANDLEAPER1 = 78,
    STATE_FREEZE = 1,
    STATE_BLAZE = 13,
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" UModInitFunc gpUModInitFunctions_0073C008[]; // 0x0073C008
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet); // 0x005DD250
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag); // 0x0055B300
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag, int bSet); // 0x0055B260
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0053DA90
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
void* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
void __stdcall sub_005A6600(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlag, D2ModeChangeStrc* pModeChange); // 0x005A6600
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
void __fastcall sub_005A9930_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam); // 0x005A9930
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2HitFunc22ParamStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkillId;
    int nLevel;
    int nParam;
    int nHitSubMissile;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);
void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear);
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8);
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __cdecl sub_00476AF0_ClearGlobals();

enum D2C_M57MissHitConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

int __fastcall MONSTERSPAWN_SpawnRandomMonsterForLevel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005B3570

struct D2SkillsTxt
{
    char unk0x000[0x138];
    int dwCalc[4];
    int dwParam[8];
    char unk0x168[0xD4];
};

extern const int gnSrvHit52_XOffsets_006E2A58[8]; // 0x006E2A58
extern const int gnSrvHit52_YOffsets_006E2A38[8]; // 0x006E2A38
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_005D5BF0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nCalc, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops); // 0x005A9370
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __fastcall sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel); // 0x0056D810
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId); // 0x005444B0
void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMissile); // 0x0058E920
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647D00
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD2F0
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __fastcall sub_004638A0(int nMonsterId, int nFlag); // 0x004638A0

typedef int(__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);
extern MISSILESRVHITFN gpfMissileSrvHitFn[]; // 0x0073C840
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

enum
{
    MISSILESFLAGINDEX_TOWN = 10,
    MISSILESFLAGINDEX_SRCTOWN = 11,
};

typedef int(__fastcall* MISSMODE_SRVDO)(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern MISSMODE_SRVDO gMissileSrvDoFuncTable_0073C768[]; // 0x0073C768
extern int gnMissileSrvDoFuncCount_0073C71C; // 0x0073C71C
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

// 0x0059F840
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pUnit = pGame->pUnitList[4][i];
        while (pUnit)
        {
            D2UnitStrc* pCurrent = pUnit;
            pUnit = SUNIT_GetNextUnitFromList(pUnit);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x005A01B0
void __fastcall MONSTERUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    if (bSet)
    {
        pMonsterData->nTypeFlag |= nFlag;
    }
    else
    {
        pMonsterData->nTypeFlag &= ~nFlag;
    }
}

// 0x005A2100
void __fastcall sub_6FC6F670(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pCallback = gpUModInitFunctions_0073C008[nUMod];
    if (pCallback)
    {
        pCallback(pUnit, nUMod, bUnique);
    }
}

// 0x005A25F0
void __fastcall MONSTERUNIQUE_FireEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

// 0x005A37D0
void __fastcall MONSTERUNIQUE_LightningEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && pBoss && pBoss->dwAnimMode == MONMODE_GETHIT)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}

// 0x005A3800
void __fastcall MONSTERUNIQUE_ColdEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if ((bUnique || nUMod != 18) && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

// 0x005A5840
void __fastcall PARTYSCREEN_ToggleIgnore(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 2) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 2, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A58A0
void __fastcall PARTYSCREEN_ToggleSquelch(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 4) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 4, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A6230
void __fastcall sub_005A6230_GetFields(D2UnkFieldsStrc* pFields, int* pUnk0x18, int* pUnk0x1C, unsigned char* pUnk0x20)
{
    *pUnk0x18 = pFields->nUnk0x18;
    *pUnk0x1C = pFields->nUnk0x1C;
    *pUnk0x20 = pFields->nUnk0x20;
}

// 0x005A8000
void __fastcall sub_005A8000_ModeChangeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused)
{
    D2ModeChangeStrc modeChange;
    modeChange.pUnit = pUnit;
    modeChange.pTargetUnit = pTarget;
    sub_005A6600(pGame, pUnit, 1, &modeChange);
}

// 0x005A91C0
void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pUnit)
    {
        return;
    }

    pDamage->dwHitFlags &= ~0x700;
    pDamage->dwPhysDamage = 0;
    pDamage->dwFireDamage = 0;
    pDamage->dwLtngDamage = 0;
    pDamage->dwMagDamage = 0;
    pDamage->dwColdDamage = 0;
    pDamage->dwPoisDamage = 0;
    pDamage->dwLifeLeech = 0;
    pDamage->dwManaLeech = 0;
    pDamage->dwStamLeech = 0;
    pDamage->dwStunLen = 0;
    pDamage->dwBurnDamage = 0;

    switch (MISSILE_GetElemTypeFromMissileId(pUnit->dwClassId))
    {
    case ELEMTYPE_POIS:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwColdLen = 0;
        pDamage->dwPoisLen = 0;
        pDamage->dwFrzLen = 0;
        break;

    default:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;

    case ELEMTYPE_COLD:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;
    }
}

// 0x005A9270
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage)
{
    if (!pMissile)
    {
        return;
    }

    switch (MISSILE_GetElemTypeFromMissileId(pMissile->dwClassId))
    {
    case ELEMTYPE_NONE:
        pDamage->dwPhysDamage += nDamage;
        break;
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        break;
    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        break;
    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        break;
    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        break;
    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;
    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;
    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage = nDamage;
        break;
    default:
        break;
    }
}

// 0x005ABEB0
int __fastcall MISSMODE_SrvHit33_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
        }
    }

    return 0;
}

// 0x005AC020
int __fastcall MISSMODE_SrvHit37_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 2;
    }

    return 0;
}

// 0x005AD290
void __fastcall MISSMODE_SrvDmg04_IceBlast(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    pDamage->dwFrzLen = pDamage->dwColdLen;
    pDamage->dwColdLen = 0;
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static int D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005A1600
void __fastcall MONSTERUNIQUE_UMod26_Teleport(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && bUnique)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_MONTELEPORT, 1, 1);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
        AIUTIL_ToggleAiControlFlag0x20(pUnit, 1);
    }
}

// 0x005A54F0
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pDamage->wResultFlags & 4)
    {
        const int nBaseId = D2GAME_GetMonsterBaseId_6FC64B10(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1 && !STATES_CheckState(pUnit, STATE_FREEZE))
        {
            pDamage->wResultFlags |= 8;
        }
    }
}

// 0x005A60E0
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((pPlayer1 ? pPlayer1->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 36);

    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 1);
}

// 0x005ABE50
int __fastcall MISSMODE_SrvHit32_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit && !MISSILE_GetTargetX(pMissile))
    {
        sub_005A9930_CreateCairnPortal(pGame, pMissile, pMissilesTxtRecord->dwParam[3]);
    }

    return 0;
}

// 0x005AC480
int __fastcall MISSMODE_SrvHit45_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0 || pMissilesTxtRecord->dwHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = UNITS_GetXPosition(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->dwHitPar[1])
    {
        missileParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;
    }

    sub_6FD14260(pGame, pMissilesTxtRecord->dwHitPar[0], &missileParams);
    return 1;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// build: symbol ?xOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E2618
// build: symbol ?xOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E2510
// build: symbol ?yOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E25F8
// build: symbol ?yOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E24D0
// 0x005A88E0
int __fastcall sub_005A88E0_RollMissileHit(D2UnitStrc* pMissile, int nUnused, D2UnitStrc* pOwner, D2UnitStrc* pUnit)
{
    int nToHit = 0;
    if (pMissile)
    {
        nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
    }

    return SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1) != 0;
}

// 0x005A9370
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pOwner || !pOrigin)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPosition(pOrigin);
    missileParams.nY = CLIENTS_GetUnitY(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    if (nMainStep < 1)
    {
        nMainStep = 1;
    }

    static const int xOffsets[16] = { 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1 };
    static const int yOffsets[16] = { 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 2 };

    for (int i = 0; i < 16; i += nMainStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (nSubStep)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;

        for (int i = 0; i < 15; i += nSubStep)
        {
            missileParams.nTargetX = xOffsets[i + 1];
            missileParams.nTargetY = yOffsets[i + 1];
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }

    return 1;
}

// 0x005A9930
void __fastcall sub_005A9930_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2GAME_CreatePortalObject_6FD13DF0(pGame, pOwner, UNITS_GetRoom(pMissile), UNITS_GetXPositionInline(pMissile), UNITS_GetYPositionInline(pMissile), nParam, 0, 60, 1);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pMissile), 1);
}

// 0x005AB2A0
int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

// 0x005AB630
int __fastcall MISSMODE_FistOfTheHeavensDelay_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pParams->nParam > 0 && pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

// 0x005AB700
int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPositionInline(pOrigin);
    missileParams.nY = UNITS_GetYPositionInline(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = nSkillLevel - 1;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    static const int xOffsets[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
    static const int yOffsets[8] = { 2, 2, 0, -2, -2, -2, 0, 2 };

    for (int i = 0; i < 8; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005ABA00
int __fastcall MISSMODE_SrvHit27_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    return 1;
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

void __fastcall sub_004CC870_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
{
    D2UnitStrc* pOwner = (D2UnitStrc*)nInitArg;
    if (!pMissile)
        return;

    D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pOwner)
        return;

    int nOffset = 0;
    if (pMissilesTxtRecord->dwCltParam[1] > 0)
        nOffset = SEED_RollLimitedRandomNumber(&pOwner->tSeed, pMissilesTxtRecord->dwCltParam[1]) - pMissilesTxtRecord->dwCltParam[1] / 2;

    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->tSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

// build: context sub_004CC9A0_CltHitProgOverlay
int __fastcall sub_004CC9A0_CltHitProgOverlay(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit && pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nOverlay = pMissilesTxtRecord->wProgOverlay;
            if (nOverlay > 0)
                sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
        }
    }
    return 1;
}

int __fastcall sub_004CCCA0_CltHitFlagOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
        pOwner->dwFlagEx |= UNITFLAGEX_0x40000;
    return 1;
}

// 0x005AC040
void __fastcall sub_004CCCC0_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused)
{
    if (!pMissile)
        return;

    const int nRange = MISSILE_GetTotalFrames(pMissile) > 255 ? 255 : MISSILE_GetTotalFrames(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->tSeed, D2COMMON_10175_PathGetFirstPointX(pPath));
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nRange);
    D2Common_10142(pPath, pMissile, 0);
}

int __fastcall sub_004CCF00_CltHitClearGlobals(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        sub_00476AF0_ClearGlobals();
        return 1;
    }
    return 0;
}

// 0x005AC1D0
int __fastcall MISSMODE_SrvHit39_ImpSpawnMonsters(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    MONSTERSPAWN_SpawnRandomMonsterForLevel(pGame, UNITS_GetRoom(pMissile), UNITS_GetXPositionInline(pMissile), UNITS_GetYPositionInline(pMissile));
    return 1;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AC250
int __fastcall MISSMODE_SrvHit40_CatapultSpikeBall(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pMissile)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    int nCalc = pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];
    if (nCalc <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nCalc < 1)
        {
            nCalc = 1;
        }
    }

    sub_005D5BF0(pGame, pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->wHitSubMissile[0], nCalc, nCalc / 4, MISSILE_GetSkill(pMissile), nLevel);
    return 1;
}

// 0x005AC800
int __fastcall MISSMODE_SrvHit50_PlagueVinesTrail(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pUnit)
    {
        const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
        if (nFrames < MISSILE_GetTotalFrames(pMissile) - pMissilesTxtRecord->dwHitPar[0])
        {
            return 2;
        }
    }

    return 0;
}

// 0x005AC870
int __fastcall MISSMODE_SrvHit51_VolcanoDebris(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    if (pMissilesTxtRecord->wHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[1];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (pMissilesTxtRecord->wHitSubMissile[2] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[2];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005AC940
int __fastcall MISSMODE_SrvHit52_BladeFury(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    for (int i = 0; i < 8; i += nParam)
    {
        missileParams.nTargetX = gnSrvHit52_XOffsets_006E2A58[i];
        missileParams.nTargetY = gnSrvHit52_YOffsets_006E2A38[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, gnSrvHit52_XOffsets_006E2A58[i]);
            MISSILE_SetTargetY(pHitSubMissile, gnSrvHit52_YOffsets_006E2A38[i]);
        }
    }

    return 1;
}

// 0x005ACAF0
int __fastcall MISSMODE_SrvHit54_BaalSpawnMonsters(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, MISSILE_GetSkill(pMissile));
        if (pSkill)
        {
            const int nMonsterId = SKILLS_GetParam1(pSkill);
            D2GAME_SpawnPresetMonster_6FC66560(pGame, UNITS_GetRoom(pMissile), nMonsterId, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MONMODE_NEUTRAL);
        }
    }

    return 1;
}

// 0x005ACB60
int __fastcall MISSMODE_SrvHit55_Baalnferno(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 2;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->dwHitPar[0] <= 0)
    {
        return 1;
    }

    const int nCurrentMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    if (nCurrentMana <= 0)
    {
        return 1;
    }

    const int nPercentage = D2_MIN(D2_MAX(pMissilesTxtRecord->dwHitPar[0], 1), 100);
    int nLostMana = DATATBLS_ApplyRatio(nCurrentMana, nPercentage, 100);
    nLostMana = D2_MIN(D2_MAX(nLostMana, 1), nCurrentMana);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nCurrentMana - nLostMana, 0);
    return 2;
}

// 0x005ACF20
int __fastcall MISSMODE_SrvHit59_BaalTauntPoisonControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nHitPar = pMissilesTxtRecord->dwHitPar[0];
    if (nHitPar < 1)
    {
        nHitPar = 1;
    }

    MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, pOwner, pMissile, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nHitPar, 2, 0);
    return 1;
}

// 0x005ACFC0
int __fastcall sub_005ACFC0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    if (nSkillId > 0 && nLevel > 0 && SUNIT_GetOwner(pGame, pMissile))
    {
        if (pUnit)
        {
            UNITS_SetTargetUnitForDynamicUnit(pMissile, pUnit);
        }

        sub_6FD14400(pGame, pMissile, pMissilesTxtRecord->dwHitPar[0], nSkillId, nLevel);
    }

    return 1;
}

// 0x005AD970
int __fastcall MISSMODE_SrvHit57_BaalFxControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit && !MISSILE_GetTargetX(pMissile))
    {
        MISSILE_SetTargetX(pMissile, 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (QUESTS_CheckNotIntroQuest(pGame, QUEST_A5Q6_BAAL))
        {
            ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
        }

        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    return 0;
}

// 0x005B07A0
int __fastcall MISSMODE_SrvHit04_ExplodingArrow_FreezingArrow_RoyalStrikeMeteorCenter(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    for (int i = 0; i < 4; ++i)
    {
        if (pMissilesTxtRecord->wHitSubMissile[i] > 0)
        {
            missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[i];

            D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
            if (pHitSubMissile && pMissilesTxtRecord->dwHitPar[0] > 0)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pHitSubMissile, pUnit, 1);
            }
        }
    }

    return 3;
}

// 0x005B0870
int __fastcall sub_005B0870(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    for (int i = 0; i < 4; ++i)
    {
        if (pMissilesTxtRecord->wHitSubMissile[i] > 0)
        {
            missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[i];

            D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
            if (pHitSubMissile && pMissilesTxtRecord->dwHitPar[0] > 0)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pHitSubMissile, pUnit, 1);
            }
        }
    }

    return 1;
}

#include "gen/data/Source/D2Game/MISSILES/MissMode.inc"

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005AC350
int __fastcall sub_005AC350(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 1;
    }

    const int nMin = SKILLS_GetMinPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nHeal = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin) + nMin;

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints != nMaxHitpoints && (short)pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, (short)pMissilesTxtRecord->wProgOverlay, 0);
    }

    nHitpoints += nHeal;
    if (nHitpoints >= nMaxHitpoints)
    {
        nHitpoints = nMaxHitpoints;
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    return pMissilesTxtRecord->nCollideKill != 0;
}

// 0x005ACDF0
int __fastcall MISSMODE_SrvHit58_BaalTauntLightningControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSeedX = CLIENTS_GetUnitX(pMissile);
    SEED_InitLowSeed(&pMissile->pSeed, nSeedX);
    const int nParam = D2_MAX(1, pMissilesTxtRecord->dwHitPar[0]);

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);
    const int nTargetX = nX + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nParam + 1) - nParam;
    const int nTargetY = nY + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nParam + 1) - nParam;

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 32;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = sub_0064A280(pMissile);
    missileParams.nSkillLevel = sub_0064A210(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nTargetX = nTargetX;
    missileParams.nTargetY = nTargetY;

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005AD050
void __fastcall MISSMODE_SrvDmg01_FireArrow_MagicArrow_ColdArrow(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwDmgCalc, -1, -1);
    if (nPercentage <= 0)
    {
        return;
    }

    nPercentage = D2_MIN(nPercentage, 100);

    const int nPhysDamage = pDamage->dwPhysDamage;
    int nDamageReduction = DATATBLS_ApplyRatio(nPhysDamage, nPercentage, 100);
    nDamageReduction = D2_MIN(nDamageReduction, nPhysDamage);
    pDamage->dwPhysDamage = nPhysDamage - nDamageReduction;
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamageReduction);
}

// 0x005AD1B0
void __fastcall MISSMODE_SrvDmg02_IceArrow_RoyalStrikeChaos(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const int nColdLength = STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
        pDamage->dwFrzLen = DATATBLS_ApplyRatio(nColdLength, pMissilesTxtRecord->dwDmgParam[0] < 0 ? 0 : pMissilesTxtRecord->dwDmgParam[0], 100);
        pDamage->dwColdLen = 0;
    }
}

// 0x005AD3E0
void __fastcall MISSMODE_SrvDmg07_Warcry_ShockWave(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        nStunLength = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nLevel);
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD450
void __fastcall MISSMODE_SrvDmg08_EruptionCrack(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 0);
    }
}

// 0x005AD4A0
void __fastcall MISSMODE_SrvDmg09_Twister(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        nStunLength = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1];
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD530
void __fastcall MISSMODE_SrvDmg11_RabiesContagion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nPoisonLength = MISSILE_GetTargetX(pMissile) - pGame->dwGameFrame;
    if (nPoisonLength < 10 || nPoisonLength > SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1))
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    pDamage->dwPoisLen = nPoisonLength;
}

// 0x005AD5C0
void __fastcall MISSMODE_SrvDmg13_BlessedHammerEx(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
        if (pOwner)
        {
            pDamage->dwPhysDamage += pDamage->dwPhysDamage * STATLIST_UnitGetStatValue(pOwner, STAT_DAMAGEPERCENT, 0) / 100;
        }

        MISSMODE_SrvDmg05_BlessedHammer(pGame, pMissile, pUnit, pDamage);
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005AD220
void __fastcall MISSMODE_SrvDmg03_Blaze_FireWall_ImmolationFire_MeteorFire(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const int nRand = SEED_RollRandomNumber(&pMissile->pSeed) & 127;
        if (nRand < pMissilesTxtRecord->dwDmgParam[0])
        {
            pDamage->wResultFlags |= 0x4000;
        }
    }
}

// 0x005AD2F0
void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nBaseDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    if (pMissilesTxtRecord->dwDmgParam[0] > 0 && MONSTERS_IsUndead(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[0], 100));
    }

    if (pMissilesTxtRecord->dwDmgParam[1] > 0 && MONSTERS_IsDemon(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[1], 100));
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

// 0x005AD3A0
void __fastcall MISSMODE_SrvDmg06_MarkTargetNoTreasureClass(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner && !UNIT_HasFlag(pOwner, UNITFLAG_ISMERC) && pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
}

// 0x005AD630
void __fastcall MISSMODE_SrvDmg14_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile || pMissile->dwUnitType != 3)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pUnit)
    {
        return;
    }

    int nChance = 0;
    if (pUnit->dwUnitType == 0)
    {
        if (pMissilesTxtRecord->dwDmgParam[0] < 1)
        {
            return;
        }
        nChance = pMissilesTxtRecord->dwDmgParam[1];
    }
    else if (pUnit->dwUnitType == 1)
    {
        const int nParam = pMissilesTxtRecord->dwDmgParam[0];
        if (nParam < 1)
        {
            if (!sub_004638A0(pUnit->dwClassId, 10))
            {
                return;
            }
            nChance = pMissilesTxtRecord->dwDmgParam[1];
        }
        else if (nParam == 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (sub_004638A0(nClassId, 10))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!sub_004638A0(nClassId, 11))
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                return;
            }
        }
        else if (nParam > 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (sub_004638A0(nClassId, 10))
            {
                nChance = 3 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!sub_004638A0(nClassId, 11))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pMissile->pSeed, 100) < nChance)
    {
        pDamage->wResultFlags |= 8;
    }
}

// 0x005AD930
static __forceinline void sub_005AD930_BaalFxOpenPortal(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (QUESTS_CheckNotIntroQuest(pGame, QUEST_A5Q6_BAAL))
    {
        ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
    }

    DUNGEON_ToggleHasPortalFlag(pRoom, 1);
}

void __fastcall sub_M250_Emit_005AD930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    sub_005AD930_BaalFxOpenPortal(pGame, pMissile);
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AD9D0
void __fastcall sub_005AD9D0_HitAndRemoveMissile(D2GameStrc* pGame, D2UnitStrc* pMissile, int bHit)
{
    const int nMissileId = !pMissile ? -1 : pMissile->dwClassId;
    if (bHit)
    {
        const short nHitFunc = DATATBLS_GetMissilesTxtRecord(nMissileId)->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, 0);
        }
    }

    SUNIT_RemoveUnit(pGame, pMissile);
}

// 0x005ADAF0
void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

inline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline int IsUnitInTown(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    return pRoom && DUNGEON_IsRoomInTown(pRoom);
}

// 0x005ADBB0
static __declspec(noinline) void __stdcall sub_005ADBB0_MISSMODE_SrvDo(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSrvDoFunc <= 0 || pMissilesTxtRecord->wSrvDoFunc >= gnMissileSrvDoFuncCount_0073C71C)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        pRoom = COLLISION_GetRoomBySubTileCoordinates(0, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if ((pMissilesTxtRecord->nFlags[MISSILESFLAGINDEX_SRCTOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_SRCTOWN & 7]) && pOwner && IsUnitInTown(pOwner)
        || pOwner && pOwner->dwUnitType == 0 && IsUnitInTown(pOwner)
        || !(pMissilesTxtRecord->nFlags[MISSILESFLAGINDEX_TOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_TOWN & 7]) && DUNGEON_IsRoomInTown(pRoom)
        || gMissileSrvDoFuncTable_0073C768[pMissilesTxtRecord->wSrvDoFunc](pGame, pMissile) == 2)
    {
        SUNIT_RemoveUnit(pGame, pMissile);
    }
}

// 0x005ADCC0
void __fastcall sub_005ADCC0(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused)
{
    sub_005ADBB0_MISSMODE_SrvDo(pGame, pMissile);
}
