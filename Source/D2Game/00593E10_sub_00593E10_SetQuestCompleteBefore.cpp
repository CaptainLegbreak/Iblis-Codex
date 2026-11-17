extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2GameStrc;

struct D2Act1Quest4Strc
{
    char unk0x00[0x52];
    unsigned char unk0x52;
    char unk0x53[0x0F];
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
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
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    D2Act1Quest4Strc* pQuestDataEx;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x00593E10
void __fastcall sub_00593E10_SetQuestCompleteBefore(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        pQuestData->pQuestDataEx->bQuestCompleteBefore = 1;
    }
}

// 0x00593F60
void __fastcall sub_00593F60_SetUnk52(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        pQuestData->pQuestDataEx->unk0x52 = 1;
    }
}

// 0x00593F80
int __fastcall sub_00593F80_GetCainNotCreated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        return pQuestData->pQuestDataEx->bCainNotCreated;
    }
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x99D);
    exit(-1);
}
