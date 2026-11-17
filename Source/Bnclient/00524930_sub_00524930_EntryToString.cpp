#pragma pack(push, 1)
struct D2StringRecordStrc { unsigned char active; unsigned char unknown[16]; };
struct D2StringTableStrc {
    unsigned short crc, count;
    int recordCount;
    unsigned char version;
    unsigned int start, maxTries, size;
    unsigned short indices[1];
};
#pragma pack(pop)
struct Unicode { unsigned short character; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00524930
const Unicode* __fastcall sub_00524930_EntryToString(D2StringTableStrc* table, const Unicode** strings, unsigned short index)
{
    unsigned short count = table->count;
    D2StringRecordStrc* records = (D2StringRecordStrc*)&table->indices[count];
    if (index >= count) index = 500;
    int entry = table->indices[index];
    D2_ASSERT(entry < table->recordCount, 0x102);
    D2_ASSERT((unsigned char*)&records[entry] < (unsigned char*)table + table->size, 0x106);
    D2_ASSERT(records[entry].active == 1, 0x107);
    const Unicode* const* pString = &strings[entry];
    D2_ASSERT(*pString, 0x109);
    return strings[entry];
}
