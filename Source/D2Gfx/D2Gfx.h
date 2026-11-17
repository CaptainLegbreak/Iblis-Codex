#pragma once

struct tagRECT;

extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* hWnd); // 0x006CC4E0
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall ShowCursor(int bShow); // 0x006CC4D8
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow); // 0x006CC4EC
extern "C" __declspec(dllimport) long __stdcall ChangeDisplaySettingsA(void* lpDevMode, unsigned long dwFlags); // 0x006CC4F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern int gnDisplayType; // 0x007C8CB0
extern void* ghInstance_007C8CA8; // 0x007C8CA8
void __cdecl sub_004F8EA0(); // 0x004F8EA0
