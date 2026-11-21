#include "D2SysTypes.h"
#include "D2QServer.h"
struct D2MessageStrc { int client; unsigned char data[0x5B0]; int size; unsigned long tick; D2MessageStrc* next; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
void __fastcall sub_006C0420_CloseClient(D2QueueServerStrc* table, int client, const char* file, int line); // 0x006C0420
void __fastcall sub_006BFEA0_RecordAddress(D2QueueServerStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __cdecl sub_00410660_LogWritePrefixed(const char*, const char*, ...); // 0x00410660
extern "C" char* __stdcall inet_ntoa(unsigned int); // 0x006B013E
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0
extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837
extern const char gszFile_006FC460[]; // 0x006FC460
extern const char gszHack_006FC4A8[]; // 0x006FC4A8
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); }
static __declspec(noinline) int __stdcall sub_006C00A0_AccountTraffic(D2QueueServerStrc*, unsigned int, D2QClientStrc*);
static int __stdcall sub_006C00A0_AccountTraffic(D2QueueServerStrc*, unsigned int, D2QClientStrc*); // 0x006C00A0
// 0x006C00A0
static int __stdcall sub_006C00A0_AccountTraffic(D2QueueServerStrc* pTable, unsigned int nBytes, D2QClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->tLock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
        return pTable->sub_006BF660_CheckAddress(pClient->nAddress) != 0;
    if (dwTick - pClient->nTick24 > 1000) {
        EnterCriticalSection(pLock);
        pClient->nTick24 = dwTick;
        if (pClient->nPending >= 200) pClient->nPending -= 200;
        else pClient->nPending = 0;
        LeaveCriticalSection(pLock);
    }
    return 1;
}
static __declspec(noinline) void __stdcall sub_006C0770_BanClient(D2QueueServerStrc*, int, const char*, int);
static void __stdcall sub_006C0770_BanClient(D2QueueServerStrc*, int, const char*, int); // 0x006C0770
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
                sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to sQSSpamCheck in QSrvProcessMsg", inet_ntoa(client->nAddress));
                sub_006C0770_BanClient(server, client->iId, gszFile_006FC460, 0x649);
                return;
            }
            break;
        case 3: return;
        case 4:
            sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to PACKET_INVALID in QSrvProcessMsg", inet_ntoa(client->nAddress));
            sub_006C0770_BanClient(server, client->iId, gszFile_006FC460, 0x635);
            return;
        }
        if (result != 5) {
            D2MessageStrc* message;
            if (server->pFreeMessages) {
                EnterCriticalSection(&server->tLock);
                message = server->pFreeMessages;
                if (message) server->pFreeMessages = message->next;
                else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x664, 0);
                LeaveCriticalSection(&server->tLock);
            } else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x66D, 0);
            int size = consumed - start;
            if (size > 0) {
                EnterCriticalSection(&client->tLock);
                memcpy(message->data, client->pBuffer + start, size);
                LeaveCriticalSection(&client->tLock);
            } else *(unsigned char*)message = 0;
            message->size = size;
            message->tick = GetTickCount();
            message->next = 0;
            message->client = client->iId;
            D2_ASSERT(queue < server->nQueueCount, 0x6A1);
            EnterCriticalSection(&server->tLock);
            D2MessageStrc* tail = server->ppMsgTails[queue];
            if (!tail) server->ppMsgHeads[queue] = message;
            else tail->next = message;
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
