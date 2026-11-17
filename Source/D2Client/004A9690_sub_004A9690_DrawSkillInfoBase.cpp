struct Unicode
{
    unsigned short wChar;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x2];
    unsigned char nFlags[8];
    char unk0x00C[0x188];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);
extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);
void __fastcall sub_004A8DF0_DrawKeyLabel(int nKeyId, int nX, int nY, int nColor);                          // 0x004A8DF0

// build: context sub_004A9260_DrawSkillCharges
static __declspec(noinline) void __stdcall sub_004A9260_DrawSkillCharges(int nCharges, int nX, int nY)
{
    Unicode wszText[16] = {};
    char szText[16];
    if (nCharges > 0)
    {
        sub_00526320_ToUnicode(wszText, _itoa(nCharges, szText, 10), 16);
        int nLength = sub_00526800((const unsigned short*)wszText);
        while (sub_00501820(wszText) > 40)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        sub_00501820(wszText);
        sub_00502320(wszText, nX + 4, nY - 1, 3, 0);
    }
}

#define SPELLSEL_HOTKEY_LABEL(i, key, flag) \
    if (gnHotkeySkill_007C06C8[i] == pSkillsTxt->nSkillId && gnHotkeyOwner_007C0768[i] == nOwner \
        && gnHotkeySkill_007C06C8[i] != -1 && gbHotkeyLeft_007C07B8[i] == flag) \
    { \
        sub_004A8DF0_DrawKeyLabel(key, nX + 0x22, nY - 0x23, 4); \
    }

// 0x004A8ED0
static __declspec(noinline) void __stdcall sub_004A8ED0_DrawSkillHotkeyLabels(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 1)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 1)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 1)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 1)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 1)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 1)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 1)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 1)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 1)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 1)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 1)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 1)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 1)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 1)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 1)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 1)
}

// 0x004A9300
static __declspec(noinline) void __stdcall sub_004A9300_DrawHotkeyLabelsB(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 0)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 0)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 0)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 0)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 0)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 0)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 0)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 0)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 0)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 0)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 0)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 0)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 0)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 0)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 0)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 0)
}

struct D2SkillDescTxt { char pad[7]; unsigned char icon; char tail[0x118]; };
struct D2DataTables { char pad[0xb8c]; D2SkillDescTxt* descs; int pad90; int descCount; D2SkillsTxt* skills; int pad9c; int skillCount; };
struct D2CelContext { int frame; char pad04[0x30]; void* cell; char pad38[8]; int zero40; int tail44; };
#pragma pack(push,1)
struct D2SkillIconFile { void* cell; char name[30]; };
#pragma pack(pop)
extern D2DataTables* gpDataTables; // 0x00744304
extern D2SkillIconFile gaSkillIconFiles[7]; // 0x00724AC0
extern void* gpGenericSkillIcons; // 0x007C07F8
int __stdcall SKILLS_GetClassIdFromSkillId(int); // 0x00645040
void* __fastcall sub_004520C0_LoadUiCelFile(const char*); // 0x004520C0
int __cdecl sub_00468730_GetMouseX(); // 0x00468730
int __cdecl sub_00468740_GetMouseY(); // 0x00468740
void __stdcall TEXTURE_CelDrawColor(D2CelContext*,int,int,int,int,int); // 0x004F64B0
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

struct D2InventoryStrc;
struct D2UnitStrc { char pad[0x60]; D2InventoryStrc* inventory; };
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __stdcall sub_0063BEF0_GetMainHand(D2InventoryStrc*); // 0x0063BEF0
D2UnitStrc* __stdcall sub_0063BDE0_GetBodyItem(D2InventoryStrc*,int); // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc*); // 0x006289F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
// 0x004A9690
void __fastcall sub_004A9690_DrawSkillInfoBase(void* cell,D2SkillsTxt* skills,int owner,int charges,int state,int x,int y,int left) {
 int id=skills->nSkillId;
 D2SkillsTxt* record;
 if(id>=0 && id<gpDataTables->skillCount)record=&gpDataTables->skills[id];else record=0;
 if(!record)return;
 id=record->wSkillDesc;
 D2SkillDescTxt* desc;
 if(id>=0 && id<gpDataTables->descCount)desc=&gpDataTables->descs[id];else desc=0;
 if(!desc)return;
 int frame=desc->icon;
 int mouseX=sub_00468730_GetMouseX();
 int mouseY=sub_00468740_GetMouseY();
 int drawState;
 if(mouseX>=x && mouseX<=x+48 && mouseY>=y-48 && mouseY<=y) {
  if(state==0)drawState=0;
  else if(state==1)drawState=1;
  else drawState=state==4?4:1;
 } else drawState=state;
 D2CelContext ctx;memset(&ctx,0,sizeof(ctx));
 ctx.cell=cell;ctx.zero40=0;ctx.frame=frame;
 TEXTURE_CelDrawColor(&ctx,x,y,-1,5,drawState);
 if(left)sub_004A8ED0_DrawSkillHotkeyLabels(skills,owner,x,y);
 else sub_004A9300_DrawHotkeyLabelsB(skills,owner,x,y);
 D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
 int quantity;
 if(player && player->inventory) {
  D2InventoryStrc* inv=player->inventory;
  switch(skills->nSkillId) {
  case 4: {
   D2UnitStrc* hand=sub_0063BEF0_GetMainHand(inv);
   D2UnitStrc* item=sub_0063BDE0_GetBodyItem(inv,4);
   D2UnitStrc* other=sub_0063BDE0_GetBodyItem(inv,5);
   if(hand==item)item=other;
   if(item && ITEMS_CheckItemTypeId(item,45) && ITEMS_CheckIfThrowable(item) && ITEMS_CheckIfStackable(item)) {
    quantity=STATLIST_UnitGetStatValue(item,70,0);goto draw;
   }
   break;
  }
  case 2: {
   D2UnitStrc* item=sub_0063BEF0_GetMainHand(inv);
   if(item && ITEMS_CheckIfThrowable(item) && ITEMS_CheckIfStackable(item)) {
    quantity=STATLIST_UnitGetStatValue(item,70,0);goto draw;
   }
   break;
  }
  }
 }
 quantity=charges;
 draw: sub_004A9260_DrawSkillCharges(quantity,x,y);
}
