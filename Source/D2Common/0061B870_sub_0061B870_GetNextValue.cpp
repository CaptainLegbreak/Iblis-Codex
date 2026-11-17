struct D2Entry0061B7E0Strc
{
    unsigned char unk_00[0x1C];
    D2Entry0061B7E0Strc* pNext1C;
    unsigned char unk_20[0x10];
    int nValue30;
    unsigned char unk_34[0x10];
    unsigned char nIndex44;
    unsigned char unk_45[0xA3];
    D2Entry0061B7E0Strc* pSelfE8;
};

struct D2Owner0061B7E0Strc
{
    unsigned char unk_00[0xA0];
    D2Entry0061B7E0Strc pEntries[4];
};

static __forceinline D2Entry0061B7E0Strc* sub_0061B870_GetFirst(D2Owner0061B7E0Strc* pOwner, unsigned char nIndex)
{
    if (pOwner->pEntries[nIndex].pNext1C != &pOwner->pEntries[nIndex])
    {
        return pOwner->pEntries[nIndex].pNext1C;
    }
    return 0;
}

static __forceinline int sub_0061B870_IsListHead(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pNext, unsigned char nIndex)
{
    return pNext == &pOwner->pEntries[nIndex];
}

static __forceinline int sub_0061B870_IsStatus(D2Entry0061B7E0Strc* pEntry, int nStatus)
{
    if (pEntry->nIndex44 == nStatus)
    {
        return 1;
    }
    return 0;
}

// 0x0061B870
int __fastcall sub_0061B870_GetNextValue(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pEntry)
{
    unsigned char nIndex = pEntry->nIndex44;
    D2Entry0061B7E0Strc* pNext = pEntry->pNext1C;
    if (sub_0061B870_IsStatus(pEntry, 0) && sub_0061B870_IsListHead(pOwner, pNext, nIndex))
        pNext = sub_0061B870_GetFirst(pOwner, 1);
    return pNext ? pNext->nValue30 : 0;
}
