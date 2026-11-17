struct D2GameStrc;
struct D2ClientStrc;

int __stdcall SERVER_GetClientGameGUID(int nClientId); // 0x0052B610
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId); // 0x005381C0
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810
void __fastcall GAME_DisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType); // 0x0052CAF0

// 0x00530270
void __fastcall GAME_DisconnectClientById(int nClientId, int nEventType)
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
    GAME_DisconnectClient(pGame, pClient, nEventType);
    GAME_LeaveGamesCriticalSection(pGame);
}
