struct D2UnitStrc;

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    int nMissileId;
    int nMissileLevel;
};

int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel); // 0x0064B340

// 0x0064B6E0
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData)
{
    D2MissileCalcStrc* pMissileCalc = (D2MissileCalcStrc*)pUserData;
    if (!pMissileCalc)
    {
        return 0;
    }

    return MISSILE_GetSpecialParamValue(pMissileCalc->pMissile, pMissileCalc->pOwner, nParamId, pMissileCalc->nMissileId, pMissileCalc->nMissileLevel);
}
