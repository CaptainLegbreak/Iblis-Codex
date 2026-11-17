struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2LockedListStrc
{
    int nCount00;
    D2CriticalSectionStrc tLock;
    int nValue1C;
    int nValue20;
};

// 0x006C1F60
void __fastcall sub_006C1F60_InitLockedList(D2LockedListStrc* pList)
{
    pList->nValue1C = 0;
    pList->nValue20 = 0;
    pList->nCount00 = 0;
    InitializeCriticalSection(&pList->tLock);
}
