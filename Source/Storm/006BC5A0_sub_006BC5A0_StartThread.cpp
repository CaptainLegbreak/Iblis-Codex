extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
struct D2ThreadRecord006BC5A0Strc
{
    void* hThread;
    unsigned long nThreadId;
    unsigned char unk_008[0x10C];
    void* hEvent;
    unsigned char unk_118[0xC];
    int n124;
};
unsigned long __stdcall sub_006BC560_ThreadProc(void* pParameter); // 0x006BC560

// 0x006BC5A0
void __stdcall sub_006BC5A0_StartThread(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && !pRecord->hThread)
    {
        pRecord->n124 = 0;
        pRecord->hEvent = CreateEventA(0, 0, 0, 0);
        pRecord->hThread = CreateThread(0, 0, sub_006BC560_ThreadProc, pRecord, 0, &pRecord->nThreadId);
        while (WaitForSingleObject(pRecord->hThread, 0))
        {
            Sleep(10);
        }
    }
}
