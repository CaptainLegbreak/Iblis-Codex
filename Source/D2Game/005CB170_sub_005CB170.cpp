struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x0C];
    unsigned int dwSeqSpeed;
    char unk0x40[0x84];
    unsigned int dwFlags;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648780
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

struct Game;
int __fastcall sub_00554EA0(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int);  // 0x00554EA0
void __stdcall sub_0064EA90(D2ActiveRoomStrc*,int,int,int,unsigned short);  // 0x0064EA90
enum { UNIT_FLAGS = 0xE };
// 0x005CB170
int __fastcall sub_005CB170(Game* game,D2UnitStrc* unit,int skillId,int level)
{
    if(!sub_00554EA0(game,unit,UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),0,0)) return 0;
    unit->dwFlags |= UNIT_FLAGS;
    sub_0064EA90(UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),1,0x1000);
    return 1;
}
