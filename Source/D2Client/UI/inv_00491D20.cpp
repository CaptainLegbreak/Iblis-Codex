#include "D2Structs.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
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

int __cdecl GAME_IsExpansion(); // 0x0044DCC0
unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
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
int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
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
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0
int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern "C" const char gszCmnItemsH[]; // 0x006D9B90
extern "C" const char gszInvCpp[]; // 0x006D9BC0

extern int gnHoverCellX; // 0x00721E4C
extern int gnHoverCellY; // 0x00721E50
extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88
static int gbNpcTradeClicked; // 0x007BCBEC
static int gnInvPanelMode; // 0x007BCBF0
static unsigned char gnSelectedTab; // 0x007BCC04

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0
int __cdecl INV_IsTradeStateInteractive(); // 0x00486B30
static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable);
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid);

// 0x004843E0
static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gnInvPanelMode == 0xA || gnInvPanelMode == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, gszInvCpp))
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
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, gszInvCpp))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, gszInvCpp))
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
int __cdecl INV_IsTradeStateInteractive()
{
    switch (gnInvPanelMode)
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
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
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
static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x0048FFE0
static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
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
            if (INV_IsTradeStateInteractive() && bIsPlayer == 1)
            {
                if (!sub_004C2240(pHit) && sub_00486D10_CheckTick())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (NPCMENU_GetInteractNpcId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), !pNpc ? -1 : pNpc->dwClassId, 1);
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
                        gbNpcTradeClicked = 1;
                    }
                    nResult = 1;
                    sub_004C21F0_SetState36(pHit);
                }
            }
            else if (gnInvPanelMode < 0x13)
            {
                INV_ForwardTradeClick((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pBox, nPage, 1);
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
                if (!sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gnInvPanelMode != 0xB && nPage != 2)
                {
                    sub_004786A0_SendDwords2(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnHoverCellX >= 0 && gnHoverCellY >= 0)
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
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gnInvPanelMode != 0xB)
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
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, GAME_IsExpansion());
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

                if (bPlace && INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && nPage != 2)
                {
                    sub_00478700_SendCommand(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnHoverCellX, gnHoverCellY);
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

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0
extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58
extern D2InventoryGridInfoStrc gtTradePage2Grid; // 0x007BCA30
extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78
extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40
extern D2InventoryGridInfoStrc gtCubeGrid; // 0x007BCB70
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
static int gbHoverInGrid; // 0x007BCBE4
static int gbHoverInBodyLoc; // 0x007BCBE8
static D2UnitStrc* gpHoverItem; // 0x007BCBF4
static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8
static int gbInvGoldButtonDown; // 0x007BCE30
static int gbPanelButtonDown; // 0x007BCE90
int __cdecl GAME_IsExitPending(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
void __cdecl INV_LoadUiRecords(); // 0x004835B0
int __cdecl sub_004979E0(); // 0x004979E0
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_0045AE90(); // 0x0045AE90
void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730
extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0
typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);
extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY); // 0x00483AB0
// 0x00483AB0
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
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
    if (nX >= gaCompGrids[5].rect.nLeft && nX <= gaCompGrids[5].rect.nRight && nY >= gaCompGrids[5].rect.nTop - 0x18 && nY < gaCompGrids[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids[4].rect.nLeft && nX <= gaCompGrids[4].rect.nRight && nY >= gaCompGrids[4].rect.nTop - 0x18 && nY < gaCompGrids[4].rect.nTop)
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
    if (nY >= gnScreenHeight + gnPanelOffsetY - 0x57 && nY <= gnScreenHeight + gnPanelOffsetY - 0x45
        && nX >= gnScreenWidth - gnPanelOffsetX - 0xED && nX <= gnScreenWidth - gnPanelOffsetX - 0xD9)
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
    if (nX < gnScreenWidth - gnPanelOffsetX - 0x12E || nX > gnScreenWidth - gnPanelOffsetX - 0x10E)
    {
        return 0;
    }
    if (nY < gnScreenHeight + gnPanelOffsetY - 0x60 || nY > gnScreenHeight + gnPanelOffsetY - 0x40)
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
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        return;
    }
    if (nY > gnScreenHeight - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    if (sub_0045AE90() == 3 && gnInvPanelMode == 0 && nX < gnScreenWidth / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004912A0
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || sub_00463DF0()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnScreenWidth) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!sub_004979E0()) {
        if(sub_00486DA0_IsOverGoldButton(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==11 || gnInvPanelMode==12 || gnInvPanelMode==15)) {
            gbInvGoldButtonDown=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(sub_00486E10_IsInNpcPanelRect(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==19)) {
            gbPanelButtonDown=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && sub_00483AB0_IsInInvRect(x,y)) {
        if(sub_00486E10_IsInNpcPanelRect(x,y)) {
            gbPanelButtonDown=1;
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
        if(x>=gtPlayerInvGrid.nGridLeft && x<=gtPlayerInvGrid.nGridRight && y>=gtPlayerInvGrid.nGridTop && y<=gtPlayerInvGrid.nGridBottom) {
            result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtPlayerInvGrid,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids[bodyloc].rect.nLeft && x<=gaCompGrids[bodyloc].rect.nRight && y>=gaCompGrids[bodyloc].rect.nTop && y<=gaCompGrids[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick[bodyloc](player,inventory,bodyloc);
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
            if(!handled && GAME_IsExpansion() && sub_00486860_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) UI_CancelCursorItemUse();
            else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gbHoverInGrid=0;
        gbHoverInBodyLoc=0;
        gpHoverItem=0;
        gpLastHoverItem=0;
        if(!handled) sub_00486E60_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gnInvPanelMode) {
    case 14:
        if(x>=gtCubeGrid.nGridLeft && x<=gtCubeGrid.nGridRight && y>=gtCubeGrid.nGridTop && y<=gtCubeGrid.nGridBottom) {
            INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtCubeGrid,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(GAME_IsExpansion()) {
                left=gtBigBankGrid.nGridLeft;right=gtBigBankGrid.nGridRight;top=gtBigBankGrid.nGridTop;bottom=gtBigBankGrid.nGridBottom;
            }
            else {
                left=gtBankGrid.nGridLeft;right=gtBankGrid.nGridRight;top=gtBankGrid.nGridTop;bottom=gtBankGrid.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(GAME_IsExpansion()) INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBigBankGrid,4);
                else INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBankGrid,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gtTradePage2Grid.nGridLeft && x<=gtTradePage2Grid.nGridRight && y>=gtTradePage2Grid.nGridTop && y<=gtTradePage2Grid.nGridBottom) {
            int result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtTradePage2Grid,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    sub_00486E60_ClickOutsidePanel(y,pMsg,x);
}

struct D2PanelButtonStrc { int active,selected; unsigned short text,padA; int padC[2]; };
extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0
extern int gnButtonCount; // 0x00722160
extern int gnButtonRow; // 0x0072215C
extern int gaNpcButtonX[][4]; // 0x00722168
extern int gnTabEnabled0; // 0x0072211E
extern int gnTabEnabled1; // 0x00722130
extern int gnTabEnabled2; // 0x00722142
extern int gnTabEnabled3; // 0x00722154
extern int gdwNpcPanelDelayTick; // 0x007BCC08
extern int gnInvMouseX; // 0x007BCA4C
extern int gnInvMouseY; // 0x007BCBD8
extern int gnGlobal_007BCBB0; // 0x007BCBB0
extern int gnGlobal_007BCBB4; // 0x007BCBB4
extern int gnGlobal_007BCBB8; // 0x007BCBB8
extern int gnGlobal_007BCBBC; // 0x007BCBBC
extern int gbPanelButtonClicked; // 0x007BCE9C
extern D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58
int __cdecl INV_IsNpcStateIdle(); // 0x00483E10
int __cdecl INV_ResetNpcButtons(); // 0x00487BE0
void __stdcall INV_SelectItemPageTab(unsigned char nTab); // 0x00487A10
int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc*,int,int*,Unicode*,int); // 0x004B2AD0
static inline int GetNpcTabLeft(int tab)
{
    return gnPanelOffsetX+80*tab;
}
static inline int GetNpcTabRight(int tab)
{
    return GetNpcTabLeft(tab)+80;
}
// 0x00491D20
void __stdcall sub_00491D20_HandleNpcClick(SMSGHANDLER_PARAMS* msg)
{
    const int x=msg->nXpos;
    const int y=msg->nYpos;
    if(gnInvPanelMode!=0 && gnInvPanelMode!=1 && gnInvPanelMode!=3 && gnInvPanelMode!=2 && gnInvPanelMode!=4) goto HANDLE;
    if(!AUTOMAP_IsCursorOverMiniPanelButton(msg) && sub_00486E10_IsInNpcPanelRect(x,y) && INV_IsNpcStateIdle()) {
        gbPanelButtonDown=1;msg->bReturn=1;msg->lResult=0;
        sub_004B9A00(4,0,0,0,0);
        sub_00420290_BreakHandlerChain(msg);return;
    }
    if(sub_004680A0()) {
        int nArg;
        if(AUTOMAP_IsCursorOverMiniPanelButton(msg)==1) {INV_ResetNpcButtons();return;}
        if(x<0 || x>gtPlayerInvRect.nLeft || y<0 || y>gtPlayerInvRect.nBottom) goto OUTSIDE;
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);
        if(x<gtNpcInvGrid.nGridLeft || x>gtNpcInvGrid.nGridRight || y<gtNpcInvGrid.nGridTop || y>gtNpcInvGrid.nGridBottom) return;
        if(sub_00468830()==6 || !NPCMENU_GetInteractNpcId(&nArg)) return;
        D2UnitStrc* player=CUNIT_FindClientUnit(nArg,1);
        if(!player) return;
        Unicode text[64];int cost;
        if(!NPCMENU_GetTradeCostText(sub_004680A0(),1,&cost,text,64)) return;
        const int arg=msg->wParam;
        D2UnitStrc* item=sub_004680A0();
        if(item && sub_004B3870((int)player,(int)item,1,x,y,arg,1,0)) sub_00468070_SetCursorItemState(0);
        return;
    }
    if(AUTOMAP_IsCursorOverMiniPanelButton(msg)==1) {INV_ResetNpcButtons();return;}
    msg->bReturn=0;
    if(x>=gnPanelOffsetX && x<=gnScreenWidth/2-1 && y>=gnScreenHeight + gnPanelOffsetY-0x1DF && y<=gnPanelOffsetY+gnScreenHeight-0x1C1) {
        if(x>=GetNpcTabLeft(0) && x<=GetNpcTabRight(0)) {
            if(gnTabEnabled0 && gnSelectedTab!=0) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(0);
            }
        } else if(x>=GetNpcTabLeft(1) && x<=GetNpcTabRight(1)) {
            if(gnTabEnabled1 && gnSelectedTab!=1) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(1);
            }
        } else if(x>=GetNpcTabLeft(2) && x<=GetNpcTabRight(2)) {
            if(gnTabEnabled2 && gnSelectedTab!=2) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(2);
            }
        } else if(x>GetNpcTabLeft(3) && x<GetNpcTabRight(3)) {
            if(gnTabEnabled3 && gnSelectedTab!=3) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(3);
            }
        } else {
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
    }
    if(x<gnGlobal_007BCBB0 || x>gnGlobal_007BCBB4) goto OUTSIDE;
    {
        const int top=gnScreenHeight+gnPanelOffsetY-0x6D;
        if(y>=top && y<=gnGlobal_007BCBBC) {
            int hasSelected=0;int selected=0;int clicked=-1;
            for(int i=0;i<gnButtonCount;++i) {
                if(gaPanelButtons_007BC9E0[i].selected==1) {selected=i;hasSelected=1;}
                if(gnInvMouseX>gaNpcButtonX[gnButtonRow][i]+gnPanelOffsetX && gnInvMouseX<gaNpcButtonX[gnButtonRow][i]+gnPanelOffsetX+45 && gnInvMouseY>top && gnInvMouseY<gnPanelOffsetY+gnScreenHeight-0x41) clicked=i;
            }
            if(clicked!=-1) {
                if(gaPanelButtons_007BC9E0[clicked].active==1) {
                    sub_004B9A00(1,0,0,0,0);
                    if(hasSelected==1) {
                        if(clicked==selected) {
                            gaPanelButtons_007BC9E0[clicked].selected=0;gnInvPanelMode=1;
                            if(sub_00463DD0_GetPlayerUnit()) {
                                D2InventoryStrc* inventory=sub_00463DD0_GetPlayerUnit()->pInventory;
                                if(inventory && !INVENTORY_GetCursorItem(inventory)) sub_00468070_SetCursorItemState(0);
                            }
                        } else {
                            gaPanelButtons_007BC9E0[clicked].selected=1;gaPanelButtons_007BC9E0[selected].selected=0;
                        }
                    } else gaPanelButtons_007BC9E0[clicked].selected=1;
                    gbPanelButtonClicked=1;
                } else {INV_ResetNpcButtons();gbPanelButtonClicked=0;}
            }
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
    }
    if(y<gnGlobal_007BCBB8 || y>gnGlobal_007BCBBC) goto OUTSIDE;
    {
    int nArg;
    if((gnInvPanelMode==1 || gnInvPanelMode==2) && x>=gtNpcInvGrid.nGridLeft && x<=gtNpcInvGrid.nGridRight && y>=gtNpcInvGrid.nGridTop && y<=gtNpcInvGrid.nGridBottom && NPCMENU_GetInteractNpcId(&nArg)) {
        D2UnitStrc* player=CUNIT_FindClientUnit(nArg,1);
        if(player) INV_ClickInvGrid(player,player->pInventory,x,y,msg->wParam,&gtNpcInvGrid,gnSelectedTab);
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
