#include "D2Client.h"

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __cdecl sub_0044DA90(); // 0x0044DA90

// 0x004C9D50
static inline D2UnitStrc* sub_004C9D50_FindDestinationById(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 3, nUnitId, 0);
}

D2UnitStrc* __fastcall sub_M109_Emit_004C9D50(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C9D50_FindDestinationById(pUnit, nUnitId + 1);
}

unsigned int gdwNextTick; // 0x007C78B0

// 0x004CA030
int __fastcall sub_004CA030_TickEvent(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nTick = sub_0044DA90();
    if (nTick > gdwNextTick)
    {
        gdwNextTick = nTick + 5;
        sub_004AF890(pUnit, 1, 0);
    }
    return 1;
}
