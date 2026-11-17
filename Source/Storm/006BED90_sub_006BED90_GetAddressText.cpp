struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2InAddrStrc { unsigned int address; };
struct D2HashNodeStrc { unsigned int key; D2HashNodeStrc* next; unsigned int reserved08[2]; int value; unsigned int reserved14; D2InAddrStrc address; };
struct D2HashTableStrc { unsigned int reserved0[2]; unsigned int count, mask; unsigned int reserved10; D2HashNodeStrc** buckets; unsigned int reserved18; D2CriticalSectionStrc* locks; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc); // 0x006B013E
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0

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
