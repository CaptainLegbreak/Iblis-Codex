#include "D2Game.h"
#include "D2GameStrc.h"

typedef int (__stdcall* FARPROC)();

struct D2ClientInfoStrc;
struct D2GameDataTableStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};


struct D2ClientStrc
{
    char unk0x000[0x68];
    D2ClientInfoStrc* pClientInfo;
    char unk0x06C[0x140];
    unsigned char nAct;
};

struct D2ServerCallbackFunctions
{
    void* pfCloseGame;
    void* pfLeaveGame;
    void (__fastcall* pfGetDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, int dwClientId, const char* szAccountName);
    void* pfSaveDatabaseCharacter;
    void* pfServerLogMessage;
    void* pfEnterGame;
    void* pfFindPlayerToken;
    void* pfSaveDatabaseGuild;
    void (__fastcall* pfUnlockDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, const char* szAccountName);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
void __fastcall sub_6FC33910(D2ClientStrc* pClient);                                                        // 0x00538320
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                            // 0x005386D0
D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9); // 0x00539A30
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320
void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340

extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern D2GameDataTableStrc* gpGameDataTbl_6FD45818;                                                         // 0x00883D38
extern int gnAct_6FD45824;                                                                                  // 0x00883D44
D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                                 // 0x00883D50

// 0x0052C260
static __declspec(noinline) void sub_0052C260_SendGameInit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
}

// 0x0052FA50
void __fastcall SrvJoinGame(int dwClientId, unsigned short nGameId, int nClass, const char* szClientName, int a5, const char* szAccountName, int nCharSaveTransactionToken, int nLocale, int a8, int a9, int a11, int a12, int a13)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return;
    }

    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    if (!nGUID)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
    {
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR cannot loc game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    SERVER_SetClientGameGUID(dwClientId, nGUID);

    D2ClientStrc* pClient = ClientAddToGame(pGame, dwClientId, nClass, szClientName, szAccountName, nCharSaveTransactionToken, nLocale, a8, a9);
    if (!pClient)
    {
        if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter), 1972);
            gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter(&pGame->pClientInfo, szClientName, szAccountName);
        }
        GAME_LeaveGamesCriticalSection(pGame);
        sub_0053B220_SendHeaderOnly0xB0(dwClientId);
        D2NET_10016(dwClientId);
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR adding Client to game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    sub_0052C260_SendGameInit(pGame, pClient);
    pClient->nAct = gnAct_6FD45824;
    GAME_LeaveGamesCriticalSection(pGame);

    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter)
    {
        GAME_LogMessage(6, "[JOIN 2] %d clientid, %d game, Requesting char from db", dwClientId, nGameId);
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter), 2023);
        gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter(&pClient->pClientInfo, szClientName, dwClientId, szAccountName);
        sub_6FC33910(pClient);
    }
    else
    {
        D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    }
}
