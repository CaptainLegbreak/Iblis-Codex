extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

struct D2WeatherStrc
{
    char unk0x000[0x114];
    int unk0x114;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall sub_004726F0(int bForce);                                                                     // 0x004726F0
void __fastcall sub_006BCAC0_ResetDataArray(D2WeatherStrc* pArray);                                         // 0x006BCAC0

extern int gnGlobal_007A89E0;                                                                               // 0x007A89E0
static D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gbPhaseActive_007A8A1C;                                                                          // 0x007A8A1C
int gbPhaseBusy_007A8A20;                                                                                   // 0x007A8A20
extern int gnPhase_007A8A24;                                                                                // 0x007A8A24

// 0x00473DC0
void __cdecl sub_00473DC0_ToggleWeather()
{
    gbPhaseBusy_007A8A20 = !gbPhaseBusy_007A8A20;
    if (gbPhaseBusy_007A8A20)
    {
        gbPhaseActive_007A8A1C = 0;
        gnPhase_007A8A24 = 0;
        D2_ASSERT(sub_00463DD0(), 0x137);
        gnGlobal_007A89E0 = 0;
        sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        D2_ASSERT(!gpWeather_007A8A04->unk0x114, 0x15B);
    }
    else
    {
        sub_004726F0(1);
    }
}
