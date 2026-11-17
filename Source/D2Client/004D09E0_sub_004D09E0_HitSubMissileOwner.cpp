struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0x000[0x1E];
    short wCltSubMissile[3];
    char unk0x024[0x08];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath);                                 // 0x006487F0
extern "C" void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);        // 0x006488A0
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset);              // 0x00649030
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                              // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                              // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                         // 0x0064A730

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D09E0
int __fastcall sub_004D09E0_HitSubMissileOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2DynamicPathStrc* pPath = pSubMissile->pDynamicPath;
            sub_006488A0(pPath, PATH_GetDirection(pMissile->pDynamicPath));
            D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
            MISSILE_SetTargetX(pSubMissile, sub_0064A730_GetMissileTargetStatus(pMissile));
        }

        return 1;
    }

    return 1;
}
