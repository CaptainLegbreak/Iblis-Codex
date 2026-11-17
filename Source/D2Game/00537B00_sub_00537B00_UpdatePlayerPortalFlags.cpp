struct D2ActiveRoomStrc;
struct D2UnitStrc;

struct D2ClientStrc
{
    char unk0x000[0x174];
    D2UnitStrc* pPlayer;
    char unk0x178[0x3C];
    D2ActiveRoomStrc* pRoom;
    int nEmitterTag;
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nFlags);                                   // 0x006221E0
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);                                                // 0x00622230

// 0x00537B00
static __forceinline void sub_00537B00_UpdatePlayerPortalFlags(D2ClientStrc* pClient)
{
    D2ActiveRoomStrc* pRoom = pClient->pRoom;
    if (pRoom && pClient->pPlayer)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nFlags = UNITS_GetPlayerPortalFlags(pClient->pPlayer);
        nFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
        UNITS_SetPlayerPortalFlags(pClient->pPlayer, nFlags);
    }
}

void __fastcall sub_M468_Emit_00537B00(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    pClient->pRoom = pRoom;
    pClient->nEmitterTag = 0x2D7;
    sub_00537B00_UpdatePlayerPortalFlags(pClient);
}
