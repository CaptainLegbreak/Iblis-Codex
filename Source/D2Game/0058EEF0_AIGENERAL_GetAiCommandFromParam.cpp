struct D2GameStrc;

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiControlStrc
{
    char unk0x00[0x20];
    D2AiCmdStrc* pCurrentCmd;
    D2AiCmdStrc* pLastCmd;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitInline(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    D2AiCmdStrc* pCurrentAiCmd = pAiControl->pCurrentCmd;
    if (!pCurrentAiCmd)
    {
        return 0;
    }

    D2AiCmdStrc* pAiCmd = pCurrentAiCmd->pNextCmd;
    while (pAiCmd->nCmdParam[0] != nCmdParam)
    {
        if (pAiCmd == pCurrentAiCmd)
        {
            break;
        }

        pAiCmd = pAiCmd->pNextCmd;
    }

    if (pAiCmd->nCmdParam[0] != nCmdParam)
    {
        return 0;
    }

    if (bSet)
    {
        pAiControl->pCurrentCmd = pAiCmd;
    }

    return pAiCmd;
}
