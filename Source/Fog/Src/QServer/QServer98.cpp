#include "Fog.h"

struct D2ServerStrc;
struct D2QAddressArg;
struct D2CriticalSectionStrc;
struct D2SocketNodeStrc;
struct D2SocketSetStrc;
struct D2TimevalStrc;
struct D2SocketAddressStrc;

struct D2QClientStrc
{
    unsigned int nId;
};

typedef void (__fastcall* D2QAcceptCallback)(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine);

struct T006BE350
{
    char unk_000[0xBC4];
    D2QAcceptCallback pfnOnAccept;
};

D2QClientStrc* __fastcall sub_006BFB70_AddClient(T006BE350* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70

struct D2QAddressArg
{
    unsigned int nAddress;
};

static __declspec(noinline) void __stdcall sub_006C3440_AddClient(T006BE350* pServer, unsigned int s, D2QAddressArg tAddress);

struct D2CriticalSectionStrc { unsigned int opaque[6]; };

struct D2SocketNodeStrc {
    int id; D2SocketNodeStrc* next; int unknown8[2]; int socket;
    char unknown14[0x18]; D2CriticalSectionStrc lock; char unknown44[0x64];
    unsigned int received; int unknownAC; char data[0x5b4];
};

typedef void (__fastcall* D2NewClientFn)(D2ServerStrc*, int, const char*, int);

struct D2ServerStrc {
    char unknown0[0x14]; D2SocketNodeStrc** buckets; int bucketCount;
    char unknown1c[0x838]; D2CriticalSectionStrc lock; char unknown86c[0x14];
    int clients; char unknown884[0x30c]; int listener;
    char unknownb94[0x30]; D2NewClientFn onNewClient; char unknownbc8[0xc];
    void* event; char unknownbd8[0x20]; int stop;
    int sub_006BE980_Refresh(unsigned int key); // 0x006BE980
};

struct D2SocketSetStrc { unsigned int count; int sockets[64]; };

struct D2TimevalStrc { int seconds; int micros; };

struct D2SocketAddressStrc { unsigned int familyPort; unsigned int address; unsigned int rest[2]; };

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char*);
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitThread(unsigned int);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
extern unsigned int __security_cookie; // 0x00749DE0
void __fastcall sub_006BE700_UpdateServer(D2ServerStrc*); // 0x006BE700
void __fastcall sub_006BE640_AddReference(D2ServerStrc*,D2SocketNodeStrc*); // 0x006BE640
void __fastcall sub_006C0360_ReleaseReference(D2ServerStrc*,D2SocketNodeStrc*); // 0x006C0360
D2SocketNodeStrc* __fastcall sub_006BE5B0_FindSocket(D2ServerStrc*,int); // 0x006BE5B0
int __fastcall sub_006BE9F0_CheckRecordThreshold(D2ServerStrc*,unsigned int*); // 0x006BE9F0
int __fastcall sub_006C0800_BanByAddress(D2ServerStrc*,unsigned int*,const char*,int); // 0x006C0800
int __fastcall sub_006BFFA0_CheckAddress(D2ServerStrc*,unsigned int*); // 0x006BFFA0
void __fastcall sub_006BFEA0_RecordAddress(D2ServerStrc*,const char*,unsigned int,int); // 0x006BFEA0
D2SocketNodeStrc* __fastcall sub_006BFB70_AddSocket(D2ServerStrc*,int,unsigned int); // 0x006BFB70
void __fastcall sub_006C0420_CloseClient(D2ServerStrc*,int,const char*,int); // 0x006C0420
void __fastcall sub_006C08A0_ProcessReceived(D2ServerStrc*,D2SocketNodeStrc*); // 0x006C08A0
void __fastcall sub_0040D880_CloseSocket(int); // 0x0040D880
void __fastcall sub_00407F90_ThreadHookNop1(int); // 0x00407F90
int __stdcall sub_006B0186_Select(int,D2SocketSetStrc*,void*,D2SocketSetStrc*,D2TimevalStrc*); // 0x006B0186
int __stdcall sub_006B0180_IsSocketSet(int,D2SocketSetStrc*); // 0x006B0180
int __stdcall sub_006B0174_Receive(int,char*,int,int); // 0x006B0174
int __stdcall sub_006B0168_GetLastSocketError(); // 0x006B0168
int __stdcall sub_006C9B6A_Accept(int,D2SocketAddressStrc*,int*); // 0x006C9B6A
void __stdcall sub_006C9B7C_SetLastSocketError(int); // 0x006C9B7C
int __cdecl sub_006823FD_Format(char*,const char*,...); // 0x006823FD
void __cdecl sub_00410660_LogWritePrefixed(const char*,const char*,...); // 0x00410660
extern const char gszSource_006FCB1C[]; // 0x006FCB1C
extern const char gszHack_006FC4A8[]; // 0x006FC4A8
extern const char gszReconnect_006FCB6C[]; // 0x006FCB6C
extern const char gszAcceptError_006FCB50[]; // 0x006FCB50
extern const char gszFatal_006FCB38[]; // 0x006FCB38
extern const char gszStopped_006FCBA8[]; // 0x006FCBA8

// 0x006C3440
static void __stdcall sub_006C3440_AddClient(T006BE350* pServer, unsigned int s, D2QAddressArg tAddress)
{
    D2QClientStrc* pClient = sub_006BFB70_AddClient(pServer, s, tAddress.nAddress);
    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, pClient->nId, ".\\Src\\QServer\\QServer98.cpp", 0x91);
}

void __fastcall sub_Emit_006C3440(T006BE350* pServer, unsigned int s, unsigned int nAddress)
{
    D2QAddressArg tAddress;
    tAddress.nAddress = nAddress;
    sub_006C3440_AddClient(pServer, s, tAddress);
    sub_006C3440_AddClient(pServer, s + 1, tAddress);
}

// 0x006C3470
void __cdecl sub_006C3470_ServerThread(D2ServerStrc* server)
{
    D2SocketNodeStrc* nodes[64];
    D2SocketSetStrc readSet, errorSet;
    D2TimevalStrc timeout;
    int addressLength;
    int bucket = 0, skip = 0;
    struct { D2SocketAddressStrc address; char discard[0x5b4]; char errorText[100]; } buffers;
    for (;;)
    {
        int count = 0;
        sub_006BE700_UpdateServer(server);
        EnterCriticalSection(&server->lock);
        readSet.count = 0; errorSet.count = 0;
        D2SocketNodeStrc* node = server->buckets[bucket];
        while (node && skip--) node = node->next;
        for (int i=0; i<64; ++i)
        {
            if(i>=server->clients) break;
            if (!node)
            {
                skip=0;
                do {
                    node=server->buckets[bucket];
                    if (++bucket==server->bucketCount) bucket=0;
                } while (!node);
            }
            D2CriticalSectionStrc* lock=&node->lock;
            EnterCriticalSection(lock);
            if (node->socket != -1)
            {
                sub_006BE640_AddReference(server,node);
                nodes[count++]=node;
                if(readSet.count<64) readSet.sockets[readSet.count++]=node->socket;
                if(errorSet.count<64) errorSet.sockets[errorSet.count++]=node->socket;
                ++skip;
            }
            node=node->next;
            LeaveCriticalSection(lock);
        }
        timeout.seconds=0; timeout.micros=100000/(server->clients/64+1);
        LeaveCriticalSection(&server->lock);
        for(int j=0;j<count;++j)
        {
            node=nodes[j];
            EnterCriticalSection(&node->lock);
            if(node->socket==-1)
            {
                unsigned int k;
                for(k=0;k<readSet.count;++k) {
                    if(readSet.sockets[k]==node->socket) {
                        for(;k<readSet.count-1;++k) readSet.sockets[k]=readSet.sockets[k+1];
                        --readSet.count; break;
                    }
                }
                for(k=0;k<errorSet.count;++k) {
                    if(errorSet.sockets[k]==node->socket) {
                        for(;k<errorSet.count-1;++k) errorSet.sockets[k]=errorSet.sockets[k+1];
                        --errorSet.count; break;
                    }
                }
            }
        }
        if(server->listener!=-1) {
            if(readSet.count<64) readSet.sockets[readSet.count++]=server->listener;
            if(errorSet.count<64) errorSet.sockets[errorSet.count++]=server->listener;
        }
        int selected=sub_006B0186_Select(64,&readSet,0,&errorSet,&timeout);
        for(int j=0;j<count;++j) {
            node=nodes[j]; LeaveCriticalSection(&node->lock);
            sub_006C0360_ReleaseReference(server,node);
        }
        if(!selected) {
            EnterCriticalSection(&server->lock);
            int stop=server->stop; server->stop=0;
            LeaveCriticalSection(&server->lock);
            if(stop) { OutputDebugStringA(gszStopped_006FCBA8); sub_00407F90_ThreadHookNop1(0); ExitThread(0); }
            continue;
        }
        if(selected==-1) continue;
        for(int j=-1;j<count;++j)
        {
            int socket=j==-1 ? server->listener : nodes[j]->socket;
            if(sub_006B0180_IsSocketSet(socket,&errorSet) || !sub_006B0180_IsSocketSet(socket,&readSet)) continue;
            if(socket==server->listener)
            {
                addressLength=16; buffers.address.familyPort=0; buffers.address.address=0; buffers.address.rest[0]=0; buffers.address.rest[1]=0;
                unsigned int retries=0;
                int bDone=0;
                while(!bDone)
                {

                    sub_006C9B7C_SetLastSocketError(0);
                    EnterCriticalSection(&server->lock);
                    int accepted=sub_006C9B6A_Accept(socket,&buffers.address,&addressLength);
                    if(accepted==-1) {
                        int error=sub_006B0168_GetLastSocketError();
                        if(error!=0x2733) {
                            sub_006823FD_Format(buffers.errorText,gszAcceptError_006FCB50,error);
                            OutputDebugStringA(gszFatal_006FCB38);
                            LeaveCriticalSection(&server->lock); ExitThread(0);
                        }
                        if(++retries>100) {
                            LeaveCriticalSection(&server->lock);
                            break;
                        }
                        LeaveCriticalSection(&server->lock);
                        continue;
                    }
                    if(server->sub_006BE980_Refresh(buffers.address.address)) sub_0040D880_CloseSocket(accepted);
                    else if(sub_006BE9F0_CheckRecordThreshold(server,&buffers.address.address)) {
                        sub_006C0800_BanByAddress(server,&buffers.address.address,gszSource_006FCB1C,0x138);
                        sub_0040D880_CloseSocket(accepted);
                    }
                    else if(!sub_006BFFA0_CheckAddress(server,&buffers.address.address)) {
                        sub_00410660_LogWritePrefixed(gszHack_006FC4A8,gszReconnect_006FCB6C);
                        sub_006BFEA0_RecordAddress(server,gszSource_006FCB1C,buffers.address.address,0x142);
                        sub_0040D880_CloseSocket(accepted);
                    }
                    else {
                        node=sub_006BFB70_AddSocket(server,accepted,buffers.address.address);
                        if(server->onNewClient) server->onNewClient(server,node->id,gszSource_006FCB1C,0x91);
                    }
                    LeaveCriticalSection(&server->lock);
                    bDone=1;
                }
            }
            else {
                EnterCriticalSection(&server->lock);
                node=sub_006BE5B0_FindSocket(server,socket);
                if(node) {
                    EnterCriticalSection(&node->lock);
                    int received=0;
                    if(node->received<=0x5b4) received=sub_006B0174_Receive(socket,node->data+node->received,0x5b4-node->received,0);
                    LeaveCriticalSection(&node->lock);
                    if(received!=-1) {
                        if(received) {
                            EnterCriticalSection(&node->lock); node->received+=received; LeaveCriticalSection(&node->lock);
                            sub_006C08A0_ProcessReceived(server,node); SetEvent(server->event);
                        }
                        else sub_006C0420_CloseClient(server,node->id,gszSource_006FCB1C,0x192);
                    }
                    else sub_006C0420_CloseClient(server,node->id,gszSource_006FCB1C,0x192);
                }
                else sub_006B0174_Receive(socket,buffers.discard,0x5b4,0);
                LeaveCriticalSection(&server->lock);
            }
        }
    }
}

#include "gen/data/Source/Fog/Src/QServer/QServer98.inc"
