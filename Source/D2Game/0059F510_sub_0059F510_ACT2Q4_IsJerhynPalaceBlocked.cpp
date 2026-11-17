struct D2GameStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    bool bNotIntro;
    bool bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act2Quest4Strc
{
    char unk0x00[0x0D];
    unsigned char bJerhynPalaceInitialized;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
bool __fastcall sub_0059DFB0_ACT2Q6_IsStateBelow4Inactive(D2GameStrc* pGame);                               // 0x0059DFB0

// 0x0059F510
unsigned char __fastcall sub_0059F510_ACT2Q4_IsJerhynPalaceBlocked(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData11 = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData11 || !((D2Act2Quest4Strc*)pQuestData11->pQuestDataEx)->bJerhynPalaceInitialized)
    {
        return 1;
    }

    D2QuestDataStrc* pQuestData8 = QUESTS_GetQuestData(pQuestData11->pGame, 8);
    return !pQuestData8 || !pQuestData8->bNotIntro || pQuestData8->fState == 5 || sub_0059DFB0_ACT2Q6_IsStateBelow4Inactive(pQuestData11->pGame)
        || pQuestData11->bNotIntro != 1 || pQuestData11->fState >= 2;
}
