#include "D2Client.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;
struct D2MenuItemStrc;
struct Unicode;
struct D2OptionEntryStrc;
struct D2OptionHeaderStrc;
struct D2EscMenuUIStateStrc;
extern "C" unsigned int __cdecl strlen(const char* szString);
extern const char gszM134CmdA[];
extern const char gszM134CmdB[];
void __stdcall sub_M134_Use(const char* szText);

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern int gnScreenWidth; // 0x0071146C
extern Unicode gwszImeResult[32]; // 0x007BB5F8
extern Unicode gwszImeComposition[32]; // 0x007BC850
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern Unicode gawszChatHistory_007BB840[8][257]; // 0x007BB840
extern Unicode gwszChatLine_007BB638[]; // 0x007BB638
extern unsigned short gwChatHistoryCount; // 0x007BB5E4
extern int gnChatCaret; // 0x007BB5E8

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
    D2CelFileStrc* pImage;
    D2CelFileStrc* pChoices[4];
};

// build: symbol _gszLightQuality 0x006D73A8
extern "C" const char gszLightQuality[];
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0
int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20
int __cdecl D2SOUND_GetNpcSpeechOption(); // 0x00514D50
int __fastcall D2SOUND_SetMasterVolumeOption(int nValue); // 0x00514CD0
int __fastcall D2SOUND_SetMusicVolumeOption(int nValue); // 0x00514D00
int __fastcall D2SOUND_SetPositionalBiasOption(int nValue); // 0x00514D30
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
int __cdecl sub_004E00D0_ToggleSoundMode01(); // 0x004E00D0
int __cdecl sub_004E0140_ToggleSoundMode12(); // 0x004E0140

void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows); // 0x004F5200
void __fastcall GAME_SetResolution(int nResolution); // 0x0044BA20
void __fastcall AUTOMAP_SetAutomapMode(int nMode); // 0x0045A720
int __fastcall AUTOMAP_SetAutomapFade(int nFade); // 0x004576F0
int __cdecl UI_GetAutomapCenters(); // 0x00457740
int __fastcall OBJECT_SaveAutomapCenters(int nValue); // 0x00457750
int __cdecl UI_GetAutomapParty(); // 0x004577B0
int __cdecl UI_GetAutomapPartyNames(); // 0x004577E0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern D2ViewStrc* gpClientView; // 0x007A0640
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth; // 0x007A5220

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall GAME_SetAlwaysRun(int bAlwaysRun); // 0x0044BE80
int __cdecl AUTOMAP_GetAutomapFade(); // 0x004576C0
int __cdecl UI_GetAutomapMode(); // 0x0045A710
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
// build: symbol _gszDiabloII 0x006CC8B8
extern "C" const char gszDiabloII[];
// build: symbol _gszResolution 0x006CC8AC
extern "C" const char gszResolution[];
// build: symbol _gszAutoMapFade 0x006D66A0
extern "C" const char gszAutoMapFade[];
// build: symbol _gszBlendedShadows 0x006D73B8
extern "C" const char gszBlendedShadows[];
// build: symbol _gszPerspective 0x006D73C8
extern "C" const char gszPerspective[];
// build: symbol _gszAutoMapMode 0x006D73E8
extern "C" const char gszAutoMapMode[];

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
extern D2EscMenuUIStateStrc gaEscMenuUIState[38]; // 0x00713058

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern void* gpMiniPanelCel; // 0x007BC960
extern int gnScreenHeight; // 0x00711470
extern int gbSmallPanel; // 0x007BC978
void __cdecl sub_K04_EmitUse(int nValue);

int __cdecl GAME_GetConnectionType(); // 0x0044DB30
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
void __fastcall TEXT_ToggleQuestLog(int nMode); // 0x004A3FE0
int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __cdecl UI_DisableUIVarDelay(); // 0x00453AC0
void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090
void __cdecl UI_EnableUIVarDelay(); // 0x00453AD0
void __cdecl UI_StartUIVarDelay(); // 0x00453AE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0
int __cdecl HIREABLES_GetBeltRowCount(); // 0x004979F0
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
extern int gbSlotClicked; // 0x007BC97C
extern int gbSlotBarBlocked; // 0x007BC970
extern int gdwGlobal_007BC974; // 0x007BC974
extern int gbAnyLeftPanelOpen; // 0x007BC968
extern int gbAnyPanelOpen; // 0x007BC96C
extern int gaSlotX[]; // 0x007BC898
extern int gaSlotKind[]; // 0x007BC8D8
void __fastcall GAME_SetExitApplication(int nValue); // 0x0044B880
void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860
void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200
extern D2OptionHeaderStrc gtMainOptionHeader; // 0x00713044
extern D2OptionEntryStrc gaMainOptionEntries[]; // 0x00713220
extern D2OptionHeaderStrc gtOptionsHeader; // 0x00714210
extern D2OptionHeaderStrc gtSoundOptionHeader; // 0x00714224
extern D2OptionEntryStrc gaOptionsEntries[]; // 0x00714238
extern D2OptionEntryStrc gaSoundOptionEntries[]; // 0x00715CC8
extern D2OptionHeaderStrc gtVideoOptionHeader; // 0x00718748
extern D2OptionHeaderStrc gtVideoResOptionHeader; // 0x0071875C
extern D2OptionEntryStrc gaVideoOptionEntries[]; // 0x00718770
extern D2OptionEntryStrc gaVideoResOptionEntries[]; // 0x0071ACA0
extern D2OptionHeaderStrc gtAutomapOptionHeader; // 0x0071D720
extern D2OptionHeaderStrc gtAutomapModeOptionHeader; // 0x0071D734
extern D2OptionEntryStrc gaAutomapOptionEntries[]; // 0x0071D748
extern D2OptionEntryStrc gaAutomapModeOptionEntries[]; // 0x0071F728

static inline int sub_0047D500(D2OptionEntryStrc* pEntry);
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
void __cdecl GLIDE_DebugFillBackBuffer()
{
}

unsigned short gwChatHistoryCount; // 0x007BB5E4

// 0x0047BA00
static void sub_0047BA00_PushChatHistory(const Unicode* pText)
{
    int nIndex;
    if (gwChatHistoryCount != 8)
    {
        if (gwChatHistoryCount)
        {
// build: symbol ?gnChatHistoryHead@* 0x00712F44
            if (--gnChatHistoryHead < 0)
                gnChatHistoryHead = 7;
        }
        nIndex = gnChatHistoryHead;
        ++gwChatHistoryCount;
    }
    else
    {
// build: symbol ?gnChatHistoryTail@* 0x00712F48
        nIndex = gnChatHistoryTail;
        gnChatHistoryHead = nIndex;
        if (--gnChatHistoryTail < 0)
            gnChatHistoryTail = 7;
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
    gnChatHistoryHead = 7;
    gnChatHistoryTail = 7;
    gnChatHistoryCursor_007BB5D8 = 0;
    gwChatHistoryCount = 0;
    gnChatCaret = 0;
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
    D2SOUND_SetMasterVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMasterVolumeOption(), 0, 100);
}

void __fastcall sub_0047CDF0_MusicVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetMusicVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMusicVolumeOption(), 0, 100);
}

void __fastcall sub_0047CE50_SoundModeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF980_IsSoundMode1Or2();
}

void __fastcall sub_0047CE70_PositionalBiasSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetPositionalBiasOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetPositionalBiasOption(), 0, 100);
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
    pItem->dwMoveCount = D2SOUND_GetNpcSpeechOption();
    if (sub_004DF880())
    {
        sub_0047CEF0_NpcSpeechSelect(pItem, (SMSGHANDLER_PARAMS*)nArg);
    }
}

void __fastcall sub_0047CF80_LightQualitySelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", gszLightQuality, 0, pItem->dwMoveCount);
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
    SRegLoadValue("Diablo II", gszLightQuality, 0, (unsigned long*)&pItem->dwMoveCount);
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
            ARCHIVE_FreeClientCellFile(pEntry->pCel);
            pEntry->pCel = 0;
        }
        if (pEntry->nKind == 1)
        {
            D2_ASSERT(pEntry->nValues > 0 && pEntry->nValues <= 4, 0x565);
            for (unsigned int j = 0; j < pEntry->nValues; ++j)
            {
                if (pEntry->pValueCels[j])
                {
                    ARCHIVE_FreeClientCellFile(pEntry->pValueCels[j]);
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
    GAME_SetAlwaysRun(dwValue);
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
    GAME_SetResolution(nResolution);
}

// 0x0047D500
static inline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

// 0x0047E200
void __fastcall sub_0047E200_CloseMenus(int bRestore)
{
    if (GAME_GetUIVarState(9))
    {
        UI_SetUIVar(9, 1, 0);
    }
    if (bRestore)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            if (gaEscMenuUIState[i].nSaved)
            {
                UI_SetUIVar(i, 0, 0);
            }
        }
    }
}

// 0x0047EC20
int __fastcall sub_0047EC20_IsPanelFreeForArg(int bArg)
{
    if (bArg && !GAME_GetUIVarState(0x17))
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
    tContext.pCellFile = gpMiniPanelCel;
    switch (nMode)
    {
    case 1:
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0xCD, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    case 2:
    {
        const int nX = gbSmallPanel ? gnScreenWidth / 2 - 0x4A : gnScreenWidth / 2 - 0x54;
        sub_004F6480(&tContext, nX - 3, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    }
    case 3:
    {
        const int nX = gbSmallPanel ? gnScreenWidth / 2 + 0x38 : gnScreenWidth / 2 + 0x23;
        sub_004F6480(&tContext, nX - 2, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    }
    }
}

// 0x0047D130
void __fastcall sub_0047D130_PerspectiveChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Perspective", 0, pEntry->nValue);
    D2GFX_SetPerspective(pEntry->nValue);
    sub_00476000_SetViewRect(gpClientView, 0, 0, gnAutomapWidth, gnAutomapHeight_007A521C);
}

// 0x0047D180
void __fastcall sub_0047D180_PerspectiveLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Perspective", 0, (unsigned long*)&pEntry->nValue);
// build: symbol ?D2GFX_CheckUnitPerspective@* 0x004F5170
    if (D2GFX_CheckUnitPerspective())
    {
        sub_0047D130_PerspectiveChanged(pEntry, 0);
    }
    else
    {
        pEntry->nValue = 0;
    }
}

static int gnOptionSelected; // 0x007BC938

static D2OptionEntryStrc* gpOptionEntries; // 0x007BC940

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
    sub_004E00D0_ToggleSoundMode01();
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
    sub_004E0140_ToggleSoundMode12();
}

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
    GAME_SetResolution(nResolution);
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
    GAME_SetResolution(nResolution);
}

// 0x0047D370
void __fastcall sub_0047D370_AutoMapModeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 2)
    {
        pEntry->nValue = 0;
    }
    AUTOMAP_SetAutomapMode(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapMode", 0, pEntry->nValue);
}

// 0x0047D3F0
void __fastcall sub_0047D3F0_AutoMapFadeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 4)
    {
        pEntry->nValue = 0;
    }
    AUTOMAP_SetAutomapFade(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapFade", 0, pEntry->nValue);
}

// 0x0047D470
void __fastcall sub_0047D470_AutoMapCentersChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    OBJECT_SaveAutomapCenters(pEntry->nValue);
}

// 0x0047D480
void __fastcall sub_0047D480_AutoMapCentersLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = UI_GetAutomapCenters();
}

// 0x0047D490
void __fastcall sub_0047D490_AutoMapPartyChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577C0_SetValue(pEntry->nValue);
}

// 0x0047D4A0
void __fastcall sub_0047D4A0_AutoMapPartyLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = UI_GetAutomapParty();
}

// 0x0047D4C0
void __fastcall sub_0047D4C0_AutoMapPartyNamesChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577F0_SetValue(pEntry->nValue);
}

// 0x0047D4D0
void __fastcall sub_0047D4D0_AutoMapPartyNamesLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = UI_GetAutomapParty() && UI_GetAutomapPartyNames();
}

// 0x0047D9A0
void __stdcall sub_0047D9A0_OptionKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 1:
            --gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
            }
            break;
        case 2:
            --gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = 0;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047DA90
void __stdcall sub_0047DA90_OptionKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 1:
            ++gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = 0;
            }
            break;
        case 2:
            ++gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D120
int __cdecl sub_0047D120_PerspectiveEnabled()
{
    return D2GFX_CheckUnitPerspective();
}

// 0x0047D1F0
int __cdecl sub_0047D1F0_GammaEnabled()
{
    return D2GFX_GammaCanBeControlled();
}

// 0x0047D4B0
int __cdecl sub_0047D4B0_PartyNamesEnabled()
{
    return UI_GetAutomapParty();
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
    AUTOMAP_SetAutomapMode(dwValue);
    pEntry->nValue = UI_GetAutomapMode();
}

// 0x0047D430
void __fastcall sub_0047D430_LoadAutoMapFade(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    if (dwValue > 4)
    {
        dwValue = 0;
        AUTOMAP_SetAutomapFade(dwValue);
    }
    pEntry->nValue = AUTOMAP_GetAutomapFade();
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
        if (GAME_GetUIVarState(2))
            UI_SetUIVar(2, 1, 0);
        else
            UI_SetUIVar(2, 2, 0);
        break;
    case 1:
        if (GAME_GetUIVarState(1))
            UI_SetUIVar(1, 1, 0);
        else
            UI_SetUIVar(1, 2, 0);
        break;
    case 2:
        if (GAME_GetUIVarState(4))
            UI_SetUIVar(4, 1, 0);
        else
            UI_SetUIVar(4, 2, 0);
        break;
    case 3:
        if (GAME_GetConnectionType())
        {
            if (GAME_GetUIVarState(0x16))
                UI_SetUIVar(0x16, 1, 0);
            else
                UI_SetUIVar(0x16, 2, 0);
        }
        break;
    case 4:
        if (GAME_GetUIVarState(0xA))
            UI_SetUIVar(0xA, 1, 0);
        else
            UI_SetUIVar(0xA, 2, 0);
        break;
    case 5:
        if (GAME_GetUIVarState(0x1F))
            UI_SetUIVar(0x1F, 1, 0);
        if (GAME_GetUIVarState(0x18))
            UI_SetUIVar(0x18, 1, 0);
        else
            UI_SetUIVar(0x18, 2, 0);
        break;
    case 6:
        OutputDebugStringA("Panel quest log toggle\n");
        TEXT_ToggleQuestLog(0);
        break;
    case 7:
        UI_CloseUIVars(0, 0);
        UI_DisableUIVarDelay();
        WARDENCLIENT_ToggleEscMenuUIState(1, 0);
        UI_EnableUIVarDelay();
        UI_StartUIVarDelay();
        break;
    }
}

int gbSlotClicked; // 0x007BC97C

// 0x0047ED90
void __stdcall sub_0047ED90_SlotsClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!gbSlotClicked)
        return;
    gbSlotClicked = 0;
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
    if (gbSmallPanel)
        nCount = 7;
    if (!gbSlotBarBlocked)
    {
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        int nOffset = 0;
        for (int i = 0; i < nCount; ++i)
            gnSlotState_007BC8F8[i] = 0;
        if (HIREABLES_AreBeltRowsShown() && HIREABLES_GetBeltRowCount() > 1)
            nOffset = -0x76;
        if (gbAnyLeftPanelOpen)
            nOffset -= 0x76;
        if (gbAnyPanelOpen)
            nOffset += 0x77;
        const int nCenter = gnScreenWidth / 2 + nOffset;
        if (nX > nCenter - 0x54 && nX < nCenter + 0x59 && nY > gnScreenHeight - 0x45 && nY < gnScreenHeight - 0x2F)
        {
            for (int i = 0; i < nCount; ++i)
            {
                if (nX <= gaSlotX[i])
                    continue;
                if (nX >= gaSlotX[i] + 0x14)
                    continue;
                const int nButton = gaSlotKind[i];
                if (nButton == 7)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
                else if (!GAME_GetUnitTypeOrInvalid(pUnit) && sub_00451F70_GetUnitMode(pUnit) != 0x11)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
            }
            GAME_ResetMouseState();
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn = 0;
    }
    gdwGlobal_007BC974 = 0;
}

D2OptionHeaderStrc* gpOptionHeader; // 0x007BC93C

// 0x0047F2A0
void __fastcall sub_0047F2A0_ShowPage1(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtOptionsHeader;
    gpOptionEntries = gaOptionsEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F460
void __fastcall sub_0047F460_ShowPage1Twin(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtOptionsHeader;
    gpOptionEntries = gaOptionsEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F2D0
void __fastcall sub_0047F2D0_ExitGame(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    GAME_SetExitApplication(0);
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    GAME_SetCinematicExit(1);
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
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtSoundOptionHeader;
    gpOptionEntries = gaSoundOptionEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F340
void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        gpOptionHeader = &gtVideoResOptionHeader;
        gpOptionEntries = gaVideoResOptionEntries;
    }
    else
    {
        gpOptionHeader = &gtVideoOptionHeader;
        gpOptionEntries = gaVideoOptionEntries;
    }
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F3A0
void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    if (FOG_IsExpansion())
    {
        gpOptionHeader = &gtAutomapModeOptionHeader;
        gpOptionEntries = gaAutomapModeOptionEntries;
    }
    else
    {
        gpOptionHeader = &gtAutomapOptionHeader;
        gpOptionEntries = gaAutomapOptionEntries;
    }
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F400
void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_GetUIVarState(9))
        UI_SetUIVar(9, 1, 0);
    UI_SetUIVar(0xB, 0, 0);
}

// 0x0047F430
void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtMainOptionHeader;
    gpOptionEntries = gaMainOptionEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}
