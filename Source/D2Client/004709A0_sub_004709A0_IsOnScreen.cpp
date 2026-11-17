struct D2InventoryStrc;
struct D2UnitStrc { int type,classId; char unknown08[0x58]; D2InventoryStrc* inventory; char unknown64[0x64]; unsigned int flagsEx; };
struct D2GfxHeaderStrc { int unknown00[2],left,right,top,bottom; };
struct D2GfxRecordStrc { char unknown00[0x14]; void* gfx; };
struct D2GfxNodeStrc { int mode,unknown04; D2GfxRecordStrc* record; int unknown0C; D2GfxNodeStrc* next; };
struct D2GfxDataStrc { char unknown00[0x28]; D2GfxNodeStrc* list; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc*,int); // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc*); // 0x004639D0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc*); // 0x00463E10
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc*,int,int); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc*,int,int); // 0x0046FA80
D2GfxHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void*); // 0x004DB040
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc*); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*,int*,int*,int*,const char*,int); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*,D2InventoryStrc*,int*,int,int); // 0x0064F380
static __forceinline int IsShapeShifted(D2UnitStrc* unit) { if(!unit) return 0; return (unit->flagsEx>>3)&1; }
static __forceinline D2InventoryStrc* GetInventory(D2UnitStrc* unit) {
 if(IsShapeShifted(unit) && STATES_CheckStateMaskOnUnit(unit,37)) {
  D2UnitStrc* owner=sub_004639D0_GetOwnerUnit(unit);
  if(owner) return owner->inventory;
 }
 return unit->inventory;
}
static __forceinline void* GetModeGfx(D2UnitStrc* unit,int mode) {
 D2GfxDataStrc* data=sub_00463E10_GetGfxData(unit);
 if(!data) return 0;
 D2GfxNodeStrc* node=data->list;
 if(!node) return 0;
 do {
  if(node->mode==mode) return node->record->gfx;
  node=node->next;
 } while(node);
 return 0;
}
// 0x004709A0
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* unit,int x,int y,int unused,int centered)
{
 int weapon;
 int weaponClass=COMPOSIT_GetWeaponClassId(unit,GetInventory(unit),&weapon,-1,1);
 if(!sub_0046E5A0_FindGfxNode(unit,weaponClass,-1)) sub_0046FA80_LoadGfxNode(unit,weaponClass,-1);
 int type=unit->type;
 int classId=unit->classId;
 int mode=UNITS_GetAnimOrSeqMode(unit);
 D2COMMON_11013_ConvertMode(unit,&type,&classId,&mode,".\\ENGINE\\Gfx.cpp",3522);
 void* gfx=GetModeGfx(unit,mode);
 if(!gfx) return 0;
 D2GfxHeaderStrc* header=sub_004DB040_GetLayerHeader(gfx);
 if(!header) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),3539); exit(-1); }
 int width=gnScreenWidth;
 int height=gnScreenHeight;
 int left=header->left+x;
 if(centered) left-=(header->bottom-header->top)/2;
 if(left>=width-1) return 0;
 if(header->right+x<0) return 0;
 if(header->bottom+y<0) return 0;
 return header->top+y<height-1;
}
