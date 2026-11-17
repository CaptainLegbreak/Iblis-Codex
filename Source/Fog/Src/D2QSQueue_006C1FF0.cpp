#include "Fog.h"

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QueueMessage006C2090Strc
{
    unsigned short nLength;
    unsigned char unk_02[2];
    D2QueueMessage006C2090Strc* pNext;
    unsigned char pData[1];
};
struct D2Queue006C2090Strc
{
    int f_0;
    D2CriticalSectionStrc tLock;
    D2QueueMessage006C2090Strc* pHead;
    D2QueueMessage006C2090Strc* pTail;
};

// 0x006C1FF0
void __fastcall sub_006C1FF0_Push(D2Queue006C2090Strc* pQueue, const void* pSource, unsigned short nLength)
{
    D2_ASSERT(nLength > 0, 0x4A);

    EnterCriticalSection(&pQueue->tLock);
    D2QueueMessage006C2090Strc* pMessage = (D2QueueMessage006C2090Strc*)FOG_Alloc(nLength + 8, ".\\Src\\D2QSQueue.cpp", 0x4E, 0);
    pMessage->nLength = nLength;
    pMessage->pNext = 0;
    memcpy(pMessage->pData, pSource, nLength);
    if (!pQueue->pHead)
    {
        pQueue->pHead = pMessage;
    }
    else
    {
        pQueue->pTail->pNext = pMessage;
    }
    pQueue->pTail = pMessage;
    LeaveCriticalSection(&pQueue->tLock);
}
