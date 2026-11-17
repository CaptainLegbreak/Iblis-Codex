struct D2CriticalSection006BE650Strc;
struct D2QMsg006BE650Strc;
struct D2QClient006BE650Strc;
struct D2HackEntryStrc;
struct D2CriticalSectionStrc;
struct D2HackListStrc;
struct D2HackNode006BE890Strc;
struct D2Server006BE890Strc;
struct D2InAddrStrc;
struct D2QServerIpNodeStrc;
struct D2QueueServerStrc;
struct D2QNode006BF1F0Strc;
struct D2QTable006BF1F0Strc;
struct D2MaskKeyStrc;
struct D2MaskPairStrc;
struct D2MaskPairListStrc;
struct D2ClientTableStrc;
struct D2ServerClientStrc;

extern "C" int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE300

struct D2CriticalSection006BE650Strc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSection006BE650Strc* pLock);

struct D2QMsg006BE650Strc
{
    unsigned int nSize;
    D2QMsg006BE650Strc* pNext;
};

struct D2QClient006BE650Strc
{
    unsigned char unk_00[0x04];
    D2QClient006BE650Strc* pNextClient;
    unsigned char unk_08[0x24];
    D2CriticalSection006BE650Strc pLock;
    unsigned char unk_44[0x30];
    D2QMsg006BE650Strc* pMsgHead;
};

static __declspec(noinline) void sub_006BE650_FreeClient(D2QClient006BE650Strc* ptClient);

struct D2HackEntryStrc
{
    unsigned int unk_00;
    unsigned int retentionSeconds;
    unsigned int activeSeconds;
    D2HackEntryStrc* next;
};

struct D2CriticalSectionStrc
{
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long spinCount;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* section);
extern const char gszHackCategory_006FC4A8[]; // 0x006FC4A8
extern const char gszHackListSize_006FC4B0[]; // 0x006FC4B0
void __cdecl sub_00410660_Log(const char* category, const char* format, ...); // 0x00410660

struct D2HackListStrc
{
    unsigned char unk_000[0x888];
    unsigned int lastTick;
    D2HackEntryStrc* freeEntries;
    unsigned int entryCount;
    D2CriticalSectionStrc section;
    D2HackEntryStrc** buckets;
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

struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2QServerIpNodeStrc
{
    unsigned long nAddress;
    int nCount;
    D2QServerIpNodeStrc* pNext;
};

struct D2QueueServerStrc
{
    char unk0x00[0x10];
    unsigned int nIpBuckets;
    char unk0x14[0x40 - 0x14];
    D2QServerIpNodeStrc** ppIpBuckets;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
static __declspec(noinline) int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress);

struct D2QNode006BF1F0Strc
{
    unsigned int nKey;
    int nRefCount;
    D2QNode006BF1F0Strc* pNext;
};

struct D2QTable006BF1F0Strc
{
    unsigned char unk_00[0x10];
    unsigned int nBuckets;
    unsigned char unk_14[0x2C];
    D2QNode006BF1F0Strc** ppBuckets;
};

static __declspec(noinline) int sub_006BF1F0_Release(D2QTable006BF1F0Strc* pTable, unsigned int* pKey);
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

struct D2ClientTableStrc
{
    char unk_000[0xBD0];
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};

struct D2ServerClientStrc
{
    char unk0x00[0x18];
    unsigned int f_18;
    char unk0x1C[0x08];
    unsigned long f_24;
    unsigned int nPending;
    D2CriticalSectionStrc lock;
};
static __declspec(noinline) int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc* pTable, unsigned int nBytes, D2ServerClientStrc* pClient);

// 0x006BE650
static void sub_006BE650_FreeClient(D2QClient006BE650Strc* ptClient)
{
    if (ptClient->pNextClient)
    {
        sub_006BE300_Nop("QSRV", "  ptClient->ptNextClient =  %08X", ptClient->pNextClient);
    }
    D2QMsg006BE650Strc* pMsg = ptClient->pMsgHead;
    while (pMsg)
    {
        D2QMsg006BE650Strc* pFree = pMsg;
        pMsg = pMsg->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x3A7, 0);
    }
    ptClient->pMsgHead = 0;
    DeleteCriticalSection(&ptClient->pLock);
    FOG_Free(ptClient, ".\\Src\\QServer\\QServer.cpp", 0x3AE, 0);
}

// calling-convention shim (not game code)
void __stdcall shim_8(D2QClient006BE650Strc* ptClient)
{
    sub_006BE650_FreeClient(ptClient);
}

unsigned int gnLastHackListLog_00989C34; // 0x00989C34

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
            D2HackEntryStrc* current = buckets[i];
            D2HackEntryStrc* previous = 0;
            while (current)
            {
                D2HackEntryStrc* next = current->next;
                if (current->activeSeconds)
                {
                    if (current->activeSeconds > seconds)
                        current->activeSeconds -= seconds;
                    else
                    {
                        current->activeSeconds = 0;
                        if (seconds < 120)
                            current->retentionSeconds = 120 - seconds;
                        else
                            current->retentionSeconds = 0;
                        current->retentionSeconds += seconds;
                    }
                }
                if (current->retentionSeconds)
                {
                    if (current->retentionSeconds > seconds)
                        current->retentionSeconds -= seconds;
                    else
                    {
                        if (previous)
                        {
                            previous->next = next;
                            current->next = freeEntries;
                            freeEntries = current;
                            current = previous;
                        }
                        else
                        {
                            buckets[i] = buckets[i]->next;
                            current->next = freeEntries;
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
                sub_00410660_Log(gszHackCategory_006FC4A8, gszHackListSize_006FC4B0, count);
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
        sub_00410660_Log("HACK", "[HACKLIST]  Hacklist size is %d", nSize);
        gdwLastHackListLog_00989C34 = dwTick;
    }
}

// 0x006BF180
static int __cdecl sub_006BF180_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    const unsigned long nAddress = pAddress->s_addr;
    const unsigned int nBucket = nAddress % pServer->nIpBuckets;

    for (D2QServerIpNodeStrc* pNode = pServer->ppIpBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nAddress == nAddress)
        {
            ++pNode->nCount;
            return 1;
        }
    }

    D2QServerIpNodeStrc* pNew = (D2QServerIpNodeStrc*)FOG_Alloc(sizeof(D2QServerIpNodeStrc), ".\\Src\\QServer\\QServer.cpp", 0x919, 0);
    pNew->nAddress = nAddress;
    pNew->nCount = 1;
    pNew->pNext = pServer->ppIpBuckets[nBucket];
    pServer->ppIpBuckets[nBucket] = pNew;
    return 1;
}

// build: context sub_006BF180_Shim
// calling-convention shim (not game code)
int __cdecl sub_006BF180_Shim(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    return sub_006BF180_IncrementPerIpConnCount(pServer, pAddress);
}

// 0x006BF1F0
static int sub_006BF1F0_Release(D2QTable006BF1F0Strc* pTable, unsigned int* pKey)
{
    const unsigned int nKey = *pKey;
    const unsigned int nBucket = nKey % pTable->nBuckets;
    D2QNode006BF1F0Strc* pPrev = 0;
    for (D2QNode006BF1F0Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
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
                    pTable->ppBuckets[nBucket] = pNode->pNext;
                }
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x940, 0);
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// calling-convention shim (not game code)
int __stdcall shim_10(D2QTable006BF1F0Strc* pTable, unsigned int* pKey)
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

#include "gen/data/Source/Fog/Src/QServer/QServer_006BE650.inc"

// 0x006C00A0
static int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc* pTable, unsigned int nBytes, D2ServerClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->lock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
    {
        return pTable->sub_006BF660_CheckAddress(pClient->f_18) != 0;
    }

    if (dwTick - pClient->f_24 > 1000)
    {
        EnterCriticalSection(pLock);
        pClient->f_24 = dwTick;
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

unsigned int __stdcall sub_E4F1_Emit_006C00A0(D2ClientTableStrc* pTable, D2ServerClientStrc* pClient, unsigned int nBytes)
{
    if (sub_006C00A0_AccountTraffic(pTable, nBytes, pClient))
    {
        return 0;
    }

    return pClient->f_18;
}
