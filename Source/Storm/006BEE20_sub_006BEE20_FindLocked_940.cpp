struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2HashNodeStrc { unsigned int key; D2HashNodeStrc* next; unsigned int reserved[4]; void* value; };
struct D2HashTableStrc { unsigned int reserved0[3]; unsigned int mask; unsigned int reserved10; D2HashNodeStrc** buckets; unsigned int reserved18; D2CriticalSectionStrc* locks; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* section);
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
