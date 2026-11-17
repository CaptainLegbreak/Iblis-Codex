// 0x005C0D40
static int __stdcall sub_005C0D40_PercentWithMinimum(int nPercent, int nValue, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

int __stdcall sub_K13_Emit_005C0D40(int nValue, int nPercent)
{
    return sub_005C0D40_PercentWithMinimum(nPercent, nValue, 2);
}
