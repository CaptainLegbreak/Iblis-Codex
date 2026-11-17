extern const int gnSetMaskToBonusMappingTable_006DBD90[0x40];                                                // 0x006DBD90

// 0x004E5A10
static __declspec(noinline) int sub_004E5A10_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gnSetMaskToBonusMappingTable_006DBD90) / sizeof(gnSetMaskToBonusMappingTable_006DBD90[0]))
        return 0;
    return gnSetMaskToBonusMappingTable_006DBD90[nSetItemMask];
}

void __fastcall sub_004E5A10_UseBonusCount(int nCount);
void __stdcall sub_004E5A10_Emit(int nUnused, unsigned int nSetItemMask)
{
    sub_004E5A10_UseBonusCount(sub_004E5A10_GetSetBonusCount(nSetItemMask));
}

#include "gen/data/Source/D2Client/004E5A10_sub_004E5A10_GetSetBonusCount.inc"
