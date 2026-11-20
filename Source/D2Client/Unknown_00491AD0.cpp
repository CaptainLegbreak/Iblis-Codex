#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
struct D2UnitStrc;

extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78
extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB88;                                                              // 0x007BCB88
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
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
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
void __cdecl sub_00453EC0();                                                                                // 0x00453EC0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
int __cdecl sub_00468830();                                                                                 // 0x00468830
void __cdecl sub_004835B0_LoadUiRecords();                                                                                // 0x004835B0
int __cdecl sub_00487BE0_ResetButtons();                                                                    // 0x00487BE0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

extern D2InventoryGridInfoStrc gGrid_007BCB58;                                                              // 0x007BCB58
#define gnGlobal_007BCB5C (gGrid_007BCB58.nGridLeft)
#define gnGlobal_007BCB60 (gGrid_007BCB58.nGridRight)
#define gnGlobal_007BCB64 (gGrid_007BCB58.nGridTop)
#define gnGlobal_007BCB68 (gGrid_007BCB58.nGridBottom)
extern int gdwGlobal_007BCBF4; // 0x007BCBF4
#define gnGlobal_007BCA7C (gGrid_007BCA78.nGridLeft)
#define gnGlobal_007BCA80 (gGrid_007BCA78.nGridRight)
#define gnGlobal_007BCA84 (gGrid_007BCA78.nGridTop)
#define gnGlobal_007BCA88 (gGrid_007BCA78.nGridBottom)
#define gnGlobal_007BCB44 (gGrid_007BCB40.nGridLeft)
#define gnGlobal_007BCB48 (gGrid_007BCB40.nGridRight)
#define gnGlobal_007BCB4C (gGrid_007BCB40.nGridTop)
#define gnGlobal_007BCB50 (gGrid_007BCB40.nGridBottom)
extern D2InventoryGridInfoStrc gGrid_007BCB70;                                                              // 0x007BCB70
#define gnGlobal_007BCB74 (gGrid_007BCB70.nGridLeft)
#define gnGlobal_007BCB78 (gGrid_007BCB70.nGridRight)
#define gnGlobal_007BCB7C (gGrid_007BCB70.nGridTop)
#define gnGlobal_007BCB80 (gGrid_007BCB70.nGridBottom)

void __stdcall sub_004917C0_OnGridClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004917C0
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY); // 0x00483AB0
int __cdecl sub_004888C0_CanUseCursor(); // 0x004888C0
int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_004B3870(D2UnitStrc* pUnit, int nSkill, int nArg3, int nX, int nY, unsigned int nArg6, int nArg7, int nArg8); // 0x004B3870
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

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

// 0x00487740
static __declspec(noinline) int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
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

// 0x00483B40
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

// 0x00483BF0
static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

static __forceinline int INV_IsModeInRange(int nMode)
{
    if (nMode < 2)
    {
        return 0;
    }
    if (nMode > 4)
    {
        return 0;
    }
    return 1;
}

// 0x00491AD0
void __stdcall sub_00491AD0_OnInventoryClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0044DA30() || !pPlayer || sub_00463DF0())
    {
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
    {
        sub_004917C0_OnGridClickMsg(pMsg);
        return;
    }

    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        return;
    }

    if (sub_00468830() == 6)
    {
        sub_00453EC0();
    }
    else if (sub_00468830() == 8)
    {
        sub_00478680_SendPacket5(0x4C, -1);
    }
    else if (!INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2)
        {
            if (nX >= 0 && nX <= gnGlobal_007BCAA0 && nY >= 0 && nY <= gnGlobal_007BCAAC)
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                if (nX >= gnGlobal_007BCB5C && nX <= gnGlobal_007BCB60 && nY >= gnGlobal_007BCB64 && nY <= gnGlobal_007BCB68 && gdwGlobal_007BCBF4)
                {
                    int nUnitId;
                    if (!sub_004B3230_GetTickPair(&nUnitId))
                    {
                        sub_00487BE0_ResetButtons();
                    }
                    else
                    {
                        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
                        if (!pUnit)
                        {
                            sub_00487BE0_ResetButtons();
                        }
                        else
                        {
                            const unsigned int nParam = pMsg->wParam;
                            if (gdwGlobal_007BCBF4 && sub_004B3870(pUnit, gdwGlobal_007BCBF4, 0, nX, nY, nParam, 1, 0))
                            {
                                sub_00468070_SetCursorItemState(0);
                            }
                        }
                    }
                }
                else if (sub_004888C0_CanUseCursor())
                {
                    sub_00487BE0_ResetButtons();
                }
            }
        }
        else if (gdwGlobal_007BCBF0 == 0xE)
        {
            if (sub_00483BF0_IsInRect(nX, nY))
            {
                sub_004CB9C0_Request(pPlayer, 0x13);
            }
        }
        else if (gdwGlobal_007BCBF0 == 0xC && sub_00483B40_IsInRect(nX, nY))
        {
            if (sub_00483AB0_IsInInvRect(nX, nY))
            {
                sub_004917C0_OnGridClickMsg(pMsg);
            }
            else if (sub_00483B40_IsInRect(nX, nY))
            {
                sub_00487740_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
            }
            else
            {
                sub_004CB9C0_Request(pPlayer, 0x13);
            }
        }
        else if (INV_IsModeInRange(gdwGlobal_007BCBF0))
        {
            sub_00487BE0_ResetButtons();
        }
    }
    else
    {
        switch (gdwGlobal_007BCBF0)
        {
        case 2:
        case 3:
        case 4:
            sub_00487BE0_ResetButtons();
            break;
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}
