struct D2DrlgRoomStrc;
struct D2ActiveRoomStrc { char unknown[0x10]; D2DrlgRoomStrc* pDrlgRoom; };
unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc*); // 0x0061BAE0
// 0x0061A440
int __stdcall DUNGEON_GetRoomStatusFlags(D2ActiveRoomStrc* pRoom)
{
    return DRLGACTIVATE_GetRoomStatusFlags(pRoom->pDrlgRoom) >= 3;
}
