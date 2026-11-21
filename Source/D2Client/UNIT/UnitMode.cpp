#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define D2_ABS(n) ((n) < 0 ? -(n) : (n))

struct D2ClientSkillCmdStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2StaticPathStrc;

struct D2UnitTargetStrc;

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath); // 0x00650590

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall sub_004E4020(D2UnitStrc* pUnit); // 0x004E4020

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __cdecl sub_004DF800(); // 0x004DF800

struct D2ClientSkillCmdStrc
{
    int nSkillId;
    int nOwnerGUID;
    int nTargetType;
    int f_C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillCmdStrc* pArgs); // 0x004C6EB0

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned short __cdecl sub_0044BEC0_GetClickFlags(); // 0x0044BEC0

int __cdecl sub_0044DAA0(); // 0x0044DAA0

void __fastcall sub_0044DAD0(int nValue); // 0x0044DAD0

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470

int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2); // 0x0047A4F0

void __fastcall sub_00480B40_SendPacket(int nHeader, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00480B40

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0

int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140

void __cdecl sub_K04_EmitUse(D2UnitStrc* pUnit);

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0

int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00480C10

extern "C" void __stdcall sub_00648750(D2DynamicPathStrc* pDynamicPath, int bSet); // 0x00648750

struct D2SkillStrc;

extern "C" const char szUnitModeFile_006D8E84[];                                                            // 0x006D8E84

int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10

static int sub_00480BA0_CanUseSkillNow(D2UnitStrc* pPlayer);

static int sub_00480C80_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction);

static int sub_00480C80_IsTargetInRange(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nAction);

#pragma intrinsic(memset)

void __fastcall sub_00481030_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3); // 0x00481030

static void __stdcall sub_004812E0_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2);

static int __stdcall sub_004814A0_TryMonsterAction(int nAction, int nArg1, int nArg2, D2UnitStrc* pPlayer, D2UnitStrc* pUnit);

static __forceinline void memset0(D2UnitTargetStrc* p) { int* q = (int*)p; for (int i = 0; i < 7; ++i) q[i] = 0; }

void __fastcall sub_00481030_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3);

static int __stdcall sub_00481400_ActOnPlayer(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit);


// 0x00480490
void __fastcall sub_00480490_RecacheUnitPath(D2UnitStrc* pUnit)
{
    PATH_RecacheRoomIfNeeded(pUnit->pDynamicPath);
}

// 0x00480930
void __fastcall sub_00480930_InteractWithUnit(unsigned short nType, int nUnitId)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(nUnitId, nType);
    if (!pUnit)
    {
        return;
    }

    switch (nType)
    {
    case 2:
    {
        PATH_SetTargetUnit(pPlayer->pDynamicPath, 0);
        int bSelectable = 0;
        if (pUnit)
        {
            bSelectable = (pUnit->dwFlags >> 2) & 1;
        }

        if (bSelectable)
        {
            UNITS_UpdateDirectionAndSpeed(pPlayer, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));

            D2ClientSkillCmdStrc tCmd;
            memset(&tCmd, 0, sizeof(tCmd));
            tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_KICK), ".\\UNIT\\UnitMode.cpp", 525);
            if (pUnit->dwClassId == 404)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20326671)
                    {
                        sub_004CB9C0_Request(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, SKILL_ATTACK, -1), ".\\UNIT\\UnitMode.cpp", 536);
                }
            }
            else if (pUnit->dwClassId == 376)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    sub_004786A0_SendDwords2(0x13, nType, nUnitId);
                    return;
                }

                if (pUnit->dwAnimMode == 2)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20686668)
                    {
                        sub_004CB9C0_Request(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, SKILL_ATTACK, -1), ".\\UNIT\\UnitMode.cpp", 558);
                }
            }

            tCmd.nOwnerGUID = -1;
            tCmd.nTargetType = 2;
            tCmd.f_C = nUnitId;
            sub_004C6EB0_StartSkillOnUnit(pPlayer, &tCmd);
        }
        break;
    }

    case 1:
    {
        const unsigned int nTick = GetTickCount();
        if (nTick - pUnit->dwTickCount < 200)
        {
            return;
        }

        pUnit->dwTickCount = nTick;
        break;
    }

    case 0:
        UNITS_UpdateDirectionAndSpeed(pPlayer, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        break;

    case 4:
        sub_004786D0_SendDwords3(0x16, 4, nUnitId, (unsigned char)sub_004538D0(1));
        return;
    }

    sub_004786A0_SendDwords2(0x13, nType, nUnitId);
}

static __forceinline D2SkillsTxt* UMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline D2PlayerDataStrc* UMODE_GetPlayerData(D2UnitStrc* pUnit)
{
    return (pUnit && pUnit->dwUnitType == UNIT_PLAYER) ? pUnit->pPlayerData : 0;
}

static __forceinline int UMODE_GetPendingFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nState;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nMode;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingType(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nArg1;
    }
    return 0;
}

static __forceinline int UMODE_GetPendingId(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nArg2;
    }
    return 0;
}

static __forceinline void UMODE_SetPendingAction(D2UnitStrc* pUnit, int bFlag, int nAction, int nType, int nId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = bFlag;
        pUnit->pPlayerData->nMode = nAction;
        pUnit->pPlayerData->nArg1 = nType;
        pUnit->pPlayerData->nArg2 = nId;
    }
}

static __forceinline int UMODE_IsTargetable(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 1) & 1 : 0;
}

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

    if (pUnit && pUnit->dwUnitType == UNIT_OBJECT)
    {
        if (sub_00623660_IsInObjectInteractRange(pPlayer, pUnit) && !sub_00622B50_IsRayFreeBetweenUnits(pPlayer, pUnit, 0x804))
        {
            return 0;
        }
        return 1;
    }

    return UNITS_IsInMeleeRange(pPlayer, pUnit, UNITS_IsInMovingModeEx(pUnit)) == 0;
}

// 0x00480D20
void __fastcall sub_00480D20_SetModeOverlay(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit)
        return;

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nMode != 0 && nMode != 4 && nMode != 0x13)
            return;
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (nMode != 0 && nMode != 3 && nMode != 0xD)
            return;
    }
    else
    {
        return;
    }

    const unsigned int dwFlags = pUnit->dwLastHitClass;
    const unsigned int dwKind = dwFlags & 0xF0;
    if (!dwKind || !(dwFlags & 0xF))
        return;

    if (dwKind == 0x20)
        sub_00470390(pUnit, 0x51, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x30)
        sub_00470390(pUnit, 0x24, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x40)
        sub_00470390(pUnit, 1, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x10)
        sub_00470390(pUnit, 0x36, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x70)
        sub_00470390(pUnit, 0x93, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x80)
        sub_00470390(pUnit, 0x15, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x90)
        sub_00470390(pUnit, 0x71, 2, 0, 0, 0, 0, 0);
}

static void __stdcall sub_004812E0_QueueAction(int nAction, int nType, int nId, D2UnitStrc* pPlayer)
{
    if (sub_0044BEC0_GetClickFlags() & 8)
    {
        if (!sub_00480BA0_CanUseSkillNow(pPlayer))
        {
            UMODE_SetPendingAction(pPlayer, 1, nAction, nType, nId);
            return;
        }

        int args[7] = {};
        args[0] = nType;
        args[1] = nId;
        if (sub_00480C10_UnitEvent(0x18, pPlayer, args, 0))
        {
            sub_004786A0_SendDwords2(4, nType, nId);
        }
    }
    else
    {
        if (!sub_00480BA0_CanUseSkillNow(pPlayer))
        {
            UMODE_SetPendingAction(pPlayer, 1, nAction, nType, nId);
            return;
        }

        int args[7] = {};
        args[0] = nType;
        args[1] = nId;
        if (sub_00480C10_UnitEvent(0, pPlayer, args, 0))
        {
            sub_004786A0_SendDwords2(2, nType, nId);
        }
    }

    UMODE_SetPendingAction(pPlayer, 0, 0, 0, 0);
    UMODE_SetPendingAction(pPlayer, 1, nAction, nType, nId);
}

static int __stdcall sub_004814A0_ActOnMonster(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
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
            D2SkillsTxt* pSkillsTxt = UMODE_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, szUnitModeFile_006D8E84, 0x44F));
            if (pSkillsTxt && BITARRAY_CHECK((unsigned char*)pSkillsTxt, 56))
            {
                goto LABEL_OK;
            }
        }
        sub_00467A70_RefreshHoverUnit(0);
        return 0;
    }

    if (!UMODE_IsTargetable(pUnit))
    {
        sub_00467A70_RefreshHoverUnit(0);
        return 0;
    }

LABEL_OK:
    if (!sub_00480C80_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        return 1;
    }

    sub_004812E0_QueueAction(nAction, nType, nId, pPlayer);
    return 0;
}

static int __stdcall sub_004815A0_ActOnObject(D2UnitStrc* pPlayer, int nType, int nId, int nAction, D2UnitStrc* pUnit)
{
    if (!UMODE_IsTargetable(pUnit))
    {
        sub_00467A70_RefreshHoverUnit(0);
        return 0;
    }

    if (!sub_00480C80_IsTargetInRange(pPlayer, pUnit, nAction))
    {
        return 1;
    }

    sub_004812E0_QueueAction(nAction, nType, nId, pPlayer);
    return 0;
}

void __fastcall sub_00481600_RunPendingAction(D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UMODE_GetPlayerData(pPlayer);
    if (!pPlayerData || !pPlayerData->nState)
    {
        return;
    }

    const int nAction = pPlayer->dwUnitType == UNIT_PLAYER ? pPlayer->pPlayerData->nMode : 0;
    const int nType = pPlayer->dwUnitType == UNIT_PLAYER ? pPlayer->pPlayerData->nArg1 : 0;
    const int nId = pPlayer->dwUnitType == UNIT_PLAYER ? pPlayer->pPlayerData->nArg2 : 0;

    D2UnitStrc* pUnit = sub_00463990(nId, nType);
    sub_0045C470_ClearPendingAction(pPlayer);

    if (nAction == 0x13 && nType == 5)
    {
        sub_0044DAD0(sub_0044DAA0() + 500);
    }

    if (!pUnit || !nAction)
    {
        return;
    }

    switch (nType)
    {
    case 0:
        if (!sub_00481400_ActOnPlayer(nAction, 0, nId, pPlayer, pUnit))
        {
            return;
        }
        break;

    case 1:
        if (!sub_004814A0_ActOnMonster(nAction, 1, nId, pPlayer, pUnit))
        {
            return;
        }
        break;

    case 2:
        if (!sub_004815A0_ActOnObject(pPlayer, 2, nId, nAction, pUnit))
        {
            return;
        }
        break;

    default:
        if (!sub_00451F30_TestUnitFlag(pUnit, 2))
        {
            sub_00467A70_RefreshHoverUnit(0);
            return;
        }
        break;
    }

    sub_00481030_DoUnitAction(nAction, pPlayer, nType, nId, 0);
}

// 0x00480E30
static int __stdcall sub_00480E30_SetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40u;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        sub_00470610_Refresh(pUnit, 0);
        return 1;
    }
    return 0;
}

// 0x00480E70
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        sub_00470610_Refresh(pUnit, 0);
        sub_00480D20_SetModeOverlay(pUnit, nMode);
        sub_004CC5B0_RequestMode(pUnit, nMode, 0);
    }
}

// 0x00480EC0
void __fastcall sub_00480EC0_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
        sub_00470610_Refresh(pUnit, 0);
}

int __cdecl sub_K04_EmitSetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    const int bOk = sub_00480E30_SetUnitMode(pUnit, nMode);
    sub_K04_EmitUse(pUnit);
    return bOk;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00480EF0
void __fastcall sub_00480EF0_MoveToPosition(D2UnitStrc* pUnit, int nX, int nY, int bSetPosition)
{
    int bMove = 0;
    int nDiff = nX - UNITS_GetUnitXPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }
    nDiff = nY - UNITS_GetUnitYPosition(pUnit);
    if (D2_ABS(nDiff) > 1)
    {
        bMove = 1;
    }

    const int nType = pUnit->dwUnitType;
    if ((nType != UNIT_MONSTER || sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 2)) && bMove)
    {
        D2UnitTargetStrc tTarget;
        tTarget.nParam1 = nX;
        tTarget.nParam2 = nY;
        int nCommand = 1;
        switch (nType)
        {
        case UNIT_PLAYER:
            if (pUnit != sub_00463DE0_GetPlayerUnit())
            {
                if (bSetPosition)
                {
                    sub_004804E0_SetPosition(pUnit, nX, nY, 2, 0, 0);
                    return;
                }
                nCommand = 0x17;
            }
            break;

        case UNIT_MONSTER:
            tTarget.unk0x0C[0] = 1;
            break;
        }
        tTarget.unk0x0C[1] = 100;
        tTarget.unk0x0C[2] = 15;
        sub_00480C10_DispatchUnitCommand(nCommand, pUnit, &tTarget, 0);
    }
    else
    {
        sub_00648750(pUnit->pDynamicPath, 0);
    }
}

// 0x00481030
void __fastcall sub_00481030_DoUnitAction(int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nArg3)
{
    if (!sub_00480BA0_CanUseSkillNow(pPlayer))
    {
        return;
    }

    int args[7] = {};
    args[0] = nArg1;
    args[1] = nArg2;

    int nEvent;
    switch (nAction)
    {
    case 1:
        nEvent = 1;
        break;

    case 2:
        nEvent = 0;
        break;

    case 3:
        nEvent = 0x17;
        break;

    case 4:
        nEvent = 0x18;
        break;

    case 19:
        if (nArg1 == 4)
        {
            D2UnitStrc* pItem = sub_00463990(nArg2, nArg1);
            if (pItem && pItem->dwUnitType == UNIT_ITEM && !sub_00451F30_TestUnitFlag(pItem, 2))
            {
                return;
            }
        }
        nEvent = 2;
        break;

    case 5:
    case 8:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), szUnitModeFile_006D8E84, 0x32C);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 6:
    case 7:
    case 9:
    case 10:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), szUnitModeFile_006D8E84, 0x336);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetLeftSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    case 12:
    case 15:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), szUnitModeFile_006D8E84, 0x33E);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x15;
        break;

    case 13:
    case 14:
    case 16:
    case 17:
        args[0] = SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), szUnitModeFile_006D8E84, 0x348);
        args[1] = SKILLS_GetOwnerGUIDFromSkill(UNITS_GetRightSkill(pPlayer));
        args[2] = nArg1;
        args[3] = nArg2;
        nEvent = 0x16;
        break;

    default:
        D2_ASSERT(0, 0x352);
    }

    if (nEvent == 1 || nEvent == 0x17)
    {
        if (UMODE_GetPendingAction(pPlayer) == 19)
        {
            return;
        }
    }

    if (sub_00480C10_UnitEvent(nEvent, pPlayer, args, 0))
    {
        switch (nAction)
        {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            STATLIST_SetUnitStat(pPlayer, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pPlayer, STAT_PIERCE_IDX, 0) + 1, 0);
            break;
        }
        sub_00480B40_SendPacket(nAction, pPlayer, nArg1, nArg2, nArg3);
    }

    UMODE_SetPendingAction(pPlayer, 0, 0, 0, 0);
}

// build: context sub_GetPlayerDataOrNull
static __forceinline D2PlayerDataStrc* sub_GetPlayerDataOrNull(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
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

// 0x004812E0
static void __stdcall sub_004812E0_DoPlayerAction(D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
{
    D2UnitTargetStrc tTarget;
    if (sub_0044BEC0_GetClickFlags() & 8)
    {
        if (sub_00480BA0_CanUseSkillNow(pPlayer))
        {
            memset(&tTarget, 0, sizeof(tTarget));
            tTarget.nParam1 = nArg1;
            tTarget.nParam2 = nArg2;
            if (sub_00480C10_DispatchUnitCommand(0x18, pPlayer, &tTarget, 0))
                sub_004786A0_SendDwords2(4, nArg1, nArg2);
            sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
        }
    }
    else if (sub_00480BA0_CanUseSkillNow(pPlayer))
    {
        memset(&tTarget, 0, sizeof(tTarget));
        tTarget.nParam1 = nArg1;
        tTarget.nParam2 = nArg2;
        if (sub_00480C10_DispatchUnitCommand(0, pPlayer, &tTarget, 0))
            sub_004786A0_SendDwords2(2, nArg1, nArg2);
        sub_SetPlayerAction(pPlayer, 0, 0, 0, 0);
    }
    sub_SetPlayerAction(pPlayer, 1, nAction, nArg1, nArg2);
}

static int __stdcall sub_004815A0_TryUnitAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nArg1, int nArg2, int nAction)
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

// calling-convention shim (not game code)
int __stdcall sub_004812E0_Shim(D2UnitStrc* pUnit, int nAction, D2UnitStrc* pPlayer, int nArg2)
{
    return sub_004815A0_TryUnitAction(pUnit, pPlayer, 2, nArg2, nAction);
}

// 0x00481400
static int __stdcall sub_00481400_ActOnPlayer(int nAction, int nType, int nId, D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
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

int sub_0044BE50(D2UnitStrc* pUnit); // 0x0044BE50

static __forceinline D2SkillsTxt* sub_004814A0_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004814A0
static int __stdcall sub_004814A0_TryMonsterAction(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nAction, int nArg1, int nArg2)
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

// 0x00481780
int __cdecl sub_00481780_GetPlayerLevelId()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return 0;
    return DUNGEON_GetLevelIdFromRoom(pRoom);
}

// 0x004817A0
int __cdecl sub_004817A0_GetPlayerSoundEnv()
{
    int nLevelId = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
            nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (!nLevelId)
        return 0;
    return DATATBLS_GetLevelsTxtRecord(nLevelId)->nSoundEnv;
}

// 0x00481830
void __cdecl sub_00481830()
{
    sub_004DF800();
    sub_004BAAB0();
}

// calling-convention shim (not game code)
int __stdcall sub_004814A0_Shim(D2UnitStrc* pUnit, int nAction, D2UnitStrc* pPlayer, int nArg1, int nArg2)
{
    return sub_004814A0_TryMonsterAction(pUnit, pPlayer, nAction, nArg1, nArg2);
}
