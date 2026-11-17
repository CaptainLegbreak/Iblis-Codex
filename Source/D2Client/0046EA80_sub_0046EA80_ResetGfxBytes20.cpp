struct D2UnitStrc;

void __fastcall sub_004DB1C0_SetGfxByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue);              // 0x004DB1C0

// 0x0046EA80
static __forceinline void sub_0046EA80_ResetGfxBytes20(D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < 20; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EAA0
static __forceinline void sub_0046EAA0_ResetGfxBytes16(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 16; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EB50
static __forceinline void sub_0046EB50_ResetGfxBytes8(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 8; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

void __fastcall sub_M113_Emit_0046EA80(D2UnitStrc* pUnit)
{
    sub_0046EA80_ResetGfxBytes20(pUnit);
    sub_0046EAA0_ResetGfxBytes16(pUnit);
    sub_0046EB50_ResetGfxBytes8(pUnit);
}
