#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

struct D2SliderButtonStrc;

struct D2Record42Strc;

struct Unicode;

struct UnicodeChar;

struct D2QuestTextLineStrc;

struct D2QuestTextBufferStrc;

struct D2QuestPanelEntryStrc;

struct D2QuestSlotRectStrc;

struct D2AiControlStrc;

struct D2AiTickParamStrc;

struct D2HotkeyActionStrc;

struct D2MsgHandlerEntryStrc;

struct D2CharStatsTxt;

struct D2MonStatsTxt;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __cdecl sub_00463DF0();

unsigned char __cdecl sub_00483350_IsCinematicBusy();

void __cdecl sub_004A2300_UpdateQuestPage();

void __cdecl sub_004A23D0_LoadPanelCels();

int __stdcall sub_004A26B0_OpenPanel(int nArg);

int __cdecl sub_004A1760_Forward();

void __stdcall sub_004A3220(int nPage, int nArg);

void __fastcall sub_00478590(char nValue);

#pragma pack(push, 2)

struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};

#pragma pack(pop)

extern unsigned char gbFlag_007BF2B0; // 0x007BF2B0

extern D2Record42Strc gtRecord_007BF355; // 0x007BF355

extern int gnPage_007C0255; // 0x007C0255

extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8

int gaPressed_007C0288[7]; // 0x007C0288

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    UnicodeChar wszText[300];
};

struct D2QuestTextBufferStrc
{
    unsigned char pHead[0x106];
    D2QuestTextLineStrc pLines[6];

    D2QuestTextBufferStrc();
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 1)

struct D2QuestPanelEntryStrc
{
    int nQuestId;
    char unk0x004[0x25E - 0x004];
    unsigned short wTextId;
    unsigned char nSlot;
    char unk0x261[0x263 - 0x261];
    unsigned char bEnabled;
    char unk0x264[0x265 - 0x264];
    int bDone;
    char unk0x269[0x26A - 0x269];
};

#pragma pack(pop)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall sub_004A3FE0(int nMode);

void __cdecl sub_0044DA70(); // 0x0044DA70

void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320

void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern D2QuestSlotRectStrc gaQuestSlots_00723EB0[]; // 0x00723EB0

extern int gnQuestCount_007BF2A0; // 0x007BF2A0

extern char gbGlobal_007BF2B0; // 0x007BF2B0

extern char gbGlobal_007BF2B3; // 0x007BF2B3

extern D2QuestPanelEntryStrc gaQuestEntries_007BF3AA[]; // 0x007BF3AA

extern char gbGlobal_007C025D; // 0x007C025D

extern char gbGlobal_007C025E; // 0x007C025E

extern char gbGlobal_007C025F; // 0x007C025F

extern char gbGlobal_007C0260; // 0x007C0260

extern int gnAutomapHeight_007A521C; // 0x007A521C

static int gnEntryCount_007C0274; // 0x007C0274

int __cdecl sub_004A44C0_GetMaxFirstEntry(); // 0x004A44C0

extern int gnThumbScale_007C0278; // 0x007C0278

int gnFirstVisible_007C02AC; // 0x007C02AC

int gnThumbY_007C02CC; // 0x007C02CC

#pragma pack(push, 2)

struct D2ClientListEntryStrc
{
    int nId;
    unsigned char unk0x04[6];
};

#pragma pack(pop)

int __cdecl sub_0044DA30(); // 0x0044DA30

extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10(); // 0x0044DCE0

extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0(); // 0x0044DD20

void __cdecl sub_00466FE0(); // 0x00466FE0

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __cdecl sub_00469D20_SaveHotkeys(); // 0x00469D20

void __cdecl sub_004A43E0(); // 0x004A43E0

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern int gnGlobal_007C0280; // 0x007C0280

static int gnGlobal_007C02B0; // 0x007C02B0

int gnGlobal_007C02B8; // 0x007C02B8

int gnGlobal_007C0284; // 0x007C0284

int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90

int __stdcall sub_B05_Sink(int nA, int nB);

int __fastcall sub_0040C720_ReleaseReferences(int nArg); // 0x0040C720

void __fastcall sub_00469A60_ResetKeyConfig(int nArg); // 0x00469A60

void __fastcall sub_00478A00(void* pCel); // 0x00478A00

extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB

struct D2HotkeyActionStrc
{
    char unk0x00[0x0A];
    short nValue0A;
    char unk0x0C[0x0C];
    int nState18;
    int nState1C;
};

extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

int __cdecl sub_004F59A0(); // 0x004F59A0

extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[]; // 0x0072478C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0

int __cdecl sub_00466DC0(); // 0x00466DC0

int __cdecl sub_0044DCA0_GetGameType(); // 0x0044DCA0

int __cdecl sub_0044DCC0(); // 0x0044DCC0

static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY);

int gnGlobal_007BF298; // 0x007BF298

#pragma pack(push, 2)

#pragma pack(pop)

int __stdcall sub_004A4780_IsAbovePanelLine(int nX); // 0x004A4780

extern int gnThumbRange_007C027C; // 0x007C027C

int gnDragThumbY_007C02A4; // 0x007C02A4

int gnDragMouseY_007C02A8; // 0x007C02A8

unsigned long gdwLastTick_007C02C0; // 0x007C02C0

int __fastcall sub_004538D0(unsigned int); // 0x004538D0

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall sub_004A6580_IsInPanelButton(int, int, int); // 0x004A6580

int __cdecl sub_004A65E0_IsMouseOnLeftButton(); // 0x004A65E0

void __fastcall sub_004B9A00_ChangeUiState(int, int, int, int, int); // 0x004B9A00

void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS*); // 0x00467F20

int __cdecl sub_004B3470_IsNpcQuestActive(); // 0x004B3470

extern int gnPressed_007C02E4; // 0x007C02E4

int __fastcall sub_004A6630_IsInRightPanelButton(int, int, int); // 0x004A6630

int __cdecl sub_004A6690_IsMouseOnRightButton(); // 0x004A6690

extern int gnPressed_007C02E8; // 0x007C02E8

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __cdecl sub_00466DD0(); // 0x00466DD0

void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int nArg); // 0x00622720

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

void __fastcall sub_004A4500_ScrollList(int nStep);

#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5

#pragma pack(push, 2)

#pragma pack(pop)

void __cdecl sub_00469D40_SaveAndBindHotkeys(); // 0x00469D40

void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200

void __fastcall sub_0047E090(int bSaveState, int nMenu); // 0x0047E090

extern int global_00724728; // 0x00724728

enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0

bool __stdcall sub_004A6A00_CheckUiVars(int nArg); // 0x004A6A00

bool __stdcall sub_004A6D50_CheckUiVars(int nArg); // 0x004A6D50

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0

void* gpGlobal_007C02DC; // 0x007C02DC

void* gpGlobal_007C02E0; // 0x007C02E0

int gnGlobal_007C02E4; // 0x007C02E4

int gnGlobal_007C02E8; // 0x007C02E8

void __fastcall sub_004A45C0_MoveSelection(int nStep);

char gbGlobal_007BF2B2; // 0x007BF2B2

char gbGlobal_007BF2B4; // 0x007BF2B4

void* gpCelFile_007C02BC; // 0x007C02BC

static int sub_004A4720_GetLineAt(int nY);


static int sub_004A47F0_IsInList(int nX, int nY);

static int sub_004A4860_IsOnUpArrow(int nX, int nY);

static int sub_004A48B0_IsOnDownArrow(int nX, int nY);

static int sub_004A4900_IsAboveThumb(int nX, int nY);

static int sub_004A4950_IsOnThumb(int nX, int nY);

static int sub_004A49A0_IsBelowThumb(int nX, int nY);

unsigned char gnTextColor_007C02F8; // 0x007C02F8

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

struct D2RectStrc;

struct D2ListScrollStrc;

struct D2ListBoxLineStrc;

class ListBoxImplementation;

struct ListBoxView;

#pragma pack(push, 2)

struct D2ListScrollStrc
{
    int nX;
    int nY;
    int nRows;

    int DrawRows(D2CelContextStrc* pContext);
};

struct D2ListBoxLineStrc
{
    Unicode wszText0[0x400];
    Unicode f_800[0x400];
    Unicode f_1000[0x400];
    Unicode f_1800[0x400];
    Unicode f_2000[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int unk0x3002;
    int nData;
    int nFont;
};

class ListBoxImplementation
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual int sub_004BE910_ScrollUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int sub_004BE990_ScrollDown(SMSGHANDLER_PARAMS* pMsg);
    virtual void Slot09();
    virtual void Slot10();
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual int sub_004BE0A0_GetLineCount();
    virtual void sub_004BE0B0_Clear();

    void sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);               // 0x004BE410

    int unk0x04;
    D2ListBoxLineStrc aLines[0x80];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int f_18074E;
    int unk0x180752;
    int unk0x180756;
    D2ListScrollStrc tBar;
    int nScrollStep;
    int nArg10;
    unsigned int nRepeatTicks;
    int nState;
};

#pragma pack(pop)

typedef char check_line_size[(sizeof(D2ListBoxLineStrc) == 0x300E) ? 1 : -1];

typedef char check_ctx_size[(sizeof(D2CelContextStrc) == 0x48) ? 1 : -1];

void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

int __fastcall sub_004BE340_CountLinesInView(ListBoxImplementation* pListBox); // 0x004BE340

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

extern void* gpCelFile_007C546C; // 0x007C546C

#pragma pack(push, 2)

struct ListBoxView
{
    void* pVtable;
    int unk0x04;
    char aLines[0x180700];
    int nRectX;
    int nRectY;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int bMouseDown;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int nTopIndex;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int nVisibleRows;
    int nThumbStart;
    int nThumbEnd;
    int nX;
    int nY;

    void sub_004BE8D0_Refresh();                                                                            // 0x004BE8D0
    int sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg);
};

#pragma pack(pop)


static int sub_004A4A00_IsOnButton(int nX, int nY);

static int sub_004A4A80_IsOnPressedButton(int nX, int nY);

// 0x004A3FE0
void __fastcall sub_004A3FE0(int nMode)
{
    if (gnGlobal_007BF298 == 0)
    {
        if (GetTickCount() - gnGlobal_007C0259 < 250)
            return;
        if (sub_00463DF0())
            return;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    if (gnGlobal_007BF298 == 1)
    {
        gnGlobal_007BF298 = 0;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    sub_004A26B0_OpenPanel(nMode);
    gnGlobal_007C0259 = GetTickCount();
    sub_004A1760_Forward();
}

// 0x004A40D0
void __fastcall sub_004A40D0_SetRecord(const D2Record42Strc* pRecord)
{
    gtRecord_007BF355 = *pRecord;
    gbFlag_007BF2B0 = 0;
    if (!sub_00483350())
    {
        if (gnState_007BF298 == 2)
        {
            sub_004A23D0_LoadPanelCels();
        }
        sub_004A3220(gnPage_007C0255, 1);
    }
}

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (sub_004A4A00_IsOnButton(nX, nY))
    {
        return sub_004A4A80_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A4260
D2QuestTextBufferStrc::D2QuestTextBufferStrc()
{
}

static unsigned char sub_004A2610_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

static int sub_004A2630_GetSlotAtPoint(int nX, int nY)
{
    int nCount = gnQuestCount_007BF2A0;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots_00723EB0[i].nX && nX < gaQuestSlots_00723EB0[i].nX + 0x38 && nY >= gaQuestSlots_00723EB0[i].nY && nY < gaQuestSlots_00723EB0[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

static unsigned char sub_004A2690_HitTestButtonB(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

static void sub_004A27D0_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (gaQuestEntries_007BF3AA[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries_007BF3AA[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    sub_004A1320_OpenTextPanel(wTextId, 1, 0);
    sub_0049E7E0_SetTextCallback(sub_004A27B0_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

// 0x004A42A0
void __stdcall sub_004A42A0_OnLeftButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) sub_004A3FE0(0);
    }
    else if (!gbGlobal_007BF2B3)
    {
        if (gnIndex_007BF2B5 != -1)
        {
            int nSlot = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nSlot == gnIndex_007BF2B5)
            {
                ganPageSelection_007BF2BD[gnGlobal_007C0255] = nSlot;
                gnIndex_007BF2B9 = nSlot;
            }
        }
        else if (gbGlobal_007BF2B4 == 1)
        {
            if (sub_004A2610_HitTestButtonA(nX, nY) && gnIndex_007BF2B9 != -1)
            {
                sub_004A27D0_OpenQuestDescription(gnIndex_007BF2B9);
            }
        }
    }
    D2_RESET_QUEST_SELECTION();
    if (D2_LOWORD(pMsg->lParam) > gnGlobal_0071146C / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31) return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static __forceinline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static __forceinline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static __forceinline int sub_F08_VisibleLines()
{
    return (sub_F08_LinesBottom() - sub_F08_LinesTop()) / 0x12;
}

// 0x004A44C0
int __cdecl sub_004A44C0_GetMaxFirstEntry()
{
    int nCount = gnEntryCount_007C0274;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

static __forceinline int sub_I18_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static __forceinline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static __forceinline int sub_I18_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

// 0x004A4500
void __fastcall sub_004A4500_ScrollList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A4500_ScrollList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A4500_ScrollList(1);
        return;
    }

    const int nMax = sub_004A44C0_GetMaxFirstEntry();
    int nFirst = gnFirstVisible_007C02AC;
    if (nStep < 0)
    {
        const int nPrev = nFirst <= 0 ? nFirst : nFirst - 1;
        if (nPrev < 0)
            goto done;
        nFirst = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNext > nMax)
            goto done;
        nFirst = nNext;
    }
    else
        goto done;
    gnFirstVisible_007C02AC = nFirst;
done:
    gnThumbY_007C02CC = sub_I18_TrackSpan() * nFirst / nMax + sub_I18_TrackTop();
}

static __forceinline int sub_F08_PanelLeft()
{
    return (gnGlobal_0071146C - 0x26C) / 2;
}

static __forceinline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnGlobal_0071146C - sub_F08_PanelLeft() * 2);
}

static __forceinline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static __forceinline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static __forceinline int sub_F08_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_F08_TrackBottom() - sub_F08_TrackTop() - sub_F08_ThumbHeight();
}

static __forceinline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
            return 0;
    }
    return 1;
}

// 0x004A45C0
void __fastcall sub_004A45C0_MoveSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A45C0_MoveSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A45C0_MoveSelection(1);
        return;
    }

    const int nCount = gnEntryCount_007C0274;
    if (nStep < 0)
    {
        const int nOld = gnGlobal_007C02B0;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnGlobal_007C02B0 = nNew;
    }
    else if (nStep > 0 && gnGlobal_007C02B0 < nCount)
    {
        const int nNew = gnGlobal_007C02B0 + 1;
        if (nNew < nCount)
            gnGlobal_007C02B0 = nNew;
    }

    const int nSelected = gnGlobal_007C02B0;
    int nFirst = gnFirstVisible_007C02AC;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnFirstVisible_007C02AC = nSelected;
        gnThumbY_007C02CC = nSelected * sub_F08_TrackSpan() / sub_004A44C0_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnGlobal_007C02B0 < nLast)
            break;

        const int nMax = sub_004A44C0_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnFirstVisible_007C02AC = nFirst;
}

// 0x004A4720
static int sub_004A4720_GetLineAt(int nY)
{
    int nIndex = gnFirstVisible_007C02AC;
    const int nCount = gnEntryCount_007C0274;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight_007A521C - 0x1A4) / 2 + 0x3A;
        do
        {
            if (nLine >= 0x0F)
                break;
            if (nY <= nLineY)
                return nIndex;
            ++nIndex;
            ++nLine;
            nLineY += 0x12;
        }
        while (nIndex < nCount);
        if (nIndex < nCount)
            return nIndex;
    }
    return nCount < 0 ? nCount : nCount - 1;
}

static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnGlobal_0071146C - 620) / 2;
    return nY < nHalf + (gnGlobal_0071146C - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A47C0
static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaSliderButtons_007246D8[i].nLeft && nX <= gaSliderButtons_007246D8[i].nRight
            && nY >= gaSliderButtons_007246D8[i].nTop && nY <= gaSliderButtons_007246D8[i].nBottom)
            break;
    }
    return i;
}

// 0x004A47F0
static int sub_004A47F0_IsInList(int nX, int nY)
{
    const int nHalf = (gnGlobal_0071146C - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnGlobal_0071146C - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight_007A521C - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

// 0x004A4860
static __declspec(noinline) int sub_004A4860_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

// 0x004A48B0
static __declspec(noinline) int sub_004A48B0_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

// 0x004A4900
static __declspec(noinline) int sub_004A4900_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnThumbY_007C02CC)
            return 1;
    }
    return 0;
}

// 0x004A4950
static __declspec(noinline) int sub_004A4950_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnThumbY_007C02CC && nY <= gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static __declspec(noinline) int sub_004A49A0_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A4A00
static __forceinline int sub_004A4A00_IsOnButton(int nX, int nY)
{
    return sub_004A47C0_GetButtonAt(nX, nY) != 3;
}

// 0x004A4A10
static int sub_004A4A10_IsOnSelectedLine(int nX, int nY)
{
    if (sub_004A47F0_IsInList(nX, nY) && sub_004A4720_GetLineAt(nY) == gnGlobal_007C02B0
        && sub_E10_IsAbovePanelLineCopy(nX) == gnGlobal_007246D4)
        return 1;
    return 0;
}

// 0x004A4A80
static __forceinline int sub_004A4A80_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnPressedButton_007C02B4;
    if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall sub_004A4AA0_IsOnlyPressed(int nIndex)
{
    for (int i = 0; i < 7; i++)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
        {
            return 0;
        }
    }
    return 1;
}

// 0x004A4FA0
static int sub_004A4FA0_GetEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnGlobal_007C02B0 && (gnGlobal_007C02B8 || nFlag == gnGlobal_007246D4))
    {
        return 3;
    }

    if (!sub_00469D90(gpListEntries_00724264[nIndex].nId, 1) && !sub_00469D90(gpListEntries_00724264[nIndex].nId, 0))
    {
        return 1;
    }

    return sub_00469D90(gpListEntries_00724264[nIndex].nId, nFlag) ? 4 : 5;
}

int sub_B05_Emit_004A4FA0(int* pIndex)
{
    int nA = sub_004A4FA0_GetEntryState(*pIndex, 1);
    int nB = sub_004A4FA0_GetEntryState(*pIndex, 0);
    return sub_B05_Sink(nA, nB);
}

int __cdecl sub_0040D530_Call0040C720()
{
    return sub_0040C720_ReleaseReferences(1);
}

// 0x004A5010
void __cdecl sub_004A5010_Call00469A60()
{
    sub_00469A60_ResetKeyConfig(0);
}

// 0x004A5020
void __cdecl sub_004A5020_AcceptKeyConfig()
{
    sub_00469D40_SaveAndBindHotkeys();
    sub_00455F20(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl sub_004A5040_CancelKeyConfig()
{
    sub_00469D50();
    sub_00455F20(11, 1, 0);
    sub_0047E090(0, 1);
}

// 0x004A51E0
void __cdecl sub_004A51E0_FreeCelFile()
{
    if (gpCelFile_007C02BC)
    {
        sub_00478A00(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x004A5200
void __fastcall sub_004A5200(int nArg)
{
    sub_004A43E0();
    if (nArg)
    {
        if (gnGlobal_007C02B8 == 0)
        {
            sub_00469D20_SaveHotkeys();
            sub_0046AA20(0, 0);
            sub_0044DCE0_MouseExtTables_451E10();
            sub_00467A70_RefreshHoverUnit(0);
        }
        gnFirstVisible_007C02AC = 0;
        gnGlobal_007C02B0 = 0;
    }
    else if (gnGlobal_007C02B8 == 0)
    {
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
    }
    sub_004A5060();
}

int __fastcall sub_005EF1E0_BaalThroneGetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

// build: context sub_00600C60_CallFree
void __fastcall sub_00600C60_CallFree(void* pMemory)
{
    sub_00517ABB(pMemory);
}

// 0x004A59D0
int __stdcall sub_004A59D0_HandleHotkeyAction(D2HotkeyActionStrc* pAction)
{
    if (sub_0044DA30())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        sub_004A4500_ScrollList(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}

// 0x004A5C70
void __stdcall sub_004A5C70(SMSGHANDLER_PARAMS* message)
{
    if (sub_0044DA30()) { message->bReturn = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            sub_00455F20(UI_VARIABLE, 1, 0);
            sub_0047E090(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->bReturn = 1;
    message->lResult = 0;
    sub_00420290_BreakHandlerChain(message);
}

// 0x004A5D00
void __cdecl sub_004A5D00_OpenSliderHandlers()
{
    gnGlobal_007C02B8 = 1;
    sub_00455AE0_CloseUIVar(0xB);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
}

// 0x004A5DE0
void __cdecl sub_004A5DE0_CloseSliderHandlers()
{
    if (gnGlobal_007C02B8)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
        gnGlobal_007C02B8 = 0;
    }
}

// 0x004A5E60
static void sub_004A5E60_Release(int nX, int nY)
{
    if (gaPressed_007C0288[0])
    {
        if (sub_004A4A10_IsOnSelectedLine(nX, nY) && gpListEntries_00724264[gnGlobal_007C02B0].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed_007C0288[6])
    {
        const int nButton = gnPressedButton_007C02B4;
        if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
        {
            gaSliderButtons_007246D8[nButton].pfnClick();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    gnGlobal_007C0284 = 0;
    gaPressed_007C0288[0] = 0;
    gaPressed_007C0288[1] = 0;
    gaPressed_007C0288[2] = 0;
    gaPressed_007C0288[3] = 0;
    gaPressed_007C0288[4] = 0;
    gaPressed_007C0288[5] = 0;
    gaPressed_007C0288[6] = 0;
}

// 0x004A5F10
void __stdcall sub_004A5F10_ButtonUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_004A5E60_Release(nX, nY);
    gnGlobal_007C0280 = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6460
void __cdecl sub_004A6460_LoadLevelCels()
{
    gpGlobal_007C02DC = sub_004520C0_LoadUiCelFile("Panel\\Level");
    gpGlobal_007C02E0 = sub_004520C0_LoadUiCelFile("Panel\\Levelsocket");
}

// 0x004A6480
void __cdecl sub_004A6480_FreeLevelCels()
{
    if (gpGlobal_007C02DC)
    {
        sub_00478A00(gpGlobal_007C02DC);
        gpGlobal_007C02DC = 0;
    }
    if (gpGlobal_007C02E0)
    {
        sub_00478A00(gpGlobal_007C02E0);
        gpGlobal_007C02E0 = 0;
    }
}

// 0x004A64C0
void __cdecl sub_004A64C0_UpdateStatButtons()
{
    if (sub_004538D0(0xB))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_004538D0(6))
    {
        if (!STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
            sub_00455F20(6, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0) && !sub_004538D0(2))
            sub_00455F20(6, 0, 0);
    }
    if (sub_004538D0(7))
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) <= 0)
            sub_00455F20(7, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) > 0 && !sub_004538D0(4))
            sub_00455F20(7, 0, 0);
    }
}

// 0x004A65E0
int __cdecl sub_004A65E0_IsMouseOnLeftButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 - 0xC2 && nX < gnGlobal_0071146C / 2 - 0xA0 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A6690
int __cdecl sub_004A6690_IsMouseOnRightButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 + 0xA3 && nX < gnGlobal_0071146C / 2 + 0xC5 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnPressedButton_007C02B4 = 3;
    if (gnGlobal_007C0284)
        return;

    const int bInList = sub_004A47F0_IsInList(nX, nY);
    const int bUp = sub_004A4860_IsOnUpArrow(nX, nY);
    const int bDown = sub_004A48B0_IsOnDownArrow(nX, nY);
    const int bPageUp = sub_004A4900_IsAboveThumb(nX, nY);
    const int bThumb = sub_004A4950_IsOnThumb(nX, nY);
    const int bPageDown = sub_004A49A0_IsBelowThumb(nX, nY);
    const int bButton = sub_004A47C0_GetButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gnGlobal_007C0284 = gnGlobal_007C0280;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (bInList || gaPressed_007C0288[0]))
    {
        gaPressed_007C0288[0] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                sub_004A45C0_MoveSelection(-1);
            if (nY > nTop + 0x136)
                sub_004A45C0_MoveSelection(1);

            const int nOldD4 = gnGlobal_007246D4;
            const int nOldSelected = gnGlobal_007C02B0;
            const int nLine = sub_004A4720_GetLineAt(nY);
            gnGlobal_007C02B0 = nLine;
            gnGlobal_007246D4 = sub_004A4780_IsAbovePanelLine(nX);
            if (gpListEntries_00724264[nLine].nId == 0x39)
            {
                gnGlobal_007246D4 = nOldD4;
                gnGlobal_007C02B0 = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed_007C0288[1] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed_007C0288[2] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed_007C0288[3] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed_007C0288[4]))
    {
        if (bThumb && !gaPressed_007C0288[4] && gnGlobal_007C0280)
        {
            gnDragThumbY_007C02A4 = gnThumbY_007C02CC;
            gnDragMouseY_007C02A8 = nY;
        }
        gaPressed_007C0288[4] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            sub_004A4500_ScrollList((gnDragThumbY_007C02A4 - nTop - gnDragMouseY_007C02A8 + nY - 0x2F)
                * (gnThumbRange_007C027C + 1) / sub_F08_TrackSpan() - gnFirstVisible_007C02AC);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed_007C0288[5] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed_007C0288[6] = gnGlobal_007C0280;
        gnPressedButton_007C02B4 = sub_004A47C0_GetButtonAt(nX, nY);
    }
}

// 0x004A66E0
void __stdcall sub_004A66E0_HandleLeftButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
    {
        return;
    }
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6580_IsInPanelButton(border, x, y))
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A65E0_IsMouseOnLeftButton())
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->bReturn = 0;
}

static __forceinline void MarkRightButtonPressed()
{
    gnPressed_007C02E8 = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}

// 0x004A6790
void __stdcall sub_004A6790_HandleRightButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
        return;
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6630_IsInRightPanelButton(border, x, y))
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A6690_IsMouseOnRightButton())
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->bReturn = 0;
}

static int __fastcall CLIENT_HitPanelButton(int nMode, int nX, int nY)
{
    return sub_004A6580_IsInPanelButton(nMode, nX, nY);
}

// 0x004A6840
void __stdcall sub_004A6840_LeftButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && sub_004538D0(9))
    {
        return;
    }

    sub_00467FA0_MsgHandler(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && CLIENT_HitPanelButton(sub_0045AE90(), nX, nY))
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(6, 1, 0);
            sub_00455F20(2, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(2, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gnGlobal_007C02E4 = 0;
    pMsg->bReturn = 0;
}

static int __fastcall CLIENT_HitRightPanelButton(int nMode, int nX, int nY)
{
    return sub_004A6630_IsInRightPanelButton(nMode, nX, nY);
}

// 0x004A6920
void __stdcall sub_004A6920_RightButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && sub_004538D0(9))
    {
        return;
    }

    sub_00467FA0_MsgHandler(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E8 && CLIENT_HitRightPanelButton(sub_0045AE90(), nX, nY))
        {
            gnGlobal_007C02E8 = 0;
            sub_00455F20(7, 1, 0);
            sub_00455F20(4, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gnGlobal_007C02E8 && sub_004A6690_IsMouseOnRightButton())
        {
            gnGlobal_007C02E8 = 0;
            sub_00455F20(4, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gnGlobal_007C02E8 = 0;
    pMsg->bReturn = 0;
}

// 0x004A6A00
bool __stdcall sub_004A6A00_CheckUiVars(int nArg)
{
    if (nArg == 3)
        return true;
    if (sub_004538D0(2))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(1))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(4))
        return true;
    return (bool)sub_004538D0(0xC);
}

// 0x004A6B30
void __cdecl sub_004A6B30_DrawLeftPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6A00_CheckUiVars(nBorder))
    {
        gnGlobal_007C02E4 = 0;
        return;
    }

    int nX;
    if (nBorder == 2)
        nX = gnGlobal_0071146C / 2 + 0x28;
    else
        nX = 0x28;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF92), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && sub_004A6580_IsInPanelButton(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A65E0_IsInLeftButton() && !sub_004538D0(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF92), gnGlobal_0071146C / 2 - 0xB3, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xC2, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A6D50
bool __stdcall sub_004A6D50_CheckUiVars(int nArg)
{
    if (nArg == 3)
        return true;
    if (sub_004538D0(4))
        return true;
    if (sub_004538D0(0xC))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(1))
        return true;
    return false;
}

// 0x004A6E60
void __cdecl sub_004A6E60_DrawRightPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6D50_CheckUiVars(nBorder))
    {
        gnGlobal_007C02E8 = 0;
        return;
    }

    int nX;
    if (nBorder == 1)
        nX = gnGlobal_0071146C - gnGlobal_0071146C / 2 - 0x49;
    else
        nX = gnGlobal_0071146C - 0x49;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF93), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E8 && sub_004A6630_IsInPanelButton2(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E8 && sub_004A6690_IsInRightButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A6690_IsInRightButton() && !sub_004538D0(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF93), gnGlobal_0071146C / 2 + 0xB2, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0xA3, gnGlobal_00711470 - 8, -1, 5, 0);
}

static int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    int i = 0;
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
    int nBest = 0;
    for (; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0 || ((pLeftItem && ITEMSIsA(pLeftItem, nItemType)) || (pRightItem && ITEMSIsA(pRightItem, nItemType))) && nValue > nBest)
        {
            nBest = nValue;
        }
    }

    return nBest;
}

// 0x004A7180
static void sub_004A7180_DrawHoverLevelText(int nX, int nY, int nValue)
{
    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    Unicode wszText[0x80];
    if (nX < gnGlobal_007A2858 + 0xAD || nX > gnGlobal_007A2858 + 0x137
        || nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x11E || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x10B)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nLevel = UNITS_GetBlockRate(pPlayer, sub_0044DCC0());
    if (nLevel <= 0)
    {
        nLevel = sub_004A70C0_GetWieldedTypeStatMax(pPlayer);
        if (nLevel > 0)
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pPlayer, pPlayer->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass != 0x0D)
            {
                nLevel = 0;
            }
        }
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(sub_00466DD0());
    D2_ASSERT(pMonStatsTxtRecord, 0x15C);

    if (nLevel)
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2779), nLevel, nValue, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }
    else
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2778), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }

    D2Win_10132(wszText, gnGlobal_007A2858 + 0x8B, gnGlobal_00711470 + gnGlobal_007A285C - 0x13B, gnTextColor_007C02F8, 2, 0);
}

void __stdcall sub_I10_Emit_004A7180(int nX, int nY, int nValue)
{
    sub_004A7180_DrawHoverLevelText(nX, nY, nValue);
}

struct D2UnitStrc;

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7300
static __declspec(noinline) int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            nAttackRate += pCharStatsTxtRecord->dwToHitFactor;
        }
    }

    return nAttackRate;
}

int __stdcall sub_004A7340_GetPercentA(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPercent = 100;
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = sub_00466DC0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !sub_0044DCC0() && sub_0044DCD0_GetDifficulty())
    {
        nDefense = nDefense * 10 / 12;
    }

    int nToHit = sub_004A7300_AddToHitFactor(pPlayer, nAttackRate);
    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nDefense += nToHit;
        nPercent = nToHit * 100 / nDefense;
    }

    const int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nChance = 2 * nPlayerLevel * nPercent / (pMonStatsTxtRecord->nLevel[nDifficulty] + nPlayerLevel);
    if (nChance < 5)
    {
        return 5;
    }
    if (nChance > 95)
    {
        return 95;
    }
    return nChance;
}

// 0x004A7660
int __fastcall sub_004A7660_SplitAtNewline(Unicode* wszText, Unicode** ppNext)
{
    Unicode* pChar = wszText;
    *ppNext = 0;
    int nLen = sub_00526800(wszText);
    int i = 0;
    while (pChar->wChar)
    {
        if (pChar->wChar == '\n')
        {
            wszText[i].wChar = 0;
            if (i >= nLen)
                return 0;
            *ppNext = pChar + 1;
            return 1;
        }
        ++pChar;
        ++i;
    }
    return 0;
}

// 0x004A7A90
void __cdecl sub_004A7A90_SetFlag()
{
    gnFlag_007C02EC = 1;
}

// 0x004A7AD0
void __cdecl sub_004A7AD0()
{
}

__forceinline int D2ListScrollStrc::DrawRows(D2CelContextStrc* pContext)
{
    int i;
    for (i = 0; i < nRows; ++i)
    {
        pContext->nFrame = 13;
        sub_004F6480(pContext, nX, nY + 12 * (i + 1), -1, 5, 0);
    }
    return i;
}

// 0x004BEE90
void ListBoxImplementation::Slot01()
{
    D2RectStrc tRect;
    tRect.nTop = f_18070C;
    tRect.nLeft = f_180708;
    tRect.nRight = f_180708 + nRectWidth - 1;
    tRect.nBottom = f_18070C + nRectHeight - 1;
    sub_00452E50_DrawRectangleBorder(&tRect);

    const int nOldFont = sub_00502EF0(nArg18);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCelFile_007C546C;
    tContext.nFrame = bTopPressed ? 11 : 9;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, tBar.nX, tBar.nY, -1, 5, 0);

    const int i = tBar.DrawRows(&tContext);

    tContext.nFrame = bBottomPressed ? 10 : 8;
    sub_004F6480(&tContext, tBar.nX, tBar.nY + 12 * i, -1, 5, 0);

    int nDrawn = 0;
    const int nLines = sub_004BE340_CountLinesInView(this);
    int nRow = 0;
    for (int nLine = f_180730; nLine < f_180730 + nLines && nLine < 0x80; ++nLine)
    {
        int nColor;
        if (nSelectedIndex == nLine && pfnCallback)
        {
            nColor = 3;
        }
        else
        {
            nColor = aLines[nLine].nData;
        }

        sub_00502EF0(aLines[nLine].nFont != 14 ? aLines[nLine].nFont : nArg18);

        if (aLines[nLine].wszText0[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].wszText0, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_800[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1000[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_1000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1800[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_1800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_2000[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_2000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText5[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].wszText5, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        ++nRow;
    }

    sub_004BBFB0();
    ++nState;

    SMSGHANDLER_PARAMS tMsg;
    tMsg.lParam = (unsigned short)sub_00468730() | ((unsigned int)(unsigned short)sub_00468740() << 16);
    const int nMouseX = (unsigned short)tMsg.lParam;
    const int nMouseY = tMsg.lParam >> 16;

    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY - 12 && nMouseY < tBar.nY && bTopPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            sub_004BE910_ScrollUp(&tMsg);
        }
    }
    else if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY + 12 * tBar.nRows - 12 && nMouseY < tBar.nY + 12 * tBar.nRows
        && bBottomPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            sub_004BE990_ScrollDown(&tMsg);
        }
    }

    sub_00502EF0(nOldFont);
}

// 0x004BF2F0
int ListBoxView::sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseY = pMsg->nYpos;
    const unsigned short nCount = nEntryCount;
    const int nTop = nY;

    if (nCount && nVisibleRows <= nCount && nMouseY - nTop > 0)
    {
        if (nThumbStart != nThumbEnd)
        {
            if (nMouseY < nTop + 12 * nThumbStart + 13)
            {
                if (nSelectedIndex - nVisibleRows > 0)
                    nSelectedIndex = nSelectedIndex - nVisibleRows;
                else
                    nSelectedIndex = 0;
            }
            else
            {
                if (nMouseY <= nY + 12 * nThumbEnd + 13)
                {
                    return 0;
                }

                if (nSelectedIndex + nVisibleRows >= nCount)
                    nSelectedIndex = nCount - 1;
                else
                    nSelectedIndex = nSelectedIndex + nVisibleRows;
                if (nCount - nSelectedIndex < nVisibleRows)
                {
                    if (nCount >= nVisibleRows)
                    {
                        nSelectedIndex = nCount - nVisibleRows;
                    }
                    else
                    {
                        nSelectedIndex = 0;
                    }
                }
            }

            if (nSelectedIndex >= 0x80)
            {
                nSelectedIndex = D2_MAX(0, nCount - 1);
            }

            nTopIndex = nSelectedIndex;
            sub_004B9A00(1, 0, 0, 0, 0);
            sub_004BE8D0_Refresh();
            return 1;
        }

        return 0;
    }

    return 0;
}

#include "gen/data/Source/D2Client/UI/text_004A3FE0.inc"
