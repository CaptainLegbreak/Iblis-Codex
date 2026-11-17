struct D2UnitStrc;

struct D2MagicAffixTxt
{
    char unk0x00[0x5C];
    int dwGroup;
    char unk0x60[0x30];
};

struct D2MagicAffixIndexAndPtrStrc
{
    int nAffixId;
    D2MagicAffixTxt* pMagicAffixRecord;
};

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo);                                // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                                // 0x00627F80
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                       // 0x00633EE0

// 0x005C0D00
static int __stdcall sub_005C0D00_ITEMS_AddPotentialMagicAffix(int nAffixId, D2MagicAffixTxt* pRecord, D2MagicAffixIndexAndPtrStrc* pAffixes, int nCount)
{
    if (nCount < 0x1FF)
    {
        pAffixes[nCount].pMagicAffixRecord = pRecord;
        pAffixes[nCount].nAffixId = nAffixId;
        ++nCount;
    }

    return nCount;
}

// 0x005C1500
static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup)
{
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_M11_Emit_005C0D00(D2UnitStrc* pItem, D2MagicAffixTxt* pFirst, int nRecords, int nBase)
{
    D2MagicAffixIndexAndPtrStrc tAffixes[0x200];
    int nCount = 0;
    for (int i = 0; i < nRecords; ++i)
    {
        D2MagicAffixTxt* pRecord = &pFirst[i];
        if (ITEMMODS_HasAffixWithGroup(pItem, pRecord->dwGroup))
        {
            continue;
        }

        nCount = sub_005C0D00_ITEMS_AddPotentialMagicAffix(i + nBase, pRecord, tAffixes, nCount);
    }

    return nCount ? tAffixes[nCount - 1].nAffixId : 0;
}
