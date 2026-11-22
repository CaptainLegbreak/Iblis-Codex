#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2TextNodeStrc;

struct D2TextListStrc;

class ListBoxWrapper;

struct D2RectStrc;

struct T00479230;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)

struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

#pragma pack(pop)

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
    virtual void AddName(const char* szName, int nSize);
};

class ListBoxWrapper
{
public:
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1C();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2C();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38();
    virtual void Refresh();
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

D2TextNodeStrc* __fastcall TEXT_CloneStringList(D2TextNodeStrc* pSource); // 0x0049DB10

extern int gnGlobal_0071146C; // 0x0071146C

extern ListBoxWrapper* gpListBox_007BF1B4; // 0x007BF1B4

D2TextListStrc gtTextList_007BF1E4; // 0x007BF1E4

extern D2TextListStrc gtTextList_007BF1EA; // 0x007BF1EA

extern D2TextListStrc gtTextList_007BF1F0; // 0x007BF1F0

#pragma pack(push, 2)

struct T00479230
{
    T0044CB60* pFirst;
    int nLines;
    int nTextTop;
    int nTextBottom;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned short f_14;
    int nScroll;
    int nField1A;
    int nField1E;
    int nField22;
    int nField26;
    unsigned short nField2A;
};

#pragma pack(pop)

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2); // 0x006CC4C4

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY); // 0x0049D8E0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0

unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661220

extern "C" const char gszTextSourceFile[]; // 0x006DA13C

extern int gnGlobal_00711470; // 0x00711470

extern int gaHoverDirs_00722654[]; // 0x00722654

extern int gnHoverDirCount_00722674; // 0x00722674

extern D2RectStrc gaHoverRects_007BF0A8[16]; // 0x007BF0A8

extern int gnGameFrame_007BF20E; // 0x007BF20E

extern D2CoordStrc gtHoverOffset_007BF214; // 0x007BF214

extern int gnHoverRectCount_007BF224; // 0x007BF224

bool __stdcall sub_0049E070_PlaceHoverRect(int nCount, D2RectStrc* pRect);

void __fastcall TEXT_AddToHistory(D2TextNodeStrc* pSource); // 0x0049DBC0

struct D2CelFileStrc;

struct D2ScrollPosStrc;

struct D2ScrollPosStrc
{
    int nX;
    int nY;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

void __cdecl TEXT_DrawPanelFrame(); // 0x0049FA10


int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern D2ScrollPosStrc gaScrollPiecePos_00722EB8[5]; // 0x00722EB8

extern D2ScrollPosStrc gaScrollFadePos_00722EE0[5]; // 0x00722EE0

extern unsigned int gaScrollThresholds_00722F08[5]; // 0x00722F08

extern unsigned short gawScrollSlots_007BF098[5]; // 0x007BF098

extern unsigned int gdwScrollTick_007BF243; // 0x007BF243

extern unsigned int gnScrollCounter_007BF247; // 0x007BF247

extern D2CelFileStrc* gpScroin3_007BF26C; // 0x007BF26C

extern D2CelFileStrc* gpScroin2_007BF270; // 0x007BF270

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

#pragma pack(push, 2)

#pragma pack(pop)

int __cdecl sub_00525150();

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

struct D2SliderButtonStrc;

struct D2Record42Strc;

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

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    Unicode wszText[300];
};

struct D2QuestTextBufferStrc
{
    unsigned char pHead[0x106];
    D2QuestTextLineStrc pLines[6];

    D2QuestTextBufferStrc();
};

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

void __fastcall TEXT_ToggleQuestLog(int nMode);

void __cdecl sub_0044DA70(); // 0x0044DA70

void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall TEXT_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

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

int __cdecl TEXT_GetMaxFirstEntry(); // 0x004A44C0

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

int __cdecl GAME_IsExitPending(); // 0x0044DA30

extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

extern "C" void __cdecl GAME_RegisterMouseHandlers(); // 0x0044DD20

void __cdecl sub_00466FE0(); // 0x00466FE0

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __cdecl CMDTBL_SaveHotkeys(); // 0x00469D20

void __cdecl TEXT_InitKeyConfigEntries(); // 0x004A43E0

extern int gnGlobal_007C0280; // 0x007C0280

static int gnGlobal_007C02B0; // 0x007C02B0

int gnGlobal_007C02B8; // 0x007C02B8

int gnGlobal_007C0284; // 0x007C0284

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

int __stdcall sub_B05_Sink(int nA, int nB);

int __fastcall EXCEPTIONS_ReleaseSymbols(int nArg); // 0x0040C720

void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

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

void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[]; // 0x0072478C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __cdecl sub_00466DC0(); // 0x00466DC0

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

static int TEXT_GetKeyConfigButtonAt(int nX, int nY);

int gnGlobal_007BF298; // 0x007BF298

#pragma pack(push, 2)

#pragma pack(pop)

int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780

extern int gnThumbRange_007C027C; // 0x007C027C

int gnDragThumbY_007C02A4; // 0x007C02A4

int gnDragMouseY_007C02A8; // 0x007C02A8

unsigned long gdwLastTick_007C02C0; // 0x007C02C0

int __fastcall TEXT_IsInPanelButton(int, int, int); // 0x004A6580

int __cdecl TEXT_IsMouseOnStatButton(); // 0x004A65E0

void __fastcall sub_004B9A00_ChangeUiState(int, int, int, int, int); // 0x004B9A00

void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS*); // 0x00467F20

int __cdecl NPCMENU_IsNpcTalkActive(); // 0x004B3470

extern int gnPressed_007C02E4; // 0x007C02E4

int __fastcall TEXT_IsInRightPanelButton(int, int, int); // 0x004A6630

int __cdecl TEXT_IsMouseOnSkillButton(); // 0x004A6690

extern int gnPressed_007C02E8; // 0x007C02E8

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __cdecl UI_GetHoverClassId(); // 0x00466DD0

void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int nArg); // 0x00622720

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

void __fastcall TEXT_ScrollKeyConfigList(int nStep);

#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5

#pragma pack(push, 2)

#pragma pack(pop)

void __cdecl CMDTBL_SaveAndBindHotkeys(); // 0x00469D40

void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200

void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090

extern int global_00724728; // 0x00724728

enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0

bool __stdcall TEXT_IsStatButtonHidden(int nArg); // 0x004A6A00

bool __stdcall TEXT_IsSkillButtonHidden(int nArg); // 0x004A6D50

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

void* gpGlobal_007C02DC; // 0x007C02DC

void* gpGlobal_007C02E0; // 0x007C02E0

int gnGlobal_007C02E4; // 0x007C02E4

int gnGlobal_007C02E8; // 0x007C02E8

void __fastcall TEXT_MoveKeyConfigSelection(int nStep);

char gbGlobal_007BF2B2; // 0x007BF2B2

char gbGlobal_007BF2B4; // 0x007BF2B4

void* gpCelFile_007C02BC; // 0x007C02BC

static int TEXT_GetKeyConfigLineAt(int nY);

static int TEXT_IsInKeyConfigList(int nX, int nY);

static int TEXT_IsOnUpArrow(int nX, int nY);

static int TEXT_IsOnDownArrow(int nX, int nY);

static int TEXT_IsAboveThumb(int nX, int nY);

static int TEXT_IsOnThumb(int nX, int nY);

static int TEXT_IsBelowThumb(int nX, int nY);

unsigned char gnTextColor_007C02F8; // 0x007C02F8

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

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

    void DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);               // 0x004BE410

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

void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

int __fastcall PANEL_CountLinesInView(ListBoxImplementation* pListBox); // 0x004BE340

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
    int ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg);
};

#pragma pack(pop)

static int TEXT_IsOnKeyConfigButton(int nX, int nY);

static int TEXT_IsOnPressedButton(int nX, int nY);

void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit);

bool __stdcall sub_0049E070_PlaceHoverRect(int nCount, D2RectStrc* pRect);

// 0x0049D490
static void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

void __fastcall TEXT_AddToHistory(D2TextNodeStrc* pSource)
{
    D2TextNodeStrc* pClone = TEXT_CloneStringList(pSource);
    D2TextNodeStrc* pNode;
    if (gtTextList_007BF1F0.wCount >= 0x80)
    {
        pNode = gtTextList_007BF1F0.pFirst;
        if (pNode)
        {
            D2TextNodeStrc* pPrevious = 0;
            while (pNode->pNext)
            {
                pPrevious = pNode;
                pNode = pNode->pNext;
            }
            sub_0049D490_FreeTextNode(pNode);
            if (pPrevious)
                pPrevious->pNext = 0;
            if (gtTextList_007BF1F0.wCount >= 1)
                gtTextList_007BF1F0.wCount--;
        }
    }
    pNode = gtTextList_007BF1F0.pFirst;
    pClone->pNext = pNode;
    gtTextList_007BF1F0.wCount++;
    gtTextList_007BF1F0.pFirst = pClone;
}

void __fastcall sub_0049E5C0_PrintWrappedLine(const Unicode* wszText, char nColor)
{
    const int nOldFont = sub_00502EF0(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    while (nCount > 0)
    {
        while (D2Win_10123(&wszText[nStart], nCount) > gnGlobal_0071146C - 0x46)
        {
            nCount--;
            if (nCount <= 0)
                break;
        }
        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30_IsLineBreak(&wszText[nStart], nCount + 1))
                nCount--;
        }
        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        char szLine[0x400];
        sub_005263E0(szLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        sub_00526790(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1EA.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1EA.pFirst;
        unsigned short nNodes = 0;
        while (pLast->pNext)
        {
            pLast = pLast->pNext;
            nNodes++;
        }
        D2_ASSERT(nNodes == gtTextList_007BF1EA.wCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextList_007BF1EA.pFirst = pNode;
    }
    gtTextList_007BF1EA.wCount++;
    TEXT_AddToHistory(pNode);

    if (gtTextList_007BF1EA.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtTextList_007BF1EA.pFirst;
        gtTextList_007BF1EA.pFirst = pFirst->pNext;
        sub_0049D490_FreeTextNode(pFirst);
        gtTextList_007BF1EA.wCount--;
    }

    if (GAME_GetUIVarState(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
    sub_004B9A00(6, 0, 0, 0, 0);
}

static void sub_0049D370_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, gszTextSourceFile, 0x60F, 0);
        FOG_Free(pLine, gszTextSourceFile, 0x610, 0);
        pLine = pNext;
    }
}

static void sub_0049D3C0_MeasureTextBox(T00479230* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (T0044CB60* pLine = pBox->pFirst; pLine; pLine = pLine->pNext)
    {
        nMaxWidth = nMaxWidth > D2Win_10121_GetTextWidth(pLine->pText) ? nMaxWidth : D2Win_10121_GetTextWidth(pLine->pText);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

void __stdcall TEXT_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        sub_0049D370_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, gszTextSourceFile, 0x68E, 0);
    }
}

static int TEXT_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnGlobal_0071146C / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnGlobal_0071146C / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    sub_0049D8E0_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

// build: context sub_J06_IntersectsAnyHoverRect
static __forceinline int sub_J06_IntersectsAnyHoverRect(const D2RectStrc* pRect, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects_007BF0A8[i], pRect))
            return 1;
    }
    return 0;
}

// 0x0049E070
static bool __stdcall sub_0049E070_PlaceHoverRect(int nCount, D2RectStrc* pRect)
{
    if (nCount >= 0x10)
        return false;

    if (!nCount)
    {
        gaHoverRects_007BF0A8[0] = *pRect;
        return true;
    }

    if (!sub_J06_IntersectsAnyHoverRect(pRect, nCount))
    {
        gaHoverRects_007BF0A8[nCount] = *pRect;
        return true;
    }

    int nDir;
    for (int nDX = 0x32; nDX < 0x190; nDX += 0x32)
    {
        for (int nDY = 0x23; nDY < 0x118; nDY += 0x23)
        {

            for (nDir = 0; nDir < gnHoverDirCount_00722674; ++nDir)
            {
                D2RectStrc tRect = *pRect;
                tRect.nLeft += gaHoverDirs_00722654[nDir] * nDX;
                tRect.nRight = tRect.nLeft + 0x190;
                tRect.nTop += gaHoverDirs_00722654[nDir] * nDY;
                tRect.nBottom = tRect.nTop + 0x118;
                if (tRect.nLeft < 0 || tRect.nRight > gnGlobal_0071146C || tRect.nTop < 0 || tRect.nBottom > gnGlobal_00711470)
                    continue;

                bool bOverlap = false;
                for (int j = 0; j < nCount; ++j)
                {
                    D2RectStrc tTest;
                    if (IntersectRect(&tTest, &gaHoverRects_007BF0A8[j], &tRect))
                        bOverlap = true;
                }
                if (!bOverlap)
                {
                    gaHoverRects_007BF0A8[nCount] = tRect;
                    *pRect = tRect;
                    return true;
                }
            }
        }
    }
    return false;
}

static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        sub_00526F20_ToUnicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (nCurrentLangId == nLangId)
        return true;
    if (nCurrentLangId == 7)
    {
        if (nLangId == 0xC)
            return true;
    }
    else if (nCurrentLangId == 0xC && nLangId == 7)
    {
        return true;
    }

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

static void __stdcall sub_004A0A00_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gnGameFrame_007BF20E > CHAT_GetTimeoutFromHoverMsg(pHoverText))
    {
        CHAT_FreeHoverMsg(0, pHoverText);
        if (pUnit)
            pUnit->pHoverText = 0;
    }

    const int nOldFont = sub_00502EF0(0x0D);
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), gszTextSourceFile, 0x65D, 0);
    pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
    sub_0049D3C0_MeasureTextBox(pTextBox);

    pPos->nX -= pTextBox->nWidth >> 1;
    pPos->nY -= 0x32;
    pPos->nY = pPos->nY - pTextBox->nLines * 0x0F - 3;

    D2RectStrc tRect;
    tRect.nTop = pPos->nY;
    tRect.nLeft = pPos->nX;
    tRect.nBottom = pTextBox->nHeight + pPos->nY;
    tRect.nRight = pTextBox->nWidth + pPos->nX;
    if (gnHoverRectCount_007BF224 < 0x10 && !sub_0049E070_PlaceHoverRect(gnHoverRectCount_007BF224, &tRect))
    {
        TEXT_FreeTextBox(pTextBox);
        return;
    }

    ++gnHoverRectCount_007BF224;
    TEXT_DrawTextBoxAt(pTextBox, &tRect);
    TEXT_FreeTextBox(pTextBox);
    sub_00502EF0(nOldFont);
}

// 0x0049E3A0
void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor)
{
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xD46, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;
    int nOldFont = sub_00502EF0(0xD);

    int nLines;
    T0044CB60* pLine = sub_00502970_SplitText(wszText, &nLines, gnGlobal_0071146C - 0x46);
    pNode->nLines = (unsigned int)nLines > 6 ? 6 : nLines;
    for (int i = 0; i < nLines; i++)
    {
        if (i < pNode->nLines)
            pNode->pLines[i] = pLine->pText;
        else
            FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0xD5A, 0);
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine, ".\\UI\\text.cpp", 0xD5D, 0);
        pLine = pNext;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1E4.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1E4.pFirst;
        unsigned short wCount = 0;
        D2TextNodeStrc** ppNext = &pLast->pNext;
        if (pLast->pNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = &pLast->pNext;
                wCount++;
            }
            while (*ppNext);
        }
        D2_ASSERT(wCount == gtTextList_007BF1E4.wCount - 1, 0xD6C);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextList_007BF1E4.pFirst = pNode;
    }

    if (pNode->nColor == 4 && pNode->nLines == 1)
    {
        char szName[0x100] = {0};
        sub_005263E0(szName, pNode->pLines[0], 0x100);
        sub_00611560_GetSquelchList()->AddName(szName, 0x100);
    }

    TEXT_AddToHistory(pNode);
    gtTextList_007BF1E4.wCount++;

    int nTotal = 0;
    D2TextNodeStrc* p = gtTextList_007BF1E4.pFirst;
    if (gtTextList_007BF1E4.pFirst)
    {
        do
        {
            nTotal += p->nLines;
            p = p->pNext;
        }
        while (p);
    }
    if (nTotal > 0x12)
    {
        D2TextNodeStrc* pOld = gtTextList_007BF1E4.pFirst;
        gtTextList_007BF1E4.pFirst = gtTextList_007BF1E4.pFirst->pNext;
        gtTextList_007BF1E4.wCount--;
        sub_0049D490_FreeTextNode(pOld);
    }

    sub_004B9A00(6, 0, 0, 0, 0);
    if (GAME_GetUIVarState(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
}

// 0x004A0B30
void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x1E - gtHoverOffset_007BF214.nY;
    tPos.nX -= gtHoverOffset_007BF214.nX;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnGlobal_0071146C / 4;
        break;
    case 2:
        tPos.nX += gnGlobal_0071146C / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnGlobal_00711470)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnGlobal_0071146C + 0x64)
        return;

    char szText[0x104];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    if (szText[0] == -1 && szText[1] == -1)
    {
        const int nStringId = atoi(&szText[2]);
        if ((nStringId >= 0x42D && nStringId <= 0x50F) || (nStringId >= 0x5587 && nStringId <= 0x5615)
            || nStringId == 0x2AA4 || nStringId == 0x5586)
        {
            const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
            if (wszString)
            {
                Unicode wszBuffer[0xC8];
                memset(wszBuffer, 0, sizeof(wszBuffer));
                int nLength = sub_00526800(wszString);
                if (nLength >= 0xC8)
                    nLength = 0xC7;
                sub_00526790(wszBuffer, wszString, nLength);
                sub_004A0A00_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
                return;
            }
        }
    }

    Unicode wszHover[0x100];
    if (!sub_0049E280_ConvertHoverText(CHAT_GetLangIdFromHoverMsg(pHoverText), wszHover, szText))
        return;
    wszHover[0xFF].wChar = 0;
    sub_004A0A00_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

// build: context TEXT_ReadLine
static __forceinline const unsigned short* TEXT_ReadLine(Unicode* pLine, const unsigned short* pText)
{
    int i = 0;
    memset(pLine, 0, 100 * sizeof(Unicode));
    for (; i < 100 && *pText != '\n'; ++i)
    {
        pLine[i] = *pText++;
    }
    if (i < 100 && *pText == '\n')
    {
        ++pText;
    }
    return pText;
}

// 0x004A0320
T0044CB60* __stdcall TEXT_BuildTextLines(const unsigned short* wszText, int* pLineCount, unsigned short* pMaxLines)
{
    Unicode szLine[100];
    const unsigned short* pText = wszText;

    *pLineCount = 0;
    T0044CB60* pLast = 0;
    T0044CB60* pFirst = 0;
    int bFirstLine = 1;
    while (*pText)
    {
        pText = TEXT_ReadLine(szLine, pText);

        T0044CB60* pLine = (T0044CB60*)FOG_Alloc(sizeof(T0044CB60), ".\\UI\\text.cpp", 0x5B8, 0);
        if (bFirstLine == 1)
        {
            const int nLength = sub_00526800(szLine);
            int bAscii = 1;
            for (int j = 0; j < nLength; ++j)
            {
                if (szLine[j].wChar >= 0x80)
                {
                    bAscii = 0;
                }
            }

            if (bAscii)
            {
                char szNumber[100];
                sub_005263E0(szNumber, szLine, 100);
                *pMaxLines = atoi(szNumber);
            }
            else
            {
                char szMessage[80];
                wsprintfA(szMessage, "line 0 of string does not contain scroll rate");
                *pMaxLines = 8;
            }

            bFirstLine = 0;
            pText = TEXT_ReadLine(szLine, pText);
        }

        const int nLength = sub_00526800(szLine);
        if (D2Win_10121_GetTextWidth(szLine) >= 0x134)
        {
            char szMessage[80];
            wsprintfA(szMessage, "line %d of string is too long", *pLineCount);
        }

        pLine->pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nLength + 1), ".\\UI\\text.cpp", 0x5EB, 0);
        sub_005267E0(pLine->pText, szLine);
        pLine->pNext = 0;
        if (pLast)
        {
            pLast->pNext = pLine;
        }
        else
        {
            pFirst = pLine;
        }
        ++*pLineCount;
        pLast = pLine;
    }
    return pFirst;
}


// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A3FE0
void __fastcall TEXT_ToggleQuestLog(int nMode)
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
void __fastcall TEXT_SetQuestRecord(const D2Record42Strc* pRecord)
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

// 0x004A4260
D2QuestTextBufferStrc::D2QuestTextBufferStrc()
{
}

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (TEXT_IsOnKeyConfigButton(nX, nY))
    {
        return TEXT_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A47C0
static int TEXT_GetKeyConfigButtonAt(int nX, int nY)
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
    TEXT_SetTextCallback(TEXT_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

// 0x004A42A0
void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) TEXT_ToggleQuestLog(0);
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

static inline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static inline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static inline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static inline int sub_F08_VisibleLines()
{
    return (sub_F08_LinesBottom() - sub_F08_LinesTop()) / 0x12;
}

// 0x004A44C0
int __cdecl TEXT_GetMaxFirstEntry()
{
    int nCount = gnEntryCount_007C0274;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

static inline int sub_I18_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static inline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static inline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static inline int sub_I18_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static inline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

// 0x004A4500
void __fastcall TEXT_ScrollKeyConfigList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_ScrollKeyConfigList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_ScrollKeyConfigList(1);
        return;
    }

    const int nMax = TEXT_GetMaxFirstEntry();
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

static inline int sub_F08_PanelLeft()
{
    return (gnGlobal_0071146C - 0x26C) / 2;
}

static inline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnGlobal_0071146C - sub_F08_PanelLeft() * 2);
}

static inline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static inline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static inline int sub_F08_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_F08_TrackBottom() - sub_F08_TrackTop() - sub_F08_ThumbHeight();
}

static inline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
            return 0;
    }
    return 1;
}

// 0x004A45C0
void __fastcall TEXT_MoveKeyConfigSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_MoveKeyConfigSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_MoveKeyConfigSelection(1);
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
        gnThumbY_007C02CC = nSelected * sub_F08_TrackSpan() / TEXT_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnGlobal_007C02B0 < nLast)
            break;

        const int nMax = TEXT_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnFirstVisible_007C02AC = nFirst;
}

// 0x004A4720
static int TEXT_GetKeyConfigLineAt(int nY)
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

// 0x004A47F0
static int TEXT_IsInKeyConfigList(int nX, int nY)
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
static int TEXT_IsOnUpArrow(int nX, int nY)
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
static int TEXT_IsOnDownArrow(int nX, int nY)
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
static int TEXT_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnThumbY_007C02CC)
            return 1;
    }
    return 0;
}

// 0x004A4950
static int TEXT_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnThumbY_007C02CC && nY <= gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static int TEXT_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A4A00
static inline int TEXT_IsOnKeyConfigButton(int nX, int nY)
{
    return TEXT_GetKeyConfigButtonAt(nX, nY) != 3;
}

// 0x004A4A10
static int TEXT_IsOnSelectedLine(int nX, int nY)
{
    if (TEXT_IsInKeyConfigList(nX, nY) && TEXT_GetKeyConfigLineAt(nY) == gnGlobal_007C02B0
        && sub_E10_IsAbovePanelLineCopy(nX) == gnGlobal_007246D4)
        return 1;
    return 0;
}

// 0x004A4A80
static inline int TEXT_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnPressedButton_007C02B4;
    if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall TEXT_IsOnlyPressed(int nIndex)
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

    if (!CUNIT_HasHotkeyBinding(gpListEntries_00724264[nIndex].nId, 1) && !CUNIT_HasHotkeyBinding(gpListEntries_00724264[nIndex].nId, 0))
    {
        return 1;
    }

    return CUNIT_HasHotkeyBinding(gpListEntries_00724264[nIndex].nId, nFlag) ? 4 : 5;
}

// 0x0049FBA0
void __stdcall TEXT_OpenTextPanel(int bDraw)
{
    if (!sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    D2CelContextStrc tPiece;
    memset(&tPiece, 0, sizeof(tPiece));
    TEXT_DrawPanelFrame();

    if (!gpScroin2_007BF270)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin2");
        gpScroin2_007BF270 = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    if (!gpScroin3_007BF26C)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin3");
        gpScroin3_007BF26C = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    if (!bDraw)
    {
        return;
    }

    const int nOldMode = sub_00502EF0(5);
    tPiece.pCellFile = gpScroin2_007BF270;
    if (!gdwScrollTick_007BF243)
    {
        gdwScrollTick_007BF243 = GetTickCount();
        gnScrollCounter_007BF247 = 0;
    }
    else if (gdwScrollTick_007BF243 + 50 < GetTickCount())
    {
        gdwScrollTick_007BF243 = GetTickCount();
        ++gnScrollCounter_007BF247;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (gnScrollCounter_007BF247 > gaScrollThresholds_00722F08[i])
        {
            const int nTicks = gnScrollCounter_007BF247 - gaScrollThresholds_00722F08[i];
            tPiece.nFrame = i;
            int nDrawMode = 5;
            if (nTicks == 1)
            {
                sub_004B9A00(0xA6F, 0, 0, 0, 0);
            }
            if (nTicks < 5)
            {
                nDrawMode = 0;
            }
            else if (nTicks < 10)
            {
                nDrawMode = 1;
            }
            else if (nTicks < 15)
            {
                nDrawMode = 2;
            }

            const unsigned short nSlot = gawScrollSlots_007BF098[i];
            if (nSlot < 6)
            {
                D2_ASSERT(nSlot < 5, 0x1673);
                TEXTURE_CelDraw(&tPiece, gaScrollPiecePos_00722EB8[nSlot].nX + gnGlobal_007A2858, gaScrollPiecePos_00722EB8[nSlot].nY - gnGlobal_007A285C, -1, nDrawMode, 0);

                D2CelContextStrc tFade;
                memset(&tFade, 0, sizeof(tFade));
                tFade.pCellFile = gpScroin3_007BF26C;
                tFade.nFrame = nTicks >= 21 ? 0 : nTicks;
                TEXTURE_CelDraw(&tFade, gaScrollFadePos_00722EE0[nSlot].nX + gnGlobal_007A2858, gaScrollFadePos_00722EE0[nSlot].nY - gnGlobal_007A285C, -1, 3, 0);
            }
        }
    }

    sub_00502EF0(nOldMode);
}

int sub_B05_Emit_004A4FA0(int* pIndex)
{
    int nA = sub_004A4FA0_GetEntryState(*pIndex, 1);
    int nB = sub_004A4FA0_GetEntryState(*pIndex, 0);
    return sub_B05_Sink(nA, nB);
}

int __cdecl sub_0040D530_Call0040C720()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}

// 0x004A5010
void __cdecl TEXT_ResetKeyConfigDefaults()
{
    CMDTBL_ResetKeyConfig(0);
}

// 0x004A5020
void __cdecl TEXT_AcceptKeyConfig()
{
    CMDTBL_SaveAndBindHotkeys();
    sub_00455F20(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl TEXT_CancelKeyConfig()
{
    sub_00469D50();
    sub_00455F20(11, 1, 0);
    WARDENCLIENT_ToggleEscMenuUIState(0, 1);
}

// 0x004A51E0
void __cdecl TEXT_FreeTextSliderCel()
{
    if (gpCelFile_007C02BC)
    {
        ARCHIVE_FreeClientCellFile(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x004A5200
void __fastcall TEXT_ToggleKeyConfigPanel(int nArg)
{
    TEXT_InitKeyConfigEntries();
    if (nArg)
    {
        if (gnGlobal_007C02B8 == 0)
        {
            CMDTBL_SaveHotkeys();
            sub_0046AA20(0, 0);
            GAME_UnregisterMouseHandlers();
            sub_00467A70_RefreshHoverUnit(0);
        }
        gnFirstVisible_007C02AC = 0;
        gnGlobal_007C02B0 = 0;
    }
    else if (gnGlobal_007C02B8 == 0)
    {
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        sub_00466FE0();
    }
    sub_004A5060();
}

int __fastcall AITHINK_BaalThroneCheckAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

void __fastcall sub_00600C60_CallFree(void* pMemory); // 0x00600C60

// 0x004A59D0
int __stdcall TEXT_KeyConfigWheelMsg(D2HotkeyActionStrc* pAction)
{
    if (GAME_IsExitPending())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        TEXT_ScrollKeyConfigList(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}

// 0x004A5C70
void __stdcall TEXT_CancelKeyConfigMsg(SMSGHANDLER_PARAMS* message)
{
    if (GAME_IsExitPending()) { message->bReturn = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            sub_00455F20(UI_VARIABLE, 1, 0);
            WARDENCLIENT_ToggleEscMenuUIState(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->bReturn = 1;
    message->lResult = 0;
    sub_00420290_BreakHandlerChain(message);
}

// 0x004A5D00
void __cdecl TEXT_RegisterKeyCaptureHandlers()
{
    gnGlobal_007C02B8 = 1;
    sub_00455AE0_CloseUIVar(0xB);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_00724738, 6);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_0072472C, 1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_00724780, 1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaMsgHandlers_0072478C, 1);
}

// 0x004A5DE0
void __cdecl TEXT_CloseKeyCaptureHandlers()
{
    if (gnGlobal_007C02B8)
    {
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_00724738, 6);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_0072478C, 1);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_00724780, 1);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMsgHandlers_0072472C, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        sub_00466FE0();
        gnGlobal_007C02B8 = 0;
    }
}

// 0x004A5E60
static void TEXT_ReleaseKeyConfigPress(int nX, int nY)
{
    if (gaPressed_007C0288[0])
    {
        if (TEXT_IsOnSelectedLine(nX, nY) && gpListEntries_00724264[gnGlobal_007C02B0].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed_007C0288[6])
    {
        const int nButton = gnPressedButton_007C02B4;
        if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
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
void __stdcall TEXT_KeyConfigButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    TEXT_ReleaseKeyConfigPress(nX, nY);
    gnGlobal_007C0280 = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6460
void __cdecl TEXT_LoadLevelCels()
{
    gpGlobal_007C02DC = sub_004520C0_LoadUiCelFile("Panel\\Level");
    gpGlobal_007C02E0 = sub_004520C0_LoadUiCelFile("Panel\\Levelsocket");
}

// 0x004A6480
void __cdecl TEXT_FreeLevelCels()
{
    if (gpGlobal_007C02DC)
    {
        ARCHIVE_FreeClientCellFile(gpGlobal_007C02DC);
        gpGlobal_007C02DC = 0;
    }
    if (gpGlobal_007C02E0)
    {
        ARCHIVE_FreeClientCellFile(gpGlobal_007C02E0);
        gpGlobal_007C02E0 = 0;
    }
}

// 0x004A64C0
void __cdecl TEXT_UpdateLevelUpButtons()
{
    if (GAME_GetUIVarState(0xB))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (GAME_GetUIVarState(6))
    {
        if (!STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
            sub_00455F20(6, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0) && !GAME_GetUIVarState(2))
            sub_00455F20(6, 0, 0);
    }
    if (GAME_GetUIVarState(7))
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) <= 0)
            sub_00455F20(7, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) > 0 && !GAME_GetUIVarState(4))
            sub_00455F20(7, 0, 0);
    }
}

// 0x004A65E0
int __cdecl TEXT_IsMouseOnStatButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 - 0xC2 && nX < gnGlobal_0071146C / 2 - 0xA0 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A6690
int __cdecl TEXT_IsMouseOnSkillButton()
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

    const int bInList = TEXT_IsInKeyConfigList(nX, nY);
    const int bUp = TEXT_IsOnUpArrow(nX, nY);
    const int bDown = TEXT_IsOnDownArrow(nX, nY);
    const int bPageUp = TEXT_IsAboveThumb(nX, nY);
    const int bThumb = TEXT_IsOnThumb(nX, nY);
    const int bPageDown = TEXT_IsBelowThumb(nX, nY);
    const int bButton = TEXT_GetKeyConfigButtonAt(nX, nY) != 3;

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
                TEXT_MoveKeyConfigSelection(-1);
            if (nY > nTop + 0x136)
                TEXT_MoveKeyConfigSelection(1);

            const int nOldD4 = gnGlobal_007246D4;
            const int nOldSelected = gnGlobal_007C02B0;
            const int nLine = TEXT_GetKeyConfigLineAt(nY);
            gnGlobal_007C02B0 = nLine;
            gnGlobal_007246D4 = TEXT_IsAbovePanelLine(nX);
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
            TEXT_ScrollKeyConfigList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed_007C0288[2] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            TEXT_ScrollKeyConfigList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed_007C0288[3] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            TEXT_ScrollKeyConfigList(1 - sub_F08_VisibleLines());
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
            TEXT_ScrollKeyConfigList((gnDragThumbY_007C02A4 - nTop - gnDragMouseY_007C02A8 + nY - 0x2F)
                * (gnThumbRange_007C027C + 1) / sub_F08_TrackSpan() - gnFirstVisible_007C02AC);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed_007C0288[5] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            TEXT_ScrollKeyConfigList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed_007C0288[6] = gnGlobal_007C0280;
        gnPressedButton_007C02B4 = TEXT_GetKeyConfigButtonAt(nX, nY);
    }
}

// 0x004A66E0
void __stdcall TEXT_StatButtonDownMsg(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && GAME_GetUIVarState(nResolution + 7))
    {
        return;
    }
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (TEXT_IsInPanelButton(border, x, y))
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (TEXT_IsMouseOnStatButton())
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->bReturn = 0;
}

static inline void MarkRightButtonPressed()
{
    gnPressed_007C02E8 = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}

// 0x004A6790
void __stdcall TEXT_SkillButtonDownMsg(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && GAME_GetUIVarState(nResolution + 7))
        return;
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (TEXT_IsInRightPanelButton(border, x, y))
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (TEXT_IsMouseOnSkillButton())
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && NPCMENU_IsNpcTalkActive()) return;
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
    return TEXT_IsInPanelButton(nMode, nX, nY);
}

// 0x004A6840
void __stdcall TEXT_StatButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && GAME_GetUIVarState(9))
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
    return TEXT_IsInRightPanelButton(nMode, nX, nY);
}

// 0x004A6920
void __stdcall TEXT_SkillButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && GAME_GetUIVarState(9))
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
        if (gnGlobal_007C02E8 && TEXT_IsMouseOnSkillButton())
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
bool __stdcall TEXT_IsStatButtonHidden(int nArg)
{
    if (nArg == 3)
        return true;
    if (GAME_GetUIVarState(2))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(1))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(4))
        return true;
    return (bool)GAME_GetUIVarState(0xC);
}

// 0x004A6B30
void __cdecl TEXT_DrawStatButton()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && TEXT_IsStatButtonHidden(nBorder))
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
    const int nCelWidth = CelGetWidth(CelGetHandle(&tContext));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF92), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && TEXT_IsInPanelButton(nBorder, sub_00468730(), sub_00468740()))
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
    CelGetWidth(CelGetHandle(&tContext));
    D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A65E0_IsInLeftButton() && !GAME_GetUIVarState(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF92), gnGlobal_0071146C / 2 - 0xB3, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xC2, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A6D50
bool __stdcall TEXT_IsSkillButtonHidden(int nArg)
{
    if (nArg == 3)
        return true;
    if (GAME_GetUIVarState(4))
        return true;
    if (GAME_GetUIVarState(0xC))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(1))
        return true;
    return false;
}

// 0x004A6E60
void __cdecl TEXT_DrawSkillButton()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && TEXT_IsSkillButtonHidden(nBorder))
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
    const int nCelWidth = CelGetWidth(CelGetHandle(&tContext));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF93), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
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
    CelGetWidth(CelGetHandle(&tContext));
    D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A6690_IsInRightButton() && !GAME_GetUIVarState(9))
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
static void TEXT_DrawBlockChanceHover(int nX, int nY, int nValue)
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
    int nLevel = UNITS_GetBlockRate(pPlayer, GAME_IsExpansion());
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

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(UI_GetHoverClassId());
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
    TEXT_DrawBlockChanceHover(nX, nY, nValue);
}

struct D2UnitStrc;

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7300
static int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate)
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

int __stdcall TEXT_GetChanceToHit(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPercent = 100;
    const int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = sub_00466DC0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !GAME_IsExpansion() && GAME_GetDifficulty())
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
int __fastcall TEXT_SplitAtNewline(Unicode* wszText, Unicode** ppNext)
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
void __cdecl TEXT_SetGoldDialogFlag()
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
    UI_DrawRectangleBorder(&tRect);

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
    const int nLines = PANEL_CountLinesInView(this);
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
            DrawClippedText(aLines[nLine].wszText0, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_800[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1000[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_1000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1800[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_1800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_2000[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_2000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText5[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText5, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
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
int ListBoxView::ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg)
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

#include "gen/data/Source/D2Client/UI/text_0049D490.inc"
