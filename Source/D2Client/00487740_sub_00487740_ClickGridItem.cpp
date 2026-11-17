struct D2InventoryStrc;
struct D2DynamicPathStrc;

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

int __stdcall sub_H19_Emit_00487740(D2UnitStrc* pPlayer, int nX, int nY)
{
    return sub_00487740_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
}
