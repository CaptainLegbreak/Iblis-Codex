#include "Fog.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct QServer;
struct D2PacketBufferStrc;
struct D2QNodeStrc;
struct D2CriticalSectionStrc;
struct D2ServerNode006BE3C0Strc;
struct D2Server006BE3C0Strc;
struct Obj006BE450;
struct D2Worker006BE4A0Strc;
struct D2Object006BE4E0Strc;
struct D2HashNode006BE540Strc;
struct D2HashTable006BE540Strc;
struct D2ReferenceStrc;
struct D2ServerNode006BE980Strc;
struct D2Server006BE980Strc;
struct D2RecordNodeStrc;
struct D2RecordTableStrc;
struct D2NetPacketStrc;
struct D2NetQueueStrc;
struct D2HashNode006BEC00Strc;
struct D2HashTable006BEC00Strc;
struct D2HashNodeStrc;
struct D2HashTableStrc;
struct D2SocketNodeStrc;
struct D2SocketTableStrc;
struct D2HashNode006BEF40Strc;
struct D2HashTable006BEF40Strc;
struct D2Server006BEFB0Strc;
struct D2QueueServerStrc;
struct D2Object006BF040Strc;
struct Obj006BF080;
struct Obj006BF4E0;
struct D2PairEntry006BF610Strc;
struct D2PairTable006BF610Strc;
struct D2ServerStrc;
struct D2RecordStrc;
struct D2QServerConfigStrc;
struct D2AddressRecordStrc;
struct D2ClientTableStrc;
struct D2ConnectionNodeStrc;
struct D2ConnectionTableStrc;
struct D2ClientNodeStrc;
struct D2SrvClientStrc;

extern int gdwGlobal_00970E50; // 0x00970E50
extern char gData_007C90C8[]; // 0x007C90C8
extern int gdwGlobal_00970E8C; // 0x00970E8C

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2ServerNode006BE3C0Strc
{
    unsigned char unk_000[0x5BC];
    D2ServerNode006BE3C0Strc* pNext;
};

struct D2Server006BE3C0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock;
    unsigned char unk_86C[4];
    D2ServerNode006BE3C0Strc** ppHeads;
    D2ServerNode006BE3C0Strc** ppTails;
    unsigned char unk_878[4];
    int nSlots;
};

struct Obj006BE450 { unsigned char bUnknown00[0x880]; unsigned int dwValue880; };

struct D2Worker006BE4A0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock854;
    unsigned char unk_86C[0x884 - 0x86C];
    unsigned int nCount884;
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct D2Object006BE4E0Strc
{
    int nClosed00;
    unsigned char unk_004[0xBD0];
    void* hEventBD4;
};

struct D2HashNode006BE540Strc
{
    unsigned int nKey;
    D2HashNode006BE540Strc* pNext;
};

struct D2HashTable006BE540Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BE540Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

struct D2ReferenceStrc
{
    int unk_00;
    int unk_04;
    volatile long nReferences;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value); // 0x006CC208
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
void __cdecl sub_00410660_LogWritePrefixed(const char* szChannel, const char* szFormat, ...); // 0x00410660
extern const char gszHackChannel_006FC4A8[]; // 0x006FC4A8
extern const char gszHackListSizeFormat_006FC4B0[]; // 0x006FC4B0
extern unsigned long gdwLastLogTick_00989C34; // 0x00989C34

struct D2ServerNode006BE980Strc
{
    unsigned int nKey;
    unsigned char unk_04[4];
    int nTimer8;
    D2ServerNode006BE980Strc* pNext;
};

struct D2Server006BE980Strc
{
    unsigned char unk_000[0x894];
    D2CriticalSectionStrc tLock;
    D2ServerNode006BE980Strc** ppBuckets;
    unsigned int nBuckets;

    int sub_006BE980_Refresh(unsigned int nKey);
};

struct D2RecordNodeStrc { unsigned int key; int value; D2RecordNodeStrc* next; };

struct D2RecordTableStrc {
    unsigned char unknown0[0x10];
    unsigned int bucketCount;
    unsigned char unknown14[0x2c];
    D2RecordNodeStrc** buckets;
    unsigned char unknown44[0x810];
    D2CriticalSectionStrc lock;
    unsigned char unknown86c[0x18];
    int threshold;
};

struct D2NetPacketStrc
{
    unsigned char data[0x5B4];
    int nSize;
    int unk_5B8;
    D2NetPacketStrc* pNext;
};

struct D2NetQueueStrc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc lock;
    unsigned char unk_86C[0x4];
    D2NetPacketStrc** ppHeads;
    D2NetPacketStrc** ppTails;
    D2NetPacketStrc* pFree;
    int nQueues;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __fastcall sub_006C30D0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds); // 0x006C30D0

struct D2HashNode006BEC00Strc
{
    unsigned int nKey;
    D2HashNode006BEC00Strc* pNext;
};

struct D2HashTable006BEC00Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BEC00Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

struct D2HashNodeStrc
{
    unsigned int key;
    D2HashNodeStrc* next;
    unsigned int reserved08[2];
    unsigned char unk_10[0x4];
    unsigned int reserved14;
    union
    {
        D2InAddrStrc address;
        void* value;
    };
};

struct D2HashTableStrc
{
    unsigned int reserved0[2];
    unsigned int count;
    unsigned int mask;
    unsigned int reserved10;
    D2HashNodeStrc** buckets;
    unsigned int reserved18;
    D2CriticalSectionStrc* locks;
};

extern "C" char* __stdcall inet_ntoa(D2InAddrStrc); // 0x006B013E
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0

struct D2SocketNodeStrc
{
    void* key;
    D2SocketNodeStrc* next;
    unsigned int reserved08[2];
    unsigned int socket;
};

struct D2SocketTableStrc
{
    unsigned int reserved00[3];
    unsigned int mask;
    unsigned int reserved10;
    D2SocketNodeStrc** buckets;
    unsigned int reserved18;
    D2CriticalSectionStrc* locks;
};

extern "C" int __stdcall getpeername(unsigned int, void*, int*); // 0x006B018C

struct D2HashNode006BEF40Strc
{
    unsigned int nKey;
    D2HashNode006BEF40Strc* pNext;
    unsigned char unk_08[8];
    int nValue;
};

struct D2HashTable006BEF40Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BEF40Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

struct D2Server006BEFB0Strc
{
    unsigned char unk_000[0xBD0];
    int bHackListBD0;
};

char* __stdcall sub_006B013E_InetNtoa(unsigned long dwAddress); // 0x006B013E
void __fastcall sub_006BE890_UnlistIP(D2Server006BEFB0Strc* pServer, const char* szFile, unsigned long dwAddress, int nLine); // 0x006BE890

struct D2QueueServerStrc
{
    int bAltSend;
    int unk0x04;
    unsigned int nBuckets;
    int unk0x0C[2];
    D2SrvClientStrc** ppBuckets;
    int unk0x18;
    D2CriticalSectionStrc* pLocks;
    unsigned char unk_20[0x870];
    int unk0x890;
    char unk0x894[0xBD0 - 0x894];
    int unk0xBD0;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct D2Object006BF040Strc
{
    unsigned char unk_000[0xBB8];
    int nValueBB8;
};

struct Obj006BF080 { unsigned char bUnknown00[0xBBC]; unsigned int dwValueBBC; };

struct Obj006BF4E0 { unsigned char bUnknown00[0xBD0]; unsigned int dwValueBD0; };

struct D2PairEntry006BF610Strc
{
    int nKey;
    int nValue;
};

struct D2PairTable006BF610Strc
{
    unsigned char unk_000[0x48];
    D2PairEntry006BF610Strc pEntries[256];
    int nCount;
};

struct D2ServerStrc
{
    unsigned char unknown[0x8b4];
    D2CriticalSectionStrc lock;
    unsigned char records[0x2dc];
    int values[1];
    int __thiscall sub_006BF660_CheckClient(int clientId); // 0x006BF660
};

struct D2RecordStrc { unsigned char data[0xac]; int value; };

typedef int (__fastcall* D2NET_ValidatePacketCallback)(D2PacketBufferStrc*, int, int*, int*, int*, int*, int, int, int);

typedef int (__fastcall* D2NET_ClientCallback)(QServer*, int, const char*, int);

typedef int (__fastcall* D2NET_PacketCallback)(int, int, int, int);

typedef int (__fastcall* D2NET_ReadPacketCallback)(QServer*, D2PacketBufferStrc*, int);

struct QServer
{
    int bUseNt;
    int unk004;
    int nClientCapacity;
    int nValue00C;
    int nValue010;
    D2QClientStrc** ppClientSlots;
    int nClientSlotCount;
    D2CriticalSectionStrc* pLocks;
    void** ppSlots020;
    int nSlotCount024;
    D2CriticalSectionStrc tLock028;
    void** ppSlots040;
    int nSlotCount044;
    char unk048[0x804];
    D2QNodeStrc* pChain84C;
    D2QNodeStrc* pChain850;
    D2CriticalSectionStrc tLock854;
    int nState;
    void** ppSlots870;
    void** ppSlots874;
    D2QClientStrc* pClients;
    int nSlotCount87C;
    int nValue880;
    int bStarted884;
    unsigned int nSocket888;
    D2QNodeStrc* pChain88C;
    int nValue890;
    D2CriticalSectionStrc tLock894;
    D2QNodeStrc** ppBuckets;
    int nBuckets;
    D2CriticalSectionStrc tLock8B4;
    char unk8CC[0x2C4];
    unsigned int aSockets[4];
    char unkBA0[0x20];
    D2NET_ValidatePacketCallback pfCallback1;
    D2NET_ClientCallback pfCallback2;
    D2NET_PacketCallback pfCallback3;
    D2NET_ReadPacketCallback pfReadPacket;
    int nValueBD0;
    char unkBD4[0x44];
    int nValueC18;
    char unkC1C[0x30];
};
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
int __cdecl sub_00410960_IsPlatformNT(); // 0x00410960
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, QServer* pServer); // 0x006BE300
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3360_Startup(QServer* pServer, int nPort); // 0x006C3360
int __fastcall sub_006C3B50_StartServer(QServer* pServer, int nPort); // 0x006C3B50
extern "C" const char gszQServerTag_006FC47C[]; // 0x006FC47C
extern "C" const char gszQServerAllocated_006FC548[]; // 0x006FC548

struct D2AddressRecordStrc
{
    unsigned int f_0;
    int f_4;
    int nRefresh;
    D2AddressRecordStrc* pNext;
};

typedef void (__fastcall* D2AddressCallback)(unsigned int, const char*, int);

struct D2ClientTableStrc
{
    unsigned char pad0[0xC];
    unsigned int mask;
    unsigned char pad1[4];
    D2ClientNodeStrc** buckets;
    unsigned char pad2[4];
    D2CriticalSectionStrc* locks;
    unsigned char unk_20[0x86C];
    D2AddressRecordStrc* pFree;
    int nCount;
    D2CriticalSectionStrc lock;
    D2AddressRecordStrc** ppBuckets;
    unsigned int f_8B0;
    char unk_8B4[0x304];
    D2AddressCallback pfnCallback;
    char unk_BBC[0x14];
    int enabled;
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};
void __stdcall sub_006BE6C0_LogHackListSize(int nSize); // 0x006BE6C0
int __fastcall sub_006C0420_ProcessClient(QServer* pServer, int nClientId, const char* szFile, int nLine); // 0x006C0420

struct D2ConnectionNodeStrc
{
    int nClient;
    char unk_04[0x14];
    unsigned int nIP;
    D2ConnectionNodeStrc* pNext;
};

struct D2ConnectionTableStrc
{
    char unk_00[0xC];
    unsigned int nMask;
    char unk_10[0x10];
    D2ConnectionNodeStrc** ppBuckets;
    int unk_24;
    D2CriticalSectionStrc tLock;
};
void __fastcall QSrvCloseRemoteConnection(D2ConnectionTableStrc* pTable, int nClient, const char* pFile, int nLine); // 0x006C0420
const char* __stdcall sub_006B013E_FormatIP(unsigned int nIP); // 0x006B013E

struct D2ClientNodeStrc { int client; D2ClientNodeStrc* next; unsigned char pad[0x10]; unsigned int address; };

void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc* table, int client, const char* file, int line); // 0x006C0420
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0

struct D2SrvClientStrc
{
    int unk0x00;
    D2SrvClientStrc* pNext;
    int unk0x08;
    int bClosed;
};

int __fastcall sub_006C2C70(D2QueueServerStrc* pServer, D2SrvClientStrc* pClient, char* pData, int nSize); // 0x006C2C70
int __fastcall sub_006C3410_Send(D2QueueServerStrc* pServer, D2SrvClientStrc* pClient, char* pData, int nSize); // 0x006C3410

// 0x006B1C00
int __cdecl sub_006B1C00()
{
    return gdwGlobal_00970E50;
}

// 0x006B20A0
void* __cdecl sub_006B20A0()
{
    return gData_007C90C8;
}

// 0x006B20B0
int __cdecl sub_006B20B0()
{
    return 0;
}

// 0x006B2F20
int __cdecl sub_006B2F20()
{
    return gdwGlobal_00970E8C;
}

// 0x006B76C0
void __stdcall sub_006B76C0(int nUnused1, int nUnused2)
{
}

// 0x006BC850
void __stdcall sub_006BC850(int nUnused1)
{
}

static int gnLockCount_0074C3E0; // 0x0074C3E0

static int gnGlobal_0074C3E4; // 0x0074C3E4

static int gnGlobal_0074C3E8; // 0x0074C3E8

static int gnGlobal_0074C3EC; // 0x0074C3EC

static int gnGlobal_00989C28; // 0x00989C28

// 0x006BE310
void __stdcall sub_006BE310_SetServerConfig(D2QServerConfigStrc* pConfig)
{
    gnLockCount_0074C3E0 = pConfig->nClientCapacity;
    gnGlobal_0074C3E4 = pConfig->nClientCapacity - 1;
    gnGlobal_0074C3E8 = pConfig->nValue04;
    gnGlobal_0074C3EC = pConfig->nValue08;
    gnGlobal_00989C28 = pConfig->nValue0C;
}

// 0x006BE3C0
int __stdcall sub_006BE3C0_FreeAllSlots(D2Server006BE3C0Strc* pServer)
{
    for (int i = 0; i < pServer->nSlots; ++i)
    {
        EnterCriticalSection(&pServer->tLock);
        D2ServerNode006BE3C0Strc* pNode = pServer->ppHeads[i];
        pServer->ppHeads[i] = 0;
        pServer->ppTails[i] = 0;
        LeaveCriticalSection(&pServer->tLock);
        while (pNode)
        {
            D2ServerNode006BE3C0Strc* pFree = pNode;
            pNode = pNode->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x1B9, 0);
        }
    }
    return 1;
}

// 0x006BE450
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BE450(Obj006BE450* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue880;
}

// 0x006BE4A0
void __stdcall sub_006BE4A0_SetCount(D2Worker006BE4A0Strc* pWorker, unsigned int nCount)
{
    if (pWorker)
    {
        if (nCount <= 0)
            nCount = 1;
        EnterCriticalSection(&pWorker->tLock854);
        pWorker->nCount884 = nCount;
        LeaveCriticalSection(&pWorker->tLock854);
    }
}

// 0x006BE4E0
unsigned long __stdcall sub_006BE4E0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (pObject->nClosed00)
        return 0;
    return WaitForSingleObject(pObject->hEventBD4, dwMilliseconds);
}

// 0x006BE540
D2HashNode006BE540Strc* __fastcall sub_006BE540_Find(D2HashTable006BE540Strc* pTable, unsigned int nKey)
{
    if (!pTable)
    {
        return 0;
    }
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2HashNode006BE540Strc* pNode;
    for (pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            break;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return pNode;
}

// 0x006BE640
long __fastcall sub_006BE640_AddReference(void* unusedContext, D2ReferenceStrc* object)
{
    return InterlockedIncrement(&object->nReferences);
}

// 0x006BE6C0
void __stdcall sub_006BE6C0_LogHackListSize(int nSize)
{
    const unsigned long dwNow = GetTickCount();
    if (dwNow - gdwLastLogTick_00989C34 > 2000)
    {
        sub_00410660_LogWritePrefixed(gszHackChannel_006FC4A8, gszHackListSizeFormat_006FC4B0, nSize);
        gdwLastLogTick_00989C34 = dwNow;
    }
}

// 0x006BE980
int D2Server006BE980Strc::sub_006BE980_Refresh(unsigned int nKey)
{
    EnterCriticalSection(&tLock);
    for (D2ServerNode006BE980Strc* pNode = ppBuckets[nKey % nBuckets]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->nTimer8)
            {
                pNode->nTimer8 = 120;
                LeaveCriticalSection(&tLock);
                return 1;
            }
            LeaveCriticalSection(&tLock);
            return 0;
        }
    }
    LeaveCriticalSection(&tLock);
    return 0;
}

// 0x006BE9F0
int __fastcall sub_006BE9F0_CheckRecordThreshold(D2RecordTableStrc* table, const unsigned int* keyPointer)
{
    if (table->threshold < 0) return 0;
    unsigned int key = *keyPointer;
    unsigned int index = key % table->bucketCount;
    EnterCriticalSection(&table->lock);
    D2RecordNodeStrc* node = table->buckets[index];
    while (node) {
        if (node->key == key) {
            int value = node->value;
            LeaveCriticalSection(&table->lock);
            return value >= table->threshold;
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->lock);
    return 0;
}

// 0x006BEAD0
int __stdcall sub_006BEAD0_ReceivePacket(D2NetQueueStrc* pQueue, int nIndex, void* pDst, unsigned int nMax)
{
    if (!pQueue)
    {
        return -1;
    }
    if (nIndex >= pQueue->nQueues)
    {
        return -1;
    }
    if (nMax > 0x5B4)
    {
        nMax = 0x5B4;
    }

    EnterCriticalSection(&pQueue->lock);
    D2NetPacketStrc* pPacket = pQueue->ppHeads[nIndex];
    if (!pPacket)
    {
        LeaveCriticalSection(&pQueue->lock);
        return -1;
    }
    pQueue->ppHeads[nIndex] = pPacket->pNext;
    if (pQueue->ppTails[nIndex] == pPacket)
    {
        pQueue->ppTails[nIndex] = 0;
    }
    LeaveCriticalSection(&pQueue->lock);

    const int nCopy = (pPacket->nSize + 4 > (int)nMax) ? nMax : pPacket->nSize + 4;
    memcpy(pDst, pPacket, nCopy);
    int nResult = pPacket->nSize;
    memset(pPacket, 0, sizeof(D2NetPacketStrc));

    EnterCriticalSection(&pQueue->lock);
    pPacket->pNext = pQueue->pFree;
    pQueue->pFree = pPacket;
    LeaveCriticalSection(&pQueue->lock);
    return nResult;
}

static inline int sub_006BEBC0_WaitHandle(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (!pObject->nClosed00)
        return WaitForSingleObject(pObject->hEventBD4, dwMilliseconds);
    return 0;
}

// 0x006BEBC0
int __stdcall sub_006BEBC0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (pObject->nClosed00)
        return sub_006C30D0_Wait(pObject, dwMilliseconds);
    return !sub_006BEBC0_WaitHandle(pObject, dwMilliseconds);
}

// 0x006BEC00
D2HashNode006BEC00Strc* __fastcall sub_006BEC00_FindLocked(D2HashTable006BEC00Strc* pTable, unsigned int nKey, D2CriticalSectionStrc** ppLock)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2HashNode006BEC00Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            *ppLock = &pTable->pLocks[nBucket];
            return pNode;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return 0;
}

static inline int sub_006BED90_MatchKey(const D2HashNodeStrc* node, unsigned int key)
{
    return node->key == key;
}

// 0x006BED90
void __stdcall sub_006BED90_GetAddressText(D2HashTableStrc* table, unsigned int key, char* output, unsigned int size)
{
    unsigned int index = table->mask & key;
    EnterCriticalSection(&table->locks[index]);
    D2HashNodeStrc* node = table->buckets[index];
    while (node) {
        if (sub_006BED90_MatchKey(node, key)) {
            const char* text = inet_ntoa(node->address);
            SStrCopy(output, text, size);
            LeaveCriticalSection(&table->locks[index]);
            return;
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[index]);
    *output = 0;
}

// 0x006BEE20
void* __stdcall sub_006BEE20_FindLocked(D2HashTableStrc* table, unsigned int key)
{
    unsigned int index = key & table->mask;
    EnterCriticalSection(&table->locks[index]);
    D2HashNodeStrc* node = table->buckets[index];
    while (node) {
        if (node->key == key) {
            void* value = node->value;
            LeaveCriticalSection(&table->locks[index]);
            return value;
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[index]);
    return 0;
}

// 0x006BEE90
unsigned int __stdcall sub_006BEE90_GetPeerAddress(D2SocketTableStrc* table, void* key)
{
    const unsigned int index = table->mask & (unsigned int)key;
    EnterCriticalSection(&table->locks[index]);
    D2SocketNodeStrc* node = table->buckets[index];
    while (node)
    {
        if (node->key == key)
        {
            const unsigned int socket = node->socket;
            LeaveCriticalSection(&table->locks[index]);
            char address[16];
            int length = sizeof(address);
            getpeername(socket, address, &length);
            return *(unsigned int*)(address + 4);
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[index]);
    return 0;
}

// 0x006BEF40
int __stdcall sub_006BEF40_GetValue(D2HashTable006BEF40Strc* pTable, unsigned int nKey)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2HashNode006BEF40Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            const int nValue = pNode->nValue;
            LeaveCriticalSection(&pTable->pLocks[nBucket]);
            return nValue;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return -1;
}

// 0x006BEFB0
void __stdcall sub_006BEFB0_HackUnlistIP(D2Server006BEFB0Strc* pServer, unsigned long dwAddress, const char* szFile, int nLine)
{
    if (pServer->bHackListBD0)
    {
        sub_00410660_LogWritePrefixed(gszHackChannel_006FC4A8, "[HACKLIST]  IP:%s  QSHackUnlistIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(dwAddress), szFile, nLine);
        sub_006BE890_UnlistIP(pServer, szFile, dwAddress, nLine);
    }
}

// 0x006BF000
void __stdcall sub_006BF000_QSHackListSize(D2QueueServerStrc* pServer, unsigned int nFile, unsigned int nLine)
{
    if (pServer->unk0xBD0)
    {
        sub_00410660_LogWritePrefixed("HACK", "[HACKLIST]  Size:%s  QSHackListSize() from FILE:%s  LINE:%d", pServer->unk0x890, nFile, nLine);
    }
}

// 0x006BF040
void __stdcall sub_006BF040_SetValue(D2Object006BF040Strc* pObject, int nValue)
{
    D2_ASSERT(pObject, 0x842);
    pObject->nValueBB8 = nValue;
}

// 0x006BF080
extern "C" __declspec(dllexport) void __stdcall sub_006BF080(Obj006BF080* pObj, unsigned int dwValue) {
    pObj->dwValueBBC = dwValue;
}

// 0x006BF4E0
extern "C" __declspec(dllexport) void __stdcall sub_006BF4E0(Obj006BF4E0* pObj, unsigned int dwValue) {
    pObj->dwValueBD0 = dwValue;
}

// 0x006BF5F0
void __stdcall sub_006BF5F0(int nUnused1)
{
}

// 0x006BF600
void __stdcall sub_006BF600(int nUnused1, int nUnused2)
{
}

// 0x006BF610
void __fastcall sub_006BF610_AddPair(D2PairTable006BF610Strc* pTable, int nValue, int nKey)
{
    if (pTable->nCount < 256)
    {
        for (int i = 0; i < pTable->nCount; ++i)
        {
            if (pTable->pEntries[i].nKey == nKey)
            {
                return;
            }
        }
        pTable->pEntries[pTable->nCount].nKey = nKey;
        pTable->pEntries[pTable->nCount].nValue = nValue;
        ++pTable->nCount;
    }
}

// 0x006BF6C0
int __fastcall sub_006BF6C0(D2ServerStrc* server, int clientId)
{
    return server->sub_006BF660_CheckClient(clientId);
}

// 0x006BF6D0
void __fastcall sub_006BF6D0_CopyRecords(D2ServerStrc* server,D2RecordStrc* destination,int count)
{
 EnterCriticalSection(&server->lock);
 memcpy(destination,server->records,count*sizeof(D2RecordStrc));
 LeaveCriticalSection(&server->lock);
 for (int i=0;i<count;++i) destination[i].value=server->values[i];
}

// 0x006BF740
void __cdecl sub_006BF740_Nop()
{
}

// 0x006BF750
void __cdecl sub_006BF750_Nop()
{
}

// 0x006BF760
QServer* __stdcall QSInit(int nState, int nSlots, int nPort, int bDisableNt, D2NET_ValidatePacketCallback pfCallback1, D2NET_ClientCallback pfCallback2, D2NET_PacketCallback pfCallback3, D2NET_ReadPacketCallback pfReadPacket)
{
    D2WSADataStrc tWsaData;
    QServer* pServer = (QServer*)FOG_Alloc(sizeof(QServer), gszQServerFile_006FC460, 148, 0);
    memset(pServer, 0, sizeof(QServer));
    pServer->nClientCapacity = gnLockCount_0074C3E0;
    pServer->nValue00C = gnGlobal_0074C3E4;
    pServer->nValue010 = gnGlobal_0074C3E8;
    pServer->nValueC18 = gnGlobal_00989C28;
    pServer->nClientSlotCount = gnLockCount_0074C3E0;
    pServer->ppClientSlots = (D2QClientStrc**)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(D2QClientStrc*), gszQServerFile_006FC460, 159, 0);
    memset(pServer->ppClientSlots, 0, gnLockCount_0074C3E0 * sizeof(D2QClientStrc*));
    pServer->pLocks = (D2CriticalSectionStrc*)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(D2CriticalSectionStrc), gszQServerFile_006FC460, 162, 0);
    memset(pServer->pLocks, 0, gnLockCount_0074C3E0 * sizeof(D2CriticalSectionStrc));
    for (int i = 0; i < gnLockCount_0074C3E0; ++i)
        InitializeCriticalSection(&pServer->pLocks[i]);
    pServer->nSlotCount024 = gnLockCount_0074C3E0;
    pServer->ppSlots020 = (void**)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(void*), gszQServerFile_006FC460, 169, 0);
    memset(pServer->ppSlots020, 0, gnLockCount_0074C3E0 * sizeof(void*));
    InitializeCriticalSection(&pServer->tLock028);
    pServer->nSlotCount044 = gnGlobal_0074C3E8;
    pServer->ppSlots040 = (void**)FOG_Alloc(gnGlobal_0074C3E8 * sizeof(void*), gszQServerFile_006FC460, 175, 0);
    memset(pServer->ppSlots040, 0, gnGlobal_0074C3E8 * sizeof(void*));
    pServer->nBuckets = gnGlobal_0074C3EC;
    pServer->ppBuckets = (D2QNodeStrc**)FOG_Alloc(gnGlobal_0074C3EC * sizeof(D2QNodeStrc*), gszQServerFile_006FC460, 180, 0);
    memset(pServer->ppBuckets, 0, gnGlobal_0074C3EC * sizeof(D2QNodeStrc*));
    sub_006BE300_Nop(gszQServerTag_006FC47C, gszQServerAllocated_006FC548, pServer);
    pServer->nValue880 = 0;
    pServer->pChain84C = 0;
    pServer->pChain850 = 0;
    pServer->pfCallback1 = pfCallback1;
    pServer->pfCallback2 = pfCallback2;
    pServer->pfCallback3 = pfCallback3;
    pServer->pfReadPacket = pfReadPacket;
    pServer->nSocket888 = -1;
    pServer->nValue890 = 0;
    pServer->nValueBD0 = 1;
    InitializeCriticalSection(&pServer->tLock894);
    InitializeCriticalSection(&pServer->tLock8B4);
    pServer->aSockets[0] = -1;
    pServer->aSockets[1] = -1;
    pServer->aSockets[2] = -1;
    pServer->aSockets[3] = -1;
    pServer->ppSlots870 = (void**)FOG_Alloc(nSlots * sizeof(void*), gszQServerFile_006FC460, 218, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppSlots870[i] = 0;
    pServer->ppSlots874 = (void**)FOG_Alloc(nSlots * sizeof(void*), gszQServerFile_006FC460, 222, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppSlots874[i] = 0;
    pServer->nSlotCount87C = nSlots;
    pServer->pClients = 0;
    pServer->pChain88C = 0;
    InitializeCriticalSection(&pServer->tLock854);
    if (sub_00410960_IsPlatformNT() && !bDisableNt)
        pServer->bUseNt = 1;
    else
        pServer->bUseNt = 0;
    pServer->nState = nState;
    if (nState != 1 && nState != 2)
    {
        if (!WSAStartup(0x101, &tWsaData))
        {
            if (pServer->bUseNt)
                sub_006C3360_Startup(pServer, nPort);
            else
                sub_006C3B50_StartServer(pServer, nPort);
        }
    }
    return pServer;
}

static __declspec(noinline)
// 0x006C0770
void __stdcall sub_006C0770_BanClient(D2ClientTableStrc* table, int client, const char* file, int line)
{
    if (!table->enabled)
        return;
    unsigned int bucket = table->mask & client;
    EnterCriticalSection(&table->locks[bucket]);
    D2ClientNodeStrc* node = table->buckets[bucket];
    unsigned int address = 0;
    while (node)
    {
        if (node->client == client)
        {
            address = node->address;
            break;
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[bucket]);
    sub_006C0420_CloseClient(table, client, file, line);
    if (address)
        sub_006BFEA0_RecordAddress(table, file, address, line);
}

void __fastcall EmitBanClient(D2ClientTableStrc* table, int client, const char* file, int line)
{
    sub_006C0770_BanClient(table + 1, client, file, line);
}

// 0x006BFAD0
int __stdcall sub_006BFAD0_BroadcastToAllClients(D2QueueServerStrc* pServer, char* pData, int nSize)
{
    for (unsigned int i = 0; i < pServer->nBuckets; ++i)
    {
        EnterCriticalSection(&pServer->pLocks[i]);
        D2SrvClientStrc* pClient = pServer->ppBuckets[i];
        do
        {
            if (!pClient)
            {
                break;
            }

            if (!pClient->bClosed)
            {
                if (pServer->bAltSend)
                {
                    sub_006C2C70(pServer, pClient, pData, nSize);
                }
                else
                {
                    sub_006C3410_Send(pServer, pClient, pData, nSize);
                }
            }

            pClient = pClient->pNext;
        }
        while (pClient);
        LeaveCriticalSection(&pServer->pLocks[i]);
    }

    return 1;
}

#include "gen/data/Source/Fog/Src/QServer/QServer.inc"

// 0x006BFEA0
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc* pTable, const char* szFile, unsigned int nAddress, int nLine)
{
    if (!pTable->enabled)
        return;
    if (pTable->sub_006BF660_CheckAddress(nAddress))
        return;
    if (pTable->pfnCallback)
        pTable->pfnCallback(nAddress, szFile, nLine);
    D2CriticalSectionStrc* pLock = &pTable->lock;
    EnterCriticalSection(pLock);
    unsigned int nBucket = nAddress % pTable->f_8B0;
    D2AddressRecordStrc* pRecord = pTable->ppBuckets[nBucket];
    while (pRecord && pRecord->f_0 != nAddress)
        pRecord = pRecord->pNext;
    if (pRecord)
    {
        pRecord->nRefresh = 120;
        LeaveCriticalSection(pLock);
        return;
    }
    pRecord = pTable->pFree;
    if (pRecord)
        pTable->pFree = pRecord->pNext;
    else
        pRecord = (D2AddressRecordStrc*)FOG_Alloc(sizeof(D2AddressRecordStrc), gszServerFile_006FC460, 0x4AA, 0);
    pRecord->f_0 = nAddress;
    pRecord->f_4 = 120;
    pRecord->nRefresh = 0;
    pRecord->pNext = pTable->ppBuckets[nBucket];
    pTable->ppBuckets[nBucket] = pRecord;
    ++pTable->nCount;
    LeaveCriticalSection(pLock);
    sub_006BE6C0_LogHackListSize(pTable->nCount);
}

// 0x006C06B0
int __stdcall FOG_10165(QServer* pServer, int nClientId, const char* szFile, int nLine)
{
    return sub_006C0420_ProcessClient(pServer, nClientId, szFile, nLine);
}

// 0x006C06D0
void __stdcall sub_006C06D0_DisconnectIP(D2ConnectionTableStrc* pTable, unsigned int nIP, const char* pFile, int nLine)
{
    unsigned int nBucket = pTable->nMask & nIP;
    EnterCriticalSection(&pTable->tLock);
    D2ConnectionNodeStrc* pNode = pTable->ppBuckets[nBucket];
    while (pNode)
    {
        if (pNode->nIP == nIP)
            break;
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&pTable->tLock);
    if (pNode)
        QSrvCloseRemoteConnection(pTable, pNode->nClient, pFile, nLine);
    else
        sub_00410660_LogWritePrefixed(gszHackChannel_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_FormatIP(nIP));
    sub_00410660_LogWritePrefixed(gszHackChannel_006FC4A8, "[HACKLIST]  IP:%s  QSDisconnectIP() from FILE:%s  LINE:%d", sub_006B013E_FormatIP(nIP), pFile, nLine);
}
