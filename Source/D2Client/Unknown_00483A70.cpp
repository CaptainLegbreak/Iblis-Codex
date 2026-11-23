#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2ClientTypes.h"
#include "D2Structs.h"
struct D2InventoryStrc;
struct D2UnitStrc;

extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth; // 0x007A5220
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88
extern int gbHoverInBodyLoc; // 0x007BCBE8
extern int gnInvPanelMode; // 0x007BCBF0
extern D2UnitStrc* gpHoverItem; // 0x007BCBF4
extern int gnHoverBodyLoc; // 0x007BCC20
extern int gbWeaponSwitch; // 0x007BCC4C
extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58
extern "C" const char gszCmnItemsH[]; // 0x006D9B90
extern "C" const char gszInvCpp[]; // 0x006D9BC0
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_00468830(); // 0x00468830
int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int,int,unsigned char,unsigned char,unsigned char,int); // 0x0046EFD0
void __cdecl INV_LoadUiRecords(); // 0x004835B0
void __stdcall INV_DrawItemSockets(D2UnitStrc*,D2InventoryGridInfoStrc*,int,int); // 0x00483E40
int __fastcall sub_004C2240(D2UnitStrc*); // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*,int,int); // 0x00621050
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
void __stdcall ITEMS_GetDimensions(D2UnitStrc*,unsigned char*,unsigned char*,const char*,int); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem); // 0x006299B0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc*); // 0x0062A4E0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc*); // 0x0062BEB0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc*,int); // 0x0062ED50
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60
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
    if (nLeft >= 0 && nLeft < gnAutomapWidth && nTop >= 0 && nTop < gnAutomapHeight_007A521C)
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

void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory); // 0x004844A0

// build: context sub_004845A0_DrawOtherHandFrame
static inline void sub_004845A0_DrawOtherHandFrame(D2InvCompGridStrc* pCompGrid)
{
    const int nLeft = pCompGrid->rect.nLeft;
    if (nLeft >= 0 && nLeft < gnAutomapWidth)
    {
        const int nTop = pCompGrid->rect.nTop;
        if (nTop >= 0 && nTop < gnAutomapHeight_007A521C)
        {
            sub_0046EFD0_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[0], 0);
        }
    }
}

// 0x004845A0
void __cdecl INV_DrawEquippedItems()
{
    unsigned char nWidth,nHeight;
    D2UnitStrc* pItem;
    D2UnitStrc* pOther;
    int nBodyLoc;
    int nOffsetX=0;
    int nOffsetY=0;
    if(GAME_IsExpansion() && gbWeaponSwitch)
    {
        nOffsetX=4;
        nOffsetY=-4;
    }
    D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    UNITS_GetInventoryRecordId(pPlayer,0,GAME_IsExpansion());
    INV_LoadUiRecords();
    for(nBodyLoc=0;nBodyLoc<11;++nBodyLoc)
    {
        pOther=0;
        pItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
        if(!pItem)continue;
        ITEMS_GetDimensions(pItem,&nWidth,&nHeight,gszCmnItemsH,0x6DC);
        int bDualWield=INVENTORY_GetWieldType(pPlayer,pInventory)==2;
        switch(nBodyLoc)
        {
        case 5:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,4);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                GFX_DrawItemCel(pItem,gaCompGrids[4].rect.nLeft+((gaCompGrids[5].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids[4].rect.nTop+((gaCompGrids[5].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids[4]);
            }
            break;
        case 4:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,5);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                GFX_DrawItemCel(pItem,gaCompGrids[5].rect.nLeft+((gaCompGrids[4].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids[5].rect.nTop+((gaCompGrids[4].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids[5]);
            }
            break;
        }
        int nX=gaCompGrids[nBodyLoc].rect.nLeft+((gaCompGrids[nBodyLoc].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1);
        int nY=gaCompGrids[nBodyLoc].rect.nTop+((gaCompGrids[nBodyLoc].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1);
        switch(nBodyLoc)
        {
        case 8:nX+=2;
        case 2:case 6:case 7:case 10:nY-=2;break;
        case 3:nX+=3;break;
        case 9:nX+=2;nY-=4;break;
        case 4:case 5:nX+=nOffsetX;nY+=nOffsetY;break;
        }
        if(pItem==gpHoverItem && gbHoverInBodyLoc)
        {
            if(sub_00468830()==8)sub_00483A70_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
            else sub_00483A70_DrawSlotFrame(&gaCompGrids[nBodyLoc],1);
            GFX_DrawItemCel(pItem,nX,nY);
            if(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0 && ITEMS_CheckItemFlag(pItem,0x800,0x673,gszInvCpp))
                INV_DrawItemSockets(pItem,&gtPlayerInvGrid,nX,nY);
        }
        else
        {
            if (pOther || (!ITEMS_GetAmmoType(pItem) && !ITEMS_GetQuiverType(pItem)))
            {
                if (ITEMS_CheckRequirements(pItem,pPlayer,0,0,0,0) && !sub_004C2240(pItem) && ITEMS_CanBeEquipped(pItem))
                {
                    if(!ITEMS_CheckItemFlag(pItem,0x10,0x682,gszInvCpp))sub_00483A70_DrawSlotFrame(&gaCompGrids[nBodyLoc],4);
                }
                else
                {
                    sub_00483A70_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
                }
            }
            else
            {
                sub_00483A70_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
            }
            GFX_DrawItemCel(pItem,nX,nY);
        }
    }
    INV_DrawBodyLocPlacement(pInventory);
}
