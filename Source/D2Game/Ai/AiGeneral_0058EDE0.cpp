#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"


struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};




extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2AiCmdStrc* __fastcall AIGENERAL_AllocAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                     // 0x0058EC90

__forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EDE0
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1 || !pUnit->pMonsterData)
    {
        return;
    }

    D2AiControlStrc* pAiControl = pUnit->pMonsterData->pAiControl;
    if (!pAiControl || !pAiControl->pLastCmd)
    {
        return;
    }

    do
    {
        if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        {
            D2AiControlStrc* pCurrentAiControl = pUnit->pMonsterData->pAiControl;
            if (pCurrentAiControl)
            {
                D2AiCmdStrc* pCurrentCmd = pCurrentAiControl->pCurrentCmd;
                if (pCurrentCmd)
                {
                    if (pCurrentCmd != pCurrentCmd->pNextCmd)
                    {
                        if (pCurrentAiControl->pLastCmd == pCurrentCmd)
                        {
                            pCurrentAiControl->pLastCmd = pCurrentCmd->pNextCmd;
                        }

                        pCurrentAiControl->pCurrentCmd = pCurrentCmd->pNextCmd;
                        pCurrentCmd->pPrevCmd->pNextCmd = pCurrentCmd->pNextCmd;
                        pCurrentCmd->pNextCmd->pPrevCmd = pCurrentCmd->pPrevCmd;
                    }
                    else
                    {
                        pCurrentAiControl->pLastCmd = 0;
                        pCurrentAiControl->pCurrentCmd = 0;
                    }

                    FOG_FreePool(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 0xA1, 0);
                }
            }
        }
    }
    while (pAiControl->pLastCmd);
}

// 0x0058F730
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl || !pAiControl->pGame)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : 6;
    if (nOwnerType != 1)
    {
        return;
    }

    D2AiControlStrc* pOwnerAiControl = AIGENERAL_GetAiControlFromUnit(pOwner);
    if (!pOwnerAiControl)
    {
        return;
    }

    for (D2MinionListStrc* pMinionList = pOwnerAiControl->pMinionList; pMinionList; pMinionList = pMinionList->pNext)
    {
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pOwnerAiControl->pGame, 1, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            D2AiCmdStrc* pCopy = AIGENERAL_AllocAiCommand(pGame, pMinion);
            if (pCopy)
            {
                memcpy(pCopy->nCmdParam, pAiCmd->nCmdParam, sizeof(pCopy->nCmdParam));
                D2AiControlStrc* pMinionAiControl = AIGENERAL_GetAiControlFromUnit(pMinion);
                if (pMinionAiControl)
                {
                    pMinionAiControl->pCurrentCmd = pCopy;
                }
            }
        }
    }
}
