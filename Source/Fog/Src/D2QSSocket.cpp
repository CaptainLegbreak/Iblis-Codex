#include "Fog.h"

struct sub_006BC290_Strc
{
    char unk_000[0x118];
    int nValue118;
    int nValue11C;
    int nValue120;
};

#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); } } while (0)

struct T006BC290;

struct FSafeSock;

struct sub_006BC780_Strc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const char gszAssert_006CC837[]; // 0x006CC837

extern "C" unsigned int __cdecl strlen(const char*);

extern "C" void* __cdecl memset(void*, int, unsigned int);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __fastcall sub_006C1F60_InitLockedList(void* pList); // 0x006C1F60

extern const char gszSocketFile[]; // 0x006FC418

extern const char gszUnknown_006CCED8[]; // 0x006CCED8

struct T006BC290
{
    char unk_00[8];
    char szName[0x104];
    int nValue;
    char unk_110[8];
    int nState;
    int nZero;
    char unk_120[8];
    char szLabel[0x40];
    char unk_168[8];
    char tList[0x24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct FSafeSock
{
    char unk_00[0x0C];
    char cs[0x18];
    int bActive;
    int unk_28;
    int bClosing;
};

struct sub_006BC780_Strc
{
    char unk_000[0x110];
    FSafeSock* pConn;
    char unk_114[0x10];
    int bClosing;
    char unk_128[0x48];
    char pQueue[4];
};

void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_006C1F80(void* pQueue); // 0x006C1F80

static void sub_006BC2C0_SetClosing(sub_006BC780_Strc* pThis);

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

struct sub_006BC2C0_Conn
{
    char unk_00[0x0C];
    char cs[0x18];
    int bActive;
    int unk_28;
    int bClosing;
};

struct sub_006BC2C0_Strc
{
    char unk_000[0x110];
    sub_006BC2C0_Conn* pConn;
    char unk_114[0x10];
    int bClosing;
};

struct sub_006BC310_Conn
{
    int bOpen;
    int unk_04;
    int hSocket;
    char cs[0x18];
};

struct sub_006BC310_Strc
{
    char unk_000[0x110];
    sub_006BC310_Conn* pConn;
};

int __fastcall sub_0040D880(unsigned int s); // 0x0040D880

static void sub_006BC310_CloseSocket(sub_006BC310_Strc* pThis);

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

// 0x006BC290
void __stdcall sub_006BC290_SetValues(sub_006BC290_Strc* pThis, int nA, int nB, int nC)
{
    if (pThis)
    {
        pThis->nValue118 = nA;
        pThis->nValue11C = nB;
        pThis->nValue120 = nC;
    }
}

// 0x006BC6A0
T006BC290* __stdcall sub_006BC6A0_AllocSocketRecord(const char* szName, int nValue, const char* szLabel)
{
    D2_ASSERT(szName, 0x242);
    D2_ASSERT(strlen(szName) < 0x103, 0x243);
    T006BC290* pRecord = (T006BC290*)FOG_Alloc(sizeof(T006BC290), gszSocketFile, 0x245, 0);
    if (pRecord)
    {
        memset(pRecord, 0, sizeof(T006BC290));
        SStrCopy(pRecord->szName, szName, 0x104);
        if (szLabel)
            SStrCopy(pRecord->szLabel, szLabel, 4);
        else
            SStrCopy(pRecord->szLabel, gszUnknown_006CCED8, 0x40);
        pRecord->nValue = nValue;
        sub_006C1F60_InitLockedList(pRecord->tList);
        pRecord->nState = 2;
        pRecord->nZero = 0;
    }
    return pRecord;
}

// 0x006BC780
void __stdcall sub_006BC780_Destroy(sub_006BC780_Strc* pThis)
{
    if (pThis)
    {
        sub_006BC2C0_SetClosing(pThis);
        sub_006C1F80(pThis->pQueue);
        if (pThis->pConn && pThis->pConn->bActive)
        {
            FOG_SOCKET_Destroy(pThis->pConn);
            pThis->pConn = 0;
        }
        FOG_Free(pThis, ".\\Src\\D2QSSocket.cpp", 636, 0);
    }
}

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

// 0x006BC560
int __stdcall sub_006BC560_Connect(sub_006BC560_Strc* pThis)
{
    pThis->nResult = FOG_SOCKET_Connect(pThis->pSocket, pThis->nPort, sub_006BC3A0, pThis, pThis->pAddress);
    return 1;
}

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

// 0x006BC5A0
void __stdcall sub_006BC5A0_StartThread(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && !pRecord->hThread)
    {
        pRecord->n124 = 0;
        pRecord->hEvent = CreateEventA(0, 0, 0, 0);
        pRecord->hThread = CreateThread(0, 0, sub_006BC560_ThreadProc, pRecord, 0, &pRecord->nThreadId);
        while (WaitForSingleObject(pRecord->hThread, 0))
        {
            Sleep(10);
        }
    }
}

// 0x006BC620
void* __stdcall sub_006BC620_StartThread(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (!pRecord)
        return 0;
    if (pRecord->hThread)
        return 0;
    pRecord->n124 = 0;
    pRecord->hEvent = CreateEventA(0, 0, 0, 0);
    pRecord->hThread = CreateThread(0, 0, sub_006BC560_ThreadProc, pRecord, 0, &pRecord->nThreadId);
    return pRecord->hThread;
}

// 0x006BC680
void __stdcall sub_006BC680_Signal(sub_006BC780_Strc* pThis)
{
    if (pThis)
        sub_006BC2C0_SetClosing(pThis);
}

// 0x006BC2C0
static void sub_006BC2C0_SetClosing(sub_006BC780_Strc* pThis)
{
    if (pThis && pThis->pConn && pThis->pConn->bActive)
    {
        pThis->bClosing = 1;
        EnterCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
        pThis->pConn->bClosing = 1;
        LeaveCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
    }
}

// 0x006BC310
static void sub_006BC310_CloseSocket(sub_006BC310_Strc* pThis)
{
    if (pThis && pThis->pConn && pThis->pConn->bOpen && pThis->pConn->hSocket)
    {
        EnterCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
        sub_0040D880(pThis->pConn->hSocket);
        pThis->pConn->hSocket = -1;
        pThis->pConn->bOpen = 0;
        LeaveCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
    }
}

// calling-convention shim (not game code)
int __stdcall sub_006BC310_Shim(sub_006BC310_Strc* pThis)
{
    sub_006BC310_CloseSocket(pThis);
    return (int)pThis->pConn;
}

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
