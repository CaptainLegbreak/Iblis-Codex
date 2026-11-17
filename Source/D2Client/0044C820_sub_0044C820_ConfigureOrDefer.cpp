typedef unsigned int U32;
typedef unsigned char U8;
#define OFFSET(T,m) ((unsigned int)&(((T*)0)->m))
struct UnitPrefix { U32 prefix0; U32 prefix4; U32 prefix8; U32 identifier; };
typedef char check_UnitPrefix_identifier[OFFSET(UnitPrefix,identifier)==12?1:-1];
struct Context;
struct Auxiliary;
struct Allocation;
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
