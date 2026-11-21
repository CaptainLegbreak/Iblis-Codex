#include "D2Launch.h"
#include "D2MultiTypes.h"

struct D2FuncTable_0077ABF0Strc;

void __cdecl sub_00435330_ShowLoginScreen(); // 0x00435330

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gnStatusDots_007799B4; // 0x007799B4
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __fastcall sub_004F9190(); // 0x004F9190
void __cdecl sub_00432100_CreateLoginScreen(); // 0x00432100
void __cdecl sub_00436F30_CreateEmailScreen(); // 0x00436F30
void __cdecl sub_004371E0_UpdatePasswordOk(); // 0x004371E0
void __cdecl sub_004370C0_CreateInfoScreen(); // 0x004370C0
void __cdecl sub_004372B0_CreatePasswordScreen(); // 0x004372B0
int __cdecl sub_0043B830(); // 0x0043B830

// 0x004370B0
int __stdcall sub_004370B0_ShowLoginScreen(int unused)
{
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x004371B0
int __stdcall sub_004371B0_OnLoginScreen(int nArg)
{
    sub_00432100_CreateLoginScreen();
    return 1;
}

// 0x004371C0
int __stdcall sub_004371C0_OnEmailScreen(int nArg)
{
    sub_00436F30_CreateEmailScreen();
    return 1;
}

// 0x004371D0
int __stdcall sub_004371D0_OnShowLogin(int nArg)
{
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x004372A0
int __stdcall sub_004372A0_OnEnter(int nArg)
{
    sub_004371E0_UpdatePasswordOk();
    return 1;
}

// 0x004374E0
int __stdcall sub_004374E0_OnInfoScreen(int nArg)
{
    sub_004370C0_CreateInfoScreen();
    return 1;
}

// 0x00437710
int __stdcall sub_00437710_OnInfoScreen(int nArg)
{
    sub_004370C0_CreateInfoScreen();
    return 1;
}

// build: context sub_004374F0_UpdateStatusWait
int __stdcall sub_004374F0_UpdateStatusWait(int nArg)
{
    sub_00436AD0_UpdateStatus();
    if (!gnStatusDots_007799B4)
    {
        sub_0043B820_Clear();
        gnStatusDots_007799B4 = (int)gpFuncTable_0077ABF0->pfnSlot04();
        if (!gnStatusDots_007799B4)
            return 1;
    }
    if (WaitForSingleObject((void*)gnStatusDots_007799B4, 0) == 0)
        sub_004F9190();
    if (sub_0043B830())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}

// 0x00437720
int __stdcall sub_00437720_OnPasswordScreen(int nArg)
{
    sub_004372B0_CreatePasswordScreen();
    return 1;
}
