#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CellFileStrc;
struct D2MsgHandlerEntryStrc;
struct D2RectStrc;
struct D2UiControlAStrc;
struct D2UiControlBStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef unsigned short Unicode;


struct D2LevelsTxt
{
    char unk0x000[0x16E];
    Unicode wszLevelName[40];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_0044DB40(int nDelay); // 0x0044DB40
int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __fastcall sub_00451E10_RegisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
void __cdecl sub_00453EE0_ClosePanel(); // 0x00453EE0
void __fastcall sub_00457640(int bForce); // 0x00457640
void __cdecl sub_0045A5C0_FreeAutomap(); // 0x0045A5C0
void __cdecl sub_0045A620_InitAutomapColors(); // 0x0045A620
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl sub_0046ACB0_DisableHotkeyHandlers(); // 0x0046ACB0
void __fastcall sub_00472890(D2DrlgActStrc* pAct); // 0x00472890
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __cdecl sub_0047DFD0_FreeOptionMenus(); // 0x0047DFD0
void __cdecl sub_0047E720_LoadAlwaysRun(); // 0x0047E720
void __cdecl sub_0047E750_SaveAlwaysRun(); // 0x0047E750
void __cdecl sub_0047F130_SaveMiniPanel(); // 0x0047F130
void __cdecl sub_00483960(); // 0x00483960
void __cdecl sub_00486980(); // 0x00486980
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __cdecl sub_004892F0(); // 0x004892F0
void __cdecl sub_0048A600(); // 0x0048A600
void __cdecl sub_00492EC0_FreeHirelingIcons(); // 0x00492EC0
void __cdecl sub_00492F90(); // 0x00492F90
void __cdecl sub_004939B0_LoadPopupHireling(); // 0x004939B0
void __cdecl sub_00494EE0_FreeHelpCels(); // 0x00494EE0
void __cdecl sub_00496990_FreePanelCels(); // 0x00496990
void __cdecl sub_00498E80_ClearPair(); // 0x00498E80
void __cdecl sub_00499E30_SetBlackColour(); // 0x00499E30
void __cdecl sub_0049C0A0_LoadPartyCels(); // 0x0049C0A0
void __cdecl sub_0049C0F0_FreePartyCels(); // 0x0049C0F0
void __cdecl sub_0049C700_CloseWaypointPanel(); // 0x0049C700
void __cdecl sub_004A0010_FreeTextLists(); // 0x004A0010
void __cdecl sub_004A0680_FreeTextResources(); // 0x004A0680
void __cdecl sub_004A2600_FreeQuestPanel(); // 0x004A2600
void __cdecl sub_004A3020_ClearQuestFlags(); // 0x004A3020
void __cdecl sub_004A3050(); // 0x004A3050
void __cdecl sub_004A51E0_FreeCelFile(); // 0x004A51E0
void __cdecl sub_004A6480_FreeLevelCels(); // 0x004A6480
void __cdecl sub_004A7AA0_InitTextEntryLengths(); // 0x004A7AA0
void __cdecl sub_004A7AD0(); // 0x004A7AD0
void __cdecl sub_004A8A30_InitSkillIcons(); // 0x004A8A30
void __cdecl sub_004A8C00_FreeSkillIcons(); // 0x004A8C00
void __cdecl sub_004AA920_LoadPanelCel(); // 0x004AA920
void __cdecl sub_004AA980(); // 0x004AA980
void __cdecl sub_004B24A0(); // 0x004B24A0
void __cdecl sub_004B32F0(); // 0x004B32F0
void __cdecl sub_004B7B50(); // 0x004B7B50
void __cdecl sub_004B8720(); // 0x004B8720
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex); // 0x004B92E0
void __cdecl sub_004B91F0(); // 0x004B91F0
void __cdecl sub_004BE060(); // 0x004BE060
void __cdecl sub_004C0100(); // 0x004C0100
void* __cdecl sub_004F59A0(); // 0x004F59A0
void __cdecl sub_005015F0(); // 0x005015F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern int gnGlobal_0071146C; // 0x0071146C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[]; // 0x006D5F28
extern D2DrlgActStrc* gpGlobal_007A063C; // 0x007A063C
extern unsigned long gdwUIVarTick_007A2790; // 0x007A2790
extern D2CellFileStrc* gpLoadingCell_007A2794; // 0x007A2794
extern int gaUIVarStates_007A27C0[]; // 0x007A27C0
extern int gdwGlobal_007A2868; // 0x007A2868
extern D2CellFileStrc* gpBuySellButton_007A287C; // 0x007A287C
extern D2CellFileStrc* gpLoadingScreen_007A2888; // 0x007A2888
extern D2CellFileStrc* gpYouDiedHardcoreCel_007A2894; // 0x007A2894
extern D2CellFileStrc* gpYouDiedInstCel_007A2898; // 0x007A2898

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

D2CellFileStrc* gpBoxPiecesCel_007A2798; // 0x007A2798

D2CellFileStrc* gpPentspinCel_007A2878; // 0x007A2878

D2CellFileStrc* gpFocus16Cel_007A2880; // 0x007A2880

int gdwGlobal_007A2884; // 0x007A2884

int gdwGlobal_007A288C; // 0x007A288C

unsigned long gdwLastTick_007A313C; // 0x007A313C

// 0x00453A90
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar)
{
    return gaUIVarStates_007A27C0[nUIVar];
}

// 0x00453AE0
void __cdecl sub_00453AE0()
{
    if (gdwGlobal_0070FA9C)
    {
        gdwUIVarTick_007A2790 = GetTickCount() + 0x64;
    }
}

// 0x00453B00
void __cdecl sub_00453B00_SendMouseMove()
{
    SendMessageA(sub_004F59A0(), 0x200, 0, ((unsigned short)sub_00468740() << 16) | (unsigned short)sub_00468730());
}

// 0x00453D90
void __cdecl sub_00453D90_RunSequenceA()
{
    sub_0049C0A0_LoadPartyCels();
    sub_004A7AA0_InitTextEntryLengths();
    sub_004AA920_LoadPanelCel();
    sub_004A8A30_InitSkillIcons();
    sub_004B8720();
    sub_00487990_ResetHover();
    sub_00498E80_ClearPair();
    sub_0048A600();
    sub_004A3050();
    sub_004939B0_LoadPopupHireling();
    sub_00457640(1);
    sub_0047E720_LoadAlwaysRun();
}

// 0x00453DE0
void __cdecl sub_00453DE0()
{
    sub_0049C0F0_FreePartyCels();
    sub_004A7AD0();
    sub_004AA980();
    sub_004A8C00_FreeSkillIcons();
    sub_004A3020_ClearQuestFlags();
    sub_004B32F0();
    sub_004B91F0();
    sub_004A0010_FreeTextLists();
    sub_00492F90();
    if (gpLoadingCell_007A2794)
    {
        sub_00478A00(gpLoadingCell_007A2794);
        gpLoadingCell_007A2794 = 0;
    }
    if (gpYouDiedHardcoreCel_007A2894)
    {
        sub_00478A00(gpYouDiedHardcoreCel_007A2894);
        gpYouDiedHardcoreCel_007A2894 = 0;
    }
    if (gpYouDiedInstCel_007A2898)
    {
        sub_00478A00(gpYouDiedInstCel_007A2898);
        gpYouDiedInstCel_007A2898 = 0;
    }
    sub_0047E750_SaveAlwaysRun();
    sub_00468070_SetCursorItemState(0);
}

// 0x00453E70
const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (pLevelsTxtRecord)
    {
        if (nLevelId == 8)
        {
            if (sub_004B92E0_GetTableByte(0, 1))
            {
                return D2LANG_GetStringFromTblIndex(0x13B8);
            }
            return D2LANG_GetStringFromTblIndex(0x13B7);
        }
        return pLevelsTxtRecord->wszLevelName;
    }
    return D2LANG_GetStringFromTblIndex(0x150D);
}

// 0x00453EC0
void __cdecl sub_00453EC0()
{
    D2UnitStrc* pUnit = sub_004680A0();
    if (pUnit)
    {
        sub_004786A0_SendIntInt(0x27, pUnit->dwUnitId, pUnit->dwUnitId);
    }
}

// 0x00454790
void __fastcall sub_00454790_SetValue(int nValue)
{
    gdwGlobal_007A288C = nValue;
}

// 0x004547B0
void __fastcall sub_004547B0()
{
    if (gpLoadingScreen_007A2888)
    {
        sub_00478A00(gpLoadingScreen_007A2888);
        gpLoadingScreen_007A2888 = 0;
        sub_004FB480_SetActA(gdwGlobal_007A288C);
        sub_00600C00_SetActB(gdwGlobal_007A288C);
        sub_0045A620_InitAutomapColors();
        sub_00483960();
        sub_00499E10();
        sub_00499E30_SetBlackColour();
        sub_004AB2F0();
        sub_00497250();
        sub_00497270();
        sub_004972B0();
        sub_00497290();
        sub_00472890(gpGlobal_007A063C);
        sub_0044DB40(0x7D0);
    }
    gdwGlobal_007A2884 = 0;
    gpLoadingScreen_007A2888 = 0;
    gdwGlobal_007A2868 = 0;
}

// 0x00454850
int __cdecl sub_00454850_TickElapsed()
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
int __fastcall sub_00454880_GetHoverRect(D2RectStrc* pRect)
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

// 0x00456D80
void __cdecl sub_00456D80_ShutdownUI()
{
    const int nPrevState = gaUIVarStates_007A27C0[0];
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0044DCC0();
    }
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    sub_00463DD0_GetPlayerUnit();
    gaUIVarStates_007A27C0[0] = 0;
    if (nPrevState)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F28, 4);
    }
    sub_00468730();
    sub_00468740();
    sub_00496990_FreePanelCels();
    if (sub_00463DD0_GetPlayerUnit())
    {
        sub_004A8C00_FreeSkillIcons();
        sub_004AA980();
    }
    sub_005015F0();
    sub_004A0680_FreeTextResources();
    sub_0047F130_SaveMiniPanel();
    sub_00494EE0_FreeHelpCels();
    sub_004A6480_FreeLevelCels();
    sub_00492EC0_FreeHirelingIcons();
    sub_004B24A0();
    sub_0045A5C0_FreeAutomap();
    sub_0049C700_CloseWaypointPanel();
    sub_004B91F0();
    sub_00453EE0_ClosePanel();
    sub_00486980();
    sub_004C0100();
    sub_004A2600_FreeQuestPanel();
    sub_004892F0();
    sub_004B7B50();
    sub_004BE060();
    if (gpPentspinCel_007A2878)
    {
        sub_00478A00(gpPentspinCel_007A2878);
        gpPentspinCel_007A2878 = 0;
    }
    if (gpFocus16Cel_007A2880)
    {
        sub_00478A00(gpFocus16Cel_007A2880);
        gpFocus16Cel_007A2880 = 0;
    }
    if (gpBoxPiecesCel_007A2798)
    {
        sub_00478A00(gpBoxPiecesCel_007A2798);
        gpBoxPiecesCel_007A2798 = 0;
    }
    if (gpBuySellButton_007A287C)
    {
        sub_00478A00(gpBuySellButton_007A287C);
        gpBuySellButton_007A287C = 0;
    }
    if (gpLoadingCell_007A2794)
    {
        sub_00478A00(gpLoadingCell_007A2794);
        gpLoadingCell_007A2794 = 0;
    }
    sub_0046ACB0_DisableHotkeyHandlers();
    sub_0047DFD0_FreeOptionMenus();
    sub_004A51E0_FreeCelFile();
}

// 0x00453FC0
int __cdecl sub_00453FC0_GoldPanelClose()
{
    sub_00453EE0_ClosePanel();
    return 0;
}

// 0x00453FE0
int __cdecl sub_00453FE0_GoldSpinnerChanged()
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
