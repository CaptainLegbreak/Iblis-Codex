struct D2BitBufferStrc;
struct D2QuestDataStrc
{
    unsigned char unk_00[0x0B];
    unsigned char nFlag0B;
    unsigned char nState0C;
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

// 0x00590890
int __fastcall sub_00590890_SyncQuest2(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestRecord, 2, 0) == 1 || QUESTRECORD_GetQuestState(pQuestRecord, 2, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 2);
    if (!pQuestData)
    {
        return 0;
    }
    const unsigned char nState = pQuestData->nState0C;
    if (nState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 2);
        return 0;
    }
    if (nState == 3)
    {
        if (pQuestData->nFlag0B == 1)
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 2, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 4);
    }
    return 0;
}
