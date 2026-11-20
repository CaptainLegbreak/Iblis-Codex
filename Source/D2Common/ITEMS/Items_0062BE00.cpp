#include "D2Structs.h"
struct D2ItemDataStrc { char unknown0[24]; unsigned int dwItemFlags; };
struct D2ItemsTxt { char unknown0[271]; unsigned char nInvWidth; unsigned char nInvHeight; };
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

static void ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight)
{
    *pWidth = 0;
    *pHeight = 0;

    if (pItem && pItem->dwUnitType == 4)
    {
        const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord)
        {
            *pWidth = pItemsTxtRecord->nInvWidth;
            *pHeight = pItemsTxtRecord->nInvHeight;
        }
    }
}

static void ITEMS_SetOrRemoveFlag(unsigned int* pFlags, unsigned int nFlag, int bSet)
{
    if (bSet)
    {
        *pFlags |= nFlag;
    }
    else
    {
        *pFlags &= ~nFlag;
    }
}

static void ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
    {
        ITEMS_SetOrRemoveFlag(&pItem->pItemData->dwItemFlags, dwFlag, bSet);
    }
}

// 0x0062BE00
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets)
{
    if (pItem && (!pItem ? 6 : pItem->dwUnitType) == 4)
    {
        int nMaxSockets = 6;
        unsigned char nWidth = 0;
        unsigned char nHeight = 0;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight);

        const int nArea = nHeight * nWidth;
        if (nArea <= 6)
        {
            nMaxSockets = nArea;
            if (nArea <= 0)
                return;
        }

        {
            if (nMaxSockets >= ITEMS_GetMaxSockets(pItem))
            {
                nMaxSockets = ITEMS_GetMaxSockets(pItem);
            }

            if (nSockets <= 1)
            {
                nSockets = 1;
            }

            if (nSockets >= nMaxSockets)
            {
                nSockets = nMaxSockets;
            }

            ITEMS_SetItemFlag(pItem, 0x800, 1);
            STATLIST_SetUnitStat(pItem, 194, nSockets, 0);
        }
    }
}
