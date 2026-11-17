struct D2QuestDataStrc;

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4

// 0x00543590
void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pRecord)
{
    while (pRecord)
    {
        D2QuestChainStrc* pNext = pRecord->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pRecord, gszQuestsSourceFile, 80, 0);
        pRecord = pNext;
    }
}
