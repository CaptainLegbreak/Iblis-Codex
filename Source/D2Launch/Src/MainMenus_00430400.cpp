#include "D2Launch.h"

struct D2WinTextBoxStrc;

struct D2LaunchRecordStrc
{
    char unk0x000[0x1EF];
    char aFlags1EF[2];
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x4C];
    int (__fastcall* pfnSlot4C)();
};
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
int gdwGlobal_0077932C;                                                                                     // 0x0077932C
D2WinControlStrc* gapControlsB_00779350[0x40];                                                              // 0x00779350
extern int gnControlCountB_00779944;                                                                        // 0x00779944
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __stdcall CONTROL_GetType(D2WinControlStrc* pControl);                                                  // 0x004FA490
int __fastcall D2Win_10054(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FB950
int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __cdecl sub_004301A0();                                                                                // 0x004301A0
void __cdecl sub_00515020_FadeOutWaves();                                                                   // 0x00515020
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0043B080();                                                                                // 0x0043B080
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430

// 0x00430400
int __stdcall sub_00430400_PollSlot4C(int nArg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() == 0x65 || gdwGlobal_0077932C)
        sub_004F9190();
    return 1;
}

// 0x00430430
int __stdcall sub_00430430_OnBack(int nArg)
{
    sub_004301A0();
    return 1;
}

// 0x00430440
int __stdcall sub_00430440_ScrollUp(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB_00779944; ++i)
    {
        pControl = gapControlsB_00779350[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3304);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    if (nLines > 0)
        D2Win_10053((D2WinTextBoxStrc*)pControl, nLines - 1);
    return 1;
}

// 0x004304B0
int __stdcall sub_004304B0_ScrollDown(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB_00779944; ++i)
    {
        pControl = gapControlsB_00779350[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3327);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    D2Win_10053((D2WinTextBoxStrc*)pControl, nLines + 1);
    return 1;
}

// 0x00430730
int __stdcall sub_00430730_ToggleFlag04(int nArg)
{
    *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF ^= 4;
    return 1;
}

// 0x00430750
int __stdcall sub_00430750_ToggleFlag40(int nArg)
{
    *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF ^= 0x40;
    return 1;
}

// 0x00430770
int __stdcall sub_00430770_ToggleFlag20(int nArg)
{
    if (!sub_00408F20_HasExpansionMpq())
        return 0;
    *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF ^= 0x20;
    return 1;
}

// 0x004309B0
void __cdecl sub_004309B0_ClearLaunchState()
{
    gnLaunchState_007795E8 = 0;
}

// 0x00430BB0
int __stdcall sub_00430BB0_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00443C10
int __stdcall sub_00443C10_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00430C30
int __stdcall sub_00430C30_OnCancel(int nArg)
{
    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080();
    return 1;
}

// 0x00430C50
int __stdcall sub_00430C50_OnCreate(int nArg)
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0xFF);
    sub_0042F430_CreateControl(0x100);
    sub_0042F430_CreateControl(0x101);
    return 1;
}
