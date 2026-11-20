#include "D2DDraw.h"
#include "D2DDrawTypes.h"

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0

extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881280;                                                         // 0x00881280

// 0x00511720
int __fastcall sub_00511720_DDrawStartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused_007C9144)
        return 0;

    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x3BF);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    sub_00512ED0_ClearScreen(1);
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    long nResult = gpDDrawSurface_00881280->lpVtbl->Lock(gpDDrawSurface_00881280, 0, &tDesc, 0x21, 0);
    if (nResult)
    {
        sub_005103B0("Lock failed!", nResult);
        LeaveCriticalSection(gpRenderCriticalSection_007C9134);
        return 0;
    }
    gpScreenBuffer_007C9154 = (unsigned char*)tDesc.lpSurface;
    gnScreenWidth_007C9138 = tDesc.lPitch;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable((unsigned char*)tDesc.lpSurface, tDesc.lPitch, gnScreenHeight_007C913C, 0);
    return 1;
}
