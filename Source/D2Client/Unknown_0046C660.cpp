#include "D2Client.h"
#include "D2Structs.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_TYPES_COUNT 6
#define UNITFLAGEX_ISSHAPESHIFTED 0x00000008
#define LINE_ENGINE_TYPE 242
#define LINE_ENGINE_CLASS 278
#define LINE_ENGINE_MODE 260
union D2SeedStrc;
struct D2Txt84Strc;



int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
extern D2UnitStrc* gpAiTargets_007A7470[]; // 0x007A7470

struct D2Txt84Strc
{
    char unk0x00[0x84];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2Txt84Strc* pTxt84;
    int nTxt84Count;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

// 0x0046C660
int __fastcall sub_0046C660_FindCorpseCallback(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc** ppTarget, int* pDistance)
{
    if (!pTarget)
        return 0;

    const int nType = pTarget->dwUnitType;
    if (nType != UNIT_PLAYER && nType != UNIT_MONSTER)
        return 0;

    const int nMode = pTarget->dwAnimMode;
    if (nType == UNIT_PLAYER)
    {
        if (nMode != PLRMODE_DEATH && nMode != PLRMODE_DEAD)
            return 0;
    }
    else
    {
        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD)
            return 0;
    }

    const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
    if (nDistance >= 3 && nDistance <= 25 && sub_006416D0_UnitEdgeDistance(pTarget, sub_00463DD0_GetPlayerUnit()) > 7 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
    {
        *pDistance = nDistance;
        *ppTarget = pTarget;
    }

    return 0;
}

// 0x0046C720
static __declspec(noinline) D2UnitStrc* __stdcall sub_0046C720_FindNearestTarget(D2UnitStrc* pUnit, int* pDistance)
{
    D2UnitStrc* pNearest = 0;
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        D2UnitStrc* pTarget = *ppSlot;
        if (pTarget && pTarget->dwAnimMode && pTarget->dwAnimMode != 12)
        {
            const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
            if (nDistance < *pDistance)
            {
                pNearest = *ppSlot;
                *pDistance = nDistance;
            }
        }
    }

    return pNearest;
}

D2UnitStrc* __fastcall sub_M305_Emit_0046C720(D2UnitStrc* pUnit)
{
    int nDistance = 0x7FFFFFFF;
    return sub_0046C720_FindNearestTarget(pUnit, &nDistance);
}

// 0x0046D9C0
D2Txt84Strc* __fastcall sub_0046D9C0_GetTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nTxt84Count)
    {
        return &sgptDataTables->pTxt84[nIndex];
    }
    return 0;
}

static __forceinline int UNITS_IsShapeshifted_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & UNITFLAGEX_ISSHAPESHIFTED) != 0;
    }

    return 0;
}

// 0x0046D9F0
int __fastcall sub_0046D9F0_GetConvertedUnitType(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwUnitType;
    }

    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_TYPE);
    return nType;
}

// 0x0046DAC0
int __fastcall sub_0046DAC0_GetConvertedClassId(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwClassId;
    }

    if (!pUnit)
    {
        return -1;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_CLASS);
    return nClass;
}

// 0x0046DA60
int __fastcall sub_0046DA60_GetConvertedUnitMode(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
    lDefault:
        return UNITS_GetAnimOrSeqMode(pUnit);
    }

    if (!pUnit)
    {
        goto lDefault;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_MODE);
    return nMode;
}
