struct D2DDCaps006B3420Strc
{
    unsigned int dwCaps;
    unsigned int dwCaps2;
    unsigned int dwCaps3;
    unsigned int dwCaps4;
};

struct D2DDSurfaceDesc006B3420Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int aUnk0x08[24];
    D2DDCaps006B3420Strc tCaps;
    unsigned int dwTextureStage;
};

struct D2ComObject006B3420Strc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDesc006B3420Strc* pDesc, D2ComObject006B3420Strc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult);                              // 0x006B20E0

extern int gbVideoUp_00970E40;                                                                              // 0x00970E40
extern int gnVideoState_00970E44;                                                                           // 0x00970E44
extern D2ComObject006B3420Strc* gpDirectDraw_00970E60;                                                      // 0x00970E60
extern D2ComObject006B3420Strc* gpPrimary_00970E68;                                                         // 0x00970E68
extern unsigned int gnRenderFlags_0096F3A8;                                                                 // 0x0096F3A8
extern const unsigned int gdwBitMask7_006CE284;                                                             // 0x006CE284
extern const unsigned int gdwBitMask8_006CE288;                                                             // 0x006CE288
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006B3420
int __cdecl sub_006B3420_InitializeCutsceneMode()
{
    D2_ASSERT(!gbVideoUp_00970E40, 0x7CB);

    gnScreenWidth_007C9138 = 640;
    gnScreenHeight_007C913C = 480;

    unsigned int nBpp = 16;
    if (gdwBitMask7_006CE284 & gnRenderFlags_0096F3A8)
    {
        nBpp = 32;
    }
    else if (gdwBitMask8_006CE288 & gnRenderFlags_0096F3A8)
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDirectDraw_00970E60->SetDisplayMode(640, 480, nBpp, 0, 0);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        D2DDSurfaceDesc006B3420Strc tDesc = { sizeof(tDesc) };
        tDesc.dwFlags = 1;
        tDesc.tCaps.dwCaps = 0x4200;
        hResult = gpDirectDraw_00970E60->CreateSurface(&tDesc, &gpPrimary_00970E68, 0);
    }
    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        sub_006B20E0_ReportError(szError, hResult);
        sub_00410610_WriteLogLine("Opening Direct3D window for cutscenes failed!");
        return 0;
    }

    gbVideoUp_00970E40 = 1;
    gnVideoState_00970E44 = 1;
    return 1;
}

#include "gen/data/Source/Storm/006B3420_sub_006B3420_InitializeCutsceneMode.inc"
