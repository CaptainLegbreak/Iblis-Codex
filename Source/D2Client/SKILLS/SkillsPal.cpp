#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2GameStrc;
struct D2ModeChangeStrc {
    int nMode; D2UnitStrc* pUnit; D2UnitStrc* pTargetUnit;
    int nX, nY, unk14, unk18, unk1C;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId); // 0x00463900
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId); // 0x004833E0
int __fastcall sub_004C9460_GetSkillParam1(int nSkillId); // 0x004C9460
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
void __fastcall SUNIT_SetCombatMode(D2GameStrc*, D2UnitStrc*, int); // 0x00553570
int __fastcall sub_6FD150A0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0056E230
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc*, int, D2ModeChangeStrc*); // 0x005A7E60
void __stdcall UNITS_SetUsedSkill(D2UnitStrc*, D2SkillStrc*); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc*, int); // 0x006445A0
void __stdcall SKILLS_SetParam4(D2SkillStrc*, int); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc*, int); // 0x00644660
void __stdcall PATH_SetVelocity(D2DynamicPathStrc*, int, const char*, int); // 0x00648690
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc*, unsigned char); // 0x00648E70
void __stdcall sub_00649050(D2DynamicPathStrc*); // 0x00649050
int __stdcall D2Common_10142(D2DynamicPathStrc*, D2UnitStrc*, int); // 0x00649970
static __forceinline int UNITS_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static __forceinline int UNITS_GetUnitIdChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*,const char*,int); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc*); // 0x006446A0
void __stdcall SKILLS_SetParam3(D2SkillStrc*,int); // 0x006445E0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc*); // 0x004648F0
int __fastcall sub_004C7630(D2UnitStrc*,D2UnitStrc*); // 0x004C7630
int __fastcall sub_004F4F40_GetMonSkillSound(D2UnitStrc*,int); // 0x004F4F40
void __fastcall sub_004B9A00(int,D2UnitStrc*,int,int,int); // 0x004B9A00
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc*,int); // 0x00465BF0
void __fastcall sub_004C7950(D2UnitStrc*); // 0x004C7950
// 0x004C9B40
int __fastcall sub_004C9B40_StartCharge(D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
 D2SkillStrc* pSkill=UNITS_GetUsedSkill(pUnit);
 if(!pSkill)return 0;
 D2SkillsTxt* pRecord=SKILLS_GetSkillsTxtRecord(nSkillId);
 if(!pRecord)return 0;
 if(SKILLS_GetSkillIdFromSkill(pSkill,".\\SKILLS\\SkillsPal.cpp",0x176)==nSkillId && pUnit==sub_00463DD0_GetPlayerUnit() && (SKILLS_GetFlags(pSkill)&1))return 0;
 D2DynamicPathStrc* pPath=pUnit->pDynamicPath;
 if(!pPath)return 0;
 D2UnitStrc* pTarget=sub_004648F0_GetPathTargetUnit(pUnit);
 if(UNITS_GetUnitTypeChecked(pUnit)==0 && pTarget && UNITS_IsInMeleeRange(pUnit,pTarget,0))return sub_004C7630(pUnit,pTarget);
 if(UNITS_GetUnitTypeChecked(pUnit)==0){
  if(pRecord->wDoSoundA>0)sub_004B9A00(pRecord->wDoSoundA,pUnit,0,0,0);
 }else if(UNITS_GetUnitTypeChecked(pUnit)==1){
  int sound=sub_004F4F40_GetMonSkillSound(pUnit,nSkillId);
  if(sound>0)sub_004B9A00(sound,pUnit,0,0,0);
 }
 if(pTarget){
  if(!STATES_CheckState(pTarget,54)){
   SKILLS_SetParam1(pSkill,UNITS_GetUnitTypeChecked(pTarget));
   SKILLS_SetParam2(pSkill,UNITS_GetUnitIdChecked(pTarget));
  }else{SKILLS_SetParam1(pSkill,6);SKILLS_SetParam2(pSkill,0);}
 }else{SKILLS_SetParam1(pSkill,6);SKILLS_SetParam2(pSkill,0);}
 int nVelocity=256;
 SKILLS_SetParam4(pSkill,7);
 if(UNITS_GetUnitTypeChecked(pUnit)==0){
  D2CharStatsTxt* rec=sub_004833E0_GetCharStatsTxtRecord(pUnit->dwClassId);
  if(rec)nVelocity=rec->nRunSpeed<<8;
 }else{
  int id=pUnit->dwClassId;
  D2MonStatsTxt* rec=DATATBLS_GetMonStatsTxtRecord(id);
  if(rec){
   nVelocity=rec->nRun<<8;
   if(id==211)SKILLS_SetParam4(pSkill,15);
   PATH_SetNewDistance(pPath,30);
  }
 }
 int bonus=STATLIST_UnitGetStatValue(pUnit,67,0);
 if(bonus<=50)bonus=50;
 PATH_SetVelocity(pPath,DATATBLS_ApplyRatio(nVelocity,sub_004C9460_GetSkillParam1(nSkillId)+bonus,100),".\\SKILLS\\SkillsPal.cpp",0x1ca);
 D2Common_10142(pPath,pUnit,0);
 if(pTarget)sub_00465BF0_SetPathTargetToTargetUnit(pUnit,1);
 SKILLS_SetFlags(pSkill,0x1001);
 SKILLS_SetParam3(pSkill,0);
 sub_004C7950(pUnit);
 return 1;
}
