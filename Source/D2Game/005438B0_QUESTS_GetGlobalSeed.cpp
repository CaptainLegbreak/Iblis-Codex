struct D2BitBufferStrc;
struct D2SeedStrc
{
    int lSeed;
    int nHighSeed;
};
struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[240];
    D2QuestDataStrc* pPrev;
};
struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    char unk0x04[4];
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    char unk0x10[8];
    D2SeedStrc pSeed;
};
struct D2GameStrc
{
    char unk0x00[4340];
    D2QuestInfoStrc* pQuestControl;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00543640
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x005438B0
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame)
{
    if (pGame->pQuestControl)
    {
        return &pGame->pQuestControl->pSeed;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 507);
    exit(-1);
}

// 0x00544470
int __stdcall QUESTS_CheckFirstPickedSet(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 1971);

    if (!pGame->pQuestControl)
    {
        return 0;
    }

    return pGame->pQuestControl->bPickedSet;
}

// 0x00544720
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2080);

    QUESTRECORD_SetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}

// 0x00544760
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2092);

    return QUESTRECORD_GetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}
