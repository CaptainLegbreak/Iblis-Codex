#include "D2Client.h"

#define NUM_HOTKEYS 114
#define NUM_HOTKEY_COMMANDS 0x39
#define KEY_WHEEL_UP 0x103
#define KEY_WHEEL_DOWN 0x104
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2HotkeyCommandStrc;
struct D2HotkeyStrc;
struct D2MsgHandlerEntryStrc;

typedef int (__stdcall* FARPROC)();

typedef void (__cdecl* HOTKEYCOMMANDFN)();

struct D2HotkeyCommandStrc
{
    HOTKEYCOMMANDFN pfnCommand;
    HOTKEYCOMMANDFN pfnUnk0x04;
    int nModeFlag;
};

#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};

#pragma pack(pop)
typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" int __cdecl isalpha(int c); // 0x00686DA5
int __cdecl sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
void __cdecl sub_0046AAE0(); // 0x0046AAE0
extern D2HotkeyCommandStrc gtHotkeyCommands_00712698[]; // 0x00712698
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7404; // 0x007A7404
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7408; // 0x007A7408
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B10; // 0x007A6B10
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A740C; // 0x007A740C
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7414; // 0x007A7414
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B14; // 0x007A6B14
extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7410; // 0x007A7410
extern D2MsgHandlerEntryStrc gtHotkeyHandlers_00712944[4]; // 0x00712944
extern D2MsgHandlerEntryStrc gtHotkeyHandlers_00712974[2]; // 0x00712974
void __cdecl sub_00469780_SaveKeyConfig(); // 0x00469780
void __cdecl sub_004694A0_BindMouseHotkeys(); // 0x004694A0

HOTKEYCOMMANDFN gpfnBoundCommand_007A6F8C; // 0x007A6F8C

int gnGlobal_007A7418; // 0x007A7418

int gnGlobal_007A7424; // 0x007A7424

int gnGlobal_007A7428; // 0x007A7428

// 0x00469370
void __cdecl sub_00469370_CallBoundCommand()
{
    if (gpfnBoundCommand_007A6F8C)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnBoundCommand_007A6F8C), 0x375);
        gpfnBoundCommand_007A6F8C();
    }
}

static __forceinline int HOTKEY_CheckWheelKey(int nCommand, int nKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gtHotkeyCommands_00712698[nCommand].pfnUnk0x04)
        {
            return 0;
        }
        break;
    }
    return 1;
}

// 0x004694A0
void __cdecl sub_004694A0_BindMouseHotkeys()
{
    gpfnBoundCommand_007A7404 = 0;
    gpfnBoundCommand_007A7408 = 0;
    gpfnBoundCommand_007A6B10 = 0;
    gpfnBoundCommand_007A740C = 0;
    gpfnBoundCommand_007A7414 = 0;
    gpfnBoundCommand_007A6B14 = 0;
    gpfnBoundCommand_007A7410 = 0;
    gpfnBoundCommand_007A6F8C = 0;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey > 0xDF && gtHotkeys_007A6F90[i].nCommand < NUM_HOTKEY_COMMANDS)
        {
            switch (gtHotkeys_007A6F90[i].nKey)
            {
            case 0x100:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A6B10 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A740C = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x101:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7414 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A6B14 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x102:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7410 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A6F8C = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_UP:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7404 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_DOWN:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7408 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            }
        }
    }
}

// 0x00469AE0
int __fastcall sub_00469AE0_IsValidKey(unsigned short nKey)
{
    switch (nKey)
    {
    case 0x08: case 0x09: case 0x0C: case 0x0D: case 0x10: case 0x11:
    case 0x12: case 0x13: case 0x14: case 0x20: case 0x21: case 0x22:
    case 0x23: case 0x24: case 0x2A: case 0x2C: case 0x2D: case 0x2E:
    case 0x2F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: case 0x70:
    case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76:
    case 0x77: case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C:
    case 0x7D: case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82:
    case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x91:
    case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
    case 0xC0: case 0xDB: case 0xDC: case 0xDD: case 0xDE: case 0x100:
    case 0x101: case 0x102: case 0x103: case 0x104:
        return 1;
    case 0x01: case 0x02: case 0x03: case 0x04: case 0x15: case 0x17:
    case 0x18: case 0x19: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29:
    case 0x2B: case 0x5B: case 0x5C: case 0x5D: case 0x90:
        return 0;
    }
    if (isalpha(nKey) || isdigit(nKey))
    {
        return 1;
    }
    return 0;
}

// 0x0046AA20
void __fastcall sub_0046AA20_SetHotkeyHandlers(int bEnable, int bFlag)
{
    gnGlobal_007A7418 = bEnable;
    if (bEnable)
    {
        if (gnGlobal_007A7428 == 0)
        {
            gnGlobal_007A7428 = 1;
            if (bFlag && gnGlobal_007A7424 != 0)
            {
                sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712974, 2);
                gnGlobal_007A7424 = 0;
            }
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
        }
    }
    else
    {
        if (gnGlobal_007A7428 == 1)
        {
            gnGlobal_007A7428 = 0;
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
            if (bFlag && gnGlobal_007A7424 == 0)
            {
                sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712974, 2);
                gnGlobal_007A7424 = 1;
            }
        }
    }
}

// 0x0046AC70
void __cdecl sub_0046AC70_EnableHotkeyHandlers()
{
    sub_0046AAE0();
    gnGlobal_007A7418 = 1;
    if (gnGlobal_007A7428 == 0)
    {
        gnGlobal_007A7428 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
    }
}

// 0x0046ACB0
void __cdecl sub_0046ACB0_DisableHotkeyHandlers()
{
    gnGlobal_007A7418 = 0;
    if (gnGlobal_007A7428 == 1)
    {
        gnGlobal_007A7428 = 0;
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
    }
}

#include "gen/data/Source/D2Client/UI/CmdTbl.inc"

// 0x00469D40
void __cdecl sub_00469D40_SaveAndBindHotkeys()
{
    sub_00469780_SaveKeyConfig();
    sub_004694A0_BindMouseHotkeys();
}
