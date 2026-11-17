#include "D2Game.h"

struct D2QuestCallbacks0058EA50Strc;
struct D2QuestData0058EA50Strc;

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nNPCNo;
    short nMessageIndex;
    unsigned short unk0x1A;
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
};

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2QuestCallbacks0058EA50Strc
{
    void* pfCallbackA0;
    unsigned char unk_A4[0x28];
    void* pfCallbackCC;
    unsigned char unk_D0[0x3C - 0x30];
};

struct D2QuestData0058EA50Strc
{
    unsigned char unk_00[0x0A];
    unsigned char nA;
    unsigned char nB;
    unsigned char nC;
    unsigned char unk_0D[0x18 - 0x0D];
    int n18;
    unsigned char unk_1C[0xA0 - 0x1C];
    D2QuestCallbacks0058EA50Strc tCallbacks;
    void* pRecordDC;
    int nE0;
    unsigned char unk_E4[4];
    void* pfStatusFilterE8;
    void* pfActiveFilterEC;
};

extern unsigned char gtRecord_00732FF8[]; // 0x00732FF8
void __fastcall sub_00586B50_Callback(); // 0x00586B50
void __fastcall sub_0058E990_Callback(); // 0x0058E990
void __fastcall sub_00586C40_StatusFilterCallback(); // 0x00586C40
void __fastcall sub_00586C50_ActiveFilterCallback(); // 0x00586C50

// 0x0058E990
void __fastcall ACT5Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nMessageIndex = pQuestArg->nMessageIndex;

    switch (pQuestArg->nNPCNo)
    {
    case 520:
    {
        if (nMessageIndex == 20003)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nNPCNo);
        }
        return;
    }
    case 512:
    {
        if (nMessageIndex == 20014)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nNPCNo);
        }
        return;
    }
    case 513:
    {
        if (nMessageIndex == 20039 || nMessageIndex == 20038 || nMessageIndex == 20037)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nNPCNo);

            D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestArg->pGame, 31);
            if (!pQuest || pQuest->fState)
            {
                return;
            }

            if (!pQuest->bNotIntro)
            {
                return;
            }

            pQuest->fState = 1;
        }
        return;
    }
    case 514:
    {
        if (nMessageIndex == 20054 || nMessageIndex == 20053 || nMessageIndex == 20055)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nNPCNo);
        }
        return;
    }
    case 515:
    {
        if (nMessageIndex == 20067 || nMessageIndex == 20066 || nMessageIndex == 20065)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nNPCNo);
        }
        return;
    }
    default:
        break;
    }
}

// 0x0058EA50
void __fastcall sub_0058EA50_InitQuestCallbacks(D2QuestData0058EA50Strc* pQuestData)
{
    memset(&pQuestData->tCallbacks, 0, sizeof(pQuestData->tCallbacks));
    pQuestData->tCallbacks.pfCallbackA0 = (void*)sub_00586B50_Callback;
    pQuestData->tCallbacks.pfCallbackCC = (void*)sub_0058E990_Callback;
    pQuestData->pRecordDC = gtRecord_00732FF8;
    pQuestData->nA = 1;
    pQuestData->nC = 0;
    pQuestData->nB = 0;
    pQuestData->n18 = 0;
    pQuestData->nE0 = 0x2A;
    pQuestData->pfStatusFilterE8 = (void*)sub_00586C40_StatusFilterCallback;
    pQuestData->pfActiveFilterEC = (void*)sub_00586C50_ActiveFilterCallback;
}

#include "gen/data/Source/D2Game/Unknown_0058E990.inc"
