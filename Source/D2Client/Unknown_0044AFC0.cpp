extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
typedef void (__fastcall* PacketCallback)(int,int,int,unsigned char,const unsigned char*);
typedef void (__cdecl* CompletionCallback)();
extern PacketCallback gpfnChunkCallback; // 0x00799300
extern CompletionCallback gpfnChunkComplete; // 0x00799304
static int gnChunkPosition; // 0x0079930C
static int gnChunkExpected; // 0x00799310
extern unsigned char gabChunkBuffer[]; // 0x00799318
// 0x0044AFC0
int __fastcall sub_0044AFC0_ReceiveChunk(const unsigned char* packet,unsigned int size)
{
 unsigned char* cursor=gabChunkBuffer;
 if(size<8)return 0;
 unsigned char subtype=packet[1];
 const unsigned short* pWords=(const unsigned short*)packet;
 unsigned short length=pWords[2];
 unsigned short total=pWords[1];
 unsigned short offset=pWords[3];
 if(!total&&!length&&!offset) {
  gpfnChunkCallback(0,0,0,0,0);
  gnChunkExpected=0;
  gnChunkPosition=0;
  return 1;
 }
 if(total<12)return 0;
 if(total!=gnChunkExpected)gnChunkExpected=total;
 gnChunkPosition=offset;
 int end=gnChunkPosition+length;
 if(end>total)return 0;
 memcpy(gabChunkBuffer+offset,packet+8,length);
 gnChunkPosition=end;
 if(end>=gnChunkExpected) {
  if(gpfnChunkComplete) {
   gpfnChunkComplete();
  }
  do {
   int id=*(int*)cursor;cursor+=4;
   int count=*(int*)cursor;cursor+=4;
   int extra=*(int*)cursor;cursor+=4;
   int payload=(extra+12)*count;
   gnChunkExpected-=12;
   if(count<0||extra<0||count>256||extra>16||payload>gnChunkExpected||id>2000)break;
   if(gpfnChunkCallback) {
    gpfnChunkCallback(id,count,extra,subtype,cursor);
   }
   gnChunkExpected-=(unsigned short)payload;
   cursor+=payload;
  } while(gnChunkExpected>0);
  gnChunkExpected=0;
 }
 return 1;
}
