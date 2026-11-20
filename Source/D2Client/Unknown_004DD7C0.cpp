#include "D2Client.h"
struct Tile;
struct Path;
struct Cell;
struct Context;
struct View;
struct TileRecord;
struct Frame;

#define FIELD(T,p,off) (*(T*)((u8*)(p)+(off)))

struct RoomCoordinates
{
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 tileX;
    s32 tileY;
    s32 tileWidth;
    s32 tileHeight;
};
struct Node
{
    s32 type;
    s32 x;
    s32 y;
    void* object;
    Node* next;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),line); exit(-1); }
extern "C" __declspec(dllimport) u32 __stdcall GetTickCount(); // 0x006CC260
extern s32 gVar_0072A968_Mode; // 0x0072A968
extern s32 gVar_007C8A08_X; // 0x007C8A08
extern s32 gVar_007C8A0C_Level; // 0x007C8A0C
extern s32 gVar_007C8A10_Y; // 0x007C8A10
extern u32 gVar_006CE268_Flags; // 0x006CE268
extern u32 gVar_006CE26C_Flags; // 0x006CE26C
extern u32 gVar_006CE274_Flags; // 0x006CE274
extern s32 __fastcall sub_00464860_Classify(Unit*); // 0x00464860
extern s32 __stdcall sub_00604CB0_Height(TileRecord*); // 0x00604CB0
extern Tile* __stdcall sub_006196A0_WallTiles(Room*,u32*); // 0x006196A0
extern Tile* __stdcall sub_006196E0_FloorTiles(Room*,u32*); // 0x006196E0
extern s32 __stdcall sub_00620650_PixelX(Unit*); // 0x00620650
extern s32 __stdcall sub_006206B0_PixelY(Unit*); // 0x006206B0
extern void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(s32,s32,s32*,s32*); // 0x00643340
extern s32 __stdcall sub_006488C0_PathX(Path*); // 0x006488C0
extern s32 __stdcall sub_00648900_PathY(Path*); // 0x00648900

static __declspec(noinline) s32 __cdecl sub_004DCF70_Inside(Context* context,s32 y,s32 x)
{
    x-=FIELD(s32,context,0xEA68);
    y-=FIELD(s32,context,0xEA6C);
    if(x<0) return 0;
    if(y<0) return 0;
    s32 size=FIELD(s32,context,0xEA78);
    if(x>=size) return 0;
    return y<size;
}

static __forceinline s32 sub_004DCF70_Inside_inl(Context* context,s32 y,s32 x)
{
    x-=FIELD(s32,context,0xEA68);
    y-=FIELD(s32,context,0xEA6C);
    if(x<0) return 0;
    if(y<0) return 0;
    s32 size=FIELD(s32,context,0xEA78);
    if(x>=size) return 0;
    if(y>=size) return 0;
    return 1;
}

static __forceinline u32 UNIT_GetFlagC4_20(Unit* unit)
{
    if(!unit) return 0;
    return (FIELD(u32,unit,196)>>20)&1;
}

static __forceinline u32 UNIT_GetFlagC8_7(Unit* unit)
{
    if(!unit) return 0;
    return (FIELD(u32,unit,200)>>7)&1;
}

struct Cell36
{
    u32 data[9];
};

static __declspec(noinline) void __cdecl sub_004DCFA0_AddUnit(Cell* cell,Context* context,Unit* unit)
{
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=0;
    node->object=unit;
    node->next=0;
    s32 x;
    s32 type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(s32,FIELD(Path*,unit,44),12);
    else { Path* path=FIELD(Path*,unit,44); x=path ? sub_006488C0_PathX(path) : 0; }
    node->x=8*x;
    s32 y;
    type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(s32,FIELD(Path*,unit,44),16);
    else { Path* path=FIELD(Path*,unit,44); y=path ? sub_00648900_PathY(path) : 0; }
    node->y=8*y;
    Node* last=FIELD(Node*,cell,24);
    if(!last) { FIELD(Node*,cell,24)=node; return; }
    while(last->next) last=last->next;
    last->next=node;
}

static __declspec(noinline) s32 __stdcall sub_004DD060_Occludes(Room* room,Tile* tile)
{
    if(gVar_0072A968_Mode)
    {
        Frame* frame=FIELD(Frame*,tile,16);
        if(!frame) return 0;
        if(FIELD(s32,frame,40)==gVar_007C8A0C_Level) return 0;
        if(gVar_007C8A08_X<FIELD(s32,frame,0)) return 1;
        return gVar_007C8A10_Y<FIELD(s32,frame,4);
    }
    RoomCoordinates coordinates;
    sub_00619730_Coordinates(room,&coordinates);
    s32 x=coordinates.x+5*FIELD(s32,tile,8);
    s32 y=coordinates.y+5*FIELD(s32,tile,12);
    s32 viewX=5*gVar_007C8A08_X;
    s32 viewY=5*gVar_007C8A10_Y;
    if(viewX<x && viewX>x-20)
    {
        switch(FIELD(s32,tile,28))
        {
        case 1: case 4: case 5: case 7: case 8: case 10: case 12: return 1;
        }
    }
    if(viewY<y && viewY>y-20)
    {
        switch(FIELD(s32,tile,28))
        {
        case 2: case 3: case 6: case 7: case 9: case 11: case 12: return 1;
        }
    }
    return 0;
}

struct WallContext
{
    s32 unk0x00;
    Node nodes[3000];
    u32 count;
};
static __declspec(noinline) void __stdcall sub_004DD180_AddWall(Context* context,Cell* cell,Room* room,Tile* tile);
// @ref 0x004DD180
static void __stdcall sub_004DD180_AddWall(Context* context,Cell* cell,Room* room,Tile* tile)
{
    RoomCoordinates coordinates;
    if(FIELD(s32,tile,28)!=0 && FIELD(s32,tile,28)!=13 && !(FIELD(u32,tile,20)&4)) FIELD(u32,cell,0)|=4;
    WallContext* wallContext=(WallContext*)context;
    u32 index=wallContext->count++;
    if(index>=3000) return;
    u32 expiry=GetTickCount()+500;
    Node* node=&wallContext->nodes[index];
    node->type=1;
    node->object=tile;
    node->next=0;
    if(!(FIELD(u32,tile,20)&4))
    {
        s32 occludes=sub_004DD060_Occludes(room,tile);
        u32 flags=FIELD(u32,tile,36);
        if(occludes)
        {
            if(!(flags&1))
            {
                u8 alpha=FIELD(u8,tile,40);
                FIELD(u8,tile,41)=255;
                FIELD(u8,tile,42)=128;
                if(alpha==255) FIELD(u32,tile,44)=expiry;
                else FIELD(u32,tile,44)=expiry+(s32(alpha)-255)*500/127;
                FIELD(u32,tile,36)=flags|3;
            }
        }
        else if(flags&1)
        {
            u8 alpha=FIELD(u8,tile,40);
            FIELD(u8,tile,41)=128;
            FIELD(u8,tile,42)=255;
            if(alpha==128) FIELD(u32,tile,44)=expiry;
            else FIELD(u32,tile,44)=expiry+(128-s32(alpha))*500/127;
            FIELD(u32,tile,36)=(flags&~1)|2;
        }
    }
    sub_00619730_Coordinates(room,&coordinates);
    node->x=8*(coordinates.x+5*FIELD(s32,tile,8));
    node->y=8*(coordinates.y+5*FIELD(s32,tile,12));
    Node* last=FIELD(Node*,cell,20);
    if(!last) { FIELD(Node*,cell,20)=node; return; }
    Node* previous=0;
    s32 order=(FIELD(u32,node->object,20)>>14)&7;
    Node* next;
    while((next=last->next)!=0)
    {
        if(order<s32((FIELD(u32,last->object,20)>>14)&7))
        {
            node->next=last;
            if(previous) previous->next=node;
            else FIELD(Node*,cell,20)=node;
            break;
        }
        previous=last;
        last=next;
    }
    if(!last->next) last->next=node;
}

// @ref 0x004DD350
static __declspec(noinline) void __stdcall sub_004DD350_AddUpper(Cell* cell,Room* room,Context* context,Tile* tile)
{
    if(FIELD(s32,tile,28)!=0 && FIELD(s32,tile,28)!=13 && !(FIELD(u32,tile,20)&4)) FIELD(u32,cell,0)|=4;
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=1;
    node->object=tile;
    node->next=0;
    RoomCoordinates coordinates;
    sub_00619730_Coordinates(room,&coordinates);
    node->x=8*(coordinates.x+5*FIELD(s32,tile,8));
    node->y=8*(coordinates.y+5*FIELD(s32,tile,12));
    FIELD(u32,context,0)|=gVar_006CE268_Flags;
    Node* last=FIELD(Node*,cell,32);
    if(!last) { FIELD(Node*,cell,32)=node; return; }
    s32 order=(FIELD(u32,node->object,20)>>14)&7;
    Node* previous=0;
    while(last->next)
    {
        if(order<s32((FIELD(u32,last->object,20)>>14)&7))
        {
            node->next=last;
            if(previous) previous->next=node;
            else FIELD(Node*,cell,32)=node;
            break;
        }
        previous=last;
        last=last->next;
    }
    if(!last->next) last->next=node;
}

// @ref 0x004DD460
static __declspec(noinline) void __stdcall sub_004DD460_AddRoof(Cell* cell,Room* room,Context* context,Tile* tile)
{
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=1;
    node->object=tile;
    node->next=0;
    RoomCoordinates coordinates;
    sub_00619730_Coordinates(room,&coordinates);
    node->x=8*(coordinates.x+5*FIELD(s32,tile,8));
    node->y=8*(coordinates.y+5*FIELD(s32,tile,12));
    FIELD(u32,context,0)|=gVar_006CE26C_Flags;
    Node* last=FIELD(Node*,cell,28);
    if(!last) { FIELD(Node*,cell,28)=node; return; }
    s32 order=(FIELD(u32,node->object,20)>>14)&7;
    Node* previous=0;
    while(last->next)
    {
        if(order<s32((FIELD(u32,last->object,20)>>14)&7))
        {
            node->next=last;
            if(previous) previous->next=node;
            else FIELD(Node*,cell,28)=node;
            break;
        }
        previous=last;
        last=last->next;
    }
    if(!last->next) last->next=node;
}

// @ref 0x004DD550
static __declspec(noinline) void __stdcall sub_004DD550_AddFloor(Cell* cell,Room* room,Context* context,Tile* tile)
{
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=1;
    node->object=tile;
    node->next=0;
    RoomCoordinates coordinates;
    sub_00619730_Coordinates(room,&coordinates);
    node->x=8*(coordinates.x+5*FIELD(s32,tile,8));
    node->y=8*(coordinates.y+5*FIELD(s32,tile,12));
    FIELD(u32,context,0)|=gVar_006CE274_Flags;
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last->next) last=last->next;
    last->next=node;
}

// @ref 0x004DD600
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
    if(type==2 || (type>3 && type<=5)) x=FIELD(s32,FIELD(Path*,unit,44),12);
    else { Path* path=FIELD(Path*,unit,44); x=path ? sub_006488C0_PathX(path) : 0; }
    node->x=8*x;
    s32 y;
    type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(s32,FIELD(Path*,unit,44),16);
    else { Path* path=FIELD(Path*,unit,44); y=path ? sub_00648900_PathY(path) : 0; }
    node->y=8*y;
    FIELD(u32,context,0)|=gVar_006CE274_Flags;
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last)
    {
        Node* next=last->next;
        if(!next) break;
        last=next;
    }
    last->next=node;
}

static __declspec(noinline) void __stdcall sub_004DD6E0_AddOverlay(Cell* cell,Context* context,Unit* unit)
{
    u32 index=FIELD(u32,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=2;
    node->object=unit;
    node->next=0;
    s32 x;
    s32 type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(s32,FIELD(Path*,unit,44),12);
    else { Path* path=FIELD(Path*,unit,44); x=path ? sub_006488C0_PathX(path) : 0; }
    node->x=8*x;
    s32 y;
    type=FIELD(s32,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(s32,FIELD(Path*,unit,44),16);
    else { Path* path=FIELD(Path*,unit,44); y=path ? sub_00648900_PathY(path) : 0; }
    node->y=8*y;
    FIELD(u32,context,0)|=gVar_006CE274_Flags;
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last->next) last=last->next;
    last->next=node;
}

// 0x004DD7C0
s32 __stdcall sub_004DD7C0_VisitRoom(Room* room,View* view)
{
    Context* context=(Context*)((u8*)FIELD(void*,view,0)+56);
    Rectangle rectangle;
    sub_00619C40_Rectangle(room,&rectangle);
    if(rectangle.left>FIELD(s32,view,12)) return 1;
    if(rectangle.top>FIELD(s32,view,16)+400) return 1;
    if(rectangle.right<FIELD(s32,view,4)-200) return 1;
    if(rectangle.bottom<FIELD(s32,view,8)) return 1;
    u32 i;
    u32 count;
    Tile* tiles=sub_006196A0_WallTiles(room,&count);
    for(i=0;i<count;++i)
    {
        Tile* tile=(Tile*)((u8*)tiles+48*i);
        TileRecord* record=FIELD(TileRecord*,tile,24);
        s32 height=sub_00604CB0_Height(record);
        s32 y,x;
        DUNGEON_ClientTileDrawPositionToGameCoords(FIELD(s32,tile,0),FIELD(s32,tile,4),&x,&y);
        --y;
        if(FIELD(s32,tile,0)>FIELD(s32,view,12)) continue;
        if(FIELD(s32,tile,0)+160<FIELD(s32,view,4)) continue;
        s32 pixelY=FIELD(s32,tile,4)-FIELD(u16,record,4);
        if(pixelY+height>FIELD(s32,view,16)) continue;
        if(pixelY-height<FIELD(s32,view,8)) continue;
        if(!sub_004DCF70_Inside(context,y,x)) continue;
        x-=FIELD(s32,context,0xEA68);
        y-=FIELD(s32,context,0xEA6C);
        Cell* cell=(Cell*)((u8*)FIELD(Cell*,context,0xEA70)+36*(x+FIELD(s32,context,0xEA78)*y));
        FIELD(u32,cell,0)=0;
        if(!(FIELD(u32,tile,20)&0x1C000)) sub_004DD550_AddFloor(cell,room,context,tile);
        else
        {
            switch(FIELD(s32,tile,28))
            {
            case 15: sub_004DD460_AddRoof(cell,room,context,tile); break;
            case 16: case 17: case 18: case 19: sub_004DD350_AddUpper(cell,room,context,tile); break;
            default: sub_004DD180_AddWall(context,cell,room,tile); break;
            }
        }
    }
    tiles=sub_006196E0_FloorTiles(room,&count);
    for(i=0;i<count;++i)
    {
        Tile* tile=(Tile*)((u8*)tiles+48*i);
        s32 height=sub_00604CB0_Height(FIELD(TileRecord*,tile,24));
        s32 y,x;
        DUNGEON_ClientTileDrawPositionToGameCoords(FIELD(s32,tile,0),FIELD(s32,tile,4),&x,&y);
        --y;
        if(FIELD(s32,tile,0)>FIELD(s32,view,12)) continue;
        if(FIELD(s32,tile,0)+160<FIELD(s32,view,4)) continue;
        if(FIELD(s32,tile,4)+height>FIELD(s32,view,16)) continue;
        if(FIELD(s32,tile,4)-height<FIELD(s32,view,8)) continue;
        if(!sub_004DCF70_Inside(context,y,x)) continue;
        x-=FIELD(s32,context,0xEA68);
        y-=FIELD(s32,context,0xEA6C);
        Cell* cell=(Cell*)((u8*)FIELD(Cell*,context,0xEA70)+36*(x+FIELD(s32,context,0xEA78)*y));
        sub_004DD550_AddFloor(cell,room,context,tile);
    }
    if(FIELD(s32,view,24)) return 1;
    for(Unit* unit=sub_00619EA0_Units(room);unit;unit=FIELD(Unit*,unit,232))
    {
        s32 x=sub_00620650_PixelX(unit);
        s32 y=sub_006206B0_PixelY(unit);
        DUNGEON_ClientTileDrawPositionToGameCoords(x,y,&x,&y);
        if(!sub_004DCF70_Inside_inl(context,y,x)) continue;
        x-=FIELD(s32,context,0xEA68);
        y-=FIELD(s32,context,0xEA6C);
        D2_ASSERT(x>=0 && x<FIELD(s32,context,0xEA78),768);
        D2_ASSERT(y>=0 && y<FIELD(s32,context,0xEA78),769);
        Cell* cell=(Cell*)&FIELD(Cell36*,context,0xEA70)[x+FIELD(s32,context,0xEA78)*y];
        if(sub_00464860_Classify(unit)) sub_004DD600_AddSpecial(cell,context,unit);
        else if(UNIT_GetFlagC4_20(unit)) sub_004DD600_AddSpecial(cell,context,unit);
        else
        {
            sub_004DCFA0_AddUnit(cell,context,unit);
            if(UNIT_GetFlagC8_7(unit)) sub_004DD6E0_AddOverlay(cell,context,unit);
        }
    }
    return 1;
}
