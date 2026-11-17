struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2StaticPathStrc
{
    char unk0x00[0xC];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    char unk0x0F0[0x1E];
    short wPrgSound;
    char unk0x110[0x4];
    unsigned int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

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
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

enum D2C_UnitTypes
{
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gaSprayOffsetX_006DBFA8[8];                                                                // 0x006DBFA8
extern const int gaSprayOffsetY_006DBFC8[8];                                                                // 0x006DBFC8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

static __forceinline unsigned int SEED_RollRandomNumber_Spray(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Spray(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static __forceinline int CLIENTS_GetUnitX_Spray(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_Spray(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void __stdcall sub_004F1A30_CreateSprayMissile(D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    const int nIndex = SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 7;
    int nX = CLIENTS_GetUnitX_Spray(pUnit);
    int nY = CLIENTS_GetUnitY_Spray(pUnit);
    const int nOffsetX = gaSprayOffsetX_006DBFA8[nIndex];
    const int nOffsetY = gaSprayOffsetY_006DBFC8[nIndex];
    nX += nOffsetX;
    nY += nOffsetY;

    int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0)
    {
        return;
    }

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollRandomNumber_Spray(&pUnit->pSeed) % 3)
            {
            case 0:
                nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!(SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 1))
        {
            nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nTargetX = nOffsetY;
    tMissile.nTargetY = -nOffsetX;
    tMissile.nSkillLevel = nSkillLevel;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissile);
    if (!pMissile)
    {
        return;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[1], nSkillId, nSkillLevel);
    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, SEED_RollLimitedRandomNumber(&pUnit->pSeed, nSpread));
    MISSILE_SetTargetX(pMissile, CLIENTS_GetUnitX_Spray(pUnit));
    MISSILE_SetTargetY(pMissile, CLIENTS_GetUnitY_Spray(pUnit));
}

// 0x004F1C80
int __fastcall sub_004F1C80_SkillCltDoSpray(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_Spray(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int bInTown = !pRoom || DUNGEON_IsRoomInTown(pRoom);
    if (pSkillsTxt->wPrgSound > 0)
    {
        void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pUnit, pSkillsTxt->wPrgSound);
        if (bInTown)
        {
            if (pUnitSfx)
            {
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
            }
        }
        else if (!pUnitSfx)
        {
            sub_004B9A00(pSkillsTxt->wPrgSound, pUnit, 0, 0, 0);
        }
    }

    if (bInTown)
    {
        return 0;
    }

    const int nSkill = nSkillId;
    const int nPasses = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkill, nSkillLevel);
    for (int i = 0; i < nPasses; ++i)
    {
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
    }

    return 1;
}
