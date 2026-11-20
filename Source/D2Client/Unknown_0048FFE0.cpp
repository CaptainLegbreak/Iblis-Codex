#include "D2Structs.h"
#include "D2Txt.h"
struct D2InventoryStrc;
struct D2BitBufferStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);

int __cdecl sub_0044DCC0(); // 0x0044DCC0
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786A0_SendDwords2(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_00478700_SendCommand(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700
int __cdecl sub_00486D10_CheckTick(); // 0x00486D10
void __cdecl sub_004A9DF0_UpdateSkillIcons(); // 0x004A9DF0
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId); // 0x004B3230
D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
int __fastcall sub_004B3870(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B3870
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall sub_004C21F0(D2UnitStrc* pItem); // 0x004C21F0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall sub_0062BEB0(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0
int __stdcall sub_0063BB20(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
static int gnGlobal_007BCBEC; // 0x007BCBEC
static int gdwGlobal_007BCBF0; // 0x007BCBF0
static unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0
int __cdecl sub_00486B30_IsNpcStateA(); // 0x00486B30
static __declspec(noinline) int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable);
static __declspec(noinline) void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid);

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gdwGlobal_007BCBF0 == 0xA || gdwGlobal_007BCBF0 == 0xB)
    {
        return 0;
    }
    if (!sub_0062BEB0(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

int __cdecl sub_00486B30_IsNpcStateA()
{
    switch (gdwGlobal_007BCBF0)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid)
{
    D2_ASSERT(pItem, 0x14E8);
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned int nPixelWidth;
    unsigned int nPixelHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004DBEA0(pItem, 0, 0, &nPixelWidth, &nPixelHeight);
    if (nWidth % 2 == 0)
    {
        nCellX = ((nPixelWidth >> 2) - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }
    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX / 2;
    }
    if (nHeight % 2 == 0)
    {
        nCellY = ((nPixelHeight >> 2) - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }
    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY / 2;
    }
    *pOutX = nCellX;
    *pOutY = nCellY;
    if (nWidth > 1)
    {
        const int n = *pOutX - nWidth / 2;
        *pOutX = n < 0 ? 0 : n;
    }
    if (nHeight > 1)
    {
        const int n = *pOutY - nHeight / 2;
        *pOutY = n < 0 ? 0 : n;
    }
}

static void __stdcall sub_00487BA0_Forward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gdwGlobal_007BCBF0 = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x0048FFE0
static int __stdcall sub_0048FFE0_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0());
    int nGridX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nGridY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    int nOutX;
    int nOutY;

    if (sub_00468830() == 6)
    {
        D2UnitStrc* pCursor = sub_004680A0();
        D2UnitStrc* pHit = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    sub_004C21F0(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (sub_00468830() == 8)
    {
        D2UnitStrc* pHit = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_00478680_SendPacket5(0x4C, pHit->dwUnitId);
                    sub_004C21F0(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (!pCursorItem)
    {
        D2UnitStrc* pHit = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0();
            if (sub_00486B30_IsNpcStateA() && bIsPlayer == 1)
            {
                if (!sub_004C2240(pHit) && sub_00486D10_CheckTick())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (sub_004B3230_GetSelectedUnitId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = sub_00463990(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, sub_0044DCD0_GetDifficulty(), sub_004B32D0(), !pNpc ? -1 : pNpc->dwClassId, 1);
                                    sub_00478700_SendCommand(0x33, !pNpc ? -1 : pNpc->dwUnitId, !pHit ? -1 : pHit->dwUnitId, !pHit ? -1 : pHit->dwAnimMode, nCost);
                                }
                                else
                                {
                                    sub_004CB9C0_Request(pUnit, 0x13);
                                }
                            }
                        }
                    }
                    else if ((nFlags & 4) && ITEMS_CheckIfBeltable(pHit) && !ITEMS_GetInvPage(pHit))
                    {
                        sub_00478680_SendPacket5(0x63, pHit->dwUnitId);
                        sub_004B9A00(0xEB, 0, 0, 0, 0);
                    }
                    else
                    {
                        sub_00478680_SendPacket5(0x19, pHit->dwUnitId);
                        gnGlobal_007BCBEC = 1;
                    }
                    nResult = 1;
                    sub_004C21F0(pHit);
                }
            }
            else if (gdwGlobal_007BCBF0 < 0x13)
            {
                sub_00487BA0_Forward((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            sub_0063BB20(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pBox, nPage, 1);
            if (pBox && DATATBLS_GetItemsTxtRecord((!pBox ? -1 : pBox->dwClassId))->dwCode == 0x20786F62)
            {
                pHit = pBox;
                goto LBL_CUBE;
            }
        }

        if (pHit && nCount == 1)
        {
            if (ITEMS_AreStackablesEqual(pCursorItem, pHit))
            {
                if (!sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gdwGlobal_007BCBF0 != 0xB && nPage != 2)
                {
                    sub_004786A0_SendDwords2(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnGlobal_00721E4C >= 0 && gnGlobal_00721E50 >= 0)
            {
                if (sub_004843E0_CanSocketInto(pHit, pCursorItem) && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMS_CheckItemTypeId(pCursorItem, 0x16) && ITEMS_CheckItemTypeId(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gdwGlobal_007BCBF0 != 0xB)
                {
                    sub_004A9DF0_UpdateSkillIcons();
                    sub_004786A0_SendDwords2(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (DATATBLS_GetItemsTxtRecord(!pHit ? -1 : pHit->dwClassId)->dwCode == 0x20786F62)
                {
LBL_CUBE:
                    if (!sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
                    {
                        int nFreeX;
                        int nFreeY;
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, sub_0044DCC0());
                        if (INVENTORY_GetFreePosition(pInventory, pCursorItem, nCubeRecord, &nFreeX, &nFreeY, 3))
                        {
                            sub_004786A0_SendDwords2(0x2A, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                            sub_004C21F0(pCursorItem);
                            sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                            nResult = 1;
                        }
                        else
                        {
                            sub_004CB9C0_Request(pUnit, 0x13);
                        }
                        goto LBL_DONE;
                    }
                }

                if (bPlace && sub_0063BB20(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pOther, nPage, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && nPage != 2)
                {
                    sub_00478700_SendCommand(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnGlobal_00721E4C, gnGlobal_00721E50);
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
LBL_DONE:
                ;
            }
        }
        else
        {
            if (nPage == 3)
            {
                D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord((!pCursorItem ? -1 : pCursorItem->dwClassId));
                D2_ASSERT(pTxt, 0x163A);
                if (pTxt->dwCode == 0x20786F62)
                {
                    return 1;
                }
            }

            int nCellX;
            int nCellY;
            sub_00486BD0_GetItemCell(nX, nY, &nCellX, &nCellY, pCursorItem, pGrid);
            D2UnitStrc* pExchange;
            unsigned int nExchangeCount;
            if (INVENTORY_CanItemBePlaced(pInventory, pCursorItem, nCellX, nCellY, nRecord, &pExchange, &nExchangeCount, nPage)
                && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
            {
                sub_00478700_SendCommand(0x18, (!pCursorItem ? -1 : pCursorItem->dwUnitId), nCellX, nCellY, nPage);
                sub_004C21F0(pCursorItem);
                sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

int __stdcall sub_19F4_Emit_0048FFE0(D2UnitStrc* pUnit, unsigned int nX, unsigned int nY, int nFlags)
{
    return sub_0048FFE0_ClickInvGrid(pUnit, pUnit->pInventory, nX, nY, nFlags, &gGrid_007BCB88, gnSelectedTab_007BCC04);
}
