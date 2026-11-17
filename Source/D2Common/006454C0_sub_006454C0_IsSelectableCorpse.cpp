struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int nPad08;
    int nPad0C;
    int dwAnimMode;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

// 0x006454C0
static __declspec(noinline) int __stdcall sub_006454C0_IsSelectableCorpse(int bDying, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 1)
    {
        return 0;
    }

    if (!(pUnit->dwAnimMode == 12 || bDying && pUnit->dwAnimMode == 0))
    {
        return 0;
    }

    if (STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        return 0;
    }

    return sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 7) != 0;
}

int __fastcall sub_G02_Emit_006454C0(D2UnitStrc* pUnit, int nMode)
{
    if (sub_006454C0_IsSelectableCorpse(nMode, pUnit))
    {
        return STATES_CheckStateMaskUdeadOnUnit(pUnit);
    }
    return sub_006454C0_IsSelectableCorpse(0, pUnit);
}
