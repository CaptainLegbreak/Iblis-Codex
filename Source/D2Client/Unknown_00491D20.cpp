#include "D2Structs.h"
#include "D2Txt.h"
struct D2UnitStrc;
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
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __fastcall sub_00478700_SendCommand(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700
int __cdecl sub_00486D10_CheckTick(); // 0x00486D10
void __cdecl sub_004A9DF0_UpdateSkillIcons(); // 0x004A9DF0
int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230
D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
int __fastcall sub_004B3870(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B3870
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem); // 0x004C21F0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem); // 0x006299B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0
int __stdcall sub_0063BB20_CheckInventoryOverlap(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern "C" const char szCmnItemsH_006D9B90[]; // 0x006D9B90
extern "C" const char szInvCpp_006D9BC0[]; // 0x006D9BC0

extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
static int gnGlobal_007BCBEC; // 0x007BCBEC
static int gdwGlobal_007BCBF0; // 0x007BCBF0
static unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0
int __cdecl sub_00486B30_IsNpcStateA(); // 0x00486B30
static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable);
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid);

// 0x004843E0
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
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, szInvCpp_006D9BC0))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (sub_0062BC20(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, szInvCpp_006D9BC0))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, szInvCpp_006D9BC0))
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

// 0x00486B30
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
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, szCmnItemsH_006D9B90, 0x6DC);
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

// 0x00487BA0
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
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    sub_004C21F0_SetState36(pHit);
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
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_00478680_SendPacket5(0x4C, pHit->dwUnitId);
                    sub_004C21F0_SetState36(pHit);
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
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0_GetPlayerUnit();
            if (sub_00486B30_IsNpcStateA() && bIsPlayer == 1)
            {
                if (!sub_004C2240(pHit) && sub_00486D10_CheckTick())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (sub_004B3230_GetTickPair(&nNpcId))
                        {
                            D2UnitStrc* pNpc = sub_00463990(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = sub_0062FDC0_GetRepairCost(sub_00463DE0_GetPlayerUnit(), pHit, sub_0044DCD0_GetDifficulty(), sub_004B32D0(), !pNpc ? -1 : pNpc->dwClassId, 1);
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
                    sub_004C21F0_SetState36(pHit);
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
            sub_0063BB20_CheckInventoryOverlap(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pBox, nPage, 1);
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
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnGlobal_00721E4C >= 0 && gnGlobal_00721E50 >= 0)
            {
                if (sub_004843E0_CanSocketInto(pHit, pCursorItem) && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMSIsA(pCursorItem, 0x16) && ITEMSIsA(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gdwGlobal_007BCBF0 != 0xB)
                {
                    sub_004A9DF0_UpdateSkillIcons();
                    sub_004786A0_SendDwords2(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
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
                            sub_004C21F0_SetState36(pCursorItem);
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

                if (bPlace && sub_0063BB20_CheckInventoryOverlap(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pOther, nPage, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && nPage != 2)
                {
                    sub_00478700_SendCommand(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnGlobal_00721E4C, gnGlobal_00721E50);
                    sub_004C21F0_SetState36(pCursorItem);
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
                sub_004C21F0_SetState36(pCursorItem);
                sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

struct SMSGHANDLER_PARAMS { void* hWnd; unsigned int uMessage,wParam; unsigned short nXpos,nYpos; unsigned int dwCommandSource,dwArg; int bReturn,lResult; };
struct D2InvRectStrc { int nLeft,nRight,nTop,nBottom; };
struct D2InvCompGridStrc { D2InvRectStrc rect; unsigned char nWidth,nHeight; unsigned short pad12; };
extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
static int gdwGlobal_007BCBE4; // 0x007BCBE4
static int gdwGlobal_007BCBE8; // 0x007BCBE8
static D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4
static D2UnitStrc* gdwGlobal_007BCBF8; // 0x007BCBF8
static int gnGlobal_007BCE30; // 0x007BCE30
static int gbGlobal_007BCE90; // 0x007BCE90
int __cdecl sub_0044DA30(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
void __cdecl sub_004835B0_LoadUiRecords(); // 0x004835B0
int __cdecl sub_004979E0(); // 0x004979E0
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_0045AE90(); // 0x0045AE90
void __cdecl sub_00453EC0(); // 0x00453EC0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS*); // 0x00498DC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730
extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0
typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);
extern D2BodyClickFn gaBodyClick_00721E58[]; // 0x00721E58

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY); // 0x00483AB0
// 0x00483AB0
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gInvRect_007BCAA0.nLeft && nX < gInvRect_007BCAA0.nRight && nY >= gInvRect_007BCAA0.nTop && nY <= gInvRect_007BCAA0.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY);
static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860
// 0x00486860
static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids_007BCC58[5].rect.nLeft && nX <= gaCompGrids_007BCC58[5].rect.nRight && nY >= gaCompGrids_007BCC58[5].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids_007BCC58[4].rect.nLeft && nX <= gaCompGrids_007BCC58[4].rect.nRight && nY >= gaCompGrids_007BCC58[4].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

static int sub_00486DA0_IsOverGoldButton(int nX, int nY);
static int sub_00486DA0_IsOverGoldButton(int nX, int nY); // 0x00486DA0
// 0x00486DA0
static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x57 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x45
        && nX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0xED && nX <= gnGlobal_0071146C - gnGlobal_007A2858 - 0xD9)
    {
        return 1;
    }
    return 0;
}

__declspec(noinline) int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY);
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY); // 0x00486E10
// 0x00486E10
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E || nX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E)
    {
        return 0;
    }
    if (nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x60 || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 0;
    }
    return 1;
}

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX);
static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60
// 0x00486E60
static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        return;
    }
    if (nY > gnGlobal_00711470 - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
    }
    if (sub_0045AE90() == 3 && gdwGlobal_007BCBF0 == 0 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004912A0
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(sub_0044DA30() || sub_00463DF0()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnGlobal_0071146C) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    sub_004835B0_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!sub_004979E0()) {
        if(sub_00486DA0_IsOverGoldButton(x,y) && (gdwGlobal_007BCBF0==0 || gdwGlobal_007BCBF0==11 || gdwGlobal_007BCBF0==12 || gdwGlobal_007BCBF0==15)) {
            gnGlobal_007BCE30=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(sub_00486E10_IsInNpcPanelRect(x,y) && (gdwGlobal_007BCBF0==0 || gdwGlobal_007BCBF0==19)) {
            gbGlobal_007BCE90=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00483AB0_IsInInvRect(x,y)) {
        if(sub_00486E10_IsInNpcPanelRect(x,y)) {
            gbGlobal_007BCE90=1;
            sub_00455F20(1,1,0);
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn=1;
        pMsg->lResult=0;
        int result=0;
        if(x>=gGrid_007BCB88.nGridLeft && x<=gGrid_007BCB88.nGridRight && y>=gGrid_007BCB88.nGridTop && y<=gGrid_007BCB88.nGridBottom) {
            result=sub_0048FFE0_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gGrid_007BCB88,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids_007BCC58[bodyloc].rect.nLeft && x<=gaCompGrids_007BCC58[bodyloc].rect.nRight && y>=gaCompGrids_007BCC58[bodyloc].rect.nTop && y<=gaCompGrids_007BCC58[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick_00721E58[bodyloc](player,inventory,bodyloc);
                    handled=1;
                }
                else {
                    D2UnitStrc* bodyItem=INVENTORY_GetItemFromBodyLoc(inventory,bodyloc);
                    if(!sub_004843E0_CanSocketInto(bodyItem,cursor)) goto USE_BODY_ACTION;
                    if(!sub_004C2240(cursor) && sub_00486D10_CheckTick()) {
                        sub_004786A0_SendDwords2(0x28,!cursor?-1:cursor->dwUnitId,!bodyItem?-1:bodyItem->dwUnitId);
                        sub_004C21F0_SetState36(cursor);
                        sub_004B9A00(sub_004C1D60(bodyItem),0,0,0,0);
                        handled=1;
                    }
                    result=0;
                }
            }
AFTER_BODY:
            if(!handled && sub_0044DCC0() && sub_00486860_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) sub_00453EC0();
            else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gdwGlobal_007BCBE4=0;
        gdwGlobal_007BCBE8=0;
        gdwGlobal_007BCBF4=0;
        gdwGlobal_007BCBF8=0;
        if(!handled) sub_00486E60_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gdwGlobal_007BCBF0) {
    case 14:
        if(x>=gGrid_007BCB70.nGridLeft && x<=gGrid_007BCB70.nGridRight && y>=gGrid_007BCB70.nGridTop && y<=gGrid_007BCB70.nGridBottom) {
            sub_0048FFE0_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gGrid_007BCB70,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gdwGlobal_007BCBE4=0;gdwGlobal_007BCBE8=0;gdwGlobal_007BCBF4=0;gdwGlobal_007BCBF8=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(sub_0044DCC0()) {
                left=gGrid_007BCA78.nGridLeft;right=gGrid_007BCA78.nGridRight;top=gGrid_007BCA78.nGridTop;bottom=gGrid_007BCA78.nGridBottom;
            }
            else {
                left=gGrid_007BCB40.nGridLeft;right=gGrid_007BCB40.nGridRight;top=gGrid_007BCB40.nGridTop;bottom=gGrid_007BCB40.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(sub_0044DCC0()) sub_0048FFE0_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gGrid_007BCA78,4);
                else sub_0048FFE0_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gGrid_007BCB40,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gdwGlobal_007BCBE4=0;gdwGlobal_007BCBE8=0;gdwGlobal_007BCBF4=0;gdwGlobal_007BCBF8=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gGrid_007BCA30.nGridLeft && x<=gGrid_007BCA30.nGridRight && y>=gGrid_007BCA30.nGridTop && y<=gGrid_007BCA30.nGridBottom) {
            int result=sub_0048FFE0_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gGrid_007BCA30,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gdwGlobal_007BCBE4=0;gdwGlobal_007BCBE8=0;gdwGlobal_007BCBF4=0;gdwGlobal_007BCBF8=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    sub_00486E60_ClickOutsidePanel(y,pMsg,x);
}

struct Unicode {
    unsigned short wChar;
    Unicode(); // 0x0042F530
};
struct D2PanelButtonStrc { int active,selected; unsigned short text,padA; int padC[2]; };
extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0
extern int gnButtonCount_00722160; // 0x00722160
extern int gnButtonRow_0072215C; // 0x0072215C
extern int ganButtonX_00722168[][4]; // 0x00722168
extern int gnTabEnabled0_0072211E; // 0x0072211E
extern int gnTabEnabled1_00722130; // 0x00722130
extern int gnTabEnabled2_00722142; // 0x00722142
extern int gnTabEnabled3_00722154; // 0x00722154
extern int gnGlobal_007BCC08; // 0x007BCC08
extern int gnGlobal_007BCA4C; // 0x007BCA4C
extern int gnGlobal_007BCBD8; // 0x007BCBD8
extern int gnGlobal_007BCBB0; // 0x007BCBB0
extern int gnGlobal_007BCBB4; // 0x007BCBB4
extern int gnGlobal_007BCBB8; // 0x007BCBB8
extern int gnGlobal_007BCBBC; // 0x007BCBBC
extern int gnGlobal_007BCE9C; // 0x007BCE9C
extern D2InventoryGridInfoStrc gGrid_007BCB58; // 0x007BCB58
int __cdecl sub_00483E10_IsNpcStateIdle(); // 0x00483E10
int __cdecl sub_00487BE0_ResetButtons(); // 0x00487BE0
void __stdcall sub_00487A10_SelectItemPageTab(unsigned char nTab); // 0x00487A10
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc*,int,int*,Unicode*,int); // 0x004B2AD0
static __forceinline int GetNpcTabLeft(int tab)
{
    return gnGlobal_007A2858+80*tab;
}
static __forceinline int GetNpcTabRight(int tab)
{
    return GetNpcTabLeft(tab)+80;
}
// 0x00491D20
void __stdcall sub_00491D20_HandleNpcClick(SMSGHANDLER_PARAMS* msg)
{
    const int x=msg->nXpos;
    const int y=msg->nYpos;
    if(gdwGlobal_007BCBF0!=0 && gdwGlobal_007BCBF0!=1 && gdwGlobal_007BCBF0!=3 && gdwGlobal_007BCBF0!=2 && gdwGlobal_007BCBF0!=4) goto HANDLE;
    if(!sub_00498DC0_MouseMoveMsg(msg) && sub_00486E10_IsInNpcPanelRect(x,y) && sub_00483E10_IsNpcStateIdle()) {
        gbGlobal_007BCE90=1;msg->bReturn=1;msg->lResult=0;
        sub_004B9A00(4,0,0,0,0);
        sub_00420290_BreakHandlerChain(msg);return;
    }
    if(sub_004680A0()) {
        int nArg;
        if(sub_00498DC0_MouseMoveMsg(msg)==1) {sub_00487BE0_ResetButtons();return;}
        if(x<0 || x>gInvRect_007BCAA0.nLeft || y<0 || y>gInvRect_007BCAA0.nBottom) goto OUTSIDE;
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);
        if(x<gGrid_007BCB58.nGridLeft || x>gGrid_007BCB58.nGridRight || y<gGrid_007BCB58.nGridTop || y>gGrid_007BCB58.nGridBottom) return;
        if(sub_00468830()==6 || !sub_004B3230_GetTickPair(&nArg)) return;
        D2UnitStrc* player=sub_00463990(nArg,1);
        if(!player) return;
        Unicode text[64];int cost;
        if(!sub_004B2AD0_GetTradeCostText(sub_004680A0(),1,&cost,text,64)) return;
        const int arg=msg->wParam;
        D2UnitStrc* item=sub_004680A0();
        if(item && sub_004B3870((int)player,(int)item,1,x,y,arg,1,0)) sub_00468070_SetCursorItemState(0);
        return;
    }
    if(sub_00498DC0_MouseMoveMsg(msg)==1) {sub_00487BE0_ResetButtons();return;}
    msg->bReturn=0;
    if(x>=gnGlobal_007A2858 && x<=gnGlobal_0071146C/2-1 && y>=gnGlobal_00711470 + gnGlobal_007A285C-0x1DF && y<=gnGlobal_007A285C+gnGlobal_00711470-0x1C1) {
        if(x>=GetNpcTabLeft(0) && x<=GetNpcTabRight(0)) {
            if(gnTabEnabled0_0072211E && gnSelectedTab_007BCC04!=0) {
                sub_004B9A00(6,0,0,0,0);gnGlobal_007BCC08=0;sub_00487A10_SelectItemPageTab(0);
            }
        } else if(x>=GetNpcTabLeft(1) && x<=GetNpcTabRight(1)) {
            if(gnTabEnabled1_00722130 && gnSelectedTab_007BCC04!=1) {
                sub_004B9A00(6,0,0,0,0);gnGlobal_007BCC08=0;sub_00487A10_SelectItemPageTab(1);
            }
        } else if(x>=GetNpcTabLeft(2) && x<=GetNpcTabRight(2)) {
            if(gnTabEnabled2_00722142 && gnSelectedTab_007BCC04!=2) {
                sub_004B9A00(6,0,0,0,0);gnGlobal_007BCC08=0;sub_00487A10_SelectItemPageTab(2);
            }
        } else if(x>GetNpcTabLeft(3) && x<GetNpcTabRight(3)) {
            if(gnTabEnabled3_00722154 && gnSelectedTab_007BCC04!=3) {
                sub_004B9A00(6,0,0,0,0);gnGlobal_007BCC08=0;sub_00487A10_SelectItemPageTab(3);
            }
        } else {
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
    }
    if(x<gnGlobal_007BCBB0 || x>gnGlobal_007BCBB4) goto OUTSIDE;
    {
        const int top=gnGlobal_00711470+gnGlobal_007A285C-0x6D;
        if(y>=top && y<=gnGlobal_007BCBBC) {
            int hasSelected=0;int selected=0;int clicked=-1;
            for(int i=0;i<gnButtonCount_00722160;++i) {
                if(gaPanelButtons_007BC9E0[i].selected==1) {selected=i;hasSelected=1;}
                if(gnGlobal_007BCA4C>ganButtonX_00722168[gnButtonRow_0072215C][i]+gnGlobal_007A2858 && gnGlobal_007BCA4C<ganButtonX_00722168[gnButtonRow_0072215C][i]+gnGlobal_007A2858+45 && gnGlobal_007BCBD8>top && gnGlobal_007BCBD8<gnGlobal_007A285C+gnGlobal_00711470-0x41) clicked=i;
            }
            if(clicked!=-1) {
                if(gaPanelButtons_007BC9E0[clicked].active==1) {
                    sub_004B9A00(1,0,0,0,0);
                    if(hasSelected==1) {
                        if(clicked==selected) {
                            gaPanelButtons_007BC9E0[clicked].selected=0;gdwGlobal_007BCBF0=1;
                            if(sub_00463DD0_GetPlayerUnit()) {
                                D2InventoryStrc* inventory=sub_00463DD0_GetPlayerUnit()->pInventory;
                                if(inventory && !INVENTORY_GetCursorItem(inventory)) sub_00468070_SetCursorItemState(0);
                            }
                        } else {
                            gaPanelButtons_007BC9E0[clicked].selected=1;gaPanelButtons_007BC9E0[selected].selected=0;
                        }
                    } else gaPanelButtons_007BC9E0[clicked].selected=1;
                    gnGlobal_007BCE9C=1;
                } else {sub_00487BE0_ResetButtons();gnGlobal_007BCE9C=0;}
            }
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
    }
    if(y<gnGlobal_007BCBB8 || y>gnGlobal_007BCBBC) goto OUTSIDE;
    {
    int nArg;
    if((gdwGlobal_007BCBF0==1 || gdwGlobal_007BCBF0==2) && x>=gGrid_007BCB58.nGridLeft && x<=gGrid_007BCB58.nGridRight && y>=gGrid_007BCB58.nGridTop && y<=gGrid_007BCB58.nGridBottom && sub_004B3230_GetTickPair(&nArg)) {
        D2UnitStrc* player=sub_00463990(nArg,1);
        if(player) sub_0048FFE0_ClickInvGrid(player,player->pInventory,x,y,msg->wParam,&gGrid_007BCB58,gnSelectedTab_007BCC04);
    }
    }
HANDLE:
    msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
OUTSIDE:
    sub_004912A0_HandlePanelClick(msg);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

// build: context ?sub_00486BD0_GetItemCell@@YGXIIPAH0PAUD2UnitStrc@@PAUD2InventoryGridInfoStrc@@@Z
// build: context ?GetNpcTabLeft@@YAHH@Z
// build: context ?GetNpcTabRight@@YAHH@Z
