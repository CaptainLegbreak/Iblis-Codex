#include "D2Multi.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinButtonStrc;
struct D2WinMsgStrc;

void __cdecl sub_0043F060_ReleaseClassButtons();                                                            // 0x0043F060
void __cdecl sub_0043F0E0();                                                                                // 0x0043F0E0
void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* pButton, int bIsPressed);                              // 0x005009A0

extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
int gnColor_0077AD74;                                                                                       // 0x0077AD74
extern D2WinButtonStrc* gpClassButtons_0077BC98[8];                                                         // 0x0077BC98

// 0x0043F150
static int __stdcall sub_0043F150_GetClassSlot(int nBase, int nMode)
{
    int nOffset;
    if (nMode >= 9 && nMode <= 16)
    {
        nOffset = 9;
    }
    else if (nMode >= 0 && nMode <= 7)
    {
        nOffset = 0;
    }
    else if (nMode >= 0x13 && nMode <= 0x1A)
    {
        nOffset = 0x13;
    }
    else if (nMode >= 0x1B && nMode <= 0x22)
    {
        nOffset = 0x1B;
    }
    else
    {
        D2_ASSERT(0, 0x1A23);
    }
    return nBase + nOffset;
}

// 0x0043F1D0
int __stdcall sub_0043F1D0_OnClassButton0(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[0], 1);
    if (gnSelectModeA_0070CD62 != 9 && gnSelectModeA_0070CD62 != 0)
    {
        gnColor_0077AD74 = 0x3E8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(0, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F230
int __stdcall sub_0043F230_OnClassButton1(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[1], 1);
    if (gnSelectModeA_0070CD62 != 10 && gnSelectModeA_0070CD62 != 1)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(1, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F290
int __stdcall sub_0043F290_OnClassButton2(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[2], 1);
    if (gnSelectModeA_0070CD62 != 11 && gnSelectModeA_0070CD62 != 2)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(2, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F2F0
int __stdcall sub_0043F2F0_OnClassButton3(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[3], 1);
    if (gnSelectModeA_0070CD62 != 12 && gnSelectModeA_0070CD62 != 3)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(3, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F350
int __stdcall sub_0043F350_OnClassButton4(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[4], 1);
    if (gnSelectModeA_0070CD62 != 13 && gnSelectModeA_0070CD62 != 4)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(4, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F3B0
int __stdcall sub_0043F3B0_OnClassButton5(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[5], 1);
    if (gnSelectModeA_0070CD62 != 14 && gnSelectModeA_0070CD62 != 5)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(5, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F410
int __stdcall sub_0043F410_OnClassButton6(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[6], 1);
    if (gnSelectModeA_0070CD62 != 15 && gnSelectModeA_0070CD62 != 6)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(6, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F470
int __stdcall sub_0043F470_OnClassButton7(D2WinMsgStrc* pMsg)
{
    sub_0043F060_ReleaseClassButtons();
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[7], 1);
    if (gnSelectModeA_0070CD62 != 16 && gnSelectModeA_0070CD62 != 7)
    {
        gnColor_0077AD74 = 0xC8;
        sub_0043F0E0();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)sub_0043F150_GetClassSlot(7, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043F150.inc"
