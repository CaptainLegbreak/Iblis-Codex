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
struct D2UnitStrc;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);
typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

enum D2C_Z09SkillConstants
{
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAG_TARGETFLAGS = 0x0E,
    STATE_INFERNO = 0x0C,
    STATE_ATTACHED = 0x8F,
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_ENDANIM = 1,
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_MOUNTING_UNIT = 0x10,
    MONSTER_IMP1 = 0x1EC,
    MONSTER_BARRICADETOWER = 0x1B3,
    MONSTER_SIEGEBEAST1 = 0x1B9,
    MONSTER_SANDLEAPER1 = 0x4E,
    STAT_MAGICMINDAM = 0x34,
    STAT_MAGICMAXDAM = 0x35,
    STAT_MODIFIERLIST_SKILL = 0x15E,
    STAT_MODIFIERLIST_LEVEL = 0x15F,
    PATHTYPE_BLESSEDHAMMER = 0x0E,
    PATHTYPE_KNOCKBACK_SERVER = 0x08,
    PATHTYPE_LEAP = 0x09,
    PATHTYPE_MON_OTHER_2 = 0x65,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                       // 0x005D3CF0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);       // 0x005D3DA0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400
int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nCalc, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId);                                             // 0x00463900
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);        // 0x006439F0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00553C70
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970
int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);                          // 0x006461D0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
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

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// build: context SKILLS_CreateSubMissilesInline
static __forceinline int SKILLS_CreateSubMissilesInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7)
{
    if (a7)
    {
        sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetUnitXPositionInline(pUnit);
    missileParams.nY = UNITS_GetUnitYPositionInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005C7160
int __fastcall SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return SKILLS_CreateSubMissilesInline(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 1);
}

// 0x005C9300
int __fastcall SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nMissileCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < nMissileCount; ++i)
    {
        missileParams.nInitArg = i;
        if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY) && missileParams.nTargetX && missileParams.nTargetY)
        {
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }

    return 1;
}

// 0x005C9B50
int __fastcall SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    sub_6FD14170(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

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

// 0x005CBF90
int __fastcall SKILLS_SrvDo092_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0)
    {
        if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        {
            nMissileId = D2Common_11050(pUnit, 1);
        }

        if (nMissileId < 0)
        {
            return 0;
        }
    }

    if (nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
        return 1;
    }

    return 0;
}

// 0x005D0040
int __fastcall SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    int nTargetX;
    int nTargetY;
    D2UnitStrc* pMissile = 0;
    if (nMissileId > 0 && D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
        }

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = nMissileId;

        pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (!pMissile)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetType(pPath, PATHTYPE_BLESSEDHAMMER);
    D2Common_10142(pPath, pMissile, 0);

    const int nBonus = SKILLS_GetConcentrationDamageBonus(pUnit, nSkillId);
    if (nBonus)
    {
        const int nPercentage = nBonus + 100;
        const int nMinDamage = DATATBLS_ApplyRatio(STATLIST_GetUnitBaseStat(pMissile, STAT_MAGICMINDAM, 0), nPercentage, 100);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMINDAM, nMinDamage, 0);
        const int nMaxDamage = DATATBLS_ApplyRatio(STATLIST_GetUnitBaseStat(pMissile, STAT_MAGICMAXDAM, 0), nPercentage, 100);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMAXDAM, nMaxDamage, 0);
    }

    return 1;
}

// 0x005D1170
int __fastcall SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);

    int nTargetX;
    int nTargetY;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nTargetX = nTargetX - CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = nTargetY - CLIENTS_GetUnitY(pUnit);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -missileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, missileParams.nTargetX);
    return 1;
}

// 0x005D18E0
void __fastcall sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pTarget)
    {
        return;
    }

    const int nBaseId = sub_00463860(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nTargetBaseId = sub_00463860(pTarget);
    if (nTargetBaseId < 0 || nTargetBaseId >= nMonStatsCount)
    {
        nTargetBaseId = -1;
    }

    switch (nTargetBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 1);
        UNITS_StoreOwner(pUnit, pTarget);
        UNITS_StoreOwner(pTarget, pUnit);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        sub_6FC35570(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId, nSkillLevel);
        pUnit->dwFlags &= ~UNITFLAG_TARGETFLAGS;
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), AISPECIALSTATE_MOUNTING_UNIT);
        break;
    }
}

// 0x005D19D0
void __fastcall sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pOwner)
    {
        return;
    }

    const int nBaseId = sub_00463860(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nOwnerBaseId = sub_00463860(pOwner);
    if (nOwnerBaseId < 0 || nOwnerBaseId >= nMonStatsCount)
    {
        nOwnerBaseId = -1;
    }

    switch (nOwnerBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 0);
        UNITS_StoreOwner(pUnit, 0);
        UNITS_StoreOwner(pOwner, 0);
        if (UNITS_GetCurrentLifePercentage(pUnit) < 10)
        {
            SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        }
        else
        {
            pUnit->dwFlags |= UNITFLAG_TARGETFLAGS;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), AISPECIALSTATE_NONE);
        }
        break;
    }
}

// 0x005D4DB0
int __fastcall SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    sub_6FD14170(pGame, pUnit, pTarget, nMissileId, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

// 0x005D5010
int __fastcall SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    return 1;
}

// 0x005D5D70
int __fastcall SKILLS_SrvDo043_ShockField(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0)
    {
        return 0;
    }

    const int nSubMissiles = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (nSubMissiles <= 0)
    {
        return 0;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    return SKILLS_CreateMissilesAroundTarget(pGame, pUnit, pUnit, nMissileId, nSubMissiles, nAuraRange, nSkillId, nSkillLevel);
}

// 0x005D68A0
int __fastcall SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0)
    {
        return 0;
    }

    const int nDuration = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel) - 1;
    if (nDuration <= 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFBF;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nNextFrame = SKILLS_GetParam1(pSkill);
    int bMissileCreated = 0;
    if (nNextFrame < pGame->dwGameFrame)
    {
        D2MissileStrc missileParams = {};
        missileParams.nMissile = nMissileId;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nTargetX = nTargetX;
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetY = nTargetY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);

        bMissileCreated = 1;

        SKILLS_SetParam1(pSkill, nDuration + pGame->dwGameFrame);
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        sub_6FCBD120(pGame, pUnit, 1);
    }

    return bMissileCreated;
}

// 0x005D7A00
int __fastcall SKILLS_SrvSt28_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId) || SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId) <= 0 || SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) <= 0)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    sub_6FD11C90(pUnit, pSkillsTxtRecord->nAuraState, 0);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

// 0x005D83E0
int __fastcall SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    sub_6FD14170(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, 0);
    SKILLS_ApplyWarcryStats(pGame, pUnit, pUnit, nSkillId, nSkillLevel);
    return 1;
}

// 0x005DB850
int __fastcall SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

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

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    const int nMissileCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    const int nTargetX = UNITS_GetUnitXPositionInline(pTarget);
    const int nTargetY = UNITS_GetUnitYPositionInline(pTarget);
    const int nDestX = 2 * nTargetX - UNITS_GetUnitXPositionInline(pUnit);
    const int nDestY = 2 * nTargetY - UNITS_GetUnitYPositionInline(pUnit);

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nX = nTargetX;
    missileParams.nY = nTargetY;
    missileParams.nTargetX = nDestX;
    missileParams.nTargetY = nDestY;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < nMissileCount; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}
