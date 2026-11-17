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
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwMissileFlags;
    unsigned short wCltDoFunc;
    unsigned short wCltHitFunc;
    unsigned short wSrvDoFunc;
    unsigned short wSrvHitFunc;
    unsigned short wSrvDmgFunc;
    unsigned short wTravelSound;
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wCltSubMissile[3];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgSound;
    unsigned short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

struct D2ActiveRoomStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                        // 0x00476A80
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
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

// 0x004D2990
static void __stdcall sub_004D2990_SpawnAtFreeSpot(D2UnitStrc* pOwner, int nX, int nY, D2UnitStrc* pMissile)
{
    int bRetry = 1;
    int nTries = 0;
    if (!pMissile || !pOwner)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        return;
    while (bRetry && nTries < 4)
    {
        const int nOffsetX = 17 - SEED_RollRandomNumber(&pMissile->tSeed) % 34;
        const int nOffsetY = 17 - SEED_RollRandomNumber(&pMissile->tSeed) % 34;
        if (nOffsetX < -1 || nOffsetX > 1 || nOffsetY < -1)
        {
            if (!COLLISION_CheckMask(pRoom, nX + nOffsetX, nY + nOffsetY, 4))
            {
                nX += nOffsetX;
                nY += nOffsetY;
                bRetry = 0;
            }
        }
        ++nTries;
    }
    if (bRetry)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nMissile = 0x267;
    tParams.nY = nY;
    sub_004CD540_CreateMissile(&tParams);
    tParams.nMissile = 0x268;
    sub_004CD540_CreateMissile(&tParams);
}

// 0x004D8000
void __fastcall sub_004D8000_CltDoEruption(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (nFrame < 110)
    {
        int nCount;
        if (!nFrame)
        {
            sub_004CDB40_SubmitRequest(pOwner, 0x214, nX, nY, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nCount = nFrame + 8;
        }
        else if (nFrame < 50)
        {
            nCount = 8;
        }
        else
        {
            nCount = nFrame < 80 ? 5 : 1;
        }
        for (int i = 0; i < nCount; ++i)
        {
            const int nLevel = MISSILE_GetLevel(pMissile);
            const int nSkill = MISSILE_GetSkill(pMissile);
            if (pOwner)
            {
                D2MissileStrc tParams;
                memset(&tParams, 0, sizeof(tParams));
                tParams.pOwner = pOwner;
                tParams.dwFlags = 1;
                tParams.nX = nX + 2;
                tParams.nY = nY + 2;
                tParams.nSkill = nSkill;
                tParams.nSkillLevel = nLevel;
                tParams.nMissile = 0x255;
                D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
                if (pNew)
                {
                    const unsigned int nRoll1 = SEED_RollRandomNumber(&pMissile->tSeed);
                    const unsigned int nRoll2 = SEED_RollRandomNumber(&pMissile->tSeed);
                    const unsigned int nRoll3 = SEED_RollRandomNumber(&pMissile->tSeed);
                    sub_004DA1D0_SetMotionVectorA(pNew, 50 - nRoll1 % 100, 50 - nRoll2 % 100, 0);
                    sub_004DA200_SetMotionVectorB(pNew, 0, 0, (nRoll3 & 7) + 2, 1);
                }
            }
        }
    }
    if (nFrame == 5)
        sub_00476A80_StartTiming(nFrame - 2, 0x258, 0xFA0, 0xBB8);
    if (nFrame < 200 && !(nFrame % 7))
        sub_004D2990_SpawnAtFreeSpot(pOwner, nX, nY, pMissile);
    sub_004D30C0_CltDoCommon(pMissile);
}
