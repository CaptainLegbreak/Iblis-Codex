struct D2Entry0061B7E0Strc
{
    unsigned char unk_00[0x1C];
    D2Entry0061B7E0Strc* pSelf1C;
    unsigned char unk_20[0x24];
    unsigned char nIndex44;
    unsigned char unk_45[0xA3];
    D2Entry0061B7E0Strc* pSelfE8;
};

struct D2Owner0061B7E0Strc
{
    unsigned char unk_00[0xA0];
    D2Entry0061B7E0Strc pEntries[4];
};

// 0x0061B7E0
void __fastcall sub_0061B7E0_InitEntries(D2Owner0061B7E0Strc* pOwner)
{
    unsigned int i;
    D2Entry0061B7E0Strc* pEntry;
    for (i = 0, pEntry = pOwner->pEntries; i < 4; ++i, ++pEntry)
    {
        pEntry->nIndex44 = (unsigned char)i;
        pEntry->pSelf1C = pEntry;
        pEntry->pSelfE8 = pEntry;
    }
}
