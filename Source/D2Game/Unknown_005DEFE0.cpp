#include "D2Game.h"

struct D2StaticPathStrc { char unknown[12]; int x; int y; };
struct D2UnitStrc { int type; char unknown[40]; union { D2PathRecordStrc* path; D2StaticPathStrc* staticPath; }; };
int __stdcall PATH_GetXPosition(D2PathRecordStrc* path); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* path); // 0x00648900
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* unit,int mode,int velocity,unsigned char flags); // 0x005DE190
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* target,int mode,int x,int y,unsigned char step,int flags); // 0x005DEB60
// build: context GetX
static __forceinline int GetX(D2UnitStrc* unit)
{
 int value;
 switch(unit->type) {
 case 2: case 4: case 5: value=unit->staticPath->x;break;
 default: if(unit->path) value=PATH_GetXPosition(unit->path);else value=0;break;
 }
 return value;
}
// build: context GetY
static __forceinline int GetY(D2UnitStrc* unit)
{
 int value;
 switch(unit->type) {
 case 2: case 4: case 5: value=unit->staticPath->y;break;
 default: if(unit->path) value=PATH_GetYPosition(unit->path);else value=0;break;
 }
 return value;
}
// 0x005DEFE0
int __fastcall sub_005DEFE0_Escape(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* target,unsigned char maxDistance,int deleteEvent)
{
 if(!unit || !target) return 0;
 int x=GetX(unit);
 int y=GetY(unit);
 int targetX=GetX(target);
 int targetY=GetY(target);
 int dx=0,dy=0;
 if(targetX>x) dx=-1;
 else if(targetX<x) dx=1;
 if(targetY>y) dy=-1;
 else if(targetY<y) dy=1;
 int destX=x+maxDistance*dx;
 int destY=y+maxDistance*dy;
 if(maxDistance>5) AITACTICS_SetVelocity(unit,0,0,maxDistance);
 int nFlags;
 if(deleteEvent) nFlags=4;
 else nFlags=0;
 return AITACTICS_MoveToTarget(game,unit,0,2,destX,destY,1,nFlags);
}
