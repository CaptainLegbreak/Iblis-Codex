struct D2CellFileStrc;
struct D2MenuItemStrc;
struct SMSGHANDLER_PARAMS;
typedef int(__fastcall* MENUENABLED)();
typedef void(__fastcall* MENUSELECT)(D2MenuItemStrc*, SMSGHANDLER_PARAMS*);
typedef void(__fastcall* MENUOPTION)(D2MenuItemStrc*, int);
typedef void(__fastcall* MENUUPDATE)(D2MenuItemStrc*, int);

struct D2MenuItemStrc
{
    unsigned int dwType;
    int bExpansion;
    int nHeight;
    char szImage[260];
    MENUENABLED pfEnabled;
    MENUSELECT pfSelect;
    MENUOPTION pfOption;
    MENUUPDATE pfUpdate;
    unsigned int dwCount;
    unsigned int dwMoveCount;
    unsigned int dwSliderType;
    char szChoices[4][260];
    D2CellFileStrc* pImage;
    D2CellFileStrc* pChoices[4];
};

int __cdecl sub_00514CC0();                                                                                 // 0x00514CC0
int __cdecl sub_00514CF0();                                                                                 // 0x00514CF0
int __cdecl sub_00514D20();                                                                                 // 0x00514D20

static __declspec(noinline) unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax);

// 0x0047CC90
static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    float fSteps = (float)(pItem->dwCount - 1);
    return (unsigned int)(fSteps * (float)(nValue - nMin + 1) / (float)(nMax - nMin));
}

void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CC0(), 0, 100);
}

void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CF0(), 0, 100);
}

void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514D20(), 0, 100);
}

void __fastcall Caller_GammaSlider(D2MenuItemStrc* pItem, int nGamma)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nGamma, 0x37, 0xFF);
}
