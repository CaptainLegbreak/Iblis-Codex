struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620
static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetXPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case 2:
    case 4:
    case 5:
        nResult = pUnit->pStaticPath->nXPos;
        break;
    }
    return nResult;
}
static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetYPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case 2:
    case 4:
    case 5:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    }
    return nResult;
}
// 0x0046B850
void __fastcall sub_0046B850_SpawnMissileAtObject182(D2UnitStrc* unit)
{
 D2UnitStrc* object=UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(unit),2,0x182);
 int x,y;
 if(object) {
  sub_004DCD40_ShowTimedHint((void*)0x124F,0,0x15E,0,0,0,0);
  x=CLIENTS_GetUnitXInline(object);
  y=CLIENTS_GetUnitYInline(object);
 } else {
  x=CLIENTS_GetUnitXInline(unit)-15;
  y=CLIENTS_GetUnitYInline(unit)-15;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.dwFlags=0x420;
 params.nMissile=0x170;
 params.pOwner=unit;
 params.pOrigin=unit;
 params.nTargetX=x;
 params.nTargetY=y;
 params.nSkillLevel=1;
 D2UnitStrc* missile=sub_004CD540_CreateMissile(&params);
 if(missile&&object)MISSILE_SetTargetX(missile,object->dwUnitId);
}
