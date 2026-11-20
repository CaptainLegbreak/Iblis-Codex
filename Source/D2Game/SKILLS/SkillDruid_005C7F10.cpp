#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

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

struct D2MonsterRegionStrc;


struct D2ModeChangeStrc
{
    int unk0x00[9];
};


struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
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

struct D2Do142ArgsStrc
{
    D2DamageStrc* pDamage;
    int nToHit;
    unsigned short wResultFlags;
    unsigned short unk0x0A;
    unsigned int dwHitFlags;
    unsigned char nSrcDam;
    unsigned char unk0x11[3];
};

struct D2UnkNecSkillStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int unk0x08;
    int bUpdateAnimRate;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalc[6];
    int nAuraTargetState;
    int nAuraEvent[3];
    int nAuraEventFunc[3];
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



struct D2StatesTxt
{
    char unk0x00[0x3C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
    char unk0x0C8[0x1C];
    unsigned int* pStateMaskRemHit;
    char unk0x0E8[0x94];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x182[0x9E2];
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3);                           // 0x005543B0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                    // 0x00554200
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);           // 0x00554DE0
int __fastcall sub_0056B740_CallWithRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);                          // 0x0056E450
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
D2UnitFindDataStrc* __fastcall sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4);    // 0x005C0B50
void __fastcall sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0
void __fastcall sub_6FC68280(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit);                     // 0x00547E90
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2);                                    // 0x005FD7B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80
void __fastcall sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0
void __fastcall sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);                                       // 0x00620C10
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A320
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);               // 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);      // 0x00644F20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00553C70
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0
void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C8BF0
void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C9420
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);        // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                           // 0x004E6CA0
int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A360
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit);                              // 0x0063A100
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue);                                                  // 0x004111A0
unsigned short __fastcall sub_6FD15650(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int a5, D2DamageStrc* pDamage, int a7); // 0x0056E6F0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005D8510
D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*)); // 0x0056BBC0
int __fastcall sub_005C35C0_CurseUnitCallback(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C35C0
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId);                                  // 0x00571B70
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D0D70
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005CC960
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);   // 0x005C96A0

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

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

// 0x005C7F10
int __fastcall SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    sub_6FD155E0(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        const int nDamagePct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nDamagePct, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    return 1;
}

// 0x005C8980
int __fastcall sub_005C8980_ProgressiveHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nToHit = 0;
    unsigned char nSrcDam = 0x80;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; i += 1)
    {
        const short nState = sgptDataTables->pProgressiveStates[i];
        if (STATES_CheckState(pUnit, nState) && DATATBLS_GetStatesTxtRecordInline(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    nToHit += SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->nSrcDam)
                    {
                        nSrcDam = pSkillsTxtRecord->nSrcDam;
                    }
                }
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

// 0x005C8E30
int __fastcall SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == 1)
    {
        int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (nTimeout < 1)
        {
            nTimeout = 1;
        }

        SKILLS_SetParam1(UNITS_GetUsedSkill(pUnit), nTimeout + pGame->dwGameFrame);
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 12);
    if (!pStatList)
    {
        const int nExpireFrame = pGame->dwGameFrame + 20;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_RemoveState);
        STATLIST_SetState(pStatList, 12);
        STATES_ToggleState(pUnit, 12, 1);
        SKILLS_SetParam1(UNITS_GetUsedSkill(pUnit), 0);
        return 1;
    }

    sub_6FCBD120(pGame, pUnit, 1);
    const int nEndFrame = pGame->dwGameFrame + 6;
    D2COMMON_10476(pStatList, nEndFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nEndFrame, 0, 0);
    SKILLS_DoInferno(pGame, pUnit, nSkillId, nSkillLevel, a5);
    return 1;
}

// 0x005C9030
int __fastcall SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nMaxDistance = nRange * nRange;
    if (PATH_ComputeSquaredDistance(UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), UNITS_GetUnitXPositionInline(pTarget), UNITS_GetUnitYPositionInline(pTarget)) > nMaxDistance)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
    case 1:
        if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            return 0;
        }
        break;
    }

    return 1;
}

// 0x005C9480
int __fastcall SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    sub_6FD11C90(pUnit, pSkillsTxtRecord->nAuraState, 1);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_DefensiveBuff;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    sub_6FCFE200(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_Unregister(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int i = 0; i < 3; i += 1)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            sub_6FD156A0(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[i], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return (int)pStatList;
}

// 0x005C96A0
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender)
{
    D2StaticFieldCallbackArgStrc* pArgs = (D2StaticFieldCallbackArgStrc*)pAuraCallback->pArgs;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;

    const int nHitpoints = STATLIST_UnitGetStatValue(pDefender, 6, 0) >> 8;
    if (nHitpoints < 1)
    {
        return 0;
    }

    if (pArgs->nStaticFieldMin)
    {
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pDefender) >> 8;
        if (nHitpoints <= DATATBLS_ApplyRatio(nMaxLife, pArgs->nStaticFieldMin, 100))
        {
            return 0;
        }
    }

    int nDamage = DATATBLS_ApplyRatio(nHitpoints, pArgs->nDamagePct, 100);
    if (nHitpoints - nDamage < 1)
    {
        nDamage = nHitpoints - 1;
    }

    nDamage <<= 8;
    if (nDamage < pArgs->nMinDamage)
    {
        nDamage = pArgs->nMinDamage;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    int nStatId = -1;
    int nElementalType = pArgs->nElementalType;
    sub_0056C8E0(pOwner, &damage, nElementalType, nDamage, pArgs->nElementalLength, &nStatId, &nElementalType);

    if (nStatId >= 0)
    {
        const int nValue = STATLIST_UnitGetStatValue(pDefender, nStatId, 0);
        if (nValue < 0)
        {
            nDamage = DATATBLS_ApplyRatio(nDamage, 100, 100 - nValue);
        }
    }

    memset(&damage, 0, sizeof(damage));
    sub_0056C8E0(pOwner, &damage, nElementalType, nDamage, pArgs->nElementalLength, 0, 0);

    damage.dwHitClass |= 0xD;
    damage.nHitClassActiveSet = 1;
    damage.wResultFlags = 0x4001;
    SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pOwner, pDefender, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pOwner, pDefender, &damage);
    return 1;
}

// 0x005C9C10
int __fastcall SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nStatValue = 0;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_6FCFE200(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_Unregister(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int i = 0; i < 3; i += 1)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            sub_6FD156A0(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[i], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    return 1;
}

// 0x005CAB40
int __fastcall SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || !SUNIT_AreUnitsHostile(pGame, pAttacker, pOwner))
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (nSkillLevel < 0)
    {
        nLevel = 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pUnit->dwClassId);
    if (!(pMissilesTxtRecord->nMissileFlags[MISSILESFLAGINDEX_RETURNFIRE >> 3] & gdwBitMasks[MISSILESFLAGINDEX_RETURNFIRE & 7]))
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pAttacker;
    missileParams.pOrigin = pAttacker;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nTargetX = CLIENTS_GetUnitX(pOwner);
    missileParams.nTargetY = CLIENTS_GetUnitY(pOwner);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005CAFA0
int __fastcall SKILLS_SrvDo084_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    if (!UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    pUnit->dwSeqSpeed = 0;

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount > 0)
    {
        int nCounter1 = 0;
        D2UnitStrc* pSummon = sub_6FC68D70(pGame, pUnit, nSummonId, nSpawnMode, -1, 0);
        if (pSummon)
        {
            nCounter1 = 1;
            pSummon->dwFlags |= UNITFLAG_NOXP;
        }

        int nCounter2 = 1;
        for (int i = 0; nCounter1 < nCount; i += 1)
        {
            if (nCounter2 >= 5 || i >= 2 * nCount)
            {
                break;
            }

            pSummon = sub_6FC68D70(pGame, pUnit, nSummonId, MONMODE_SKILL1, nCounter2, 0);
            if (pSummon)
            {
                pSummon->dwFlags |= UNITFLAG_NOXP;
                nCounter1 += 1;
            }
            else
            {
                nCounter2 += 1;
            }
        }
    }

    SUNITDMG_KillMonster(pGame, pUnit, pUnit, 1);
    return 1;
}

// 0x005CB0C0
int __fastcall SKILLS_SrvDo085_UnholyBolt_ShamanFire(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    int nMissileOffset;
    DATATBLS_GetMonsterChainInfo(nClassId, 0, &nMissileOffset);
    nMissileId += nMissileOffset;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}

// 0x005CB300
int __fastcall SKILLS_SrvDo086_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    const int nPercentage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercentage > 0)
    {
        int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
        nHitpoints += DATATBLS_ApplyRatio(nHitpoints, nPercentage, 100);
        if (nHitpoints >= nMaxHp)
        {
            nHitpoints = nMaxHp;
        }

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    }

    return 1;
}

// 0x005CB3C0
int __fastcall SKILLS_SrvDo087_MaggotLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
    const int nIndex = sub_0063E7A0_GetByteTableEntry(nDirection) % 8;

    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(gnMaggotLayDirections_006E3138[(unsigned char)nIndex], &nOffsetX, &nOffsetY);

    const int nX = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    const int nY = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    pUnit->nActionFrame = 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pSummon = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nSummonId, nSpawnMode, -1, 0);
    if (!pSummon)
    {
        return 0;
    }

    pSummon->dwFlags |= UNITFLAG_NOXP;
    return 1;
}

// 0x005CB580
int __fastcall SKILLS_SrvDo088_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam1(pSkill);
    int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }
    }

    unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, nX, nY);
    const unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection) & 7;

    nX = CLIENTS_GetUnitX(pUnit);
    nY = CLIENTS_GetUnitY(pUnit);

    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(gnAndrialSprayDirections_006E3188[nIndex], &nOffsetX, &nOffsetY);
    nX += nOffsetX;
    nY += nOffsetY;

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    nFrame -= 4;
    const int nClampedFrame = nFrame > 0 ? nFrame : 0;
    nFrame = nClampedFrame < 8 ? nClampedFrame : 8;

    const unsigned char nSprayDirection = gnAndrialSprayOffsets_006E3140[9 * nIndex + nFrame];
    if (nSprayDirection != 99)
    {
        sub_0063E7E0_GetDirectionDelta(nSprayDirection, &nOffsetX, &nOffsetY);
        nX += nOffsetX;
        nY += nOffsetY;
    }

    D2MissileStrc missileParams = {};
    missileParams.nTargetX = nX;
    missileParams.nTargetY = nY;
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005CD6A0
int __fastcall SKILLS_SrvDo105_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nOffsetX = nTargetX - nX;
    int nOffsetY = nTargetY - nY;
    if (!nOffsetX && !nOffsetY)
    {
        return 0;
    }

    int nBaseX = 0;
    int nBaseY = 0;
    if (nOffsetX < 0 && nOffsetY < 0)
    {
        nBaseX = 2;
        nBaseY = -2;
    }
    else if (nOffsetX == 0 && nOffsetY < 0)
    {
        nBaseX = 2;
    }
    else if (nOffsetX > 0 && nOffsetY < 0)
    {
        nBaseX = 2;
        nBaseY = 2;
    }
    else if (nOffsetX > 0 && nOffsetY == 0)
    {
        nBaseY = 2;
    }
    else if (nOffsetX > 0 && nOffsetY > 0)
    {
        nBaseX = -2;
        nBaseY = 2;
    }
    else if (nOffsetX == 0 && nOffsetY > 0)
    {
        nBaseX = -2;
    }
    else if (nOffsetX < 0 && nOffsetY > 0)
    {
        nBaseX = -2;
        nBaseY = -2;
    }
    else if (nOffsetX < 0 && nOffsetY == 0)
    {
        nBaseY = -2;
    }

    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    nOffsetX -= nSubMissiles / 2 * nBaseX;
    nOffsetY -= nSubMissiles / 2 * nBaseY;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 3;
    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.pOwner = pUnit;
        missileParams.nX = nX + nOffsetX / 6;
        missileParams.nY = nY + nOffsetX / 6;
        missileParams.nTargetX = nOffsetX;
        missileParams.nTargetY = nOffsetY;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = nMissileId;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        nOffsetX += nBaseX;
        nOffsetY += nBaseY;
    }

    return 1;
}

// 0x005CE0B0
int __fastcall SKILLS_SrvDo149_NecromageMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const unsigned char nComponent = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->nComponent[11] : 0;
    nMissileId += nComponent;
    if (nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_01 >> 3] & gdwBitMasks[SKILLSFLAGINDEX_01 & 7])
    {
        sub_6FD11710(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    }
    else
    {
        sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    }

    return 1;
}

// 0x005D10C0
void __fastcall SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    int nPercent;
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, STAT_THORNS_PERCENT, 0);
    if (nThornsPercent <= 0)
    {
        return;
    }

    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        nPercent = (nThornsPercent + 4) / 8;
    }
    else
    {
        nPercent = nThornsPercent;
    }

    if (nPercent <= 0)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    damage.dwHitClass = 0x8D;
    damage.wResultFlags = 0x4021;
    SUNITDMG_ExecuteEvents(pGame, pDefender, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pDefender, pAttacker, &damage);
}

// 0x005D1800
int __fastcall SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = 1;
    aiCmd.nCmdParam[1] = pTarget->dwUnitType;
    aiCmd.nCmdParam[2] = pTarget->dwUnitId;

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    aiCmd.nCmdParam[3] = nTimeout + pGame->dwGameFrame;
    AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}

// 0x005D2090
int __fastcall SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    int nMissileOffset;
    DATATBLS_GetMonsterChainInfo(nClassId, 0, &nMissileOffset);
    sub_6FD11420(pGame, nMissileOffset + nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}

// 0x005D25B0
int __fastcall SKILLS_SrvDo136_DeathMaul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nSpeed > 0)
    {
        UNITS_SetAnimationSpeed(pMissile, nSpeed);
    }

    const int nTotalFrames = MISSILE_GetTotalFrames(pMissile);
    int nDistance = sub_006417F0_GetDistanceToXY(pUnit, nX, nY);
    if (nDistance < 1)
    {
        nDistance = 1;
    }

    int nFrame;
    if (nDistance >= 10)
    {
        nFrame = nTotalFrames * nDistance / 12;
    }
    else
    {
        nFrame = nTotalFrames * nDistance / 24 + nTotalFrames / 2;
    }

    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

// 0x005D2F80
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nUnitSize)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nX = UNITS_GetUnitXPositionInline(pUnit);
    const int nY = UNITS_GetUnitYPositionInline(pUnit);

    D2UnitFindArgStrc unitFindArg;
    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nFlags = 0x1002;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nUnitSize;

    D2UnitFindDataStrc unitFindData;
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nUnitSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    for (int i = 0; i < unitFindData.nIndex; ++i)
    {
        D2UnitStrc* pResult = unitFindData.pUnitsArray[i];
        if (UNITS_IsCorpseUseable(pResult) && SUNIT_AreUnitsHostile(pGame, pUnit, pResult))
        {
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return pResult;
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
    return 0;
}

// 0x005D6410
void __fastcall sub_6FCF8DD0(D2UnitStrc* pDefender)
{
    if (!STATES_CheckStateMaskRemHitOnUnit(pDefender))
    {
        return;
    }

    const unsigned int* pStatFlags = D2COMMON_10494_STATES_GetStatFlags(pDefender);
    const int nRecords = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;

    unsigned int nFlags[8];
    memcpy(nFlags, pStatFlags, sizeof(unsigned int) * nRecords);

    int nBase = 0;
    for (int i = 0; i < nRecords; ++i, nBase += 32)
    {
        unsigned int* pFlag = &nFlags[i];
        unsigned int nFlag = *pFlag;
        int nBit = sub_004111A0_GetLowestSetBit(nFlag);
        if (nBit >= 0)
        {
            do
            {
                nFlag &= ~(1 << nBit);
                const int nStateId = nBit + nBase;
                if (sgptDataTables->pStateMaskRemHit[nStateId >> 5] & gdwBitMasks[nStateId & 31])
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, nStateId);
                    if (pStatList)
                    {
                        D2Common_10474(pDefender, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pDefender, nStateId, 0);
                }

                nBit = sub_004111A0_GetLowestSetBit(nFlag);
            }
            while (nBit >= 0);

            *pFlag = nFlag;
        }
    }
}

// 0x005D7C40
int __fastcall sub_005D7C40(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2Do142ArgsStrc* pArgs = (D2Do142ArgsStrc*)pAuraCallback->pArgs;
    D2DamageStrc damage = *pArgs->pDamage;

    sub_6FD15650(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, pArgs->wResultFlags, pArgs->nToHit, &damage, 1);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= pArgs->dwHitFlags;
        if (pArgs->nSrcDam)
        {
            SUNITDMG_FillDamageValues(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0, pArgs->nSrcDam);
        }

        SUNITDMG_AllocCombat(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0x80);
        SUNITDMG_DrainItemDurability(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 0);
    }

    return 1;
}

// 0x005D8290
int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nExpireFrame = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(a2, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(a2, pStatList, 1);
        STATES_ToggleState(a2, pSkillsTxtRecord->nAuraState, 1);
    }

    STATES_ToggleGfxStateFlag(a2, pSkillsTxtRecord->nAuraState, 1);
    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, a2, 12, nExpireFrame, 0, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    sub_6FD14C30(a2);
    return 1;
}

// 0x005D8570
int __fastcall SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !SKILLS_Callback_FindTargetForTaunt(pGame, pTarget) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        pTarget = SKILLS_FindAuraTarget(pGame, pUnit, 20, SKILLS_Callback_FindTargetForTaunt);
    }

    if (!pTarget)
    {
        return 0;
    }

    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);

    D2UnkNecSkillStrc curseData;
    memset(&curseData, 0, sizeof(curseData));
    curseData.pUnit = pUnit;
    curseData.nDuration = nDuration;
    curseData.pGame = pGame;
    curseData.unk0x08 = 1;
    curseData.nSkillId = nSkillId;
    curseData.nSkillLevel = nSkillLevel;
    curseData.bUpdateAnimRate = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            curseData.nAuraStat[i] = -1;
            break;
        }

        D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[9 >> 3] & gdwBitMasks[9 & 7])
        {
            curseData.bUpdateAnimRate = 1;
        }

        curseData.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        curseData.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    curseData.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    sub_005C35C0_CurseUnitCallback(pTarget, &curseData);

    D2AiControlStrc* pAiControl = (pTarget->dwUnitType == 1 && pTarget->pMonsterData) ? pTarget->pMonsterData->pAiControl : 0;
    AITHINK_SetAiControlParams(pAiControl, -666, -666, -666);
    AIUTIL_SetOwnerGUIDAndType(pTarget, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 2, 0);
    EVENT_SetEvent(pGame, pTarget, 2, pGame->dwGameFrame + 1, 0, 0);
    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);
    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillDruid_005C7F10.inc"
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
