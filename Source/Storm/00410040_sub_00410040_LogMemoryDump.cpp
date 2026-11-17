typedef unsigned int size_t;
typedef char* va_list;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2LogMsgLinkStrc
{
    D2LogMsgLinkStrc* m_prevlink;
    char* m_next;

    D2LogMsgLinkStrc() { m_prevlink = 0; m_next = 0; }
    ~D2LogMsgLinkStrc() { Unlink(); }

    D2LogMsgLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2LogMsgLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2LogMsgLinkStrc*)(m_next + nLinkOffset);
    }

    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }

    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2LogMsgLinkStrc m_terminator;

    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags); // 0x0040FF40
};

struct D2LogMessageStrc
{
    D2LogMsgLinkStrc f_0;
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc f_14;
    char szName[1];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...);                  // 0x006831DB
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0
extern "C" const char gszLogFormatError_006CE22C[];                                                         // 0x006CE22C
extern int gbLogInitialized_0075D2EC;                                                                       // 0x0075D2EC
extern int gbLogThreadStop_0075E830;                                                                        // 0x0075E830
D2CriticalSectionStrc gtLogQueueLock_0075E838;                                                              // 0x0075E838
extern D2LogMsgListStrc gtLogMsgQueue_0075E868;                                                             // 0x0075E868
int gnLogQueued_0075D140;                                                                                   // 0x0075D140
int gnLogQueuedBytes_0075D144;                                                                              // 0x0075D144

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* pAddress, unsigned int nSize); // 0x006CC238
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0
struct D2LogMemoryInfoStrc
{
    const void* pAddress;
    unsigned int nSize;
    int nArg5;
    int bBadPointer;
    int bArg7;
};

// 0x00410040
void __cdecl sub_00410040_LogMemoryDump(const char* szPrefix, const char* szTitle, const void* pAddress, unsigned int nSize, int nArg5, int bBadPointer, int nArg7)
{
    if (gbLogThreadStop_0075E830 || !gbLogInitialized_0075D2EC)
        return;
    if (!bBadPointer && IsBadReadPtr(pAddress, nSize))
        bBadPointer = 1;
    unsigned int nExtraBytes = SStrLen(szPrefix) + 1 + sizeof(D2LogMemoryInfoStrc);
    nExtraBytes += SStrLen(szTitle) + 1;
    if (!bBadPointer)
        nExtraBytes += nSize;
    EnterCriticalSection(&gtLogQueueLock_0075E838);
    D2LogMessageStrc* pMessage = (D2LogMessageStrc*)gtLogMsgQueue_0075E868.sub_0040FF40_NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock_0075E838);
    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 2;
    pMessage->bTimeStamp = 1;
    GetLocalTime(&pMessage->f_14);
    char* pText = pMessage->szName;
    pText += SStrCopy(pText, szPrefix, 0x7FFFFFFF) + 1;
    D2LogMemoryInfoStrc* pInfo = (D2LogMemoryInfoStrc*)pText;
    pInfo->pAddress = pAddress;
    pInfo->nSize = nSize;
    pInfo->nArg5 = nArg5;
    pInfo->bBadPointer = bBadPointer;
    pInfo->bArg7 = !nArg7;
    pText = (char*)(pInfo + 1);
    pText += SStrCopy(pText, szTitle, 0x7FFFFFFF) + 1;
    if (!bBadPointer)
        memcpy(pText, pAddress, nSize);
    EnterCriticalSection(&gtLogQueueLock_0075E838);
    D2LogMsgLinkStrc* pLink = &pMessage->f_0;
    if (pLink->m_prevlink)
    {
        pLink->NextLink(-1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
    D2LogMsgLinkStrc* pPrev = gtLogMsgQueue_0075E868.m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = (char*)pMessage;
    gtLogMsgQueue_0075E868.m_terminator.m_prevlink = pLink;
    ++gnLogQueued_0075D140;
    gnLogQueuedBytes_0075D144 += pMessage->nSize;
    LeaveCriticalSection(&gtLogQueueLock_0075E838);
}
