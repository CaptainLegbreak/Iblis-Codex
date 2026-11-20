#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

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
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

// build: context sub_00480BA0_CanUseSkillNow
static __declspec(noinline) int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (pSkill)
    {
        int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szUnitModeFile_006D8E84, 0x2CC);
        if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2SkillsTxt* pTxt = &sgptDataTables->pSkillsTxt[nSkillId];
            if (pTxt && !(pTxt->nFlagsB & (unsigned char)gdwTitleMaskB_006CE284))
            {
                if (!pPlayer || (pPlayer->dwAnimMode != 1 && pPlayer->dwAnimMode != 5))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// build: context sub_00480C80_IsTargetInRange
static __declspec(noinline) int sub_00480C80_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction)
{
    D2SkillStrc* pSkill = 0;
    if (nAction == 6)
    {
        pSkill = UNITS_GetLeftSkill(pPlayer);
    }
    else if (nAction == 13)
    {
        pSkill = UNITS_GetRightSkill(pPlayer);
    }
    {
        if (pSkill)
        {
            D2SkillsTxt* pTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
            if (pTxt && pTxt->wSrvDoFunc == 19)
            {
                int nRange, nDistance;
                return sub_00461AC0_IsInAuraRange(pSkill, pUnit, &nDistance, &nRange) != 0;
            }
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

static __forceinline void sub_SetPlayerAction(D2UnitStrc* pPlayer, int nState, int nAction, int nArg1, int nArg2)
{
    if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = nState;
        pPlayer->pPlayerData->nAction = nAction;
        pPlayer->pPlayerData->nArg1 = nArg1;
        pPlayer->pPlayerData->nArg2 = nArg2;
    }
}

static __forceinline void memset0(D2UnitTargetStrc* p) { int* q = (int*)p; for (int i = 0; i < 7; ++i) q[i] = 0; }

// build: context sub_004812E0_DoPlayerAction
static __declspec(noinline) void __stdcall sub_004812E0_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    D2UnitTargetStrc tTarget;
    if (sub_0044BEC0_GetClickFlags() & 8)
    {
        if (sub_00480BA0_CanUseSkillNow(pPlayer))
        {
            memset0(&tTarget);
            tTarget.nArg1 = nArg1;
            tTarget.nArg2 = nArg2;
            if (sub_00480C10_DispatchUnitCommand(0x18, pPlayer, &tTarget, 0))
                sub_004786A0_SendDwords2(4, nArg1, nArg2);
            sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
        }
    }
    else if (sub_00480BA0_CanUseSkillNow(pPlayer))
    {
        memset0(&tTarget);
        tTarget.nArg1 = nArg1;
        tTarget.nArg2 = nArg2;
        if (sub_00480C10_DispatchUnitCommand(0, pPlayer, &tTarget, 0))
            sub_004786A0_SendDwords2(2, nArg1, nArg2);
        sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
    }
    sub_SetPlayerAction(pPlayer, 1, nAction, nArg1, nArg2);
}

// 0x004815A0
static __declspec(noinline) int __stdcall sub_004815A0_TryUnitAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nAction)
{
    int bSelectable = 0;
    if (pUnit)
        bSelectable = (pUnit->dwFlags >> 1) & 1;
    if (!bSelectable)
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

static __forceinline D2SkillsTxt* sub_004814A0_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks_006CE268[(nBit) & 7])

// 0x004814A0
static __declspec(noinline) int __stdcall sub_004814A0_TryMonsterAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    if (sub_00464820_IsDeadOrDying(pUnit))
    {
        D2SkillStrc* pSkill;
        switch (nAction)
        {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            pSkill = UNITS_GetLeftSkill(pPlayer);
            break;

        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            pSkill = UNITS_GetRightSkill(pPlayer);
            break;

        default:
            pSkill = 0;
            break;
        }

        if (pSkill)
        {
            int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szUnitModeFile_006D8E84, 0x44F);
            D2SkillsTxt* pTxt = sub_004814A0_GetSkillsTxtRecord(nSkillId);
            if (pTxt && BITARRAY_CHECK((unsigned char*)pTxt, 56))
            {
                goto InRange;
            }
        }
        sub_00467A70_RefreshHoverUnit(0);
        return 0;
    }

    {
        int bSelectable = 0;
        if (pUnit)
            bSelectable = (pUnit->dwFlags >> 1) & 1;
        if (!bSelectable)
        {
            sub_00467A70_RefreshHoverUnit(0);
            return 0;
        }
    }

InRange:
    if (sub_00480C80_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        sub_004812E0_DoPlayerAction(pPlayer, nAction, nArg1, nArg2);
        return 0;
    }
    return 1;
}

// calling-convention shim (not game code)
int __stdcall sub_004812E0_Shim(D2UnitStrc* pUnit, int nAction, D2UnitStrc* pPlayer, int nArg2)
{
    return sub_004815A0_TryUnitAction(pUnit, pPlayer, 2, nArg2, nAction);
}

// calling-convention shim (not game code)
int __stdcall sub_004814A0_Shim(D2UnitStrc* pUnit, int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2)
{
    return sub_004814A0_TryMonsterAction(pUnit, pPlayer, nAction, nArg1, nArg2);
}
