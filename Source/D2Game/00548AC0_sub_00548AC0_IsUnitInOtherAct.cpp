struct D2UnitStrc;
struct D2ActiveRoomStrc;

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

inline int sub_00548AC0_GetActMismatchStatus(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nAct == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOther))))
    {
        return 0;
    }
    return 2;
}

// 0x00548AC0
int __fastcall sub_00548AC0_IsUnitInOtherAct(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    return sub_00548AC0_GetActMismatchStatus(pUnit, pOther) != 0;
}
