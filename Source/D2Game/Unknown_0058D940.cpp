#include "D2Game.h"
#include "D2GameStrc.h"


struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    unsigned short nNPCNo;
    unsigned short unk0x16;
    unsigned short nMessageIndex;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0xD8];
    int eFilter;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

// 0x0058D940
void __fastcall sub_0058D940_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    switch (pQuestArg->nMessageIndex)
    {
    case 20178:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 4);
        break;
    }
    case 20177:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 5);
        break;
    }
    case 20179:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 6);
        break;
    }
    case 20175:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 7);
        break;
    }
    case 20180:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 8);
        break;
    }
    case 20176:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 9);
        break;
    }
    }
}
