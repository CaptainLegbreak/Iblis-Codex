#include "D2Structs.h"

int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470
int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wFlag); // 0x004AC7E0

// 0x004B11F0
int __fastcall sub_004B11F0_CheckStatus(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return 0;
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
        return 0;
    if (pUnit->dwUnitType == 1)
    {
        if (sub_004AC7E0(pUnit, 8))
            return 0;
        if (pUnit->dwUnitType == 1 && sub_004AC7E0(pUnit, 2))
            return 0;
    }
    return 1;
}
