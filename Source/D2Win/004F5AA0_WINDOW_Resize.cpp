struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2GraphicsInterfaceStrc
{
    void* unk0x00[9];
    int (__fastcall* pfChangeRes)(void* hWnd, int nResolutionMode);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC

void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight);                // 0x004F5570
void __cdecl sub_004F8EA0();                                                          // 0x004F8EA0

extern int gbIsWindowed;                                                                                    // 0x007C8CB4
extern int gnResolutionMode;                                                                                // 0x007C8CB8
extern void* ghWnd;                                                                                         // 0x007C8CBC
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0

// 0x004F5AA0
int __stdcall WINDOW_Resize(int nResolution, int bForceResize)
{
    D2_ASSERT(gpGraphicsInterface, 485);

    if (!bForceResize && nResolution == gnResolutionMode)
    {
        return 1;
    }

    gnResolutionMode = nResolution;

    if (gbIsWindowed == 1)
    {
        tagRECT tClientRect = { 0 };
        GetClientRect(ghWnd, &tClientRect);
        if (tClientRect.right - tClientRect.left <= 800 && tClientRect.bottom - tClientRect.top <= 600)
        {
            tagRECT tRect;
            tRect.left = 0;
            tRect.top = 0;
            sub_004F5570_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
            AdjustWindowRectEx(&tRect, 0xCB0000, 0, 0x40000);
            SetWindowPos(ghWnd, (void*)-2, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top, 0x16);
        }
    }

    const int bResult = gpGraphicsInterface->pfChangeRes(ghWnd, nResolution);
    sub_004F8EA0();
    return bResult;
}
