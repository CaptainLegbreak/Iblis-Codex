struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char unk0x00[0x38];
    int dwParam[5];
    int dwSrvCalcParam[3];
    int dwCltParam[5];
    int dwHitPar[3];
    int dwDmgPar[2];
    char unk0x80[0x16];
    short nRange;
    short nLevRange;
    char unk0x9A[0x10A];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

#define UNIT_MISSILE 3

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0064B340
int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel)
{
    int nResult;
    {
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        nResult = 0;
        goto Done;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        nResult = 0;
        goto Done;
    }

    switch (nParamId)
    {
    case 0: nResult = pMissilesTxtRecord->dwParam[0];
    goto Done;
    case 1: nResult = pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 2: nResult = pMissilesTxtRecord->dwParam[2];
    goto Done;
    case 3: nResult = pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 4: nResult = pMissilesTxtRecord->dwParam[4];
    goto Done;
    case 5: nResult = pMissilesTxtRecord->dwCltParam[0];
    goto Done;
    case 6: nResult = pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 7: nResult = pMissilesTxtRecord->dwCltParam[2];
    goto Done;
    case 8: nResult = pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 9: nResult = pMissilesTxtRecord->dwCltParam[4];
    goto Done;
    case 10: nResult = pMissilesTxtRecord->dwSrvCalcParam[0];
    goto Done;
    case 11: nResult = pMissilesTxtRecord->dwSrvCalcParam[1];
    goto Done;
    case 12: nResult = pMissilesTxtRecord->dwSrvCalcParam[2];
    goto Done;
    case 13: nResult = pMissilesTxtRecord->dwHitPar[0];
    goto Done;
    case 14: nResult = pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 15: nResult = pMissilesTxtRecord->dwHitPar[2];
    goto Done;
    case 16: nResult = pMissilesTxtRecord->dwDmgPar[0];
    goto Done;
    case 17: nResult = pMissilesTxtRecord->dwDmgPar[1];
    goto Done;
    case 18: nResult = nLevel;
    goto Done;
    case 19: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 20: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 21: nResult = sub_0064B2A0_GetMissileElementLength(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 22: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 23: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 24: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 25: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 26: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 27: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 28: nResult = pMissilesTxtRecord->nLevRange * nLevel + pMissilesTxtRecord->nRange;
    goto Done;
    case 29: nResult = pMissilesTxtRecord->dwParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 30: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[1]);
    goto Done;
    case 31: nResult = pMissilesTxtRecord->dwParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 32: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[2], pMissilesTxtRecord->dwParam[3]);
    goto Done;
    case 33: nResult = pMissilesTxtRecord->dwCltParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 34: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1]);
    goto Done;
    case 35: nResult = pMissilesTxtRecord->dwCltParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 36: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[3]);
    goto Done;
    case 37: nResult = pMissilesTxtRecord->dwSrvCalcParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwSrvCalcParam[1];
    goto Done;
    case 38: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwSrvCalcParam[0], pMissilesTxtRecord->dwSrvCalcParam[1]);
    goto Done;
    case 39: nResult = pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 40: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1]);
    goto Done;
    case 41: nResult = pMissilesTxtRecord->dwDmgPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwDmgPar[1];
    goto Done;
    case 42: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwDmgPar[0], pMissilesTxtRecord->dwDmgPar[1]);
    goto Done;
    }

    nResult = 0;
    }
Done:
    return nResult;
}
