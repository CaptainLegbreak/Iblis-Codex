extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QuestDataStrc;

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x6C];
    D2QuestChainStrc* pQuestEventList;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6
#define QUEST_A1Q4_CAIN 4
#define QUEST_A2Q1_RADAMENT 8
#define QUEST_A2Q5_SUMMONER 12
#define OBJECT_INVISIBLE_OBJECT 61
#define MONSTER_RADAMENT 229
#define MONSTER_SUMMONER 250

extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00592F80
void __fastcall sub_005991B0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);           // 0x005991B0
void __fastcall sub_0059C3B0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);           // 0x0059C3B0

// 0x005435C0
static int __stdcall sub_005435C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2QuestDataStrc* pQuestData)
{
    D2QuestChainStrc* i = pUnit->pQuestEventList;
    D2_ASSERT(pQuestData, 93);
    for (; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }
        if (i->pQuestData == pQuestData)
        {
            return 0;
        }
    }
    D2QuestChainStrc* pNew = (D2QuestChainStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2QuestChainStrc), gszQuestsSourceFile, 104, 0);
    pNew->pQuestData = pQuestData;
    pNew->pNext = pUnit->pQuestEventList;
    pUnit->pQuestEventList = pNew;
    return 1;
}

// 0x005436B0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId)
{
    D2_ASSERT(nQuestId >= 0, 224);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, nQuestId);
    if (pQuestData)
    {
        int nUnitType = UNIT_INVALID;
        if (pUnit)
        {
            nUnitType = pUnit->dwUnitType;
        }
        if (nQuestId == QUEST_A1Q4_CAIN)
        {
            if (nUnitType == UNIT_OBJECT && pUnit && pUnit->dwClassId == OBJECT_INVISIBLE_OBJECT)
            {
                ACT1Q4_SetInvisibleObjectGUID(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuestId == QUEST_A2Q1_RADAMENT)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_RADAMENT)
            {
                sub_005991B0(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuestId == QUEST_A2Q5_SUMMONER)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_SUMMONER)
            {
                sub_0059C3B0(pGame, pQuestData, pUnit);
            }
        }
        return sub_005435C0(pGame, pUnit, pQuestData);
    }
    return 0;
}
