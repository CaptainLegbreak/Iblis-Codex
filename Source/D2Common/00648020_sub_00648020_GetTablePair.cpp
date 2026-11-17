extern const int gnTable_006EB490[][9];                                                                      // 0x006EB490

// 0x00648020
static void __stdcall sub_00648020_GetTablePair(int b, int a, int* pOut1, int* pOut2)
{
    *pOut1 = gnTable_006EB490[a][b];
    *pOut2 = gnTable_006EB490[b][a];
}

void __stdcall sub_K15_Emit8(int* p, int n)
{
    sub_00648020_GetTablePair(p[1], n, p, p + 1);
    sub_00648020_GetTablePair(n, p[2], p + 2, p + 3);
}

#include "gen/data/Source/D2Common/00648020_sub_00648020_GetTablePair.inc"
