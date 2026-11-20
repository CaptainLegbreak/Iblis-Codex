#include "D2Game.h"
#include "D2Structs.h"

struct D2CoordStrc { int x; int y; };
struct D2MonsterDataStrc { int unk00[12]; void* interact; };
struct D2QuestExStrc {
    char unk00[12]; unsigned char oldSpawned; unsigned char spawned;
    char unk0E[7]; unsigned char coordinatesSet; char unk16[18];
    int x; int y; int unk30[3]; int unitId;
};
struct D2QuestDataStrc {
    int id; D2GameStrc* game; unsigned char act; unsigned char notIntro;
    unsigned char active; unsigned char lastState; unsigned char state;
    char unk0D[11]; D2QuestExStrc* ex;
};
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(void*); // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc*,D2UnitStrc*,void*,int); // 0x00573180
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*,int); // 0x00543640
D2ActiveRoomStrc* __fastcall sub_00463740(D2ActiveRoomStrc*,int,int); // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc*,D2CoordStrc*,unsigned int,unsigned int,D2ActiveRoomStrc**,int,int); // 0x00545340
D2UnitStrc* __fastcall sub_005B2F20(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005B2F20
static __forceinline void* GetMonsterInteract(D2UnitStrc* unit) {
    if (unit && unit->dwUnitType==1 && unit->pMonsterData) return unit->pMonsterData->interact;
    return 0;
}
static __declspec(noinline)
// 0x0059EF70
void __stdcall sub_0059EF70_SpawnQuestNpc(D2QuestDataStrc* quest,D2CoordStrc* coords,D2ActiveRoomStrc* room) {
    D2QuestExStrc* ex=quest->ex;
    if (ex->oldSpawned==1) {
        D2UnitStrc* unit=SUNIT_GetServerUnit(quest->game,1,ex->unitId);
        if (unit) {
            void* interact=GetMonsterInteract(unit);
            if (MONSTERAI_HasInteractUnit(interact)) {
                sub_00573180(quest->game,unit,0,1);
                return;
            }
            sub_0052E050_RemoveUnit(unit,quest->game);
            ex->oldSpawned=0;
        }
    }
    if (ex->spawned==1) return;
    D2QuestDataStrc* other=QUESTS_GetQuestData(quest->game,13);
    int bDone=1;
    if (other && other->notIntro && other->state < 2) bDone=0;
    if (bDone) coords->x+=15;
    else coords->x-=10;
    coords->y-=3;
    D2ActiveRoomStrc* found=sub_00463740(room,coords->x,coords->y);
    QUESTS_GetFreePosition(room,coords,3,0x100,&found,9,100);
    D2UnitStrc* npc=sub_005B2F20(quest->game,found,coords->x,coords->y,201,1,-1,0);
    if (!npc) npc=sub_005B2F20(quest->game,found,coords->x,coords->y,201,1,2,0);
    if (npc) {
        npc->dwFlags|=0x03000000;
        ex=quest->ex;
        ex->spawned=1;
        if (!ex->coordinatesSet) {
            ex->coordinatesSet=1;
            ex->x=coords->x;
            ex->y=coords->y;
        }
    }
}
void __stdcall EmitQuestNpc(D2QuestDataStrc* quest,D2CoordStrc* coords,D2ActiveRoomStrc* room) {
    sub_0059EF70_SpawnQuestNpc(quest,coords+1,room);
}
