struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;
struct D2CellFileStrc;

typedef int (__stdcall* D2LaunchCallback)(int nArg);

struct D2LaunchControlTemplateStrc
{
    char unk0x00[0x14];
    int nFlags;
    int nStringId;
    char unk0x1C[0x04];
    D2LaunchCallback pfnCallback;
    char unk0x24[0x0C];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

const char* __cdecl sub_0040DF60_GetLocalIp();                                                              // 0x0040DF60
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
void __cdecl sub_0042F6C0_SetDone();                                                                        // 0x0042F6C0
void __cdecl sub_00437B90();                                                                                // 0x00437B90
void __cdecl sub_00438EA0();                                                                                // 0x00438EA0
int __stdcall BACKGROUND_SetCellFile(D2CellFileStrc* pCellFile);                                            // 0x004F9140
D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate);                         // 0x004F93C0
int __stdcall sub_004F95C0_ControlDestroy(D2WinControlStrc** ppControl);                                   // 0x004F95C0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __stdcall D2Win_10029(int a1);                                                                         // 0x004FA410
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30

extern "C" const char gszPalFeCharDat_006D39E8[];                                                           // 0x006D39E8
extern D2LaunchControlTemplateStrc gtControlTemplates_00708D10[];                                           // 0x00708D10
extern int gdwGlobal_0077932C;                                                                              // 0x0077932C
D2WinControlStrc* gpControl_00779338;                                                                       // 0x00779338
extern D2WinControlStrc* gapControlsB_00779350[0x40];                                                       // 0x00779350
extern D2WinControlStrc* gapControlsA_00779450[0x40];                                                       // 0x00779450
D2WinControlStrc* gpControl_00779588;                                                                       // 0x00779588
D2WinControlStrc* gpControl_007795A0;                                                                       // 0x007795A0
D2WinControlStrc* gpControl_007795A4;                                                                       // 0x007795A4
extern void (__cdecl* gpfnGatewayDone_007795BC)();                                                          // 0x007795BC
extern int gbFeCharPalette_007795F0;                                                                        // 0x007795F0
int gnControlCountB_00779944;                                                                               // 0x00779944
extern int gnControlCountA_00779948;                                                                        // 0x00779948
int gnValue_0077994C;                                                                                       // 0x0077994C
int gnValue_00779950;                                                                                       // 0x00779950
int gbGatewayFlag_00779954;                                                                                 // 0x00779954
extern int gbPaletteBusy_00779970;                                                                          // 0x00779970
extern int gdwGlobal_00779974;                                                                              // 0x00779974
int gnValue_00779980;                                                                                       // 0x00779980

// 0x0042F3A0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA_00779948 < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlTemplates_00708D10[nTemplateId]);
    gapControlsA_00779450[gnControlCountA_00779948++] = pControl;
    return pControl;
}

// 0x0042F3F0
void __cdecl sub_0042F3F0_DestroyControls()
{
    for (int i = 0; i < gnControlCountA_00779948; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA_00779450[i]);
    gnControlCountA_00779948 = 0;
}

// 0x0042F430
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId)
{
    D2_ASSERT(gnControlCountB_00779944 < 0x40, 0x627);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlTemplates_00708D10[nId]);
    gapControlsB_00779350[gnControlCountB_00779944++] = pControl;
    return pControl;
}

// 0x0042F480
void __cdecl sub_0042F480_Reset()
{
    for (int i = 0; i < gnControlCountB_00779944; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsB_00779350[i]);
    gnValue_0077994C = 0;
    gnValue_00779950 = 0;
    gnControlCountB_00779944 = 0;
    for (int i = 0; i < gnControlCountA_00779948; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA_00779450[i]);
    gnControlCountA_00779948 = 0;
    BACKGROUND_SetCellFile(0);
    if (gbPaletteBusy_00779970)
    {
        sub_0042F2E0_ReadPaletteFiles(gszPalFeCharDat_006D39E8, "palette\\fechar\\pal.pl2");
        gbPaletteBusy_00779970 = 0;
    }
    sub_00438EA0();
    sub_00437B90();
    D2Win_10029(1);
}

// 0x0042F6E0
void __cdecl sub_0042F6E0()
{
    sub_0042F3F0_DestroyControls();
    gbGatewayFlag_00779954 = 1;
    gdwGlobal_00779974 = 0;
    D2WinControlStrc* pControlA;
    D2WinControlStrc* pControlB;
    D2WinControlStrc* pControlC;
    if (gbFeCharPalette_007795F0)
    {
        pControlA = sub_0042F3A0_CreateFromTemplate(0xF7);
        D2Win_10033(pControlA, 0);
        pControlB = sub_0042F3A0_CreateFromTemplate(0xFA);
        pControlC = sub_0042F3A0_CreateFromTemplate(0xF9);
    }
    else
    {
        pControlA = sub_0042F3A0_CreateFromTemplate(0xDE);
        D2Win_10033(pControlA, 0);
        pControlB = sub_0042F3A0_CreateFromTemplate(0xDF);
        pControlC = sub_0042F3A0_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
    gpfnGatewayDone_007795BC = sub_0042F6C0_SetDone;
}

// 0x0042F800
void __cdecl sub_0042F800()
{
    sub_0042F3F0_DestroyControls();
    gbGatewayFlag_00779954 = 1;
    gdwGlobal_00779974 = 0;
    D2WinControlStrc* pControlA = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pControlA, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2WinControlStrc* pControlB = sub_0042F3A0_CreateFromTemplate(0xFC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2WinControlStrc* pControlC = sub_0042F3A0_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    sub_0042F3A0_CreateFromTemplate(0xFB);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
}

// 0x0042FA20
void __cdecl sub_0042FA20()
{
    gdwGlobal_0077932C = 0;
}

// 0x0042FF10
void __fastcall sub_0042FF10_SetValue(int nValue)
{
    gnValue_00779980 = nValue;
}

// 0x0042FF20
void __cdecl sub_0042FF20_ShowLocalAddress()
{
    const char* szAddress = sub_0040DF60_GetLocalIp();
    sub_004FB6A0_ClearText(gpControl_00779588);
    if (!strcmp(szAddress, "127.0.0.1"))
    {
        sub_004FD060_SetText(gpControl_00779588, D2LANG_GetStringFromTblIndex(0x1404));
        sub_004F96F0_ControlClearState(gpControl_007795A4, 0);
        sub_004F96F0_ControlClearState(gpControl_007795A0, 0);
        sub_004F96F0_ControlClearState(gpControl_00779338, 0);
    }
    else
    {
        sub_004FCF80_SetTextA(gpControl_00779588, szAddress);
        sub_004F96F0_ControlClearState(gpControl_007795A4, 1);
        sub_004F96F0_ControlClearState(gpControl_007795A0, 1);
        sub_004F96F0_ControlClearState(gpControl_00779338, 1);
    }
}

#include "gen/data/Source/D2Client/0042F3A0_sub_0042F3A0_CreateFromTemplate.inc"
