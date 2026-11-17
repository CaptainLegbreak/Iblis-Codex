static __declspec(noinline) unsigned char sub_00482C70_GetFlagIndex(unsigned char nFlags);

// 0x00482C70
static unsigned char sub_00482C70_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_00482C70_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += sub_00482C70_GetFlagIndex(pFlags[i]);
    return nSum;
}
