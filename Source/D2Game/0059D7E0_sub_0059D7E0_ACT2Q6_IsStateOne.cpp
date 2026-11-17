#define QUEST_A2Q6_DURIEL 13

struct D2GameStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x0059D7E0
unsigned char __fastcall sub_0059D7E0_ACT2Q6_IsStateOne(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState == 1)
    {
        return 1;
    }

    return 0;
}
