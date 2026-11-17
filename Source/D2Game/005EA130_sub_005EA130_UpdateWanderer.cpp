struct D2GameStrc;
struct D2UnitStrc { char unknown[0xC4]; unsigned int flags; };
struct D2CoordStrc { int x; int y; };
struct D2AiControlStrc { char unknown[0x14]; int param[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* control; int unknown04; D2UnitStrc* target; int unknown0C[2]; int distance; };
int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* game,D2UnitStrc* unit,D2CoordStrc* coords); // 0x005BD0D0
void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* game,D2UnitStrc* unit); // 0x005BD4A0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* unit,int x,int y); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* game,D2UnitStrc* unit,int mode,int x,int y); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* game,D2UnitStrc* unit,int frames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* unit,int mode,int velocity,unsigned char flags); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* game,D2UnitStrc* unit,int x,int y); // 0x005DED90
// 0x005EA130
void __fastcall sub_005EA130_UpdateWanderer(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
 D2AiControlStrc* control=tick->control;
 D2UnitStrc* target=tick->target;
 int distance=tick->distance;
 D2CoordStrc coords;
 if(!ACT3Q7_GetWandererCoordinates(game,unit,&coords)) {
  AITACTICS_IdleInNeutralMode(game,unit,10);return;
 }
 if(!control->param[0]) {
  control->param[0]=1;control->param[1]=0;control->param[2]=0;
 }
 if(!target) {AITACTICS_IdleInNeutralMode(game,unit,10);return;}
 if(distance<20) {
  int nState=control->param[0];
  {
  if(nState==1) {
   AITACTICS_WalkToTargetCoordinates(game,unit,coords.x,coords.y);
   control->param[0]=2;return;
  }
  else if(nState==2) {
   if(AIUTIL_GetDistanceToCoordinates(unit,coords.x,coords.y)<2) {
    if(unit) unit->flags|=0x20000;
    AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
    ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
   }
   if(control->param[1]<3) {
    ++control->param[1];
    AITACTICS_SetVelocity(unit,1,0,0);
    AITACTICS_WalkToTargetCoordinates(game,unit,coords.x,coords.y);return;
   }
   if(unit) unit->flags|=0x20000;
   AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
   ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
  }
  else { AITACTICS_IdleInNeutralMode(game,unit,40); return; }
 }
 }
 AITACTICS_IdleInNeutralMode(game,unit,40);
}
