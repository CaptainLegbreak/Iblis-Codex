#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct D2QServerNodeStrc
{
    int unk0x00;
    unsigned int dwTime;
    int unk0x08;
    D2QServerNodeStrc* pNext;
};

struct D2QueueServerStrc
{
    char unk0x000[0x84C];
    D2QServerNodeStrc* pHead;
    int unk0x850;
    D2CriticalSectionStrc tLock;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

__declspec(noinline) static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer);
static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer); // 0x006BF260

// 0x006BF260
static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer)
{
    const unsigned int dwTickCount = GetTickCount();
    EnterCriticalSection(&pServer->tLock);

    while (pServer->pHead)
    {
        D2QServerNodeStrc* pNode = pServer->pHead;
        if (dwTickCount - pNode->dwTime <= 15000)
        {
            break;
        }

        pServer->pHead = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x980, 0);
    }

    D2QServerNodeStrc* pPrevious = pServer->pHead;
    if (pPrevious)
    {
        for (D2QServerNodeStrc* pNode = pPrevious->pNext; pNode; )
        {
            if (dwTickCount - pNode->dwTime > 15000)
            {
                pPrevious->pNext = pNode->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x993, 0);
                pNode = pPrevious->pNext;
            }
            else
            {
                pPrevious = pNode;
                pNode = pNode->pNext;
            }
        }
    }

    LeaveCriticalSection(&pServer->tLock);
    return 1;
}

int __stdcall sub_Emit_006BF260(D2QueueServerStrc* pServer)
{
    return sub_006BF260_ExpireNodes(pServer) + 1;
}
