#define QUEST_A3Q3_GIDBINN 0x11
#define QUEST_A3Q4_GOLDENBIRD 0x12
#define QUESTEVENT_MONSTERKILLED 8

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

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
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char pad0x03;
    int nBossGUID;
    unsigned char bTalkedToAlkor;
    unsigned char bTalkedToCainOnce;
    unsigned char bTalkedToCainTwice;
    unsigned char bTalkedToMeshif;
    unsigned char unk0x0C;
};

struct D2Act3Quest3Strc
{
    char unk0x00[0x4];
    unsigned char bBossIsSpawning;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
void __fastcall ACT3Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BAB60

// 0x005BAC70
int __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro || !pQuestDataEx->unk0x0C || pQuestDataEx->unk0x01 != 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A3Q3_GIDBINN);
    if (pQuest && ((D2Act3Quest3Strc*)pQuest->pQuestDataEx)->bBossIsSpawning)
    {
        return 0;
    }

    QUESTS_CreateChainRecord(pQuestData->pGame, pUnit, QUEST_A3Q4_GOLDENBIRD);
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT3Q4_Callback08_MonsterKilled;
    pQuestDataEx->unk0x01 = 0;
    pQuestDataEx->unk0x02 = 1;
    pQuestDataEx->nBossGUID = !pUnit ? -1 : pUnit->dwUnitId;
    return 1;
}

// 0x005BACF0
void __fastcall sub_005BACF0_GoldenBirdSpawnCheck(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x02 != 1)
    {
        return;
    }

    if (pQuestDataEx->nBossGUID == (!pUnit ? -1 : pUnit->dwUnitId))
    {
        pQuestDataEx->unk0x02 = 0;
        pQuestDataEx->unk0x01 = 1;
    }
}
