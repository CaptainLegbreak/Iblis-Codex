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

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x40];
    int dwStaticFieldMin;
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
int __fastcall sub_0056E620_GetValidMonsterId(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0056E620
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
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

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D0D70
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005CC960
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);   // 0x005C96A0

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

// 0x005D1570
int __fastcall SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    sub_6FD155E0(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_RollSuckBloodDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel, &damage);
        const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nPercent, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
    }

    return 1;
}

// 0x005D1AB0
int __fastcall SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pOwner)
    {
        int nTargetX;
        int nTargetY;
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY);
        sub_6FCBDFE0(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
        sub_6FD01010(pGame, pUnit, pOwner, nSkillId, nSkillLevel);
        return 1;
    }

    if (!pTarget)
    {
        return SKILLS_SrvDo098_MonTeleport(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (SUNIT_GetOwner(pGame, pTarget) || SUNIT_IsDead(pTarget) || !sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 1, 0))
    {
        return 0;
    }

    sub_6FD00EC0(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_005D1570.inc"
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
