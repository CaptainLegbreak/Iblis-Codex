extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__fastcall* PacketHandlerFn)(unsigned char* pData, int nLength, void* pArg);

struct Lock { int data[6]; };
struct NetData { int connected; int unk04; unsigned socket; Lock lock; int unk24; int unk28; int error; int closed; };
struct D2PacketQueueStrc;
struct D2NetConnectionStrc
{
    char unk0x000[0x110]; NetData* net;
    void* hEvent;
    int nHeaderSize;
    int nLengthOffset;
    int unk120; int stop; char unk128[0x40];
    PacketHandlerFn pfnHandler;
    void* pHandlerArg;
    char tQueue[0x10];
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn);                                   // 0x006CC34C
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                     // 0x006CC130
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
void __fastcall sub_006C1FF0_QueuePacket(void* pQueue, unsigned char* pData, int nLength);                  // 0x006C1FF0

__declspec(noinline) static int __stdcall sub_006BC150_SplitPackets(unsigned char* pBuffer, int nLength, D2NetConnectionStrc* pConn);

static int __stdcall sub_006BC150_SplitPackets(unsigned char* pBuffer, int nLength, D2NetConnectionStrc* pConn); // 0x006BC150

// build: context sub_006BC150_SplitPackets
static int __stdcall sub_006BC150_SplitPackets(unsigned char* pBuffer, int nLength, D2NetConnectionStrc* pConn)
{
    unsigned char* pCursor = pBuffer;
    for (;;)
    {
        const int nPacketSize = *(unsigned short*)(pCursor + pConn->nLengthOffset);
        const int nHeaderSize = pConn->nHeaderSize;
        const int nRemaining = pBuffer - pCursor + nLength;
        if (nRemaining < nHeaderSize || nRemaining < nPacketSize)
        {
            break;
        }

        D2_ASSERT(nPacketSize < 0x2064, 0xFB);

        unsigned char* pPayload = pCursor + nHeaderSize;
        const unsigned short nPayloadSize = (unsigned short)(nPacketSize - nHeaderSize);
        if (pConn->pfnHandler)
        {
            D2_ASSERT(!IsBadCodePtr(pConn->pfnHandler), 0x101);

            int bHandled;
            if (pConn->nLengthOffset > 0)
                bHandled = pConn->pfnHandler(pCursor, nPacketSize, pConn->pHandlerArg);
            else
                bHandled = pConn->pfnHandler(pPayload, nPayloadSize, pConn->pHandlerArg);

            if (!bHandled)
            {
                if (pConn->nLengthOffset > 0)
                    sub_006C1FF0_QueuePacket(pConn->tQueue, pCursor, nPacketSize);
                else
                    sub_006C1FF0_QueuePacket(pConn->tQueue, pPayload, nPayloadSize);
                SetEvent(pConn->hEvent);
            }
        }
        else
        {
            sub_006C1FF0_QueuePacket(pConn->tQueue, pPayload, nPayloadSize);
            SetEvent(pConn->hEvent);
        }

        pCursor += nPacketSize;
    }

    const int nLeft = pBuffer - pCursor + nLength;
    memmove(pBuffer, pCursor, nLeft);
    return nLeft;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(Lock*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(Lock*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned);
int __fastcall sub_0040D880(unsigned); // 0x0040D880
int __fastcall FOG_SOCKET_Select(NetData* net); // 0x0040DDF0
unsigned __fastcall FOG_SOCKET_Receive(NetData* net,unsigned char* data,unsigned length); // 0x0040DC60
void __fastcall sub_0040E0B0_GetStatus(NetData* net,int* error,int* status); // 0x0040E0B0
static __declspec(noinline) void __stdcall sub_006BC310_CloseSocket(D2NetConnectionStrc* socket);
static void __stdcall sub_006BC310_CloseSocket(D2NetConnectionStrc* socket); // 0x006BC310
// 0x006BC310
static void __stdcall sub_006BC310_CloseSocket(D2NetConnectionStrc* socket)
{
 if(!socket)return;
 NetData* net=socket->net;
 if(!(net && net->connected && net->socket))return;
 EnterCriticalSection(&net->lock);
 sub_0040D880(socket->net->socket);
 socket->net->socket=(unsigned)-1;
 socket->net->connected=0;
 LeaveCriticalSection(&socket->net->lock);
}
// 0x006BC3A0
unsigned __stdcall sub_006BC3A0_ReceiveLoop(D2NetConnectionStrc* socket)
{
 unsigned char buffer[0x2068];
 unsigned left=0;
 while(!socket->net) { if(socket->stop)goto done; Sleep(0); }
 while(!socket->stop) {
  NetData* net=socket->net;
  if(!net || !net->connected || net->error || net->closed)break;
  int ready=FOG_SOCKET_Select(net);
  if(!socket->net || socket->net->error)break;
  if(ready) {
   while(!socket->stop) {
    unsigned available=0x2064-left;
    unsigned received=FOG_SOCKET_Receive(socket->net,buffer+left,available);
    int error,status;
    sub_0040E0B0_GetStatus(socket->net,&error,&status);
    if(error || received==0 || received==(unsigned)-1) {
     NetData* n=socket->net;
     if(n && n->connected && n->socket) {
      EnterCriticalSection(&n->lock);
      sub_0040D880(socket->net->socket);
      socket->net->socket=(unsigned)-1;
      socket->net->connected=0;
      LeaveCriticalSection(&socket->net->lock);
     }
     return 0;
    }
    left=sub_006BC150_SplitPackets(buffer,received+left,socket);
    if(received<available)break;
   }
  }
 }
 done:
 sub_006BC310_CloseSocket(socket);
 return 0;
}
