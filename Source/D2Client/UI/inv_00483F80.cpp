#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct Unicode;
struct D2SetItemsTxt;
struct D2InvRectStrc;
struct D2InventoryGridInfoStrc;
struct D2InvCompGridStrc;
struct D2NpcButtonStrc;



struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct Unicode
{
    unsigned short wChar;
};


struct D2SetItemsTxt
{
    short wSetItemId;
    char unk0x02[0x1B6];
};


struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};


struct D2InvCompGridStrc
{
    D2InvRectStrc rect;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned short pad0x12;
};

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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0044DA30(); // 0x0044DA30
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
void __cdecl sub_00453EC0(); // 0x00453EC0
void __fastcall sub_00454150_OpenGoldPanel(int nMode); // 0x00454150
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __cdecl sub_0045AE90(); // 0x0045AE90
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00463DF0(); // 0x00463DF0
void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0
void __cdecl sub_004835B0_LoadUiRecords(); // 0x004835B0
int __cdecl sub_004979E0(); // 0x004979E0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, void* pItemsTxt); // 0x0049FF90
int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230
void __cdecl sub_004B8CB0(); // 0x004B8CB0
void __fastcall sub_004B9070(int nArg); // 0x004B9070
void __cdecl sub_004B90B0(); // 0x004B90B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004C1E20(D2UnitStrc* pItem, int nArg2, int nArg3, int nArg4); // 0x004C1E20
void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem); // 0x004C21F0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __cdecl D2GFX_GetResolutionMode(); // 0x004F5160
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD); // 0x00621050
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem); // 0x00628C70
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A0A0(D2UnitStrc* pItem); // 0x0062A0A0
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, int nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall sub_00483E40_DrawItemSockets(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0
int __stdcall sub_0063BB20_CheckInventoryOverlap(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_00721E34; // 0x00721E34
extern int gnGlobal_00721E38; // 0x00721E38
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gnButtonCount_00722160; // 0x00722160
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2NpcButtonStrc gaNpcButtons_007BC9E0[4]; // 0x007BC9E0
extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0
extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
void __stdcall sub_Z12_EmitUse(int nValue);
static __declspec(noinline) void __stdcall sub_00487000_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid);
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY); // 0x00486E10
void __cdecl sub_0048A050_CloseQuestPanel(); // 0x0048A050

static int gnGlobal_007BCA4C; // 0x007BCA4C

D2InventoryGridInfoStrc gGrid_007BCB58; // 0x007BCB58

D2InvRectStrc gRect_007BCBB0; // 0x007BCBB0

static int gnGlobal_007BCBD8; // 0x007BCBD8

static int gdwGlobal_007BCBE4; // 0x007BCBE4

static int gdwGlobal_007BCBE8; // 0x007BCBE8

static int gdwGlobal_007BCBF0; // 0x007BCBF0

static D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4

static D2UnitStrc* gdwGlobal_007BCBF8; // 0x007BCBF8

static unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

static int gnGlobal_007BCC20; // 0x007BCC20

static int gnGlobal_007BCC40; // 0x007BCC40

static int gnGlobal_007BCC44; // 0x007BCC44

static int gnGlobal_007BCC50; // 0x007BCC50

static int gnGlobal_007BCE18; // 0x007BCE18

static int gnGlobal_007BCE1C; // 0x007BCE1C

static int gnGlobal_007BCE20; // 0x007BCE20

static int gnGlobal_007BCE24; // 0x007BCE24

static int gnGlobal_007BCE2C; // 0x007BCE2C

static int gnGlobal_007BCE30; // 0x007BCE30

static int gnGlobal_007BCE34; // 0x007BCE34

static int gnGlobal_007BCE38; // 0x007BCE38

static int gnGlobal_007BCE3C; // 0x007BCE3C

static int gbGlobal_007BCE90; // 0x007BCE90

static int gnGlobal_007BCE94; // 0x007BCE94

static int gnGlobal_007BCE9C; // 0x007BCE9C

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gInvRect_007BCAA0.nLeft && nX < gInvRect_007BCAA0.nRight && nY >= gInvRect_007BCAA0.nTop && nY <= gInvRect_007BCAA0.nBottom)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
{
    if (nX > gGrid_007BCB18.nGridLeft && nX < gGrid_007BCB18.nGridRight && nY >= gGrid_007BCB18.nGridTop && nY <= gGrid_007BCB18.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B10_IsInGrid7BCA30(int nX, int nY)
{
    if (nX > gGrid_007BCA30.nGridLeft && nX < gGrid_007BCA30.nGridRight && nY >= gGrid_007BCA30.nGridTop && nY <= gGrid_007BCA30.nGridBottom)
    {
        return 1;
    }
    return 0;
}

// 0x00483B40
static int sub_00483B40_IsInCubeGrid(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gGrid_007BCA78.nGridLeft && nX <= gGrid_007BCA78.nGridRight && nY >= gGrid_007BCA78.nGridTop && nY <= gGrid_007BCA78.nGridBottom)
        {
            return 1;
        }
        return 0;
    }
    if (nX > gGrid_007BCB40.nGridLeft && nX <= gGrid_007BCB40.nGridRight && nY >= gGrid_007BCB40.nGridTop && nY <= gGrid_007BCB40.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483BF0_IsInGrid7BCB70(int nX, int nY)
{
    if (nX >= gGrid_007BCB70.nGridLeft && nX < gGrid_007BCB70.nGridRight && nY >= gGrid_007BCB70.nGridTop && nY <= gGrid_007BCB70.nGridBottom)
    {
        return 1;
    }
    return 0;
}

// build: context sub_004839D0_DrawGridCells
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
            if (nPixelX >= 0 && nPixelX < gnAutomapWidth_007A5220 && nPixelY >= 0 && nPixelY < gnAutomapHeight_007A521C)
            {
                sub_0046EFD0_DrawFramedBox(nPixelX, nPixelY, nBoxWidth, nBoxHeight, gabColors_007BCAD8[nColor], 0);
            }
        }
    }
}

// build: context sub_00483A70_DrawSlotFrame
static void sub_00483A70_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor)
{
    if (nColor == 2)
    {
        return;
    }
    const int nLeft = pCompGrid->rect.nLeft;
    const int nTop = pCompGrid->rect.nTop;
    if (nLeft >= 0 && nLeft < gnAutomapWidth_007A5220 && nTop >= 0 && nTop < gnAutomapHeight_007A521C)
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
    if (!pCursorItem || !gdwGlobal_007BCBE4)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    if (gnGlobal_00721E4C < 0 || gnGlobal_00721E50 < 0)
    {
        return;
    }
    if (gdwGlobal_007BCBF0 == 1 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    if (gdwGlobal_007BCBF0 == 0x13 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &nOutX, &nOutY, nPage))
    {
        sub_004839D0_DrawGridCells(pGrid, gnGlobal_00721E4C, 1, nWidth, nHeight, gnGlobal_00721E50);
        return;
    }
    if (!sub_0063BB20_CheckInventoryOverlap(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pOther, nPage, 1)
        && (!pOther || DATATBLS_GetItemsTxtRecord(pOther->dwClassId)->dwCode != 0x20786F62))
    {
        sub_004839D0_DrawGridCells(pGrid, gnGlobal_00721E4C, 0, nWidth, nHeight, gnGlobal_00721E50);
        return;
    }
    unsigned char nOtherWidth;
    unsigned char nOtherHeight;
    ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004839D0_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), 3, nOtherWidth, nOtherHeight, CLIENTS_GetUnitY(pOther));
}

// 0x00483F80
static int sub_00483F80_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x25, 8) || QUESTRECORD_GetQuestState(sub_004B32D0(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall sub_00483FF0_DrawUnitInventory(D2UnitStrc* pUnit)
{
    sub_004835B0_LoadUiRecords();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    switch (nType)
    {
    case 1:
        pGrid = &gGrid_007BCB58;
        break;
    case 0:
        switch (gnSelectedTab_007BCC04)
        {
        case 1:
            pGrid = &gGrid_007BCB18;
            break;
        case 2:
            pGrid = &gGrid_007BCA30;
            break;
        case 4:
            pGrid = sub_0044DCC0() ? &gGrid_007BCA78 : &gGrid_007BCB40;
            break;
        case 3:
            pGrid = &gGrid_007BCB70;
            break;
        default:
            pGrid = &gGrid_007BCB88;
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
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab_007BCC04, sub_0044DCC0());
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
        case 2:
        case 4:
        case 5:
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
        case 2:
        case 4:
        case 5:
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
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab_007BCC04)
        {
            continue;
        }
        if (pItem == gdwGlobal_007BCBF4 && gdwGlobal_007BCBE4)
        {
            if (sub_00468830() == 8 && !sub_0062A0A0(gdwGlobal_007BCBF4))
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 0, nWidth, nHeight, nY);
            }
            else
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
            }
            sub_0046EE80_DrawCursorItem(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && sub_0062BC20(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, ".\\UI\\inv.cpp"))
            {
                sub_00483E40_DrawItemSockets(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            continue;
        }
        int nColor = 0;
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, ".\\UI\\inv.cpp")
            && !sub_004C2240(pItem) && ITEMS_CanBeEquipped(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, ".\\UI\\inv.cpp"))
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
    if (pUnit->dwUnitType == 1)
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
    switch (gdwGlobal_007BCBF0)
    {
    case 0xB:
        if (gnSelectedTab_007BCC04 == 1)
        {
            return;
        }
        if (gnSelectedTab_007BCC04 == 2)
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
        if (gnSelectedTab_007BCC04 == 4)
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
        if (gnSelectedTab_007BCC04 == 3)
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
    sub_00483C50_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab_007BCC04, pCursorItem);
}

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
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
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

// build: context sub_004844A0_DrawBodyLocPlacement
static void sub_004844A0_DrawBodyLocPlacement(D2InventoryStrc* pInventory)
{
    if (gdwGlobal_007BCBF0 == 1 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    if (sub_00468730() < gnGlobal_0071146C / 2)
    {
        gnGlobal_007BCC20 = 0;
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (!pCursorItem || !gdwGlobal_007BCBE8)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    int nColor;
    if ((ITEMS_CheckBodyLocation(pCursorItem, gnGlobal_007BCC20) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0_GetPlayerUnit(), 0, 0, 0, 0))
        || sub_004843E0_CanSocketInto(INVENTORY_GetItemFromBodyLoc(pInventory, gnGlobal_007BCC20), pCursorItem))
    {
        nColor = 1;
    }
    else
    {
        nColor = 0;
    }
    sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[gnGlobal_007BCC20], nColor);
}

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

int __cdecl sub_00486AE0_GetPanelX()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_007A2858 + 0x113;
    }
    return gnGlobal_007A2858 + 0x110;
}

int __cdecl sub_00486B00_GetPanelY()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x41;
    }
    return gnGlobal_007A285C + gnGlobal_00711470 - 0x40;
}

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

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00486E60_ClickOutsidePanel(pMsg->nYpos, pMsg, pMsg->nXpos);
}

// 0x00486EF0
void __stdcall sub_00486EF0_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_00498DC0_MouseMoveMsg(pMsg))
    {
        if (sub_00486E10_IsInNpcPanelRect(nX, nY))
        {
            sub_00455F20(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gnGlobal_007BCE30 && !gdwGlobal_007BCBF0)
    {
        gnGlobal_007BCE30 = 0;
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
        {
            sub_00454150_OpenGoldPanel(1);
        }
    }
    sub_0044DA70();
    if (sub_00483AB0_IsInInvRect(nX, nY) && !sub_00498DC0_MouseMoveMsg(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00487230
static void __stdcall sub_00487230_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gnGlobal_007BCC20 = nBodyLoc;
        gdwGlobal_007BCBE8 = 1;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
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
        if (pOther && !pItem && gdwGlobal_007BCBF0 == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gdwGlobal_007BCBE8 = 1;
        if (pItem == gdwGlobal_007BCBF8)
        {
            return;
        }
        const int nLeft = (gaCompGrids_007BCC58[nBodyLoc].rect.nRight + gaCompGrids_007BCC58[nBodyLoc].rect.nLeft) / 2;
        gnGlobal_00721E3C = nLeft;
        gnGlobal_00721E44 = nLeft;
        gdwGlobal_007BCBF4 = pItem;
        gdwGlobal_007BCBF8 = pItem;
        gnGlobal_00721E40 = gaCompGrids_007BCC58[nBodyLoc].rect.nTop;
        gnGlobal_00721E48 = gaCompGrids_007BCC58[nBodyLoc].rect.nBottom;
        return;
    }
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

// 0x004873A0
void __stdcall sub_004873A0_HandleClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnGlobal_00721E34)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_004835B0_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00483AB0_IsInInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gGrid_007BCB88);
            gnGlobal_007BCC20 = 0;
            gnGlobal_00721E38 = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids_007BCC58[nBodyLoc].rect.nLeft && nX <= gaCompGrids_007BCC58[nBodyLoc].rect.nRight && nY >= gaCompGrids_007BCC58[nBodyLoc].rect.nTop && nY <= gaCompGrids_007BCC58[nBodyLoc].rect.nBottom)
            {
                sub_00487230_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gnGlobal_00721E38 = 1;
                return;
            }
        }
        gnGlobal_007BCC20 = 0;
        pMsg->bReturn = 0;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483AE0_IsInGrid7BCB18(nX, nY))
        {
            gnSelectedTab_007BCC04 = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gGrid_007BCB18);
            bHandled = 1;
        }
        else if (sub_00483B10_IsInGrid7BCA30(nX, nY))
        {
            gnSelectedTab_007BCC04 = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gGrid_007BCA30);
            bHandled = 1;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483B40_IsInCubeGrid(nX, nY))
        {
            gnSelectedTab_007BCC04 = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (sub_0044DCC0())
            {
                sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gGrid_007BCA78);
            }
            else
            {
                sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gGrid_007BCB40);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483BF0_IsInGrid7BCB70(nX, nY))
        {
            gnSelectedTab_007BCC04 = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gGrid_007BCB70);
        }
        else
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (sub_004538D0(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
    gnGlobal_00721E38 = 0;
}

// 0x00487BE0
int __cdecl sub_00487BE0_ResetButtons()
{
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
    return 1;
}

// 0x004888C0
int __cdecl sub_004888C0_CanUseCursor()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4 || gdwGlobal_007BCBF0 == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
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

// 0x004889D0
void __stdcall sub_004889D0_TradeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0 || gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnGlobal_007BCA4C = nX;
        gnGlobal_007BCBD8 = nY;
        if (sub_004680A0() && nX >= gRect_007BCBB0.nLeft && nX <= gRect_007BCBB0.nRight && nY >= gRect_007BCBB0.nTop && nY <= gRect_007BCBB0.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gdwGlobal_007BCBF0 && sub_004B3230_GetTickPair(&nUnitId))
        {
            D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gRect_007BCBB0.nLeft && nX <= gRect_007BCBB0.nRight && nY >= gRect_007BCBB0.nTop && nY <= gRect_007BCBB0.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gGrid_007BCB58.nGridLeft && nX <= gGrid_007BCB58.nGridRight && nY >= gGrid_007BCB58.nGridTop && nY <= gGrid_007BCB58.nGridBottom)
                    {
                        sub_00487000_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab_007BCC04, &gGrid_007BCB58);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gnGlobal_00721E38 = 0;
                        return;
                    }
                }
            }
        }
        sub_004873A0_HandleClick(pMsg);
    }
}

// 0x00488E10
static void sub_00488E10_SelectButtonByKey(int nKey)
{
    gaNpcButtons_007BC9E0[0].bActive = gaNpcButtons_007BC9E0[0].nKey == nKey;
    gaNpcButtons_007BC9E0[1].bActive = gaNpcButtons_007BC9E0[1].nKey == nKey;
    gaNpcButtons_007BC9E0[2].bActive = gaNpcButtons_007BC9E0[2].nKey == nKey;
    gaNpcButtons_007BC9E0[3].bActive = gaNpcButtons_007BC9E0[3].nKey == nKey;
}

// build: context sub_00488F10_OpenTradeFromButton
void __cdecl sub_00488F10_OpenTradeFromButton()
{
    if (!sub_004888C0_CanUseCursor())
    {
        return;
    }
    sub_00487BE0_ResetButtons();
    const int nButton = gnGlobal_007BCC40;
    if (nButton >= 0 && nButton < gnButtonCount_00722160 && gaNpcButtons_007BC9E0[nButton].nTextId != 0x276F)
    {
        sub_00488E10_SelectButtonByKey(gnGlobal_007BCC44);
        gdwGlobal_007BCBF0 = gaNpcButtons_007BC9E0[nButton].nMode;
        sub_00468040(gaNpcButtons_007BC9E0[nButton].nArg, 0);
    }
    int nUnitId;
    if (sub_004B3230_GetTickPair(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            const int nX = sub_00468730();
            const int nY = sub_00468740();
            if (nX >= gGrid_007BCB58.nGridLeft && nX <= gGrid_007BCB58.nGridRight && nY >= gGrid_007BCB58.nGridTop && nY <= gGrid_007BCB58.nGridBottom)
            {
                sub_00487000_UpdateGridHover(pUnit, pUnit->pInventory, 0, nX, nY, gnSelectedTab_007BCC04, &gGrid_007BCB58);
                gnGlobal_00721E38 = 0;
            }
        }
    }
}

// 0x00489430
static int sub_00489430_IsOverButtonA(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0xDF && nX < gnGlobal_007A2858 + 0xFF
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00489480
static int sub_00489480_IsOverButtonB(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x133
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00489580
void __stdcall sub_00489580_StashMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xB)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!sub_00483B10_IsInGrid7BCA30(nX, nY))
    {
        if (sub_00489430_IsOverButtonA(nX, nY))
        {
            if (gnGlobal_007BCE18 && gnGlobal_007BCE20)
            {
                sub_004B9070(0);
            }
            gnGlobal_007BCE9C = 0;
            gnGlobal_007BCE20 = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (sub_00489480_IsOverButtonB(nX, nY))
        {
            if (gnGlobal_007BCE1C && gnGlobal_007BCE24)
            {
                sub_004B8CB0();
                gnGlobal_007BCE1C = 0;
            }
            gnGlobal_007BCE24 = 0;
            gnGlobal_007BCE9C = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
        {
            gnGlobal_007BCE20 = 0;
            gnGlobal_007BCE18 = 0;
            gnGlobal_007BCE9C = 0;
            gnGlobal_007BCE1C = 0;
            return;
        }
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
        {
            sub_00454150_OpenGoldPanel(2);
        }
        if (gnGlobal_007BCE9C)
        {
            const int bFlag = gnGlobal_007BCE20;
            gnGlobal_007BCE9C = 0;
            if (bFlag)
            {
                if (gnGlobal_007BCE18 == 1)
                {
                    gnGlobal_007BCE18 = 0;
                    sub_004B90B0();
                }
            }
            else if (gnGlobal_007BCE24 && gnGlobal_007BCE1C)
            {
                gnGlobal_007BCE1C = 0;
            }
            gnGlobal_007BCE24 = 0;
            gnGlobal_007BCE20 = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gnGlobal_007BCE18)
    {
        sub_004B90B0();
    }
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE1C = 0;
    gnGlobal_007BCE18 = 0;
}

// 0x00489920
static int sub_00489920_IsOverCloseButton(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x1C7 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6
            && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x103 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0xF2
        && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
    {
        return 1;
    }
    return 0;
}

// 0x00489980
static int sub_00489980_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > sub_00486AE0_GetPanelX() && nX < sub_00486AE0_GetPanelX() + 0x28
        && nY > sub_00486B00_GetPanelY() - 0x23 && nY < sub_00486B00_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00489A30
void __stdcall sub_00489A30_CubeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xC || gdwGlobal_007BCBF0 == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnGlobal_007BCA4C = nX;
        gnGlobal_007BCBD8 = nY;
        if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483B40_IsInCubeGrid(nX, nY))
        {
            sub_004873A0_HandleClick(pMsg);
            return;
        }
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    }
}

// 0x00489AC0
void __stdcall sub_00489AC0_CubeClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xC && gdwGlobal_007BCBF0 != 0xD)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if ((!sub_004979E0() || !sub_00498DC0_MouseMoveMsg(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_00455F20(0x19, 1, 0);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        if (gnGlobal_007BCE38)
        {
            gnGlobal_007BCE38 = 0;
            sub_00455F20(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
        }
        gnGlobal_007BCE3C = 0;
        gnGlobal_007BCE9C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gnGlobal_007BCE38 = 0;
    gnGlobal_007BCE3C = 0;
    if (!sub_004979E0() && sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(3);
    }
    if (sub_00489920_IsOverCloseButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(4);
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    gnGlobal_007BCE34 = 0;
    gnGlobal_007BCE30 = 0;
    if (gnGlobal_007BCE9C)
    {
        const int bFlag = gnGlobal_007BCE20;
        gnGlobal_007BCE9C = 0;
        if (bFlag)
        {
            if (gnGlobal_007BCE18 == 1)
            {
                gnGlobal_007BCE18 = 0;
            }
        }
        else if (gnGlobal_007BCE3C && gnGlobal_007BCE38)
        {
            gnGlobal_007BCE38 = 0;
        }
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE38 = 0;
    gnGlobal_007BCE18 = 0;
}

// 0x00489FB0
static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        return 1;
    }
    return 0;
}

// 0x004865D0
static void sub_004865D0_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gdwGlobal_007BCBF4, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gdwGlobal_007BCBF4, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

// 0x00486770
static D2UnitStrc* sub_00486770_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == 5 && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
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

// build: context sub_E05_Emit_004844A0
void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId)
{
    for (int i = 0; i < 11; ++i)
    {
        INVENTORY_GetItemFromBodyLoc(pInventory, i);
    }
    sub_004844A0_DrawBodyLocPlacement(pInventory);
    sub_004865D0_AppendBookCharges(pText);
    sub_00486770_FindSetItem(pInventory, nSetItemId);
}

// build: context sub_E05_Emit_00486860
int __cdecl sub_E05_Emit_00486860()
{
    return sub_00486860_IsOverWeaponSwapTab(sub_00468730(), sub_00468740());
}

// build: context sub_E05_Emit_00489FB0
int __cdecl sub_E05_Emit_00489FB0(int nX, int nY)
{
    return sub_00489FB0_IsOverButtonC(nX, nY);
}

#include "gen/data/Source/D2Client/UI/inv_00483F80.inc"

// 0x00486820
static int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// build: context sub_Z12_EmitIsMouseInBox
void __fastcall sub_Z12_EmitIsMouseInBox(int nX, int nY)
{
    sub_Z12_EmitUse(sub_00486820_IsMouseInBox(nX + 0x31, nY - 0x27, 0x23, 0x25));
}

// 0x00487000
static void __stdcall sub_00487000_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    if (pCursorItem)
    {
        unsigned char nWidth;
        unsigned char nHeight;
        unsigned int nPixelWidth;
        unsigned int nPixelHeight;
        ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
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
        gnGlobal_00721E50 = nCellY;
        gnGlobal_00721E4C = nCellX;
        gdwGlobal_007BCBE4 = 1;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        return;
    }

    int nOutX;
    int nOutY;
    D2UnitStrc* pItem = sub_0063BD10(pInventory, nCellX, nCellY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        gdwGlobal_007BCBE4 = 1;
        if (pItem == gdwGlobal_007BCBF8)
        {
            return;
        }
        unsigned char nItemWidth;
        unsigned char nItemHeight;
        ITEMS_GetDimensions(pItem, &nItemWidth, &nItemHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        const int nItemX = CLIENTS_GetUnitX(pItem);
        const int nItemY = CLIENTS_GetUnitY(pItem);
        const int nLeft = nItemWidth * pGrid->nGridBoxWidth / 2 + pGrid->nGridBoxWidth * nItemX + pGrid->nGridLeft;
        const int nBoxHeight = pGrid->nGridBoxHeight;
        const int nGridTop = pGrid->nGridTop;
        gnGlobal_00721E3C = nLeft;
        gnGlobal_00721E44 = nLeft;
        gdwGlobal_007BCBF4 = pItem;
        gdwGlobal_007BCBF8 = pItem;
        gnGlobal_00721E40 = nBoxHeight * nItemY + nGridTop;
        gnGlobal_00721E48 = nBoxHeight * (nItemY + nItemHeight) + nGridTop;
        return;
    }
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

int __fastcall sub_E19_Emit_00487000(D2UnitStrc* pPlayer, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    sub_00487000_UpdateGridHover(pPlayer, pPlayer->pInventory, pCursorItem, nX, nY, nPage, pGrid);
    return gnGlobal_00721E3C + gnGlobal_00721E40 + gnGlobal_00721E44 + gnGlobal_00721E48 + gnGlobal_00721E4C + gnGlobal_00721E50
        + gdwGlobal_007BCBE4 + (gdwGlobal_007BCBF4 == gdwGlobal_007BCBF8);
}

static int gnGlobal_007BCE40; // 0x007BCE40

static int gnGlobal_007BCE44; // 0x007BCE44

static int gnGlobal_007BCE48; // 0x007BCE48

static int gnGlobal_007BCE4C; // 0x007BCE4C

// 0x0048A000
static int sub_0048A000_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x90 && nX < gnGlobal_007A2858 + 0xB8
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0xDF && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x0048A190
void __stdcall sub_0048A190_CubeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xE)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_004979E0() && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_00455F20(0x1A, 1, 0);
        return;
    }
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        if (gnGlobal_007BCE40)
        {
            gnGlobal_007BCE40 = 0;
            sub_0048A050_CloseQuestPanel();
        }
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE44 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_0048A000_IsOverCubeButton(nX, nY))
    {
        if (gnGlobal_007BCE48)
        {
            gnGlobal_007BCE48 = 0;
            sub_00478600_SendShorts(0x4F, 0x18, 0, 0);
        }
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE9C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gnGlobal_007BCE40 = 0;
    gnGlobal_007BCE44 = 0;
    gnGlobal_007BCE48 = 0;
    gnGlobal_007BCE4C = 0;
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE4C = 0;
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(1);
    }
    gnGlobal_007BCE30 = 0;
    if (gnGlobal_007BCE9C)
    {
        const int bFlag = gnGlobal_007BCE20;
        gnGlobal_007BCE9C = 0;
        if (bFlag)
        {
            if (gnGlobal_007BCE18)
                gnGlobal_007BCE18 = 0;
        }
        else if (gnGlobal_007BCE44)
        {
            if (gnGlobal_007BCE40)
                gnGlobal_007BCE40 = 0;
        }
        else if (gnGlobal_007BCE4C && gnGlobal_007BCE48)
        {
            gnGlobal_007BCE48 = 0;
        }
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE44 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE40 = 0;
    gnGlobal_007BCE48 = 0;
    gnGlobal_007BCE18 = 0;
}
