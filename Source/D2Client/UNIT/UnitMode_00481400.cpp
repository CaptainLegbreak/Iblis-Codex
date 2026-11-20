#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
struct D2UnitStrc;
struct D2SkillStrc;
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
int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
unsigned short __cdecl sub_0044BEC0_GetClickFlags(); // 0x0044BEC0
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00480C10
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2); // 0x0047A4F0
void __fastcall sub_00481030_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3); // 0x00481030
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
int __cdecl sub_0044DAA0(); // 0x0044DAA0
void __fastcall sub_0044DAD0(int nValue); // 0x0044DAD0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30
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
        if (sub_00623660_IsInObjectInteractRange(pPlayer, pUnit) && !sub_00622B50_IsRayFreeBetweenUnits(pPlayer, pUnit, 0x804))
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
        pPlayer->pPlayerData->nMode = nAction;
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

// 0x004814A0
static __declspec(noinline) int __stdcall sub_004814A0_TryMonsterAction(int nAction, int nArg1, int nArg2, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
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
            D2SkillsTxt* pTxt = UMODE_GetSkillsTxtRecord(nSkillId);
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

// 0x00481400
static __declspec(noinline) int __stdcall sub_00481400_ActOnPlayer(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (sub_00464820_IsDeadOrDying(pUnit))
    {
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        if (sub_0047A4F0_TestFlag1(nPlayerId, nId))
        {
            sub_00481030_DoUnitAction(nAction, pPlayer, nType, nId, 0);
            return 0;
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

    if (sub_00480C80_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        sub_004812E0_DoPlayerAction(pPlayer, nAction, nType, nId);
        return 0;
    }

    return 1;
}

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// 0x00481600
void __fastcall sub_00481600_RunPendingAction(D2UnitStrc* pPlayer)
{
    if (sub_0044BE50(pPlayer) == 0 && pPlayer->pPlayerData && pPlayer->pPlayerData->nState)
    {
        const int nAction = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nMode : 0;
        const int nArg1 = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nArg1 : 0;
        const int nArg2 = sub_0044BE50(pPlayer) == 0 ? pPlayer->pPlayerData->nArg2 : 0;

        D2UnitStrc* pUnit = sub_00463990(nArg2, nArg1);
        sub_0045C470_ClearPendingAction(pPlayer);

        if (nAction == 0x13 && nArg1 == 5)
        {
            sub_0044DAD0(sub_0044DAA0() + 500);
        }

        if (pUnit && nAction)
        {
            switch (nArg1)
            {
            case 0:
                if (!sub_00481400_ActOnPlayer(nAction, 0, nArg2, pPlayer, pUnit))
                    return;
                break;
            case 1:
                if (!sub_004814A0_TryMonsterAction(nAction, 1, nArg2, pPlayer, pUnit))
                    return;
                break;
            case 2:
                if (!sub_004815A0_TryUnitAction(pUnit, pPlayer, 2, nArg2, nAction))
                    return;
                break;
            default:
                if (!sub_00451F30_TestUnitFlag(pUnit, 2))
                {
                    sub_00467A70_RefreshHoverUnit(0);
                    return;
                }
                break;
            }
            sub_00481030_DoUnitAction(nAction, pPlayer, nArg1, nArg2, 0);
        }
    }
}
