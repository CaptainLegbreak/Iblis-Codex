#include "D2BNClient.h"
#include "D2Primitives.h"
#include "D2NetTypes.h"
#include "D2BnMessages.h"
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __fastcall BNSEND_DispatchPacket(unsigned char nId, const void* pData, int nSize);       // 0x00521B00

#define FD_ZERO(set) (((D2FdSetStrc*)(set))->fd_count = 0)
#define FD_SET(fd, set) do { \
    if (((D2FdSetStrc*)(set))->fd_count < 64) \
        ((D2FdSetStrc*)(set))->fd_array[((D2FdSetStrc*)(set))->fd_count++] = (fd); \
} while (0)
struct D2BnCheckAdReplyStrc;
struct D2CriticalSectionStrc;
struct D2BnStateStrc;
struct D2BnServerEntryStrc;

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
extern long volatile gnConnected; // 0x00881BF0
extern int gbReady; // 0x00881BF8

struct D2BnServerEntryStrc
{
    char szAddress[0x100];
    FSafeSock* pSafeSock;
    int nUnused;
};

unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter); // 0x0051C7E0
int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState); // 0x005205F0
extern long volatile gnDnsDone; // 0x00881BFC

long volatile gnReceiveThreads; // 0x00881BF4

long volatile gnDnsDone; // 0x00881BFC

int gbDnsPending; // 0x008818E0

long volatile gnConnected; // 0x00881BF0

int gbReady; // 0x00881BF8

// build: symbol ?BNDOWNLOAD_IsReady@* 0x0051CA30
int __cdecl BNDOWNLOAD_IsReady()
{
    D2BnStateStrc tState;
    sub_005205F0_GetState(&tState);
// build: symbol ?GAME_GetAbortFlag@* 0x00520AE0
    if (!GAME_GetAbortFlag() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected, 0, 0))
        return 1;
    return 0;
}

// 0x0051C760
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength)
{
    unsigned char* p = pBuffer;
    for (;;)
    {
        while (*p != 0xFF && p - pBuffer < nLength)
            ++p;
        const unsigned short nSize = *(unsigned short*)(p + 2);
        const int nLeft = pBuffer + nLength - p;
        if ((unsigned int)nLeft < 4 || nLeft < nSize)
            break;
        BNSEND_DispatchPacket(p[1], p + 4, nSize - 4);
        p += nSize;
    }
    const int nRemain = pBuffer + nLength - p;
    memcpy(pBuffer, p, nRemain);
    return nRemain;
}
// 0x0051C7E0
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000 + 1];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone, 0, 0) && !gbReady)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], 0x2000 - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = sub_0051C760_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            BNSEND_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads);
    return nResult;
}

