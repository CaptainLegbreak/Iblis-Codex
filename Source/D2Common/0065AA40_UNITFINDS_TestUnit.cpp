struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2FieldStrc;
struct D2StaticPathStrc { char unk_00[12]; int x; int y; };
struct D2UnitStrc { int type; int classId; char pMemoryPool[8]; int mode; char unk_14[24]; union {D2DynamicPathStrc* dynamicPath;D2StaticPathStrc* staticPath;}; };
struct D2UnitFindArgStrc;
typedef int (__fastcall* UnitFilter)(D2UnitStrc*,D2UnitFindArgStrc*);
struct D2UnitFindArgStrc { unsigned int flags; int unk_04; D2UnitStrc* ignored; int x; int y; int radius; int maximum; int count; D2FieldStrc* field; UnitFilter filter; };
struct D2MissilesTxt { char unk_00[4]; unsigned char flags; };
extern const unsigned char gMissileMask_006CE26C; // 0x006CE26C
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall MONSTERS_IsUndead(D2UnitStrc*); // 0x0063E990
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int); // 0x0046ACE0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc*,int); // 0x00451F30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __stdcall D2Common_11098(D2FieldStrc*,int*,int*); // 0x0066A5D0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short); // 0x0064CB30
static __forceinline int GetX(D2UnitStrc* unit) {
 switch(unit->type) {case 2:case 4:case 5:return unit->staticPath->x;default:return unit->dynamicPath ? PATH_GetXPosition(unit->dynamicPath):0;}
}
static __forceinline int GetY(D2UnitStrc* unit) {
 switch(unit->type) {case 2:case 4:case 5:return unit->staticPath->y;default:return unit->dynamicPath ? PATH_GetYPosition(unit->dynamicPath):0;}
}
// 0x0065AA40
int __stdcall UNITFINDS_TestUnit(D2UnitStrc* unit,D2UnitFindArgStrc* args)
{
 if(!args) return 0;
 if((args->flags&64) && args->count>=args->maximum) return 0;
 int x=GetX(unit);int y=GetY(unit);
 int dx=x-args->x;int dy=y-args->y;
 if(dx*dx+dy*dy>args->radius*args->radius) return 0;
 switch(unit->type) {
  case 0: {
   if(!(args->flags&1))return 0;
   int mode=unit->mode;
   if(args->flags&4096) {if(mode!=17)return 0;} else if(mode==17 || mode==0)return 0;
   if(unit==args->ignored)return 0;
   } break;
  case 1: {
   if(!(args->flags&2))return 0;
   int mode=unit->mode;
   if(args->flags&4096) {if(mode!=12)return 0;} else if(mode==12 || mode==0)return 0;
   if((args->flags&4) && !MONSTERS_IsUndead(unit))return 0;
   } break;
  case 2:if(!(args->flags&16))return 0;break;
  case 3: {
   if(!(args->flags&8))return 0;
   D2MissilesTxt* record=DATATBLS_GetMissilesTxtRecord(unit->classId);
   if(!record || (record->flags&gMissileMask_006CE26C))return 0;
   break;
  }
  case 4:if(!(args->flags&32))return 0;break;
  default:return 0;
 }
 unsigned int flags=args->flags;
 if((flags&128) && !sub_00451F30_TestUnitFlag(unit,4))return 0;
 if((flags&1024) && !sub_00451F30_TestUnitFlag(unit,8))return 0;
 if((flags&256) && DUNGEON_IsRoomInTown(UNITS_GetRoom(unit)))return 0;
 if(args->flags&512) {
  D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
  if(room) {
   while(D2Common_11098(args->field,&x,&y)) {
    if(COLLISION_CheckMask(room,x,y,4)==4)return 0;
   }
  }
 }
 if((args->flags&2048) && args->filter(unit,args))return 0;
 ++args->count;
 return 1;
}
