struct Unicode
{
    unsigned short wChar;
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

int __cdecl sub_0040EB10();                                                                                 // 0x0040EB10
void __fastcall sub_00482B40(unsigned int nTick);                                                           // 0x00482B40
void __fastcall sub_004BA020(unsigned int nTick);                                                           // 0x004BA020
void __fastcall sub_004DCAA0(unsigned int nTick);                                                           // 0x004DCAA0
int __cdecl sub_004DF870();                                                                                 // 0x004DF870
void __cdecl sub_004DF890();                                                                                // 0x004DF890
void __fastcall sub_004E42E0(unsigned int nTick);                                                           // 0x004E42E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

unsigned int gdwGlobal_007BC9BC;                                                                            // 0x007BC9BC
extern char gbCinematicStop_007BC9D4;                                                                       // 0x007BC9D4
extern char gbCinematicWide_007BC9D6;                                                                       // 0x007BC9D6
extern char gbCinematicBusy_007BC9D7;                                                                       // 0x007BC9D7
extern char gbCinematicChain_007BC9D8;                                                                      // 0x007BC9D8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0

// 0x00482C20
void __cdecl sub_00482C20_Tick()
{
    if (sub_004DF870())
    {
        sub_004E42E0(gdwGlobal_007BC9BC);
        sub_004DCAA0(gdwGlobal_007BC9BC);
        sub_00482B40(gdwGlobal_007BC9BC);
        sub_004BA020(gdwGlobal_007BC9BC);
        sub_004DF890();
        ++gdwGlobal_007BC9BC;
        Sleep(0);
    }
}

// 0x00483310
void __cdecl sub_00483310_ResetCinematicFlags()
{
    gbCinematicStop_007BC9D4 = 0;
    gbCinematicWide_007BC9D6 = !sub_0040EB10();
    gbCinematicChain_007BC9D8 = 0;
    gbCinematicBusy_007BC9D7 = 0;
}

// 0x00483350
unsigned char __cdecl sub_00483350_IsCinematicBusy()
{
    return gbCinematicBusy_007BC9D7;
}

// 0x004834A0
const Unicode* __fastcall sub_004834A0_SkipBracketTag(const Unicode* pString)
{
    int n = sub_00526800(pString);
    for (; n > 0; --n)
    {
        if (pString[n].wChar == ']')
        {
            break;
        }
    }
    if (pString[n].wChar == ']' && n >= 3 && pString[n - 3].wChar == '[')
    {
        return &pString[n + 1];
    }
    return pString;
}

// 0x00483E10
int __cdecl sub_00483E10_IsNpcStateIdle()
{
    if (gdwGlobal_007BCBF0 == 0 || gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4)
    {
        return 1;
    }
    return 0;
}
