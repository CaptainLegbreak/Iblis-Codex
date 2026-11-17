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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);                // 0x004639B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                       // 0x0064A380
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

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

// 0x004D1D70
int __fastcall sub_004D1D70_CltHitLinkMissile(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004639B0_FindServerSideUnit(MISSILE_GetTargetX(pMissile), 3);
    if (pTarget)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0xA021;
        tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tMissileParams.nMissile = 0x160;
        tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
        tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissileParams.nRange = sub_0064A380_GetRemainingFrames(pTarget);
        tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
        tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
        tMissileParams.nTargetX = UNITS_GetUnitXPosition(pTarget);
        tMissileParams.nTargetY = UNITS_GetUnitYPosition(pTarget);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissileParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }

    return 1;
}
