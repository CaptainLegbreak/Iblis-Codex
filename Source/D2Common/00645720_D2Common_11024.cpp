struct D2UnitStrc;
struct D2SkillsTxt
{
    char unk0x00[20];
    unsigned char nRange;
    char unk0x15[24 - 20 - 1];
    short nITypeA[3];
    char unk0x1E[572 - 24 - 6];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
};

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck);                                         // 0x00629B50
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pStat, int nArraySize);        // 0x006261D0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

// 0x00645720
int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus)
{
    int nStatId = 0;
    D2StatStrc pStat[32];

    if (pHasThrowBonus)
    {
        *pHasThrowBonus = 0;
    }

    if (!pSkill)
    {
        pSkill = UNITS_GetUsedSkill(pUnit);
        if (!pSkill)
        {
            return 0;
        }
    }

    if (!ITEMS_CheckIfThrowable(pItem) || !pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 48)
        || pSkillsTxtRecord->nRange != 2)
    {
        return 0;
    }

    switch (nType)
    {
    case 0:
        nStatId = 345;
        break;
    case 1:
        nStatId = 346;
        break;
    case 2:
        nStatId = 347;
        break;
    default:
        return 0;
    }

    int nCount = STATLIST_CopyStats(pUnit, nStatId, pStat, 32);
    int nValue = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMS_CheckItemTypeId(pItem, pStat[i].nLayer) && pStat[i].nValue > nValue)
        {
            nValue = pStat[i].nValue;
        }
    }

    if (pHasThrowBonus)
    {
        *pHasThrowBonus = 1;
    }

    return nValue;
}

// 0x00645830
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType)
{
    int nStatId = 0;
    D2StatStrc pStat[32];

    if (pUnit && pItem)
    {
        if (!pSkill)
        {
            pSkill = UNITS_GetUsedSkill(pUnit);
        }

        int bHasThrowBonus = 0;
        int nThrowBonus = D2Common_11024(pUnit, pItem, pSkill, nType, &bHasThrowBonus);
        if (bHasThrowBonus)
        {
            return nThrowBonus;
        }

        switch (nType)
        {
        case 0:
            nStatId = 342;
            break;
        case 1:
            nStatId = 343;
            break;
        case 2:
            nStatId = 344;
            break;
        default:
            return 0;
        }

        int nCount = STATLIST_CopyStats(pUnit, nStatId, pStat, 32);
        int nValue = 0;
        for (int i = 0; i < nCount; ++i)
        {
            if (ITEMS_CheckItemTypeId(pItem, pStat[i].nLayer) && pStat[i].nValue > nValue)
            {
                nValue = pStat[i].nValue;
            }
        }

        return nValue;
    }

    return 0;
}
