struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708420Strc();
    void sub_0041C770_UnlinkAll();                                                                          // 0x0041C770
    void sub_0041C9C0_DeleteAll();                                                                          // 0x0041C9C0
};

struct D2StormMsgSourceStrc
{
    unsigned short wFacility;
    char unk0x02[2];
    void* hModule;
    D2StormMsgSourceStrc* pNext;
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormInit0041C0C0Strc
{
    D2StormInit0041C0C0Strc();
};

extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();                                          // 0x006CC31C
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);   // 0x006CC320
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __cdecl sub_0041BEE0_InitStorm();                                                                      // 0x0041BEE0

extern D2StormList00708420Strc gHandlerList_00708420;                                                       // 0x00708420
extern long gnErrorLockUsers_0070841C;                                                                      // 0x0070841C
extern D2CriticalSectionStrc gErrorStateLock_007790CC;                                                      // 0x007790CC
extern D2StormMsgSourceStrc* gpStormMsgSources_007790E8;                                                    // 0x007790E8
int gnStormDword_007790EC;                                                                                  // 0x007790EC

// 0x0041C0C0
D2StormInit0041C0C0Strc::D2StormInit0041C0C0Strc()
{
    sub_0041BEE0_InitStorm();
}

// 0x0041C7B0
D2StormList00708420Strc::~D2StormList00708420Strc()
{
    sub_0041C770_UnlinkAll();
}

// 0x0041CA80
int __cdecl sub_0041CA80_Destroy()
{
    gHandlerList_00708420.sub_0041C9C0_DeleteAll();
    gnStormDword_007790EC = 0;
    while (gpStormMsgSources_007790E8)
    {
        D2StormMsgSourceStrc* pNext = gpStormMsgSources_007790E8->pNext;
        HeapFree(GetProcessHeap(), 0, gpStormMsgSources_007790E8);
        gpStormMsgSources_007790E8 = pNext;
    }
    if (gnErrorLockUsers_0070841C != -1)
    {
        DeleteCriticalSection(&gErrorStateLock_007790CC);
        gnErrorLockUsers_0070841C = -1;
    }
    return 1;
}
