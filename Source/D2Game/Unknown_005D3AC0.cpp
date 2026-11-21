#include "D2StatIds.h"
#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"




extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline int SKILLS_GetProgressiveState(int nIndex)
{
    return sgptDataTables->pProgressiveStates[nIndex];
}

// 0x005D3680
static void __stdcall sub_005D3680_ApplyProgressiveDamage(D2StatListStrc* pStatList, D2DamageStrc* pDamage, D2UnitStrc* pUnit)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    const int nMaxLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nMaxLevel > nSkillLevel)
    {
        nSkillLevel = nMaxLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    nValue *= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    pDamage->dwEnDmgPct += nValue;

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(SUNIT_GetGameFromUnit(pUnit), pUnit);
    if (pTarget && pSkillsTxtRecord->wTgtOverlay > 0 && pSkillsTxtRecord->wTgtOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wTgtOverlay, 0);
    }
}

// volatile only reproduces the original reloading the table pointer at each access in this loop
#define VOLATILE_DATATABLES (*(D2DataTablesStrc* volatile*)&sgptDataTables)

// 0x005D3AC0
void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < VOLATILE_DATATABLES->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, VOLATILE_DATATABLES->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, VOLATILE_DATATABLES->pProgressiveStates[i]);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < VOLATILE_DATATABLES->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 1:
                            sub_005D3680_ApplyProgressiveDamage(pStatList, pDamage, pUnit);
                            break;
                        }
                    }
                }
            }
        }
    }
}
