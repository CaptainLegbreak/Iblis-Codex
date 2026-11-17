typedef unsigned short U16;
typedef unsigned int U32;
struct ActiveRoom;
extern "C" U16 __stdcall COLLISION_CheckMaskWithSize(ActiveRoom* room,int x,int y,int unitSize,U16 mask); // 0x0064D9B0
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_word_width[sizeof(U16)==2?1:-1];
struct PathCollisionView
{
    char retainedGap0[0x2];
    U16 positionX;
    char retainedGap1[0x2];
    U16 positionY;
    char retainedGap2[0x14];
    ActiveRoom* room;
    char retainedGap3[0x24];
    int f_44;
    char retainedGap4[0xC];
    U16 collidedMask;
    char retainedGap5[0x26];
    int velocity;
};
typedef char check_positionX[OFFSET(PathCollisionView,positionX)==0x2?1:-1];
typedef char check_positionY[OFFSET(PathCollisionView,positionY)==0x6?1:-1];
typedef char check_room[OFFSET(PathCollisionView,room)==0x1C?1:-1];
typedef char check_unitSize[OFFSET(PathCollisionView,f_44)==0x44?1:-1];
typedef char check_collidedMask[OFFSET(PathCollisionView,collidedMask)==0x54?1:-1];
typedef char check_velocity[OFFSET(PathCollisionView,velocity)==0x7C?1:-1];

// 0x00648EB0
extern "C" U16 __stdcall sub_00648EB0(PathCollisionView* path)
{
    if (path->velocity == 0)
        path->collidedMask = COLLISION_CheckMaskWithSize(path->room,path->positionX,path->positionY,path->f_44,0x7FFF);
    return path->collidedMask;
}
