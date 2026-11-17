struct sub_006BC290_Strc
{
    char unk_000[0x118];
    int nValue118;
    int nValue11C;
    int nValue120;
};

// 0x006BC290
void __stdcall sub_006BC290_SetValues(sub_006BC290_Strc* pThis, int nA, int nB, int nC)
{
    if (pThis)
    {
        pThis->nValue118 = nA;
        pThis->nValue11C = nB;
        pThis->nValue120 = nC;
    }
}
