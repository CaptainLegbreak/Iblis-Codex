struct Seed { unsigned int low,high; };
struct Path;
struct StaticPath { char unknown00[12]; int x,y; };
struct Unit { int type; char unknown04[28]; Seed seed; int unknown28; union { Path* path; StaticPath* staticPath; }; };
struct Game { char unknown00[0x6D]; unsigned char difficulty; };
struct MonStats { char unknown00[0x56]; short param[8][3]; };
struct AiControl { char unknown00[0x14]; int param[3]; };
struct Tick { AiControl* control; int unknown04; Unit* target; int unknown0C[2]; int distance,combat; MonStats* stats; };
struct Room;
struct Coord { int x,y; };

struct TargetSearch { Unit* target; int classId; int range; int unk0C[7]; };
typedef Unit* (__fastcall* TargetCallback)(Game*,Unit*,Unit*,void*);
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*,int); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(Seed*,int); // 0x0045C3E0
int __fastcall sub_00472210_SeedRollMasked(Seed*,int); // 0x00472210
Unit* __fastcall AIGENERAL_GetMinionOwner(Unit*); // 0x0058F0D0
int __fastcall AITHINK_GetSquaredDistance(Unit*,Unit*); // 0x005B0BD0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(Unit*,int,int); // 0x005DC5C0
Unit* __fastcall sub_6FCF1E80(Game*,Unit*,void*,TargetCallback,int); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(Game*,Unit*,int,Unit*); // 0x005DDF90
void __fastcall AITACTICS_Idle(Game*,Unit*,int); // 0x005DE0F0
void __fastcall AITACTICS_SetVelocity(Unit*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(Game*,Unit*,int,int,int); // 0x005DE440
int __fastcall sub_005DE4E0_MoveAwayFromTarget(Game*,Unit*,Unit*,int,int,int); // 0x005DE4E0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(Game*,Unit*,Unit*,int,int); // 0x005DE6D0
int __fastcall sub_005DF7D0(Game*,Unit*,Unit*,int,int); // 0x005DF7D0
void __fastcall sub_005F2EB0_RemoveGroundCollision(Game*,Unit*); // 0x005F2EB0
int __fastcall AITHINK_TryRestoreGroundCollision(Game*,Unit*); // 0x005F2FC0
Unit* __fastcall sub_005F30F0_SearchCallback(Game*,Unit*,Unit*,void*); // 0x005F30F0
int __stdcall UNITS_GetUnitSizeX(Unit*); // 0x00620510
Room* __stdcall UNITS_GetRoom(Unit*); // 0x00620BB0
int __stdcall PATH_GetXPosition(Path*); // 0x006488C0
int __stdcall PATH_GetYPosition(Path*); // 0x00648900
Room* __stdcall COLLISION_GetFreeCoordinates(Room*,Coord*,int,unsigned int,int); // 0x0064E7B0
// build: context GetX
static __forceinline int GetX(Unit* unit) {
    switch(unit->type) { case 2: case 4: case 5: return unit->staticPath->x;
    default: return unit->path ? PATH_GetXPosition(unit->path):0; }
}
// build: context GetY
static __forceinline int GetY(Unit* unit) {
    switch(unit->type) { case 2: case 4: case 5: return unit->staticPath->y;
    default: return unit->path ? PATH_GetYPosition(unit->path):0; }
}
// build: context SEED_RollRandomNumber
inline unsigned __int64 SEED_RollRandomNumber(Seed* seed) {
    const unsigned __int64 value=seed->high+0x6AC690C5i64*seed->low;
    seed->high=(unsigned int)(value>>32);seed->low=(unsigned int)value;return value;
}
#define PARAM(n) (stats->param[n][game->difficulty])
// 0x005F3170
void __fastcall sub_005F3170_GroundCollisionAi(Game* game,Unit* unit,Tick* tick)
{
    const int distance=tick->distance;
    const int combat=tick->combat;
    Unit* target=tick->target;
    MonStats* stats=tick->stats;
    AiControl* control=tick->control;
    Seed* seed=&unit->seed;
    int state=control->param[0];
    if (!target) {
        if(state<1) { AITACTICS_Idle(game,unit,12); return; }
        if(AITHINK_TryRestoreGroundCollision(game,unit)) {
            sub_005DE4E0_MoveAwayFromTarget(game,unit,unit,9,2,3);
            AITACTICS_Idle(game,unit,12);
            control->param[0]=-1;
            return;
        }
    }
    int far=AITHINK_GetSquaredDistance(unit,target)>144;
    if (target) {
        if(UNITS_GetRoom(target)!=UNITS_GetRoom(unit) && far) {
            if(state>=1) {
                if(AITHINK_TryRestoreGroundCollision(game,unit)) {
                    sub_005DE4E0_MoveAwayFromTarget(game,unit,unit,9,2,3);
                    AITACTICS_Idle(game,unit,12);
                    control->param[0]=-1;
                    return;
                }
            }
            else { D2GAME_AICORE_Escape_6FCD0560(game,unit,target,9,0); return; }
        }
    }
    if(!state && !AIGENERAL_GetMinionOwner(unit) && target && far && (int)SEED_RollLimitedRandomNumber(seed,100)<60) {
        sub_005F2EB0_RemoveGroundCollision(game,unit);
        control->param[0]=sub_00472210_SeedRollMasked(seed,8)+24;
        sub_005DE4E0_MoveAwayFromTarget(game,unit,target,8,8,8);
        AITACTICS_Idle(game,unit,12);
        return;
    }
    TargetSearch search;
    search.target=0;
    search.classId=121;
    search.range=PARAM(2);
    sub_6FCF1E80(game,unit,&search,sub_005F30F0_SearchCallback,1);
    if(state>1) {
        if(search.target) goto SUCCESS;
        if(distance<6 && (int)SEED_RollLimitedRandomNumber(seed,100)<15) {
SUCCESS:
            control->param[0]=1;
            state=1;
            goto RESTORE_TARGET;
        }
        else {
            sub_005F2EB0_RemoveGroundCollision(game,unit);
            int x=GetX(unit);
            int y=GetY(unit);
            if(control->param[1] && control->param[2] && AIUTIL_GetDistanceToCoordinates(unit,control->param[1],control->param[2])>1) {
                Coord coord;
                coord.x=control->param[1]; coord.y=control->param[2];
                if(target && COLLISION_GetFreeCoordinates(UNITS_GetRoom(target),&coord,UNITS_GetUnitSizeX(unit),0xFFFF,1)) {
                    control->param[1]=coord.x;control->param[2]=coord.y;
                }
                else if(COLLISION_GetFreeCoordinates(UNITS_GetRoom(unit),&coord,UNITS_GetUnitSizeX(unit),0xFFFF,1)) {
                    control->param[1]=coord.x;control->param[2]=coord.y;
                }
                --control->param[0];
                AITACTICS_SetVelocity(unit,7,0,0);
                AITACTICS_ChangeModeAndTargetCoordinatesOneStep(game,unit,control->param[1],control->param[2],8);
                AITACTICS_Idle(game,unit,12);
                return;
            }
            int radius=state+8;
            int targetX=GetX(target);
            int moveX=targetX-radius+ITEMS_RollLimitedRandomNumber(seed,2*radius);
            int targetY=GetY(target);
            int moveY=targetY-radius+ITEMS_RollLimitedRandomNumber(seed,2*radius);
            int threshold=radius<<1;
            if(threshold<12) threshold=12;
            else if(threshold>36) threshold=36;
            while((int)AIUTIL_GetDistanceToCoordinates(unit,moveX,moveY)<threshold) {
                if(moveX<x) --moveX; else if(moveX>x) ++moveX;
                if(moveY<y) --moveY; else if(moveY>y) ++moveY;
                if(moveX==x && moveY==y) { ++moveX;++moveY; }
            }
            control->param[1]=moveX;control->param[2]=moveY;
            AITACTICS_SetVelocity(unit,1,0,0);
            AITACTICS_ChangeModeAndTargetCoordinatesOneStep(game,unit,moveX,moveY,8);
            AITACTICS_Idle(game,unit,12);
            --control->param[0];
            return;
        }
    }
    else if(state>=1) {
RESTORE_TARGET:
        if(AITHINK_TryRestoreGroundCollision(game,unit)) {
            sub_005DE4E0_MoveAwayFromTarget(game,unit,target,9,2,3);
            AITACTICS_Idle(game,unit,12);
            control->param[0]=-1;
            return;
        }
        control->param[0]=8;
        AITACTICS_Idle(game,unit,12);
    }
    if(combat) {
        if((int)((unsigned int)SEED_RollRandomNumber(seed)%100)<PARAM(0)) AITACTICS_ChangeModeAndTargetUnit(game,unit,4,target);
        else AITACTICS_Idle(game,unit,PARAM(1));
        return;
    }
    if(state!=-1) {
        const int difficulty=game->difficulty;
        if((int)SEED_RollLimitedRandomNumber(seed,100)>=stats->param[4][difficulty]) {
            AITACTICS_Idle(game,unit,stats->param[1][difficulty]);
            return;
        }
    }
    if((int)SEED_RollLimitedRandomNumber(seed,100)<PARAM(3)) sub_005DF7D0(game,unit,target,6,0);
    else D2GAME_AICORE_Escape_6FCD0560(game,unit,target,9,0);
    control->param[0]=0;
    AITACTICS_Idle(game,unit,12);
}
