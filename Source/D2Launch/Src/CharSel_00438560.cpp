struct D2CompositeUnitStrc;
struct Unicode
{
    unsigned short wChar;
    Unicode() : wChar(0) {}
};

extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                      // 0x005267E0

__declspec(noinline) static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass);
static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass); // 0x00437F60
// 0x00437F60
static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

struct D2WinControlStrc;
struct D2LaunchCharEntryStrc {
    char szName[0x100]; Unicode wszName[0x100];
    unsigned char aBlock0x300[16],aBlock0x310[16];
    unsigned char nType,pad321; unsigned short nLevel,wFlags;
    char pad326[4],szTag[4]; unsigned char nFlag32E; char pad32F[5]; int nStatus; void* pAnim;
    char pad33C[12]; unsigned int nExpire; D2LaunchCharEntryStrc* pNext;
};
extern int gnSelected_0070CC00; // 0x0070CC00
extern int gnSelectionA_0070CC04; // 0x0070CC04
extern int gnSelectionB_0070CC08; // 0x0070CC08
extern int gnVisibleRows_0070CC0C; // 0x0070CC0C
extern int gnCount_00779DC4; // 0x00779DC4
extern int gnTopRow_00779DC8; // 0x00779DC8
extern int gbFlag_00779DD8; // 0x00779DD8
extern D2LaunchCharEntryStrc* gpCharList_00779DBC; // 0x00779DBC
static D2LaunchCharEntryStrc* gpCurrent_00779DC0; // 0x00779DC0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInverseMasks[]; // 0x006CE2E8
extern "C" const char gszCharSelFile[]; // 0x006D4DBC
extern "C" const char gszNameTagFormat[]; // 0x006D4E34
extern "C" const char gszLevelFormat[]; // 0x006D4E24
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sprintf(char*,const char*,...); // 0x006823FD
int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
int __cdecl sub_004390A0_UpdateSelection(); // 0x004390A0
void* __fastcall FOG_Alloc(int,const char*,int,int); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc*,int); // 0x004F96F0
void __fastcall sub_004F9740(D2WinControlStrc*,int); // 0x004F9740
void __stdcall sub_004FD0B0_SetSprite(D2WinControlStrc*,int,void*); // 0x004FD0B0
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc*); // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc*,const Unicode*,int,int,int); // 0x004FC9B0
void __fastcall D2Win_10046(D2WinControlStrc*,const char*,int); // 0x004FCFF0
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0
D2CompositeUnitStrc* __stdcall sub_005066C0_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0
void __stdcall D2Win_10149(D2CompositeUnitStrc* ptUnit, unsigned char nValue); // 0x005051A0
void __stdcall D2Win_10151(D2CompositeUnitStrc* ptUnit, int nFrame); // 0x00505260
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode); // 0x005042F0
void __stdcall sub_005052B0_SetAnimX(void*,int); // 0x005052B0
void __stdcall sub_005052F0_SetAnimY(void*,int); // 0x005052F0
void __stdcall sub_00505360_SetAnimFlags(void*,unsigned int); // 0x00505360
Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700
void __fastcall sub_00526F20_ToUnicode(Unicode*,const char*,int); // 0x00526F20
extern D2WinControlStrc* gpControl_007799F0; // 0x007799F0
extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4
extern D2WinControlStrc* gpControl_00779A1C; // 0x00779A1C
extern D2WinControlStrc* gpControl_00779B60; // 0x00779B60
extern D2WinControlStrc* gpControl_00779B64; // 0x00779B64
extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68
extern D2WinControlStrc* gpControl_00779C70; // 0x00779C70
extern D2WinControlStrc* gpControl_00779C78; // 0x00779C78
extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94
extern int gaSlotY_007799FC[]; // 0x007799FC

extern int gnLaunchMode_007795EC; // 0x007795EC
extern int gnBusy_00779DAC; // 0x00779DAC
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern D2WinControlStrc* gpControl_00779DD0; // 0x00779DD0
extern D2WinControlStrc* gaRowControls_00779A20[]; // 0x00779A20
extern "C" const char gszTagFormat[]; // 0x006D4E2C
void __cdecl sub_004380F0_UpdateCharList(); // 0x004380F0
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
void __fastcall sub_004FB740_SetTextOffset(D2WinControlStrc*,int,int); // 0x004FB740
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
const char* __stdcall D2Win_10161(int,int,int,int); // 0x005068A0
void __cdecl sub_005269D0(int,Unicode*,const Unicode*,...); // 0x005269D0
extern "C" char* __cdecl strcat(char*,const char*);
__declspec(noinline) static unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime);
static unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime); // 0x004380B0
// 0x004380B0
static unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime) {
    long nNow;
    const unsigned int nTime=_time32(&nNow);
    if(nExpireTime<=nTime) return 0;
    return (nExpireTime-nTime)/86400;
}
static __forceinline int GetCharType(D2LaunchCharEntryStrc* entry)
{
    return entry ? entry->nType : 0;
}
// 0x00438560
void __cdecl sub_00438560_Refresh()
{
    if(sub_00408F20_HasExpansionMpq()) {sub_004380F0_UpdateCharList();return;}
    D2LaunchCharEntryStrc* entry=gpCharList_00779DBC;
    int y=gaSlotY_007799FC[0]-13;
    int index=0;
    char unusedText[256];
    sub_005263E0(unusedText,D2LANG_GetStringFromTblIndex(0x1419),256);
    sub_004F9740(gpControl_00779D90,0);
    for(int i=0;i<gnVisibleRows_0070CC0C;++i) {
        sub_004FB6A0_ClearText(gaRowControls_00779A20[i]);
        if(STRTABLE_GetLanguage()==7) sub_004FB740_SetTextOffset(gaRowControls_00779A20[i],-1,-5);
    }
    if(gpControl_00779DD0) sub_004FB6A0_ClearText(gpControl_00779DD0);
    if(gnLaunchMode_007795EC==1 && gnBusy_00779DAC) return;
    for(;entry;entry=entry->pNext,++index) {
        if(index>=gnTopRow_00779DC8 && index<gnTopRow_00779DC8+gnVisibleRows_0070CC0C) {
            int row=index-gnTopRow_00779DC8;
            sub_005052B0_SetAnimX(entry->pAnim,0x221);
            sub_005052F0_SetAnimY(entry->pAnim,y);
            if(entry->nStatus==1) {
                sub_00505360_SetAnimFlags(entry->pAnim,0);
                sub_004FD0B0_SetSprite(gpControl_00779D90,0x200,(void*)(gaSlotY_007799FC[row]-3));
                sub_004F9740(gpControl_00779D90,1);
                sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x1419),1,0,0);
                if(gnLaunchMode_007795EC==1 && gbFlag_00779DD8) {
                    sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x1416),0,0,0);
                    sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x1417),0,0,0);
                } else {
                    sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x1418),0,0,0);
                    sub_004FC9B0_SetText(gaRowControls_00779A20[row],entry->wszName,0,0,0);
                }
                goto VISIBLE_END;
            }
            const int hardcore=entry->wFlags&4;
            unsigned int flags=1;
            if(entry->wFlags&8) flags|=gdwBitMasks[4];else flags&=gdwInverseMasks[4];
            if(hardcore) flags|=gdwBitMasks[5];else flags&=gdwInverseMasks[5];
            sub_00505360_SetAnimFlags(entry->pAnim,flags);
            if(entry->nStatus==2) {
                sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x2B3B),1,0,0);
                goto VISIBLE_END;
            }
            if(entry->nStatus!=0) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x3B0);exit(-1);}
            char text[100];text[0]=0;
            Unicode className[100];
            const int bExpansion=entry->wFlags&32;
            const char* title=D2Win_10161(GetCharType(entry),(entry->wFlags>>8)&31,hardcore,bExpansion);
            if(title) strcat(text,title);
            strcat(text,entry->szName);
            if(strlen(entry->szTag)) {
                int length=strlen(text);
                char* end=text+length;
                sprintf(end,gszTagFormat,entry->szTag);
            }
            D2Win_10046(gaRowControls_00779A20[row],text,hardcore?1:4);
            sub_00437F60_GetClassName(className,entry->nType);
            Unicode description[100];
            Unicode level[10];
            sprintf(text,gszLevelFormat,entry->nLevel);
            sub_00526F20_ToUnicode(level,text,9);
            sub_005267E0(description,D2LANG_GetStringFromTblIndex(0xFD9));
            sub_00526700(description,level);
            sub_00526700(description,className);
            sub_004FC9B0_SetText(gaRowControls_00779A20[row],description,0,0,0);
            if(entry->wFlags&32) sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x2B45),2,0,0);
            if(entry->nFlag32E) sub_004FC9B0_SetText(gaRowControls_00779A20[row],D2LANG_GetStringFromTblIndex(0x2AAF),4,0,0);
            unsigned int days=sub_004380B0_GetDaysLeft(entry->nExpire);
            if(gnLaunchMode_007795EC==1 && days<=60) {
                int color=1;unsigned short str;
                if(days==0) str=0x2B7E;
                else if(days<2) str=0x2B7C;
                else {str=0x2B7D;if(days>=15) color=0;}
                sub_005269D0(100,description,D2LANG_GetStringFromTblIndex(str),days);
                sub_004FC9B0_SetText(gaRowControls_00779A20[row],description,color,0,0);
            }
VISIBLE_END:
            y+=93;
        } else sub_00505360_SetAnimFlags(entry->pAnim,0);
    }
}
