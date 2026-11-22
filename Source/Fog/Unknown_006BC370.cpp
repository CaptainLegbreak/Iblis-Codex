struct Lock;
struct NetData;
struct QSocket;
struct sub_006BC560_Strc;
struct D2ThreadRecord006BC5A0Strc;

struct Lock { int data[6]; };

struct NetData { char pad00[0xC]; Lock lock; void* thread; int unk28; int blocked; };

struct QSocket { char pad00[0x110]; NetData* net; };


void __fastcall sub_0040DBD0_FreeNet(NetData*); // 0x0040DBD0
static void __stdcall sub_006BC370_FreeNet(QSocket* socket);

struct sub_006BC560_Strc
{
    char unk_000[8];
    char pSocket[0x104];
    int nPort;
    int nResult;
    char unk_114[0x14];
    char pAddress[4];
};


void __stdcall sub_006BC3A0(void* pContext); // 0x006BC3A0
int __fastcall FOG_SOCKET_Connect(void* pSocket, int nPort, void (__stdcall* pfnCallback)(void*), void* pContext, void* pAddress); // 0x0040E230
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

struct D2ThreadRecord006BC5A0Strc
{
    void* hThread;
    unsigned long nThreadId;
    unsigned char unk_008[0x10C];
    void* hEvent;
    unsigned char unk_118[0xC];
    int n124;
};


unsigned long __stdcall sub_006BC560_ThreadProc(void* pParameter); // 0x006BC560

// 0x006BC370
static void __stdcall sub_006BC370_FreeNet(QSocket* socket)
{
    if (!socket)
        return;
    NetData* net = socket->net;
    if (!(net && net->thread))
        return;
    sub_0040DBD0_FreeNet(net);
    socket->net = 0;
}

void __stdcall FreeNetContext(QSocket* socket)
{
    sub_006BC370_FreeNet(socket);
}


