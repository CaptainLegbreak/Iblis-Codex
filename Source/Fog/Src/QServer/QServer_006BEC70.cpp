#include "Fog.h"

struct D2QueueServerStrc;
struct D2CriticalSectionStrc;
struct D2QServerClientStrc;
struct D2Entry006BF0A0Strc;
struct D2QPacketStrc;
struct D2AddressRefStrc;
struct D2QNodeStrc;
struct D2ClientNodeStrc;
struct D2ClientTableStrc;

struct D2CriticalSectionStrc
{
    char data[24];
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2QServerClientStrc
{
    unsigned char unk_00[0x7C];
    unsigned int nLocalIp;
};

D2QServerClientStrc* __fastcall sub_006BEC00_FindLocked(D2QueueServerStrc* pServer, unsigned int nToken, D2CriticalSectionStrc** ppLock); // 0x006BEC00

struct D2Entry006BF0A0Strc
{
    unsigned char unk_00[0x20];
    int nValue20;
};

D2Entry006BF0A0Strc* __fastcall sub_006BE540_Find(void* pContainer, int nKey); // 0x006BE540

struct D2QPacketStrc { int id; unsigned char data[0x5B0]; int size; unsigned int tick; D2QPacketStrc* next; };

typedef int (__fastcall *D2PacketParser)(const unsigned char*,int,int*,int*,int*,int*,int,int,int);

struct T006BE350
{
    int nMode;
    unsigned int nextId;
    int unknown08;
    unsigned int mask;
    unsigned int modulus;
    union
    {
        D2QClientStrc** clients;
        void* p014;
    };
    int unknown18;
    union
    {
        D2CriticalSectionStrc* locks;
        D2CriticalSectionStrc* pLocks;
    };
    union
    {
        D2QClientStrc** addressClients;
        void* p020;
    };
    int unknown24;
    union
    {
        D2CriticalSectionStrc addressLock;
        D2CriticalSectionStrc tLock028;
    };
    union
    {
        D2AddressRefStrc** addressRefs;
        void* p040;
    };
    char unk0x044[0x84C - 0x44];
    D2QNodeStrc* pChain84C;
    char unk0x850[0x04];
    union
    {
        D2CriticalSectionStrc lock;
        D2CriticalSectionStrc idLock;
        D2CriticalSectionStrc tLock854;
    };
    int nState;
    union
    {
        D2QPacketStrc** heads;
        void* p870;
    };
    union
    {
        D2QPacketStrc** tails;
        void* p874;
    };
    union
    {
        D2QPacketStrc* freePackets;
        D2QClientStrc* f_878;
    };
    int channelCount;
    int count;
    unsigned char unk_884[0x8];
    D2QNodeStrc* pChain88C;
    int n890;
    D2CriticalSectionStrc tLock894;
    D2QNodeStrc** ppBuckets;
    unsigned int f_8B0;
    D2CriticalSectionStrc tLock8B4;
    char unk0x8CC[0xB90 - 0x8CC];
    unsigned int aSockets[4];
    unsigned char unk_BA0[0x20];
    D2PacketParser parser;
};

extern const char gszQServerSource[]; // 0x006FC460
void* __fastcall FOG_Alloc(unsigned int size,const char* file,int line,int flags); // 0x0040B380
void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();

struct D2QClientStrc
{
    unsigned int id;
    D2QClientStrc* next;
    long references;
    int unknown0C;
    unsigned int socket;
    int unknown14;
    unsigned int address;
    D2QClientStrc* addressNext;
    int unknown20;
    int pending;
    int queued;
    D2CriticalSectionStrc lock;
    char unknown44[0x14];
    int enabled;
    char unknown5C[0x14];
    int state;
    int unknown74;
    char unknown78[0x20];
    unsigned int tick1;
    unsigned int tick2;
    unsigned int tick3;
    unsigned int tick4;
    unsigned char unk_A8[0x514];
    D2QClientStrc* pNext;
    unsigned char unk_5C0[0xA4];
};

struct D2AddressRefStrc { unsigned int address,count; D2AddressRefStrc* next; };

extern const char gszQServerPrefix[]; // 0x006FC47C
unsigned int __cdecl sub_00410A80_GetTick(); // 0x00410A80
const char* __stdcall sub_006B013E_InetNtoa(unsigned int address); // 0x006B013E
void __cdecl sub_006BE300_Log(const char* prefix,const char* format,...); // 0x006BE300
extern "C" void* __cdecl memset(void*,int,unsigned int);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
static int __stdcall sub_006BF180_ReferenceAddress(T006BE350* server,const unsigned int* address); // 0x006BF180
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC1FC

struct D2QNodeStrc
{
    char unk0x00[0x0C];
    D2QNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
extern "C" int __stdcall WSACleanup(void); // 0x006B0138
void __stdcall sub_006BE3C0_Shutdown(T006BE350* pServer); // 0x006BE3C0
void __stdcall sub_006BFAD0_Notify(T006BE350* pServer, int a2, int a3); // 0x006BFAD0
void __fastcall sub_006C2110_StopServerThreads(T006BE350* pServer); // 0x006C2110
void __fastcall sub_006C33D0_Stop(T006BE350* pServer); // 0x006C33D0
extern int gnLockCount_0074C3E0; // 0x0074C3E0
static __declspec(noinline) void sub_006BF320_FreeChain(T006BE350* pServer);
static __declspec(noinline) void sub_006BF0F0_FreeBuckets(T006BE350* pServer);

struct D2ClientNodeStrc
{
    union
    {
        int nClient;
        int client;
    };
    D2ClientNodeStrc* pNext;
    char f_8[0x10];
    union
    {
        unsigned int f_18;
        unsigned int ip;
    };
    D2ClientNodeStrc* next;
};

struct D2ClientTableStrc
{
    char unk_00[0xC];
    union
    {
        unsigned int nMask;
        unsigned int mask;
    };
    int unk_10;
    D2ClientNodeStrc** ppBuckets;
    int unk_18;
    D2CriticalSectionStrc* pLocks;
    D2ClientNodeStrc** buckets;
    int unknown24;
    D2CriticalSectionStrc lock;
    char unknown40[0xb90];
    union
    {
        int bEnabled;
        int enabled;
    };
};

void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc*, int, const char*, int); // 0x006C0420
void __cdecl sub_00410660_LogWritePrefixed(const char*, const char*, ...); // 0x00410660
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc*, const char*, unsigned int, int); // 0x006BFEA0
extern const char gszLogTag_006FC4A8[]; // 0x006FC4A8

// 0x006BEC70
unsigned int __stdcall sub_006BEC70_GetClientLocalIpByToken(D2QueueServerStrc* pServer, unsigned int nToken)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QServerClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nToken, &pLock);
    unsigned int nIp = 0;
    if (pClient)
    {
        nIp = pClient->nLocalIp;
    }
    if (pLock)
    {
        LeaveCriticalSection(pLock);
    }
    return nIp;
}

// 0x006BF0A0
void __stdcall sub_006BF0A0_SetValue(void* pContainer, int nKey, int nValue)
{
    if (nKey)
    {
        D2Entry006BF0A0Strc* pEntry = sub_006BE540_Find(pContainer, nKey);
        if (pEntry)
            pEntry->nValue20 = nValue;
    }
}

// 0x006BF0C0
int __stdcall sub_006BF0C0_GetValue(void* pContainer, int nKey)
{
    if (!nKey)
        return 0;
    D2Entry006BF0A0Strc* pEntry = sub_006BE540_Find(pContainer, nKey);
    if (!pEntry)
        return 0;
    return pEntry->nValue20;
}

// 0x006BF370
int __stdcall FOG_10175(T006BE350* server,const unsigned char* buffer,int size,int id)
{
 int consumed=0;
 int unknown1=0;
 int channel=0;
 int unknown2=0;
 int result=server->parser(buffer,size,&unknown1,&consumed,&channel,&unknown2,0,0,0);
 if(result!=2 && result!=1) return 0;
 D2QPacketStrc* packet;
 if(server->freePackets) {
  EnterCriticalSection(&server->lock);
  packet=server->freePackets;
  if(packet) server->freePackets=packet->next;
  else packet=(D2QPacketStrc*)FOG_Alloc(sizeof(D2QPacketStrc),gszQServerSource,2569,0);
  LeaveCriticalSection(&server->lock);
 } else packet=(D2QPacketStrc*)FOG_Alloc(sizeof(D2QPacketStrc),gszQServerSource,2578,0);
 sub_006829C0_Copy(packet->data,buffer+consumed,size-consumed);
 packet->size=size-consumed;
 packet->tick=GetTickCount();
 packet->next=0;
 packet->id=id;
 if(channel<server->channelCount) {
  EnterCriticalSection(&server->lock);
  D2QPacketStrc* last=server->tails[channel];
  if(!last) server->heads[channel]=packet;
  else last->next=packet;
  server->tails[channel]=packet;
  LeaveCriticalSection(&server->lock);
 }
 return 1;
}

static __declspec(noinline)
int __stdcall sub_006BF180_ReferenceAddress(T006BE350* server,const unsigned int* address)
{
 unsigned int value=*address;
 unsigned int bucket=value%server->modulus;
 D2AddressRefStrc* entry=server->addressRefs[bucket];
 while(entry) {
  if(entry->address==value) {
   ++entry->count;
   return 1;
  }
  entry=entry->next;
 }
 entry=(D2AddressRefStrc*)FOG_Alloc(sizeof(D2AddressRefStrc),gszQServerSource,2329,0);
 entry->address=value;
 entry->count=1;
 entry->next=server->addressRefs[bucket];
 server->addressRefs[bucket]=entry;
 return 1;
}

// 0x006BFB70
D2QClientStrc* __fastcall QSrvAddClient(T006BE350* server,unsigned int socket,unsigned int address)
{
 D2QClientStrc* client=(D2QClientStrc*)FOG_Alloc(sizeof(D2QClientStrc),gszQServerSource,571,0);
 memset(client,0,sizeof(D2QClientStrc));
 EnterCriticalSection(&server->idLock);
 unsigned int id=++server->nextId;
 LeaveCriticalSection(&server->idLock);
 client->id=id;
 client->socket=socket;
 client->address=address;
 client->pending=0;client->queued=0;client->unknown74=0;
 client->enabled=1;client->state=2;
 unsigned int tick=sub_00410A80_GetTick();
 client->tick1=tick;client->tick2=tick;client->tick3=tick;client->tick4=tick;
 InitializeCriticalSection(&client->lock);
 unsigned int bucket=id&server->mask;
 EnterCriticalSection(&server->locks[bucket]);
 client->next=server->clients[bucket];
 server->clients[bucket]=client;
 LeaveCriticalSection(&server->locks[bucket]);
 EnterCriticalSection(&server->addressLock);
 unsigned int addressBucket=address&server->mask;
 client->addressNext=server->addressClients[addressBucket];
 server->addressClients[addressBucket]=client;
 LeaveCriticalSection(&server->addressLock);
 EnterCriticalSection(&server->idLock);
 sub_006BF180_ReferenceAddress(server,&address);
 InterlockedIncrement(&client->references);
 ++server->count;
 LeaveCriticalSection(&server->idLock);
 sub_006BE300_Log(gszQServerPrefix,"[QSrvAddClient]  Added client %d %s on socket %d",client->id,sub_006B013E_InetNtoa(client->address),client->socket);
 return client;
}

static void sub_006BF320_FreeChain(T006BE350* pServer)
{
    EnterCriticalSection(&pServer->tLock854);
    D2QNodeStrc* pNode = pServer->pChain84C;
    while (pNode)
    {
        D2QNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, gszQServerFile_006FC460, 0x9B0, 0);
        pNode = pNext;
    }
    pServer->pChain84C = 0;
    LeaveCriticalSection(&pServer->tLock854);
}

static void sub_006BF0F0_FreeBuckets(T006BE350* pServer)
{
    EnterCriticalSection(&pServer->tLock894);
    for (unsigned int i = 0; i < pServer->f_8B0; ++i)
    {
        D2QNodeStrc* pNode = pServer->ppBuckets[i];
        while (pNode)
        {
            D2QNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, gszQServerFile_006FC460, 0x8BE, 0);
            pNode = pNext;
        }
        pServer->ppBuckets[i] = 0;
    }
    pServer->n890 = 0;
    LeaveCriticalSection(&pServer->tLock894);
}

// 0x006C0170
int __stdcall sub_006C0170_DestroyServer(T006BE350* pServer, int a2, int a3)
{
    if (!pServer)
        return 1;

    if (a2)
        sub_006BFAD0_Notify(pServer, a2, a3);

    if (pServer->nState != 1 && pServer->nState != 2)
    {
        if (pServer->nMode)
            sub_006C2110_StopServerThreads(pServer);
        else
            sub_006C33D0_Stop(pServer);
    }

    sub_006BF320_FreeChain(pServer);
    sub_006BF0F0_FreeBuckets(pServer);
    sub_006BE3C0_Shutdown(pServer);

    for (int i = 0; i < 4; ++i)
    {
        if (pServer->aSockets[i] != -1)
        {
            sub_0040D880(pServer->aSockets[i]);
            pServer->aSockets[i] = -1;
        }
    }

    WSACleanup();
    DeleteCriticalSection(&pServer->tLock854);
    DeleteCriticalSection(&pServer->tLock894);
    DeleteCriticalSection(&pServer->tLock8B4);

    while (pServer->f_878)
    {
        D2QClientStrc* pNext = pServer->f_878->pNext;
        FOG_Free(pServer->f_878, gszQServerFile_006FC460, 0x183, 0);
        pServer->f_878 = pNext;
    }

    while (pServer->pChain88C)
    {
        D2QNodeStrc* pNext = pServer->pChain88C->pNext;
        FOG_Free(pServer->pChain88C, gszQServerFile_006FC460, 0x189, 0);
        pServer->pChain88C = pNext;
    }

    FOG_Free(pServer->p870, gszQServerFile_006FC460, 0x18D, 0);
    FOG_Free(pServer->p874, gszQServerFile_006FC460, 0x18E, 0);
    FOG_Free(pServer->p040, gszQServerFile_006FC460, 0x192, 0);
    FOG_Free(pServer->ppBuckets, gszQServerFile_006FC460, 0x193, 0);
    FOG_Free(pServer->p020, gszQServerFile_006FC460, 0x195, 0);
    DeleteCriticalSection(&pServer->tLock028);
    FOG_Free(pServer->p014, gszQServerFile_006FC460, 0x198, 0);

    for (int i = 0; i < gnLockCount_0074C3E0; ++i)
        DeleteCriticalSection(&pServer->pLocks[i]);

    FOG_Free(pServer->pLocks, gszQServerFile_006FC460, 0x19C, 0);
    FOG_Free(pServer, gszQServerFile_006FC460, 0x19F, 0);
    return 1;
}

#include "gen/data/Source/Fog/Src/QServer/QServer_006BEC70.inc"

// 0x006C0530
void __stdcall sub_006C0530_RecordClient(D2ClientTableStrc* pTable, int nClient, const char* szFile, int nLine)
{
    if (!pTable->bEnabled) return;
    unsigned int nBucket = pTable->nMask & nClient;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2ClientNodeStrc* pNode = pTable->ppBuckets[nBucket];
    while (pNode && pNode->nClient != nClient)
        pNode = pNode->pNext;
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    if (!pNode)
    {
        sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Couldn't hacklist client %d (closed) from FILE:%s  LINE:%d", nClient, szFile, nLine);
        return;
    }
    unsigned int nAddress = pNode->f_18;
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackList() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(nAddress), szFile, nLine);
    sub_006C0420_CloseClient(pTable, nClient, szFile, nLine);
    sub_006BFEA0_RecordAddress(pTable, szFile, nAddress, nLine);
}

// 0x006C0600
void __stdcall sub_006C0600_RecordClosedAddress(D2ClientTableStrc* table, unsigned int ip, const char* file, int line)
{
    if (!table->enabled) return;
    unsigned int bucket = table->mask & ip;
    EnterCriticalSection(&table->lock);
    D2ClientNodeStrc* node = table->buckets[bucket];
    while (node && node->ip != ip) node = node->next;
    LeaveCriticalSection(&table->lock);
    if (node) sub_006C0420_CloseClient(table, node->client, file, line);
    else sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_InetNtoa(ip));
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackListIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(ip), file, line);
    sub_006BFEA0_RecordAddress(table, file, ip, line);
}
