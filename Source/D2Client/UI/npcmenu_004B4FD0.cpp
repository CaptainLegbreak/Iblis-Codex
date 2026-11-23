#include "D2StatIds.h"
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
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
void __cdecl INV_ResetHover(); // 0x00487990
void __fastcall NPCMENU_EndNpcInteraction(int); // 0x004B3C20
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __cdecl sub_004B3DE0_CloseNpc(); // 0x004B3DE0
void __cdecl NPCMENU_OpenGreetingDialog(); // 0x004B4DB0
int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70
D2UnitStrc* __cdecl NPCMENU_GetInteractNpc(); // 0x004B1620
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc*,int); // 0x004E0590
void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc*); // 0x004CB190
int __fastcall sub_004B9A00(int,D2UnitStrc*,int,int,int); // 0x004B9A00
static void NPCMENU_SetNpcInteract(D2UnitStrc*); // 0x004B1640

static __declspec(noinline) void NPCMENU_SetNpcInteract(D2UnitStrc* unit)
{
 if(unit) { gnNpcActive=1;gnNpcId=unit->id;gnNpcClass=unit->classId; }
 else gnNpcActive=0;
}
inline D2UnitStrc* FindCurrentNpc() { return gnNpcActive?CUNIT_FindClientUnit(gnNpcId,1):0; }
// 0x004B4FD0
void __stdcall sub_004B4FD0_OpenNpcWindow(D2UnitStrc* unit)
{
 GAME_ResetMouseState();
 if(!unit) {
  gnNpcOpen=0;
  INV_ResetHover();
  NPCMENU_EndNpcInteraction(gnNpcId);
  UI_SetUIVar(8,1,0);
  return;
 }
 if(FindCurrentNpc()) {
  gnNpcOpen=0;
  INV_ResetHover();
  NPCMENU_EndNpcInteraction(gnNpcId);
  UI_SetUIVar(8,1,0);
  return;
 }
 gnNpcOpen=1;
 gnNpcMenu=0;
 gnNpcPlayerStat=STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(),STAT_GOLD,0);
 UI_CloseUIVars(0,0);
 GAME_ResetMouseState();
 if(FindCurrentNpc()) { sub_00408A60(gszEmptyAssert,sub_00408090(),3529);exit(-1); }
 NPCMENU_SetNpcInteract(unit);
 D2UnitStrc* npc=FindCurrentNpc();
 if(npc) npc->flags&=~2;
 if(!UI_SetUIVar(8,2,0)) {
  sub_004B3DE0_CloseNpc();
  return;
 }
 NPCMENU_OpenGreetingDialog();
 int index=sub_004B1D70_FindNpcEntry();
 if(gaNpcEntries[index].greeting) {
  int sound=sub_004E0590_PickNpcSound(NPCMENU_GetInteractNpc(),1);
  if(sound) {
   UNITSND_ReleaseSkillSfx(unit);
   sub_004B9A00(sound,sub_00463DD0_GetPlayerUnit(),0,1,0);
  }
  gaNpcEntries[index].greeting=0;
 }
}

#include "gen/data/Source/D2Client/UI/npcmenu_004B4FD0.inc"
