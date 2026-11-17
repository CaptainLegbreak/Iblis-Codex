struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

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
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28;
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

struct D2MissilesTxt
{
    char unk0x00[0x96];
    short wRange;
    char unk0x98[0x10C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_0063EE10_GetMonsterDirectionDelta(D2UnitStrc* pUnit, int* pX, int* pY);                  // 0x0063EE10
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

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

// 0x004CD2D0
static int sub_004CD2D0_GetFrameDelay(int nFrames)
{
    if (nFrames < 0x96)
        return 0x14;
    if (nFrames < 0xC8)
        return 0xF;
    if (nFrames < 0xE1)
        return 0xA;
    return nFrames < 0x177 ? 5 : 0x19;
}

// 0x004D1FA0
static void __stdcall sub_004D1FA0_SpawnBehindOwner(int nMissileId, D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pOwner, &nDirX, &nDirY);
    D2_ASSERT(nDirX || nDirY, 0x1850);
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissileId;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile) + SEED_RollRandomNumber(&pMissile->tSeed) % 20 - 10;
    tParams.nY = UNITS_GetUnitYPosition(pMissile) + SEED_RollRandomNumber(&pMissile->tSeed) % 20 - 10;
    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
    if (!pNew)
        return;
    D2_ASSERT(SKILLS_GetMissilesTxtRecord(nMissileId)->wRange == 25, 0x1861);
    int nScreenX = nDirX * -25;
    int nScreenY = nDirY * -25;
    int nOffsetX = nDirX;
    int nOffsetY = nDirY;
    sub_00643260(&nScreenX, &nScreenY);
    sub_00643260(&nOffsetX, &nOffsetY);
    sub_004DA1D0_SetMotionVectorA(pNew, nScreenX, nScreenY, 0x190);
    sub_004DA200_SetMotionVectorB(pNew, nOffsetX, nOffsetY, -0x10, 1);
    sub_004DA350_UpdateMotion(pNew);
}

// 0x004D7690
void __fastcall sub_004D7690_CltDoOwnerSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int nValue = MISSILE_GetTargetX(pMissile);
    if (!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    if (!nValue)
    {
        if (SEED_RollRandomNumber(&pMissile->tSeed) & 1)
            sub_004D1FA0_SpawnBehindOwner(0x1A0, pOwner, pMissile);
        else
            sub_004D1FA0_SpawnBehindOwner(0x1A6, pOwner, pMissile);
        nValue = sub_004CD2D0_GetFrameDelay(sub_0064A3B0_GetElapsedFrames(pMissile));
    }
    MISSILE_SetTargetX(pMissile, nValue - 1);
    sub_004D30C0_CltDoCommon(pMissile);
}
