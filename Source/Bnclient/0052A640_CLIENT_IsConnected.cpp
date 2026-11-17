struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2NetPacketRecStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_0040D880(unsigned int s);                                                                // 0x0040D880
int __fastcall NET_IsLocalConnection();                                                                     // 0x0052B7E0
int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList);    // 0x0052B8B0

extern int gClientSocket;                                                                                   // 0x00730AE0
extern void* gpPacketBuffer;                                                                                // 0x00882B34
void* ghReceiveThread_00882CD8;                                                                             // 0x00882CD8
extern D2NetPacketRecStrc* gpSystemPacketList;                                                                    // 0x00882CDC
extern D2NetPacketRecStrc* gpGamePacketList;                                                                      // 0x00882CE4
extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern int gdwGlobal_00882D00;                                                                              // 0x00882D00
extern int gbConnected_00882D04;                                                                            // 0x00882D04

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
