struct BnClientInterface;
struct FSafeSock;

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile* pTarget, long nValue);  // 0x006CC3A4
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock);                                                   // 0x0040DBD0
int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength);                 // 0x0040DEE0
int __fastcall sub_0040DF20_SOCKET_GetSockName(FSafeSock* pSafeSock, void* pAddress, int* pnLength);        // 0x0040DF20
void __cdecl sub_00519300_FreeCache();                                                                      // 0x00519300
void __cdecl sub_0051AC20_FreeBuffer();                                                                     // 0x0051AC20
void __cdecl sub_0051B210_FreeBuffer();                                                                     // 0x0051B210
void __cdecl sub_0051E5D0_SetStopFlag();                                                                    // 0x0051E5D0
extern "C" int __cdecl sub_0051E5E0_IsPendingCountPositive();                                               // 0x0051E5E0
void __cdecl sub_005201E0_InitMessageQueue();                                                               // 0x005201E0
int __cdecl sub_00520440_FreeMessages();                                                                    // 0x00520440
extern "C" int __cdecl sub_00520AD0_SetFlag882528();                                                        // 0x00520AD0
void __cdecl sub_00521B90_ClearSrpState();                                                                  // 0x00521B90

extern BnClientInterface gBnClientInterface_0072FAA0;                                                       // 0x0072FAA0
extern int gdwGlobal_008818BC;                                                                              // 0x008818BC
int gdwGlobal_008818C0;                                                                                     // 0x008818C0
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
extern long volatile gnReceiveThreads_00881BF4;                                                             // 0x00881BF4
extern long volatile gnDnsDone_00881BFC;                                                                    // 0x00881BFC
extern long volatile gnSendBusy_00881C00;                                                                   // 0x00881C00

// 0x00518C00
BnClientInterface* __cdecl sub_00518C00_GetInterface()
{
    sub_005201E0_InitMessageQueue();
    return &gBnClientInterface_0072FAA0;
}

// 0x0051A480
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...)
{
}

// 0x0051A540
void __fastcall sub_0051A540_SetValue(int nValue)
{
    gdwGlobal_008818BC = nValue;
}

// 0x0051A560
void __fastcall sub_0051A560_SetValue(int nValue)
{
    gdwGlobal_008818C0 = nValue;
}

// 0x0051BEC0
int __cdecl sub_0051BEC0_IsExpansion()
{
    return sub_00408F20_HasExpansionMpq();
}

// 0x0051C470
int __cdecl sub_0051C470_CloseBNetConnection()
{
    sub_0051AC20_FreeBuffer();
    sub_0051B210_FreeBuffer();
    sub_00519300_FreeCache();
    sub_00520440_FreeMessages();
    sub_00521B90_ClearSrpState();
    InterlockedExchange(&gnDnsDone_00881BFC, 1);
    while (InterlockedCompareExchange(&gnReceiveThreads_00881BF4, 0, 0))
        Sleep(10);
    const long hSocket = InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (hSocket)
    {
        sub_00520AD0_SetFlag882528();
        while (InterlockedCompareExchange(&gnSendBusy_00881C00, 0, 0))
            Sleep(10);
        if (InterlockedCompareExchange(&gnConnected_00881BF0, 0, hSocket) == hSocket)
            FOG_SOCKET_Destroy((FSafeSock*)hSocket);
    }
    sub_0051E5D0_SetStopFlag();
    while (sub_0051E5E0_IsPendingCountPositive())
        Sleep(10);
    if (InterlockedCompareExchange(&gnSendBusy_00881C00, 0, 0))
    {
        int nWaited = 0;
        do
        {
            nWaited += 100;
            Sleep(10);
            if (nWaited > 60)
                return 0;
        }
        while (InterlockedCompareExchange(&gnSendBusy_00881C00, 0, 0));
    }
    return 1;
}

// 0x0051C9B0
int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (pSocket)
        return FOG_SOCKET_GetPeerName(pSocket, pAddress, pnLength);
    return 0;
}

// 0x0051C9E0
int __fastcall sub_0051C9E0_GetSockName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (pSocket)
        return sub_0040DF20_SOCKET_GetSockName(pSocket, pAddress, pnLength);
    return 0;
}

#include "gen/data/Source/Bnclient/00518C00_sub_00518C00_GetInterface.inc"
