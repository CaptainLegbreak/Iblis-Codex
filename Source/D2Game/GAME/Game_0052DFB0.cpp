#include "D2Game.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


struct D2ClientStrc
{
    char unk_000[0x1B4];
    D2ActiveRoomStrc* hRoom;
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszEmptyAssertText; // 0x006CC837
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId); // 0x005381C0
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810
void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType); // 0x0052CAF0

// 0x0052DFB0
void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 5566);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 5571);

        if (pUnitRoom == pRoom)
        {
            sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            return;
        }
    }
}

// 0x00530270
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType)
{
    if (!nClientId)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (!pGame)
    {
        return;
    }

    if (!sub_005381C0(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    SrvDisconnectClient(pGame, pClient, nEventType);
    GAME_LeaveGamesCriticalSection(pGame);
}
