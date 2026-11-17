struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2ItemDropStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    char pad0x14[0xA4];
    unsigned int dwDropItemCode;
};

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char pad0x1C[0x30];
    int bBusy;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
        int nOldLevel;
    };
    union
    {
        unsigned short nMessageIndex;
        int nNewLevel;
    };
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char unk0xE4[0x0C];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act4Quest3Strc
{
    char pad0x00[0x02];
    unsigned char bCainActivated;
    char pad0x03[0x0D];
    int nHellforgeHammersInGame;
    char pad0x14[0x08];
    unsigned char bSoulstoneAcquired;
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    char pad0x03[0x19];
    int nGidbinnsInGame;
    unsigned char bPlayerWithGidbinnDropped;
    char pad0x21[0x0B];
    int nAltarObjectMode;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
    unsigned char unk0x01;
    unsigned char unk0x02;
    char pad0x03[0x09];
    unsigned char unk0x0C;
    char pad0x0D[0x03];
    int nGoldenBirdsInGame;
    unsigned char bJadeFigurineDropped;
    unsigned char bPlayerDroppedWithItem;
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
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall ACT3Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B9E70

// 0x005B64E0
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' hfh'))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15))
    {
        return;
    }

    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
    {
        pQuestData->fState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 5) == 1)
    {
        ((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired = 1;
        pQuestData->fLastState = 4;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
}

// 0x005B72B0
bool __fastcall ACT3Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 254)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 15))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' bbb'))
        {
            return true;
        }
    }

    return false;
}

// 0x005B8CC0
bool __fastcall ACT3Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 19, 13) ? 13 : 11;
        return true;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;

    *pStatus = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
    {
        *pStatus = 4;
        return true;
    }

    if (pQuestDataEx->bPlayerWithGidbinnDropped)
    {
        *pStatus = (pQuest->pGame->nGameType == 3) + 7;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 6))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 8))
        {
            *pStatus = 6;
        }
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 7))
        {
            *pStatus = 5;
        }
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 4))
    {
        *pStatus = (pQuestDataEx->bGidbinnDropped == 1) + 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 3))
    {
        *pStatus = 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 2))
    {
        *pStatus = 1;
    }

    return true;
}

// 0x005BA9E0
void __fastcall ACT3Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    bool bGoldAcquired = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
    {
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g'))
    {
        bGoldAcquired = true;
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (pQuestDataEx->nGoldenBirdsInGame != 1 || !pQuestData->bNotIntro || !pQuestDataEx->bPlayerDroppedWithItem)
    {
        return;
    }

    pQuestDataEx->bPlayerDroppedWithItem = 0;
    pQuestData->dwFlags &= 0xFFFFFF00;

    int nState = 1;
    if (bGoldAcquired)
    {
        nState = 3;
    }

    QUESTS_UnitIterate(pQuestData, nState, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
}

// 0x005BAB60
void __fastcall ACT3Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 852);

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro || !pQuestDataEx->unk0x02 || !pQuestDataEx->unk0x0C)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    if (pPlayer)
    {
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0))
        {
            return;
        }
    }

    pQuestArg->pTarget->dwDropItemCode = ' 43j';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestData->pfCallback[8] = 0;
        pQuestDataEx->unk0x0C = 0;
        pQuestDataEx->bJadeFigurineDropped = 1;
        ++pQuestDataEx->nGoldenBirdsInGame;
        if (pQuestData->fState < 1)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 879);
        }

        if (!pQuestData->fLastState)
        {
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->unk0x02 = 0;
            return;
        }
    }
    else
    {
        pQuestDataEx->unk0x01 = 1;
    }
    pQuestDataEx->unk0x02 = 0;
}

// 0x005BBE20
bool __fastcall sub_005BBE20(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    *pStatus = pQuest->fLastState;
    if (QUESTRECORD_GetQuestState(pFlags, 21, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 21, 13) ? 13 : 11;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 21, 4))
    {
        *pStatus = ((D2Act3Quest5Strc*)pQuest->pQuestDataEx)->bOrbSmashed ? 13 : 4;
    }

    if (!pQuest->bNotIntro)
    {
        *pStatus = 0;
    }

    return true;
}
