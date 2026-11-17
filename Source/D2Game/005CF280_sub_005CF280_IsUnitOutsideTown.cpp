struct D2UnitStrc;
struct D2ActiveRoomStrc;

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

// 0x005CF280
static int sub_005CF280_IsUnitOutsideTown(D2UnitStrc* pUnit)
{
    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit));
}

void __stdcall sub_M217_Emit_005CF280(D2UnitStrc* pUnit, int* pResult)
{
    if (pUnit)
    {
        *pResult = sub_005CF280_IsUnitOutsideTown(pUnit);
    }
}
