struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;
struct D2ConfigStrc;

typedef int (__stdcall* D2LaunchCallback)(int nArg);

void __cdecl sub_004336C0();                                                                                // 0x004336C0
int __cdecl sub_00514D80();                                                                                 // 0x00514D80
void __fastcall D2SOUND_10034(int nArg);                                                                    // 0x005148F0
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl);                                    // 0x004FB950
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
int __cdecl sub_004F9050();                                                                                 // 0x004F9050
void __cdecl sub_00433640_PlayIntroVideo();                                                                 // 0x00433640
void __stdcall D2Win_10004(int nResolution);                                                                // 0x004F9060
void __cdecl sub_0042FB20();                                                                                // 0x0042FB20
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
void __cdecl sub_004FAD70();                                                                                // 0x004FAD70
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
int __stdcall sub_00431950_LoopCallback(int nArg);                                                          // 0x00431950
void __fastcall sub_00431570_CreateControls(int bFlag);                                                     // 0x00431570

extern D2WinControlStrc* gpList_00779964;                                                                   // 0x00779964
int gnListPos_0077996C;                                                                                     // 0x0077996C
extern D2ConfigStrc* gpConfig_007795D4;                                                                     // 0x007795D4
extern int gnFlag_007798D0;                                                                                 // 0x007798D0
extern int gnFlag_007798D4;                                                                                 // 0x007798D4
void* gpfnArchiveLoader2_007798DC;                                                                          // 0x007798DC
int gnLoaderFlag_007798E0;                                                                                  // 0x007798E0

// 0x004341F0
int __stdcall sub_004341F0_CheckListEnd(int nArg)
{
    if (gnListPos_0077996C <= sub_004FB950_GetFirstVisible(gpList_00779964) + 10)
        sub_004336C0();
    return 1;
}

// 0x00434220
int __cdecl sub_00434220_PlayDisc()
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2_007798DC = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag_007798E0 = 0;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x004342E0
int __cdecl sub_004342E0_ExpansionDisc()
{
    sub_00431570_CreateControls(1);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2_007798DC = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag_007798E0 = 0;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x004345C0
int __stdcall sub_004345C0_ReloadAndLeave(int nArg)
{
    sub_004FAD70();
    ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    if (sub_00514D80())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// 0x00434760
int __stdcall sub_00434760_ResetAndLeave(int nArg)
{
    sub_0042F480_Reset();
    if (sub_00514D80())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// 0x00434D90
int __stdcall sub_00434D90_PlayIntroAndLeave(int nArg)
{
    if (sub_004F9050())
        sub_00433640_PlayIntroVideo();
    D2Win_10004(1);
    sub_0042FB20();
    return 1;
}

// 0x00434DC0
int __stdcall sub_00434DC0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}

// 0x00434DD0
int __stdcall sub_00434DD0_ClearAndLeave(int nArg)
{
    sub_0043B9A0();
    sub_004336C0();
    return 1;
}

// 0x00434DF0
int __stdcall sub_00434DF0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}
