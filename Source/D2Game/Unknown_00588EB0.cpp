#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};


struct D2Act5Quest3Strc
{
    char unk0x00[0xAC];
    unsigned char bMalahIntroActivated;
    char unk0xAD[0x101 - 0xAD];
    unsigned char bMalahActivated;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    void* pGame;
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

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);                 // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

// 0x00588EB0
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 37, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 37, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 33);
    }

    return 0;
}

// 0x00588F80
void __fastcall ACT5Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nClassId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if ((short)nClassId != 0x201)
    {
        return;
    }

    if (pQuestDataEx->bMalahIntroActivated)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bMalahIntroActivated = 0;
    }

    if (pQuestData->bNotIntro && pQuestDataEx->bMalahActivated && pQuestData->fLastState < 4)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bMalahActivated = 0;
    }
}
