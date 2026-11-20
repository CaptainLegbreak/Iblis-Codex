#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2LaunchControlTemplateStrc;
struct D2FuncTable_0077ABF0Strc;

struct Unicode
{
    unsigned short wChar;
};

struct D2LaunchControlTemplateStrc
{
    char unk0x00[0x30];
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
    char unk0x1A5[0x21E];
    unsigned int dwPasswordHash;
    int nPasswordLength;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
unsigned int __stdcall sub_00414150_HashPath(const char* szPath); // 0x00414150
int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
void __cdecl sub_00432100_CreateLoginScreen(); // 0x00432100
void __cdecl sub_004325B0_CreateScreen(); // 0x004325B0
int __cdecl sub_00433810_ShowTerms(); // 0x00433810
void __cdecl sub_00435330_ShowLoginScreen(); // 0x00435330
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode); // 0x0043C180
D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate); // 0x004F93C0
int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl); // 0x004F95C0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2); // 0x00526590
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
extern D2LaunchControlTemplateStrc gtControlTemplates_00708D10[]; // 0x00708D10
extern D2WinControlStrc* gpEdit_00779334; // 0x00779334
extern D2WinControlStrc* gpEdit_00779340; // 0x00779340
extern D2WinControlStrc* gpEdit_0077958C; // 0x0077958C
extern D2WinControlStrc* gpControl_00779594; // 0x00779594
extern D2LaunchDoneFn gpfnGatewayDone_007795BC; // 0x007795BC
extern int gnLaunchMode_007795EC; // 0x007795EC
extern int gbFeCharPalette_007795F0; // 0x007795F0
extern int gdwGlobal_007795F4; // 0x007795F4

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0xB8];
    void (__fastcall* pfnSlotB8)(char* szText);
};
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
int __fastcall sub_004F9190(); // 0x004F9190
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

D2WinControlStrc* gapControlsA_00779450[0x40]; // 0x00779450

int gnControlCountA_00779948; // 0x00779948

D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA_00779948 < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlTemplates_00708D10[nTemplateId]);
    gapControlsA_00779450[gnControlCountA_00779948++] = pControl;
    return pControl;
}

void __cdecl sub_0042F3F0_DestroyControls()
{
    for (int i = 0; i < gnControlCountA_00779948; ++i)
        CONTROL_Destroy(&gapControlsA_00779450[i]);
    gnControlCountA_00779948 = 0;
}

static void sub_00432080_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit)
{
    if (pAccountEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pAccountEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szPassword, pText, 0x100);
        gpLaunchRecord_007795D4->dwPasswordHash = sub_00414150_HashPath(gpLaunchRecord_007795D4->szPassword);
        gpLaunchRecord_007795D4->nPasswordLength = SStrLen(gpLaunchRecord_007795D4->szPassword);
    }
}

static int __stdcall sub_004330A0_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    sub_0042F3F0_DestroyControls();
    if (gbFeCharPalette_007795F0)
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    sub_004330A0_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00434E00
int __stdcall sub_00434E00_CheckFreeSpace(int nUnused)
{
    char szPath[0x400];
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    sub_00407050_GetSavePath(szPath, 0x400);
    for (unsigned int i = 0; i < 0x400; i += 1)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    if (nFreeClusters * nBytesPerSector * nSectorsPerCluster < 5000)
    {
        sub_00433380_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), sub_0042FDD0, 1);
        return 1;
    }
    return sub_00433810_ShowTerms();
}

int __stdcall sub_00435030_ChangePasswordOk(int nArg)
{
    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779340);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779340);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    sub_00526F70(gszOldPassword_00779550, pOldPassword, 0x100);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        sub_00433380_ShowMessage(pMessage, sub_00432100_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        sub_00433380_ShowMessage(pMessage, sub_00432100_CreateLoginScreen, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        sub_00433380_ShowMessage(pMessage, sub_00432100_CreateLoginScreen, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        sub_00433380_ShowMessage(pMessage, sub_00432100_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        sub_00433380_ShowMessage(pMessage, sub_00432100_CreateLoginScreen, 1);
        return 1;
    }
    gdwGlobal_007795F4 = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 1))
    {
        if (gdwGlobal_007795F4)
        {
            sub_00432100_CreateLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        sub_0042F3F0_DestroyControls();
        sub_0042FDD0();
    }
    return 1;
}

int __stdcall sub_004361B0_LoginOk(int nArg)
{
    if (!nArg)
    {
        sub_004336C0();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpControl_00779594))
        return 0;
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    if (sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        if (gnLaunchMode_007795EC == 1)
        {
            sub_00515020();
            sub_0042F480_Reset();
            sub_0043B080();
            return 1;
        }
        if (sub_00430BC0_HasSaveFiles())
        {
            sub_0042FDD0();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

int __stdcall sub_00436910_CreateAccountOk(int nArg)
{
    if (!nArg)
    {
        sub_00435330_ShowLoginScreen();
        return 1;
    }
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    sub_004325B0_CreateScreen();
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_00434E00.inc"

// 0x00436C10
static int sub_00436C10_CheckAtAndDot(const char* szText)
{
    if (!szText)
        return 0;
    int bValid = 0;
    const char* pAt = SStrChr(szText, '@');
    if (pAt)
    {
        const char* pDot = SStrChr(pAt, '.');
        if (pDot && pAt > szText && pDot > pAt + 1 && SStrLen(szText) > pDot - szText + 1)
            bValid = 1;
    }
    return bValid;
}

// 0x00436EB0
void __cdecl sub_00436EB0_UpdateOkButton()
{
    char szText[0x100];
    int bOk = sub_00526800(sub_004FDD90_GetEditText(gpEdit_007799DC)) > 0;
    if (bOk)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_007799E0);
        sub_005263E0(szText, pText, 0x100);
        bOk = sub_00436C10_CheckAtAndDot(szText);
    }
    sub_004F96F0_ControlClearState(gpButton_007799E4, bOk);
}

// 0x004371E0
void __cdecl sub_004371E0_UpdatePasswordOk()
{
    char szText3[0x100];
    char szText1[0x100];
    char szText2[0x100];
    int bOk = sub_00526800(sub_004FDD90_GetEditText(gpPasswordEdit_007799BC)) > 2;
    if (bOk)
    {
        const Unicode* pText1 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C0);
            sub_005263E0(szText1, pText1, 0x100);
        bOk = sub_00436C10_CheckAtAndDot(szText1);
        if (bOk)
        {
            const Unicode* pText2 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C8);
            sub_005263E0(szText2, pText2, 0x100);
            bOk = sub_00436C10_CheckAtAndDot(szText2);
            if (bOk)
            {
                const Unicode* pText3 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C4);
            sub_005263E0(szText3, pText3, 0x100);
                bOk = sub_00436C10_CheckAtAndDot(szText3);
            }
        }
    }
    sub_004F96F0_ControlClearState(gpPasswordOk_007799A4, bOk);
}

// 0x00437620
int __stdcall sub_00437620_ConfirmText(int nArg)
{
    char szText[0x100];
    const Unicode* pText1 = sub_004FDD90_GetEditText(gpEdit_007799CC);
    const Unicode* pText2 = sub_004FDD90_GetEditText(gpEdit_007799D0);
    if (!sub_005264F0_Compare(pText1, pText2))
    {
        sub_005263E0(szText, pText1, 0x100);
        if (!sub_00436C10_CheckAtAndDot(szText))
        {
            sub_0042F540_ShowMessageBox(D2LANG_GetStringFromTblIndex(0x2B5C), D2LANG_GetStringFromTblIndex(0x2B5D), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
            return 1;
        }
        gpFuncTable_0077ABF0->pfnSlotB8(szText);
        sub_004F9190();
        return 1;
    }
    sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5B), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
    return 1;
}
