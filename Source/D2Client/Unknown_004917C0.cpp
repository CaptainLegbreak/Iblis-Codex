#include "D2Client.h"

enum D2C_H19GridClickConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    int dwCode;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78
extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB88;                                                              // 0x007BCB88
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gnGlobal_007BCC50;                                                                               // 0x007BCC50

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar);                                                            // 0x004538D0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                          // 0x00478680
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);                    // 0x004786D0
int __cdecl sub_00486D10_CheckTick();                                                                      // 0x00486D10
void __fastcall sub_0049FF90_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt);                            // 0x0049FF90
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                  // 0x004B9A00
int __fastcall sub_004C1E20(D2UnitStrc* pItem);                                                            // 0x004C1E20
void __fastcall sub_004C21F0(D2UnitStrc* pItem);                                                           // 0x004C21F0
int __fastcall sub_004C2240(D2UnitStrc* pItem);                                                            // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);             // 0x00621050
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                        // 0x00628590
int __stdcall sub_00628C20(D2UnitStrc* pItem);                                                             // 0x00628C20
int __stdcall sub_00628C70(D2UnitStrc* pItem);                                                             // 0x00628C70
int __stdcall sub_0062A0A0(D2UnitStrc* pItem);                                                             // 0x0062A0A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                             // 0x006335F0
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                // 0x0063C1E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                 // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                 // 0x00648900

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

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0
#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)
#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)
#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)
#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
void __cdecl sub_00453EC0();                                                                                // 0x00453EC0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
int __cdecl sub_00468830();                                                                                 // 0x00468830
void __cdecl sub_004835B0();                                                                                // 0x004835B0
int __cdecl sub_00487BE0_ResetButtons();                                                                    // 0x00487BE0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

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

    D2UnitStrc* pItem = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && sub_0062A0A0(pItem))
        {
            if (!sub_004C2240(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0(pItem);
                return 1;
            }
        }
        else if (sub_00628C20(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
            {
                if (sub_004538D0(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gnGlobal_007BCC50 = 1;
                }

                sub_004786D0_SendPacket(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0(pItem);
                sub_004B9A00(sub_004C1E20(pItem), 0, 0, 0, 0);
                gdwGlobal_007BCBE4 = 0;
                return 1;
            }
        }
        else if (sub_00628C70(pItem))
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
    pPlayer = sub_00463DD0();
    sub_004835B0();
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
            sub_00420290_HandleMsg(pMsg);
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
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        if ((unsigned int)(gdwGlobal_007BCBF0 - 2) <= 2)
        {
            sub_00487BE0_ResetButtons();
        }
        sub_00420290_HandleMsg(pMsg);
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
