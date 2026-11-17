struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[0x0B];
    void* pQuestDataEx;
};

struct D2Act3Quest6Strc
{
    char unk0x00[0x28];
    int nSavedStatus;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005BC210

#define QUEST_A3Q6_MEPHISTO 20

// 0x005BCF60
void __fastcall sub_005BCF60_ACT3Q6_UpdatePlayerStatus(D2GameStrc* pGame, bool bRestore)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fState >= 6)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    int nStatus;
    if (bRestore)
    {
        nStatus = pQuestDataEx->nSavedStatus;
    }
    else
    {
        pQuestDataEx->nSavedStatus = pQuestData->fLastState;
        nStatus = (pQuestData->pGame->nGameType != 3) ? 7 : 6;
    }

    bool bIterate = false;
    if (pQuestData->fState > 0)
    {
        bIterate = true;
    }
    QUESTS_UnitIterate(pQuestData, nStatus, 0, ACT3Q6_UnitIterate_StatusCyclerEx, bIterate);
}
