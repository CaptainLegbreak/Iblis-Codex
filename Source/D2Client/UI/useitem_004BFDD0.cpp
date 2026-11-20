#include "D2Client.h"
#include "D2Path.h"
struct D2CelFileStrc;
struct D2SelectionRectStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXPos;
    unsigned short nYPos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};


struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

extern int gnGlobal_007C5474;                                                                               // 0x007C5474
extern int gnGlobal_007C5480;                                                                               // 0x007C5480
extern int gnGlobal_007C5470;                                                                               // 0x007C5470
extern void* gpGlobal_007C5484;                                                                             // 0x007C5484
unsigned long gdwTick_007C5488;                                                                             // 0x007C5488
extern D2MsgHandlerEntryStrc gaMsgHandlers_00727950[];                                                      // 0x00727950
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __stdcall sub_004922A0_ClickMsg(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004922A0
void __fastcall sub_004BFBC0_HitTestHotspots(int nX, int nY);                                               // 0x004BFBC0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __cdecl sub_004B1670();                                                                                 // 0x004B1670
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_00467430_SetSelectionRect(const D2SelectionRectStrc* pRect); // 0x00467430

static void sub_004BFA70_ToggleUseMode(D2UnitStrc* pItem)
{
    if (gnGlobal_007C5474 == 1)
    {
        gnGlobal_007C5474 = 2;
        sub_00468070_SetCursorItemState(0);
        if (!pItem)
            return;
        gnGlobal_007C5480 = pItem->dwUnitId;
        sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
        return;
    }
    if (gnGlobal_007C5474 == 2)
    {
        gnGlobal_007C5474 = 1;
        gnGlobal_007C5480 = 0;
        if (pItem)
            sub_00468070_SetCursorItemState(pItem);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

static D2UnitStrc* GetCursorItem_Inline()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    return INVENTORY_GetCursorItem(pInventory);
}

// 0x004BFC50
void __stdcall sub_004BFC50_OnClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYPos;
    const int nX = pMsg->nXPos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (GetTickCount() - gdwTick_007C5488 < 0x190)
        return;
    gdwTick_007C5488 = GetTickCount();
    int bHandled;
    if (gnGlobal_007C5474 == 1)
    {
        bHandled = sub_004922A0_ClickMsg(pMsg);
    }
    else if (gnGlobal_007C5474 == 2)
    {
        bHandled = sub_00489190(pMsg);
    }
    else
    {
        goto check_item;
    }
    if (bHandled)
        return;
    sub_004BFBC0_HitTestHotspots(nX, nY);
check_item:
    D2UnitStrc* pItem = GetCursorItem_Inline();
    if (!pItem)
        return;
    if (nX < 0x7B || nX > 0x7B + 0x58 || nY < 0x6A || nY > 0x6A + 0x72)
        return;
    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pTxt)
        return;
    if (ITEMS_CheckItemFlag(pItem, 0x10, 0x210, ".\\UI\\UseItem.cpp"))
    {
        if (gnGlobal_007C5470 == 1)
        {
            if (sub_004B1670() == 0x9A && sub_0062C590(pItem))
                goto use_item;
            if (sub_004B1670() == 0x1FF && sub_0062C770(pItem))
                goto use_item;
            if (sub_004B1670() == 0x200 && sub_0062C6A0(pItem))
                goto use_item;
        }
        else if (!gnGlobal_007C5470 && pTxt->dwCode == 0x20747368)
        {
            goto use_item;
        }
    }
    sub_004B9A00(3, 0, 0, 0, 0);
    return;
use_item:
    sub_004BFA70_ToggleUseMode(pItem);
}

struct Unicode { unsigned short value; };

struct T0044CB60 { Unicode* text; T0044CB60* next; };

struct D2CelContextStrc { int frame; int unk04[12]; void* cellFile; int unk38[2]; int direction; int unk44; };

#pragma pack(push, 2)

struct D2HotspotStrc {
 unsigned short textIndex; int tooltipX,tooltipY;
 int x,y,left,right,top,bottom,frame;
 char hovered,pressed;
};

#pragma pack(pop)

extern D2HotspotStrc gaHotspots_00727900[]; // 0x00727900

extern int gnGlobal_00711470; // 0x00711470

extern void* gpCelFile_007C5494; // 0x007C5494

extern void* gpCelFile_007C5498; // 0x007C5498

extern const char gszUseItemCpp_006DAB50[]; // 0x006DAB50

extern "C" void* __cdecl memset(void*,int,unsigned int);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

D2CelFileStrc* __cdecl sub_00454600_GetBuySellButtonCells(); // 0x00454600

void __fastcall sub_0046EFD0_DrawFramedBox(int,int,int,int,int,int); // 0x0046EFD0

void __fastcall sub_004B8100_DrawControl(void*); // 0x004B8100

int __stdcall sub_004F6480(D2CelContextStrc*,int,int,int,int,int); // 0x004F6480

int __fastcall sub_00501820(const Unicode*); // 0x00501820


void __fastcall sub_00502320(const Unicode*,int,int,int,int); // 0x00502320

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode*,int*,int); // 0x00502970

int __fastcall sub_00502EF0(int); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30

// 0x004BFDD0
void __cdecl sub_004BFDD0_DrawUseItemPanel()
{
 int oldFont=sub_00502EF0(1);
 int mode=gnGlobal_007C5470;
 if(mode==1 || mode==0){
  D2CelContextStrc context;
  memset(&context,0,sizeof(context));
  context.direction=0;
  if(mode==0)context.cellFile=gpCelFile_007C5498;
  else context.cellFile=gpCelFile_007C5494;
  context.frame=0;
  sub_004F6480(&context,105,270,-1,5,0);
  context.cellFile=sub_00454600_GetBuySellButtonCells();
  for(int i=0;i<gnGlobal_007278FC;++i){
   const int drawY=gaHotspots_00727900[i].y;
   const int drawX=gaHotspots_00727900[i].x;
   context.frame=gaHotspots_00727900[i].frame+(gaHotspots_00727900[i].hovered!=0);
   sub_004F6480(&context,drawX,drawY,-1,5,0);
  }
  int mouseX=sub_00468730_GetMouseX();
  int mouseY=sub_00468740_GetMouseY();
  if(mouseX<320 && mouseY<gnGlobal_00711470-48){
   for(int i=0;i<gnGlobal_007278FC;++i){
    D2HotspotStrc* spot=&gaHotspots_00727900[i];
    if(mouseX>=spot->left && mouseX<=spot->right && mouseY>=spot->top && mouseY<=spot->bottom){
     unsigned short textIndex=spot->textIndex;
     if(textIndex==4017){
      if(gnGlobal_007C5470==0)textIndex=3401;
      if(sub_004B1670()==511)textIndex=22748;
      else if(sub_004B1670()==512)textIndex=22749;
     }
     const Unicode* text=D2LANG_GetStringFromTblIndex(textIndex);
     int width=sub_00501820(text);
     sub_0046EFD0_DrawFramedBox(spot->tooltipX-(width/2)+10,spot->tooltipY-D2Win_10125()-42,width+12,D2Win_10125()+6,0,2);
     sub_00502320(text,spot->tooltipX-(width/2)+16,spot->tooltipY-38,0,0);
    }
   }
  }
  if(gnGlobal_007C5470==1){
   unsigned short textIndex=10076;
   if(sub_004B1670()==511)textIndex=22750;
   else if(sub_004B1670()==512)textIndex=22747;
   const Unicode* panelText=D2LANG_GetStringFromTblIndex(textIndex);
   int lineCount;
   T0044CB60* line=sub_00502970_SplitText(panelText,&lineCount,300);
   if(line){
    int y=30;
    do {
    int lineWidth=sub_00501820(line->text);
    sub_00502320(line->text,160-lineWidth/2,y,4,0);
    T0044CB60* next=line->next;
    FOG_Free(line->text,gszUseItemCpp_006DAB50,707,0);
    FOG_Free(line,gszUseItemCpp_006DAB50,708,0);
    y+=20;line=next;
    } while(line);
   }
  }
 }
 if(gpGlobal_007C5484)sub_004B8100_DrawControl(gpGlobal_007C5484);
 sub_00502EF0(oldFont);
}
