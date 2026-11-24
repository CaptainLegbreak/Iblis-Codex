#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007419E0
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2UnkCallRecordStrc;

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

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit); // 0x0056DE40
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    EVENTTYPE_ENDANIM = 1,
    STATLIST_FLAG_8 = 8,
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00554DE0
int __fastcall SKILLS_ApplyAuraToSelf(void* pArg1, void* pArg2, int (__fastcall* pfnCallback)(D2UnkCallRecordStrc*), int nArg4); // 0x0056B740
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680
int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450
D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740
D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210
D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0056E620
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
int __fastcall MONSTERSPAWN_SpawnBonePrison(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0
void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit); // 0x00547E90
void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int a2); // 0x005544B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2); // 0x005FD7B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80
void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0
void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0
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
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY); // 0x0063E7E0
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
int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath); // 0x006505C0
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D0D70
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender); // 0x005C96A0

struct D2MonStatsTxt;

struct D2MonStats2Txt;

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x00553C70

static void sub_005C8C10_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C8C10

inline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

// 0x005C9220
int __fastcall SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pTargetRoom)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

// 0x005C9420
void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillSor.cpp", 425);
        SKILLS_RefreshPassivesAndPetLimits(pUnit);
    }
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

inline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
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

// 0x005C9800
int __fastcall SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (!pDifficultyLevelsTxtRecord)
    {
        return 0;
    }

    D2StaticFieldCallbackArgStrc staticField;
    staticField.nMinDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    staticField.nDamagePct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    staticField.nStaticFieldMin = 0;
    if (pGame->bExpansion)
    {
        staticField.nStaticFieldMin = pDifficultyLevelsTxtRecord->dwStaticFieldMin;
    }

    staticField.nElementalLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    staticField.nElementalType = pSkillsTxtRecord->nEType;

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_StaticField, &staticField, 0, gszSkillSorSourceFile, 627);
    return 1;
}

#define STAT_MODIFIERLIST_SKILL 350

#define STAT_MODIFIERLIST_LEVEL 351

// 0x005C9D90
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit->pDynamicPath || !PATH_HasEnteredNewSubtile(pUnit->pDynamicPath))
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLAZE);
    if (!pStatList)
    {
        return;
    }

    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    if (nSkillId <= 0)
    {
        return;
    }

    D2DataTablesStrc* pDataTables = sgptDataTables;
    if (nSkillId >= pDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= pDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// 0x005C9EA0
int __fastcall SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nX = 0;
    int nY = 0;
    if (pTarget)
    {
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
        nX = nTargetX;
    }
    else
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    }

    if (!nX || !nY)
    {
        return 0;
    }

    D2ActiveRoomStrc* const tArg1 = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(tArg1, nX, nY);
    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    const int nDiffX = CLIENTS_GetUnitX(pUnit) - nX;
    const int nDiffY = CLIENTS_GetUnitY(pUnit) - nY;

    missileParams.nTargetX = nX - nDiffY;
    missileParams.nTargetY = nY + nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    missileParams.nTargetX = nX + nDiffY;
    missileParams.nTargetY = nY - nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    const int nMissileB = pSkillsTxtRecord->wSrvMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        missileParams.nTargetX = 0;
        missileParams.nTargetY = 0;
        missileParams.nMissile = nMissileB;
        missileParams.dwFlags = 1;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005CA030
int __fastcall SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && !SUNIT_AreUnitsAligned(pGame, pUnit, pTarget))
    {
        pTarget = pUnit;
    }

    if (!pTarget)
    {
        pTarget = pUnit;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
            }
        }
    }

    STATES_ToggleGfxStateFlag(pTarget, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

// 0x005CA1B0
int __fastcall SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nParam);
    return 1;
}

// 0x005CA260
int __fastcall SKILLS_SrvDo151_CreateMissileAtTargetOffset(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nDiffX = 0;
    int nDiffY = 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        nDiffX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        nDiffY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, nDiffX, nDiffY, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nParam);
    return 1;
}

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

enum D2C_TeleportConstants
{
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

// 0x005CA360
int __fastcall SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (pLevelsTxtRecord && pLevelsTxtRecord->nTeleport != 0 && (pLevelsTxtRecord->nTeleport != 2 || !UNITS_TestCollisionByCoordinates(pUnit, nTargetX, nTargetY, COLLIDE_MASK_PLAYER_FLYING)))
    {
        return SUNIT_TeleportUnit(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
    }

    return 0;
}

#define UNIT_FLAG 0x40

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

// 0x005CA3E0
int __fastcall SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    if (!SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
        return 0;
    return D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0) != 0;
}

struct D2EnergyShieldDataStrc;

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

extern "C" int __fastcall sub_005C8BC0_GetSkillsTxtParam7(int nSkillId); // 0x005C8BC0

D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

extern "C" int __fastcall sub_005C8BC0_GetSkillsTxtParam7(int nSkillId); // 0x005C8BC0

struct D2EnergyShieldDataStrc
{
    int nDamageOffset;
    int bPlayerOnly;
};

extern const D2EnergyShieldDataStrc gaEnergyShieldData[8]; // 0x006E30E0

// 0x005CA470
static D2UnitStrc* __stdcall SKILLS_CreateThunderStormBolt(D2GameStrc* pGame, int nMissileId, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit && pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
    }
    return 0;
}

// 0x005CA4D0
int __fastcall SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState) && !SKILLS_GetParam2(pSkill))
    {
        const int nParam1 = SKILLS_GetParam1(pSkill);
        const int nRange = sub_005C8BC0_GetSkillsTxtParam7(nSkillId);
        D2UnitStrc* pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, nParam1, 0);
        if (pTarget)
        {
            D2UnitStrc* pMissile = SKILLS_CreateThunderStormBolt(pGame, nMissileId, nSkillId, nSkillLevel, pUnit, pTarget);
            if (pMissile)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 1);
                SUNIT_RemoveUnit(pGame, pMissile);
                SUNITMSG_QueueSkillEvent(pUnit, pTarget, nSkillId, nSkillLevel, 0, 0, 0);
            }

            SKILLS_SetParam1(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
        else
        {
            SKILLS_SetParam1(pSkill, -1);
        }
    }
    else
    {
        D2CurseStrc curse = {};
        curse.pUnit = pUnit;
        curse.pTarget = pUnit;
        curse.nSkill = nSkillId;
        curse.nSkillLevel = nSkillLevel;
        curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        curse.nStat = -1;
        curse.nStatValue = 0;
        curse.nState = pSkillsTxtRecord->nAuraState;

        D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, 350, nSkillId, 0);
            STATLIST_SetStatIfListIsValid(pStatList, 351, nSkillLevel, 0);
        }
    }

    SKILLS_SetParam2(pSkill, 0);
    return 1;
}

// 0x005CA6C0
int __fastcall SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    if (!pDamage)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || !STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nMultiplier = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nMultiplier <= 0)
    {
        return 0;
    }

    int nMana = STATLIST_UnitGetStatValue(pAttacker, STAT_MANA, 0);
    int nDivisor = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nDivisor <= 0)
    {
        nDivisor = 1;
    }

    int bIsPlayer = 1;
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || MONSTERS_GetHirelingTypeId(pUnit)))
    {
        bIsPlayer = 0;
    }

    int nAbsorbedDamage = 0;
    for (int i = 0; i < 8; ++i)
    {
        const D2EnergyShieldDataStrc* pEnergyShieldData = &gaEnergyShieldData[i];
        if (!pEnergyShieldData->bPlayerOnly || bIsPlayer)
        {
            int* pDamageValue = (int*)((char*)pDamage + pEnergyShieldData->nDamageOffset);
            const int nDamage = *pDamageValue;
            if (nDamage > 0)
            {
                int nAbsorb = DATATBLS_ApplyRatio(nDamage, nMultiplier, 100);
                const int nMax = DATATBLS_ApplyRatio(nMana, 16, nDivisor);
                if (nAbsorb >= nMax)
                {
                    nAbsorb = nMax;
                }

                nAbsorbedDamage += nAbsorb;
                *pDamageValue = nDamage - nAbsorb;
                nMana -= DATATBLS_ApplyRatio(nAbsorb, nDivisor, 16);
                nMana = nMana > 0 ? nMana : 0;
            }
        }
    }

    nMana = nMana > 0 ? nMana : 0;

    STATLIST_SetUnitStat(pAttacker, STAT_MANA, nMana, 0);

    if (pUnit && nAbsorbedDamage > 0 && pSkillsTxtRecord->wPrgOverlay >= 0 && pSkillsTxtRecord->wPrgOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pAttacker, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        const int nOffset = INVENTORY_GetEightWayDirection(nDirection);
        UNITS_SetOverlay(pAttacker, pSkillsTxtRecord->wPrgOverlay + nOffset, 0);
    }

    if (nMana <= 0)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pAttacker, pStatList);
            STATLIST_FreeStatList(pStatList);
            return 1;
        }

        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
    }

    return 1;
}

// 0x005CAC50
int __fastcall SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDamage && pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x20;
    damage.dwFrzLen = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);

    if (pSkillsTxtRecord->wCltOverlayA >= 0 && pSkillsTxtRecord->wCltOverlayA < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wCltOverlayA, 0);
    }

    return 1;
}

// 0x005CAD40
int __fastcall SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollElementalDamage_6FD14DD0(pAttacker, &damage, nSkillId, nLevel);
    damage.nHitClassActiveSet = 1;
    damage.dwHitClass |= 0xD;
    damage.wResultFlags = 0x4021;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);

    if (pSkillsTxtRecord->wCltOverlayA >= 0 && pSkillsTxtRecord->wCltOverlayA < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wCltOverlayA, 0);
    }

    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillSor.inc"
