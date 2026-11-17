#include "D2Client.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WeatherStrc
{
    char unk0x000[0x114];
    int unk0x114;
};
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00

static D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gbPhaseActive_007A8A1C;                                                                          // 0x007A8A1C
extern int gnPhase_007A8A24;                                                                                // 0x007A8A24

// 0x004723F0
int __cdecl sub_004723F0_GetPhase()
{
    return gnPhase_007A8A24;
}

// 0x00472530
static __forceinline void sub_00472530_SetPhaseActive(int bValue)
{
    gbPhaseActive_007A8A1C = bValue;
    if (bValue)
        sub_00473D00_SetPhase(2);
}

// 0x00472550
void __cdecl sub_00472550_ResetWeather()
{
    sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
    D2_ASSERT(!gpWeather_007A8A04->unk0x114, 0x15B);
}

void __fastcall sub_M110_Emit_00472530(int bValue)
{
    sub_00472530_SetPhaseActive(bValue - 1);
}
