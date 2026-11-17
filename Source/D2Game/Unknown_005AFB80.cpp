#include "D2Game.h"

#define STAT_HITPOINTS 6
struct D2SeedStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;

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
    D2SeedStrc pSeed;
    int dwInitSeed;
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0x00[0x18];
    short wSubMissile[3];
    char unk0x1E[0x18];
    short wProgOverlay;
    int dwParam[5];
    char unk0x4C[0x158];
};

struct D2SkillsTxt
{
    char unk0x000[0x64];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0xD0];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005AFB80
int __fastcall MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!(pOwner))
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    int nRange = pMissilesTxtRecord->dwParam[1];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nFrequency = pMissilesTxtRecord->dwParam[0];
    if (nFrequency <= 0)
    {
        nFrequency = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrequency < 1)
        {
            nFrequency = 1;
        }
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames > pMissilesTxtRecord->dwParam[2] && nFrames < pMissilesTxtRecord->dwParam[3] && !(nFrames % nFrequency))
    {
        SEED_InitLowSeed(&pMissile->pSeed, MISSILE_GetTargetX(pMissile));
        nFrequency = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - nRange;
        nRange = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - nRange;
        int const tArg9 = SEED_GetLowSeed(&pMissile->pSeed);
        MISSILE_SetTargetX(pMissile, tArg9);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x520;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nTargetX = CLIENTS_GetUnitX(pMissile) + nFrequency;
        missileParams.nTargetY = CLIENTS_GetUnitY(pMissile) + nRange;
        missileParams.nGfxArg = pMissilesTxtRecord->dwParam[4];
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nLevel;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AFD70
int __fastcall MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }
    {
        const int nLevel = MISSILE_GetLevel(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
        {
            int nHitpoints = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0) >> 8;
            const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner) >> 8;
            if (nHitpoints < nMaxHp)
            {
                nHitpoints += DATATBLS_ApplyRatio(nMaxHp, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
                if (nHitpoints >= nMaxHp)
                {
                    nHitpoints = nMaxHp;
                }

                STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nHitpoints << 8, 0);

                if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
                {
                    UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
                }
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
