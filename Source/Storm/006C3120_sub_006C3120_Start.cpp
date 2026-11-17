extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" __declspec(dllimport) void* __stdcall CreateIoCompletionPort(void* hFile, void* hExistingPort, unsigned long nKey, unsigned long nThreads); // 0x006CC124
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

struct D2SockAddrInStrc
{
    short sin_family;
    unsigned short sin_port;
    unsigned long sin_addr;
    char sin_zero[8];
};

struct T006BE350
{
    char unk0x000[0xB8C];
    int nListeners;
    unsigned int aSockets[4];
    unsigned short aPorts[4];
    int aActive[4];
    char unk0xBB8[0x20];
    void* aThreads[4];
    unsigned long aThreadIds[4];
    char unk0xBF8[0x10];
    void* aCompletionPorts[4];
    int bSecondWorker;
    void* aThreads2[4];
    unsigned long aThreadIds2[4];
};

struct D2QWorkerArgStrc
{
    T006BE350* pServer;
    int nSlot;
};

extern "C" unsigned int __stdcall socket(int af, int type, int protocol);                                   // 0x006B016E
extern "C" int __stdcall WSAGetLastError(void);                                                             // 0x006B0168
extern "C" int __stdcall setsockopt(unsigned int s, int level, int optname, const char* optval, int optlen); // 0x006B0162
extern "C" int __stdcall ioctlsocket(unsigned int s, long cmd, unsigned long* argp);                        // 0x006B015C
extern "C" unsigned short __stdcall htons(unsigned short hostshort);                                         // 0x006B0156
extern "C" int __stdcall bind(unsigned int s, const D2SockAddrInStrc* name, int namelen);                   // 0x006C9B76
extern "C" int __stdcall listen(unsigned int s, int backlog);                                               // 0x006C9B70
void __cdecl sub_00410610_WriteLogLine(const char* format, ...);                                                             // 0x00410610
int __fastcall sub_0040D880(unsigned int s);                                                                // 0x0040D880
void __fastcall sub_00407F80_ThreadHookNop2(unsigned long nThreadId, void* hThread);                        // 0x00407F80
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned long __stdcall sub_006C2860_WorkerThread(void* pArg);                                              // 0x006C2860
unsigned long __stdcall sub_006C3030_WorkerThread2(void* pArg);                                             // 0x006C3030

// 0x006C3120
unsigned int __fastcall sub_006C3120_Start(T006BE350* pServer, int nPort)
{
    void* hPort = CreateIoCompletionPort((void*)-1, 0, 0, 0);
    D2_ASSERT(hPort, 0x4E);

    unsigned int s = socket(2, 1, 0);
    if (s == (unsigned int)-1)
    {
        sub_00410610_WriteLogLine("[SERVER]  QSNTInit failed on socket() - err=%d", WSAGetLastError());
        return 0;
    }

    int bNoDelay = 1;
    setsockopt(s, 6, 1, (const char*)&bNoDelay, 4);
    int bKeepAlive = 1;
    setsockopt(s, 0xFFFF, 8, (const char*)&bKeepAlive, 4);
    int bReuseAddr = 1;
    setsockopt(s, 0xFFFF, 4, (const char*)&bReuseAddr, 4);
    unsigned long nNonBlocking = 1;
    ioctlsocket(s, 0x8004667E, &nNonBlocking);

    D2SockAddrInStrc tAddr;
    memset(&tAddr, 0, sizeof(tAddr));
    tAddr.sin_family = 2;
    tAddr.sin_port = htons(nPort);
    if (bind(s, &tAddr, sizeof(tAddr)) == -1)
    {
        sub_00410610_WriteLogLine("[SERVER]  QSNTInit failed on bind() - err=%d", WSAGetLastError());
        sub_0040D880(s);
        return 0;
    }

    if (listen(s, 0xFA) == -1)
    {
        sub_00410610_WriteLogLine("[SERVER]  QSNTInit failed on listen() - err=%d", WSAGetLastError());
        sub_0040D880(s);
        return 0;
    }

    const int nSlot = pServer->nListeners++;
    pServer->aCompletionPorts[nSlot] = hPort;
    pServer->aPorts[nSlot] = nPort;
    pServer->aSockets[nSlot] = s;
    pServer->aActive[nSlot] = 1;

    D2QWorkerArgStrc* pArg = (D2QWorkerArgStrc*)FOG_Alloc(sizeof(D2QWorkerArgStrc), ".\\Src\\QServer\\QServerNT.cpp", 0xA2, 0);
    pArg->pServer = pServer;
    pArg->nSlot = nSlot;
    pServer->aThreads[nSlot] = CreateThread(0, 0, sub_006C2860_WorkerThread, pArg, 0, &pServer->aThreadIds[nSlot]);
    sub_00407F80_ThreadHookNop2(pServer->aThreadIds[nSlot], pServer->aThreads[nSlot]);

    if (pServer->bSecondWorker)
    {
        D2QWorkerArgStrc* pArg2 = (D2QWorkerArgStrc*)FOG_Alloc(sizeof(D2QWorkerArgStrc), ".\\Src\\QServer\\QServerNT.cpp", 0xB5, 0);
        pArg2->pServer = pServer;
        pArg2->nSlot = nSlot;
        unsigned long* pThreadId = &pServer->aThreadIds2[nSlot];
        pServer->aThreads2[nSlot] = CreateThread(0, 0, sub_006C3030_WorkerThread2, pArg2, 0, pThreadId);
        sub_00407F80_ThreadHookNop2(*pThreadId, pServer->aThreads2[nSlot]);
    }

    return s;
}
