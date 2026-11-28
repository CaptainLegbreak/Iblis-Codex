#include "D2DataTbls.h"
#include "D2TxtItems.h"
#include "FogApi.h"

extern D2CubeMainTxt* gpCubeMainTxt; // 0x0096D628
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09
extern int gnCubeMainTxtRecordCount; // 0x0096D62C

#define CUBE_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0066A1A0
void __fastcall DATATBLS_UnloadCubeMainTxt()
{
    DATATBLS_UnloadBin(gpCubeMainTxt);
}

// 0x0066A1B0
D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex)
{
    CUBE_ASSERT(gpCubeMainTxt, 846);
    CUBE_ASSERT(nIndex < gnCubeMainTxtRecordCount, 847);

    return &gpCubeMainTxt[nIndex];
}

// 0x0066A200
int __fastcall DATATBLS_GetCubemainTxtRecordCount()
{
    return gnCubeMainTxtRecordCount;
}

// 0x0066A260
void __fastcall sub_0066A260_PlayerDataFreeHook(D2UnitStrc* pUnit)
{
}

// 0x0066A270
void __fastcall sub_0066A270_Nop(void* hArchive)
{
}

// build: symbol ?D2COMMON_10916_Return@* 0x0066A280
void __fastcall D2COMMON_10916_Return()
{
}

#include "gen/data/Source/D2Common/Unknown_0066A1A0.inc"
