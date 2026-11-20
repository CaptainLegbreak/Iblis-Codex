#include "D2Game.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
struct D2ServerCallbackFunctions;
struct D2GameStatisticsStrc;
struct D2UnitInfoStrc;
struct D2UnitDescriptionListStrc;
struct D2StormLinkStrc;
struct D2StormListAStrc;
struct D2StormListArrayStrc;
struct D2StormHashNodeStrc;
struct D2StormHashTableStrc;
struct HASHKEY_NONE;
struct D2GameHashLinkStrc;
struct D2GameHashListStrc;
struct D2GameDataTableStrc;


struct D2ActiveRoomStrc
{
    char unk0x0000[0x34];
    unsigned int dwFlags;
    unsigned char unk_38[0x3C];
    D2UnitStrc* pUnitFirst;
    unsigned char unk_78[0x4];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2GameStrc
{
    unsigned int f_0;
    unsigned char unk_04[0x14];
    D2CriticalSectionStrc* lpCriticalSection;
    D2PoolSystemStrc* pMemoryPool;
    char unk0x0020[0x8];
    unsigned short nGameId;
    unsigned char unk_2A[0x46];
    int bExpansion;
    char f_74[0x8];
    unsigned int dwInitSeed;
    unsigned char unk_80[0x8];
    D2ClientStrc* pClientList;
    char unk0x008C[0x1C];
    int dwGameFrame;
    unsigned int nFrameRate;
    unsigned int nFramesSinceLastFrameRateUpdate;
    unsigned int nPreviousUpdateTickCount;
    char unk0x00B8[0x4];
    D2DrlgActStrc* pAct[5];
    unsigned char unk_D0[0x1050];
    D2UnitStrc* pUnitList[5][128];
    unsigned char unk_1B20[0x2A8];
    int nDebugBreakTrigger;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005433F0
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00552610
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x005559A0
int __cdecl sub_005377B0(); // 0x005377B0

struct D2DrlgActStrc
{
    char unk0x0000[0x54];
    int bHasPendingRoomsUpdates;
};
void __stdcall sub_0061AA20(D2DrlgActStrc* pAct); // 0x0061AA20

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    char unk0x0008[0x2];
    unsigned short nSaveFlags;
    char unk0x000C[0x1];
    char szName[16];
    char unk0x001D[0x197];
    D2ActiveRoomStrc* pRoom;
    char unk0x01B8[0x2F0];
    D2ClientStrc* pNext;
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

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern int gnFrameRate_00731010; // 0x00731010
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...); // 0x0052BE20
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0052C410
void __fastcall sub_0052CA10(D2GameStrc* pGame); // 0x0052CA10
void __stdcall sub_0052D240(D2GameStrc* pGame); // 0x0052D240
void __stdcall sub_0052D350_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected); // 0x0052D350
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame); // 0x0052D7B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall CLIENTS_SynchronizePlayer(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x005380D0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState); // 0x005386D0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0
void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame); // 0x0053A820
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame); // 0x0053B000
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader); // 0x0053B320
unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame); // 0x0053FCA0
void __fastcall EVENT_IterateEvents(D2GameStrc* pGame); // 0x005414D0
void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct); // 0x00542AC0
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame); // 0x00543E10
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054F060
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct); // 0x00558B90
void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B620
int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom); // 0x0061A460
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

struct D2CriticalSectionStrc
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

struct D2GameStatisticsStrc
{
    int nGamesCount;
    int nActiveMonsters;
    int nInactiveMonsters;
    int nPlayersCount;
};

struct D2UnitInfoStrc
{
    char unk0x00[0x24];
    char szDescription[0x10];
};

typedef void (__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pUnitInfo); // 0x00553F30
extern UnitDescriptionFunction gpfGetDescription_6FD2CA64[5]; // 0x0073107C
extern int gnGamesGUIDs_6FD447F8[1024]; // 0x00882D38

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszGameSourceFile; // 0x006D5D1C
extern D2CriticalSectionStrc gCriticalSection_6FD45800; // 0x00882D18
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void LinkToTail(char* pNode)
    {
        LinkNode(pNode, 2, 0);
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    void sub_00450110_SetCount(unsigned int nCount);                                                        // 0x00450110
};

struct D2StormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(char* pNode);                                                               // 0x004503F0
    virtual void sub_00450420_VirtSlot1();                                                                  // 0x00450420
    virtual void sub_00450550_VirtSlot2();                                                                  // 0x00450550
    virtual void sub_00450520_VirtSlot3();                                                                  // 0x00450520
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0052FF20_GrowListArray();
};

struct D2GameHashLinkStrc
{
    D2GameHashLinkStrc* m_prevlink;
    D2GameStrc* m_next;

    D2GameHashLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
        {
            return (D2GameHashLinkStrc*)~(int)m_next;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (char*)this - (char*)m_prevlink->m_next;
        }
        return (D2GameHashLinkStrc*)((char*)m_next + nLinkOffset);
    }

    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2GameHashListStrc
{
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
};

struct D2GameDataTableStrc
{
    virtual void sub_Destroy();
    virtual D2GameStrc* sub_NewNode(D2GameHashListStrc* pList, int nExtraBytes, int nFlags);

    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
    unsigned int m_fullnessIndicator;
    unsigned int f_14;
    unsigned int f_18;
    D2GameHashListStrc* m_slotlistarray;
    unsigned int f_20;
    unsigned int m_hashmask;

    int sub_00530600(unsigned int nSlot);                                                   // 0x00530600
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);
};

// 0x0052D090
static __forceinline void sub_0052D090_CompressRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pNextUnit = 0;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
    {
        pNextUnit = pUnit->pRoomNext;
        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
    }
}

// 0x0052D0C0
static __forceinline void GAME_PopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
    OBJECTS_PopulationHandler(pGame, pRoom);
    D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
}

// 0x0052D2E0
static __forceinline void sub_0052D2E0_RefreshActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i])
        {
            sub_0061AA20(pGame->pAct[i]);
        }
    }
}

// 0x0052DAD0
void __cdecl sub_0052DAD0_AssertFail()
{
    D2_ASSERT(0, 0x1165);
}

// 0x0052DB80
int __cdecl sub_0052DB80_CountFlaggedClients()
{
    return sub_005377B0();
}

void __fastcall sub_M118_Emit_0052D000(D2GameStrc* pGame, int nAct)
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); pRoom; pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct + 1]))
    {
        if (D2Common_10074(pRoom))
        {
            GAME_PopulateRoom(pGame, pRoom);
        }
        else
        {
            sub_0052D090_CompressRoomUnits(pGame, pRoom);
        }
    }
    sub_0052D2E0_RefreshActs(pGame);
}

static unsigned int gnPeakMemoryUsage_00883D48; // 0x00883D48

static unsigned int gnPreviousMemUsageTick_00883D68; // 0x00883D68

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
            CLIENTS_SynchronizePlayer(pGame, pClient);

            if (D2Common_10073(pClient->pRoom) && CLIENTS_GetPlayerFromClient(pClient, 0))
            {
                GAME_LogMessage(6, "[JOIN 6] %d clientid, sUpdateClients: SCMD_STARTACT - Player(%s)", pClient->dwClientId, pClient->szName);
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 0, 1);
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
            CLIENTS_SynchronizePlayer(pGame, pClient);
            break;
        }
        case 5:
        {
            CLIENTS_SynchronizePlayer(pGame, pClient);

            if (D2Common_10073(pClient->pRoom))
            {
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 0, 1);
                }
            }
            break;
        }
        }

        pClient = pNext;
    }
}

static __declspec(noinline) void sub_0052D720_UpdateFrameRate(D2GameStrc* pGame)
{
    const unsigned int nTickCount = GetTickCount();
    const unsigned int nTickDiff = nTickCount - pGame->nPreviousUpdateTickCount;
    if (nTickDiff >= 1000)
    {
        const unsigned int nFrames = pGame->nFramesSinceLastFrameRateUpdate;
        pGame->nFramesSinceLastFrameRateUpdate = 0;
        pGame->nPreviousUpdateTickCount = nTickCount;
        pGame->nFrameRate = 1000 * nFrames / nTickDiff;
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
                sub_0061AA20(pGame->pAct[i]);
            }
        }
    }

    sub_0052D310_DeleteInactiveItems(pGame);
}

D2CriticalSectionStrc gCriticalSection_6FD45800; // 0x00882D18

D2GameStrc* gpGame_6FD457FC; // 0x00882D34

// 0x0052EAE0
int __stdcall sub_0052EAE0()
{
    int nExpansionGames = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                if (pGame->bExpansion)
                {
                    ++nExpansionGames;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nExpansionGames;
}

// 0x0052F2C0
int __stdcall sub_0052F2C0(unsigned short nGameId, int nMaxCount, D2UnitInfoStrc* pUnitInfo, int* pUnitType, int* pUnitGUID)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nUnitInfoCount = 0;
    if (!pGame)
    {
        return 0;
    }

    {
        for (int i = 0; i < nMaxCount; ++i)
        {
            D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, pUnitType[i], pUnitGUID[i]);
            if (pUnit)
            {
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nUnitInfoCount]);

                if (pUnitType[i])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[pUnitType[i]]), 0x1472);
                    gpfGetDescription_6FD2CA64[pUnitType[i]](pUnitInfo[nUnitInfoCount].szDescription, pUnit->dwClassId);
                }

                ++nUnitInfoCount;
            }
        }

        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }

    return nUnitInfoCount;
}

// 0x0052F3E0
void __stdcall GAME_GetStatistics(D2GameStatisticsStrc* pStats)
{
    pStats->nGamesCount = 0;
    pStats->nActiveMonsters = 0;
    pStats->nInactiveMonsters = 0;
    pStats->nPlayersCount = 0;

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (D2UnitStrc* k = pGame->pUnitList[UNIT_MONSTER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nActiveMonsters;
                    }

                    for (D2UnitStrc* k = pGame->pUnitList[UNIT_PLAYER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nPlayersCount;
                    }
                }

                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);

                ++pStats->nGamesCount;
            }
        }
    }
}

// 0x0052F840
unsigned int __fastcall sub_0052F840()
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (*gnGamesGUIDs_6FD447F8 && *gnGamesGUIDs_6FD447F8 != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs_6FD447F8;
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    gpGame_6FD457FC = pGame;
    if (!pGame)
    {
        return 0;
    }

    const unsigned int nInitSeed = pGame->dwInitSeed;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nInitSeed;
}

#include "gen/data/Source/D2Game/GAME/Game_0052D090.inc"

// 0x0052DC20
static void __stdcall sub_0052DC20_AddUnitDescription(D2UnitDescriptionListStrc* pList, int bCount, int nClassId)
{
    D2UnitDescriptionListStrc* pHead = pList;
    D2_ASSERT(pList, 0x139E);
    do
    {
        if (pList->nClassId == nClassId)
        {
            if (bCount)
            {
                ++pList->nCount;
            }
            else
            {
                ++pList->nDefaultCount;
            }
            return;
        }
        pList = pList->pNext;
    }
    while (pList);

    D2UnitDescriptionListStrc* pNew = (D2UnitDescriptionListStrc*)sub_0040B430(0, sizeof(D2UnitDescriptionListStrc), &gszGameSourceFile, 0x13AF, 0);
    if (pNew)
    {
        memset(pNew, 0, sizeof(D2UnitDescriptionListStrc));
        pNew->nClassId = nClassId;
        pNew->nCount = 0;
        pNew->nDefaultCount = 0;
        if (bCount)
        {
            pNew->nCount = 1;
        }
        else
        {
            pNew->nDefaultCount = 1;
        }
        pNew->pNext = pHead->pNext;
        pHead->pNext = pNew;
    }
}

// 0x0052F160
void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2UnitStrc** pUnitList = 0;
    if (pGame)
    {
        switch (eType)
        {
        case 0:
            pUnitList = pGame->pUnitList[0];
            break;
        case 1:
            pUnitList = pGame->pUnitList[1];
            break;
        case 2:
            pUnitList = pGame->pUnitList[2];
            break;
        case 3:
            pUnitList = pGame->pUnitList[3];
            break;
        case 4:
            pUnitList = pGame->pUnitList[4];
            break;
        }

        D2UnitDescriptionListStrc* pList = pUnitDescriptionsList;
        for (int i = 0; i < 128; ++i)
        {
            for (D2UnitStrc* pUnit = pUnitList[i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                const int v_dwClassId_147 = pUnit ? pUnit->dwClassId : -1;
                sub_0052DC20_AddUnitDescription(pList, 1, v_dwClassId_147);
            }
        }

        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);

        const unsigned int nType = eType;
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[nType]), 0x1450);
        for (D2UnitDescriptionListStrc* pNode = pList->pNext; pNode; pNode = pNode->pNext)
        {
            gpfGetDescription_6FD2CA64[nType](pNode->szDescription, pNode->nClassId);
        }
    }
}

// 0x0052FF20
void D2StormHashTableStrc::sub_0052FF20_GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormListAStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.sub_00450110_SetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.f_8[((D2StormHashNodeStrc*)pNode)->f_0 & m_slotmask].LinkToTail(pNode);
}

// 0x00530820
D2GameStrc* D2GameDataTableStrc::sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_hashmask;
    if (sub_00530600(nSlot))
    {
        nSlot = nHashVal & m_hashmask;
    }

    D2GameHashListStrc* pList = &m_slotlistarray[nSlot];
    D2GameStrc* pNode = sub_NewNode(pList, nExtraBytes, nFlags);

    D2GameHashLinkStrc* pLink;
    if (pNode)
    {
        pLink = (D2GameHashLinkStrc*)((char*)pNode + m_linkoffset);
    }
    else
    {
        pLink = &m_terminator;
    }

    pLink->Unlink();

    D2GameHashLinkStrc* pPrev = m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = pNode;
    m_terminator.m_prevlink = pLink;

    pNode->f_0 = nHashVal;
    return pNode;
}
