#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

struct D2MonsterDataStrc;

struct D2AiCmdStrc;

struct D2MinionListStrc;

struct Sub0058EE80;

struct Data0058EE80;

struct Unit0058EE80;

struct Sub0058F000;

struct Data0058F000;

struct Unit0058F000;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Sub0058EE80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwValue20;
};

struct Data0058EE80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    Sub0058EE80* f_28;
};

struct Unit0058EE80 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0058EE80* pData;
};

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

struct Sub0058F000 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwField38;
};

struct Data0058F000 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    Sub0058F000* f_28;
};

struct Unit0058F000 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0058F000* pData;
};

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EBC0
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc* pGame)
{
    D2AiControlStrc* pAiControl = (D2AiControlStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2AiControlStrc), ".\\Ai\\AiGeneral.cpp", 0x1B, 0);
    memset(pAiControl, 0, sizeof(D2AiControlStrc));
    pAiControl->dwOwnerGUIDEx = -1;
    pAiControl->dwOwnerTypeEx = UNIT_MONSTER;
    pAiControl->dwOwnerGUID = -1;
    pAiControl->dwOwnerType = UNIT_MONSTER;

    return pAiControl;
}

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

// 0x0058EE80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0058EE80(Unit0058EE80* pUnit) {
    Data0058EE80* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    Sub0058EE80* pSub = pData ? pData->f_28 : 0;
    if (!pSub) {
        return 0;
    }
    return pSub->dwValue20;
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

// 0x0058EFA0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet)
{
    if (!AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet))
    {
        D2AiCmdStrc tAiCmd;
        tAiCmd.nCmdParam[0] = nCmdParam;
        tAiCmd.nCmdParam[1] = 0;
        tAiCmd.nCmdParam[2] = 0;
        tAiCmd.nCmdParam[3] = 0;
        tAiCmd.nCmdParam[4] = 0;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &tAiCmd);
    }

    return AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet);
}

// 0x0058F000
extern "C" __declspec(dllexport) unsigned int* __stdcall sub_0058F000(Unit0058F000* pUnit) {
    Sub0058F000* pSub;
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pSub = pUnit->pData->f_28;
    } else {
        pSub = 0;
    }
    return &pSub->dwField38;
}

// 0x0058F0D0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    if (!pAiControl->pGame)
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
}

inline void AIGENERAL_SetOwnerData_Inl(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (bSetFlag2)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 2, UNIT_MONSTER);
    }

    if (bSetFlag1)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, UNIT_MONSTER, UNIT_MONSTER);
    }

    pAiControl->dwOwnerGUIDEx = nOwnerGUID;
    pAiControl->dwOwnerTypeEx = nOwnerType;
    pAiControl->pGame = pGame;
}

// 0x0058F530
static __declspec(noinline) void __stdcall sub_0058F530_LinkMinions(D2UnitStrc* pUnit, D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pList = pAiControl->pMinionList;
    if (!pList)
    {
        return;
    }

    D2GameStrc* pGame = pAiControl->pGame;
    for (D2MinionListStrc* pMinionList = pList; pMinionList; pMinionList = pMinionList->pNext)
    {
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            AIGENERAL_SetOwnerData_Inl(pGame, pMinion, pMinionList->dwMinionGUID, UNIT_MONSTER, UNIT_MONSTER, UNIT_MONSTER);
            AIGENERAL_SetOwnerData_Inl(pGame, pUnit, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pMinion, pUnit);

            do
            {
                D2UnitStrc* pTemp = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pList->dwMinionGUID);
                if (pTemp && pTemp != pMinion)
                {
                    AIGENERAL_SetOwnerData_Inl(pGame, pTemp, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
                    AIGENERAL_AllocMinionList(pGame, pMinion, pTemp);
                }
                pList = pList->pNext;
            }
            while (pList);
            return;
        }
    }
}

// 0x0058F660
static __declspec(noinline) void sub_0058F660_ReleaseMinions(D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pMinionList = pAiControl->pMinionList;
    D2GameStrc* pGame = pAiControl->pGame;
    while (pMinionList)
    {
        AIGENERAL_SetOwnerData_Inl(pGame, SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID), -1, UNIT_MONSTER, 0, 0);
        pMinionList = pMinionList->pNext;
    }
}

// 0x0058F6C0
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!AIUTIL_CheckAiControlFlag(pAiControl, UNIT_MONSTER))
    {
        return;
    }

    if (AIUTIL_CheckAiControlFlag(pAiControl, 2))
    {
        sub_0058F530_LinkMinions(pUnit, pAiControl);
    }
    else
    {
        sub_0058F660_ReleaseMinions(pAiControl);
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
