#include "D2Net.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAX_MSG_SIZE 0x204

struct D2NetPacketRecStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress); // 0x0052A680
int __fastcall NET_IsLocalConnection(); // 0x0052B7E0
extern D2CriticalSectionStrc gCriticalSection; // 0x00882CE8
extern int gbConnected_00882D04; // 0x00882D04
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList); // 0x0052B8B0
extern void* gpPacketBuffer; // 0x00882B34
extern D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC
extern D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4
extern int gdwGlobal_00882D00; // 0x00882D00
int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052B820
int __fastcall sub_0052B690_SendToServer(const unsigned char* pBuffer, unsigned short nSize); // 0x0052B690
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A

unsigned long gdwThreadId; // 0x00882B30

void* ghClientConnectToHostThreadHandle; // 0x00882CE0

// 0x0052A610
void __fastcall sub_0052A610_SetConnected(int bConnected)
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = bConnected;
        LeaveCriticalSection(&gCriticalSection);
    }
}

// 0x0052A730
static __forceinline void sub_0052A730_StartConnectThread(const char* szIpAddress)
{
    ghClientConnectToHostThreadHandle = CreateThread(0, 0, CLIENT_ConnectToHost, (void*)szIpAddress, 0, &gdwThreadId);
}

// 0x0052AAD0
void __cdecl sub_0052AAD0_ClearConnected()
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
}

// 0x0052AAA0
void __cdecl sub_0052AAA0_OnSocketError()
{
    WSAGetLastError();
    sub_0052AAD0_ClearConnected();
}

void __stdcall sub_M118_Emit_0052A730(int nArg, const char* szIpAddress)
{
    sub_0052B810(nArg);
    if (NET_IsLocalConnection())
    {
        return;
    }
    sub_0052A730_StartConnectThread(szIpAddress);
}

void* ghReceiveThread_00882CD8; // 0x00882CD8

// 0x0052A640
int __cdecl CLIENT_IsConnected()
{
    if (NET_IsLocalConnection())
    {
        return 1;
    }

    if (!gpPacketBuffer)
    {
        return 0;
    }

    EnterCriticalSection(&gCriticalSection);
    const int bConnected = gbConnected_00882D04;
    LeaveCriticalSection(&gCriticalSection);

    return bConnected;
}

// 0x0052A7E0
void __cdecl CLIENT_Release()
{
    EnterCriticalSection(&gCriticalSection);

    if (gpPacketBuffer)
    {
        FOG_Free(gpPacketBuffer, ".\\SRC\\Client.cpp", 0xDA, 0);
    }

    gpPacketBuffer = 0;
    gdwGlobal_00882D00 = 1;

    LeaveCriticalSection(&gCriticalSection);

    WaitForSingleObject(ghReceiveThread_00882CD8, 6000);

    NET_FreePacketList(&gCriticalSection, &gpSystemPacketList);
    NET_FreePacketList(&gCriticalSection, &gpGamePacketList);

    DeleteCriticalSection(&gCriticalSection);

    if (NET_IsLocalConnection())
    {
        return;
    }

    const int nResult = sub_0040D880(gClientSocket);
    gClientSocket = -1;
    if (nResult == -1)
    {
        WSAGetLastError();
    }
}

// 0x0052A890
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpGamePacketList, pBuffer, nBufferSize);
}

// 0x0052A8B0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpSystemPacketList, pBuffer, nBufferSize);
}

// 0x0052ADC0
int __fastcall sub_0052ADC0_SendToServerChecked(void* pUnused, unsigned short nSize, const unsigned char* pBuffer)
{
    D2_ASSERT(nSize <= 0x204, 0x1C6);
    return sub_0052B690_SendToServer(pBuffer, nSize);
}

// 0x0052AE00
static __declspec(noinline) int sub_0052AE00_SendToSocket(const unsigned char* pBuffer, int nSize)
{
    const int nSent = send(gClientSocket, (const char*)pBuffer, nSize, 0);
    if (nSent != -1)
    {
        return nSent;
    }

    WSAGetLastError();
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
    return 0;
}

// 0x0052AE50
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData)
{
    const unsigned char* pBuffer = (const unsigned char*)pData;
    if (!gpPacketBuffer)
    {
        return 0;
    }

    if (NET_IsLocalConnection())
    {
        const unsigned short nPacketSize = nSize;
        D2_ASSERT(nPacketSize <= MAX_MSG_SIZE, 0x1C6);
        return sub_0052B690_SendToServer(pBuffer, nPacketSize);
    }

    return sub_0052AE00_SendToSocket(pBuffer, nSize);
}
