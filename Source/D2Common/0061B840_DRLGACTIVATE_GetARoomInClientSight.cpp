struct D2ActiveRoomStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x1C];
    D2DrlgRoomStrc* pStatusNext;
    char unk0x20[0x08];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0xE8 - 0x45];
    D2DrlgRoomStrc* pStatusPrev;
};

struct D2DrlgStrc
{
    char unk0x000[0xA0];
    D2DrlgRoomStrc tStatusRoomsLists[4];
};

static __forceinline D2DrlgRoomStrc* DRLGACTIVATE_RoomExStatusList_GetFirst(D2DrlgStrc* pDrlg, int nStatus)
{
    D2DrlgRoomStrc* pNext = pDrlg->tStatusRoomsLists[nStatus].pStatusNext;
    if (pNext != &pDrlg->tStatusRoomsLists[nStatus])
        return pNext;
    return 0;
}

// 0x0061B840
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInClientSight(D2DrlgStrc* pDrlg)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, 0);
    if (!pDrlgRoom)
        pDrlgRoom = DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, 1);
    if (pDrlgRoom)
        return pDrlgRoom->pRoom;
    return 0;
}

// 0x0061BAC0
void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(D2DrlgRoomStrc* pDrlgRoom, int bReset)
{
    if (bReset)
        pDrlgRoom->dwFlags &= ~0x400000;
    else
        pDrlgRoom->dwFlags |= 0x400000;
}
