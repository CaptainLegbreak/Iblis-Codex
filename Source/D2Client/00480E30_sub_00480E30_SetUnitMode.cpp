struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
};

void __fastcall sub_004E4020(D2UnitStrc* pUnit);                                                            // 0x004E4020
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __cdecl sub_K04_EmitUse(D2UnitStrc* pUnit);

// 0x00480E30
static int __stdcall sub_00480E30_SetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40u;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        sub_00470610_Refresh(pUnit, 0);
        return 1;
    }
    return 0;
}

int __cdecl sub_K04_EmitSetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    const int bOk = sub_00480E30_SetUnitMode(pUnit, nMode);
    sub_K04_EmitUse(pUnit);
    return bOk;
}
