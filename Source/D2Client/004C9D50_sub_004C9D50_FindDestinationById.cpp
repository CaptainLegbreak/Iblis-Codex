struct D2UnitStrc;

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

// 0x004C9D50
static __forceinline D2UnitStrc* sub_004C9D50_FindDestinationById(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 3, nUnitId, 0);
}

D2UnitStrc* __fastcall sub_M109_Emit_004C9D50(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C9D50_FindDestinationById(pUnit, nUnitId + 1);
}
