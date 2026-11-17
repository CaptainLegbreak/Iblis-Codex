extern int gnGlobal_0077B0A0; // 0x0077B0A0
extern int gnGlobal_0077AD70; // 0x0077AD70
extern int gnGlobal_0070CD7C; // 0x0070CD7C
extern unsigned char gbGlobal_0070CD63; // 0x0070CD63
extern unsigned char gbGlobal_0070CD62; // 0x0070CD62

// 0x0043ED10
int __stdcall sub_0043ED10_UpdateCounter(int nUnused)
{
    int nBase = gnGlobal_0077B0A0;
    int nOther = gnGlobal_0077AD70;
    int nCurrent = gnGlobal_0070CD7C;
    int nDifference = nOther - nBase;
    int nCombined = nBase + nCurrent;
    if (nCombined < nDifference)
        nDifference = nCombined;
    gbGlobal_0070CD62 = gbGlobal_0070CD63;
    gnGlobal_0070CD7C = nDifference;
    return 1;
}
