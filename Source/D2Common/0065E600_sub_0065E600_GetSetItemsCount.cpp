extern const int gnSetItemsCount_006EDA40[];                                                                // 0x006EDA40

// 0x0065E600
static __forceinline int sub_0065E600_GetSetItemsCount(unsigned int nMask)
{
    if (nMask >= 0x40)
        return 0;
    return gnSetItemsCount_006EDA40[nMask];
}

int __fastcall sub_M115_Emit_0065E600(unsigned int nMask)
{
    return sub_0065E600_GetSetItemsCount(nMask);
}

// 0x0065E610
void __stdcall sub_0065E610_Empty(int a1, int a2, int a3)
{
}

#include "gen/data/Source/D2Common/0065E600_sub_0065E600_GetSetItemsCount.inc"
