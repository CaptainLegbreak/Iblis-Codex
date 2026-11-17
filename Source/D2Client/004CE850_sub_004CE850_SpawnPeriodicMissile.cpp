struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char unk0x00[0x1E];
    short wSound;
    char unk0x20[0x14];
    short wProgOverlay;
    char unk0x36[0x1A4 - 0x36];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
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

extern D2DataTablesStrc* sgptDataTable;                                                                     // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_004B9A00_PlayOverlay(int nOverlay, D2UnitStrc* pOwner, int a3, int a4, int a5);         // 0x004B9A00
void __fastcall sub_004CD540_CreateClientMissile(D2MissileStrc* pMissile);                                  // 0x004CD540
void __fastcall sub_004CE650_PlaySound(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSound, int nLevel);      // 0x004CE650
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_0064A210(D2UnitStrc* pUnit);                                                            // 0x0064A210
int __stdcall sub_0064A280(D2UnitStrc* pUnit);                                                            // 0x0064A280
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

static __forceinline int UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int RollOffset(D2UnitStrc* pUnit, int nRange)
{
    return ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRange / 2;
}

// 0x004CE850
void __fastcall sub_004CE850_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissileId, int nFrame, int nLevel)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTable->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (pMissilesTxtRecord->wSound > 0)
    {
        sub_004CE650_PlaySound(pOwner, pUnit, pMissilesTxtRecord->wSound, nLevel);
    }

    if (pMissilesTxtRecord->wProgOverlay > 0 && nFrame == 315)
    {
        sub_004B9A00_PlayOverlay(pMissilesTxtRecord->wProgOverlay, pOwner, 0, 0, 0);
    }

    if (nFrame % 2 != 0)
    {
        return;
    }

    if (nLevel < 3 && nFrame % 16 != 0)
    {
        return;
    }

    int nRange = 4;
    if (nLevel < 3)
    {
        nRange = 1;
    }
    else if (nLevel < 6)
    {
        nRange = 2;
    }
    else if (nLevel < 9)
    {
        nRange = 3;
    }

    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nRange > 1)
    {
        nOffsetX = RollOffset(pUnit, nRange);
        nOffsetY = RollOffset(pUnit, nRange);
    }

    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 1;
    missile.pOwner = pOwner;
    missile.nSkill = sub_0064A280(pUnit);
    missile.nSkillLevel = sub_0064A210(pUnit);
    missile.nMissile = nMissileId;
    missile.nX = UNITS_GetXPosition(pUnit) + nOffsetX;
    missile.nY = UNITS_GetYPosition(pUnit) + nOffsetY;
    sub_004CD540_CreateClientMissile(&missile);
}
