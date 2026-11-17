typedef int (__stdcall* FARPROC)();
struct D2BitBufferStrc;
struct D2UnitStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x10];
    void* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;

    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xD4];
    D2UnitStrc* pRoomNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;

    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
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

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;

    unsigned char unk0x01;
    unsigned char unk0x02;
    char unk0x03[0x05];

    unsigned char bTalkedToAlkor;
    unsigned char bTalkedToCainOnce;
    unsigned char bTalkedToCainTwice;
    unsigned char bTalkedToMeshif;
    unsigned char unk0x0C;
    char unk0x0D[0x03];
    int nGoldenBirdsInGame;
    unsigned char bJadeFigurineDropped;
    unsigned char bPlayerDroppedWithItem;
    char unk0x16[0x06];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern char gpAct3Q4NpcMessages[];                                                                          // 0x007401D0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_ResetPlayerGUIDCount(void* pQuestGUID);                                              // 0x00545300
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

bool __fastcall ACT3Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B9D90
void __fastcall ACT3Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005B9ED0
void __fastcall ACT3Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BA320
void __fastcall ACT3Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA870
void __fastcall ACT3Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA990
void __fastcall ACT3Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA9E0
bool __fastcall ACT3Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BA170

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B9E70
int __fastcall ACT3Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 20, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 20, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 18);
    }

    return 0;
}

// 0x005BA0A0
void __fastcall ACT3Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel == 75)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}

// 0x005BA0B0
void __fastcall ACT3Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    if ((short)nNpcId == 254)
    {
        if (pQuestDataEx->bTalkedToAlkor == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 5, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToAlkor = 0;
            pQuestDataEx->bGoldenBirdBroughtToAlkor = 1;
        }
    }
    else if ((short)nNpcId == 245)
    {
        if (pQuestDataEx->bTalkedToCainOnce == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToCainOnce = 0;
        }

        if (pQuestDataEx->bTalkedToCainTwice == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToCainTwice = 0;
        }
    }
    else if ((short)nNpcId == 264)
    {
        if (pQuestDataEx->bTalkedToMeshif == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToMeshif = 0;
        }
    }
}

// 0x005BA6A0
void __fastcall ACT3Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        return;
    }

    QUESTS_DebugOutput(pQuestData->pGame, "something acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 605);

    const unsigned int dwItemCode = DATATBLS_GetItemsTxtRecord(!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId)->dwCode;
    if (dwItemCode == ' 43g')
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 611);
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
    }
    else if (dwItemCode == ' 43j')
    {
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 622);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 6))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 6);
            SUNIT_AttachSound(pQuestArg->pPlayer, 72, pQuestArg->pPlayer);
        }
    }
}

// 0x005BA7B0
bool __fastcall ACT3Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    bool bResult = false;
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 644);
        bResult = pQuest->pfSeqFilter(pQuest);
    }

    D2QuestDataStrc* pQuestData17 = QUESTS_GetQuestData(pQuestData->pGame, 17);
    if (pQuestData17)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 650);
        return pQuestData17->pfSeqFilter(pQuestData17) || bResult;
    }

    return bResult;
}

// 0x005BA9A0
void __fastcall ACT3Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nGoldenBirdsInGame;
    if (!pQuestDataEx->nGoldenBirdsInGame && pQuestData->bNotIntro && pQuestDataEx->bJadeFigurineDropped && pQuestData->fState < 4)
    {
        pQuestDataEx->bPlayerDroppedWithItem = 1;
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 6, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005BAA70
void __fastcall ACT3Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct3Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = 20;
    pQuestData->pfActiveFilter = ACT3Q4_ActiveFilterCallback;
    pQuestData->nInitNo = 0;
    pQuestData->pfStatusFilter = ACT3Q4_StatusFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q4_SeqCallback;
    pQuestData->nSeqId = 16;
    pQuestData->pfCallback[4] = ACT3Q4_Callback04_ItemPickedUp;
    pQuestData->pfCallback[0] = ACT3Q4_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q4_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q4_Callback03_ChangedLevel;
    pQuestData->pfCallback[13] = ACT3Q4_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[10] = ACT3Q4_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[14] = ACT3Q4_Callback14_PlayerJoinedGame;
    pQuestData->pfCallback[9] = ACT3Q4_Callback09_PlayerDroppedWithQuestItem;
    QUESTS_ResetPlayerGUIDCount(&pQuestData->tPlayerGUIDs);

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 832, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest4Strc));
    pQuestDataEx->unk0x0C = 1;
    pQuestDataEx->unk0x01 = 1;
}

#include "gen/data/Source/D2Game/005B9E70_ACT3Q4_UnitIterate_StatusCyclerEx.inc"
