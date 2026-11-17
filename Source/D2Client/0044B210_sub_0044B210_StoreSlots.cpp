typedef unsigned int U32;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
struct LimbCell
{
    U32 value;
};
struct SequenceView
{
    char prefix[0x4];
    U32 count;
    LimbCell* values;
    char gap[0x4];
    U32 cursor;
};
struct StoredRecordView
{
    char prefix[0x10];
    int f_10;
};
typedef char check_pointer[sizeof(void*)==4?1:-1];
typedef char check_word[sizeof(U32)==4?1:-1];
typedef char check_cell[sizeof(LimbCell)==0x4?1:-1];
typedef char check_count[OFFSET(SequenceView,count)==0x4?1:-1];
typedef char check_values[OFFSET(SequenceView,values)==0x8?1:-1];
typedef char check_cursor[OFFSET(SequenceView,cursor)==0x10?1:-1];
typedef char check_mode[OFFSET(StoredRecordView,f_10)==0x10?1:-1];
extern "C" { U32 gSlotFirst; } // 0x00799300
extern "C" { U32 gSlotSecond; } // 0x00799304
extern "C" U32 gRangeMode;
extern "C" int gRangeValue;
struct UiContext;
extern "C" UiContext* gUiContext;
extern "C" int gRequest;
extern "C" int gState;

// 0x00420FE0
extern "C" LimbCell* __fastcall sub_00420FE0_LastCell(SequenceView* sequence)
{
    U32 count = sequence->count;
    if (count)
        return sequence->values + count - 1;
    return 0;
}

// 0x0044B210
extern "C" void __fastcall sub_0044B210_StoreSlots(U32 first, U32 second)
{
    gSlotFirst = first;
    gSlotSecond = second;
}

extern "C" int __cdecl sub_004549C0_IsEnabled()
{
    return gUiContext != 0;
}

extern "C" int __fastcall sub_0047A0C0_GetRecordUnitId(StoredRecordView* object)
{
    if (object)
        return object->f_10;
    return -1;
}

extern "C" int __cdecl sub_00487CA0_SetStateIfDifferent()
{
    int value = 6;
    if (gState == value)
        return 0;
    gState = value;
    return 1;
}
