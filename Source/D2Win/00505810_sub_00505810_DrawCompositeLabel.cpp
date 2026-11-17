struct Unicode { unsigned short wChar; Unicode():wChar(0) {} };
struct D2CompositeUnitStrc {
 unsigned int flags;char pad04[0x10];int x,y,unitClass;
 char pad20[0xac];Unicode accountName[64],characterName[64];
 Unicode guildTag[50];unsigned int productCode;
};
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern const char gszEmptyAssertText; // 0x006CC837
extern const char gszGuildPrefix[]; // 0x006DCE68
extern const char gszGuildSuffix[]; // 0x006DCE64
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

Unicode* __fastcall sub_005267E0(Unicode*,const Unicode*); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700
int __fastcall sub_00526800(const Unicode*); // 0x00526800
Unicode* __fastcall sub_00526F20(Unicode*,const char*,int); // 0x00526F20
void __fastcall sub_00526320(Unicode*,const char*,int); // 0x00526320
int __fastcall sub_00502EF0(int); // 0x00502EF0
int __stdcall sub_00503EC0_TruncateText(Unicode*,int); // 0x00503EC0
void __fastcall sub_00502520(const Unicode*,int*,int*); // 0x00502520
void __fastcall sub_00502320(const Unicode*,int,int,int,int); // 0x00502320

static __forceinline int sub_00505640_IsFemaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 1;
    }
    return 0;
}

// 0x00505640
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nTitle, int bExpansion)
{
    if (bExpansion)
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Patriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Matriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
    }
    else
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Sir ";
            case 2: return "Lord ";
            case 3: return "Baron ";
            case 4: return "Count ";
            case 5: return "Duke ";
            case 6: return "King ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Dame ";
            case 2: return "Lady ";
            case 3: return "Baroness ";
            case 4: return "Countess ";
            case 5: return "Duchess ";
            case 6: return "Queen ";
            }
        }
    }

    return &gszEmptyAssertText;
}

// 0x00505810
int __fastcall sub_00505810_DrawCompositeLabel(D2CompositeUnitStrc* unit)
{
 if(!unit){sub_00408A60(&gszEmptyAssertText,sub_00408090(),1723);exit(-1);}
 if(!(unit->flags & gdwBitMasks[1]))return 0;
 int y=unit->y+6;
 Unicode text[256];
 int color=0,shadow=0;
 if(unit->unitClass==20){shadow=1;color=3;}
 else if(unit->unitClass==18){color=3;shadow=1;}
 else if(unit->flags & gdwBitMasks[5])color=1;
 unsigned int flags=unit->flags;
 if(unit->flags & gdwBitMasks[8])y+=15;
 if((flags & gdwBitMasks[6]) || (flags & gdwBitMasks[7])){
  const char* title=D2Win_10160_GetPlayerTitle(unit->unitClass,3*((flags>>5)&1)+2*((flags>>7)&1)+((flags>>6)&1),(flags>>12)&1);
  Unicode titleText[256];
  sub_00526F20(titleText,title,255);
  memset(text,0,sizeof(text));
  sub_005267E0(text,titleText);
  sub_00526700(text,unit->characterName);
 }else{
  if(unit->productCode=='D2DV' || unit->productCode=='D2ST' || unit->productCode=='D2XP')
   sub_005267E0(text,unit->characterName);
  else sub_005267E0(text,unit->accountName);
 }
 Unicode decoration[256];
 if(sub_00526800(unit->guildTag)){
  sub_00526320(decoration,gszGuildPrefix,256);
  sub_00526700(text,decoration);
  sub_00526700(text,unit->guildTag);
  sub_00526320(decoration,gszGuildSuffix,256);
  sub_00526700(text,decoration);
 }
 sub_00502EF0(12);
 sub_00503EC0_TruncateText(text,120);
 int width,height;
 sub_00502520(text,&width,&height);
 if(shadow)sub_00502320(text,unit->x-(width>>1)-1,y-1,6,0);
 sub_00502320(text,unit->x-(width>>1),y,color,0);
 return 1;
}

#include "gen/data/Source/D2Win/00505810_sub_00505810_DrawCompositeLabel.inc"
