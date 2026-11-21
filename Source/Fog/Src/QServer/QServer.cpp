#include "Fog.h"
#include "D2QServer.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"
#include "D2SysTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct QServer;

struct D2PacketBufferStrc;

struct D2CriticalSectionStrc;

struct D2ServerNode006BE3C0Strc;

struct D2Server006BE3C0Strc;

struct Obj006BE450;

struct D2Worker006BE4A0Strc;

struct D2Object006BE4E0Strc;

struct D2ReferenceStrc;


struct D2RecordTableStrc;

struct D2NetPacketStrc;

struct D2NetQueueStrc;

struct D2HashNodeStrc;

struct D2HashTableStrc;

struct D2SocketTableStrc;

struct D2HashNode006BEF40Strc;

struct D2HashTable006BEF40Strc;

struct D2Server006BEFB0Strc;

struct D2Object006BF040Strc;

struct Obj006BF080;

struct Obj006BF4E0;

struct D2PairEntry006BF610Strc;

struct D2PairTable006BF610Strc;

struct D2RecordStrc;

struct D2QServerConfigStrc;

struct D2ConnectionNodeStrc;

struct D2ConnectionTableStrc;

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

struct D2RecordTableStrc {
    unsigned char unknown0[0x10];
    unsigned int bucketCount;
    unsigned char unknown14[0x2c];
    D2QIpCountStrc** buckets;
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

struct D2SocketTableStrc
{
    unsigned int reserved00[3];
    unsigned int mask;
    unsigned int reserved10;
    D2QClientStrc** buckets;
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
    D2QServerNodeStrc* pChain84C;
    D2QServerNodeStrc* pChain850;
    D2CriticalSectionStrc tLock854;
    int nState;
    void** ppSlots870;
    void** ppSlots874;
    D2QClientStrc* pClients;
    int nSlotCount87C;
    int nValue880;
    int bStarted884;
    unsigned int nSocket888;
    D2QServerNodeStrc* pChain88C;
    int nValue890;
    D2CriticalSectionStrc tLock894;
    D2QServerNodeStrc** ppBuckets;
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

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132

int __fastcall sub_006C3360_Startup(QServer* pServer, int nPort); // 0x006C3360

int __fastcall sub_006C3B50_StartServer(QServer* pServer, int nPort); // 0x006C3B50

extern "C" const char gszQServerTag_006FC47C[]; // 0x006FC47C

extern "C" const char gszQServerAllocated_006FC548[]; // 0x006FC548

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

void __fastcall sub_006C0420_CloseClient(D2QueueServerStrc* table, int client, const char* file, int line); // 0x006C0420

void __fastcall sub_006BFEA0_RecordAddress(D2QueueServerStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0

int __fastcall sub_006C2C70(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize); // 0x006C2C70

int __fastcall sub_006C3410_Send(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize); // 0x006C3410

struct D2QueueServerStrc;

typedef int (__fastcall *D2PacketParser)(const unsigned char*,int,int*,int*,int*,int*,int,int,int);

extern const char gszQServerSource[]; // 0x006FC460

void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0

extern const char gszQServerPrefix[]; // 0x006FC47C

long __cdecl sub_00410A80_GetTimeSeconds(); // 0x00410A80

void __cdecl sub_006BE300_Log(const char* prefix,const char* format,...); // 0x006BE300

static int __stdcall sub_006BF180_ReferenceAddress(D2QueueServerStrc* server,const unsigned int* address); // 0x006BF180

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC1FC

int __fastcall sub_0040D880(unsigned int s); // 0x0040D880

extern "C" int __stdcall WSACleanup(void); // 0x006B0138

void __stdcall sub_006BE3C0_Shutdown(D2QueueServerStrc* pServer); // 0x006BE3C0

void __stdcall sub_006BFAD0_Notify(D2QueueServerStrc* pServer, int a2, int a3); // 0x006BFAD0

void __fastcall sub_006C2110_StopServerThreads(D2QueueServerStrc* pServer); // 0x006C2110

void __fastcall sub_006C33D0_Stop(D2QueueServerStrc* pServer); // 0x006C33D0

static void sub_006BF320_FreeChain(D2QueueServerStrc* pServer);

static void sub_006BF0F0_FreeBuckets(D2QueueServerStrc* pServer);

extern const char gszLogTag_006FC4A8[]; // 0x006FC4A8

static int sub_006C0140_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize); // 0x006C0140

static int __fastcall sub_006BF500_Dispatch(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize);

extern "C" unsigned int __security_cookie; // 0x00749DE0

extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

static void sub_006BF520_StartServer(QServer* pServer, int nValue);

struct D2QEntry006BF580Strc
{
    unsigned char unk_000[0x5BC];
    D2QEntry006BF580Strc* pNext;
};

struct D2QServer006BF580Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc pLock;
    unsigned char unk_86C[0x04];
    D2QEntry006BF580Strc** ppBuckets;
    unsigned char unk_874[0x08];
    int nBuckets;
};

const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E

void __stdcall sub_006C0770_BanClient(int nClient, const char* szFile, int nLine); // 0x006C0770

extern const char gszHack_006FC4A8[]; // 0x006FC4A8

static int gnLockCount_0074C3E0; // 0x0074C3E0

static int gnGlobal_0074C3E4; // 0x0074C3E4

static int gnGlobal_0074C3E8; // 0x0074C3E8

static int gnGlobal_0074C3EC; // 0x0074C3EC

static int gnGlobal_00989C28; // 0x00989C28

int __stdcall sub_006C03A0_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize);

struct sub_006BE510_Guard;

struct sub_006BE530_LockRef;

struct sub_006BE510_Guard
{
    D2CriticalSectionStrc* pCriticalSection;

    sub_006BE510_Guard* sub_006BE510_Enter(D2CriticalSectionStrc* pCs);
};

struct sub_006BE530_LockRef
{
    D2CriticalSectionStrc* pCriticalSection;
};

 D2CriticalSectionStrc;

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

struct D2HackListStrc;

struct D2HackNode006BE890Strc;

struct D2Server006BE890Strc;

struct D2MaskKeyStrc;

struct D2MaskPairStrc;

struct D2MaskPairListStrc;

extern const char gszHackCategory_006FC4A8[]; // 0x006FC4A8

extern const char gszHackListSize_006FC4B0[]; // 0x006FC4B0

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

void __cdecl sub_006BE2F0_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE2F0

static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId);

static void sub_006BE650_DestroyClient(D2QClientStrc* pClient);

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090

extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840

extern const char gszAssert_006CC837[]; // 0x006CC837

extern const char gszFile_006FC460[]; // 0x006FC460

void __stdcall sub_006C0770_BanClient(D2QueueServerStrc* table, int client, const char* file, int line); // 0x006C0770

unsigned int gnLastHackListLog_00989C34; // 0x00989C34

void __fastcall sub_006C0360_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient);

static void sub_006BF0F0_FreeAll(D2QueueServerStrc* pServer);

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

// 0x006BE470
int __stdcall sub_006BE470_IsActive(D2QueueServerStrc* pServer)
{
    if (!pServer)
        return 0;
    return pServer->nState == 1 || pServer->nState == 2;
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

// 0x006BE510
sub_006BE510_Guard* sub_006BE510_Guard::sub_006BE510_Enter(D2CriticalSectionStrc* pCs)
{
    pCriticalSection = pCs;
    EnterCriticalSection(pCs);
    return this;
}

// 0x006BE530
void __fastcall sub_006BE530_Leave(sub_006BE530_LockRef* pLock)
{
    LeaveCriticalSection(pLock->pCriticalSection);
}

// 0x006BE540
D2QClientStrc* __fastcall sub_006BE540_Find(D2QueueServerStrc* pTable, unsigned int nKey)
{
    if (!pTable)
    {
        return 0;
    }
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2QClientStrc* pNode;
    for (pNode = pTable->ppClients[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nKey)
        {
            break;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return pNode;
}

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

// 0x006BE640
long __fastcall sub_006BE640_AddReference(void* unusedContext, D2ReferenceStrc* object)
{
    return InterlockedIncrement(&object->nReferences);
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

// 0x006BE980
int D2QueueServerStrc::sub_006BE980_Refresh(unsigned int nKey)
{
    EnterCriticalSection(&tRecordLock);
    for (D2QServerNodeStrc* pNode = ppRecords[nKey % nRecordBuckets]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->iCount)
            {
                pNode->iCount = 120;
                LeaveCriticalSection(&tRecordLock);
                return 1;
            }
            LeaveCriticalSection(&tRecordLock);
            return 0;
        }
    }
    LeaveCriticalSection(&tRecordLock);
    return 0;
}

// 0x006BE9F0
int __fastcall sub_006BE9F0_CheckRecordThreshold(D2RecordTableStrc* table, const unsigned int* keyPointer)
{
    if (table->threshold < 0) return 0;
    unsigned int key = *keyPointer;
    unsigned int index = key % table->bucketCount;
    EnterCriticalSection(&table->lock);
    D2QIpCountStrc* node = table->buckets[index];
    while (node) {
        if (node->nKey == key) {
            int value = node->nRefCount;
            LeaveCriticalSection(&table->lock);
            return value >= table->threshold;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->lock);
    return 0;
}

// 0x006BEA70
int __stdcall sub_006BEA70_CountBucket(D2QueueServerStrc* pServer, int nBucket)
{
    if (nBucket >= pServer->nQueueCount)
        return -1;

    int nCount = 0;
    EnterCriticalSection(&pServer->tLock);
    for (D2MessageStrc* pMessage = pServer->ppMsgHeads[nBucket]; pMessage; pMessage = pMessage->pNext)
        ++nCount;
    LeaveCriticalSection(&pServer->tLock);
    return nCount;
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
D2QClientStrc* __fastcall sub_006BEC00_FindLocked(D2QueueServerStrc* pTable, unsigned int nKey, D2CriticalSectionStrc** ppLock)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2QClientStrc* pNode = pTable->ppClients[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nKey)
        {
            *ppLock = &pTable->pLocks[nBucket];
            return pNode;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return 0;
}

// 0x006BEC70
unsigned int __stdcall sub_006BEC70_GetClientLocalIpByToken(D2QueueServerStrc* pServer, unsigned int nToken)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nToken, &pLock);
    unsigned int nIp = 0;
    if (pClient)
    {
        nIp = pClient->tLocalAddr.sin_addr.s_addr;
    }
    if (pLock)
    {
        LeaveCriticalSection(pLock);
    }
    return nIp;
}

// 0x006BECB0
unsigned short __stdcall sub_006BECB0_GetPort(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nId, &pLock);
    unsigned short nPort = 0;
    if (pClient)
        nPort = sub_006B019E(pClient->tLocalAddr.sin_port);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
}

// 0x006BED00
int __stdcall sub_006BED00_GetValue(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nId, &pLock);
    int nValue = 0;
    if (pClient)
        nValue = pClient->tPeerAddr.sin_addr.s_addr;
    if (pLock)
        LeaveCriticalSection(pLock);
    return nValue;
}

// 0x006BED40
unsigned short __stdcall sub_006BED40_GetPort(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nId, &pLock);
    unsigned short nPort = 0;
    if (pClient)
        nPort = sub_006B019E(pClient->tPeerAddr.sin_port);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
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
    D2QClientStrc* node = table->buckets[index];
    while (node)
    {
        if (node->pKey == key)
        {
            const unsigned int socket = node->nSocket;
            LeaveCriticalSection(&table->locks[index]);
            char address[16];
            int length = sizeof(address);
            getpeername(socket, address, &length);
            return *(unsigned int*)(address + 4);
        }
        node = node->pNext;
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
    if (pServer->bEnabled)
    {
        sub_00410660_LogWritePrefixed("HACK", "[HACKLIST]  Size:%s  QSHackListSize() from FILE:%s  LINE:%d", pServer->nRecordCount, nFile, nLine);
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

// 0x006BF0A0
void __stdcall sub_006BF0A0_SetValue(void* pContainer, int nKey, int nValue)
{
    if (nKey)
    {
        D2QClientStrc* pClient = sub_006BE540_Find((D2QueueServerStrc*)pContainer, nKey);
        if (pClient)
            pClient->nContext = nValue;
    }
}

// 0x006BF0C0
int __stdcall sub_006BF0C0_GetValue(void* pContainer, int nKey)
{
    if (!nKey)
        return 0;
    D2QClientStrc* pClient = sub_006BE540_Find((D2QueueServerStrc*)pContainer, nKey);
    if (!pClient)
        return 0;
    return pClient->nContext;
}

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

// 0x006BF170
void __fastcall sub_006BF170_Dispatch(D2QueueServerStrc* pServer)
{
    if (pServer->bAltSend)
        sub_006C2110_StopServerThreads(pServer);
    else
        sub_006C33D0_Stop(pServer);
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

// 0x006BF250
void __stdcall sub_006BF250_Nop(int a1, int a2, int a3)
{
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

// 0x006BF370
int __stdcall FOG_10175(D2QueueServerStrc* server,const unsigned char* buffer,int size,int id)
{
 int consumed=0;
 int unknown1=0;
 int channel=0;
 int unknown2=0;
 int result=server->pfnProcess(buffer,size,&unknown1,&consumed,&channel,&unknown2,0,0,0);
 if(result!=2 && result!=1) return 0;
 D2MessageStrc* packet;
 if(server->pFreeMessages) {
  EnterCriticalSection(&server->tLock);
  packet=server->pFreeMessages;
  if(packet) server->pFreeMessages=packet->pNext;
  else packet=(D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc),gszQServerSource,2569,0);
  LeaveCriticalSection(&server->tLock);
 } else packet=(D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc),gszQServerSource,2578,0);
 sub_006829C0_Copy(packet->aData,buffer+consumed,size-consumed);
 packet->nSize=size-consumed;
 packet->dwTick=GetTickCount();
 packet->pNext=0;
 packet->nId=id;
 if(channel<server->nQueueCount) {
  EnterCriticalSection(&server->tLock);
  D2MessageStrc* last=server->ppMsgTails[channel];
  if(!last) server->ppMsgHeads[channel]=packet;
  else last->pNext=packet;
  server->ppMsgTails[channel]=packet;
  LeaveCriticalSection(&server->tLock);
 }
 return 1;
}

// 0x006BF4E0
extern "C" __declspec(dllexport) void __stdcall sub_006BF4E0(Obj006BF4E0* pObj, unsigned int dwValue) {
    pObj->dwValueBD0 = dwValue;
}

// 0x006BF500
static int __fastcall sub_006BF500_Dispatch(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize)
{
    if (!pClient || pClient->bClosing) return 0;
    if (pServer->bAltSend) return sub_006C2C70(pServer, pClient, pData, nSize);
    return sub_006C3410_Send(pServer, pClient, pData, nSize);
}

// build: context sub_Emit_006BF500
// calling-convention shim (not game code)
int __stdcall sub_Emit_006BF500(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nState == 1 || pServer->nState == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, pData, nSize);
    }
    D2QClientStrc* pClient = sub_006BE540_Find(pServer, nKey);
    return sub_006BF500_Dispatch(pServer, pClient, pData, nSize);
}

// 0x006BF520
static void sub_006BF520_StartServer(QServer* pServer, int nValue)
{
    D2WSADataStrc tWsaData;
    if (WSAStartup(0x101, &tWsaData))
    {
        return;
    }

    if (pServer->bUseNt)
    {
        sub_006C3360_Startup(pServer, nValue);
    }
    else
    {
        sub_006C3B50_StartServer(pServer, nValue);
    }
}

void __fastcall sub_Emit_006BF520(QServer* pServer, int nValue)
{
    sub_006BF520_StartServer(pServer, nValue);
    sub_006BF520_StartServer(pServer, nValue);
}

// 0x006BF580
int __stdcall sub_006BF580_CountEntries(D2QServer006BF580Strc* pServer)
{
    int nCount = 0;
    if (!pServer)
    {
        return 0;
    }
    EnterCriticalSection(&pServer->pLock);
    for (int i = 0; i < pServer->nBuckets; ++i)
    {
        for (D2QEntry006BF580Strc* pEntry = pServer->ppBuckets[i]; pEntry; pEntry = pEntry->pNext)
        {
            ++nCount;
        }
    }
    LeaveCriticalSection(&pServer->pLock);
    return nCount;
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

// 0x006BF6C0
int __fastcall sub_006BF6C0(D2QueueServerStrc* server, int clientId)
{
    return server->sub_006BF660_CheckClient(clientId);
}

// 0x006BF6D0
void __fastcall sub_006BF6D0_CopyRecords(D2QueueServerStrc* server,D2RecordStrc* destination,int count)
{
 EnterCriticalSection(&server->tClientLock);
 memcpy(destination,server->aRecords,count*sizeof(D2RecordStrc));
 LeaveCriticalSection(&server->tClientLock);
 for (int i=0;i<count;++i) destination[i].value=server->aValues[i];
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
    pServer->ppBuckets = (D2QServerNodeStrc**)FOG_Alloc(gnGlobal_0074C3EC * sizeof(D2QServerNodeStrc*), gszQServerFile_006FC460, 180, 0);
    memset(pServer->ppBuckets, 0, gnGlobal_0074C3EC * sizeof(D2QServerNodeStrc*));
    sub_006BE300_Log(gszQServerTag_006FC47C, gszQServerAllocated_006FC548, pServer);
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

static
// 0x006C0770
void __stdcall sub_006C0770_BanClient(D2QueueServerStrc* table, int client, const char* file, int line)
{
    if (!table->bEnabled)
        return;
    unsigned int bucket = table->nMask & client;
    EnterCriticalSection(&table->pLocks[bucket]);
    D2QClientStrc* node = table->ppClients[bucket];
    unsigned int address = 0;
    while (node)
    {
        if (node->iId == client)
        {
            address = node->nAddress;
            break;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[bucket]);
    sub_006C0420_CloseClient(table, client, file, line);
    if (address)
        sub_006BFEA0_RecordAddress(table, file, address, line);
}

void __fastcall EmitBanClient(D2QueueServerStrc* table, int client, const char* file, int line)
{
    sub_006C0770_BanClient(table + 1, client, file, line);
}

// 0x006BFAD0
int __stdcall sub_006BFAD0_BroadcastToAllClients(D2QueueServerStrc* pServer, char* pData, int nSize)
{
    for (unsigned int i = 0; i < pServer->nBuckets; ++i)
    {
        EnterCriticalSection(&pServer->pLocks[i]);
        D2QClientStrc* pClient = pServer->ppClients[i];
        do
        {
            if (!pClient)
            {
                break;
            }

            if (!pClient->bClosing)
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

// build: context sub_006BF180_ReferenceAddress
static
int __stdcall sub_006BF180_ReferenceAddress(D2QueueServerStrc* server,const unsigned int* address)
{
 unsigned int value=*address;
 unsigned int bucket=value%server->nIpBuckets;
 D2QIpCountStrc* entry=server->ppIpCounts[bucket];
 while(entry) {
  if(entry->nAddress==value) {
   ++entry->nCount;
   return 1;
  }
  entry=entry->pNext;
 }
 entry=(D2QIpCountStrc*)FOG_Alloc(sizeof(D2QIpCountStrc),gszQServerSource,2329,0);
 entry->nAddress=value;
 entry->nCount=1;
 entry->pNext=server->ppIpCounts[bucket];
 server->ppIpCounts[bucket]=entry;
 return 1;
}

// 0x006BFB70
D2QClientStrc* __fastcall QSrvAddClient(D2QueueServerStrc* server,unsigned int socket,unsigned int address)
{
 D2QClientStrc* client=(D2QClientStrc*)FOG_Alloc(sizeof(D2QClientStrc),gszQServerSource,571,0);
 memset(client,0,sizeof(D2QClientStrc));
 EnterCriticalSection(&server->tLock);
 unsigned int id=++server->nNextId;
 LeaveCriticalSection(&server->tLock);
 client->nId=id;
 client->nSocket=socket;
 client->nAddress=address;
 client->nPending24=0;client->nQueued=0;client->nValue74=0;
 client->bEnabled=1;client->nState=2;
 unsigned int tick=sub_00410A80_GetTimeSeconds();
 client->nCreateTime=tick;client->nLastTick=tick;client->nTick3=tick;client->nTick4=tick;
 InitializeCriticalSection(&client->tLock);
 unsigned int bucket=id&server->nMask;
 EnterCriticalSection(&server->pLocks[bucket]);
 client->pNext=server->ppClients[bucket];
 server->ppClients[bucket]=client;
 LeaveCriticalSection(&server->pLocks[bucket]);
 EnterCriticalSection(&server->tAddressLock);
 unsigned int addressBucket=address&server->nMask;
 client->pNextByAddress=server->ppAddressBuckets[addressBucket];
 server->ppAddressBuckets[addressBucket]=client;
 LeaveCriticalSection(&server->tAddressLock);
 EnterCriticalSection(&server->tLock);
 sub_006BF180_ReferenceAddress(server,&address);
 InterlockedIncrement(&client->nRefCount);
 ++server->nClients;
 LeaveCriticalSection(&server->tLock);
 sub_006BE300_Log(gszQServerPrefix,"[QSrvAddClient]  Added client %d %s on socket %d",client->nId,sub_006B013E_InetNtoa(client->nAddress),client->nSocket);
 return client;
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

// 0x006BFEA0
void __fastcall sub_006BFEA0_RecordAddress(D2QueueServerStrc* pTable, const char* szFile, unsigned int nAddress, int nLine)
{
    if (!pTable->bEnabled)
        return;
    if (pTable->sub_006BF660_CheckAddress(nAddress))
        return;
    if (pTable->pfnAddressCallback)
        pTable->pfnAddressCallback(nAddress, szFile, nLine);
    D2CriticalSectionStrc* pLock = &pTable->tRecordLock;
    EnterCriticalSection(pLock);
    unsigned int nBucket = nAddress % pTable->nRecordBuckets;
    D2QServerNodeStrc* pRecord = pTable->ppRecords[nBucket];
    while (pRecord && pRecord->nKey != nAddress)
        pRecord = pRecord->pNext;
    if (pRecord)
    {
        pRecord->iCount = 120;
        LeaveCriticalSection(pLock);
        return;
    }
    pRecord = pTable->pFreeRecords;
    if (pRecord)
        pTable->pFreeRecords = pRecord->pNext;
    else
        pRecord = (D2QServerNodeStrc*)FOG_Alloc(sizeof(D2QServerNodeStrc), gszServerFile_006FC460, 0x4AA, 0);
    pRecord->nKey = nAddress;
    pRecord->iTime = 120;
    pRecord->iCount = 0;
    pRecord->pNext = pTable->ppRecords[nBucket];
    pTable->ppRecords[nBucket] = pRecord;
    ++pTable->nRecordCount;
    LeaveCriticalSection(pLock);
    sub_006BE6C0_LogHackListSize(pTable->nRecordCount);
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

// 0x006C0140
static int sub_006C0140_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    D2QClientStrc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bAltSend)
    {
        return sub_006C2C70(pServer, pConnection, pData, nSize);
    }
    return sub_006C3410_Send(pServer, pConnection, pData, nSize);
}

// build: context sub_006BF320_FreeChain
static void sub_006BF320_FreeChain(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tLock);
    D2QServerNodeStrc* pNode = pServer->pHead;
    while (pNode)
    {
        D2QServerNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, gszQServerFile_006FC460, 0x9B0, 0);
        pNode = pNext;
    }
    pServer->pHead = 0;
    LeaveCriticalSection(&pServer->tLock);
}

// build: context sub_006BF0F0_FreeBuckets
static void sub_006BF0F0_FreeBuckets(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tRecordLock);
    for (unsigned int i = 0; i < pServer->nRecordBuckets; ++i)
    {
        D2QServerNodeStrc* pNode = pServer->ppRecords[i];
        while (pNode)
        {
            D2QServerNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, gszQServerFile_006FC460, 0x8BE, 0);
            pNode = pNext;
        }
        pServer->ppRecords[i] = 0;
    }
    pServer->nRecordCount = 0;
    LeaveCriticalSection(&pServer->tRecordLock);
}

// 0x006C0170
int __stdcall sub_006C0170_DestroyServer(D2QueueServerStrc* pServer, int a2, int a3)
{
    if (!pServer)
        return 1;

    if (a2)
        sub_006BFAD0_Notify(pServer, a2, a3);

    if (pServer->nState != 1 && pServer->nState != 2)
    {
        if (pServer->bAltSend)
            sub_006C2110_StopServerThreads(pServer);
        else
            sub_006C33D0_Stop(pServer);
    }

    sub_006BF320_FreeChain(pServer);
    sub_006BF0F0_FreeBuckets(pServer);
    sub_006BE3C0_Shutdown(pServer);

    for (int i = 0; i < 4; ++i)
    {
        if (pServer->aListenSockets[i] != -1)
        {
            sub_0040D880(pServer->aListenSockets[i]);
            pServer->aListenSockets[i] = -1;
        }
    }

    WSACleanup();
    DeleteCriticalSection(&pServer->tLock);
    DeleteCriticalSection(&pServer->tRecordLock);
    DeleteCriticalSection(&pServer->tClientLock);

    while (pServer->pFreeClients)
    {
        D2QClientStrc* pNext = pServer->pFreeClients->pNextQueued;
        FOG_Free(pServer->pFreeClients, gszQServerFile_006FC460, 0x183, 0);
        pServer->pFreeClients = pNext;
    }

    while (pServer->pFreeRecords)
    {
        D2QServerNodeStrc* pNext = pServer->pFreeRecords->pNext;
        FOG_Free(pServer->pFreeRecords, gszQServerFile_006FC460, 0x189, 0);
        pServer->pFreeRecords = pNext;
    }

    FOG_Free(pServer->ppMsgHeads, gszQServerFile_006FC460, 0x18D, 0);
    FOG_Free(pServer->ppMsgTails, gszQServerFile_006FC460, 0x18E, 0);
    FOG_Free(pServer->ppIpCounts, gszQServerFile_006FC460, 0x192, 0);
    FOG_Free(pServer->ppRecords, gszQServerFile_006FC460, 0x193, 0);
    FOG_Free(pServer->ppAddressBuckets, gszQServerFile_006FC460, 0x195, 0);
    DeleteCriticalSection(&pServer->tAddressLock);
    FOG_Free(pServer->ppClients, gszQServerFile_006FC460, 0x198, 0);

    for (int i = 0; i < gnLockCount_0074C3E0; ++i)
        DeleteCriticalSection(&pServer->pLocks[i]);

    FOG_Free(pServer->pLocks, gszQServerFile_006FC460, 0x19C, 0);
    FOG_Free(pServer, gszQServerFile_006FC460, 0x19F, 0);
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

// build: context sub_CallSite_SendToKey
// calling-convention shim (not game code)
int __stdcall sub_CallSite_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    return sub_006C0140_SendToKey(pServer, nKey, pData, nSize);
}

// 0x006C03A0
int __stdcall sub_006C03A0_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nState == 1 || pServer->nState == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, pData, nSize);
    }
    D2QClientStrc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bAltSend)
    {
        return sub_006C2C70(pServer, pConnection, pData, nSize);
    }
    return sub_006C3410_Send(pServer, pConnection, pData, nSize);
}

// 0x006C0530
void __stdcall sub_006C0530_RecordClient(D2QueueServerStrc* pTable, int nClient, const char* szFile, int nLine)
{
    if (!pTable->bEnabled) return;
    unsigned int nBucket = pTable->nMask & nClient;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2QClientStrc* pNode = pTable->ppClients[nBucket];
    while (pNode && pNode->iId != nClient)
        pNode = pNode->pNext;
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    if (!pNode)
    {
        sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Couldn't hacklist client %d (closed) from FILE:%s  LINE:%d", nClient, szFile, nLine);
        return;
    }
    unsigned int nAddress = pNode->nAddress;
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackList() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(nAddress), szFile, nLine);
    sub_006C0420_CloseClient(pTable, nClient, szFile, nLine);
    sub_006BFEA0_RecordAddress(pTable, szFile, nAddress, nLine);
}

// 0x006C0600
void __stdcall sub_006C0600_RecordClosedAddress(D2QueueServerStrc* table, unsigned int ip, const char* file, int line)
{
    if (!table->bEnabled) return;
    unsigned int bucket = table->nMask & ip;
    EnterCriticalSection(&table->tAddressLock);
    D2QClientStrc* node = table->ppAddressBuckets[bucket];
    while (node && node->nAddress != ip) node = node->pNextByAddress;
    LeaveCriticalSection(&table->tAddressLock);
    if (node) sub_006C0420_CloseClient(table, node->iId, file, line);
    else sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_InetNtoa(ip));
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackListIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(ip), file, line);
    sub_006BFEA0_RecordAddress(table, file, ip, line);
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

// 0x006C0800
int __fastcall sub_006C0800_BanByAddress(D2QueueServerStrc* pServer, unsigned int* pAddress, const char* szFile, int nLine)
{
    unsigned int nAddress = *pAddress;
    unsigned int nBucket = pServer->nMask & nAddress;
    EnterCriticalSection(&pServer->tAddressLock);
    D2QClientStrc* pNode = pServer->ppAddressBuckets[nBucket];
    while (pNode && pNode->nAddress != nAddress)
        pNode = pNode->pNextByAddress;
    LeaveCriticalSection(&pServer->tAddressLock);
    if (pNode && !pServer->sub_006BF660_CheckAddress(pNode->nAddress))
    {
        sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  Client %d at %s banned via QSBanByAddr()", pNode->iId, sub_006B013E_FormatAddress(*pAddress));
        sub_006C0770_BanClient(pNode->iId, gszServerFile_006FC460, 0x584);
    }
    return 1;
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

// calling-convention shim (not game code)
void __stdcall shim_9(D2QueueServerStrc* pServer)
{
    sub_006BF0F0_FreeAll(pServer);
}

#include "gen/data/Source/Fog/Src/QServer/QServer.inc"
