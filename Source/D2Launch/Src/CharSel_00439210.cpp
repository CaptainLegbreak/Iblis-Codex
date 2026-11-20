struct Unicode
{
    unsigned short wChar;
    Unicode(); // 0x0042F530
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

__declspec(noinline) static int sub_00438030_IsNotListedCode(int nValue);
static int sub_00438030_IsNotListedCode(int nValue); // 0x00438030
// 0x00438030
static int sub_00438030_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

struct D2WinControlStrc;
struct D2LaunchCharEntryStrc {
    char szName[0x100]; Unicode wszName[0x100];
    unsigned char aBlock0x300[16],aBlock0x310[16];
    unsigned char nType,pad321; unsigned short nLevel,wFlags;
    char pad326[4],szTag[10]; int nStatus; void* pAnim;
    char pad33C[16]; D2LaunchCharEntryStrc* pNext;
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
void __cdecl sub_004390A0_RedrawExpansion(); // 0x004390A0
void* __fastcall FOG_Alloc(int,const char*,int,int); // 0x0040B380
void __fastcall FOG_Free(void*,const char*,int,int); // 0x0040B3C0
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc*,int); // 0x004F96F0
void __fastcall sub_004F9740(D2WinControlStrc*,int); // 0x004F9740
void __stdcall sub_004FD0B0_SetSprite(D2WinControlStrc*,int,void*); // 0x004FD0B0
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc*); // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc*,const Unicode*,int,int,int); // 0x004FC9B0
void __fastcall D2Win_10046(D2WinControlStrc*,const char*,int); // 0x004FCFF0
void __stdcall sub_005041B0_FreeAnim(void*,int); // 0x005041B0
void* __stdcall sub_005066C0_CreateAnim(int,int,unsigned char*,unsigned char*); // 0x005066C0
void __stdcall sub_005051A0_SetAnimField(void*,int); // 0x005051A0
void __stdcall sub_00505260_SetAnimField(void*,int); // 0x00505260
void __fastcall sub_005042F0_SetAnimMode(void*,int); // 0x005042F0
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
extern void* gaSprites_007799FC[]; // 0x007799FC

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00439210
int __cdecl sub_00439210_Redraw()
{
    if(sub_00408F20_HasExpansionMpq()) {sub_004390A0_RedrawExpansion();return 1;}
    if(!gnCount_00779DC4) gnSelected_0070CC00=0;
    int row=gnSelected_0070CC00-gnTopRow_00779DC8;
    sub_004F96F0_ControlClearState(gpControl_007799F4,gnCount_00779DC4>0 && gnSelected_0070CC00>gnSelectionA_0070CC04 && gnSelected_0070CC00!=gnSelectionB_0070CC08 ? 1:0);
    sub_004F96F0_ControlClearState(gpControl_00779C68,1);
    if(row>=0 && row<gnVisibleRows_0070CC0C) {
        if(gnSelected_0070CC00==gnSelectionA_0070CC04 && gbFlag_00779DD8) {
            sub_004FD0B0_SetSprite(gpControl_00779C78,0x202,gaSprites_007799FC[row]);
            sub_004F9740(gpControl_00779C78,1);
            sub_004F9740(gpControl_00779D94,0);
        } else {
            sub_004FD0B0_SetSprite(gpControl_00779D94,0x202,gaSprites_007799FC[row]);
            sub_004F9740(gpControl_00779D94,1);
            sub_004F9740(gpControl_00779C78,0);
        }
    } else {
        sub_004F9740(gpControl_00779D94,0);
        sub_004F9740(gpControl_00779C78,0);
    }
    if(gnTopRow_00779DC8>0) sub_004F9740(gpControl_00779A1C,1);
    else sub_004F9740(gpControl_00779A1C,0);
    if(gnTopRow_00779DC8+gnVisibleRows_0070CC0C<gnCount_00779DC4) sub_004F9740(gpControl_00779B64,1);
    else sub_004F9740(gpControl_00779B64,0);
    int index=0;
    D2LaunchCharEntryStrc* entry=gpCharList_00779DBC;
    if(!gpCharList_00779DBC) return 1;
    do {
        if(gnSelected_0070CC00==index) break;
        entry=entry->pNext;
        ++index;
    } while(entry);
    if(!entry) return 1;
    if(gpCurrent_00779DC0) {
        if(!gpCurrent_00779DC0->nStatus) sub_005041B0_FreeAnim(gpCurrent_00779DC0->pAnim,1);
        FOG_Free(gpCurrent_00779DC0,gszCharSelFile,0x5DE,0);
        gpCurrent_00779DC0=0;
    }
    gpCurrent_00779DC0=(D2LaunchCharEntryStrc*)FOG_Alloc(0x350,gszCharSelFile,0x5E2,0);
    SMemCopy(gpCurrent_00779DC0,entry,0x350);
    gpCurrent_00779DC0->pNext=0;
    unsigned short statusText;
    if(entry->nStatus==1) {
        sub_004FB6A0_ClearText(gpControl_00779B60);
        statusText=0x1419;
    } else if(entry->nStatus==2) {
        sub_004FB6A0_ClearText(gpControl_00779B60);
        statusText=0x2B3B;
    } else goto BUILD_MODEL;
    sub_004FC9B0_SetText(gpControl_00779B60,D2LANG_GetStringFromTblIndex(statusText),1,0,0);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    return 1;
BUILD_MODEL:
    unsigned char type=gpCurrent_00779DC0->nType;
    int mode=5;
    if(gpCurrent_00779DC0->wFlags&4) {
        if(gpCurrent_00779DC0->wFlags&8) type=8+(sub_00438030_IsNotListedCode(type)!=0);
        else if(sub_00408F20_HasExpansionMpq() || gpCurrent_00779DC0->nType<5) mode=1;
    }
    gpCurrent_00779DC0->pAnim=sub_005066C0_CreateAnim(type,mode,gpCurrent_00779DC0->aBlock0x300,gpCurrent_00779DC0->aBlock0x310);
    if(!gpCurrent_00779DC0->pAnim) {
        for(int i=0;i<16;++i) {gpCurrent_00779DC0->aBlock0x300[i]=0;gpCurrent_00779DC0->aBlock0x310[i]=255;}
        gpCurrent_00779DC0->aBlock0x300[1]=1;
        gpCurrent_00779DC0->pAnim=sub_005066C0_CreateAnim(7,5,gpCurrent_00779DC0->aBlock0x300,gpCurrent_00779DC0->aBlock0x310);
    }
    if(!gpCurrent_00779DC0->pAnim) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x619);exit(-1);}
    sub_005051A0_SetAnimField(gpCurrent_00779DC0->pAnim,0);
    sub_00505260_SetAnimField(gpCurrent_00779DC0->pAnim,0);
    sub_005042F0_SetAnimMode(gpCurrent_00779DC0->pAnim,5);
    sub_005052B0_SetAnimX(gpCurrent_00779DC0->pAnim,0x118);
    sub_005052F0_SetAnimY(gpCurrent_00779DC0->pAnim,0x172);
    unsigned int flags=5;
    if(gpCurrent_00779DC0->wFlags&8) flags|=gdwBitMasks[4];else flags&=gdwInverseMasks[4];
    if(gpCurrent_00779DC0->wFlags&4) flags|=gdwBitMasks[5];else flags&=gdwInverseMasks[5];
    if(gpCurrent_00779DC0->wFlags&32) flags|=gdwBitMasks[12];else flags&=gdwInverseMasks[12];
    sub_00505360_SetAnimFlags(gpCurrent_00779DC0->pAnim,flags);
    Unicode className[100];
    char text[100];
    sub_004FB6A0_ClearText(gpControl_00779B60);
    if(strlen(gpCurrent_00779DC0->szTag)) {
        sprintf(text,gszNameTagFormat,gpCurrent_00779DC0->szName,gpCurrent_00779DC0->szTag);
        D2Win_10046(gpControl_00779B60,text,0);
    } else D2Win_10046(gpControl_00779B60,gpCurrent_00779DC0->szName,0);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_00437F60_GetClassName(className,gpCurrent_00779DC0->nType);
    Unicode description[100];
    Unicode level[10];
    sprintf(text,gszLevelFormat,entry->nLevel);
    sub_00526F20_ToUnicode(level,text,9);
    sub_005267E0(description,D2LANG_GetStringFromTblIndex(0xFD9));
    sub_00526700(description,level);
    sub_00526700(description,className);
    sub_004FC9B0_SetText(gpControl_007799F0,description,0,0,0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    if(gpCurrent_00779DC0->wszName[0].wChar) sub_004FC9B0_SetText(gpControl_00779C70,gpCurrent_00779DC0->wszName,0,0,0);
    else sub_004FC9B0_SetText(gpControl_00779C70,D2LANG_GetStringFromTblIndex(0x142C),0,0,0);
    if(entry->wFlags&32) sub_004F96F0_ControlClearState(gpControl_00779C68,0);
    return 1;
}
