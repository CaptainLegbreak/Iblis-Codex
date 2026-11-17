struct D2DrlgRoomStrc
{
    char unk0x00[0x44];
    unsigned char fRoomStatus;
};

// 0x0061BAE0
unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->fRoomStatus;
}
