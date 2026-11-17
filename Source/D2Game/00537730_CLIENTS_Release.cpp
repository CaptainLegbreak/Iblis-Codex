struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* pOwningThread;
    void* pLockSemaphore;
    unsigned long nSpinCount;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    char unk0x008[0x4A4];
    D2ClientStrc* pServerNext;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

extern D2ClientStrc* gpClientList_008842A8[256];                                                            // 0x008842A8
D2CriticalSectionStrc gClientListLock_008846A8;                                                             // 0x008846A8
extern D2CriticalSectionStrc gSrvClientListByNameLock_008846C0;                                             // 0x008846C0
extern int gbClientListInitialized_008846D8;                                                                // 0x008846D8

// 0x00537730
void __fastcall CLIENTS_Release()
{
    DeleteCriticalSection(&gClientListLock_008846A8);
    DeleteCriticalSection(&gSrvClientListByNameLock_008846C0);
    gbClientListInitialized_008846D8 = 0;
}

// 0x00537760
D2ClientStrc* __fastcall sub_00537760_GetClientFromId(int nClientId)
{
    EnterCriticalSection(&gClientListLock_008846A8);
    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }
    LeaveCriticalSection(&gClientListLock_008846A8);
    return 0;
}

// 0x005377A0
void __fastcall sub_005377A0_UnlockClientList(int nClientId)
{
    LeaveCriticalSection(&gClientListLock_008846A8);
}

// 0x00538930
int __fastcall CLIENTS_CheckState(int nClientId, int nExpectedClientState)
{
    if (!gbClientListInitialized_008846D8)
    {
        return 0;
    }

    int bResult = 0;
    EnterCriticalSection(&gClientListLock_008846A8);
    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            bResult = pClient->dwClientState == nExpectedClientState;
            break;
        }
    }
    LeaveCriticalSection(&gClientListLock_008846A8);
    return bResult;
}
