#define QUEST_A2Q6_DURIEL 13

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameByte0x6A;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x0B];
    unsigned char bDurielLairTombOpen;
    char unk0x0C[0x02];
    unsigned char nUnk0x0E;
    char unk0x0F;
    unsigned char bUnk0x10;
    char unk0x11[0x03];
    int nUnk0x14;
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
    char pad0x0E[0x2];
    int nSeqId;
    unsigned int dwFlags;
    D2Act2Quest6Strc* pQuestDataEx;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x4];
    int dwUnitId;
    int dwAnimMode;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp);                                  // 0x0059D9D0

// 0x0059D800
unsigned char __fastcall sub_0059D800_ACT2Q6_IsNotBusy(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro)
    {
        const unsigned char nState = pQuestData->fState;
        if (nState == 1 || !nState)
        {
            return 0;
        }
    }
    return 1;
}

// 0x0059D850
unsigned char __fastcall sub_0059D850_ACT2Q6_IsTombOpen(D2QuestArgStrc* pQuestArg)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuestArg->pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro)
    {
        return pQuestData->pQuestDataEx->bDurielLairTombOpen;
    }
    return 1;
}

// 0x0059DA10
int __fastcall sub_0059DA10_ACT2Q6_OperateTombPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData || pQuestData->bNotIntro != 1 || pQuestData->pQuestDataEx->bDurielLairTombOpen)
    {
        if (pOp->pObject && pOp->pObject->dwAnimMode == 2)
        {
            D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
        }
    }
    return 0;
}

// 0x0059E060
void __fastcall sub_0059E060_ACT2Q6_SetPortalState(D2QuestDataStrc* pQuest, unsigned char bClear)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }
    D2Act2Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->nUnk0x0E == 1)
    {
        return;
    }
    if (!bClear)
    {
        if (pQuestData->pGame->nGameByte0x6A == 3)
        {
            pQuestDataEx->bUnk0x10 = 1;
            pQuestDataEx->nUnk0x14 = 8;
        }
        else
        {
            pQuestDataEx->bUnk0x10 = 1;
            pQuestDataEx->nUnk0x14 = 9;
        }
    }
    else
    {
        pQuestDataEx->bUnk0x10 = 0;
    }
}

// 0x0059E2A0
void __fastcall sub_0059E2A0_ACT2Q7_Callback08_Empty(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}
