extern unsigned char gnUtf8Trailing_006FCCA0[]; // 0x006FCCA0
extern unsigned int gnUtf8Offsets_006FCC88[]; // 0x006FCC88
// 0x006C72F0
int __stdcall sub_006C72F0_Utf16Length(const char* source, int maxLength, int* consumed)
{
 if (!maxLength || !source) { if(consumed) *consumed=0; return -1; }
 const char* start=source;
 const char* end=maxLength==0x7FFFFFFF ? (const char*)-1 : source+maxLength;
 int length=0;
 for(;;) {
  if(source>=end) { length=-1; break; }
  unsigned int trailing=gnUtf8Trailing_006FCCA0[*source];
  if(source+trailing>=end) { length=-1-trailing; break; }
  unsigned int ch=0;
  switch(trailing) {
   case 5: ch+=*source++; ch<<=6;
   case 4: ch+=*source++; ch<<=6;
   case 3: ch+=*source++; ch<<=6;
   case 2: ch+=*source++; ch<<=6;
   case 1: ch+=*source++; ch<<=6;
   case 0: ch+=*source++;
  }
  ch-=gnUtf8Offsets_006FCC88[trailing];
  if(ch<=0xFFFF) { ++length; if(!ch) break; }
  else if(ch>0x10FFFF) ++length;
  else length+=2;
 }
 if(consumed) *consumed=source-start;
 return length;
}

#include "gen/data/Source/Storm/006C72F0_sub_006C72F0_Utf16Length.inc"
