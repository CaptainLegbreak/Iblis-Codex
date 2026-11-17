extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define NUM_ACTS 5
#define CLIENTSTATE_INGAME 4
#define D2GameReservedSlotHandle (-1)

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2UnitStrc;
struct D2DrlgActStrc;
struct D2PoolSystemStrc;
struct D2MonsterRegionStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x34];
    unsigned int dwFlags;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    char unk0x008[0x4A0];
    D2ClientStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    D2PoolSystemStrc* pMemoryPool;
    char unk0x20[0x68];
    D2ClientStrc* pClientList;
    char unk0x8C[0x30];
    D2DrlgActStrc* pAct[NUM_ACTS];
    char unk0xD0[0x20];
    D2MonsterRegionStrc* pMonReg[1024];
};

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                       // 0x00409C80
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);          // 0x0040B480
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, void* pUnit);                           // 0x0052DFB0
void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame);                                               // 0x00536640
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame);                                             // 0x00537AC0
void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame);                                                    // 0x0053AFD0
void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID);              // 0x0053CA90
void __fastcall ARENA_FreeArena(D2GameStrc* pGame);                                                         // 0x0053F500
void __fastcall PARTY_FreePartyControl(D2GameStrc* pGame);                                                  // 0x00540000
void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame);                                                    // 0x00541400
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);             // 0x00542B40
void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame);                                     // 0x00543080
void __fastcall QUESTS_QuestFree(D2GameStrc* pGame);                                                        // 0x00543800
void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* pGame);                                                // 0x00546E90
void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion);               // 0x00547B50
void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                   // 0x0054EC90
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);         // 0x0054F060
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                      // 0x00552610
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                   // 0x005559A0
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet);                                           // 0x0061A510
void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* pAct);                                                        // 0x0061AFD0

extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern D2GameStrc* gpGame_6FD457FC;                                                                         // 0x00882D34
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38

// 0x0052BE20
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...)
{
}

// 0x0052C060
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);
    return nGUID;
}

// 0x0052C500
void __fastcall GAME_SendPacket0x5CToAllConnectedClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
        {
            if (pClient->dwClientState == CLIENTSTATE_INGAME)
            {
                D2GAME_PACKETS_SendPacket0x5C_6FC3E090(pClient, sub_00451F50_GetUnitGUID(pPlayer));
            }
        }
    }
}

// 0x0052C7F0
void __fastcall GAME_FreeGame(int nGameGUID, D2GameStrc* pGame)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] == nGameGUID)
        {
            gnGamesGUIDs_6FD447F8[i] = 0;
        }
    }

    LeaveCriticalSection(&gCriticalSection_6FD45800);

    MONSTERREGION_FreeAll(pGame->pMemoryPool, pGame->pMonReg);
    OBJRGN_FreeObjectControl(pGame);
    QUESTS_QuestFree(pGame);
    SUNITPROXY_FreeNpcControl(pGame);
    CLIENTS_FreeClientsFromGame(pGame);
    LEVEL_RemoveAllUnits(pGame);
    SUNITINACTIVE_FreeInactiveUnitLists(pGame);
    EVENT_FreeEventQueue(pGame);
    PARTY_FreePartyControl(pGame);
    ARENA_FreeArena(pGame);

    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            DUNGEON_FreeAct(pGame->pAct[i]);
            pGame->pAct[i] = 0;
        }
    }

    if (pGame->pMemoryPool)
    {
        FOG_DestroyMemoryPoolSystem(pGame->pMemoryPool);
    }

    D2CriticalSectionStrc* pCriticalSection = pGame->lpCriticalSection;
    pGame->lpCriticalSection = 0;
    LeaveCriticalSection(pCriticalSection);
    DeleteCriticalSection(pCriticalSection);
    FOG_FreePool(0, pCriticalSection, ".\\GAME\\Game.cpp", 0x8DA, 0);
}

// 0x0052D0F0
void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
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
    else
    {
        if (!D2Common_10074(pRoom))
        {
            SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
            D2Common_10075(pRoom, 1);
        }
    }
}

// 0x0052DA90
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x1063);
    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);
}

// 0x0052DF40
void __fastcall GAME_UnlockDebugGame()
{
    GAME_LeaveGamesCriticalSection(gpGame_6FD457FC);
}

// 0x0052E050
void __fastcall GAME_RemoveUnit(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    GAME_ForEachIngameClient(pGame, GAME_SendUnitRemovalToClient, pUnit);
    SUNIT_RemoveUnit(pGame, pUnit);
}
