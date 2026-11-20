#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

struct D2PlayerDataStrc;
struct D2Act1Quest6Strc;


struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    unsigned char unk_0D[0x7];
    unsigned int dwFlags;
    D2Act1Quest6Strc* pQuestDataEx;
    char unk_1C[0x8C];
    void* pfNpcDeactivate;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

struct D2QuestArgStrc { D2GameStrc* pGame; int nEvent; D2UnitStrc* pTarget; };

struct D2Act1Quest6Strc { char unk_000[0x195]; unsigned char bCainActivated; };

int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x00595B20
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*, int, D2UnitStrc*, int (__fastcall*)(D2GameStrc*, D2UnitStrc*, void*), bool); // 0x00544300

// 0x00595B20
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 6, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 6);
    }
    return 0;
}

// 0x00595BD0
int __fastcall ACT1Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 6, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 6);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 6, 2);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 3);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 4);
        }
    }
    return 0;
}

// 0x00595B80
void __fastcall sub_00595B80_HandleNpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 265)
    {
        D2Act1Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainActivated == 1)
        {
            *(unsigned char*)&pQuestData->dwFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q6_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->bCainActivated = 0;
            pQuestData->pfNpcDeactivate = 0;
        }
    }
}
