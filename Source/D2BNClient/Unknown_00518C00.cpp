#include "D2BNClient.h"
#include "FogApi.h"
#include "FogApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct BnClientInterface;

struct D2CacheHeaderStrc;

struct D2CacheHashEntryStrc;

struct D2CacheBlockEntryStrc;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0

void __cdecl CACHE_FreeCache(); // 0x00519300

void __cdecl BNSEND_FreeChannelList(); // 0x0051AC20

void __cdecl BNSEND_FreeGamesList(); // 0x0051B210

void __cdecl BNDOWNLOAD_StopDownloads(); // 0x0051E5D0

extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads(); // 0x0051E5E0

void __cdecl BNMESSQUEUE_InitMessageQueue(); // 0x005201E0

int __cdecl BNMESSQUEUE_FreeAllMessages(); // 0x00520440

extern "C" int __cdecl BNDOWNLOAD_SetDisconnected(); // 0x00520AD0

void __cdecl sub_00521B90_ClearSrpState(); // 0x00521B90

extern BnClientInterface gtBnClientInterface; // 0x0072FAA0

extern int gdwServerToken; // 0x008818BC

extern long volatile gnConnected; // 0x00881BF0

extern long volatile gnReceiveThreads; // 0x00881BF4

extern long volatile gnDnsDone; // 0x00881BFC

extern long volatile gnSendBusy; // 0x00881C00


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CacheHeaderStrc
{
    char unk0x00[0x18];
    unsigned int nHashTableSize;
    unsigned int f_1C;
};

struct D2CacheBlockEntryStrc
{
    char unk0x00[0x08];
    unsigned int dwFieldA;
    unsigned int dwFieldB;
};

extern D2CacheHeaderStrc* gpCacheHeader; // 0x00881880

extern D2CacheBlockEntryStrc* gpCacheBlockTable; // 0x00881884

extern unsigned int* gpCacheTable_00881888; // 0x00881888

extern D2CacheHashEntryStrc* gpCacheHashTable; // 0x0088188C

extern const char gszH08EmitKey[];

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, void* pFileTime); // 0x006CC26C

int __cdecl sub_0051C470_CloseBNetConnection();

int gnLogonType; // 0x008818C0

// 0x00518C00
BnClientInterface* __cdecl sub_00518C00_GetInterface()
{
    BNMESSQUEUE_InitMessageQueue();
    return &gtBnClientInterface;
}

// 0x0051A480
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...)
{
}

// 0x0051A540
void __fastcall sub_0051A540_SetValue(int nValue)
{
    gdwServerToken = nValue;
}

// 0x0051A550
int __cdecl BNCLIENT_GetServerToken()
{
    return gdwServerToken;
}

// 0x0051A560
void __fastcall sub_0051A560_SetValue(int nValue)
{
    gnLogonType = nValue;
}

// 0x0051BEC0
int __cdecl sub_0051BEC0_IsExpansion()
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    return FOG_IsExpansion();
}

// 0x0051C470
int __cdecl sub_0051C470_CloseBNetConnection()
{
    BNSEND_FreeChannelList();
    BNSEND_FreeGamesList();
    CACHE_FreeCache();
    BNMESSQUEUE_FreeAllMessages();
    sub_00521B90_ClearSrpState();
    InterlockedExchange(&gnDnsDone, 1);
    while (InterlockedCompareExchange(&gnReceiveThreads, 0, 0))
        Sleep(10);
    const long hSocket = InterlockedCompareExchange(&gnConnected, 0, 0);
    if (hSocket)
    {
        BNDOWNLOAD_SetDisconnected();
        while (InterlockedCompareExchange(&gnSendBusy, 0, 0))
            Sleep(10);
        if (InterlockedCompareExchange(&gnConnected, 0, hSocket) == hSocket)
            FOG_SOCKET_Destroy((FSafeSock*)hSocket);
    }
    BNDOWNLOAD_StopDownloads();
    while (BNDOWNLOAD_HasPendingDownloads())
        Sleep(10);
    if (InterlockedCompareExchange(&gnSendBusy, 0, 0))
    {
        int nWaited = 0;
        do
        {
            nWaited += 100;
            Sleep(10);
            if (nWaited > 60)
                return 0;
        }
        while (InterlockedCompareExchange(&gnSendBusy, 0, 0));
    }
    return 1;
}

// 0x0051C9B0
int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (pSocket)
        return FOG_SOCKET_GetPeerName(pSocket, pAddress, pnLength);
    return 0;
}

// 0x0051C9E0
int __fastcall sub_0051C9E0_GetSockName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (pSocket)
        return FOG_SOCKET_GetSockName(pSocket, pAddress, pnLength);
    return 0;
}

#include "gen/data/Source/D2BNClient/Unknown_00518C00.inc"
