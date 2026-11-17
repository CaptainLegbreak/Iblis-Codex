struct D2AiTableStrc { int a, b, c, d; };
struct D2MonStatsTxt { char pad[0x1E]; unsigned short wAI; };
struct D2MonsterDataStrc { D2MonStatsTxt* pMonStatsTxt; };
struct D2UnitStrc { int dwUnitType; int dwClassId; char pad[0xC]; D2MonsterDataStrc* pMonsterData; };

int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470
extern const D2AiTableStrc gpAiTable_6FD3F990[148]; // 0x0073CA18

static __forceinline D2MonStatsTxt* GetRec(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData) {
        return pUnit->pMonsterData->pMonStatsTxt;
    }
    return 0;
}
static __forceinline const D2AiTableStrc* GetByIndex(D2MonStatsTxt* pRecord)
{
    short nIndex = pRecord->wAI;
    if (nIndex >= 0 && (unsigned short)nIndex < 148) {
        return &gpAiTable_6FD3F990[nIndex];
    }
    return &gpAiTable_6FD3F990[0];
}
// 0x005B15D0
const D2AiTableStrc* __fastcall sub_005B15D0_GetAiTable(D2UnitStrc* pUnit, int nMode)
{
    D2MonStatsTxt* pRecord = GetRec(pUnit);
    if (nMode) {
        if (nMode == 10 || nMode == 11 || nMode == 12) {
            if (!UNITS_CanSwitchAI(!pUnit ? -1 : pUnit->dwClassId)) {
                return GetByIndex(pRecord);
            }
        }
        return &gpAiTable_6FD3F990[148 + nMode];
    }
    return GetByIndex(pRecord);
}

#include "gen/data/Source/D2Game/005B15D0_sub_005B15D0_GetAiTable.inc"
