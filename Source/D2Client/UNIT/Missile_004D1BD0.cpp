#include "D2Client.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxtStrc;
struct D2SkillsTxtStrc;

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned __int64 lSeed;
        };
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
    };
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int nClassId;
    int unk0x08[6];
    union
    {
        D2SeedStrc tSeed;
        int dwSeed;
    };
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pCallbackUnit;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004E2ED0_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile); // 0x0064A780
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

struct D2MissilesTxtStrc
{
    char pad0[0x1E];
    short nMin;
    short nMax;
    char pad1[0x1A4 - 0x22];
};

struct D2SkillsTxtStrc
{
    char pad0[0x138];
    int nCalc1;
    int nCalc2;
    char pad1[0x23C - 0x140];
};

struct D2DataTablesStrc
{
    char pad0[0xB64];
    D2MissilesTxtStrc* pMissilesTxt;
    char padB68[4];
    int nMissilesTxtRecordCount;
    char padB70[0xB98 - 0xB70];
    D2SkillsTxtStrc* pSkillsTxt;
    char padB9C[4];
    int nSkillsTxtRecordCount;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3); // 0x004CE320
void __fastcall sub_004CE420(D2UnitStrc* pMissile); // 0x004CE420
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile); // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollNextHL_Inline(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
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

// 0x004D1BD0
int __fastcall sub_004D1BD0_CltHitScatter(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2SeedStrc* pSeed = &pMissile->tSeed;
    SEED_InitLowSeed(pSeed, sub_0064A780_targetValue(pMissile));
    const int nCount = MISSILE_GetTargetX(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nX = nX;
    tParams.nY = nY;
    tParams.nMissile = 0x15D;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    for (int i = 0; i < nCount; ++i)
    {
        unsigned __int64 lSeed = SEED_RollRandomNumber(pSeed);
        const int nTargetX = (unsigned int)lSeed % 20 - 10 + nX;
        lSeed = SEED_RollNextHL_Inline(pSeed, lSeed);
        const int nTargetY = (unsigned int)lSeed % 20 - 10 + nY;

        tParams.nTargetX = nTargetX;
        tParams.nTargetY = nTargetY;
        if (nTargetX == nX && nTargetY == nY)
        {
            --i;
            continue;
        }

        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            sub_004E2ED0_InitCappedChargedPath(pNew, nTargetX);
        }
    }

    return 1;
}

// 0x004D3F10
void __fastcall sub_004D3F10_ClientMissileDo(D2UnitStrc* pMissile)
{
    struct { int nValue1; int nLevel; D2UnitStrc* pOwner; int nRange; } tLocal;
    D2MissilesTxtStrc* pMissilesTxt;
    if (pMissile && pMissile->nClassId >= 0 && pMissile->nClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxt = &sgptDataTables->pMissilesTxt[pMissile->nClassId];
    }
    else
    {
        pMissilesTxt = 0;
    }
    if (!pMissilesTxt || pMissilesTxt->nMin < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nMin = pMissilesTxt->nMin;
    tLocal.nRange = nMin;
    if (nMin < pMissilesTxt->nMax)
    {
        tLocal.nRange = ITEMS_RollLimitedRandomNumber((D2SeedStrc*)&pMissile->dwSeed, pMissilesTxt->nMax - nMin + 1) + nMin;
    }

    int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxtStrc* pSkillsTxt;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    else
    {
        pSkillsTxt = 0;
    }
    if (!pSkillsTxt)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    tLocal.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tLocal.nLevel = MISSILE_GetLevel(pMissile);
    tLocal.nValue1 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->nCalc1, nSkillId, tLocal.nLevel);
    int nValue2 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->nCalc2, nSkillId, tLocal.nLevel);
    if (nValue2 && tLocal.nValue1 > 0)
    {
        D2UnitStrc* pTarget = sub_004CE320(pMissile, tLocal.nValue1, nValue2, tLocal.nRange);
        if (pTarget)
        {
            sub_004CE420(pTarget);
        }
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    sub_004CD390_CltDoDefault(pMissile);
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004D6FA0
void __fastcall sub_004D6FA0_CltDoLinked(D2UnitStrc* pMissile)
{
    D2SeedStrc* pSeed = &pMissile->tSeed;
    int nPrevState = sub_0064A780_targetValue(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pLinked = sub_004639B0_FindServerSideUnit(sub_0064A730_GetMissileTargetStatus(pMissile), 3);
    if (pLinked)
    {
        int nState = sub_0064A730_GetMissileTargetStatus(pLinked);
        int nDistance = sub_006416D0_UnitEdgeDistance(pMissile, pLinked);
        int nMin = MAX((int)((unsigned int)SEED_RollRandomNumberInline(pSeed) % 5), 1);

        if (nPrevState != nState && nState > 1)
        {
            MISSILE_SetTargetY(pMissile, nState);
            switch (nState)
            {
            case 4:
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 20, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, 400, 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 1);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;

            case 3:
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -6, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40), 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 0);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;

            case 2:
                PATH_SetVelocity(pPath, 0, gszMissileSourceFile_006DAEF4, 6004);
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 6, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40) + 170, 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 1);
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
                PATH_SetVelocity(pPath, 0x300, gszMissileSourceFile_006DAEF4, 6012);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;
            }
        }
        else if (nDistance < nMin && !nPrevState)
        {
            MISSILE_SetTargetY(pMissile, 1);
            sub_004DA690_ReplaceMotionFlag1With8(pMissile);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 1, 1);
            sub_004D30C0_CltDoCommon(pMissile);
            return;
        }
        else if (nPrevState == 1)
        {
            int nDiffX = -CLIENTS_GetUnitX(pLinked) + CLIENTS_GetUnitX(pMissile);
            int nDiffY = -CLIENTS_GetUnitY(pLinked) + CLIENTS_GetUnitY(pMissile);
            if (nDiffX || nDiffY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDiffY, CLIENTS_GetUnitY(pMissile) + nDiffX);
                PATH_SetVelocity(pPath, 0xA00, gszMissileSourceFile_006DAEF4, 6046);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
        else if (nPrevState == 3)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
            PATH_SetVelocity(pPath, 0x200, gszMissileSourceFile_006DAEF4, 6055);
            D2Common_10142(pPath, pMissile, 0);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
