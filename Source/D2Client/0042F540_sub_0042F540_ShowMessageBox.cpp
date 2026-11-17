struct Unicode
{
    unsigned short wChar;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2WinControlStrc;

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

struct D2LaunchRecord3Strc
{
    int nValue0;
    int nValue1;
    int f_8;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x78];
    int (__fastcall* pfn0x78)(int nA, int nB, int nC, void* pKey);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
void __fastcall sub_005009D0_SetValue(D2WinControlStrc* pControl, int nMode, unsigned short* pText, int nArg); // 0x005009D0
void __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                         // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
int __stdcall sub_0042FDE0_FilterChar(void* pControl, int nUnused, const char* pChar);                      // 0x0042FDE0
int __fastcall sub_00431A60_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg);                                        // 0x00431A60
int __stdcall sub_00434700(SMSGHANDLER_PARAMS* pMsg);                                                       // 0x00434700
void __cdecl sub_0043A650_Refresh();                                                                        // 0x0043A650
int __stdcall sub_0043A950(SMSGHANDLER_PARAMS* pMsg);                                                       // 0x0043A950
void __fastcall sub_0043ADB0_UseName(char* szName);                                                         // 0x0043ADB0
void __cdecl sub_0043EA20_Wait();                                                                           // 0x0043EA20
int __stdcall sub_0043F580(int nArg);                                                                       // 0x0043F580
int __stdcall sub_0043F590_CallTable7C(int nUnused);                                                        // 0x0043F590
void __fastcall sub_004401C0_ShowText(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x004401C0

extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern D2LaunchControlTemplateStrc gtControlTemplates_00708D10[];                                           // 0x00708D10
extern int gnTextMode_00708D0C;                                                                             // 0x00708D0C
extern int gnTextSentinel_0070CB80;                                                                         // 0x0070CB80
extern char gKey_0070CD54;                                                                                  // 0x0070CD54
D2WinControlStrc* gpTextControl1_007795D8;                                                                  // 0x007795D8
D2WinControlStrc* gpTextControl2_007795DC;                                                                  // 0x007795DC
extern D2WinControlStrc* gpNameControl_007799E8;                                                            // 0x007799E8
char gszName_00779C88[256];                                                                                 // 0x00779C88
int gbFlag_0077ADA4;                                                                                        // 0x0077ADA4
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
D2LaunchRecord3Strc gtRecord_0077B0A8;                                                                      // 0x0077B0A8
extern D2WinControlStrc* gpMaxPlayerControl_00798C38;                                                       // 0x00798C38

// 0x0042F540
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2)
{
    D2_ASSERT(nButton1StringId, 0x746);
    int nButtons = 1;
    if (nButton2StringId)
        nButtons = 2;
    sub_0042F3F0_DestroyControls();
    switch (nButtons)
    {
    case 1:
    {
        D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xE7);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gtControlTemplates_00708D10[0x11A].nStringId = nButton1StringId;
        if (bFlag2)
            gtControlTemplates_00708D10[0x11A].nFlags = 0x1B;
        else
            gtControlTemplates_00708D10[0x11A].nFlags = bFlag1 ? 0xD : 0;
        gtControlTemplates_00708D10[0x11A].pfnCallback = pfnButton1;
        pControl = sub_0042F3A0_CreateFromTemplate(0x11A);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    case 2:
    {
        D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0x119);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gtControlTemplates_00708D10[0x11B].nStringId = nButton1StringId;
        gtControlTemplates_00708D10[0x11B].nFlags = bFlag1 ? 0xD : 0;
        gtControlTemplates_00708D10[0x11B].pfnCallback = pfnButton1;
        pControl = sub_0042F3A0_CreateFromTemplate(0x11B);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gtControlTemplates_00708D10[0x11C].nStringId = nButton2StringId;
        gtControlTemplates_00708D10[0x11C].nFlags = bFlag1 ? 0x1B : 0;
        gtControlTemplates_00708D10[0x11C].pfnCallback = pfnButton2;
        pControl = sub_0042F3A0_CreateFromTemplate(0x11C);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    }
    if (pTitle)
    {
        D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0x11D);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FD060_SetText(pControl, pTitle);
    }
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(pTitle ? 0x11E : 0x11F);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FD060_SetText(pControl, pMessage);
}

// 0x0042FEF0
int __stdcall sub_0042FEF0_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return sub_0042FDE0_FilterChar(pControl, nUnused, pChar);
}

// 0x004307A0
int __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2)
{
    if (gnTextSentinel_0070CB80 == -1)
    {
        if (nArg)
        {
            sub_004FB6A0_ClearText(gpTextControl1_007795D8);
            sub_004FC9B0_SetText(gpTextControl1_007795D8, D2LANG_GetStringFromTblIndex(nStringId1), 0, 0, 0);
            sub_004FB6A0_ClearText(gpTextControl2_007795DC);
            sub_004FC9B0_SetText(gpTextControl2_007795DC, D2LANG_GetStringFromTblIndex(nStringId2), 0, 0, 0);
            gnTextMode_00708D0C = nMode;
            return 1;
        }
        if (gnTextMode_00708D0C == nMode)
        {
            sub_004FB6A0_ClearText(gpTextControl1_007795D8);
            sub_004FB6A0_ClearText(gpTextControl2_007795DC);
        }
    }
    return 1;
}

// 0x004313D0
void __stdcall sub_004313D0(int nLevel)
{
    sub_0042F480_Reset();
    sub_0042F3F0_DestroyControls();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_0042F430_CreateControl(8);
    sub_0042F430_CreateControl(0x3D);
    D2WinControlStrc* pTitle = sub_0042F430_CreateControl(0x3E);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    sub_0042F430_CreateControl(0x3F);
    D2WinControlStrc* pField1 = sub_0042F430_CreateControl(0x40);
    D2WinControlStrc* pField2 = sub_0042F430_CreateControl(0x41);
    D2WinControlStrc* pField3 = sub_0042F430_CreateControl(0x42);
    D2WinControlStrc* pField4 = sub_0042F430_CreateControl(0x43);
    D2WinControlStrc* pField5 = sub_0042F430_CreateControl(0x44);
    D2WinControlStrc* pField6 = sub_0042F430_CreateControl(0x45);
    sub_0042F430_CreateControl(0x46);
    unsigned short wszEmpty[1] = { 0 };
    switch (nLevel)
    {
    default:
        sub_004F96F0_ControlClearState(pField1, 0);
        sub_005009D0_SetValue(pField1, 10, wszEmpty, 0);
    case 2:
        sub_004F96F0_ControlClearState(pField2, 0);
        sub_005009D0_SetValue(pField2, 10, wszEmpty, 0);
    case 3:
        sub_004F96F0_ControlClearState(pField3, 0);
        sub_005009D0_SetValue(pField3, 10, wszEmpty, 0);
    case 4:
        sub_004F96F0_ControlClearState(pField4, 0);
        sub_005009D0_SetValue(pField4, 10, wszEmpty, 0);
    case 5:
        sub_004F96F0_ControlClearState(pField5, 0);
        sub_005009D0_SetValue(pField5, 10, wszEmpty, 0);
    case 6:
        sub_004F96F0_ControlClearState(pField6, 0);
        sub_005009D0_SetValue(pField6, 10, wszEmpty, 0);
    case 7:
        break;
    }
}

// 0x00435D50
int __stdcall sub_00435D50(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00431A60_IsDoubleClick(pMsg))
        return sub_00434700(pMsg);
    return 1;
}

// 0x0043B4C0
int __stdcall sub_0043B4C0(SMSGHANDLER_PARAMS* pMsg)
{
    const Unicode* pText = sub_004FBB30_GetText(gpNameControl_007799E8);
    sub_005263E0(gszName_00779C88, pText, 0x100);
    sub_0043ADB0_UseName(gszName_00779C88);
    sub_0043A650_Refresh();
    if (sub_00431A60_IsDoubleClick(pMsg))
        return sub_0043A950(pMsg);
    return 1;
}

// 0x00440CA0
int __fastcall sub_00440CA0(int nA, int nB, int nC, int nD)
{
    gtRecord_0077B0A8.nValue0 = nB;
    gtRecord_0077B0A8.nValue1 = nC;
    gtRecord_0077B0A8.f_8 = nD;
    gpLaunchFuncs_0077B09C->pfn0x78(nA, 3, 1, &gKey_0070CD54);
    gbFlag_0077ADA4 = 0;
    sub_004401C0_ShowText(D2LANG_GetStringFromTblIndex(0x147B), sub_0043F580);
    sub_004FA590_RunLoop(sub_0043F590_CallTable7C);
    sub_0043EA20_Wait();
    return gbFlag_0077ADA4 == 0;
}

// 0x004431B0
void __cdecl sub_004431B0()
{
    unsigned long nValue = 4;
    if (!SRegLoadValue("Diablo II", "MAX_PLAYER", 0, &nValue))
        SRegSaveValue("Diablo II", "MAX_PLAYER", 0, nValue);
    char szText[2] = "4";
    int nPlayers = nValue;
    if (nPlayers < 9 && nPlayers > 0)
    {
        sprintf(szText, gszFormatD_006D57BC, nPlayers);
        sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, szText);
    }
}

#include "gen/data/Source/D2Client/0042F540_sub_0042F540_ShowMessageBox.inc"
