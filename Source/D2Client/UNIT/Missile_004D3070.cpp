#include "D2Client.h"
#include "D2Structs.h"


D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390

// 0x004D3070
void __fastcall sub_004D3070_CltDoOwnerStep(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    if ((unsigned int)pOwner->dwUnitType <= UNIT_MONSTER && sub_00464820_IsDeadOrDying(pOwner))
    {
        sub_004D2D70_CltMissileHit(pMissile, 0, 0);
        return;
    }
    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);
}
