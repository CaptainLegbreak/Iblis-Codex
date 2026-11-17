struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int low, high; };
struct D2StaticPathStrc { char pad[12]; int x,y; };
struct D2UnitStrc { int type,id; char pad08[24]; D2SeedStrc seed; char pad28[4]; union { D2DynamicPathStrc* dynamicPath; D2StaticPathStrc* staticPath; }; char pad30[20]; int frame; };
struct D2MissilesTxt { char pad[0x181]; unsigned char startFrame,endFrame; char tail[0x21]; };
struct D2DataTables { char pad[0xb64]; D2MissilesTxt* missiles; int unknown; int count; };
extern D2DataTables* gpDataTables; // 0x00744304
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc*,D2UnitStrc*); // 0x005AE1F0
int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc*,int); // 0x0045C3E0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064EA00
static __forceinline int GetX(D2UnitStrc* p) { switch(p->type) {case 2:case 4:case 5:return p->staticPath->x;} return p->dynamicPath?PATH_GetXPosition(p->dynamicPath):0; }
static __forceinline int GetY(D2UnitStrc* p) { switch(p->type) {case 2:case 4:case 5:return p->staticPath->y;} return p->dynamicPath?PATH_GetYPosition(p->dynamicPath):0; }
// 0x005AE520
int __fastcall sub_005AE520_UpdateMissileFrames(D2GameStrc* game,D2UnitStrc* unit)
{
 D2MissilesTxt* rec;
 if(unit && unit->id>=0 && unit->id<gpDataTables->count) rec=&gpDataTables->missiles[unit->id];
 else rec=0;
 if(!rec) return MISSMODE_HandleMissileCollision(game,unit);
 int frame=unit->frame>>8;
 COLLISION_SetMaskWithSize(UNITS_GetRoom(unit),GetX(unit),GetY(unit),UNITS_GetUnitSizeX(unit),0x40);
 if(frame==rec->startFrame-1) {
  unit->frame=(frame+sub_0045C3E0_RollLimited(&unit->seed,rec->endFrame-rec->startFrame))<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)==rec->startFrame) {
  unit->frame=(rec->startFrame-3)<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)<rec->startFrame) {
  frame-=2; if(frame<0)frame=0; unit->frame=frame<<8;
 }
 return MISSMODE_HandleMissileCollision(game,unit);
}
