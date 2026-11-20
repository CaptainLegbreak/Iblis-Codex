#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x1A4 - 0x08];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

// build: context DATATBLS_GetMissilesTxtRecord
static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __declspec(noinline) int sub_005ADA80_GetDamageTarget(D2UnitStrc* pMissile);

// 0x005ADA80
static int sub_005ADA80_GetDamageTarget(D2UnitStrc* pMissile)
{
    int nResult = 3;

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord->nMissileFlags[2 >> 3] & gdwBitMasks[2 & 7])
    {
        const int nPierceIndex = STATLIST_UnitGetStatValue(pMissile, 328, 0);
        if (nPierceIndex)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pMissile, 328, nPierceIndex - 1, 0);
        }
    }

    return nResult;
}

// build: context sub_005ADA80_Shim

// calling-convention shim (not game code)
int __fastcall sub_005ADA80_Shim(D2UnitStrc* pMissile)
{
    return sub_005ADA80_GetDamageTarget(pMissile);
}
