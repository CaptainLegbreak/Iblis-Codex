#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_TYPES 6
#define MONMODE_SEQUENCE 14
#define COLLIDE_MASK_PLAYER_PATH 0x1C09
union D2SeedStrc;
struct D2SkillsTxt;
struct D2ModeChangeStrc;

enum D2C_J10SkillMonstConstants
{
    STAT_HITPOINTS = 6,
    UNITFLAG_SKSRVDOFUNC = 0x00000040,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2); // 0x005FD7B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005CC840
int __fastcall SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nMaxRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nMax = D2_MIN(D2_MAX(nMaxRaw, 0), 100);

    const int nMinRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMin = D2_MIN(D2_MAX(nMinRaw, 0), nMax);

    const int nPercentage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin) + nMin;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget);
    int nNewHp = DATATBLS_ApplyRatio(nMaxHp, nPercentage, 100) + STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    nNewHp = D2_MIN(D2_MAX(nNewHp, 1), nMaxHp);
    STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
    return 1;
}

// 0x005CCB10
int __fastcall SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!MONSTERS_IsDead(pTarget) || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    const int nUnitType = pTarget->dwUnitType;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pTarget);
    if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, nCollisionPattern, nUnitType != UNIT_PLAYER ? COLLIDE_MASK_MONSTER_PATH : COLLIDE_MASK_PLAYER_PATH))
    {
        return 0;
    }

    sub_00648B90_SetPathTarget(pUnit->pDynamicPath, pTarget);
    SKILLS_ResurrectUnit(pGame, pTarget);

    const int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_TYPES;
    if (nTargetType == UNIT_MONSTER)
    {
        const int nMode = MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pTarget, nMode, &tModeChange);
        MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2GAME_ModeChange_6FC65220(pGame, &tModeChange, nMode != MONMODE_SEQUENCE);
    }

    if (pSkillsTxtRecord->wSrvOverlay >= 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}
