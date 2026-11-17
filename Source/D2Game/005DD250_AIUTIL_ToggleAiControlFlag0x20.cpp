struct D2AiControlStrc { int nAiSpecialState; void* pAiParamFn; unsigned short nAiFlags; };
struct D2MonsterDataStrc { char pad[0x28]; D2AiControlStrc* pAiControl; };
struct D2UnitStrc { int dwUnitType; char pad[0x10]; D2MonsterDataStrc* pMonsterData; };
// 0x005DD250
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet)
{
    D2AiControlStrc* pAiControl;
    if (pUnit && pUnit->dwUnitType == 1) {
        D2MonsterDataStrc* m = pUnit->pMonsterData;
        if (m) { pAiControl = m->pAiControl; }
        else pAiControl = 0;
    } else pAiControl = 0;
    if (bSet)
        pAiControl->nAiFlags |= 0x20;
    else
        pAiControl->nAiFlags &= ~0x20;
}
