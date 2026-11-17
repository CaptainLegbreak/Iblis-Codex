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
    static char* NextOf(char* pNext)
    {
        if ((int)pNext > 0)
            return pNext;
        return 0;
    }
    char* Next()
    {
        return NextOf(m_next);
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

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern "C" const char gszDelete_006CC824[];                                                                 // 0x006CC824

struct D2LogMsgNodeStrc
{
    D2LogMsgLinkStrc f_0;

    D2LogMsgNodeStrc() {}
    ~D2LogMsgNodeStrc();                                                    // 0x0040FAA0
    void Unlink()
    {
        f_0.Unlink();
    }
};

struct D2LogMessageStrc : D2LogMsgNodeStrc
{
    unsigned int nSize;
    int nType;
    char unk0x10[0x14];

    D2LogMessageStrc() {}
    ~D2LogMessageStrc() {}
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, gszDelete_006CC824, -1, 0);
    }
};

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2LogMsgLinkStrc m_terminator;

    D2LogMessageStrc* Head()
    {
        return (D2LogMessageStrc*)m_terminator.Next();
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void __fastcall sub_0040F720_WriteMessage(D2LogMessageStrc* pMessage);                                      // 0x0040F720
void __fastcall sub_0040F070_WriteMessage2(D2LogMessageStrc* pMessage);                                     // 0x0040F070
void __cdecl sub_0040F350_CloseStaleLogs();                                                                 // 0x0040F350
void __cdecl sub_0040F970_SweepOldLogFiles();                                                               // 0x0040F970

extern int gnLogQueued_0075D140;                                                                            // 0x0075D140
extern int gnLogQueuedBytes_0075D144;                                                                       // 0x0075D144
extern int gbLogThreadStop_0075E830;                                                                        // 0x0075E830
extern D2CriticalSectionStrc gtLogQueueLock_0075E838;                                                       // 0x0075E838
extern D2CriticalSectionStrc gtLogLock_0075E850;                                                            // 0x0075E850
extern D2LogMsgListStrc gtLogMsgQueue_0075E868;                                                             // 0x0075E868

static __forceinline D2LogMessageStrc* sub_DequeueMessage()
{
    EnterCriticalSection(&gtLogQueueLock_0075E838);
    D2LogMessageStrc* pMessage = gtLogMsgQueue_0075E868.Head();
    if (pMessage)
    {
        ((D2LogMessageStrc*)gtLogMsgQueue_0075E868.m_terminator.m_next)->Unlink();
        --gnLogQueued_0075D140;
        gnLogQueuedBytes_0075D144 -= pMessage->nSize;
    }
    LeaveCriticalSection(&gtLogQueueLock_0075E838);
    return pMessage;
}

// 0x004101C0
unsigned long __stdcall sub_004101C0_LogThreadProc(void* pParam)
{
    unsigned long dwStopTime = 0;
next:
    {
        D2LogMessageStrc* pMessage = sub_DequeueMessage();

        if (gbLogThreadStop_0075E830)
        {
            if (!dwStopTime)
                dwStopTime = GetTickCount();
            if (!pMessage || GetTickCount() - dwStopTime >= 15000)
                return 1;
        }

        unsigned long dwSleep = 0;
        if (!pMessage)
        {
            dwSleep = 50;
        }
        else
        {
            EnterCriticalSection(&gtLogLock_0075E850);
            switch (pMessage->nType)
            {
            case 1:
                sub_0040F720_WriteMessage(pMessage);
                break;
            case 2:
                sub_0040F070_WriteMessage2(pMessage);
                break;
            }
            LeaveCriticalSection(&gtLogLock_0075E850);
            delete pMessage;
        }

        if (!gbLogThreadStop_0075E830)
        {
            Sleep(dwSleep);
            EnterCriticalSection(&gtLogLock_0075E850);
            sub_0040F350_CloseStaleLogs();
            sub_0040F970_SweepOldLogFiles();
            LeaveCriticalSection(&gtLogLock_0075E850);
        }
    }
    goto next;
}
