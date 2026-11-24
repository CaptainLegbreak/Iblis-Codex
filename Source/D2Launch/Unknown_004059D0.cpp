#include "D2FogTypes.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2ModeEntryStrc gaModeTable[6]; // 0x00706554
extern int gnMode_0074C704; // 0x0074C704
extern void* gpModeContext_0074C718; // 0x0074C718
D2ModeIfaceStrc* gpModeIface; // 0x0074C700

// 0x004059D0
int __stdcall ERRORMANAGER_RunModeInterface(int nArg)
{
    if (gnMode_0074C704 < 1 || gnMode_0074C704 > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnCreate, 307);
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnRelease, 308);
    gpModeIface = gaModeTable[gnMode_0074C704].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface->pfnRun(nArg);
    gaModeTable[gnMode_0074C704].pfnRelease();
    return nResult;
}

#include "gen/data/Source/D2Launch/Unknown_004059D0.inc"
