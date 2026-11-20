struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2QSrvConnectionStrc
{
    unsigned char unk_00[0x0C];
    int bClosing;
    unsigned int hSocket;
    unsigned char unk_14[0x18];
    D2CriticalSectionStrc tLock;
};

struct D2QSrvServerStrc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

D2QSrvConnectionStrc* __fastcall sub_006BE540_Find(D2QSrvServerStrc* pServer, int nKey);                   // 0x006BE540
int __fastcall sub_0040D880_CloseSocket(unsigned int hSocket);                                              // 0x0040D880
void __fastcall sub_006C0360_RemoveConnection(D2QSrvServerStrc* pServer, D2QSrvConnectionStrc* pConnection); // 0x006C0360
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

struct D2QSrvAutoLock
{
    D2CriticalSectionStrc* m_pLock;

    D2QSrvAutoLock(D2CriticalSectionStrc* pLock)
    {
        m_pLock = pLock;
        EnterCriticalSection(m_pLock);
    }
    // 0x006BE530
    ~D2QSrvAutoLock()
    {
        LeaveCriticalSection(m_pLock);
    }
};

// 0x006C0420
void __fastcall QSrvCloseRemoteConnection(D2QSrvServerStrc* pServer, int nKey, const char* szFile, int nLine)
{
    D2QSrvAutoLock tLock(&pServer->tLock);

    D2QSrvConnectionStrc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection)
        return;

    EnterCriticalSection(&pConnection->tLock);
    if (pConnection->bClosing)
    {
        LeaveCriticalSection(&pConnection->tLock);
        return;
    }

    pConnection->bClosing = 1;
    int nResult = sub_0040D880_CloseSocket(pConnection->hSocket);
    pConnection->hSocket = (unsigned int)-1;
    LeaveCriticalSection(&pConnection->tLock);

    if (nResult)
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "[QSrvCloseRemoteConnection] *** closesocket() err = %d ***", WSAGetLastError());

    sub_006C0360_RemoveConnection(pServer, pConnection);
    if (nResult == -1)
        WSAGetLastError();
}
