extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
struct D2RectStrc { long left, top, right, bottom; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) __declspec(noalias) int __stdcall GetWindowRect(void* hWindow, D2RectStrc* pRect);
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);
int __cdecl sub_004F5A30_IsFullscreen(); // 0x004F5A30
void* __cdecl sub_004F59A0_GetWindow(); // 0x004F59A0
extern int gnCursorY_007A6AAC; // 0x007A6AAC
extern int gnCursorX_007A6AB0; // 0x007A6AB0

// 0x00468770
void __fastcall sub_00468770_SetCursorPosition(int nX, int nY)
{
    D2RectStrc rect;
    D2_ASSERT(nX >= 0, 0x30F);
    D2_ASSERT(nY >= 0, 0x310);
    if (!sub_004F5A30_IsFullscreen())
    {
        _ReadWriteBarrier();
        D2RectStrc* pWindowRect = &rect;
        GetWindowRect(sub_004F59A0_GetWindow(), pWindowRect);
        int nScreenY = GetSystemMetrics(4);
        nScreenY += pWindowRect->top;
        nScreenY += nY;
        const int nScreenX = GetSystemMetrics(7) + rect.left + nX;
        SetCursorPos(nScreenX, nScreenY);
    }
    else
    {
        SetCursorPos(nX, nY);
    }
    gnCursorY_007A6AAC = nY;
    gnCursorX_007A6AB0 = nX;
}
