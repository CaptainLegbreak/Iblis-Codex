struct D2InventoryStrc;
struct D2CellFileStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2GfxDataStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[4];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

extern D2CellFileStrc* gpTorsoCell_007BCE68;                                                                // 0x007BCE68
extern D2CellFileStrc* gpHeadCell_007BCE74;                                                                 // 0x007BCE74
extern D2CellFileStrc* gpArmCell_007BCE7C;                                                                  // 0x007BCE7C
extern int gnRectHeadLeft_007BCD4C;                                                                         // 0x007BCD4C
extern int gnRectHeadBottom_007BCD58;                                                                       // 0x007BCD58
extern int gnRectTorsoLeft_007BCD74;                                                                        // 0x007BCD74
extern int gnRectTorsoBottom_007BCD80;                                                                      // 0x007BCD80
extern int gnRectRArmLeft_007BCD88;                                                                         // 0x007BCD88
extern int gnRectRArmBottom_007BCD94;                                                                       // 0x007BCD94
extern int gnRectLArmLeft_007BCD9C;                                                                         // 0x007BCD9C
extern int gnRectLArmBottom_007BCDA8;                                                                       // 0x007BCDA8
extern int gnOffsetTorsoX_007220B0;                                                                         // 0x007220B0
extern int gnOffsetTorsoY_007220B4;                                                                         // 0x007220B4
extern int gnOffsetHeadX_007220C8;                                                                          // 0x007220C8
extern int gnOffsetHeadY_007220CC;                                                                          // 0x007220CC
extern int gnOffsetRArmX_007220F0;                                                                          // 0x007220F0
extern int gnOffsetRArmY_007220F4;                                                                          // 0x007220F4
extern int gnOffsetLArmX_007220F8;                                                                          // 0x007220F8
extern int gnOffsetLArmY_007220FC;                                                                          // 0x007220FC

// 0x0048B0A0
void __stdcall sub_0048B0A0_DrawMercEmptyBodyLocs(D2UnitStrc* pUnit)
{
    D2GfxDataStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 3))
    {
        tGfx.pCellFile = gpTorsoCell_007BCE68;
        tGfx.nFrame = 0;
        TEXTURE_CelDraw(&tGfx, gnRectTorsoLeft_007BCD74 + gnOffsetTorsoX_007220B0, gnRectTorsoBottom_007BCD80 + gnOffsetTorsoY_007220B4, -1, 5, 0);
    }

    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 1))
    {
        tGfx.pCellFile = gpHeadCell_007BCE74;
        tGfx.nFrame = 1;
        TEXTURE_CelDraw(&tGfx, gnRectHeadLeft_007BCD4C + gnOffsetHeadX_007220C8, gnRectHeadBottom_007BCD58 + gnOffsetHeadY_007220CC, -1, 5, 0);
    }

    D2UnitStrc* pRightItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 4) : 0;
    D2UnitStrc* pLeftItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 5) : 0;
    int bTwoHanded = pInventory ? INVENTORY_GetWieldType(pUnit, pInventory) == 2 : 0;

    if (!pLeftItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pRightItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectLArmLeft_007BCD9C + gnOffsetLArmX_007220F8, gnRectLArmBottom_007BCDA8 + gnOffsetLArmY_007220FC, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectLArmLeft_007BCD9C + gnOffsetLArmX_007220F8, gnRectLArmBottom_007BCDA8 + gnOffsetLArmY_007220FC, -1, 5, 0);
        }
    }

    if (!pRightItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pLeftItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectRArmLeft_007BCD88 + gnOffsetRArmX_007220F0, gnRectRArmBottom_007BCD94 + gnOffsetRArmY_007220F4, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectRArmLeft_007BCD88 + gnOffsetRArmX_007220F0, gnRectRArmBottom_007BCD94 + gnOffsetRArmY_007220F4, -1, 5, 0);
        }
    }
}
