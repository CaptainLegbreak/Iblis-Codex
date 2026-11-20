#include "D2Game.h"
#include "D2Structs.h"

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
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};


#define UNIT_MONSTER 1

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
D2AiCmdStrc* __fastcall AIGENERAL_AllocAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058EC90

// build: context AIGENERAL_GetAiControlFromUnit
static D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EF40
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd)
{
    D2AiCmdStrc* pCopy = AIGENERAL_AllocAiCommand(pGame, pUnit);
    memcpy(pCopy->nCmdParam, pAiCmd->nCmdParam, sizeof(pCopy->nCmdParam));

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (pAiControl)
    {
        pAiControl->pCurrentCmd = pCopy;

        while (!pAiControl)
        {
        }
    }
}
