extern "C" void* __cdecl memset(void*,int,unsigned int);
struct D2GameStrc;
struct D2UnitStrc { char unk_00[12]; int dwUnitId; char unk_10[28]; void* path; };
struct D2SkillsTxt { char unk_00[190]; unsigned char petType; };
struct D2DataTablesStrc { char unk_00[3056]; int petTypeCount; };
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
int __fastcall sub_0045ADF0_GetX(D2UnitStrc*); // 0x0045ADF0
int __fastcall sub_0045AE20_GetY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall sub_0056D940_Summon(D2GameStrc*,D2SummonArgs*); // 0x0056D940
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int,int); // 0x005C4470
void __stdcall UNITS_StoreOwner(D2UnitStrc*,D2UnitStrc*); // 0x00621CE0
void __fastcall sub_6FC40280(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990
void __stdcall MISSILE_SetTargetY(D2UnitStrc*,int); // 0x0064A760
int __fastcall sub_005AE1F0_Finish(D2GameStrc*,D2UnitStrc*); // 0x005AE1F0
// 0x005AEDA0
int __fastcall sub_005AEDA0_SummonPet(D2GameStrc* game,D2UnitStrc* unit)
{
 if(!SUNIT_GetOwner(game,unit) || !sub_0064A780_GetCount(unit)) return 2;
 if(sub_006505C0_CheckPath(unit->path)) {
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
  if(petType>=sgptDataTables->petTypeCount) petType=0;
  D2UnitStrc* target=SUNIT_GetServerUnit(game,1,sub_0064A730_GetUnitId(unit));
  if(target) {
   D2SummonArgs args;
   memset(&args,0,sizeof(args));
   args.mode=13;args.owner=owner;args.monsterId=monsterId;args.unknown=0;args.variant=variant;
   args.x=sub_0045ADF0_GetX(unit);args.y=sub_0045AE20_GetY(unit);args.petType=petType;
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
 return sub_005AE1F0_Finish(game,unit);
}
