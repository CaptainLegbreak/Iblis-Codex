struct D2BitBufferStrc;
struct D2QuestDataExStrc
{
    unsigned char unk_00[0x18];
    int nState18;
};
struct D2QuestDataStrc
{
    unsigned char unk_00[0x18];
    D2QuestDataExStrc* pQuestDataEx;
};
struct D2PlayerDataStrc
{
    unsigned char unk_00[0x10];
    D2BitBufferStrc* pQuestData[3];
};
struct D2GameStrc
{
    unsigned char unk_00[0x6D];
    unsigned char nDifficulty;
};
struct D2UnitStrc;
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C360

// 0x005BA290
void __fastcall sub_005BA290_UpdateQuest20(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x12);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 0) && !QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 1))
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 0x14, pQuestData->pQuestDataEx->nState18);
        }
    }
}
