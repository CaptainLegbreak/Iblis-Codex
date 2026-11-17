struct D2BitBufferStrc;

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
struct D2UnitStrc
{
    int dwUnitType;
    unsigned short wClassId;
    unsigned short unk0x06;
    int unk0x08;
    int dwUnitId;
};
struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pfCallback[16];
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

extern "C" const char gszAct3Q6SourceFile[];                                                                // 0x006E2F7C
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);         // 0x005BC020
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);       // 0x005BC210
void __fastcall ACT3Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005BC370
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// build: context ACT3Q6_CycleStatusFromLastState
static __forceinline int ACT3Q6_CycleStatusFromLastState(D2QuestDataStrc* pQuestData)
{
    int bResult = 0;
    if (pQuestData->fLastState == 2)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    else if (pQuestData->fLastState == 0)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    return bResult;
}

// 0x005BC3C0
void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 75)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState > 1 && pQuestData->fState <= 3)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1)
            {
                return;
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 11) == 1)
            {
                return;
            }

            if (pQuestData->fLastState < 3)
            {
                pQuestData->bStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 0);
            }

            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 364);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 368);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel >= 98 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pfCallback[2] = ACT3Q6_Callback02_NpcDeactivate;
    }

    if (nNewLevel == 100)
    {
        int bUpdate = ACT3Q6_CycleStatusFromLastState(pQuestData);

        if (pQuestData->fState == 1)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 400);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 404);
            }
            bUpdate = 1;
        }

        if (bUpdate)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if (nNewLevel == 102)
    {
        if (pQuestData->fLastState != 4)
        {
            pQuestData->bStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        }

        if (pQuestData->fState != 4 && pQuestData->fState != 5)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 426);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 430);
            }
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
    }
}
