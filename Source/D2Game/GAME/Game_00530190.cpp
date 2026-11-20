#include "D2Game.h"

int __stdcall sub_0052B4F0(int nClientId, int a2, int a3);                                                  // 0x0052B4F0
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20
void __fastcall sub_0052C210_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                      // 0x0052C210
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                   // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bFlag);                        // 0x00537860
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId);                         // 0x005381C0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nState);                                  // 0x005386D0
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY);
int __fastcall sub_00539760(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY);
void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);           // 0x00539DA0
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nReason);           // 0x0053B260

// 0x00530190
void __fastcall SrvJoinAct(int nClientId)
{
    D2ClientStrc* pClient;
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (pGame)
    {
        if (!sub_005381C0(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
            const int nErrorCode = sub_00539760(pClient, pGame, 1, 0, 0, 0);
            if (nErrorCode)
            {
                D2GAME_PACKETS_SendSystemError(nClientId, nErrorCode);
                ClientRemoveFromGame(pGame, nClientId, 1);
                sub_0052B4F0(nClientId, (int)".\\GAME\\Game.cpp", 0x672);
                GAME_LeaveGamesCriticalSection(pGame);
                return;
            }

            sub_0052C210_ClientEnterAct(pGame, pClient);
            sub_005394A0(pClient, CLIENTS_GetPlayerFromClient(pClient, 1), pGame, 0, 0, 0);
            CLIENTS_SetClientState(pClient, 3);
            GAME_LeaveGamesCriticalSection(pGame);
            GAME_LogMessage(6, "[JOIN 5] %d clientid, SrvJoinAct: Added to game.", nClientId);
            return;
        }
    }

    GAME_LogMessage(6, "[JOIN]  SrvJoinAct: No game found for client(%d)", nClientId);
}
