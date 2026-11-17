#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2ClientStrc
{
    char unk0x000[0x3D8];
    unsigned long dwLastPacketTick;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                   // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall sub_0054D750_HandleClientPacket(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pPacket, int nPacketSize); // 0x0054D750

// 0x0053F3D0
void __fastcall CCMD_ProcessClientMessage(void* pData, int nPacketSize)
{
    const int nClientId = *(int*)pData;
    unsigned char* pPacket = (unsigned char*)pData + 4;
    D2GameStrc* pGame = sub_0052FEE0_LockGameByClientId(nClientId);
    if (!pGame)
    {
        GAME_LogMessage(9, "[ProcessClientMessage] Client %d is not in any game", nClientId);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    D2_ASSERT(pClient, 0x1F9);
    pClient->dwLastPacketTick = GetTickCount();
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer && (pPlayer ? pPlayer->dwUnitType : 6) == 0)
    {
        sub_0054D750_HandleClientPacket(pGame, pPlayer, pPacket, nPacketSize);
    }

    GAME_LeaveGamesCriticalSection(pGame);
}
