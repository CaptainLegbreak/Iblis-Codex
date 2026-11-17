struct D2CriticalSectionStrc { void* debug; long lockCount; long recursionCount; void* owner; void* semaphore; unsigned long spinCount; };
struct D2ClientNodeStrc { int client; D2ClientNodeStrc* next; unsigned char pad[0x10]; unsigned int address; };
struct D2ClientTableStrc { unsigned char pad0[0xC]; unsigned int mask; unsigned char pad1[4]; D2ClientNodeStrc** buckets; unsigned char pad2[4]; D2CriticalSectionStrc* locks; unsigned char pad3[0xBB0]; int enabled; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc* table, int client, const char* file, int line); // 0x006C0420
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0

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
