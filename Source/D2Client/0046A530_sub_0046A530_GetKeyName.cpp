struct Unicode
{
    unsigned short wChar;
};

#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};
#pragma pack(pop)

enum
{
    NUM_HOTKEYS = 114,
};

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0

static __forceinline unsigned short FindHotkeyKey_Inline(int nId, int nMode)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }
    return 0xFFFF;
}

// 0x0046A530
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB)
{
    switch (FindHotkeyKey_Inline(nA, nB))
    {
    case 0x100:
        return D2LANG_GetStringFromTblIndex(0xF15);
    case 0x101:
        return D2LANG_GetStringFromTblIndex(0xF16);
    case 0x102:
        return D2LANG_GetStringFromTblIndex(0xF17);
    case 0x103:
        return D2LANG_GetStringFromTblIndex(0xF18);
    case 0x104:
        return D2LANG_GetStringFromTblIndex(0xF19);
    case 0x11:
        return D2LANG_GetStringFromTblIndex(0xF30);
    case 0x21:
        return D2LANG_GetStringFromTblIndex(0xF34);
    case 0x22:
        return D2LANG_GetStringFromTblIndex(0xF35);
    case 0x1B:
        return D2LANG_GetStringFromTblIndex(0xF1E);
    case 0x90:
        return D2LANG_GetStringFromTblIndex(0xF2B);
    case 0x8:
        return D2LANG_GetStringFromTblIndex(0xF2C);
    case 0x10:
        return D2LANG_GetStringFromTblIndex(0xF2F);
    case 0x60:
        return D2LANG_GetStringFromTblIndex(0xF3B);
    case 0x61:
        return D2LANG_GetStringFromTblIndex(0xF3C);
    case 0x62:
        return D2LANG_GetStringFromTblIndex(0xF3D);
    case 0x63:
        return D2LANG_GetStringFromTblIndex(0xF3E);
    case 0x64:
        return D2LANG_GetStringFromTblIndex(0xF3F);
    case 0x65:
        return D2LANG_GetStringFromTblIndex(0xF40);
    case 0x66:
        return D2LANG_GetStringFromTblIndex(0xF41);
    case 0x67:
        return D2LANG_GetStringFromTblIndex(0xF42);
    case 0x68:
        return D2LANG_GetStringFromTblIndex(0xF43);
    case 0x69:
        return D2LANG_GetStringFromTblIndex(0xF44);
    case 0x6A:
        return D2LANG_GetStringFromTblIndex(0xF45);
    case 0x6B:
        return D2LANG_GetStringFromTblIndex(0xF46);
    case 0x6C:
        return D2LANG_GetStringFromTblIndex(0xF48);
    case 0x6D:
        return D2LANG_GetStringFromTblIndex(0xF47);
    case 0x6F:
        return D2LANG_GetStringFromTblIndex(0xF49);
    case 0x91:
        return D2LANG_GetStringFromTblIndex(0xF4A);
    case 0x2C:
        return D2LANG_GetStringFromTblIndex(0xF37);
    case 0x2D:
        return D2LANG_GetStringFromTblIndex(0xF38);
    case 0x2E:
        return D2LANG_GetStringFromTblIndex(0xF39);
    }
    return sub_00469DE0_GetKeyText(nA, nB);
}
