#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0x00
#define CLIENTS_MAX_UPDATES 55u




struct D2Act4Quest2Strc
{
    char unk0x000[0x1];
    unsigned char bTimerCreated;
    unsigned char bNeedToSpawnDiablo;
    unsigned char unk0x03;
    unsigned char bNeedToEndGame;
    unsigned char bNeedToWarpPlayers;
    unsigned char bDiabloStartPointInitialized;
    char unk0x007[0x1];
    int nDiabloStartPointObjectGUID;
    char unk0x00C[0x9];
    unsigned char bClientsSaved;
    char unk0x016[0x2];
    unsigned int dwTickCount;
    char unk0x01C[0x30];
};
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2PacketDataStrc
{
    int nPacketSize;
    unsigned char packetData[0x200];
    D2PacketDataStrc* pNext;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    char unk0x008[0x174];
    unsigned char* pSaveHeader;
    int nSaveHeaderSize;
    unsigned int nSaveHeaderSendDelay;
    int nSaveHeaderDataSentBytes;
    char unk0x18C[0x1C];
    D2GameStrc* pGame;
    char unk0x1AC[0x4];
    int nPlayerSyncCount;
    char unk0x1B4[0xC];
    D2PacketDataStrc* pPacketDataPool;
    int nSaveHeaderSendFailures;
    char unk0x1C8[0x2E0];
    D2ClientStrc* pNext;
};

#pragma pack(push, 1)
struct D2SavePartPacketStrc
{
    unsigned char nHeader;
    unsigned char nPartDataSize;
    unsigned char bFirstPart;
    int nSaveHeaderSize;
    unsigned char aData[0x100];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned int dwParam;
    unsigned char nParam;
    char szText[32];
};
#pragma pack(pop)

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerUnion* pCount);        // 0x006CC25C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260

extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern unsigned long gdwPlayerPos_00883D4C;                                                                 // 0x00883D4C
unsigned long dword_6FD45848;                                                                               // 0x00883D5C

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);              // 0x004135D0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
unsigned int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);          // 0x0052B330
int __cdecl sub_0052B910();                                                                                 // 0x0052B910
void __fastcall sub_0052CA10(D2GameStrc* pGame);                                                          // 0x0052CA10
void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                  // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* pClient, unsigned int nUpdateSize);            // 0x00537FD0
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId);                         // 0x005381C0
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient);                                                  // 0x00538590
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient);                                              // 0x00538F10
int __fastcall sub_00538FC0(D2ClientStrc* pClient);                                        // 0x00538FC0
unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* pClient);                                          // 0x00539030
void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);         // 0x00539270
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient);                         // 0x005392A0
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* pGame, D2ClientStrc* pClient);                   // 0x00530590
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer);                     // 0x005392F0
void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);           // 0x00539DA0
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);        // 0x0053B320
void __fastcall sub_0053E130_SendUnitUpdates(D2ClientStrc* pClient);                           // 0x0053E130
int __fastcall sub_6FC82360(D2UnitStrc* pUnit, D2UnitStrc* pUnit2, int bSkipHpCheck);                       // 0x00548760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __stdcall TASK_FreeAllQueueSlots();                                                                    // 0x00564890
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005B4A80
D2UnitStrc* __fastcall sub_005B4B60_SpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x0052D980
static void sub_0052D980_SyncPlayerStats(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    int bSkipHpCheck = 0;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (pPacketData && pClient->nPlayerSyncCount >= 10)
        {
            bSkipHpCheck = 1;
        }

        if (pClient->nPlayerSyncCount >= 20)
        {
            bSkipHpCheck = 1;
        }

        D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF05);

        if (sub_6FC82360(pPlayer, pPlayer, bSkipHpCheck))
        {
            pClient->nPlayerSyncCount = 0;
        }
    }
}

// 0x0052DA00
static void sub_0052DA00_RefreshUnitsUpdate(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    if (pPacketData)
    {
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pPlayer && pClient->nPlayerSyncCount >= 10)
        {
            D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF19);

            const int nUpdateSize = (499 - pPacketData->nPacketSize) / 9;
            if (nUpdateSize > 0)
            {
                D2_ASSERT(nUpdateSize <= CLIENTS_MAX_UPDATES, 0xF23);
                CLIENTS_RefreshUnitsUpdateList(pClient, nUpdateSize);
                sub_0053E130_SendUnitUpdates(pClient);
            }
        }
    }
}

// 0x0052E110
static void __stdcall GAME_SendSaveFilePart(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!sub_00538FC0(pClient))
    {
        return;
    }

    if (pClient->nSaveHeaderSendDelay)
    {
        --pClient->nSaveHeaderSendDelay;
        return;
    }

    const unsigned char* pSaveData = pClient->pSaveHeader;
    pClient->nSaveHeaderSendDelay = 5;
    if (!pSaveData)
    {
        return;
    }

    const unsigned char* pData = &pSaveData[pClient->nSaveHeaderDataSentBytes];
    int nDataSize = pClient->nSaveHeaderSize - pClient->nSaveHeaderDataSentBytes;
    if (nDataSize >= 255)
    {
        nDataSize = 255;
    }

    D2SavePartPacketStrc* pPacket = (D2SavePartPacketStrc*)sub_0040B430(pClient->pGame->pMemoryPool, sizeof(D2SavePartPacketStrc), ".\\GAME\\Game.cpp", 0x904, 0);
    pPacket->nHeader = 0xB3;
    pPacket->nPartDataSize = nDataSize;
    pPacket->bFirstPart = pClient->nSaveHeaderDataSentBytes == 0;
    pPacket->nSaveHeaderSize = pClient->nSaveHeaderSize;
    unsigned char* pPacketData = pPacket->aData;

    for (int i = 0; i < nDataSize; ++i)
    {
        *pPacketData++ = *pData++;
    }

    if (sub_0052B330(0, pClient->dwClientId, pPacket, nDataSize + 0x7))
    {
        pClient->nSaveHeaderDataSentBytes += nDataSize;

        if (pClient->nSaveHeaderDataSentBytes == pClient->nSaveHeaderSize)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        pClient->nSaveHeaderSendFailures = 0;
    }
    else
    {
        ++pClient->nSaveHeaderSendFailures;
    }

    sub_0040B480(pClient->pGame->pMemoryPool, pPacket, ".\\GAME\\Game.cpp", 0x92A, 0);

    if (pClient->nSaveHeaderSendFailures >= 3)
    {
        CLIENTS_FreeSaveHeader(pClient);
        SrvDisconnectClient(pGame, pClient, 0);
    }
}

// 0x0052E260
static void sub_0052E260_SendRemainingSaveParts(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        while (sub_00538FC0(pClient))
        {
            GAME_SendSaveFilePart(pGame, pClient);
        }
    }
}

// 0x0052E2A0
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        D2ClientStrc* pClient = pGame->pClientList;
        while (pClient)
        {
            D2ClientStrc* pNextClient = pClient->pNext;

            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pPlayer)
            {
                D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(pClient), 0);
                sub_0052E260_SendRemainingSaveParts(pGame, pClient);
            }

            pClient = pNextClient;
        }
    }
}

// 0x0052E320
static void __stdcall GAME_SendClientPackets(D2GameStrc* ptGame, int bSyncPlayer, D2ClientStrc* ptClient)
{
    D2_ASSERT(ptGame, 0xF37);
    D2_ASSERT(ptClient, 0xF38);

    if (bSyncPlayer && ptClient->dwClientState == CLIENTSTATE_INGAME)
    {
        if (gdwPlayerPos_00883D4C)
        {
            sub_0052DA00_RefreshUnitsUpdate(ptClient);
        }

        sub_0052D980_SyncPlayerStats(ptClient);
    }

    if (ptGame->nGameType == 1 || ptGame->nGameType == 2)
    {
        GAME_SendSaveFilePart(ptGame, ptClient);
    }

    int nCounter = 0;
    int bError = 0;
    do
    {
        D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_PopHead(ptClient);
        if (!pPacketData || !pPacketData->nPacketSize)
        {
            break;
        }

        if (sub_0052B330(1, ptClient->dwClientId, pPacketData->packetData, pPacketData->nPacketSize) > 0)
        {
            ++nCounter;
            pPacketData->nPacketSize = 0;
            pPacketData->pNext = ptClient->pPacketDataPool;
            ptClient->pPacketDataPool = pPacketData;
            ptClient->nSaveHeaderSendFailures = 0;
        }
        else
        {
            sub_0052B910();
            bError = 1;
            ++ptClient->nSaveHeaderSendFailures;
            CLIENTS_PacketDataList_Reset(ptClient, pPacketData);
            if (ptClient->nSaveHeaderSendFailures >= 3)
            {
                SrvDisconnectClient(ptGame, ptClient, 0);
                return;
            }
        }
    }
    while ((ptGame->nGameType != 1 && ptGame->nGameType != 2 || nCounter < 3) && !bError);
}

// 0x0052E440
void __fastcall GAME_SendAllClientPackets(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNextClient = pClient->pNext;
        GAME_SendClientPackets(pGame, 1, pClient);
        pClient = pNextClient;
    }
}

// 0x0052E9C0
void __stdcall GAME_CloseAllGames()
{
    TASK_FreeAllQueueSlots();

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGUID);
            D2_ASSERT(ptGame, 0x1206);

            D2ClientStrc* pClient = ptGame->pClientList;
            while (pClient)
            {
                D2ClientStrc* pNextClient = pClient->pNext;

                sub_0053B220_SendHeaderOnly0xB0(pClient->dwClientId);
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                D2GAME_SAVE_WriteFile_6FC8A500(ptGame, pPlayer, CLIENTS_GetName(pClient), 1);
                sub_0052E260_SendRemainingSaveParts(ptGame, pClient);
                sub_0053B240_SendHeaderOnly0x06(pClient->dwClientId);
                ClientRemoveFromGame(ptGame, pClient->dwClientId, 0);

                pClient = pNextClient;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);

            GAME_CloseGame(nGUID);
        }
    }
}

// 0x0052FD90
int __stdcall GAME_UpdateClients(int bForceUpdate1, int bForceUpdate2)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const unsigned long nTickCount = GetTickCount();
    if (!bForceUpdate1 && !bForceUpdate2)
    {
        if (nTickCount - dword_6FD45848 < 40)
        {
            return 0;
        }

        dword_6FD45848 = nTickCount;
    }

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(nGUID);
            if (pGame)
            {
                D2ClientStrc* pClient = pGame->pClientList;
                bQueryPerformance = 1;
                while (pClient)
                {
                    D2ClientStrc* pNextClient = pClient->pNext;
                    GAME_SendClientPackets(pGame, 1, pClient);
                    pClient = pNextClient;
                }

                if (!pGame->nClients)
                {
                    if (!pGame->nTickCountSinceNoClients)
                    {
                        pGame->nTickCountSinceNoClients = nTickCount;
                    }

                    if (nTickCount - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                        GAME_CloseGame(nGUID);
                    }
                    else
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                    }
                }
                else
                {
                    pGame->nTickCountSinceNoClients = 0;
                    GAME_LeaveGamesCriticalSection(pGame);
                }
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}

// 0x005303D0
void __fastcall SrvEndGame(int nClientId, int bSendLeaveMessage)
{
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
    const unsigned int bOwner = CLIENT_IsGameOwner(pClient);
    if (bOwner || pGame->nGameType)
    {
        sub_0052CA10(pGame);
    }

    if (pClient)
    {
        while (1)
        {
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 5);
            sub_0052E260_SendRemainingSaveParts(pGame, pClient);
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 6);
            sub_0053B220_SendHeaderOnly0xB0(nClientId);
            GAME_SendClientPackets(pGame, 0, pClient);

            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nType = 3;
            packet5A.nColor = 4;
            packet5A.dwParam = 0;
            CLIENTS_CopyAccountNameToBuffer(pClient, &packet5A.szText[16]);
            packet5A.szText[31] = '\0';
            SStrCopy(packet5A.szText, CLIENTS_GetName(pClient), 16);
            ClientRemoveFromGame(pGame, nClientId, !bOwner);

            if (bSendLeaveMessage)
            {
                sub_6FC84D40(pGame, &packet5A);
            }

            if (!bOwner)
            {
                break;
            }

            pClient = sub_00539070_GetClientList(pGame);
            if (!pClient)
            {
                break;
            }

            nClientId = CLIENTS_GetClientId(pClient);
        }
    }

    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);

    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        Sleep(100);
    }

    D2NET_10016(nClientId);
}
