#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UIVarRecordStrc
{
    int anCloseKind[0x26];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __cdecl GAME_IsHardcore();                                                                      // 0x0044B850

void __cdecl GAME_SetCharDiedFlag();                                                                                // 0x0044B860

void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880

void __cdecl GAME_RequestExit();                                                                                // 0x0044D520

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

void __fastcall UI_SetPanelHandlers(int nUIVar);                                                         // 0x00455720

void __fastcall PLAYER_SetPanelSlide(int nMode);                                                      // 0x0045AEA0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

int __cdecl sub_00468730();                                                                                 // 0x00468730

int __cdecl sub_00468740();                                                                                 // 0x00468740

void __fastcall UI_SetCursorPosition(int nA, int nB);                                                               // 0x00468770

void __fastcall sub_00478590(char nValue);                                                                  // 0x00478590

void __cdecl CHAT_ClearChatLine();                                                                                // 0x0047BDC0

void __cdecl INV_ResetHover();                                                                     // 0x00487990

int __cdecl TEXT_IsTextBoxOpen();                                                                                 // 0x004A0000

void __cdecl TEXT_CloseKeyCaptureHandlers();                                                                                // 0x004A5DE0

int __fastcall NPCMENU_GetInteractNpcId(int* pLow);                                                         // 0x004B3230

void __fastcall NPCMENU_EndNpcInteraction(int nValue);                                                                   // 0x004B3C20

int __cdecl sub_004B85E0();                                                                                 // 0x004B85E0

extern const int gaUIVarDefaults_006D6378[];                                                                // 0x006D6378

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gdwGlobal_007A0618;                                                                              // 0x007A0618

extern int gdwGlobal_007A061C;                                                                              // 0x007A061C

unsigned long gdwUIVarTick_007A2790;                                                                        // 0x007A2790

extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                    // 0x00455F20

struct D2CelFileStrc;

struct D2MsgHandlerEntryStrc;

struct D2RectStrc;

struct D2UiControlAStrc;

struct D2UiControlBStrc;

typedef unsigned short Unicode;

void __fastcall GAME_ExtendDelay(int nDelay); // 0x0044DB40

void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __cdecl UI_CloseGoldDialog(); // 0x00453EE0

void __fastcall sub_00457640(int bForce); // 0x00457640

void __cdecl AUTOMAP_FreeAutomap(); // 0x0045A5C0

void __cdecl AUTOMAP_InitAutomapColors(); // 0x0045A620

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0

void __cdecl CMDTBL_DisableHotkeyHandlers(); // 0x0046ACB0

void __fastcall sub_00472890(D2DrlgActStrc* pAct); // 0x00472890

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __cdecl sub_0047DFD0_FreeOptionMenus(); // 0x0047DFD0

void __cdecl sub_0047E720_LoadAlwaysRun(); // 0x0047E720

void __cdecl sub_0047E750_SaveAlwaysRun(); // 0x0047E750

void __cdecl sub_0047F130_SaveMiniPanel(); // 0x0047F130

void __cdecl CUNIT_InitColorTable(); // 0x00483960

void __cdecl sub_00486980(); // 0x00486980

void __cdecl sub_004892F0(); // 0x004892F0

void __cdecl sub_0048A600(); // 0x0048A600

void __cdecl HIREABLES_FreeHirelingIcons(); // 0x00492EC0

void __cdecl VIEW_ResetLifeColors(); // 0x00492F90

void __cdecl TEXT_LoadPopupHireling(); // 0x004939B0

void __cdecl HIREABLES_FreeHelpCels(); // 0x00494EE0

void __cdecl HIREABLES_FreePanelCels(); // 0x00496990

void __cdecl sub_00498E80_ClearPair(); // 0x00498E80

void __cdecl PANEL_SetBlackColour(); // 0x00499E30

void __cdecl PANEL_LoadPartyCels(); // 0x0049C0A0

void __cdecl PANEL_FreePartyCels(); // 0x0049C0F0

void __cdecl sub_0049C700_CloseWaypointPanel(); // 0x0049C700

void __cdecl TEXT_FreeTextLists(); // 0x004A0010

void __cdecl TEXT_FreeTextResources(); // 0x004A0680

void __cdecl TEXT_FreeQuestPanel(); // 0x004A2600

void __cdecl TEXT_ClearQuestFlags(); // 0x004A3020

void __cdecl sub_004A3050(); // 0x004A3050

void __cdecl TEXT_FreeTextSliderCel(); // 0x004A51E0

void __cdecl TEXT_FreeLevelCels(); // 0x004A6480

void __cdecl sub_004A7AA0_InitTextEntryLengths(); // 0x004A7AA0

void __cdecl sub_004A7AD0(); // 0x004A7AD0

void __cdecl sub_004A8A30_InitSkillIcons(); // 0x004A8A30

void __cdecl sub_004A8C00_FreeSkillIcons(); // 0x004A8C00

void __cdecl sub_004AA920_LoadPanelCel(); // 0x004AA920

void __cdecl sub_004AA980(); // 0x004AA980

void __cdecl NPCMENU_FreeNpcMenu(); // 0x004B24A0

void __cdecl NPCMENU_ResetNpcMenu(); // 0x004B32F0

void __cdecl DIALOG_FreeDialogs(); // 0x004B7B50

void __cdecl sub_004B8720(); // 0x004B8720

int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

void __cdecl sub_004B91F0(); // 0x004B91F0

void __cdecl sub_004BE060(); // 0x004BE060

void __cdecl USEITEM_FreeUseItemPanel(); // 0x004C0100

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __stdcall D2Win_10116(); // 0x005015F0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[]; // 0x006D5F28

extern D2DrlgActStrc* gpGlobal_007A063C; // 0x007A063C

extern D2CelFileStrc* gpLoadingCell_007A2794; // 0x007A2794

extern int gdwGlobal_007A2868; // 0x007A2868

extern D2CelFileStrc* gpBuySellButton_007A287C; // 0x007A287C

extern D2CelFileStrc* gpLoadingScreen_007A2888; // 0x007A2888

extern D2CelFileStrc* gpYouDiedHardcoreCel_007A2894; // 0x007A2894

extern D2CelFileStrc* gpYouDiedInstCel_007A2898; // 0x007A2898

enum D2C_StatIds
{
    STAT_GOLD = 14,
    STAT_GOLDBANK = 15,
};

struct D2UiControlAStrc
{
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual int GetDirection();
    virtual unsigned int GetStep(int nArg);
};

struct D2UiControlBStrc
{
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual unsigned int GetValue();
    virtual void sub_Virtual30();
    virtual void sub_Virtual34();
    virtual void SetValue(int nValue);
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

extern D2UiControlAStrc* gpGoldControlA_007A27A4; // 0x007A27A4

extern D2UiControlBStrc* gpGoldControlB_007A27A8; // 0x007A27A8

D2CelFileStrc* gpBoxPiecesCel_007A2798; // 0x007A2798

D2CelFileStrc* gpPentspinCel_007A2878; // 0x007A2878

D2CelFileStrc* gpFocus16Cel_007A2880; // 0x007A2880

int gdwGlobal_007A2884; // 0x007A2884

int gdwGlobal_007A288C; // 0x007A288C

unsigned long gdwLastTick_007A313C; // 0x007A313C

// 0x00453910
static int UI_CanSetUIVar(int nUIVar, int nState)
{
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    if (nState == 0 || (nState == 2 && !gaUIVarStates_007A27C0[nUIVar]))
    {
        if (nUIVar == 0x05 || nUIVar == 0x09)
        {
            if (sub_004B85E0() && nUIVar == 0x05 && !gaUIVarStates_007A27C0[0x18])
            {
                return 0;
            }
            if (gdwUIVarTick_007A2790 > GetTickCount())
            {
                return 0;
            }
            if (nUIVar == 0x09)
            {
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                if (!pPlayer)
                {
                    return 0;
                }
                if (pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->dwAnimMode == 0x11)
                {
                    sub_004647D0(pPlayer);
                    sub_00478590(0x41);
                    if (GAME_IsHardcore())
                    {
                        sub_00477EE0();
                        gdwGlobal_007A061C = 0;
                        gdwGlobal_007A0618 = 0;
                        GAME_SetCharDiedFlag();
                        sub_0044B880_SetValue(0);
                        GAME_RequestExit();
                    }
                    return 0;
                }
            }
        }
        if (TEXT_IsTextBoxOpen() && nUIVar != 0x0A && nUIVar != 0x13 && nUIVar != 0x11 && nUIVar != 0x06 && nUIVar != 0x07)
        {
            return 0;
        }
        for (int i = 0; i < gnUIVarCount_0070F9CC; i++)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                switch (gpUIVarRecords_00711130[i]->anCloseKind[nUIVar])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                    {
                        NPCMENU_EndNpcInteraction(nLow);
                    }
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                    return 0;
                default:
                    D2_ASSERT(nUIVar, 0x13E6);
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x00453AE0
void __cdecl UI_StartUIVarDelay()
{
    if (gdwGlobal_0070FA9C)
    {
        gdwUIVarTick_007A2790 = GetTickCount() + 0x64;
    }
}

// 0x00453A90
int __fastcall UI_GetUIVarUnchecked(int nUIVar)
{
    return gaUIVarStates_007A27C0[nUIVar];
}

// 0x00453B00
void __cdecl UI_SendMouseMove()
{
    SendMessageA(WINDOW_GetWindow(), 0x200, 0, ((unsigned short)sub_00468740() << 16) | (unsigned short)sub_00468730());
}

// 0x00453D90
void __cdecl UI_LoadPlayerUI()
{
    PANEL_LoadPartyCels();
    sub_004A7AA0_InitTextEntryLengths();
    sub_004AA920_LoadPanelCel();
    sub_004A8A30_InitSkillIcons();
    sub_004B8720();
    INV_ResetHover();
    sub_00498E80_ClearPair();
    sub_0048A600();
    sub_004A3050();
    TEXT_LoadPopupHireling();
    sub_00457640(1);
    sub_0047E720_LoadAlwaysRun();
}

// 0x00453DE0
void __cdecl UI_FreePlayerUI()
{
    PANEL_FreePartyCels();
    sub_004A7AD0();
    sub_004AA980();
    sub_004A8C00_FreeSkillIcons();
    TEXT_ClearQuestFlags();
    NPCMENU_ResetNpcMenu();
    sub_004B91F0();
    TEXT_FreeTextLists();
    VIEW_ResetLifeColors();
    if (gpLoadingCell_007A2794)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingCell_007A2794);
        gpLoadingCell_007A2794 = 0;
    }
    if (gpYouDiedHardcoreCel_007A2894)
    {
        ARCHIVE_FreeClientCellFile(gpYouDiedHardcoreCel_007A2894);
        gpYouDiedHardcoreCel_007A2894 = 0;
    }
    if (gpYouDiedInstCel_007A2898)
    {
        ARCHIVE_FreeClientCellFile(gpYouDiedInstCel_007A2898);
        gpYouDiedInstCel_007A2898 = 0;
    }
    sub_0047E750_SaveAlwaysRun();
    sub_00468070_SetCursorItemState(0);
}

// 0x00453E70
const Unicode* __fastcall UI_GetLevelName(int nLevelId)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (pLevelsTxtRecord)
    {
        if (nLevelId == LEVEL_DENOFEVIL)
        {
            if (INV_GetTableByte(0, 1))
            {
                return D2LANG_GetStringFromTblIndex(0x13B8);
            }
            return D2LANG_GetStringFromTblIndex(0x13B7);
        }
        return (const Unicode*)pLevelsTxtRecord->wszLevelName;
    }
    return D2LANG_GetStringFromTblIndex(0x150D);
}

// 0x00453EC0
void __cdecl UI_CancelCursorItemUse()
{
    D2UnitStrc* pUnit = sub_004680A0();
    if (pUnit)
    {
        sub_004786A0_SendDwords2(0x27, pUnit->dwUnitId, pUnit->dwUnitId);
    }
}

// 0x00453FC0
int __cdecl UI_GoldPanelCloseCallback()
{
    UI_CloseGoldDialog();
    return 0;
}

// 0x00453FE0
int __cdecl UI_GoldSpinnerChanged()
{
    const int nDirection = gpGoldControlA_007A27A4->GetDirection();
    const unsigned int nStep = gpGoldControlA_007A27A4->GetStep(0);
    if (gpGoldControlB_007A27A8)
    {
        gnGoldPanelValue_007A2A68 = gpGoldControlB_007A27A8->GetValue();
    }
    unsigned int nValue = gnGoldPanelValue_007A2A68;
    unsigned int nMax;
    if (gnGoldPanelMode_007A279C == 4)
    {
        nMax = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLDBANK, 0);
    }
    else
    {
        nMax = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    }
    if (nDirection == 1)
    {
        nValue += nStep;
        if (nValue > nMax)
        {
            nValue = nMax;
        }
    }
    else if (nDirection == 2)
    {
        if (nStep > nValue)
        {
            nValue = 0;
        }
        else if (nValue)
        {
            nValue -= nStep;
        }
    }
    gnGoldPanelValue_007A2A68 = nValue;
    if (gpGoldControlB_007A27A8)
    {
        gpGoldControlB_007A27A8->SetValue(nValue);
    }
    return 0;
}

// 0x00454790
void __fastcall UI_SetLoadingAct(int nValue)
{
    gdwGlobal_007A288C = nValue;
}

// 0x004547B0
void __fastcall UI_FreeLoadingScreen()
{
    if (gpLoadingScreen_007A2888)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingScreen_007A2888);
        gpLoadingScreen_007A2888 = 0;
        sub_004FB480_SetActA(gdwGlobal_007A288C);
        sub_00600C00_SetActB(gdwGlobal_007A288C);
        AUTOMAP_InitAutomapColors();
        CUNIT_InitColorTable();
        sub_00499E10();
        PANEL_SetBlackColour();
        sub_004AB2F0();
        sub_00497250();
        sub_00497270();
        sub_004972B0();
        sub_00497290();
        sub_00472890(gpGlobal_007A063C);
        GAME_ExtendDelay(0x7D0);
    }
    gdwGlobal_007A2884 = 0;
    gpLoadingScreen_007A2888 = 0;
    gdwGlobal_007A2868 = 0;
}

// 0x00454850
int __cdecl UI_TickElapsed()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastTick_007A313C > 0x32)
    {
        gdwLastTick_007A313C = dwTick;
        return 1;
    }
    return 0;
}

// 0x00454880
int __fastcall UI_GetHoverRect(D2RectStrc* pRect)
{
    pRect->nLeft = 0;
    pRect->nRight = gnGlobal_0071146C;
    pRect->nTop = 0;
    pRect->nBottom = gnGlobal_0071146C;
    if (gaUIVarStates_007A27C0[0x17] || gaUIVarStates_007A27C0[0x19] || gaUIVarStates_007A27C0[0x1A]
        || gaUIVarStates_007A27C0[0x0C] || gaUIVarStates_007A27C0[0x1C] || gaUIVarStates_007A27C0[0x1B])
    {
        return 0;
    }
    if (gaUIVarStates_007A27C0[0x1D] || gaUIVarStates_007A27C0[0x16] || gaUIVarStates_007A27C0[0x02]
        || gaUIVarStates_007A27C0[0x0F] || gaUIVarStates_007A27C0[0x24] || gaUIVarStates_007A27C0[0x25]
        || gaUIVarStates_007A27C0[0x14])
    {
        pRect->nLeft = gnGlobal_0071146C / 2;
    }
    if (gaUIVarStates_007A27C0[0x01] || gaUIVarStates_007A27C0[0x04])
    {
        pRect->nRight = gnGlobal_0071146C / 2;
    }
    return pRect->nLeft != pRect->nRight;
}

// 0x00455F20
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg)
{
    D2_ASSERT(nUIVar < 0x26, 0x13FB);
    D2_ASSERT(nState <= 2, 0x13FC);
    const int nOldState = gaUIVarStates_007A27C0[nUIVar];
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        if (nUIVar == 0x23 || nUIVar == 0x24 || nUIVar == 0x25)
        {
            return 0;
        }
    }
    if (!UI_CanSetUIVar(nUIVar, nState))
    {
        return 0;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    switch (nState)
    {
    case 0:
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
        {
            gaUIVarStates_007A27C0[nUIVar] = 1;
        }
        break;
    case 1:
        gaUIVarStates_007A27C0[nUIVar] = 0;
        break;
    case 2:
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer))
            {
                gaUIVarStates_007A27C0[nUIVar] = !gaUIVarStates_007A27C0[nUIVar];
            }
            else if (nUIVar == 0x05)
            {
                gaUIVarStates_007A27C0[0x05] = !gaUIVarStates_007A27C0[0x05];
            }
        }
        else
        {
            gaUIVarStates_007A27C0[nUIVar] = !gaUIVarStates_007A27C0[nUIVar];
        }
        break;
    }

    const int nNewState = gaUIVarStates_007A27C0[nUIVar];
    if (!nOldState)
    {
        if (nNewState)
        {
            UI_SetPanelHandlers(nUIVar);
            if (nUIVar == 0x05)
            {
                CHAT_ClearChatLine();
            }
        }
    }
    else if (!nNewState)
    {
        sub_00455AE0_CloseUIVar(nUIVar);
    }

    const int nA = sub_00468730();
    const int nB = sub_00468740();
    switch (nUIVar)
    {
    case 14:
        if (nNewState)
        {
            PLAYER_SetPanelSlide(1);
        }
        else
        {
            PLAYER_SetPanelSlide(0);
        }
        break;
    case 12:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 32:
        if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(0);
        }
        break;
    case 11:
        if (!nNewState)
        {
            TEXT_CloseKeyCaptureHandlers();
        }
        break;
    case 1:
        INV_ResetHover();

    case 4:
        if (!gaUIVarStates_007A27C0[2] && !gaUIVarStates_007A27C0[0x14] && !gaUIVarStates_007A27C0[0xF] && !gaUIVarStates_007A27C0[0x10]
            && !gaUIVarStates_007A27C0[0x24] && !gaUIVarStates_007A27C0[0x25] && !gaUIVarStates_007A27C0[0x16])
        {
            if (nNewState)
            {
                PLAYER_SetPanelSlide(1);
                if (nArg && nA > gnGlobal_0071146C / 4)
                {
                    UI_SetCursorPosition(nA - gnGlobal_0071146C / 4, nB);
                }
            }
            else
            {
                PLAYER_SetPanelSlide(0);
                if (nArg && nA < gnGlobal_0071146C / 2)
                {
                    UI_SetCursorPosition(gnGlobal_0071146C / 4 + nA, nB);
                }
            }
        }
        else if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(2);
        }
        break;
    case 2:
    case 15:
    case 16:
    case 20:
    case 22:
    case 36:
    case 37:
        if (!gaUIVarStates_007A27C0[1] && !gaUIVarStates_007A27C0[4])
        {
            if (nNewState)
            {
                PLAYER_SetPanelSlide(2);
                if (nArg && nA < gnGlobal_0071146C - gnGlobal_0071146C / 4)
                {
                    UI_SetCursorPosition(gnGlobal_0071146C / 4 + nA, nB);
                }
            }
            else
            {
                PLAYER_SetPanelSlide(0);
                if (nArg && nA > gnGlobal_0071146C / 2)
                {
                    UI_SetCursorPosition(nA - gnGlobal_0071146C / 4, nB);
                }
            }
        }
        else if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(1);
        }
        break;
    }
    return 1;
}

// 0x00456D80
void __cdecl UI_ShutdownUI()
{
    const int nPrevState = gaUIVarStates_007A27C0[0];
    if (FOG_IsExpansion())
    {
        GAME_IsExpansion();
    }
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    sub_00463DD0_GetPlayerUnit();
    gaUIVarStates_007A27C0[0] = 0;
    if (nPrevState)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gtPanelHandlers_006D5F28, 4);
    }
    sub_00468730();
    sub_00468740();
    HIREABLES_FreePanelCels();
    if (sub_00463DD0_GetPlayerUnit())
    {
        sub_004A8C00_FreeSkillIcons();
        sub_004AA980();
    }
    D2Win_10116();
    TEXT_FreeTextResources();
    sub_0047F130_SaveMiniPanel();
    HIREABLES_FreeHelpCels();
    TEXT_FreeLevelCels();
    HIREABLES_FreeHirelingIcons();
    NPCMENU_FreeNpcMenu();
    AUTOMAP_FreeAutomap();
    sub_0049C700_CloseWaypointPanel();
    sub_004B91F0();
    UI_CloseGoldDialog();
    sub_00486980();
    USEITEM_FreeUseItemPanel();
    TEXT_FreeQuestPanel();
    sub_004892F0();
    DIALOG_FreeDialogs();
    sub_004BE060();
    if (gpPentspinCel_007A2878)
    {
        ARCHIVE_FreeClientCellFile(gpPentspinCel_007A2878);
        gpPentspinCel_007A2878 = 0;
    }
    if (gpFocus16Cel_007A2880)
    {
        ARCHIVE_FreeClientCellFile(gpFocus16Cel_007A2880);
        gpFocus16Cel_007A2880 = 0;
    }
    if (gpBoxPiecesCel_007A2798)
    {
        ARCHIVE_FreeClientCellFile(gpBoxPiecesCel_007A2798);
        gpBoxPiecesCel_007A2798 = 0;
    }
    if (gpBuySellButton_007A287C)
    {
        ARCHIVE_FreeClientCellFile(gpBuySellButton_007A287C);
        gpBuySellButton_007A287C = 0;
    }
    if (gpLoadingCell_007A2794)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingCell_007A2794);
        gpLoadingCell_007A2794 = 0;
    }
    CMDTBL_DisableHotkeyHandlers();
    sub_0047DFD0_FreeOptionMenus();
    TEXT_FreeTextSliderCel();
}

// 0x00456300
int __fastcall UI_CloseUIVars(int bArg1, int nArg2)
{
    int bResult = 0;
    for (int i = 0; i < 0x26; i++)
    {
        if (gaUIVarStates_007A27C0[i] == 1 && (gaUIVarDefaults_006D6378[i] == 1 || (bArg1 && i == 0x0A)))
        {
            sub_00455F20(i, 1, nArg2);
            bResult = 1;
            if (i == 0x19 || i == 1)
            {
                INV_ResetHover();
            }
        }
    }
    return bResult;
}

#include "gen/data/Source/D2Client/UI/ui_00453910.inc"
