struct D2BinFieldStrc { const char* name; int type,length,offset; void* lookup; };
struct D2MonStatsTxt { unsigned char unk00[42]; short equipIndex; unsigned char unk2C[380]; };
struct D2MonEquipTxt { short monster,level; char onInit; char unk05[3]; unsigned int item[3]; char location[3]; char modifier[3]; char unk1A[2]; };
struct D2DataTablesStrc { unsigned char unk00[148]; void* itemsLinker; unsigned char unk98[2536]; int monStatsCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MonStatsTxt* gpMonStatsTxt_0096C6A8; // 0x0096C6A8
extern D2MonEquipTxt* gpMonEquipTxt_0096C810; // 0x0096C810
extern int gnMonEquipCount_0096C814; // 0x0096C814
extern void* gpMonStatsLinker_0096C6AC; // 0x0096C6AC
extern void* gpItemsLinker_0096BCC4; // 0x0096BCC4
extern void* gpBodyLocsLinker_0096BC3C; // 0x0096BC3C
extern const char gszEmptyAssertText_006CC837[]; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
void* __stdcall DATATBLS_CompileTxt(void*,const char*,D2BinFieldStrc*,int*,int); // 0x006122F0
int __stdcall FOG_GetLinkIndex(void*,unsigned int,int); // 0x006BD130
extern const char gszField_end[]; // 0x006D9060
extern const char gszField_level[]; // 0x006DCCBC
extern const char gszField_item3[]; // 0x006E6588
extern const char gszField_item2[]; // 0x006E659C
extern const char gszField_item1[]; // 0x006E65B0
extern const char gszField_mod3[]; // 0x006ED53C
extern const char gszField_loc3[]; // 0x006ED544
extern const char gszField_mod2[]; // 0x006ED54C
extern const char gszField_loc2[]; // 0x006ED554
extern const char gszField_mod1[]; // 0x006ED55C
extern const char gszField_loc1[]; // 0x006ED564
extern const char gszField_oninit[]; // 0x006ED56C
extern const char gszField_monster[]; // 0x006ED574
extern const char gszField_monequip[]; // 0x006ED57C

static __forceinline D2MonStatsTxt* GetMonStatsRecord(int monster)
{
 if(monster>=0 && monster<sgptDataTables->monStatsCount)return &gpMonStatsTxt_0096C6A8[monster];
 return 0;
}
// 0x00659E60
void __fastcall DATATBLS_LoadMonEquipTxt(void* archive)
{
 D2BinFieldStrc fields[]={
 {gszField_monster,20,0,0,&gpMonStatsLinker_0096C6AC},
 {gszField_level,3,0,2,0},
 {gszField_oninit,4,0,4,0},
 {gszField_item1,9,0,8,&gpItemsLinker_0096BCC4},
 {gszField_loc1,13,0,20,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod1,4,0,23,0},
 {gszField_item2,9,0,12,&gpItemsLinker_0096BCC4},
 {gszField_loc2,13,0,21,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod2,4,0,24,0},
 {gszField_item3,9,0,16,&gpItemsLinker_0096BCC4},
 {gszField_loc3,13,0,22,&gpBodyLocsLinker_0096BC3C},
 {gszField_mod3,4,0,25,0},
 {gszField_end,0,0,0,0}};
 gpMonEquipTxt_0096C810=(D2MonEquipTxt*)DATATBLS_CompileTxt(archive,gszField_monequip,fields,&gnMonEquipCount_0096C814,sizeof(D2MonEquipTxt));
 if(gnMonEquipCount_0096C814>=32767){
  sub_00408A60(gszEmptyAssertText_006CC837,sub_00408090(),3356);exit(-1);
 }
 for(int i=0;i<sgptDataTables->monStatsCount;++i)gpMonStatsTxt_0096C6A8[i].equipIndex=-1;
 for(int i=0;i<gnMonEquipCount_0096C814;++i){
  D2MonEquipTxt* equip=&gpMonEquipTxt_0096C810[i];
  if(equip->monster>=0 && equip->monster<sgptDataTables->monStatsCount){
   if(gpMonStatsTxt_0096C6A8[equip->monster].equipIndex<0)gpMonStatsTxt_0096C6A8[equip->monster].equipIndex=(short)i;
   char* location=equip->location;
   unsigned int* item=equip->item;
   int remaining=3;
   do {
    if (*location<=0 || *location>=11)
    {
        *location=0;
    }
    else if (*item!=0x20202020 && FOG_GetLinkIndex(sgptDataTables->itemsLinker,*item,1)<0)
    {
        *location=0;
    }
    ++item;
    ++location;
   } while(--remaining);
  }
 }
}

#include "gen/data/Source/D2Common/00659E60_DATATBLS_LoadMonEquipTxt.inc"
