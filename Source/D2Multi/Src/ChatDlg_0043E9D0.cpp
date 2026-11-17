#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinButtonStrc;
struct Unicode;
struct D2LaunchCharInfoStrc;
struct UnicodeChar;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2WinControlInitStrc
{
    char data[0x30];
};

struct D2LaunchCharInfoStrc
{
    char unk0x000[0x22D];
    char nByte22D;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* pButton, int bIsPressed); // 0x005009A0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __cdecl sub_00525150(); // 0x00525150
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_004FC720(D2WinControlStrc* pList, int nValue); // 0x004FC720
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740
void __fastcall sub_004FBCD0(D2WinControlStrc* pList, int nColumn, int nValue); // 0x004FBCD0
void __cdecl sub_0043F0E0(); // 0x0043F0E0
void __fastcall sub_004FD830(D2WinControlStrc* pControl); // 0x004FD830
void __fastcall sub_004FDA50(D2WinControlStrc* pControl); // 0x004FDA50
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50
void __fastcall sub_004403F0_OnListEvent(int nA, int nB); // 0x004403F0
void __cdecl sub_0043ED50_Nop(); // 0x0043ED50
int __stdcall sub_0043EB00_OnErrorDone(int nArg); // 0x0043EB00
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern D2WinControlInitStrc gtControlInits_0070CE50[]; // 0x0070CE50
extern D2LaunchCallback gpfnLaunchCallback_0077BDA4; // 0x0077BDA4
extern unsigned long gdwConnectTime_0077BBF0; // 0x0077BBF0
extern int gnSelection_0077BBF4; // 0x0077BBF4
extern int gnGlobal_0077B0A0; // 0x0077B0A0
extern int gnGlobal_0077AD70; // 0x0077AD70
extern char gszSelectName_0077B040[]; // 0x0077B040
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

extern "C" void __fastcall sub_00500B20_SetButtonField5C(D2WinButtonStrc* pButton, int nValue); // 0x00500B20
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
extern "C" int __cdecl rand();
extern D2WinControlStrc* gpChatControl_0077BC48; // 0x0077BC48
extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C

D2WinControlStrc* gpControls_0077ADA8[32]; // 0x0077ADA8

int gnControlCount_0077BBE8; // 0x0077BBE8

static D2WinButtonStrc* gpClassButtons_0077BC98[8]; // 0x0077BC98

static int gbExpansionClasses_0070CD70; // 0x0070CD70

static D2WinControlStrc* gpList_0077BD00; // 0x0077BD00

static int gnColor_0077AD74; // 0x0077AD74

// 0x0043E9D0
static D2WinControlStrc* sub_0043E9D0_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount_0077BBE8 < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlInits_0070CE50[nIndex]);
    gpControls_0077ADA8[gnControlCount_0077BBE8++] = pControl;
    return pControl;
}

// 0x0043EA70
void __fastcall sub_0043EA70_ShowMessage(const Unicode* pTitle, const Unicode* pText)
{
    sub_0043EA20_Wait();
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x25);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x27);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x28);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, pTitle, 0, 0, 0);
    pControl = sub_0043E9D0_CreateControl(0x29);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, pText, 0, 0, 0);
}

// 0x0043EB30
void __cdecl sub_0043EB30_CreateControls()
{
    D2WinControlStrc* pControl;
    sub_0043E9D0_CreateControl(0x5D);
    pControl = sub_0043E9D0_CreateControl(0x5E);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    sub_0043E9D0_CreateControl(0x5F);
    sub_0043E9D0_CreateControl(0x61);
    sub_0043E9D0_CreateControl(0x62);
    sub_0043E9D0_CreateControl(0x63);
    sub_004FA450_SetActive(sub_0043E9D0_CreateControl(0x64));
}

// 0x0043ED60
void __cdecl sub_0043ED60_CreateClassButtons()
{
    D2WinControlStrc* pControl;
    Unicode szText0[0x10];
    Unicode szText1[0x10];
    Unicode szText2[0x10];
    Unicode szText3[0x10];
    Unicode szText4[0x10];
    Unicode szText5[0x10];
    Unicode szText6[0x10];
    sub_00526F20_ToUnicode(szText0, "AMA", 0x10);
    sub_00526F20_ToUnicode(szText1, "SOR", 0x10);
    sub_00526F20_ToUnicode(szText2, "NEC", 0x10);
    sub_00526F20_ToUnicode(szText3, "PAL", 0x10);
    sub_00526F20_ToUnicode(szText4, "BAR", 0x10);
    sub_00526F20_ToUnicode(szText5, "DRU", 0x10);
    sub_00526F20_ToUnicode(szText6, "ASN", 0x10);
    gpClassButtons_0077BC98[0] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x6E);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[0], 1);
    pControl = sub_0043E9D0_CreateControl(0x76);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14CE));
    gpClassButtons_0077BC98[1] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x6F);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[1], 0);
    sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x77), szText0);
    gpClassButtons_0077BC98[2] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x70);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[2], 0);
    sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x78), szText1);
    gpClassButtons_0077BC98[3] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x71);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[3], 0);
    sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x79), szText2);
    gpClassButtons_0077BC98[4] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x72);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[4], 0);
    sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x7A), szText3);
    gpClassButtons_0077BC98[5] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x73);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[5], 0);
    sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x7B), szText4);
    if (gbExpansionClasses_0070CD70)
    {
        gpClassButtons_0077BC98[6] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x74);
        BUTTON_SetIsPressed(gpClassButtons_0077BC98[6], 0);
        sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x7C), szText5);
        gpClassButtons_0077BC98[7] = (D2WinButtonStrc*)sub_0043E9D0_CreateControl(0x75);
        BUTTON_SetIsPressed(gpClassButtons_0077BC98[7], 0);
        sub_004FD060_SetText(sub_0043E9D0_CreateControl(0x7D), szText6);
    }
}

// 0x00440140
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone)
{
    sub_0043EA20_Wait();
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x22);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, pText, 0, 0, 0);
    gpfnLaunchCallback_0077BDA4 = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
}

// 0x004401C0
void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone)
{
    sub_0043EA20_Wait();
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x23);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0043E9D0_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, pText, 0, 0, 0);
    gpfnLaunchCallback_0077BDA4 = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
    gdwConnectTime_0077BBF0 = GetTickCount();
}

// 0x004406F0
void __cdecl sub_004406F0_CreateClassScreen()
{
    sub_0043ED60_CreateClassButtons();
    sub_004FA450_SetActive(sub_0043E9D0_CreateControl(0x6D));
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x67);
    sub_004FD060_SetText(pControl, sub_00525150() == 3 ? D2LANG_GetStringFromTblIndex(0x2B54) : D2LANG_GetStringFromTblIndex(0x14C8));
    pControl = sub_0043E9D0_CreateControl(0x68);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14C9));
    pControl = sub_0043E9D0_CreateControl(0x69);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14CA));
    pControl = sub_0043E9D0_CreateControl(0x6B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14CC));
    pControl = sub_0043E9D0_CreateControl(0x6A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0xFD9));
    gpList_0077BD00 = sub_0043E9D0_CreateControl(0x6C);
    sub_004FC720(gpList_0077BD00, 0x10);
    sub_004FBC20(gpList_0077BD00, 5);
    sub_004FB740(gpList_0077BD00, 0, -6);
    sub_004FBC80(gpList_0077BD00, 0, 0);
    sub_004FBCD0(gpList_0077BD00, 0, 0x10);
    sub_004FBC80(gpList_0077BD00, 1, 0x23);
    sub_004FBC80(gpList_0077BD00, 2, 0xA5);
    sub_004FBC80(gpList_0077BD00, 3, 0xC3);
    sub_004FBCD0(gpList_0077BD00, 3, 0x10);
    sub_004FBC80(gpList_0077BD00, 4, 0xDC);
    sub_004FBCD0(gpList_0077BD00, 4, 0x10);
    sub_0043F0E0();
    pControl = sub_0043E9D0_CreateControl(0x80);
    sub_004FD830(pControl);
    sub_004FDA50(pControl);
    gszSelectName_0077B040[0] = 0;
}

void __cdecl sub_004408B0_OpenClassSelectA()
{
    gbExpansionClasses_0070CD70 = 0;
    gpClassButtons_0077BC98[0] = 0;
    gpClassButtons_0077BC98[1] = 0;
    gpClassButtons_0077BC98[2] = 0;
    gpClassButtons_0077BC98[3] = 0;
    gpClassButtons_0077BC98[4] = 0;
    gpClassButtons_0077BC98[5] = 0;
    gpClassButtons_0077BC98[6] = 0;
    gpClassButtons_0077BC98[7] = 0;
    gpList_0077BD00 = 0;
    gnColor_0077AD74 = 1000;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }

    sub_0043E9D0_CreateControl(0x65);
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x66);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    sub_004406F0_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(sub_004403F0_OnListEvent, sub_0043ED50_Nop);
}

void __cdecl sub_00440980_OpenClassSelectB()
{
    gbExpansionClasses_0070CD70 = 0;
    gpClassButtons_0077BC98[0] = 0;
    gpClassButtons_0077BC98[1] = 0;
    gpClassButtons_0077BC98[2] = 0;
    gpClassButtons_0077BC98[3] = 0;
    gpClassButtons_0077BC98[4] = 0;
    gpClassButtons_0077BC98[5] = 0;
    gpClassButtons_0077BC98[6] = 0;
    gpClassButtons_0077BC98[7] = 0;
    gpList_0077BD00 = 0;
    gnColor_0077AD74 = 1000;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }

    sub_0043E9D0_CreateControl(0x65);
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x66);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14C6));
    sub_004406F0_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(sub_004403F0_OnListEvent, sub_0043ED50_Nop);
}

void __cdecl sub_00440A50_OpenClassSelectC()
{
    gbExpansionClasses_0070CD70 = 1;
    gpClassButtons_0077BC98[0] = 0;
    gpClassButtons_0077BC98[1] = 0;
    gpClassButtons_0077BC98[2] = 0;
    gpClassButtons_0077BC98[3] = 0;
    gpClassButtons_0077BC98[4] = 0;
    gpClassButtons_0077BC98[5] = 0;
    gpClassButtons_0077BC98[6] = 0;
    gpClassButtons_0077BC98[7] = 0;
    gpList_0077BD00 = 0;
    gnColor_0077AD74 = 1000;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }

    sub_0043E9D0_CreateControl(0x65);
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x66);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x276A));
    sub_004406F0_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(sub_004403F0_OnListEvent, sub_0043ED50_Nop);
}

void __cdecl sub_00440B30_OpenClassSelectD()
{
    gbExpansionClasses_0070CD70 = 1;
    gpClassButtons_0077BC98[0] = 0;
    gpClassButtons_0077BC98[1] = 0;
    gpClassButtons_0077BC98[2] = 0;
    gpClassButtons_0077BC98[3] = 0;
    gpClassButtons_0077BC98[4] = 0;
    gpClassButtons_0077BC98[5] = 0;
    gpClassButtons_0077BC98[6] = 0;
    gpClassButtons_0077BC98[7] = 0;
    gpList_0077BD00 = 0;
    gnColor_0077AD74 = 1000;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }

    sub_0043E9D0_CreateControl(0x65);
    D2WinControlStrc* pControl = sub_0043E9D0_CreateControl(0x66);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x276B));
    sub_004406F0_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(sub_004403F0_OnListEvent, sub_0043ED50_Nop);
}

int gbToggle_0077BBEC; // 0x0077BBEC

static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
        D2Win_10051(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043F630
int __stdcall sub_0043F630_OnToggleButton(int nArg)
{
    if (gbToggle_0077BBEC)
    {
        sub_00500B20_SetButtonField5C((D2WinButtonStrc*)gpChatControl_0077BC48, 0);
        gbToggle_0077BBEC = 0;
        PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D7), 0x0B);
    }
    else
    {
        sub_00500B20_SetButtonField5C((D2WinButtonStrc*)gpChatControl_0077BC48, 2);
        gbToggle_0077BBEC = 1;
        if (rand() % 1000 == 0)
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D8), 0x0B);
        }
        else if (rand() % 1000 == 0 && rand() % 1000 == 0)
        {
            UnicodeChar wszText[20];
            sub_00526320_ToUnicode(wszText, "Moooooooo!", 12);
            PrintTextBox(wszText, 9);
        }
        else
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D6), 0x0B);
        }
    }
    return 1;
}
