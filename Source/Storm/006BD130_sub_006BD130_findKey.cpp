typedef unsigned int U32;
typedef signed char S8;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
struct RoomFlags
{
    char pad0[0x28];
    U32 flags;
};
typedef char check_RoomFlags_flags[OFFSET(RoomFlags,flags)==0x28?1:-1];
typedef char check_RoomFlags_size[sizeof(RoomFlags)==0x2C?1:-1];
struct PathFlags
{
    char pad0[0x34];
    U32 flags;
};
typedef char check_PathFlags_flags[OFFSET(PathFlags,flags)==0x34?1:-1];
typedef char check_PathFlags_size[sizeof(PathFlags)==0x38?1:-1];
struct KeyValue
{
    U32 key;
    int value;
};
typedef char check_KeyValue_value[OFFSET(KeyValue,value)==4?1:-1];
typedef char check_KeyValue_size[sizeof(KeyValue)==8?1:-1];
struct CodeRow
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    int row;
};
typedef char check_CodeRow_row[OFFSET(CodeRow,row)==4?1:-1];
typedef char check_CodeRow_c0[OFFSET(CodeRow,c0)==0?1:-1];
typedef char check_CodeRow_c1[OFFSET(CodeRow,c1)==1?1:-1];
typedef char check_CodeRow_c2[OFFSET(CodeRow,c2)==2?1:-1];
typedef char check_CodeRow_c3[OFFSET(CodeRow,c3)==3?1:-1];
typedef char check_CodeRow_size[sizeof(CodeRow)==8?1:-1];
struct CodeOutput
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    S8 terminal;
};
typedef char check_CodeOutput_terminal[OFFSET(CodeOutput,terminal)==4?1:-1];
typedef char check_CodeOutput_c0[OFFSET(CodeOutput,c0)==0?1:-1];
typedef char check_CodeOutput_c1[OFFSET(CodeOutput,c1)==1?1:-1];
typedef char check_CodeOutput_c2[OFFSET(CodeOutput,c2)==2?1:-1];
typedef char check_CodeOutput_c3[OFFSET(CodeOutput,c3)==3?1:-1];
typedef char check_CodeOutput_size[sizeof(CodeOutput)==5?1:-1];
struct LinkView
{
    int count;
    char pad4[0x4];
    KeyValue* entries;
};
typedef char check_LinkView_entries[OFFSET(LinkView,entries)==0x8?1:-1];
typedef char check_LinkView_size[sizeof(LinkView)==0xC?1:-1];
struct CodeLink
{
    int count;
    char pad4[0x4];
    CodeRow* entries;
};
typedef char check_CodeLink_entries[OFFSET(CodeLink,entries)==0x8?1:-1];
typedef char check_CodeLink_size[sizeof(CodeLink)==0xC?1:-1];
struct Vector
{
    int x;
    int y;
};
typedef char check_Vector_y[OFFSET(Vector,y)==4?1:-1];
typedef char check_Vector_size[sizeof(Vector)==8?1:-1];
struct DirectionRecord
{
    int x;
    int y;
    int angle;
};
typedef char check_DirectionRecord_y[OFFSET(DirectionRecord,y)==4?1:-1];
typedef char check_DirectionRecord_angle[OFFSET(DirectionRecord,angle)==8?1:-1];
typedef char check_DirectionRecord_size[sizeof(DirectionRecord)==12?1:-1];
extern DirectionRecord gDirectionTable_006EB7E0[128];

extern "C" void __fastcall sub_0061BAC0_portalFlag(RoomFlags* room, int reset)
{
    if (reset)
        room->flags &= ~0x400000U;
    else
        room->flags |= 0x400000U;
}

// 0x00648B40
extern "C" void __stdcall sub_00648B40_roomInvalid(PathFlags* path, int invalid)
{
    if (invalid != 0)
        path->flags |= 2U;
    else
        path->flags &= ~2U;
}

// 0x006BD130
extern "C" int __stdcall sub_006BD130_findKey(LinkView* link, U32 key, int unusedLogError)
{
    int upper = link->count;
    int lower = 0;
    KeyValue* entries = link->entries;
    while (lower < upper)
    {
        int middle = lower + (upper - lower) / 2;
        U32 current = entries[middle].key;
        if (key > current)
            lower = middle + 1;
        else if (key < current)
            upper = middle;
        else
            return entries[middle].value;
    }
    return -1;
}
