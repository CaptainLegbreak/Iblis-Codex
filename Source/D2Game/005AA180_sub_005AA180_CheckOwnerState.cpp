struct D2GameStrc;
struct D2UnitStrc;
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

// 0x005AA180
int __fastcall sub_005AA180_CheckOwnerState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pExpectedOwner)
{
    int nResult = 2;
    if (!pExpectedOwner)
        return nResult;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner && pExpectedOwner == pOwner)
    {
        if (STATES_CheckState(pOwner, 13))
            nResult = 0;
    }
    return nResult;
}
