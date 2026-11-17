#define COF_PAD 0x20
#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))
struct D2UnitStrc; struct D2InventoryStrc;
struct D2ModeTypeTxt {char pad[0x20]; unsigned int token;};
struct D2MonStatsTxt {char pad[0x10]; unsigned int code; char rest[0x194];};
struct D2DataTablesStrc {char pad[0xA78]; D2MonStatsTxt* monsters; void* linker; int monsterCount;};
struct D2CompositStrc {unsigned int code; int mode;};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2CompositStrc gPlayerModes_00745900[]; // 0x00745900
extern unsigned int gPlayerModeCount_00745910; // 0x00745910
extern D2CompositStrc gMonsterModes_00745914[]; // 0x00745914
extern unsigned int gMonsterModeCount_0074591C; // 0x0074591C
extern const char gChars_006DCC34[]; // 0x006DCC34
extern const char gMonsters_006D6CAC[]; // 0x006D6CAC
extern const char gObjects_006E3628[]; // 0x006E3628
extern const char gFormatPath_006D6C94[]; // 0x006D6C94
extern const char gFormatCode_006D5514[]; // 0x006D5514
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468
D2ModeTypeTxt* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(int,int); // 0x0065B480
D2ModeTypeTxt* __stdcall DATATBLS_GetMonModeTxtRecord(int,int); // 0x0065B500
D2ModeTypeTxt* __stdcall DATATBLS_GetObjModeTypeTxtRecord(int,int); // 0x0065B570
int __fastcall sub_004638A0_CheckMonStats2Flag(int,int); // 0x004638A0
int __stdcall sub_0064F060(D2UnitStrc*,int,int,int,D2InventoryStrc*,int*); // 0x0064F060
// build: context DATATBLS_GetMonStatsTxtRecord
inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int id) {if(id>=0 && id<sgptDataTables->monsterCount)return &sgptDataTables->monsters[id];return 0;}
// build: context COMPOSIT_FormatPathInto
static __forceinline void COMPOSIT_FormatPathInto(char* path,unsigned int classCode,unsigned int modeCode,int* weapon,const char* prefix,int full,char* w,char* c,char* m) {
 w[0]=TOKEN_CHAR(((char*)weapon)[0]);
 w[1]=TOKEN_CHAR(((char*)weapon)[1]);
 w[2]=TOKEN_CHAR(((char*)weapon)[2]);
 w[3]=0;
 c[0]=TOKEN_CHAR(((char*)&classCode)[0]);
 c[1]=TOKEN_CHAR(((char*)&classCode)[1]);
 c[2]=TOKEN_CHAR(((char*)&classCode)[2]);
 c[3]=0;
 m[0]=TOKEN_CHAR(((char*)&modeCode)[0]);
 m[1]=TOKEN_CHAR(((char*)&modeCode)[1]);
 m[2]=TOKEN_CHAR(((char*)&modeCode)[2]);
 m[3]=0;
 if(full)wsprintfA(path,gFormatPath_006D6C94,prefix,c,c,m,w);else wsprintfA(path,gFormatCode_006D5514,c,m,w);
}

// 0x0064F5B0
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* unit,int cls,int mode,int type,D2InventoryStrc* inv,char* path,int* weapon,int full,int determine) {
 unsigned int clsCode;
 unsigned int modeCode;
 char wo[4],co[4],mo[4];
 switch(type){
 case 0:{
  char w[4],c[4],m[4];
  clsCode=DATATBLS_GetPlrModeTypeTxtRecord(cls,0)->token;
  modeCode=DATATBLS_GetPlrModeTypeTxtRecord(mode,1)->token;
  if(determine){if(mode && mode!=17){int weaponId;*weapon=sub_0064F060(unit,0,cls,mode,inv,&weaponId);}else *weapon=0x20687468;}
  for(unsigned int i=0;i<gPlayerModeCount_00745910;++i)if(mode==gPlayerModes_00745900[i].mode)modeCode=gPlayerModes_00745900[i].code;
  if(mode==11 && *weapon!=0x20736831 && *weapon!=0x20746831 && *weapon!=0x20736A31 && *weapon!=0x20746A31 && *weapon!=0x20737331 && *weapon!=0x20747331)*weapon=0x20687468;
  COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gChars_006DCC34,full,w,c,m);return;
 }
 case 1:{
  char w[4],c[4],m[4];
  D2MonStatsTxt* record=DATATBLS_GetMonStatsTxtRecord(cls);if(!record)return;
  clsCode=record->code;
  modeCode=DATATBLS_GetMonModeTxtRecord(mode,1)->token;
  if(mode && mode!=12){int weaponId;*weapon=sub_0064F060(unit,1,cls,mode,inv,&weaponId);}
  else{if(sub_004638A0_CheckMonStats2Flag(cls,16)){int weaponId;*weapon=sub_0064F060(unit,1,cls,mode,inv,&weaponId);}else *weapon=0x20687468;}
  for(unsigned int i=0;i<gMonsterModeCount_0074591C;++i)if(mode==gMonsterModes_00745914[i].mode)modeCode=gMonsterModes_00745914[i].code;
  COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gMonsters_006D6CAC,full,w,c,m);return;
 }
 case 2:
  clsCode=DATATBLS_GetObjModeTypeTxtRecord(cls,0)->token;
  modeCode=DATATBLS_GetObjModeTypeTxtRecord(mode,1)->token;
  {int weaponId;*weapon=sub_0064F060(unit,2,cls,mode,inv,&weaponId);}
  break;
 default:
  return;
 }
 COMPOSIT_FormatPathInto(path,clsCode,modeCode,weapon,gObjects_006E3628,full,wo,co,mo);
}

#include "gen/data/Source/D2Common/0064F5B0_D2Common_10884_COMPOSIT_unk.inc"
