#include "D2Common.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillsTxt;
struct D2SkillListStrc;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[12 - 2];
    char nCharClass;
    char unk0x0D[476 - 12 - 1];
    unsigned char nEType;
    char unk0x1DD[572 - 476 - 1];
};

struct D2SkillDescTxt
{
    char unk0x00[2];
    char nSkillPage;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[40 - 4 - 4];
    int nSkillLevel;
    int nLevelBonus;
    char unk0x30[52 - 44 - 4];
    int nOwnerGUID;
    char unk0x38[60 - 52 - 4];
    int bExcludeFromHighestLevelLookup;
};

struct D2SkillListStrc
{
    char unk0x00[4];
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[168 - 4 - 4];
    D2SkillListStrc* pSkills;
};

struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit); // 0x00644150
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00644180
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// @ref 0x00643810
// 0x00643810
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

// @ref 0x00644180
// build: context SKILLS_GetBonusSkillLevel
static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill || !pSkill->pSkillsTxt)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;

    int nSkillId = pSkillsTxtRecord->nSkillId;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    int nSkillLevel = pSkill->nLevelBonus;
    nSkillLevel += SKILLS_GetShrineSkillLevelBonus(pUnit);
    nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 127, 0);

    if (pUnit && pUnit->dwUnitType == 0)
    {
        if (pSkillsTxtRecord->nCharClass == pUnit->dwClassId)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 83, pUnit->dwClassId);

            D2SkillDescTxt* pSkillDescTxtRecord = sub_004A89D0(nSkillId);
            if (pSkillDescTxtRecord->nSkillPage)
            {
                nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 188, pSkillDescTxtRecord->nSkillPage + 8 * pUnit->dwClassId - 1);
            }

            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus > 3)
            {
                nBonus = 3;
            }
            nSkillLevel += nBonus;
        }
        else
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
    }
    else
    {
        if (pSkill->nSkillLevel <= 0)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
        else
        {
            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus)
            {
                if (nBonus > 3)
                {
                    nBonus = 3;
                }
                nSkillLevel += nBonus;
            }
        }
    }

    if (pSkillsTxtRecord->nEType > 0)
    {
        nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 126, pSkillsTxtRecord->nEType);
    }

    return nSkillLevel + STATLIST_UnitGetStatValue(pUnit, 107, nSkillId);
}

// 0x006442A0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus)
{
    int nSkillLevel = 0;
    int nMaxLevel = 0;

    if (pUnit && pSkill)
    {
        nSkillLevel = pSkill->nSkillLevel;
        if (bBonus && pSkill->nOwnerGUID == -1)
        {
            nSkillLevel += SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }

        nSkillLevel = D2_MAX(nSkillLevel, 0);
        return D2_MIN(nSkillLevel, DATATBLS_GetMaxLevel(0));
    }

    return 0;
}

// 0x00644300
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (pSkill && pSkill->nOwnerGUID == -1)
        {
            return SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }
    }

    return 0;
}

// 0x00644AA0
int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit)
    {
        return SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId), 1);
    }

    return 0;
}

// 0x00645F00
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue)
{
    int nWeaponClass = 0;
    int nValue = 0;

    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 0)
    {
        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 27;
        }

        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 41;
        }

        return 0;
    }
    else
    {
        nWeaponClass = UNITS_GetWeaponClass(pUnit);
        if (nWeaponClass == 1)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 0;
        }
        else if (nWeaponClass == 7)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 31;
        }

        return -1;
    }
}
