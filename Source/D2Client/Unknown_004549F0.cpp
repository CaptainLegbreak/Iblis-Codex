#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MsgHandlerEntryStrc;
struct D2CelFileStrc;
struct D2UiControlAStrc;
struct D2UiControlBStrc;
struct D2UiControlCStrc;
struct D2RectStrc;

int __fastcall UI_GetHoverRect(D2RectStrc* pRect); // 0x00454880
unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource); // 0x005267E0
int __fastcall D2Win_10121_GetTextWidth(const unsigned short* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
static void __stdcall sub_004549F0_DrawHoverLine(const unsigned short* wszText, int nFont, int nY, int nColor);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


struct D2UIVarRecordStrc
{
    int anCloseKind[0x26];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __cdecl UI_ToggleMiniPanel(); // 0x004567F0
void __cdecl AUTOMAP_InitAutomap(); // 0x0045A4C0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl CMDTBL_EnableHotkeyHandlers(); // 0x0046AC70
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
void __cdecl sub_0047DD70_LoadOptionMenus(); // 0x0047DD70
void __cdecl sub_0047F0C0_LoadMiniPanel(); // 0x0047F0C0
void __cdecl sub_004868B0(); // 0x004868B0
void __cdecl INV_LoadShopPanelCels(); // 0x00489220
void __cdecl HIREABLES_LoadHirelingIcons(); // 0x00492C20
void __cdecl INV_LoadPanelCels(); // 0x004967F0
void __cdecl sub_0049C6A0(); // 0x0049C6A0
void __cdecl TEXT_LoadTextSettings(); // 0x0049D440
int __cdecl TEXT_IsTextBoxOpen(); // 0x004A0000
void __cdecl TEXT_ResetQuestPanel(); // 0x004A3410
void __cdecl TEXT_InitTextSlider(); // 0x004A5190
void __cdecl TEXT_LoadLevelCels(); // 0x004A6460
void __cdecl TEXT_InitNpcMenu(); // 0x004B23E0
int __fastcall NPCMENU_GetInteractNpcId(int* pLow); // 0x004B3230
void __fastcall NPCMENU_EndNpcInteraction(int nValue); // 0x004B3C20
void __cdecl DIALOG_InitDialogs(); // 0x004B7B40
void __cdecl sub_004B8720(); // 0x004B8720
void __cdecl TEXT_LoadTextSliderCel(); // 0x004BE020
void __cdecl USEITEM_InitUseItemPanel(); // 0x004BF9D0
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
extern D2MsgHandlerEntryStrc gaGameUIHandlers[]; // 0x006D5F28
extern D2MsgHandlerEntryStrc gaHelpButtonHandlers[]; // 0x006D6300
extern D2CelFileStrc* gpBoxPiecesCel; // 0x007A2798
extern D2UiControlAStrc* gpGoldControlA; // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB; // 0x007A27A8
extern D2UiControlCStrc* gpGoldControlC; // 0x007A27AC
extern D2UiControlCStrc* gpGoldControlD; // 0x007A27B0
extern int gbGoldPanelFlag; // 0x007A27B4
extern D2CelFileStrc* gpPentspinCel; // 0x007A2878
extern D2CelFileStrc* gpFocus16Cel; // 0x007A2880

// 0x004549F0
static void __stdcall sub_004549F0_DrawHoverLine(const unsigned short* wszText, int nFont, int nY, int nColor)
{
    unsigned short wszBuffer[256];
    for (int i = 0; i < 256; i++)
    {
        wszBuffer[i] = 0;
    }

    D2RectStrc tRect;

    if (!UI_GetHoverRect(&tRect) || !wszText)
    {
        return;
    }

    const int nOldFont = sub_00502EF0_SetFont(nFont);
    sub_005267E0(wszBuffer, wszText);
    const int nX = ((tRect.nLeft + tRect.nRight) >> 1) - (D2Win_10121_GetTextWidth(wszBuffer) >> 1);
    D2Win_10117_DrawText(wszBuffer, nX, nY, nColor, 1);
    sub_00502EF0_SetFont(nOldFont);
}

// build: context sub_004549F0_Shim
// calling-convention shim (not game code)
void __fastcall sub_004549F0_Shim(const unsigned short* wszText, int nFont)
{
    sub_004549F0_DrawHoverLine(wszText, nFont, 10, 0);
}

int gaUIVarStates[1]; // 0x007A27C0

// 0x00456970
void __cdecl sub_00456970_InitUI()
{
    char szPath[0x104];
    INV_LoadPanelCels();
    sub_0047F0C0_LoadMiniPanel();
    TEXT_LoadTextSettings();
    TEXT_LoadLevelCels();
    HIREABLES_LoadHirelingIcons();
    TEXT_InitNpcMenu();
    AUTOMAP_InitAutomap();
    sub_0049C6A0();
    sub_004B8720();
// build: symbol ?gpGoldPanel@* 0x007A27A0
    gpGoldPanel = 0;
    gpGoldControlA = 0;
    gpGoldControlB = 0;
    gpGoldControlD = 0;
    gpGoldControlC = 0;
    gbGoldPanelFlag = 0;
    sub_004868B0();
    for (int i = 0; i < 0x26; i++)
        gaUIVarStates[i] = 0;

    {
        const int bWasOn = gaUIVarStates[0];
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (FOG_IsExpansion())
            GAME_IsExpansion();
// build: symbol ?gnUIVarCount@* 0x0070F9CC
        D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
        if (TEXT_IsTextBoxOpen())
            goto mini_panel;
        for (int i = 0; i < gnUIVarCount; ++i)
        {
            if (gaUIVarStates[i] == 1)
            {
// build: symbol ?gapUIVarRecords@* 0x00711130
                switch (gapUIVarRecords[i]->anCloseKind[0])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                    goto mini_panel;
                default:
                    D2_ASSERT(false, 0x13E6);
                }
            }
        }
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
            gaUIVarStates[0] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates[0])
                COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaGameUIHandlers, 4);
        }
        else
        {
            if (!gaUIVarStates[0])
                sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaGameUIHandlers, 4);
        }
        sub_00468730();
        sub_00468740();
    }

mini_panel:
    UI_ToggleMiniPanel();
    {
        const int bWasOn = gaUIVarStates[0x22];
        if (FOG_IsExpansion())
            GAME_IsExpansion();
        D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
        if (TEXT_IsTextBoxOpen())
            goto load_cels;
        for (int i = 0; i < gnUIVarCount; ++i)
        {
            if (gaUIVarStates[i] == 1)
            {
                bool bClose = true;
                switch (gapUIVarRecords[i]->anCloseKind[0x22])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                case 3:
                    bClose = false;
                    break;
                default:
                    goto load_cels;
                }
                if (!bClose)
                    goto load_cels;
            }
        }
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
            gaUIVarStates[0x22] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates[0x22])
                COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaHelpButtonHandlers, 2);
        }
        else
        {
            if (!gaUIVarStates[0x22])
                sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHelpButtonHandlers, 2);
        }
        sub_00468730();
        sub_00468740();
    }

load_cels:
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\UI\\CURSOR\\Pentspin", gszDataGlobal);
    gpPentspinCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\focus16", gszDataGlobal);
    gpFocus16Cel = ARCHIVE_LoadClientCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\menu\\boxpieces", gszDataGlobal);
    gpBoxPiecesCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    USEITEM_InitUseItemPanel();
    DIALOG_InitDialogs();
    INV_LoadShopPanelCels();
    TEXT_LoadTextSliderCel();
    TEXT_ResetQuestPanel();
    CMDTBL_EnableHotkeyHandlers();
    sub_0047DD70_LoadOptionMenus();
    TEXT_InitTextSlider();
}

#include "gen/data/Source/D2Client/Unknown_004549F0.inc"
