extern "C" void* __cdecl memset(void* buffer,int value,unsigned int size);
struct T006BE350 {
 char unknown000[0x884]; int running;
 char unknown888[0x308]; unsigned int socket;
 char unknownB94[0x0C]; unsigned short port;
 char unknownBA2[0x32]; void* event; void* thread;
 char unknownBDC[0x0C]; unsigned long threadId;
};
struct D2SockAddrStrc { unsigned short family,port; unsigned int address; char zero[8]; };
unsigned int __stdcall sub_006B016E_Socket(int family,int type,int protocol); // 0x006B016E
int __stdcall sub_006B0162_SetOption(unsigned int socket,int level,int option,const char* value,int size); // 0x006B0162
int __stdcall sub_006B015C_Ioctl(unsigned int socket,unsigned int command,unsigned long* argument); // 0x006B015C
unsigned short __stdcall sub_006B0156_Htons(unsigned short value); // 0x006B0156
int __stdcall sub_006C9B76_Bind(unsigned int socket,const D2SockAddrStrc* address,int size); // 0x006C9B76
int __stdcall sub_006C9B70_Listen(unsigned int socket,int backlog); // 0x006C9B70
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
unsigned long __stdcall sub_006C3470_ServerThread(void* context); // 0x006C3470
void __fastcall sub_00407F80_ThreadHookNop2(unsigned int nId, void* hThread); // 0x00407F80
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* attributes,int manualReset,int initialState,const char* name);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* attributes,unsigned int stackSize,unsigned long (__stdcall* routine)(void*),void* argument,unsigned long flags,unsigned long* id);
// 0x006C3B50
int __fastcall sub_006C3B50_StartServer(T006BE350* server,int port)
{
 server->running=1;
 unsigned int socket=sub_006B016E_Socket(2,1,0);
 if(socket==-1u) return 0;
 server->socket=socket;
 int noDelay=1;
 sub_006B0162_SetOption(socket,6,1,(const char*)&noDelay,4);
 int keepAlive=1;
 sub_006B0162_SetOption(socket,0xFFFF,8,(const char*)&keepAlive,4);
 int reuse=1;
 sub_006B0162_SetOption(server->socket,0xFFFF,4,(const char*)&reuse,4);
 unsigned long nonblocking=1;
 sub_006B015C_Ioctl(socket,0x8004667E,&nonblocking);
 D2SockAddrStrc address;
 memset(&address,0,sizeof(address));
 address.family=2;
 address.port=sub_006B0156_Htons((unsigned short)port);
 server->port=(unsigned short)port;
 if(sub_006C9B76_Bind(server->socket,&address,sizeof(address))==-1) {
  sub_0040D880(socket);
  return 0;
 }
 if(sub_006C9B70_Listen(socket,25)==-1)
  sub_0040D880(socket);
 server->event=CreateEventA(0,0,0,0);
 server->thread=CreateThread(0,0,sub_006C3470_ServerThread,server,0,&server->threadId);
 sub_00407F80_ThreadHookNop2(server->threadId,server->thread);
 return 1;
}
