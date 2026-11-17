struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc();
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern D2CriticalSectionStrc gaLocks_00779238[4];                                                          // 0x00779238

// 0x00420040
void __cdecl sub_00420040_InitLocks()
{
    D2CriticalSectionStrc* pLock = gaLocks_00779238;
    int n = 4;
    do
    {
        InitializeCriticalSection(pLock);
        ++pLock;
    }
    while (--n);
}

// 0x00426A70
D2StormLinkStrc::D2StormLinkStrc() : m_prevlink(0), m_next(0)
{
}
