#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameTypes.h"




typedef int (__fastcall* AIBAAL_CullFn)(D2UnitStrc*, D2UnitStrc*);

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pKiller, int bSkipDrops); // 0x0057CCB0
int __fastcall AIBAAL_CullPotentialTargets(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005FC000
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd); // 0x005FCB60
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __stdcall shim_1(void* p1, void* p2);

// build: symbol ?AIBAAL_GetUberTarget@* 0x005FBDD0
// build: context AIBAAL_GetUberTarget
static D2UnitStrc* __stdcall AIBAAL_GetUberTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, void* pArgs, AIBAAL_CullFn pfCull)
{

    int a = shim_1(&pGame, &pMax);
    int b = shim_1(&pCount, &pArgs);
    a += shim_1((void*)a, (void*)b);
    b += shim_1((void*)a, (void*)b);
    a += shim_1((void*)a, (void*)b);
    shim_1(pUnit, &pfCull);
    shim_1(pUnit, 0);
    return (D2UnitStrc*)(a + b);
}

// build: context sub_005FC630
static int __stdcall sub_005FC630(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nMax, int nCount, D2AiCmdStrc* pAiCmd)
{

    pTarget->dwUnitType = 0;
    pUnit->dwUnitType = 1;
    shim_1(&pGame, &pAiControl);
    return shim_1(&nMax, &nCount) + shim_1(&pAiCmd, 0);
}

// 0x005FD210
void __fastcall AITHINK_Fn140_BaalCrabClone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    int nMax = 0;
    int nCount = 0;
    D2UnitStrc* pTarget = AIBAAL_GetUberTarget(pGame, pUnit, &nMax, &nCount, 0, AIBAAL_CullPotentialTargets);

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        aiCmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam = sub_005FC630(pGame, pUnit, pAiControl, pTarget, nMax, nCount, pAiCmd);
    if (nParam == 7 || nParam == 9 || nParam == 14 || nParam == 15)
    {
        nParam = 2;
    }

    if (pTarget)
    {
        AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, nParam, pAiCmd);
        AITACTICS_Idle(pGame, pUnit, 25);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}
