extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
typedef void (__fastcall* PacketCallback)(int,int,int,unsigned char,const unsigned char*);
typedef void (__cdecl* CompletionCallback)();
extern PacketCallback gpCallback_00799300; // 0x00799300
extern CompletionCallback gpComplete_00799304; // 0x00799304
static int gnPosition_0079930C; // 0x0079930C
static int gnExpected_00799310; // 0x00799310
extern unsigned char gaBuffer_00799318[]; // 0x00799318
// 0x0044AFC0
int __fastcall sub_0044AFC0_ReceiveChunk(const unsigned char* packet,unsigned int size)
{
 unsigned char* cursor=gaBuffer_00799318;
 if(size<8)return 0;
 unsigned char subtype=packet[1];
 const unsigned short* pWords=(const unsigned short*)packet;
 unsigned short length=pWords[2];
 unsigned short total=pWords[1];
 unsigned short offset=pWords[3];
 if(!total&&!length&&!offset) {
  gpCallback_00799300(0,0,0,0,0);
  gnExpected_00799310=0;
  gnPosition_0079930C=0;
  return 1;
 }
 if(total<12)return 0;
 if(total!=gnExpected_00799310)gnExpected_00799310=total;
 gnPosition_0079930C=offset;
 int end=gnPosition_0079930C+length;
 if(end>total)return 0;
 memcpy(gaBuffer_00799318+offset,packet+8,length);
 gnPosition_0079930C=end;
 if(end>=gnExpected_00799310) {
  if(gpComplete_00799304) {
   gpComplete_00799304();
  }
  do {
   int id=*(int*)cursor;cursor+=4;
   int count=*(int*)cursor;cursor+=4;
   int extra=*(int*)cursor;cursor+=4;
   int payload=(extra+12)*count;
   gnExpected_00799310-=12;
   if(count<0||extra<0||count>256||extra>16||payload>gnExpected_00799310||id>2000)break;
   if(gpCallback_00799300) {
    gpCallback_00799300(id,count,extra,subtype,cursor);
   }
   gnExpected_00799310-=(unsigned short)payload;
   cursor+=payload;
  } while(gnExpected_00799310>0);
  gnExpected_00799310=0;
 }
 return 1;
}
