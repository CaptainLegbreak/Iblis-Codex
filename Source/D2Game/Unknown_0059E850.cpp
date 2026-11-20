#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0



struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

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

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short unk0x0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char unk0xE4[0x04];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};


struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
    unsigned char bHoradricScrollDropped;
    unsigned char bCubeDropped;
    unsigned char bStaffCubed;
    unsigned char unk0x2B;
    int nPlayerGUID;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x0B];
    unsigned char bDurielLairTombOpen;
    char unk0x0C[0x02];
    unsigned char bStaffItemsRemoved;
    unsigned char unk0x0F;
    unsigned char bHoradricStaffIsMissing;
    char unk0x11[0x03];
    int nQuestStatus;
};

struct D2Act2Quest3Strc
{
    char unk0x00[0x04];
    unsigned char bAltarDestroyed;
};

enum
{
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
    LEVEL_LUTGHOLEIN = 40,
};

extern "C" const char gszA2Q2SourceFile[];                                                                  // 0x006E211C
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
bool __fastcall ACT2Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005996C0
void __fastcall ACT2Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005997F0
void __fastcall ACT2Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00599910
void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00599A30
void __fastcall ACT2Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E850
bool __fastcall ACT2Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E630

int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT2Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q2_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q2_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059E850
void __fastcall sub_0059E850(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
    D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
    D2UnitStrc* base=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' fsm');
    D2UnitStrc* box=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' xob');
    D2UnitStrc* amulet=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' piv');
    D2UnitStrc* staff=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' tsh');
    D2Act2Quest2Strc* ex=(D2Act2Quest2Strc*)q->pQuestDataEx;
    if(base) ++ex->nBaseStaffs;
    if(amulet) ++ex->nAmulets;
    if(box) ++ex->nHoradricCubes;
    if(staff) ++ex->nCubedStaffs;
    if(!QUESTRECORD_GetQuestState(flags,10,0))
    {
        D2QuestDataStrc* duriel=QUESTS_GetQuestData(arg->pGame,13);
        if(duriel && duriel->bNotIntro && !((D2Act2Quest6Strc*)duriel->pQuestDataEx)->bDurielLairTombOpen && !ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' tsh') && (!base || !box || !amulet))
        {
            if(!base) QUESTRECORD_ClearQuestState(flags,10,5);
            if(!box) QUESTRECORD_ClearQuestState(flags,10,6);
            if(!amulet) QUESTRECORD_ClearQuestState(flags,10,4);
        }
    }
}
