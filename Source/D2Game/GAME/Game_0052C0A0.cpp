#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"

struct D2ServerCallbackFunctions;

typedef int (__stdcall* FARPROC)();




struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    char unk0x08[0x4A0];
    D2ClientStrc* pNext;
};



struct D2GameListStrc
{
    int nLinkOffset;
    D2GameLinkStrc tTerminator;

    D2GameStrc* RawNext(D2GameStrc* pGame);
    D2GameStrc* Next(D2GameStrc* pGame);
};

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2GameStrc* pGame);
    char unk0x04[0x18];
    D2GameListStrc* pSlotLists;
    int unk0x20;
    unsigned int f_24;
    char unk0x28[0x1C];
    D2HashKeyNoneStrc f_44;
    char unk0x45[0xB];
    D2CriticalSectionStrc f_50;

    void SyncEnterLock(int* pLockHandle, int bForWriting);
    void SyncLeaveLock(int nLockHandle);
    void Unlock(int nLockHandle);
    void Unlink(D2GameStrc* pGame);                                         // 0x0052E490
    void sub_0052E590(D2GameStrc* pGame);
    void sub_0052E5B0(D2GameStrc* pGame);
    void DeleteUnlock(D2GameStrc* pGame, int nLockHandle);
    D2GameStrc* Ptr(unsigned int nHashValue, const D2HashKeyNoneStrc* pKey); // 0x0052E650
    D2GameStrc* sub_0052E6B0(unsigned int nHashValue);
    D2GameStrc* Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting);
};

struct D2MessageThreadArgsStrc
{
    int nParam1;
    int nParam2;
    char szMessage[0x100];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize, unsigned long (__stdcall* lpStartAddress)(D2MessageThreadArgsStrc*), D2MessageThreadArgsStrc* lpParameter, unsigned long dwCreationFlags, unsigned long* lpThreadId); // 0x006CC250
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __stdcall sub_0052B4F0(int nClientId, int a2, int a3);                                                  // 0x0052B4F0
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage);               // 0x0052F4C0
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType);                                   // 0x00530270
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId);                         // 0x005381C0
void __fastcall CLIENTS_UpdatePing(int nClientId, int a2, int a3, int a4);                                  // 0x005389A0
int __fastcall CLIENTS_GetClientIdByName(const char* szClientName);                                         // 0x00538BF0
void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);           // 0x00539DA0
void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005433F0
int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                      // 0x0061A3F0
int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A790
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                     // 0x0061A910

extern D2GameDataTableStrc* gpGameDataTbl_6FD45818;                                                         // 0x00883D38
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
int gbD2ServerCallbackFunctionsInitialized_6FD45834;                                                        // 0x00883D54
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
int gnGamesGUIDs_6FD447F8[1024];                                                                            // 0x00882D38
extern int nInitSeed_6FDC2CA08;                                                                             // 0x00731004
int dword_6FD4581C;                                                                                         // 0x00883D3C
int dword_6FD45820;                                                                                         // 0x00883D40
int gnPeakMemoryUsageInLast10s_6FD45828;                                                                    // 0x00883D48
extern int gnTargetFrameRate_6FD2CA60;                                                                      // 0x00731014
extern int gnTargetMsPerFrame_6FD457F8;                                                                     // 0x00883D60
extern int gnAct_6FD45824;                                                                                  // 0x00883D44

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

// 0x0052C0A0
void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList)
{
    D2_ASSERT(pGameDataTbl, 347);

    gpGameDataTbl_6FD45818 = pGameDataTbl;

    D2_ASSERT(pGameList, 349);
}

// 0x0052C0E0
void __stdcall GAME_SetServerCallbackFunctions(D2ServerCallbackFunctions* pD2ServerCallbackFunctions)
{
    if (pD2ServerCallbackFunctions)
    {
        gpD2EventCallbackTable_6FD45830 = pD2ServerCallbackFunctions;
        gbD2ServerCallbackFunctionsInitialized_6FD45834 = 1;
    }
    else
    {
        gpD2EventCallbackTable_6FD45830 = 0;
        gbD2ServerCallbackFunctionsInitialized_6FD45834 = 0;
    }
}

// 0x0052C110
void __stdcall sub_0052C110(int nGameGUID, unsigned short nGameId)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] == D2GameReservedSlotHandle)
    {
        gnGamesGUIDs_6FD447F8[nGameId - 1] = nGameGUID;
        LeaveCriticalSection(&gCriticalSection_6FD45800);
        return;
    }

    D2_ASSERT(0, 394);
}

// 0x0052C320
void __stdcall GAME_SetInitSeed(int nInitSeed)
{
    nInitSeed_6FDC2CA08 = nInitSeed;
}

// 0x0052C3E0
void __stdcall D2Game_10056(int a1)
{
    dword_6FD4581C = a1;
    dword_6FD45820 = 0;
}

// 0x0052C400
void __fastcall sub_0052C400_UpdatePing(int nClientId, int a2, int a3, int a4)
{
    CLIENTS_UpdatePing(nClientId, a2, a3, a4);
}

// 0x0052C570
int __fastcall sub_0052C570_RemoveClientFromGame(D2GameStrc* pGame, int nClientId, int a3, int a4)
{
    if (pGame && sub_005381C0(pGame, nClientId))
    {
        ClientRemoveFromGame(pGame, nClientId, 1);
    }

    return sub_0052B4F0(nClientId, a3, a4);
}

// 0x0052D240
void __stdcall sub_0052D240(D2GameStrc* pGame)
{
    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            D2ActiveRoomStrc* pNextRoom = 0;
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pNextRoom)
            {
                pNextRoom = pRoom->pRoomNext;
                if (D2Common_10081_GetTileCountFromRoom(pRoom) > 10 && DUNGEON_TestRoomCanUnTile(pGame->pAct[i], pRoom))
                {
                    D2UnitStrc* pNextUnit = 0;
                    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
                    {
                        pNextUnit = pUnit->ptRoomNext;
                        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
                    }

                    DUNGEON_RemoveRoomFromAct(pGame->pAct[i], pRoom);
                }
            }
        }
    }
}

// 0x0052DBA0
void __stdcall GAME_GetMemoryUsage(int* pCurrentMemoryUsage, int* pPeakMemoryUsageInLast10s)
{
    *pCurrentMemoryUsage = sub_0040A040_GetPoolSystemCount(0);
    *pPeakMemoryUsageInLast10s = gnPeakMemoryUsageInLast10s_6FD45828;
}

// 0x0052DC00
int __stdcall sub_0052DC00_PassThrough(int a1)
{
    return a1;
}

// 0x0052DED0
void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext)
{
    D2_ASSERT(pGame, 5496);
    D2_ASSERT(!IsBadCodePtr((FARPROC)pFn), 5497);

    for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
    {
        if (pClient->dwClientState == CLIENTSTATE_INGAME)
        {
            pFn(pClient, pContext);
        }
    }
}

// 0x0052DF80
void __stdcall sub_0052DF80(int a1)
{
    gnTargetFrameRate_6FD2CA60 = a1;
    gnTargetMsPerFrame_6FD457F8 = 1000 / a1;
}

// 0x0052DFA0
void __stdcall GAME_SetGlobalAct(int nAct)
{
    gnAct_6FD45824 = nAct;
}

// 0x0052E0A0
void D2GameDataTableStrc::SyncEnterLock(int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&f_50);
    *pLockHandle = bForWriting ? 1 : -1;
}

// 0x0052E0D0
int __stdcall sub_0052E0D0_IsOne(int nValue)
{
    return nValue == 1;
}

// 0x0052E470
void D2GameDataTableStrc::SyncLeaveLock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E510
D2GameStrc* D2GameListStrc::RawNext(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    return pLink->pNext;
}

// 0x0052E530
D2GameStrc* D2GameListStrc::Next(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    D2GameStrc* pNext = pLink->pNext;
    return (int)pNext > 0 ? pNext : 0;
}

// 0x0052E570
void D2GameDataTableStrc::Unlock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E590
void D2GameDataTableStrc::sub_0052E590(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5B0
void D2GameDataTableStrc::sub_0052E5B0(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5D0
void D2GameDataTableStrc::DeleteUnlock(D2GameStrc* pGame, int nLockHandle)
{
    Unlink(pGame);
    InternalDelete(pGame);
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E6B0
D2GameStrc* D2GameDataTableStrc::sub_0052E6B0(unsigned int nHashValue)
{
    return Ptr(nHashValue, &f_44);
}

// 0x0052E710
D2GameStrc* D2GameDataTableStrc::Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&f_50);
    *pLockHandle = bForWriting ? 1 : -1;
    D2GameStrc* pGame = Ptr(nHashValue, &f_44);
    if (!pGame)
    {
        if (*pLockHandle)
        {
            LeaveCriticalSection(&f_50);
        }
        *pLockHandle = 0;
    }
    return pGame;
}

// 0x0052EB50
void __stdcall sub_0052EB50(short* pCount, int nArraySize)
{
    memset(pCount, 0, 2 * nArraySize + 2);

    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGuid = gnGamesGUIDs_6FD447F8[i];
        if (nGameGuid && nGameGuid != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGameGuid);
            if (ptGame)
            {
                int nIndex = ptGame->nClients;
                D2_ASSERT(ptGame->lpCriticalSection, 4196);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                if (nIndex > nArraySize)
                {
                    nIndex = nArraySize;
                }

                ++pCount[nIndex];
            }
        }
    }
}

// 0x0052EC90
int __stdcall sub_0052EC90(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2_ASSERT(pGame, 4806);
    const int nClients = pGame->nClients;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nClients;
}

// 0x0052EF70
int __stdcall GAME_GetGameServerGameIds(unsigned short* pServerToken, int nMaxCount)
{
    int nServerTokenCount = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (nServerTokenCount >= nMaxCount)
        {
            break;
        }

        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            if (pGame)
            {
                pServerToken[nServerTokenCount] = pGame->nGameId;
                ++nServerTokenCount;
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nServerTokenCount;
}

// 0x0052F720
unsigned long __stdcall sub_0052F720_MessageThreadProc(D2MessageThreadArgsStrc* pArgs)
{
    GAME_SendMessageToAllClients(pArgs->nParam1, pArgs->nParam2, pArgs->szMessage);
    return 1;
}

// 0x0052F740
void __fastcall sub_0052F740_SendMessageToAllClientsAsync(int a1, int nPacketParam, const char* szMessage)
{
    unsigned long nThreadId;
    D2MessageThreadArgsStrc* pArgs = (D2MessageThreadArgsStrc*)FOG_AllocPool(0, sizeof(D2MessageThreadArgsStrc), ".\\GAME\\Game.cpp", 5665, 0);
    if (pArgs)
    {
        pArgs->nParam1 = a1;
        pArgs->nParam2 = nPacketParam;
        strncpy(pArgs->szMessage, szMessage, 0xFF);
        pArgs->szMessage[0xFF] = 0;
        CreateThread(0, 0, sub_0052F720_MessageThreadProc, pArgs, 0, &nThreadId);
    }
}

// 0x0052F7B0
int __fastcall GAME_FindGameWithName(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGameGUID)
        {
            D2GameStrc* pGame = GAME_LockGame(nGameGUID);
            if (pGame)
            {
                if (!SStrCmpI(pGame->szGameName, szGameName, 0x7FFFFFFF))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 4196);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return nGameGUID;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 0;
}

// 0x005300F0
int __stdcall sub_005300F0_RemoveClientById(int nClientId, int a2, int a3)
{
    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (pGame)
    {
        if (!sub_005381C0(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            if (sub_005381C0(pGame, nClientId))
            {
                ClientRemoveFromGame(pGame, nClientId, 1);
            }

            D2_ASSERT(pGame->lpCriticalSection, 4196);
            LeaveCriticalSection(pGame->lpCriticalSection);
        }
    }
    return sub_0052B4F0(nClientId, a2, a3);
}

// 0x005302D0
int __stdcall GAME_DisconnectClientByName(const char* szClientName, int nEventType)
{
    const int nClientId = CLIENTS_GetClientIdByName(szClientName);
    if (!nClientId)
    {
        return 0;
    }

    SrvDisconnectClientById(nClientId, nEventType);
    return 1;
}

#include "gen/data/Source/D2Game/GAME/Game_0052C0A0.inc"
