struct D2CriticalSectionStrc { void* debug; long lockCount, recursionCount; void* owner; void* semaphore; unsigned long spinCount; };
struct D2ClientNodeStrc { int client; D2ClientNodeStrc* next; unsigned char pad[0x10]; unsigned int address; };
struct D2MessageStrc { int client; unsigned char data[0x5B0]; int size; unsigned long tick; D2MessageStrc* next; };
typedef int (__fastcall* D2MessageCallback)(unsigned char*, int, int*, int*, int*, int*, int, int, unsigned int);
struct D2ClientTableStrc {
    unsigned char pad0[0xC]; unsigned int mask; unsigned char pad1[4]; D2ClientNodeStrc** buckets;
    unsigned char pad2[4]; D2CriticalSectionStrc* locks;
    unsigned char pad20[0x854-0x20]; D2CriticalSectionStrc messageLock;
    unsigned char pad86C[4]; D2MessageStrc** heads; D2MessageStrc** tails; D2MessageStrc* freeMessages; int queueCount;
    unsigned char pad880[0xBC0-0x880]; D2MessageCallback process;
    unsigned char padBC4[0xBD0-0xBC4]; int enabled;
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};
struct D2ServerClientStrc {
    int client; unsigned char pad4[0x14]; unsigned int address; unsigned char pad1C[4]; int context;
    unsigned long lastTick; unsigned int nPending; D2CriticalSectionStrc lock;
    unsigned char pad44[0xA8-0x44]; int readBytes; unsigned int padAC; unsigned char buffer[0x5B4];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc* table, int client, const char* file, int line); // 0x006C0420
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0
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
static __declspec(noinline) int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc*, unsigned int, D2ServerClientStrc*);
static int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc*, unsigned int, D2ServerClientStrc*); // 0x006C00A0
// 0x006C00A0
static int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc* pTable, unsigned int nBytes, D2ServerClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->lock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
        return pTable->sub_006BF660_CheckAddress(pClient->address) != 0;
    if (dwTick - pClient->lastTick > 1000) {
        EnterCriticalSection(pLock);
        pClient->lastTick = dwTick;
        if (pClient->nPending >= 200) pClient->nPending -= 200;
        else pClient->nPending = 0;
        LeaveCriticalSection(pLock);
    }
    return 1;
}
static __declspec(noinline) void __stdcall sub_006C0770_BanClient(D2ClientTableStrc*, int, const char*, int);
static void __stdcall sub_006C0770_BanClient(D2ClientTableStrc*, int, const char*, int); // 0x006C0770
// 0x006C0770
static void __stdcall sub_006C0770_BanClient(D2ClientTableStrc* table, int client, const char* file, int line)
{
    if (!table->enabled) return;
    unsigned int bucket = table->mask & client;
    EnterCriticalSection(&table->locks[bucket]);
    D2ClientNodeStrc* node = table->buckets[bucket];
    unsigned int address = 0;
    while (node) {
        if (node->client == client) { address = node->address; break; }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[bucket]);
    sub_006C0420_CloseClient(table, client, file, line);
    if (address) sub_006BFEA0_RecordAddress(table, file, address, line);
}
// 0x006C08A0
void __fastcall sub_006C08A0_Dispatch(D2ClientTableStrc* server, D2ServerClientStrc* client)
{
    int start = 0, consumed = 0, queue = 0, charge = 0;
    while (server->process) {
        EnterCriticalSection(&client->lock);
        int count = client->readBytes;
        LeaveCriticalSection(&client->lock);
        int result = server->process(client->buffer, count, &consumed, &start, &queue, &charge, client->client, client->context, client->address);
        switch (result) {
        case 2:
            if (server->enabled && !sub_006C00A0_AccountTraffic(server, charge, client)) {
                sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to sQSSpamCheck in QSrvProcessMsg", inet_ntoa(client->address));
                sub_006C0770_BanClient(server, client->client, gszFile_006FC460, 0x649);
                return;
            }
            break;
        case 3: return;
        case 4:
            sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  User at %s banned due to PACKET_INVALID in QSrvProcessMsg", inet_ntoa(client->address));
            sub_006C0770_BanClient(server, client->client, gszFile_006FC460, 0x635);
            return;
        }
        if (result != 5) {
            D2MessageStrc* message;
            if (server->freeMessages) {
                EnterCriticalSection(&server->messageLock);
                message = server->freeMessages;
                if (message) server->freeMessages = message->next;
                else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x664, 0);
                LeaveCriticalSection(&server->messageLock);
            } else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszFile_006FC460, 0x66D, 0);
            int size = consumed - start;
            if (size > 0) {
                EnterCriticalSection(&client->lock);
                memcpy(message->data, client->buffer + start, size);
                LeaveCriticalSection(&client->lock);
            } else *(unsigned char*)message = 0;
            message->size = size;
            message->tick = GetTickCount();
            message->next = 0;
            message->client = client->client;
            D2_ASSERT(queue < server->queueCount, 0x6A1);
            EnterCriticalSection(&server->messageLock);
            D2MessageStrc* tail = server->tails[queue];
            if (!tail) server->heads[queue] = message;
            else tail->next = message;
            server->tails[queue] = message;
            LeaveCriticalSection(&server->messageLock);
        }
        EnterCriticalSection(&client->lock);
        client->readBytes -= consumed;
        D2_ASSERT(client->readBytes + consumed <= 0x5B4, 0x6AD);
        memmove(client->buffer, client->buffer + consumed, client->readBytes);
        LeaveCriticalSection(&client->lock);
        start = 0; consumed = 0; queue = 0; charge = 0;
    }
}
