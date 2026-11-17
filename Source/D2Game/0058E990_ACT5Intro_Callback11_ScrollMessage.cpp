struct D2UnitStrc;
struct D2GameStrc;

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

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId);             // 0x00572360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

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
