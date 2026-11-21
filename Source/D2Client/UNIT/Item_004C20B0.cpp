#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2GameRecords.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2LevelTxt.h"

struct D2UnitStrc;

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

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __cdecl sub_00487990_ResetHover(); // 0x00487990

void __fastcall sub_004B2A00(int nUnitId); // 0x004B2A00

void __fastcall sub_004B2A40(int nUnitId); // 0x004B2A40

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem); // 0x004C2180

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

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

void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

void __stdcall sub_004C35F0_ItemToBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C35F0

static void __stdcall sub_004C2970_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX);

struct D2SkillStrc;

struct D2GameStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

extern short gwGlobal_007C78A8;                                                                             // 0x007C78A8

extern short gwGlobal_007C78AC;                                                                             // 0x007C78AC

D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

void __fastcall sub_004B9B50_SetValue(int nKey, int nValue);                                            // 0x004B9B50

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame);  // 0x00626D40

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450

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

// 0x004C20B0
void __fastcall sub_004C20B0_ItemToCursor9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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

static __declspec(noinline) D2UnitStrc* __stdcall sub_004C0F20_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9CStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 8;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pData, nSize, 0, &tItemSave);
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

static __declspec(noinline) D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9DStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 0x0D;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pData, nSize, 0, &tItemSave);
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

static __forceinline D2UniqueItemsTxt* ITEM_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    return 0;
}

static __forceinline D2SetItemsTxt* ITEM_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nIndex];
    return 0;
}

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

static __declspec(noinline) void sub_004C18B0_PlayDropSound(D2UnitStrc* pItem)
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
        sub_00624390_AnimInit(pItem);
        sub_004C18B0_PlayDropSound(pItem);
        break;

    case 3:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags |= 2;
        sub_00624390_AnimInit(pItem);
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
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 0x40, 0, 4, pItem->dwUnitId);
    D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
    if (ITEMS_CheckIfSocketable(pItem) && !pItem->pInventory)
        INVENTORY_AllocInventory(0, pItem);
}

static __declspec(noinline) void sub_004C1C20_SetWeaponClass(D2UnitStrc* pItem, unsigned char nType)
{
    const int nWeaponClass = ITEMS_GetWeaponClassId(pItem);
    if (nType == 4)
        gwGlobal_007C78A8 = nWeaponClass;
    else if (nType == 5)
        gwGlobal_007C78AC = nWeaponClass;
}

// 0x004C25B0
void __fastcall sub_004C25B0_ItemDropToGround9C(D2ItemPacket9CStrc* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pData, pPacket->nSize - 8, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

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

// 0x004C4990
void __fastcall sub_004C4990_ItemToSocket9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

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
