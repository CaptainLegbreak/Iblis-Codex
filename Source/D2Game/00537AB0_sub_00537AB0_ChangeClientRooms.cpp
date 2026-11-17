struct D2ActiveRoomStrc;

struct D2ClientStrc
{
    char unk0x000[0x1B4];
    D2ActiveRoomStrc* pRoom;
};

void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom);            // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom);                      // 0x0061A9F0

// 0x00537AB0
static __forceinline void sub_00537AB0_ChangeClientRooms(D2ActiveRoomStrc* pNewRoom, D2ActiveRoomStrc* pOldRoom)
{
    DUNGEON_ChangeClientRoom(pOldRoom, pNewRoom);
    D2Common_10077(pOldRoom, pNewRoom);
}

void __fastcall sub_M124_Emit_00537AB0(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    if (pClient->pRoom != pRoom)
    {
        sub_00537AB0_ChangeClientRooms(pRoom, pClient->pRoom);
        pClient->pRoom = pRoom;
    }
}
