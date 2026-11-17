struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2PlayerDataStrc { char unk_00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2Act5Quest3Strc { char unk_00[0xD8]; int nDefrostPotionsInGame; char unk_DC[0x26]; unsigned char unk_102; };
struct D2QuestDataStrc { int nQuestNo; D2GameStrc* pGame; unsigned char nActNo; unsigned char bNotIntro; unsigned char bActive; unsigned char fLastState; unsigned char fState; char unk_0D[0xB]; D2Act5Quest3Strc* pQuestDataEx; char unk_1C[0xC4]; int nQuestFilter; };
struct D2QuestArgStrc { D2GameStrc* pGame; int nEvent; D2UnitStrc* pTarget; D2UnitStrc* pPlayer; int unk_10; D2TextHeaderStrc* pTextControl; };
struct D2ModeChangeStrc { int unk_00[8]; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc*, D2TextHeaderStrc*, int, int); // 0x00543790
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc*, int); // 0x005452C0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc*, D2UnitStrc*, unsigned int); // 0x00558110
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc*, int, D2ModeChangeStrc*); // 0x005A7E60
extern const unsigned int gnAct5Q3MessageIndices_00734304[]; // 0x00734304
// 0x00589B00
void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (nNpcId == 527)
    {
        if (pQuestData->fState == 6)
        {
            D2ModeChangeStrc mode;
            MONSTERMODE_GetModeChangeInfo(pQuestArg->pTarget, 12, &mode);
            D2GAME_ModeChange_6FC65220(pQuestArg->pGame, &mode, 1);
        }
        return;
    }
    if (nNpcId == 513)
    {
        if (pQuestData->fState == 4)
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20656369) && !pQuestDataEx->nDefrostPotionsInGame)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 3);
            return;
        }
        if ((QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 15))
            && !pQuestDataEx->unk_102 && QUESTRECORD_GetQuestState(pFlags, 37, 8)
            && !QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 7)
            && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20327274)
            && !QUESTRECORD_GetQuestState(pFlags, 37, 8))
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 5);
    }
    if (QUESTRECORD_GetQuestState(pFlags, pQuestData->nQuestFilter, 1))
    {
        if (nNpcId == 512 && QUESTRECORD_GetQuestState(pFlags, 37, 9)) return;
        if (nNpcId == 513 && QUESTRECORD_GetQuestState(pFlags, 37, 8)) return;
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }
    if (bRewardGranted != 1 && (pQuestData->fState < 5 || bPrimaryGoalDone) && pQuestData->bNotIntro)
    {
        const unsigned int nIndex = gnAct5Q3MessageIndices_00734304[pQuestData->fState];
        if (nIndex != -1 && nIndex < 10)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

#include "gen/data/Source/D2Game/00589B00_ACT5Q3_Callback00_NpcActivate.inc"
