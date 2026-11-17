struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char unk0x008[0x2];
    unsigned char nFlags0x0A;
    char unk0x00B[0x4A1];
    D2ClientStrc* pServerNext;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern int gbClientListInitialized_008846D8;                                                                // 0x008846D8
extern D2CriticalSectionStrc gClientListLock_008846A8;                                                      // 0x008846A8
extern D2ClientStrc* gpClientList_008842A8[256];                                                            // 0x008842A8

// 0x005377B0
int __cdecl sub_005377B0_CountFlaggedClients()
{
    int nCount = 0;
    if (!gbClientListInitialized_008846D8)
    {
        return 0;
    }
    EnterCriticalSection(&gClientListLock_008846A8);
    for (int i = 0; i < 256; ++i)
    {
        for (D2ClientStrc* pClient = gpClientList_008842A8[i]; pClient; pClient = pClient->pServerNext)
        {
            if (pClient->nFlags0x0A & 0x20)
            {
                ++nCount;
            }
        }
    }
    LeaveCriticalSection(&gClientListLock_008846A8);
    return nCount;
}
