struct D2UnitStrc { int type,classId,unknown008,id; char unknown010[0xB4]; unsigned int flags; };
struct D2NpcEntryStrc { char unknown000[21]; unsigned char greeting; };
extern int gnNpcOpen; // 0x007C0C6B
extern int gnNpcPlayerStat; // 0x007C0C73
extern int gnNpcId; // 0x007C0D25
extern int gnNpcActive; // 0x007C0D29
extern int gnNpcClass; // 0x007C0D2D
extern int gnNpcMenu; // 0x007C0D31
extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850
extern const char gszEmptyAssert[]; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __cdecl sub_0044DA40(); // 0x0044DA40
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __fastcall sub_004B3C20_CloseInteraction(int); // 0x004B3C20
int __fastcall sub_00455F20(int,int,int); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990_GetClientUnit(int,int); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
void __fastcall sub_00456300(int,int); // 0x00456300
void __cdecl sub_004B3DE0_CloseNpc(); // 0x004B3DE0
void __cdecl sub_004B4DB0_OpenGreetingDialog(); // 0x004B4DB0
int __cdecl sub_004B1D70_GetNpcIndex(); // 0x004B1D70
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc(); // 0x004B1620
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc*,int); // 0x004E0590
void __fastcall sub_004CB190_ReleaseSkillSfx(D2UnitStrc*); // 0x004CB190
int __fastcall sub_004B9A00(int,D2UnitStrc*,int,int,int); // 0x004B9A00
static void sub_004B1640_SetNpcInteract(D2UnitStrc*); // 0x004B1640

static __declspec(noinline) void sub_004B1640_SetNpcInteract(D2UnitStrc* unit)
{
 if(unit) { gnNpcActive=1;gnNpcId=unit->id;gnNpcClass=unit->classId; }
 else gnNpcActive=0;
}
inline D2UnitStrc* FindCurrentNpc() { return gnNpcActive?sub_00463990_GetClientUnit(gnNpcId,1):0; }
// 0x004B4FD0
void __stdcall sub_004B4FD0_OpenNpcWindow(D2UnitStrc* unit)
{
 sub_0044DA40();
 if(!unit) {
  gnNpcOpen=0;
  sub_00487990_ResetHover();
  sub_004B3C20_CloseInteraction(gnNpcId);
  sub_00455F20(8,1,0);
  return;
 }
 if(FindCurrentNpc()) {
  gnNpcOpen=0;
  sub_00487990_ResetHover();
  sub_004B3C20_CloseInteraction(gnNpcId);
  sub_00455F20(8,1,0);
  return;
 }
 gnNpcOpen=1;
 gnNpcMenu=0;
 gnNpcPlayerStat=STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(),14,0);
 sub_00456300(0,0);
 sub_0044DA40();
 if(FindCurrentNpc()) { sub_00408A60(gszEmptyAssert,sub_00408090(),3529);exit(-1); }
 sub_004B1640_SetNpcInteract(unit);
 D2UnitStrc* npc=FindCurrentNpc();
 if(npc) npc->flags&=~2;
 if(!sub_00455F20(8,2,0)) {
  sub_004B3DE0_CloseNpc();
  return;
 }
 sub_004B4DB0_OpenGreetingDialog();
 int index=sub_004B1D70_GetNpcIndex();
 if(gaNpcEntries[index].greeting) {
  int sound=sub_004E0590_PickNpcSound(sub_004B1620_GetInteractNpc(),1);
  if(sound) {
   sub_004CB190_ReleaseSkillSfx(unit);
   sub_004B9A00(sound,sub_00463DD0_GetPlayerUnit(),0,1,0);
  }
  gaNpcEntries[index].greeting=0;
 }
}

#include "gen/data/Source/D2Client/004B4FD0_sub_004B4FD0_OpenNpcWindow.inc"
