struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* ptRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

enum
{
    UNIT_PLAYER = 1,
};

D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

// 0x004608C0
void __cdecl sub_004608C0_RefreshAdjacentPlayers()
{
    if (!sub_00463DE0_GetStoredUnit())
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if ((pUnit ? pUnit->dwUnitType : 6) == UNIT_PLAYER && STATES_CheckState(pUnit, 0x3F))
            {
                sub_00470610_Refresh(pUnit, 0);
            }
        }
    }
}
