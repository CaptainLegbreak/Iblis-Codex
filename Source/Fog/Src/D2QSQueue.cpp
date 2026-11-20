#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSection006C1F80Strc;
struct D2QSNode006C1F80Strc;
struct D2QSQueue006C1F80Strc;
struct D2CriticalSectionStrc;
struct D2QueueMessage006C2090Strc;
struct D2Queue006C2090Strc;

struct D2CriticalSection006C1F80Strc
{
    int aData[6];
};

struct D2QSNode006C1F80Strc
{
    int unk00;
    D2QSNode006C1F80Strc* pNext;
};

struct D2QSQueue006C1F80Strc
{
    int unk00;
    D2CriticalSection006C1F80Strc tLock;
    D2QSNode006C1F80Strc* pHead;
    int nCount;

    void Destroy();
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSection006C1F80Strc* pLock); // 0x006CC1FC

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2QueueMessage006C2090Strc
{
    unsigned short nLength;
    unsigned char unk_02[2];
    D2QueueMessage006C2090Strc* pNext;
    unsigned char pData[1];
};

struct D2Queue006C2090Strc
{
    int bOverflow;
    D2CriticalSectionStrc tLock;
    D2QueueMessage006C2090Strc* pHead;
    D2QueueMessage006C2090Strc* pTail;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x006C1F80
void D2QSQueue006C1F80Strc::Destroy()
{
    D2QSNode006C1F80Strc* pNode = pHead;
    while (pHead)
    {
        pNode = pNode->pNext;
        FOG_Free(pHead, ".\\Src\\D2QSQueue.cpp", 0x27, 0);
        pHead = pNode;
    }
    nCount = 0;
    pHead = 0;
    DeleteCriticalSection(&tLock);
}

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

// 0x006C2090
int __fastcall sub_006C2090_Pop(D2Queue006C2090Strc* pQueue, void* pDest, unsigned short nMaxLength)
{
    int nLength;
    EnterCriticalSection(&pQueue->tLock);
    D2QueueMessage006C2090Strc* pMessage = pQueue->pHead;
    if (pMessage)
    {
        if (pMessage->nLength > nMaxLength)
        {
            pQueue->bOverflow = 1;
            nLength = 0;
        }
        else
        {
            memcpy(pDest, pMessage->pData, pMessage->nLength);
            nLength = pMessage->nLength;
        }
        D2QueueMessage006C2090Strc* pNext = pMessage->pNext;
        FOG_Free(pQueue->pHead, ".\\Src\\D2QSQueue.cpp", 0x78, 0);
        pQueue->pHead = pNext;
        if (!pNext)
        {
            pQueue->pTail = 0;
        }
    }
    else
    {
        nLength = 0;
    }
    LeaveCriticalSection(&pQueue->tLock);
    return nLength;
}
