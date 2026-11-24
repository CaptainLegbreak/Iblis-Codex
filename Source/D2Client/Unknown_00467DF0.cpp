#include "D2Client.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CursorAnimStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT]; // 0x00712010
extern int gdwGlobal_007A6ADC; // 0x007A6ADC
extern int gnCursorAnimFrame; // 0x007A6AE0

extern int gbCursorVisible; // 0x007A6B08
int __cdecl GAME_IsExitPending(); // 0x0044DA30
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey); // 0x004A9E60
void __fastcall sub_004AA030_SelectHotkey(int nSlot); // 0x004AA030
void __cdecl PANEL_BeltHotkeyFirst(); // 0x00498C50
void __cdecl PANEL_BeltHotkeySecond(); // 0x00498C90
void __cdecl PANEL_BeltHotkeyThird(); // 0x00498CD0
void __cdecl PANEL_BeltHotkeyFourth(); // 0x00498D10
extern int gpCursorItem; // 0x007A6ABC
extern int gdwGlobal_007A6AF0; // 0x007A6AF0

// 0x00467DF0
static inline int sub_00467DF0_GetCursorAnimField00(int nIndex)
{
// build: symbol ?gnCursorAnimCount@* 0x007120D4
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x85);
    return gaCursorAnim[nIndex].bAnimated;
}

int __stdcall sub_M121_Emit_00467DF0(int nIndex) { return sub_00467DF0_GetCursorAnimField00(nIndex); }

// 0x00467EE0
static inline void sub_00467EE0_SetCursorAnim(int nIndex)
{
    gdwGlobal_007A6ADC = nIndex;
    gnCursorAnimFrame = 0;
}

void __stdcall sub_M121_Emit_00467EE0(int nIndex) { sub_00467EE0_SetCursorAnim(nIndex); }

// 0x00467EF0
void __stdcall sub_00467EF0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        gbCursorVisible = 0;
        sub_004F59F0(0);
    }
    else
    {
        gbCursorVisible = 0;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x00468000
void __fastcall sub_00468000_SetGlobal7A6B08(int nValue)
{
    gbCursorVisible = nValue;
}

// 0x00468010
void __fastcall sub_00468010_SetState(int nValue, int nArg)
{
    gpCursorItem = nValue;
    gdwGlobal_007A6ADC = 6;
    gdwGlobal_007A6AE0 = nArg;
    gdwGlobal_007A6AF0 = 6;
}

// 0x00468B20
static inline void sub_00468B20_HandleHotkey(int nHotkey)
{
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    if (nHotkey > 8 && !GAME_IsExpansion())
        return;
    D2_ASSERT(nHotkey >= 0 || nHotkey <= 15, 0xFC);
    if (GAME_GetUIVarState(3))
        sub_004A9E60_AssignHotkey(nHotkey);
    else
        sub_004AA030_SelectHotkey(nHotkey);
}

void __fastcall sub_M115_Emit_00468B20(int nHotkey)
{
    sub_00468B20_HandleHotkey(nHotkey);
}

// 0x00468F40
void __cdecl sub_00468F40_BeltHotkey0()
{
    PANEL_BeltHotkeyFirst();
}

// 0x00468F50
void __cdecl sub_00468F50_BeltHotkey1()
{
    PANEL_BeltHotkeySecond();
}

// 0x00468F60
void __cdecl sub_00468F60_BeltHotkey2()
{
    PANEL_BeltHotkeyThird();
}

// 0x00468F70
void __cdecl sub_00468F70_BeltHotkey3()
{
    PANEL_BeltHotkeyFourth();
}

int gpCursorItem; // 0x007A6ABC

int gdwGlobal_007A6ADC; // 0x007A6ADC

// 0x00468040
void __fastcall sub_00468040(int nArg, int nArg2)
{
    gpCursorItem = 0;
    gdwGlobal_007A6ADC = 6;
    gdwGlobal_007A6AE0 = nArg;
    gdwGlobal_007A6AF0 = nArg2 ? 8 : 7;
}

int gdwGlobal_007A6AF0; // 0x007A6AF0

// 0x00468070
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem)
{
    gpCursorItem = (int)pItem;
    gdwGlobal_007A6ADC = 5;
    if (!pItem)
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
    }
    else
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
        gdwGlobal_007A6AF0 = 4;
    }
}
