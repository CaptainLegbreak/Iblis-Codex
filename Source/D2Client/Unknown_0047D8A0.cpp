#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"

struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C
extern D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __fastcall sub_0047DF00_FreeOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries); // 0x0047DF00
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __cdecl sub_0044BE90(); // 0x0044BE90
int __cdecl sub_0044DB30(); // 0x0044DB30
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_004979E0(); // 0x004979E0
int __cdecl sub_004979F0(); // 0x004979F0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
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
extern int gaSlotState_007BC8F8[]; // 0x007BC8F8
extern int gbPanelFlag_0071315C; // 0x0071315C
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470

static int gnOptionSelected_007BC938; // 0x007BC938

// 0x0047D8A0
void __stdcall sub_0047D8A0_SelectNextOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        ++gnOptionSelected_007BC938;
        if (gnOptionSelected_007BC938 > gpOptionHeader_007BC93C->nCount - 1)
        {
            gnOptionSelected_007BC938 = 0;
        }
    }
    while (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind == -1
        || gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled && !gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled());
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
        --gnOptionSelected_007BC938;
        if (gnOptionSelected_007BC938 < 0)
        {
            gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
        }
    }
    while (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind == -1
        || gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled && !gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void* gpOptionCel_007BC950; // 0x007BC950

void* gpOptionCel_007BC954; // 0x007BC954

void* gpOptionCel_007BC958; // 0x007BC958

int gdwGlobal_007BC968; // 0x007BC968

int gdwGlobal_007BC96C; // 0x007BC96C

int gdwGlobal_007BC978; // 0x007BC978

void* gpCellFile_007BC960; // 0x007BC960

void* gpSlotCells_007BC964; // 0x007BC964

// 0x0047DFD0
void __cdecl sub_0047DFD0_FreeOptionMenus()
{
    gpOptionHeader_007BC93C = 0;
    gpOptionEntries_007BC940 = 0;
    sub_0047DF00_FreeOptionCels(&gOptionHeader_00714224, gaOptionEntries_00715CC8);
    sub_0047DF00_FreeOptionCels(&gOptionHeader_00714210, gaOptionEntries_00714238);
    sub_0047DF00_FreeOptionCels(&gOptionHeader_00713044, gaOptionEntries_00713220);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0047DF00_FreeOptionCels(&gOptionHeader_0071875C, gaOptionEntries_0071ACA0);
        sub_0047DF00_FreeOptionCels(&gOptionHeader_0071D734, gaOptionEntries_0071F728);
    }
    else
    {
        sub_0047DF00_FreeOptionCels(&gOptionHeader_00718748, gaOptionEntries_00718770);
        sub_0047DF00_FreeOptionCels(&gOptionHeader_0071D720, gaOptionEntries_0071D748);
    }
    if (gpOptionCel_007BC950)
    {
        sub_00478A00(gpOptionCel_007BC950);
        gpOptionCel_007BC950 = 0;
    }
    if (gpOptionCel_007BC954)
    {
        sub_00478A00(gpOptionCel_007BC954);
        gpOptionCel_007BC954 = 0;
    }
    if (gpOptionCel_007BC958)
    {
        sub_00478A00(gpOptionCel_007BC958);
        gpOptionCel_007BC958 = 0;
    }
}

// 0x0047E750
void __cdecl sub_0047E750_SaveAlwaysRun()
{
    SRegSaveValue("Diablo II", "Always Run", 0, sub_0044BE90());
}

// 0x0047EA60
int __cdecl sub_0047EA60_IsAnyPanelOpen()
{
    int bResult = 0;
    if (sub_004538D0(0x17) || sub_004538D0(0x19) || sub_004538D0(0x1A) || sub_004538D0(0xC)
        || sub_004538D0(0x1C) || sub_004538D0(0x1D) || sub_004538D0(0x18) || sub_004538D0(3)
        || sub_004538D0(0x10) || sub_004538D0(0x16) || sub_004538D0(0x24) || sub_004538D0(2)
        || sub_004538D0(0xF) || sub_004538D0(0x14) || sub_004538D0(0x1B))
    {
        bResult = 1;
    }
    gdwGlobal_007BC96C = bResult;
    if (sub_004538D0(0x24))
    {
        bResult = 1;
        gdwGlobal_007BC96C = bResult;
    }
    return bResult;
}

// 0x0047EB50
int __cdecl sub_0047EB50_IsAnyLeftPanelOpen()
{
    int bResult = 0;
    if (sub_004538D0(0x17) || sub_004538D0(0x19) || sub_004538D0(0x1C) || sub_004538D0(0x1A)
        || sub_004538D0(0xC) || sub_004538D0(0x18) || sub_004538D0(0x1B) || sub_004538D0(3))
    {
        bResult = 1;
        gdwGlobal_007BC968 = bResult;
    }
    if ((sub_004538D0(0x1F) || sub_004979E0()) && sub_004979F0() > 1)
    {
        bResult = 1;
        gdwGlobal_007BC968 = bResult;
    }
    if (sub_004538D0(1) || sub_004538D0(4))
    {
        bResult = 1;
        gdwGlobal_007BC968 = bResult;
    }
    else
    {
        gdwGlobal_007BC968 = 0;
    }
    return bResult;
}

// 0x0047F0C0
void __cdecl sub_0047F0C0_LoadMiniPanel()
{
    if (sub_0044DB30())
    {
        gpCellFile_007BC960 = sub_004520C0_LoadUiCelFile("Panel\\minipanel");
        gdwGlobal_007BC978 = 0;
    }
    else
    {
        gpCellFile_007BC960 = sub_004520C0_LoadUiCelFile("Panel\\minipanel_s");
        gdwGlobal_007BC978 = 1;
    }
    gpSlotCells_007BC964 = sub_004520C0_LoadUiCelFile("Panel\\minipanelbtn");
    int nSlots = 8;
    if (gdwGlobal_007BC978)
        nSlots = 7;
    for (int i = 0; i < nSlots; i++)
        gaSlotState_007BC8F8[i] = 0;
}

// 0x0047F130
void __cdecl sub_0047F130_SaveMiniPanel()
{
    int bValue = 0;
    if (!gbPanelFlag_0071315C)
        bValue = 1;
    SRegSaveValue("Diablo II", "Mini Panel", 1, bValue);
    if (gpCellFile_007BC960)
    {
        sub_00478A00(gpCellFile_007BC960);
        gpCellFile_007BC960 = 0;
    }
    if (gpSlotCells_007BC964)
    {
        sub_00478A00(gpSlotCells_007BC964);
        gpSlotCells_007BC964 = 0;
    }
}

// 0x0047F190
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY)
{
    const int nHalfWidth = gnGlobal_0071146C / 2;
    if (nX > nHalfWidth - 0x4A && nX < nHalfWidth + 0x47 && nY < gnGlobal_00711470 - 0x32 && nY > gnGlobal_00711470 - 0x45)
        return 1;
    return 0;
}

// 0x0047F210
int __cdecl sub_0047F210_IsMouseInSlots()
{
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (sub_004538D0(0x14) && sub_004538D0(0x15))
    {
        const int bSmallPanel = gdwGlobal_007BC978;
        int nLeft = gnGlobal_0071146C / 2;
        if (bSmallPanel)
            nLeft += 0x38;
        else
            nLeft += 0x23;
        const int nBottom = gnGlobal_00711470 - 0x32;
        int nSlots = 8;
        if (bSmallPanel)
            nSlots = 7;
        if (nX > nLeft && nX < nLeft + nSlots * 20 && nY > nBottom - 0x1A && nY < nBottom)
            return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_0047D8A0.inc"
