struct Unicode
{
    unsigned short wChar;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x2];
    unsigned char nFlags[8];
    char unk0x00C[0x188];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

int gnHotkeySkill_007C06C8[16];                                                                             // 0x007C06C8
int gnHotkeyOwner_007C0768[16];                                                                             // 0x007C0768
int gbHotkeyLeft_007C07B8[16];                                                                              // 0x007C07B8

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);
extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall sub_004A8DF0_DrawKeyLabel(int nKeyId, int nX, int nY, int nColor);                          // 0x004A8DF0

// 0x004A9260
static __declspec(noinline) void __stdcall sub_004A9260_DrawSkillCharges(int nCharges, int nX, int nY)
{
    Unicode wszText[16] = {};
    char szText[16];
    if (nCharges > 0)
    {
        sub_00526320_ToUnicode(wszText, _itoa(nCharges, szText, 10), 16);
        int nLength = sub_00526800((const unsigned short*)wszText);
        while (sub_00501820(wszText) > 40)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        sub_00501820(wszText);
        sub_00502320(wszText, nX + 4, nY - 1, 3, 0);
    }
}

#define SPELLSEL_HOTKEY_LABEL(i, key, flag) \
    if (gnHotkeySkill_007C06C8[i] == pSkillsTxt->nSkillId && gnHotkeyOwner_007C0768[i] == nOwner \
        && gnHotkeySkill_007C06C8[i] != -1 && gbHotkeyLeft_007C07B8[i] == flag) \
    { \
        sub_004A8DF0_DrawKeyLabel(key, nX + 0x22, nY - 0x23, 4); \
    }

// 0x004A8ED0
static __declspec(noinline) void __stdcall sub_004A8ED0_DrawSkillHotkeyLabels(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 1)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 1)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 1)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 1)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 1)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 1)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 1)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 1)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 1)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 1)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 1)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 1)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 1)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 1)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 1)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 1)
}

// 0x004A9300
static __declspec(noinline) void __stdcall sub_004A9300_DrawHotkeyLabelsB(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 0)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 0)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 0)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 0)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 0)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 0)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 0)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 0)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 0)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 0)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 0)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 0)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 0)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 0)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 0)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 0)
}

void __fastcall sub_M292_Emit_SpellselStatics(const D2SkillsTxt* pSkillsTxt, int nOwner, int nCharges, int nX, int nY, int bLeft)
{
    if (bLeft)
    {
        sub_004A8ED0_DrawSkillHotkeyLabels(pSkillsTxt, nOwner, nX, nY);
    }
    else
    {
        sub_004A9300_DrawHotkeyLabelsB(pSkillsTxt, nOwner, nX, nY);
    }

    sub_004A9260_DrawSkillCharges(nCharges, nX, nY);
}
