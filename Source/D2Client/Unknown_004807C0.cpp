#include "D2Client.h"

extern "C" void __fastcall sub_00480420_ValidatePath(D2UnitStrc* unit);
extern "C" int __stdcall sub_00639DF0_CheckState(D2UnitStrc* unit, int state);
extern "C" void __fastcall sub_004E3AB0_UpdateState13(D2UnitStrc* unit);
extern "C" int __fastcall sub_004E2D40_UpdateState22(D2UnitStrc* unit);
extern "C" unsigned int __cdecl sub_0044DB10_GetFrame();
extern "C" int __stdcall sub_00650840_UpdatePath(D2UnitStrc* unit, unsigned int frame);

// 0x004807C0
extern "C" int __fastcall sub_004807C0_UpdateUnitPath(D2UnitStrc* unit)
{
    sub_00480420_ValidatePath(unit);
    if (sub_00639DF0_CheckState(unit, 13))
        sub_004E3AB0_UpdateState13(unit);
    if (sub_00639DF0_CheckState(unit, 22))
        sub_004E2D40_UpdateState22(unit);
    return sub_00650840_UpdatePath(unit, sub_0044DB10_GetFrame()) ? 0 : 1;
}
