#include "D2Common.h"

struct D2MissileDataStrc
{
    unsigned int unk0x00;
    short nStreamMissile;
    short nStreamRange;
    short nActivateFrame;
    short nSkill;
    short nLevel;
    short nTotalFrames;
    short nCurrentFrame;
    unsigned short unk0x12;
    unsigned int fFlags;
    int nOwnerType;
    int dwOwnerGUID;
    int nHomeType;
    int dwHomeGUID;
    int nTargetX;
    int nTargetY;
    void* pStream;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MissileDataStrc* pMissileData;
};

struct D2MissilesTxt
{
    char unk0x00[0xB0];
    int dwMinDamage;
    int dwMaxDamage;
    int dwMinLevDam[5];
    int dwMaxLevDam[5];
    int dwDmgSymPerCalc;
    unsigned char nElemType;
    unsigned char pad0xE5[3];
    int dwElemMin;
    int dwElemMax;
    int dwMinElemLev[5];
    int dwMaxElemLev[5];
    int dwElemDmgSymPerCalc;
    int dwElemLen;
    int dwElemLevLen[3];
    char unk0x12C[0x6A];
    unsigned char nHitShift;
    char unk0x197[0x0D];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    int nMissileId;
    int nMissileLevel;
};

#define UNIT_MISSILE 3
#define D2UnitInvalidGUID -1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);                           // 0x00644B70
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel);  // 0x00646460
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0064A100
void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && !pMissile->pMissileData)
    {
        D2MissileDataStrc* pMissileData = (D2MissileDataStrc*)sub_0040B430(pMissile->pMemoryPool, sizeof(D2MissileDataStrc), ".\\UNITS\\Missile.cpp", 34, 0);
        memset(pMissileData, 0x00, sizeof(D2MissileDataStrc));
        pMissileData->dwOwnerGUID = D2UnitInvalidGUID;
        pMissile->pMissileData = pMissileData;
    }
}

// 0x0064A150
void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        sub_0040B480(pMissile->pMemoryPool, pMissile->pMissileData, ".\\UNITS\\Missile.cpp", 62, 0);
        pMissile->pMissileData = 0;
    }
}

// 0x0064AF20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwMinDamage + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMinLevDam);
    if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064AFF0
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwMaxDamage + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMaxLevDam);
    if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064B0C0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    return pMissilesTxtRecord->nElemType;
}

// 0x0064B100
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwElemMin + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMinElemLev);
    if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064B1D0
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    if (nMissileId < 0 && pMissile)
    {
        nMissileId = pMissile->dwClassId;
    }

    int nMissileIdLevel = nLevel;
    if (nLevel <= 0 && pMissile)
    {
        if (pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
        {
            nMissileIdLevel = pMissile->pMissileData->nLevel;
        }
        else
        {
            nMissileIdLevel = 0;
        }
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDamage = pMissilesTxtRecord->dwElemMax + SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, pMissilesTxtRecord->dwMaxElemLev);
    if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
    {
        const int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissileId, nMissileIdLevel);
        if (nPercentage)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
        }
    }

    return nDamage << pMissilesTxtRecord->nHitShift;
}

// 0x0064B760
int __fastcall MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
    D2MissileCalcStrc* pMissileCalc = (D2MissileCalcStrc*)pUserData;
    if (!pMissileCalc)
    {
        return 0;
    }

    int nSkillLevel = 0;
    if (pMissileCalc->pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pMissileCalc->pOwner, nSkillId);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pMissileCalc->pOwner, pSkill, 1);
        }
    }

    return SKILLS_GetSpecialParamValue(pMissileCalc->pOwner, nParamId, nSkillId, nSkillLevel);
}
