extern int gaLookupRow_006F1088[];                                                                          // 0x006F1088
extern int gaLookupSmall_006F0630[][4];                                                                     // 0x006F0630
extern int gaLookupLarge_006F06F0[][2];                                                                     // 0x006F06F0

// 0x00675600
int __fastcall sub_00675600_LookupTable(int nA, int nB, int nC, int nD, int nE)
{
    if (nA < 0)
    {
        nA -= 2;
    }
    else if (nA > 0)
    {
        nA += 2;
    }

    if (nC < 0)
    {
        nC -= 2;
    }
    else if (nC > 0)
    {
        nC += 2;
    }

    const int nRow = gaLookupRow_006F1088[nA + 9 * (nC + nD) + nB];
    if (nRow == -1)
    {
        return 0;
    }

    if (nE >= 4)
    {
        return gaLookupLarge_006F06F0[nRow - 1][nE - 4];
    }

    return gaLookupSmall_006F0630[nRow - 1][nE];
}
