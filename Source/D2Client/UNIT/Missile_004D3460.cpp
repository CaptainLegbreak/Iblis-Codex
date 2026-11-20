#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"

typedef char cc_M338_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004CE050_SpawnFollowUp(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);             // 0x004CE050
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                             // 0x0064A210

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D3460
void __fastcall sub_004D3460_CltDoFollowUp(D2UnitStrc* pMissile)
{
    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
        {
            sub_004CE050_SpawnFollowUp(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwCltCalc, nMissileId, sub_0064A210(pMissile)));
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
