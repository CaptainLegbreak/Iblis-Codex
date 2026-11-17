struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x30];
    int nInifussTreeGUID;
    char unk0x34[0x13];
    unsigned char bInifussTreeInitialized;
    char unk0x48[7];
    unsigned char bOperatedWithLastCairnStone;
    char unk0x50[8];
    int unk0x58;
    char unk0x5C[0x20];
    int nScrollsInGame;
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
    unsigned char nFlags;
    unsigned char unk0x15[3];
    void* pQuestDataEx;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0
int __fastcall ACT1Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00592130
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590

// 0x00592BD0
static __declspec(noinline) void ACT1Q4_ResetInifussTree(D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree && pInifussTree->dwClassId == 0x1E)
        {
            UNITS_ChangeAnimMode(pInifussTree, 0);
        }

        pQuestData->nFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x397);
        pQuestDataEx->unk0x58 = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }
    else
    {
        pQuestData->nFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x39F);
        pQuestDataEx->unk0x58 = 0;
    }
}

// 0x00592C80
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro || pQuestData->fState == 6)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    const int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);
    if (dwItemCode == 0x20646B62 || dwItemCode == 0x20736B62)
    {
        --pQuestDataEx->nScrollsInGame;
    }

    if (!pQuestDataEx->nScrollsInGame && pQuestData->fState <= 5 && pQuestDataEx->bOperatedWithLastCairnStone != 1 && pQuestDataEx->bInifussTreeInitialized == 1)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x3F7);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}

// 0x00592E60
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bOperatedWithLastCairnStone != 1 && pQuestData->fState <= 5)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x501);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}
