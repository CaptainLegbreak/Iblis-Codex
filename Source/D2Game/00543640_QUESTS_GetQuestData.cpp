struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[240];
    D2QuestDataStrc* pPrev;
};
struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
};
struct D2GameStrc
{
    char unk0x00[4340];
    D2QuestInfoStrc* pQuestControl;
};
struct D2UnitStrc
{
    char unk0x00[16];
    int dwAnimMode;
};
struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp);      // 0x0059F380
void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp);     // 0x0059F440
void __fastcall sub_0059A3F0(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp);   // 0x0059A3F0
void __fastcall sub_005B7310(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A2Q3_TAINTEDSUN 10
#define QUEST_A2Q4_HORAZONTOME 11
#define QUEST_A3Q1_LAMESENTOME 15
#define OBJMODE_OPENED 2

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

// 0x005448B0
void __fastcall OBJECTS_InitFunction18_JerhynPosition(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynStartObject(pQuestData, pOp);
    }
}

// 0x005448E0
void __fastcall OBJECTS_InitFunction19_JerhynPositionEx(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynPalaceObject(pQuestData, pOp);
    }
}

// 0x00544910
void __fastcall OBJECTS_InitFunction20_TaintedAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData)
    {
        sub_0059A3F0(pQuestData, pOp);
        return;
    }

    int nAnimMode = 0;
    if (pOp->pObject)
    {
        nAnimMode = pOp->pObject->dwAnimMode;
    }

    if (nAnimMode != OBJMODE_OPENED)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x00544E30
void __fastcall OBJECTS_InitFunction23_LamEsenTomeStand(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q1_LAMESENTOME);
    D2_ASSERT(pQuestData, 2435);

    sub_005B7310(pQuestData, pOp);
}
