#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2MissileDataStrc
{
    unsigned char unk_00[0x18];
    int nOwnerType;
    unsigned int dwOwnerGUID;
};


struct D2MissilesTxt
{
    unsigned char unk_00[0x04];
    unsigned int dwMissileFlags;
    unsigned char unk_08[0x19C];
};

extern const unsigned char gbBitMasks_006CE268[]; // 0x006CE268

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        return &sgptDataTable->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0064A400
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;

    if (pMissile && (!pMissile ? 6 : pMissile->dwUnitType) == 3)
    {
        pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->dwMissileFlags & gbBitMasks_006CE268[0])
        {
            D2MissileDataStrc* pMissileData = pMissile->pMissileData;
            if (pMissileData)
            {
                if (pOwner)
                {
                    pMissileData->nOwnerType = pOwner->dwUnitType;
                    pMissileData->dwOwnerGUID = pOwner->dwUnitId;
                }
                else
                {
                    pMissileData->dwOwnerGUID = -1;
                }
            }
        }
    }
}
