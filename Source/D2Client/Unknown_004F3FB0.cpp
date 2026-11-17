#include "D2Client.h"

struct D2SkillsTxt;
struct D2MissileStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[7];
    D2DynamicPathStrc* pDynamicPath;
};

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit); // 0x004C54F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

struct D2SkillsTxt
{
    char unk0x000[0x64];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    short wCltMissileB;
    char unk0x0EE[0x14E];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
void __fastcall sub_004C76D0_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent); // 0x004C76D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId); // 0x004F4110
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

// 0x004F3FB0
D2UnitStrc* __fastcall sub_004F3FB0_GetTargetMonster(D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != 1)
    {
        return 0;
    }
    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
    return sub_004B11F0(pTarget) ? pTarget : 0;
}

// 0x004F4140
int __fastcall sub_004F4140_CanThrowCheck(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_004C54F0_CanThrow(pUnit) != 0;
}

// 0x004F4150
int __fastcall sub_004F4150_ClearSkillParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F4A30
int __fastcall sub_004F4A30_CltDoChargedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nCharges = SKILLS_GetParam1(pSkill);
    if (nCharges <= 0)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nUnitGUID = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = sub_00463990(nUnitGUID, SKILLS_GetParam2(pSkill));
    if (!pTarget)
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 3, nUnitGUID, 0);
    }

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wCltMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wCltMissileB >= 0)
    {
        nMissileId = pSkillsTxtRecord->wCltMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissileId;
    tMissileParams.nTargetX = nTargetX;
    tMissileParams.nTargetY = nTargetY;
    sub_004CD540_CreateMissile(&tMissileParams);

    --nCharges;
    SKILLS_SetParam1(pSkill, nCharges);
    if (nCharges > 0)
    {
        D2UnitStrc* pNext = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 3, pTarget ? pTarget->dwUnitId : -1, 0);
        if (!pNext)
        {
            return 0;
        }

        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pNext), CLIENTS_GetUnitY(pNext), 0);
        int nUnitType = -1;
        if (pNext)
        {
            nUnitType = pNext->dwUnitType;
        }
        SKILLS_SetParam2(pSkill, nUnitType);
        int nNextGUID;
        if (!pNext)
        {
            nNextGUID = -1;
        }
        else
        {
            nNextGUID = pNext->dwUnitId;
        }
        SKILLS_SetParam3(pSkill, nNextGUID);
        sub_004C76D0_ScaleFramePrecise(pUnit, sub_004F4110_GetSkillParam5(nSkillId));
    }

    return 1;
}
