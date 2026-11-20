#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#ifdef MOVED_TEST
#define LEVEL_LOW 27
#define LEVEL_HIGH 42
#else
#define LEVEL_LOW 25
#define LEVEL_HIGH 40
#endif




struct D2ItemTypesTxt
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    unsigned char nRepair;
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    short wShoots;
    short wQuiver;
    unsigned char nThrowable;
    unsigned char nReload;
    unsigned char nReEquip;
    unsigned char nAutoStack;
    char unk0x14[6];
    unsigned char nMaxSock1;
    unsigned char nMaxSock25;
    unsigned char nMaxSock40;
    char unk0x1D[0xC7];
};

extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);  // 0x006335F0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);  // 0x0062B400
inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x006281E0
__declspec(noinline) int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }

    return 1;
}

inline unsigned char __stdcall ITEMS_GetAllowedGemSocketsFromItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nGemSockets;
}
// 0x0062BC20
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pType = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pType)
            return 0;
        int nSockets = ITEMS_GetAllowedGemSocketsFromItemId(pItem->dwClassId);
        int nLevel = ITEMS_GetItemLevel(pItem);
        int nTypeSockets;
        if (nLevel <= LEVEL_LOW)
            nTypeSockets = pType->nMaxSock1;
        else if (nLevel <= LEVEL_HIGH)
            nTypeSockets = pType->nMaxSock25;
        else
            nTypeSockets = pType->nMaxSock40;
        if (nSockets >= nTypeSockets)
            nSockets = nTypeSockets;
        return (unsigned char)nSockets;
    }
    return 0;
}
