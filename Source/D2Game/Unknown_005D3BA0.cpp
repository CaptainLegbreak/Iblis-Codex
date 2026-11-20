#include "D2Game.h"
#include "D2DataTbls.h"

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[8];
    int dwColdLen;
    int dwFrzLen;
};

struct D2SkillsTxt
{
    char unk0x000[0x44];
    unsigned char nPrgDamage;
    char unk0x045[0xF];
    short wAuraStat[6];
    char unk0x060[0xD8];
    unsigned int dwCalc[4];
    char unk0x148[0x94];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3790
void __stdcall sub_005D3880_ProgressiveElemental(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3880

// build: context SKILLS_GetSkillsTxtRecord
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context SKILLS_GetProgressiveState
inline int SKILLS_GetProgressiveState(int nIndex)
{
    return sgptDataTables->pProgressiveStates[nIndex];
}

static __declspec(noinline) void __stdcall sub_6FCF5BC0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage);

// 0x005D3970
static void __stdcall sub_6FCF5BC0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nLevel > nSkillLevel)
    {
        nSkillLevel = nLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType == 4 && nValue == 3)
    {
        const int nDivisor = sub_004E6C70(nSkillId);
        if (nDivisor)
        {
            pDamage->dwFrzLen += pDamage->dwColdLen / nDivisor;
        }
    }

    pDamage->wResultFlags |= 0x4000;

    int nPercentage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercentage > 0)
    {
        if (nPercentage >= 100)
        {
            nPercentage = 100;
        }

        const int nBaseDamage = pDamage->dwPhysDamage;
        int nDamage = DATATBLS_ApplyRatio(nBaseDamage, nPercentage, 100);
        if (nDamage >= nBaseDamage)
        {
            nDamage = nBaseDamage;
        }

        pDamage->dwPhysDamage = nBaseDamage - nDamage;
        sub_0056C8E0(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, 0, 0, 0);
    }
}

// 0x005D3BA0
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {

        if (STATES_CheckState(pUnit, (*(D2DataTablesStrc* volatile*)&sgptDataTables)->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, SKILLS_GetProgressiveState(i));
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 2:
                            sub_005D3790_ProgressiveLeech(pUnit, pStatList, pDamage);
                            break;

                        case 3:
                            sub_005D3880_ProgressiveElemental(pUnit, pStatList, pDamage);
                            break;

                        case 4:
                            sub_6FCF5BC0(pUnit, pStatList, pDamage);
                            break;
                        }
                    }
                }
            }
        }
    }
}
