#include "D2Multi.h"

struct D2WinButtonStrc;

struct Unicode
{
    unsigned short wChar;
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

typedef int (__stdcall* D2LaunchCallback)(int nArg);
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __fastcall sub_004403F0_OnListEvent(int nA, int nB);                                                   // 0x004403F0
void __cdecl sub_0043ED50_Nop();                                                                            // 0x0043ED50
void __cdecl sub_004406F0_CreateClassScreen();                                                              // 0x004406F0
void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone);              // 0x004401C0
int __fastcall sub_004F9190();                                                            // 0x004F9190

extern D2WinControlInitStrc gtControlInits_0070CE50[];                                                      // 0x0070CE50
extern D2WinControlStrc* gpControls_0077ADA8[];                                                             // 0x0077ADA8
extern int gnControlCount_0077BBE8;                                                                         // 0x0077BBE8
D2WinButtonStrc* gpClassButtons_0077BC98[8];                                                                // 0x0077BC98
extern int gbExpansionClasses_0070CD70;                                                                     // 0x0070CD70
extern D2WinControlStrc* gpList_0077BD00;                                                                   // 0x0077BD00
extern int gnColor_0077AD74;                                                                                // 0x0077AD74
int gnSelection_0077BBF4;                                                                                   // 0x0077BBF4
int gnGlobal_0077B0A0;                                                                                      // 0x0077B0A0
int gnGlobal_0077AD70;                                                                                      // 0x0077AD70
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
extern int gbDone_0077BDA0;                                                                                 // 0x0077BDA0

static D2WinControlStrc* sub_0043E9D0_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount_0077BBE8 < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlInits_0070CE50[nIndex]);
    gpControls_0077ADA8[gnControlCount_0077BBE8++] = pControl;
    return pControl;
}

static inline void ResetClassSelectState(int bExpansionClasses)
{
    gbExpansionClasses_0070CD70 = bExpansionClasses;
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
}

// 0x004403E0
int __stdcall sub_004403E0_OnResetCallback(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    return 1;
}

// 0x004408B0
void __cdecl sub_004408B0_OpenClassSelectA()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(0);
        if (!sub_00449B30_QueryAddress())
        {
            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
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

// 0x00440980
void __cdecl sub_00440980_OpenClassSelectB()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(0);
        if (!sub_00449B30_QueryAddress())
        {
            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
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

// 0x00440A50
void __cdecl sub_00440A50_OpenClassSelectC()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(1);
        if (!sub_00449B30_QueryAddress())
        {
            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
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

// 0x00440B30
void __cdecl sub_00440B30_OpenClassSelectD()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(1);
        if (!sub_00449B30_QueryAddress())
        {
            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
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

// 0x00440C10
int __stdcall sub_00440C10_ShowClassSelectA(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_004408B0_OpenClassSelectA();
    gnSelectModeA_0070CD62 = 9;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C40
int __stdcall sub_00440C40_ShowClassSelectC(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00440A50_OpenClassSelectC();
    gnSelectModeA_0070CD62 = 0x1B;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C70
int __stdcall sub_00440C70_ShowClassSelectD(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00440B30_OpenClassSelectD();
    gnSelectModeA_0070CD62 = 0x13;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440DB0
int __stdcall sub_00440DB0_OnQuitMessage(int nArg)
{
    sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
    gbDone_0077BDA0 = 4;
    sub_004F9190();
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_004403E0.inc"
