#include "D2Common.h"

struct D2InventoryStrc;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
};

struct D2ItemDataStrc
{
    char unk0x00[0x5C];
    D2ItemExtraDataStrc pExtraData;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
};

struct D2InventoryNodeStrc
{
    int nItemId;
    D2InventoryNodeStrc* pNext;
};

struct D2CorpseStrc
{
    unsigned int unk0x00;
    unsigned int dwUnitId;
    unsigned int unk0x08;
    D2CorpseStrc* pNextCorpse;
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    void* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
    D2UnitStrc* pCursorItem;
    int dwOwnerGuid;
    int dwItemCount;
    D2InventoryNodeStrc* pFirstNode;
    D2InventoryNodeStrc* pLastNode;
    D2CorpseStrc* pFirstCorpse;
    D2CorpseStrc* pLastCorpse;
    int nCorpseCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem);                                                     // 0x0063AAF0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD50
int __stdcall INVENTORY_CheckForItemInTradeInventory(D2InventoryStrc* pInventory, int nItemId);            // 0x0063CC30

#define INVENTORY_SIGNATURE 0x1020304
#define UNIT_ITEM 4
#define D2UnitInvalidGUID -1

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

inline D2UnitStrc* INVENTORY_UnitIsItemInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pExtraData;
    }

    return 0;
}

// 0x0063AD90
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return 0;
    }

    if (INVENTORY_CompareWithItemsParentInventory(pInventory, pItem))
    {
        INVENTORY_RemoveItem(pItem);
        return pItem;
    }

    return 0;
}

// 0x0063C180
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        if (!pItem)
        {
            if (INVENTORY_GetItemExtraDataFromItem(pInventory->pCursorItem))
            {
                INVENTORY_RemoveItem(pInventory->pCursorItem);
            }
        }
        else
        {
            if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem))
            {
                pInventory->pCursorItem = pItem;
                pItemExtraData->pParentInv = pInventory;
            }
        }
    }
}

// 0x0063CB70
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        for (D2UnitStrc* pItem = pInventory->pFirstItem; pItem; pItem = pInventory->pFirstItem)
        {
            INVENTORY_RemoveItem(pItem);
        }
    }
}

// 0x0063CBD0
void __stdcall INVENTORY_FreeTradeInventory(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryNodeStrc* pNextNode = 0;
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNextNode)
        {
            pNextNode = pNode->pNext;
            FOG_FreeServerMemory(pInventory->pMemPool, pNode, gszInventorySourceFile_006EA918, 3259, 0);
        }

        pInventory->pFirstNode = 0;
        pInventory->pLastNode = 0;
    }
}

// 0x0063CC70
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        return;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return;
    }

    if (INVENTORY_CheckForItemInTradeInventory(pInventory, pItem->dwUnitId))
    {
        return;
    }

    D2InventoryNodeStrc* pNode = (D2InventoryNodeStrc*)sub_0040B430(pInventory->pMemPool, sizeof(D2InventoryNodeStrc), gszInventorySourceFile_006EA918, 3337, 0);
    D2_ASSERT(pNode, 3338);
    memset(pNode, 0x00, sizeof(D2InventoryNodeStrc));
    pNode->nItemId = pItem->dwUnitId;

    if (!pInventory->pFirstNode)
    {
        pInventory->pFirstNode = pNode;
    }
    else
    {
        pInventory->pLastNode->pNext = pNode;
    }

    pNode->pNext = 0;
    pInventory->pLastNode = pNode;
}

// 0x0063D4E0
int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int a3)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2CorpseStrc* pPreviousCorpse = 0;
    D2CorpseStrc* pCorpse = pInventory->pFirstCorpse;
    for (; pCorpse; pCorpse = pCorpse->pNextCorpse)
    {
        if (pCorpse->dwUnitId == nUnitId && pCorpse->unk0x00 == a3)
        {
            break;
        }

        pPreviousCorpse = pCorpse;
    }

    if (!pCorpse)
    {
        return 0;
    }

    D2CorpseStrc* pNextCorpse = pCorpse->pNextCorpse;
    if (!pPreviousCorpse)
    {
        pInventory->pFirstCorpse = pNextCorpse;
        if (!pNextCorpse)
        {
            pInventory->pLastCorpse = 0;
        }
    }
    else
    {
        pPreviousCorpse->pNextCorpse = pNextCorpse;
        if (!pNextCorpse)
        {
            pInventory->pLastCorpse = pPreviousCorpse;
        }
    }

    if (pCorpse->unk0x00)
    {
        --pInventory->nCorpseCount;
    }

    FOG_FreeServerMemory(pInventory->pMemPool, pCorpse, gszInventorySourceFile_006EA918, 4148, 0);
    return 1;
}

// 0x0063D590
void __stdcall sub_0063D590_FreeCorpses(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2CorpseStrc* pNextCorpse = 0;
        for (D2CorpseStrc* pCorpse = pInventory->pFirstCorpse; pCorpse; pCorpse = pNextCorpse)
        {
            pNextCorpse = pCorpse->pNextCorpse;
            FOG_FreeServerMemory(pInventory->pMemPool, pCorpse, gszInventorySourceFile_006EA918, 4209, 0);
        }

        pInventory->pFirstCorpse = 0;
        pInventory->pLastCorpse = 0;
    }
}

// 0x0063E0B0
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    pInventory->pCursorItem = 0;
    pInventory->dwLeftItemGUID = D2UnitInvalidGUID;

    while (pInventory->pFirstItem)
    {
        if (!INVENTORY_RemoveItem(pInventory->pFirstItem))
        {
            return 0;
        }
    }

    return 1;
}
