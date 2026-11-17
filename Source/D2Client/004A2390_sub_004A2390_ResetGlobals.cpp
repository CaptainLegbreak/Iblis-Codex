#define FIELD_OFFSET(T, F) ((unsigned long)&(((T*)0)->F))

#pragma pack(push, 2)
struct PackedNode
{
    char unused0[0x1e];
    int value;
    PackedNode* next;
};
#pragma pack(pop)
typedef char PackedNode_value_offset[(FIELD_OFFSET(PackedNode,value)==0x1e)?1:-1];
typedef char PackedNode_next_offset[(FIELD_OFFSET(PackedNode,next)==0x22)?1:-1];
typedef char PackedNode_size[(sizeof(PackedNode)==0x26)?1:-1];
extern "C" PackedNode* gListHead_007BF1E4;
extern "C" { unsigned char gByte_007BF2B1; } // 0x007BF2B1
extern "C" unsigned char gByte_007BF2B2; // 0x007BF2B2
extern "C" unsigned char gByte_007BF2B0; // 0x007BF2B0
extern "C" int gSentinel_007BF2B5; // 0x007BF2B5
extern "C" unsigned char gByte_007BF2B4; // 0x007BF2B4
extern "C" unsigned char gByte_007C025D; // 0x007C025D
extern "C" unsigned char gByte_007C025E; // 0x007C025E
extern "C" unsigned char gByte_007C025F; // 0x007C025F
extern "C" unsigned char gByte_007C0260; // 0x007C0260

struct SearchRecord
{
    char unused0[2];
    unsigned char value;
    unsigned char destination;
    char unused4[4];
    int key;
    char unusedC[0x4];
};
typedef char SearchRecord_size[(sizeof(SearchRecord)==0x10)?1:-1];
typedef char SearchRecord_key_offset[(FIELD_OFFSET(SearchRecord,key)==8)?1:-1];
typedef char SearchRecord_value_offset[(FIELD_OFFSET(SearchRecord,value)==2)?1:-1];
typedef char SearchRecord_destination_offset[(FIELD_OFFSET(SearchRecord,destination)==3)?1:-1];
extern "C" SearchRecord gSearch_00723F30[41];
extern "C" int gSelected_007BF280[];

struct OutputRecord
{
    char opaque[0x120];
};
struct InputRecord
{
    char unused0[0x12c];
    short value;
    char unusedAfterValue[0x66];
    short outputIndex;
    char unusedTail[0xa6];
};
struct TablesView
{
    char unused0[0xb8c];
    OutputRecord* outputs;
    int unusedBetweenOutputs;
    int outputCount;
    InputRecord* inputs;
    int unusedBetweenInputs;
    int inputCount;
};
typedef char OutputRecord_size[(sizeof(OutputRecord)==0x120)?1:-1];
typedef char InputRecord_size[(sizeof(InputRecord)==0x23c)?1:-1];
typedef char InputRecord_value_offset[(FIELD_OFFSET(InputRecord,value)==0x12c)?1:-1];
typedef char InputRecord_index_offset[(FIELD_OFFSET(InputRecord,outputIndex)==0x194)?1:-1];
typedef char TablesView_size[(sizeof(TablesView)==0xba4)?1:-1];
typedef char TablesView_outputs_offset[(FIELD_OFFSET(TablesView,outputs)==0xb8c)?1:-1];
typedef char TablesView_outputCount_offset[(FIELD_OFFSET(TablesView,outputCount)==0xb94)?1:-1];
typedef char TablesView_inputs_offset[(FIELD_OFFSET(TablesView,inputs)==0xb98)?1:-1];
typedef char TablesView_inputCount_offset[(FIELD_OFFSET(TablesView,inputCount)==0xba0)?1:-1];
extern "C" TablesView* gTables_00744304;

struct PayloadView
{
    char unused0[0x16];
    unsigned short flags;
    char unusedAfterFlags[4];
    unsigned char modifiers[10];
    short value26;
};
struct UnitView
{
    int type;
    char unused4[0x10];
    PayloadView* payload;
};
typedef char PayloadView_size[(sizeof(PayloadView)==0x28)?1:-1];
typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags)==0x16)?1:-1];
typedef char PayloadView_modifiers_offset[(FIELD_OFFSET(PayloadView,modifiers)==0x1c)?1:-1];
typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value26)==0x26)?1:-1];
typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];
typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

extern "C" void __cdecl sub_004A01E0_ClearList(void)
{
    for (PackedNode* p = gListHead_007BF1E4; p; p = p->next)
        p->value = 0;
}

// 0x004A2390
extern "C" void __cdecl sub_004A2390_ResetGlobals(void)
{
    gByte_007BF2B1 = 0;
    gByte_007BF2B2 = 0;
    gByte_007BF2B0 = 0;
    gSentinel_007BF2B5 = -1;
    gByte_007BF2B4 = 0;
    gByte_007C025D = 0;
    gByte_007C025E = 0;
    gByte_007C025F = 0;
    gByte_007C0260 = 0;
}

extern "C" void __fastcall sub_004A2C30_SelectRecord(int key)
{
    for (int i = 0; i < 41; ++i)
    {
        if (gSearch_00723F30[i].key == key)
        {
            if (i != -1)
                gSelected_007BF280[gSearch_00723F30[i].destination] = gSearch_00723F30[i].value;
            return;
        }
    }
}

extern "C" int __fastcall sub_004AA8B0_GetPositiveValue(int index)
{
    if (index >= 0 && index < gTables_00744304->inputCount)
    {
        int value = gTables_00744304->inputs[index].value;
        if (value > 0)
            return value;
    }
    return 20;
}
