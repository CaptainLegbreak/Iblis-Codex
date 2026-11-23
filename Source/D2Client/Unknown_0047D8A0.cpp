#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"

struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern D2OptionHeaderStrc* gpOptionHeader; // 0x007BC93C
extern D2OptionEntryStrc* gpOptionEntries; // 0x007BC940
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __fastcall sub_0047DF00_FreeOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries); // 0x0047DF00
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90
int __cdecl GAME_GetConnectionType(); // 0x0044DB30
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_004979E0(); // 0x004979E0
int __cdecl HIREABLES_GetBeltRowCount(); // 0x004979F0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
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
extern int gaSlotState[]; // 0x007BC8F8
extern int gbPanelFlag; // 0x0071315C
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470

static int gnOptionSelected; // 0x007BC938

// 0x0047D8A0
void __stdcall sub_0047D8A0_SelectNextOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        ++gnOptionSelected;
        if (gnOptionSelected > gpOptionHeader->nCount - 1)
        {
            gnOptionSelected = 0;
        }
    }
    while (gpOptionEntries[gnOptionSelected].nKind == -1
        || gpOptionEntries[gnOptionSelected].pfnEnabled && !gpOptionEntries[gnOptionSelected].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D920
void __stdcall sub_0047D920_SelectPreviousOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        --gnOptionSelected;
        if (gnOptionSelected < 0)
        {
            gnOptionSelected = gpOptionHeader->nCount - 1;
        }
    }
    while (gpOptionEntries[gnOptionSelected].nKind == -1
        || gpOptionEntries[gnOptionSelected].pfnEnabled && !gpOptionEntries[gnOptionSelected].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void* gpSliderDisabledCel; // 0x007BC950

void* gpSliderEnabledCel; // 0x007BC954

void* gpSliderKnobCel; // 0x007BC958

int gbAnyLeftPanelOpen; // 0x007BC968

int gbAnyPanelOpen; // 0x007BC96C

int gbSmallPanel; // 0x007BC978

void* gpMiniPanelCel; // 0x007BC960

void* gpSlotCells; // 0x007BC964

// 0x0047DFD0
void __cdecl sub_0047DFD0_FreeOptionMenus()
{
    gpOptionHeader = 0;
    gpOptionEntries = 0;
    sub_0047DF00_FreeOptionCels(&gtSoundOptionHeader, gaSoundOptionEntries);
    sub_0047DF00_FreeOptionCels(&gtOptionsHeader, gaOptionsEntries);
    sub_0047DF00_FreeOptionCels(&gtMainOptionHeader, gaMainOptionEntries);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        sub_0047DF00_FreeOptionCels(&gtVideoResOptionHeader, gaVideoResOptionEntries);
        sub_0047DF00_FreeOptionCels(&gtAutomapModeOptionHeader, gaAutomapModeOptionEntries);
    }
    else
    {
        sub_0047DF00_FreeOptionCels(&gtVideoOptionHeader, gaVideoOptionEntries);
        sub_0047DF00_FreeOptionCels(&gtAutomapOptionHeader, gaAutomapOptionEntries);
    }
    if (gpSliderDisabledCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderDisabledCel);
        gpSliderDisabledCel = 0;
    }
    if (gpSliderEnabledCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderEnabledCel);
        gpSliderEnabledCel = 0;
    }
    if (gpSliderKnobCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderKnobCel);
        gpSliderKnobCel = 0;
    }
}

// 0x0047E750
void __cdecl sub_0047E750_SaveAlwaysRun()
{
    SRegSaveValue("Diablo II", "Always Run", 0, GAME_GetAlwaysRun());
}

// 0x0047EA60
int __cdecl sub_0047EA60_IsAnyPanelOpen()
{
    int bResult = 0;
    if (GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0x1A) || GAME_GetUIVarState(0xC)
        || GAME_GetUIVarState(0x1C) || GAME_GetUIVarState(0x1D) || GAME_GetUIVarState(0x18) || GAME_GetUIVarState(3)
        || GAME_GetUIVarState(0x10) || GAME_GetUIVarState(0x16) || GAME_GetUIVarState(0x24) || GAME_GetUIVarState(2)
        || GAME_GetUIVarState(0xF) || GAME_GetUIVarState(0x14) || GAME_GetUIVarState(0x1B))
    {
        bResult = 1;
    }
    gbAnyPanelOpen = bResult;
    if (GAME_GetUIVarState(0x24))
    {
        bResult = 1;
        gbAnyPanelOpen = bResult;
    }
    return bResult;
}

// 0x0047EB50
int __cdecl sub_0047EB50_IsAnyLeftPanelOpen()
{
    int bResult = 0;
    if (GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0x1C) || GAME_GetUIVarState(0x1A)
        || GAME_GetUIVarState(0xC) || GAME_GetUIVarState(0x18) || GAME_GetUIVarState(0x1B) || GAME_GetUIVarState(3))
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    if ((GAME_GetUIVarState(0x1F) || sub_004979E0()) && HIREABLES_GetBeltRowCount() > 1)
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    if (GAME_GetUIVarState(1) || GAME_GetUIVarState(4))
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    else
    {
        gbAnyLeftPanelOpen = 0;
    }
    return bResult;
}

// 0x0047F0C0
void __cdecl sub_0047F0C0_LoadMiniPanel()
{
    if (GAME_GetConnectionType())
    {
        gpMiniPanelCel = sub_004520C0_LoadUiCelFile("Panel\\minipanel");
        gbSmallPanel = 0;
    }
    else
    {
        gpMiniPanelCel = sub_004520C0_LoadUiCelFile("Panel\\minipanel_s");
        gbSmallPanel = 1;
    }
    gpSlotCells = sub_004520C0_LoadUiCelFile("Panel\\minipanelbtn");
    int nSlots = 8;
    if (gbSmallPanel)
        nSlots = 7;
    for (int i = 0; i < nSlots; i++)
        gaSlotState[i] = 0;
}

// 0x0047F130
void __cdecl sub_0047F130_SaveMiniPanel()
{
    int bValue = 0;
    if (!gbPanelFlag)
        bValue = 1;
    SRegSaveValue("Diablo II", "Mini Panel", 1, bValue);
    if (gpMiniPanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpMiniPanelCel);
        gpMiniPanelCel = 0;
    }
    if (gpSlotCells)
    {
        ARCHIVE_FreeClientCellFile(gpSlotCells);
        gpSlotCells = 0;
    }
}

// 0x0047F190
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY)
{
    const int nHalfWidth = gnScreenWidth / 2;
    if (nX > nHalfWidth - 0x4A && nX < nHalfWidth + 0x47 && nY < gnScreenHeight - 0x32 && nY > gnScreenHeight - 0x45)
        return 1;
    return 0;
}

// 0x0047F210
int __cdecl sub_0047F210_IsMouseInSlots()
{
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (GAME_GetUIVarState(0x14) && GAME_GetUIVarState(0x15))
    {
        const int bSmallPanel = gbSmallPanel;
        int nLeft = gnScreenWidth / 2;
        if (bSmallPanel)
            nLeft += 0x38;
        else
            nLeft += 0x23;
        const int nBottom = gnScreenHeight - 0x32;
        int nSlots = 8;
        if (bSmallPanel)
            nSlots = 7;
        if (nX > nLeft && nX < nLeft + nSlots * 20 && nY > nBottom - 0x1A && nY < nBottom)
            return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_0047D8A0.inc"
