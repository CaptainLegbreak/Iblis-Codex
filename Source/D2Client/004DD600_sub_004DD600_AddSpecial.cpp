typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
struct Unit;
struct Cell;
struct Context;
struct D2DynamicPathStrc;

#define FIELD(T,p,off) (*(T*)((u8*)(p)+(off)))

struct Node
{
    s32 type;
    s32 x;
    s32 y;
    void* object;
    Node* next;
};

extern u32 gVar_006CE274_Flags;                                                                             // 0x006CE274
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

// 0x004DD600
static __declspec(noinline) void __stdcall sub_004DD600_AddSpecial(Cell* cell,Context* context,Unit* unit)
{
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=0;
    node->object=unit;
    node->next=0;
    s32 x;
    s32 type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(s32,FIELD(D2DynamicPathStrc*,unit,44),12);
    else { D2DynamicPathStrc* path=FIELD(D2DynamicPathStrc*,unit,44); x=path ? PATH_GetXPosition(path) : 0; }
    node->x=8*x;
    s32 y;
    type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(s32,FIELD(D2DynamicPathStrc*,unit,44),16);
    else { D2DynamicPathStrc* path=FIELD(D2DynamicPathStrc*,unit,44); y=path ? PATH_GetYPosition(path) : 0; }
    node->y=8*y;
    FIELD(u32,context,0)|=gVar_006CE274_Flags;
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last)
    {
        if(!last->next) break;
        last=last->next;
    }
    last->next=node;
}

void __stdcall sub_M95_Emit_004DD7C0(Context* context, Cell* cell, Unit* unit)
{
    sub_004DD600_AddSpecial(cell, context, unit);
}

#include "gen/data/Source/D2Client/004DD600_sub_004DD600_AddSpecial.inc"
