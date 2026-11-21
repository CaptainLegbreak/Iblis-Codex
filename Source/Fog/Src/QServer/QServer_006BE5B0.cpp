#include "D2GameTypes.h"
#include "D2QServer.h"
#include "D2NetTypes.h"
#include "D2SysTypes.h"
#include "Fog.h"

 D2CriticalSectionStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

struct D2HashNode006BE5B0Strc
{
	void* pPrev;
	D2HashNode006BE5B0Strc* pNext;
	int unk_08;
	int unk_0C;
	int nKey;
};

struct D2HashTable006BE5B0Strc
{
	int unk_00;
	int unk_04;
	unsigned int nBuckets;
	int unk_0C;
	int unk_10;
	D2HashNode006BE5B0Strc** ppBuckets;
	int unk_18;
	D2CriticalSectionStrc* pLocks;
};

struct D2CriticalSectionStrc;

struct D2HackListStrc;

struct D2HackNode006BE890Strc;

struct D2Server006BE890Strc;

struct D2MaskKeyStrc;

struct D2MaskPairStrc;

struct D2MaskPairListStrc;

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl sub_006BE300_Log(const char* szTag, const char* szFormat, ...); // 0x006BE300

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

extern const char gszHackCategory_006FC4A8[]; // 0x006FC4A8

extern const char gszHackListSize_006FC4B0[]; // 0x006FC4B0

void __cdecl sub_00410660_LogWritePrefixed(const char* category, const char* format, ...); // 0x00410660

struct D2HackListStrc
{
    unsigned char unk_000[0x888];
    unsigned int lastTick;
    D2QServerNodeStrc* freeEntries;
    unsigned int entryCount;
    D2CriticalSectionStrc section;
    D2QServerNodeStrc** buckets;
    unsigned int bucketCount;

    void __thiscall sub_006BE700_ExpireEntries(); // 0x006BE700
};

extern unsigned long gdwLastHackListLog_00989C34; // 0x00989C34

struct D2HackNode006BE890Strc
{
    unsigned int f_0;
    unsigned char f_4[8];
    D2HackNode006BE890Strc* pNext;
};

struct D2Server006BE890Strc
{
    unsigned char unk_000[0x890];
    int nHackListSize;
    D2CriticalSectionStrc tLock;
    D2HackNode006BE890Strc** ppBuckets;
    unsigned int f_8B0;
    unsigned char unk_8B4[0xBD0 - 0x8B4];
    int bHackList;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

static int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress);

static int sub_006BF1F0_Release(D2QueueServerStrc* pTable, unsigned int* pKey);

extern unsigned int gaMaskTable_0074C3F0[]; // 0x0074C3F0

struct D2MaskKeyStrc
{
    unsigned int nValue;
};

struct D2MaskPairStrc
{
    D2MaskKeyStrc tKey;
    unsigned int nMaskIndex;
};

struct D2MaskPairListStrc
{
    char unk0x00[0x48];
    D2MaskPairStrc aPairs[0x100];
    int nCount;

    int __thiscall sub_006BF660_HasMaskedKey(unsigned int nMask);
};

static int __stdcall sub_006C00A0_AccountTraffic(D2QueueServerStrc* pTable, unsigned int nBytes, D2QClientStrc* pClient);

static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer);

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct sub_006BF320_Node;

struct sub_006BF320_Server;

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

static void sub_006BF320_FreePending(sub_006BF320_Server* pServer);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl sub_006BE2F0_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE2F0

const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E

long __cdecl sub_00410A80_GetTimeSeconds(); // 0x00410A80

static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId);

static void sub_006BE650_DestroyClient(D2QClientStrc* pClient);

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090

static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId);

void __fastcall sub_006C0420_CloseClient(D2QueueServerStrc* table, int client, const char* file, int line); // 0x006C0420

void __fastcall sub_006BFEA0_RecordAddress(D2QueueServerStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0

char* __stdcall sub_006B013E_InetNtoa(unsigned long dwAddress); // 0x006B013E

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0

extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840

extern const char gszAssert_006CC837[]; // 0x006CC837

extern const char gszFile_006FC460[]; // 0x006FC460

extern const char gszHack_006FC4A8[]; // 0x006FC4A8

static void __stdcall sub_006C0770_BanClient(D2QueueServerStrc*, int, const char*, int);

unsigned int gnLastHackListLog_00989C34; // 0x00989C34

void __fastcall sub_006C0360_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient);

// 0x006BE5B0
D2HashNode006BE5B0Strc* __fastcall sub_006BE5B0_FindNode(D2HashTable006BE5B0Strc* pTable, int nKey)
{
	D2HashNode006BE5B0Strc * pResult;
	D2HashNode006BE5B0Strc* pNode = 0;
	for (unsigned int i = 0; i < pTable->nBuckets; ++i)
	{
		EnterCriticalSection(&pTable->pLocks[i]);
		for (pNode = pTable->ppBuckets[i]; pNode; pNode = pNode->pNext)
		{
			if (pNode->nKey == nKey)
			{
				LeaveCriticalSection(&pTable->pLocks[i]);
				pResult = pNode;
				goto Done;
			}
		}
		LeaveCriticalSection(&pTable->pLocks[i]);
	}

	pResult = pNode;
Done:
	return pResult;
}

// 0x006BE650
static void sub_006BE650_DestroyClient(D2QClientStrc* pClient)
{
    if (pClient->pNext)
    {
        sub_006BE300_Log("QSRV", "  ptClient->ptNextClient =  %08X", pClient->pNext);
    }
    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
    while (pNode)
    {
        D2QWriteNodeStrc* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x3A7, 0);
    }
    pClient->pWriteQueue = 0;
    DeleteCriticalSection((D2CriticalSectionStrc*)pClient->cs);
    FOG_Free(pClient, ".\\Src\\QServer\\QServer.cpp", 0x3AE, 0);
}

// calling-convention shim (not game code)
void __stdcall shim_8(D2QClientStrc* pClient)
{
    sub_006BE650_DestroyClient(pClient);
}

// 0x006BE700
void __thiscall D2HackListStrc::sub_006BE700_ExpireEntries()
{
    if (lastTick == ~0u)
        lastTick = GetTickCount();

    unsigned int now = GetTickCount();
    unsigned int elapsed = now - lastTick;
    if (elapsed >= 1000)
    {
        unsigned int seconds = elapsed / 1000;
        int changed = 0;
        EnterCriticalSection(&section);
        lastTick = now;
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            D2QServerNodeStrc* current = buckets[i];
            D2QServerNodeStrc* previous = 0;
            while (current)
            {
                D2QServerNodeStrc* next = current->pNext;
                if (current->nCount)
                {
                    if (current->nCount > seconds)
                        current->nCount -= seconds;
                    else
                    {
                        current->nCount = 0;
                        if (seconds < 120)
                            current->dwTime = 120 - seconds;
                        else
                            current->dwTime = 0;
                        current->dwTime += seconds;
                    }
                }
                if (current->dwTime)
                {
                    if (current->dwTime > seconds)
                        current->dwTime -= seconds;
                    else
                    {
                        if (previous)
                        {
                            previous->pNext = next;
                            current->pNext = freeEntries;
                            freeEntries = current;
                            current = previous;
                        }
                        else
                        {
                            buckets[i] = buckets[i]->pNext;
                            current->pNext = freeEntries;
                            freeEntries = current;
                            current = 0;
                        }
                        --entryCount;
                        changed = 1;
                    }
                }
                previous = current;
                current = next;
            }
        }
        LeaveCriticalSection(&section);
        if (changed)
        {
            unsigned int count = entryCount;
            unsigned int logTick = GetTickCount();
            if (logTick - gnLastHackListLog_00989C34 > 2000)
            {
                sub_00410660_LogWritePrefixed(gszHackCategory_006FC4A8, gszHackListSize_006FC4B0, count);
                gnLastHackListLog_00989C34 = logTick;
            }
        }
    }
}

// 0x006BE890
void __fastcall sub_006BE890_UnlistIP(D2Server006BE890Strc* pServer, const char* szFile, unsigned int dwAddress, int nLine)
{
    if (!pServer->bHackList)
        return;

    EnterCriticalSection(&pServer->tLock);
    unsigned int nBucket = dwAddress % pServer->f_8B0;
    D2HackNode006BE890Strc* pPrev = 0;
    D2HackNode006BE890Strc* pNode = pServer->ppBuckets[nBucket];
    while (pNode)
    {
        D2HackNode006BE890Strc* pNext = pNode->pNext;
        if (pNode->f_0 == dwAddress)
        {
            if (pPrev)
            {
                pPrev->pNext = pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D0, 0);
                pNode = pPrev;
            }
            else
            {
                pServer->ppBuckets[nBucket] = pServer->ppBuckets[nBucket]->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D7, 0);
                pNode = 0;
            }
            --pServer->nHackListSize;
        }
        pPrev = pNode;
        pNode = pNext;
    }
    LeaveCriticalSection(&pServer->tLock);

    int nSize = pServer->nHackListSize;
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastHackListLog_00989C34 > 2000)
    {
        sub_00410660_LogWritePrefixed("HACK", "[HACKLIST]  Hacklist size is %d", nSize);
        gdwLastHackListLog_00989C34 = dwTick;
    }
}

// 0x006BF180
static int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    const unsigned long nAddress = pAddress->s_addr;
    const unsigned int nBucket = nAddress % pServer->nIpBuckets;

    for (D2QIpCountStrc* pNode = pServer->ppIpCounts[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nAddress == nAddress)
        {
            ++pNode->nCount;
            return 1;
        }
    }

    D2QIpCountStrc* pNew = (D2QIpCountStrc*)FOG_Alloc(sizeof(D2QIpCountStrc), ".\\Src\\QServer\\QServer.cpp", 0x919, 0);
    pNew->nAddress = nAddress;
    pNew->nCount = 1;
    pNew->pNext = pServer->ppIpCounts[nBucket];
    pServer->ppIpCounts[nBucket] = pNew;
    return 1;
}

// build: context sub_006BF180_Shim
// calling-convention shim (not game code)
int __cdecl sub_006BF180_Shim(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    return sub_006BF180_IncrementPerIpConnCount(pServer, pAddress);
}

// 0x006BF1F0
static int sub_006BF1F0_Release(D2QueueServerStrc* pTable, unsigned int* pKey)
{
    const unsigned int nKey = *pKey;
    const unsigned int nBucket = nKey % pTable->nIpBuckets;
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

// 0x006BF320
static void sub_006BF320_FreePending(sub_006BF320_Server* pServer)
{
    EnterCriticalSection((D2CriticalSectionStrc*)pServer->cs);
    sub_006BF320_Node* pNode = pServer->pPending;
    while (pNode)
    {
        sub_006BF320_Node* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 2480, 0);
    }
    pServer->pPending = 0;
    LeaveCriticalSection((D2CriticalSectionStrc*)pServer->cs);
}

// calling-convention shim (not game code)
int __stdcall shim_10(D2QueueServerStrc* pTable, unsigned int* pKey)
{
    return sub_006BF1F0_Release(pTable, pKey);
}

// 0x006BF660
int __thiscall D2MaskPairListStrc::sub_006BF660_HasMaskedKey(unsigned int nMask)
{
    const int n = nCount;
    for (int i = 0; i < n; ++i)
    {
        const D2MaskKeyStrc tKey = aPairs[i].tKey;
        if ((gaMaskTable_0074C3F0[aPairs[i].nMaskIndex] & nMask) == tKey.nValue)
            return 1;
    }
    return 0;
}

// calling-convention shim (not game code)
void __fastcall sub_006BF320_Shim(sub_006BF320_Server* pServer)
{
    sub_006BF320_FreePending(pServer);
    FOG_Free(pServer, ".\\Src\\QServer\\QServer.cpp", 0, 0);
}

// 0x006BFCD0
static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId)
{
    const unsigned int nBucket = nClientId & pServer->nMask;
    EnterCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);

    D2QClientStrc* pPrev = 0;
    D2QClientStrc* pClient = pServer->ppClients[nBucket];
    while (pClient)
    {
        if (pClient->nId == nClientId)
        {
            break;
        }
        pPrev = pClient;
        pClient = pClient->pNext;
    }

    if (!pClient)
    {
        sub_006BE2F0_Nop(&gszEmptyAssertText, "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        sub_006BE300_Log("QSRV", "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);
        return;
    }

    EnterCriticalSection((D2CriticalSectionStrc*)&pServer->tLock);
    --pServer->nClients;
    LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->tLock);

    if (pClient != pServer->ppClients[nBucket])
    {
        pPrev->pNext = pClient->pNext;
    }
    else
    {
        pServer->ppClients[nBucket] = pClient->pNext;
    }
    pClient->pNext = 0;
    LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);

    D2_ASSERT(nClientId == pClient->nId, 0x3E0);

    unsigned int* pAddress = &pClient->nAddress;
    sub_006BE300_Log("QSRV", "[sRemoveClient]  Remove client %d %s refcount=%d life=%d", nClientId,
        sub_006B013E_FormatAddress(*pAddress), pClient->nRefCount, sub_00410A80_GetTimeSeconds() - pClient->nCreateTime);

    D2CriticalSectionStrc* pLock = (D2CriticalSectionStrc*)&pServer->tAddressLock;
    EnterCriticalSection(pLock);

    const unsigned int nAddressBucket = pClient->nAddress & pServer->nMask;
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

    pLock = (D2CriticalSectionStrc*)&pServer->tLock;
    EnterCriticalSection(pLock);
    sub_006BF1F0_Release(pServer, pAddress);
    LeaveCriticalSection(pLock);
}

// 0x006BFFA0
int __fastcall sub_006BFFA0_CheckKeyFlood(D2QueueServerStrc* pServer, const int* pKey)
{
    if (pServer->nLimit < 1)
    {
        return 1;
    }

    const int nKey = *pKey;
    const unsigned int dwTickCount = GetTickCount();
    const unsigned int nMaxCount = 2 * pServer->nLimit + 3;
    sub_006BF260_ExpireNodes(pServer);
    EnterCriticalSection(&pServer->tLock);

    for (D2QServerNodeStrc* pNode = pServer->pHead; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (dwTickCount - pNode->dwTime < 15000)
            {
                ++pNode->nCount;
                if (pNode->nCount > nMaxCount)
                {
                    LeaveCriticalSection(&pServer->tLock);
                    return 0;
                }
            }
            else
            {
                pNode->dwTime = dwTickCount;
                pNode->nCount = 1;
            }
        }
    }

    D2QServerNodeStrc* pNew = (D2QServerNodeStrc*)FOG_Alloc(sizeof(D2QServerNodeStrc), ".\\Src\\QServer\\QServer.cpp", 0x553, 0);
    pNew->nKey = nKey;
    pNew->dwTime = dwTickCount;
    pNew->nCount = 1;
    pNew->pNext = 0;
    if (!pServer->pHead)
    {
        pServer->pHead = pNew;
    }
    else
    {
        pServer->pTail->pNext = pNew;
    }

    pServer->pTail = pNew;
    LeaveCriticalSection(&pServer->tLock);
    return 1;
}

// 0x006C00A0
static int __stdcall sub_006C00A0_AccountTraffic(D2QueueServerStrc* pTable, unsigned int nBytes, D2QClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->tLock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
    {
        return pTable->sub_006BF660_CheckAddress(pClient->nAddress) != 0;
    }

    if (dwTick - pClient->nTick24 > 1000)
    {
        EnterCriticalSection(pLock);
        pClient->nTick24 = dwTick;
        if (pClient->nPending >= 200)
        {
            pClient->nPending -= 200;
        }
        else
        {
            pClient->nPending = 0;
        }

        LeaveCriticalSection(pLock);
    }

    return 1;
}

unsigned int __stdcall sub_E4F1_Emit_006C00A0(D2QueueServerStrc* pTable, D2QClientStrc* pClient, unsigned int nBytes)
{
    if (sub_006C00A0_AccountTraffic(pTable, nBytes, pClient))
    {
        return 0;
    }

    return pClient->nAddress;
}

// 0x006C0360
void __fastcall sub_006C0360_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient)
{
    if (InterlockedDecrement(&pClient->nRefCount) == 0)
    {
        if (pServer->pfnOnRemove)
            pServer->pfnOnRemove(pServer, pClient->nId, ".\\Src\\QServer\\QServer.cpp", 891);
        sRemoveClient(pServer, pClient->nId);
        sub_006BE650_DestroyClient(pClient);
    }
}

// 0x006C0770
static void __stdcall sub_006C0770_BanClient(D2QueueServerStrc* table, int client, const char* file, int line)
{
    if (!table->bEnabled) return;
    unsigned int bucket = table->nMask & client;
    EnterCriticalSection(&table->pLocks[bucket]);
    D2QClientStrc* node = table->ppClients[bucket];
    unsigned int address = 0;
    while (node) {
        if (node->iId == client) { address = node->nAddress; break; }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[bucket]);
    sub_006C0420_CloseClient(table, client, file, line);
    if (address) sub_006BFEA0_RecordAddress(table, file, address, line);
}

// 0x006C08A0
void __fastcall sub_006C08A0_Dispatch(D2QueueServerStrc* server, D2QClientStrc* client)
{
    int start = 0, consumed = 0, queue = 0, charge = 0;
    while (server->pfnProcess) {
        EnterCriticalSection(&client->tLock);
        int count = client->iReadBytes;
        LeaveCriticalSection(&client->tLock);
        int result = server->pfnProcess(client->pBuffer, count, &consumed, &start, &queue, &charge, client->iId, client->nContext, client->nAddress);
        switch (result) {
        case 2:
            if (server->bEnabled && !sub_006C00A0_AccountTraffic(server, charge, client)) {
                sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to sQSSpamCheck in QSrvProcessMsg", sub_006B013E_InetNtoa(client->nAddress));
                sub_006C0770_BanClient(server, client->iId, gszFile_006FC460, 0x649);
                return;
            }
            break;
        case 3: return;
        case 4:
            sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to PACKET_INVALID in QSrvProcessMsg", sub_006B013E_InetNtoa(client->nAddress));
            sub_006C0770_BanClient(server, client->iId, gszFile_006FC460, 0x635);
            return;
        }
        if (result != 5) {
            D2MessageStrc* message;
            if (server->pFreeMessages) {
                EnterCriticalSection(&server->tLock);
                message = server->pFreeMessages;
                if (message) server->pFreeMessages = message->pNext;
                else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x664, 0);
                LeaveCriticalSection(&server->tLock);
            } else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x66D, 0);
            int size = consumed - start;
            if (size > 0) {
                EnterCriticalSection(&client->tLock);
                memcpy(message->aData, client->pBuffer + start, size);
                LeaveCriticalSection(&client->tLock);
            } else *(unsigned char*)message = 0;
            message->nSize = size;
            message->nTick = GetTickCount();
            message->pNext = 0;
            message->nClient = client->iId;
            D2_ASSERT(queue < server->nQueueCount, 0x6A1);
            EnterCriticalSection(&server->tLock);
            D2MessageStrc* tail = server->ppMsgTails[queue];
            if (!tail) server->ppMsgHeads[queue] = message;
            else tail->pNext = message;
            server->ppMsgTails[queue] = message;
            LeaveCriticalSection(&server->tLock);
        }
        EnterCriticalSection(&client->tLock);
        client->iReadBytes -= consumed;
        D2_ASSERT(client->iReadBytes + consumed <= 0x5B4, 0x6AD);
        memmove(client->pBuffer, client->pBuffer + consumed, client->iReadBytes);
        LeaveCriticalSection(&client->tLock);
        start = 0; consumed = 0; queue = 0; charge = 0;
    }
}

#include "gen/data/Source/Fog/Src/QServer/QServer_006BE5B0.inc"
