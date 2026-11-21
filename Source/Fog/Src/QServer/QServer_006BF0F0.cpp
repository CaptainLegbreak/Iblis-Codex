#include "D2QServer.h"

extern "C" int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);

static void sub_006BF0F0_FreeAll(D2QueueServerStrc* pServer);

// 0x006BF0F0
static void sub_006BF0F0_FreeAll(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tRecordLock);
    for (unsigned int i = 0; i < pServer->nRecordBuckets; ++i)
    {
        D2QServerNodeStrc* pEntry = pServer->ppRecords[i];
        while (pEntry)
        {
            D2QServerNodeStrc* pFree = pEntry;
            pEntry = pEntry->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x8BE, 0);
        }
        pServer->ppRecords[i] = 0;
    }
    pServer->nRecordCount = 0;
    LeaveCriticalSection(&pServer->tRecordLock);
}

// calling-convention shim (not game code)
void __stdcall shim_9(D2QueueServerStrc* pServer)
{
    sub_006BF0F0_FreeAll(pServer);
}
