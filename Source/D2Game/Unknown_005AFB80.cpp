#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

#define STAT_HITPOINTS 6
union D2SeedStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;







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
