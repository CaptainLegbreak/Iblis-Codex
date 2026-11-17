struct Level;
struct Room;
struct Room
{
    char pad_0[36];
    Room* next;
    char pad_28[56];
    unsigned flags;
};
struct Node
{
    char pad_0[12];
    Node* next;
};
struct T00642010
{
    char pad_0[68];
    T00642010* next;
};
struct Level
{
    int kind;
    char pad_4[4];
    int f_8;
    int activeCount;
    Room* rooms;
    char pad_14[24];
    char regionA[384];
    Level* next;
    void* mapData;
    char pad_1B4[8];
    void* allocation;
    char pad_1C0[12];
    Node* nodes;
    char pad_1D0[4];
    int inactiveTicks;
    int state;
    char pad_1DC[4];
    char regionB[76];
    unsigned* savedFlags;
};
struct Dungeon
{
    char pad_0[144];
    T00642010* aux;
    char pad_94[996];
    void* pool;
    Level* levels;
};
extern "C" void* __fastcall sub_0040B430_Allocate(void*, unsigned, const char*, int, int); // 0x0040B430
extern "C" int __fastcall sub_0040B480_Free(void*, void*, const char*, int, int); // 0x0040B480
extern "C" void __fastcall sub_0066C100_FreeRoom(Room*); // 0x0066C100
extern "C" void __fastcall sub_006683D0_FreeMap(void*, void*); // 0x006683D0
extern "C" void __fastcall sub_006754C0_ClearType3(Level*, int); // 0x006754C0
extern "C" void __fastcall sub_006674D0_ClearType2(Level*, int); // 0x006674D0
extern "C" void __fastcall sub_00673FE0_ClearType1(Level*, int); // 0x00673FE0
extern "C" int __stdcall sub_00643060_CanFree(Level*); // 0x00643060
extern "C" void* __cdecl memset(void*, int, unsigned); // 0x00681EF0
// 0x00642010
static __declspec(noinline) void __stdcall sub_00642010_ClearLevel(void* pool, int keep, Level* level)
{
    if (keep)
    {
        if (!level->savedFlags)
        {
            if (level->f_8)
                level->savedFlags = (unsigned*)sub_0040B430_Allocate(pool, 4 * level->f_8, ".\\DRLG\\Drlg.cpp", 124, 0);
            else
                level->f_8 = 0;
            memset(level->savedFlags, 0, 4 * level->f_8);
        }
    }
    else if (level->savedFlags)
    {
        sub_0040B480_Free(pool, level->savedFlags, ".\\DRLG\\Drlg.cpp", 132, 0);
        level->savedFlags = 0;
    }
    Room* room = level->rooms;
    if (room)
    {
        int index = 0;
        do
        {
            Room* current = room;
            room = room->next;
            if (level->savedFlags)
                level->savedFlags[index++] = current->flags & 1;
            sub_0066C100_FreeRoom(current);
        } while (room);
        level->rooms = 0;
        level->f_8 = 0;
    }
    if (level->mapData)
    {
        sub_006683D0_FreeMap(pool, level->mapData);
        level->mapData = 0;
    }
    switch (level->kind)
    {
    case 1: sub_00673FE0_ClearType1(level, keep); break;
    case 2: sub_006674D0_ClearType2(level, keep); break;
    case 3: sub_006754C0_ClearType3(level, keep); break;
    }
    memset(level->regionA, 0, 384);
    level->state = 0;
    memset(level->regionB, 0, 76);
    if (!keep && level->allocation)
    {
        sub_0040B480_Free(pool, level->allocation, ".\\DRLG\\Drlg.cpp", 183, 0);
        level->allocation = 0;
    }
    Node* node = level->nodes;
    if (node)
    {
        do
        {
            Node* current = node;
            node = node->next;
            sub_0040B480_Free(pool, current, ".\\DRLG\\Drlg.cpp", 197, 0);
        } while (node);
        level->nodes = 0;
    }
}
// 0x00642190
void __fastcall sub_00642190_FreeDungeon(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    if (level)
    {
        do
        {
            Level* current = level;
            level = level->next;
            sub_00642010_ClearLevel(dungeon->pool, 0, current);
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 221, 0);
        } while (level);
        dungeon->levels = 0;
    }
    T00642010* aux = dungeon->aux;
    if (aux)
    {
        do
        {
            T00642010* current = aux;
            aux = aux->next;
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 236, 0);
        } while (aux);
        dungeon->aux = 0;
    }
    sub_0040B480_Free(dungeon->pool, dungeon, ".\\DRLG\\Drlg.cpp", 242, 0);
}
// 0x00643200
void __fastcall sub_00643200_UpdateInactive(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    void* pool = dungeon->pool;
    while (level)
    {
        if (!level->activeCount && level->rooms)
        {
            if (level->inactiveTicks)
                --level->inactiveTicks;
            else if (sub_00643060_CanFree(level))
                sub_00642010_ClearLevel(pool, 1, level);
            else
                level->inactiveTicks = 10;
        }
        level = level->next;
    }
}
