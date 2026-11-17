#include "D2Common.h"

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBD4];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

// 0x00627BB0
int __fastcall sub_00627BB0_ItemCalcGetStatValue(int nStatId, int nType, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (pItemCalc && pItemCalc->pUnit && nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        if (nStatId == 19)
        {
            return UNITS_GetAttackRate(pItemCalc->pUnit);
        }
        switch (nType)
        {
        case 1:
            return STATLIST_GetUnitBaseStat(pItemCalc->pUnit, nStatId, 0);
        case 2:
            return STATLIST_UnitGetItemStatOrSkillStatValue(pItemCalc->pUnit, nStatId, 0);
        default:
            return STATLIST_UnitGetStatValue(pItemCalc->pUnit, nStatId, 0);
        }
    }
    return 0;
}
