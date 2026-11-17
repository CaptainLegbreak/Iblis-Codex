struct D2GameStrc;
struct D2UnitStrc { int type; char unk04[0xC0]; unsigned int flags; };
struct D2DamageStrc { int unk00; unsigned short resultFlags; unsigned short unk06; int physical; };
struct D2SkillsTxt { char unk00[0x138]; int calc; char unk13C[0x100]; };
struct D2DataTablesStrc { char unk00[0xB98]; D2SkillsTxt* skills; int unkB9C; int skillCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc*,D2UnitStrc*); // 0x0057D690
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc*); // 0x0058F0D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,int,int,int); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int,int,int); // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0057D4F0
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
static inline int sub_0044BE50(D2UnitStrc* unit)
{
 if(!unit)return 6;
 return unit->type;
}
// 0x005D16A0
int __fastcall sub_005D16A0_TransferLifeFromDamage(D2GameStrc* game,D2UnitStrc* unit,int skillId,int level)
{
 D2SkillsTxt* skill=(skillId>=0 && skillId<sgptDataTables->skillCount)?&sgptDataTables->skills[skillId]:0;
 if(!skill)return 0;
 D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
 if(!target)return 0;
 if(unit)unit->flags|=0x40;
 D2DamageStrc* damage=SUNITDMG_GetDamageFromUnits(unit,target);
 if(!damage)return 0;
 if(damage->resultFlags&1) {
  D2UnitStrc* owner=0;
  if(sub_0044BE50(unit)==1) {
   owner=AIGENERAL_GetMinionOwner(unit);
   if(!owner)owner=unit;
  }
  int life=STATLIST_UnitGetStatValue(owner,6,0);
  int maxLife=STATLIST_GetMaxLifeFromUnit(owner);
  int amount=MIN(damage->physical,STATLIST_UnitGetStatValue(target,6,0));
  life+=DATATBLS_ApplyRatio(amount,SKILLS_EvaluateSkillFormula(unit,skill->calc,skillId,level),100);
  life=MIN(MAX(life,1),maxLife);
  STATLIST_SetUnitStat(owner,6,life,0);
 }
 SUNITDMG_DrainItemDurability(game,unit,target,0);
 return 1;
}
