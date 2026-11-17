struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2Worker006BE4A0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock854;
    unsigned char unk_86C[0x884 - 0x86C];
    unsigned int nCount884;
};

// 0x006BE4A0
void __stdcall sub_006BE4A0_SetCount(D2Worker006BE4A0Strc* pWorker, unsigned int nCount)
{
    if (pWorker)
    {
        if (nCount <= 0)
            nCount = 1;
        EnterCriticalSection(&pWorker->tLock854);
        pWorker->nCount884 = nCount;
        LeaveCriticalSection(&pWorker->tLock854);
    }
}
