#include "D2Gdi.h"
#include "D2Win32Base.h"
#include "D2GfxTypes.h"

struct D2Callbacks006C7CF0Strc;
struct D2CriticalSectionStrc;
struct D2RgbQuadStrc;
struct D2RgbQuad006C7FA0Strc;

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);

struct D2Callbacks006C7CF0Strc
{
    void (__fastcall* pfnCallback00)(int a, int b, int c, int d);
};

void __cdecl sub_006C8960_DeleteGraphicObject(); // 0x006C8960
extern void* ghObject_0098A164; // 0x0098A164
extern D2Callbacks006C7CF0Strc* gpCallbacks_007C914C; // 0x007C914C

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern int gnValue_007C9144; // 0x007C9144
void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB); // 0x006C9280

struct D2RgbQuadStrc { unsigned char nBlue, nGreen, nRed, nReserved; };

extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd);
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC);
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);
extern "C" __declspec(dllimport) unsigned int __stdcall SetDIBColorTable(void* hDC, unsigned int nStart, unsigned int nCount, const D2RgbQuadStrc* pColors);
extern "C" __declspec(dllimport) void* __stdcall SelectPalette(void* hDC, void* hPalette, int bForceBackground);
extern "C" __declspec(dllimport) unsigned int __stdcall RealizePalette(void* hDC);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* pRect);
extern "C" __declspec(dllimport) int __stdcall StretchBlt(void* hDest, int nX, int nY, int nWidth, int nHeight, void* hSrc, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight, unsigned long nRop);
extern "C" __declspec(dllimport) int __stdcall GdiFlush();
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);
void* __stdcall WINDOW_GetWindow(); // 0x004F59A0
extern int gnRenderHeight; // 0x007C913C
extern D2RgbQuadStrc gaPalette_00989C40[256]; // 0x00989C40
extern void* ghPalette; // 0x0098A160

struct D2RgbQuad006C7FA0Strc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7C10Strc* pEntries);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2RgbQuad006C7FA0Strc gatGdiColors[256]; // 0x00989C40
extern D2PaletteEntry006C7C10Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150



// 0x006C7D80
int __fastcall sub_006C7D80_LockAndSend(void* pObject, char nKey, int a, int b)
{
    if (gnValue_007C9144)
    {
        return 0;
    }
    D2_ASSERT(gpLock_007C9134, 0x10D);
    EnterCriticalSection(gpLock_007C9134);
    if (pObject)
    {
        sub_006C9280_Apply(1, nKey, a, b);
    }
    return 1;
}


void* ghRenderWindow; // 0x007C9140

// 0x006C7E30
int __cdecl sub_006C7E30_BlitWindow()
{
    void* hDC = GetDC(ghRenderWindow);
    void* hMemoryDC = CreateCompatibleDC(hDC);
    SelectObject(hMemoryDC, ghObject_0098A164);
    SetDIBColorTable(hMemoryDC, 0, 256, gaPalette_00989C40);
    SelectPalette(hDC, ghPalette, 0);
    RealizePalette(hDC);
    tagRECT tRect;
    GetClientRect(WINDOW_GetWindow(), &tRect);
    StretchBlt(hDC, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top,
// build: symbol ?gnRenderWidth@* 0x007C9138
        hMemoryDC, 0, 0, gnRenderWidth, gnRenderHeight, 0xCC0020);
    GdiFlush();
    DeleteDC(hMemoryDC);
    ReleaseDC(ghRenderWindow, hDC);
    return 1;
}

// 0x006C7F90
void __fastcall sub_006C7F90_GetScreenSize(int* width, int* height)
{
    *width = gnRenderWidth;
    *height = gnRenderHeight;
}


D2PaletteTableStrc gtPaletteView; // 0x0098A040

// 0x006C8000
void __fastcall sub_006C8000_SetPaletteView(const D2PaletteTableStrc* source)
{
    gtPaletteView = *source;
    gpGfxPaletteView_007C9150 = &gtPaletteView;
}

// 0x006C8030
void __cdecl sub_006C8030_Nop()
{
}

// 0x006C8040
void __cdecl sub_006C8040_Nop()
{
}

// 0x006C8070
void __cdecl sub_006C8070_Nop()
{
}

// 0x006C8080
void __stdcall sub_006C8080_Nop(int unused1, int unused2, int unused3)
{
}

// 0x006C8090
void __stdcall sub_006C8090_Nop(int unused1, int unused2, int unused3, int unused4)
{
}

// 0x006C80A0
void __cdecl sub_006C80A0_Nop()
{
}
