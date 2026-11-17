struct D2GameStrc;
struct D2PathRecordStrc;
struct D2RoomStrc;
struct D2StaticPathStrc { char unknown[12]; int x; int y; };
struct D2UnitStrc { int type; char unknown04[8]; int id; char unknown10[28]; union {D2PathRecordStrc* path;D2StaticPathStrc* staticPath;}; char unknown30[0x94]; unsigned int flags; unsigned int flagsEx; int unknownCC; int owner; };
D2UnitStrc* __fastcall sub_00574EC0_FindPet(D2GameStrc* game,D2UnitStrc* player,int type,int index); // 0x00574EC0
void __fastcall sub_0058F030_SetOwner(D2GameStrc* game,D2UnitStrc* pet,int id,int type,int a,int b); // 0x0058F030
void __fastcall sub_005750E0_RemovePet(D2GameStrc* game,D2UnitStrc* player,int id,int flags); // 0x005750E0
D2RoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* unit); // 0x00620BB0
void __stdcall sub_0061A270_RemoveRoomUnit(D2RoomStrc* room,int type,int id); // 0x0061A270
void __fastcall sub_00555600_RemoveUnit(D2GameStrc* game,D2UnitStrc* unit); // 0x00555600
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* unit,int mode); // 0x00624690
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* unit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* unit,int stat,int value,int layer); // 0x00627260
void __fastcall sub_00574AB0_AttachPet(D2GameStrc* game,D2UnitStrc* player,D2UnitStrc* pet); // 0x00574AB0
void __fastcall sub_005B1900_InitAi(D2GameStrc* game,D2UnitStrc* pet,int flag,int owner); // 0x005B1900
void __stdcall STATES_ToggleState(D2UnitStrc* unit,int state,int set); // 0x00639DB0
void __fastcall sub_00577470_RefreshPet(D2UnitStrc* pet); // 0x00577470
int __stdcall PATH_GetXPosition(D2PathRecordStrc* path); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* path); // 0x00648900
void __fastcall sub_005754B0_MovePets(D2GameStrc* game,D2UnitStrc* player,int x,int y); // 0x005754B0
void __fastcall sub_005726C0_RefreshPlayer(D2GameStrc* game,D2UnitStrc* player,int value); // 0x005726C0
static __forceinline int GetId(D2UnitStrc* u){ if(u) return u->id; return -1; }
static __forceinline int GetX(D2UnitStrc* unit) {
 switch(unit->type) { case 2:case 4:case 5:return unit->staticPath->x; }
 return unit->path?PATH_GetXPosition(unit->path):0;
}
static __forceinline int GetY(D2UnitStrc* unit) {
 switch(unit->type) { case 2:case 4:case 5:return unit->staticPath->y; }
 return unit->path?PATH_GetYPosition(unit->path):0;
}
static __forceinline void RemoveExistingPet(D2GameStrc* game,D2UnitStrc* player)
{
 D2UnitStrc* old=sub_00574EC0_FindPet(game,player,7,0);
 if(old) {
  sub_0058F030_SetOwner(game,old,-1,1,0,0);
  sub_005750E0_RemovePet(game,player,GetId(old),0);
  sub_0061A270_RemoveRoomUnit(UNITS_GetRoom(old),1,GetId(old));
  sub_00555600_RemoveUnit(game,old);
 }
}
// 0x00579AA0
void __fastcall sub_00579AA0_ReplacePet(D2GameStrc* game,D2UnitStrc* player,D2UnitStrc* pet)
{
 if(!pet || !player) return;
 RemoveExistingPet(game,player);
 UNITS_ChangeAnimMode(pet,1);
 STATLIST_SetUnitStat(pet,6,STATLIST_GetMaxLifeFromUnit(pet),0);
 sub_00574AB0_AttachPet(game,player,pet);
 sub_005B1900_InitAi(game,pet,0,player->owner);
 STATES_ToggleState(pet,1,0);
 STATES_ToggleState(pet,107,0);
 STATES_ToggleState(pet,154,0);
 pet->flags|=0x402000E;
 pet->flagsEx&=~0x40000;
 sub_00577470_RefreshPet(pet);
 sub_005754B0_MovePets(game,player,GetX(player),GetY(player));
 sub_005726C0_RefreshPlayer(game,player,0);
}
