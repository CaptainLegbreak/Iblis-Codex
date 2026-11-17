struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
static unsigned int gnWorkBufferSize_00779208;                                                              // 0x00779208
static void* gpWorkBuffer_0077920C;                                                                         // 0x0077920C
static unsigned long gdwWorkBufferOwner_00779210;                                                           // 0x00779210
static D2CriticalSectionStrc gtWorkBufferLock_00779214;                                                     // 0x00779214

// 0x0041E440
static void* sub_0041E440_AllocWorkBuffer(unsigned int nSize, int* pbShared)
{
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    const unsigned long dwThreadId = GetCurrentThreadId();
    if (!gpWorkBuffer_0077920C)
    {
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x620, 0);
        gdwWorkBufferOwner_00779210 = 0;
    }
    else if (gdwWorkBufferOwner_00779210)
    {
        void* pBuffer = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x626, 0);
        *pbShared = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return pBuffer;
    }
    if (gnWorkBufferSize_00779208 < nSize)
    {
        SMemFree(gpWorkBuffer_0077920C, ".\\SOURCE\\SCOMP.CPP", 0x62F, 0);
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x631, 0);
    }
    *pbShared = 1;
    gdwWorkBufferOwner_00779210 = dwThreadId;
    void* pBuffer = gpWorkBuffer_0077920C;
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
    return pBuffer;
}

// 0x0041E510
static void __stdcall sub_0041E510_FreeWorkBuffer(int bShared, void* pBuffer)
{
    if (!pBuffer)
    {
        return;
    }
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    if (bShared)
    {
        gdwWorkBufferOwner_00779210 = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return;
    }
    SMemFree(pBuffer, ".\\SOURCE\\SCOMP.CPP", 0x647, 0);
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
}

int __stdcall sub_M01_Emit_0041E440(unsigned int nSize)
{
    int bShared;
    void* pBuffer = sub_0041E440_AllocWorkBuffer(nSize, &bShared);
    sub_0041E510_FreeWorkBuffer(bShared, pBuffer);
    return 1;
}
