struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
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
    int unk0x38[9];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004BD0C0
void __fastcall sub_004BD0C0_SpawnMissileGrid(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 3;
            tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
            tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
            tMissileParams.nTargetX = (i & 1) ? 5 * i : -5 * i;
            tMissileParams.nTargetY = (j & 1) ? 5 * j : -5 * j;
            tMissileParams.pOwner = pOwner;
            tMissileParams.nMissile = 0x3E;
            int nLevel = STATLIST_UnitGetStatValue(pOwner, 0xC, 0) / 5;
            if (nLevel < 1)
            {
                nLevel = 1;
            }
            else if (nLevel > 8)
            {
                nLevel = 8;
            }
            tMissileParams.nSkillLevel = nLevel;
            sub_004CD540_CreateMissile(&tMissileParams);
        }
    }
}

// 0x004BD220
void __fastcall sub_004BD220_SpawnMissileStar(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    int aOffsetX[6] = { -6, -6, 0, 0, 6, 6 };
    int aOffsetY[6] = { 6, -6, 6, -6, 6, -6 };
    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x520;
        tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
        tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
        tMissileParams.nTargetX = tMissileParams.nX + aOffsetX[i];
        tMissileParams.nTargetY = tMissileParams.nY + aOffsetY[i];
        tMissileParams.pOwner = pOwner;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nGfxArg = 1;
        tMissileParams.nMissile = 0x2D;
        int nLevel = STATLIST_UnitGetStatValue(pOwner, 0xC, 0) / 5;
        if (nLevel < 1)
        {
            nLevel = 1;
        }
        else if (nLevel > 8)
        {
            nLevel = 8;
        }
        tMissileParams.nSkillLevel = nLevel;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
}

// 0x004BD360
void __fastcall sub_004BD360_SpawnMissileStar(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    int aOffsetX[6] = { -6, -6, 0, 0, 6, 6 };
    int aOffsetY[6] = { 6, -6, 6, -6, 6, -6 };
    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x520;
        tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
        tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
        tMissileParams.nTargetX = tMissileParams.nX + aOffsetX[i];
        tMissileParams.nTargetY = tMissileParams.nY + aOffsetY[i];
        tMissileParams.pOwner = pOwner;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nGfxArg = 1;
        tMissileParams.nMissile = 0x30;
        int nLevel = STATLIST_UnitGetStatValue(pOwner, 0xC, 0) / 5;
        if (nLevel < 1)
        {
            nLevel = 1;
        }
        else if (nLevel > 8)
        {
            nLevel = 8;
        }
        tMissileParams.nSkillLevel = nLevel;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
}
