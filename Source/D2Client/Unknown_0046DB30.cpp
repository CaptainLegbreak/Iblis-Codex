#include "D2Client.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[22];
    D2InventoryStrc* pInventory;
    int unk0x64[25];
    unsigned int dwFlagEx;
};

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

// 0x0046DB30
D2InventoryStrc* __fastcall sub_0046DB30_GetCompInventory(D2UnitStrc* pUnit, int* pOut)
{
    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x25))
        {
            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
            if (pOwner)
            {
                if (pOut)
                    *pOut = 1;
                return pOwner->pInventory;
            }

            if (pOut)
                *pOut = 0;
            return pUnit->pInventory;
        }

        if (pOut)
            *pOut = 0;
        return pUnit->pInventory;
    }

    if (pOut)
        *pOut = 0;
    return pUnit->pInventory;
}
