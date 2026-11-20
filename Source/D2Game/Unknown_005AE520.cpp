#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissilesTxt;
struct D2DataTables;
struct D2SkillsTxt;
struct D2SummonArgs;




struct D2MissilesTxt
{
    char unk00[0x38];
    int dwParam[5];
    unsigned char unk_4C[0x135];
    unsigned char startFrame;
    unsigned char endFrame;
    char tail[0x21];
};

struct D2DataTables { char pad[0xb64]; D2MissilesTxt* missiles; int unknown; int count; };

extern D2DataTables* gpDataTables; // 0x00744304
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc*,D2UnitStrc*); // 0x005AE1F0
int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc*,int); // 0x0045C3E0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064EA00
extern "C" void* __cdecl memset(void*,int,unsigned int);

struct D2SkillsTxt { char unk_00[190]; unsigned char petType; };


struct D2SummonArgs { int mode; D2UnitStrc* owner; int monsterId; int unknown; int variant; int x; int y; int petType; int flags; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*,D2UnitStrc*); // 0x00552FD0
int __stdcall sub_0064A780_GetCount(D2UnitStrc*); // 0x0064A780
int __stdcall sub_006505C0_CheckPath(void*); // 0x006505C0
int __stdcall sub_0064A280_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall sub_0064A210_GetSkillLevel(D2UnitStrc*); // 0x0064A210
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0
int __fastcall sub_0056E620_GetValidMonsterId(D2UnitStrc*,int,int,int,int*,int,int); // 0x0056E620
int __stdcall sub_0064A730_GetUnitId(D2UnitStrc*); // 0x0064A730
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall sub_0056D940_Summon(D2GameStrc*,D2SummonArgs*); // 0x0056D940
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int,int); // 0x005C4470
void __stdcall UNITS_StoreOwner(D2UnitStrc*,D2UnitStrc*); // 0x00621CE0
void __fastcall sub_6FC40280(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990
void __stdcall MISSILE_SetTargetY(D2UnitStrc*,int); // 0x0064A760
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc*); // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc*, int); // 0x0064A710
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc*, int, int); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc*, D2UnitStrc*, int); // 0x00649970

static __forceinline int GetX(D2UnitStrc* p) { switch(p->dwUnitType) {case 2:case 4:case 5:return p->pStaticPath->nXPos;} return p->pDynamicPath?PATH_GetXPosition(p->pDynamicPath):0; }

static __forceinline int GetY(D2UnitStrc* p) { switch(p->dwUnitType) {case 2:case 4:case 5:return p->pStaticPath->nYPos;} return p->pDynamicPath?PATH_GetYPosition(p->pDynamicPath):0; }

// 0x005AE520
int __fastcall sub_005AE520_UpdateMissileFrames(D2GameStrc* game,D2UnitStrc* unit)
{
 D2MissilesTxt* rec;
 if(unit && unit->dwClassId>=0 && unit->dwClassId<gpDataTables->count) rec=&gpDataTables->missiles[unit->dwClassId];
 else rec=0;
 if(!rec) return MISSMODE_HandleMissileCollision(game,unit);
 int frame=unit->nSeqCurrentFramePrecise>>8;
 COLLISION_SetMaskWithSize(UNITS_GetRoom(unit),GetX(unit),GetY(unit),UNITS_GetUnitSizeX(unit),0x40);
 if(frame==rec->startFrame-1) {
  unit->nSeqCurrentFramePrecise=(frame+sub_0045C3E0_RollLimited(&unit->pSeed,rec->endFrame-rec->startFrame))<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)==rec->startFrame) {
  unit->nSeqCurrentFramePrecise=(rec->startFrame-3)<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)<rec->startFrame) {
  frame-=2; if(frame<0)frame=0; unit->nSeqCurrentFramePrecise=frame<<8;
 }
 return MISSMODE_HandleMissileCollision(game,unit);
}

// 0x005AEDA0
int __fastcall sub_005AEDA0_SummonPet(D2GameStrc* game,D2UnitStrc* unit)
{
 if(!SUNIT_GetOwner(game,unit) || !sub_0064A780_GetCount(unit)) return 2;
 if(sub_006505C0_CheckPath(unit->pDynamicPath)) {
  D2UnitStrc* owner=SUNIT_GetOwner(game,unit);
  int skillId,skillLevel;
  D2SkillsTxt* skill;
  if(!owner) return 2;
  skillId=sub_0064A280_GetSkill(unit);
  skillLevel=sub_0064A210_GetSkillLevel(unit);
  skill=sub_0045C4B0_GetSkillsTxtRecord(skillId);
  if(!skill) return 2;
  int variant;
  int monsterId=sub_0056E620_GetValidMonsterId(owner,0,skillId,skillLevel,&variant,0,0);
  if(monsterId<0) return 0;
  unsigned char petType=skill->petType;
  if(petType>=sgptDataTables->nPetTypeTxtRecordCount) petType=0;
  D2UnitStrc* target=SUNIT_GetServerUnit(game,1,sub_0064A730_GetUnitId(unit));
  if(target) {
   D2SummonArgs args;
   memset(&args,0,sizeof(args));
   args.mode=13;args.owner=owner;args.monsterId=monsterId;args.unknown=0;args.variant=variant;
   args.x=CLIENTS_GetUnitX(unit);args.y=CLIENTS_GetUnitY(unit);args.petType=petType;
   D2UnitStrc* summoned=sub_0056D940_Summon(game,&args);
   if(summoned) {
    AIGENERAL_SetOwnerData(game,summoned,!target ? -1 : target->dwUnitId,1,0,0);
    AIGENERAL_AllocMinionList(game,target,summoned);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(game,summoned,15,0);
    D2GAME_SetSummonPassiveStats_6FD0C530(game,owner,summoned,skillId,skillLevel,0);
    UNITS_StoreOwner(summoned,owner);
    sub_6FC40280(game,summoned,0,9);
    int count=sub_0064A780_GetCount(unit);--count;MISSILE_SetTargetY(unit,count);
   }
  }
 }
 return MISSMODE_HandleMissileCollision(game,unit);
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

// 0x005AF170
int __fastcall sub_005AF170_RotateMissileTarget(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord) return 2;
    const int nPeriod = pRecord->dwParam[1] < 1 ? 1 : pRecord->dwParam[1];
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pRecord->dwParam[0] && !(nFrames % nPeriod))
    {
        int nNewX = sub_0064A730_GetUnitId(pMissile);
        int nNewY = sub_0064A780_GetCount(pMissile);
        const int nOldX = nNewX;
        const int nNegY = -nNewY;
        __assume(nNegY != (-2147483647 - 1));
        nNewX = (nNegY + nNewX) / 2;
        nNewY = (nOldX + nNewY) / 2;
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nNewX, CLIENTS_GetUnitY(pMissile) + nNewY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nNewX);
        MISSILE_SetTargetY(pMissile, nNewY);
    }
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
