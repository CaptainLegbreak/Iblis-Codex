struct D2RectStrc { long nLeft; long nTop; long nRight; long nBottom; };
struct D2RgbQuadStrc { unsigned char nBlue, nGreen, nRed, nReserved; };
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd);
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC);
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);
extern "C" __declspec(dllimport) unsigned int __stdcall SetDIBColorTable(void* hDC, unsigned int nStart, unsigned int nCount, const D2RgbQuadStrc* pColors);
extern "C" __declspec(dllimport) void* __stdcall SelectPalette(void* hDC, void* hPalette, int bForceBackground);
extern "C" __declspec(dllimport) unsigned int __stdcall RealizePalette(void* hDC);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, D2RectStrc* pRect);
extern "C" __declspec(dllimport) int __stdcall StretchBlt(void* hDest, int nX, int nY, int nWidth, int nHeight, void* hSrc, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight, unsigned long nRop);
extern "C" __declspec(dllimport) int __stdcall GdiFlush();
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);
void* __stdcall sub_004F59A0(); // 0x004F59A0
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
void* ghWindow_007C9140;        // 0x007C9140
extern D2RgbQuadStrc gaPalette_00989C40[256]; // 0x00989C40
extern void* ghPalette_0098A160; // 0x0098A160
extern void* ghBitmap_0098A164; // 0x0098A164

// 0x006C7E30
int __cdecl sub_006C7E30_BlitWindow()
{
    void* hDC = GetDC(ghWindow_007C9140);
    void* hMemoryDC = CreateCompatibleDC(hDC);
    SelectObject(hMemoryDC, ghBitmap_0098A164);
    SetDIBColorTable(hMemoryDC, 0, 256, gaPalette_00989C40);
    SelectPalette(hDC, ghPalette_0098A160, 0);
    RealizePalette(hDC);
    D2RectStrc tRect;
    GetClientRect(sub_004F59A0(), &tRect);
    StretchBlt(hDC, 0, 0, tRect.nRight - tRect.nLeft, tRect.nBottom - tRect.nTop,
        hMemoryDC, 0, 0, gnScreenWidth_007C9138, gnScreenHeight_007C913C, 0xCC0020);
    GdiFlush();
    DeleteDC(hMemoryDC);
    ReleaseDC(ghWindow_007C9140, hDC);
    return 1;
}
