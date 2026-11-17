struct D2DynamicPathStrc;
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);                       // 0x006488A0
void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear);                            // 0x00649030
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

inline unsigned int SEED_RollLimitedRandomNumber_004D1EC0(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        if ((nMax - 1) & nMax)
        {
            return (unsigned int)lSeed % nMax;
        }
        return (unsigned int)lSeed & (nMax - 1);
    }
    return 0;
}

inline int UNITS_GetClassId_004D1EC0(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x004D1EC0
int __fastcall sub_004D1EC0_CltHitRolledRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2SeedStrc* pSeed = &pMissile->pSeed;
    if ((int)SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) > 0)
    {
        return 1;
    }

    const int nMissile = UNITS_GetClassId_004D1EC0(pMissile) + SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) + 1;
    D2UnitStrc* pNew = sub_004CDBA0_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNew->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        sub_00649030_SetPathFlag40(pNewPath, 0);
    }

    return 1;
}
