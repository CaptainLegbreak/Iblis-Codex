struct D2BitBufferStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
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
    D2Act1Quest5Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#define UNIT_PLAYER 0
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_FORGOTTENTOWER 20
#define LEVEL_TOWERCELLARLEV5 25
#define QFLAG_REWARDGRANTED 0

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00594830
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594890
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x00594740
static __declspec(noinline) int __stdcall ACT1Q5_UpdateUnitGUIDLists(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID, int a3)
{
    if (a3)
    {
        for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs2[i] == nUnitGUID)
            {
                if (i != pQuestDataEx->nUnitCount2 - 1)
                {
                    pQuestDataEx->nUnitGUIDs2[i] = pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2 - 1];
                }
                --pQuestDataEx->nUnitCount2;
                return 1;
            }
        }
        return 0;
    }
    else
    {
        for (int i = 0; i < pQuestDataEx->nUnitCount1; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs1[i] == nUnitGUID)
            {
                if (i != pQuestDataEx->nUnitCount1 - 1)
                {
                    pQuestDataEx->nUnitGUIDs1[i] = pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1 - 1];
                }
                --pQuestDataEx->nUnitCount1;
                return 1;
            }
        }
        return 0;
    }
}

// 0x00595010
void __fastcall ACT1Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestData->bNotIntro)
    {
        if (nNewLevel == LEVEL_FORGOTTENTOWER)
        {
            if (!pQuestData->fState)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 615);
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            else if (pQuestData->fState <= 3 && pQuestData->fLastState == 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            return;
        }

        if (nNewLevel == LEVEL_TOWERCELLARLEV5)
        {
            if (pQuestData->fState < 4 && pQuestData->fLastState != 2)
            {
                if (pQuestData->fState != 3)
                {
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 634);
                }
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            return;
        }
    }

    if (nOldLevel == LEVEL_ROGUEENCAMPMENT)
    {
        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) != 1)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 653);
            }
        }
        else if (pQuestData->fState == 5 && pQuestData->bNotIntro)
        {
            D2Act1Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
            if (ACT1Q5_UpdateUnitGUIDLists(pQuestDataEx, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId, 0) && !pQuestDataEx->nUnitCount1 && !pQuestDataEx->nUnitCount2)
            {
                pQuestData->bActive = 0;
            }
        }
    }
}
