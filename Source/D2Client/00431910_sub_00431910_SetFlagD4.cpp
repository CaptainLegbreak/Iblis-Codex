struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

typedef int (__stdcall* D2LaunchCallback)(int nArg);

void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042FFE0_CreateScreen();                                                                   // 0x0042FFE0
void __fastcall sub_00515F50(int nArg);                                                                     // 0x00515F50
int __cdecl CLIENT_GetConnectionStatus();                                                                   // 0x0052B050
void __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                         // 0x0042F2E0
int __stdcall sub_004F95C0_ControlDestroy(D2WinControlStrc** ppControl);                                    // 0x004F95C0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox);                                                     // 0x004FDD00
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __fastcall sub_004FD830(D2WinControlStrc* pControl);                                                   // 0x004FD830
void __fastcall sub_004FDA50(D2WinControlStrc* pControl);                                                   // 0x004FDA50
int __fastcall sub_004F9190();                                                            // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __cdecl sub_00431970_CreateScreen();                                                                   // 0x00431970
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion);                 // 0x004FAD10

int gnFlag_007798D0;                                                                                        // 0x007798D0
int gnFlag_007798D4;                                                                                        // 0x007798D4
void* gpfnArchiveLoader_007798D8;                                                                           // 0x007798D8
extern int gnLoaderFlag_007798E0;                                                                           // 0x007798E0
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gnLaunchState_007795E8;                                                                          // 0x007795E8
int gbConnected_0077959C;                                                                                   // 0x0077959C
D2WinControlStrc* gpControl_00779344;                                                                       // 0x00779344
D2WinControlStrc* gpAddressEdit_00779958;                                                                   // 0x00779958
char gszAddress_007795F8[255];                                                                              // 0x007795F8

// 0x00431910
int __stdcall sub_00431910_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431920
int __stdcall sub_00431920_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431950
int __stdcall sub_00431950_LoopCallback(int nArg)
{
    if (gnFlag_007798D0 || gnFlag_007798D4)
        sub_004F9190();
    return 1;
}

// 0x00431A00
int __cdecl sub_00431A00_ShowArchiveMessage()
{
    sub_00431970_CreateScreen();
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader_007798D8 = (void*)ARCHIVE_LoadVideoArchives;
    gnLoaderFlag_007798E0 = 1;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x00431A40
int __stdcall sub_00431A40_SetMode2(int nArg)
{
    gnLaunchMode_007795EC = 2;
    sub_0042FFE0_CreateScreen();
    return 1;
}

// 0x00431C30
int __stdcall sub_00431C30_Leave(int nArg)
{
    gnLaunchState_007795E8 = 0;
    sub_00515F50(0xB4);
    sub_004F9190();
    return 1;
}

// 0x00431D10
int __stdcall sub_00431D10_ClearLoop(int nArg)
{
    sub_004F9190();
    return 1;
}

// 0x00431D20
int __stdcall sub_00431D20_CreateTcpIpScreen(int nArg)
{
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_004F95C0_ControlDestroy(&gpControl_00779344);
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0x10F);
    D2Win_10033(pControl, 0);
    sub_0042F3A0_CreateFromTemplate(0x10E);
    pControl = sub_0042F3A0_CreateFromTemplate(0x10C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B1F));
    gpAddressEdit_00779958 = sub_0042F3A0_CreateFromTemplate(0x10D);
    if (!gszAddress_007795F8[0])
        SRegLoadString("Diablo II", "LastTcpIp", 0, gszAddress_007795F8, 0x100);
    sub_004FFE10_SetTextA(gpAddressEdit_00779958, gszAddress_007795F8);
    sub_004F91C0(gpAddressEdit_00779958);
    D2Win_10082(gpAddressEdit_00779958);
    sub_004FA450_SetActive(sub_0042F3A0_CreateFromTemplate(0x110));
    sub_0042F3A0_CreateFromTemplate(0x111);
    return 1;
}

// 0x00431E00
int __stdcall sub_00431E00_CreateControl10B(int nArg)
{
    sub_0042F3F0_DestroyControls();
    gpControl_00779344 = sub_0042F430_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    return 1;
}

// 0x00431E30
int __stdcall sub_00431E30_PollConnection(int nArg)
{
    const int nStatus = CLIENT_GetConnectionStatus();
    if (!nStatus)
    {
        gbConnected_0077959C = nStatus;
        sub_004F9190();
        return 1;
    }
    if (nStatus == 2)
    {
        gbConnected_0077959C = 1;
        sub_004F9190();
    }
    return 1;
}
