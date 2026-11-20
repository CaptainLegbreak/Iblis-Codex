#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2MonsterRegionStrc;
struct D2StaticPathStrc;
struct D2ModeChangeStrc;
struct D2MonsterDataStrc;
struct D2CurseStrc;
struct D2AuraCallbackStrc;
struct D2StaticFieldCallbackArgStrc;
struct D2BasicAuraParamStrc;
struct D2DamageAuraParamStrc;
struct D2UnkPalSkillStrc2;
struct D2AiCmdStrc;
struct D2DifficultyLevelsTxt;
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2UnitFindDataStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2DamageStrc;
struct D2MissileStrc;
struct D2DataTablesStrc;

enum D2C_F39Constants
{
    STAT_HITPOINTS = 6,
    STAT_MODIFIERLIST_SKILL = 350,
    STAT_MODIFIERLIST_LEVEL = 351,
    STATE_BLAZE = 13,
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    DAMAGERESULTFLAG_WILLDIE = 2,
    MONMODE_SKILL1 = 8,
    MISSILE_BOLT = 0x1F,
    SKILLSFLAGINDEX_01 = 1,
    STAT_ATTACKRATE = 0x44,
    STATE_FETISHAURA = 0x19,
    MONSTER_FETISH1 = 0x8D,
    MONSTER_FETISH2 = 0x8E,
    MONSTER_FETISH3 = 0x8F,
    MONSTER_FETISH4 = 0x90,
    MONSTER_FETISH5 = 0x91,
    MONSTER_FETISHBLOW1 = 0x18C,
    MONSTER_FETISHBLOW2 = 0x18D,
    MONSTER_FETISHBLOW3 = 0x18E,
    MONSTER_FETISHBLOW4 = 0x18F,
    MONSTER_FETISHBLOW5 = 0x190,
    MONMODE_SEQUENCE = 14,
    UNITFLAG_NOTC = 0x20000,
    EVENTTYPE_ENDANIM = 1,
    STAT_MAXHP = 7,
    STAT_MANA = 8,
    STAT_LEVEL = 12,
    STAT_THORNS_PERCENT = 0x83,
    STAT_CONVERSION_LEVEL = 0xB0,
    STAT_CONVERSION_MAXHP = 0xB1,
    STATE_NOMANAREGEN = 0x55,
    STATE_CONVERSION_SAVE = 0x6D,
    STATLIST_FLAG_8 = 8,
};


struct D2ModeChangeStrc
{
    int unk0x00[9];
};

struct D2MonsterDataStrc
{
    int unk0x00;
    unsigned char nComponent[16];
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    int unk0x08[4];
    int nIndex;
};

struct D2GameStrc
{
    char pad00[0x1c];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x34];
    int dwGameFrame;
    char unk0xAC[0x44];
    D2MonsterRegionStrc* pMonReg;
};



struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[9];
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int unk0x40[3];
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

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
    int unk0x38[7];
    void (__fastcall* pInitFunc)(D2UnitStrc* pMissile, int nInitArg);
    int nInitArg;
};

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    void* pStateRemoveCallback;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2BasicAuraParamStrc
{
    int nAuraState;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
    int field_40;
    D2StatListStrc* pStatList;
    int nPassiveState;
    void* pStateRemoveCallback;
};

struct D2DamageAuraParamStrc
{
    int nAuraState;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
    int field_40;
    D2StatListStrc* pStatList;
    int nPassiveState;
    D2DamageStrc* pDamage;
};

struct D2AiCmdStrc
{
    int unk0x00[2];
    int nCmdParam[5];
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x40];
    int dwStaticFieldMin;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x30];
    int dwParam[5];
    char unk0x4C[0x158];
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x3C];
    short wSrvMissileA;
    short wSrvMissileB;
    char unk0x04C[0x02];
    short wSrvOverlay;
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    short wAuraTargetState;
    short wAuraEvent[3];
    short wAuraEventFunc[3];
    char unk0x090[0x08];
    short nPassiveStat[5];
    char unk0x0A2[0x02];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x2E];
    short wSumOverlay;
    char unk0x0E8[0x28];
    short wCltOverlayA;
    char unk0x112[0x1C];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    int dwParam[4];
    char unk0x158[0x4D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0x10];
    int nItemStatCostTxtRecordCount;
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00554DE0
int __fastcall sub_0056B740_CallWithRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
D2UnitFindDataStrc* __fastcall sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50
void __fastcall sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0
void __fastcall sub_6FC68280(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit); // 0x00547E90
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2); // 0x005544B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2); // 0x005FD7B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80
void __fastcall sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0
void __fastcall sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY); // 0x0063E7E0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill); // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath); // 0x006505C0
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset); // 0x006510C0
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D0D70
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender); // 0x005C96A0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, void (__fastcall*)(D2UnitStrc*,int,D2StatListStrc*)); // 0x00625CE0
void __fastcall SKILLS_StatRemoveCallback_Conversion(D2UnitStrc*,int,D2StatListStrc*); // 0x005D01A0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall D2COMMON_10476(D2StatListStrc*, int); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
void __fastcall sub_6FD154D0(D2UnitStrc*); // 0x0056E580
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1900
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline unsigned char UNITS_GetMonsterComponent(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }

    return 0;
}

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

// 0x005CE790
int __fastcall SKILLS_SrvSt29_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pUnit, 1, 0, 0, 0, nDamagePercent, 0, pSkillsTxtRecord->nSrcDam);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        damage.dwHitFlags = 1;
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
    return 1;
}

// 0x005CF280
static int sub_005CF280_IsUnitOutsideTown(D2UnitStrc* pUnit)
{
    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit));
}

// 0x005CF2A0
int __fastcall SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageAuraParamStrc* pArgs = (D2DamageAuraParamStrc*)pAuraCallback->pArgs;
    D2GameStrc* pGame = pAuraCallback->pGame;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    if (pArgs->nPassiveState)
    {
        D2BasicAuraParamStrc args;
        memset(&args, 0, sizeof(args));
        args.nAuraState = pArgs->nAuraState;
        args.nSkillId = pArgs->nSkillId;
        args.nSkillLevel = pArgs->nSkillLevel;
        args.nDuration = pArgs->nDuration;
        for (int i = 0; i < 6; ++i)
        {
            args.nAuraStat[i] = pArgs->nAuraStat[i];
            args.nAuraStatCalcValue[i] = pArgs->nAuraStatCalcValue[i];
        }

        D2AuraCallbackStrc auraCallback;
        auraCallback.pOwner = pOwner;
        auraCallback.pArgs = &args;
        auraCallback.pGame = pGame;
        SKILLS_AuraCallback_BasicAura(&auraCallback, pUnit);
    }

    if (pArgs->pDamage)
    {
        D2DamageStrc damage = *pArgs->pDamage;
        SUNITDMG_ExecuteEvents(pGame, pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pUnit, &damage);
    }

    return 1;
}

void __stdcall sub_M217_Emit_005CF280(D2UnitStrc* pUnit, int* pResult)
{
    if (pUnit)
    {
        *pResult = sub_005CF280_IsUnitOutsideTown(pUnit);
    }
}

// 0x005CF8A0
static __forceinline D2UnitStrc* sub_005CF8A0_FindMeleeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID)
{
    return sub_6FD107F0(pGame, pUnit, 0, 0, 3, 3, nUnitGUID, 0);
}

int __fastcall sub_M132_Emit_005CF8A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return sub_005CF8A0_FindMeleeTarget(pGame, pUnit, 0x4D3) != 0;
}

// 0x005D0180
int __fastcall SKILLS_SrvSt36_HolyShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    return INVENTORY_GetEquippedShield(pUnit->pInventory, 0) != 0;
}

// 0x005D01A0
void __fastcall SKILLS_StatRemoveCallback_Conversion(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
    sub_6FCBDD30(pUnit, 0, 1);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);

    D2StatListStrc* pConversionStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONVERSION_SAVE);
    if (!pConversionStatList)
    {
        return;
    }

    const int nConversionLevel = STATLIST_GetStatValue(pConversionStatList, STAT_CONVERSION_LEVEL, 0);
    const int nConversionMaxHp = STATLIST_GetStatValue(pConversionStatList, STAT_CONVERSION_MAXHP, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;

    int nNewHp = 1;
    if (nMaxHp)
    {
        nNewHp = DATATBLS_ApplyRatio(nConversionMaxHp, nHitpoints, nMaxHp);
    }

    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nConversionLevel, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp << 8, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nConversionMaxHp, 0);
    D2Common_10474(pUnit, pConversionStatList);
    STATLIST_FreeStatList(pConversionStatList);

    for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pUnit, STATLIST_FLAG_8); i; i = STATLIST_GetStatListFromUnitAndFlag(pUnit, STATLIST_FLAG_8))
    {
        D2Common_10474(pUnit, i);
        STATLIST_FreeStatList(i);
    }
}

// 0x005D02B0
static int __stdcall sub_005D02B0_CanConvertTarget(D2UnitStrc* pUnit, int nSkillLevel, int bRoll, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && !MONSTERS_GetHirelingTypeId(pTarget))
    {
        const int nType = pTarget ? pTarget->dwUnitType : 6;
        if (nType == 1 && !STATLIST_GetUnitAlignment(pTarget) && sub_6FD15190(pTarget, 11))
        {
            const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            if (!bRoll || (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
            {
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall sub_M97_Emit_005D02B0(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    return sub_005D02B0_CanConvertTarget(pUnit, nSkillLevel, 1, pTarget, nSkillId);
}

// 0x005D0350
int __fastcall SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
 D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
 if (!pSkillsTxtRecord) return 0;
 if (pUnit) pUnit->dwFlags |= 0x40;
 D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
 if (!pTarget) return 0;
 int bConverted = 0;
 if (SUNITDMG_GetDamageFromUnits(pUnit, pTarget))
  bConverted = sub_005D02B0_CanConvertTarget(pUnit, nSkillLevel, 1, pTarget, nSkillId);
 if (pSkillsTxtRecord->wAuraTargetState < 0)
 {
Drain:
  SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
  return 1;
 }
 if (pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
  goto Drain;
 if (!bConverted)
  goto Drain;
 int nFrame = pGame->dwGameFrame;
 int nExpireFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) + nFrame;
 if (nExpireFrame <= nFrame + 1) nExpireFrame = nFrame + 1;
 D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
 if (!pStatList)
 {
  int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
  int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
  pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitId);
  if (!pStatList) return 0;
  STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
  STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_Conversion);
  D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
  STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
 }
 D2COMMON_10476(pStatList, nExpireFrame);
 EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
 sub_6FD154D0(pTarget);
 sub_6FCBDD30(pTarget, 2, 1);
 D2GAME_UpdateSummonAI_6FC401F0(pGame, pTarget, 0, pUnit->dwNodeIndex);
 UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
 for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8))
 {
  D2Common_10474(pTarget, i);
  STATLIST_FreeStatList(i);
 }
 int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 12, 0);
 int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
 if (nTargetLevel && nUnitLevel < nTargetLevel && !STATLIST_GetStatListFromUnitAndState(pTarget, 109))
 {
  int nTargetId = pTarget->dwUnitId;
  int nTargetType = pTarget->dwUnitType;
  D2StatListStrc* pSave = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nTargetType, nTargetId);
  if (pSave)
  {
   STATLIST_SetState(pSave, 109);
   D2COMMON_10475_PostStatToStatList(pTarget, pSave, 1);
   int nHp = STATLIST_UnitGetStatValue(pTarget, 6, 0) >> 8;
   int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget) >> 8;
   STATLIST_SetStatIfListIsValid(pSave, 176, nTargetLevel, 0);
   STATLIST_SetStatIfListIsValid(pSave, 177, nMaxHp, 0);
   int nNewHp = DATATBLS_ApplyRatio(nHp, nUnitLevel, nTargetLevel) << 8;
   int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nUnitLevel, nTargetLevel) << 8;
   if (nNewMaxHp < 1) nNewMaxHp = 1;
   nNewHp = (nNewHp > 1 ? nNewHp : 1) < nNewMaxHp ? (nNewHp > 1 ? nNewHp : 1) : nNewMaxHp;
   STATLIST_SetUnitStat(pTarget, 12, nUnitLevel, 0);
   STATLIST_SetUnitStat(pTarget, 6, nNewHp, 0);
   STATLIST_SetUnitStat(pTarget, 7, nNewMaxHp, 0);
  }
 }
 return 1;
}

// 0x005D0770
void __fastcall SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);

        if (!SUNIT_IsDead(pUnit))
        {
            STATES_ToggleState(pUnit, STATE_SHATTER, 0);
        }

        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\SkilPal.cpp", 1558);
    }
}
