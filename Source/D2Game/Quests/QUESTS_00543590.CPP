#include "D2Game.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6
#define QUEST_A1Q4_CAIN 4
#define QUEST_A2Q1_RADAMENT 8
#define QUEST_A2Q5_SUMMONER 12
#define OBJECT_INVISIBLE_OBJECT 61
#define MONSTER_RADAMENT 229
#define MONSTER_SUMMONER 250
#define MAX_QUEST_STATUS 41
#define QFLAG_REWARDGRANTED 0
#define QFLAG_PRIMARYGOALDONE 13
#define QUESTSTATEFLAG_A1Q1 1
#define QUESTSTATEFLAG_A2Q4 12
#define QUEST_A1Q1_DENOFEVIL 1
#define ACT_II 1
#define PACKET_QUESTSTATUS 0x52
#define PACKET_QUESTPROGRESS 0x50
#define LINE_UPDATEFLAGS_CLIENT 0xCA7
#define LINE_STATUS_CLIENT 0x49A
#define LINE_STATUS_QUESTNO 0x4B3
#define LINE_STATUS_FILTER 0x4CB
struct T005438E0;
struct D2QuestChainStrc;
struct D2PlayerDataStrc;
struct D2MonStatsTxt;
struct D2GSPacketSrv8A;
struct D2ItemsTxt;
struct D2GSPacketSrv52;
struct D2GSPacketSrv50;
struct D2GSPacketSrv5D;

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
    int bExpansion;
    unsigned char unk_74[0x48];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1024];
    T005438E0* pQuestControl;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    void* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char unk_0A[0x1];
    unsigned char fLastState;
    unsigned char unk_0C[0x94];
    QUESTCALLBACK pfCallback[15];
    unsigned char unk_DC[0x4];
    int nQuestFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    char unk0xF0[0x04];
    D2QuestDataStrc* pPrev;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00592F80
void __fastcall sub_005991B0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005991B0
void __fastcall sub_0059C3B0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059C3B0

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
    int unk0x04;
    int unk0x08;
    D2BitBufferStrc* pQuestFlags;
};

extern int dword_6FD4DC34; // 0x008846DC
int __fastcall sub_005968C0_IsAndarielKilled(D2QuestDataStrc* pQuestData); // 0x005968C0

typedef int (__stdcall* FARPROC)();

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char pad0x1C[0x30];
    int bBusy;
    char pad0x50[0x10];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char dwMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

#pragma pack(push, 1)
struct D2GSPacketSrv8A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
};

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket); // 0x0053DFF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

struct D2ItemsTxt
{
    char unk0x00[0xDC];
    unsigned char nBitField1;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

#pragma pack(push, 1)
struct D2GSPacketSrv52
{
    unsigned char nHeader;
    unsigned char pQuestList[MAX_QUEST_STATUS];
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nMonstersToBeKilled;
    unsigned short nStaffTombLevelOffset;
    unsigned short nBarbsToBeRescued;
    unsigned char unk0x09[6];
};

#pragma pack(pop)

void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
void __fastcall sub_0053D840(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket); // 0x0053D840
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pQuestList, D2BitBufferStrc* pQuestFlags); // 0x00543F90
unsigned short __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData); // 0x00588C50
unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc* pQuestData); // 0x005901E0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

#pragma pack(push, 1)
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

#pragma pack(pop)

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C150
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572420
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310
void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x005BCFD0

// 0x00543590
void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pRecord)
{
    while (pRecord)
    {
        D2QuestChainStrc* pNext = pRecord->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pRecord, gszQuestsSourceFile, 80, 0);
        pRecord = pNext;
    }
}

// 0x005435C0
static int __stdcall sub_005435C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2QuestDataStrc* pQuestData)
{
    D2QuestChainStrc* i = pUnit->pQuestEventList;
    D2_ASSERT(pQuestData, 93);
    for (; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }
        if (i->pQuestData == pQuestData)
        {
            return 0;
        }
    }
    D2QuestChainStrc* pNew = (D2QuestChainStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2QuestChainStrc), gszQuestsSourceFile, 104, 0);
    pNew->pQuestData = pQuestData;
    pNew->pNext = pUnit->pQuestEventList;
    pUnit->pQuestEventList = pNew;
    return 1;
}

// 0x005436B0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId)
{
    D2_ASSERT(nQuestId >= 0, 224);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, nQuestId);
    if (pQuestData)
    {
        int nUnitType = UNIT_INVALID;
        if (pUnit)
        {
            nUnitType = pUnit->dwUnitType;
        }
        if (nQuestId == QUEST_A1Q4_CAIN)
        {
            if (nUnitType == UNIT_OBJECT && pUnit && pUnit->dwClassId == OBJECT_INVISIBLE_OBJECT)
            {
                ACT1Q4_SetInvisibleObjectGUID(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuestId == QUEST_A2Q1_RADAMENT)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_RADAMENT)
            {
                sub_005991B0(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuestId == QUEST_A2Q5_SUMMONER)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_SUMMONER)
            {
                sub_0059C3B0(pGame, pQuestData, pUnit);
            }
        }
        return sub_005435C0(pGame, pUnit, pQuestData);
    }
    return 0;
}

// build: context QUESTS_GetQuestData_Inl
static __forceinline D2QuestDataStrc* QUESTS_GetQuestData_Inl(D2GameStrc* pGame, int nId)
{
    D2_ASSERT(nId >= 0, 119);
    if (!pGame->pQuestControl)
        return 0;
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
            return pQuestData;
    }
    return 0;
}

// 0x00544090
void __fastcall sub_00544090_SetQuestDebugFlag(int nValue)
{
    dword_6FD4DC34 = nValue;
}

// 0x005447F0
int __fastcall sub_005447F0_IsAndarielKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inl(pGame, 6);
    D2_ASSERT(pQuestData, 0x85C);
    return sub_005968C0_IsAndarielKilled(pQuestData);
}

static __forceinline int sub_00544590_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->dwMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00544590
int __fastcall sub_00544590_QuestsActiveFilter(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC)
{
    const bool bIsPlayer = pPlayer && pPlayer->dwUnitType == 0;
    D2_ASSERT(bIsPlayer, 2028);

    const int nNPCType = pNPC ? pNPC->dwUnitType : 6;
    D2_ASSERT(nNPCType == 1, 2029);

    const int nNpcId = pNPC->dwClassId;
    if (!sub_00544590_CheckMonStatsFlag(nNpcId, 9))
    {
        return 0;
    }

    T005438E0* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(pQuestControl->unk0x08, 2036);

    const unsigned char nAct = CLIENTS_GetActNo(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 2038));

    for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (nAct == pQuestData->nActNo)
        {
            if (pQuestData->pfActiveFilter)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfActiveFilter), 2050);
                D2_ASSERT(UNITS_GetPlayerData(pPlayer), 2051);
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
                D2_ASSERT(pQuestFlags, 2053);

                if (pQuestData->pfActiveFilter(pQuestData, nNpcId, pPlayer, pQuestFlags, pNPC))
                {
                    D2GSPacketSrv8A tPacket8A;
                    tPacket8A.nHeader = 0x8A;
                    tPacket8A.nUnitType = 1;
                    tPacket8A.dwUnitGUID = pNPC->dwUnitId;
                    D2GAME_SendPacket0x8A_6FC3FA60(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 2061), &tPacket8A);
                    return 1;
                }
            }
            else
            {
                D2_ASSERT(false, 2067);
            }
        }
    }

    return 0;
}

// 0x005451B0
int __fastcall sub_005451B0_HasFlaggedItem(D2UnitStrc* pUnit)
{
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (DATATBLS_GetItemsTxtRecord(!pCheckedItem ? -1 : pCheckedItem->dwClassId)->nBitField1 & 2)
        {
            return 1;
        }
    }

    return 0;
}

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, LINE_UPDATEFLAGS_CLIENT), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
}

// 0x00546040
void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, LINE_STATUS_CLIENT);
    D2GSPacketSrv52 packet52 = { PACKET_QUESTSTATUS };

    T005438E0* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2QuestDataStrc* pQuest = pQuestControl->pLastQuest;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    for (; pQuest; pQuest = pQuest->pPrev)
    {
        D2_ASSERT(pQuest->nQuestNo < MAX_QUEST_STATUS, LINE_STATUS_QUESTNO);

        if (pQuest->fLastState)
        {
            if (!pQuest->pfStatusFilter)
            {
                QUESTS_RefreshStatus(pQuest, &packet52.pQuestList[pQuest->nQuestFilter], pQuestFlags);
            }
            else
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfStatusFilter), LINE_STATUS_FILTER);

                unsigned char nStatus;
                if (pQuest->pfStatusFilter(pQuest, pUnit, pQuestControl->pQuestFlags, pQuestFlags, &nStatus) == 1)
                {
                    packet52.pQuestList[pQuest->nQuestFilter] = nStatus;
                }
            }
        }
    }

    bool bSendPacket0x50 = false;
    D2GSPacketSrv50 packet50 = {};
    if (packet52.pQuestList[QUESTSTATEFLAG_A1Q1] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData1 = pGame->pQuestControl->pLastQuest;
        while (pQuestData1 && pQuestData1->nQuestNo != QUEST_A1Q1_DENOFEVIL)
        {
            pQuestData1 = pQuestData1->pPrev;
        }

        if (pQuestData1)
        {
            bSendPacket0x50 = true;
            packet50.nMonstersToBeKilled = ACT1Q1_GetMonstersToBeKilled(pQuestData1);
        }
    }

    if (packet52.pQuestList[QUESTSTATEFLAG_A5Q2] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData32 = pGame->pQuestControl->pLastQuest;
        while (pQuestData32 && pQuestData32->nQuestNo != QUEST_A5Q2_RESCUESOLDIERS)
        {
            pQuestData32 = pQuestData32->pPrev;
        }

        if (pQuestData32)
        {
            bSendPacket0x50 = true;
            packet50.nBarbsToBeRescued = ACT5Q2_GetBarbsToBeRescued(pQuestData32);
        }
    }

    if ((QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE)) && pGame->pAct[ACT_II])
    {
        bSendPacket0x50 = true;
        packet50.nStaffTombLevelOffset = DUNGEON_GetHoradricStaffTombLevelId(pGame->pAct[ACT_II]) - LEVEL_TALRASHASTOMB1;
    }

    if (bSendPacket0x50)
    {
        packet50.nHeader = PACKET_QUESTPROGRESS;
        packet50.nQuestId = QUEST_A1Q1_DENOFEVIL;
        D2GAME_SendPacket0x50_6FC3F440(pClient, &packet50);
    }

    sub_0053D840(pClient, &packet52);
}

// build: symbol ?QUESTS_DeleteItemEx@@YGXPAUD2InventoryStrc@@PAUD2GameStrc@@PAUD2UnitStrc@@2@Z 0x005440A0
static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0x534);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;
    switch (nAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, nFlags);
        D2GAME_RemoveItem_6FC471F0(pGame, pPlayer, pItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pItem);
        int a5;
        sub_6FC45B30(pGame, pPlayer, nBodyLoc, 1, &a5);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        break;
    }
}

// 0x00544160
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode)
{
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, dwCode);
    if (pItem)
    {
        QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
    }
}

static void sub_00544FA0_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 6; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct1_NPCIds_007318B0[i]);
        break;
    }
    case 1:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 11; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct2_NPCIds_007318C8[i]);
        break;
    }
    case 2:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct3_NPCIds_007318F4[i]);
        break;
    }
    case 4:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct5_NPCIds_00731910[i]);
        break;
    }
    }
}

static __forceinline D2QuestDataStrc* QUESTS_GetQuestDataInl_B08(D2GameStrc* pGame, int nId)
{
    if (!pGame->pQuestControl)
    {
        return 0;
    }
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
        {
            return pQuestData;
        }
    }
    return 0;
}

// 0x005467E0
void __fastcall QUESTS_ActChange_HirelingChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pVendor, unsigned int dwDestLvl, unsigned int nUnused)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    const int nVendorType = pVendor ? pVendor->dwUnitType : 6;
    if (nVendorType != 1)
    {
        return;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    switch (pVendor->dwClassId)
    {
    case 0x9B:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 7, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 13);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xAD3);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 2);
            }
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 0);
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 13) == 1 && QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestDataInl_B08(pGame, 6);
            if (pQuestData && pQuestData->bNotIntro)
            {
                D2QuestArgStrc tArgs;
                tArgs.pGame = pGame;
                tArgs.nEvent = 3;
                tArgs.nOldLevel = 1;
                tArgs.nNewLevel = 40;
                tArgs.pPlayer = pUnit;
                if (pQuestData->pfCallback[3])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfCallback[3]), 0xAEE);
                    pQuestData->pfCallback[3](pQuestData, &tArgs);
                }
            }
        }

        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case 0xD2:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 15, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 10, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);
                QUESTS_DeleteItem(pGame, pUnit, ' fsm');
                QUESTS_DeleteItem(pGame, pUnit, ' piv');
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 15, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 15, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xB0F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 3);
            }
        }
        break;

    case 0x16F:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0) && pGame->bExpansion)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xB1F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GSPacketSrv5D packet5D = {};
                packet5D.nHeader = 0x5D;
                packet5D.nQuestId = 23;
                packet5D.nFlags = 2;
                sub_6FC3F380(pClient, &packet5D);
                sub_0053D940_SendPacket0x61(pClient, 5);
            }
        }
        break;
    }
}

// 0x00546AC0
void __fastcall QUESTS_HellPortalActChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nLevel, D2UnitStrc* pObject)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nLevel == 0x66)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x17, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x12, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 13);

                D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' yeq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rhq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rbq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 1fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 2fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 2);
            D2BitBufferStrc* pPlayerFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            D2GAME_SendPacket0x28_6FC3F2F0(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0xCA7), 0x28, 6, 0, pPlayerFlags, 0);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0xB56);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 4);
            }
        }
    }
    else
    {
        ACT3Q6_SetObjectModes(pGame, pObject);
    }
}
