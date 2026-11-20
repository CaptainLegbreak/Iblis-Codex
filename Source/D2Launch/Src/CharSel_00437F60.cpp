#include "D2Launch.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"

struct SMSGHANDLER_PARAMS;

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_A15_UseText(const Unicode* pText);

void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
void __cdecl sub_00439CC0_CreateControls(); // 0x00439CC0
extern int gdwGlobal_00779DC4; // 0x00779DC4
extern int gnTopRow_00779DC8; // 0x00779DC8
char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50
void __cdecl sub_0043A270_UpdateStatus(); // 0x0043A270
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern unsigned long gdwStartTick_00779DB4; // 0x00779DB4

// 0x00437F60
static __declspec(noinline) Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

// 0x00438030
static __declspec(noinline) int sub_00438030_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

// 0x004380B0
static __declspec(noinline) unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

void __fastcall sub_A15_Emit_00437F60(const unsigned char* pClass)
{
    Unicode wszText[0x40];
    sub_00437F60_GetClassName(wszText, *pClass);
    sub_A15_UseText(wszText);
}

int __fastcall sub_A15_Emit_00438030(const unsigned char* pClass)
{
    return sub_00438030_IsNotListedCode(*pClass);
}

unsigned int __fastcall sub_A15_Emit_004380B0(const unsigned int* pExpire)
{
    return sub_004380B0_GetDaysLeft(*pExpire);
}

int gnLastValue_00779DCC; // 0x00779DCC

// 0x00439BE0
int __stdcall sub_00439BE0_CreateExpansionControls(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0042F3F0_DestroyControls();
        D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDA);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0xDB);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
        D2WinControlStrc* pControl3 = sub_0042F3A0_CreateFromTemplate(0xDC);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
        pControl = sub_0042F3A0_CreateFromTemplate(0xDD);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CE), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CF), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58D0), 0, 0, 0);
    }
    return 1;
}

// 0x00439CA0
int __stdcall sub_00439CA0_DestroyIfExpansion(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00408F20_HasExpansionMpq())
        sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00439D40
int __stdcall sub_00439D40_DestroyControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00439D50
int __stdcall sub_00439D50_CreateControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439CC0_CreateControls();
    return 1;
}

// 0x00439D60
int __stdcall sub_00439D60_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 > 0)
        gnTopRow_00779DC8 -= 1;
    if (gnSelected_0070CC00 > 0)
        gnSelected_0070CC00 -= 1;
    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
}

// 0x00439DA0
int __stdcall sub_00439DA0_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 + gnVisibleRows_0070CC0C < gdwGlobal_00779DC4)
    {
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
            gnSelected_0070CC00 += 1;
        gnTopRow_00779DC8 += 1;
        sub_00438560_Refresh();
        sub_00439210_Redraw();
    }
    return 1;
}

// 0x00439DF0
int __stdcall sub_00439DF0_OnScroll(SMSGHANDLER_PARAMS* pMsg)
{
    const int nValue = sub_004FC620_GetValue(gpControl_00779C84);
    if (gnLastValue_00779DCC == nValue)
        return 0;
    gnTopRow_00779DC8 += 2 * (nValue - gnLastValue_00779DCC);
    if (gnTopRow_00779DC8 < 0)
        gnTopRow_00779DC8 = 0;
    if (gnTopRow_00779DC8 >= gdwGlobal_00779DC4)
        gnTopRow_00779DC8 = gdwGlobal_00779DC4 - 1;
    gnLastValue_00779DCC = nValue;
    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
}

int gbFlag_00779C6C; // 0x00779C6C

int gnState_00779DAC; // 0x00779DAC

char* gpszName_00779DB0; // 0x00779DB0

static __declspec(noinline) void sub_00437CB0_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
next:
    if (i >= sub_00430B40())
        return;
    char* szSlot = sub_00430B50_GetSlotName(i);
    if (!szSlot)
        return;
    if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        D2Win_10188(gpNameControl_007799E8, i, 1);
    ++i;
    goto next;
}

// 0x0043A1F0
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

// 0x0043AC00
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
