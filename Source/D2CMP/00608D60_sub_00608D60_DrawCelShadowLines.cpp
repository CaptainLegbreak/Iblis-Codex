struct D2CelStrc { unsigned int unknown000,width; char unknown008[24]; };
extern const char gszEmptyAssert[]; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
static __forceinline const char* __fastcall SkipCelRows(const char* current,int rows)
{
 if(!rows) return current;
 for(;;) {
  const char code=*current++;
  if(code<0) {
   if(!(code&127) && !--rows) break;
  } else current+=code;
 }
 return current;
}
// 0x00608D60
void __fastcall sub_00608D60_DrawCelShadowLines(const D2CelStrc* cel,unsigned char* dst,int x,int clipLeft,int clipRight,unsigned int pitch,int skip,int rows,const unsigned char* table,int color)
{
 int startX=x;
 if(pitch<cel->width) { sub_00408A60(gszEmptyAssert,sub_00408090(),1871);exit(-1); }
 const char* src=SkipCelRows((const char*)cel+32,skip*2);
 int step=-(int)pitch;
 unsigned char* nextRow=dst+step;
 for(;;) {
  char code=*src++;
  if(code<0) {
   code&=127;
   if(!code) {
    dst=nextRow-1;
    nextRow+=step-1;
    --startX;
    x=startX;
    if(!--rows) return;
    do {
     code=*src++;
     if(code>0) src+=code;
     else code&=127;
    } while(code);
   } else {
    x+=code;
    dst+=code;
   }
   continue;
  }
  int count=code;
  unsigned char* next=dst+count;
  int length=count;
  if(clipLeft || clipRight) {
   int left=clipLeft-x>0?clipLeft-x:0;
   int right=clipRight-x>0?clipRight-x:0;
   length=(right<count?right:count)-left;
   if(length<=0) goto advance;
   dst+=left;
  }
  if(length) {
   if(table) {
    unsigned char* end=dst+length;
    while(dst<end) {
     *dst=table[(*dst<<8)+(unsigned char)color];
     ++dst;
    }
   } else memset(dst,(unsigned char)color,length);
  }
 advance:
  x+=count;
  dst=next;
  src+=count;
 }
}
