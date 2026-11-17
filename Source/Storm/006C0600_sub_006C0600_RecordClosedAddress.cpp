struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2ClientNodeStrc { int client; char unknown4[20]; unsigned int ip; D2ClientNodeStrc* next; };
struct D2ClientTableStrc { char unknown0[12]; unsigned int mask; char unknown10[16]; D2ClientNodeStrc** buckets; int unknown24; D2CriticalSectionStrc lock; char unknown40[0xb90]; int enabled; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc*, int, const char*, int); // 0x006C0420
const char* __stdcall sub_006B013E_FormatAddress(unsigned int); // 0x006B013E
void __cdecl sub_00410660_LogWritePrefixed(const char*, const char*, ...); // 0x00410660
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc*, const char*, unsigned int, int); // 0x006BFEA0
extern const char gszLogTag_006FC4A8[]; // 0x006FC4A8
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
    else sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_FormatAddress(ip));
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackListIP() from FILE:%s  LINE:%d", sub_006B013E_FormatAddress(ip), file, line);
    sub_006BFEA0_RecordAddress(table, file, ip, line);
}
