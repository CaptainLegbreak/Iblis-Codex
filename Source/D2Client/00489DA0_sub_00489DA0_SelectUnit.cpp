struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

extern int gnGlobal_00721E54; // 0x00721E54

// 0x00489DA0
void __fastcall sub_00489DA0_SelectUnit(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwClassId : -1) != 267)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(sub_00463DD0());
    if (!pPlayerRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pPlayerRoom)) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        gnGlobal_00721E54 = pUnit->dwUnitId;
    }
}
