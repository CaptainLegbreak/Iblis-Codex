extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

int __cdecl SLogWrite(void* hLog, const char* szFormat, ...);                                               // 0x00420190
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned long __stdcall sub_0051BEE0(void* pArguments);                                                    // 0x0051BEE0
void __fastcall sub_0051D260_SelectVersion(int bAlternate);                                                 // 0x0051D260
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00
void __fastcall sub_0051AE10_Send(const char* szArg1, const char* szArg2, int nArg3);                      // 0x0051AE10
void __fastcall sub_0051ACA0_SendString(const char* szText, int nArg2, int nArg3);                         // 0x0051ACA0
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply);                                             // 0x00520B70
int __cdecl sub_00520AE0();                                                                                 // 0x00520AE0
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int __fastcall sub_00520520_SetState(int nState);                                                           // 0x00520520

struct D2BnStateStrc
{
    int nState;
    void* pArg;
};

int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState);                                                // 0x005205F0

struct D2BnDnsArgsStrc
{
    char* szResult;
    const char* f_4;
};

struct D2BnMessageStrc
{
    int nId;
    char szText[0x120];
    unsigned int nLength;
    D2BnMessageStrc* pNext;
};

struct D2BnLogStrc
{
    void* hLog;

    void sub_00518BA0_LogWrite(const char* szText);
};

extern int gbDnsPending_008818E0;                                                                           // 0x008818E0
D2BnDnsArgsStrc gDnsArgs_00881BE8;                                                                          // 0x00881BE8
extern long gnConnected_00881BF0;                                                                           // 0x00881BF0
extern long gnDnsDone_00881BFC;                                                                             // 0x00881BFC
extern unsigned int gnPercent_00881C50;                                                                     // 0x00881C50
extern D2CriticalSectionStrc gMessageLock_00882004;                                                         // 0x00882004
extern D2BnMessageStrc* gpMessageHead_00882020;                                                             // 0x00882020
extern D2BnMessageStrc* gpMessageTail_00882024;                                                             // 0x00882024
extern "C" const char szBnMessQueueFile_006DF78C[];                                                         // 0x006DF78C

// 0x00518BA0
void D2BnLogStrc::sub_00518BA0_LogWrite(const char* szText)
{
    SLogWrite(hLog, szText);
}

// 0x0051BE80
long __cdecl sub_0051BE80_CompareExchange(long* pDestination, long nExchange, long nComparand)
{
    return InterlockedCompareExchange(pDestination, nExchange, nComparand);
}

// 0x0051C0E0
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost)
{
    gbDnsPending_008818E0 = 1;
    Sleep(10);
    *szResult = 0;
    unsigned long dwThreadId = 0;
    gDnsArgs_00881BE8.szResult = szResult;
    gDnsArgs_00881BE8.f_4 = szHost;
    void* hThread = CreateThread(0, 0, sub_0051BEE0, &gDnsArgs_00881BE8, 0, &dwThreadId);
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        if (WaitForSingleObject(hThread, 0) == 0)
            break;
        Sleep(10);
    }
}

// 0x0051C3E0
int __fastcall sub_0051C3E0_EnterChat(const char* szArg1, const char* szArg2, int nArg3, const char* szText, int nFlags)
{
    const int bAlternate = nFlags & 1;
    sub_0051D260_SelectVersion(bAlternate);
    sub_00520C00_ClearReply(10);
    sub_0051AE10_Send(szArg1, szArg2, nArg3);
    if (nFlags & 2)
        sub_0051ACA0_SendString(szText, 1, bAlternate);
    sub_00520B70_WaitForReply(10);
    if (sub_00520AE0())
    {
        sub_005204A0_SetError(0xE);
        return 1;
    }
    sub_00520520_SetState(0);
    return 1;
}

// 0x0051CA30
int __cdecl sub_0051CA30_IsReady()
{
    D2BnStateStrc tState;
    sub_005205F0_GetState(&tState);
    if (!sub_00520AE0() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0))
        return 1;
    return 0;
}

// 0x0051EA20
void __fastcall sub_0051EA20_SetPercent(int nUnused, unsigned int nCurrent, unsigned int nTotal)
{
    gnPercent_00881C50 = nCurrent * 100 / nTotal;
}

// 0x00520210
int __fastcall sub_00520210_QueueMessage(int nId, const void* pData, unsigned int nLength)
{
    D2BnMessageStrc* pMessage = (D2BnMessageStrc*)FOG_Alloc(sizeof(D2BnMessageStrc), szBnMessQueueFile_006DF78C, 0x37, 0);
    if (nLength > 0x120)
        nLength = 0x120;
    if (nLength)
        memcpy(pMessage->szText, pData, nLength);
    else
        pMessage->szText[0] = 0;
    pMessage->nLength = nLength;
    pMessage->nId = nId;
    pMessage->pNext = 0;
    D2_ASSERT(nLength <= 0x120, 0x44);
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gpMessageHead_00882020)
        gpMessageHead_00882020 = pMessage;
    else
        gpMessageTail_00882024->pNext = pMessage;
    gpMessageTail_00882024 = pMessage;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}
