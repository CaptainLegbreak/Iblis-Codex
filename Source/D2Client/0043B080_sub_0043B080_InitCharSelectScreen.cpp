struct Unicode;
struct D2WinControlStrc;
struct D2WinTimerStrc;
struct D2WinButtonStrc;
struct D2CellFileStrc;

class BNGatewayAccess
{
public:
    const char* __stdcall Realm(int nGateway);                                                                 // 0x005180E0

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x210];
    char nByte210;
};
#pragma pack(pop)

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x98];
    BNGatewayAccess* (__cdecl* pfnGetGatewayAccess)();
};

typedef void (__cdecl* D2LaunchDoneFn)();

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
int __cdecl sub_00408F20_HasExpansionMpq();                                                                    // 0x00408F20
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                        // 0x004135D0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                             // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                              // 0x0042F430
void __cdecl sub_0042F480_Reset();                                                                             // 0x0042F480
int __cdecl sub_00430B40();                                                                                    // 0x00430B40
char* __fastcall sub_00430B50_GetSlotName(int nIndex);                                                         // 0x00430B50
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);
void __cdecl sub_004336C0_ShowMainMenu();
void __cdecl sub_00434060();
void __cdecl sub_0043AE30_InitRealmList();
void __fastcall sub_0043ADB0_UseName(char* szName);
void __cdecl sub_0043B9A0();                                                                                   // 0x0043B9A0
int __stdcall BACKGROUND_SetCellFile(D2CellFileStrc* pCellFile);                                               // 0x004F9140
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                        // 0x004F96F0
void __fastcall sub_004F9740(D2WinControlStrc* pControl, int bSet);                     // 0x004F9740
void __fastcall sub_004FB590(int nArg);                                                                        // 0x004FB590
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall sub_004FD830(D2WinTimerStrc* pTimer);                                                           // 0x004FD830
void __fastcall sub_004FDA50(D2WinTimerStrc* pTimer);                                                           // 0x004FDA50
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* pButton, int nX, int nY, int nWidth, int nHeight);      // 0x00500A70
void __fastcall sub_005148F0_SetChannelValue(int nValue);                                                      // 0x005148F0
int __cdecl sub_00514D80();                                                                                    // 0x00514D80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                                 // 0x00524A30

extern "C" const char* const gapszSkyPalette_006D3A08[2];                                                      // 0x006D3A08
extern int gnSelected_0070CC00;                                                                                // 0x0070CC00
extern int gnVisibleRows_0070CC0C;                                                                             // 0x0070CC0C
extern D2CellFileStrc* gpCellFile_00779768;                                                                    // 0x00779768
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                            // 0x007795D4
extern int gnLaunchMode_007795EC;                                                                              // 0x007795EC
D2WinControlStrc* gpControl_007799F0;                                                                          // 0x007799F0
extern D2WinControlStrc* gpControl_007799F4;                                                                   // 0x007799F4
extern D2WinControlStrc* gpControl_007799F8;                                                                   // 0x007799F8
extern int ganRowValues_007799FC[];                                                                            // 0x007799FC
D2WinControlStrc* gpControl_00779A1C;                                                                          // 0x00779A1C
void* gapRowControls_00779A20[1];                                                                              // 0x00779A20
char gData_00779A40[256];                                                                                      // 0x00779A40
extern D2WinControlStrc* gpControl_00779B60;                                                                   // 0x00779B60
D2WinControlStrc* gpControl_00779B64;                                                                          // 0x00779B64
extern D2WinControlStrc* gpControl_00779C68;                                                                   // 0x00779C68
extern int gbFlag_00779C6C;                                                                                    // 0x00779C6C
D2WinControlStrc* gpControl_00779C70;                                                                          // 0x00779C70
D2WinControlStrc* gpControl_00779C78;                                                                          // 0x00779C78
extern D2WinControlStrc* gpControl_00779D8C;                                                                   // 0x00779D8C
extern D2WinControlStrc* gpControl_00779D90;                                                                   // 0x00779D90
extern D2WinControlStrc* gpControl_00779D94;                                                                   // 0x00779D94
D2WinControlStrc* gpControl_00779D98;                                                                          // 0x00779D98
extern int gdwGlobal_00779DA4;                                                                                 // 0x00779DA4
extern int gnState_00779DAC;                                                                                   // 0x00779DAC
extern int gdwGlobal_00779DC4;                                                                                 // 0x00779DC4
extern int gnTopRow_00779DC8;                                                                                  // 0x00779DC8
D2WinControlStrc* gpControl_00779DD0;                                                                          // 0x00779DD0
extern D2WinControlStrc* gpCharSelectText_00779DD4;                                                            // 0x00779DD4
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                         // 0x0077ABF0

static __declspec(noinline) int sub_00437A20_FindSlotName(const char* szName)
{
    int i = 0;
    char* szSlot;
    while (i < sub_00430B40() && (szSlot = sub_00430B50_GetSlotName(i)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            return 1;
        ++i;
    }
    return 0;
}

// 0x0043B080
void __cdecl sub_0043B080_InitCharSelectScreen()
{
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0043AE30_InitRealmList();
        return;
    }

    sub_0042F480_Reset();
    BACKGROUND_SetCellFile(gpCellFile_00779768);
    sub_0042F2E0_ReadPaletteFiles(gapszSkyPalette_006D3A08[0], gapszSkyPalette_006D3A08[1]);

    if (gnLaunchMode_007795EC == 1)
    {
        sub_00434060();
        const int nCount = sub_00430B40();
        if (nCount != -1)
        {
            if (nCount == 0)
            {
                sub_0043B9A0();
                sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14AA), sub_004336C0_ShowMainMenu);
                return;
            }
        }
        else
        {
            sub_0043B9A0();
            sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
            return;
        }
    }

    gdwGlobal_00779DA4 = 1;
    gdwGlobal_00779DC4 = 0;
    gnTopRow_00779DC8 = 0;
    gnSelected_0070CC00 = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText_00779DD4 = 0;
    gpControl_00779DD0 = 0;
    gnState_00779DAC = 0;

    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)sub_0042F430_CreateControl(0x7A);
    sub_004FD830(pTimer);
    sub_004FDA50(pTimer);
    gpLaunchRecord_007795D4->nByte210 = 0;

    gpControl_007799F8 = sub_0042F430_CreateControl(0x7C);
    gpControl_007799F4 = sub_0042F430_CreateControl(0x7D);
    sub_004F96F0_ControlClearState(gpControl_007799F4, 0);
    gpControl_00779C68 = sub_0042F430_CreateControl(0x7E);
    gpControl_00779A1C = sub_0042F430_CreateControl(0x99);
    gpControl_00779B64 = sub_0042F430_CreateControl(0x9A);
    sub_004F9740(gpControl_00779A1C, 0);
    sub_004F9740(gpControl_00779B64, 0);
    gpControl_00779B60 = sub_0042F430_CreateControl(0x9B);
    gpControl_007799F0 = sub_0042F430_CreateControl(0x9D);
    gpControl_00779C70 = sub_0042F430_CreateControl(0x9E);
    gpControl_00779D90 = sub_0042F430_CreateControl(0x9F);
    memset(gapRowControls_00779A20, 0, 0x20);

    if (gnLaunchMode_007795EC == 1)
    {
        gnVisibleRows_0070CC0C = 4;
        for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
        {
            sub_004FB590(1);
            gapRowControls_00779A20[i] = sub_0042F430_CreateControl(i + 0x80);
            sub_004FB590(0);
            ganRowValues_007799FC[i] = 0xF6 + 0x5D * i;
        }

        gpControl_00779DD0 = sub_0042F430_CreateControl(0x98);
        gpCharSelectText_00779DD4 = sub_0042F430_CreateControl(0x79);
        BUTTON_SetCoordinates((D2WinButtonStrc*)gpControl_00779A1C, 0x27A, 0x8F, 0x1D, 0x14);
        sub_0042F430_CreateControl(0x65);
        gpControl_00779D98 = sub_0042F430_CreateControl(0x67);
        gpControl_00779D8C = sub_0042F430_CreateControl(0x68);
        D2Win_10051(sub_0042F430_CreateControl(0x66), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

        int nFound = 0;
        if (SRegLoadString("Diablo II", "Preferred Realm", 0, gData_00779A40, 0x100))
            nFound = sub_00437A20_FindSlotName(gData_00779A40);
        if (nFound == 0)
        {
            BNGatewayAccess* pAccess = gpFuncTable_0077ABF0->pfnGetGatewayAccess();
            SStrCopy(gData_00779A40, pAccess->Realm(pAccess->m_nCurGateway), 0x7FFFFFFF);
            SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
            nFound = sub_00437A20_FindSlotName(gData_00779A40);
        }
        if (nFound == 0)
        {
            const char* szFirst = sub_00430B40() > 0 ? sub_00430B50_GetSlotName(0) : 0;
            SStrCopy(gData_00779A40, szFirst, 0x7FFFFFFF);
            SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
        }
    }
    else
    {
        gnVisibleRows_0070CC0C = 5;
        for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
        {
            sub_004FB590(1);
            gapRowControls_00779A20[i] = sub_0042F430_CreateControl(i + 0x7F);
            sub_004FB590(0);
            ganRowValues_007799FC[i] = 0x99 + 0x5D * i;
        }
        BUTTON_SetCoordinates((D2WinButtonStrc*)gpControl_00779A1C, 0x27A, 0x32, 0x1D, 0x14);
    }

    gpControl_00779D94 = sub_0042F430_CreateControl(0x96);
    gpControl_00779C78 = sub_0042F430_CreateControl(0x97);
    sub_004F9740(gpControl_00779C78, 0);
    sub_004F96F0_ControlClearState(gpControl_007799F8, 0);
    sub_0043ADB0_UseName(gData_00779A40);
    if (sub_00514D80())
        sub_005148F0_SetChannelValue(1);
    sub_004F96F0_ControlClearState(gpControl_007799F8, 1);
}
