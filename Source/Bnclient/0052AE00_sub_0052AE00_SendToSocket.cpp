extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX_MSG_SIZE 0x204

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags);          // 0x006B017A
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
int __fastcall NET_IsLocalConnection();                                                                     // 0x0052B7E0
int __fastcall sub_0052B690_SendToServer(const unsigned char* pBuffer, unsigned short nSize);               // 0x0052B690

extern int gClientSocket;                                                                                   // 0x00730AE0
extern void* gpPacketBuffer;                                                                                // 0x00882B34
extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern int gbConnected_00882D04;                                                                            // 0x00882D04

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
