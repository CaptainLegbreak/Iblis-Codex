extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2InventoryStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2ItemsTxt
{
    char unk0x00[0x124];
    short wDropSound;
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x84];
    short wDropSound;
    char unk0x86[0xC6];
};

struct D2SetItemsTxt
{
    char unk0x00[0x82];
    short wDropSound;
    char unk0x84[0x134];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x04];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

#pragma pack(push, 1)
struct D2PacketRecord8Strc
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};

struct D2PacketRecord13Strc
{
    unsigned char nHeader;
    unsigned int nItemGUID;
    unsigned int dwFlag;
    unsigned int bSet;
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern short gwGlobal_007C78A8;                                                                             // 0x007C78A8
extern short gwGlobal_007C78AC;                                                                             // 0x007C78AC
extern int gaCursorKind_00727A40[];                                                                         // 0x00727A40
extern unsigned int gnCursorKindCount_00727A48;                                                             // 0x00727A48

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                        // 0x006280D0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __fastcall sub_004B29E0(int nUnitId);                                                                  // 0x004B29E0
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __fastcall sub_00468010(D2UnitStrc* pItem, int nCursor);                                               // 0x00468010

static __forceinline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nId];
    return 0;
}

static __forceinline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nId];
    return 0;
}

// 0x004C1D60
int __fastcall sub_004C1D60(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > 0)
        nSound = pItemsTxt->wDropSound;

    if (ITEMS_GetItemQuality(pItem) == 7)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEMS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
                nSound = pUniqueItemsTxt->wDropSound;
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
            nSound = pSetItemsTxt->wDropSound;
    }
    return nSound;
}

// 0x004C1E30
void __cdecl sub_004C1E30()
{
    gwGlobal_007C78A8 = 0;
    gwGlobal_007C78AC = 0;
}

// 0x004C2020
void __fastcall sub_004C2020(D2PacketRecord13Strc* pPacket)
{
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemGUID, 4);
    if (pItem)
        ITEMS_SetItemFlag(pItem, pPacket->dwFlag, pPacket->bSet);
}

// 0x004C2050
void __fastcall sub_004C2050(D2GSPacketSrv42Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitGUID, pPacket->nUnitType);
    if (!pUnit)
        return;
    if (pUnit != sub_00463DD0())
        return;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem)
        return;
    int nItemId = pItem->dwUnitId;
    INVENTORY_SetCursorItem(pInventory, 0);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_00465EE0_RemoveClientSideUnit(nItemId, pItem->dwUnitType);
    sub_004B29E0(nItemId);
}

// 0x004C2180
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0xCC2);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pItem, 0x36);
    if (pStatList)
    {
        STATES_ToggleState(pItem, 0x36, 0);
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
        UNITS_UpdateAnimRateAndVelocity(pItem, ".\\UNIT\\Item.cpp", 0xCCA);
    }
}

// 0x004C2240
int __fastcall sub_004C2240(D2UnitStrc* pUnit)
{
    if (STATLIST_GetStatListFromUnitAndFlag(pUnit, 2))
        return 1;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer && STATES_CheckState(pPlayer, 0x36))
        return 1;
    return 0;
}

// 0x004C4620
void __fastcall sub_004C4620(D2PacketRecord8Strc* pPacket)
{
    if (pPacket->nSkill != 0xFFFF)
    {
        for (unsigned int i = 0; i < gnCursorKindCount_00727A48; ++i)
        {
            if (pPacket->nCursor == gaCursorKind_00727A40[i] && !sub_00453A90_GetUIVarUnchecked(1))
            {
                sub_00455F20(1, 0, 0);
                break;
            }
        }
        D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
        if (pItem)
            sub_00468010(pItem, pPacket->nCursor);
        return;
    }

    if (pPacket->nCursor == 0xFF)
    {
        D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 4, 0);
            sub_004C2180_UpdateCursorItem(pItem);
        }
        sub_00468070_SetCursorItemState(0);
        return;
    }

    for (unsigned int i = 0; i < gnCursorKindCount_00727A48; ++i)
    {
        if (pPacket->nCursor == gaCursorKind_00727A40[i] && !sub_00453A90_GetUIVarUnchecked(1))
            sub_00455F20(1, 0, 0);
    }
    D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 4, 1);
        sub_00468010(pItem, pPacket->nCursor);
    }
}

#include "gen/data/Source/D2Client/004C1D60_sub_004C1D60.inc"
