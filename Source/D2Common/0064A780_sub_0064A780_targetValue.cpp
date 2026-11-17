typedef unsigned int U32;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
struct TargetData
{
    char gap0[0x2C];
    int value;
};
typedef char check_TargetData_value[OFFSET(TargetData,value)==0x2C?1:-1];
typedef char check_TargetData_size[sizeof(TargetData)==0x30?1:-1];
struct UnitView
{
    U32 kind;
    char gap4[0x10];
    TargetData* data;
};
typedef char check_UnitView_kind[OFFSET(UnitView,kind)==0x0?1:-1];
typedef char check_UnitView_data[OFFSET(UnitView,data)==0x14?1:-1];
typedef char check_UnitView_size[sizeof(UnitView)==0x18?1:-1];
struct SlotPair
{
    U32 first;
    U32 second;
};
typedef char check_SlotPair_first[OFFSET(SlotPair,first)==0x0?1:-1];
typedef char check_SlotPair_second[OFFSET(SlotPair,second)==0x4?1:-1];
typedef char check_SlotPair_size[sizeof(SlotPair)==0x8?1:-1];
struct Node32
{
    char gap0[0x4];
    SlotPair* slots;
    U32 slotIndex;
    char gapC[0xC];
    Node32* next;
    Node32* previous;
};
typedef char check_Node32_slots[OFFSET(Node32,slots)==0x4?1:-1];
typedef char check_Node32_slotIndex[OFFSET(Node32,slotIndex)==0x8?1:-1];
typedef char check_Node32_next[OFFSET(Node32,next)==0x18?1:-1];
typedef char check_Node32_previous[OFFSET(Node32,previous)==0x1C?1:-1];
typedef char check_Node32_size[sizeof(Node32)==0x20?1:-1];
struct Queue32
{
    char gap0[0x4];
    U32 count;
    Node32* head;
    Node32* tail;
    Node32* freeHead;
    Node32* freeTail;
    Node32* array;
};
typedef char check_Queue32_count[OFFSET(Queue32,count)==0x4?1:-1];
typedef char check_Queue32_head[OFFSET(Queue32,head)==0x8?1:-1];
typedef char check_Queue32_tail[OFFSET(Queue32,tail)==0xC?1:-1];
typedef char check_Queue32_freeHead[OFFSET(Queue32,freeHead)==0x10?1:-1];
typedef char check_Queue32_freeTail[OFFSET(Queue32,freeTail)==0x14?1:-1];
typedef char check_Queue32_array[OFFSET(Queue32,array)==0x18?1:-1];
typedef char check_Queue32_size[sizeof(Queue32)==0x1C?1:-1];
struct Node24
{
    char gap0[0x10];
    Node24* next;
    Node24* previous;
};
typedef char check_Node24_next[OFFSET(Node24,next)==0x10?1:-1];
typedef char check_Node24_previous[OFFSET(Node24,previous)==0x14?1:-1];
typedef char check_Node24_size[sizeof(Node24)==0x18?1:-1];
struct Queue24
{
    char gap0[0x8];
    Node24* head;
    Node24* tail;
    char gap10[0x8];
    Node24* array;
};
typedef char check_Queue24_head[OFFSET(Queue24,head)==0x8?1:-1];
typedef char check_Queue24_tail[OFFSET(Queue24,tail)==0xC?1:-1];
typedef char check_Queue24_array[OFFSET(Queue24,array)==0x18?1:-1];
typedef char check_Queue24_size[sizeof(Queue24)==0x1C?1:-1];

// 0x0064A780
extern "C" int __stdcall sub_0064A780_targetValue(UnitView* unit)
{
    if (unit && unit->kind == 3)
    {
        TargetData* data = unit->data;
        if (data)
            return data->value;
    }
    return 0;
}
