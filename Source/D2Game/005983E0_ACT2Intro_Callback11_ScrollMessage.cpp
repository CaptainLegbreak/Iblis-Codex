struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    void* pTextControl;
    int nNPCNo;
    unsigned short nMessageIndex;
};
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360

// 0x005983E0
void __fastcall ACT2Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = pQuestArg->nNPCNo;
    const unsigned short nMessage = pQuestArg->nMessageIndex;
    switch (nNpcId)
    {
    case 199:
        if (nMessage == 204 || nMessage == 203)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 200:
        if (nMessage == 231 || nMessage == 230)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 210:
        if (nMessage == 242 || nMessage == 241)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 178:
        if (nMessage == 264 || nMessage == 263)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 177:
        if (nMessage == 286 || nMessage == 285)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 198:
        if (nMessage == 190)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 175:
        if (nMessage == 215)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 202:
        if (nMessage == 274)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    }
}
