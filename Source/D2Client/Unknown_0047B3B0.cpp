#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CellFileStrc;
struct D2MenuItemStrc;
struct Unicode;
struct D2OptionEntryStrc;
struct D2OptionHeaderStrc;
struct D2EscMenuUIStateStrc;
extern "C" unsigned int __cdecl strlen(const char* szString);
extern const char gszM134CmdA[];
extern const char gszM134CmdB[];
void __stdcall sub_M134_Use(const char* szText);

struct Unicode
{
    unsigned short wChar;
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern int gnGlobal_0071146C; // 0x0071146C
extern Unicode gwChatText_007BB5F8[32]; // 0x007BB5F8
extern Unicode gwChatText_007BC850[32]; // 0x007BC850
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern Unicode gawszChatHistory_007BB840[8][257]; // 0x007BB840
extern Unicode gwszChatLine_007BB638[]; // 0x007BB638
extern unsigned short gwChatHistoryCount_007BB5E4; // 0x007BB5E4
extern int gnChatCaret_007BB5E8; // 0x007BB5E8

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    union
    {
        struct
        {
            unsigned int lParam;
        };
        struct
        {
            unsigned short nXPos;
            unsigned short nYPos;
        };
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

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

extern "C" const char szLightQuality_006D73A8[];
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl sub_00514CC0();
int __cdecl sub_00514CF0();
int __cdecl sub_00514D20();
int __cdecl sub_00514D50();
int __fastcall sub_00514CD0_SetMasterVolume(int nValue);
int __fastcall sub_00514D00_SetMusicVolume(int nValue);
int __fastcall sub_00514D30_SetPositionalBias(int nValue);
int __fastcall sub_00514D60_SetNpcSpeech(int nValue);
int __cdecl sub_004DF880();
int __cdecl sub_004DF980_IsSoundMode1Or2();
int __cdecl sub_004DF9B0_IsSoundMode2();
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue);
void __fastcall sub_0049D570_SetTextDisplayBeta(int nValue);
void __stdcall D2GFX_SetLowQuality(int bLowQuality);
void __fastcall sub_004CCF20_SetLightFlag(int nValue);
void __fastcall sub_004776C0(void* pArg);
int __cdecl sub_004F5140();
int __cdecl sub_004DF940(); // 0x004DF940
int __cdecl sub_004DF960(); // 0x004DF960
void __cdecl sub_004E00D0(); // 0x004E00D0
void __cdecl sub_004E0140(); // 0x004E0140

struct D2OptionEntryStrc
{
    int nKind;
    int bExpansionOnly;
    int nY;
    char f_C[0x104];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[4];
    char szValueCels[4][0x104];
    void* pCel;
    void* pValueCels[4];
};

void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows); // 0x004F5200
void __fastcall sub_0044BA20(int nResolution); // 0x0044BA20
void __fastcall sub_0045A720(int nMode); // 0x0045A720
void __fastcall sub_004576F0(int nFade); // 0x004576F0
int __cdecl sub_00457740(); // 0x00457740
int __fastcall sub_00457750_SetValue(int nValue); // 0x00457750
int __cdecl sub_004577B0(); // 0x004577B0
int __cdecl sub_004577E0(); // 0x004577E0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern D2ViewStrc* gpView_007A0640; // 0x007A0640
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220

struct D2OptionHeaderStrc
{
    int nCount;
    int nHeight;
    int nTextOffset;
    int nArrowOffset;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall sub_0044BE80(int bAlwaysRun); // 0x0044BE80
int __cdecl sub_004576C0(); // 0x004576C0
int __cdecl sub_0045A710(); // 0x0045A710
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern "C" const char gszDiablo2_006CC8B8[];
extern "C" const char gszResolution_006CC8AC[];
extern "C" const char gszAutoMapFade_006D66A0[];
extern "C" const char szBlendedShadows_006D73B8[];
extern "C" const char szPerspective_006D73C8[];
extern "C" const char gszAutoMapMode_006D73E8[];

struct D2EscMenuUIStateStrc
{
    int bCheck;
    int bSave;
    int nSaved;
};

int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
extern D2EscMenuUIStateStrc gaEscMenuUIState_00713058[38]; // 0x00713058

typedef unsigned int size_t;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern void* gpCellFile_007BC960; // 0x007BC960
extern int gnGlobal_00711470; // 0x00711470
extern int gdwGlobal_007BC978; // 0x007BC978
void __cdecl sub_K04_EmitUse(int nValue);

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

int __cdecl sub_0044DB30(); // 0x0044DB30
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
void __fastcall sub_004A3FE0(int nMode); // 0x004A3FE0
void __fastcall sub_00456300(int nArg1, int nArg2); // 0x00456300
void __cdecl sub_00453AC0(); // 0x00453AC0
void __fastcall sub_0047E090(int bSaveState, int nMenu); // 0x0047E090
void __cdecl sub_00453AD0(); // 0x00453AD0
void __cdecl sub_00453AE0(); // 0x00453AE0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __cdecl sub_004979E0(); // 0x004979E0
int __cdecl sub_004979F0(); // 0x004979F0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
void __cdecl sub_0044DA40(); // 0x0044DA40
void __cdecl sub_0044DA70(); // 0x0044DA70
extern int gbSlotClicked_007BC97C; // 0x007BC97C
extern int gdwGlobal_007BC970; // 0x007BC970
extern int gdwGlobal_007BC974; // 0x007BC974
extern int gdwGlobal_007BC968; // 0x007BC968
extern int gdwGlobal_007BC96C; // 0x007BC96C
extern int gnSlotX_007BC898[]; // 0x007BC898
extern int gaSlotKind_007BC8D8[]; // 0x007BC8D8
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue); // 0x0044C860
void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200
extern D2OptionHeaderStrc gOptionHeader_00713044; // 0x00713044
extern D2OptionEntryStrc gaOptionEntries_00713220[]; // 0x00713220
extern D2OptionHeaderStrc gOptionHeader_00714210; // 0x00714210
extern D2OptionHeaderStrc gOptionHeader_00714224; // 0x00714224
extern D2OptionEntryStrc gaOptionEntries_00714238[]; // 0x00714238
extern D2OptionEntryStrc gaOptionEntries_00715CC8[]; // 0x00715CC8
extern D2OptionHeaderStrc gOptionHeader_00718748; // 0x00718748
extern D2OptionHeaderStrc gOptionHeader_0071875C; // 0x0071875C
extern D2OptionEntryStrc gaOptionEntries_00718770[]; // 0x00718770
extern D2OptionEntryStrc gaOptionEntries_0071ACA0[]; // 0x0071ACA0
extern D2OptionHeaderStrc gOptionHeader_0071D720; // 0x0071D720
extern D2OptionHeaderStrc gOptionHeader_0071D734; // 0x0071D734
extern D2OptionEntryStrc gaOptionEntries_0071D748[]; // 0x0071D748
extern D2OptionEntryStrc gaOptionEntries_0071F728[]; // 0x0071F728

static __forceinline int sub_0047D500(D2OptionEntryStrc* pEntry);
void __fastcall sub_0047F310_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);

// 0x0047B3B0
static int __stdcall sub_0047B3B0_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

void __fastcall sub_M134_Emit_0047C100(const char* szText)
{
    if (!sub_0047B3B0_CompareCommand(szText, gszM134CmdA))
        return;
    if (!sub_0047B3B0_CompareCommand(szText, gszM134CmdB))
        sub_M134_Use(szText);
}

unsigned long gdwBlinkTick_007BC890; // 0x007BC890

// 0x0047B450
static void sub_0047B450_DrawBlinkingCaret(int nColor, int nY, int nX)
{
    if (gnBlinkOn_00713004 == 1)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xD4C), nX + 0x83, nY, nColor, 0);
    }

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwBlinkTick_007BC890 > gwBlinkDelay_00713000)
    {
        gdwBlinkTick_007BC890 = dwTick;
        if (gnBlinkOn_00713004)
        {
            gwBlinkDelay_00713000 = 100;
            gnBlinkOn_00713004 = 0;
        }
        else
        {
            gwBlinkDelay_00713000 = 500;
            gnBlinkOn_00713004 = 1;
        }
    }
}

void __stdcall sub_0047B4F0_DrawImeText(int nX, int nY)
{
    int nWidth = 0;
    int nTextX = nX;
    int nTextY = nY;
    if (sub_00526800(gwChatText_007BB5F8))
    {
        nWidth = sub_00501820(gwChatText_007BB5F8);
        if (nWidth + nTextX - 0x83 > gnGlobal_0071146C - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        sub_00502320(gwChatText_007BB5F8, nTextX, nTextY, 4, 0);
    }

    const int nWidth2 = sub_00501820(gwChatText_007BC850);
    if (sub_00526800(gwChatText_007BC850))
    {
        if (nWidth2 + nTextX + nWidth - 0x83 > gnGlobal_0071146C - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        sub_00502320(gwChatText_007BC850, nTextX + nWidth, nTextY, 4, 0);
    }

    sub_0047B450_DrawBlinkingCaret(4, nTextY, nWidth2 + nTextX + nWidth - 0x83);
}

void __cdecl sub_E04_Emit_0047B450(int nX, int nY)
{
    sub_0047B450_DrawBlinkingCaret(0, nY, nX);
}

#include "gen/data/Source/D2Client/Unknown_0047B3B0.inc"

// 0x004095D0
void __cdecl sub_004095D0_Nop()
{
}

// 0x00409C70
void __cdecl sub_00409C70_Nop()
{
}

// 0x0047B4D0
void __cdecl sub_0047B4D0_Nop()
{
}

// 0x004BF9C0
void __cdecl sub_004BF9C0_Nop()
{
}

// 0x0050B7A0
void __cdecl sub_0050B7A0_Nop()
{
}

unsigned short gwChatHistoryCount_007BB5E4; // 0x007BB5E4

// 0x0047BA00
static void sub_0047BA00_PushChatHistory(const Unicode* pText)
{
    int nIndex;
    if (gwChatHistoryCount_007BB5E4 != 8)
    {
        if (gwChatHistoryCount_007BB5E4)
        {
            if (--gnChatHistoryHead_00712F44 < 0)
                gnChatHistoryHead_00712F44 = 7;
        }
        nIndex = gnChatHistoryHead_00712F44;
        ++gwChatHistoryCount_007BB5E4;
    }
    else
    {
        nIndex = gnChatHistoryTail_00712F48;
        gnChatHistoryHead_00712F44 = nIndex;
        if (--gnChatHistoryTail_00712F48 < 0)
            gnChatHistoryTail_00712F48 = 7;
    }
    gnChatHistoryCursor_007BB5D8 = nIndex;
    memcpy(gawszChatHistory_007BB840[nIndex], pText, sizeof(gawszChatHistory_007BB840[0]));
}

void sub_A23_Emit_0047BA00(int nSkip)
{
    const Unicode* pText = &gwszChatLine_007BB638[nSkip];
    if (sub_00526800(pText))
        sub_0047BA00_PushChatHistory(pText);
}

// 0x0047BD30
void __cdecl sub_0047BD30_ResetChatHistory()
{
    gnChatHistoryHead_00712F44 = 7;
    gnChatHistoryTail_00712F48 = 7;
    gnChatHistoryCursor_007BB5D8 = 0;
    gwChatHistoryCount_007BB5E4 = 0;
    gnChatCaret_007BB5E8 = 0;
}

// build: symbol ?sub_0047CC90_ValueToSlider@@YGIPAUD2MenuItemStrc@@III@Z 0x0047CC90
static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nValue - nMin + 1) * (float)(pItem->dwCount - 1) / (float)(nMax - nMin));
}

// 0x0047CD00
static unsigned int sub_0047CD00_SliderToValue(D2MenuItemStrc* pItem, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nMax - nMin) / (float)(pItem->dwCount - 1) * (float)pItem->dwMoveCount + (float)nMin);
}

void __fastcall sub_0047CDA0_MasterVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514CD0_SetMasterVolume(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CC0(), 0, 100);
}

void __fastcall sub_0047CDF0_MusicVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D00_SetMusicVolume(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514CF0(), 0, 100);
}

void __fastcall sub_0047CE50_SoundModeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF980_IsSoundMode1Or2();
}

void __fastcall sub_0047CE70_PositionalBiasSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D30_SetPositionalBias(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, sub_00514D20(), 0, 100);
}

void __fastcall sub_0047CED0_SoundMode2Option(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF9B0_IsSoundMode2();
}

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

void __fastcall sub_0047CF50_NpcSpeechOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_00514D50();
    if (sub_004DF880())
    {
        sub_0047CEF0_NpcSpeechSelect(pItem, (SMSGHANDLER_PARAMS*)nArg);
    }
}

void __fastcall sub_0047CF80_LightQualitySelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", szLightQuality_006D73A8, 0, pItem->dwMoveCount);
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

void __fastcall sub_0047CFE0_LightQualityOption(D2MenuItemStrc* pItem, int nArg)
{
    SRegLoadValue("Diablo II", szLightQuality_006D73A8, 0, (unsigned long*)&pItem->dwMoveCount);
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

// 0x0047D200
void __fastcall sub_0047D200_GammaSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nGamma = sub_0047CD00_SliderToValue(pItem, 0x37, 0xFF);
    SRegSaveValue("Diablo II", "Gamma", 0, nGamma);
    sub_004776C0((void*)nGamma);
}

// 0x0047D230
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

// 0x0047D2B0
void __fastcall sub_0047D2B0_ContrastSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Contrast", 0, sub_0047CD00_SliderToValue(pItem, 0, 100));
    D2GFX_SetOption(0x0B, pItem->dwMoveCount);
    D2GFX_SetGamma(0);
}

// 0x0047D2F0
void __fastcall sub_0047D2F0_ContrastOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nContrast = (sub_004F5140() != 4) ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nContrast, 0, 100);
    sub_0047D2B0_ContrastSelect(pItem, 0);
}

// 0x0047CD80
int __fastcall sub_0047CD80_IsSoundEnabled()
{
    return sub_004DF880();
}

// 0x0047CD90
int __fastcall sub_0047CD90_IsSoundEnabled()
{
    return sub_004DF880();
}

// 0x0047CE30
int __fastcall sub_0047CE30_Is3DSoundEnabled()
{
    return sub_004DF940();
}

// 0x0047CE40
void __fastcall sub_0047CE40_3DSoundSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E00D0();
}

// 0x0047CE60
int __fastcall sub_0047CE60_Is3DBiasEnabled()
{
    return sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CEB0
int __fastcall sub_0047CEB0_IsEAXEnabled()
{
    return sub_004DF960();
}

// 0x0047CEC0
void __fastcall sub_0047CEC0_EAXSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E0140();
}

static int gnOptionSelected_007BC938; // 0x007BC938

static D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940

// 0x0047D040
void __fastcall sub_0047D040_BlendShadowsChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Blended Shadows", 0, pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D070
void __fastcall sub_0047D070_BlendShadowsLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Blended Shadows", 0, (unsigned long*)&pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D0A0
void __fastcall sub_0047D0A0_ResolutionChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Resolution", 0, pEntry->nValue);
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}

// 0x0047D0E0
void __fastcall sub_0047D0E0_ResolutionLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    if (!SRegLoadValue("Diablo II", "Resolution", 0, (unsigned long*)&pEntry->nValue))
    {
        pEntry->nValue = 1;
    }
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}

// 0x0047D130
void __fastcall sub_0047D130_PerspectiveChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Perspective", 0, pEntry->nValue);
    D2GFX_SetPerspective(pEntry->nValue);
    sub_00476000_SetViewRect(gpView_007A0640, 0, 0, gnAutomapWidth_007A5220, gnAutomapHeight_007A521C);
}

// 0x0047D180
void __fastcall sub_0047D180_PerspectiveLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Perspective", 0, (unsigned long*)&pEntry->nValue);
    if (sub_004F5170())
    {
        sub_0047D130_PerspectiveChanged(pEntry, 0);
    }
    else
    {
        pEntry->nValue = 0;
    }
}

// 0x0047D370
void __fastcall sub_0047D370_AutoMapModeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 2)
    {
        pEntry->nValue = 0;
    }
    sub_0045A720(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapMode", 0, pEntry->nValue);
}

// 0x0047D3F0
void __fastcall sub_0047D3F0_AutoMapFadeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 4)
    {
        pEntry->nValue = 0;
    }
    sub_004576F0(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapFade", 0, pEntry->nValue);
}

// 0x0047D470
void __fastcall sub_0047D470_AutoMapCentersChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00457750_SetValue(pEntry->nValue);
}

// 0x0047D480
void __fastcall sub_0047D480_AutoMapCentersLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_00457740();
}

// 0x0047D490
void __fastcall sub_0047D490_AutoMapPartyChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577C0_SetValue(pEntry->nValue);
}

// 0x0047D4A0
void __fastcall sub_0047D4A0_AutoMapPartyLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_004577B0();
}

// 0x0047D4C0
void __fastcall sub_0047D4C0_AutoMapPartyNamesChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577F0_SetValue(pEntry->nValue);
}

// 0x0047D4D0
void __fastcall sub_0047D4D0_AutoMapPartyNamesLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_004577B0() && sub_004577E0();
}

// 0x0047D9A0
void __stdcall sub_0047D9A0_OptionKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
    if (sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
        {
        case 1:
            --gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1;
            }
            break;
        case 2:
            --gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue)
    {
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged(&gpOptionEntries_007BC940[gnOptionSelected_007BC938], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047DA90
void __stdcall sub_0047DA90_OptionKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
    if (sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
        {
        case 1:
            ++gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
            }
            break;
        case 2:
            ++gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue)
    {
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged(&gpOptionEntries_007BC940[gnOptionSelected_007BC938], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047D120
int __cdecl sub_0047D120_PerspectiveEnabled()
{
    return sub_004F5170();
}

// 0x0047D1F0
int __cdecl sub_0047D1F0_GammaEnabled()
{
    return D2GFX_GammaCanBeControlled();
}

// 0x0047D4B0
int __cdecl sub_0047D4B0_PartyNamesEnabled()
{
    return sub_004577B0();
}

// 0x0047D3B0
void __fastcall sub_0047D3B0_LoadAutoMapMode(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapMode", 0, &dwValue);
    if (dwValue > 2)
    {
        dwValue = 0;
    }
    sub_0045A720(dwValue);
    pEntry->nValue = sub_0045A710();
}

// 0x0047D430
void __fastcall sub_0047D430_LoadAutoMapFade(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    if (dwValue > 4)
    {
        dwValue = 0;
        sub_004576F0(dwValue);
    }
    pEntry->nValue = sub_004576C0();
}

// 0x0047DF00
void __fastcall sub_0047DF00_FreeOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x558);
    D2_ASSERT(pEntries, 0x559);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
        D2OptionEntryStrc* pEntry = &pEntries[i];
        if (pEntry->pCel)
        {
            sub_00478A00(pEntry->pCel);
            pEntry->pCel = 0;
        }
        if (pEntry->nKind == 1)
        {
            D2_ASSERT(pEntry->nValues > 0 && pEntry->nValues <= 4, 0x565);
            for (unsigned int j = 0; j < pEntry->nValues; ++j)
            {
                if (pEntry->pValueCels[j])
                {
                    sub_00478A00(pEntry->pValueCels[j]);
                    pEntry->pValueCels[j] = 0;
                }
            }
        }
    }
}

// 0x0047E720
void __cdecl sub_0047E720_LoadAlwaysRun()
{
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "Always Run", 0, &dwValue);
    sub_0044BE80(dwValue);
}

// 0x0047F1D0
void __cdecl sub_0047F1D0_LoadResolution()
{
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Resolution", 0, &dwValue))
    {
        dwValue = 1;
    }
    int nResolution = 2;
    if (!dwValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}

// 0x0047D500
static __forceinline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

// 0x0047E200
void __fastcall sub_0047E200_CloseMenus(int bRestore)
{
    if (sub_004538D0(9))
    {
        sub_00455F20(9, 1, 0);
    }
    if (bRestore)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            if (gaEscMenuUIState_00713058[i].nSaved)
            {
                sub_00455F20(i, 0, 0);
            }
        }
    }
}

// 0x0047EC20
int __fastcall sub_0047EC20_IsPanelFreeForArg(int bArg)
{
    if (bArg && !sub_004538D0(0x17))
    {
        return 1;
    }
    return 0;
}

// 0x0047E770
static void sub_0047E770_DrawModeCel(int nMode)
{
    if (!nMode)
        return;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BC960;
    switch (nMode)
    {
    case 1:
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xCD, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    case 2:
    {
        const int nX = gdwGlobal_007BC978 ? gnGlobal_0071146C / 2 - 0x4A : gnGlobal_0071146C / 2 - 0x54;
        sub_004F6480(&tContext, nX - 3, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    }
    case 3:
    {
        const int nX = gdwGlobal_007BC978 ? gnGlobal_0071146C / 2 + 0x38 : gnGlobal_0071146C / 2 + 0x23;
        sub_004F6480(&tContext, nX - 2, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    }
    }
}

void __cdecl sub_K04_EmitDrawModeCel(int nMode)
{
    sub_0047E770_DrawModeCel(nMode);
    sub_K04_EmitUse(nMode);
}

// 0x0047EC50
static void sub_0047EC50_DoSlotAction(int nButton)
{
    switch (nButton)
    {
    case 0:
        if (sub_004538D0(2))
            sub_00455F20(2, 1, 0);
        else
            sub_00455F20(2, 2, 0);
        break;
    case 1:
        if (sub_004538D0(1))
            sub_00455F20(1, 1, 0);
        else
            sub_00455F20(1, 2, 0);
        break;
    case 2:
        if (sub_004538D0(4))
            sub_00455F20(4, 1, 0);
        else
            sub_00455F20(4, 2, 0);
        break;
    case 3:
        if (sub_0044DB30())
        {
            if (sub_004538D0(0x16))
                sub_00455F20(0x16, 1, 0);
            else
                sub_00455F20(0x16, 2, 0);
        }
        break;
    case 4:
        if (sub_004538D0(0xA))
            sub_00455F20(0xA, 1, 0);
        else
            sub_00455F20(0xA, 2, 0);
        break;
    case 5:
        if (sub_004538D0(0x1F))
            sub_00455F20(0x1F, 1, 0);
        if (sub_004538D0(0x18))
            sub_00455F20(0x18, 1, 0);
        else
            sub_00455F20(0x18, 2, 0);
        break;
    case 6:
        OutputDebugStringA("Panel quest log toggle\n");
        sub_004A3FE0(0);
        break;
    case 7:
        sub_00456300(0, 0);
        sub_00453AC0();
        sub_0047E090(1, 0);
        sub_00453AD0();
        sub_00453AE0();
        break;
    }
}

int gbSlotClicked_007BC97C; // 0x007BC97C

// 0x0047ED90
void __stdcall sub_0047ED90_SlotsClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!gbSlotClicked_007BC97C)
        return;
    gbSlotClicked_007BC97C = 0;
    if (!pPlayer)
        return;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
        return;
    if (INVENTORY_GetCursorItem(pInventory))
        return;
    if (sub_00468830() != 7)
        sub_00468070_SetCursorItemState(0);
    int nCount = 8;
    if (gdwGlobal_007BC978)
        nCount = 7;
    if (!gdwGlobal_007BC970)
    {
        D2UnitStrc* pUnit = sub_00463DD0();
        const int nX = pMsg->nXPos;
        const int nY = pMsg->nYPos;
        int nOffset = 0;
        for (int i = 0; i < nCount; ++i)
            gnSlotState_007BC8F8[i] = 0;
        if (sub_004979E0() && sub_004979F0() > 1)
            nOffset = -0x76;
        if (gdwGlobal_007BC968)
            nOffset -= 0x76;
        if (gdwGlobal_007BC96C)
            nOffset += 0x77;
        const int nCenter = gnGlobal_0071146C / 2 + nOffset;
        if (nX > nCenter - 0x54 && nX < nCenter + 0x59 && nY > gnGlobal_00711470 - 0x45 && nY < gnGlobal_00711470 - 0x2F)
        {
            for (int i = 0; i < nCount; ++i)
            {
                if (nX <= gnSlotX_007BC898[i])
                    continue;
                if (nX >= gnSlotX_007BC898[i] + 0x14)
                    continue;
                const int nButton = gaSlotKind_007BC8D8[i];
                if (nButton == 7)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
                else if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit) && sub_00451F70_GetUnitMode(pUnit) != 0x11)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
            }
            sub_0044DA40();
            sub_0044DA70();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }
        pMsg->bReturn = 0;
    }
    gdwGlobal_007BC974 = 0;
}

D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C

// 0x0047F2A0
void __fastcall sub_0047F2A0_ShowPage1(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714210;
    gpOptionEntries_007BC940 = gaOptionEntries_00714238;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F460
void __fastcall sub_0047F460_ShowPage1Twin(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714210;
    gpOptionEntries_007BC940 = gaOptionEntries_00714238;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F2D0
void __fastcall sub_0047F2D0_ExitGame(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_0044B880_SetValue(0);
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    sub_0044C860_SetValue(1);
    sub_0047E200_CloseMenus(1);
}

// 0x0047F300
void __fastcall sub_0047F300_CloseMenus(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047E200_CloseMenus(1);
}

// 0x0047F310
void __fastcall sub_0047F310_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714224;
    gpOptionEntries_007BC940 = gaOptionEntries_00715CC8;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F340
void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071875C;
        gpOptionEntries_007BC940 = gaOptionEntries_0071ACA0;
    }
    else
    {
        gpOptionHeader_007BC93C = &gOptionHeader_00718748;
        gpOptionEntries_007BC940 = gaOptionEntries_00718770;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F3A0
void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071D734;
        gpOptionEntries_007BC940 = gaOptionEntries_0071F728;
    }
    else
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071D720;
        gpOptionEntries_007BC940 = gaOptionEntries_0071D748;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F400
void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_004538D0(9))
        sub_00455F20(9, 1, 0);
    sub_00455F20(0xB, 0, 0);
}

// 0x0047F430
void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00713044;
    gpOptionEntries_007BC940 = gaOptionEntries_00713220;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}
