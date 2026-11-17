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
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char unk0x01[0x0B];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
};

#define QUEST_A5Q5_ANCIENTS 35

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x0058CFB0
int __fastcall ACT5Q5_GetPortalCount(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS)->pQuestDataEx)->nActivePortalCount;
}

// 0x0058CFE0
int __fastcall ACT5Q5_IsActivatable(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);

    return pQuestData && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable;
}
