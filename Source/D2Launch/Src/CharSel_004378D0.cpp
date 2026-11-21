#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct SMSGHANDLER_PARAMS;
struct D2LaunchCharEntryStrc;
struct D2LaunchCharSelectStrc;
struct D2LaunchGameRecStrc;

struct D2CompositeUnitStrc;
struct D2CelFileStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};

struct D2LaunchCharSelectStrc
{
    char unk0x000[0x210];
    char nMode;
};

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __stdcall sub_00411320_CapitalizeWords(char* szText); // 0x00411320
char* __fastcall sub_0040E080_AddressToString(int nAddress); // 0x0040E080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4); // 0x004FCD40
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton); // 0x00500960
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __fastcall sub_00434A00_Join(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00
int __fastcall sub_00434960_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x00434960
int __fastcall sub_004349B0_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x004349B0
void __fastcall sub_00435180_ShowMessage2(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00435180
int __stdcall sub_004370B0_ShowLoginScreen(int nArg); // 0x004370B0
void __cdecl sub_0043B080_InitCharSelectScreen(); // 0x0043B080
void __fastcall sub_0043C750_JoinEntry(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x0043C750
int __fastcall sub_0043CAA0_UpdateSaveFlags(const char* szName); // 0x0043CAA0
int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0
int __cdecl sub_0043E570(); // 0x0043E570
int __fastcall sub_0043F5F0_CallTable74(int nA, int nB, int nC, int nD); // 0x0043F5F0
void __cdecl sub_0043FC20(); // 0x0043FC20
int __fastcall sub_0043FFA0_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
void __fastcall sub_004411E0_Use(const char* szText); // 0x004411E0
int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper); // 0x004428D0
int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0
extern char gszValue_0070EBD0[]; // 0x0070EBD0
extern char gszValue_0070EBD4[]; // 0x0070EBD4
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80
extern int gnCounter_00779DDC; // 0x00779DDC
extern D2LaunchGameRecStrc gaNewGames_0077BDC8[]; // 0x0077BDC8
extern D2LaunchGameRecStrc gaGames_0078A440[]; // 0x0078A440
extern D2WinControlStrc* gpGameText_00798BC4; // 0x00798BC4
extern D2WinControlStrc* gpJoinName_00798BD4; // 0x00798BD4
extern D2WinControlStrc* gpJoinPassword_00798BD8; // 0x00798BD8
extern D2WinControlStrc* gpCreateButton_00798C28; // 0x00798C28
extern D2WinControlStrc* gpCreateName_00798C2C; // 0x00798C2C
extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40; // 0x00798C40
extern D2WinControlStrc* gpSubmitEditA_00798C80; // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB_00798C84; // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC_00798C88; // 0x00798C88
extern int gnSubmitMode_00798CAC; // 0x00798CAC
char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50
void __cdecl sub_0043A270_UpdateStatus(); // 0x0043A270
extern int gbFlag_00779C6C; // 0x00779C6C
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern int gnState_00779DAC; // 0x00779DAC
extern char* gpszName_00779DB0; // 0x00779DB0
extern unsigned long gdwStartTick_00779DB4; // 0x00779DB4
static __declspec(noinline) void sub_00437CB0_SelectNamedSlot(const char* szName);

D2WinControlStrc* gpButton_007799E4; // 0x007799E4

int gbBusy_00779DA0; // 0x00779DA0

D2LaunchCharEntryStrc* gpCharList_00779DBC; // 0x00779DBC

D2WinControlStrc* gpButton_0077BCEC; // 0x0077BCEC

D2WinControlStrc* gpGameList_00798BC0; // 0x00798BC0

D2WinControlStrc* gpJoinButton_00798BCC; // 0x00798BCC

int gnGameCount_00798CC8; // 0x00798CC8

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
        sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B60), 0x13EE, 0, sub_004370B0_ShowLoginScreen, 0, 1, 0);
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
                        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080_InitCharSelectScreen);
                    }
                    else
                    {
                        Unicode wszText[0x100];
                        Unicode wszArg[0x100];
                        sub_00526F20_ToUnicode(wszArg, pEntry->szName, 0x100);
                        sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszArg);
                        sub_00433450_ShowText(wszText, sub_0043B080_InitCharSelectScreen);
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
                sub_00435180_ShowMessage2(D2LANG_GetStringFromTblIndex(0x5570), sub_0043B080_InitCharSelectScreen, 1);
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
                sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080_InitCharSelectScreen);
                gbBusy_00779DA0 = 0;
                return 1;
            }
        }
        else
        {
            sub_0043C750_JoinEntry(pEntry, &gszEmptyAssertText);
        }

        sub_0043B080_InitCharSelectScreen();
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
        D2Win_10045(gpGameList_00798BC0, gaGames_0078A440[i].szName);
        int nRow = sub_004FBD20_GetLastRow(gpGameList_00798BC0);
        if (!bNoNumbers)
        {
            _itoa(*(unsigned short*)gaGames_0078A440[i].wValue0x31, szNumber, 10);
            D2Win_10057(gpGameList_00798BC0, szNumber, nRow, 1);
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
            sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            return 1;
        }

        for (int i = 0; i < gnValue_00798CCC; ++i)
        {
            if (!strcmp(gaGames_0078A440[i].szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)gaGames_0078A440[i].wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)gaGames_0078A440[i].nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }

        if (sub_004438E0_Lookup(szName, szPassword, &tRecord))
        {
            if (!strcmp(tRecord.szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)tRecord.wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)tRecord.nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
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

#include "gen/data/Source/D2Launch/Src/CharSel_004378D0.inc"
struct D2WinControlStrc;

// 0x00437CB0
static void sub_00437CB0_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
    char* szSlot;
    while ((szSlot = (i < sub_00430B40() ? sub_00430B50_GetSlotName(i) : 0)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            D2Win_10188(gpNameControl_007799E8, i, 1);
        ++i;
    }
}

static __declspec(noinline) void sub_0043A1F0_ShowConnectError(int nError)
{
    int nStringId;
    switch (nError)
    {
    case 0x7E:
        nStringId = 0x2B99;
        break;
    case 0x7F:
        nStringId = 0x2B9A;
        break;
    default:
        nStringId = 0x2B3A;
        break;
    }

    gdwGlobal_00779DB8 = 1;
    gnState_00779DAC = 0;
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(nStringId), 4, 0, 0);
    sub_004F96F0_ControlClearState(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

int __stdcall sub_0043AC00_PollConnect(int nUnused)
{
    switch (gnState_00779DAC)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl_007799E8, -1, 4);
        sub_00437CB0_SelectNamedSlot(gpszName_00779DB0);
        sub_00432480(gpszName_00779DB0, 1);
        gnState_00779DAC = 2;
        gdwStartTick_00779DB4 = GetTickCount();
        break;

    case 2:
        sub_0043A270_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
            sub_00449E70_SetMcpPacket(0, 0);
            gnState_00779DAC = 3;
            if (!sub_0044AAB0_SendPacket19())
                sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        case 2:
            sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        }
        break;

    case 3:
    {
        sub_0043A270_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnState_00779DAC = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl_007799E8, -1, 4);
            sub_0043AAB0(gpszName_00779DB0, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}
