struct D2GameStrc;
struct D2UnitStrc;

D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

// 0x005CF8A0
static __forceinline D2UnitStrc* sub_005CF8A0_FindMeleeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID)
{
    return sub_6FD107F0(pGame, pUnit, 0, 0, 3, 3, nUnitGUID, 0);
}

int __fastcall sub_M132_Emit_005CF8A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return sub_005CF8A0_FindMeleeTarget(pGame, pUnit, 0x4D3) != 0;
}
