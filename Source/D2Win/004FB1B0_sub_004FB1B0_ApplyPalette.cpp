extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct T004F51E0
{
    unsigned char nBlue;
    unsigned char nGreen;
    unsigned char nRed;
    unsigned char nFlags;
};

struct D2WinControlStrc
{
    int dwType;
    char unk0x04[0x8C];
    D2WinControlStrc* pChild;
};

void __stdcall D2GFX_SetPalette(T004F51E0* pPalette);                                              // 0x004F63D0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
T004F51E0 gaPalette_0081E668[256];                                                                   // 0x0081E668

// 0x004FB1B0
void __cdecl sub_004FB1B0_ApplyPalette()
{
    D2GFX_SetPalette(gaPalette_0081E668);
}

// 0x004FBD70
void __fastcall sub_004FBD70_SetControlStateWithChild(D2WinControlStrc* pControl, int bSet)
{
    sub_004F9740_SetControlState(pControl, bSet);
    D2_ASSERT(pControl, 0x320);
    D2_ASSERT(pControl->dwType == 4, 0x321);
    if (pControl->pChild)
    {
        sub_004F9740_SetControlState(pControl->pChild, bSet);
    }
}

// 0x004FBDC0
void __cdecl sub_004FBDC0_Unsupported()
{
    D2_ASSERT(0, 0x32E);
}
