struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};
int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0

static __forceinline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x00467470
int __fastcall sub_00467470_UnitFindTest(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pUnit->dwUnitType == 4
        && ITEMS_IsMetalItem(UNITS_GetClassIdInline(pUnit)))
    {
        return 1;
    }
    return 0;
}
