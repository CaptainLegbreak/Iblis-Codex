#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

enum D2C_J10SkillPalConstants
{
    STAT_HITPOINTS = 6,
    STAT_MANA = 8,
    STATE_REDEEMED = 0x63,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax);                                    // 0x0045C390
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D0C40
int __fastcall SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pCorpse || !sub_006456D0_CanUnitCorpseBeSelected(pCorpse))
    {
        return 0;
    }

    if (!bSkipChanceRoll)
    {
        const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) >= nChance)
        {
            return 0;
        }
    }

    {
        const int nLifeBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        int nNewHp = nLifeBonus + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        if (nMaxLife < nNewHp)
        {
            nNewHp = nMaxLife;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

        const int nManaBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel) << 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
        int nNewMana = nManaBonus + STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
        if (nMaxMana < nNewMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

        STATES_ToggleState(pCorpse, STATE_REDEEMED, 1);
        pCorpse->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_CANBEATTACKED);
        return 1;
    }
}
