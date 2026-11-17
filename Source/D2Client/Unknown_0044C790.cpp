#include "D2Client.h"

#define OFFSET(T,m) ((unsigned int)&(((T*)0)->m))
struct D2DrlgStrc;
struct Context;
struct Auxiliary;
struct Allocation;
struct UnitPrefix;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __cdecl sub_0044C750_InitRooms(); // 0x0044C750
void __cdecl sub_00465AA0(); // 0x00465AA0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __stdcall sub_0061AEF0(D2ActiveRoomStrc* pRoom); // 0x0061AEF0
void __cdecl sub_0046BEB0(); // 0x0046BEB0
void __fastcall sub_00470350(int nValue); // 0x00470350
int __stdcall sub_0061BFC0(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061BFC0
void __cdecl sub_004646C0(); // 0x004646C0
D2DrlgStrc* __stdcall sub_0061AA90(D2DrlgActStrc* pAct); // 0x0061AA90
void __stdcall sub_0061B920(D2DrlgStrc* pDrlg); // 0x0061B920
void __cdecl sub_00459020(); // 0x00459020
void __stdcall sub_0061AA20(D2DrlgActStrc* pAct); // 0x0061AA20
extern unsigned long gdwTickCount_007A048C; // 0x007A048C
extern unsigned int gnTickCounter_007A0498; // 0x007A0498
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634

typedef unsigned int U32;

typedef unsigned char U8;

struct UnitPrefix { U32 prefix0; U32 prefix4; U32 prefix8; U32 identifier; };

typedef char check_UnitPrefix_identifier[OFFSET(UnitPrefix,identifier)==12?1:-1];

extern "C" UnitPrefix* __cdecl sub_004680A0_GetSelected();
extern "C" void __fastcall sub_004786A0_SendPacket(U8 command,U32 first,U32 second);
extern "C" Auxiliary* __cdecl sub_004646A0_GetAuxiliary();
extern "C" void __stdcall sub_0061C240_Configure(Context* context,Auxiliary* auxiliary,int mode,int angle,int flag);
extern "C" void __cdecl sub_0049F960_Cleanup();
extern "C" void __stdcall sub_006612A0_Release(Allocation* allocation);
extern "C" int __cdecl sub_0044DCC0_Mode();
extern "C" Context* gContext; // 0x007A0634
extern "C" U8 gDeferred; // 0x007A060E
extern "C" U32 gCleanupState;
extern "C" Allocation* gAllocation;
extern "C" int gCoordinateBase;
extern "C" int gCoordinateOffset;

// 0x0044C790
void __cdecl sub_0044C790_Update()
{
    gdwTickCount_007A048C = GetTickCount();
    sub_0044C750_InitRooms();
    sub_00465AA0();
    sub_0061AEF0(sub_004646A0_GetPlayerRoom());
    sub_0046BEB0();
    sub_00470350(1);
    if (sub_0061BFC0(gpAct_007A0634, sub_004646A0_GetPlayerRoom()))
        sub_004646C0();
    sub_0061B920(sub_0061AA90(gpAct_007A0634));
    sub_00459020();
    if (++gnTickCounter_007A0498 % 13 == 0)
        sub_0061AA20(gpAct_007A0634);
}

// 0x0044C820
extern "C" void __cdecl sub_0044C820_ConfigureOrDefer()
{
    if(gContext != (Context*)0)
        sub_0061C240_Configure(gContext,sub_004646A0_GetAuxiliary(),5,0,1);
    else
        gDeferred=1;
}

extern "C" void __cdecl sub_004A1730_ClearAllocation()
{
    sub_0049F960_Cleanup();
    Allocation* allocation=gAllocation;
    gCleanupState=0;
    if(allocation) {
        sub_006612A0_Release(allocation);
        gAllocation=(Allocation*)0;
    }
}

extern "C" int __cdecl sub_00486B00_Coordinate()
{
    if(!sub_0044DCC0_Mode())
        return gCoordinateOffset+gCoordinateBase-65;
    return gCoordinateOffset+gCoordinateBase-64;
}
