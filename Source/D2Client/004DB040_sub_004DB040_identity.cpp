struct PartialSparseClear
{
    char unknown_00[0x38];
    unsigned int first;
    char unknown_3C[0xEA9C - 0x3C];
    unsigned int second;
    char unknown_EAA0[8];
    unsigned int third;
    char unknown_EAAC[4];
    unsigned int fourth;
};
struct PartialTableRecord
{
    char opaque[12];
};
struct PartialTableView
{
    char unknown_00[0xC34];
    int count;
    char unknown_C38[4];
    PartialTableRecord* records;
};
extern "C" PartialTableView* gTableView_00744304;
struct PartialLookupRecord
{
    unsigned char key;
    unsigned char first;
    unsigned char second;
    char unknown_03[6];
};
struct PartialLookupHeader
{
    unsigned char count;
    char unknown_01[0x1B];
    PartialLookupRecord records[1];
};
#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))
typedef char check_PartialSparseClear_size[sizeof(PartialSparseClear) == 0xEAB4 ? 1 : -1];
typedef char check_PartialSparseClear_first[offsetof(PartialSparseClear, first) == 0x38 ? 1 : -1];
typedef char check_PartialSparseClear_second[offsetof(PartialSparseClear, second) == 0xEA9C ? 1 : -1];
typedef char check_PartialSparseClear_third[offsetof(PartialSparseClear, third) == 0xEAA8 ? 1 : -1];
typedef char check_PartialSparseClear_fourth[offsetof(PartialSparseClear, fourth) == 0xEAB0 ? 1 : -1];
typedef char check_PartialTableRecord_size[sizeof(PartialTableRecord) == 12 ? 1 : -1];
typedef char check_PartialTableView_size[sizeof(PartialTableView) == 0xC40 ? 1 : -1];
typedef char check_PartialTableView_count[offsetof(PartialTableView, count) == 0xC34 ? 1 : -1];
typedef char check_PartialTableView_records[offsetof(PartialTableView, records) == 0xC3C ? 1 : -1];
typedef char check_PartialLookupRecord_size[sizeof(PartialLookupRecord) == 9 ? 1 : -1];
typedef char check_PartialLookupRecord_key[offsetof(PartialLookupRecord, key) == 0 ? 1 : -1];
typedef char check_PartialLookupRecord_first[offsetof(PartialLookupRecord, first) == 1 ? 1 : -1];
typedef char check_PartialLookupRecord_second[offsetof(PartialLookupRecord, second) == 2 ? 1 : -1];
typedef char check_PartialLookupHeader_records[offsetof(PartialLookupHeader, records) == 0x1C ? 1 : -1];

// 0x004DB040
extern "C" void* __fastcall sub_004DB040_identity(void* pointer)
{
    return pointer;
}

extern "C" int __fastcall sub_004DB180_range(const int* record)
{
    if (record && *record >= 0 && *record <= 2)
        return 1;
    return 0;
}

extern "C" PartialTableRecord* __fastcall sub_004E4640_boundedTable(int index)
{
    if (index >= 0 && index < gTableView_00744304->count)
        return &gTableView_00744304->records[index];
    return gTableView_00744304->records;
}
