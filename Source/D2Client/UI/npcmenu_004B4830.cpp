#include "D2Client.h"

struct Unicode { unsigned short wChar; Unicode(unsigned short ch=0):wChar(ch){} };
struct UnicodeChar:Unicode
{
    UnicodeChar(); // 0x0042F530
};
struct D2UnitStrc { int dwUnitType,dwClassId; void* pPool; int dwUnitId; };
struct D2CoordStrc { int nX,nY; };
struct tagRECT { int left,top,right,bottom; };
typedef int (__cdecl* D2MenuHandler)();
#pragma pack(push,1)
struct D2NpcIndexStrc { int nId,nCount; unsigned short awIds[5]; D2MenuHandler apfHandlers[5]; char bEnabled; };
#pragma pack(pop)
typedef char CheckNpcIndexSize[sizeof(D2NpcIndexStrc)==39?1:-1];
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT*,int,int,int,int); // 0x006CC498
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468
extern const char gszFormatD[]; // 0x006D57BC
extern D2ViewStrc* gpView_007A0640; // 0x007A0640
extern int gnGlobal_007C0D2D; // 0x007C0D2D
int gnGlobal_007C0DD0;        // 0x007C0DD0
extern unsigned int gnHirelingName_00725494; // 0x00725494
extern D2NpcIndexStrc gaNpcIndex_00726C48[]; // 0x00726C48
D2UnitStrc* __fastcall sub_00463990(int,int); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
void __fastcall sub_00455F20(int,int,int); // 0x00455F20
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc*); // 0x00464A60
void __stdcall UNITS_GetClientCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620900
void __fastcall sub_00476070_GetViewRect(D2ViewStrc*,int*,int*,int*,int*); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc*,int*,int*); // 0x004760C0
void __fastcall sub_004786D0_SendPacket38(unsigned char,int,int,int); // 0x004786D0
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __fastcall sub_004B3C20(int); // 0x004B3C20
int __cdecl sub_004B45D0_NpcMenuCancel(); // 0x004B45D0
int __cdecl sub_004B4620_NpcMenuCancelB(); // 0x004B4620
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int,int,D2MenuHandler,D2MenuHandler,int,int,int,int,int,int,int); // 0x004B7EB0
void __fastcall sub_004B8370(void*,int); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void*,const Unicode*,int,int,int,int,D2MenuHandler,int); // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode*,const Unicode*); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700
int __fastcall sub_00526800(const Unicode*); // 0x00526800
void __cdecl sub_005269D0(int,Unicode*,const Unicode*,...); // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode*,const char*,int); // 0x00526F20
int __stdcall UNITS_GetHealingCost(D2UnitStrc*); // 0x00622DE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc*); // 0x0062A530
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*,int,int); // 0x0065C310
static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25,1):0;
}
static __declspec(noinline) int sub_004B1C80_GetNpcDialogPos(D2CoordStrc*);
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004B1C80
static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if(NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(),pCoords);
        tagRECT tView;
        sub_00476070_GetViewRect(gpView_007A0640,&tView.left,&tView.top,&tView.right,&tView.bottom);
        D2CoordStrc tOffset;
        sub_004760C0_GetViewOffset(gpView_007A0640,&tOffset.nX,&tOffset.nY);
        tagRECT tRect;
        SetRect(&tRect,tOffset.nX,tOffset.nY,tOffset.nX+(tView.right-tView.left),tOffset.nY+(tView.bottom-tView.top));
        pCoords->nY += -150-tRect.top;
        pCoords->nX -= tRect.left;
        if(pCoords->nY<20)pCoords->nY=20;
        return 1;
    }
    return 0;
}
static __forceinline int NPC_FindIndex_Inline(D2UnitStrc* pNpc)
{
    if(!pNpc)return -1;
    const int nId=pNpc->dwClassId;
    for(int i=0;i<gnNpcIndexCount_00725A74;++i)
        if(gaNpcIndex_00726C48[i].nId==nId)return i;
    return 0;
}
// 0x004B4830
void __cdecl sub_004B4830_Rebuild()
{
    if(gpDialog_007C0D6B){sub_00408A60(&gszEmptyAssertText,sub_00408090(),0xC74);exit(-1);}
    if(!NPC_GetInteractUnit_Inline())
    {
        gnGlobal_007C0C6B=0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8,1,0);
        return;
    }
    if(gnGlobal_007C0D2D==252 || gnGlobal_007C0D2D==198 || gnGlobal_007C0D2D==515 || gnGlobal_007C0D2D==150)
    {
        D2UnitStrc* pPlayer=sub_00463DD0();
        sub_004786D0_SendPacket38(0x38,3,gnGlobal_007C0D25,!pPlayer?-1:pPlayer->dwUnitId);
    }
    D2CoordStrc tCoords;
    tCoords.nX=0;
    tCoords.nY=0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);
    gpDialog_007C0D6B=sub_004B7EB0_CreateDialog(tCoords.nX,tCoords.nY,sub_004B45D0_NpcMenuCancel,sub_004B4620_NpcMenuCancelB,0,0,1,0,0,0,1);
    sub_004B8370(gpDialog_007C0D6B,1);
    Unicode wszName[80];
    sub_005267E0(wszName,sub_00464A60_GetUnitName(NPC_GetInteractUnit_Inline()));
    sub_00526800(wszName);
    sub_004B85F0_AddTextLine(gpDialog_007C0D6B,wszName,21,0,4,1,0,0);
    int nIndex=NPC_FindIndex_Inline(NPC_GetInteractUnit_Inline());
    if(nIndex<0 || nIndex>=gnNpcIndexCount_00725A74)return;
    gnGlobal_007C0C6B=1;
    for(int i=0;i<gaNpcIndex_00726C48[nIndex].nCount-1;++i)
    {
        Unicode wszLine[512];
        unsigned short nStringId=gaNpcIndex_00726C48[nIndex].awIds[i];
        int bEnabled=1;
        if(nStringId==0x1507)
        {
            const Unicode* wszHireling=D2LANG_GetStringFromTblIndex(0x2B0D);
            if((unsigned short)gnHirelingName_00725494!=0x421)wszHireling=D2LANG_GetStringFromTblIndex((unsigned short)gnHirelingName_00725494);
            sub_005269D0(512,wszLine,D2LANG_GetStringFromTblIndex(0x58A8),wszHireling,gnGlobal_007C0DD0);
        }
        else if(nStringId==0xD09)
        {
            int nLife=STATLIST_UnitGetStatValue(sub_00463DD0(),6,0);
            if(nLife>=STATLIST_GetMaxLifeFromUnit(sub_00463DD0()))continue;
            int nCost=UNITS_GetHealingCost(sub_00463DD0());
            if(!nCost)nCost=1;
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex_00726C48[nIndex].awIds[i]));
            Unicode wszNumber[10] = {0,0,0,0,0,0,0,0,0,0};
            char szNumber[12];
            wsprintfA(szNumber,gszFormatD,nCost);
            sub_00526F20_ToUnicode(wszNumber,szNumber,9);
            sub_00526700(wszLine,wszNumber);
            if(!nCost)bEnabled=0;
        }
        else if(nStringId==0xFB4)
        {
            int bCharge=0;
            if(!QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,4,0) && !QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,4,1))bCharge=1;
            int nCount=ITEMS_GetNoOfUnidItems(sub_00463DD0());
            if(nCount)
            {
            gaNpcIndex_00726C48[nIndex].nCount=3;
            if(bCharge)
            {
                sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB5));
                UnicodeChar wszNumber[10];
                char szNumber[12];
                nCount*=100;
                wsprintfA(szNumber,gszFormatD,nCount);
                sub_00526F20_ToUnicode(wszNumber,szNumber,9);
                sub_00526700(wszLine,wszNumber);
            }
            else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB4));
            }
            else {gaNpcIndex_00726C48[nIndex].nCount=2;continue;}
        }
        else if(nStringId==0x2BA0)
        {
            if(QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,0))continue;
            if(QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,1)!=1)
            {
                if(sub_0044DCD0_GetDifficulty()!=2 || QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,1))continue;
            }
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex_00726C48[nIndex].awIds[i]));
        }
        else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(nStringId));
        sub_004B85F0_AddTextLine(gpDialog_007C0D6B,wszLine,15,0,0,1,gaNpcIndex_00726C48[nIndex].apfHandlers[i],bEnabled);
    }
    sub_004B85F0_AddTextLine(gpDialog_007C0D6B,D2LANG_GetStringFromTblIndex(0x102E),15,0,0,1,sub_004B45D0_NpcMenuCancel,1);
}
