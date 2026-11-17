struct D2GameStrc { char unk00[0xA8]; int dwGameFrame; };
struct D2ActiveRoomStrc;
struct D2CoordStrc { int x; int y; };
struct D2MonsterDataStrc { int unk00[12]; void* interact; };
struct D2UnitStrc { int type; int classId; int pool; int id; int mode; D2MonsterDataStrc* monster; int unk18[43]; unsigned int flags; };
struct D2QuestExStrc {
    char unk00[12]; unsigned char oldSpawned; unsigned char spawned;
    char unk0E[7]; unsigned char coordinatesSet; char unk16[18];
    int x; int y; int guardX; int guardY; int blockerId; int unitId;
};
struct D2QuestDataStrc {
    int id; D2GameStrc* game; unsigned char act; unsigned char notIntro;
    unsigned char active; unsigned char lastState; unsigned char state;
    char unk0D[11]; D2QuestExStrc* ex;
};
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(void*); // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc*,D2UnitStrc*,void*,int); // 0x00573180
void __fastcall sub_0052E050_RemoveUnit(D2UnitStrc*,D2GameStrc*); // 0x0052E050
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*,int); // 0x00543640
D2ActiveRoomStrc* __fastcall sub_00463740(D2ActiveRoomStrc*,int,int); // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc*,D2CoordStrc*,unsigned int,unsigned int,D2ActiveRoomStrc**,int,int); // 0x00545340
D2UnitStrc* __fastcall sub_005B2F20(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005B2F20
static __forceinline void* GetMonsterInteract(D2UnitStrc* unit) {
    if (unit && unit->type==1 && unit->monster) return unit->monster->interact;
    return 0;
}
static __declspec(noinline)
// 0x0059EF70
void __stdcall sub_0059EF70_SpawnQuestNpc(D2QuestDataStrc* quest,D2ActiveRoomStrc* room,D2CoordStrc* coords) {
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
        npc->flags|=0x03000000;
        ex=quest->ex;
        ex->spawned=1;
        if (!ex->coordinatesSet) {
            ex->coordinatesSet=1;
            ex->x=coords->x;
            ex->y=coords->y;
        }
    }
}

struct D2ObjInitFnStrc {
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    int unk0C[2];
    int nX;
    int nY;
};
int __fastcall QUESTS_GetGlobalState(D2GameStrc*, int, int); // 0x00544760
D2UnitStrc* __fastcall sub_005B3090_SpawnAtPosition(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int); // 0x005B3090
void __fastcall sub_005417D0_DirectDated(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0

// 0x0059F440
void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2QuestExStrc* pQuestDataEx = pQuestData->ex;
    if (QUESTS_GetGlobalState((!pQuestData ? 0 : pQuestData->game), 14, 13) != 1)
    {
        D2ActiveRoomStrc* pRoom = pOp->pRoom;
        pQuestDataEx->guardX = pOp->nX + 1;
        pQuestDataEx->guardY = pOp->nY;
        sub_005B3090_SpawnAtPosition((pQuestData ? pQuestData->game : 0), pRoom, pQuestDataEx->guardX, pQuestDataEx->guardY, 331, 1, 0);
    }
    sub_005417D0_DirectDated(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 1, 0, 0);
    D2CoordStrc pCoord;
    pCoord.x = pOp->nX;
    pCoord.y = pOp->nY;
    if (pQuestDataEx->spawned) return;
    if (!QUESTS_GetGlobalState((pQuestData ? pQuestData->game : 0), 8, 13) && !QUESTS_GetGlobalState((pQuestData ? pQuestData->game : 0), 9, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData((pQuestData ? pQuestData->game : 0), 13);
        if (pQuest && pQuest->notIntro && pQuest->state < 2) return;
    }
    sub_0059EF70_SpawnQuestNpc(pQuestData, pOp->pRoom, &pCoord);
}
