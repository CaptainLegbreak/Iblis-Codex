extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48
struct D2CipherKeyView {
 void Init(int); // 0x00522C30
};
void __cdecl sub_005241A0_ClearHashContexts(); // 0x005241A0
void __fastcall sub_005241C0_GetDigest(int,void*); // 0x005241C0
void __fastcall sub_00524200_HashBlock(int,const void*,unsigned int*); // 0x00524200
void __cdecl sub_00524740_ClearKeySchedules(); // 0x00524740
void __fastcall sub_00524760_CipherBlock(int,const unsigned short*,unsigned short*); // 0x00524760
#define CHECK(p,line) if(!(p)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
// 0x00522E10
unsigned int __fastcall sub_00522E10_Decrypt(unsigned char* data,unsigned int size,unsigned int key)
{
 struct { unsigned char input[64],output[64]; } buffers;
 unsigned char digest[20];
 CHECK(data,0x91);
 const unsigned int& keyValue=key;
 const char* checkedKey=(const char*)keyValue;
 CHECK(checkedKey,0x92);
 ((D2CipherKeyView*)checkedKey)->Init(0);
 if(size<=8)return 0;
 size-=8;
 if(size&63)return 0;
 unsigned int remaining=size;
 int blockIndex=0;
 while(remaining){
  memcpy(buffers.input,data,64);
  sub_005241C0_GetDigest(0,digest);
  if(!(blockIndex&7)){
   for(int i=0;i<64;i+=8)sub_00524760_CipherBlock(0,(const unsigned short*)&buffers.input[i],(unsigned short*)&buffers.output[i]);
  }else memcpy(buffers.output,buffers.input,64);
  for(int i=0;i<64;++i)buffers.input[i]=buffers.output[i]-digest[(63-i)%20];
  if(!(blockIndex&15))sub_00524200_HashBlock(0,buffers.input,0);
  ++blockIndex;
  memcpy(data,buffers.input,64);
  remaining-=64;
  data+=64;
 }
 if(data[4]>0){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 sub_005241C0_GetDigest(0,digest);
 if(*(unsigned int*)data!=*(unsigned int*)digest){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 size+=data[5];
 size-=64;
 sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return size;
}
