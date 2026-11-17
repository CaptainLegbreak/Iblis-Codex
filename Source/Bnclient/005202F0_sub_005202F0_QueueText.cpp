typedef unsigned int size_t;
extern "C" size_t __cdecl strlen(const char* szString);
#pragma intrinsic(strlen)

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2BnStateStrc
{
    int nState;
    void* pArg;
};

struct D2BnMessageStrc
{
    int nId;
    char szText[0x120];
    unsigned int nLength;
    D2BnMessageStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

extern "C" const char szBnMessQueueFile_006DF78C[];                                                         // 0x006DF78C
char gszEmptyStateText_00881F80[128];                                                                       // 0x00881F80
extern void* gpBnStateArg_00882000;                                                                         // 0x00882000
extern D2CriticalSectionStrc gMessageLock_00882004;                                                         // 0x00882004
extern int gnBnState_0088201C;                                                                              // 0x0088201C
D2BnMessageStrc* gpMessageHead_00882020;                                                                    // 0x00882020
D2BnMessageStrc* gpMessageTail_00882024;                                                                    // 0x00882024

// 0x005202F0
int __fastcall sub_005202F0_QueueText(int nId, const char* szText)
{
    D2BnMessageStrc* pMessage = (D2BnMessageStrc*)FOG_Alloc(sizeof(D2BnMessageStrc), szBnMessQueueFile_006DF78C, 0x5C, 0);
    SStrCopy(pMessage->szText, szText, 0x120);
    unsigned int nLength = strlen(pMessage->szText) + 1;
    pMessage->nLength = nLength;
    pMessage->nId = nId;
    pMessage->pNext = 0;
    D2_ASSERT(nLength <= 0x120, 0x62);
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gpMessageHead_00882020)
        gpMessageHead_00882020 = pMessage;
    else
        gpMessageTail_00882024->pNext = pMessage;
    gpMessageTail_00882024 = pMessage;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x005203B0
unsigned int __fastcall sub_005203B0_TakeMessage(int* pId, void* pBuffer)
{
    unsigned int nLength;
    EnterCriticalSection(&gMessageLock_00882004);
    D2BnMessageStrc* pMessage = gpMessageHead_00882020;
    if (pMessage)
    {
        memcpy(pBuffer, pMessage->szText, pMessage->nLength);
        *pId = pMessage->nId;
        nLength = pMessage->nLength;
        D2BnMessageStrc* pNext = pMessage->pNext;
        FOG_Free(gpMessageHead_00882020, szBnMessQueueFile_006DF78C, 0x86, 0);
        gpMessageHead_00882020 = pNext;
    }
    else
    {
        nLength = 0;
    }
    LeaveCriticalSection(&gMessageLock_00882004);
    return nLength;
}

// 0x00520580
int __fastcall sub_00520580_TakeState(D2BnStateStrc* pState)
{
    D2_ASSERT(pState, 0xE2);
    EnterCriticalSection(&gMessageLock_00882004);
    pState->nState = gnBnState_0088201C;
    pState->pArg = gpBnStateArg_00882000;
    if (gnBnState_0088201C == 0x1B)
        pState->pArg = gszEmptyStateText_00881F80;
    gnBnState_0088201C = 0;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}
