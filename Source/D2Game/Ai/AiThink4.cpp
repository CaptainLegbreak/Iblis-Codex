#include "D2Game.h"
#include "D2ItemsWorld.h"
#include "D2Drlg.h"
#include "D2GameObjs.h"
#include "D2GameAux.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

struct D2GameStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MONSTER_DEMONHOLE 711

#define MONMODE_SKILL1 8

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2AiParamStrc;

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2StaticPathStrc;

struct D2MonsterDataStrc;

struct D2MapAIPathPositionStrc;

struct D2AiCmdStrc;

struct D2BaalToStairsAiCallbackArgStrc;

struct D2SandRaiderAiCallbackArgStrc;

union D2SeedStrc;

struct D2Unk005EAD50CounterStrc;

struct D2Unk005EAD50LimitsStrc;

struct D2Unk005EAD50ArgStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

enum
{
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_WALK = 2,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL3 = 10,
    MONMODE_DEAD = 12,
    MONMODE_RUN = 15,
};

enum
{
    SKILL_BAALMONSTERSPAWN = 286,
    OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER = 563,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2BaalToStairsAiCallbackArgStrc
{
    int unk0x00;
    int nMaxDistance;
    int unk0x08[8];
};

struct D2SandRaiderAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
};

int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60

void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int a2, int nVel, unsigned char a4); // 0x005A6260

void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

void __fastcall sub_005F6630_InitAiParamsFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005F6630

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0

D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0

bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam); // 0x005E6800

int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40

int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0

int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam); // 0x005EA2B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill); // 0x00644360

D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20

struct D2Unk005EAD50CounterStrc
{
    char unk0x00[0x14];
    int nFrame;
    int nValue;
    int nBase;
};

struct D2Unk005EAD50LimitsStrc
{
    char unk0x00[0x82];
    short nMin;
    short nMax;
};

struct D2Unk005EAD50ArgStrc
{
    D2Unk005EAD50CounterStrc* pCounter;
    char unk0x04[0x18];
    D2Unk005EAD50LimitsStrc* pLimits;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall sub_005EABF0(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pUnit, int nSkillId, D2Unk005EAD50ArgStrc* pArg); // 0x005EABF0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040

int __stdcall sub_006459F0(int nSkillId, int nSkillLevel); // 0x006459F0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2SiegeBeastTowerAiCallbackArgStrc;

struct D2NihlathakOverseerAiCallbackArgStrc;

struct D2MinionSpawnerAiCallbackArgStrc;

struct D2ShadowMasterAiCallbackArgStrc;

struct D2FallenShamanAiCallbackArgStrc;

struct D2ZakarumPriestAiCallbackArgStrc;

struct D2FetishShamanAiCallbackArgStrc;

struct D2OblivionKnightAiCallbackArgStrc;

struct D2ModeChangeStrc;

enum
{
    UNIT_ALIGNMENT_EVIL = 0,
    UNIT_ALIGNMENT_GOOD = 2,
};

enum
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

enum
{
    MONTYPEFLAG_UNIQUE = 0x08,
    MONTYPEFLAG_CHAMPION = 0x04,
};

enum
{
    ITEMQUAL_NORMAL = 2,
    ITEMQUAL_UNIQUE = 7,
};

enum
{
    STATE_BLOODLUST = 141,
};

enum
{
    MONSTER_FALLEN1 = 19,
    MONSTER_FALLENSHAMAN1 = 58,
    MONSTER_FETISH1 = 141,
    MONSTER_ZEALOT1 = 235,
    MONSTER_CANTOR1 = 238,
    MONSTER_DOOMKNIGHT1 = 310,
    MONSTER_FETISHBLOW1 = 396,
    MONSTER_WAKEOFDESTRUCTION = 410,
    MONSTER_CHARGEBOLTSENTRY = 411,
    MONSTER_LIGHTNINGSENTRY = 412,
    MONSTER_BLADECREEPER = 413,
    MONSTER_INFERNOSENTRY = 415,
    MONSTER_DEATHSENTRY = 416,
    MONSTER_MINION1 = 453,
    MONSTER_SUICIDEMINION1 = 461,
    MONSTER_IMP1 = 492,
    MONSTER_UBERMEPHISTO = 704,
    MONSTER_UBERDIABLO = 705,
    MONSTER_UBERBAAL = 709,
};

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
    int unk0x04;
    int unk0x08[8];
};

struct D2NihlathakOverseerAiCallbackArgStrc
{
    int nMaxDistance;
    int nDistantMaxDistance;
    int nMaxLifePercentage;
    D2UnitStrc* pTarget;
    D2UnitStrc* pDistantTarget;
    int nCounter;
    int unk0x18[4];
};

struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
    int unk0x04[10];
};

struct D2ShadowMasterAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    D2UnitStrc* unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    D2UnitStrc* unk0x24;
};

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
    int unk0x10[6];
};

struct D2ZakarumPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nMaxLifePercentage;
    int nMaxDistance;
    int unk0x10[6];
};

struct D2FetishShamanAiCallbackArgStrc
{
    D2UnitStrc* pClosestDeadTarget;
    int nSquaredDistanceToClosestDeadTarget;
    int nMaxSearchRangeSquared;
    D2UnitStrc* pClosestAliveTarget;
    int nSquaredDistanceToClosestAliveTarget;
    int nAliveTargets;
    int nHealCapability;
};

struct D2OblivionKnightAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
};

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80

int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860

int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId); // 0x00463900

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* a1, D2UnitStrc* a2); // 0x005EB650

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId); // 0x005EAB20

int __fastcall sub_005EB420_ShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId); // 0x005EB420

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190

int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEE50

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

enum D2C_Y11AiConstants
{
    STAT_TOHIT = 0x13,
    STAT_ITEM_TOHIT_PERCENT = 0x77,
};

int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0

struct D2ActiveRoomStrc;

enum D2C_F42AiConstants
{

    MONMODE_ATTACK2 = 5,
    MONMODE_SKILL2 = 9,
    MONMODE_SKILL4 = 11,

    PLRMODE_NEUTRAL = 1,

    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,

    UNITFLAG_NOTC = 0x00020000,
    UNITFLAG_NOXP = 0x04000000,

    STATE_POISON = 2,
    STATE_INFERNO = 12,
    STATE_BAALTOSTAIRS_INVIS = 0x92,
    STAT_HITPOINTS = 6,
    STAT_POISONRESIST = 45,
    SKILL_BAALTAUNT = 284,
    SKILL_IMPREGNATE = 300,
    MONSTATSFLAGINDEX_LUNDEAD = 11,
};

struct D2GreaterMummyAiCallbackArgStrc
{
    D2UnitStrc* pReviveTarget;
    D2UnitStrc* pHealTarget;
    int nHealReviveCounter;
    int nCounter;
    int nMaxDistance;
    int bRadament;
    int bNormal;
};

struct D2VultureAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int nLifePercentage;
};

struct D2MephistoAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    int unk0x04;
    int unk0x08;
    D2UnitStrc* unk0x0C;
    int unk0x10;
    D2UnitStrc* unk0x14;
    int unk0x18;
    int nCounter;
    int unk0x20;
    int unk0x24;
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0

void __fastcall sub_6FCD0150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                           // 0x005DE130

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

bool __fastcall sub_6FCE69A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E6AE0

bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E7080

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit);                                                // 0x0058F160

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730

int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit);                                         // 0x0058F710

void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3);                                        // 0x005E5710

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270

int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DE890

int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE440

int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED00

int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);       // 0x005DECA0

int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0

int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0

int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0

unsigned int __fastcall sub_005DC380(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                  // 0x005DC380

void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame);                                            // 0x0058E600

int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

void __stdcall sub_0063EE10_GetMonsterDirectionDelta(D2UnitStrc* pUnit, int* pX, int* pY);                  // 0x0063EE10

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __fastcall sub_005429B0_IsDeadMonsterAt(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nIndex); // 0x005429B0

D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EF5E0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

enum D2C_V04AiBaalConstants
{
    STAT_DAMAGERESIST = 0x24,
    STAT_MAGICRESIST = 0x25,
    STAT_FIRERESIST = 0x27,
    STAT_LIGHTRESIST = 0x29,
    STAT_COLDRESIST = 0x2B,
    STAT_MAXDAMAGE = 0x16,
    STAT_FIREMAXDAM = 0x31,
    STAT_LIGHTMAXDAM = 0x33,
    STAT_MAGICMAXDAM = 0x35,
    STAT_COLDMAXDAM = 0x37,
    STAT_POISONMAXDAM = 0x3A,
    STATE_COLD = 0x0B,
};

int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY);             // 0x005DC480

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget);             // 0x005DD290

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

#pragma intrinsic(memcpy)

struct D2SkillStrc;

struct D2DynamicPathStrc;

struct D2PlayerCountBonusStrc
{
    int nHp,nExperience,nSkillBonus,nDifficulty,nPlayerCount;
};

extern const char gszAiThink4Source[]; // 0x006E3500

int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc*); // 0x005353F0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60

void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc*,D2PlayerCountBonusStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00573930

unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*,D2UnitStrc*); // 0x005DC380

int __fastcall sub_005DD290_CheckAttack(D2UnitStrc*,D2UnitStrc*); // 0x005DD290

int __fastcall sub_005FD470(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0

unsigned int __stdcall sub_006417F0_GetDistance(D2UnitStrc*,int,int); // 0x006417F0

int __stdcall PATH_GetY(D2DynamicPathStrc*); // 0x00648900

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

struct D2SkillListStrc;

struct D2ShadowMasterSkillStrc
{
    D2UnitStrc* pTarget;
    int nSkillId;
    int nChance;
    int nX;
    int nY;
};

extern "C" const char szAiThink4File[];                                                                     // 0x006E3500

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0

D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit);                           // 0x0055B7E0

int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);   // 0x005DED20

int __fastcall sub_005DF140_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140

D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EB6D0

int __fastcall sub_005EB7F0_IsStateGroupActive(D2UnitStrc* pUnit, int nState);                              // 0x005EB7F0

int __fastcall sub_005EB8B0_ShadowMasterUseSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam); // 0x005EB8B0

int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A2B0

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910

enum D2C_ShadowMasterConstants
{
    COLLIDE_MISSILE_BARRIER = 4,
    SKILLSFLAGINDEX_AURA = 2,

    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_FREEZE = 12,

};

int __fastcall sub_005DC480_GetDistance(D2UnitStrc*,int,int); // 0x005DC480

struct D2StatListStrc;

#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* game,D2UnitStrc* unit,D2CoordStrc* coords); // 0x005BD0D0

void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* game,D2UnitStrc* unit); // 0x005BD4A0

int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* game,D2UnitStrc* unit,int x,int y); // 0x005DED90

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M81OverseerAi
{
    OVERSEER_AI_PARAM_RALLY_SPELL_TIMER = 0,
    OVERSEER_AI_PARAM_HEAL_CHANCE_PCT = 1,
    OVERSEER_AI_PARAM_WHIP_CHANCE_PCT = 2,
    OVERSEER_AI_PARAM_COMFORT_DISTANCE = 3,
    OVERSEER_AI_PARAM_COMFORT_ZONE = 4,
    OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT = 5,
    OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT = 6,
};

void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00587900

int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId); // 0x005DD2D0

D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DE830

int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E26D0

extern const char gszAiThink4File[]; // 0x006E3500

void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc*, D2UnitStrc*); // 0x0058BC40

void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc*, int, int, unsigned char); // 0x005DF850

D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc*, D2UnitStrc*, int, int); // 0x0056E390

int __fastcall sub_6FC68350(int, D2ActiveRoomStrc*, int, int, int); // 0x005FD350

int __stdcall D2Common_11063(D2ActiveRoomStrc*, int); // 0x0063EC70

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed);

int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nSkillLevel);                                   // 0x004CC7C0

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30

#define MINIMUM(a,b) ((a) < (b) ? (a) : (b))

#pragma pack(push,1)

struct D2Packet8A
{
    unsigned char header;
    unsigned char type;
    int guid;
};

#pragma pack(pop)

int __fastcall ACT5Q2_FindPortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc**); // 0x00588D60

int __fastcall ACT5Q2_CheckWussieCounters(D2GameStrc*,D2UnitStrc*); // 0x00588830

void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc*,int,D2UnitStrc*); // 0x00588880

void __stdcall sub_00648730(D2DynamicPathStrc*); // 0x00648730

D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc*,D2UnitStrc*,int*); // 0x005DDF20

int __fastcall sub_00588E10_IsMonsterNearby(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588E10

void __fastcall sub_005888D0_SpawnRescuePortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x005888D0

void __fastcall sub_6FC40280(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990

void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588DD0

extern const char gszAiThink4[]; // 0x006E3500

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0

void __fastcall sub_0053DFF0(D2ClientStrc*,D2Packet8A*); // 0x0053DFF0

#define MONSTER_SUCKERNEST1 334

#define MONMODE_ATTACK2 5

struct Obj00648AD0;

struct D2HighPriestAiCallbackArgStrc;

struct D2PetMoveStrc;

struct D2PlayerDataStrc;

struct D2MonStats2Txt;

struct D2PetInfoStrc;

int __fastcall sub_005FD350_SpawnNearby(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5); // 0x005FD350

enum D2C_F41AiThinkConstants
{
    MONSTER_EVILHUT = 528,
    SKILL_NEST = 167,
};

struct D2HighPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nLifePercentage;
    int nMaxDistance;
};

struct D2PetMoveStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nCounter;
};

int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000

D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E1720

void __fastcall sub_005E17E0_SiegeBeastSetTower(D2UnitStrc* pUnit, D2UnitStrc* pTower); // 0x005E17E0

D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70

void __fastcall sub_005E4830(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4830

void __fastcall sub_005E4AC0_NecroPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4AC0

bool __fastcall sub_005E6020_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId); // 0x005E6020

bool __fastcall sub_6FCE61E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition); // 0x005E6DE0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

extern "C" const int gnDesertTurretIndices_006E33E0[64]; // 0x006E33E0

extern "C" const D2CoordStrc gDesertTurretOffsets_006E33A0[8]; // 0x006E33A0

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);

extern "C" void __stdcall sub_00648AD0(Obj00648AD0* pObj, unsigned short wA, unsigned short wB); // 0x00648AD0

void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10

int __fastcall PLAYERPETS_GetTotalPetCount(D2UnitStrc*); // 0x00574F40

int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10

unsigned int __stdcall sub_00648A20_GetLastPointX(D2DynamicPathStrc*); // 0x00648A20

unsigned int __stdcall sub_00648A30_GetLastPointY(D2DynamicPathStrc*); // 0x00648A30

D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc*, int); // 0x00574BD0

void __fastcall AITHINK_SelectHirelingAction(D2GameStrc*, D2UnitStrc*, int, int, D2UnitStrc*, D2SeedStrc*); // 0x005E4D30

int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame); // 0x0059AEC0

int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame); // 0x0059B8B0

int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord); // 0x0059B8F0

bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E68F0

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0

void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);

void __fastcall sub_005E7DC0_SpecialState08TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);

#define MON_FLAG 9

#define ATTACK_MODE 4

#define WALK_CHANCE 20

#define WALK_DISTANCE 3

#define IDLE_FRAMES 10

struct D2AiControlStrc;

struct D2MissilesTxt;

#define MONMODE_ATTACK1 4

int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

int __fastcall AITACTICS_WalkAroundTargetWithScaledDistance(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nScale); // 0x005DE6F0

int __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2); // 0x005ECBC0

void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ECEE0

void __fastcall AITHINK_Fn108_Fenris(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ED2A0

enum D2C_M80TotemAi
{
    PLRMODE_WALK = 2,
    PLRMODE_RUN = 3,
    PLRMODE_TOWNWALK = 6,
    TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT = 0,
    TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT = 1,
    TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE = 2,
    TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE = 3,
};

D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

enum D2C_M230FallenAi
{
    FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT = 0,
    FALLEN_AI_PARAM_APPROACH_DISTANCE = 1,
    FALLEN_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

extern "C" D2AiCmdStrc* __fastcall sub_0058EE80(D2UnitStrc* pUnit); // 0x0058EE80

int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

enum D2C_M197ZakarumPriestAi
{
    ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT = 1,
    ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT = 2,
    ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT = 3,
    ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER = 4,
    ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE = 5,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7240

int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80

int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2FC0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

enum D2C_SummonerAIParams
{
    SUMMONER_AI_PARAM_CAST_CHANCE_PCT = 0,
    SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT = 1,
    SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT = 2,
    SUMMONER_AI_PARAM_NOVA_TIMER = 3,
    SUMMONER_AI_PARAM_FIREWALL_TIMER = 4,
    SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT = 5,
    SUMMONER_AI_PARAM_NOVA_DISTANCE = 6,
    SUMMONER_AI_PARAM_MISSILE_DISTANCE = 7,
};

void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059C330

int __fastcall sub_005DEFE0_AiEscape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback);

struct D2PantherAiCallbackArgStrc;

enum D2C_AiThink005F12A0
{
    AI_PARAM_WALK_CHANCE_PCT = 0,
    AI_PARAM_IDLE_FRAMES = 1,
    AI_PARAM_ATTACK_CHANCE_PCT = 2,
};

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00

enum D2C_M86FallenShamanAi
{
    FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT = 0,
    FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT = 2,
    FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE = 3,
    FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE = 4,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F1380

static D2SkillsTxt* AITHINK_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static D2MonStatsTxt* AITHINK_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x005E0070
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nMonsterId;

    if (!pUnit)
    {
        nMonsterId = -1;
    }
    else
    {
        nMonsterId = pUnit->dwClassId;
    }

    switch (nMonsterId)
    {
    case MONSTER_UBERMEPHISTO:
        pGame->bUberMephistoKilled = 1;
        break;
    case MONSTER_UBERDIABLO:
        pGame->bUberDiabloKilled = 1;
        break;
    case MONSTER_UBERBAAL:
        pGame->bUberBaalKilled = 1;
        break;
    default:
        D2_ASSERT(0, 230);
        return;
    }

    if (pGame->bUberMephistoKilled && pGame->bUberDiabloKilled && pGame->bUberBaalKilled)
    {
        int nItemLevel;
        pUnit->dwDropItemCode = ' 2mc';
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 0);
        D2GAME_RechargeItem_6FC4BD50(pGame, 0, pItem);
        pUnit->dwDropItemCode = ' dts';
        const int nClients = pGame->nClients;
        for (int i = 0; i < nClients; i++)
        {
            D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
        }
    }
}

static __forceinline int MONSTERS_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

// 0x005E0260
void __fastcall sub_005E0260_AiThinkSuckerNest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->nTargetDistance <= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        if (pAiControl->dwAiParam[1] > AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            if (pUnit)
            {
                pUnit->dwFlags |= UNITFLAG_NOTC;
            }

            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0]
            && sub_005FD350_SpawnNearby(MONSTERS_ValidateMonsterId(MONSTER_SUCKERNEST1), UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, 2);
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005E0390
void __fastcall sub_005E0390(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = AITHINK_GetSkillsTxtRecordInline(pMonStatsTxtRecord->nSkill[0]);
        pAiControl->dwAiParam[0] = (!pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1]) + pGame->dwGameFrame;
    }
}

// 0x005E0400
void __fastcall AITHINK_Fn084_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005E0430
D2UnitStrc* __fastcall AITHINK_TargetCallback_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2HighPriestAiCallbackArgStrc* pArg = (D2HighPriestAiCallbackArgStrc*)pCallbackArg;
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 75 || nLifePercentage >= pArg->nLifePercentage)
    {
        return 0;
    }

    pArg->nLifePercentage = nLifePercentage;
    pArg->pTarget = pTarget;
    return 0;
}

static short AITHINK_GetParam_Desert(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static __forceinline int GetXInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetYInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E0980
void __fastcall AITHINK_Fn094_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        pAiControl->dwAiParam[2] = 0;
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (nTargetDistance > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 3))
    {
        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    const int nTargetX = GetXInl_Desert(pTarget);
    const int nTargetY = GetYInl_Desert(pTarget);
    const int nUnitX = GetXInl_Desert(pUnit);
    const int nUnitY = GetYInl_Desert(pUnit);
    const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY);
    const int nIndex1 = pAiControl->dwAiParam[2] % 8;
    const int nIndex2 = sub_0063E7A0_GetByteTableEntry(nDirection) % 8;
    pAiControl->dwAiParam[2] = gnDesertTurretIndices_006E33E0[nIndex1 + 8 * nIndex2];

    const int nSpread = AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 4);
    const int nX = nUnitX + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nX;
    const int nY = nUnitY + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nY;

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    if (pMonStatsTxt->nSkill[0] >= 0 && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, nX, nY)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        sub_00648AD0((Obj00648AD0*)pUnit->pDynamicPath, nX, nY);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 1))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 0);
        }
        return;
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        --pAiControl->dwAiParam[1];
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E0F60
void __fastcall AITHINK_Fn093_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[1][pGame->nDifficulty];
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[4][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[5][pGame->nDifficulty];
        }
    }
}

// 0x005E1720
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SiegeBeastTowerAiCallbackArgStrc* pArg = (D2SiegeBeastTowerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nImp = MONSTERS_ValidateMonsterIdInline(MONSTER_IMP1);
    if (sub_00463860(pTarget) != nImp)
    {
        return 0;
    }

    if (!STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (SUNIT_GetOwner(pGame, pUnit))
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pTarget);
    if (pAiControl->dwAiParam[0] != -1)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    return pTarget;
}

// 0x005E1860
void __fastcall AITHINK_Fn113_SiegeTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        if (pTarget)
        {
            D2SiegeBeastTowerAiCallbackArgStrc arg;
            arg.nMaxDistance = 400;
            arg.unk0x04 = 0;
            D2UnitStrc* pBeast = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
            if (pBeast)
            {
                sub_005E17E0_SiegeBeastSetTower(pBeast, pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
}

// 0x005E1B60
void __fastcall AITHINK_Fn116_Minion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    int bForced = 0;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1 && pCurrentAiCmd->nCmdParam[3] > pGame->dwGameFrame)
        {
            D2UnitStrc* pTargetUnit = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]);
            if (pTargetUnit && !SUNIT_IsDead(pTargetUnit))
            {
                bForced = 1;
                if (pTarget != pTargetUnit)
                {
                    pTarget = pTargetUnit;
                    sub_006416D0_UnitEdgeDistance(pUnit, pTargetUnit);
                    bCombat = UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
                }
            }
            else
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        else
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }

    if (bCombat)
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[1][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][pGame->nDifficulty]);
        }
    }
    else
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[2][pGame->nDifficulty])
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[3][pGame->nDifficulty]);
        }
    }
}

// 0x005E26D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2NihlathakOverseerAiCallbackArgStrc* pArg = (D2NihlathakOverseerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)) != MONSTER_MINION1 || MONSTERS_IsDead(pTarget) || SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) || STATES_CheckState(pTarget, STATE_BLOODLUST))
    {
        return 0;
    }

    ++pArg->nCounter;

    if (!pArg->pTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nMaxDistance && UNITS_GetCurrentLifePercentage(pTarget) < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    if (!pArg->pDistantTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nDistantMaxDistance && !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE))
    {
        pArg->pDistantTarget = pTarget;
    }

    return 0;
}

// 0x005E27A0
void __fastcall AITHINK_Fn120_Overseer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    ACT5Q1_OnSiegeBossActivated(pGame, pUnit);

    D2UnitStrc* pMinion = AITACTICS_GetTargetMinion(pGame, pUnit);
    if (pMonStatsTxt->nSkill[0] >= 0 && sub_6FCF2E70(pUnit) && pGame->dwGameFrame > pAiControl->dwAiParam[0]
        && pMinion && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMinion, 0, 0);
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_RALLY_SPELL_TIMER);
        return;
    }

    if (bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    D2NihlathakOverseerAiCallbackArgStrc arg;
    arg.nMaxDistance = 576;
    arg.nDistantMaxDistance = 400;
    arg.nMaxLifePercentage = 50;
    arg.pTarget = 0;
    arg.pDistantTarget = 0;
    arg.nCounter = 0;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);

    D2UnitStrc* pHealTarget = arg.pTarget;
    D2UnitStrc* pDistantTarget = arg.pDistantTarget;
    int nCounter = arg.nCounter;

    if (pMonStatsTxt->nSkill[1] >= 0 && pHealTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_HEAL_CHANCE_PCT) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pHealTarget, 0, 0);
        return;
    }

    if (pMonStatsTxt->nSkill[2] && pDistantTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_WHIP_CHANCE_PCT)
        && STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_GOOD && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[2]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pDistantTarget, 0, 0);
        return;
    }

    if (nCounter)
    {
        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE))
        {
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - nTargetDistance, 0);
            return;
        }

        if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE) + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 5, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (AI_ROLL_PERCENT(pSeed) < 60)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E2B70
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MinionSpawnerAiCallbackArgStrc* pArg = (D2MinionSpawnerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)))
    {
    case MONSTER_MINION1:
    case MONSTER_SUICIDEMINION1:
        if (STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL)
        {
            ++pArg->nMinions;
        }
        break;
    }

    return 0;
}

// 0x005E2FD0
void __fastcall sub_005E2FD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = -1;
}

// 0x005E3840
void __fastcall AITHINK_Fn097_Spirit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
        return;
    }

    if (bCombat)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E3890
void __fastcall AITHINK_Fn098_Smith(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    nLifePercentage = nLifePercentage < 0 ? 0 : (nLifePercentage > 100 ? 100 : nLifePercentage);
    sub_005DE190_SetAiParam(pUnit, 0, (100 - nLifePercentage) >> 1, 0);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

// build: context AITHINK_Fn121_MinionSpawner
void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        return;
    }

    if (pAiTickParam->nTargetDistance > pMonStatsTxt->wAiParam[3][pGame->nDifficulty])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    D2MinionSpawnerAiCallbackArgStrc arg;
    arg.nMinions = 0;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_MinionSpawner, 1);
    if (pMonStatsTxt->nSkill[0] >= 0 && arg.nMinions < pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        ++pAiControl->dwAiParam[1];
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005E3900
void __fastcall sub_6FCE34B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PetMoveStrc* pArg = (D2PetMoveStrc*)pCallbackArg;
    if (pArg->pUnit == pTarget)
    {
        return;
    }

    if ((int)AIUTIL_GetDistanceToCoordinates_FullUnitSize(pArg->pUnit, pTarget) > 1)
    {
        return;
    }

    pArg->nCounter += 1;
    pArg->pTarget = pTarget;
}

static __forceinline int GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E45D0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pAiTickParam, int bSkipIdle, int nRange)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nMode = pOwner->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOwner);
    int nOwnerCollision;
    int nUnitCollision;
    int nFirstX;
    int nFirstY;
    unsigned int nLastX;
    unsigned int nLastY;
    int nMove;
    nRange += PLAYERPETS_GetTotalPetCount(pOwner) >> 1;
    if (nRange > 36) nRange = 36;
    if (nDistance <= 1 && nMode == 1 && !bCombat)
        return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 5, 0, 0, nRange);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (nDistance > 80)
            return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, nRange);
        goto ReturnZero;
    }
    nOwnerCollision = D2Common_10095(UNITS_GetRoom(pOwner), GetUnitX(pOwner), GetUnitY(pOwner));
    nUnitCollision = D2Common_10095(UNITS_GetRoom(pUnit), GetUnitX(pUnit), GetUnitY(pUnit));
    nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);
    nLastX = sub_00648A20_GetLastPointX(pPath);
    nLastY = sub_00648A30_GetLastPointY(pPath);
    nMove = 2;
    if (nMode == 2 || nMode == 6 || nMode == 3) nMove = 0;
    if (nFirstX != nLastX && nFirstY != nLastY) nMove = 0;
    if (nOwnerCollision != nUnitCollision) nMove = 1;
    if (nDistance > nRange) nMove = 1;
    if (nDistance > 50) nMove = 3;
    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pPlayerData->nSkillCooldown148, pPlayerData->nSkillCooldown14C) < 28)
    {
        if ((nMove == 1 && nDistance < 30) || nMove == 2) nMove = 4;
    }
    if (bSkipIdle && nMove == 2)
    {
ReturnZero:
        return 0;
    }
    return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, nMove, 0, 0, nRange);
}

// 0x005E4CF0
void __fastcall AITHINK_Fn067_NecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    if (pAiTickParam->pAiControl->dwAiParam[0] != 0)
    {
        sub_005E4AC0_NecroPetFollowOwner(pGame, pUnit, pAiTickParam);
    }
    else
    {
        sub_005E4830(pGame, pUnit, pAiTickParam);
    }
}

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

// 0x005E5050
void __fastcall sub_005E5050_RunHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, D2UnitStrc* pOwner, D2UnitStrc* pTarget, D2SeedStrc* pSeed, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nChance;
    if (nMonsterId == 338 || nMonsterId > 559 && nMonsterId <= 561)
        nChance = 98;
    else
    {
        const int nBaseChance = pAiControl->dwAiParam[0] + 40;
        nChance = nBaseChance + 2 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        if (nChance >= 95) nChance = 95;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pPetInfo)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    const int nHirelingId = pPetInfo->nHirelingId;
    int bAction = 0;
    if ((int)(RollSeed(pSeed) % 100) < nChance)
    {
        bAction = 1;
        pAiControl->dwAiParam[0] = 0;
    }
    else
        pAiControl->dwAiParam[0] += 10;
    if (!pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (nDistance < 4 && (int)(RollSeed(pSeed) % 100) < 50)
        {
            if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 4)) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (sub_005DEFE0_Escape(pGame, pUnit, pTarget, 4, 1)) return;
        }
        else if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    if (nDistance < 3 && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
    AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
}

// 0x005E5280
void __fastcall sub_005E5280_AiSpecialState04(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E5710
void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3)
{
    if (!pUnit || MONSTERS_IsDead(pUnit))
    {
        *(int*)a2 = 1;
    }
}

// 0x005E5B70
int __fastcall sub_6FCE5520(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MapAIStrc* pMapAi = pAiControl->pMapAi;
    if (pMapAi && pAiControl->dwAiParam[0] < pMapAi->nPathNodes)
    {
        if (pUnit)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = AITHINK_GetMonStatsTxtRecordInline(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                const int nSkillId = pMonStatsTxtRecord->nSkill[0];
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, nSkillId, 0, pMapAi->pPosition[pAiControl->dwAiParam[0]].nX, pMapAi->pPosition[pAiControl->dwAiParam[0]].nY);
                    ++pAiControl->dwAiParam[0];
                    pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                    return 1;
                }
            }
        }
    }
    else
    {
        int nFrameDiff = pGame->dwGameFrame - pAiControl->dwAiParam[1];
        if (nFrameDiff < 0)
        {
            nFrameDiff = -nFrameDiff;
        }

        if (nFrameDiff > 700)
        {
            pAiControl->dwAiParam[0] = 0;
        }
    }

    return 0;
}

// 0x005E6190
void __fastcall sub_005E6190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    sub_005F6630_InitAiParamsFrame(pGame, pUnit, pAiTickParam);
    pAiTickParam->pAiControl->nMinionSpawnClassId = -1;
}

// 0x005E61B0
void __fastcall AITHINK_Fn129_GenericSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->nMinionSpawnClassId == -1 && !sub_005E6020_SelectGenericSpawnClass(pGame, pUnit, &pAiControl->nMinionSpawnClassId))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (nTargetDistance > 20)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    int nDiff = pGame->dwGameFrame - pAiControl->dwAiParam[0];
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        const int nMonsterId = MONSTER_EVILHUT >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_EVILHUT;
        if (sub_005FD350_SpawnNearby(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSequenceSkill(pGame, pUnit, SKILL_NEST, pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E6300
void __fastcall sub_005E6300(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[2] = 0;
}

// 0x005E6860
bool __fastcall sub_005E6860_HomeCommandStep(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        return sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam);
    }

    if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) > nMaxDistance)
    {
        D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pCurrentAiCmd)
        {
            pCurrentAiCmd->nCmdParam[1] = pAiCmd->nCmdParam[1];
            pCurrentAiCmd->nCmdParam[2] = pAiCmd->nCmdParam[2];
            pCurrentAiCmd->nCmdParam[3] = 12;
            pCurrentAiCmd->nCmdParam[4] = 10;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return true;
    }

    return false;
}

// 0x005E6EF0
bool __fastcall sub_005E6EF0_MapAiActionWalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    return sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
}

// 0x005E6F00
bool __fastcall sub_6FCE6340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_SKILL1) ? MONMODE_SKILL1 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

// 0x005E6FC0
bool __fastcall sub_6FCE64D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_SKILL2) ? MONMODE_SKILL2 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

// build: context AITHINK_IdleInline
inline void AITHINK_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

inline short AI_GetParamValue(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
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

// 0x005E7540
void __fastcall AITHINK_Fn041_Towner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam) && !sub_6FCE69A0(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
    }
}

// 0x005E7590
void __fastcall AITHINK_Fn081_JarJar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!ACT2Q4_HasGuardMovedToEndPosition(pGame))
    {
        D2CoordStrc coords;
        coords.nX = pAiCmd->nCmdParam[1];
        coords.nY = pAiCmd->nCmdParam[2];

        int bFree = 1;
        if (ACT2Q4_GetGuardCoordinates(pGame, &coords))
        {
            bFree = 0;
        }

        if (pAiCmd->nCmdParam[4] < pGame->dwGameFrame && pGame->dwGameFrame - pAiCmd->nCmdParam[4] < 200)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 1)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
            pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            return;
        }

        if (bFree)
        {
            if (sub_005E68F0(pGame, pUnit, pAiTickParam))
            {
                pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }
        return;
    }

    if (pAiCmd)
    {
        int bCloseToTarget;
        D2UnitStrc* pOwner = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
        if (ACT2Q4_IsHaremBlockerObjectOpened(pGame) && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 2)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 7)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (!sub_005E68F0(pGame, pUnit, pAiTickParam) && pOwner && pOwner != pUnit)
        {
            if (pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (nDistance < 12)
                {
                    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 100)
                    {
                        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 2);
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }

            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 50)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 120);
}

static inline int AI_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005E7C10
void __fastcall sub_005E7C10_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_GetAnimMode(pUnit) != 1)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int nDistance;
        int bCombat;
        D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
        if (pTarget)
        {
            const int nRand = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (bCombat)
            {
                if (nRand < 80)
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }

            if (nRand < 30)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E7D30
int __fastcall sub_005E7D30_IsInTownOrRoomless(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 1;
    }

    return DUNGEON_IsRoomInTown(pRoom) != 0;
}

// 0x005E7D60
void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7DC0
void __fastcall sub_005E7DC0_SpecialState08TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7F50
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (UNITS_GetRoom(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
    }
}

// 0x005E7F80
void __fastcall D2GAME_AI_SpecialState09_6FCE7C40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd && pCurrentAiCmd->nCmdParam[0] == 8)
    {
        AIGENERAL_FreeMinionList(pUnit);
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
    }
    else
    {
        int nCount = 0;
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, &nCount, 0, sub_6FCE4FD0);
        if (sub_6FCF2E70(pUnit) || nCount || nDistance < 20)
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 8;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_FreeMinionList(pUnit);
            AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static __forceinline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline unsigned int CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
    }
    return 0;
}

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

static __forceinline int AI_RollPercentage_005F02C0(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005E8020
void __fastcall sub_005E8020_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pTick->bCombat && !CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, MON_FLAG)
        && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, ATTACK_MODE))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, ATTACK_MODE, pTarget);
        return;
    }
    if (AI_RollPercentage(pUnit) < WALK_CHANCE)
        AITACTICS_WalkCloseToUnit(pGame, pUnit, WALK_DISTANCE);
    else
        AITACTICS_IdleInNeutralMode(pGame, pUnit, IDLE_FRAMES);
}

// 0x005E80E0
void __fastcall D2GAME_AI_SpecialState11_6FCE7E20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return;
    }

    switch (pTarget->dwUnitType)
    {
    case 0:
        sub_6FC61E30(pUnit, 1, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case 1:
        sub_6FC61E30(pUnit, 2, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case 3:
        sub_6FC61E30(pUnit, 4, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    }
}

// 0x005E8340
void __fastcall D2GAME_AI_SpecialState12_6FCE81B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit_Inline(pUnit), AISPECIALSTATE_NONE);
        AITHINK_IdleInline(pGame, pUnit, 1);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    int bCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nDistance;
    D2UnitStrc* pTargetUnit = sub_6FCCF9D0(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
    if (pTargetUnit && bCombat)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    sub_6FCD0410(pGame, pUnit, pTarget, 7);
}

// 0x005E8480
void __fastcall sub_005E8480(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005E8530
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs)
{
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);

    int nDistanceWeight = 0;
    if (pArgs && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pArgs->nX, pArgs->nY) > 85 && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pArgs->nX, pArgs->nY) < 85)
    {
        nDistanceWeight = 100;
    }

    const int nDamageResist = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
    const int nFireResist = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
    const int nLightningResist = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
    const int nMagicResist = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
    const int nColdResist = !bInMeleeRange ? 0 : STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
    const int nResistWeight = (nFireResist + nColdResist + nLightningResist + 4 * (nDamageResist + 2 * nMagicResist)) / 15;

    const int nMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAXDAMAGE, 0);
    const int nFireMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_FIREMAXDAM, 0);
    const int nLightningMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTMAXDAM, 0);
    const int nMagicMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICMAXDAM, 0);
    const int nColdMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_COLDMAXDAM, 0);
    const int nPoisonMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_POISONMAXDAM, 0) >> 8;
    const int nDamageWeight = (nMaxDamage + nFireMaxDamage + nLightningMaxDamage + nMagicMaxDamage + nColdMaxDamage + nPoisonMaxDamage) / 2;

    const int nColdStateWeight = STATES_CheckState(pTarget, STATE_COLD) ? 100 : 0;
    const int nLifePercentageWeight = UNITS_GetCurrentLifePercentage(pTarget) < 20 ? 100 : 0;

    int nLeftSkillLevel;
    int nRightSkillLevel;
    unsigned char nLeftSkillAttackRank;
    unsigned char nRightSkillAttackRank;
    nLeftSkillLevel = nRightSkillLevel = 0;
    nLeftSkillAttackRank = nRightSkillAttackRank = 0;

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pTarget);
    if (pLeftSkill)
    {
        nLeftSkillLevel = SKILLS_GetSkillLevel(pTarget, pLeftSkill, 1);
        nLeftSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\Ai\\AiThink4.cpp", 0x225))->nAttackRank;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pTarget);
    if (pRightSkill)
    {
        nRightSkillLevel = SKILLS_GetSkillLevel(pTarget, pRightSkill, 1);
        nRightSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\Ai\\AiThink4.cpp", 0x22B))->nAttackRank;
    }

    const int nAttackRankWeight = (nLeftSkillLevel * nLeftSkillAttackRank + nRightSkillLevel * nRightSkillAttackRank) / 4;

    int nCollisionRangeWeight = 0;
    if (bInMeleeRange)
    {
        nCollisionRangeWeight = 100;
    }
    else if (sub_005DD290_NoMissileBarrierCollision(pUnit, pTarget))
    {
        nCollisionRangeWeight = 75;
    }

    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (pMonStatsTxtRecord->nThreat <= 1)
        {
            return 0;
        }
    }

    int nTotalScore = (nResistWeight + 5 * (nCollisionRangeWeight + nDistanceWeight) + 2 * (nDamageWeight + nAttackRankWeight + 2 * nColdStateWeight) + 3 * nLifePercentageWeight) / 22;
    if (!nTotalScore)
    {
        nTotalScore = 1;
    }

    return nTotalScore;
}

static __forceinline int sub_0045ADF0(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case 2:case 4:case 5:return pUnit->pStaticPath->nXPos;}
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath):0;
}

static __forceinline int sub_0045AE20(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case 2:case 4:case 5:return pUnit->pStaticPath->nYPos;}
    return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath):0;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned int SEED_RollBounded(D2SeedStrc* pSeed,int nMax)
{
    unsigned int nResult=0;
    if(nMax>0)
    {
        if((nMax-1)&nMax) nResult=(unsigned int)SEED_RollRandomNumber(pSeed)%nMax;
        else nResult=SEED_RollRandomNumber(pSeed)&(nMax-1);
    }
    return nResult;
}

// 0x005E8810
int __fastcall sub_005E8810_SelectBaalAction(D2AiControlStrc* pAi,D2UnitStrc* pUnit,D2UnitStrc* pTarget,unsigned int nDistance,int nTargets,D2AiBaalTargetArgsStrc* pInfo)
{
    if(pAi->dwAiParam[0]) return pAi->dwAiParam[0];
    if(!pTarget)
    {
        if(COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit),sub_0045ADF0(pUnit),sub_0045AE20(pUnit),2,64)) return 16;
        return (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed)%1000)<1 ? 4:11;
    }
    D2GameStrc* pGame=SUNIT_GetGameFromUnit(pTarget);
    if(!pGame)pGame=SUNIT_GetGameFromUnit(pUnit);
    D2UnitStrc* pPortal=0;
    int bPortal=0;
    if((!pTarget ? 6:pTarget->dwUnitType)==0)
    {
        pPortal=SUNIT_GetServerUnit(pGame,2,PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if(pPortal && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal))==108)
            if(sub_006417F0_GetDistance(pPortal,pInfo->nX,pInfo->nY)<85)bPortal=1;
    }
    int bDangerousSkill=0;
    D2SkillStrc* pSkill=UNITS_GetLeftSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,639);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    pSkill=UNITS_GetRightSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,646);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    int bVeryFar=0;
    int bFar=0;
    if(pInfo)
    {
        int nDist=sub_005DC480_GetDistance(pTarget,pInfo->nX,pInfo->nY);
        if(nDist>85)bFar=1;
        if(nDist>105)bVeryFar=1;
    }
    int bMelee=UNITS_IsInMeleeRange(pUnit,pTarget,0);
    int bAttack=sub_005DD290_CheckAttack(pUnit,pTarget);
    int nFireRes=STATLIST_UnitGetStatValue(pTarget,39,0);
    int nColdRes=STATLIST_UnitGetStatValue(pTarget,41,0);
    int nWeights[17];
    int bInitialized=0;
    if(bMelee)
    {
        int nInitial[17]={0,0,40,70,0,40,24,40,15,0,0,0,0,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(UNITS_GetCurrentLifePercentage(pTarget)<20)nWeights[2]=50;
        if(STATES_CheckState(pTarget,11)){nWeights[7]=0;nWeights[8]=0;}
        if(nFireRes>nColdRes)nWeights[6]-=10;
        if(nFireRes<nColdRes)nWeights[6]+=10;
        if(!bAttack){nWeights[5]=0;nWeights[6]=0;}
        if(bPortal)nWeights[15]=10;
        bInitialized=1;
    }
    if(!bAttack)
    {
        if(!bInitialized)
        {
            int nInitial[17]={0,0,0,0,5,0,25,0,25,40,0,0,25,0,0,0,0};
            memcpy(nWeights,nInitial,sizeof(nWeights));
            if(nTargets<2){nWeights[6]=0;nWeights[1]=25;nWeights[8]-=5;nWeights[9]=0;}
            if(bDangerousSkill && !bFar)nWeights[13]=15;
            else if(bFar)
            {
                nWeights[1]=0;nWeights[12]=15;nWeights[13]=25;
                if(!nWeights[9])nWeights[9]=20;
                if(nTargets<2)nWeights[9]-=5;
            }
            if(bVeryFar)nWeights[14]=60;
            if(bPortal)nWeights[15]=20;
        }
    }
    else if(!bInitialized)
    {
        int nInitial[17]={0,0,0,0,0,25,25,0,15,20,10,0,20,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit,pTarget)>25){nWeights[10]=20;nWeights[5]=0;nWeights[8]-=5;}
        if(nFireRes>nColdRes){nWeights[6]-=10;nWeights[8]-=10;}
        if(nFireRes<nColdRes){nWeights[6]+=10;nWeights[8]+=10;}
        if(nTargets<2)nWeights[6]-=10;
        if(nTargets>3)nWeights[6]+=5;
        if(nDistance>60)nWeights[9]+=10;
        D2PlayerCountBonusStrc tBonus;
        MONSTER_GetPlayerCountBonus(pGame,&tBonus,UNITS_GetRoom(pUnit),pUnit);
        if(nTargets<2 && tBonus.nDifficulty<2)nWeights[9]=0;
        if(bDangerousSkill && !bFar){nWeights[6]+=10;nWeights[10]=30;nWeights[13]=15;}
        else if(bFar)
        {
            nWeights[1]=0;nWeights[12]=10;nWeights[10]=0;nWeights[13]=15;
            if(!nWeights[9])nWeights[9]=10;
        }
        if(bVeryFar){nWeights[9]=20;nWeights[14]=60;}
        if(bPortal)nWeights[15]=15;
    }
    if(sub_005FD470(pGame,pUnit,199,pTarget,0,0))nWeights[9]=0;
    if(nWeights[15] && pPortal && !sub_005FD470(pGame,pUnit,199,pPortal,0,0))nWeights[15]=0;
    int* pWeight=nWeights;
    int nTotal=0;
    for(int n=17;n;--n)nTotal+=*pWeight++;
    int nRoll=SEED_RollBounded(&pUnit->pSeed,nTotal);
    int nSum=0;
    pWeight=nWeights;
    for(int i=0;i<17;++i,++pWeight)
    {
        nSum+=*pWeight;
        if(nRoll<nSum)return i;
    }
    return 11;
}

// 0x005E9750
int __fastcall sub_005E9750_DiabloChooseAction(D2AiControlStrc* pAi,D2UnitStrc* pUnit,D2UnitStrc* pTarget,unsigned int nDistance,int nTargets,D2AiBaalTargetArgsStrc* pInfo)
{
    if(pAi->dwAiParam[0]) return pAi->dwAiParam[0];
    if(!pTarget)
    {
        if(COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit),sub_0045ADF0(pUnit),sub_0045AE20(pUnit),2,64)) return 16;
        return (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed)%1000)<1 ? 4:11;
    }
    D2GameStrc* pGame=SUNIT_GetGameFromUnit(pTarget);
    if(!pGame)pGame=SUNIT_GetGameFromUnit(pUnit);
    D2UnitStrc* pPortal=0;
    int bPortal=0;
    if((!pTarget ? 6:pTarget->dwUnitType)==0)
    {
        pPortal=SUNIT_GetServerUnit(pGame,2,PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if(pPortal && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal))==108)
            if(sub_006417F0_GetDistance(pPortal,pInfo->nX,pInfo->nY)<85)bPortal=1;
    }
    int bDangerousSkill=0;
    D2SkillStrc* pSkill=UNITS_GetLeftSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1356);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    pSkill=UNITS_GetRightSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1363);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    int bFar=0;
    int bVeryFar=0;
    if(pInfo)
    {
        int nDist=AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget,pUnit);
        if(nDist>85)bFar=1;
        if(nDist>105)bVeryFar=1;
    }
    int bMelee=UNITS_IsInMeleeRange(pUnit,pTarget,0);
    int bAttack=sub_005DD290_CheckAttack(pUnit,pTarget);
    int nFireRes=STATLIST_UnitGetStatValue(pTarget,39,0);
    int nColdRes=STATLIST_UnitGetStatValue(pTarget,41,0);
    int nWeights[17];
    int bInitialized=0;
    if(bMelee)
    {
        int nInitial[17]={0,0,40,70,0,75,24,40,15,0,0,0,0,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(UNITS_GetCurrentLifePercentage(pTarget)<20)nWeights[2]=50;
        if(STATES_CheckState(pTarget,11)){nWeights[7]=0;nWeights[8]=0;}
        if(nFireRes>nColdRes)nWeights[6]-=10;
        if(nFireRes<nColdRes)nWeights[6]+=10;
        if(!bAttack){nWeights[5]=0;nWeights[6]=0;}
        if(bPortal)nWeights[15]=10;
        bInitialized=1;
    }
    if(!bAttack)
    {
        if(!bInitialized)
        {
            int nInitial[17]={0,0,0,0,5,0,25,0,25,40,0,0,25,0,0,0,0};
            memcpy(nWeights,nInitial,sizeof(nWeights));
            if(nTargets<2){nWeights[6]=0;nWeights[1]=25;nWeights[8]-=5;nWeights[9]=0;}
            if(bDangerousSkill && !bFar)nWeights[13]=15;
            else if(bFar)
            {
                nWeights[1]=60;nWeights[12]=15;nWeights[13]=25;
                if(!nWeights[9])nWeights[9]=20;
                if(nTargets<2)nWeights[9]-=5;
            }
            if(bVeryFar)nWeights[1]=60;
            if(bPortal)nWeights[15]=20;
        }
    }
    else if(!bInitialized)
    {
        int nInitial[17]={0,0,0,0,0,5,25,0,15,20,10,0,20,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit,pTarget)>25){nWeights[10]=20;nWeights[5]=0;nWeights[8]-=5;}
        if(nFireRes>nColdRes){nWeights[6]-=10;nWeights[8]-=10;}
        if(nFireRes<nColdRes){nWeights[6]+=10;nWeights[8]+=10;}
        if(nTargets<2)nWeights[6]-=10;
        if(nTargets>3)nWeights[6]+=5;
        if(nDistance>60)nWeights[9]+=10;
        D2PlayerCountBonusStrc tBonus;
        MONSTER_GetPlayerCountBonus(pGame,&tBonus,UNITS_GetRoom(pUnit),pUnit);
        if(nTargets<2 && tBonus.nDifficulty<2)nWeights[9]=0;
        if(bDangerousSkill && !bFar){nWeights[6]+=10;nWeights[10]=30;nWeights[13]=15;}
        else if(bFar)
        {
            nWeights[1]=50;nWeights[10]=0;nWeights[13]=15;
            if(!nWeights[9])nWeights[9]=10;
        }
        if(bVeryFar){nWeights[9]=20;nWeights[1]=60;}
        if(bPortal)nWeights[15]=15;
    }
    if(sub_005FD470(pGame,pUnit,199,pTarget,0,0))nWeights[9]=0;
    if(nWeights[15] && pPortal && !sub_005FD470(pGame,pUnit,199,pPortal,0,0))nWeights[15]=0;
    int* pWeight=nWeights;
    int nTotal=0;
    for(int n=17;n;--n)nTotal+=*pWeight++;
    int nRoll=SEED_RollBounded(&pUnit->pSeed,nTotal);
    int nSum=0;
    pWeight=nWeights;
    for(int i=0;i<17;++i,++pWeight)
    {
        nSum+=*pWeight;
        if(nRoll<nSum)return i;
    }
    return 11;
}

// 0x005E9DD0
void __fastcall AITHINK_SpawnUberDiabloMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget)
    {
        sub_6FC68D70(pGame, pTarget, MONSTER_DEMONHOLE, MONMODE_NEUTRAL, 4, 64);
    }
}

// 0x005E9DF0
void __fastcall AITHINK_Fn147_UberDiablo(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

// 0x005E9E00
void __fastcall AITHINK_Fn042_Vendor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_RollPercentage(pUnit) < 20)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005E9E60
void __fastcall sub_005E9E60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if ( pAiTickParam->nTargetDistance < 25 && AI_RollPercentage(pUnit) < 60)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E9F10
void __fastcall AITHINK_Fn099_TrappedSoul(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2CoordStrc unitCoord;
    D2CoordStrc targetCoord;

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }

    UNITS_GetCoords(pUnit, &unitCoord);

    if (pTarget && nDistance < 5)
    {
        if (!pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pGame->dwGameFrame;
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat && pGame->dwGameFrame > pAiControl->dwAiParam[1])
        {
            UNITS_GetCoords(pTarget, &targetCoord);

            if ((unsigned int)unitCoord.nX >= (unsigned int)targetCoord.nX && (unsigned int)unitCoord.nY <= (unsigned int)targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
                return;
            }

            if ((unsigned int)unitCoord.nX <= (unsigned int)targetCoord.nX && (unsigned int)unitCoord.nY >= (unsigned int)targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 5;
            }
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
    }
    else
    {
        if (pAiControl->dwAiParam[0])
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        }
    }
}

// 0x005EA080
void __fastcall AITHINK_Fn088_7TIllusion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] == 1)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_ATTACK1, UNITS_GetUnitXPositionInline(pUnit) - 10, UNITS_GetUnitYPositionInline(pUnit));
    pAiControl->dwAiParam[1] = 1;
}

// 0x005EA130
void __fastcall sub_005EA130_UpdateWanderer(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
 D2AiControlStrc* control=tick->pAiControl;
 D2UnitStrc* target=tick->pTarget;
 int distance=tick->nTargetDistance;
 D2CoordStrc coords;
 if(!ACT3Q7_GetWandererCoordinates(game,unit,&coords)) {
  AITACTICS_IdleInNeutralMode(game,unit,10);return;
 }
 if(!control->dwAiParam[0]) {
  control->dwAiParam[0]=1;control->dwAiParam[1]=0;control->dwAiParam[2]=0;
 }
 if(!target) {AITACTICS_IdleInNeutralMode(game,unit,10);return;}
 if(distance<20) {
  int nState=control->dwAiParam[0];
  {
  if(nState==1) {
   AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);
   control->dwAiParam[0]=2;return;
  }
  else if(nState==2) {
   if((unsigned int)AIUTIL_GetDistanceToCoordinates(unit,coords.nX,coords.nY)<2) {
    if(unit) unit->dwFlags|=0x20000;
    AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
    ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
   }
   if(control->dwAiParam[1]<3) {
    ++control->dwAiParam[1];
    sub_005DE190_SetAiParam(unit,1,0,0);
    AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);return;
   }
   if(unit) unit->dwFlags|=0x20000;
   AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
   ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
  }
  else { AITACTICS_IdleInNeutralMode(game,unit,40); return; }
 }
 }
 AITACTICS_IdleInNeutralMode(game,unit,40);
}

// 0x005EA290
void __fastcall sub_005EA290(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = pGame->dwGameFrame;
    pAiControl->dwAiParam[1] = -1;
}

// 0x005EA2B0
int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] < 0)
    {
        const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        D2AiControlStrc* pAiControlSet = pAiTickParam->pAiControl;
        pAiControlSet->dwAiParam[1] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        if (bDecreaseParam)
        {
            pAiControl->dwAiParam[1] -= 1;
        }
        return 0;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
    return 1;
}

// 0x005EA3D0
void __fastcall AITHINK_Fn101_AssassinSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nActiveDistance = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
    const int nSkillId = pMonStatsTxt->nSkill[0];
    if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, 12))
    {
        STATES_ToggleState(pUnit, 12, 0);
    }

    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget || nDistance >= nActiveDistance)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
        return;
    }

    const int nDifficulty = pGame->nDifficulty;
    if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[0][nDifficulty])
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][nDifficulty]);
}

// 0x005EA510
void __fastcall sub_005EA510(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = -1;
    pAiControl->dwAiParam[1] = 1;
    pAiControl->dwAiParam[2] = 0;
}

// 0x005EA540
void __fastcall AITHINK_Fn102_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (pAiControl->dwAiParam[0] < 0)
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (!pAiControl->dwAiParam[2])
    {
        if (pSkillsTxtRecord->wSrvMissileA >= 0 && pSkillsTxtRecord->wSrvMissileA < sgptDataTables->nMissilesTxtRecordCount)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }

            D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pOwner, nSkillId, nSkillLevel, pSkillsTxtRecord->wSrvMissileA, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            if (pMissile)
            {
                UNITS_StoreOwner(pMissile, pUnit);
                const int nAttackRate = UNITS_GetAttackRate(pOwner);
                STATLIST_AddUnitStat(pUnit, STAT_TOHIT, nAttackRate, 0);

                int nToHitPercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_TOHIT_PERCENT, 0);
                D2UnitStrc* pWeapon = sub_6FC7C7B0(pOwner);
                if (pWeapon)
                {
                    nToHitPercent += SKILLS_GetWeaponMasteryBonus(pOwner, pWeapon, 0, 0);
                }

                STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHitPercent, 0);
            }

            pAiControl->dwAiParam[2] = 1;
        }
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pAiCmd)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return;
    }

    AITACTICS_SetVelocity(pUnit, 15, 0, 20);

    if (pAiControl->dwAiParam[1])
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }
    }
    else
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }
    }

    D2UnitStrc* pWalkOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pWalkOwner, 5))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
    }
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitXInline_005F02C0(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline_005F02C0(D2UnitStrc* pUnit)
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

// 0x005EA7A0
void __fastcall AITHINK_Fn103_InvisoPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);

    int nParam = AI_GetParam(pGame, pMonStatsTxt, 0);
    const int nAnimMode = !pOwner ? 0 : pOwner->dwAnimMode;

    const int bOwnerGetHit = nAnimMode == 3;
    if (bOwnerGetHit)
    {
        nParam /= 2;
    }

    if (pAiControl->dwAiParam[0] >= pGame->dwGameFrame && !bOwnerGetHit && !sub_6FCF2E70(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pOwner) + SEED_RollLimitedRandomNumber_Inline(&pUnit->pSeed, 2 * nParam) - nParam;
    const int nY = CLIENTS_GetUnitYInline(pOwner) + SEED_RollLimitedRandomNumber_Inline(&pUnit->pSeed, 2 * nParam) - nParam;

    AITACTICS_UseSkill(pGame, pUnit, 9, 0x124, 0, nX, nY);
    pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, 1);
}

// 0x005EA980
void __fastcall sub_005EA980_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt;
    int nSkillId;
    D2SkillStrc* pSkill;
    int nSkillLevel;
    D2UnitStrc* pTarget;
    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pSkillTarget;
    int nLastTarget;
    int nRange;

    if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    nSkillId = pMonStatsTxt->nSkill[0];
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return;
    }

    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (nSkillLevel <= 0)
    {
        return;
    }

    pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    pSkillTarget = sub_6FD15210(pUnit, pTarget, nSkillId, nSkillLevel);
    nLastTarget = pAiTickParam->pAiControl->dwAiParam[0];
    nRange = sub_004CC7C0_GetSkillMissileRange(nSkillId, nSkillLevel) / 2;
    if (pSkillTarget && (!pSkillTarget ? -1 : pSkillTarget->dwUnitId) != nLastTarget && sub_006416D0_UnitEdgeDistance(pTarget, pSkillTarget) < nRange)
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = !pSkillTarget ? -1 : pSkillTarget->dwUnitId;
        AITACTICS_UseSkill(pGame, pUnit, 9, nSkillId, pSkillTarget, 0, 0);
        return;
    }

    if (nDistance < pMonStatsTxt->wAiParam[3][pGame->nDifficulty] && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        AITACTICS_UseSkill(pGame, pUnit, 14, pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005EAB20
int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const short nSummonId = pSkillsTxtRecord->wSummon;
    if (!nSummonId)
    {
        return 1;
    }

    const int nTargetClassId = !pTarget ? -1 : pTarget->dwClassId;
    if ((short)pSkillsTxtRecord->wSummon == (unsigned short)nTargetClassId)
    {
        return 0;
    }

    const int nPetType = (signed char)pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount || !pUnit)
    {
        return 1;
    }

    return PLAYERPETS_GetPetTypeFromPetGUID(pUnit, !pTarget ? -1 : pTarget->dwUnitId) != nPetType;
}

// 0x005EABF0
int __fastcall sub_005EABF0_CheckShadowMasterSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, D2AiTickParamStrc* pAiTick)
{
    int bCombat = pAiTick->bCombat;
    D2UnitStrc* pTarget = pAiTick->pTarget;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkills || !AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId)) return 0;
    if (bCombat)
    {
        if (pSkills->nAiType != 4 && pSkills->nAiType != 13) return 0;
    }
    else
    {
        if (pSkills->nAiType == 4 || pSkills->nAiType == 13) return 0;
    }
    if (pSkills->nAiType == 1 && pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
    if (!pTarget)
    {
        switch (pSkills->nAiType)
        {
        case 2: case 4: case 5: case 11: case 12: case 13: return 0;
        }
    }
    if (pSkills->nAiType == 2)
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
        if (pSkills->wAuraTargetState > 0 && STATES_CheckState(pTarget, pSkills->wAuraTargetState)) return 0;
    }
    if (pSkills->nFlags[0] & (unsigned char)gdwBitMasks[2])
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkills->nAuraState);
            if (pStatList && STATLIST_GetStatValue(pStatList, pSkills->wAuraStat[0], 0) >= 3) return 0;
        }
    }
    return 1;
}

// 0x005EAD50
int __fastcall sub_005EAD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillStrc* pSkill, int nSkillId, int nUnused, D2Unk005EAD50ArgStrc* pArg)
{
    if (pSkill && pTarget && pArg)
    {
        D2Unk005EAD50CounterStrc* pCounter = pArg->pCounter;
        if (pCounter)
        {
            const int nClassId = pTarget->dwClassId;
            if (SKILLS_GetClassIdFromSkillId(nSkillId) != nClassId)
            {
                return 0;
            }

            if (!sub_005EABF0(pGame, pTarget, pUnit, nSkillId, pArg))
            {
                return 0;
            }

            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            if (!nSkillId)
            {
                return 1;
            }

            const int nValue = sub_006459F0(nSkillId, nSkillLevel);
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) > 100 - nValue * 160 / 100)
            {
                return 0;
            }

            if (pCounter->nFrame > pGame->dwGameFrame)
            {
                return 0;
            }

            D2Unk005EAD50LimitsStrc* pLimits = pArg->pLimits;
            const int nMin = D2_MIN(D2_MAX(pLimits->nMin, 1), 128);
            const int nMax = D2_MIN(D2_MAX(pLimits->nMax, 1), 256);
            if (pCounter->nValue < nMin || pCounter->nValue > 32 * nMax)
            {
                pCounter->nValue = nMin;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, pCounter->nValue) > (int)SEED_RollLimitedRandomNumber(pSeed, 100))
            {
                return 0;
            }

            pCounter->nValue += (320 - pCounter->nBase) * nValue / (pCounter->nBase + 100);
            return 1;
        }
    }

    return 0;
}

// 0x005EAF00
int __fastcall sub_005EAF00_ShadowWarriorSkillLevel(D2GameStrc* pGame, D2UnitStrc* pOwner, D2SkillStrc* pSkill, D2AiTickParamStrc* pAiTickParam)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nLevel = pAiTickParam->pAiControl->dwAiParam[2] / 3 + nSkillLevel / 2;
    return nLevel > 1 ? nLevel : 1;
}

// 0x005EAF50
void __fastcall sub_005EAF50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }
}

// 0x005EAFA0
void __fastcall sub_005EAFA0_ShadowWarrior(D2GameStrc* game, D2UnitStrc* unit, D2AiTickParamStrc* tick)
{
    D2MonStatsTxt* stats = tick->pMonstatsTxt;
    D2UnitStrc* target = tick->pTarget;
    int combat = tick->bCombat;
    int distance = tick->nTargetDistance;
    D2GAME_EVENTS_Delete_6FC34840(game, unit, 2, 0);
    D2UnitStrc* owner = AIGENERAL_GetMinionOwner(unit);
    if (!owner) { AITACTICS_IdleInNeutralMode(game, unit, 100); return; }
    int limit = MINIMUM(MAXIMUM(tick->pMonstatsTxt->wAiParam[7][2], 1), 256);
    tick->pAiControl->dwAiParam[1] -= stats->wAiParam[3][game->nDifficulty] + 1;
    if (tick->pAiControl->dwAiParam[1] < 0 || tick->pAiControl->dwAiParam[1] > 64 * limit) tick->pAiControl->dwAiParam[1] = 0;
    int ownerDistance = sub_006416D0_UnitEdgeDistance(unit, owner);
    if (distance > stats->wAiParam[0][game->nDifficulty] || ownerDistance > stats->wAiParam[1][game->nDifficulty]) target = 0;
    if (sub_005E45D0(game, unit, target, owner, combat, tick, 0, 6)) return;
    if (!target) goto idle;
    {
    D2SkillStrc* ownerRight = UNITS_GetRightSkill(owner);
    D2SkillStrc* ownerLeft = UNITS_GetLeftSkill(owner);
    if (!ownerRight || !ownerLeft) goto idle;
    int rightId = SKILLS_GetSkillIdFromSkill(ownerRight, ".\\Ai\\AiThink4.cpp", 0xB53);
    int leftId = SKILLS_GetSkillIdFromSkill(ownerLeft, ".\\Ai\\AiThink4.cpp", 0xB54);
    int rightLevel = sub_005EAF00_ShadowWarriorSkillLevel((D2GameStrc*)unit, owner, ownerRight, tick);
    int leftLevel = sub_005EAF00_ShadowWarriorSkillLevel((D2GameStrc*)unit, owner, ownerLeft, tick);
    SKILLS_AssignSkill(unit, rightId, rightLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB59);
    SKILLS_AssignSkill(unit, leftId, leftLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB5A);
    D2SkillStrc* right = SKILLS_GetSkillById(unit, rightId, -1);
    D2SkillStrc* left = SKILLS_GetSkillById(unit, leftId, -1);
    if (!right || !left) goto idle;
    D2SkillStrc* selected = right;
    if (SEED_RollLimitedRandomNumber(&unit->pSeed, 2)) selected = left;
    int skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB66);
    int count = MAXIMUM(tick->pAiControl->dwAiParam[2], 1);
    int chance = stats->wAiParam[2][game->nDifficulty] - 2 * count;
    chance = MINIMUM(MAXIMUM(chance, 5), 100);
    if (combat && (int)SEED_RollLimitedRandomNumber(&unit->pSeed, 100) < chance) {
        selected = SKILLS_GetSkillById(unit, 0, -1);
        skillId = 0;
    }
    if (!sub_005EAD50(game, unit, owner, selected, skillId, combat, (D2Unk005EAD50ArgStrc*)tick)) {
        selected = selected == left ? right : left;
        int alternativeId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB79);
        if (!sub_005EAD50(game, unit, owner, selected, alternativeId, combat, (D2Unk005EAD50ArgStrc*)tick)) {
            selected = SKILLS_GetSkillById(unit, 0, -1);
            if (!selected) {
                SKILLS_AssignSkill(unit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 0xB81);
                selected = SKILLS_GetSkillById(unit, 0, -1);
            }
        }
    }
    if (!selected) goto idle;
    skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB8F);
    if (D2Common_11016(unit, selected) == 1) {
        if (combat) {
            AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB96), target, 0, 0);
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
            int level = SKILLS_GetSkillLevel(unit, selected, 1);
            if (level <= 1) level = 1;
            tick->pAiControl->dwAiParam[0] = SKILLS_EvaluateSkillFormula(unit, record->dwDelay, skillId, level) / 3 + game->dwGameFrame + 18;
            return;
        }
        AITACTICS_RunToTargetUnit(game, unit, target);
        return;
    }
    AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xBA8), target, 0, 0);
    D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
    int level = SKILLS_GetSkillLevel(unit, selected, 1);
    if (level <= 1) level = 1;
    tick->pAiControl->dwAiParam[0] = SKILLS_EvaluateSkillFormula(unit, record->dwDelay, skillId, level) / 3 + game->dwGameFrame + 18;
    return;
    }
idle:
    AITACTICS_IdleInNeutralMode(game, unit, 25);
}

// 0x005EB420
int __fastcall sub_005EB420_ShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pOwner, nSkillId, -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 0);
        }
    }

    const int nLevel = nSkillLevel / 2 + nParam / 2;
    if (nLevel > 1 && nLevel < 24)
    {
        return nLevel;
    }
    if (nLevel <= 1)
    {
        return 1;
    }
    return 24;
}

// 0x005EB490
void __fastcall sub_005EB490(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = 0;
    pAiControl->dwAiParam[1] = 0;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nParam = pAiControl->dwAiParam[2];

    if (!SKILLS_GetSkillById(pUnit, 0, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3054);
    }

    SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    SKILLS_SetRightActiveSkill(pUnit, 0, -1);

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(sub_00451F60_UnitClassId(pOwner)); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(sub_00451F60_UnitClassId(pOwner), i);

        if (AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId))
        {
            SKILLS_GetSkillById(pUnit, nSkillId, -1);
            const int nLevel = sub_005EB420_ShadowMasterSkillLevel(pGame, pUnit, pOwner, nParam, nSkillId);
            SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\Ai\\AiThink4.cpp", 3069);
        }
    }
}

// 0x005EB5C0
void __fastcall sub_005EB5C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    if (!SKILLS_GetSkillById(pUnit, 0, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3101);
    }

    SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    SKILLS_SetRightActiveSkill(pUnit, 0, -1);
}

// 0x005EB6D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ShadowMasterAiCallbackArgStrc* pArg = (D2ShadowMasterAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        const int nClassId = MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget));
        switch (nClassId)
        {
        case MONSTER_WAKEOFDESTRUCTION:
        case MONSTER_CHARGEBOLTSENTRY:
        case MONSTER_LIGHTNINGSENTRY:
        case MONSTER_BLADECREEPER:
        case MONSTER_INFERNOSENTRY:
        case MONSTER_DEATHSENTRY:
            ++pArg->unk0x20;
            return 0;

        default:
            break;
        }
    }

    if (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (pArg->unk0x00)
    {
        const int nDistance = AITHINK_GetSquaredDistance(pArg->unk0x00, pTarget);

        if (nDistance <= 100)
        {
            ++pArg->unk0x18;
        }

        if (nDistance < pArg->unk0x14)
        {
            pArg->unk0x10 = pTarget;
            pArg->unk0x14 = nDistance;
        }
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance <= 1024)
    {
        ++pArg->unk0x1C;

        if (nDistance <= 100)
        {
            ++pArg->unk0x0C;
        }

        if (nDistance < pArg->unk0x08)
        {
            pArg->unk0x04 = pTarget;
            pArg->unk0x08 = nDistance;
        }

        if (AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
        {
            pArg->unk0x24 = pTarget;
        }
    }

    return 0;
}

// 0x005EB8B0
int __fastcall sub_005EB8B0_ShadowMasterUseSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam)
{
    if (pTarget && (pTarget == pOwner || pTarget == pUnit))
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (!pSkill)
    {
        return 0;
    }

    if (pTarget && (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit))))
    {
        return 0;
    }

    if (D2Common_11016(pUnit, pSkill) == 1 && !bCombat)
    {
        return AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 4);
    }

    return AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, nX, nY);
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0)
    {
        return 0;
    }

    return sub_0046ACE0(nMissileId);
}

static __forceinline D2StatListStrc* GetAuraStateStatList(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord)
{
    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    }

    return 0;
}

static __forceinline int AI_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return SKILLS_GetSkillLevel(pUnit, pSkill, 1);
}

static __forceinline int AI_ClampChance(int nChance)
{
    if (nChance > 5 && nChance < 100)
    {
        return nChance;
    }

    if (nChance <= 5)
    {
        return 5;
    }

    return 100;
}

// 0x005EB970
void __fastcall AITHINK_Fn106_143_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SkillListStrc* pSkillList = pUnit->pSkills;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!pSkillList)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 100);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (pOwner)
    {
        const int nOwnerDistance = AITHINK_GetSquaredDistance(pUnit, pOwner);
        if (nOwnerDistance > pMonStatsTxt->wAiParam[1][2] * pMonStatsTxt->wAiParam[1][2]
            && sub_005E45D0(pGame, pUnit, 0, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pCurrentTarget)
        {
            pTarget = pCurrentTarget;
        }

        if (!pTarget)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
            if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, pAiControl->dwAiParam[1], bCombat, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }
    }

    if (nTargetDistance > pMonStatsTxt->wAiParam[1][1])
    {
        pTarget = 0;
    }

    if (!pTarget)
    {
        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3443);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState > 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (!sub_005EB7F0_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState) || (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 4)
                        {
                            if ((int)(SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100) < 60)
                            {
                                D2SkillStrc* pUseSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                                if (pUseSkill)
                                {
                                    int nResult;
                                    if (D2Common_11016(pUnit, pUseSkill) == 1)
                                    {
                                        if (!bCombat)
                                        {
                                            nResult = AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, 0, 4);
                                        }
                                        else
                                        {
                                            nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                        }
                                    }
                                    else
                                    {
                                        nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                    }

                                    if (nResult)
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit) && (int)(SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100) < 20)
                    {
                        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                    }
                    break;
                }
            }
        }
    }

    D2UnitStrc* pOwnerTarget = 0;
    if (pOwner)
    {
        pOwnerTarget = SUNIT_GetTargetUnit(pGame, pOwner);
        if (pOwnerTarget)
        {
            if (!SUNIT_IsDead(pOwnerTarget) && SUNIT_AreUnitsHostile(pGame, pUnit, pOwnerTarget))
            {
                pTarget = pOwnerTarget;
            }
            else
            {
                pOwnerTarget = 0;
            }
        }

        if (AITHINK_GetSquaredDistance(pUnit, pOwner) <= 144 && sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nParam = pAiTickParam->pAiControl->dwAiParam[2];
    if (nParam <= 1)
    {
        nParam = 1;
    }

    int nChance = pMonStatsTxt->wAiParam[2][pGame->nDifficulty] - 2 * nParam;
    nChance = AI_ClampChance(nChance);

    if (!bCombat || (int)SEED_RollLimitedRandomNumber(pSeed, 100) >= nChance
        || !sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, 0, bCombat, pTarget, 0, 0, pAiTickParam))
    {

        D2ShadowMasterAiCallbackArgStrc arg = {};
        arg.unk0x00 = pOwner;
        arg.unk0x08 = 0x7FFFFFFF;
        arg.unk0x14 = 0x7FFFFFFF;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_ShadowMaster, 1);

        if (!bCombat)
        {
            if (pOwnerTarget)
            {
                pTarget = pOwnerTarget;
            }
            else if (arg.unk0x10)
            {
                pTarget = arg.unk0x10;
            }
            else if (arg.unk0x24)
            {
                D2UnitStrc* pArg24 = arg.unk0x24;
                if (AITHINK_GetSquaredDistance(pUnit, pArg24) < 1024)
                {
                    pTarget = pArg24;
                }
            }

            if (!AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
            {
                D2UnitStrc* pTargetOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (pTargetOwner && !SUNIT_IsDead(pTargetOwner) && AITHINK_GetSquaredDistance(pUnit, pTargetOwner) < 1024)
                {
                    pTarget = pTargetOwner;
                }
            }
        }

        const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
        const int nDistanceToTarget = AITHINK_GetSquaredDistance(pUnit, pTarget);

        int bProgressiveState;
        if (pMonStatsTxt->wAiParam[0][2] > 0 && STATES_CheckStateMaskPgsvOnUnit(pUnit))
        {
            bProgressiveState = 1;
        }
        else
        {
            bProgressiveState = 0;
        }

        const int bNotColliding = UNITS_TestCollisionWithUnit(pUnit, pTarget, COLLIDE_MISSILE_BARRIER) == 0;

        D2UnitStrc* pArg10 = arg.unk0x10;
        const int nArg20 = arg.unk0x20;
        const int nArg1C = arg.unk0x1C;

        const int nArg0C = *(volatile int*)&arg.unk0x0C;
        const int nArg08 = arg.unk0x08;
        const int nArg18 = arg.unk0x18;

        if (nArg0C > 3)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 32) < 2 * nArg0C)
            {
                if (pOwner && AITHINK_GetSquaredDistance(pUnit, pOwner) > 36)
                {
                    AITACTICS_RunToTargetUnit(pGame, pUnit, pOwner);
                    return;
                }

                if (sub_005DF140_Escape(pGame, pUnit, pTarget, 8, 1))
                {
                    return;
                }
            }
        }

        int nAuraStatBonus = 0;

        D2ShadowMasterSkillStrc shadowMasterSkills[48];
        shadowMasterSkills[0].nSkillId = 0;
        shadowMasterSkills[0].nChance = 0;
        shadowMasterSkills[0].pTarget = pTarget;
        shadowMasterSkills[0].nX = 0;
        shadowMasterSkills[0].nY = 0;

        int nCounter = 1;
        const int nRandomPick = pMonStatsTxt->wAiParam[1][0];

        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3645);
            int nResistance = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pSkillTarget = pTarget;
                int nCurrentValue = 0;
                int nTemp = pSkillsTxtRecord->wAiBonus;
                nTemp += pSkillsTxtRecord->wReqLevel / 4 + nResistance;
                nResistance = 0;

                switch (pSkillsTxtRecord->nEType)
                {
                case ELEMTYPE_NONE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
                    break;

                case ELEMTYPE_FIRE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
                    break;

                case ELEMTYPE_LTNG:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
                    break;

                case ELEMTYPE_COLD:
                case ELEMTYPE_FREEZE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
                    break;

                case ELEMTYPE_POIS:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0);
                    break;

                case ELEMTYPE_MAGIC:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
                    break;
                }

                nTemp += nResistance / -10;

                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAuraState <= 0 || STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (nArg08 <= 25)
                        {
                            nTemp -= 6;
                        }

                        if (sub_005EB7F0_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState))
                        {
                            nTemp -= 10;
                        }
                        else
                        {
                            nTemp += 10;
                        }

                        nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        pSkillTarget = pUnit;
                    }
                    break;

                case 2:
                    if (pSkillsTxtRecord->nAuraState <= 0 || !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (pSkillsTxtRecord->wAuraTargetState <= 0 || !STATES_CheckState(pTarget, pSkillsTxtRecord->wAuraTargetState))
                        {
                            if (nArg08 <= 25)
                            {
                                nTemp -= 10;
                            }

                            nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        }
                    }
                    break;

                case 3:
                    if (nArg20 > 5)
                    {
                        nTemp += -2 * nArg20;
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 7;
                    }

                    if (nArg1C < 3)
                    {
                        nTemp -= 10;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * (nArg1C - 3);
                    break;

                case 4:
                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_AURA])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }

                        nTemp += pMonStatsTxt->wAiParam[0][2];
                    }
                    else if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 10;
                    }
                    else
                    {
                        nTemp += 4 * nAuraStatBonus + 3;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 5:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit))
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    else
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 6)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    break;

                case 7:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = 0;
                    if (!pOwner)
                    {
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                    }
                    else
                    {
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitY(pOwner);
                    }

                    nCurrentValue += 10;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue += 10;
                    }
                    break;

                case 8:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = pUnit;
                    nCurrentValue *= 2;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue *= 2;
                    }
                    break;

                case 11:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * nArg1C;
                    break;

                case 12:
                    if (sub_0044BE50_GetUnitTypeOrInvalid(pTarget) == UNIT_MONSTER)
                    {
                        D2MonStatsTxt* pTargetMonStatsTxt = sub_0055B7E0_GetMonStatsTxtFromUnit(pTarget);
                        if (!pTargetMonStatsTxt || pTargetMonStatsTxt->nDrain[pGame->nDifficulty] < 25)
                        {
                            break;
                        }
                    }

                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_AURA])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage < 75)
                    {
                        nCurrentValue += 8;
                    }

                    if (nLifePercentage < 50)
                    {
                        nCurrentValue += 12;
                    }
                    break;

                case 13:
                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 5;
                    }
                    else
                    {
                        nTemp += nAuraStatBonus;
                    }

                    if ((nLifePercentage < 50 || nArg0C > 3) && pArg10 && nArg18 < 4 && AITHINK_GetSquaredDistance(pUnit, pArg10) > 25)
                    {
                        nTemp += 20;
                        pSkillTarget = pArg10;
                    }
                    else
                    {
                        if (nDistanceToTarget < 25)
                        {
                            break;
                        }

                        if (nDistanceToTarget > 324)
                        {
                            nTemp += 10;
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;
                }

                if (nCurrentValue > shadowMasterSkills[nCounter - 1].nChance)
                {
                    shadowMasterSkills[nCounter].nSkillId = nSkillId;
                    shadowMasterSkills[nCounter].pTarget = pSkillTarget;
                    shadowMasterSkills[nCounter].nChance = nCurrentValue;
                    shadowMasterSkills[nCounter].nX = 0;
                    shadowMasterSkills[nCounter].nY = 0;
                    ++nCounter;
                }
            }
        }

        while (nCounter)
        {
            --nCounter;

            if (SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3)
            {
                D2UnitStrc* pPickTarget = shadowMasterSkills[nCounter].pTarget;
                const int nPickSkillId = shadowMasterSkills[nCounter].nSkillId;
                const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pPickTarget, 0);
                if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, nPickSkillId, bInMeleeRange, pPickTarget, shadowMasterSkills[nCounter].nX, shadowMasterSkills[nCounter].nY, pAiTickParam))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPickSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wSrvDoFunc == 19)
                    {
                        pAiControl->dwAiParam[1] = nPickSkillId;
                        pAiControl->dwAiParam[0] = 25;
                    }
                    return;
                }
            }
        }

        if (pTarget)
        {
            const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
            if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, 0, bInMeleeRange, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

// 0x005EC6A0
void __fastcall sub_005EC6A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = 0;
}

// 0x005ECBC0
int __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2)
{
    AITACTICS_SetVelocity(pUnit, a2, 0, a4);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.pTargetUnit = pTarget;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005ECC10
void __fastcall AITHINK_Fn107_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pAiControl->dwAiParam[0] == -1)
    {
        pAiControl->dwAiParam[0] = 3;
        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            const int nSkillLevel = SKILLS_GetSkillLevel(pOwner, SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pMonStatsTxt->nSkill[0]), 1);
            pAiControl->dwAiParam[0] = sub_004EFCB0_GetSummonLevel(pMonStatsTxt->nSkill[0], nSkillLevel);
        }
    }
    else if (pAiControl->dwAiParam[0] == 0)
    {
        SUNITDMG_KillMonster(pGame, pUnit, pUnit, 1);
        return;
    }

    const int nOwnerDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nOwnerDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }

    int nVel;
    if (pMonStatsTxt->nVelocity <= 0)
    {
        nVel = 100;
    }
    else
    {
        nVel = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        if (nVel >= 100)
        {
            nVel = 100;
        }
    }

    if (nOwnerDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, nVel, 0);
        return;
    }

    int nDist;
    int bFoundCombat;
    D2UnitStrc* pFound = sub_6FCF2110(pGame, pOwner, pAiTickParam->pAiControl, &nDist, &bFoundCombat);
    if (pFound)
    {
        nDist = sub_006416D0_UnitEdgeDistance(pUnit, pFound);
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int nAverageDistance = (AI_PARAM(pGame, pMonStatsTxt, 1) + AI_PARAM(pGame, pMonStatsTxt, 0)) / 2;

    if (pTarget && pAiControl->dwAiParam[1] < pGame->dwGameFrame)
    {
        const int nDifficulty = pGame->nDifficulty;
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[3][nDifficulty]
            && nTargetDistance < pMonStatsTxt->wAiParam[4][nDifficulty])
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 10 * AI_PARAM(pGame, pMonStatsTxt, 2);
                --pAiControl->dwAiParam[0];
            }
            else
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            return;
        }
    }

    int bFailed;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (nOwnerDistance < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (pAiControl->dwAiParam[2] ? sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
    {
        return;
    }
    else
    {
        pAiControl->dwAiParam[2] = pAiControl->dwAiParam[2] == 0;
        if (pAiControl->dwAiParam[2] ? sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
        {
            return;
        }

        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }

    if (bFailed)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 1, 0, 0, 0);
    }
}

// 0x005ED710
void __fastcall AITHINK_Fn108_DruidWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pUnit && pUnit->dwClassId == 420)
    {
        AITHINK_Fn108_SpiritWolf(pGame, pUnit, pAiTickParam);
        return;
    }
    AITHINK_Fn108_Fenris(pGame, pUnit, pAiTickParam);
}

static __forceinline int CLIENTS_GetUnitXInline_Totem(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline_Totem(D2UnitStrc* pUnit)
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

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005ED9E0
void __fastcall AITHINK_Fn109_Totem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCCFD40(pGame, pUnit, pAiControl, &nDistance, &bCombat, 24);
    if (bCombat && pTarget && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT) && sub_005DEFE0_Escape(pGame, pUnit, pTarget, 6, 1))
    {
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT))
    {
        pTarget = 0;
        bCombat = 0;
    }

    const int nOwnerDistance = sub_006416D0_UnitEdgeDistance(pUnit, pOwner);
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE))
    {
        if (sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pOwner), CLIENTS_GetUnitXInline_Totem(pOwner), CLIENTS_GetUnitYInline_Totem(pOwner), 0, 0))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            return;
        }
    }

    const int nOwnerAnimMode = pOwner->dwAnimMode;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE))
    {
        if (((nOwnerAnimMode == PLRMODE_WALK || nOwnerAnimMode == PLRMODE_TOWNWALK) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            || (nOwnerAnimMode == PLRMODE_RUN && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 60, 0)))
        {
            return;
        }
    }

    if (sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EDC00
void __fastcall sub_005EDC00_SetAiParams12(D2GameStrc* pGame, D2AiControlStrc* pAiControl, int nParam1, int nParam2)
{
    D2_ASSERT(pAiControl, 0x13B6);
    pAiControl->dwAiParam[1] = nParam1;
    pAiControl->dwAiParam[2] = nParam2;
}

// build: context AITHINK_Fn110_Vines
void __fastcall AITHINK_Fn110_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    int nDistance = 0;
    int bCombat = 0;
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    if (sub_006416D0_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(pGame, pMonStatsTxt, 4) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 6))
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!sub_005E45D0(pGame, pUnit, 0, pOwner, 0, pAiTickParam, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
        }
        return;
    }

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        pTarget = 0;
    }

    if (sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (STATES_CheckState(pTarget, STATE_POISON) || STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0) == 100)
        {
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, 3), 0);
            return;
        }

        if (bCombat)
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && AI_PARAM(pGame, pMonStatsTxt, 0) + pAiControl->dwAiParam[1] < pGame->dwGameFrame)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                return;
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
}

// 0x005EDF70
int __fastcall sub_005EDF70_TryRoomSteps(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 5147);

    D2DrlgCoordsStrc coords;
    DUNGEON_GetRoomCoordinates(pRoom, &coords);
    int nX = coords.nSubtileX;
    int nY = coords.nSubtileY;
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pUnit, &nDirX, &nDirY);
    nDirX = -nDirX;
    nDirY = -nDirY;
    int bResult = 0;
    const int nIndex = (!pUnit ? -1 : pUnit->dwClassId) - 19;
    for (int i = 0; !bResult && i < 3; ++i)
    {
        nX += coords.nSubtileWidth * nDirX;
        nY += coords.nSubtileHeight * nDirY;
        bResult = sub_005429B0_IsDeadMonsterAt(pGame, pRoom, nX, nY, nIndex);
    }
    return bResult;
}

// 0x005EE3C0
void __fastcall AITHINK_Fn131_Wussie(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pPortal = 0;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (ACT5Q2_FindPortal(pGame,pUnit,&pPortal))
    {
        if (pPortal && (ACT5Q2_CheckWussieCounters(pGame,pUnit) || (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit,CLIENTS_GetUnitX(pPortal),CLIENTS_GetUnitY(pPortal)) < 4))
        {
            ACT5Q2_UpdateWussieCounters(pGame,0,pUnit);
            sub_00648730(pUnit->pDynamicPath);
            sub_00540E60(pGame,pUnit,2,0);
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit),nUnitType,nUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame,pUnit);
            return;
        }
        if (pPortal)
        {
            if ((int)(SEED_RollRandomNumber_Inline(pSeed) % 100) < 70)
                AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,pPortal,7);
            else if ((int)SEED_RollLimitedRandomNumber(pSeed,100) < 10)
                AITACTICS_WalkCloseToUnit(pGame,pUnit,4);
            else
                AITACTICS_IdleInNeutralMode(pGame,pUnit,10);
            return;
        }
    }
    else
    {
        int bCloseToTarget = 0;
        D2UnitStrc* pPlayer = sub_6FCCFD70(pGame,pUnit,&bCloseToTarget);
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            if (sub_00588E10_IsMonsterNearby(pGame,pPlayer,pUnit))
            {
                sub_005888D0_SpawnRescuePortal(pGame,pPlayer,pUnit);
                if (pUnit->dwNodeIndex == 11)
                {
                    sub_6FC40280(pGame,pUnit,0,8);
                    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
                    return;
                }
            }
            else
            {
                ACT5Q2_OnWussieActivated(pGame,pPlayer,pUnit);
                if ((int)SEED_RollLimitedRandomNumber(pSeed,1000) < 100)
                {
                    D2Packet8A packet;
                    packet.header = 0x8A;
                    packet.type = 1;
                    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
                    packet.guid = nUnitGUID;
                    sub_0053DFF0(UnitGetClient(pPlayer,gszAiThink4,0x14FF),&packet);
                }
            }
        }
    }
    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
}

// 0x005EE5D0
void __fastcall sub_005EE5D0_ThinkNihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2SkillStrc* pSkill;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    ACT5Q4_OnNihlathakActivated(pGame, pUnit);
    if (STATES_CheckState(pUnit, 12))
        STATES_ToggleState(pUnit, 12, 0);
    if (!pTarget)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
        if (pSkill && sub_6FCF2E70(pUnit))
        {
            AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1537), SKILLS_GetSkillMode(pSkill));
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
    if (pSkill && bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1544), SKILLS_GetSkillMode(pSkill));
        return;
    }
    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 4) && AI_ROLL_PERCENT(pSeed) < 40)
    {
        if (sub_005DEFE0_Escape(pGame, pUnit, pTarget, 5, 1))
            return;
    }
    if (pMonStatsTxt->nSkill[2] > 0)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[2]);
        if (pSkill && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            D2UnitStrc* pSkillTarget = sub_6FD15210(pUnit, pTarget, pMonStatsTxt->nSkill[2], SKILLS_GetSkillLevel(pUnit, pSkill, 1));
            if (pSkillTarget && AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pSkillTarget, 0, 0))
                return;
        }
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && AI_ROLL_PERCENT(pSeed) < 60 && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (pMonStatsTxt->nSkill[1] > 0 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 3) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        D2NihlathakOverseerAiCallbackArgStrc arg;
        arg.nMaxDistance = 0;
        arg.nDistantMaxDistance = 625;
        arg.nMaxLifePercentage = 50;
        arg.pTarget = 0;
        arg.pDistantTarget = 0;
        arg.nCounter = 0;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);
        if (arg.pDistantTarget)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], arg.pDistantTarget, 0, 0);
            return;
        }
        if (pMonStatsTxt->nSkill[4] > 0)
        {
            const int nMonsterId = MONSTERS_ValidateMonsterId(528);
            if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
            {
                pAiTickParam->pAiControl->nMinionSpawnClassId = D2Common_11063(UNITS_GetRoom(pUnit), MONSTERS_ValidateMonsterId(453));
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, 0, 0);
                return;
            }
        }
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (AI_ROLL_PERCENT(pSeed) < 60)
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}

// 0x005EF1F0
void __fastcall AITHINK_BaalThroneSetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag, int bSet)
{
    if (bSet)
    {
        pAiTickParam->pAiControl->dwAiParam[1] |= nFlag;
    }
    else
    {
        pAiTickParam->pAiControl->dwAiParam[1] &= ~nFlag;
    }
}

// 0x005EF210
void __fastcall sub_005EF210_BaalThroneSpawnMinion(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pAiTickParam)
{
    SKILLS_AssignSkill(pUnit, SKILL_BAALMONSTERSPAWN, 1, 0, ".\\Ai\\AiThink4.cpp", 0x1700);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_BAALMONSTERSPAWN);
    D2_ASSERT(pSkill, 0x1702);
    SKILLS_SetParam1(pSkill, nSuperUnique);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }

    AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL3, SKILL_BAALMONSTERSPAWN, 0, nX, nY + 13);
    ++pAiTickParam->pAiControl->dwAiParam[0];
    pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 100;
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 2, 1);
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 1, 0);
}

// 0x005EF5E0
D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2BaalToStairsAiCallbackArgStrc* pArg = (D2BaalToStairsAiCallbackArgStrc*)pCallbackArg;

    if (pTarget && pTarget->dwUnitType == UNIT_OBJECT && pTarget->dwClassId == OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER)
    {
        return sub_006416D0_UnitEdgeDistance(pTarget, pUnit) <= pArg->nMaxDistance ? pTarget : 0;
    }

    return 0;
}

// 0x005EF620
void __fastcall AITHINK_Fn138_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2BaalToStairsAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pTarget = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_BaalToStairs, 1);
    if (pTarget)
    {
        if (sub_006416D0_UnitEdgeDistance(pUnit, pTarget) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            ACT5Q6_OpenWorldStoneChamber(pGame);
            STATES_ToggleState(pUnit, STATE_BAALTOSTAIRS_INVIS, 1);
            D2Common_10153(pUnit->pDynamicPath);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), pUnit->dwUnitType, pUnit->dwUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame, pUnit);
            return;
        }

        sub_005DE190_SetAiParam(pUnit, 1, 0, 0);
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EF710
void __fastcall AITHINK_Fn136_BaalTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int bIsTargetNeutral = 0;
    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        bIsTargetNeutral = pTarget->dwAnimMode == PLRMODE_NEUTRAL;
        break;
    case UNIT_MONSTER:
        bIsTargetNeutral = pTarget->dwAnimMode == MONMODE_NEUTRAL;
        break;
    }

    int bTaunt = 0;
    if (bIsTargetNeutral)
    {
        ++pAiTickParam->pAiControl->dwAiParam[0];
        bTaunt = pAiTickParam->pAiControl->dwAiParam[0] > AI_GetParamValue(pGame, pMonStatsTxt, 1);
    }

    if (!bIsTargetNeutral || bTaunt)
    {
        pAiTickParam->pAiControl->dwAiParam[0] = 0;
        if (bTaunt)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, SKILL_BAALTAUNT, pTarget, 0, 0);
            return;
        }
    }

    if ((nDistance <= AI_GetParamValue(pGame, pMonStatsTxt, 2) || !sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0, 0))
        && nDistance > AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
    }
}

// 0x005EF820
void __fastcall AITHINK_Fn139_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pAiTickParam->pAiControl->dwAiParam[2])
    {
        const int nDuration = AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nFrames = 25 * ((int)SEED_RollLimitedRandomNumber(pSeed, nDuration) + nDuration);
        pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + nFrames;
    }

    if (pGame->dwGameFrame > pAiTickParam->pAiControl->dwAiParam[2])
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    if (bCombat && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005EFA50
D2UnitStrc* __fastcall AITHINK_TargetCallback_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    if (!sub_6FD01910(pUnit, pTarget))
    {
        return 0;
    }

    return sub_005DC380(pUnit, pTarget) <= 25 ? pTarget : 0;
}

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F02C0
void __fastcall AITHINK_Fn006_Fallen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pUnit)
    {
        return;
    }

    const int nAnimMode = pUnit->dwAnimMode;
    if (nAnimMode == MONMODE_DEATH || nAnimMode == MONMODE_DEAD)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (; nNumRooms; ++ppRoomList, --nNumRooms)
    {
        const int* pDeadGUID = (*ppRoomList)->nLastDeadGUIDs;
        for (int i = 0; i < 4; ++i, ++pDeadGUID)
        {
            D2UnitStrc* pCorpse = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, *pDeadGUID);
            if (pCorpse && pCorpse->dwAnimMode == MONMODE_DEATH && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCorpse, nX, nY) < 15)
            {
                pAiControl->dwAiParam[0] = 1;
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                sub_005DE190_SetAiParam(pUnit, 0, 50, 0);

                if (sub_005DEFE0_Escape(pGame, pUnit, pAiTickParam->pTarget, 12, 1))
                {
                    if ((int)(AI_RollUnit(pUnit) % 20) < 1)
                    {
                        SUNIT_AttachSound(pUnit, 17, 0);
                    }

                    return;
                }

                nNumRooms = 1;
                break;
            }
        }
    }

    if (nAnimMode != MONMODE_NEUTRAL)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (!pCurrentAiCmd)
    {
        if (!bCombat && sub_6FCF2E70(pUnit))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if (nDistance < 15 && AIGENERAL_GetMinionOwner(pUnit) == pUnit && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT))
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 1;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat)
        {
            if (!pAiControl->dwAiParam[0])
            {
                if (!((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT)))
                {
                    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
                    {
                        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
                        return;
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }
            }

            pAiControl->dwAiParam[0] = 0;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_APPROACH_DISTANCE))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }
    else
    {
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005F06B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SandRaiderAiCallbackArgStrc* pArg = (D2SandRaiderAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || !pTarget || pTarget->dwUnitType != UNIT_MONSTER || STATLIST_GetUnitAlignment(pTarget) != 0 || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005F12A0
void __fastcall sub_005F12A0_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_WALK_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

// 0x005F1380
D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FallenShamanAiCallbackArgStrc* pArg = (D2FallenShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget));
    if ((nClassId != MONSTER_FALLEN1 && nClassId != MONSTER_FALLENSHAMAN1)
        || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL
        || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE)
        || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    const int nMode = pTarget ? pTarget->dwAnimMode : 0;
    if (nMode != MONMODE_DEAD || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nMaxDistance || MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION))
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    ++pArg->nCounter;
    return 0;
}

// 0x005F1440
void __fastcall AITHINK_Fn013_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->bCombat && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2FallenShamanAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE) * AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE);

    if (!MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) || MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION))
    {
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 9);
    }
    else
    {
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_FallenShaman, 1);
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
    }

    D2UnitStrc* pResurrectTarget = arg.pTarget;
    if (pResurrectTarget && arg.nCounter && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0))
    {
        AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pResurrectTarget, 0, 0);
        return;
    }

    if (pTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    D2UnitStrc* pNearTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pNearTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pNearTarget, 0, 0);
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// build: context AITHINK_Fn137_PutridDefiler
void __fastcall AITHINK_Fn137_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pTarget && pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2PutridDefilerAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pVictim = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_PutridDefiler, 1);
    if (pVictim)
    {
        if (UNITS_IsInMeleeRange(pUnit, pVictim, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_IMPREGNATE, pVictim, 0, 0);
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pVictim);
        }
        return;
    }

    if (nDistance < AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        sub_005DEFE0_Escape(pGame, pUnit, pTarget, AI_GetParamValue(pGame, pMonStatsTxt, 1), 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005F1750
void __fastcall sub_005F1750(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 14, 0);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiCmd->nCmdParam[4] == 1 && pMonStatsTxt->nSkill[0] >= 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], SUNIT_GetTargetUnit(pGame, pUnit), 0, 0);
        sub_6FCD0150(pGame, pUnit, 30);
        pAiCmd->nCmdParam[4] = 0;
        return;
    }

    const int nParam = pAiControl->dwAiParam[2];
    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    pAiControl->dwAiParam[2] = nParam;
    sub_6FCD0150(pGame, pUnit, 1);
}

// 0x005F22B0
void __fastcall sub_005F22B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
        return;
    }

    if (!bCombat && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        sub_005DE190_SetAiParam(pUnit, 0, 75, 0);
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    D2PantherAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

    D2UnitStrc* pPanther = arg.pTarget;
    if (pPanther && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, 2) * AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        sub_005DE190_SetAiParam(pUnit, 0, 75, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pPanther, 7);
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 25)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x005F2A00
D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2GreaterMummyAiCallbackArgStrc* pArg = (D2GreaterMummyAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || pUnit == pTarget || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (pArg->bRadament)
    {
        if (!MONSTERS_IsUndead(pTarget))
        {
            return 0;
        }
    }
    else
    {
        if (!(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_LUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_LUNDEAD & 7]))
        {
            return 0;
        }
    }

    if (!pArg->bNormal && MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE) || AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (pTarget->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        pArg->pReviveTarget = pTarget;
        ++pArg->nHealReviveCounter;
        return 0;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    if (STATLIST_GetMaxLifeFromUnit(pTarget) != nHitpoints && pTarget->dwAnimMode != MONMODE_DEATH)
    {
        pArg->pHealTarget = pTarget;
        ++pArg->nHealReviveCounter;
    }

    return 0;
}

// 0x005F30F0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VultureAiCallbackArgStrc* pArg = (D2VultureAiCallbackArgStrc*)pCallbackArg;
    if (pTarget && (pTarget->dwUnitType == UNIT_MONSTER || pTarget->dwUnitType == UNIT_PLAYER) && pUnit != pTarget && !MONSTERS_IsDead(pTarget))
    {
        const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistance <= pArg->nDistance)
        {
            const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
            if (nHitpoints <= STATLIST_GetMaxLifeFromUnit(pTarget) / 100 * pArg->nLifePercentage)
            {
                pArg->pTarget = pTarget;
                pArg->nDistance = nDistance;
            }
        }
    }

    return 0;
}

// 0x005F4FD0
void __fastcall sub_005F4FD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pUnit && pUnit->dwAnimMode == MONMODE_SKILL4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_Idle(pGame, pUnit, 1);
        return;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL3, 0);
        return;
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

static __forceinline int RollPercentage(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed % 100;
}

// 0x005F53E0
void __fastcall sub_005F53E0_ThinkMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* const pUnitSeed = &pUnit->pSeed;
    const int nTargetDistance = pTick->nTargetDistance;
    const int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pRecord = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2AiCmdStrc* pCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCmd)
    {
        if (pCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                sub_005DE190_SetAiParam(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        if (pCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                sub_005DE190_SetAiParam(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pTarget);
    switch (pAi->dwAiParam[0])
    {
    case 2:
        if (nTargetDistance > 12)
        {
            ++pAi->dwAiParam[1];
            if (pAi->dwAiParam[1] > 1)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
            }
            if (RollPercentage(pUnitSeed) < 20)
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        sub_005DE190_SetAiParam(pUnit, 2, 50, 0);
        if (sub_005DEFE0_Escape(pGame, pUnit, pTarget, 14, 1))
            return;
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        break;
    case 1:
        ++pAi->dwAiParam[1];
        if (pAi->dwAiParam[1] > AI_GetParam(pGame, pRecord, 2) && nLife > AI_GetParam(pGame, pRecord, 3))
        {
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = 0;
            sub_005DE190_SetAiParam(pUnit, 2, 50, 0);
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, 14, 1);
            return;
        }
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pUnitSeed, 100) < pRecord->wAiParam[0][pGame->nDifficulty])
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pRecord->wAiParam[1][pGame->nDifficulty]);
            return;
        }
        sub_005DE190_SetAiParam(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    case 0:
        if (bCombat)
        {
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[0] = 1;
            if (RollPercentage(pUnitSeed) < AI_GetParam(pGame, pRecord, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pRecord, 1));
                return;
            }
        }
        sub_005DE190_SetAiParam(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static __forceinline int UNITS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int UNITS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005F56D0
void __fastcall AITHINK_Fn033_HellMeteor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxt->nSkill[0] >= 0 && (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        const int nX = UNITS_GetUnitXInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nY = UNITS_GetUnitYInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005F7240
D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ZakarumPriestAiCallbackArgStrc* pArg = (D2ZakarumPriestAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (sub_00463900_GetValidMonsterId(sub_00463860(pTarget)))
    {
    case MONSTER_ZEALOT1:
    case MONSTER_CANTOR1:
        break;

    default:
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 60)
    {
        return 0;
    }

    if (pArg->nMaxLifePercentage <= 0)
    {
        pArg->nMaxLifePercentage = 0x7FFFFFFF;
    }

    ++pArg->nCounter;

    if (nLifePercentage < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    return 0;
}

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F72D0
void __fastcall AITHINK_Fn049_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    if (bCombat || sub_6FCF2E70(pUnit))
    {
        if (pMonStatsTxt->nSkill[2] >= 0 && nLifePercentage < 33 && pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + 4 * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);

            int nTargetX;
            int nShift = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            nTargetX = CLIENTS_GetUnitX(pTarget);
            int nTargetY = CLIENTS_GetUnitY(pTarget);
            if (bCombat)
            {
                nShift = 2;
            }

            nTargetX = ((nTargetX - nX) << nShift) + nTargetX;
            nTargetY = ((nTargetY - nY) << nShift) + nTargetY;

            if (sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY);
                return;
            }
        }

        if (bCombat && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }

    D2ZakarumPriestAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxLifePercentage = 0x7FFFFFFF;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE) * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_ZakarumPriest, 1);

    if (pMonStatsTxt->nSkill[0] >= 0 && arg.pTarget && (int)(AI_RollSeed(pSeed) % 100) < 25)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0);
        return;
    }

    if (sub_005DD290_NoMissileBarrierCollision(pUnit, pTarget))
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
                return;
            }

            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame + 20;
                return;
            }
        }
    }
    else
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT) && pMonStatsTxt->nSkill[3] >= 0
            && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < 30)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    }
}

// 0x005F7700
D2UnitStrc* __fastcall AITHINK_TargetCallback_Mephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MephistoAiCallbackArgStrc* pArg = (D2MephistoAiCallbackArgStrc*)pCallbackArg;
    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget || !UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > 1024)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (nDistance <= 225)
    {
        ++pArg->unk0x08;
    }

    if (nDistance < pArg->unk0x04)
    {
        pArg->unk0x00 = pTarget;
        pArg->unk0x04 = nDistance;
    }

    const int nLife = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0) >> 8;
    if (nLife < pArg->unk0x10)
    {
        pArg->unk0x0C = pTarget;
        pArg->unk0x10 = nLife;
    }

    if (nDistance < pArg->unk0x18 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pArg->unk0x14 = pTarget;
        pArg->unk0x18 = nDistance;
    }

    return 0;
}

// 0x005F81C0
void __fastcall AITHINK_Fn146_UberMephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

// 0x005F81D0
void __fastcall AITHINK_SpecialFn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
	D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
	const int nAiSpecialState = pAiControl->nAiSpecialState;
	D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

	if (nAiSpecialState != 10 && nAiSpecialState != 11)
	{
		const short nSkillId = pMonStatsTxt->nSkill[0];
		if (nSkillId >= 0 && pAiControl->dwAiParam[2] >= 2)
		{
			AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pAiTickParam->pTarget, 0, 0);
			pAiControl->dwAiParam[2] = 1;
			sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
			return;
		}

		AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
		AITACTICS_Idle(pGame, pUnit, 1);
		return;
	}

	AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
	AITACTICS_Idle(pGame, pUnit, 1);
}

static __forceinline int CLIENTS_GetUnitX_FrogDemon(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitY_FrogDemon(D2UnitStrc* pUnit)
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

// 0x005F8260
void __fastcall AITHINK_Fn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiControl->dwAiParam[2] == 0)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance > 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pAiTickParam->pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[2] = 1;
            sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            goto LABEL_EMERGE0;
        }

        if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX_FrogDemon(pUnit), CLIENTS_GetUnitY_FrogDemon(pUnit), 0xC01))
        {
            pAiControl->dwAiParam[2] = 2;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 7) && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
LABEL_EMERGE:
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < 20 && pAiControl->dwAiParam[1] > 64 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
        AITACTICS_Idle(pGame, pUnit, 24);
        ++pAiControl->dwAiParam[1];
        pAiControl->dwAiParam[2] = 1;
        return;

LABEL_EMERGE0:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    {
        if (!pTarget)
        {
            AITACTICS_Idle(pGame, pUnit, 32);
            return;
        }

        if (bCombat)
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 2))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 5))
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 4))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }
}

// 0x005F85C0
void __fastcall AITHINK_Fn053_Summoner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pAiControl->dwAiParam[0])
    {
        ACT2Q5_OnSummonerActivated(pGame, pUnit);
        pAiControl->dwAiParam[0] = 1;
    }

    if (nTargetDistance < 5 && AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        sub_005DEFE0_AiEscape(pGame, pUnit, pTarget, 6, 0);
    }

    int bUseColdSkill = STATLIST_UnitGetStatValue(pTarget, 39, 0) >= STATLIST_UnitGetStatValue(pTarget, 43, 0);

    const int nX = CLIENTS_GetUnitXInline_005F02C0(pTarget);
    const int nY = CLIENTS_GetUnitYInline_005F02C0(pTarget);

    if (AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_CAST_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }

        int nDistance;
        D2UnitStrc* pMissileTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

        if (AI_RollPercentage_005F02C0(pUnit) > AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT))
        {
            bUseColdSkill = (bUseColdSkill == 0);
        }

        if (bUseColdSkill)
        {
            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
            {
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMissileTarget, nX, nY);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2])
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_FIREWALL_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pMissileTarget, nX, nY);
            return;
        }

        if (!bUseColdSkill && pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
        {
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[4] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
}

// 0x005F9950
void __fastcall D2GAME_AI_SpecialState04_6FCDC170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005F99A0
D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FetishShamanAiCallbackArgStrc* pArg = (D2FetishShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    if (!pArg->nHealCapability && AIGENERAL_GetMinionOwner(pTarget) != pUnit)
    {
        return 0;
    }

    const int nClassId = sub_00463900_GetValidMonsterId(sub_00463860(pTarget));
    if ((nClassId == MONSTER_FETISH1 || nClassId == MONSTER_FETISHBLOW1 && pArg->nHealCapability != 1)
        && STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL
        && (pArg->nHealCapability >= 3 || !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION)))
    {
        const int nDistanceSquared = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistanceSquared <= pArg->nMaxSearchRangeSquared)
        {
            if (pTarget->dwAnimMode != MONMODE_DEAD)
            {
                ++pArg->nAliveTargets;

                if (nDistanceSquared < pArg->nSquaredDistanceToClosestAliveTarget)
                {
                    pArg->pClosestAliveTarget = pTarget;
                    pArg->nSquaredDistanceToClosestAliveTarget = nDistanceSquared;
                }
            }
            else
            {
                if (nDistanceSquared < pArg->nSquaredDistanceToClosestDeadTarget)
                {
                    pArg->pClosestDeadTarget = pTarget;
                    pArg->nSquaredDistanceToClosestDeadTarget = nDistanceSquared;
                }
            }
        }
    }

    return 0;
}

// 0x005F9CF0
void __fastcall AITHINK_Fn066_SandMaggotQueen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25 * AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[2] = 0;
        return;
    }

    if (!pAiControl->dwAiParam[1] && pAiControl->dwAiParam[0] < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 8);
        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 1;
        return;
    }

    if (pAiControl->dwAiParam[1])
    {
        int nSpawnMode;
        int nMonsterId;
        int nX;
        int nY;
        MONSTERS_GetMinionSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nSpawnMode, 0, AIGENERAL_GetMinionSpawnClassId);
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitStrc* pSandMaggot = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nSpawnMode, 2, 66);
            if (pSandMaggot)
            {
                pSandMaggot->dwFlags |= UNITFLAG_NOXP;
                ++pAiControl->dwAiParam[0];
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 0;
        pAiControl->dwAiParam[2] = 1;
    }
}

// 0x005FAE40
D2UnitStrc* __fastcall AITHINK_TargetCallback_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2OblivionKnightAiCallbackArgStrc* pArg = (D2OblivionKnightAiCallbackArgStrc*)pCallbackArg;

    if (pTarget == pUnit)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)) != MONSTER_DOOMKNIGHT1)
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->unk0x08 || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (nDistance < pArg->unk0x0C)
    {
        pArg->unk0x00 = pTarget;
        pArg->unk0x0C = nDistance;
    }

    if (nDistance < pArg->unk0x10 && UNITS_GetCurrentLifePercentage(pTarget) < 40)
    {
        pArg->unk0x04 = pTarget;
        pArg->unk0x10 = nDistance;
    }

    return 0;
}

static int UNITS_GetAnimMode_FB410(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005FB410
void __fastcall sub_005FB410_AiThinkSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nMode = UNITS_GetAnimMode_FB410(pUnit);

    if (pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;
        pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, 0);
    }

    if (nMode == 1)
    {
        if (nDistance > 5)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 10, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 10)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 11, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 11 && pAiControl->dwAiParam[1] > 0)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;

            int nMonsterId;
            int nX;
            int nY;
            int nAnimMode;
            MONSTERS_GetMinionSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nAnimMode, 0, 0);

            D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
            if (pRoom)
            {
                D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 2, 0x42);
                if (pMonster)
                {
                    --pAiControl->dwAiParam[1];
                    pMonster->dwFlags |= 0x4020000;

                    if (pUnit && pUnit->dwClassId == 0x2C7)
                    {
                        STATES_ToggleState(pMonster, 0xB8, 1);
                        UNITS_SetOverlay(pMonster, 0xCA, 0);
                    }
                }
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
}

// 0x005FB900
void __fastcall sub_005FB900_ThinkLimitedCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}

// 0x005FB9B0
void __fastcall sub_005FB9B0_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}

// 0x005FC830
void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc* pUnit, void* ppUnitArg, void* pCounterArg)
{
    D2UnitStrc** ppUnit = (D2UnitStrc**)ppUnitArg;
    int* pCounter = (int*)pCounterArg;

    if (pUnit != *ppUnit && pUnit && pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
    {
        ++*pCounter;
    }
}

// build: context ?SKILLS_GetSkillsTxtRecord@@YAPAUD2SkillsTxt@@H@Z
// build: context ?SKILLS_GetMissilesTxtRecord@@YAPAUD2MissilesTxt@@H@Z
// build: context ?GetAuraStateStatList@@YAPAUD2StatListStrc@@PAUD2UnitStrc@@PAUD2SkillsTxt@@@Z
// build: context ?AI_ClampChance@@YAHH@Z


#include "gen/data/Source/D2Game/Ai/AiThink4.inc"
