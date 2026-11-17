struct Unit { char pad[0x60]; void* inventory; };
typedef int (__cdecl* Callback)();
void __cdecl sub_00466FE0(); // 0x00466FE0
void __cdecl sub_00487CC0_SelectFirstButton(); // 0x00487CC0
void __cdecl sub_00487D30_SetNpcState7(); // 0x00487D30
void __cdecl sub_00488F10(); // 0x00488F10
void __cdecl sub_004939B0_LoadPopupHireling(); // 0x004939B0
int __cdecl sub_004B4CF0_NpcMenuReturn(); // 0x004B4CF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
Unit* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
Unit* __fastcall sub_00463990(int,int); // 0x00463990
Unit* __stdcall INVENTORY_GetCursorItem(void*); // 0x0063C1E0
Unit* __cdecl sub_004680A0(); // 0x004680A0
void __fastcall sub_00468070_SetCursorItemState(Unit*); // 0x00468070
int __fastcall sub_004B9A00(int,Unit*,int,int,int); // 0x004B9A00
void __fastcall sub_004B8020(void*); // 0x004B8020
void* __fastcall sub_004B7EB0_CreateDialog(int,int,Callback,Callback,int,int,int,int,int,int,int); // 0x004B7EB0
void __fastcall sub_004B8370_SetCtrlState(void*,int); // 0x004B8370
unsigned short* __fastcall D2LANG_GetStringFromTblIndex(int); // 0x00524A30
void __fastcall sub_004B85F0_AddTextLine(void*,unsigned short*,int,int,int,int,Callback,int); // 0x004B85F0
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern const char empty; // 0x006CC837
extern int g007C0C6B; // 0x007C0C6B
extern int g007C0D31; // 0x007C0D31
extern int g007C0D3F; // 0x007C0D3F
extern int g007C0D5B; // 0x007C0D5B
extern void* g007C0D63; // 0x007C0D63
extern void* g007C0D67; // 0x007C0D67
extern unsigned char g007C0D89; // 0x007C0D89
extern int g007C0D8E; // 0x007C0D8E
extern int g007C0D96; // 0x007C0D96
unsigned char g007C0DE0;        // 0x007C0DE0
extern int g007C0DE1; // 0x007C0DE1
extern int g007C0DE5; // 0x007C0DE5
#define CHECK(c,line) if(!(c)) { sub_00408A60(&empty,sub_00408090(),line); exit(-1); }
// 0x004B53F0
void __cdecl sub_004B53F0()
{
 void* inv=sub_00463DD0_GetPlayerUnit()->inventory;
 if(g007C0D89<=6) {
  switch(g007C0D89) {
   case 0:
    sub_004B9A00(g007C0D5B,0,0,0,0); g007C0D5B=0;
    if(!sub_00463990(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 1:
    sub_004B9A00(0xdd,0,0,0,0);
    if(sub_00463990(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 5: sub_004939B0_LoadPopupHireling(); break;
  }
  g007C0D96=0;
  if(g007C0D67) { sub_004B8020(g007C0D67);g007C0D67=0; }
  sub_00466FE0(); g007C0DE0=0;g007C0DE1=0;g007C0DE5=0;g007C0C6B=3;
  sub_00487CC0_SelectFirstButton();sub_00488F10();return;
 }
 if(g007C0D67) {sub_004B8020(g007C0D67);g007C0D67=0;}
 int text;
 switch(g007C0D89) {
 case 15:text=0xd23;break;
 case 16:text=0xd1d;break;
 case 12:text=0xd22;break;
 case 10:text=0xd1c;break;
 case 11:text=0xd20;break;
 case 7:case 8:text=0xd1e;break;
 default:text=0xd21;break;
 }
 if(g007C0C6B==5) {
 g007C0C6B=6;sub_00487D30_SetNpcState7();
 CHECK(!g007C0D63,0x1399);
 if(g007C0D31==2) {
  Unit* item=INVENTORY_GetCursorItem(inv);
  if(g007C0D3F==1 && item && !sub_004680A0()) sub_00468070_SetCursorItemState(item);
 }
 g007C0D63=sub_004B7EB0_CreateDialog(sub_00468730(),sub_00468740(),sub_004B4CF0_NpcMenuReturn,0,0,1,1,0,0,0,1);
 sub_004B8370_SetCtrlState(g007C0D63,1);
 sub_004B85F0_AddTextLine(g007C0D63,D2LANG_GetStringFromTblIndex(text),0x15,0,1,1,0,0);
 sub_004B85F0_AddTextLine(g007C0D63,D2LANG_GetStringFromTblIndex(0xd4b),0xf,0,0,1,sub_004B4CF0_NpcMenuReturn,1);
 } else { sub_00408A60(&empty,sub_00408090(),0x13ad);exit(-1); }
}
