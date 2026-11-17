struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x24];
    unsigned int dwInitSeed;
};

struct D2SkillsTxt
{
    char unk0x000[0x64];
    int dwAuraRangeCalc;
    char unk0x068[0x1D4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnRingX_006DBFE8[];                                                                          // 0x006DBFE8
extern int gnRingY_006DC0E8[];                                                                          // 0x006DC0E8

void __fastcall sub_004F2AC0_RingMissileInit(D2UnitStrc* pMissile, int nArg);                              // 0x004F2AC0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId);                                                   // 0x004EFC20
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                               // 0x004F21B0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_004F2260_GetSkillCount(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                // 0x004F2260
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004F2B20
static void __stdcall sub_004F2B20_CreateMissileRing(D2UnitStrc* pUnit, int nMissile, int nX, int nY, int nSkillLevel, int nCount, unsigned int nInitSeed, int nSkillId)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nInitSeed);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pInitFunc = sub_004F2AC0_RingMissileInit;
    for (int i = 0; i < 64; i += nCount)
    {
        tMissileParams.nTargetX = gnRingX_006DBFE8[i];
        tMissileParams.nTargetY = gnRingY_006DC0E8[i];
        tMissileParams.nInitArg = SEED_RollRandomNumberInline(&tSeed);
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        MISSILE_SetTargetX(pMissile, sub_004EFC20_GetSkillParam2(nSkillId) + 1);
    }
}

// 0x004F2F20
int __fastcall sub_004F2F20_CltSkillMissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    const unsigned int nInitSeed = pUnit->dwInitSeed;
    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    sub_004F2B20_CreateMissileRing(pUnit, nMissile, nX, nY, nSkillLevel, nCount, nInitSeed, nSkillId);
    return 1;
}

#include "gen/data/Source/D2Client/004F2B20_sub_004F2B20_CreateMissileRing.inc"
