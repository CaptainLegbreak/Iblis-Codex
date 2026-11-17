struct D2GameStrc;
struct D2UnitStrc;
struct D2AiControlStrc { int nAiSpecialState; };
struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    int unk_04;
    D2UnitStrc* pTarget;
    int unk_0C[2];
    int nTargetDistance;
    int bCombat;
};
struct D2AiStateStrc { int nTargetMode; };
D2AiStateStrc* __fastcall sub_005B15D0_GetAiState(D2UnitStrc*, int); // 0x005B15D0
D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE890
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0
D2UnitStrc* __fastcall sub_005DE9D0_FindTarget(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE9D0

// 0x005B1650
int __fastcall sub_005B1650_AiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const D2AiControlStrc* v_pAiControl_22 = pAiTickParam->pAiControl;
    D2AiStateStrc* pState = sub_005B15D0_GetAiState(pUnit, v_pAiControl_22->nAiSpecialState);
    switch (pState->nTargetMode)
    {
    case 0:
        return 0;
    case 1:
        pAiTickParam->pTarget = sub_6FCCF9D0(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 2:
        pAiTickParam->pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    case 4:
        pAiTickParam->pTarget = sub_005DE9D0_FindTarget(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 5:
        pAiTickParam->pTarget = sub_005DE9D0_FindTarget(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    default:
        return 1;
    }
}
