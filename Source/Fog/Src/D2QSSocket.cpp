#include "Fog.h"

#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); } } while (0)

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

struct FSafeSock;
struct D2ThreadRecord006BC5A0Strc;

typedef int (__fastcall* D2QSPacketHandlerFn)(unsigned char* pData, int nLength, void* pArg);

// A Safesock connection.
struct FSafeSock
{
    int bConnected;                         // 0x00
    int unk_04;                             // 0x04
    unsigned int hSocket;                   // 0x08
    char cs[0x18];                          // 0x0C
    void* hThread;                          // 0x24
    int unk_28;                             // 0x28
    int bError;                             // 0x2C
    int bClosed;                            // 0x30
};

// A queued-socket record (0x194 bytes): its receive thread, the connection and the packet queue.
struct D2ThreadRecord006BC5A0Strc
{
    void* hThread;                          // 0x000
    unsigned long nThreadId;                // 0x004
    char szName[0x104];                     // 0x008
    int nPort;                              // 0x10C
    FSafeSock* pSafeSock;                   // 0x110
    void* hEvent;                           // 0x114
    int nHeaderSize;                        // 0x118
    int nLengthOffset;                      // 0x11C
    int nValue120;                          // 0x120
    int bStop;                              // 0x124
    char szLabel[0x40];                     // 0x128
    D2QSPacketHandlerFn pfnHandler;         // 0x168
    void* pHandlerArg;                      // 0x16C
    char tQueue[0x24];                      // 0x170
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __fastcall sub_006C1F60_InitLockedList(void* pList); // 0x006C1F60
void __fastcall sub_006C1F80(void* pQueue); // 0x006C1F80
void __fastcall sub_006C1FF0_QueuePacket(void* pQueue, unsigned char* pData, unsigned short nLength); // 0x006C1FF0
extern const char gszSocketFile[]; // 0x006FC418
extern const char gszUnknown_006CCED8[]; // 0x006CCED8

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C

int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0
unsigned int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, unsigned char* pData, unsigned int nLength); // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock); // 0x0040DDF0
void __fastcall sub_0040E0B0_GetStatus(FSafeSock* pSafeSock, int* pnError, int* pnStatus); // 0x0040E0B0
FSafeSock* __fastcall FOG_SOCKET_Connect(void* pSocket, int nPort, void (__stdcall* pfnCallback)(void*), void* pContext, void* pAddress); // 0x0040E230

static int __stdcall sub_006BC150_SplitPackets(unsigned char* pBuffer, int nLength, D2ThreadRecord006BC5A0Strc* pRecord);
static void sub_006BC2C0_SetClosing(D2ThreadRecord006BC5A0Strc* pRecord);
static void sub_006BC310_CloseSocket(D2ThreadRecord006BC5A0Strc* pRecord);
static void __stdcall sub_006BC370_FreeNet(D2ThreadRecord006BC5A0Strc* pRecord);

// 0x006BC150
static int __stdcall sub_006BC150_SplitPackets(unsigned char* pBuffer, int nLength, D2ThreadRecord006BC5A0Strc* pRecord)
{
    unsigned char* pCursor = pBuffer;
    int nPacketSize, nHeaderSize, nRemaining;
    while (nRemaining = pBuffer - pCursor + nLength, nPacketSize = *(unsigned short*)(pCursor + pRecord->nLengthOffset),
           nHeaderSize = pRecord->nHeaderSize, nRemaining >= nHeaderSize ? nRemaining >= nPacketSize : false)
    {

        D2_ASSERT(nPacketSize < 0x2064, 0xFB);

        unsigned char* pPayload = pCursor + nHeaderSize;
        const unsigned short nPayloadSize = (unsigned short)(nPacketSize - nHeaderSize);
        if (pRecord->pfnHandler)
        {
            D2_ASSERT(!IsBadCodePtr((void*)pRecord->pfnHandler), 0x101);

            int bHandled;
            if (pRecord->nLengthOffset > 0)
                bHandled = pRecord->pfnHandler(pCursor, nPacketSize, pRecord->pHandlerArg);
            else
                bHandled = pRecord->pfnHandler(pPayload, nPayloadSize, pRecord->pHandlerArg);

            if (!bHandled)
            {
                if (pRecord->nLengthOffset > 0)
                    sub_006C1FF0_QueuePacket(pRecord->tQueue, pCursor, nPacketSize);
                else
                    sub_006C1FF0_QueuePacket(pRecord->tQueue, pPayload, nPayloadSize);
                SetEvent(pRecord->hEvent);
            }
        }
        else
        {
            sub_006C1FF0_QueuePacket(pRecord->tQueue, pPayload, nPayloadSize);
            SetEvent(pRecord->hEvent);
        }

        pCursor += nPacketSize;
    }

    const int nLeft = pBuffer - pCursor + nLength;
    memcpy(pBuffer, pCursor, nLeft);
    return nLeft;
}

// 0x006BC290
void __stdcall sub_006BC290_SetValues(D2ThreadRecord006BC5A0Strc* pRecord, int nA, int nB, int nC)
{
    if (pRecord)
    {
        pRecord->nHeaderSize = nA;
        pRecord->nLengthOffset = nB;
        pRecord->nValue120 = nC;
    }
}

// 0x006BC2C0
static void sub_006BC2C0_SetClosing(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->hThread)
    {
        pRecord->bStop = 1;
        EnterCriticalSection((CRITICAL_SECTION*)pRecord->pSafeSock->cs);
        pRecord->pSafeSock->bError = 1;
        LeaveCriticalSection((CRITICAL_SECTION*)pRecord->pSafeSock->cs);
    }
}

// 0x006BC310
static void sub_006BC310_CloseSocket(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->bConnected && pRecord->pSafeSock->hSocket)
    {
        EnterCriticalSection((CRITICAL_SECTION*)pRecord->pSafeSock->cs);
        sub_0040D880(pRecord->pSafeSock->hSocket);
        pRecord->pSafeSock->hSocket = (unsigned int)-1;
        pRecord->pSafeSock->bConnected = 0;
        LeaveCriticalSection((CRITICAL_SECTION*)pRecord->pSafeSock->cs);
    }
}

// 0x006BC370
static void __stdcall sub_006BC370_FreeNet(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (!pRecord)
        return;
    FSafeSock* pSafeSock = pRecord->pSafeSock;
    if (!(pSafeSock && pSafeSock->hThread))
        return;
    FOG_SOCKET_Destroy(pSafeSock);
    pRecord->pSafeSock = 0;
}

void __stdcall FreeNetContext(D2ThreadRecord006BC5A0Strc* pRecord)
{
    sub_006BC370_FreeNet(pRecord);
}

// 0x006BC3A0
unsigned long __stdcall sub_006BC3A0_ReceiveLoop(D2ThreadRecord006BC5A0Strc* pRecord)
{
    unsigned char buffer[0x2068];
    unsigned int nLeft = 0;
    while (!pRecord->pSafeSock)
    {
        if (pRecord->bStop)
            goto done;
        Sleep(0);
    }
    while (!pRecord->bStop)
    {
        FSafeSock* pSafeSock = pRecord->pSafeSock;
        if (!pSafeSock || !pSafeSock->bConnected || pSafeSock->bError || pSafeSock->bClosed)
            break;
        int bReady = FOG_SOCKET_Select(pSafeSock);
        if (!pRecord->pSafeSock || pRecord->pSafeSock->bError)
            break;
        if (bReady)
        {
            while (!pRecord->bStop)
            {
                unsigned int nAvailable = 0x2064 - nLeft;
                unsigned int nReceived = FOG_SOCKET_Receive(pRecord->pSafeSock, buffer + nLeft, nAvailable);
                int nError, nStatus;
                sub_0040E0B0_GetStatus(pRecord->pSafeSock, &nError, &nStatus);
                if (nError || nReceived == 0 || nReceived == (unsigned int)-1)
                {
                    FSafeSock* pSock = pRecord->pSafeSock;
                    if (pSock && pSock->bConnected && pSock->hSocket)
                    {
                        EnterCriticalSection((CRITICAL_SECTION*)pSock->cs);
                        sub_0040D880(pRecord->pSafeSock->hSocket);
                        pRecord->pSafeSock->hSocket = (unsigned int)-1;
                        pRecord->pSafeSock->bConnected = 0;
                        LeaveCriticalSection((CRITICAL_SECTION*)pRecord->pSafeSock->cs);
                    }
                    return 0;
                }
                nLeft = sub_006BC150_SplitPackets(buffer, nReceived + nLeft, pRecord);
                if (nReceived < nAvailable)
                    break;
            }
        }
    }
done:
    sub_006BC310_CloseSocket(pRecord);
    return 0;
}

// 0x006BC560
int __stdcall sub_006BC560_Connect(D2ThreadRecord006BC5A0Strc* pRecord)
{
    pRecord->pSafeSock = FOG_SOCKET_Connect(pRecord->szName, pRecord->nPort, (void (__stdcall*)(void*))sub_006BC3A0_ReceiveLoop, pRecord, pRecord->szLabel);
    return 1;
}

// 0x006BC5A0
void __stdcall sub_006BC5A0_StartThread(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && !pRecord->hThread)
    {
        pRecord->bStop = 0;
        pRecord->hEvent = CreateEventA(0, 0, 0, 0);
        pRecord->hThread = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))sub_006BC560_Connect, pRecord, 0, &pRecord->nThreadId);
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
    pRecord->bStop = 0;
    pRecord->hEvent = CreateEventA(0, 0, 0, 0);
    pRecord->hThread = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))sub_006BC560_Connect, pRecord, 0, &pRecord->nThreadId);
    return pRecord->hThread;
}

// 0x006BC680
void __stdcall sub_006BC680_Signal(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord)
        sub_006BC2C0_SetClosing(pRecord);
}

// 0x006BC6A0
D2ThreadRecord006BC5A0Strc* __stdcall sub_006BC6A0_AllocSocketRecord(const char* szName, int nPort, const char* szLabel)
{
    D2_ASSERT(szName, 0x242);
    D2_ASSERT(strlen(szName) < 0x103, 0x243);
    D2ThreadRecord006BC5A0Strc* pRecord = (D2ThreadRecord006BC5A0Strc*)FOG_Alloc(sizeof(D2ThreadRecord006BC5A0Strc), gszSocketFile, 0x245, 0);
    if (pRecord)
    {
        memset(pRecord, 0, sizeof(D2ThreadRecord006BC5A0Strc));
        SStrCopy(pRecord->szName, szName, 0x104);
        if (szLabel)
            SStrCopy(pRecord->szLabel, szLabel, 4);
        else
            SStrCopy(pRecord->szLabel, gszUnknown_006CCED8, 0x40);
        pRecord->nPort = nPort;
        sub_006C1F60_InitLockedList(pRecord->tQueue);
        pRecord->nHeaderSize = 2;
        pRecord->nLengthOffset = 0;
    }
    return pRecord;
}

// 0x006BC780
void __stdcall sub_006BC780_Destroy(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord)
    {
        sub_006BC2C0_SetClosing(pRecord);
        sub_006C1F80(pRecord->tQueue);
        if (pRecord->pSafeSock && pRecord->pSafeSock->hThread)
        {
            FOG_SOCKET_Destroy(pRecord->pSafeSock);
            pRecord->pSafeSock = 0;
        }
        FOG_Free(pRecord, ".\\Src\\D2QSSocket.cpp", 636, 0);
    }
}
