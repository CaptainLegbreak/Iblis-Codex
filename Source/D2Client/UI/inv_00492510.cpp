#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"

struct D2UnitStrc;

extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78

extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40

extern D2InventoryGridInfoStrc gGrid_007BCB88;                                                              // 0x007BCB88

static int gdwGlobal_007BCBE4;

extern int gnGlobal_007BCC50;                                                                               // 0x007BCC50

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                          // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __cdecl sub_00486D10_CheckTick();                                                                      // 0x00486D10

void __fastcall sub_0049FF90_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt);                            // 0x0049FF90

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                  // 0x004B9A00

int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem);                                                            // 0x004C1E20

void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem);                                                           // 0x004C21F0

int __fastcall sub_004C2240(D2UnitStrc* pItem);                                                            // 0x004C2240

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                             // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem);                                                             // 0x00628C70

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                             // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                // 0x0063C1E0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                 // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                 // 0x00648900

extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)

#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)

#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)

#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)

static int gdwGlobal_007BCBF0; // 0x007BCBF0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30

void __cdecl sub_00453EC0();                                                                                // 0x00453EC0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0

int __cdecl sub_00468830();                                                                                 // 0x00468830

void __cdecl sub_004835B0_LoadUiRecords();                                                                                // 0x004835B0

int __cdecl sub_00487BE0_ResetButtons();                                                                    // 0x00487BE0

int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

struct D2InvRectStrc;

int __cdecl sub_0045AE90();

D2UnitStrc* __cdecl sub_00463DD0();

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);

void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg);

int __cdecl sub_004979E0();

int __cdecl D2GFX_GetResolutionMode();

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern int gnGlobal_007BCA68;

extern int gnGlobal_007BCA6C;

extern int gnGlobal_007BCA74;

extern int gnGlobal_007BCA7C;

extern int gnGlobal_007BCA80;

extern int gnGlobal_007BCA84;

extern int gnGlobal_007BCA88;

extern int gnGlobal_007BCAF4;

extern int gnGlobal_007BCAF8;

extern int gnGlobal_007BCB00;

extern int gnGlobal_007BCB44;

extern int gnGlobal_007BCB48;

extern int gnGlobal_007BCB4C;

extern int gnGlobal_007BCB50;

int __cdecl sub_004680A0(); // 0x004680A0

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

extern D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30

extern int gnGlobal_007BCB74;

extern int gnGlobal_007BCB78;

extern int gnGlobal_007BCB7C;

extern int gnGlobal_007BCB80;

static int gnGlobal_007BCA4C; // 0x007BCA4C

static int gnGlobal_007BCBD8; // 0x007BCBD8

static int gdwGlobal_007BCBE8;

static int gnGlobal_007BCE18; // 0x007BCE18

static int gnGlobal_007BCE20; // 0x007BCE20

static int gnGlobal_007BCE30; // 0x007BCE30

static int gnGlobal_007BCE34; // 0x007BCE34

static int gnGlobal_007BCE38; // 0x007BCE38

static int gnGlobal_007BCE3C; // 0x007BCE3C

static int gbGlobal_007BCE90; // 0x007BCE90

static int gnGlobal_007BCE9C; // 0x007BCE9C

static int gnGlobal_007BCE40; // 0x007BCE40

static int gnGlobal_007BCE44; // 0x007BCE44

static int gnGlobal_007BCE48; // 0x007BCE48

static int gnGlobal_007BCE4C; // 0x007BCE4C

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gGrid_007BCB88.nGridLeft) / gGrid_007BCB88.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB88.nGridTop) / gGrid_007BCB88.nGridBoxHeight;
    }
    else if (sub_0044DCC0())
    {
        nGridX = (nX - gGrid_007BCA78.nGridLeft) / gGrid_007BCA78.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCA78.nGridTop) / gGrid_007BCA78.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gGrid_007BCB40.nGridLeft) / gGrid_007BCB40.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB40.nGridTop) / gGrid_007BCB40.nGridBoxHeight;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && ITEMS_GetTransmogrify(pItem))
        {
            if (!sub_004C2240(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0_SetState36(pItem);
                return 1;
            }
        }
        else if (ITEMS_CheckIfUseable(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
            {
                if (sub_004538D0(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gnGlobal_007BCC50 = 1;
                }

                sub_004786D0_SendDwords3(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0_SetState36(pItem);
                sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
                gdwGlobal_007BCBE4 = 0;
                return 1;
            }
        }
        else if (ITEMS_GetUniqueColumnFromItemsTxt(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                sub_0049FF90_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x004917C0
void __stdcall sub_004917C0_OnGridClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPlayer;
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_004835B0_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (sub_00498DC0_MouseMoveMsg(pMsg) || nX < gnGlobal_007BCAA0 || nX >= gnGlobal_007BCAA4 || nY < gnGlobal_007BCAA8 || nY > gnGlobal_007BCAAC)
    {
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
    {
        if (sub_00487740_ClickGridItem(pPlayer, pInventory, nX, nY, 0))
        {
            if (gdwGlobal_007BCBF0 >= 2 && gdwGlobal_007BCBF0 <= 4)
            {
                sub_00487BE0_ResetButtons();
            }
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        pMsg->bReturn = 0;
    }

    if (gdwGlobal_007BCBF0)
    {
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if ((unsigned int)(gdwGlobal_007BCBF0 - 2) <= 2)
        {
            sub_00487BE0_ResetButtons();
        }
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
            return;
        }

        if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
        }
    }
}

static __declspec(noinline) int sub_00483B40_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
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

static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
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

static int sub_00489980_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > sub_00486AE0_GetPanelX() && nX < sub_00486AE0_GetPanelX() + 0x28
        && nY > sub_00486B00_GetPanelY() - 0x23 && nY < sub_00486B00_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00492510
void __stdcall sub_00492510_CubeButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xC && gdwGlobal_007BCBF0 != 0xD)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if ((!sub_004979E0() || !sub_00498DC0_MouseMoveMsg(pMsg)) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        gnGlobal_007BCE3C = 1;
        gnGlobal_007BCE38 = 1;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483AB0_IsInInvRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483B40_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483BA0_IsInRect(nX, nY))
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE3C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_00486E60_ClickOutsidePanel(nY, pMsg, nX);
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE3C = 0;
}

static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        return 1;
    }
    return 0;
}

static int sub_0048A000_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x90 && nX < gnGlobal_007A2858 + 0xB8
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0xDF && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x004927C0
void __stdcall sub_004927C0_CubeButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xE)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489FB0_IsOverButtonC(nX, nY))
    {
        gnGlobal_007BCE44 = 1;
        gnGlobal_007BCE40 = 1;
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_0048A000_IsOverCubeButton(nX, nY))
    {
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE40 = 0;
        if (!sub_004680A0())
        {
            gnGlobal_007BCE4C = 1;
            gnGlobal_007BCE48 = 1;
            gnGlobal_007BCE9C = 1;
            pMsg->bReturn = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE4C = 0;
        return;
    }
    if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483BF0_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE48 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE4C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!pMsg->bReturn)
    {
        sub_00486E60_ClickOutsidePanel(nY, pMsg, nX);
    }
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE44 = 0;
    gnGlobal_007BCE4C = 0;
}
