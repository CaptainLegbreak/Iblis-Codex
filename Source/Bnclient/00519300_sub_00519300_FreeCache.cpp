struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern void* ghCacheFile_0072FB78;                                                                          // 0x0072FB78
void* gpCacheBuffer_00881880;                                                                               // 0x00881880
void* gpCacheBuffer_00881884;                                                                               // 0x00881884
unsigned int* gpCacheTable_00881888;                                                                        // 0x00881888
void* gpCacheBuffer_0088188C;                                                                               // 0x0088188C
extern int gnCacheValue_00881890;                                                                           // 0x00881890
extern D2CriticalSectionStrc gCacheLock_00881894;                                                           // 0x00881894

// 0x00519300
void __cdecl sub_00519300_FreeCache()
{
    EnterCriticalSection(&gCacheLock_00881894);
    gnCacheValue_00881890 = 0;
    if (gpCacheBuffer_00881884)
    {
        SMemFree(gpCacheBuffer_00881884, ".\\CACHE.CPP", 0x155, 0);
        gpCacheBuffer_00881884 = 0;
    }
    if (gpCacheBuffer_0088188C)
    {
        SMemFree(gpCacheBuffer_0088188C, ".\\CACHE.CPP", 0x159, 0);
        gpCacheBuffer_0088188C = 0;
    }
    if (gpCacheBuffer_00881880)
    {
        SMemFree(gpCacheBuffer_00881880, ".\\CACHE.CPP", 0x15D, 0);
        gpCacheBuffer_00881880 = 0;
    }
    if (ghCacheFile_0072FB78 != (void*)-1)
    {
        CloseHandle(ghCacheFile_0072FB78);
        ghCacheFile_0072FB78 = (void*)-1;
    }
    if (gpCacheTable_00881888)
    {
        SMemFree(gpCacheTable_00881888, ".\\CACHE.CPP", 0x165, 0);
        gpCacheTable_00881888 = 0;
    }
    LeaveCriticalSection(&gCacheLock_00881894);
}
