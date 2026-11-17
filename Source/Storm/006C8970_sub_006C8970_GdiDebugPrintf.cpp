struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd);                                          // 0x006CC44C
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC);                             // 0x006CC448
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc);                             // 0x006CC0A0
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h);                          // 0x006CC09C
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color);      // 0x006CC0AC
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color);        // 0x006CC0B0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);                              // 0x006CC0B4
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc);                                         // 0x006CC0D8

void* __cdecl sub_006C8020();                                                                               // 0x006C8020

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern unsigned long gdwGdiDebugTextColor_0074C5C0;                                                         // 0x0074C5C0
extern void* ghGdiDebugFont_0098A170;                                                                       // 0x0098A170
unsigned long gdwGdiDebugBkColor_0098A174;                                                                  // 0x0098A174

// 0x006C8970
void __fastcall sub_006C8970_GdiDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    int anText[0x200 / sizeof(int)];
    wvsprintfA((char*)anText, szFormat, args);
    void* hScreenDC = GetDC(0);
    void* hDC = CreateCompatibleDC(hScreenDC);
    SelectObject(hDC, sub_006C8020());
    SelectObject(hDC, ghGdiDebugFont_0098A170);
    SetTextColor(hDC, gdwGdiDebugTextColor_0074C5C0);
    SetBkColor(hDC, gdwGdiDebugBkColor_0098A174);
    SetBkMode(hDC, 1);
    tagRECT tRect;
    SetRect(&tRect, nX, nY, gnScreenWidth_007C9138 - nX, gnScreenHeight_007C913C - nY);
    DrawTextA(hDC, (char*)anText, -1, &tRect, 0);
    DeleteDC(hDC);
    ReleaseDC(0, hScreenDC);
}

#include "gen/data/Source/Storm/006C8970_sub_006C8970_GdiDebugPrintf.inc"
