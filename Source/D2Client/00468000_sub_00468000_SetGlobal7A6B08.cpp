extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey);                                                     // 0x004A9E60
void __fastcall sub_004AA030_SelectHotkey(int nSlot);                                                       // 0x004AA030
void __cdecl sub_00498C50_BeltHotkey0();                                                                    // 0x00498C50
void __cdecl sub_00498C90_BeltHotkey1();                                                                    // 0x00498C90
void __cdecl sub_00498CD0_BeltHotkey2();                                                                    // 0x00498CD0
void __cdecl sub_00498D10_BeltHotkey3();                                                                    // 0x00498D10

extern int gnGlobal_007A6B08;                                                                               // 0x007A6B08
extern int gdwGlobal_007A6ABC;                                                                              // 0x007A6ABC
extern int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0
extern int gdwGlobal_007A6AF0;                                                                              // 0x007A6AF0

// 0x00468000
void __fastcall sub_00468000_SetGlobal7A6B08(int nValue)
{
    gnGlobal_007A6B08 = nValue;
}

// 0x00468010
void __fastcall sub_00468010_SetState(int nValue, int nArg)
{
    gdwGlobal_007A6ABC = nValue;
    gnGlobal_007A6ADC = 6;
    gdwGlobal_007A6AE0 = nArg;
    gdwGlobal_007A6AF0 = 6;
}

// 0x00468B20
static __forceinline void sub_00468B20_HandleHotkey(int nHotkey)
{
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;
    if (nHotkey > 8 && !sub_0044DCC0())
        return;
    D2_ASSERT(nHotkey >= 0 || nHotkey <= 15, 0xFC);
    if (sub_004538D0(3))
        sub_004A9E60_AssignHotkey(nHotkey);
    else
        sub_004AA030_SelectHotkey(nHotkey);
}

// build: context sub_M115_Emit_00468B20
void __fastcall sub_M115_Emit_00468B20(int nHotkey)
{
    sub_00468B20_HandleHotkey(nHotkey);
}

// 0x00468F40
void __cdecl sub_00468F40_BeltHotkey0()
{
    sub_00498C50_BeltHotkey0();
}

// 0x00468F50
void __cdecl sub_00468F50_BeltHotkey1()
{
    sub_00498C90_BeltHotkey1();
}

// 0x00468F60
void __cdecl sub_00468F60_BeltHotkey2()
{
    sub_00498CD0_BeltHotkey2();
}

// 0x00468F70
void __cdecl sub_00468F70_BeltHotkey3()
{
    sub_00498D10_BeltHotkey3();
}
