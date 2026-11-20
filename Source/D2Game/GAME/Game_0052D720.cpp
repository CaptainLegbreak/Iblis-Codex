#include "D2Structs.h"
struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2PoolSystemStrc;
struct D2UnitStrc;

struct D2DrlgActStrc
{
    char unk0x0000[0x54];
    int bHasPendingRoomsUpdates;
};

struct D2ActiveRoomStrc
{
    char unk0x0000[0x34];
    unsigned int dwFlags;
    char unk0x0038[0x44];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    char unk0x0008[0x2];
    unsigned short nSaveFlags;
    char unk0x000C[0x1];
    char szName[16];
    char unk0x001D[0x197];
    D2ActiveRoomStrc* hRoom;
    char unk0x01B8[0x2F0];
    D2ClientStrc* pNext;
};


struct D2GameStrc
{
    char unk0x0000[0x1C];
    D2PoolSystemStrc* pMemoryPool;
    char unk0x0020[0x8];
    unsigned short nGameId;
    char unk0x002A[0x5E];
    D2ClientStrc* pClientList;
    char unk0x008C[0x1C];
    int dwGameFrame;
    unsigned int nFrameRate;
    unsigned int nFramesSinceLastFrameRateUpdate;
    unsigned int nPreviousUpdateTickCount;
    char unk0x00B8[0x4];
    D2DrlgActStrc* pAct[5];
    char unk0x00D0[0x1CF8];
    int nDebugBreakTrigger;
};

typedef void (__fastcall* D2EnterGameFn)(int nGameId, char* szName, int nClass, int nLevel, int nSaveFlags);

struct D2ServerCallbackFunctions
{
    char unk0x0000[0x14];
    D2EnterGameFn pfEnterGame;
};

#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    int dwParam;
    unsigned char nParam;
    char szText[32];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260
#include "gen/data/Source/D2Game/GAME/Game_0052D720.static/gnFrameRate_00731010.inc"
static unsigned int gnPeakMemoryUsage_00883D48;                                                                  // 0x00883D48
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
static unsigned int gnPreviousMemUsageTick_00883D68;                                                            // 0x00883D68

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                              // 0x0040B380
int __cdecl sub_0040A040_GetPoolSystemCount(D2PoolSystemStrc* pSystem);                                     // 0x0040A040
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient);               // 0x0052C410
void __fastcall sub_0052CA10(D2GameStrc* pGame);                                                          // 0x0052CA10
void __stdcall sub_0052D240(D2GameStrc* pGame);                                                         // 0x0052D240
void __stdcall sub_0052D350_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected);                  // 0x0052D350
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame);                                                  // 0x0052D7B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                // 0x00537860
void __fastcall sub_6FC33670(D2GameStrc* pGame, D2ClientStrc* pClient);                       // 0x005380D0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                           // 0x005386D0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer);                    // 0x005392F0
void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame);                                                   // 0x0053A820
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame);                                                  // 0x0053B000
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);         // 0x0053B320
unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame);                                         // 0x0053FCA0
void __fastcall EVENT_IterateEvents(D2GameStrc* pGame);                                                     // 0x005414D0
void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct);                         // 0x00542AC0
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);            // 0x00542B40
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame);                                                     // 0x00543E10
void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                 // 0x0054AA40
void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x0054EC90
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);        // 0x0054F060
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                     // 0x00552610
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x005559A0
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct);                                     // 0x00558B90
void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer);              // 0x0055B620
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                   // 0x0061A180
int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A460
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet);                                           // 0x0061A510
void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct);                                                           // 0x0061AA20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480

// 0x0052D160
static __declspec(noinline) void sub_0052D160_UpdatePendingRooms(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0xC60);

    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && pGame->pAct[i]->bHasPendingRoomsUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pRoom->pRoomNext)
            {
                MONSTERREGION_TrySpawnWanderingMonster(pGame, pRoom);

                if (!(pRoom->dwFlags & 1))
                {
                    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    OBJECTS_PopulationHandler(pGame, pRoom);
                    D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
                    pRoom->dwFlags |= 1;
                    D2Common_10075(pRoom, 1);
                }
                else if (!D2Common_10074(pRoom))
                {
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    D2Common_10075(pRoom, 1);
                }
            }

            pGame->pAct[i]->bHasPendingRoomsUpdates = 0;
        }
    }
}

// 0x0052D310
static __declspec(noinline) void sub_0052D310_DeleteInactiveItems(D2GameStrc* pGame)
{
    if (!(pGame->dwGameFrame % 1500))
    {
        for (int i = 0; i < 5; ++i)
        {
            ITEMS_DeleteInactiveItems(pGame, i);
            SUNITINACTIVE_DeleteExpiredItemNodes(pGame, i);
        }
    }
}

// 0x0052D440
static __declspec(noinline) void sub_0052D440_UpdateAllClients(D2GameStrc* pGame)
{
    {
        int bUpdateLadder = 0;
        int bPlayerDisconnected = 0;

        if (!(pGame->dwGameFrame % 8192))
        {
            bUpdateLadder = 1;
        }

        D2_ASSERT(ARENA_NeedsClientUpdate(pGame), 0xD31);

        sub_0052D350_CheckClientHeartbeats(pGame, &bPlayerDisconnected);

        if (bUpdateLadder && !bPlayerDisconnected)
        {
            sub_0052CA10(pGame);
        }
    }

    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;

        switch (pClient->dwClientState)
        {
        case 3:
        {
            sub_6FC33670(pGame, pClient);

            if (D2Common_10073(pClient->hRoom) && CLIENTS_GetPlayerFromClient(pClient, 0))
            {
                GAME_LogMessage(6, "[JOIN 6] %d clientid, sUpdateClients: SCMD_STARTACT - Player(%s)", pClient->dwClientId, pClient->szName);
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    sub_0055DF00_RecalcItemStates(pGame, pPlayer, 0, 1);
                }

                GAME_SynchronizePlayerWithClients(pGame, pClient);
                PLAYERLIST_InitializePlayerRelations(pGame, CLIENTS_GetPlayerFromClient(pClient, 1));

                if (gpD2EventCallbackTable_6FD45830)
                {
                    pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                    if (pPlayer && gpD2EventCallbackTable_6FD45830->pfEnterGame)
                    {
                        const int nClassId = pPlayer->dwClassId;
                        gpD2EventCallbackTable_6FD45830->pfEnterGame(pGame->nGameId, pClient->szName, nClassId, STATLIST_UnitGetStatValue(pPlayer, 12, 0), pClient->nSaveFlags);
                    }
                }

                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 2;
                packet5A.nColor = 4;
                packet5A.dwParam = 0;
                packet5A.szText[16] = '\0';

                char szAccountName[256];
                CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
                if (strlen(szAccountName) != 0)
                {
                    SStrCopy(&packet5A.szText[16], szAccountName, 16);
                    packet5A.szText[31] = '\0';
                }

                SStrCopy(packet5A.szText, pClient->szName, 16);
                sub_6FC84D40(pGame, &packet5A);
            }
            break;
        }
        case 4:
        {
            sub_6FC33670(pGame, pClient);
            break;
        }
        case 5:
        {
            sub_6FC33670(pGame, pClient);

            if (D2Common_10073(pClient->hRoom))
            {
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    sub_0055DF00_RecalcItemStates(pGame, pPlayer, 0, 1);
                }
            }
            break;
        }
        }

        pClient = pNext;
    }
}

// 0x0052D720
static __declspec(noinline) void sub_0052D720_UpdateFrameRate(D2GameStrc* pGame)
{
    const unsigned int nTickCount = GetTickCount();
    const unsigned int nTickDiff = nTickCount - pGame->nPreviousUpdateTickCount;
    if (nTickDiff >= 1000)
    {
        pGame->nFrameRate = 1000 * pGame->nFramesSinceLastFrameRateUpdate / nTickDiff;
        pGame->nFramesSinceLastFrameRateUpdate = 0;
        pGame->nPreviousUpdateTickCount = nTickCount;
        gnFrameRate_00731010 = pGame->nFrameRate;

        const unsigned int nMemoryUsage = sub_0040A040_GetPoolSystemCount(pGame->pMemoryPool);
        if (nTickCount - gnPreviousMemUsageTick_00883D68 > 10000)
        {
            gnPreviousMemUsageTick_00883D68 = nTickCount;
            gnPeakMemoryUsage_00883D48 = nMemoryUsage;
        }
        else if (nMemoryUsage > gnPeakMemoryUsage_00883D48)
        {
            gnPeakMemoryUsage_00883D48 = nMemoryUsage;
        }
    }

    ++pGame->nFramesSinceLastFrameRateUpdate;
}

// 0x0052D870
void __fastcall GAME_UpdateProgress(D2GameStrc* pGame)
{
    const int nDebugBreakTrigger = pGame->nDebugBreakTrigger;
    ++pGame->dwGameFrame;

    if (nDebugBreakTrigger == 1)
    {
        *((unsigned char*)0) = 0;
    }
    else if (nDebugBreakTrigger == 2)
    {
        *((unsigned char*)0xC0000001) = 0;
    }
    else if (nDebugBreakTrigger == 3)
    {
        D2_ASSERT(0, 0xE1C);
    }
    else if (nDebugBreakTrigger == 4)
    {
        FOG_Alloc(0x70000000, ".\\GAME\\Game.cpp", 0xE20, 0);
    }

    GAME_UpdateEnvironment(pGame);
    sub_0052D720_UpdateFrameRate(pGame);
    sub_0052D160_UpdatePendingRooms(pGame);
    EVENT_IterateEvents(pGame);
    sub_0052D440_UpdateAllClients(pGame);
    LEVEL_UpdateQueuedUnitsInAllActs(pGame);
    LEVEL_FreeDrlgDeletes(pGame);

    if (!(pGame->dwGameFrame % 20))
    {
        QUESTS_QuestUpdater(pGame);
    }

    if (!(pGame->dwGameFrame % 12))
    {
        sub_0052D240(pGame);
    }

    if (!(pGame->dwGameFrame % 11))
    {
        for (int i = 0; i < 5; ++i)
        {
            if (pGame->pAct[i])
            {
                DUNGEON_UpdateAndFreeInactiveRooms(pGame->pAct[i]);
            }
        }
    }

    sub_0052D310_DeleteInactiveItems(pGame);
}
