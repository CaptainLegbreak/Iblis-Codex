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
    int dwClassId;
    char unk0x08[0x20 - 0x04 - 4];
    D2SeedStrc tSeed;
    char unk0x28[0x2C - 0x20 - 8];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile);

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
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

struct D2CltMissileSpawnArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkill;
    int nSkillLevel;
    int nMaxCount;
    int nMissile;
};

struct D2AreaScanStrc
{
    int unk0x00;
    int nCount;
    D2CltMissileSpawnArgStrc* pArg;
};

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    unsigned short wCltHitSubMissile[4];
    char unk0x034[0x58 - 0x2C - 8];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x078[0x1A4 - 0x6C - 12];
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    char unk0x054[0x64 - 0x50 - 4];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0x138 - 0x64 - 4];
    unsigned int dwCalc[4];
    char unk0x148[0x23C - 0x138 - 16];
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0xB6C - 0xB64 - 4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB6C - 4];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0xBA0 - 0xB98 - 4];
    int nSkillsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50
void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);                // 0x006488A0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax);                              // 0x004CC790
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004CE4B0
void __fastcall sub_004CE4B0_InitMotion(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->dwCltParam[1] > 0)
    {
        sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[0]);
        sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[1], 1);
        const int nFrames = pMissilesTxtRecord->dwCltParam[0] / pMissilesTxtRecord->dwCltParam[1];
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }
}

// 0x004CED20
void __fastcall sub_004CED20_SubmitWithDirection(D2UnitStrc* pMissile, int nMissile)
{
    D2UnitStrc* pNew = sub_004CDBA0_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        PATH_SetDirection(pNew->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }
}

// 0x004CF250
int __fastcall sub_004CF250_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CEF50_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], 0x109, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004CF2B0
int __fastcall sub_004CF2B0_CltHitEffect(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if (nSubMissile >= 0)
        {
            sub_004CEFE0_AddMissileEffect(pMissile, nSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->dwCltHitPar[2]);
        }
    }
    return 1;
}

// 0x004CFC80
int __fastcall sub_004CFC80_CltHitRandomSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && (short)pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] > (short)pMissilesTxtRecord->wCltHitSubMissile[0])
        {
            const int nMax = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
            if (nSubMissile < nMax)
            {
                nSubMissile += ITEMS_RollLimitedRandomNumber(&pMissile->tSeed, nMax - nSubMissile + 1);
            }
        }

        sub_004CDBA0_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004CFD00
int __fastcall sub_004CFD00_CltHitOwnerRequest(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CDBA0_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 0;
}

// 0x004CF300
int __fastcall sub_004CF300_CltHitTwoSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CDBA0_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[2] > (short)pMissilesTxtRecord->wCltHitSubMissile[1])
    {
        nSubMissile = sub_004CC790_RollRange(&pMissile->tSeed, (short)pMissilesTxtRecord->wCltHitSubMissile[1], (short)pMissilesTxtRecord->wCltHitSubMissile[2]);
    }

    D2UnitStrc* pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pSubMissile)
    {
        sub_00464810(pSubMissile);
    }
    return 1;
}
