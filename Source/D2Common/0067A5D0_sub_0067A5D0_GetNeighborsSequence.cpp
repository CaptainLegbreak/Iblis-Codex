extern const int dword_6FDD1BE0[8][8];                                                                      // 0x006F17D8

// 0x0067A5D0
static __declspec(noinline) const int* __stdcall sub_0067A5D0_GetNeighborsSequence(int nBase, int nDirection)
{
    return dword_6FDD1BE0[(nDirection - nBase) & 7];
}

const int* __stdcall sub_M125_Emit_0067A5D0(int nUnused1, int nUnused2, int nBase, int nDirection)
{
    return sub_0067A5D0_GetNeighborsSequence(nBase, nDirection);
}

#include "gen/data/Source/D2Common/0067A5D0_sub_0067A5D0_GetNeighborsSequence.inc"
