#include "D2StatIds.h"
#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GemsTxt;
struct D2UnitTargetStrc;



#pragma pack(push, 1)
struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
    int dwItemId;
    int dwAction;
    int bSet;
};
#pragma pack(pop)

void __fastcall sub_0046F280(D2UnitStrc* pUnit, int nComponent);
void __fastcall sub_0046F950(D2UnitStrc* pUnit);
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);
int __fastcall sub_004C10E0_CanUseItem(D2UnitStrc* pUnit, D2UnitStrc* pItem);
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);
unsigned char __stdcall sub_00623D60_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall sub_00629A40(D2UnitStrc* pItem);
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);
void __stdcall sub_0063D1D0_InventoryItemCall(D2InventoryStrc* pInventory, D2UnitStrc* pItem);
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2GemsTxt* pGemsTxt, int nArg2, int nArg5);
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);

static void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pUnit, D2UnitStrc* pItem, int bForce)
{
    D2ItemsTxt* pItemsTxtRecord;
    D2GemsTxt* pGemsTxtRecord;

    if (!pUnit)
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        D2_ASSERT(pUnit->dwUnitType == UNIT_ITEM, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        sub_0065FEC0_ItemApplyProps(2, NULL, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2_ASSERT(pUnit->dwUnitType == UNIT_ITEM, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        sub_0065FEC0_ItemApplyProps(5, pUnit, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x48, ".\\UNIT\\Item.cpp"))
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        if (UNITS_CanDualWield(pUnit))
        {
            int bType = 1;
            if (pLeftHand && pItem != pLeftHand && ITEMSIsA(pItem, 0x2D))
            {
                bType = 0;
            }

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x64, ".\\UNIT\\Item.cpp") && !bForce)
            {
                return;
            }

            STATLIST_MergeStatLists(pUnit, pItem, bType);
            return;
        }
    }

    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x70, ".\\UNIT\\Item.cpp") && !bForce)
    {
        return;
    }

    STATLIST_MergeStatLists(pUnit, pItem, 1);
}

static void sub_004C1160_SaveSkillState(D2SkillStateStrc* pState, D2UnitStrc* pUnit)
{
    pState->nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    pState->nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    pState->nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pState->nLeftOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\Item.cpp", 0x155);
    }
    else
    {
        pState->nLeftOwnerGUID = -1;
        pState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pState->nRightOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\UNIT\\Item.cpp", 0x161);
    }
    else
    {
        pState->nRightOwnerGUID = -1;
        pState->nRightSkillId = 0;
    }
}

static void sub_004C1200_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
{
    if (pState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetLeftActiveSkill(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
                break;
            }
        }
    }

    if (pState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetRightActiveSkill(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
                break;
            }
        }
    }
}

static void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem || !pUnit->pInventory)
        return;

    sub_0063D2B0_DetachItem(pUnit->pInventory, pItem);
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
    sub_0046F280(pUnit, nComponent);
}

static void __stdcall sub_004C12F0_ReattachItem(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0x0B || nBodyLoc == 0x0C)
        return;

    sub_0063D2B0_DetachItem(pInventory, pItem);
    sub_0046F280(pUnit, nComponent);
    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
}

static __forceinline int sub_H18_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (pUnit->dwUnitType && !sub_H18_UnitFlag9(pUnit))
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2SkillStateStrc tState;
    int bChanged = 0;
    sub_004C1160_SaveSkillState(&tState, pUnit);

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (pItem && INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)
            && !STATLIST_GetOwner(pItem, NULL) && sub_004C10E0_CanUseItem(pUnit, pItem))
        {
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        }
    }

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x203, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x208, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (sub_004C10E0_CanUseItem(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        sub_004C1290_AttachItem(sub_00623D60_GetItemComponent(pUnit, pItem), pUnit, pItem);
        bChanged = 1;
    }

    int nTries = 100;
    int bMore;
    do
    {
        bMore = 0;
        for (int i = 0; i < 0x0B; ++i)
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (!pItem)
                continue;

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x226, ".\\UNIT\\Item.cpp"))
                continue;

            if (!ITEMS_CheckItemFlag(pItem, 0x4000, 0x22A, ".\\UNIT\\Item.cpp") && STATLIST_GetOwner(pItem, NULL))
                continue;

            if (!sub_004C10E0_CanUseItem(pUnit, pItem))
                continue;

            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            const int nComponent = sub_00623D60_GetItemComponent(pUnit, pItem);
            const int nMode = pItem->dwAnimMode;
            D2InventoryStrc* pBodyInventory = pUnit->pInventory;
            if (pBodyInventory)
            {
                const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
                if (nBodyLoc != 0x0B && nBodyLoc != 0x0C)
                {
                    sub_0063D2B0_DetachItem(pBodyInventory, pItem);
                    sub_0046F280(pUnit, nComponent);
                    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
                        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

                    sub_0063D1D0_InventoryItemCall(pBodyInventory, pItem);
                }
            }
            bMore = 1;
            bChanged = 1;
        }
    }
    while (bMore && nTries--);

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && !ITEMS_CheckItemFlag(pItem, 0x100, 0x247, ".\\UNIT\\Item.cpp")
            && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x248, ".\\UNIT\\Item.cpp"))
        {
            if (pUnit->dwUnitType == UNIT_PLAYER)
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

            ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        }
    }

    sub_004C1200_RestoreSkillState(pUnit, &tState);
    if (bChanged)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_0046F950(pUnit);
            sub_00470610_Refresh(pUnit, 0);
        }
        else
        {
            sub_004AFF60_MonsterCommand(7, pUnit, NULL);
        }
    }
}

void __fastcall sub_004C2270(D2GSPacketSrv7DStrc* pPacket)
{
    D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
    if (!pItem)
        return;

    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nComponent = sub_00623D60_GetItemComponent(pUnit, pItem);
    const int nMode = pItem->dwAnimMode;
    if (pPacket->dwAction == 0x100)
    {
        ITEMS_SetItemFlag(pItem, 0x100, pPacket->bSet);
        sub_0046F950(pUnit);
        sub_004C1290_AttachItem(nComponent, pUnit, pItem);
        sub_00470610_Refresh(pUnit, 0);
        ITEMS_UpdateSets(pUnit, pItem, 1, 1);
        sub_004C1350_RefreshEquippedItems(pUnit);
    }
    else if (pPacket->dwAction == 0x200)
    {
        ITEMS_SetItemFlag(pItem, 0x100, 0);
        sub_004C12F0_ReattachItem(nMode, nComponent, pUnit, pItem);
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
        sub_004C1350_RefreshEquippedItems(pUnit);
    }
}

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02[1];
    unsigned int dwUnitId;
    unsigned char unk0x07[4];
};
#pragma pack(pop)

// 0x004C1BE0
static void sub_004C1BE0_RefreshUnitItems(D2UnitStrc* pUnit)
{
    sub_004C1350_RefreshEquippedItems(pUnit);
}

// 0x004C1BF0
void __fastcall sub_004C1BF0(D2PacketRecord11Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
        sub_004C1BE0_RefreshUnitItems(pUnit);
}

// 0x004C1C10
void __fastcall sub_004C1C10(D2UnitStrc* pUnit)
{
    sub_004C1350_RefreshEquippedItems(pUnit);
}


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
struct Unit006280A0;
extern "C" unsigned int __stdcall sub_006280A0(Unit006280A0* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260
int __fastcall sub_004C1E40_SetChargedSkill(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges);

// 0x004C1F30
void __fastcall sub_004C1F30(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE)
{
    D2UnitStrc* pItem = sub_00463990(nA, 4);
    if (!pItem)
        return;

    if (nC == 0xCC)
    {
        if (sub_00463DD0_GetPlayerUnit())
            sub_004C1E40_SetChargedSkill(pItem, nE >> sgptDataTables->nStuff, nE & sgptDataTables->nShiftedStuff, nD & 0xFF);
        return;
    }

    if (nB == 1)
        STATLIST_SetUnitStat(pItem, nC, nD, 0);

    if (!sub_00463DD0_GetPlayerUnit())
        return;

    if (nC != 0x46)
    {
        sub_004C1350_RefreshEquippedItems(sub_00463DD0_GetPlayerUnit());
        return;
    }

    if ((int)nD <= 0)
        return;

    if (sub_006280A0((Unit006280A0*)pItem, 4, 0xA38, (unsigned int)".\\UNIT\\Item.cpp"))
        ITEMS_SetItemFlag(pItem, 4, 0);

    if (sub_006280A0((Unit006280A0*)pItem, 0x4000, 0xA3C, (unsigned int)".\\UNIT\\Item.cpp"))
        ITEMS_SetItemFlag(pItem, 0x4000, 0);
}
