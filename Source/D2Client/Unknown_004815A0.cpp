#include "D2Structs.h"
#include "D2DataTbls.h"
struct D2SkillStrc;
struct D2PlayerDataStrc
{
    char _pad_0x0[0x150];
    int nState;
    int nAction;
    int nArg1;
    int nArg2;
};
struct D2SkillsTxt
{
    char _pad_0x0[0x7];
    unsigned char nFlagsB;
    char _pad_0x8[0x26];
    short wSrvDoFunc;
    char _pad_0x30[0x20C];
};
struct D2UnitTargetStrc
{
    int nArg1;
    int nArg2;
    int unk[5];
};

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask); // 0x00622B50
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
unsigned short __cdecl sub_0044BEC0_GetClickFlags(); // 0x0044BEC0
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00480C10
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
extern "C" const char szUnitModeFile_006D8E84[]; // 0x006D8E84
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

// build: context UMODE_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* UMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __declspec(noinline) int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer);

// 0x00480BA0

static int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxt = UMODE_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, szUnitModeFile_006D8E84, 0x2CC));
    if (!pSkillsTxt || BITARRAY_CHECK((unsigned char*)pSkillsTxt, 63))
    {
        return 1;
    }

    if (pPlayer)
    {
        const int nMode = pPlayer->dwAnimMode;
        if (nMode == 1 || nMode == 5)
        {
            return 1;
        }
    }
    return 0;
}

static __declspec(noinline) int sub_00480C80_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction);

// 0x00480C80

static int sub_00480C80_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction)
{
    D2SkillStrc* pSkill;
    switch (nAction)
    {
    case 6:
        pSkill = UNITS_GetLeftSkill(pPlayer);
        break;

    case 13:
        pSkill = UNITS_GetRightSkill(pPlayer);
        break;

    default:
        pSkill = 0;
        break;
    }

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
        {
            int nRange;
            int nDistance;
            return sub_00461AC0_IsInAuraRange(pSkill, pUnit, &nRange, &nDistance) != 0;
        }
    }

    if (pUnit && pUnit->dwUnitType == 2)
    {
        if (UNITS_IsObjectInInteractRange(pPlayer, pUnit) && !sub_00622B50_TestInteractCollision(pPlayer, pUnit, 0x804))
        {
            return 0;
        }
        return 1;
    }

    return UNITS_IsInMeleeRange(pPlayer, pUnit, UNITS_IsInMovingModeEx(pUnit)) == 0;
}

// build: context sub_GetPlayerDataOrNull
static __forceinline D2PlayerDataStrc* sub_GetPlayerDataOrNull(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
        return pUnit->pPlayerData;
    return 0;
}
// build: context sub_SetPlayerAction
static __forceinline void sub_SetPlayerAction(D2UnitStrc* pPlayer, int nState, int nAction, int nArg1, int nArg2)
{
    if (sub_GetPlayerDataOrNull(pPlayer))
    {
        pPlayer->pPlayerData->nState = nState;
        pPlayer->pPlayerData->nAction = nAction;
        pPlayer->pPlayerData->nArg1 = nArg1;
        pPlayer->pPlayerData->nArg2 = nArg2;
    }
}

extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)

// 0x004812E0
static __declspec(noinline) void __stdcall sub_004812E0_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    D2UnitTargetStrc tTarget;
    if (sub_0044BEC0_GetClickFlags() & 8)
    {
        if (sub_00480BA0_CanUseSkillNow(pPlayer))
        {
            memset(&tTarget, 0, sizeof(tTarget));
            tTarget.nArg1 = nArg1;
            tTarget.nArg2 = nArg2;
            if (sub_00480C10_DispatchUnitCommand(0x18, pPlayer, &tTarget, 0))
                sub_004786A0_SendDwords2(4, nArg1, nArg2);
            sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
        }
    }
    else if (sub_00480BA0_CanUseSkillNow(pPlayer))
    {
        memset(&tTarget, 0, sizeof(tTarget));
        tTarget.nArg1 = nArg1;
        tTarget.nArg2 = nArg2;
        if (sub_00480C10_DispatchUnitCommand(0, pPlayer, &tTarget, 0))
            sub_004786A0_SendDwords2(2, nArg1, nArg2);
        sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
    }
    sub_SetPlayerAction(pPlayer, 1, nAction, nArg1, nArg2);
}

// build: context sub_IsUnitTargetable
static __forceinline int sub_IsUnitTargetable(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 1) & 1;
}

// 0x004815A0
static __declspec(noinline) int __stdcall sub_004815A0_TryUnitAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    if (!sub_IsUnitTargetable(pUnit))
    {
        sub_00467A70_RefreshHoverUnit(0);
        return 0;
    }

    if (sub_00480C80_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        sub_004812E0_DoPlayerAction(pPlayer, nAction, nArg1, nArg2);
        return 0;
    }

    return 1;
}

// build: context sub_004815A0_Shim
// calling-convention shim (not game code)
int __stdcall sub_004815A0_Shim(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction, int nArg1, int nArg2)
{
    return sub_004815A0_TryUnitAction(pUnit, pPlayer, nAction, nArg1, nArg2);
}
