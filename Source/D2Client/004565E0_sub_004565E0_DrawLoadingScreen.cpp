struct D2CellFileStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2CellFileStrc* gpLoadingScreen_007A2888;                                                                   // 0x007A2888
int gnLoadingFrame_007A2A6C;                                                                                // 0x007A2A6C
int gnValue_007A27B8;                                                                                       // 0x007A27B8
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
unsigned char gnLoadingBarColor_007A2A70;                                                                   // 0x007A2A70
unsigned char gnLoadingBoxColor_007A2A71;                                                                   // 0x007A2A71

int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
void __stdcall D2GFX_ClearScreen(int bPartial);                                                             // 0x004F63B0
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
void __cdecl sub_0044CD70_TickTimer();                                                                      // 0x0044CD70
void __fastcall sub_004FB0D0();                                                                             // 0x004FB0D0
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
void __cdecl sub_00456550_LoadLoadingScreen();                                                              // 0x00456550
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __cdecl sub_00478150();                                                                                 // 0x00478150
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __stdcall sub_006019F0(D2CellFileStrc* pCelFile);                                               // 0x006019F0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70

// 0x004565E0
void __fastcall sub_004565E0_DrawLoadingScreen(int bAdvanceFrame)
{
    if (!WINDOW_GetState())
    {
        D2GFX_ClearScreen(0);
    }

    const int nLoadState = sub_0044DB30();
    sub_0044CD70_TickTimer();

    if (WINDOW_GetState())
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame_007A2A6C;
        }
        return;
    }

    sub_004FB0D0();
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame_007A2A6C;
        }
        return;
    }

    if (!gpLoadingScreen_007A2888)
    {
        sub_00456550_LoadLoadingScreen();
        D2_ASSERT(gpLoadingScreen_007A2888, 6594);
    }

    if (nLoadState == 6 || nLoadState == 8 || nLoadState == 7 || nLoadState == 9)
    {
        if (!gnLoadingBarColor_007A2A70)
        {
            gnLoadingBarColor_007A2A70 = D2Win_10034_MixRGB(0x60, 0, 0);
            gnLoadingBoxColor_007A2A71 = D2Win_10034_MixRGB(0xFF, 0xFF, 0);
        }

        if (!gnValue_007A27B8)
        {
            D2GFX_DrawBox(gnGlobal_0071146C / 2 - 0x82, gnGlobal_00711470 / 2 + 0x9E, gnGlobal_0071146C / 2 + 0x82, gnGlobal_00711470 / 2 + 0xB2, gnLoadingBoxColor_007A2A71, 1);
            D2GFX_DrawBox(gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0xA0, gnGlobal_0071146C / 2 + 0x80, gnGlobal_00711470 / 2 + 0xB0, 0, 5);

            const int nWidth = sub_00478150();
            if (nWidth)
            {
                sub_0046EFD0_DrawFramedBox(gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0xA0, nWidth, 0x10, gnLoadingBarColor_007A2A70, 5);
            }
        }
    }

    const int nFrames = sub_006019F0(gpLoadingScreen_007A2888);
    if (gnLoadingFrame_007A2A6C >= nFrames)
    {
        gnLoadingFrame_007A2A6C = nFrames - 1;
    }

    D2CelContextStrc tContext;
    tContext.pCellFile = gpLoadingScreen_007A2888;
    tContext.nFrame = gnLoadingFrame_007A2A6C;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0x80, -1, 5, 0);
    D2GFX_EndScene();
    sub_0044DA40();
    sub_0044DA70();

    if (bAdvanceFrame)
    {
        ++gnLoadingFrame_007A2A6C;
    }
}
