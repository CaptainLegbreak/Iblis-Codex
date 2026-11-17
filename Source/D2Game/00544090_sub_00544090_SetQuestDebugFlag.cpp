extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[0xF0];
    D2QuestDataStrc* pPrev;
};

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
};

struct D2GameStrc
{
    char unk0x0000[0x10F4];
    T005438E0* pQuestControl;
};

extern int dword_6FD4DC34;                                                                                  // 0x008846DC
int __fastcall sub_005968C0_IsAndarielKilled(D2QuestDataStrc* pQuestData);                                  // 0x005968C0

// build: context QUESTS_GetQuestData_Inl
static __forceinline D2QuestDataStrc* QUESTS_GetQuestData_Inl(D2GameStrc* pGame, int nId)
{
    D2_ASSERT(nId >= 0, 119);
    if (!pGame->pQuestControl)
        return 0;
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
            return pQuestData;
    }
    return 0;
}

// 0x00544090
void __fastcall sub_00544090_SetQuestDebugFlag(int nValue)
{
    dword_6FD4DC34 = nValue;
}

// 0x005447F0
int __fastcall sub_005447F0_IsAndarielKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inl(pGame, 6);
    D2_ASSERT(pQuestData, 0x85C);
    return sub_005968C0_IsAndarielKilled(pQuestData);
}
