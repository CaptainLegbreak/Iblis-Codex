#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Skills.h"

struct D2SkillsTxt;
struct D2SkillListStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

// 0x006435C0
int __cdecl sub_006435C0_GetPassiveSkillCount()
{
    return sgptDataTables->nPassiveSkills;
}

// 0x006435D0
short __fastcall sub_006435D0_GetPassiveSkillId(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nPassiveSkills)
        return sgptDataTables->pPassiveSkills[nIndex];
    return -1;
}

// 0x00643610
void __stdcall sub_00643610_Nop(int nUnused)
{
}

// 0x006437E0
static __forceinline D2SkillStrc* sub_006437E0_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
        return 0;
    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
        return 0;
    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            break;
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}

D2SkillStrc* __stdcall sub_M113_Emit_006437E0(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    return sub_006437E0_GetSkillById(pUnit, nSkillId, nOwnerGUID);
}

// 0x00643600
int __cdecl sub_00643600_ReturnZero() {
#ifdef MOVED_TEST
 return 4;
#else
 return 0;
#endif
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline void* UNITS_GetMemoryPool(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pMemoryPool;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// @ref 0x00643810
static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    D2SkillStrc* pHighestLevelSkill = 0;
    for (; pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && !pSkill->bExcludeFromHighestLevelLookup && (!pHighestLevelSkill
            || pSkill->nOwnerGUID == -1 || pHighestLevelSkill->nOwnerGUID != -1 && pSkill->nSkillLevel > pHighestLevelSkill->nSkillLevel))
        {
            pHighestLevelSkill = pSkill;
        }
    }

    return pHighestLevelSkill;
}

// 0x00643620
static D2StatListStrc* __stdcall sub_00643620(D2UnitStrc* pUnit, int nState, int nSkillLevel)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);

    if (nSkillLevel)
    {
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(UNITS_GetMemoryPool(pUnit), 0, 0, sub_0044BE50(pUnit), UNITS_GetUnitId(pUnit));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        return pStatList;
    }

    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 0;
}

// @ref 0x00646D60
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    short nPassiveState = pSkillsTxtRecord->nPassiveState;
    if (nPassiveState <= 0 || nPassiveState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
    if (!pSkill)
    {
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nPassiveState);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nPassiveState);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    D2StatListStrc* pStatList = sub_00643620(pUnit, pSkillsTxtRecord->nPassiveState, nSkillLevel);
    if (!pStatList || STATLIST_GetStatValue(pStatList, 351, 0) == nSkillLevel)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->nPassiveStat[i] < 0 || pSkillsTxtRecord->nPassiveStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            break;
        }

        int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nPassiveIType <= 0)
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, 0);
        }
        else
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, pSkillsTxtRecord->nPassiveIType);
        }
    }

    STATLIST_SetStat(pStatList, 350, nSkillId, 0);
    STATLIST_SetStat(pStatList, 351, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nPassiveState, 1);
}

// 0x00643690
int __stdcall SKILLS_GetPassiveState(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nPassiveState <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->nPassiveState;
}
