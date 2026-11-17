extern const int gnSetMaskToBonusMappingTable[0x40];                                                        // 0x006EE440

// 0x00663A10
static __declspec(noinline) int sub_00663A10_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gnSetMaskToBonusMappingTable) / sizeof(gnSetMaskToBonusMappingTable[0]))
        return 0;
    return gnSetMaskToBonusMappingTable[nSetItemMask];
}

void __fastcall sub_M102_UseBonusCount_00663A10(int nCount);
void __stdcall sub_M102_Emit_00663A10(int nUnused, unsigned int nSetItemMask)
{
    sub_M102_UseBonusCount_00663A10(sub_00663A10_GetSetBonusCount(nSetItemMask));
}

#include "gen/data/Source/D2Common/00663A10_sub_00663A10_GetSetBonusCount.inc"
