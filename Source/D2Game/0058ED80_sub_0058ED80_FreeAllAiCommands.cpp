struct D2MapAIStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
};

struct D2MinionListStrc
{
    int nUnitGUID;
    D2MinionListStrc* pNext;
};

struct D2AiControlStrc
{
    char unk0x00[0x20];
    D2AiCmdStrc* pCurrentCmd;
    D2AiCmdStrc* pLastCmd;
    char unk0x28[0x0C];
    D2MinionListStrc* pMinionList;
    D2MapAIStrc* pMapAi;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAi);                                  // 0x00666130

// 0x0058ED80
static void sub_0058ED80_FreeAllAiCommands(D2GameStrc* pGame, D2AiControlStrc* pAiControl)
{
    while (pAiControl->pLastCmd)
    {
        D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
        if (!pCurrentCmd)
        {
            break;
        }

        if (pCurrentCmd != pCurrentCmd->pNextCmd)
        {
            if (pAiControl->pLastCmd == pCurrentCmd)
            {
                pAiControl->pLastCmd = pCurrentCmd->pNextCmd;
            }

            pAiControl->pCurrentCmd = pCurrentCmd->pNextCmd;
            pCurrentCmd->pPrevCmd->pNextCmd = pCurrentCmd->pNextCmd;
            pCurrentCmd->pNextCmd->pPrevCmd = pCurrentCmd->pPrevCmd;
        }
        else
        {
            pAiControl->pLastCmd = 0;
            pAiControl->pCurrentCmd = 0;
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 196, 0);
    }
}

// 0x0058F810
void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl)
{
    if (!pAiControl)
    {
        return;
    }

    if (pAiControl->pMapAi)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pAiControl->pMapAi);
    }

    D2MinionListStrc* pNext = 0;
    for (D2MinionListStrc* i = pAiControl->pMinionList; i; i = pNext)
    {
        pNext = i->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, i, ".\\Ai\\AiGeneral.cpp", 582, 0);
    }

    sub_0058ED80_FreeAllAiCommands(pGame, pAiControl);
    FOG_FreeServerMemory(pGame->pMemoryPool, pAiControl, ".\\Ai\\AiGeneral.cpp", 413, 0);
}
