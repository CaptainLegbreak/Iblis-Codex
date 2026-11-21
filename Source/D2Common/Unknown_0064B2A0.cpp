#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304

static inline D2MissilesTxt* GetMissileRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gpDataTables_00744304->nMissilesTxtRecordCount)
        return &gpDataTables_00744304->pMissilesTxt[nMissileId];
    return 0;
}

// 0x0064B2A0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    D2MissilesTxt* pRecord = GetMissileRecord(nMissileId);
    if (!pRecord)
        return 0;
    if (nLevel <= 0)
        return pRecord->nElementLength;

    int nBonus;
    if (nLevel > 16)
        nBonus = 7 * pRecord->nElementLengthPerLevel[0] + 8 * pRecord->nElementLengthPerLevel[1] + (nLevel - 16) * pRecord->nElementLengthPerLevel[2];
    else if (nLevel > 8)
        nBonus = 7 * pRecord->nElementLengthPerLevel[0] + (nLevel - 8) * pRecord->nElementLengthPerLevel[1];
    else
        nBonus = (nLevel - 1) * pRecord->nElementLengthPerLevel[0];
    return pRecord->nElementLength + nBonus;
}
