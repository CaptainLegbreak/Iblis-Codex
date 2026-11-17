// build: base-profile

struct D2BinFieldStrc { const char* name; int type,length,offset; void* linker; };
struct D2LvlSubTxt { int type; char file[60]; char unk_040[0x118]; int expansion; };
struct D2DrlgFileStrc { char unk_00[0x4c]; int groups; };
extern D2LvlSubTxt* gpRows_0096CA10; // 0x0096CA10
extern int gnCount_0096CA14; // 0x0096CA14
extern int* gpTypeStarts_0096CA18; // 0x0096CA18
extern D2DrlgFileStrc** gpFiles_0096CA24; // 0x0096CA24
extern const char gszFile_006E84DC[]; // 0x006E84DC
extern const char gszDirectory_006E867C[]; // 0x006E867C
extern const char gszPathFormat_006D4124[]; // 0x006D4124
extern const char gszTable_006E8928[]; // 0x006E8928
extern const char gszAssert_006CC837[]; // 0x006CC837
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468
void* __stdcall DATATBLS_CompileTxt(void*,const char*,D2BinFieldStrc*,int*,int); // 0x006122F0
void* __fastcall FOG_AllocPool(void*,int,const char*,int,int); // 0x0040B430
void* __fastcall FOG_Alloc(int,const char*,int,int); // 0x0040B380
int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc**,void*,const char*); // 0x00665F40
void* __stdcall sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,void*,int); // 0x00408A60
__declspec(noreturn) void __cdecl sub_00681E09_Exit(int);
void __cdecl sub_00681E09_Exit(int); // 0x00681E09
static void sub_0061E4A0_FixPath(const char*,char*); // 0x0061E4A0
// 0x0061E4A0
static void sub_0061E4A0_FixPath(const char* directory,char* path)
{
 char buffer[60]; int length=strlen(path);
 if(length) { for(int i=0;i<length;++i) { if(path[i]=='/')path[i]='\\'; } }
 if(length>1) { wsprintfA(buffer,gszPathFormat_006D4124,directory,path);strcpy(path,buffer); }
}
extern const char gszField_Type[]; // 0x006E89A4
extern const char gszField_File[]; // 0x006E899C
extern const char gszField_CheckAll[]; // 0x006E8990
extern const char gszField_BordType[]; // 0x006E8984
extern const char gszField_GridSize[]; // 0x006E8978
extern const char gszField_Dt1Mask[]; // 0x006E879C
extern const char gszField_Prob0[]; // 0x006E8970
extern const char gszField_Trials0[]; // 0x006E8968
extern const char gszField_Max0[]; // 0x006E8960
extern const char gszField_Prob1[]; // 0x006E8958
extern const char gszField_Trials1[]; // 0x006E8950
extern const char gszField_Max1[]; // 0x006E8948
extern const char gszField_Prob2[]; // 0x006E8940
extern const char gszField_Trials2[]; // 0x006E8938
extern const char gszField_Max2[]; // 0x006E8930
extern const char gszField_Prob3[]; // 0x006E8920
extern const char gszField_Trials3[]; // 0x006E8918
extern const char gszField_Max3[]; // 0x006E8910
extern const char gszField_Prob4[]; // 0x006E8908
extern const char gszField_Trials4[]; // 0x006E8900
extern const char gszField_Max4[]; // 0x006E88F8
extern const char gszField_Expansion[]; // 0x006DCF44
extern const char gszField_end[]; // 0x006D9060
// 0x0061F500
void __fastcall DATATBLS_LoadLvlSubTxt(void* archive,int loadFiles,int extra)
{
 D2BinFieldStrc fields[]={
  {gszField_Type,2,0,0x0,0},
  {gszField_File,1,59,0x4,0},
  {gszField_CheckAll,2,0,0x40,0},
  {gszField_BordType,2,0,0x44,0},
  {gszField_GridSize,2,0,0x4c,0},
  {gszField_Dt1Mask,2,0,0x48,0},
  {gszField_Prob0,2,0,0x11c,0},
  {gszField_Trials0,2,0,0x130,0},
  {gszField_Max0,2,0,0x144,0},
  {gszField_Prob1,2,0,0x120,0},
  {gszField_Trials1,2,0,0x134,0},
  {gszField_Max1,2,0,0x148,0},
  {gszField_Prob2,2,0,0x124,0},
  {gszField_Trials2,2,0,0x138,0},
  {gszField_Max2,2,0,0x14c,0},
  {gszField_Prob3,2,0,0x128,0},
  {gszField_Trials3,2,0,0x13c,0},
  {gszField_Max3,2,0,0x150,0},
  {gszField_Prob4,2,0,0x12c,0},
  {gszField_Trials4,2,0,0x140,0},
  {gszField_Max4,2,0,0x154,0},
  {gszField_Expansion,2,0,0x158,0},
  {gszField_end,0,0,0x0,0},
 };
  int maxType=0;
 D2LvlSubTxt* rows=(D2LvlSubTxt*)DATATBLS_CompileTxt(archive,gszTable_006E8928,fields,&gnCount_0096CA14,sizeof(D2LvlSubTxt));
 gpRows_0096CA10=rows;
 if(gnCount_0096CA14>0) {
  for(int i=0;i<gnCount_0096CA14;++i) { if(rows[i].type>maxType)maxType=rows[i].type; }
  if(maxType) {
   int size=sizeof(int)*(maxType+1);
   gpTypeStarts_0096CA18=(int*)FOG_AllocPool(0,size,gszFile_006E84DC,0x3a6,0);
   memset(gpTypeStarts_0096CA18,0,size);
   int lastType=0;
   D2LvlSubTxt* txt=gpRows_0096CA10;
   int i=0;
   while(i<gnCount_0096CA14) {
    if(txt[i].type!=lastType) {

     if(txt[i].type>lastType) { lastType=txt[i].type;gpTypeStarts_0096CA18[lastType]=i; }
     else { lastType=txt[i].type;gpTypeStarts_0096CA18[lastType]=i; }
     ++i; continue;
    }
    ++i;
   }
  }
 }
 if(loadFiles||extra) {
  gpFiles_0096CA24=(D2DrlgFileStrc**)FOG_Alloc(sizeof(D2DrlgFileStrc*)*gnCount_0096CA14,gszFile_006E84DC,0x3b6,0);
  memset(gpFiles_0096CA24,0,sizeof(D2DrlgFileStrc*)*gnCount_0096CA14);
 }
 D2LvlSubTxt* row=gpRows_0096CA10;
 int expansion=sub_00408F20_HasExpansionMpq();
 for(int i=0;i<gnCount_0096CA14;++i,++row) {
  sub_0061E4A0_FixPath(gszDirectory_006E867C,row->file);
  if((expansion||!row->expansion)&&(loadFiles||extra)) {
   DRLGPRESET_LoadDrlgFile(&gpFiles_0096CA24[i],0,row->file);
   if(!gpFiles_0096CA24[i]->groups) {
    sub_00408A60(gszAssert_006CC837,sub_00408090(),0x3c8);sub_00681E09_Exit(-1);
   }
  }
 }
}

#include "gen/data/Source/D2Common/DATATBLS/LvlTbls_0061F500.inc"
