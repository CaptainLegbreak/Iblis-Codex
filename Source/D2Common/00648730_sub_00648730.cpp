typedef unsigned char U8;
typedef unsigned int U32;
struct ActiveRoom;
struct T00648730
{
    char retainedPrefix[0x1c];
    T00648730* statusNext;
    char retainedMiddle[0x10];
    ActiveRoom* activeRoom;
    char retainedBeforeStatus[0x10];
    U8 status;
    char retainedTail[0xA7];
};
struct DrlgView
{
    char retainedPrefix[0xa0];
    T00648730 statusRooms[4];
};
struct PathView
{
    char retainedPrefix[0x28];
    int pointCount;
    char retainedGap[8];
    U32 flags;
    char retainedBeforePattern[0x10];
    int collisionPattern;
};
struct UnitView
{
    char retainedPrefix[0x2c];
    PathView* path;
};
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_room_next[OFFSET(T00648730,statusNext)==0x1c?1:-1];
typedef char check_room_active[OFFSET(T00648730,activeRoom)==0x30?1:-1];
typedef char check_room_status[OFFSET(T00648730,status)==0x44?1:-1];
typedef char check_room_stride[sizeof(T00648730)==0xec?1:-1];
typedef char check_room_array[OFFSET(DrlgView,statusRooms)==0xa0?1:-1];
typedef char check_first_head[OFFSET(DrlgView,statusRooms)+OFFSET(T00648730,statusNext)==0xbc?1:-1];
typedef char check_second_sentinel[OFFSET(DrlgView,statusRooms)+sizeof(T00648730)==0x18c?1:-1];
typedef char check_second_head[OFFSET(DrlgView,statusRooms)+sizeof(T00648730)+OFFSET(T00648730,statusNext)==0x1a8?1:-1];
typedef char check_path_count[OFFSET(PathView,pointCount)==0x28?1:-1];
typedef char check_path_flags[OFFSET(PathView,flags)==0x34?1:-1];
typedef char check_path_pattern[OFFSET(PathView,collisionPattern)==0x48?1:-1];
typedef char check_unit_path[OFFSET(UnitView,path)==0x2c?1:-1];

extern "C" ActiveRoom* __fastcall DRLGACTIVATE_GetARoomInClientSight(DrlgView* drlg)
{
    T00648730* room = drlg->statusRooms[0].statusNext;
    if (room == &drlg->statusRooms[0] || !room)
    {
        room = drlg->statusRooms[1].statusNext;
        if (room == &drlg->statusRooms[1] || !room)
            return 0;
    }
    return room->activeRoom;
}

// 0x00648730
extern "C" void __stdcall sub_00648730(PathView* path)
{
    path->flags &= 0xffffffdf;
    path->pointCount = 0x0;
}

// 0x00649190
extern "C" void __stdcall PATH_SetUnitCollisionPattern(UnitView* unit,int collisionPattern)
{
    unit->path->collisionPattern = collisionPattern;
}
