struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc { unsigned int type; char unknown004[0xC]; unsigned int mode; char unknown014[0xC0]; unsigned int lastOperateTick; };
struct D2CoordStrc { int x,y; };
struct D2ObjOperateStrc { D2GameStrc* game; D2UnitStrc* object; D2UnitStrc* player; };
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620870
unsigned int __stdcall sub_00620510(D2UnitStrc*); // 0x00620510
unsigned int __stdcall sub_006205A0(D2UnitStrc*); // 0x006205A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall sub_0055F140(D2GameStrc*,D2UnitStrc*); // 0x0055F140
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __stdcall UNITS_RefreshInventory(D2UnitStrc*); // 0x00623830
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc*,D2ActiveRoomStrc*,int,int); // 0x00620A70
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc*,int,int,unsigned int,unsigned int,unsigned short); // 0x0064D800
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
static inline unsigned int GetAnimMode(D2UnitStrc* unit) { if(!unit) return 0; return unit->mode; }
// 0x00581D40
int __fastcall sub_00581D40_OperateDoor(D2ObjOperateStrc* context,int unused)
{
 D2ActiveRoomStrc* room=UNITS_GetRoom(context->object);
 D2CoordStrc coords;
 UNITS_GetCoords(context->object,&coords);
 unsigned int sizeX=sub_00620510(context->object);
 unsigned int sizeY=sub_006205A0(context->object);
 unsigned int tick=GetTickCount();
 unsigned int mode=GetAnimMode(context->object);
 if(tick<context->object->lastOperateTick+500) return 1;
 switch(mode) {
 case 6:
  if(!sub_0055F140(context->game,context->player)) {
   SUNIT_AttachSound(context->player,22,context->player);
   return 1;
  }
 case 0:
  UNITS_RefreshInventory(context->object);
  UNITS_ChangeAnimMode(context->object,2);
  context->object->lastOperateTick=tick;
  return 1;
 case 2:
 case 5:
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.x,coords.y,sizeX,sizeY,0x8180)) {
   UNITS_BlockCollisionPath(context->object,room,coords.x,coords.y);
   UNITS_ChangeAnimMode(context->object,0);
   context->object->lastOperateTick=tick;
   return 1;
  }
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.x,coords.y,sizeX,sizeY,0x8000)) {
   if(mode!=5) {
    UNITS_ChangeAnimMode(context->object,5);
    context->object->lastOperateTick=tick;
    break;
   }
  } else {
   UNITS_ChangeAnimMode(context->object,4);
   context->object->lastOperateTick=tick;
   return 1;
  }
 }
 return 1;
}
