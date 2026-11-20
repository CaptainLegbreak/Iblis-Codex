#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2MissileStrc;




struct D2SkillsTxt
{
    char unk0x000[0x16];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x18];
    short nAuraState;
    unsigned char unk_82[0x6C];
    short wCltMissileC;
    unsigned char unk_F0[0x58];
    int dwParam[8];
    char unk0x168[0xD4];
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_004F28A0_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nCount, int nSkillId, int nSkillLevel); // 0x004F28A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F25A0
int __fastcall sub_004F25A0_RepeatMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags &= ~0x40;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill);
    if (nParam <= 0)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x20;
        tMissileParams.pOwner = pUnit;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nMissile = nMissile;
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nTargetX = nX;
        tMissileParams.nTargetY = nY;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 15);
        }

        SKILLS_SetParam1(pSkill, nCount);
    }
    else
    {
        SKILLS_SetParam1(pSkill, nParam - 1);
    }

    if (STATES_CheckState(pUnit, 12))
    {
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->nSeqInput - 1);
        pUnit->dwFrameCountPrecise = 0x800;
    }

    return 1;
}

// 0x004F29F0
int __fastcall sub_004F29F0_MissileScatterAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    int nX;
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        nX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }
    else if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    sub_004F28A0_MissileScatter(pUnit, nX, nMissile, nX, nY, nCount, nSkillId, nSkillLevel);
    return 1;
}

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

// 0x004F3680
static int __stdcall sub_004F3680_SpawnMissileTowardTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;

    const int nDeltaX = nTargetX - UNITS_GetUnitXPosition(pUnit);
    const int nDeltaY = nTargetY - UNITS_GetUnitYPosition(pUnit);
    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
    if (nDistance <= 1)
        nDistance = 1;

    const int nX = UNITS_GetUnitXPosition(pUnit) + 2 * nDeltaX / nDistance;
    const int nY = UNITS_GetUnitYPosition(pUnit) + 2 * nDeltaY / nDistance;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = 5 * nDeltaX;
    missileParams.nTargetY = 5 * nDeltaY;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&missileParams);
    if (!pMissile)
        return 0;

    D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY));
    return 1;
}

// 0x004F3810
int __fastcall sub_004F3810_SkillCltStartMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
        if (pSkillsTxt)
        {
            const int nMissileId = pSkillsTxt->wCltMissileC;
            if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
                return sub_004F3680_SpawnMissileTowardTarget(pUnit, nSkillId, nSkillLevel, nMissileId);
        }
    }

    return 0;
}

// 0x004F39A0
int __fastcall sub_004F39A0_SetTargetParams(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit == sub_00463DD0() && !sub_00645680_CanUnitCorpseBeSelected(pTarget))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetUnitXPosition(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetUnitYPosition(pTarget));
    SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwClassId);
    return 1;
}
