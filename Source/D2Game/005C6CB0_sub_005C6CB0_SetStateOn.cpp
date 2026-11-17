struct D2UnitStrc;

void __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nState, int a3);                                        // 0x0056C740

// 0x005C6CB0
void __fastcall sub_005C6CB0_SetStateOn(D2UnitStrc* pUnit, int nState)
{
    sub_6FD11C90(pUnit, nState, 1);
}
