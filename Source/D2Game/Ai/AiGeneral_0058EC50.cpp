#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    int dwOwnerType;
    int dwAiParam[3];
    D2AiCmdStrc* pCurrentCmd;
    D2AiCmdStrc* pLastCmd;
};



#define UNIT_MONSTER 1
#define UNIT_INVALID 6

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitByType(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EC50
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (pAiControl)
    {
        switch (nIndex)
        {
        case 1:
            return pAiControl->dwAiParam[0];

        case 2:
            return pAiControl->dwAiParam[1];

        case 3:
            return pAiControl->dwAiParam[2];

        default:
            break;
        }
    }

    return 0;
}

// 0x0058EC90
D2AiCmdStrc* __fastcall AIGENERAL_AllocAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    D2AiCmdStrc* pAiCmd = (D2AiCmdStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2AiCmdStrc), ".\\Ai\\AiGeneral.cpp", 0x65, 0);
    memset(pAiCmd, 0, sizeof(D2AiCmdStrc));
    D2AiCmdStrc* pLastCmd = pAiControl->pLastCmd;
    if (!pLastCmd)
    {
        pAiControl->pLastCmd = pAiCmd;
        pAiControl->pCurrentCmd = pAiCmd;
        pAiCmd->pNextCmd = pAiCmd;
        pAiCmd->pPrevCmd = pAiCmd;
    }
    else
    {
        D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
        if (pLastCmd == pCurrentCmd)
        {
            pAiControl->pLastCmd = pAiCmd;
        }

        pAiCmd->pNextCmd = pCurrentCmd;
        pAiCmd->pPrevCmd = pAiControl->pCurrentCmd->pPrevCmd;
        pAiControl->pCurrentCmd->pPrevCmd = pAiCmd;
        pAiCmd->pPrevCmd->pNextCmd = pAiCmd;
    }

    return pAiCmd;
}

// 0x0058ED10
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return;
    }

    D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
    if (!pCurrentCmd)
    {
        return;
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

    FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 0xA1, 0);
}
