#include "D2Client.h"
#include "D2ClientMenus.h"

#define NUM_HOTKEYS 114
#define HOTKEY_COMMAND_LIMIT 0x38
#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); } } while (0)

struct D2HotkeyCommandStrc;
struct D2HotkeyStrc;
struct D2KeyBindingStrc;
struct D2HotkeyActionStrc;

struct D2HotkeyCommandStrc
{
    void (__cdecl* pfnCommand)();
    int unk0x04;
    int nModeFlag;
};

#pragma pack(push, 2)

#pragma pack(pop)

extern D2HotkeyCommandStrc gtHotkeyCommands_00712698[]; // 0x00712698
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
int __fastcall sub_00469AE0_IsValidKey(unsigned short nKey); // 0x00469AE0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837

typedef void (__cdecl* D2HotkeyCallback)();

#pragma pack(push, 1)
struct D2KeyBindingStrc { int nAction; unsigned short nKey; char unk_06[4]; };

#pragma pack(pop)
struct D2HotkeyActionStrc { D2HotkeyCallback pfnCallback; int bAllowed; int f_8; };

struct SMSGHANDLER_PARAMS
{
    char unk_00[8];
    int nKey;
    char unk_0C[0xC];
    int bHandled;
    int nResult;
};

extern D2HotkeyActionStrc gaActions_0071269C[]; // 0x0071269C
extern int gnMode_007A7418; // 0x007A7418
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2HotkeyCallback);
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

static __declspec(noinline) int sub_00469420_CheckWheelKey(int nId, unsigned short nKey, unsigned short* pKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gtHotkeyCommands_00712698[nId].unk0x04)
        {
            if (pKey)
            {
                *pKey = 0xF8A;
            }
            return 0;
        }
        break;
    }
    return 1;
}

// 0x00469C20
int __fastcall sub_00469C20_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey)
{
    const unsigned short nKey = (unsigned short)nCommand;
    if (pKey)
    {
        *pKey = 0;
    }
    if (nId > HOTKEY_COMMAND_LIMIT || nId == HOTKEY_COMMAND_LIMIT)
    {
        return 0;
    }

    int bError = 1;
    if (sub_00469AE0_IsValidKey(nKey))
    {
        if (!sub_00469420_CheckWheelKey(nId, nKey, pKey))
        {
            return 0;
        }
        bError = nKey == 0x2C && gtHotkeyCommands_00712698[nId].pfnCommand;
    }
    if (bError)
    {
        if (pKey)
        {
            *pKey = 0xF8B;
        }
        return 0;
    }

    int nFree = NUM_HOTKEYS;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey == nKey)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
            nFree = i;
            break;
        }
    }
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            gtHotkeys_007A6F90[i].nKey = nKey;
            return 1;
        }
    }
    if (nFree != NUM_HOTKEYS)
    {
        gtHotkeys_007A6F90[nFree].nKey = nKey;
    }
    return 0;
}

D2KeyBindingStrc gaBindings_007A6F90[114]; // 0x007A6F90

// 0x0046A940
void __stdcall sub_0046A940_DispatchHotkey(SMSGHANDLER_PARAMS* pMsg)
{
    int nKey = pMsg->nKey;
    for (int i = 0; i < 114; ++i)
    {
        if (gaBindings_007A6F90[i].nKey != nKey)
            continue;
        int nAction = gaBindings_007A6F90[i].nAction;
        if (nAction != 0xFFFF && nAction < 0x39 && nAction <= 0xDF && gaActions_0071269C[nAction].pfnCallback)
        {
            if (gnMode_007A7418 == 2 && !gaActions_0071269C[gaBindings_007A6F90[i].nAction].bAllowed)
                return;
            D2_ASSERT(!IsBadCodePtr(gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback), 0x81C);
            gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback();
            pMsg->bHandled = 1;
            pMsg->nResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

#include "gen/data/Source/D2Client/UI/CmdTbl_00469C20.inc"
