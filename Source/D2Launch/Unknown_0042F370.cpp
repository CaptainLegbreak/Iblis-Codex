#include "D2Launch.h"
#include "D2Unicode.h"
struct D2LaunchControlTemplateStrc;

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
extern "C" const char gszFeCharPalDat[]; // 0x006D39E8
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
void __cdecl MAINMENUS_SetDone(); // 0x0042F6C0
void __cdecl CHARSEL_FreeCache(); // 0x00437B90
void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate); // 0x004F93C0
void __stdcall D2Win_10029(int a1); // 0x004FA410
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern D2LaunchControlTemplateStrc gatControlTemplates[]; // 0x00708D10
extern int gbStopMainLoop; // 0x0077932C
extern D2WinControlStrc* gapControlsB[0x40]; // 0x00779350
extern D2WinControlStrc* gapControlsA[0x40]; // 0x00779450
extern void (__cdecl* gpfnGatewayDone)(); // 0x007795BC
extern int gbFeCharPalette; // 0x007795F0
extern int gnControlCountA; // 0x00779948
extern int gbPaletteBusy; // 0x00779970
extern int gdwGlobal_00779974; // 0x00779974

int gbPaletteBusy; // 0x00779970

// 0x0042F370
void __cdecl sub_0042F370_RestorePalette()
{
    if (gbPaletteBusy)
    {
        sub_0042F2E0_ReadPaletteFiles(gszFeCharPalDat, "palette\\fechar\\pal.pl2");
        gbPaletteBusy = 0;
    }
}

// 0x0042F880
void __cdecl sub_0042F880_DestroyControls()
{
    MAINMENUS_DestroyControls();
}

D2WinControlStrc* gpControl_00779338; // 0x00779338

D2WinControlStrc* gpControl_00779588; // 0x00779588

D2WinControlStrc* gpControl_007795A0; // 0x007795A0

D2WinControlStrc* gpControl_007795A4; // 0x007795A4

int gnControlCountB; // 0x00779944



extern int gbGatewayFlag; // 0x00779954

int gnValue_00779980; // 0x00779980

// 0x0042F800
void __cdecl sub_0042F800()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gdwGlobal_00779974 = 0;
// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
    D2WinControlStrc* pControlA = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControlA, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2WinControlStrc* pControlB = MAINMENUS_CreateFromTemplate(0xFC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2WinControlStrc* pControlC = MAINMENUS_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    MAINMENUS_CreateFromTemplate(0xFB);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
}

// 0x0042FA20
void __cdecl sub_0042FA20()
{
    gbStopMainLoop = 0;
}

// 0x0042FF10
void __fastcall sub_0042FF10_SetValue(int nValue)
{
    gnValue_00779980 = nValue;
}

// 0x0042FF20
void __cdecl sub_0042FF20_ShowLocalAddress()
{
    const char* szAddress = FOG_GetHostIPAddress();
    sub_004FB6A0_ClearText(gpControl_00779588);
    if (!strcmp(szAddress, "127.0.0.1"))
    {
        sub_004FD060_SetText(gpControl_00779588, D2LANG_GetStringFromTblIndex(0x1404));
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControl_007795A4, 0);
        CONTROL_SetEnabled(gpControl_007795A0, 0);
        CONTROL_SetEnabled(gpControl_00779338, 0);
    }
    else
    {
        D2Win_10045(gpControl_00779588, szAddress);
        CONTROL_SetEnabled(gpControl_007795A4, 1);
        CONTROL_SetEnabled(gpControl_007795A0, 1);
        CONTROL_SetEnabled(gpControl_00779338, 1);
    }
}

#include "gen/data/Source/D2Launch/Unknown_0042F370.inc"
