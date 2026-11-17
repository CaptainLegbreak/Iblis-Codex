struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[7];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

struct D2SkillsTxt
{
    char unk0x00[0xEE];
    short wCltMissileC;
    char unk0xF0[0x14C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004F3680
static int __stdcall sub_004F3680_SpawnMissileTowardTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;

    const int nDeltaX = nTargetX - UNITS_GetUnitXPosition(pUnit);
    const int nDeltaY = nTargetY - UNITS_GetUnitYPosition(pUnit);
    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
    if (nDistance <= 1)
        nDistance = 1;

    const int nX = UNITS_GetUnitXPosition(pUnit) + 2 * nDeltaX / nDistance;
    const int nY = UNITS_GetUnitYPosition(pUnit) + 2 * nDeltaY / nDistance;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = 5 * nDeltaX;
    missileParams.nTargetY = 5 * nDeltaY;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&missileParams);
    if (!pMissile)
        return 0;

    D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY));
    return 1;
}

// 0x004F3810
int __fastcall sub_004F3810_SkillCltStartMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
        if (pSkillsTxt)
        {
            const int nMissileId = pSkillsTxt->wCltMissileC;
            if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
                return sub_004F3680_SpawnMissileTowardTarget(pUnit, nSkillId, nSkillLevel, nMissileId);
        }
    }

    return 0;
}
