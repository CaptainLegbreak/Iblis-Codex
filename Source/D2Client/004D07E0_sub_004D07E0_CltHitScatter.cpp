struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc tSeed;
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

struct D2MissilesTxt
{
    char unk0x000[0x1E];
    short wCltSubMissile[3];
    char unk0x024[0x08];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                              // 0x0064A280
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                         // 0x0064A730

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D07E0
int __fastcall sub_004D07E0_CltHitScatter(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0x102;
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = sub_0064A280(pMissile);

            const int nSpread = pMissilesTxtRecord->dwCltHitPar[0] < 3 ? 3 : pMissilesTxtRecord->dwCltHitPar[0];
            const int nCount = sub_0064A730_GetMissileTargetStatus(pMissile);
            for (int i = 0; i < nCount; ++i)
            {
                tMissileParams.nSkillLevel = SEED_RollRandomNumber(&pMissile->tSeed) % 5 + 1;
                const int nOffsetX = SEED_RollLimitedRandomNumber(&pMissile->tSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetX = nOffsetX;
                const int nOffsetY = SEED_RollLimitedRandomNumber(&pMissile->tSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetY = nOffsetY;
                if (!nOffsetX && !nOffsetY)
                {
                    tMissileParams.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->tSeed, nSpread) + 1;
                }
                sub_004CD540_CreateMissile(&tMissileParams);
            }
        }

        return 1;
    }

    return 1;
}
