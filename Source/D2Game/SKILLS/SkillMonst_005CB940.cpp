#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"

#define STATEMASK_REMHIT 6

struct D2GameStrc;

struct D2UnitStrc;

#define UNITFLAG_SKSRVDOFUNC 0x40

#define AISPECIALSTATE_NONE 0

#define SKILLDRUID_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SummonArgStrc;

struct D2SkillsTxt;

union D2SeedStrc;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

void __fastcall sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056F020

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __fastcall sub_6FCFE030(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList); // 0x005C6C50

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0

extern "C" void __stdcall sub_00625CE0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

extern "C" void __stdcall sub_006260B0(D2StatListStrc* pStatList, int nValue); // 0x006260B0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall sub_005C7B10_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel); // 0x005C7B10

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450

void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nMask); // 0x00645950

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

struct D2StaticPathStrc;

D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0

enum D2C_Z09SkillConstants
{
    UNITFLAG_TARGETFLAGS = 0x0E,
    EVENTTYPE_ENDANIM = 1,
    AISPECIALSTATE_MOUNTING_UNIT = 0x10,
    PATHTYPE_BLESSEDHAMMER = 0x0E,
    PATHTYPE_KNOCKBACK_SERVER = 0x08,
    PATHTYPE_LEAP = 0x09,
    PATHTYPE_MON_OTHER_2 = 0x65,
};

int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);       // 0x005D3DA0

void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290

int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nCalc, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860

int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId);                                             // 0x00463900

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0

int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500

int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00553C70

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970

int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);                          // 0x006461D0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit);                                                             // 0x0056E5B0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId);         // 0x0056C840

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

#define HIT_SUCCESS 1

#define HIT_FLAG 2

#define SOURCE_DAMAGE 128

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    STATLIST_FLAG_8 = 8,
};

struct D2MonsterRegionStrc;

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

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0

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

D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110

D2UnitFindDataStrc* __fastcall sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210

D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4);    // 0x005C0B50

void __fastcall sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690

void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270

D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0

int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0

void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0

void __fastcall sub_6FC68280(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit);                     // 0x00547E90

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

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);                                       // 0x00620C10

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A320

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);               // 0x00625760

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0

void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0

void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C8BF0

void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C9420

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0

void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780

int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490

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

void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId);                                  // 0x00571B70

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0

int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D0D70

int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005CC960

int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);   // 0x005C96A0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560

int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

extern const int gnHydraOffsetX_006E312C[]; // 0x006E312C

extern const int gnHydraOffsetY_006E3120[]; // 0x006E3120

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780

int __fastcall sub_00554EA0(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

enum { UNIT_FLAGS = 0xE };

struct D2MissilesTxt;

struct Monster;

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_AITHINK = 2,
};

void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440

struct Game
{
    unsigned char pad[28];
    void* pool;
};

struct Seed
{
    U32 low;
    U32 high;
};

struct Unit
{
    int type;
    int classId;
    U32 unknown08;
    int id;
    int mode;
    Monster* monster;
    U32 unknown18;
    void* pool;
    Seed seed;
};

struct AuraRequest
{
    Unit* owner;
    Unit* target;
    int skill;
    int level;
    int duration;
    int stat;
    int amount;
    int state;
    void* callback;
};

struct ModeRequest
{
    int mode;
    Unit* target;
    U32 field08;
    U32 field0C;
    U32 field10;
    U32 f_14;
    U32 f_18;
    U32 field1C;
};

extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, U32, int, int); // 0x00646CA0

struct D2PlayerDataStrc;

struct D2AiCmdStrc;

struct D2MonStatsTxt;

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380

int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc*, D2UnitStrc*); // 0x005DC640

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0

D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*, int); // 0x005DDE50

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080

void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall sub_6FCD0410(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DED40

int __fastcall AITACTICS_WanderToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance); // 0x005DF400

int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3EA0

int __fastcall sub_005E45D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, D2AiTickParamStrc*, int, int); // 0x005E45D0

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc*, int); // 0x00472210

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*, D2UnitStrc*, unsigned int*, int*); // 0x005DDC30

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200

int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90

int __fastcall sub_005DEFE0_Escape(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF530

int __fastcall sub_005E3930_MovePet(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3930

void __fastcall sub_005E5050_RunHirelingAction(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*, D2UnitStrc*, D2SeedStrc*, D2AiTickParamStrc*); // 0x005E5050

int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0

int __stdcall sub_00648A20_GetTargetX(D2DynamicPathStrc*); // 0x00648A20

int __stdcall sub_00648A30_GetTargetY(D2DynamicPathStrc*); // 0x00648A30

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline int SKILLS_IsValidPetType(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

// 0x005CB940
int __fastcall SKILLS_SrvDo089_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    if (pUnit->nActionFrame == 2)
    {
        pUnit->nActionFrame = 0;

        D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
        if (pTarget)
        {
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }

        return 1;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (CLIENTS_GetUnitX(pUnit) == nX && CLIENTS_GetUnitY(pUnit) == nY)
        {
            SKILLS_SetFlags(pSkill, 0);
            sub_6FCBDE90(pUnit, 0);
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
            PATH_SetFootprintCollisionMask(pPath, 0x100);
            PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
            PATH_SetType(pPath, PATHTYPE_MON_OTHER_2);

            if (sub_00463900_GetValidMonsterId(sub_00463860(pUnit)) == MONSTER_SANDLEAPER1)
            {
                D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
                if (pTarget)
                {
                    SKILLS_SetFlags(pSkill, 1);
                    UNITS_SetAnimationFrame(pUnit, 12);
                    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
                    PATH_RecacheRoomIfNeeded(pPath);
                    PATH_SetNewDistance(pPath, 5);
                    PATH_SetStepNum(pPath, 1);
                    PATH_SetTargetUnit(pPath, 0);
                    const int nTargetX = 3 * nX - 2 * CLIENTS_GetUnitX(pTarget);
                    const int nTargetY = 3 * nY - 2 * CLIENTS_GetUnitY(pTarget);
                    D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
                    PATH_SetType(pPath, PATHTYPE_KNOCKBACK_SERVER);
                    D2COMMON_10190_PATH_SetDistance(pPath, 5);
                    D2Common_10142(pPath, pUnit, 0);
                }
            }
        }
        else
        {
            int nFrame = 0;
            if (sub_00463900_GetValidMonsterId(sub_00463860(pUnit)) == MONSTER_SANDLEAPER1)
            {
                nFrame = 8;
            }

            UNITS_SetAnimationFrame(pUnit, nFrame);
            pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
        }

        return 1;
    }

    if (nSkillFlags & 0x80)
    {
        SKILLS_SetFlags(pSkill, 0x101);
        PATH_SetMoveTestCollisionMask(pPath, 0);
        PATH_SetFootprintCollisionMask(pPath, 0);
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        PATH_SetType(pPath, PATHTYPE_LEAP);
        PATH_SetVelocity(pPath, SKILLS_GetBaseWalkVelocity(pUnit), ".\\SKILLS\\SkillMonst.cpp", 0x282);
        D2Common_10142(pPath, pUnit, 0);
    }
    else
    {
        SKILLS_SetFlags(pSkill, 0);
    }

    return 1;
}
