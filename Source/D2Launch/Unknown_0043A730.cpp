#include "D2Launch.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2WinTextBoxStrc;
struct D2WinTimerStrc;
struct D2WinButtonStrc;
struct D2CelFileStrc;
struct D2FuncTable_0077ABF0Strc;
struct D2CharSelCacheStrc;
class BNGatewayAccess;

void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
int __cdecl sub_00439210_Redraw(); // 0x00439210
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl sub_0043A800(); // 0x0043A800
extern int gnSelected_0070CC00; // 0x0070CC00
extern int gnSelectionA_0070CC04; // 0x0070CC04
extern D2WinControlStrc* gpControl_007799F8; // 0x007799F8
extern D2WinControlStrc* gpControl_00779A1C; // 0x00779A1C
extern char gData_00779A40[]; // 0x00779A40
extern D2WinControlStrc* gpControl_00779B64; // 0x00779B64
extern char gszName_00779C88[]; // 0x00779C88
extern int gdwGlobal_00779DC4; // 0x00779DC4
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __cdecl sub_0043A730_UpdateButtons(); // 0x0043A730
extern int gnLaunchMode_007795EC; // 0x007795EC
extern int gbFlag_00779C6C; // 0x00779C6C

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x0C];
    int (__fastcall* pfnSlot0C)();
    void (__fastcall* pfnSlot10)();
    char unk0x14[0x38];
    int (__fastcall* pfnSlot4C)();
    char unk0x50[0x14];
    int (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    unsigned char unk_6C[0x2C];
    BNGatewayAccess* (__cdecl* pfnGetGatewayAccess)();
    unsigned char unk_9C[0x4];
    int (__fastcall* pfnSlotA0)(int* pValue);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);
void __cdecl sub_004336C0_ShowMainMenu();
void __cdecl sub_00438EA0_FreeCharList();
int __stdcall sub_0043AAB0(const char* szName, int pPacket, int bFlag);
int __fastcall D2Win_10047(D2WinTextBoxStrc* pTextBox); // 0x004FB6A0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int a3); // 0x004FCFF0
void __cdecl sub_00438560_Refresh();
void __cdecl sub_0043A5D0_ShowMessage();
void __cdecl sub_00438F70();
extern D2CharSelCacheStrc* gpCharSelCache_00779DE8; // 0x00779DE8
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gdwGlobal_00779DB8; // 0x00779DB8
extern int gnState_00779DAC; // 0x00779DAC
extern char* gpszName_00779DB0; // 0x00779DB0
extern int gbFlag_00779DD8; // 0x00779DD8

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

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
int __cdecl sub_00430B40(); // 0x00430B40
void __cdecl sub_00434060();
void __cdecl sub_0043AE30_InitRealmList();
void __fastcall sub_0043ADB0_UseName(char* szName);
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
void __fastcall sub_004F9740(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __fastcall sub_004FB590(int nArg); // 0x004FB590
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall sub_004FD830_2(D2WinTimerStrc* pTimer); // 0x004FD830
void __fastcall sub_004FDA50_2(D2WinTimerStrc* pTimer); // 0x004FDA50
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* pButton, int nX, int nY, int nWidth, int nHeight); // 0x00500A70
extern D2CelFileStrc* gpCellFile_00779768; // 0x00779768
extern D2WinControlStrc* gpControl_00779D8C; // 0x00779D8C
extern int gnTopRow_00779DC8; // 0x00779DC8
extern D2WinControlStrc* gpCharSelectText_00779DD4; // 0x00779DD4

void __cdecl sub_0043A730_UpdateButtons(); // 0x0043A730
int __cdecl sub_0042FA30(); // 0x0042FA30
void __cdecl sub_0042F990_UpdateProgress(); // 0x0042F990
int __cdecl sub_0042F6D0(); // 0x0042F6D0
int __fastcall sub_004F9190(); // 0x004F9190
extern int gdwGlobal_0077AC04; // 0x0077AC04
void __cdecl sub_00518C20_DeleteQueueLock(); // 0x00518C20
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
int __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
int __fastcall D2Win_10192(D2WinTextBoxStrc* ptTextData); // 0x004FC620
int __fastcall D2Win_10193(D2WinTextBoxStrc* ptTextData, int nCurrentStep); // 0x004FC660
extern D2WinControlStrc* gpControl_007795E0; // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4
extern void** gppSlots_00779988; // 0x00779988
extern D2WinControlStrc* gpControl_00779C84; // 0x00779C84
extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
extern const char gacCDKeyMap_006DF238[];

int gdwGlobal_00779DB8; // 0x00779DB8

// 0x0043A730
void __cdecl sub_0043A730_UpdateButtons()
{
    sub_004F96F0_ControlClearState(gpControl_007799F4, (gdwGlobal_00779DC4 > 0 && gnSelected_0070CC00 > gnSelectionA_0070CC04) ? 1 : 0);
    sub_004F96F0_ControlClearState(gpControl_00779C68, gdwGlobal_00779DC4 > 0);
    sub_004F96F0_ControlClearState(gpControl_007799F8, 1);
    sub_004F96F0_ControlClearState(gpControl_00779A1C, 1);
    sub_004F96F0_ControlClearState(gpControl_00779B64, 1);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_004F96F0_ControlClearState(gpControl_00779C80, 1);
        sub_004F96F0_ControlClearState(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    }
    gnSelected_0070CC00 = 0;
    sub_00439210_Redraw();
}

// 0x0043A9A0
int __stdcall sub_0043A9A0_CopyName(int nArg)
{
    SStrCopy(gszName_00779C88, gData_00779A40, 0x7FFFFFFF);
    sub_0043A800();
    return 1;
}

// 0x0043A7E0
void __cdecl sub_0043A7E0_ResetRealmScreen()
{
    if (gnLaunchMode_007795EC == 1)
    {
        sub_0042F3F0_DestroyControls();
        sub_0043A730_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
}

D2WinControlStrc* gpControl_00779D8C; // 0x00779D8C

static inline void* CharSelCache_FindData(unsigned int dwHash, int nTick)
{
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x0043AD10
static void sub_0043AD10_RequestCharList(char* szName)
{
    sub_00438EA0_FreeCharList();
    gdwGlobal_00779DB8 = 0;
    sub_004F96F0_ControlClearState(gpControl_00779D90, 1);
    const unsigned int dwHash = SStrHash(szName, 0, 0);
    const int nTick = GetTickCount();
    void* pData = CharSelCache_FindData(dwHash, nTick);
    if (!pData)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
            return;
        }
        gnState_00779DAC = 1;
        gpszName_00779DB0 = szName;
        return;
    }
    sub_0043AAB0(szName, (int)pData, 0);
}

// 0x0043ADB0
void __fastcall sub_0043ADB0_UseName(char* szName)
{
    gbFlag_00779DD8 = 0;
    if (gnLaunchMode_007795EC == 1)
    {
        D2Win_10047((D2WinTextBoxStrc*)gpControl_00779D8C);
        D2Win_10046(gpControl_00779D8C, szName, 0);
        sub_0043AD10_RequestCharList(szName);
    }
    else if (gnLaunchMode_007795EC == 0 || gnLaunchMode_007795EC == 3 || gnLaunchMode_007795EC == 2)
    {
        sub_00438EA0_FreeCharList();
        if (!sub_00408F20_HasExpansionMpq())
            sub_0043A5D0_ShowMessage();
        sub_00438F70();
    }
    sub_00439210_Redraw();
    sub_00438560_Refresh();
}

D2WinControlStrc* gpControl_007799F0; // 0x007799F0

D2WinControlStrc* gpControl_00779A1C; // 0x00779A1C

void* gapRowControls_00779A20[1]; // 0x00779A20

char gData_00779A40[256]; // 0x00779A40

D2WinControlStrc* gpControl_00779B64; // 0x00779B64

D2WinControlStrc* gpControl_00779C70; // 0x00779C70

D2WinControlStrc* gpControl_00779C78; // 0x00779C78

D2WinControlStrc* gpControl_00779D98; // 0x00779D98

D2WinControlStrc* gpControl_00779DD0; // 0x00779DD0

static int sub_00437A20_FindSlotName(const char* szName)
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
    sub_004FD830_2(pTimer);
    sub_004FDA50_2(pTimer);
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

// 0x0043B490
int __stdcall sub_0043B490_OnName(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043ADB0_UseName(gData_00779A40);
    if (gnLaunchMode_007795EC == 1)
    {
        sub_0042F3F0_DestroyControls();
        sub_0043A730_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x0043B810
void __cdecl sub_0043B810_SetFlag()
{
    gdwGlobal_0077AC04 = 1;
}

// 0x0043B850
int __stdcall sub_0043B850_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x65 && !sub_0042FA30())
    {
        sub_0042F990_UpdateProgress();
        return 1;
    }
    sub_004F9190();
    return 1;
}

// 0x0043B890
int __stdcall sub_0043B890_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot0C())
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
        sub_004F9190();
    return 1;
}

// 0x0043B800
void __cdecl sub_0043B800_ClearFuncTable()
{
    gpFuncTable_0077ABF0 = 0;
    sub_00518C20_DeleteQueueLock();
}

// 0x0043B8E0
int __stdcall sub_0043B8E0_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlot64(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}

// 0x0043B940
int __stdcall sub_0043B940_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlotA0(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}

// 0x0043C530
static long sub_0051DC70_GetTime(long* pTime)
{
    return _time32(pTime);
}

static unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap_006DF238[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return sub_0051DC70_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return sub_0051DD10_NibbleToHex(tolower(n)) + sub_0051DD10_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return sub_0051DD20_HexToNibble((char)tolower(n)) * 16 + sub_0051DD20_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return sub_0051DD40_MapKeyChar((unsigned char)tolower(n)) * 24 + sub_0051DD40_MapKeyChar((unsigned char)tolower(n + 1));
}
