#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
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
    void* pQuestDataEx;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    char pad0x05[0x07];
    unsigned char bOrbSmashed;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C310
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110

// 0x005BD630
void __fastcall ACT3Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 245)
    {
        return;
    }

    if (pQuestData->fState >= 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 0);
        return;
    }

    int nParts = 0;
    int bCubedFlail = 0;
    int bBaseFlail = 0;
    int bEye = 0;
    int bHeart = 0;
    int bBrain = 0;
    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' 2fq'))
    {
        bCubedFlail = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 7))
        {
            D2QuestDataStrc* pQuestData19 = QUESTS_GetQuestData(pQuestData->pGame, 19);
            const bool bNotSmashed = pQuestData19 ? ((D2Act3Quest5Strc*)pQuestData19->pQuestDataEx)->bOrbSmashed == 0 : true;
            if (bNotSmashed)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 5);
                return;
            }
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' 1fq'))
    {
        ++nParts;
        bBaseFlail = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 4);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' yeq'))
    {
        ++nParts;
        bEye = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 3))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 1);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' rhq'))
    {
        ++nParts;
        bHeart = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 6))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 2);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' rbq'))
    {
        ++nParts;
        bBrain = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 3);
            return;
        }
    }

    if (nParts > 0)
    {
        if (bBaseFlail)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 10);
            return;
        }

        if (bHeart)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 8);
            return;
        }

        if (bEye)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 7);
            return;
        }

        if (bBrain)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 9);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 6);
        }
        return;
    }

    if (bCubedFlail)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 11);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 6);
    }
}
