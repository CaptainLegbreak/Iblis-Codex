struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
void __cdecl sub_00472400_ResetPhaseState();                                                                // 0x00472400
int __stdcall sub_004726F0(int nArg);                                                                       // 0x004726F0
extern unsigned int gnPhaseMax_007A89C0;                                                                    // 0x007A89C0
extern int gnPhaseLevel_007A89E0;                                                                           // 0x007A89E0
extern int gnGlobal_007A8A08;                                                                               // 0x007A8A08
extern int gbPhaseActive_007A8A1C;                                                                          // 0x007A8A1C
extern int gbPhaseBusy_007A8A20;                                                                            // 0x007A8A20
extern int gnPhase_007A8A24;                                                                                // 0x007A8A24

// 0x00473D00
void __fastcall sub_00473D00_SetPhase(int nPhase)
{
    D2_ASSERT(nPhase >= 0 && nPhase <= 3, 0x12A);

    if (gbPhaseBusy_007A8A20 && nPhase != 0)
    {
        return;
    }

    if (gbPhaseActive_007A8A1C && nPhase != 2)
    {
        return;
    }

    gnPhase_007A8A24 = nPhase;
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x137);

    switch (nPhase)
    {
    case 0:
        gnPhaseLevel_007A89E0 = 0;
        break;

    case 1:
        sub_004726F0(0);
        gnPhaseMax_007A89C0 = sub_00472280(&pPlayer->pSeed, 0x20, 0xE0);
        break;

    case 2:
        sub_00472400_ResetPhaseState();
        break;

    case 3:
        gnGlobal_007A8A08 = 0;
        break;
    }
}
