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
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress);                                            // 0x0052A680
int __fastcall NET_IsLocalConnection();                                                                     // 0x0052B7E0
void __fastcall sub_0052B810(int nArg);                                                                     // 0x0052B810

unsigned long gdwThreadId;                                                                                  // 0x00882B30
void* ghClientConnectToHostThreadHandle;                                                                    // 0x00882CE0
extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern int gbConnected_00882D04;                                                                            // 0x00882D04

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
