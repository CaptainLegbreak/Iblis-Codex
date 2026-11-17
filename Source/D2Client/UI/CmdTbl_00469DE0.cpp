struct Unicode;
struct D2HotkeyStrc;

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


const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
extern Unicode gwszKeyText_007A741C[4]; // 0x007A741C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2); // 0x00469DE0

static __forceinline unsigned short sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469DE0
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nA, int nB)
{
    const unsigned short nKey = sub_00469AA0(nA, nB);
    if (nKey == 0xFFFF)
    {
        return D2LANG_GetStringFromTblIndex(0xEB2);
    }

    if (nKey > 0xDF)
    {
        switch (nKey)
        {
        case 0x103:
            return D2LANG_GetStringFromTblIndex(0xEB9);

        case 0x104:
            return D2LANG_GetStringFromTblIndex(0xEBA);

        case 0x100:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x101:
            return D2LANG_GetStringFromTblIndex(0xEB7);

        case 0x102:
            return D2LANG_GetStringFromTblIndex(0xEB8);
        }
    }
    else
    {
        switch (nKey)
        {
        case 0x1:
            return D2LANG_GetStringFromTblIndex(0xEB3);

        case 0x2:
            return D2LANG_GetStringFromTblIndex(0xEB4);

        case 0x3:
            return D2LANG_GetStringFromTblIndex(0xEB5);

        case 0x4:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x15:
            return D2LANG_GetStringFromTblIndex(0xEBB);

        case 0x17:
            return D2LANG_GetStringFromTblIndex(0xEBC);

        case 0x18:
            return D2LANG_GetStringFromTblIndex(0xEBD);

        case 0x19:
            return D2LANG_GetStringFromTblIndex(0xEBE);

        case 0x1B:
            return D2LANG_GetStringFromTblIndex(0xEBF);

        case 0x1C:
            return D2LANG_GetStringFromTblIndex(0xEC0);

        case 0x1D:
            return D2LANG_GetStringFromTblIndex(0xEC1);

        case 0x1E:
            return D2LANG_GetStringFromTblIndex(0xEC2);

        case 0x1F:
            return D2LANG_GetStringFromTblIndex(0xEC3);

        case 0x25:
            return D2LANG_GetStringFromTblIndex(0xEC4);

        case 0x26:
            return D2LANG_GetStringFromTblIndex(0xEC5);

        case 0x27:
            return D2LANG_GetStringFromTblIndex(0xEC6);

        case 0x28:
            return D2LANG_GetStringFromTblIndex(0xEC7);

        case 0x29:
            return D2LANG_GetStringFromTblIndex(0xEC8);

        case 0x2B:
            return D2LANG_GetStringFromTblIndex(0xEC9);

        case 0x5B:
            return D2LANG_GetStringFromTblIndex(0xECA);

        case 0x5C:
            return D2LANG_GetStringFromTblIndex(0xECB);

        case 0x5D:
            return D2LANG_GetStringFromTblIndex(0xECC);

        case 0x90:
            return D2LANG_GetStringFromTblIndex(0xECD);

        case 0x8:
            return D2LANG_GetStringFromTblIndex(0xECE);

        case 0x9:
            return D2LANG_GetStringFromTblIndex(0xECF);

        case 0xC:
            return D2LANG_GetStringFromTblIndex(0xED0);

        case 0xD:
            return D2LANG_GetStringFromTblIndex(0xED1);

        case 0x10:
            return D2LANG_GetStringFromTblIndex(0xED2);

        case 0x11:
            return D2LANG_GetStringFromTblIndex(0xED3);

        case 0x12:
            return D2LANG_GetStringFromTblIndex(0xED4);

        case 0x13:
            return D2LANG_GetStringFromTblIndex(0xED5);

        case 0x14:
            return D2LANG_GetStringFromTblIndex(0xED6);

        case 0x20:
            return D2LANG_GetStringFromTblIndex(0xED7);

        case 0x21:
            return D2LANG_GetStringFromTblIndex(0xED8);

        case 0x22:
            return D2LANG_GetStringFromTblIndex(0xED9);

        case 0x23:
            return D2LANG_GetStringFromTblIndex(0xEDA);

        case 0x24:
            return D2LANG_GetStringFromTblIndex(0xEDB);

        case 0x2A:
            return D2LANG_GetStringFromTblIndex(0xEDC);

        case 0x2C:
            return D2LANG_GetStringFromTblIndex(0xEDD);

        case 0x2D:
            return D2LANG_GetStringFromTblIndex(0xEDE);

        case 0x2E:
            return D2LANG_GetStringFromTblIndex(0xEDF);

        case 0x2F:
            return D2LANG_GetStringFromTblIndex(0xEE0);

        case 0x60:
            return D2LANG_GetStringFromTblIndex(0xEE1);

        case 0x61:
            return D2LANG_GetStringFromTblIndex(0xEE2);

        case 0x62:
            return D2LANG_GetStringFromTblIndex(0xEE3);

        case 0x63:
            return D2LANG_GetStringFromTblIndex(0xEE4);

        case 0x64:
            return D2LANG_GetStringFromTblIndex(0xEE5);

        case 0x65:
            return D2LANG_GetStringFromTblIndex(0xEE6);

        case 0x66:
            return D2LANG_GetStringFromTblIndex(0xEE7);

        case 0x67:
            return D2LANG_GetStringFromTblIndex(0xEE8);

        case 0x68:
            return D2LANG_GetStringFromTblIndex(0xEE9);

        case 0x69:
            return D2LANG_GetStringFromTblIndex(0xEEA);

        case 0x6A:
            return D2LANG_GetStringFromTblIndex(0xEEB);

        case 0x6B:
            return D2LANG_GetStringFromTblIndex(0xEEC);

        case 0x6C:
            return D2LANG_GetStringFromTblIndex(0xEED);

        case 0x6D:
            return D2LANG_GetStringFromTblIndex(0xEEE);

        case 0x6E:
            return D2LANG_GetStringFromTblIndex(0xEEF);

        case 0x6F:
            return D2LANG_GetStringFromTblIndex(0xEF0);

        case 0x70:
            return D2LANG_GetStringFromTblIndex(0xEF1);

        case 0x71:
            return D2LANG_GetStringFromTblIndex(0xEF2);

        case 0x72:
            return D2LANG_GetStringFromTblIndex(0xEF3);

        case 0x73:
            return D2LANG_GetStringFromTblIndex(0xEF4);

        case 0x74:
            return D2LANG_GetStringFromTblIndex(0xEF5);

        case 0x75:
            return D2LANG_GetStringFromTblIndex(0xEF6);

        case 0x76:
            return D2LANG_GetStringFromTblIndex(0xEF7);

        case 0x77:
            return D2LANG_GetStringFromTblIndex(0xEF8);

        case 0x78:
            return D2LANG_GetStringFromTblIndex(0xEF9);

        case 0x79:
            return D2LANG_GetStringFromTblIndex(0xEFA);

        case 0x7A:
            return D2LANG_GetStringFromTblIndex(0xEFB);

        case 0x7B:
            return D2LANG_GetStringFromTblIndex(0xEFC);

        case 0x7C:
            return D2LANG_GetStringFromTblIndex(0xEFD);

        case 0x7D:
            return D2LANG_GetStringFromTblIndex(0xEFE);

        case 0x7E:
            return D2LANG_GetStringFromTblIndex(0xEFF);

        case 0x7F:
            return D2LANG_GetStringFromTblIndex(0xF00);

        case 0x80:
            return D2LANG_GetStringFromTblIndex(0xF01);

        case 0x81:
            return D2LANG_GetStringFromTblIndex(0xF02);

        case 0x82:
            return D2LANG_GetStringFromTblIndex(0xF03);

        case 0x83:
            return D2LANG_GetStringFromTblIndex(0xF04);

        case 0x84:
            return D2LANG_GetStringFromTblIndex(0xF05);

        case 0x85:
            return D2LANG_GetStringFromTblIndex(0xF06);

        case 0x86:
            return D2LANG_GetStringFromTblIndex(0xF07);

        case 0x87:
            return D2LANG_GetStringFromTblIndex(0xF08);

        case 0x91:
            return D2LANG_GetStringFromTblIndex(0xF09);

        case 0xBA:
            return D2LANG_GetStringFromTblIndex(0xF0A);

        case 0xBB:
            return D2LANG_GetStringFromTblIndex(0xF0B);

        case 0xBC:
            return D2LANG_GetStringFromTblIndex(0xF0C);

        case 0xBD:
            return D2LANG_GetStringFromTblIndex(0xF0D);

        case 0xBE:
            return D2LANG_GetStringFromTblIndex(0xF0E);

        case 0xBF:
            return D2LANG_GetStringFromTblIndex(0xF0F);

        case 0xC0:
            return D2LANG_GetStringFromTblIndex(0xF10);

        case 0xDB:
            return D2LANG_GetStringFromTblIndex(0xF11);

        case 0xDC:
            return D2LANG_GetStringFromTblIndex(0xF12);

        case 0xDD:
            return D2LANG_GetStringFromTblIndex(0xF13);

        case 0xDE:
            return D2LANG_GetStringFromTblIndex(0xF14);
        }
    }

    memset(gwszKeyText_007A741C, 0, sizeof(gwszKeyText_007A741C));
    gwszKeyText_007A741C[0].wChar = (unsigned char)nKey;
    return gwszKeyText_007A741C;
}

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
