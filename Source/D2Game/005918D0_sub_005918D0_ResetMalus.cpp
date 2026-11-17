struct D2GameStrc;
struct D2QuestArgStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2Act1Quest3Strc
{
    unsigned char unk0x00;
    unsigned char bMalusInitialized;
    unsigned char bCharsiIntroActivated;
    unsigned char bCharsiEndActivated;
    int nMalusGUID;
    unsigned char unk0x08;
    char unk0x09[0x8F];
    int nMalusObjectMode;
    int nMalusItemsInGame;
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
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005912E0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x005918D0
static __declspec(noinline) bool sub_005918D0_ResetMalus(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->bNotIntro)
    {
        return false;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nMalusObjectMode = 0;
    if (!pQuestDataEx->bMalusInitialized)
    {
        return false;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x1C8);
    pQuestData->nFlags = 1;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, true);
    pQuestDataEx->unk0x08 = 0;
    if (pQuestDataEx->bMalusInitialized == 1)
    {
        D2UnitStrc* pMalus = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nMalusGUID);
        if (pMalus && pMalus->dwClassId == 0x6C)
        {
            UNITS_ChangeAnimMode(pMalus, 0);
            return true;
        }

        pQuestDataEx->bMalusInitialized = 0;
    }

    return true;
}

// 0x00591A90
void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    --pQuestDataEx->nMalusItemsInGame;
    if (!pQuestDataEx->nMalusItemsInGame && pQuestDataEx->nMalusObjectMode == 2)
    {
        sub_005918D0_ResetMalus(pQuestData);
    }
}
