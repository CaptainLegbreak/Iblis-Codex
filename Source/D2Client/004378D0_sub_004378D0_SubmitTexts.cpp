typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;
    Unicode();
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
typedef void (__cdecl* D2LaunchDoneFn)();

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x50];
    int (__fastcall* pfnSlotBC)(char* szA, char* szB);
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x68];
    int (__fastcall* pfn0x68)();
    char unk0x6C[0x40];
    void (__fastcall* pfn0xAC)();
};

struct D2LaunchCharEntryStrc
{
    char szName[0x100];
    Unicode wszName[0x100];
    char unk0x300[0x20];
    unsigned char nType;
    char unk0x321[0x03];
    unsigned short wFlags;
    char unk0x326[0x26];
    D2LaunchCharEntryStrc* pNext;
};

struct D2LaunchCharSelectStrc
{
    char unk0x000[0x210];
    char nMode;
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    char szText0x8D[0x10];
};

struct D2LaunchGameRecStrc
{
    char nUnk0x00;
    char szName[0x30];
    char wValue0x31[2];
    char wValue0x33[2];
    char f_35[2];
    char nAddress0x37[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);                                        // 0x00687605
extern "C" char* __cdecl strtok(char* szText, const char* szDelim);                                         // 0x0068264F
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
void __stdcall sub_00411320_CapitalizeWords(char* szText);                                                  // 0x00411320
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
char* __fastcall sub_0040E080_AddressToString(int nAddress);                                                // 0x0040E080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __cdecl sub_005269D0_Sprintf(int nCount, Unicode* pDest, const Unicode* pFormat, ...);                 // 0x005269D0
int __fastcall sub_004F9710_TestFlag(D2WinControlStrc* pControl);                                           // 0x004F9710
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl);                                    // 0x004FB950
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl);                                         // 0x004FBD20
void __fastcall sub_004FCD40_SetCell(D2WinControlStrc* pControl, const char* szText, int nRow, int nColumn); // 0x004FCD40
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine);                                 // 0x004FB9D0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton);                                           // 0x00500960
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __cdecl sub_004336C0();                                                                                // 0x004336C0
void __fastcall sub_00434A00_Join(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00
int __fastcall sub_00434960_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName);                    // 0x00434960
int __fastcall sub_004349B0_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName);                    // 0x004349B0
void __fastcall sub_00435180_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);              // 0x00435180
int __stdcall sub_004370B0(int nArg);                                                                       // 0x004370B0
void __cdecl sub_004370C0();                                                                                // 0x004370C0
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __cdecl sub_0043B080();                                                                                // 0x0043B080
void __fastcall sub_0043C750_JoinEntry(D2LaunchCharEntryStrc* pEntry, const char* szName);                  // 0x0043C750
int __fastcall sub_0043CAA0_UpdateSaveFlags(const char* szName);                                            // 0x0043CAA0
int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0
void __cdecl sub_0043E570();                                                                                // 0x0043E570
int __fastcall sub_0043F5F0_CallTable74(int nA, int nB, int nC, int nD);                                    // 0x0043F5F0
void __cdecl sub_0043FC20();                                                                                // 0x0043FC20
int __fastcall sub_0043FFA0_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
void __fastcall sub_004401C0_ShowText(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x004401C0
void __fastcall sub_004411E0_Use(const char* szText);                                                       // 0x004411E0
int __fastcall sub_004428D0_SendChatText(const char* szText, int bFlag);                                    // 0x004428D0
void __cdecl sub_00443130_Reset();                                                                          // 0x00443130
int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0
void __cdecl sub_00443E10();                                                                                // 0x00443E10
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
int __cdecl sub_00449C00();                                                                                 // 0x00449C00

extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern char gszValue_0070EBD0[];                                                                            // 0x0070EBD0
extern char gszValue_0070EBD4[];                                                                            // 0x0070EBD4
extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnHistoryIndex_0070CD74;                                                                         // 0x0070CD74
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4;                                                       // 0x007795D4
extern D2WinControlStrc* gpEdit_007799DC;                                                                   // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0;                                                                   // 0x007799E0
D2WinControlStrc* gpButton_007799E4;                                                                        // 0x007799E4
extern D2WinControlStrc* gpControl_00779C80;                                                                // 0x00779C80
int gbBusy_00779DA0;                                                                                        // 0x00779DA0
D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                                 // 0x00779DBC
extern int gbFlag_00779DD8;                                                                                 // 0x00779DD8
extern int gnCounter_00779DDC;                                                                              // 0x00779DDC
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
D2WinControlStrc* gpButton_0077BCEC;                                                                        // 0x0077BCEC
extern D2WinControlStrc* gpEdit_0077BCF4;                                                                   // 0x0077BCF4
extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern D2LaunchGameRecStrc gaNewGames_0077BDC8[];                                                           // 0x0077BDC8
extern D2LaunchGameRecStrc gaGames_0078A440[];                                                              // 0x0078A440
D2WinControlStrc* gpGameList_00798BC0;                                                                      // 0x00798BC0
extern D2WinControlStrc* gpGameText_00798BC4;                                                               // 0x00798BC4
D2WinControlStrc* gpJoinButton_00798BCC;                                                                    // 0x00798BCC
extern D2WinControlStrc* gpJoinName_00798BD4;                                                               // 0x00798BD4
extern D2WinControlStrc* gpJoinPassword_00798BD8;                                                           // 0x00798BD8
extern D2WinControlStrc* gpCreateButton_00798C28;                                                           // 0x00798C28
extern D2WinControlStrc* gpCreateName_00798C2C;                                                             // 0x00798C2C
extern D2WinControlStrc* gpMaxPlayerControl_00798C38;                                                       // 0x00798C38
extern D2WinControlStrc* gpEditBox_00798C3C;                                                                // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40;                                                                 // 0x00798C40
extern D2WinControlStrc* gpSubmitEditA_00798C80;                                                            // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB_00798C84;                                                            // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC_00798C88;                                                            // 0x00798C88
extern int gnSubmitMode_00798CAC;                                                                           // 0x00798CAC
int gnGameCount_00798CC8;                                                                                   // 0x00798CC8
extern int gnValue_00798CCC;                                                                                // 0x00798CCC

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004378D0
int __stdcall sub_004378D0_SubmitTexts(int nArg)
{
    char szA[0x100];
    char szB[0x100];

    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }

    if (!sub_004F9710_TestFlag(gpButton_007799E4))
        return 1;

    const Unicode* pTextA = sub_004FDD90_GetEditText(gpEdit_007799DC);
    const Unicode* pTextB = sub_004FDD90_GetEditText(gpEdit_007799E0);
    sub_005263E0(szA, pTextA, 0x100);
    sub_005263E0(szB, pTextB, 0x100);

    if (gpFuncTable_0077ABF0->pfnSlot68() && gpFuncTable_0077ABF0->pfnSlotBC(szA, szB))
    {
        sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B60), 0x13EE, 0, sub_004370B0, 0, 1, 0);
        return 1;
    }

    sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
    return 0;
}

// 0x00439AF0
void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode)
{
    char szName[0x100];

    if (gnSelected_0070CC00 == -1)
        return;

    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected_0070CC00 == i)
            break;
    }

    if (!pEntry)
        return;

    gpCharSelect_007795D4->nMode = nMode;
    sub_0042F3F0_DestroyControls();
    sub_00526F70(szName, pEntry->wszName, 0xFF);
    sub_00434A00_Join(pEntry, pEntry->wFlags, pEntry->nType, szName);
}

// 0x0043B520
int __stdcall sub_0043B520_OnCharSelect(int nArg)
{
    char szName[0x100];

    if (sub_00408F20_HasExpansionMpq())
    {
        D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
        for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
        {
            if (gnSelected_0070CC00 == i)
                break;
        }

        if (pEntry)
        {
            if (pEntry->wFlags & 0x20)
                return 1;

            int bOk;
            const Unicode* pwszName = pEntry->wszName;
            if (pwszName && pwszName->wChar)
            {
                sub_00526F70(szName, pwszName, 0xFF);
                bOk = sub_004349B0_Validate(pEntry, szName);
                if (!bOk)
                {
                    if (sub_00449C00() != 0x7B)
                    {
                        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080);
                    }
                    else
                    {
                        Unicode wszText[0x100];
                        Unicode wszArg[0x100];
                        sub_00526F20_ToUnicode(wszArg, pEntry->szName, 0x100);
                        sub_005269D0_Sprintf(0x100, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszArg);
                        sub_00433450_ShowText(wszText, sub_0043B080);
                    }
                    gbBusy_00779DA0 = 0;
                    return 1;
                }
            }
            else
            {
                bOk = sub_0043CAA0_UpdateSaveFlags(pEntry->szName);
            }

            if (bOk)
            {
                pEntry->wFlags |= 0x20;
                sub_00438560_Refresh();
                sub_0042F3F0_DestroyControls();
            }
            else
            {
                sub_00435180_ShowText(D2LANG_GetStringFromTblIndex(0x5570), sub_0043B080, 1);
            }
        }

        sub_004F96F0_ControlClearState(gpControl_00779C80, 0);
    }
    return 1;
}

// 0x0043B6B0
int __stdcall sub_0043B6B0_JoinSelected(int nArg)
{
    char szName[0x100];

    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected_0070CC00 == i)
            break;
    }

    if (pEntry)
    {
        gbBusy_00779DA0 = 1;

        const Unicode* pwszName = pEntry->wszName;
        if (pwszName && pwszName->wChar)
        {
            sub_00526F70(szName, pwszName, 0xFF);
            if (sub_00434960_Validate(pEntry, szName))
            {
                ++gnCounter_00779DDC;
                gbFlag_00779DD8 = 0;
                sub_0043C750_JoinEntry(pEntry, szName);
            }
            else
            {
                sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080);
                gbBusy_00779DA0 = 0;
                return 1;
            }
        }
        else
        {
            sub_0043C750_JoinEntry(pEntry, &gszEmptyAssertText);
        }

        sub_0043B080();
        gbBusy_00779DA0 = 0;
        return 1;
    }

    return 0;
}

// 0x0043E660
void __cdecl sub_0043E660_UpdateOkEnabled()
{
    char szText[0x20];

    const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    int bEnable = 0;
    if (pText)
    {
        sub_00526F70(szText, pText, 0x1F);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    sub_004F96F0_ControlClearState(gpButton_0077BCEC, bEnable);
}

// 0x00441240
int __stdcall sub_00441240_UseEditText(int nArg)
{
    char szText[0x100];

    if (!sub_004F9710_TestFlag(gpButton_0077BCEC))
        return 0;

    const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    if (pText)
    {
        sub_00526F70(szText, pText, 0x100);
        sub_004411E0_Use(szText);
    }
    return 1;
}

// 0x004412A0
int __stdcall sub_004412A0_UseRegistryChannel(int nArg)
{
    char szText[0x20];

    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 1;
    }

    gpLaunchFuncs_0077B09C->pfn0xAC();
    sub_0043E570();
    sub_0043FC20();
    sub_004411E0_Use(SRegLoadString("Diablo II", "Default Channel", 0, szText, 0x20) ? szText : &gszEmptyAssertText);
    return 1;
}

// 0x004429A0
int __stdcall sub_004429A0_ChatLine(const Unicode* pText)
{
    char szCopy[0x100];
    char szText[0x100];

    gnHistoryIndex_0070CD74 = -1;
    if (!sub_00526800(pText))
        return 0;

    D2_ASSERT(gpLaunchFuncs_0077B09C, 0x12C2);

    szText[0] = 0;
    sub_00526F70(szText, pText, 0x100);
    strcpy(szCopy, szText);

    char szDelim[2] = " ";
    if (!strtok(szCopy, szDelim))
    {
        sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
        return 1;
    }
    return sub_004428D0_SendChatText(szText, 0);
}

// 0x00442C20
void __cdecl sub_00442C20_HandleList()
{
    char szSel[0x100];
    char szNumber[0x10];

    if (!gpGameList_00798BC0)
        return;

    const Unicode* pSel = sub_004FBB30_GetText(gpGameList_00798BC0);
    int bHaveSel = 0;
    if (pSel)
    {
        sub_00526F70(szSel, pSel, 0x100);
        bHaveSel = 1;
    }

    int nTop = sub_004FB950_GetFirstVisible(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    gnGameCount_00798CC8 = gnValue_00798CCC;
    if (!gnGameCount_00798CC8)
        return;

    int bNoNumbers = !sub_00449B30_QueryAddress();
    memcpy(gaGames_0078A440, gaNewGames_0077BDC8, gnValue_00798CCC * sizeof(D2LaunchGameRecStrc));
    for (int i = 0; i < gnGameCount_00798CC8; ++i)
    {
        sub_004FCF80_SetTextA(gpGameList_00798BC0, gaGames_0078A440[i].szName);
        int nRow = sub_004FBD20_GetLastRow(gpGameList_00798BC0);
        if (!bNoNumbers)
        {
            _itoa(*(unsigned short*)gaGames_0078A440[i].wValue0x31, szNumber, 10);
            sub_004FCD40_SetCell(gpGameList_00798BC0, szNumber, nRow, 1);
        }
    }

    if (bHaveSel)
    {
        for (int i = 0; i < gnGameCount_00798CC8; ++i)
        {
            if (!strcmp(szSel, gaGames_0078A440[i].szName))
            {
                sub_004FB9D0_Select(gpGameList_00798BC0, i);
                break;
            }
        }
        D2Win_10053(gpGameList_00798BC0, nTop);
    }
    else
    {
        D2Win_10053(gpGameList_00798BC0, 0);
    }
}

// 0x00443360
int __cdecl sub_00443360_GetMaxPlayers()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    return atoi(szText);
}

// 0x00443390
int __cdecl sub_00443390_GetLevelRange()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    return atoi(szText);
}

// 0x004433C0
int __stdcall sub_004433C0_IncrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 8)
        ++nValue;
    sprintf(gszValue_0070EBD4, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, gszValue_0070EBD4);
    return 1;
}

// 0x00443420
int __stdcall sub_00443420_DecrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 1)
        --nValue;
    sprintf(gszValue_0070EBD4, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, gszValue_0070EBD4);
    return 1;
}

// 0x00443480
int __stdcall sub_00443480_IncrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 0x63)
        ++nValue;
    sprintf(gszValue_0070EBD0, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszValue_0070EBD0);
    return 1;
}

// 0x004434E0
int __stdcall sub_004434E0_DecrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 0)
        --nValue;
    sprintf(gszValue_0070EBD0, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszValue_0070EBD0);
    return 1;
}

// build: context sub_00443630_UpdateCreateButton
void __cdecl sub_00443630_UpdateCreateButton()
{
    char szText[0x104];
    int bName = 0;
    int bPlayers = 0;
    int bLevel = 0;

    const Unicode* pText = sub_004FDD90_GetEditText(gpCreateName_00798C2C);
    if (pText)
    {
        sub_00526F70(szText, pText, 0x10);
        int nLen = strlen(szText);
        if (szText[0] != ' ' && nLen >= 1 && szText[nLen - 1] != ' ')
            bName = 1;
    }

    if (sub_00449B30_QueryAddress())
    {
        pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
        if (pText)
        {
            sub_00526F70(szText, pText, 3);
            if (strlen(szText))
            {
                bPlayers = 1;
                int nPlayers = atoi(szText);
                if (nPlayers < 1 || nPlayers > 8)
                {
                    nPlayers = D2_MIN(D2_MAX(nPlayers, 1), 8);
                    sprintf(szText, gszFormatD_006D57BC, nPlayers);
                    sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, szText);
                }
            }
        }

        if (sub_00500960_IsPressed(gpButton_00798C40))
        {
            pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
            sub_00526F70(szText, pText, 3);
            if (strlen(szText) && atoi(szText) >= 0)
                bLevel = 1;
        }
        else
        {
            bLevel = 1;
        }
    }
    else
    {
        bPlayers = 1;
        bLevel = 1;
    }

    if (bName && bPlayers && bLevel)
        sub_004F96F0_ControlClearState(gpCreateButton_00798C28, 1);
    else
        sub_004F96F0_ControlClearState(gpCreateButton_00798C28, 0);
}

// 0x004437E0
void __cdecl sub_004437E0_UpdateButtonState()
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpJoinName_00798BD4);
    int bEnable = 0;
    if (pText)
    {
        sub_00526F70(szText, pText, 0xFF);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    sub_004F96F0_ControlClearState(gpJoinButton_00798BCC, bEnable);
}

// 0x004439F0
int __stdcall sub_004439F0_JoinByName(int nArg)
{
    char szPassword[0x100];
    char szName[0x100];
    D2LaunchGameRecStrc tRecord;

    if (!sub_004F9710_TestFlag(gpJoinButton_00798BCC))
        return 0;

    const Unicode* pName = sub_004FDD90_GetEditText(gpJoinName_00798BD4);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpJoinPassword_00798BD8);
    if (pName)
    {
        sub_00526F70(szName, pName, 0x100);
        sub_00526F70(szPassword, pPassword, 0x100);
        sub_00411320_CapitalizeWords(szName);
        sub_00411320_CapitalizeWords(szPassword);

        if (sub_00449B30_QueryAddress())
        {
            sub_0043FFA0_SetupCharacter(0, szName, szPassword, 0);
            sub_00443130_Reset();
            sub_004401C0_ShowText(D2LANG_GetStringFromTblIndex(0x147B), 0);
            return 1;
        }

        for (int i = 0; i < gnValue_00798CCC; ++i)
        {
            if (!strcmp(gaGames_0078A440[i].szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)gaGames_0078A440[i].wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)gaGames_0078A440[i].nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowText(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }

        if (sub_004438E0_Lookup(szName, szPassword, &tRecord))
        {
            if (!strcmp(tRecord.szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)tRecord.wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)tRecord.nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowText(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }
        else
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x1411), 0);
        }
    }

    return 0;
}

// 0x00443F80
int __stdcall sub_00443F80_SubmitCreateGame(int nArg)
{
    if (gnSubmitMode_00798CAC == 2)
    {
        char szA[0x8 + 1];
        char szB[0x28 + 1];
        char szC[0xC8 + 1];

        const Unicode* pTextA = sub_004FDD90_GetEditText(gpSubmitEditA_00798C80);
        const Unicode* pTextB = sub_004FDD90_GetEditText(gpSubmitEditB_00798C84);
        const Unicode* pTextC = sub_004FDD90_GetEditText(gpSubmitEditC_00798C88);
        char* szName = gpCharInfo_0077BBD8->szText0x8D;
        sub_00526F70(szA, pTextA, 0x8);
        sub_00526F70(szB, pTextB, 0x28);
        sub_00526F70(szC, pTextC, 0xC8);
        if (!sub_0043F5F0_CallTable74((int)szName, (int)szA, (int)szB, (int)szC))
            return 1;
    }

    sub_00443E10();
    return 1;
}

// 0x00446890
int __stdcall sub_00446890_SendChatLine(int nArg)
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
    if (pText && sub_00526800(pText))
    {
        sub_00526F70(szText, pText, 0x100);
        return sub_004428D0_SendChatText(szText, 0);
    }
    return 1;
}

#include "gen/data/Source/D2Client/004378D0_sub_004378D0_SubmitTexts.inc"
