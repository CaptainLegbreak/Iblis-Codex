#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Unicode.h"

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170

Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0

void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern int gnGlobal_00721E38; // 0x00721E38

extern int gnGlobal_00721E3C; // 0x00721E3C

extern int gnGlobal_00721E40; // 0x00721E40

extern int gnGlobal_00721E44; // 0x00721E44

extern int gnGlobal_00721E48; // 0x00721E48

static int gdwGlobal_007BCBF0; // 0x007BCBF0

static D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4

struct D2InventoryStrc;

struct D2BitBufferStrc;

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

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0

int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0

int __stdcall sub_0063BB20_CheckInventoryOverlap(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern int gnGlobal_00721E4C; // 0x00721E4C

extern int gnGlobal_00721E50; // 0x00721E50

D2InventoryGridInfoStrc gGrid_007BCB88;        // 0x007BCB88

static int gnGlobal_007BCBEC; // 0x007BCBEC

static unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

int __cdecl sub_00486B30_IsNpcStateA(); // 0x00486B30




static int __stdcall sub_0048FFE0_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);

struct SMSGHANDLER_PARAMS { void* hWnd; unsigned int uMessage,wParam; unsigned short nXpos,nYpos; unsigned int dwCommandSource,dwArg; int bReturn,lResult; };

struct D2InvRectStrc { int nLeft,nRight,nTop,nBottom; };

struct D2InvCompGridStrc { D2InvRectStrc rect; unsigned char nWidth,nHeight; unsigned short pad12; };

extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58

D2InventoryGridInfoStrc gGrid_007BCA30;        // 0x007BCA30

D2InventoryGridInfoStrc gGrid_007BCA78;        // 0x007BCA78

D2InventoryGridInfoStrc gGrid_007BCB40;        // 0x007BCB40

D2InventoryGridInfoStrc gGrid_007BCB70;        // 0x007BCB70

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

static int gdwGlobal_007BCBE4; // 0x007BCBE4

static int gdwGlobal_007BCBE8; // 0x007BCBE8

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

__declspec(noinline) int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);


__declspec(noinline) static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY);


__declspec(noinline) static int sub_00486DA0_IsOverGoldButton(int nX, int nY);


__declspec(noinline) int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY);


__declspec(noinline) static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX);


static void __stdcall sub_00486100_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, 0x46, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x0048CEA0
static void __stdcall sub_0048CEA0_AppendItemSetName(const Unicode* pSource, Unicode* pText)
{
    Unicode wszName[0x40] = { 0 };
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gdwGlobal_007BCBF0 == 4 && ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        Unicode wszLabel[0x80];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(wszLabel, 1));
    }

    int nSetIndex;
    if (sub_004B2AD0_GetTradeCostText(gdwGlobal_007BCBF4, gnGlobal_00721E38, &nSetIndex, wszName, 0x40))
    {
        if (wszName[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, wszName);
        return;
    }

    if (gdwGlobal_007BCBF0 != 4)
    {
        Unicode wszLabel[0x40];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(wszLabel, 1));
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048CFF0
void __cdecl sub_0048CFF0_DrawStackTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(gdwGlobal_007BCBF4 && ITEMS_GetItemType(gdwGlobal_007BCBF4) == 0x12, 0xCF1);
    D2_ASSERT(DATATBLS_GetItemsTxtRecord(!gdwGlobal_007BCBF4 ? -1 : gdwGlobal_007BCBF4->dwClassId), 0xCF5);

    sub_00486100_AppendStackQuantity(gdwGlobal_007BCBF4, wszText);
    if (gdwGlobal_007BCBF0 == 0)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89B));
        sub_00526700(wszText, pColorEnd);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89E));
        sub_00526700(wszText, pColorEnd);
    }

    Unicode wszLine[0x80];
    sub_0048C060_BuildItemName(gdwGlobal_007BCBF4, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400];
    if (gdwGlobal_007BCBF0 >= 1 && gdwGlobal_007BCBF0 <= 9)
    {
        sub_0048CEA0_AppendItemSetName(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnGlobal_00721E40 - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnGlobal_00721E3C, gnGlobal_00721E40, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnGlobal_00721E44, gnGlobal_00721E48 + nHeight, 0, 0);
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048DB80
void __cdecl sub_0048DB80_DrawBaseItemTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (!ITEMS_GetTransmogrify(gdwGlobal_007BCBF4))
    {
        return;
    }

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gdwGlobal_007BCBF4 ? -1 : gdwGlobal_007BCBF4->dwClassId);
    D2_ASSERT(pItemsTxt, 0xE61);
    int nItemId = 0;
    D2ItemsTxt* pBaseTxt = DATATBLS_GetItemRecordFromItemCode(pItemsTxt->dwTransmogrifyType, &nItemId);
    D2_ASSERT(pBaseTxt, 0xE64);

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(pBaseTxt->wNameStr));
    sub_00526700(wszText, pColorEnd);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_00526700(wszText, pColorEnd);

    Unicode wszLine[0x80];
    sub_0048C060_BuildItemName(gdwGlobal_007BCBF4, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400] = { 0 };
    if ((unsigned int)(gdwGlobal_007BCBF0 - 1) <= 8)
    {
        sub_0048CEA0_AppendItemSetName(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnGlobal_00721E40 - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnGlobal_00721E3C, gnGlobal_00721E40, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnGlobal_00721E44, gnGlobal_00721E48 + nHeight, 0, 0);
    }
}

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

int __stdcall sub_19F4_Emit_0048FFE0(D2UnitStrc* pUnit, unsigned int nX, unsigned int nY, int nFlags)
{
    return sub_0048FFE0_ClickInvGrid(pUnit, pUnit->pInventory, nX, nY, nFlags, &gGrid_007BCB88, gnSelectedTab_007BCC04);
}

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gInvRect_007BCAA0.nLeft && nX < gInvRect_007BCAA0.nRight && nY >= gInvRect_007BCAA0.nTop && nY <= gInvRect_007BCAA0.nBottom)
    {
        return 1;
    }
    return 0;
}

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

#include "gen/data/Source/D2Client/UI/inv_0048CEA0.inc"
