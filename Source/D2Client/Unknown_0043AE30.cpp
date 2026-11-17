#include "D2Client.h"

struct D2WinTextBoxStrc;
struct D2WinButtonStrc;

struct D2LaunchRecordStrc
{
    char unk0x000[0x210];
    char nByte210;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
int __stdcall sub_00439DF0_OnScroll(SMSGHANDLER_PARAMS* pMsg);                                              // 0x00439DF0
int __cdecl sub_0043A2B0_InitRealmScreen();                                                                 // 0x0043A2B0
void __fastcall sub_0043ADB0_UseName(char* szName);                                                         // 0x0043ADB0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __fastcall sub_004FB590(int nFont);                                                                    // 0x004FB590
int __fastcall D2Win_10191(D2WinTextBoxStrc* pTextBox, int nMaxSteps);                                      // 0x004FC5E0
int __fastcall D2Win_10194(D2WinTextBoxStrc* pTextBox, D2WinTextBoxStrc* pLinkedTextBox);                   // 0x004FC6A0
int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x004FC6E0
void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId);                                // 0x00500BF0
D2WinControlStrc* gpControl_007799F8;                                                                       // 0x007799F8
extern void* gapRowControls_00779A20[];                                                                     // 0x00779A20
extern char gData_00779A40[];                                                                               // 0x00779A40
void* gapRowControlsX_00779B40[8];                                                                          // 0x00779B40
D2WinControlStrc* gpControl_00779C84;                                                                       // 0x00779C84

static int gdwGlobal_00779DC4;          // 0x00779DC4
static int gnTopRow_00779DC8;           // 0x00779DC8
static int gnSelected_0070CC00;         // 0x0070CC00
static int gbFlag_00779C6C;             // 0x00779C6C
static D2WinControlStrc* gpCharSelectText_00779DD4; // 0x00779DD4
static D2WinControlStrc* gpControl_00779DD0;        // 0x00779DD0
static int gnLastValue_00779DCC;        // 0x00779DCC

// 0x0043AE30
void __cdecl sub_0043AE30_InitCharList()
{
    sub_0042F480_Reset();
    sub_0042F2E0_ReadPaletteFiles(gapszSkyPalette_006D3A08[0], gapszSkyPalette_006D3A08[1]);
    gdwGlobal_00779DA4 = 1;
    gdwGlobal_00779DC4 = 0;
    gnTopRow_00779DC8 = 0;
    gnSelected_0070CC00 = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText_00779DD4 = 0;
    gpControl_00779DD0 = 0;
    gnLastValue_00779DCC = 0;
    gpLaunchRecord_007795D4->nByte210 = 0;
    sub_0042F430_CreateControl(0xA1);
    gpControl_00779C68 = sub_0042F430_CreateControl(0xA2);
    gpControl_007799F8 = sub_0042F430_CreateControl(0xA3);
    gpControl_00779D90 = sub_0042F430_CreateControl(0xA4);
    gpControl_00779C80 = sub_0042F430_CreateControl(0xA5);
    gpControl_007799F4 = sub_0042F430_CreateControl(0xA6);
    gpControl_00779B60 = sub_0042F430_CreateControl(0x9C);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779D90, 0x5524);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779C80, 0x58CA);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_007799F4, 0x5524);
    gpControl_00779C84 = sub_0042F430_CreateControl(0xA7);
    D2Win_10194((D2WinTextBoxStrc*)gpControl_00779C84, 0);
    D2Win_10195((D2WinTextBoxStrc*)gpControl_00779C84, (void(__stdcall*)(SMSGHANDLER_PARAMS*))sub_00439DF0_OnScroll);
    memset(gapRowControls_00779A20, 0, 8 * sizeof(void*));
    gnVisibleRows_0070CC0C = 8;
    for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
    {
        if (sub_00408F20_HasExpansionMpq())
        {
            gapRowControlsX_00779B40[i] = sub_0042F430_CreateControl(i + 0x8C);
            D2Win_10045((D2WinControlStrc*)gapRowControlsX_00779B40[i], gszSpace_006FFC44);
        }
        sub_004FB590(1);
        gapRowControls_00779A20[i] = sub_0042F430_CreateControl(i + 0x84);
        sub_004FB590(0);
        ganRowValues_007799FC[i] = i / 2 * 0x5D + 0xB2;
    }
    gpControl_00779D94 = sub_0042F430_CreateControl(0x96);
    if (sub_0043A2B0_InitRealmScreen())
    {
        sub_004F96F0_ControlClearState(gpControl_007799F8, 0);
        sub_0043ADB0_UseName(gData_00779A40);
        const int nExtra = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
        if (nExtra > 0)
            D2Win_10191((D2WinTextBoxStrc*)gpControl_00779C84, nExtra / 2 + (nExtra % 2 != 0));
        if (sub_00514D80())
            sub_005148F0_SetChannelValue(1);
        sub_004F96F0_ControlClearState(gpControl_007799F8, 1);
    }
}

#include "gen/data/Source/D2Client/Unknown_0043AE30.inc"
