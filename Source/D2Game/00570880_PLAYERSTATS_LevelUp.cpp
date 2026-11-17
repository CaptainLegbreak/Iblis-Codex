struct D2UnitStrc { int type; int classId; };
struct D2GameStrc { char unk_00[40]; unsigned short gameId; };
struct D2CharStatsTxt { char unk_00[67]; unsigned char lifePerLevel; unsigned char staminaPerLevel; unsigned char manaPerLevel; char unk_46[10]; signed char statPerLevel; char unk_51[115]; };
struct D2DataTablesStrc { char unk_00[3012]; D2CharStatsTxt* charStats; int charStatsCount; };
typedef void (__fastcall* LevelCallback)(unsigned int, int);
struct D2ServerCallbacks { char unk_00[44]; LevelCallback levelUp; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall DATATBLS_GetCurrentLevelFromExp(int, int); // 0x00611860
int __stdcall DATATBLS_GetLevelThreshold(int, int); // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
int __stdcall sub_00625D10(D2UnitStrc*); // 0x00625D10
int __stdcall sub_00625D60(D2UnitStrc*); // 0x00625D60
int __stdcall sub_00625DB0(D2UnitStrc*); // 0x00625DB0
void __fastcall sub_00536850_UpdateLevel(D2GameStrc*,D2UnitStrc*,int); // 0x00536850
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc*,D2UnitStrc*,void*);
void __fastcall sub_00570850_Forward(void*,D2UnitStrc*,int); // 0x00570850
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc*,SUNIT_IterateFn,void*); // 0x005538D0
void __fastcall sub_0055F500_Update(D2GameStrc*,D2UnitStrc*); // 0x0055F500
void __fastcall sub_0055FDE0(D2GameStrc*,D2UnitStrc*,int); // 0x0055FDE0
int __stdcall sub_00622150_GetLevelInfo(D2UnitStrc*,int,int); // 0x00622150
// 0x00570880
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* game,D2UnitStrc* unit)
{
 int classId;
 if(!unit) classId=-1; else classId=unit->classId;
 int previousLevel=STATLIST_GetUnitBaseStat(unit,12,0);
 int level=DATATBLS_GetCurrentLevelFromExp(classId,STATLIST_UnitGetStatValue(unit,13,0));
 STATLIST_SetUnitStat(unit,12,level,0);
 STATLIST_SetUnitStat(unit,30,DATATBLS_GetLevelThreshold(classId,level),0);
 int gained=level-previousLevel;
 if(gained>0) {
  D2CharStatsTxt* record=(classId>=0 && classId<sgptDataTables->charStatsCount)?&sgptDataTables->charStats[classId]:0;
  int life=STATLIST_GetUnitBaseStat(unit,7,0)+((record->lifePerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,7,life,0);
  int maxLife=sub_00625D10(unit);
  if(STATLIST_UnitGetStatValue(unit,6,0)>0) STATLIST_SetUnitStat(unit,6,maxLife,0);
  int mana=STATLIST_GetUnitBaseStat(unit,9,0)+((record->manaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,9,mana,0);
  int maxMana=sub_00625D60(unit);
  STATLIST_SetUnitStat(unit,8,maxMana,0);
  int stamina=STATLIST_GetUnitBaseStat(unit,11,0)+((record->staminaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,11,stamina,0);
  int maxStamina=sub_00625DB0(unit);
  STATLIST_SetUnitStat(unit,10,maxStamina,0);
  STATLIST_AddUnitStat(unit,4,record->statPerLevel*gained,0);
  STATLIST_AddUnitStat(unit,5,gained,0);
  sub_00536850_UpdateLevel(game,unit,level);
  SUNIT_AttachSound(unit,2,unit);
  SUNIT_IterateLivingPlayers(game,(SUNIT_IterateFn)sub_00570850_Forward,unit);
  sub_0055F500_Update(game,unit);
  sub_0055FDE0(game,unit,1);
  if(gpServerCallbacks && gpServerCallbacks->levelUp) gpServerCallbacks->levelUp(game->gameId,sub_00622150_GetLevelInfo(unit,classId,level));
 }
}
