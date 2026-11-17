struct D2GameStrc;

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0xAE];
    unsigned char bChangeToSpecialObjectModeInTown;
    unsigned char bUnk0xAF;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x0058A9B0
void __fastcall sub_0058A9B0_SetDrehyaSpecialModeInTown(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bChangeToSpecialObjectModeInTown = 1;
    }
}

// 0x0058A9D0
int __fastcall sub_0058A9D0_GetQuestFlagAF(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bUnk0xAF != 0;
}
