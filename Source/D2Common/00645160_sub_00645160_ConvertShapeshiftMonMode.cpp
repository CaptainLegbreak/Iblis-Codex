extern const int gnShapeshiftMonModes_006EB308[];                                                           // 0x006EB308

// 0x00645160
static int __stdcall sub_00645160_ConvertShapeshiftMonMode(int nMode, int nClass)
{
    return (nClass == 6 && nMode == 4) ? 12 : gnShapeshiftMonModes_006EB308[nMode];
}

int __stdcall sub_K15_Emit6(int* p, int n)
{
    return sub_00645160_ConvertShapeshiftMonMode(p[0], n) + sub_00645160_ConvertShapeshiftMonMode(p[n], p[2]);
}

#include "gen/data/Source/D2Common/00645160_sub_00645160_ConvertShapeshiftMonMode.inc"
