struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2InventoryStrc;
struct D2GfxLightStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    int dwInitSeed;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x18];
    int dwFrameCountPrecise;
    char unk0x4C[0x14];
    D2InventoryStrc* pInventory;
    D2GfxLightStrc* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char unk0x00C[0x0A];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    short wCltMissileD;
    char unk0x0F2[0x18];
    unsigned short wTgtSound;
    short wPrgOverlay;
    short wPrgSound;
    char unk0x110[0x04];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2MissilesTxt
{
    char unk0x000[0x18];
    short wSubMissile[3];
    char unk0x01E[0x186];
};

struct D2MonStats2Txt
{
    unsigned int dwId;
    union
    {
        unsigned int dwFlags;
        unsigned char nFlags[4];
    };
    char unk0x08[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

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
    int unk0x38;
    int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int nInitArg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                           // 0x0046ACE0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004C7480_CreateSpread(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nArg1, int nArg2);
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F3A60
int __fastcall sub_004F3A60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nMonsterId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!nX)
    {
        return 0;
    }

    if (!nY)
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2021;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + nX - 1;
    tMissileParams.nTargetY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + nY - 1;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    if (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[2])
    {
        sub_004C7480_CreateSpread(pUnit, &tMissileParams, 0, 1);
    }
    else if (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[3])
    {
        sub_004C7480_CreateSpread(pUnit, &tMissileParams, 3, 3);
        const short nSubMissile = sub_0046ACE0(nMissile)->wSubMissile[0];
        if (nSubMissile > 0 && nSubMissile < sgptDataTables->nMissilesTxtRecordCount)
        {
            tMissileParams.nMissile = nSubMissile;
            sub_004C7480_CreateSpread(pUnit, &tMissileParams, 2, 4);
        }
    }
    else
    {
        sub_004C7480_CreateSpread(pUnit, &tMissileParams, 2, 2);
        const short nSubMissile = sub_0046ACE0(nMissile)->wSubMissile[1];
        if (nSubMissile > 0 && nSubMissile < sgptDataTables->nMissilesTxtRecordCount)
        {
            tMissileParams.nMissile = nSubMissile;
            sub_004C7480_CreateSpread(pUnit, &tMissileParams, 1, 3);
        }
    }

    tMissileParams.nY = nY;
    tMissileParams.nX = nX;

    D2UnitStrc* pMissile = 0;
    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB > 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nMissile = nMissileB;
        pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    }

    const int nMissileC = pSkillsTxtRecord->wCltMissileC;
    if (nMissileC > 0 && nMissileC < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nSkillLevel = 2;
        tMissileParams.nMissile = nMissileC;
        sub_004CD540_CreateMissile(&tMissileParams);
    }

    if (!sub_004648F0_GetPathTargetUnit(pUnit) && pMissile)
    {
        const short nSound = pSkillsTxtRecord->wTgtSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
        }
    }

    return 1;
}
