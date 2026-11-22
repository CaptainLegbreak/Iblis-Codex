#include "D2BNClient.h"

extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" char* __cdecl strncpy(char*,const char*,unsigned);
#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
struct D2Storm408ElemStrc { int flags; unsigned stamp; char text[1024]; };
struct D2StormArray408Strc {
 unsigned alloc,count; D2Storm408ElemStrc* data; unsigned chunk;
 void sub_0051D810_SetCount(unsigned count); // 0x0051D810
};
extern D2StormArray408Strc gtNewsItems_00881C30; // 0x00881C30
extern int (__fastcall* gpfnNewsMessage_00881C28)(unsigned,const char*); // 0x00881C28
extern unsigned gnNewsFirstIndex_00881C40; // 0x00881C40
extern unsigned gnNewsLastStamp_00881C44; // 0x00881C44
int __cdecl BNNEWS_SaveNews(); // 0x0051D370
void __cdecl BNNEWS_ReportNews(); // 0x0051D510
// 0x0051D860
int __fastcall sub_0051D860_ParseNewsInfo(const char* data)
{
 unsigned count=*data;
 const char* cursor=data+5;
 unsigned first=*(unsigned*)cursor;cursor+=4;
 unsigned last=*(unsigned*)cursor;cursor+=4;
 D2_ASSERT(count<=256,0x77);
 for(unsigned i=0;i<count;++i) {
  unsigned stamp=*(unsigned*)cursor;cursor+=4;
  const char* text=cursor;
  while(*cursor++);
  if(stamp) {
   unsigned index=gtNewsItems_00881C30.count;
   unsigned* entry=0;
   if(gtNewsItems_00881C30.count) {
    entry=&gtNewsItems_00881C30.data[gtNewsItems_00881C30.count].stamp;
    do {
     entry=(unsigned*)((char*)entry-0x408);
     --index;
     if(stamp>*entry)goto insert;
     if(stamp==*entry)goto update;
    }while(index);
   }
   --index;
   goto insert;
update:
   entry[-1]=0;
   strncpy((char*)(entry+1),text,1024);
   goto next;
insert:
   ++index;
   gtNewsItems_00881C30.sub_0051D810_SetCount(gtNewsItems_00881C30.count+1);
   for(unsigned j=gtNewsItems_00881C30.count-1;j>index;--j)gtNewsItems_00881C30.data[j]=gtNewsItems_00881C30.data[j-1];
   gtNewsItems_00881C30.data[index].flags=0;
   gtNewsItems_00881C30.data[index].stamp=stamp;
   strncpy(gtNewsItems_00881C30.data[index].text,text,1024);
  } else if(gpfnNewsMessage_00881C28)gpfnNewsMessage_00881C28(0,text);
next:;
 }
 gnNewsLastStamp_00881C44=last;
 unsigned index=0;
 while(index<gtNewsItems_00881C30.count && gtNewsItems_00881C30.data[index].stamp<first)++index;
 gnNewsFirstIndex_00881C40=index;
 BNNEWS_SaveNews();BNNEWS_ReportNews();return 1;
}
