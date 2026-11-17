typedef void* HANDLE;
typedef unsigned long DWORD;
typedef DWORD (__stdcall* LPTHREAD_START_ROUTINE)(void* lpParameter);
extern "C" __declspec(dllimport) HANDLE __stdcall CreateEventA(void* lpEventAttributes, int bManualReset, int bInitialState, const char* lpName);
extern "C" __declspec(dllimport) HANDLE __stdcall CreateThread(void* lpThreadAttributes, unsigned int dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, void* lpParameter, DWORD dwCreationFlags, DWORD* lpThreadId);

struct sub_006BC620_Strc
{
    HANDLE hThread;
    DWORD dwThreadId;
    char unk_008[0x10C];
    HANDLE hEvent;
    char unk_118[0x0C];
    int nState;
};

DWORD __stdcall sub_006BC560(void* pContext); // 0x006BC560

// 0x006BC620
HANDLE __stdcall sub_006BC620_StartThread(sub_006BC620_Strc* pThis)
{
    if (!pThis)
        return 0;
    if (pThis->hThread)
        return 0;

    pThis->nState = 0;
    pThis->hEvent = CreateEventA(0, 0, 0, 0);
    pThis->hThread = CreateThread(0, 0, sub_006BC560, pThis, 0, &pThis->dwThreadId);
    return pThis->hThread;
}
