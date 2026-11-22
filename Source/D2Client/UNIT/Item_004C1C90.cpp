#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2TxtItems.h"
#include "D2Path.h"

#include "D2ItemsWorld.h"
struct D2SkillStrc;

struct D2UnitStrc;

struct D2GameStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

short gwGlobal_007C78A8;                                                                                    // 0x007C78A8

short gwGlobal_007C78AC;                                                                                    // 0x007C78AC

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4);          // 0x004B9A00

void __fastcall sub_004B9B50_SetValue(int nKey, int nValue);                                            // 0x004B9B50

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame);  // 0x00626D40

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0

int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0

int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GemsTxt;

struct D2StaticPathStrc;

struct D2ItemSaveStrc;

struct D2GSPacketSrv9C;

struct D2GSPacketSrv9D;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

int __cdecl sub_0044DCC0(); // 0x0044DCC0

void __cdecl sub_00453B00_SendMouseMove(); // 0x00453B00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

void __cdecl sub_00487990_ResetHover(); // 0x00487990

void __fastcall sub_004B2A00(int nUnitId); // 0x004B2A00

void __fastcall sub_004B2A40(int nUnitId); // 0x004B2A40

void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem); // 0x004C2180

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __fastcall sub_004B2640(D2UnitStrc* pUnit); // 0x004B2640

void __fastcall sub_004B2A80_ResetHoverForItem(int nUnitId); // 0x004B2A80

int __cdecl sub_004B2E20_IsQuestActive(); // 0x004B2E20

int __fastcall sub_004B3230_GetTickPair(int* pLow); // 0x004B3230

void __fastcall sub_00498D50(int nX, int nArg); // 0x00498D50

void __cdecl sub_00498D60(); // 0x00498D60

void __fastcall sub_004B2A60(int nUnitId); // 0x004B2A60

void __fastcall sub_0048A540_QuestCodeUpdate(int nCode); // 0x0048A540

void __fastcall sub_0046F950(D2UnitStrc* pUnit); // 0x0046F950

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

void __stdcall sub_004C35F0_ItemToBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C35F0

void __stdcall sub_004C2970_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX);

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

static D2UnitStrc* __stdcall sub_004C0F20_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9CStrc* pPacket, D2ItemSaveStrc* pItemSave);

static D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9DStrc* pPacket, D2ItemSaveStrc* pItemSave);

static void sub_004C1160_SaveSkillState(D2SkillStateStrc* pState, D2UnitStrc* pUnit);

static void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem);

static int sub_004C16D0_GetItemDropSound(D2UnitStrc* pItem, int* pDelay);

static void sub_004C18B0_PlayDropSound(D2UnitStrc* pItem);

static void sub_004C1C20_SetWeaponClass(D2UnitStrc* pItem, unsigned char nType);

struct D2MonCommandStrc;

struct D2UnitTargetStrc;

#pragma pack(push, 1)

#pragma pack(pop)

void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue);                        // 0x0046F020

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60

void __fastcall sub_004B2A20(int nUnitId);                                                                  // 0x004B2A20

void __fastcall sub_004B3C00(int nUnitId);                                                                  // 0x004B3C00

int __fastcall ITEMMODE_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem);                               // 0x004C10E0

int __fastcall sub_004C1C50_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);    // 0x004C1C50

unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00623D60

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020

void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880

void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860

void __cdecl sub_0044D520();                                                                                // 0x0044D520

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

#pragma pack(push, 1)

#pragma pack(pop)

static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit);

void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket);

static void __stdcall sub_004C2540_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage);

extern "C" const char szItemCppFile[];

D2UnitStrc* __fastcall sub_004661C0_CreateItem(int nUnitId, int nClassId, int nX, int nY, int nArg, int nValue);

void __fastcall sub_0046F280(D2UnitStrc* pUnit, int nComponent);

void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue);

int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);

static void sub_004C1200_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState);

#pragma pack(push, 1)

#pragma pack(pop)

static void __stdcall sub_004C1C90_RemoveBodyItem(D2UnitStrc* pItem, D2UnitStrc* pUnit);

void __fastcall sub_004C2810(D2GSPacketSrv9C* pPacket);

void __fastcall sub_004C2E90(D2GSPacketSrv9D* pPacket);

static void __stdcall sub_004C3980_SwapBodyItem9D(D2ItemSaveStrc* pItemSave, D2GSPacketSrv9D* pPacket);

void __fastcall sub_004C3B00(D2GSPacketSrv9D* pPacket);

void __fastcall sub_004C4740(D2GSPacketSrv9D* pPacket);

void __fastcall sub_004C4AA0(D2GSPacketSrv9D* pPacket);

D2UnitStrc* __fastcall sub_004C4C70(D2GSPacketSrv9D* pPacket);

// 0x004C0F20
static D2UnitStrc* __stdcall sub_004C0F20_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9CStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 8;
    if (!pItemSave)
    {
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pData, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->dwUnitId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pData, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->dwUnitId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xD8, ".\\UNIT\\Item.cpp"))
            sub_00478680_SendPacket5(0x37, pPacket->dwUnitId);
    }
    return pItem;
}

// 0x004C0FF0
static D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9DStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 0x0D;
    if (!pItemSave)
    {
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pData, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->dwUnitId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pData, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->dwUnitId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xFE, ".\\UNIT\\Item.cpp"))
            sub_00478680_SendPacket5(0x37, pPacket->dwUnitId);
    }
    return pItem;
}

// 0x004C1160
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

// 0x004C1200
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

// 0x004C1290
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

static inline D2UniqueItemsTxt* ITEM_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    return 0;
}

static inline D2SetItemsTxt* ITEM_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nIndex];
    return 0;
}

// 0x004C16D0
static int sub_004C16D0_GetItemDropSound(D2UnitStrc* pItem, int* pDelay)
{
    int nSound = 0;
    if (pDelay)
        *pDelay = 0x0C;

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > nSound)
    {
        if (pDelay && pItemsTxt->nDropSfxFrame > 0)
            *pDelay = pItemsTxt->nDropSfxFrame;
        nSound = pItemsTxt->wDropSound;
    }

    if (ITEMS_GetItemQuality(pItem) == 7)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEM_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
            {
                if (pDelay && pUniqueItemsTxt->nDropSfxFrame > 0)
                    *pDelay = pUniqueItemsTxt->nDropSfxFrame;
                nSound = pUniqueItemsTxt->wDropSound;
            }
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEM_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
        {
            if (pDelay && pSetItemsTxt->nDropSfxFrame > 0)
                *pDelay = pSetItemsTxt->nDropSfxFrame;
            nSound = pSetItemsTxt->wDropSound;
        }
    }
    return nSound;
}

// 0x004C18B0
static void sub_004C18B0_PlayDropSound(D2UnitStrc* pItem)
{
    int nDelay = 0x0C;
    const int nSound = sub_004C16D0_GetItemDropSound(pItem, &nDelay);
    sub_004B9A00(0xD8, pItem, 0, 0, 0);
    if (nSound > 0)
    {
        const int nHandle = sub_004B9A00(nSound, pItem, nDelay, 0, 0);
        if (nHandle)
            sub_004B9B50_SetValue(nHandle, 0xB4);
    }
}

// 0x004C1910
void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bInit)
{
    if (nMode >= 7)
        return;

    const int nCurrentMode = pItem->dwAnimMode;
    if ((nCurrentMode == 5 || nCurrentMode == 3) && nMode != 5 && nMode != 3)
        UNITS_FreeCollisionPath(pItem);

    pItem->dwAnimMode = nMode;
    UNITROOM_UpdatePath(pItem);
    switch (pItem->dwAnimMode)
    {
    case 5:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags &= ~2;
        UNITS_SetAnimStartFrame(pItem);
        sub_004C18B0_PlayDropSound(pItem);
        break;

    case 3:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags |= 2;
        UNITS_SetAnimStartFrame(pItem);
        break;

    case 4:
        sub_004B9A00(0xEB, 0, 0, 0, 0);
    case 0:
    case 1:
    case 2:
    case 6:
        pItem->dwFlags &= ~2;
        break;

    default:
        return;
    }

    pItem->dwFlags &= ~4;
    pItem->dwFlags &= ~0x08;
    pItem->dwFlags |= 0x20;
    if (!bInit)
        return;

    ITEMS_SetItemFlag(pItem, 0x10, 1);
    STATLIST_AllocStatListEx(pItem, 0, 0, 0);
    unsigned int nId = pItem->dwUnitId;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 0x40, 0, 4, nId);
    D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
    if (ITEMS_CheckIfSocketable(pItem) && !pItem->pInventory)
        INVENTORY_AllocInventory(0, pItem);
}

// 0x004C1C20
static void sub_004C1C20_SetWeaponClass(D2UnitStrc* pItem, unsigned char nType)
{
    const int nWeaponClass = ITEMS_GetWeaponClassId(pItem);
    if (nType == 4)
        gwGlobal_007C78A8 = nWeaponClass;
    else if (nType == 5)
        gwGlobal_007C78AC = nWeaponClass;
}

// 0x004C1C90
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

// build: context sub_E08_Emit_ItemCreate
// calling-convention shim (not game code)
D2UnitStrc* __fastcall sub_E08_Emit_ItemCreate(D2ItemPacket9CStrc* pPacket, D2ItemPacket9DStrc* pOwned, unsigned short nX, unsigned short nY, D2ItemSaveStrc* pSave)
{
    D2UnitStrc* pItem = sub_004C0F20_CreateWorldItem(nX, nY, 0, pPacket, 0);
    if (!pItem)
        pItem = sub_004C0FF0_CreateOwnedItem(nX, nY, 0, pOwned, pSave);
    sub_004C1C20_SetWeaponClass(pItem, pOwned->nAction);
    return pItem;
}

void __fastcall sub_E08_Emit_SkillState(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2SkillStateStrc tState;
    sub_004C1160_SaveSkillState(&tState, pUnit);
    sub_004C1290_AttachItem(pItem->dwClassId, pUnit, pItem);
    sub_004C1200_RestoreSkillState(pUnit, &tState);
}

static inline int ITEMPKT_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int ITEMPKT_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline unsigned int ITEMPKT_GetItemCode(D2UnitStrc* pItem)
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
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, nSize, 0, &tItemSave);
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
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, nSize, 0, &tItemSave);
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

// 0x004C20B0
void __fastcall sub_004C20B0_ItemToCursor9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0xB0C);

    if (sub_00463990(pPacket->nItemId, 4))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    D2UnitStrc* pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0xB13);

    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x004C2340
void __fastcall sub_004C2340_ItemToCursor9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    D2UnitStrc* pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0xD35);

    STATLIST_SetUnitStat(pItem, 0x46, 1, 0);
    D2InventoryStrc* pInventory = pUnit->pInventory;
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x004C2540
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

// 0x004C25B0
void __fastcall sub_004C25B0_ItemDropToGround9C(D2ItemPacket9CStrc* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pData, pPacket->nSize - 8, 0, &tItemSave);

    D2UnitStrc* pItem = sub_004C0F20_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0x384);

    sub_004C2180_UpdateCursorItem(pItem);
    if (pItem->dwAnimMode == 3 && ITEMS_CheckItemFlag(pItem, 0x2000, 0x388, ".\\UNIT\\Item.cpp"))
    {
        UNITS_ChangeAnimMode(pItem, 5);
        sub_004C18B0_PlayDropSound(pItem);
    }
}

// 0x004C2650
void __fastcall sub_004C2650_ItemOnCursor9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (tItemSave.bMode == 4)
    {
        D2_ASSERT(!sub_00463990(pPacket->nItemId, 4), 0x3A0);

        D2UnitStrc* pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(pItem, 0x3A2);

        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
}

// 0x004C26F0
void __fastcall sub_004C26F0_ItemDropped9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
        if (pCursorItem && pCursorItem == pItem)
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }

        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
        }
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    }

    D2_ASSERT(pItem, 0x3CF);
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, 5, 1, tItemSave.nStorePage);
}

// 0x004C2810
void __fastcall sub_004C2810(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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

// 0x004C2970
static void __stdcall sub_004C2970_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX)
{
    UNITS_SetXForStaticUnit(pItem, nX);
    UNITS_SetYForStaticUnit(pItem, nY);

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0x413);

    if (!INVENTORY_PlaceItemInSocket(hInventory, pItem, 1))
    {
        return;
    }

    if (!sub_0063BCC0_PlaceItem(hInventory, pItem, ITEMPKT_GetUnitX(pItem), ITEMPKT_GetUnitY(pItem), UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0()), 1, nPage))
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
            INVENTORY_SetCursorItem(hInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage == 3)
    {
        const int nClassId = pItem->dwClassId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        if (pItemsTxtRecord->dwCode == 0x20747368 || pItemsTxtRecord->dwCode == 0x20326671)
        {
            sub_0048A540_QuestCodeUpdate(pItemsTxtRecord->dwCode);
        }
    }
}

// 0x004C2E90
void __fastcall sub_004C2E90(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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
    case UNIT_PLAYER:
    case UNIT_MONSTER:
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

static inline int ITEMPKT_UnitFlag9(D2UnitStrc* pUnit)
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
            && !STATLIST_GetOwner(pItem, NULL) && ITEMMODE_CheckEquipRequirements(pUnit, pItem))
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

        if (ITEMMODE_CheckEquipRequirements(pUnit, pItem))
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

            if (!ITEMMODE_CheckEquipRequirements(pUnit, pItem))
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

// 0x004C3070
void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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
    case UNIT_PLAYER:
    case UNIT_MONSTER:
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
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
}

// 0x004C3380
void __fastcall sub_004C3380_RemoveBodyItem9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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

// 0x004C35F0
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

// 0x004C3980
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

// 0x004C3B00
void __fastcall sub_004C3B00(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    sub_004C3980_SwapBodyItem9D(&tItemSave, pPacket);
}

static void __stdcall sub_004C3760_ItemFromBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x6ED);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x6EF);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, pItemSave->nBodyloc);
    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, pItemSave->nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x6F7);
    D2_ASSERT(pRemoved == pItem, 0x6F8);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    sub_0063BE30(pInventory, pItemSave->nBodyloc);

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, pItemSave);
            D2_ASSERT(pItem, 0x703);
        }
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        sub_00487990_ResetHover();
        ITEMS_SetBodyLocation(pItem, 0);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
}

void __fastcall sub_004C3920_BodyPacket9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x40))
    {
        sub_004C35F0_ItemToBody9D(pPacket, &tItemSave);
        return;
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x80))
    {
        sub_004C3760_ItemFromBody9D(pPacket, &tItemSave);
    }
}

void __fastcall sub_004C2AD0_ItemToStorage9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            if (INVENTORY_RemoveItemFromInventory(pPlayer->pInventory, pItem))
            {
                const unsigned char nPage = ITEMS_GetInvPage(pItem);
                const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
                INVENTORY_Return(".\\UNIT\\Item.cpp", 0x456, pPlayer->pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nRecordId, 1, nPage);
                sub_00487990_ResetHover();
                if (pPlayer->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pPlayer, pItem);
                }
            }

            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
            ITEMS_SetItemFlag(pItem, -1, 0);
            ITEMS_SetItemFlag(pItem, tItemSave.dwFlags, 1);
        }
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 1, pPacket, &tItemSave);
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    sub_004C2970_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pPlayer, pItem, tItemSave.nX);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004B2A40(!pItem ? -1 : pItem->dwUnitId);
}

void __fastcall sub_004C2C80_ItemFromStorage9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
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

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x4B7);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        if (tItemSave.nStorePage == 2)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x4CB);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x4CF, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
    sub_00487990_ResetHover();
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pItem, 0x4DD);
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
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            if (tItemSave.nStorePage == 1)
            {
                sub_004B9A00(1, NULL, 0, 0, 0);
            }
            else
            {
                sub_00468070_SetCursorItemState(NULL);
            }
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        sub_004B2A00(pItem->dwUnitId);
    }
}

void __fastcall sub_004C3C00_ItemToMerc9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    int nUnitId;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!sub_004B3230_GetTickPair(&nUnitId))
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pPacket->nAction == 0x0C)
    {
        if (!pItem)
        {
            return;
        }

        if (sub_004B2E20_IsQuestActive())
        {
            sub_00487990_ResetHover();
        }

        if (!INVENTORY_RemoveItemFromInventory(pInventory, pItem))
        {
            return;
        }

        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        if (nPage == 0xFF)
        {
            return;
        }

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0x81B, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
        sub_00453B00_SendMouseMove();
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        sub_004B2A80_ResetHoverForItem(pPacket->nItemId);
        return;
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!pItem)
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
        ITEMS_SetInvPage(pItem, tItemSave.nStorePage);
    }
    else
    {
        INVENTORY_CompareWithItemsParentInventory(pInventory, pItem);
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }

            if (tItemSave.nStorePage != ITEMS_GetInvPage(pItem))
            {
                return;
            }
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, 0, 0, 0, 0, tItemSave.nStorePage);
        }
    }

    ITEMS_SetInvPage(pItem, tItemSave.nStorePage);

    int nX;
    int nY;
    if (!sub_0063B9D0_PlaceItemAt(pInventory, pItem, tItemSave.nX, tItemSave.nY, UNITS_GetInventoryRecordId(pUnit, tItemSave.nStorePage, sub_0044DCC0()), &nX, &nY, tItemSave.nStorePage))
    {
        return;
    }

    sub_004C2970_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pUnit, pItem, tItemSave.nX);
    sub_004B2640(pUnit);
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C3E00
static void sub_004C3E00_CursorItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x86C);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x874);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x87C);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        return;
    }

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (pItemSave->nStorePage == 0xFF)
    {
        return;
    }

    D2_ASSERT(sub_0063BCC0_PlaceItem(pInventory, pItem, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0()), 1, nPage), 0x892);

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C3F60
static void __stdcall sub_004C3F60_BeltItemToCursor(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x8A6);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8AB);

    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x8B0);
    D2_ASSERT(pRemoved == pItem, 0x8B1);

    const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x8B4, pInventory, pItemSave->nX, pItemSave->nY, nRecordId, 1, nPage);
    sub_00487990_ResetHover();
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x8BB);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C40D0
void __fastcall sub_004C40D0_BeltPacket2_9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 0)
    {
        sub_004C3F60_BeltItemToCursor(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        sub_004C3E00_CursorItemToBelt(pPacket, &tItemSave);
    }
}

// 0x004C4130
void __fastcall sub_004C4130_ItemToBelt9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x8EF);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 1, pPacket, &tItemSave);
    }

    UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
    UNITS_SetYForStaticUnit(pItem, tItemSave.nY);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8FF);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem));
    }

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    if (tItemSave.dwFlags & 0x400)
    {
        ITEMS_SetItemFlag(pItem, 0x400, 1);
    }

    INVENTORY_SetCursorItem(pInventory, NULL);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_00498D50(ITEMPKT_GetUnitX(pItem), 1);
    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004B2A60(pItem->dwUnitId);
}

// 0x004C42A0
void __fastcall sub_004C42A0_ItemFromBelt9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x92C);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x931);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x93A);

    sub_0063C550_Return(pInventory, tItemSave.nX);
    sub_00498D60();
    sub_00498D50(tItemSave.nX, 0);
    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
    else
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        sub_00468070_SetCursorItemState(NULL);
    }
}

// 0x004C43E0
static void __stdcall sub_004C43E0_ItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x957);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x963);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (ITEMSIsA(pItem, 0x0D))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        D2_ASSERT(INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem)), 0x970);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C44D0
void __stdcall sub_004C44D0_ItemFromBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x98D);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x98F);
    D2_ASSERT(pRemoved == pItem, 0x990);

    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    sub_0063C550_Return(pInventory, pItemSave->nX);
    sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C45C0
void __fastcall sub_004C45C0_BeltPacket9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 2)
    {
        sub_004C44D0_ItemFromBelt(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        sub_004C43E0_ItemToBelt(pPacket, &tItemSave);
    }
}

// 0x004C4740
void __fastcall sub_004C4740(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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

// 0x004C4990
void __fastcall sub_004C4990_ItemToSocket9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xB34);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
        {
            D2InventoryStrc* pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            D2_ASSERT(pPlayerInventory, 0xB3A);
            INVENTORY_SetCursorItem(pPlayerInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
        }

        sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
    }

    sub_004C2180_UpdateCursorItem(pItem);
}

// build: context ?ITEMPKT_GetUnitX@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEMPKT_GetUnitY@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEMPKT_UnitFlag9@@YAHPAUD2UnitStrc@@@Z
// build: context ?sub_0044BE50@@YAHPAUD2UnitStrc@@@Z
// build: context ?ITEM_RemoveItemStats@@YAXPAUD2UnitStrc@@0@Z
// build: context ?ITEM_ReattachItem@@YAXHHPAUD2UnitStrc@@0@Z
// build: context ?sub_004C3070@@YIXPAUD2GSPacketSrv9D@@@Z

// 0x004C4AA0
void __fastcall sub_004C4AA0(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0xB77);

    D2UnitStrc* hGridItem = NULL;
    if (pUnit == pPlayer)
    {
        hGridItem = sub_00463990(pPacket->nItemId, 4);
        if (!hGridItem)
        {
            return;
        }

        D2_ASSERT(hGridItem == INVENTORY_RemoveItemFromInventory(hInventory, hGridItem), 0xB83);

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, 0, sub_0044DCC0());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xB85, hInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, 0);
        sub_00487990_ResetHover();
        sub_00453B00_SendMouseMove();
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        hGridItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(hGridItem, 0xB8D);
    }
    else if (!hGridItem)
    {
        hGridItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(hGridItem, 0xB93);
    }
    else
    {
        sub_004C2540_PlaceItem(hGridItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }

    ITEMS_SetBodyLocation(hGridItem, tItemSave.nBodyloc);

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(hInventory, hGridItem, nPage))
    {
        return;
    }

    if (!sub_004C1C50_PlaceBodyItem(hInventory, hGridItem, tItemSave.nBodyloc))
    {
        return;
    }

    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnInsert(hInventory, hGridItem);
    sub_00470610_Refresh(pUnit, 0);
    sub_004C0D20_ApplyItemStats(pUnit, hGridItem, 0);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C1350_RefreshEquippedItems(pUnit);
    sub_004C2180_UpdateCursorItem(hGridItem);
}

// 0x004C4C70
D2UnitStrc* __fastcall sub_004C4C70(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return NULL;
    }

    D2InventoryStrc* hInventory = pUnit->pInventory;
    if (!hInventory)
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
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(hInventory, pItem);
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
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xBFC, hInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, tItemSave.nStorePage);
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
        D2UnitStrc* pBodyItem = INVENTORY_GetItemFromBodyLoc(hInventory, tItemSave.nBodyloc);
        sub_0046F950(pUnit);
        if (!pBodyItem)
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnRemoval(hInventory, pBodyItem);
        sub_0046F280_ClearGfxBytes(pUnit, pPacket->nComponent);
        INVENTORY_GetSecondWieldingWeapon(pUnit, hInventory, &pBodyItem, tItemSave.nBodyloc);

        D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(hInventory, pBodyItem);
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
        sub_0063BE30(hInventory, tItemSave.nBodyloc);
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

        if (!INVENTORY_PlaceItemInSocket(hInventory, pItem, nPage))
        {
            return NULL;
        }

        if (!sub_004C1C50_PlaceBodyItem(hInventory, pItem, tItemSave.nBodyloc))
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnInsert(hInventory, pItem);
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
                INVENTORY_SetCursorItem(hInventory, NULL);
                sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
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
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(hInventory, pItem) == pItem, 0xC5E);
                sub_0063C550_Return(hInventory, CLIENTS_GetUnitX(pItem));
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
            if (INVENTORY_PlaceItemInSocket(hInventory, pItem, 2))
            {
                if (!INVENTORY_PlaceItemInBeltSlot(hInventory, pItem, CLIENTS_GetUnitX(pItem)))
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
            INVENTORY_SetCursorItem(hInventory, pItem);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
            sub_00453B00_SendMouseMove();
        }
    }

    if (pItem)
    {
        sub_004C2180_UpdateCursorItem(pItem);
    }

    return pItem;
}
