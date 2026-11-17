struct D2MissileDataStrc
{
    char unk0x00[0x0C];
    short nLevel;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x14 - 0x08];
    D2MissileDataStrc* pMissileData;
};

struct D2DataTablesStrc
{
    char unk0x00[0x60];
    char* pMissCode;
    unsigned int nMissCodeSize;
};

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    int nMissileId;
    int nMissileLevel;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern void* gpMissileCalcFunctions_00745828[];                                                             // 0x00745828
extern int gnMissileCalcFunctions_00745848;                                                                 // 0x00745848
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData);                                    // 0x0064B6E0
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// build: context MISSILE_GetLevel
static unsigned int MISSILE_GetLevel(D2UnitStrc* pMissile)
{
    D2MissileDataStrc* pMissileData = sub_0044BE50(pMissile) == 3 ? pMissile->pMissileData : 0;
    if (!pMissileData)
    {
        return 0;
    }

    return pMissileData->nLevel;
}

// 0x0064B7C0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel)
{
    D2MissileCalcStrc pMissileCalc;
    if (pMissile)
    {
        const int nType = sub_0044BE50(pMissile);
        if (nType != 3)
        {
            return 0;
        }

        if (nMissileId < 0)
        {
            nMissileId = pMissile->dwClassId;
        }

        if (nLevel < 0)
        {
            nLevel = MISSILE_GetLevel(pMissile);
        }
    }

    if (!sgptDataTables->pMissCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nMissCodeSize)
    {
        return 0;
    }

    pMissileCalc.pMissile = pMissile;
    pMissileCalc.pOwner = pOwner;
    pMissileCalc.nMissileId = nMissileId;
    pMissileCalc.nMissileLevel = nLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pMissCode[nCalc], sgptDataTables->nMissCodeSize - nCalc, MISSILE_GetCalcParamValue, gpMissileCalcFunctions_00745828, gnMissileCalcFunctions_00745848, &pMissileCalc);
}

#include "gen/data/Source/D2Common/0064B7C0_MISSILE_EvaluateMissileFormula.inc"
