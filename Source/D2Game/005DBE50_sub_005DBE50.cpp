struct D2GameStrc; struct D2DynamicPathStrc;
struct D2StaticPathStrc { int unknown[3]; int nXPos,nYPos; };
struct D2UnitStrc { int dwUnitType; char pad4[8]; int dwUnitId; char pad10[0x1C]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; }; };
struct Skills { char pad0[0x138]; unsigned rangeCalc,durationCalc; char pad140[0xFC]; };
struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };
extern Tables* tables;  // 0x00744304
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*);  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*);  // 0x00648900
typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);
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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};
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

D2UnitStrc* __stdcall sub_00553540(D2GameStrc*,D2UnitStrc*);  // 0x00553540
void __fastcall sub_0057D4F0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int);  // 0x0057D4F0
int __stdcall sub_00646CA0(D2UnitStrc*,unsigned,int,int);  // 0x00646CA0
D2UnitStrc* __fastcall sub_0056BD10(D2GameStrc*,D2UnitStrc*,int,int,int,unsigned,int,int*);  // 0x0056BD10
int __fastcall sub_005D3CF0(D2UnitStrc*,int);  // 0x005D3CF0
extern "C" void* __cdecl memset(void*,int,unsigned);
int __fastcall sub_0045ADF0(D2UnitStrc*);  // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc*);  // 0x0045AE20
D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc*,D2MissileStrc*);  // 0x0059FA30
void __stdcall sub_0064A710(D2UnitStrc*,int);  // 0x0064A710
inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}
enum { MISSILE_FLAGS = 0x20 };
// 0x005DBE50
int __fastcall sub_005DBE50(D2GameStrc* game,D2UnitStrc* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    D2UnitStrc* target=sub_00553540(game,unit);
    if(!target) return 0;
    sub_0057D4F0(game,unit,target,0);
    int range=sub_00646CA0(unit,record->rangeCalc,skillId,level);
    const int targetId=target->dwUnitId;
    D2UnitStrc* other=sub_0056BD10(game,unit,UNITS_GetUnitXPosition(target),UNITS_GetUnitYPosition(target),range,3,targetId,0);
    if(!other) return 0;
    int missileId=sub_005D3CF0(unit,skillId);
    if(missileId<0 || missileId>=tables->missileCount) return 0;
    int duration=sub_00646CA0(unit,record->durationCalc,skillId,level);
    D2MissileStrc params;
    memset(&params,0,sizeof(params));
    params.dwFlags=MISSILE_FLAGS;
    params.pOwner=unit;
    params.pOrigin=target;
    params.nSkill=skillId;
    params.nSkillLevel=level;
    params.nMissile=missileId;
    params.nTargetX=sub_0045ADF0(other);
    params.nTargetY=sub_0045AE20(other);
    D2UnitStrc* missile=sub_0059FA30(game,&params);
    if(missile) sub_0064A710(missile,duration);
    return 1;
}
