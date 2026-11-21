#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2GameRecords.h"

struct D2MonCommandStrc;

struct D2SkillStrc;

struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GemsTxt;

struct D2UnitTargetStrc;

#pragma pack(push, 1)

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};

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

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

void __cdecl sub_00453B00_SendMouseMove();                                                                  // 0x00453B00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680

void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990

void __fastcall sub_004B2A00(int nUnitId);                                                                  // 0x004B2A00

void __fastcall sub_004B2A40(int nUnitId);                                                                  // 0x004B2A40

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);          // 0x004B9A00

void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910

int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60

void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem);                                           // 0x004C2180

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250

int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem);                                                              // 0x00629A40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

void __fastcall sub_0046F950(D2UnitStrc* pUnit);                                                            // 0x0046F950

void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

void __fastcall sub_004B2640(int nUnused); // 0x004B2640

void __fastcall sub_004B2A80_ResetHoverForItem(int nUnitId);                                                // 0x004B2A80

int __cdecl sub_004B2E20_IsQuestActive();                                                                   // 0x004B2E20

int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230

void __fastcall sub_00498D50(int nX, int nArg);                                                             // 0x00498D50

void __cdecl sub_00498D60();                                                                                // 0x00498D60

void __fastcall sub_004B2A60(int nUnitId);                                                                  // 0x004B2A60

short gwGlobal_007C78A8;                                                                                    // 0x007C78A8

short gwGlobal_007C78AC;                                                                                    // 0x007C78AC

void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue);                        // 0x0046F020

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand); // 0x004AFF60

void __fastcall sub_004B2A20(int nUnitId);                                                                  // 0x004B2A20

void __fastcall sub_004B3C00(int nUnitId);                                                                  // 0x004B3C00

int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem);                               // 0x004C10E0

int __fastcall sub_004C1C50_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);    // 0x004C1C50

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00623D60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880

void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860

void __cdecl sub_0044D520();                                                                                // 0x0044D520

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

#pragma pack(push, 1)

#pragma pack(pop)

static __declspec(noinline) void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit);

void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket);

static __forceinline int ITEMPKT_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int ITEMPKT_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline unsigned int ITEMPKT_GetItemCode(D2UnitStrc* pItem)
{
    return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->dwCode;
}

// build: context sub_004C0D20_ApplyItemStats
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
        ITEMMODS_AssignProperty(2, NULL, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2_ASSERT(pUnit->dwUnitType == UNIT_ITEM, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
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

static D2UnitStrc* __stdcall sub_004C0F20_CreateItem9C(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    const int nSize = pPacket->nPacketSize - 0x08;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_CreateClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        return NULL;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xD8, ".\\UNIT\\Item.cpp"))
        {
            sub_00478680_SendPacket5(0x37, pPacket->nItemId);
        }
    }

    return pItem;
}

static D2UnitStrc* __stdcall sub_004C0FF0_CreateItem9D(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    const int nSize = pPacket->nPacketSize - 0x0D;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_CreateClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        return NULL;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xFE, ".\\UNIT\\Item.cpp"))
        {
            sub_00478680_SendPacket5(0x37, pPacket->nItemId);
        }
    }

    return pItem;
}

static void sub_004C1160_SaveSkillState(D2SkillStateStrc* pState, D2UnitStrc* pUnit)
{
    pState->nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pState->nStamina = STATLIST_UnitGetStatValue(pUnit, 0x0A, 0);

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

static __declspec(noinline) void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
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

static __forceinline int ITEMPKT_UnitFlag9(D2UnitStrc* pUnit)
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

    if (pUnit->dwUnitType && !ITEMPKT_UnitFlag9(pUnit))
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
            && !STATLIST_GetOwner(pItem, NULL) && sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
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

        if (sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        sub_004C1290_AttachItem(UNITS_GetItemComponentId(pUnit, pItem), pUnit, pItem);
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
            const int nComponent = UNITS_GetItemComponentId(pUnit, pItem);
            const int nMode = pItem->dwAnimMode;
            D2InventoryStrc* pBodyInventory = pUnit->pInventory;
            if (pBodyInventory)
            {
                const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
                if (nBodyLoc != 0x0B && nBodyLoc != 0x0C)
                {
                    INVENTORY_UpdateWeaponGUIDOnRemoval(pBodyInventory, pItem);
                    sub_0046F280_ClearGfxBytes(pUnit, nComponent);
                    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
                        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

                    INVENTORY_UpdateWeaponGUIDOnInsert(pBodyInventory, pItem);
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
        if (pItem && ITEMS_GetItemQuality(pItem) == 5 && !ITEMS_CheckItemFlag(pItem, 0x100, 0x247, ".\\UNIT\\Item.cpp")
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

static __declspec(noinline) void sub_004C1C20_SetWeaponClass(D2UnitStrc* pItem, unsigned char nType)
{
    const int nWeaponClass = ITEMS_GetWeaponClassId(pItem);
    if (nType == 4)
        gwGlobal_007C78A8 = nWeaponClass;
    else if (nType == 5)
        gwGlobal_007C78AC = nWeaponClass;
}

static void __stdcall sub_004C2540_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage)
{
    D2_ASSERT(pItem, 0xAC);

    D2ActiveRoomStrc* pRoom = NULL;
    if (bFindRoom && (nX || nY))
    {
        pRoom = sub_00465420_FindRoomAt(nX, nY);
    }

    sub_004C1910_SetItemMode(pItem, pRoom, nX, nY, nMode, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// build: context sub_004C2970_PlaceItemAt
static void __stdcall sub_004C2970_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX)
{
    UNITS_SetXForStaticUnit(pItem, nX);
    UNITS_SetYForStaticUnit(pItem, nY);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x413);

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        return;
    }

    if (!sub_0063BCC0_PlaceItem(pInventory, pItem, ITEMPKT_GetUnitX(pItem), ITEMPKT_GetUnitY(pItem), UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0()), 1, nPage))
    {
        return;
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (nPage == 1)
        {
            sub_004B9A00(sub_004C1D60(pItem), NULL, 0, 0, 0);
        }
        else
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage == 3)
    {
        const int nClassId = pItem->dwClassId;
        const unsigned int dwCode = DATATBLS_GetItemsTxtRecord(nClassId)->dwCode;
        if (dwCode == 0x20747368 || dwCode == 0x20326671)
        {
            sub_0048A540();
        }
    }
}

static void __stdcall sub_004C1C90_RemoveBodyItem(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 4 || nBodyLoc == 5)
    {
        INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
        sub_0046F280_ClearGfxBytes(pUnit, UNITS_GetItemComponentId(pUnit, pItem));
        INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, nBodyLoc);
    }

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (pRemoved)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        sub_0063BE30(pInventory, nBodyLoc);
    }

    sub_00465EE0_RemoveClientSideUnit(!pItem ? -1 : pItem->dwUnitId, !pItem ? 6 : pItem->dwUnitType);
}

void __fastcall sub_004C2810(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        switch (pItem->dwAnimMode)
        {
        case 0:
            D2_ASSERT(0, 0x3FD);
            break;

        case 1:
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            D2_ASSERT(pPlayer, 0x3E9);

            D2InventoryStrc* pInventory = pPlayer->pInventory;
            sub_0046F950(pPlayer);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            sub_0046F280_ClearGfxBytes(pPlayer, UNITS_GetItemComponentId(pPlayer, pItem));

            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            INVENTORY_GetSecondWieldingWeapon(pPlayer, pInventory, &pItem, nBodyLoc);

            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            if (pRemoved)
            {
                sub_0063BE30(pInventory, nBodyLoc);
                if (pPlayer->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pPlayer, pRemoved);
                }
            }

            sub_004C1350_RefreshEquippedItems(pPlayer);
            sub_00470610_Refresh(pPlayer, 0);
            break;
        }
        }

        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    pItem = sub_004C0F20_CreateItem9C(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0x405);
    sub_004C2180_UpdateCursorItem(pItem);
}

void __fastcall sub_004C2E90(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_004C1C90_RemoveBodyItem(pItem, pUnit);
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        }
    }
    else
    {
        pItem = sub_004C0FF0_CreateItem9D(0, 0, pUnit == pPlayer, pPacket, &tItemSave);
    }

    if (pItem)
    {
        ITEMS_SetBodyLocation(pItem, tItemSave.nBodyloc);
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!sub_004C1C50_PlaceBodyItem(pInventory, pItem, tItemSave.nBodyloc))
    {
        return;
    }

    sub_0046F950(pUnit);
    if (nPage == 3)
    {
        INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
    }

    sub_0046F020_FillGfxEntries(pUnit, 0);
    switch (pUnit->dwUnitType)
    {
    case 0:
    case 1:
        break;

    default:
        return;
    }

    const unsigned char nComponent = pPacket->nComponent;
    if (nComponent == 0 || nComponent == 1)
    {
        sub_0046F280_ClearGfxBytes(pUnit, nComponent);
    }

    sub_00470610_Refresh(pUnit, 0);
    if (pUnit == pPlayer)
    {
        sub_004C1C20_SetWeaponClass(pItem, tItemSave.nBodyloc);
        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    if (tItemSave.nBodyloc < 0x0B)
    {
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
    }

    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004B3C00(!pItem ? -1 : pItem->dwUnitId);
}

void __stdcall sub_004C35F0_ItemToBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x6B0);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x6B7);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    ITEMS_SetBodyLocation(pItem, pItemSave->nBodyloc);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x6BE);

    int nPage = 3;
    if (pItemSave->nBodyloc == 0x0B || pItemSave->nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!sub_004C1C50_PlaceBodyItem(pInventory, pItem, pItemSave->nBodyloc))
    {
        return;
    }

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
    sub_0046F020_FillGfxEntries(pUnit, 0);
    sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1C20_SetWeaponClass(pItem, pItemSave->nBodyloc);
    sub_00470610_Refresh(pUnit, 0);
    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

static void __stdcall sub_004C3980_SwapBodyItem9D(D2ItemSaveStrc* pItemSave, D2GSPacketSrv9D* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x750);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x753);
    D2_ASSERT(sub_006287A0_TestFlags(pItemSave->dwFlags, 1), 0x755);

    sub_0046F950(pUnit);

    D2UnitStrc* pOldItem = sub_00463990(pPacket->nItemId, 4);
    if (pOldItem)
    {
        sub_004C1C90_RemoveBodyItem(pOldItem, pUnit);
    }

    D2UnitStrc* pBodyItem = INVENTORY_GetItemFromBodyLoc(pInventory, pItemSave->nBodyloc);
    if (pBodyItem)
    {
        sub_004C1C90_RemoveBodyItem(pBodyItem, pUnit);
    }

    D2UnitStrc* pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, pItemSave);
    D2_ASSERT(pItem, 0x765);

    ITEMS_SetBodyLocation(pItem, pItemSave->nBodyloc);

    int nPage = 3;
    if (pItemSave->nBodyloc == 0x0B || pItemSave->nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!sub_0063BDB0(pInventory, pItem, pItemSave->nBodyloc))
    {
        return;
    }

    if (pItemSave->nBodyloc != 4 && pItemSave->nBodyloc != 5)
    {
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C1350_RefreshEquippedItems(pUnit);
    }
    else
    {
        INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
        sub_0046F020_FillGfxEntries(pUnit, 0);
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C1C20_SetWeaponClass(pItem, pItemSave->nBodyloc);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

void __fastcall sub_004C3B00(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    sub_004C3980_SwapBodyItem9D(&tItemSave, pPacket);
}

// 0x004C3070
void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    sub_0046F950(pUnit);

    int nOtherLoc;
    switch (tItemSave.nBodyloc)
    {
    case 5:
        nOtherLoc = 4;
        break;

    case 4:
        nOtherLoc = 5;
        break;

    case 0x0C:
        nOtherLoc = 4;
        break;

    case 0x0B:
        nOtherLoc = 5;
        break;

    default:
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
    D2_ASSERT(pItem, 0x5EF);

    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, UNITS_GetItemComponentId(pUnit, pItem));
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, nOtherLoc);

    int bRemoved = 0;
    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (pRemoved && pRemoved == pItem)
    {
        bRemoved = 1;

        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        sub_0063BE30(pInventory, nOtherLoc);
        sub_00470610_Refresh(pUnit, 0);

        if (pUnit == pPlayer)
        {
            sub_00487990_ResetHover();
            if (tItemSave.nBodyloc == 4)
            {
                gwGlobal_007C78A8 = 0;
            }
            else if (tItemSave.nBodyloc == 5)
            {
                gwGlobal_007C78AC = 0;
            }

            sub_004C2540_PlaceItem(pItem, 0, 0, 4, 0, tItemSave.nStorePage);
            ITEMS_SetBodyLocation(pItem, 0);
            INVENTORY_SetCursorItem(pInventory, pItem);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    D2_ASSERT(bRemoved, 0x5F7);

    sub_004C2180_UpdateCursorItem(pItem);

    D2UnitStrc* pNewItem = sub_00463990(pPacket->nItemId, 4);
    if (pNewItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pNewItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pNewItem, 0x618);
        }
        else
        {
            sub_004C2540_PlaceItem(pNewItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        }
    }
    else
    {
        pNewItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
    }

    ITEMS_SetBodyLocation(pNewItem, tItemSave.nBodyloc);

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pNewItem, nPage))
    {
        return;
    }

    if (!sub_004C1C50_PlaceBodyItem(pInventory, pNewItem, tItemSave.nBodyloc))
    {
        return;
    }

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pNewItem);
    sub_0046F020_FillGfxEntries(pUnit, 0);

    switch (pUnit->dwUnitType)
    {
    case 0:
    case 1:
        break;

    default:
        D2_ASSERT(0, 0x641);
        break;
    }

    const unsigned char nComponent = pPacket->nComponent;
    if (nComponent == 0 || nComponent == 1)
    {
        sub_0046F280_ClearGfxBytes(pUnit, nComponent);
    }

    sub_00470610_Refresh(pUnit, 0);
    sub_004C1C20_SetWeaponClass(pNewItem, tItemSave.nBodyloc);
    sub_004C0D20_ApplyItemStats(pUnit, pNewItem, 0);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pNewItem);
}

// build: context sub_004C3380
void __fastcall sub_004C3380(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x65C);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
    if (!pItem)
    {
        return;
    }

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, tItemSave.nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    sub_0063BE30(pInventory, tItemSave.nBodyloc);
    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_00470610_Refresh(pUnit, 0);

    if (pUnit == pPlayer)
    {
        sub_004B2A20(!pItem ? -1 : pItem->dwUnitId);
        sub_00487990_ResetHover();
        if (tItemSave.nBodyloc == 4)
        {
            gwGlobal_007C78A8 = 0;
        }
        else if (tItemSave.nBodyloc == 5)
        {
            gwGlobal_007C78AC = 0;
        }

        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
        {
            if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
            {
                sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
                pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
                D2_ASSERT(pItem, 0x67E);
            }
            else
            {
                sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
            }

            ITEMS_SetBodyLocation(pItem, 0);
            INVENTORY_SetCursorItem(pInventory, pItem);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
            sub_004C1350_RefreshEquippedItems(pUnit);
            sub_004C1350_RefreshEquippedItems(pUnit);
            if (pItem)
            {
                sub_004C2180_UpdateCursorItem(pItem);
            }

            if (pItem && ITEMS_CheckItemFlag(pItem, 0x4000, 0x69C, ".\\UNIT\\Item.cpp"))
            {
                ITEMS_SetItemFlag(pItem, 0x4000, 0);
            }
        }
        else
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        }
    }
    else if (sub_00463990(pPacket->nItemId, 4))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    }
}

void __fastcall sub_004C4740(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, 0, sub_0044DCC0());
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xAA7);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
    D2_ASSERT(pItem, 0xAA9);

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, tItemSave.nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0xAAF);
    D2_ASSERT(pRemoved == pItem, 0xAB0);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    sub_004C2180_UpdateCursorItem(pRemoved);
    sub_0063BE30(pInventory, tItemSave.nBodyloc);
    sub_00470610_Refresh(pUnit, 0);

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pItem, 0xABD);
        }
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }

    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    sub_00487990_ResetHover();
    if (tItemSave.nBodyloc == 4)
    {
        gwGlobal_007C78A8 = 0;
    }
    else if (tItemSave.nBodyloc == 5)
    {
        gwGlobal_007C78AC = 0;
    }

    if (sub_0063BCC0_PlaceItem(pInventory, pItem, tItemSave.nX, tItemSave.nY, nRecordId, 1, 0))
    {
        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
        {
            return;
        }

        ITEMS_SetBodyLocation(pItem, 0);
        INVENTORY_SetCursorItem(pInventory, NULL);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C2180_UpdateCursorItem(pItem);
    }
    else
    {
        D2_ASSERT(0, 0xADF);
    }
}

void __fastcall sub_004C4AA0(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xB77);

    D2UnitStrc* pItem = NULL;
    if (pUnit == pPlayer)
    {
        pItem = sub_00463990(pPacket->nItemId, 4);
        if (!pItem)
        {
            return;
        }

        D2_ASSERT(pItem == INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xB83);

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, 0, sub_0044DCC0());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xB85, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, 0);
        sub_00487990_ResetHover();
        sub_00453B00_SendMouseMove();
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(pItem, 0xB8D);
    }
    else if (!pItem)
    {
        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(pItem, 0xB93);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }

    ITEMS_SetBodyLocation(pItem, tItemSave.nBodyloc);

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!sub_004C1C50_PlaceBodyItem(pInventory, pItem, tItemSave.nBodyloc))
    {
        return;
    }

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
    sub_00470610_Refresh(pUnit, 0);
    sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C2180_UpdateCursorItem(pItem);
}

D2UnitStrc* __fastcall sub_004C4C70(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return NULL;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return NULL;
    }

    D2UnitStrc* pItem = NULL;
    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return NULL;
    }

    const unsigned char nMode = tItemSave.bMode;
    if (pUnit == pPlayer && nMode == 0)
    {
        pItem = sub_00463990(pPacket->nItemId, 4);
        if (pItem)
        {
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved == pItem, 0xBF5);

            if (pUnit->dwUnitType == UNIT_PLAYER)
            {
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
            }

            if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
            {
                STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
            }

            sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
        }

        sub_00487990_ResetHover();
        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, tItemSave.nStorePage, sub_0044DCC0());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xBFC, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, tItemSave.nStorePage);
        if (tItemSave.nStorePage == 0xFF)
        {
            return NULL;
        }

        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        sub_004C2970_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pUnit, pItem, tItemSave.nX);
        if (ITEMS_IsCharmUsable(pItem, pUnit))
        {
            sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        }

        sub_00453B00_SendMouseMove();
    }
    else if (nMode == 1)
    {
        D2UnitStrc* pBodyItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
        sub_0046F950(pUnit);
        if (!pBodyItem)
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pBodyItem);
        sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
        INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pBodyItem, tItemSave.nBodyloc);

        D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pBodyItem);
        D2_ASSERT(pRemoved == pBodyItem, 0xC1E);

        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
        sub_0063BE30(pInventory, tItemSave.nBodyloc);
        sub_00470610_Refresh(pUnit, 0);
        sub_00465EE0_RemoveClientSideUnit(!pBodyItem ? -1 : pBodyItem->dwUnitId, !pBodyItem ? 6 : pBodyItem->dwUnitType);
        pBodyItem = NULL;

        if (pUnit == pPlayer)
        {
            sub_00487990_ResetHover();
            if (tItemSave.nBodyloc == 4)
            {
                gwGlobal_007C78A8 = 0;
            }
            else if (tItemSave.nBodyloc == 5)
            {
                gwGlobal_007C78AC = 0;
            }
        }

        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        ITEMS_SetBodyLocation(pItem, tItemSave.nBodyloc);

        int nPage = 3;
        if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
        {
            nPage = 4;
        }

        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
        {
            return NULL;
        }

        if (!sub_004C1C50_PlaceBodyItem(pInventory, pItem, tItemSave.nBodyloc))
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
        sub_0046F020_FillGfxEntries(pUnit, 0);

        const unsigned char nComponent = pPacket->nComponent;
        if (nComponent == 0 || nComponent == 1)
        {
            sub_0046F280_ClearGfxBytes(pUnit, nComponent);
        }

        sub_00470610_Refresh(pUnit, 0);
        if (pUnit == pPlayer)
        {
            sub_004C1C20_SetWeaponClass(pItem, tItemSave.nBodyloc);
            if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
            {
                INVENTORY_SetCursorItem(pInventory, NULL);
                sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
            }
        }

        sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_004C1350_RefreshEquippedItems(pUnit);
        sub_00453B00_SendMouseMove();
    }
    else if (pUnit == pPlayer)
    {
        if (nMode == 2)
        {
            pItem = sub_00463990(pPacket->nItemId, 4);
            if (pItem)
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem) == pItem, 0xC5E);
                sub_0063C550_Return(pInventory, CLIENTS_GetUnitX(pItem));
                sub_00498D50(CLIENTS_GetUnitX(pItem), 0);
                if (pUnit->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pUnit, pItem);
                }

                sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }

            sub_00498D60();
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(tItemSave.bMode == 2, 0xC69);

            UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
            UNITS_SetYForStaticUnit(pItem, tItemSave.nY);
            if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
            {
                if (!INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem)))
                {
                    sub_00477EE0();
                    sub_0044B880_SetValue(0);
                    sub_0044C860_SetValue(1);
                    sub_0044D520();
                }

                if (ITEMS_IsCharmUsable(pItem, pUnit))
                {
                    sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
                }

                sub_00498D50(CLIENTS_GetUnitX(pItem), 1);
                sub_00453B00_SendMouseMove();
                if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x400))
                {
                    sub_00470390(pItem, 0x46, 2, 0, 0, 0, 0, 0);
                }
            }
            else
            {
                D2_ASSERT(0, 0xC89);
            }
        }
        else if (nMode == 4)
        {
            sub_00498D60();
            D2UnitStrc* pOldItem = sub_00463990(pPacket->nItemId, 4);
            if (pOldItem)
            {
                sub_00465EE0_RemoveClientSideUnit(!pOldItem ? -1 : pOldItem->dwUnitId, !pOldItem ? 6 : pOldItem->dwUnitType);
            }

            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
            UNITS_SetYForStaticUnit(pItem, tItemSave.nY);
            INVENTORY_SetCursorItem(pInventory, pItem);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
            sub_00453B00_SendMouseMove();
        }
    }

    if (pItem)
    {
        sub_004C2180_UpdateCursorItem(pItem);
    }

    return pItem;
}


static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static __forceinline void ITEM_RemoveItemStats(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
}

static __forceinline void ITEM_ReattachItem(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
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
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
}


// 0x004C3380
void __fastcall sub_004C3380_RemoveBodyItem9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int bToCursor = 0;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    pInventory = pUnit->pInventory;
    D2_ASSERT(pUnit->pInventory, 0x65C);

    D2UnitStrc* hItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
    if (!hItem)
    {
        return;
    }

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hItem);
    sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hItem, tItemSave.nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, hItem);
    sub_0063BE30(pInventory, tItemSave.nBodyloc);
    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_00470610_Refresh(pUnit, 0);

    if (pUnit == pPlayer)
    {
        sub_004B2A20(!hItem ? -1 : hItem->dwUnitId);
        sub_00487990_ResetHover();
        if (tItemSave.nBodyloc == 4)
        {
            gwGlobal_007C78A8 = 0;
        }
        else if (tItemSave.nBodyloc == 5)
        {
            gwGlobal_007C78AC = 0;
        }

        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
        {
            if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
            {
                sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
                hItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
                D2_ASSERT(hItem, 0x67E);
            }
            else
            {
                sub_004C2540_PlaceItem(hItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
            }

            ITEMS_SetBodyLocation(hItem, 0);
            INVENTORY_SetCursorItem(pInventory, hItem);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
            sub_004C1350_RefreshEquippedItems(pUnit);
            sub_004C1350_RefreshEquippedItems(pUnit);
            bToCursor = 1;
        }
        else
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        }
    }
    else if (sub_00463990(pPacket->nItemId, 4))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    if (bToCursor && hItem)
    {
        sub_004C2180_UpdateCursorItem(hItem);
        if (ITEMS_CheckItemFlag(hItem, 0x4000, 0x69C, ".\\UNIT\\Item.cpp"))
        {
            ITEMS_SetItemFlag(hItem, 0x4000, 0);
        }
    }
}

// build: context ?ITEMPKT_GetUnitX@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEMPKT_GetUnitY@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEMPKT_UnitFlag9@@YAHPAUD2UnitStrc@@@Z
// build: context ?sub_0044BE50@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEM_RemoveItemStats@@YAXPAUD2UnitStrc@@0@Z
// build: context ?ITEM_ReattachItem@@YAXHHPAUD2UnitStrc@@0@Z
// build: context ?sub_004C3070@@YIXPAUD2GSPacketSrv9D@@@Z
