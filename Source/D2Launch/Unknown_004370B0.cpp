#include "D2Launch.h"

#include "D2MultiTypes.h"

struct D2FuncTable_0077ABF0Strc;

void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0

extern int gnStatusDots; // 0x007799B4

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100

void __cdecl MAINMENUS_CreateEmailScreen(); // 0x00436F30

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0

void __cdecl MAINMENUS_CreateInfoScreen(); // 0x004370C0

void __cdecl MAINMENUS_CreatePasswordScreen(); // 0x004372B0

int __cdecl sub_0043B830(); // 0x0043B830

// 0x00437710
int __stdcall sub_00437710_OnInfoScreen(int nArg)
{
    MAINMENUS_CreateInfoScreen();
    return 1;
}

int __stdcall sub_004374F0_UpdateStatusWait(int nArg); // 0x004374F0

// 0x00437720
int __stdcall sub_00437720_OnPasswordScreen(int nArg)
{
    MAINMENUS_CreatePasswordScreen();
    return 1;
}
