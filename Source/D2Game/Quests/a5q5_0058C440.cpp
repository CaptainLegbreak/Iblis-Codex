#include "D2Structs.h"
#ifdef MOVED_TEST
#define NPC_SHIFT 4
#define FLAG_SHIFT 2
#define MESSAGE_SHIFT 2
#define MESSAGE_LIMIT 11u
#else
#define NPC_SHIFT 0
#define FLAG_SHIFT 0
#define MESSAGE_SHIFT 0
#define MESSAGE_LIMIT 9u
#endif
struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
struct D2GameStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};


struct D2PlayerDataStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2Act5Quest5Strc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    unsigned char bAncientsDefeated;
    unsigned char bQualKehkActivated;
    unsigned char unused0x02[2];
    unsigned char bTimerActive;
    unsigned char unused0x05[7];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
    unsigned char pad0x12[2];
    int nAncientStatueGUID[3];
    int nAncientMonsterGUID[3];
    unsigned char bAncientMonsterSpawned[3];
    unsigned char pad0x2F;
    int nAncientStatueObjectMode[3];
    unsigned char bAncienStatueRespawned[3];
    unsigned char pad0x3F;
    int nAncientsSpawned;
    int nAncientsAlive;
    unsigned char unk0x48[2];
    unsigned char bQuestCompletedBefore;
    unsigned char unk0x4B[0x19];
};

struct D2QuestGUIDStrc
{
    char data[0x84];
};

struct D2QuestDataStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
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
    D2Act5Quest5Strc* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    void* pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    union
    {
        D2TextHeaderStrc* pTextControl;
        int nOldLevel;
    };
    int nNewLevel;
};
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
extern const unsigned int gnA5Q5NpcActivateIndices[];  // 0x007357E4
static __forceinline bool IsAncientStatue(int nNpcId)
{
    if (nNpcId < 537 + NPC_SHIFT)
        return false;
    if (nNpcId > 539 + NPC_SHIFT)
        return false;
    return true;
}
// 0x0058C440
void __fastcall sub_0058C440(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestData->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    int bRewarded = QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 0 + FLAG_SHIFT);
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (!pQuestData->bNotIntro)
        return;
    if (bRewarded)
    {
        int bPrimaryGoal = QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 13 + FLAG_SHIFT);
        switch (nNpcId)
        {
        case 511 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 5 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 520 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 6 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 512 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 7 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 513 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 8 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 515 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 9 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        }
        return;
    }
    if (IsAncientStatue(nNpcId) && !pQuestDataEx->unk0x10)
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4 + MESSAGE_SHIFT);
    unsigned int nIndex = gnA5Q5NpcActivateIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < MESSAGE_LIMIT)
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
}

#include "gen/data/Source/D2Game/Quests/a5q5_0058C440.inc"
