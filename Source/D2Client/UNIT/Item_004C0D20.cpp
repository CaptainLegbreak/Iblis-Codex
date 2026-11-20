#include "D2Client.h"
#include "D2Structs.h"

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


struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x6C];
    int dwGemOffset;
};

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall sub_00629A40(D2UnitStrc* pItem); // 0x00629A40
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
D2UnitStrc* __stdcall sub_0063BEF0_GetLeftWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nArg2, int nArg5); // 0x0065FEC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0
static __declspec(noinline) void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce);

struct D2DataTablesStrc
{
    char unk0x000[0xC6C];
    int nStuff;
    int nShiftedStuff;
};

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
    unsigned int nItemId;
    unsigned char nUnitType;
    unsigned int nUnitId;
    unsigned char pBitstream[0xF4];
};

#pragma pack(pop)
struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};

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

static __forceinline int GetUnitType(D2UnitStrc* p)
{
    if (p)
    {
        return p->dwUnitType;
    }
    return 6;
}

static __forceinline D2InventoryStrc* GetInventory(D2UnitStrc* p)
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

    if (ITEMS_CheckItemTypeId(pItem, 0x14))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x32);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x34);
        sub_0065FEC0_ItemApplyProps(2, NULL, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x4A))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x3C);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x3E);
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

    if (GetUnitType(pUnit) == 0)
    {
        D2UnitStrc* pLeftHand = sub_0063BEF0_GetLeftWeapon(GetInventory(pUnit));
        if (UNITS_CanDualWield(pUnit))
        {
            int bType = 1;
            if (pLeftHand && pItem != pLeftHand && ITEMS_CheckItemTypeId(pItem, 0x2D))
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
        int nValue = STATLIST_GetStatValue(pStatList, 204, nLayer);
        if (nValue)
        {
            nValue >>= 8;
            if (nValue > 0 && nValue <= 255)
            {
                nCharges = D2_MIN(D2_MAX(nCharges, 0), nValue);
                STATLIST_SetBaseStat2(pStatList, 204, (nValue << 8) + (nCharges & 0xFF), nLayer, pItem);
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
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x36);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x0C, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        STATLIST_SetState(pStatList, 0x36);
        STATLIST_SetStatRemoveCallback(pStatList, sub_004C21E0_StatRemoveCallback_ToggleStateOff);
    }
    else
    {
        STATLIST_SetState(pStatList, 0x36);
    }
}

// 0x004C0FF0
static __declspec(noinline) D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    int nSize = pPacket->nPacketSize - 13;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->nAnimMode);
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

// 0x004C2540
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

    if (pOwner->dwUnitType == 0)
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
            sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nX, tItemSave.nAnimMode, 0, tItemSave.nStorePage);
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
