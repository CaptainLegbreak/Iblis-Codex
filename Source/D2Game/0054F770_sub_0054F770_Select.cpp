#define N0 0
#define N1 1
#define N2 2
#define N3 3
#define N4 4
#define N5 5
#define N8 8
#define N10 10
#define N12 12
#define N16 16
#define N18 18
#define N20 20
#define N30 30
#define N32 32
#define N59 59
#define N84 84
#define N100 100
#define N108 108
#define N148 148
#define N180 180
#define N196 196
#define N573 573
#define N716 716
#define NNEG1 -1
#define NRNG 0x6ac690c5u
typedef unsigned int U32;
struct Game;
struct Seed
{
    U32 lo;
    U32 hi;
};
struct ObjectData
{
    U32 unused;
    unsigned char interact;
};
struct Path
{
    U32 unused0;
    U32 unused4;
    U32 unused8;
    int x;
    int y;
};
struct Unit
{
    int type;
    int classId;
    void* pool;
    int id;
    int mode;
    ObjectData* data;
    char reserved24[N20];
    Path* path;
    char reserved48[N148];
    U32 flags;
};
struct Room
{
    char reserved0[N108];
    Seed seed;
};
struct RoomBounds
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};
struct ObjectRecord
{
    char reserved0[N196];
    unsigned char collisions[N12];
    int sizeX;
    int sizeY;
    char reserved216[N100];
    unsigned char placement;
    char reserved317[N59];
    int selection;
    int subclass;
};
struct ShrineRecord
{
    char reserved0[N180];
    U32 minimumLevel;
};
struct ShrineLists
{
    int counts[N8];
    int* lists[N8];
};
struct InitContext
{
    Game* game;
    Unit* object;
    Room* room;
    Seed* control;
    ObjectRecord* record;
    int x;
    int y;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
Seed* __fastcall sub_00546FA0_Control(Game*,Room*); // 0x00546FA0
ShrineLists* __fastcall sub_00546FB0_Lists(Game*); // 0x00546FB0
unsigned char __fastcall sub_00547330_Force(Game*,int); // 0x00547330
unsigned char __fastcall sub_00547360_Limit(Game*,int); // 0x00547360
void __fastcall sub_00547390_Increment(Game*,int); // 0x00547390
unsigned char __fastcall sub_00547430_Permit(Game*,int,int,int); // 0x00547430
void __fastcall sub_00547490_Add(Game*,int,int,int); // 0x00547490
typedef unsigned char (__fastcall *Permit)(Game*,int,int,int);
Unit* __stdcall sub_00550A30_Spawn(Game*,int,int,int,Room*,int,int,Permit); // 0x00550A30
void __stdcall sub_00619730_Bounds(Room*,RoomBounds*); // 0x00619730
U32 __stdcall sub_0061A1B0_Level(Room*); // 0x0061A1B0
int __stdcall sub_0061A1F0_Region(Room*); // 0x0061A1F0
void __stdcall sub_00621BB0_SetShrine(Unit*,ShrineRecord*); // 0x00621BB0
ObjectRecord* __stdcall sub_00640E90_ObjectRecord(int); // 0x00640E90
ShrineRecord* __stdcall sub_006414B0_ShrineRecord(int); // 0x006414B0
int __cdecl sub_00641500_ShrineCount(); // 0x00641500
int __stdcall sub_006488C0_PathX(Path*); // 0x006488C0
int __stdcall sub_00648900_PathY(Path*); // 0x00648900
static __forceinline U32 Roll(Seed* seed)
{
    unsigned __int64 value = (unsigned __int64)seed->hi + (unsigned __int64)seed->lo * NRNG;
    seed->hi = (U32)(value >> N32);
    seed->lo = (U32)value;
    return (U32)value;
}
static __forceinline U32 Limited(Seed* seed,int maximum)
{
    if (maximum <= N0)
        return N0;
    if (maximum & (maximum - N1))
        return Roll(seed) % maximum;
    return Roll(seed) & (maximum - N1);
}
// 0x0054F770
static __declspec(noinline) int __stdcall sub_0054F770_Select(Game* game,U32 level,Room* room,unsigned char category)
{
    if (!category || category > N4)
        category = N2;
    ShrineLists* lists = sub_00546FB0_Lists(game);
    if (lists->counts[category])
    {
        int retries = N8;
        int choice;
        do
        {
            int count = lists->counts[category];
            Seed* seed = sub_00546FA0_Control(game,room);
            U32 index = Limited(seed,count);
            choice = lists->lists[category][index];
            if (!choice)
                choice = N1;
            if (level >= sub_006414B0_ShrineRecord(choice)->minimumLevel)
                break;
            --retries;
        } while (retries > N0);
        return choice;
    }
    sub_00408A60(&gszEmptyAssertText,sub_00408090(),N716);
    exit(NNEG1);
}
// 0x0054F9D0
void __fastcall sub_0054F9D0_Initialize(InitContext* context)
{
    int mode = context->record->selection;
    U32 level = sub_0061A1B0_Level(context->room);
    int choice;
    if (mode)
    {
        int category;
        switch (mode)
        {
        case N1: category = N2; break;
        case N2: category = N3; break;
        default:
            category = N4;
            if (!(Roll(context->control) % N10))
                category = N1;
            break;
        }
        choice = sub_0054F770_Select(context->game,level,context->room,(unsigned char)category);
    }
    else
    {
        int retries = N8;
        const U32 randomLevel = sub_0061A1B0_Level(context->room);
        do
        {
            int count = sub_00641500_ShrineCount() - N1;
            choice = Limited(context->control,count) + N1;
            if (randomLevel >= sub_006414B0_ShrineRecord(choice)->minimumLevel)
                break;
            --retries;
        } while (retries > N0);
    }
    if (choice == N5)
        choice = N3;
    else if (choice == N4)
        choice = N2;
    else if (choice == N16)
        choice = N18;
    context->object->data->interact = (unsigned char)choice;
    sub_00621BB0_SetShrine(context->object,sub_006414B0_ShrineRecord(choice));
}
// 0x00552AC0
static __declspec(noinline) void __cdecl sub_00552AC0_Class(Unit* unit)
{
    int id;
    if (!unit)
        id = NNEG1;
    else
        id = unit->classId;
    int replacement = sub_00640E90_ObjectRecord(id)->subclass;
    int classId = N84;
    if (replacement && replacement < N573)
        classId = replacement;
    unit->classId = classId;
}

static __forceinline int CoordinateX(Unit* object)
{
    if (object->type == N2 || (object->type > N3 && object->type <= N5))
        return object->path->x;
    if (object->path)
        return sub_006488C0_PathX(object->path);
    return N0;
}
static __forceinline int CoordinateY(Unit* object)
{
    if (object->type == N2 || (object->type > N3 && object->type <= N5))
        return object->path->y;
    if (object->path)
        return sub_00648900_PathY(object->path);
    return N0;
}

Unit* __fastcall sub_00552B50_Create(Game* game,Room* room,int unusedGroup,int classId,unsigned short probability)
{
    ObjectRecord* record = sub_00640E90_ObjectRecord(classId);
    int sizeX = record->sizeX;
    int sizeY = record->sizeY;
    RoomBounds bounds;
    sub_00619730_Bounds(room,&bounds);
    int region = sub_0061A1F0_Region(room);
    Seed* seed = room ? &room->seed : N0;
    U32 roll = Roll(seed);
    unsigned char forced = N0;
    int retries = N3;
    if (sub_00547330_Force(game,region))
    {
        forced = N1;
        retries = N30;
    }
    else if (roll % N100 > probability)
        return N0;
    if (sub_00547360_Limit(game,region))
        return N0;
    while (retries > N0)
    {
        Unit* object = sub_00550A30_Spawn(game,classId,sizeX,sizeY,room,record->placement,region,sub_00547430_Permit);
        if (object)
        {
            if (record->collisions[object->mode])
                object->flags |= N2;
            else
                object->flags &= ~N2;
            if (object->data->interact == N2)
                sub_00547390_Increment(game,region);
            else if (forced)
            {
                sub_00552AC0_Class(object);
                sub_0054F770_Select(game,N1,room,N2);
                object->data->interact = N2;
                sub_00621BB0_SetShrine(object,sub_006414B0_ShrineRecord(N2));
                sub_00547390_Increment(game,region);
            }
            sub_00547490_Add(game,region,CoordinateX(object),CoordinateY(object));
            return object;
        }
        --retries;
    }
    return N0;
}
