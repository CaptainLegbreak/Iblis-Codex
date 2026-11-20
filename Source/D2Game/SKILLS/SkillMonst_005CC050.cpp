#include "D2Game.h"
#include "D2Structs.h"

struct D2SkillsTxt;
struct D2MissilesTxt;


struct D2SkillsTxt
{
    char unk0x00[0x48];
    short wSrvMissileA;
    char unk0x04A[0xEE];
    int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pParams); // 0x0059FA30
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

// build: context GetSkillsTxtRecord
static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context SKILLS_Abs
static int SKILLS_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x005CC050
int __fastcall sub_005CC050_PlaceSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nUnitX = CLIENTS_GetUnitX(pUnit);
    const int nUnitY = CLIENTS_GetUnitY(pUnit);

    int nY = nTargetY;
    int nX = nTargetX;
    int i = 4;
    if (SKILLS_Abs(nTargetX - nUnitX) < SKILLS_Abs(nTargetY - nUnitY))
    {
        nX = nUnitX;
        do
        {
            if (nX > nTargetX)
            {
                --nX;
            }
            else if (nX < nTargetX)
            {
                ++nX;
            }
        }
        while (--i > 0);
    }
    else
    {
        nY = nUnitY;
        do
        {
            if (nY > nTargetY)
            {
                --nY;
            }
            else if (nY < nTargetY)
            {
                ++nY;
            }
        }
        while (--i > 0);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    const int nDX = nX - nUnitX;
    const int nDY = nY - nUnitY;
    missileParams.nX = nUnitX + nDX / 6 - 1;
    missileParams.nY = nUnitY + nDY / 6 - 1;
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 3;
    missileParams.nTargetX = nDX;
    missileParams.nTargetY = nDY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CCFA0
int __fastcall SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissile;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        missileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return pMissilesTxtRecord ? 1 : 0;
}
