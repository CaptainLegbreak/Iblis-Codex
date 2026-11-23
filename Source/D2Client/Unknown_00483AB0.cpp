#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ItemsWorld.h"

#pragma pack(push, 2)
struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    unsigned short nTextId;
    int nMode;
    unsigned short nKey;
    int nArg;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
int __cdecl GAME_IsExitPending(); // 0x0044DA30
void __cdecl sub_0044DA70();
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(int nUIVar); // 0x004538D0
void __cdecl UI_CancelCursorItemUse();
void __fastcall UI_OpenGoldPanel(int nMode);
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);
int __cdecl sub_0045AE90();
D2UnitStrc* __fastcall CUNIT_FindClientUnit(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();
int __cdecl sub_00463DF0();
void __fastcall sub_00468040(int nArg, int nArg2);
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);
D2UnitStrc* __cdecl sub_004680A0();
int __cdecl sub_00468730();
int __cdecl sub_00468740();
int __cdecl sub_00468830();
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);
void __cdecl sub_004835B0();
int __cdecl sub_004979E0();
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, void* pItemsTxt);
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId);
void __cdecl sub_004B8CB0();
void __fastcall sub_004B9070(int nArg);
void __cdecl sub_004B90B0();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
int __fastcall sub_004C1E20(D2UnitStrc* pItem, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004C21F0(D2UnitStrc* pItem);
int __fastcall sub_004C2240(D2UnitStrc* pItem);
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight);
int __cdecl D2GFX_GetResolutionMode();
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5);
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD);
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine);
int __stdcall sub_00628C20(D2UnitStrc* pItem);
int __stdcall sub_00628C70(D2UnitStrc* pItem);
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);
int __stdcall sub_0062A0A0(D2UnitStrc* pItem);
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, int nPage);
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);
void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY);
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY);
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
void __fastcall sub_004E6850(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);
int __stdcall sub_0062BEB0(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel);
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc);
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);
int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage);
int __stdcall sub_0063BB20(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8);
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);

// build: symbol _gszCmnItemsH 0x006D9B90
extern "C" const char gszCmnItemsH[];
// build: symbol _gszInvCpp 0x006D9BC0
extern "C" const char gszInvCpp[];

// build: symbol ?gnScreenWidth@* 0x0071146C
extern int gnScreenWidth;
// build: symbol ?gnScreenHeight@* 0x00711470
extern int gnScreenHeight;
extern int gnDialogState; // 0x00721E34
extern int gbHoverPlayerItem; // 0x00721E38
extern int gnHoverTopX; // 0x00721E3C
extern int gnHoverTopY; // 0x00721E40
extern int gnHoverBottomX; // 0x00721E44
extern int gnHoverBottomY; // 0x00721E48
extern int gnHoverCellX; // 0x00721E4C
extern int gnHoverCellY; // 0x00721E50
// build: symbol ?gnButtonCount@* 0x00722160
extern int gnButtonCount;
extern int gnAutomapHeight_007A521C;
// build: symbol ?gnAutomapWidth@* 0x007A5220
extern int gnAutomapWidth;
extern D2DataTablesStrc* sgptDataTables;
// build: symbol ?gnPanelOffsetX@* 0x007A2858
extern int gnPanelOffsetX;
// build: symbol ?gnPanelOffsetY@* 0x007A285C
extern int gnPanelOffsetY;
// build: symbol ?gaNpcButtons@* 0x007BC9E0
extern D2NpcButtonStrc gaNpcButtons[4];
// build: symbol ?gtTradePage2Grid@* 0x007BCA30
extern D2InventoryGridInfoStrc gtTradePage2Grid;
extern unsigned char gabColors_007BCAD8[5];
// build: symbol ?gnInvMouseX@* 0x007BCA4C
static int gnInvMouseX;
// build: symbol ?gtBigBankGrid@* 0x007BCA78
extern D2InventoryGridInfoStrc gtBigBankGrid;
extern D2InvRectStrc gtPlayerInvRect;                                                                     // 0x007BCAA0
// build: symbol ?gtTradePage1Grid@* 0x007BCB18
extern D2InventoryGridInfoStrc gtTradePage1Grid;
// build: symbol ?gtBankGrid@* 0x007BCB40
extern D2InventoryGridInfoStrc gtBankGrid;
// build: symbol ?gtNpcInvGrid@* 0x007BCB58
extern D2InventoryGridInfoStrc gtNpcInvGrid;
// build: symbol ?gtCubeGrid@* 0x007BCB70
extern D2InventoryGridInfoStrc gtCubeGrid;
// build: symbol ?gtPlayerInvGrid@* 0x007BCB88
extern D2InventoryGridInfoStrc gtPlayerInvGrid;
// build: symbol ?gtNpcInvRect@* 0x007BCBB0
extern D2InvRectStrc gtNpcInvRect;
// build: symbol ?gnInvMouseY@* 0x007BCBD8
static int gnInvMouseY;
// build: symbol ?gbHoverInGrid@* 0x007BCBE4
static int gbHoverInGrid;
// build: symbol ?gbHoverInBodyLoc@* 0x007BCBE8
static int gbHoverInBodyLoc;
// build: symbol ?gnInvPanelMode@* 0x007BCBF0
static int gnInvPanelMode;
// build: symbol ?gpHoverItem@* 0x007BCBF4
static D2UnitStrc* gpHoverItem;
// build: symbol ?gpLastHoverItem@* 0x007BCBF8
static D2UnitStrc* gpLastHoverItem;
// build: symbol ?gnSelectedTab@* 0x007BCC04
static unsigned char gnSelectedTab;
// build: symbol ?gnHoverBodyLoc@* 0x007BCC20
static int gnHoverBodyLoc;
// build: symbol ?gnSelectedShopButton@* 0x007BCC40
static int gnSelectedShopButton;
// build: symbol ?gnSelectedShopButtonKey@* 0x007BCC44
static int gnSelectedShopButtonKey;
// build: symbol ?gbCubeItemClicked@* 0x007BCC50
static int gbCubeItemClicked;
// build: symbol ?gaCompGrids@* 0x007BCC58
extern D2InvCompGridStrc gaCompGrids[11];
// build: symbol ?gbTradeAccepted@* 0x007BCE18
static int gbTradeAccepted;
// build: symbol ?gbTradeCancelClicked@* 0x007BCE1C
static int gbTradeCancelClicked;
// build: symbol ?gbTradeAcceptButtonDown@* 0x007BCE20
static int gbTradeAcceptButtonDown;
// build: symbol ?gbTradeCancelButtonDown@* 0x007BCE24
static int gbTradeCancelButtonDown;
// build: symbol ?gbGoldButtonDisabled@* 0x007BCE2C
static int gbGoldButtonDisabled;
// build: symbol ?gbInvGoldButtonDown@* 0x007BCE30
static int gbInvGoldButtonDown;
// build: symbol ?gbStashGoldButtonDown@* 0x007BCE34
static int gbStashGoldButtonDown;
// build: symbol ?gbStashButtonDown@* 0x007BCE38
static int gbStashButtonDown;
// build: symbol ?gbStashButtonClicked@* 0x007BCE3C
static int gbStashButtonClicked;
// build: symbol ?gbPanelButtonDown@* 0x007BCE90
static int gbPanelButtonDown;
static int gnGlobal_007BCE94;
// build: symbol ?gbPanelButtonClicked@* 0x007BCE9C
static int gbPanelButtonClicked;

// 0x00483AB0
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
{
    if (nX > gtTradePage1Grid.nGridLeft && nX < gtTradePage1Grid.nGridRight && nY >= gtTradePage1Grid.nGridTop && nY <= gtTradePage1Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B10_IsInGrid7BCA30(int nX, int nY)
{
    if (nX > gtTradePage2Grid.nGridLeft && nX < gtTradePage2Grid.nGridRight && nY >= gtTradePage2Grid.nGridTop && nY <= gtTradePage2Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B40_IsInCubeGrid(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX > gtBigBankGrid.nGridLeft && nX <= gtBigBankGrid.nGridRight && nY >= gtBigBankGrid.nGridTop && nY <= gtBigBankGrid.nGridBottom)
        {
            return 1;
        }
        return 0;
    }
    if (nX > gtBankGrid.nGridLeft && nX <= gtBankGrid.nGridRight && nY >= gtBankGrid.nGridTop && nY <= gtBankGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BF0_IsInGrid7BCB70(int nX, int nY)
{
    if (nX >= gtCubeGrid.nGridLeft && nX < gtCubeGrid.nGridRight && nY >= gtCubeGrid.nGridTop && nY <= gtCubeGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY)
{
    for (int y = nY; y < nY + nHeight; ++y)
    {
        for (int x = nX; x < nX + nWidth; ++x)
        {
            const int nBoxWidth = pGrid->nGridBoxWidth;
            const int nPixelX = nBoxWidth * x + pGrid->nGridLeft;
            const int nBoxHeight = pGrid->nGridBoxHeight;
            const int nPixelY = nBoxHeight * y + pGrid->nGridTop;
            if (nPixelX >= 0 && nPixelX < gnAutomapWidth && nPixelY >= 0 && nPixelY < gnAutomapHeight_007A521C)
            {
                sub_0046EFD0_DrawFramedBox(nPixelX, nPixelY, nBoxWidth, nBoxHeight, gabColors_007BCAD8[nColor], 0);
            }
        }
    }
}

static void sub_00483A70_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor)
{
    if (nColor == 2)
    {
        return;
    }
    const int nLeft = pCompGrid->rect.nLeft;
    const int nTop = pCompGrid->rect.nTop;
    if (nLeft >= 0 && nLeft < gnAutomapWidth && nTop >= 0 && nTop < gnAutomapHeight_007A521C)
    {
        sub_0046EFD0_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[nColor], 0);
    }
}

static void __stdcall sub_00483C50_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem)
{
    if (nPage == 0xFF)
    {
        return;
    }
    D2UnitStrc* pOther = 0;
    if (!pCursorItem || !gbHoverInGrid)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    if (gnHoverCellX < 0 || gnHoverCellY < 0)
    {
        return;
    }
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (gnInvPanelMode == 0x13 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &nOutX, &nOutY, nPage))
    {
        sub_004839D0_DrawGridCells(pGrid, gnHoverCellX, 1, nWidth, nHeight, gnHoverCellY);
        return;
    }
    if (!sub_0063BB20(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 1)
        && (!pOther || DATATBLS_GetItemsTxtRecord(pOther->dwClassId)->dwCode != 0x20786F62))
    {
        sub_004839D0_DrawGridCells(pGrid, gnHoverCellX, 0, nWidth, nHeight, gnHoverCellY);
        return;
    }
    unsigned char nOtherWidth;
    unsigned char nOtherHeight;
    ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, gszCmnItemsH, 0x6DC);
    sub_004839D0_DrawGridCells(pGrid, UNITS_GetXPosition(pOther), 3, nOtherWidth, nOtherHeight, CLIENTS_GetUnitY(pOther));
}

static int sub_00483F80_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 8) || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit)
{
    sub_004835B0();
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 1:
        pGrid = &gtNpcInvGrid;
        break;
    case 0:
        switch (gnSelectedTab)
        {
        case 1:
            pGrid = &gtTradePage1Grid;
            break;
        case 2:
            pGrid = &gtTradePage2Grid;
            break;
        case 4:
            pGrid = GAME_IsExpansion() ? &gtBigBankGrid : &gtBankGrid;
            break;
        case 3:
            pGrid = &gtCubeGrid;
            break;
        default:
            pGrid = &gtPlayerInvGrid;
            break;
        }
        break;
    default:
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab, GAME_IsExpansion());
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (!pItem || INVENTORY_GetItemNodePage(pNode) != 1)
        {
            continue;
        }
        int nX;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nX = PATH_GetXPosition(pItem->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        int nY;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pItem->pStaticPath->nYPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nY = PATH_GetYPosition(pItem->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab)
        {
            continue;
        }
        if (pItem == gpHoverItem && gbHoverInGrid)
        {
            if (sub_00468830() == 8 && !sub_0062A0A0(gpHoverItem))
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 0, nWidth, nHeight, nY);
            }
            else
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
            }
            sub_0046EE80_DrawCursorItem(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, gszInvCpp))
            {
                sub_00483E40(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            continue;
        }
        int nColor = 0;
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, gszInvCpp)
            && !sub_004C2240(pItem) && sub_0062A4E0_TestItem(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, gszInvCpp))
            {
                nColor = 4;
            }
            else
            {
                nColor = 2;
                D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                if (pItemsTxt->nQuest && sub_00483F80_IsUnusableQuestBook(pItemsTxt))
                {
                    nColor = 0;
                }
            }
        }
        sub_004839D0_DrawGridCells(pGrid, nX, nColor, nWidth, nHeight, nY);
        sub_0046EE80_DrawCursorItem(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
    }
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pPlayer->pInventory);
    if (!pCursorItem)
    {
        return;
    }
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    switch (gnInvPanelMode)
    {
    case 0xB:
        if (gnSelectedTab == 1)
        {
            return;
        }
        if (gnSelectedTab == 2)
        {
            if (!sub_00483B10_IsInGrid7BCA30(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xC:
    case 0xD:
        if (gnSelectedTab == 4)
        {
            if (!sub_00483B40_IsInCubeGrid(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xE:
        if (gnSelectedTab == 3)
        {
            if (!sub_00483BF0_IsInGrid7BCB70(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    default:
        if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    }
    sub_00483C50_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab, pCursorItem);
}

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
    if (!sub_0062BEB0(pSocketable))
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

static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory)
{
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (sub_00468730() < gnScreenWidth / 2)
    {
        gnHoverBodyLoc = 0;
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (!pCursorItem || !gbHoverInBodyLoc)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    int nColor;
    if ((ITEMS_CheckBodyLocation(pCursorItem, gnHoverBodyLoc) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0(), 0, 0, 0, 0))
        || sub_004843E0_CanSocketInto(INVENTORY_GetItemFromBodyLoc(pInventory, gnHoverBodyLoc), pCursorItem))
    {
        nColor = 1;
    }
    else
    {
        nColor = 0;
    }
    sub_00483A70_DrawSlotFrame(&gaCompGrids[gnHoverBodyLoc], nColor);
}

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

int __cdecl INV_GetPanelX()
{
    if (!GAME_IsExpansion())
    {
        return gnPanelOffsetX + 0x113;
    }
    return gnPanelOffsetX + 0x110;
}

int __cdecl sub_00486B00_GetPanelY()
{
    if (!GAME_IsExpansion())
    {
        return gnScreenHeight + gnPanelOffsetY - 0x41;
    }
    return gnPanelOffsetY + gnScreenHeight - 0x40;
}

static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
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

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00486E60_ClickOutsidePanel(pMsg->nYpos, pMsg, pMsg->nXpos);
}

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        if (sub_00486E10_IsInNpcPanelRect(nX, nY))
        {
            sub_00455F20(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gbInvGoldButtonDown && !gnInvPanelMode)
    {
        gbInvGoldButtonDown = 0;
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(1);
        }
    }
    sub_0044DA70();
    if (sub_00483AB0_IsInInvRect(nX, nY) && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

static void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    if (pCursorItem)
    {
        unsigned char nWidth;
        unsigned char nHeight;
        unsigned int nPixelWidth;
        unsigned int nPixelHeight;
        ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
        sub_004DBEA0(pCursorItem, 0, 0, &nPixelWidth, &nPixelHeight);
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
        if (nWidth > 1)
        {
            nCellX -= nWidth / 2;
            if (nCellX < 0)
            {
                nCellX = 0;
            }
            if (nWidth + nCellX > pGrid->nGridX)
            {
                return;
            }
        }
        if (nHeight > 1)
        {
            nCellY -= nHeight / 2;
            if (nCellY < 0)
            {
                nCellY = 0;
            }
            if (nHeight + nCellY > pGrid->nGridY)
            {
                return;
            }
        }
        gnHoverCellY = nCellY;
        gnHoverCellX = nCellX;
        gbHoverInGrid = 1;
        gpLastHoverItem = 0;
        gpHoverItem = 0;
        return;
    }

    int nOutX;
    int nOutY;
    D2UnitStrc* pItem = sub_0063BD10(pInventory, nCellX, nCellY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        gbHoverInGrid = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        unsigned char nItemWidth;
        unsigned char nItemHeight;
        ITEMS_GetDimensions(pItem, &nItemWidth, &nItemHeight, gszCmnItemsH, 0x6DC);
        const int nItemX = UNITS_GetXPosition(pItem);
        const int nItemY = CLIENTS_GetUnitY(pItem);
        const int nLeft = nItemWidth * pGrid->nGridBoxWidth / 2 + pGrid->nGridBoxWidth * nItemX + pGrid->nGridLeft;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = pGrid->nGridBoxHeight * nItemY + pGrid->nGridTop;
        gnHoverBottomY = pGrid->nGridBoxHeight * (nItemY + nItemHeight) + pGrid->nGridTop;
        return;
    }
    gbHoverInGrid = 0;
    gpLastHoverItem = 0;
    gpHoverItem = 0;
}

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gnHoverBodyLoc = nBodyLoc;
        gbHoverInBodyLoc = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        return;
    }
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc);
    if ((nBodyLoc == 4 || nBodyLoc == 5) && bTwoHanded)
    {
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!pOther)
        {
            pOther = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 5);
        }
        if (pOther && pItem && !ITEMSIsA(pOther, 0x23) && !ITEMSIsA(pItem, 0x23)
            && !ITEMSIsA(pOther, 0x1B) && !ITEMSIsA(pItem, 0x1B))
        {
            pItem = pOther;
        }
        if (pOther && !pItem && gnInvPanelMode == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gbHoverInBodyLoc = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        const int nLeft = (gaCompGrids[nBodyLoc].rect.nRight + gaCompGrids[nBodyLoc].rect.nLeft) / 2;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = gaCompGrids[nBodyLoc].rect.nTop;
        gnHoverBottomY = gaCompGrids[nBodyLoc].rect.nBottom;
        return;
    }
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnDialogState)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0();
    sub_004835B0();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && sub_00483AB0_IsInInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gtPlayerInvGrid);
            gnHoverBodyLoc = 0;
            gbHoverPlayerItem = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids[nBodyLoc].rect.nLeft && nX <= gaCompGrids[nBodyLoc].rect.nRight && nY >= gaCompGrids[nBodyLoc].rect.nTop && nY <= gaCompGrids[nBodyLoc].rect.nBottom)
            {
                INV_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gbHoverPlayerItem = 1;
                return;
            }
        }
        gnHoverBodyLoc = 0;
        pMsg->bReturn = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483AE0_IsInGrid7BCB18(nX, nY))
        {
            gnSelectedTab = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gtTradePage1Grid);
            bHandled = 1;
        }
        else if (sub_00483B10_IsInGrid7BCA30(nX, nY))
        {
            gnSelectedTab = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gtTradePage2Grid);
            bHandled = 1;
        }
        gnSelectedTab = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483B40_IsInCubeGrid(nX, nY))
        {
            gnSelectedTab = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (GAME_IsExpansion())
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBigBankGrid);
            }
            else
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBankGrid);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483BF0_IsInGrid7BCB70(nX, nY))
        {
            gnSelectedTab = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gtCubeGrid);
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (GAME_GetUIVarState(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
    gbHoverPlayerItem = 0;
}

int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    return 1;
}

int __cdecl sub_004888C0_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (sub_004680A0() && nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gnInvPanelMode && sub_004B3230_GetSelectedUnitId(&nUnitId))
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
                    {
                        INV_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gbHoverPlayerItem = 0;
                        return;
                    }
                }
            }
        }
        INV_UpdateInventoryHover(pMsg);
    }
}

static void INV_SelectButtonByKey(int nKey)
{
    gaNpcButtons[0].bActive = gaNpcButtons[0].nKey == nKey;
    gaNpcButtons[1].bActive = gaNpcButtons[1].nKey == nKey;
    gaNpcButtons[2].bActive = gaNpcButtons[2].nKey == nKey;
    gaNpcButtons[3].bActive = gaNpcButtons[3].nKey == nKey;
}

void __cdecl INV_RestoreSelectedShopButton()
{
    if (!sub_004888C0_CanUseCursor())
    {
        return;
    }
    INV_ResetNpcButtons();
    const int nButton = gnSelectedShopButton;
    if (nButton >= 0 && nButton < gnButtonCount && gaNpcButtons[nButton].nTextId != 0x276F)
    {
        INV_SelectButtonByKey(gnSelectedShopButtonKey);
        gnInvPanelMode = gaNpcButtons[nButton].nMode;
        sub_00468040(gaNpcButtons[nButton].nArg, 0);
    }
    int nUnitId;
    if (sub_004B3230_GetSelectedUnitId(&nUnitId))
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
        if (pUnit)
        {
            const int nX = sub_00468730();
            const int nY = sub_00468740();
            if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
            {
                INV_UpdateGridHover(pUnit, pUnit->pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                gbHoverPlayerItem = 0;
            }
        }
    }
}

static int INV_IsOverTradeButtonLeft(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0xDF && nX < gnPanelOffsetX + 0xFF
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTradeButtonRight(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x133
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!sub_00483B10_IsInGrid7BCA30(nX, nY))
    {
        if (INV_IsOverTradeButtonLeft(nX, nY))
        {
            if (gbTradeAccepted && gbTradeAcceptButtonDown)
            {
                sub_004B9070(0);
            }
            gbPanelButtonClicked = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (INV_IsOverTradeButtonRight(nX, nY))
        {
            if (gbTradeCancelClicked && gbTradeCancelButtonDown)
            {
                sub_004B8CB0();
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbPanelButtonClicked = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
        {
            gbTradeAcceptButtonDown = 0;
            gbTradeAccepted = 0;
            gbPanelButtonClicked = 0;
            gbTradeCancelClicked = 0;
            return;
        }
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(2);
        }
        if (gbPanelButtonClicked)
        {
            const int bFlag = gbTradeAcceptButtonDown;
            gbPanelButtonClicked = 0;
            if (bFlag)
            {
                if (gbTradeAccepted == 1)
                {
                    gbTradeAccepted = 0;
                    sub_004B90B0();
                }
            }
            else if (gbTradeCancelButtonDown && gbTradeCancelClicked)
            {
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gbTradeAccepted)
    {
        sub_004B90B0();
    }
    gbPanelButtonClicked = 0;
    gbTradeCancelClicked = 0;
    gbTradeAccepted = 0;
}

static int sub_00489920_IsOverCloseButton(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nY >= gnScreenHeight + gnPanelOffsetY - 0x1C7 && nY <= gnScreenHeight + gnPanelOffsetY - 0x1B6
            && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnScreenHeight + gnPanelOffsetY - 0x103 && nY <= gnScreenHeight + gnPanelOffsetY - 0xF2
        && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
    {
        return 1;
    }
    return 0;
}

static int sub_00489980_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > INV_GetPanelX() && nX < INV_GetPanelX() + 0x28
        && nY > sub_00486B00_GetPanelY() - 0x23 && nY < sub_00486B00_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC || gnInvPanelMode == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483B40_IsInCubeGrid(nX, nY))
        {
            INV_UpdateInventoryHover(pMsg);
            return;
        }
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    }
}

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xC && gnInvPanelMode != 0xD)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    if ((!sub_004979E0() || !AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_00455F20(0x19, 1, 0);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        if (gbStashButtonDown)
        {
            gbStashButtonDown = 0;
            sub_00455F20(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
        }
        gbStashButtonClicked = 0;
        gbPanelButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbStashButtonDown = 0;
    gbStashButtonClicked = 0;
    if (!sub_004979E0() && sub_00486DA0_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(3);
    }
    if (sub_00489920_IsOverCloseButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(4);
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    gbStashGoldButtonDown = 0;
    gbInvGoldButtonDown = 0;
    if (gbPanelButtonClicked)
    {
        const int bFlag = gbTradeAcceptButtonDown;
        gbPanelButtonClicked = 0;
        if (bFlag)
        {
            if (gbTradeAccepted == 1)
            {
                gbTradeAccepted = 0;
            }
        }
        else if (gbStashButtonClicked && gbStashButtonDown)
        {
            gbStashButtonDown = 0;
        }
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbPanelButtonClicked = 0;
    gbStashButtonDown = 0;
    gbTradeAccepted = 0;
}

static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        return 1;
    }
    return 0;
}

static void INV_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gpHoverItem, 0x35), 0xC43);
    sub_004E6850(gpHoverItem, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

static D2UnitStrc* sub_00486770_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, gszInvCpp))
        {
            const unsigned char nPage = ITEMS_GetInvPage(pItem);
            if (nPage == 0 || nPage == 3 || nPage == 4 || nPage == 0xFF)
            {
                const int nNodePage = INVENTORY_GetItemNodePage(pNode);
                if (nNodePage == 1 || nNodePage == 3 || nNodePage == 4)
                {
                    const int nFileIndex = ITEMS_GetFileIndex(pItem);
                    D2SetItemsTxt* pSetItemsTxt = (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nFileIndex] : 0;
                    if (pSetItemsTxt && pSetItemsTxt->wSetItemId == nSetItemId)
                    {
                        return pItem;
                    }
                }
            }
        }
    }
    return 0;
}

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId)
{
    for (int i = 0; i < 11; ++i)
    {
        INVENTORY_GetItemFromBodyLoc(pInventory, i);
    }
    INV_DrawBodyLocPlacement(pInventory);
    INV_AppendBookCharges(pText);
    sub_00486770_FindSetItem(pInventory, nSetItemId);
}

int __cdecl sub_E05_Emit_00486860()
{
    return sub_00486860_IsOverWeaponSwapTab(sub_00468730(), sub_00468740());
}

int __cdecl sub_E05_Emit_00489FB0(int nX, int nY)
{
    return sub_00489FB0_IsOverButtonC(nX, nY);
}
