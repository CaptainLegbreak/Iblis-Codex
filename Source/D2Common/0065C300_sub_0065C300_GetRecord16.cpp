struct D2Record16Strc
{
    int a[4];
};

// 0x0065C300
static __forceinline D2Record16Strc* __stdcall sub_0065C300_GetRecord16(D2Record16Strc* pBase, int nIndex)
{
    return &pBase[nIndex];
}

int __fastcall sub_M117_Emit_0065C300(D2Record16Strc* pBase, int nIndex)
{
    return (int)sub_0065C300_GetRecord16(pBase, nIndex + 1);
}
