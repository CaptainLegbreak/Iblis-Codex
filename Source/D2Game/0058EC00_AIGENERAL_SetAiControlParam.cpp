struct D2GameStrc;

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[3];
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
#define UNIT_INVALID 6

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitType(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EC00
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitType(pMonster);
    if (!pAiControl)
    {
        return;
    }

    switch (nIndex)
    {
    case 1:
        pAiControl->dwAiParam[0] = nParamValue;
        break;

    case 2:
        pAiControl->dwAiParam[1] = nParamValue;
        break;

    case 3:
        pAiControl->dwAiParam[2] = nParamValue;
        break;

    default:
        break;
    }
}

// 0x0058EEA0
void __fastcall sub_0058EEA0_StepCurrentAiCommand(D2UnitStrc* pUnit, int nSteps, D2AiCmdStrc* pAiCmd)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitType(pUnit);
    if (!pAiControl)
    {
        return;
    }

    if (!pAiCmd)
    {
        pAiCmd = pAiControl->pCurrentCmd;
        if (!pAiCmd)
        {
            return;
        }

        if (nSteps < 0)
        {
            for (int i = nSteps; i < 0; ++i)
            {
                pAiCmd = pAiCmd->pPrevCmd;
            }
        }
        else
        {
            while (nSteps)
            {
                --nSteps;
                pAiCmd = pAiCmd->pNextCmd;
            }
        }
    }

    pAiControl->pCurrentCmd = pAiCmd;
}
