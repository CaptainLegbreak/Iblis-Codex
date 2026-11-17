int __stdcall sub_K06_EmitGettier2(int nValue);
void __stdcall sub_K06_EmitPuttier2(int nValue, int nOther);

// 0x004D8D60
static int __stdcall sub_004D8D60_GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

void __stdcall sub_K06_Emittier2(int a, int b)
{
    const int v = sub_K06_EmitGettier2(a);
    const int t = sub_K06_EmitGettier2(b);
    sub_K06_EmitPuttier2(sub_004D8D60_GetThirdsTier(v, t), v);
}
