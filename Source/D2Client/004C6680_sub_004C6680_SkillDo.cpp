struct D2DynamicPathStrc;
struct D2CoordStrc { int nX; int nY; };
struct D2StaticPathStrc { void* pRoom; int dwClientCoordX; int dwClientCoordY; D2CoordStrc tGameCoords; };
struct D2UnitStrc { int dwUnitType; char pad04[0x28]; union { D2StaticPathStrc* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; char pad30[0x8];unsigned int frame;char pad3c[0x88];unsigned int flags; };
enum D2C_UnitTypes { UNIT_OBJECT = 2, UNIT_ITEM = 4, UNIT_TILE = 5 };
struct D2SkillsTxt {
 int skillId;unsigned char flags[8];char pad0c[4];unsigned char animation;
 char pad11[0xd7];short clientMissile;char padea[0xa];short clientDo;
 char padf6[0xa];short sound;char pad102[6];short targetOverlay,targetSound;
 char pad10c[0x60];short clientDoSecondary;char pad16e[0x22];unsigned int delay;
 char pad194[0xa8];
};
struct D2DataTablesStrc { char pad00[0xb98];D2SkillsTxt* skills;int unused;int skillCount; };
typedef int (__fastcall* ClientSkillDo)(D2UnitStrc*,int,int);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gnClientDoCount; // 0x00727DB0
extern ClientSkillDo gaClientDo[]; // 0x00727BA8
extern unsigned int gdwBitMasks[]; // 0x006CE268
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit); // 0x00620100
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __fastcall UNITS_GetXPosition(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc*,int,int,int,int,int,int,int,int); // 0x004CDC30
D2UnitStrc* __fastcall sub_004C57B0_FireMissileAtTarget(int,D2UnitStrc*,int,int,int,int,int,int); // 0x004C57B0
void* __stdcall D2Common_10958(D2UnitStrc*,void*); // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(void*); // 0x004743D0
int __fastcall sub_004B9A00(int,D2UnitStrc*,int,int,int); // 0x004B9A00
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc*); // 0x004648F0
void __fastcall sub_00470390_AddOverlay(D2UnitStrc*,int,int,int,int,int,int,int); // 0x00470390
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
unsigned int __cdecl sub_0044DA90_GetTick(); // 0x0044DA90
void __fastcall sub_0044CE40_SetSkillDelay(int); // 0x0044CE40
// 0x004C51E0
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    *pX = aOffsetX[nDirection] + nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    *pY = aOffsetY[nDirection] + nY;
}

// 0x004C52E0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        sub_004C51E0_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

static __forceinline D2SkillsTxt* GetSkillRecord(int id)
{if(id>=0 && id<sgptDataTables->skillCount)return &sgptDataTables->skills[id];return 0;}
// 0x004C6680
int __fastcall sub_004C6680_SkillDo(D2UnitStrc* unit,int skillId,int skillLevel,int mode)
{
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 0;
 if(skill->clientDo<0 || skill->clientDo>=gnClientDoCount)return 0;
 int result=0;
 if(skill->clientMissile>0){
  int x=0,y=0,targetX=0,targetY=0;
  if(mode){
   sub_004C52E0_GetTargetPosition(unit,&x,&y);
   if(x && y){
    targetX=x;targetY=y;
    x-=UNITS_GetXPosition(unit);
    y-=CLIENTS_GetUnitY(unit);
    targetX+=x;targetY+=y;
   }
  }
  D2UnitStrc* missile;
  if(skill->flags[0] & (unsigned char)gdwBitMasks[1])
   missile=sub_004CDC30(unit,skill->clientMissile,x,y,targetX,targetY,skillId,skillLevel,0);
  else missile=sub_004C57B0_FireMissileAtTarget(skill->clientMissile,unit,skillId,skillLevel,x,y,targetX,targetY);
  if(missile)result=1;
  if(unit)unit->flags|=0x40;
 }
 int index=skill->clientDo;
 if(mode && skill->clientDoSecondary>1)index=skill->clientDoSecondary;
 if(index>=0 && index<gnClientDoCount && gaClientDo[index]){
  if(gaClientDo[index](unit,skillId,skillLevel))result=1;
 }else{
  if(unit)unit->flags|=0x40;
  result=1;
 }
 void* resource=D2Common_10958(unit,0);
 if(resource)sub_004743D0_ReleaseOverlayResource(resource);
 if(!result)return 0;
 if(skill->sound>0)sub_004B9A00(skill->sound,unit,0,0,0);
 if(skill->targetSound>0){
  D2UnitStrc* target=sub_004648F0_GetTargetUnit(unit);
  if(target)sub_004B9A00(skill->targetSound,target,0,0,0);
 }
 if(skill->targetOverlay>0){
  D2UnitStrc* target=sub_004648F0_GetTargetUnit(unit);
  if(target)sub_00470390_AddOverlay(target,skill->targetOverlay,2,0,0,0,0,0);
 }
 int delay=SKILLS_EvaluateSkillFormula(unit,skill->delay,skillId,skillLevel);
 if(delay>0 && sub_00463DD0()==unit){
  if(delay>12)delay=12;
  if(skill->animation!=18 || !(unit->frame & 0xffffff00))
   sub_0044CE40_SetSkillDelay(sub_0044DA90_GetTick()+delay);
 }
 return 1;
}
