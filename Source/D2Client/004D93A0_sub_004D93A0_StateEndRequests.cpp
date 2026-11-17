struct D2UnitStrc;

void __fastcall sub_004ADCE0_StateRequests(D2UnitStrc* pUnit);                                             // 0x004ADCE0
void __fastcall sub_0044CE40(int nValue);                                                                    // 0x0044CE40

// 0x004D93A0
void __fastcall sub_004D93A0_StateEndRequests(D2UnitStrc* pUnit, int nState)
{
    sub_004ADCE0_StateRequests(pUnit);
}

// 0x004D97E0
void __fastcall sub_004D97E0_StateResetValue(D2UnitStrc* pUnit, int nState)
{
    sub_0044CE40(0);
}
