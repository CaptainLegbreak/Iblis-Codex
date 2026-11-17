struct D2GameStrc;
struct D2ClientStrc;
struct D2UnitStrc { int dwUnitType; char unk04[0xE4]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; unsigned int nNumClients; };
struct D2DrlgCoordsStrc { int nSubtileX; int nSubtileY; int nSubtileWidth; int nSubtileHeight; int nTileX; int nTileY; int nTileWidth; int nTileHeight; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*, D2DrlgCoordsStrc*); // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc*, int, int, int); // 0x0053BC50
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc*, D2ClientStrc*); // 0x0061A660
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc*, D2UnitStrc*); // 0x00573780
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
void __fastcall sub_00571F90(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00571F90
inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}
// 0x0053A8E0
void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pRoom) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 207); exit(-1); }
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), tCoords.nTileX, tCoords.nTileY);
    DUNGEON_AddClientToRoom(pRoom, pClient);
    if (pRoom->nNumClients <= 1)
    {
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
            switch (nUnitType)
            {
            case 1: MONSTER_UpdateAiCallbackEvent(pGame, pUnit); break;
            }
        }
    }
    D2UnitStrc* pUnit = pRoom->pUnitFirst;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    while (pUnit)
    {
        if (pPlayer != pUnit) sub_00571F90(pGame, pUnit, pClient);
        pUnit = pUnit->pRoomNext;
    }
}
