#include "D2Game.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

#pragma pack(push, 1)
struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    D2MessageListStrc tMessageList;
};
#pragma pack(pop)

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        struct
        {
            D2TextHeaderStrc* pTextControl;
            unsigned int dw18;
        };
        struct
        {
            int nNPCNo;
            int nMessageIndex;
        };
        struct
        {
            int nOldLevel;
            int nNewLevel;
        };
    };
};
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    char unk0x0B[0x95];
    QUESTCALLBACK pfCallback[15];
    char unk0xDC[0x18];
    D2QuestDataStrc* pPrev;
};

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
};

struct D2GameStrc
{
    char unk0x0000[0x1C];
    void* pMemoryPool;
    char unk0x0020[0x10D4];
    T005438E0* pQuestControl;
};

struct D2ItemsTxt
{
    char unk0x000[0x12A];
    unsigned char nQuest;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661480
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket);   // 0x0053C8D0
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient);                          // 0x00544520

// build: symbol ?QUESTS_EventCallback@@YGX_NEPAUD2QuestArgStrc@@@Z 0x005438E0
static void __stdcall QUESTS_EventCallback(bool bCheckActive, unsigned char bCheckAct, D2QuestArgStrc* pArgs)
{
    T005438E0* pQuestControl = pArgs->pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }
    unsigned char nAct = 0xFF;
    D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest;
    if (bCheckAct == 1)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pArgs->pPlayer);
        if (pRoom)
        {
            nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        }
    }
    while (pQuestData)
    {
        if (pQuestData->pfCallback[pArgs->nEvent] && (bCheckActive || pQuestData->bActive == 1) && (nAct == 0xFF || nAct == pQuestData->nActNo))
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfCallback[pArgs->nEvent]), 550);
            pQuestData->pfCallback[pArgs->nEvent](pQuestData, pArgs);
        }
        pQuestData = pQuestData->pPrev;
    }
}

void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nOldLevelId, int nTargetLevelId, D2UnitStrc* pUnit)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_CHANGEDLEVEL;
    tArgs.nOldLevel = nOldLevelId;
    tArgs.nNewLevel = nTargetLevelId;
    tArgs.pPlayer = pUnit;
    QUESTS_EventCallback(true, false, &tArgs);
}

static __forceinline D2QuestDataStrc* QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    T005438E0* pControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);
    if (!pControl)
    {
        return 0;
    }
    for (D2QuestDataStrc* pQuestData = pControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
        {
            return pQuestData;
        }
    }
    return 0;
}

static __forceinline int QUESTS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00543BD0
void __fastcall QUESTS_PlayerDroppedWithQuestItem(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2QuestArgStrc tArgs;
    tArgs.pPlayer = pPlayer;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM;
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pUnit = INVENTORY_UnitIsItem(pItem);
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(QUESTS_GetClassIdInline(pUnit));
        if (pItemsTxtRecord && pItemsTxtRecord->nQuest)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, pItemsTxtRecord->nQuest - 1);
            tArgs.pTarget = pUnit;
            if (pQuestData && pQuestData->pfCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM])
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM]), 734);
                pQuestData->pfCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM](pQuestData, &tArgs);
            }
        }
    }
    tArgs.nEvent = QUESTEVENT_PLAYERLEAVESGAME;
    QUESTS_EventCallback(true, false, &tArgs);
}

void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = CLIENTS_GetGame(pClient);
    tArgs.nEvent = QUESTEVENT_NPCACTIVATE;
    tArgs.pTarget = pTarget;
    tArgs.pPlayer = pPlayer;
    tArgs.pTextControl = pTextControl;
    QUESTS_EventCallback(true, true, &tArgs);
}

void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.pTarget = pNPC;
    tArgs.pPlayer = pPlayer;
    tArgs.nEvent = QUESTEVENT_NPCDEACTIVATE;
    QUESTS_EventCallback(true, true, &tArgs);
}

void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_SCROLLMESSAGE;
    tArgs.pPlayer = pPlayer;
    tArgs.nNPCNo = 0;
    if (dwNPCGUID == -1)
    {
        tArgs.pTarget = 0;
    }
    else
    {
        tArgs.pTarget = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, dwNPCGUID);
        if (tArgs.pTarget)
        {
            tArgs.nNPCNo = tArgs.pTarget->dwClassId;
        }
    }
    tArgs.nMessageIndex = nMessage;
    QUESTS_EventCallback(true, true, &tArgs);
}

static __forceinline int QUESTS_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static __forceinline int QUESTS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_INVALID;
    }

    return pUnit->dwUnitType;
}

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame->pMemoryPool);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 3362);

    D2QuestArgStrc tArgs;
    tArgs.pGame = CLIENTS_GetGame(pClient);
    tArgs.nEvent = QUESTEVENT_NPCACTIVATE;
    tArgs.pTarget = pTarget;
    tArgs.pPlayer = pPlayer;
    tArgs.pTextControl = pTextHeader;
    QUESTS_EventCallback(true, true, &tArgs);

    D2GSPacketSrv27 tPacket27;
    tPacket27.nHeader = 0x27;
    tPacket27.dwUnitGUID = QUESTS_GetUnitGUIDInline(pTarget);
    tPacket27.nUnitType = QUESTS_GetUnitTypeInline(pTarget);
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &tPacket27.tMessageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &tPacket27);
    TEXT_FreeTextHeader(pTextHeader);
    QUESTS_SendCurrentFlags(pGame, pClient);
}
