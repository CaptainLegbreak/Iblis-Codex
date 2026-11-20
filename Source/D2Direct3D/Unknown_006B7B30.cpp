#include "D2Direct3D.h"

struct D2VertexStrc { float x,y,z,rhw; unsigned int color,specular; float u,v; };
struct D2DeviceStrc;
struct D2DeviceVtableStrc { void* unknown[28]; int (__stdcall* DrawPrimitive)(D2DeviceStrc*,int,unsigned int,D2VertexStrc*,unsigned int,unsigned int); };
struct D2DeviceStrc { D2DeviceVtableStrc* vtable; };
extern D2DeviceStrc* gpDevice_00970E78; // 0x00970E78
void __fastcall sub_006B1EA0_SetState(int mode); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int mode); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int mode); // 0x006B2030
// 0x006B7B30
void __fastcall sub_006B7B30_DrawLine(int x1,int y1,int x2,int y2,unsigned char index,unsigned char alpha)
{
 if(x2<0 && x1<0) return;
 if(x2>=gnScreenWidth_007C9138 && x1>=gnScreenWidth_007C9138) return;
 if(y2<0 && y1<0) return;
 if(y2>=gnScreenHeight_007C913C && y1>=gnScreenHeight_007C913C) return;
 unsigned int color=sub_006B1D50_GetColor(index);
 sub_006B1EA0_SetState(2);
 if(alpha==255) sub_006B1F40_SetBlendMode(1);
 else {
  sub_006B1F40_SetBlendMode(4);
  color=(color&0xFFFFFF)|((unsigned int)alpha<<24);
 }
 sub_006B2030_SetFilterMode(1);
 if(x1==x2 && y1==y2) {
  D2VertexStrc point;
  point.x=(float)x1;point.y=(float)y1;point.z=0.5f;point.rhw=1.0f;
  point.color=color;point.u=0.0f;point.v=0.0f;
  gpDevice_00970E78->vtable->DrawPrimitive(gpDevice_00970E78,1,0x1C4,&point,1,0x1C);
  return;
 } else {
 D2VertexStrc line[2];
 line[0].x=(float)x1;line[0].y=(float)y1;line[0].z=0.5f;line[0].rhw=1.0f;
 line[0].color=color;line[0].u=0.0f;line[0].v=0.0f;
 line[1].x=(float)x2;line[1].y=(float)y2;line[1].z=0.5f;line[1].rhw=1.0f;
 line[1].color=color;line[1].u=0.0f;line[1].v=0.0f;
 gpDevice_00970E78->vtable->DrawPrimitive(gpDevice_00970E78,2,0x1C4,line,2,0x1C);
 }
}
