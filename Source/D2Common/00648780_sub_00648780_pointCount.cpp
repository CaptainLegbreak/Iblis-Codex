struct Room;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
struct View_00648780
{
    char gap[0x28];
    int pointCount;
};
typedef char check_offset_00648780[OFFSET(View_00648780,pointCount)==0x28?1:-1];
typedef char check_size_00648780[sizeof(View_00648780)==0x2C?1:-1];
struct View_006489C0
{
    char gap[0x8];
    int clientX;
};
typedef char check_offset_006489C0[OFFSET(View_006489C0,clientX)==0x8?1:-1];
typedef char check_size_006489C0[sizeof(View_006489C0)==0xC?1:-1];
struct View_00648AA0
{
    char gap[0x20];
    Room* previousRoom;
};
typedef char check_offset_00648AA0[OFFSET(View_00648AA0,previousRoom)==0x20?1:-1];
typedef char check_size_00648AA0[sizeof(View_00648AA0)==0x24?1:-1];
struct View_00648700
{
    char gap[0x88];
    int acceleration;
};
typedef char check_offset_00648700[OFFSET(View_00648700,acceleration)==0x88?1:-1];
typedef char check_size_00648700[sizeof(View_00648700)==0x8C?1:-1];

// 0x00648780
extern "C" int __stdcall sub_00648780_pointCount(View_00648780* path)
{
    return path->pointCount;
}

extern "C" int __stdcall sub_006489C0_clientX(View_006489C0* path)
{
    return path->clientX;
}

// 0x00648AA0
extern "C" Room* __stdcall sub_00648AA0_previousRoom(View_00648AA0* path)
{
    return path->previousRoom;
}

// 0x00648700
extern "C" void __stdcall sub_00648700_acceleration(View_00648700* path, int value)
{
    path->acceleration = value;
}
