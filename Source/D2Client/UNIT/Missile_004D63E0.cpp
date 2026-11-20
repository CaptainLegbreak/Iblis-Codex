#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"





extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, int nX, int nY);                                    // 0x00648AD0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
int __stdcall sub_0064A3B0(D2UnitStrc* pMissile);                                                         // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nValue);                                        // 0x0064A710
int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                                    // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nValue);                                        // 0x0064A760
int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);                                               // 0x0064A780
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40
int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                          // 0x00650E50

static __forceinline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004D63E0
void __fastcall sub_004D63E0_CltDoZigZag(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nUpdateInterval = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0(pMissile) % nUpdateInterval)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    if (!pSeed)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    SEED_InitLowSeed(pSeed, sub_0064A730_GetMissileTargetStatus(pMissile));

    const unsigned int nPackedOffset = sub_0064A780_targetValue(pMissile);
    const int nPreviousOffsetX = (short)nPackedOffset;
    const int nPreviousOffsetY = (short)(nPackedOffset >> 16);

    int nSignedOffsetX;
    int nSignedOffsetY;
    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nSignedOffsetX = nPreviousOffsetX;
        nSignedOffsetY = -nPreviousOffsetY;
    }
    else
    {
        nSignedOffsetX = -nPreviousOffsetX;
        nSignedOffsetY = nPreviousOffsetY;
    }

    int nNextOffsetX = (nSignedOffsetY + 4 * nPreviousOffsetX) / 4;
    int nNextOffsetY = (nSignedOffsetX + 4 * nPreviousOffsetY) / 4;
    if (!nNextOffsetX)
    {
        nNextOffsetX = 1;
    }

    if (!nNextOffsetY)
    {
        nNextOffsetY = 1;
    }

    sub_00648AD0(pMissile->pDynamicPath, nNextOffsetX + CLIENTS_GetUnitX(pMissile), nNextOffsetY + CLIENTS_GetUnitY(pMissile));
    D2Common_10142(pMissile->pDynamicPath, pMissile, 0);

    MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
    const unsigned short nPackedOffsetX = (unsigned short)nNextOffsetX;
    const unsigned short nPackedOffsetY = (unsigned short)nNextOffsetY;
    MISSILE_SetTargetY(pMissile, nPackedOffsetX + (nPackedOffsetY << 16));

    sub_004D30C0_CltDoCommon(pMissile);
}
