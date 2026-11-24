#include "Fog.h"

extern "C" double __cdecl pow(double,double);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl FOG_DisplayHalt(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if(!(expr)){FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
// 0x006BE190
void __fastcall sub_006BE190_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask)
{
 D2_ASSERT(entrySize==1 || entrySize==2 || entrySize==4,14);
 D2_ASSERT(gamma>=0,15);
 D2_ASSERT(scale>=0.0 && scale<=100.0,16);
 unsigned char* bytes=(unsigned char*)table;
 unsigned short* words=(unsigned short*)table;
 unsigned int* dwords=(unsigned int*)table;
 double remainder=100.0-scale;
 double factor=gamma/100.0;
 double power=100.0/gamma;
 double last=entries-1.0;
 double maximum=mask;
 for(double i=0.0;i<=last;i+=1.0) {
  double linear=(i*factor*maximum/last<maximum)?i*factor*maximum/last:maximum;
  int value=(int)((pow(i/last,power)*maximum*remainder+linear*scale)/100.0);
  switch(entrySize) {
   case 1: *bytes++=(unsigned char)value; break;
   case 2: *words++=(unsigned short)value; break;
   case 4: *dwords++=value; break;
  }
 }
}
