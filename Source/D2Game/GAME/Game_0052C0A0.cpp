#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameClient.h"
#include "D2GameServer.h"
#include "D2Primitives.h"

struct D2ServerCallbackFunctions;

typedef int (__stdcall* FARPROC)();

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

D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                                 // 0x00883D50

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

struct D2ClientInfoStrc;

struct D2GameDataTableStrc;

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20

void __fastcall sub_6FC33910(D2ClientStrc* pClient);                                                        // 0x00538320

void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                            // 0x005386D0

D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9); // 0x00539A30

void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220

void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320

void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                              // 0x006CC260

struct D2GSPacketClt66
{
    unsigned char nHeader;
    char szGameName[16];
    unsigned char nGameType;
    unsigned char nPlayerClass;
    unsigned char nTemplate;
    unsigned char nDifficulty;
    char szClientName[16];
    unsigned char abArena[2];
    unsigned char abGameFlags[4];
    unsigned char unk0x2B;
    unsigned char unk0x2C;
    unsigned char nLocale;
};

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char abParam[4];
    unsigned char nParam;
    char szText[32];
};

extern int gbCheckHeartbeat_00730FFC;                                                                       // 0x00730FFC

int __stdcall sub_0052B2D0_ObjectCallMode1(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0

int __stdcall sub_0052B2F0_ObjectCallMode0(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0

int __stdcall sub_0052B310_ObjectCallMode2(unsigned char* pBuffer, int nSize);                              // 0x0052B310

void __fastcall sub_0052CC20_Statistics(void* pData, int nSize);                                                       // 0x0052CC20

void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0

int __stdcall sub_005300F0_RemoveClientById(int nClientId, const char* szFile, int nLine);                  // 0x005300F0

int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400

D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                   // 0x00537810

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860

int __fastcall sub_6FC33EA0(int nClientId, char* szName);                                                   // 0x00538B70

int __fastcall sub_6FC33F90(const char* szName, char* szGameName);                                          // 0x00538C60

int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient);                                                     // 0x00538640

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag);                              // 0x00538670

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830

int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7); // 0x00538CE0

void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBackgroundColor, unsigned char* pForegroundColor, unsigned char* pEmblemType); // 0x00539190

int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize);                               // 0x0053EFC0

void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize);                                    // 0x0053F100

void __fastcall ProcessClientMessage(void* pData, int nPacketSize);                                    // 0x0053F3D0

void __fastcall sub_6FC84CD0(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A9B0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __fastcall sub_0052C210_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                      // 0x0052C210

void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY);

int __fastcall sub_00539760(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY);

void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nReason);           // 0x0053B260

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

// 0x0052C260
static __declspec(noinline) void sub_0052C260_SendGameInit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
}

// 0x0052C330
int __fastcall SrvVerifyCreateNewGame(int nClientId, D2GSPacketClt66* pPacket)
{
    const char* szGameName = pPacket->szGameName;
    const unsigned char nPlayerClass = pPacket->nPlayerClass;
    const char* szClientName = pPacket->szClientName;
    const unsigned int nGameFlags = *(const unsigned int*)pPacket->abGameFlags;
    char szCurrentGame[16];

    if (gpD2EventCallbackTable_6FD45830 && pPacket->nGameType)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (pPacket->nLocale > 14u)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szGameName, 16))
    {
        return 0;
    }
    if (!(nGameFlags & 6))
    {
        return 0;
    }
    if (!sub_6FC33EA0(nClientId, szCurrentGame))
    {
        return 0;
    }
    if (!sub_6FC33F90(szClientName, szCurrentGame))
    {
        return 0;
    }
    return nPlayerClass < 7u;
}

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

// 0x0052CA10
void __fastcall sub_0052CA10(D2GameStrc* pGame)
{
    D2ClientStrc* i = pGame->pClientList;
    while (i)
    {
        D2ClientStrc* pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, 12, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, 13, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
        i = pNext;
    }
}

// 0x0052CFE0
void __fastcall GAME_ProcessNetworkMessages()
{
    unsigned char buffer[512];
    int nSize;

    do
    {
        nSize = sub_0052B2F0_ObjectCallMode0(buffer, 512);
        if (nSize != -1)
        {
            CCMD_ProcessClientSystemMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = sub_0052B2D0_ObjectCallMode1(buffer, 512);
        if (nSize != -1)
        {
            ProcessClientMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = sub_0052B310_ObjectCallMode2(buffer, 512);
        if (nSize != -1)
        {
            sub_0052CC20_Statistics(buffer, nSize);
        }
    } while (nSize != -1);
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

// 0x0052D350
void __stdcall sub_0052D350_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected)
{
    if (!gbCheckHeartbeat_00730FFC)
    {
        return;
    }

    *pbDisconnected = 0;
    const unsigned int nTickCount = GetTickCount();
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;
        const int bHardcore = CLIENTS_CheckFlag(pClient, 4);
        if (nTickCount > pClient->dwLastPacketTick && (bHardcore && nTickCount - pClient->dwLastPacketTick > 10000 && pClient->dwPingsCount > 10 || nTickCount - pClient->dwLastPacketTick > 45000 || pClient->dw504) && gpD2EventCallbackTable_6FD45830)
        {
            D2GAME_SAVE_WriteFile_6FC8A500(pGame, CLIENTS_GetPlayerFromClient(pClient, 0), CLIENTS_GetName(pClient), 0);
            *pbDisconnected = 1;
            SrvDisconnectClient(pGame, pClient, 0);
        }
        pClient = pNext;
    }

    if (*pbDisconnected)
    {
        sub_0052CA10(pGame);
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

// 0x0052EBE0
void __stdcall sub_0052EBE0(unsigned short* pCount, int nMaxCount)
{
    memset(pCount, 0, sizeof(*pCount) * nMaxCount);

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                const int nSecondsPassed = ptGame->dwGameFrame / 25;

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                int nIndex = nSecondsPassed / 300;
                if (nIndex >= nMaxCount)
                {
                    nIndex = nMaxCount - 1;
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

// 0x0052F4C0
void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            D2_ASSERT(ptGame, 0x1063);
            switch (a1)
            {
            case 1:
            {
                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 0x0F;
                packet5A.nColor = 4;
                *(int*)packet5A.abParam = nPacketParam;
                packet5A.szText[16] = 0;
                sub_6FC84D40(ptGame, &packet5A);
                break;
            }
            default:
                if (strlen(szMessage) > 255)
                {
                    char szCopy[256];
                    strncpy(szCopy, szMessage, 255);
                    szCopy[255] = '\0';
                    sub_6FC84CD0(ptGame, szCopy, 1);
                }
                else
                {
                    sub_6FC84CD0(ptGame, szMessage, 1);
                }
                break;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);
        }
    }
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
    pClient->bAct = gnAct_6FD45824;
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

// 0x005306E0
int __stdcall SrvRecvDatabaseCharacter(int nClientId, const unsigned char* pSaveData, unsigned short nSaveSize, unsigned short nTotalSize, int nResult, int a6, D2FileTimeStrc* pSaveCreationTimestamp, int nCharSaveTransactionToken)
{
    GAME_LogMessage(6, "[JOIN 3] %d clientid, %d csresult - Recv'ed char from CS", nClientId, nResult);

    if (nTotalSize && !CLIENTS_AttachSaveFile(nClientId, pSaveData, nSaveSize, nTotalSize, nResult == 0, 1, a6))
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Didn't recv full char from db - CSResult(%d), ClientID(%d)", nResult, nClientId);
        return 1;
    }

    if (nResult)
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Did not recv CSDATA_SUCCESS - CSResult(%d), ClientID(%d)", nResult, nClientId);
        sub_005300F0_RemoveClientById(nClientId, ".\\GAME\\Game.cpp", 0x407);
        return 0;
    }

    if (!nTotalSize)
    {
        sub_005300F0_RemoveClientById(nClientId, ".\\GAME\\Game.cpp", 0x414);
        return 0;
    }

    D2GameStrc* pGame = sub_0052FEE0_LockGameByClientId(nClientId);
    if (!pGame)
    {
        return 0;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    if (!pClient)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return 0;
    }

    if (pClient->nCharSaveTransactionToken != nCharSaveTransactionToken)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        sub_005300F0_RemoveClientById(nClientId, ".\\GAME\\Game.cpp", 0x479);
        return 0;
    }

    pClient->nSaveCreationTimestamp = *pSaveCreationTimestamp;
    GAME_LeaveGamesCriticalSection(pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    return nTotalSize;
}

// 0x00530EA0
void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        switch (nStat)
        {
        case 14:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, 14, 0, 0);
                return;
            }
            break;
        case 15:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, 15, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

struct D2GameStrc;

struct D2UnitStrc;

#include "gen/data/Source/D2Game/GAME/Game_0052C0A0.inc"
