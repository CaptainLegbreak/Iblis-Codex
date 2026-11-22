#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_ASSERT_LINE(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GemsTxt;

struct D2GSPacketSrv9D;

struct D2ItemSaveStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

D2UnitStrc* __stdcall sub_0063BEF0_GetLeftWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

void __stdcall ITEMMODS_AssignProperty(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nArg2, int nArg5); // 0x0065FEC0

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

static void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfnCallback); // 0x00625CE0

void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004C21E0

#pragma pack(push, 1)

struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char pBitstream[244];
};

#pragma pack(pop)

int __cdecl sub_0044DCC0(); // 0x0044DCC0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomBySubtile(int nX, int nY); // 0x00465420

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __cdecl sub_00487990_ResetHover(); // 0x00487990

void __fastcall sub_004B2A00(int nUnitId); // 0x004B2A00

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910

void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem); // 0x004C2180

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0

int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

struct D2MonCommandStrc;

struct D2UnitStrc;

#define NULL 0

struct D2InventoryStrc;

struct D2SkillStrc;

struct D2UnitTargetStrc;

void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280

void __fastcall sub_0046F950(D2UnitStrc* pUnit);                                                            // 0x0046F950

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60

int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem);                               // 0x004C10E0

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00623D60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0

void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

static void sub_004C1160_SaveSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState); // 0x004C1160

static void sub_004C1200_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState); // 0x004C1200

static void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x004C1290

static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit);

static inline int GetUnitType(D2UnitStrc* p)
{
    if (p)
    {
        return p->dwUnitType;
    }
    return 6;
}

static inline D2InventoryStrc* GetInventory(D2UnitStrc* p)
{
    if (p)
    {
        return p->pInventory;
    }
    return 0;
}

// 0x004C0D20
static void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce)
{
    D2ItemsTxt* pItemsTxtRecord;
    D2GemsTxt* pGemsTxtRecord;

    if (!pUnit)
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x32);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x34);
        ITEMMODS_AssignProperty(2, NULL, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x3C);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x3E);
        ITEMMODS_AssignProperty(5, pUnit, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x48, ".\\UNIT\\Item.cpp"))
    {
        return;
    }

    if (GetUnitType(pUnit) == 0)
    {
        D2UnitStrc* pLeftHand = sub_0063BEF0_GetLeftWeapon(GetInventory(pUnit));
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

static void sub_004C1160_SaveSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
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
            switch (sub_004D9FC0(pUnit, pSkill))
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
            switch (sub_004D9FC0(pUnit, pSkill))
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

    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, nComponent);
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline void ITEM_RemoveItemStats(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
}

static inline void ITEM_ReattachItem(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0x0B || nBodyLoc == 0x0C)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, nComponent);
    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
        sub_004C0D20_ApplyItemStats(pItem, pUnit, 1);

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
}

static inline int sub_H18_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// 0x004C1350
static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (sub_0044BE50(pUnit) && !sub_H18_UnitFlag9(pUnit))
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2SkillStateStrc tState;
    int bChanged = 0;
    sub_004C1160_SaveSkillState(pUnit, &tState);

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (pItem && INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)
            && !STATLIST_GetOwner(pItem, NULL) && sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
        {
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            sub_004C0D20_ApplyItemStats(pItem, pUnit, 0);
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

        if (sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        const int nComponent = UNITS_GetItemComponentId(pUnit, pItem);
        sub_004C1290_AttachItem(nComponent, pUnit, pItem);
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

            if (!sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
                continue;

            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            ITEM_ReattachItem(pItem->dwAnimMode, UNITS_GetItemComponentId(pUnit, pItem), pUnit, pItem);
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
            ITEM_RemoveItemStats(pUnit, pItem);
            sub_004C0D20_ApplyItemStats(pItem, pUnit, 0);
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

void __stdcall sub_004C0D20_CallerA(int nArg, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    sub_004C0D20_ApplyItemStats(pItem, pUnit, 0);
    ITEMS_UpdateSets(pUnit, pItem, nArg, nArg);
    sub_004C0D20_ApplyItemStats(pItem, pUnit, nArg);
    ITEMS_UpdateSets(pUnit, pItem, nArg, 0);
}

// 0x004C1E40
int __fastcall sub_004C1E40_SetChargedSkill(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges)
{
    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        int nValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nLayer);
        if (nValue)
        {
            nValue >>= 8;
            if (nValue > 0 && nValue <= 255)
            {
                nCharges = D2_MIN(D2_MAX(nCharges, 0), nValue);
                STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, (nValue << 8) + (nCharges & 0xFF), nLayer, pItem);
                return 1;
            }
            return 0;
        }
    }

    D2InventoryStrc* pInventory = pItem->pInventory;
    if (pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (sub_004C1E40_SetChargedSkill(pSocketed, nSkillId, nSkillLevel, nCharges))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x004C21F0
void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_UNINTERRUPTABLE);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x0C, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        STATLIST_SetState(pStatList, STATE_UNINTERRUPTABLE);
        STATLIST_SetStatRemoveCallback(pStatList, sub_004C21E0_StatRemoveCallback_ToggleStateOff);
    }
    else
    {
        STATLIST_SetState(pStatList, STATE_UNINTERRUPTABLE);
    }
}

static D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    int nSize = pPacket->nPacketSize - 13;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 254, ".\\UNIT\\Item.cpp"))
        {
            sub_00478680_SendPacket5(0x37, pPacket->nItemId);
        }
    }
    return pItem;
}

static __declspec(noinline) void __stdcall sub_004C2540_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage)
{
    D2_ASSERT_LINE(pItem, 172);

    D2ActiveRoomStrc* pRoom = 0;
    if (bFindRoom && (nX || nY))
    {
        pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
    }
    sub_004C1910_SetItemMode(pItem, pRoom, nX, nY, nMode, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// 0x004C2C80
void __fastcall sub_004C2C80(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 13, 0, &tItemSave);

    D2UnitStrc* pOwner = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pOwner)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        if (tItemSave.nStorePage == 1)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }

    D2InventoryStrc* pInventory = pOwner->pInventory;
    D2_ASSERT_LINE(pInventory, 1207);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        if (tItemSave.nStorePage == 2)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }
    D2_ASSERT_LINE(pRemoved == pItem, 1227);

    unsigned char nPage = ITEMS_GetInvPage(pItem);
    int bLoD = sub_0044DCC0();
    int nInventoryRecordId = UNITS_GetInventoryRecordId(pOwner, nPage, bLoD);
    INVENTORY_Return(".\\UNIT\\Item.cpp", 1231, pInventory, tItemSave.nX, tItemSave.nY, nInventoryRecordId, 1, nPage);
    sub_00487990_ResetHover();

    if (pOwner->dwUnitType == UNIT_PLAYER)
    {
        sub_0063BEF0_GetLeftWeapon(pOwner->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 150, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pOwner, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0FF0_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT_LINE(pItem, 1245);
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nX, tItemSave.bMode, 0, tItemSave.nStorePage);
        }

        ITEMS_SetInvPage(pItem, 0xFF);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
    else
    {
        sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, 4);
        if (pOwner == sub_00463DD0_GetPlayerUnit())
        {
            if (tItemSave.nStorePage == 1)
            {
                sub_004B9A00(1, 0, 0, 0, 0);
            }
            else
            {
                sub_00468070_SetCursorItemState(0);
            }
        }
    }

    if (pOwner == sub_00463DD0_GetPlayerUnit())
    {
        sub_004B2A00(pItem->dwUnitId);
    }
}

void __fastcall sub_BF69_Emit_004C1350(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    ITEMS_SetItemFlag(pItem, 0x100, 0);
    sub_004C1350_RefreshEquippedItems(pUnit);
    ITEMS_UpdateSets(pUnit, pItem, 0, 0);
}
