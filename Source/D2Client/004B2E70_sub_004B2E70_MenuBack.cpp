extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __cdecl sub_00487C20_ResetButtonsFromState5();                                                         // 0x00487C20
void __cdecl sub_004B1E80();                                                                                // 0x004B1E80
void __stdcall sub_004B2650(int nArg1, int nArg2);                                                          // 0x004B2650
int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020

extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern void* gpRes_007C0D5F;                                                                                // 0x007C0D5F

// 0x004B2E70
int __cdecl sub_004B2E70_MenuBack()
{
    if (gnGlobal_007C0D31 == 5)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B1E80();
        return 1;
    }
    if (gnGlobal_007C0C6B == 4)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B2650(0, 0);
        return 1;
    }
    sub_00466FE0();
    D2_ASSERT(gnGlobal_007C0C6B != 4, 0x14F9);
    return 1;
}

// 0x004B2F00
int __cdecl sub_004B2F00_MenuClose()
{
    sub_004B8020(gpRes_007C0D5F);
    gpRes_007C0D5F = 0;
    if (gnGlobal_007C0D31 == 5)
    {
        sub_004B5C60_Handler();
        return 1;
    }
    sub_00487C20_ResetButtonsFromState5();
    gnGlobal_007C0C6B = 3;
    sub_00466FE0();
    return 1;
}
