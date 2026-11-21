#include "D2ClientMenus.h"
struct D2HotkeyCommandStrc
{
    void (__cdecl* pfnCommand)();
    int unk0x04;
    int nModeFlag;
};

#define NUM_HOTKEYS 114
#define HOTKEY_COMMAND_LIMIT 0x38
#define KEY_WHEEL_UP 0x103
#define KEY_WHEEL_DOWN 0x104

extern D2HotkeyCommandStrc gtHotkeyCommands_00712698[];                                                     // 0x00712698
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
int __fastcall sub_00469AE0_IsValidKey(unsigned short nKey);                                                // 0x00469AE0

// 0x00469420
static int sub_00469420_CheckWheelKey(int nId, unsigned short nKey, unsigned short* pKey)
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
    if (sub_00469AE0_IsValidKey(nKey))
    {
        if (!sub_00469420_CheckWheelKey(nId, nKey, pKey))
        {
            return 0;
        }
        if (nKey != 0x2C || !gtHotkeyCommands_00712698[nId].pfnCommand)
        {
            goto update;
        }
    }
    if (pKey)
    {
        *pKey = 0xF8B;
    }
    return 0;

update:
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
