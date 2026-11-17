#define FIELD_OFFSET(T,F) ((unsigned long)&(((T*)0)->F))

struct RecordView
{
    char opaque[0x1a8];
};
struct PayloadView
{
    RecordView* record;
    char unused4[0x24];
    unsigned short flags28;
    char unusedAfterFlags[0x12];
    int value3c;
};
struct UnitView
{
    int type;
    int classId;
    char unusedAfterClass[0x0c];
    PayloadView* payload;
};
struct TablesView
{
    char unused0[0xa78];
    RecordView* records;
    int unusedAfterRecords;
    int count;
};
extern "C" TablesView* gTables_00744304;
typedef char RecordView_size[(sizeof(RecordView)==0x1a8)?1:-1];
typedef char PayloadView_size[(sizeof(PayloadView)==0x40)?1:-1];
typedef char PayloadView_record_offset[(FIELD_OFFSET(PayloadView,record)==0)?1:-1];
typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags28)==0x28)?1:-1];
typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value3c)==0x3c)?1:-1];
typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];
typedef char UnitView_class_offset[(FIELD_OFFSET(UnitView,classId)==0x4)?1:-1];
typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];
typedef char TablesView_size[(sizeof(TablesView)==0xa84)?1:-1];
typedef char TablesView_records_offset[(FIELD_OFFSET(TablesView,records)==0xa78)?1:-1];
typedef char TablesView_count_offset[(FIELD_OFFSET(TablesView,count)==0xa80)?1:-1];

// 0x004AE080
extern "C" int __fastcall sub_004AE080_MaskedPayloadWord(UnitView* unit, unsigned short mask)
{
    if (unit && unit->type == 1)
    {
        PayloadView* data = unit->payload;
        if (data)
            return data->flags28 & mask;
    }
    return 0;
}

extern "C" int __fastcall sub_004AE130_GetPayloadValue(UnitView* unit)
{
    PayloadView* data = (unit && unit->type == 1) ? unit->payload : 0;
    if (!data)
        return -1;
    return data->value3c;
}
