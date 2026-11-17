struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2CellFileStrc;
struct D2MenuItemStrc;
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

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __cdecl sub_00514CC0();                                                                                 // 0x00514CC0
int __cdecl sub_00514CF0();                                                                                 // 0x00514CF0
int __cdecl sub_00514D20();                                                                                 // 0x00514D20
int __cdecl sub_00514D50();                                                                                 // 0x00514D50
int __fastcall sub_00514CD0_SetMasterVolume(int nValue);                                                    // 0x00514CD0
int __fastcall sub_00514D00_SetMusicVolume(int nValue);                                                     // 0x00514D00
int __fastcall sub_00514D30_SetPositionalBias(int nValue);                                                  // 0x00514D30
int __fastcall sub_00514D60_SetNpcSpeech(int nValue);                                                       // 0x00514D60
int __cdecl sub_004DF880();                                                                                 // 0x004DF880
int __cdecl sub_004DF980_IsSoundMode1Or2();                                                                 // 0x004DF980
int __cdecl sub_004DF9B0_IsSoundMode2();                                                                    // 0x004DF9B0
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue);                                                 // 0x004E0690
void __fastcall sub_0049D570_SetTextDisplayBeta(int nValue);                                                // 0x0049D570
void __stdcall D2GFX_SetLowQuality(int bLowQuality);                                                        // 0x004F5220
void __fastcall sub_004CCF20_SetLightFlag(int nValue);                                                      // 0x004CCF20
void __fastcall sub_004776C0(void* pArg);                                                                   // 0x004776C0
int __stdcall D2GFX_GammaCanBeControlled();                                                                 // 0x004F5260
int __fastcall D2GFX_SetOption(int nOption, int nValue);                                                    // 0x004F52B0
int __stdcall D2GFX_SetGamma(int nGamma);                                                                   // 0x004F5230
int __cdecl sub_004F5140();                                                                                 // 0x004F5140

static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nValue - nMin + 1) * (float)(pItem->dwCount - 1) / (float)(nMax - nMin));
}

static unsigned int sub_0047CD00_SliderToValue(D2MenuItemStrc* pItem, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nMax - nMin) / (float)(pItem->dwCount - 1) * (float)pItem->dwMoveCount + (float)nMin);
}

// 0x0047CDA0
void __fastcall sub_0047CDA0_MasterVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514CD0_SetMasterVolume(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CDC0
void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CC0(), 0, 100);
}

// 0x0047CDF0
void __fastcall sub_0047CDF0_MusicVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D00_SetMusicVolume(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE10
void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CF0(), 0, 100);
}

// 0x0047CE50
void __fastcall sub_0047CE50_SoundModeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CE70
void __fastcall sub_0047CE70_PositionalBiasSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D30_SetPositionalBias(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE90
void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514D20(), 0, 100);
}

// 0x0047CED0
void __fastcall sub_0047CED0_SoundMode2Option(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF9B0_IsSoundMode2();
}

// 0x0047CEF0
void __fastcall sub_0047CEF0_NpcSpeechSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D60_SetNpcSpeech(pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        sub_004E0690_SetSoundTableFlag(1);
        sub_0049D570_SetTextDisplayBeta(0);
        break;
    case 1:
        sub_004E0690_SetSoundTableFlag(0);
        sub_0049D570_SetTextDisplayBeta(1);
        break;
    case 2:
        sub_004E0690_SetSoundTableFlag(1);
        sub_0049D570_SetTextDisplayBeta(1);
        break;
    }
}

// 0x0047CF50
void __fastcall sub_0047CF50_NpcSpeechOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_00514D50();
    if (sub_004DF880())
    {
        sub_0047CEF0_NpcSpeechSelect(pItem, (SMSGHANDLER_PARAMS*)nArg);
    }
}

// 0x0047CF80
void __fastcall sub_0047CF80_LightQualitySelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Light Quality", 0, pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        sub_004CCF20_SetLightFlag(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetLightFlag(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetLightFlag(1);
        break;
    }
}

// 0x0047CFE0
void __fastcall sub_0047CFE0_LightQualityOption(D2MenuItemStrc* pItem, int nArg)
{
    SRegLoadValue("Diablo II", "Light Quality", 0, (unsigned long*)&pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        sub_004CCF20_SetLightFlag(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetLightFlag(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetLightFlag(1);
        break;
    }
}

void __fastcall sub_0047D200_GammaSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nGamma = sub_0047CD00_SliderToValue(pItem, 0x37, 0xFF);
    SRegSaveValue("Diablo II", "Gamma", 0, nGamma);
    sub_004776C0((void*)nGamma);
}

void __fastcall sub_0047D230_GammaOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nGamma = 0x9B;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nGamma, 0x37, 0xFF);
    if (D2GFX_GammaCanBeControlled())
    {
        sub_0047D200_GammaSelect(pItem, 0);
    }
}

void __fastcall sub_0047D2B0_ContrastSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Contrast", 0, sub_0047CD00_SliderToValue(pItem, 0, 100));
    D2GFX_SetOption(0x0B, pItem->dwMoveCount);
    D2GFX_SetGamma(0);
}

void __fastcall sub_0047D2F0_ContrastOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nContrast = (sub_004F5140() != 4) ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nContrast, 0, 100);
    sub_0047D2B0_ContrastSelect(pItem, 0);
}
