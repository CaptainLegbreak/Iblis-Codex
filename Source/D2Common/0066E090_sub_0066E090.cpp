struct Tile { char pad0[0x20]; Tile* next; char f_24[0xC]; };
struct T0066E090 { char pad0[0x10]; int count; char pad14[0x10]; Tile* tiles; int capacity; };
struct Drlg { char pad0[0x478]; void* pool; };
struct Level { char pad0[0x1B4]; Drlg* drlg; };
struct Room { char pad0[0x54]; T0066E090* grid; Level* level; };
void __fastcall sub_0040B480(void*,void*,const char*,int,int);  // 0x0040B480
void* __fastcall sub_0040B4B0(void*,void*,int,const char*,int,int);  // 0x0040B4B0
// 0x0066E090
void __fastcall sub_0066E090(Room* room)
{
    void* pool=room->level->drlg->pool;
    T0066E090* grid=room->grid;
    if(!grid->count)
    {
        if(grid->tiles) sub_0040B480(pool,grid->tiles,".\\DRLG\\RoomTile.cpp",0x257,0);
        grid->tiles=0;
        return;
    }
    if(grid->capacity>grid->count)
    {
        grid->tiles=(Tile*)sub_0040B4B0(pool,grid->tiles,grid->count*sizeof(Tile),".\\DRLG\\RoomTile.cpp",0x25F,0);
        int i;
        const int& nCount=grid->count;
        for(i=0;i<nCount-1;++i) grid->tiles[i].next=&grid->tiles[i+1];
        grid->tiles[i].next=0;
        grid->capacity=grid->count;
    }
}
