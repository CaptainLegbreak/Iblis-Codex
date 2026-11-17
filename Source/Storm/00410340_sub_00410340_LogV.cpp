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

    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
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

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...);
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0
extern int gbLogInitialized_0075D2EC;                                                                       // 0x0075D2EC
extern int gbLogThreadStop_0075E830;                                                                        // 0x0075E830
extern D2CriticalSectionStrc gtLogQueueLock_0075E838;                                                       // 0x0075E838
extern D2LogMsgListStrc gtLogMsgQueue_0075E868;                                                             // 0x0075E868
extern int gnLogQueued_0075D140;                                                                            // 0x0075D140
extern int gnLogQueuedBytes_0075D144;                                                                       // 0x0075D144

// 0x00410340
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args)
{
    if (gbLogThreadStop_0075E830 || !gbLogInitialized_0075D2EC)
    {
        return;
    }

    char szBuffer[0x1000];
    __try
    {
        _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, args);
        szBuffer[sizeof(szBuffer) - 1] = 0;
    }
    __except (1)
    {
        _snprintf(szBuffer, sizeof(szBuffer), "Bad message: format string is '%s'", szFormat);
    }

    if (nArg3 == 1)
    {
        sub_00413800(szBuffer, gszNewline_006FFCB0, sizeof(szBuffer));
    }

    unsigned int nExtraBytes = SStrLen(szPrefix) + 1;
    nExtraBytes += SStrLen(szBuffer) + 1;

    EnterCriticalSection(&gtLogQueueLock_0075E838);
    D2LogMessageStrc* pMessage = (D2LogMessageStrc*)gtLogMsgQueue_0075E868.sub_0040FF40_NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock_0075E838);

    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 1;
    pMessage->bTimeStamp = nArg2 == 1;
    GetLocalTime(&pMessage->f_14);

    char* pText = pMessage->szName;
    SStrCopy(pText, szPrefix, nExtraBytes);
    pText += SStrLen(pText) + 1;
    SStrCopy(pText, szBuffer, nExtraBytes);

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
