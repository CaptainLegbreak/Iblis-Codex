#ifdef MOVED_TEST
#define PREFIX char movedPrefix[4];
#define TERMINAL_STATE 7
#define ASSERT_LINE 681
#else
#define PREFIX
#define TERMINAL_STATE 5
#define ASSERT_LINE 677
#endif
struct D2GameStrc;
struct D2QuestDataStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

struct D2QuestDataStrc
{
    PREFIX
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
    char tPlayerGUIDs[0x84];
    void* pCallback[15];
    void* pNPCMessages;
    int eFilter;
    int unk0xE4;
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
// 0x0059A480
bool __fastcall sub_0059A480_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != TERMINAL_STATE && pQuestData->bNotIntro)
        return true;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), ASSERT_LINE);
            exit(-1);
        }
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}
