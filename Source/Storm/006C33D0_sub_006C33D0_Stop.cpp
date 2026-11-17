struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct D2Worker006C33D0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock854;
    unsigned char unk_86C[0xBD8 - 0x86C];
    void* hThreadBD8;
    unsigned char unk_BDC[0xBF8 - 0xBDC];
    int bStopBF8;
};

// 0x006C33D0
void __fastcall sub_006C33D0_Stop(D2Worker006C33D0Strc* pWorker)
{
    EnterCriticalSection(&pWorker->tLock854);
    pWorker->bStopBF8 = 1;
    LeaveCriticalSection(&pWorker->tLock854);
    WaitForSingleObject(pWorker->hThreadBD8, 2000);
}
