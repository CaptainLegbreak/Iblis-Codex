struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };
struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2QuestDataStrc { char unk00[0xB]; unsigned char fLastState; unsigned char fState; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640
// 0x00594890
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pFlags, 5, 0) == 1 || QUESTRECORD_GetQuestState(pFlags, 5, 1) == 1) return 0;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, 5);
    if (!pQuest) return 0;
    if (pQuest->fState == 2)
    {
        QUESTRECORD_SetQuestState(pFlags, 5, 2);
        return 0;
    }
    if (pQuest->fState == 3)
    {
        switch (pQuest->fLastState)
        {
        case 1: QUESTRECORD_SetQuestState(pFlags, 5, 3); break;
        case 2: QUESTRECORD_SetQuestState(pFlags, 5, 4); break;
        case 3: QUESTRECORD_SetQuestState(pFlags, 5, 5); break;
        case 4: QUESTRECORD_SetQuestState(pFlags, 5, 6); break;
        }
    }
    return 0;
}
