#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QueueServerStrc;
struct sub_006BF320_Node;
struct sub_006BF320_Server;
struct D2QLockStrc;
struct D2QNodeStrc;
struct D2QIpCountStrc;

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);
void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct sub_006BF320_Node
{
    char unk_00[0x0C];
    sub_006BF320_Node* pNext;
};

struct sub_006BF320_Server
{
    char unk_000[0x84C];
    sub_006BF320_Node* pPending;
    char unk_850[4];
    char cs[0x18];
};

static __declspec(noinline) void sub_006BF320_FreePending(sub_006BF320_Server* pServer);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl sub_006BE2F0_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE2F0
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE300
const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E
unsigned int __cdecl sub_00410A80_GetTimeSeconds(); // 0x00410A80

struct D2QLockStrc
{
    char cs[0x18];
};

struct D2QNodeStrc
{
    int unk_00;
    D2QNodeStrc* pNext;
};

struct D2QIpCountStrc
{
    unsigned int nKey;
    int nRefCount;
    D2QIpCountStrc* pNext;
};

struct D2QClientStrc
{
    unsigned int nId;
    D2QClientStrc* pNextClient;
    long nRefCount;
    char unk_0C[0x0C];
    unsigned int nAddress;
    D2QClientStrc* pNextByAddress;
    char unk_20[0x0C];
    char cs[0x48];
    D2QNodeStrc* pNodes;
    char unk_78[0x20];
    unsigned int nCreateTime;
};

typedef void (__fastcall* D2QRemoveCallback)(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine);

struct D2QueueServerStrc
{
    char unk_000[0x0C];
    unsigned int nHashMask;
    unsigned int nIpCountBuckets;
    D2QClientStrc** ppClients;
    int unk_018;
    D2QLockStrc* pClientLocks;
    D2QClientStrc** ppAddressBuckets;
    int unk_024;
    D2QLockStrc tAddressLock;
    D2QIpCountStrc** ppIpCounts;
    char unk_044[0x810];
    D2QLockStrc tCountLock;
    char unk_86C[0x14];
    int nClients;
    char unk_884[0x344];
    D2QRemoveCallback pfnOnRemove;
};

static __declspec(noinline) int sub_006BF1F0_Release(D2QueueServerStrc* pTable, unsigned int* pKey);
static __declspec(noinline) void __stdcall sub_006BFCD0_RemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId);
static __declspec(noinline) void sub_006BE650_DestroyClient(D2QClientStrc* pClient);

// 0x006BF320
static void sub_006BF320_FreePending(sub_006BF320_Server* pServer)
{
    EnterCriticalSection((CRITICAL_SECTION*)pServer->cs);
    sub_006BF320_Node* pNode = pServer->pPending;
    while (pNode)
    {
        sub_006BF320_Node* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 2480, 0);
    }
    pServer->pPending = 0;
    LeaveCriticalSection((CRITICAL_SECTION*)pServer->cs);
}

// calling-convention shim (not game code)
void __fastcall sub_006BF320_Shim(sub_006BF320_Server* pServer)
{
    sub_006BF320_FreePending(pServer);
    FOG_Free(pServer, ".\\Src\\QServer\\QServer.cpp", 0, 0);
}

// 0x006BF1F0
static int sub_006BF1F0_Release(D2QueueServerStrc* pTable, unsigned int* pKey)
{
    const unsigned int nKey = *pKey;
    const unsigned int nBucket = nKey % pTable->nIpCountBuckets;
    D2QIpCountStrc* pPrev = 0;
    for (D2QIpCountStrc* pNode = pTable->ppIpCounts[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            --pNode->nRefCount;
            if (pNode->nRefCount <= 0)
            {
                if (pPrev)
                {
                    pPrev->pNext = pNode->pNext;
                }
                else
                {
                    pTable->ppIpCounts[nBucket] = pNode->pNext;
                }
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x940, 0);
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// 0x006BFCD0
static void __stdcall sub_006BFCD0_RemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId)
{
    const unsigned int nBucket = nClientId & pServer->nHashMask;
    EnterCriticalSection((CRITICAL_SECTION*)&pServer->pClientLocks[nBucket]);

    D2QClientStrc* pPrev = 0;
    D2QClientStrc* pClient = pServer->ppClients[nBucket];
    while (pClient)
    {
        if (pClient->nId == nClientId)
        {
            break;
        }
        pPrev = pClient;
        pClient = pClient->pNextClient;
    }

    if (!pClient)
    {
        sub_006BE2F0_Nop(&gszEmptyAssertText, "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        sub_006BE300_Nop("QSRV", "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        LeaveCriticalSection((CRITICAL_SECTION*)&pServer->pClientLocks[nBucket]);
        return;
    }

    EnterCriticalSection((CRITICAL_SECTION*)&pServer->tCountLock);
    --pServer->nClients;
    LeaveCriticalSection((CRITICAL_SECTION*)&pServer->tCountLock);

    if (pClient != pServer->ppClients[nBucket])
    {
        pPrev->pNextClient = pClient->pNextClient;
    }
    else
    {
        pServer->ppClients[nBucket] = pClient->pNextClient;
    }
    pClient->pNextClient = 0;
    LeaveCriticalSection((CRITICAL_SECTION*)&pServer->pClientLocks[nBucket]);

    D2_ASSERT(nClientId == pClient->nId, 0x3E0);

    unsigned int* pAddress = &pClient->nAddress;
    sub_006BE300_Nop("QSRV", "[sRemoveClient]  Remove client %d %s refcount=%d life=%d", nClientId,
        sub_006B013E_FormatAddress(*pAddress), pClient->nRefCount, sub_00410A80_GetTimeSeconds() - pClient->nCreateTime);

    CRITICAL_SECTION* pLock = (CRITICAL_SECTION*)&pServer->tAddressLock;
    EnterCriticalSection(pLock);

    const unsigned int nAddressBucket = pClient->nAddress & pServer->nHashMask;
    D2QClientStrc** ppBucket = &pServer->ppAddressBuckets[nAddressBucket];
    D2QClientStrc* pFound = *ppBucket;
    pPrev = 0;
    while (pFound)
    {
        if (pFound->nId == nClientId)
        {
            break;
        }
        pPrev = pFound;
        pFound = pFound->pNextByAddress;
    }

    if (!pFound)
    {
        sub_006BE2F0_Nop(&gszEmptyAssertText, "[sRemoveClient]  Couldn't remove TCLIENT %d %s from IP-hash",
            nClientId, sub_006B013E_FormatAddress(*pAddress));
    }
    else
    {
        D2QClientStrc* pNext = pFound->pNextByAddress;
        if (pFound != pServer->ppAddressBuckets[nAddressBucket])
        {
            pPrev->pNextByAddress = pNext;
        }
        else
        {
            *ppBucket = pNext;
        }
    }
    LeaveCriticalSection(pLock);

    pLock = (CRITICAL_SECTION*)&pServer->tCountLock;
    EnterCriticalSection(pLock);
    sub_006BF1F0_Release(pServer, pAddress);
    LeaveCriticalSection(pLock);
}

// build: context sub_006BE650_DestroyClient
static void sub_006BE650_DestroyClient(D2QClientStrc* pClient)
{
    if (pClient->pNextClient)
        sub_006BE300_Nop("QSRV", "  ptClient->ptNextClient =  %08X", pClient->pNextClient);

    D2QNodeStrc* pNode = pClient->pNodes;
    while (pNode)
    {
        D2QNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 935, 0);
        pNode = pNext;
    }
    pClient->pNodes = 0;
    DeleteCriticalSection((CRITICAL_SECTION*)pClient->cs);
    FOG_Free(pClient, ".\\Src\\QServer\\QServer.cpp", 942, 0);
}

// 0x006C0360
void __fastcall sub_006C0360_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient)
{
    if (InterlockedDecrement(&pClient->nRefCount) == 0)
    {
        if (pServer->pfnOnRemove)
            pServer->pfnOnRemove(pServer, pClient->nId, ".\\Src\\QServer\\QServer.cpp", 891);
        sub_006BFCD0_RemoveClient(pServer, pClient->nId);
        sub_006BE650_DestroyClient(pClient);
    }
}
