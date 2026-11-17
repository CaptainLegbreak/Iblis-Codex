struct D2BitBufferStrc;
struct D2UnitStrc;

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
};

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C310
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110

// 0x005BA170
bool __fastcall ACT3Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 1))
    {
        *pStatus = 5;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 20, 13) ? 13 : 11;
    }
    else
    {
        *pStatus = 0;
        D2UnitStrc* pBird = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g');
        D2UnitStrc* pJade = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j');
        if (pBird)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 4) != 0) + 3;
        }
        else if (pJade)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 2) != 0) + 1;
        }
        else if (pQuest->bNotIntro)
        {
            if (pQuest->fLastState >= 6)
            {
                *pStatus = (pQuest->pGame->nGameType != 3) + 6;
            }
            else
            {
                *pStatus = pQuest->fLastState;
            }
        }
    }

    return true;
}
