#ifdef MOVED_TEST
#define INPUT_PREFIX 4
#define REPLY_FA 0xF6
#define REPLY_FB 0xF7
#define REPLY_FC 0xF8
#else
#define INPUT_PREFIX 0
#define REPLY_FA 0xFA
#define REPLY_FB 0xFB
#define REPLY_FC 0xFC
#endif
#pragma pack(push,1)
struct Request {
#if INPUT_PREFIX
 char movedPrefix[INPUT_PREFIX];
#endif
 int client; unsigned char unused,command;
};
struct ShortResponse { unsigned char command; char payload[15]; };
struct Array8 { unsigned int values[8]; };
struct ServerInfo {
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a8,ac,b0,b4,b8,bc,c0,c4,c8,cc,d0;
 unsigned short d4;
 unsigned int d6,da,de,e2,e6;
 unsigned short unusedEA;
 unsigned int ec;
 Array8 f0;
 unsigned int f110;
};
struct Reply {
 unsigned char command;
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a9,ad,b1,b5,b9,bd;
 Array8 c1;
 unsigned int e1,e5,e9,ed,f1;
 unsigned short f5;
 unsigned int f7,fb,ff,f103,f107,f10b,f10f,f113,f117;
 char reserved[0x4A];
};
#pragma pack(pop)

struct D2ServerCallbackFunctions {
 void* slots00[4];
 void* slot10;
 void* slots14[7];
 void (__fastcall* getInfo)(ServerInfo*);
};
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;  // 0x00883D50
long gnCounter_00883D64;         // 0x00883D64
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);  // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);  // 0x006CC204
int __stdcall sub_0052B490_ObjectCall_6BED90(int,int,int);
int __stdcall sub_0052B330(unsigned char,int,void*,int);  // 0x0052B330
void __stdcall D2NET_10016(int);  // 0x0052B570
unsigned int __stdcall SStrCopy(char*,const char*,unsigned int);  // 0x004135D0
extern "C" void* __cdecl memset(void*,int,unsigned int);
// 0x0052CC20
void __fastcall sub_0052CC20_Statistics(void* pData,int nSize) {
 if (!gpD2EventCallbackTable_6FD45830) return;
 Request* request=(Request*)pData;
 int client=request->client;
 ShortResponse response;
 char received[16];
 switch(request->command) {
 case 0xFA:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  InterlockedIncrement(&gnCounter_00883D64);
  response.command=REPLY_FA;
  sub_0052B330(2,client,&response,16);
  break;
 case 0xFB:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FB;
  sub_0052B330(2,client,&response,16);
  D2NET_10016(client);
  InterlockedDecrement(&gnCounter_00883D64);
  break;
 case 0xFC:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FC;
  sub_0052B330(2,client,&response,16);
  break;
 case 1:
 case 0xFD:
  if(gpD2EventCallbackTable_6FD45830->getInfo && gpD2EventCallbackTable_6FD45830->slot10) {
   ServerInfo info;
   Reply reply;
   gpD2EventCallbackTable_6FD45830->getInfo(&info);
   reply.command=request->command;
   reply.a=info.a;reply.b=info.b;reply.c=info.c;reply.d=info.d;reply.e=info.e;
   reply.f=info.f;reply.g=info.g;reply.h=info.h;reply.i=info.i;reply.j=info.j;
   SStrCopy(reply.description,info.description,128);
   reply.a9=info.a8;
   reply.f10b=info.ac;
   reply.f10f=info.b0;
   reply.f113=info.b8-gnCounter_00883D64;
   reply.f117=info.bc;
   reply.ad=reply.f10b+reply.f10f;
   reply.b1=info.b4;
   reply.b5=reply.f113+reply.f117;
   reply.b9=info.c0;
   reply.bd=info.ec;
   reply.c1=info.f0;
   reply.e1=info.f110;
   reply.e5=info.c4;reply.e9=info.c8;reply.ed=info.cc;reply.f1=info.d0;
   reply.f5=info.d4;reply.f7=info.d6;reply.fb=info.da;reply.ff=info.de;
   reply.f103=info.e2;reply.f107=info.e6;
   memset(reply.reserved,0,0x4A);
   int packetSize;
   switch(reply.command) {
   case 1: packetSize=0x165; break;
   default: packetSize=0xBD; break;
   }
   sub_0052B330(2,client,&reply,packetSize);
  }
  break;
 }
}
