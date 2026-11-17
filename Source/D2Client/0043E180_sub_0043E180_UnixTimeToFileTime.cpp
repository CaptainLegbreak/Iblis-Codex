struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

D2CriticalSectionStrc gtChatLock_0077AE28;                                                                  // 0x0077AE28
D2ChatMessageStrc* gpChatQueueHead_0077BDAC;                                                                // 0x0077BDAC
extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
extern int gnSelectIdA_0070CD7C;                                                                            // 0x0070CD7C

// 0x0043E180
static __forceinline void sub_0043E180_UnixTimeToFileTime(unsigned int nTime, _FILETIME* pFileTime)
{
    const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
    pFileTime->dwLowDateTime = (unsigned long)nFileTime;
    pFileTime->dwHighDateTime = (unsigned long)(nFileTime >> 32);
}

// 0x0043E230
void __cdecl sub_0043E230_InitChatLock()
{
    InitializeCriticalSection(&gtChatLock_0077AE28);
}

// 0x0043E240
void __cdecl sub_0043E240_DeleteChatLock()
{
    DeleteCriticalSection(&gtChatLock_0077AE28);
}

// 0x0043E2E0
static __forceinline void sub_0043E2E0(D2ChatMessageStrc* pMessage)
{
    if (pMessage)
    {
        if (pMessage->szText)
        {
            FOG_Free(pMessage->szText, ".\\Src\\ChatDlg.cpp", 0xC38, 0);
        }
        FOG_Free(pMessage, ".\\Src\\ChatDlg.cpp", 0xC39, 0);
    }
}

// 0x0043E370
D2ChatMessageStrc* __cdecl sub_0043E370()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock_0077AE28);
    if (gpChatQueueHead_0077BDAC)
    {
        pMessage = gpChatQueueHead_0077BDAC;
        gpChatQueueHead_0077BDAC = gpChatQueueHead_0077BDAC->pNext;
    }
    LeaveCriticalSection(&gtChatLock_0077AE28);
    return pMessage;
}

// 0x0043EC50
void __fastcall sub_0043EC50_SetSelect(unsigned char nMode, int nId)
{
    gnSelectModeA_0070CD62 = nMode;
    gnSelectIdA_0070CD7C = nId;
}

// 0x0043ED50
void __cdecl sub_0043ED50_Nop()
{
}

int __fastcall sub_M110_Emit_0043E180(unsigned int nTime, _FILETIME* pFileTime)
{
    sub_0043E180_UnixTimeToFileTime(nTime, pFileTime);
    sub_0043E2E0((D2ChatMessageStrc*)pFileTime->dwHighDateTime);
    return 1;
}
