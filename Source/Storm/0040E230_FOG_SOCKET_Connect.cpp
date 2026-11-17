struct FSafeSock;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2LogMsgLinkStrc
{
    D2LogMsgLinkStrc* m_prevlink;
    char* m_next;
};

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2LogMsgLinkStrc m_terminator;

    void sub_0040FED0_DeleteAll();                                          // 0x0040FED0
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking); // 0x0040D8E0

extern int gnLogQueued_0075D140;                                                                            // 0x0075D140
extern int gnLogQueuedBytes_0075D144;                                                                       // 0x0075D144
void* ghLogThread_0075D2E8;                                                                                 // 0x0075D2E8
extern int gbLogInitialized_0075D2EC;                                                                       // 0x0075D2EC
int gbLogThreadStop_0075E830;                                                                               // 0x0075E830
extern unsigned long gnLogThreadId_0075E834;                                                                // 0x0075E834
extern D2CriticalSectionStrc gtLogQueueLock_0075E838;                                                       // 0x0075E838
extern D2LogMsgListStrc gtLogMsgQueue_0075E868;                                                             // 0x0075E868
extern D2CriticalSectionStrc gTimeLock_0075E880;                                                            // 0x0075E880

// 0x0040E230
FSafeSock* __fastcall FOG_SOCKET_Connect(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName)
{
    return FOG_SOCKET_ConnectEx(szHostAddress, nPortNumber, pThreadProc, lpParameter, szName, 0);
}

// 0x0040FFD0
void __cdecl sub_0040FFD0_ShutdownLogSystem()
{
    gbLogThreadStop_0075E830 = 1;
    WaitForSingleObject(ghLogThread_0075D2E8, 30000);
    CloseHandle(ghLogThread_0075D2E8);
    EnterCriticalSection(&gtLogQueueLock_0075E838);
    gtLogMsgQueue_0075E868.sub_0040FED0_DeleteAll();
    gnLogQueued_0075D140 = 0;
    gnLogQueuedBytes_0075D144 = 0;
    ghLogThread_0075D2E8 = 0;
    gnLogThreadId_0075E834 = 0;
    gbLogInitialized_0075D2EC = 0;
    gbLogThreadStop_0075E830 = 0;
    LeaveCriticalSection(&gtLogQueueLock_0075E838);
}

// 0x004107A0
void __cdecl sub_004107A0_DeleteTimeLock()
{
    DeleteCriticalSection(&gTimeLock_0075E880);
}
