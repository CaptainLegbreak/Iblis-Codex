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

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[7];
    void* pInitFunc;
    int pInitArgs;
};

struct D2MissilesTxt
{
    char unk0x000[0x1E];
    short wCltSubMissile[3];
    char unk0x024[0x08];
    short wCltHitSubMissile[4];
    char unk0x034[0x24];
    int dwCltParam[5];
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_00465F00_RemoveClientUnit(int nUnitId, int nUnitType);                                  // 0x00465F00
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
void __fastcall sub_004D01D0_FireForward(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nSkill, int nSkillLevel, int nCount); // 0x004D01D0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

#define UNIT_INVALID 6

inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D02E0
int __fastcall sub_004D02E0_HitForward(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        if (!pUnit)
        {
            pUnit = pMissile;
        }

        int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        if (nCount < 1)
        {
            nCount = 1;
        }

        sub_004D01D0_FireForward(pOwner, pUnit, pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nCount);
        return 1;
    }

    return 1;
}

// 0x004D5710
void __fastcall sub_004D5710_CltDoPerpendicular(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && pMissile->pDynamicPath)
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) < 2)
        {
            int nDX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath) - nX;
            int nDY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath) - nY;
            MISSILE_SetTargetX(pMissile, -nDY);
            MISSILE_SetTargetY(pMissile, nDX);
        }

        if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0xB;
            tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
            tMissileParams.nX = nX;
            tMissileParams.nY = nY;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            tMissileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
            tMissileParams.nTargetX = MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = MISSILE_GetTargetY(pMissile);
            sub_004CD540_CreateMissile(&tMissileParams);
            tMissileParams.nTargetX = -MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = -MISSILE_GetTargetY(pMissile);
            sub_004CD540_CreateMissile(&tMissileParams);
        }

        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}
