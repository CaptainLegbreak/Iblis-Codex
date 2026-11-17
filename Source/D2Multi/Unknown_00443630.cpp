#include "D2Multi.h"

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
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
char* __fastcall sub_0040E080_AddressToString(int nAddress);                                                // 0x0040E080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __cdecl sub_005269D0_Sprintf(int nCount, Unicode* pDest, const Unicode* pFormat, ...);                 // 0x005269D0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl);                                         // 0x004FBD20
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __cdecl sub_004336C0();                                                                                // 0x004336C0
int __fastcall sub_00434960_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName);                    // 0x00434960
int __fastcall sub_004349B0_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName);                    // 0x004349B0
void __fastcall sub_00435180_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);              // 0x00435180
int __stdcall sub_004370B0(int nArg);                                                                       // 0x004370B0
void __cdecl sub_004370C0();                                                                                // 0x004370C0
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __cdecl sub_0043B080();                                                                                // 0x0043B080
void __fastcall sub_0043C750_JoinEntry(D2LaunchCharEntryStrc* pEntry, const char* szName);                  // 0x0043C750
int __fastcall sub_0043CAA0_UpdateSaveFlags(const char* szName);                                            // 0x0043CAA0
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
extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern D2WinControlStrc* gpEdit_007799DC;                                                                   // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0;                                                                   // 0x007799E0
extern D2WinControlStrc* gpButton_007799E4;                                                                 // 0x007799E4
extern D2WinControlStrc* gpControl_00779C80;                                                                // 0x00779C80
extern int gbFlag_00779DD8;                                                                                 // 0x00779DD8
extern int gnCounter_00779DDC;                                                                              // 0x00779DDC
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern D2WinControlStrc* gpButton_0077BCEC;                                                                 // 0x0077BCEC
extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern D2LaunchGameRecStrc gaNewGames_0077BDC8[];                                                           // 0x0077BDC8
extern D2LaunchGameRecStrc gaGames_0078A440[];                                                              // 0x0078A440
extern D2WinControlStrc* gpJoinButton_00798BCC;                                                             // 0x00798BCC
extern D2WinControlStrc* gpJoinName_00798BD4;                                                               // 0x00798BD4
extern D2WinControlStrc* gpJoinPassword_00798BD8;                                                           // 0x00798BD8
D2WinControlStrc* gpCreateButton_00798C28;                                                                  // 0x00798C28
extern D2WinControlStrc* gpCreateName_00798C2C;                                                             // 0x00798C2C
extern D2WinControlStrc* gpEditBox_00798C3C;                                                                // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40;                                                                 // 0x00798C40
extern D2WinControlStrc* gpSubmitEditA_00798C80;                                                            // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB_00798C84;                                                            // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC_00798C88;                                                            // 0x00798C88
extern int gnSubmitMode_00798CAC;                                                                           // 0x00798CAC

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x00443630
void __cdecl sub_00443630_UpdateCreateButton()
{
    char szText[0x100];
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
