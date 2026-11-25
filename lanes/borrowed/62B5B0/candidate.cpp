// 0x0062B5B0
int __fastcall sub_0062B5B0(D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2StatStrc pStat[64];
    const int nQuality = ITEMS_GetItemQuality_Inl(pItem);
    int nRequiredLevel = 0;
    switch (nQuality)
    {
    case ITEMQUAL_MAGIC:
    {
        D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
        D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2MagicAffixTxt* pAutoAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(pItem));
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pPrefix, pPlayer);
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pSuffix, pPlayer);
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pAutoAffix, pPlayer);
        break;
    }
    case ITEMQUAL_RARE:
    {
        for (int i = 0; i < 3; ++i)
        {
            D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
            D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pPrefix, pPlayer);
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pSuffix, pPlayer);
        }
        D2MagicAffixTxt* pAutoAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix_Inl(pItem));
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pAutoAffix, pPlayer);
        break;
    }
    case ITEMQUAL_CRAFT:
    {
        int nCraftBonus = 10;
        for (int i = 0; i < 3; ++i)
        {
            D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
            D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pPrefix, pPlayer);
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(nRequiredLevel, pSuffix, pPlayer);
            if (pPrefix)
            {
                nCraftBonus += 3;
            }
            if (pSuffix)
            {
                nCraftBonus += 3;
            }
        }
        nRequiredLevel += nCraftBonus;
        const int nMaxLevel = DATATBLS_GetMaxLevel(0) - 1;
        if (nRequiredLevel > nMaxLevel)
        {
            nRequiredLevel = nMaxLevel;
        }
        break;
    }
    case ITEMQUAL_UNIQUE:
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUnique = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUnique)
            {
                if (!pPlayer)
                {
                    const int nLevel = (short)pUnique->wLvlReq;
                    if (nLevel >= 0)
                    {
                        nRequiredLevel = nLevel;
                    }
                }
                else if (sub_00463720_TestUnitFlagEx(pPlayer, 0x2000000) || ITEMS_GetItemFormat(pItem) >= 1)
                {
                    const int nLevel = (short)pUnique->wLvlReq;
                    if (nLevel >= 0)
                    {
                        nRequiredLevel = nLevel;
                    }
                }
            }
        }
        break;
    case ITEMQUAL_SET:
    {
        D2SetItemsTxt* pSet = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSet)
        {
            const int nLevel = (short)pSet->wLvlReq;
            if (nLevel >= 0)
            {
                nRequiredLevel = nLevel;
            }
        }
        break;
    }
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->levelReq > nRequiredLevel)
    {
        nRequiredLevel = pItemsTxtRecord->levelReq;
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* pSocketed = INVENTORY_GetFirstItem(pItem->pInventory); pSocketed; pSocketed = INVENTORY_GetNextItem(pSocketed))
        {
            D2UnitStrc* pSocketable = INVENTORY_UnitIsItem(pSocketed);
            if (!pSocketable)
            {
                break;
            }
            const int nLevel = sub_0062B5B0(pSocketable, pPlayer);
            if (nRequiredLevel <= nLevel)
            {
                nRequiredLevel = nLevel;
            }
        }
    }

    int nCount = STATLIST_CopyStats(pItem, 107, pStat, 64);
    for (int i = 0; i < nCount; ++i)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStat[i].nLayer);
        if (pSkillsTxtRecord && pSkillsTxtRecord->wReqLevel > nRequiredLevel)
        {
            nRequiredLevel = pSkillsTxtRecord->wReqLevel;
        }
    }

    nCount = STATLIST_CopyStats(pItem, 97, pStat, 64);
    for (int i = 0; i < nCount; ++i)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStat[i].nLayer);
        if (pSkillsTxtRecord)
        {
            int nLevel;
            char nCharClass;
            if (pPlayer && !GAME_GetUnitTypeOrInvalid(pPlayer) && (nCharClass = pSkillsTxtRecord->nCharClass) >= 0)
            {
                if (nCharClass < 7 && (unsigned char)GAME_GetUnitClassId(pPlayer) == nCharClass)
                {
                    nLevel = pSkillsTxtRecord->wReqLevel;
                    if (nLevel > nRequiredLevel)
                    {
                        nRequiredLevel = nLevel;
                    }
                }
                else
                {
                    nLevel = pSkillsTxtRecord->wReqLevel + 6;
                    if (nLevel > nRequiredLevel)
                    {
                        nRequiredLevel = nLevel;
                    }
                }
            }
            else
            {
                nLevel = pSkillsTxtRecord->wReqLevel + 6;
                if (nLevel > nRequiredLevel)
                {
                    nRequiredLevel = nLevel;
                }
            }
        }
    }

    nRequiredLevel += STATLIST_UnitGetStatValue(pItem, 92, 0);
    return nRequiredLevel > 0 ? nRequiredLevel : 0;
}
