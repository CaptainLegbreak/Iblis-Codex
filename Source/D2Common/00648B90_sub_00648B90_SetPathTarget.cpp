typedef unsigned char U8;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct B25TargetUnit
{
    unsigned int type;
    U8 pad4[0x8];
    unsigned int id;
};
struct B25Path
{
    U8 pad0[0x58];
    B25TargetUnit* target;
    unsigned int targetType;
    unsigned int targetId;
};
struct B25DistancePath
{
    U8 pad0[0x90];
    U8 distance;
    U8 newDistance;
};
struct B25MissileData
{
    U8 pad0[0x28];
    int targetStatus;
};
struct B25MissileUnit
{
    unsigned int type;
    U8 pad4[0x10];
    B25MissileData* data;
};
typedef char CheckTargetUnitid[(OFFSET(B25TargetUnit,id)==0xC)?1:-1];
typedef char CheckPathtarget[(OFFSET(B25Path,target)==0x58)?1:-1];
typedef char CheckPathtargetType[(OFFSET(B25Path,targetType)==0x5C)?1:-1];
typedef char CheckPathtargetId[(OFFSET(B25Path,targetId)==0x60)?1:-1];
typedef char CheckDistancePathdistance[(OFFSET(B25DistancePath,distance)==0x90)?1:-1];
typedef char CheckDistancePathnewDistance[(OFFSET(B25DistancePath,newDistance)==0x91)?1:-1];
typedef char CheckMissileDatatargetStatus[(OFFSET(B25MissileData,targetStatus)==0x28)?1:-1];
typedef char CheckMissileUnitdata[(OFFSET(B25MissileUnit,data)==0x14)?1:-1];

// 0x00648B90
extern "C" void __stdcall sub_00648B90_SetPathTarget(B25Path* path, B25TargetUnit* target)
{
    path->target = target;
    if (target)
    {
        path->targetType = target->type;
        path->targetId = target->id;
    }
}

// 0x00648E70
extern "C" void __stdcall sub_00648E70_SetDistance(B25DistancePath* path, U8 distance)
{
    if (path)
    {
        if (distance >= 0x4D)
            distance = 0x4D;
        path->newDistance = distance;
        path->distance = distance;
    }
}

// 0x0064A730
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(B25MissileUnit* unit)
{
    if (unit && unit->type == 3 && unit->data)
        return unit->data->targetStatus;
    return 0;
}
