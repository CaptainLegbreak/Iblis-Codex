struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char unk0x00[0x0E];
    short wSrvHitFunc;
    char unk0x10[0x194];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

typedef int(__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnMissileSrvHitFnCount;                                                                          // 0x0073C83C
extern MISSILESRVHITFN gpfMissileSrvHitFn[];                                                                // 0x0073C840

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AD9D0
void __fastcall sub_005AD9D0_HitAndRemoveMissile(D2GameStrc* pGame, D2UnitStrc* pMissile, int bHit)
{
    const int nMissileId = !pMissile ? -1 : pMissile->dwClassId;
    if (bHit)
    {
        const short nHitFunc = DATATBLS_GetMissilesTxtRecord(nMissileId)->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, 0);
        }
    }

    SUNIT_RemoveUnit(pGame, pMissile);
}
