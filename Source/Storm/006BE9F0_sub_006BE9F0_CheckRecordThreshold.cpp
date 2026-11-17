struct D2CriticalSectionStrc { unsigned int opaque[6]; };
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
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
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
