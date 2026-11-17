struct D2UnkEntry8Strc
{
    int f_0;
    int f_4;
};

int __stdcall sub_K11_EmitUse(D2UnkEntry8Strc* pEntry);

// 0x00555D00
static D2UnkEntry8Strc* __stdcall sub_00555D00_GetBoundedEntry(D2UnkEntry8Strc* pBase, int nIndex, int nMax)
{
    if (nIndex > nMax)
    {
        return 0;
    }
    return &pBase[nIndex];
}

int __fastcall sub_K11_Emit00555D00(D2UnkEntry8Strc* pBase, int nIndex, int nMax)
{
    return sub_K11_EmitUse(sub_00555D00_GetBoundedEntry(pBase, nIndex + 3, nMax));
}
