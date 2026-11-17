struct D2InventoryStrc;
struct D2UnitStrc { char unknown00[0x60]; D2InventoryStrc* pInventory; };
struct D2InvRectStrc { int nLeft,nRight,nTop,nBottom; };
struct D2InvCompGridStrc { D2InvRectStrc rect; unsigned char nWidth,nHeight; unsigned short pad; };
struct D2InventoryGridInfoStrc { unsigned char nGridX,nGridY; unsigned short pad; int nGridLeft,nGridRight,nGridTop,nGridBottom; unsigned char nGridBoxWidth,nGridBoxHeight; unsigned short pad2; };
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gnGlobal_007BCC20; // 0x007BCC20
extern int gnGlobal_007BCC4C; // 0x007BCC4C
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
extern "C" const char szCmnItemsH_006D9B90[]; // 0x006D9B90
extern "C" const char szInvCpp_006D9BC0[]; // 0x006D9BC0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc*,int,int); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int,int,unsigned char,unsigned char,unsigned char,int); // 0x0046EFD0
void __cdecl sub_004835B0_LoadUiRecords(); // 0x004835B0
void __stdcall sub_00483E40(D2UnitStrc*,D2InventoryGridInfoStrc*,int,int); // 0x00483E40
int __fastcall sub_004C2240(D2UnitStrc*); // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*,int,int); // 0x00621050
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
void __stdcall ITEMS_GetDimensions(D2UnitStrc*,unsigned char*,unsigned char*,const char*,int); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc*); // 0x0062A4E0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
int __stdcall sub_0062BEB0(D2UnitStrc*); // 0x0062BEB0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc*,int); // 0x0062ED50
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc*); // 0x0063CD60
int __stdcall INVENTORY_GetWieldType(D2UnitStrc*,D2InventoryStrc*); // 0x0063D340

// 0x00483A70
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
    if (!sub_0062BEB0(pSocketable))
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
    if (ITEMS_GetMaxSockets(pItem) <= 0)
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
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, szCmnItemsH_006D9B90, 0x6DC);
    int nColor;
    if ((ITEMS_CheckBodyLocation(pCursorItem, gnGlobal_007BCC20) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0(), 0, 0, 0, 0))
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

// build: context sub_004845A0_DrawOtherHandFrame
static __forceinline void sub_004845A0_DrawOtherHandFrame(D2InvCompGridStrc* pCompGrid)
{
    const int nLeft = pCompGrid->rect.nLeft;
    if (nLeft >= 0 && nLeft < gnAutomapWidth_007A5220)
    {
        const int nTop = pCompGrid->rect.nTop;
        if (nTop >= 0 && nTop < gnAutomapHeight_007A521C)
        {
            sub_0046EFD0_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[0], 0);
        }
    }
}

// 0x004845A0
void __cdecl sub_004845A0_DrawEquippedItems()
{
    unsigned char nWidth,nHeight;
    D2UnitStrc* pItem;
    D2UnitStrc* pOther;
    int nBodyLoc;
    int nOffsetX=0;
    int nOffsetY=0;
    if(sub_0044DCC0() && gnGlobal_007BCC4C)
    {
        nOffsetX=4;
        nOffsetY=-4;
    }
    D2UnitStrc* pPlayer=sub_00463DD0();
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    UNITS_GetInventoryRecordId(pPlayer,0,sub_0044DCC0());
    sub_004835B0_LoadUiRecords();
    for(nBodyLoc=0;nBodyLoc<11;++nBodyLoc)
    {
        pOther=0;
        pItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
        if(!pItem)continue;
        ITEMS_GetDimensions(pItem,&nWidth,&nHeight,szCmnItemsH_006D9B90,0x6DC);
        int bDualWield=INVENTORY_GetWieldType(pPlayer,pInventory)==2;
        switch(nBodyLoc)
        {
        case 5:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,4);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                sub_0046EE80_DrawCursorItem(pItem,gaCompGrids_007BCC58[4].rect.nLeft+((gaCompGrids_007BCC58[5].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids_007BCC58[4].rect.nTop+((gaCompGrids_007BCC58[5].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids_007BCC58[4]);
            }
            break;
        case 4:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,5);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                sub_0046EE80_DrawCursorItem(pItem,gaCompGrids_007BCC58[5].rect.nLeft+((gaCompGrids_007BCC58[4].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids_007BCC58[5].rect.nTop+((gaCompGrids_007BCC58[4].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids_007BCC58[5]);
            }
            break;
        }
        int nX=gaCompGrids_007BCC58[nBodyLoc].rect.nLeft+((gaCompGrids_007BCC58[nBodyLoc].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1);
        int nY=gaCompGrids_007BCC58[nBodyLoc].rect.nTop+((gaCompGrids_007BCC58[nBodyLoc].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1);
        switch(nBodyLoc)
        {
        case 8:nX+=2;
        case 2:case 6:case 7:case 10:nY-=2;break;
        case 3:nX+=3;break;
        case 9:nX+=2;nY-=4;break;
        case 4:case 5:nX+=nOffsetX;nY+=nOffsetY;break;
        }
        if(pItem==gdwGlobal_007BCBF4 && gdwGlobal_007BCBE8)
        {
            if(sub_00468830()==8)sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
            else sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],1);
            sub_0046EE80_DrawCursorItem(pItem,nX,nY);
            if(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0 && ITEMS_CheckItemFlag(pItem,0x800,0x673,szInvCpp_006D9BC0))
                sub_00483E40(pItem,&gGrid_007BCB88,nX,nY);
        }
        else
        {
            if (pOther || (!ITEMS_GetAmmoType(pItem) && !ITEMS_GetQuiverType(pItem)))
            {
                if (ITEMS_CheckRequirements(pItem,pPlayer,0,0,0,0) && !sub_004C2240(pItem) && sub_0062A4E0_TestItem(pItem))
                {
                    if(!ITEMS_CheckItemFlag(pItem,0x10,0x682,szInvCpp_006D9BC0))sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],4);
                }
                else
                {
                    sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
                }
            }
            else
            {
                sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
            }
            sub_0046EE80_DrawCursorItem(pItem,nX,nY);
        }
    }
    sub_004844A0_DrawBodyLocPlacement(pInventory);
}
