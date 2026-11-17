#include "D2Game.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                              // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ClientStrc
{
    char unk0x000[0x60];
    int nCharSaveTransactionToken;
    char unk0x064[0x12C];
    D2FileTimeStrc nSaveCreationTimestamp;
    char unk0x198[0x240];
    unsigned int dwLastPacketTick;
    char unk0x3DC[0xCC];
    D2ClientStrc* pNext;
    char unk0x4AC[0x54];
    unsigned int dwPingsCount;
    int unk0x504;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0x58];
    int dwGameType;
    char unk0x78[0x10];
    D2ClientStrc* pClientList;
    char unk0x8C[0x1C];
    int dwGameFrame;
};

typedef void (__fastcall* FnUpdateCharacterLadder)(const char* szCharName, int nClassId, int nLevel, unsigned __int64 nExperience, unsigned int nFlags, D2FileTimeStrc* pSaveCreationTimestamp);

struct D2ServerCallbackFunctions
{
    void* pfCallbacks[10];
    FnUpdateCharacterLadder pfUpdateCharacterLadder;
};

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

extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern int gbCheckHeartbeat_00730FFC;                                                                       // 0x00730FFC

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20
int __stdcall sub_0052B2D0_ObjectCallMode1(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0
int __stdcall sub_0052B2F0_ObjectCallMode0(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0
int __stdcall sub_0052B310_ObjectCallMode2(unsigned char* pBuffer, int nSize);                              // 0x0052B310
void __fastcall sub_6FC38140(void* pData, int nSize);                                                       // 0x0052CC20
void __fastcall GAME_DisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
int __stdcall sub_005300F0_RemoveClientById(int nClientId, const char* szFile, int nLine);                  // 0x005300F0
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned long dwArg); // 0x00532400
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                   // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __fastcall sub_6FC33EA0(int nClientId, char* szName);                                                   // 0x00538B70
int __fastcall sub_6FC33F90(const char* szName, char* szGameName);                                          // 0x00538C60
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient);                                                     // 0x00538640
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag);                              // 0x00538670
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7); // 0x00538CE0
void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBackgroundColor, unsigned char* pForegroundColor, unsigned char* pEmblemType); // 0x00539190
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, unsigned char nClientState);                  // 0x0053B320
int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize);                               // 0x0053EFC0
void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize);                                    // 0x0053F100
void __fastcall CCMD_ProcessClientMessage(void* pData, int nPacketSize);                                    // 0x0053F3D0
void __fastcall sub_6FC84CD0(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A9B0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x0052C330
int __fastcall GAME_VerifyCreateNewGame(int nClientId, D2GSPacketClt66* pPacket)
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
            CCMD_ProcessClientMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = sub_0052B310_ObjectCallMode2(buffer, 512);
        if (nSize != -1)
        {
            sub_6FC38140(buffer, nSize);
        }
    } while (nSize != -1);
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
        if (nTickCount > pClient->dwLastPacketTick && (bHardcore && nTickCount - pClient->dwLastPacketTick > 10000 && pClient->dwPingsCount > 10 || nTickCount - pClient->dwLastPacketTick > 45000 || pClient->unk0x504) && gpD2EventCallbackTable_6FD45830)
        {
            D2GAME_SAVE_WriteFile_6FC8A500(pGame, CLIENTS_GetPlayerFromClient(pClient, 0), CLIENTS_GetName(pClient), 0);
            *pbDisconnected = 1;
            GAME_DisconnectClient(pGame, pClient, 0);
        }
        pClient = pNext;
    }

    if (*pbDisconnected)
    {
        sub_0052CA10(pGame);
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
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                const int nSecondsPassed = pGame->dwGameFrame / 25;

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);

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

// 0x0052F4C0
void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            D2_ASSERT(pGame, 0x1063);
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
                sub_6FC84D40(pGame, &packet5A);
                break;
            }
            default:
                if (strlen(szMessage) > 255)
                {
                    char szCopy[256];
                    strncpy(szCopy, szMessage, 255);
                    szCopy[255] = '\0';
                    sub_6FC84CD0(pGame, szCopy, 1);
                }
                else
                {
                    sub_6FC84CD0(pGame, szMessage, 1);
                }
                break;
            }

            D2_ASSERT(pGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(pGame->lpCriticalSection);
        }
    }
}

// 0x005306E0
int __stdcall GAME_ReceiveDatabaseCharacter(int nClientId, const unsigned char* pSaveData, unsigned short nSaveSize, unsigned short nTotalSize, int nResult, int a6, D2FileTimeStrc* pSaveCreationTimestamp, int nCharSaveTransactionToken)
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
    CLIENTS_SetClientState(pClient, 2);
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

#include "gen/data/Source/D2Game/GAME/Game_0052C330.inc"
