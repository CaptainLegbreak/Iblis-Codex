struct D2UnitStrc;
struct D2ActiveRoomStrc;

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

// 0x005E7D30
int __fastcall sub_005E7D30_IsInTownOrRoomless(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 1;
    }

    return DUNGEON_IsRoomInTown(pRoom) != 0;
}
