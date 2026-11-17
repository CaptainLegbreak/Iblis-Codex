struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

typedef int (__stdcall* D2LaunchCallback)(int nArg);

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0xB8];
    void (__fastcall* pfnSlotB8)(char* szText);
};

const char* __stdcall SStrChr(const char* szString, char nChar);                                           // 0x00413490
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);                // 0x005263E0
int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2);                      // 0x005264F0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
int __stdcall sub_004334D0_CloseBox(int nArg);                                                              // 0x004334D0
int __fastcall sub_004F9190();                                                            // 0x004F9190

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2WinControlStrc* gpPasswordOk_007799A4;                                                             // 0x007799A4
extern D2WinControlStrc* gpPasswordEdit_007799BC;                                                           // 0x007799BC
extern D2WinControlStrc* gpPasswordEdit_007799C0;                                                           // 0x007799C0
extern D2WinControlStrc* gpPasswordEdit_007799C4;                                                           // 0x007799C4
extern D2WinControlStrc* gpPasswordEdit_007799C8;                                                           // 0x007799C8
extern D2WinControlStrc* gpEdit_007799CC;                                                                   // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0;                                                                   // 0x007799D0
extern D2WinControlStrc* gpEdit_007799DC;                                                                   // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0;                                                                   // 0x007799E0
extern D2WinControlStrc* gpButton_007799E4;                                                                 // 0x007799E4

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
