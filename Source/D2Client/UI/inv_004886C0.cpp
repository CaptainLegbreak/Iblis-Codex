#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"
#include "D2Records.h"
#include "D2ItemsWorld.h"

struct D2CelFileStrc;

struct D2UnitStrc;

typedef unsigned int size_t;

struct Unicode;

struct D2InventoryStrc;

#pragma pack(push, 2)

struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};

#pragma pack(pop)

#pragma pack(push, 1)

struct D2PanelTabStrc
{
    int nX;
    int nY;
    unsigned short nString;
    int bSelected;
    int bEnabled;
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                     // 0x00681EF0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall sub_004B3230_GetTickPair(int* pUnitId);                                                // 0x004B3230

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __stdcall sub_00483FF0_DrawUnitInventory(D2UnitStrc* pUnit);                                           // 0x00483FF0

D2CelFileStrc* __cdecl sub_00454600_GetBuySellButtonCells(); // 0x00454600

int __fastcall sub_00502EF0(int nFont);                                                                     // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820

int __cdecl sub_004B3500();                                                                                 // 0x004B3500

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

extern int gnGlobal_007BCBEC;                                                                               // 0x007BCBEC

static int gdwGlobal_007BCBF0; // 0x007BCBF0

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0

extern void* gpCelFile_007C0DC8;                                                                            // 0x007C0DC8

extern void* gpCellFile_007BCC24;                                                                           // 0x007BCC24

extern int gnGlobal_007A2858;                                                                               // 0x007A2858

extern int gnGlobal_007A285C;                                                                               // 0x007A285C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern int gnButtonCount_00722160;                                                                          // 0x00722160

extern int gnButtonRow_0072215C;                                                                            // 0x0072215C

extern int ganButtonX_00722168[][4];                                                                        // 0x00722168

extern int gnGlobal_00722158;                                                                               // 0x00722158

extern D2PanelTabStrc gaTabs_00722110[];                                                                    // 0x00722110

extern int gdwGlobal_007A6ABC;                                                                              // 0x007A6ABC

extern int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC

extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0

extern int gdwGlobal_007A6AF0;                                                                              // 0x007A6AF0

#pragma pack(push, 2)

#pragma pack(pop)

static int gnGlobal_007BCA4C; // 0x007BCA4C

static int gnGlobal_007BCBD8; // 0x007BCBD8

D2InvRectStrc gRect_007BCBB0; // 0x007BCBB0

#define gnGlobal_007BCBB0 (gRect_007BCBB0.nLeft)

#define gnGlobal_007BCBB4 (gRect_007BCBB0.nRight)

#define gnGlobal_007BCBBC (gRect_007BCBB0.nBottom)

D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620

D2BitBufferStrc* __cdecl sub_004B32D0();                                                                        // 0x004B32D0

unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0

int __stdcall ITEMS_GetAllRepairCosts(void* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void* pfCallback); // 0x0062FE60

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78

extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40

extern D2InventoryGridInfoStrc gGrid_007BCB88;                                                              // 0x007BCB88

static int gdwGlobal_007BCBE4;

static int gnGlobal_007BCC50; // 0x007BCC50

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                          // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __cdecl sub_00486D10_CheckTick();                                                                      // 0x00486D10

void __fastcall sub_0049FF90_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt);                            // 0x0049FF90

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                  // 0x004B9A00

int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem);                                                            // 0x004C1E20

void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem);                                                           // 0x004C21F0

int __fastcall sub_004C2240(D2UnitStrc* pItem);                                                            // 0x004C2240

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                             // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem);                                                             // 0x00628C70

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                             // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                 // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                 // 0x00648900

extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)

#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)

#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)

#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30

void __cdecl sub_00453EC0();                                                                                // 0x00453EC0

int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0

int __cdecl sub_00468830();                                                                                 // 0x00468830

void __cdecl sub_004835B0_LoadUiRecords();                                                                                // 0x004835B0

int __cdecl sub_00487BE0_ResetButtons();                                                                    // 0x00487BE0

int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

struct D2InvRectStrc;

int __cdecl sub_0045AE90();

D2UnitStrc* __cdecl sub_00463DD0();

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);

void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg);

int __cdecl sub_004979E0();

int __stdcall D2GFX_GetResolutionMode();

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_007BCA68;

extern int gnGlobal_007BCA6C;

extern int gnGlobal_007BCA74;

extern int gnGlobal_007BCA7C;

extern int gnGlobal_007BCA80;

extern int gnGlobal_007BCA84;

extern int gnGlobal_007BCA88;

extern int gnGlobal_007BCAF4;

extern int gnGlobal_007BCAF8;

extern int gnGlobal_007BCB00;

extern int gnGlobal_007BCB44;

extern int gnGlobal_007BCB48;

extern int gnGlobal_007BCB4C;

extern int gnGlobal_007BCB50;

int __cdecl sub_004680A0(); // 0x004680A0

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

extern D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30

extern int gnGlobal_007BCB74;

extern int gnGlobal_007BCB78;

extern int gnGlobal_007BCB7C;

extern int gnGlobal_007BCB80;

static int gdwGlobal_007BCBE8;

static int gnGlobal_007BCE18; // 0x007BCE18

static int gnGlobal_007BCE20; // 0x007BCE20

static int gnGlobal_007BCE30; // 0x007BCE30

static int gnGlobal_007BCE34; // 0x007BCE34

static int gnGlobal_007BCE38; // 0x007BCE38

static int gnGlobal_007BCE3C; // 0x007BCE3C

static int gbGlobal_007BCE90; // 0x007BCE90

static int gnGlobal_007BCE9C; // 0x007BCE9C

static int gnGlobal_007BCE40; // 0x007BCE40

static int gnGlobal_007BCE44; // 0x007BCE44

static int gnGlobal_007BCE48; // 0x007BCE48

static int gnGlobal_007BCE4C; // 0x007BCE4C

struct D2ClientTextDataStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2BitBufferStrc;

struct D2StaticPathStrc;

struct SMSGHANDLER_PARAMS;

struct D2ItemsTxt;

struct D2SetItemsTxt;

struct D2DataTablesStrc;

struct D2InventoryGridInfoStrc;

struct D2InvCompGridStrc;

struct D2NpcButtonStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

#pragma pack(push, 2)

struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    unsigned short nTextId;
    int nMode;
    unsigned short nKey;
    int nArg;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl sub_0044DA70(); // 0x0044DA70

void __fastcall sub_00454150_OpenGoldPanel(int nMode); // 0x00454150

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600


void __cdecl sub_004B8CB0(); // 0x004B8CB0

void __fastcall sub_004B9070(int nArg); // 0x004B9070

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

void __stdcall sub_00483E40_DrawItemSockets(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40

int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

extern int gnGlobal_00721E34; // 0x00721E34

extern int gnGlobal_00721E38; // 0x00721E38

extern int gnGlobal_00721E3C; // 0x00721E3C

extern int gnGlobal_00721E40; // 0x00721E40

extern int gnGlobal_00721E44; // 0x00721E44

extern int gnGlobal_00721E48; // 0x00721E48

extern int gnGlobal_00721E4C; // 0x00721E4C

extern int gnGlobal_00721E50; // 0x00721E50

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth_007A5220; // 0x007A5220

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2NpcButtonStrc gaNpcButtons_007BC9E0[4]; // 0x007BC9E0

extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18

extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70

extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58

void __cdecl sub_00487990_ResetHover(); // 0x00487990

int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

void __cdecl sub_004B3ED0(); // 0x004B3ED0

extern int gnGlobal_0072215C; // 0x0072215C

extern int gaButtonY_00722168[][4]; // 0x00722168

extern unsigned char gnGlobal_007BCC05; // 0x007BCC05

typedef char* va_list;

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __fastcall sub_0048BE00_CutBracketToken(Unicode* pString, const Unicode* pToken); // 0x0048BE00

void __fastcall sub_004834E0_ReplaceToken(Unicode* pString, int nIndex, const Unicode* pInsert); // 0x004834E0

D2InventoryGridInfoStrc gGrid_007BCB58; // 0x007BCB58

static D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4

static D2UnitStrc* gdwGlobal_007BCBF8; // 0x007BCBF8

static unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

static int gnGlobal_007BCC20; // 0x007BCC20

static int gnGlobal_007BCC40; // 0x007BCC40

static int gnGlobal_007BCC44; // 0x007BCC44

static int gnGlobal_007BCE1C; // 0x007BCE1C

static int gnGlobal_007BCE24; // 0x007BCE24

static int gnGlobal_007BCE2C; // 0x007BCE2C

static int gnGlobal_007BCE94; // 0x007BCE94

void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY); // 0x004839D0

void sub_00483A70_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70

void sub_004844A0_DrawBodyLocPlacement(D2InventoryStrc* pInventory); // 0x004844A0

void __stdcall sub_00487000_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid); // 0x00487000

void __cdecl sub_00488F10_OpenTradeFromButton(); // 0x00488F10

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId); // 0x004844A0

static int gnGlobal_007BCC48; // 0x007BCC48

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX);

static int sub_00489980_IsOverTransmuteButton(int nX, int nY);

static int sub_00489920_IsOverCloseButton(int nX, int nY);

static int sub_00486DA0_IsOverGoldButton(int nX, int nY);

// 0x00488400
void __cdecl sub_00488400_DrawPanel()
{
    if (gnGlobal_007BCBEC == 1)
    {
        gaPanelButtons_007BC9E0[0].nValue = 0;
        gaPanelButtons_007BC9E0[1].nValue = 0;
        gaPanelButtons_007BC9E0[2].nValue = 0;
        gaPanelButtons_007BC9E0[3].nValue = 0;
        gdwGlobal_007BCBF0 = 1;
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        gnGlobal_007BCBEC = 0;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCelFile_007C0DC8;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);

    int nUnitId;
    if (sub_004B3230_GetTickPair(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            sub_00483FF0_DrawUnitInventory(pUnit);
        }
    }

    tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        tContext.nFrame = gaPanelButtons_007BC9E0[i].nValue + gaPanelButtons_007BC9E0[i].nFrame;
        sub_004F6480(&tContext, ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858 - 1,
            gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, -1, 5, 0);
    }

    const int nOldFont = sub_00502EF0(1);
    for (int i = 0; i < gnGlobal_00722158; ++i)
    {
        int nColor = 0;
        if (gaTabs_00722110[i].bSelected)
        {
            nColor = 4;
        }
        if (gaTabs_00722110[i].bEnabled)
        {
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaTabs_00722110[i].nString);
            const int nWidth = sub_00501820(wszText);
            tContext.pCellFile = gpCellFile_007BCC24;
            if (nColor == 4)
            {
                tContext.nFrame = i;
            }
            else if (nColor == 0)
            {
                tContext.nFrame = i + 4;
            }
            sub_004F6480(&tContext, i * 0x50 + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x1C1, -1, 5, 0);
            if (!sub_004B3500())
            {
                sub_00502320(wszText, gaTabs_00722110[i].nX - nWidth / 2 + gnGlobal_007A2858,
                    gaTabs_00722110[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, nColor, 0);
            }
        }
    }
    sub_00502EF0(nOldFont);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004886C0
void __cdecl sub_004886C0_DrawButtonHoverText()
{
    if (gnGlobal_007BCA4C < gnGlobal_007BCBB0 || gnGlobal_007BCA4C > gnGlobal_007BCBB4)
    {
        return;
    }
    const int nTop = gnGlobal_00711470 + gnGlobal_007A285C - 0x6D;
    if (gnGlobal_007BCBD8 < nTop || gnGlobal_007BCBD8 > gnGlobal_007BCBBC)
    {
        return;
    }
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        if (gaPanelButtons_007BC9E0[i].bActive == 1
            && gnGlobal_007BCA4C > ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858
            && gnGlobal_007BCA4C < ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858 + 0x2D
            && gnGlobal_007BCBD8 > gnGlobal_00711470 + gnGlobal_007A285C - 0x6D
            && gnGlobal_007BCBD8 < gnGlobal_00711470 + gnGlobal_007A285C - 0x41)
        {
            if (gaPanelButtons_007BC9E0[i].nString == 0x276F)
            {
                Unicode wszText[0x100];
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                D2UnitStrc* pNpc = sub_004B1620_GetInteractNpc();
                if (pPlayer && pNpc)
                {
                    const int nNpcClass = pNpc->dwClassId;
                    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x276F),
                        ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, sub_0044DCD0_GetDifficulty(), sub_004B32D0(), 0));
                    D2Win_10129_DrawFramedText(wszText, ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858,
                        gnGlobal_00711470 + gnGlobal_007A285C - 0x64, 0, 0);
                }
            }
            else
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(gaPanelButtons_007BC9E0[i].nString),
                    ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x64, 0, 0);
            }
            return;
        }
    }
}

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gInvRect_007BCAA0.nLeft && nX < gInvRect_007BCAA0.nRight && nY >= gInvRect_007BCAA0.nTop && nY <= gInvRect_007BCAA0.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
{
    if (nX > gGrid_007BCB18.nGridLeft && nX < gGrid_007BCB18.nGridRight && nY >= gGrid_007BCB18.nGridTop && nY <= gGrid_007BCB18.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B10_IsInGrid7BCA30(int nX, int nY)
{
    if (nX > gGrid_007BCA30.nGridLeft && nX < gGrid_007BCA30.nGridRight && nY >= gGrid_007BCA30.nGridTop && nY <= gGrid_007BCA30.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B40_IsInCubeGrid(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gGrid_007BCA78.nGridLeft && nX <= gGrid_007BCA78.nGridRight && nY >= gGrid_007BCA78.nGridTop && nY <= gGrid_007BCA78.nGridBottom)
        {
            return 1;
        }
        return 0;
    }
    if (nX > gGrid_007BCB40.nGridLeft && nX <= gGrid_007BCB40.nGridRight && nY >= gGrid_007BCB40.nGridTop && nY <= gGrid_007BCB40.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BF0_IsInGrid7BCB70(int nX, int nY)
{
    if (nX >= gGrid_007BCB70.nGridLeft && nX < gGrid_007BCB70.nGridRight && nY >= gGrid_007BCB70.nGridTop && nY <= gGrid_007BCB70.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static void __stdcall sub_00483C50_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem)
{
    if (nPage == 0xFF)
    {
        return;
    }
    D2UnitStrc* pOther = 0;
    if (!pCursorItem || !gdwGlobal_007BCBE4)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    if (gnGlobal_00721E4C < 0 || gnGlobal_00721E50 < 0)
    {
        return;
    }
    if (gdwGlobal_007BCBF0 == 1 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    if (gdwGlobal_007BCBF0 == 0x13 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &nOutX, &nOutY, nPage))
    {
        sub_004839D0_DrawGridCells(pGrid, gnGlobal_00721E4C, 1, nWidth, nHeight, gnGlobal_00721E50);
        return;
    }
    if (!INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnGlobal_00721E4C, gnGlobal_00721E50, nRecord, &pOther, nPage, 1)
        && (!pOther || DATATBLS_GetItemsTxtRecord(pOther->dwClassId)->dwCode != 0x20786F62))
    {
        sub_004839D0_DrawGridCells(pGrid, gnGlobal_00721E4C, 0, nWidth, nHeight, gnGlobal_00721E50);
        return;
    }
    unsigned char nOtherWidth;
    unsigned char nOtherHeight;
    ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004839D0_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), 3, nOtherWidth, nOtherHeight, CLIENTS_GetUnitY(pOther));
}

static int sub_00483F80_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x25, 8) || QUESTRECORD_GetQuestState(sub_004B32D0(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall sub_00483FF0_DrawUnitInventory(D2UnitStrc* pUnit)
{
    sub_004835B0_LoadUiRecords();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 1:
        pGrid = &gGrid_007BCB58;
        break;
    case 0:
        switch (gnSelectedTab_007BCC04)
        {
        case 1:
            pGrid = &gGrid_007BCB18;
            break;
        case 2:
            pGrid = &gGrid_007BCA30;
            break;
        case 4:
            pGrid = sub_0044DCC0() ? &gGrid_007BCA78 : &gGrid_007BCB40;
            break;
        case 3:
            pGrid = &gGrid_007BCB70;
            break;
        default:
            pGrid = &gGrid_007BCB88;
            break;
        }
        break;
    default:
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab_007BCC04, sub_0044DCC0());
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (!pItem || INVENTORY_GetItemNodePage(pNode) != 1)
        {
            continue;
        }
        int nX;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nX = PATH_GetXPosition(pItem->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        int nY;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pItem->pStaticPath->nYPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nY = PATH_GetYPosition(pItem->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab_007BCC04)
        {
            continue;
        }
        if (pItem == gdwGlobal_007BCBF4 && gdwGlobal_007BCBE4)
        {
            if (sub_00468830() == 8 && !ITEMS_GetTransmogrify(gdwGlobal_007BCBF4))
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 0, nWidth, nHeight, nY);
            }
            else
            {
                sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
            }
            sub_0046EE80_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, ".\\UI\\inv.cpp"))
            {
                sub_00483E40_DrawItemSockets(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            continue;
        }
        int nColor = 0;
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, ".\\UI\\inv.cpp")
            && !sub_004C2240(pItem) && ITEMS_CanBeEquipped(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, ".\\UI\\inv.cpp"))
            {
                nColor = 4;
            }
            else
            {
                nColor = 2;
                D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                if (pItemsTxt->nQuest && sub_00483F80_IsUnusableQuestBook(pItemsTxt))
                {
                    nColor = 0;
                }
            }
        }
        sub_004839D0_DrawGridCells(pGrid, nX, nColor, nWidth, nHeight, nY);
        sub_0046EE80_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
    }
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pPlayer->pInventory);
    if (!pCursorItem)
    {
        return;
    }
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    switch (gdwGlobal_007BCBF0)
    {
    case 0xB:
        if (gnSelectedTab_007BCC04 == 1)
        {
            return;
        }
        if (gnSelectedTab_007BCC04 == 2)
        {
            if (!sub_00483B10_IsInGrid7BCA30(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xC:
    case 0xD:
        if (gnSelectedTab_007BCC04 == 4)
        {
            if (!sub_00483B40_IsInCubeGrid(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xE:
        if (gnSelectedTab_007BCC04 == 3)
        {
            if (!sub_00483BF0_IsInGrid7BCB70(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    default:
        if (!sub_00483AB0_IsInInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    }
    sub_00483C50_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab_007BCC04, pCursorItem);
}

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gdwGlobal_007BCBF0 == 0xA || gdwGlobal_007BCBF0 == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids_007BCC58[5].rect.nLeft && nX <= gaCompGrids_007BCC58[5].rect.nRight && nY >= gaCompGrids_007BCC58[5].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids_007BCC58[4].rect.nLeft && nX <= gaCompGrids_007BCC58[4].rect.nRight && nY >= gaCompGrids_007BCC58[4].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00486E60_ClickOutsidePanel(pMsg->nYpos, pMsg, pMsg->nXpos);
}

void __stdcall sub_00486EF0_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_00498DC0_MouseMoveMsg(pMsg))
    {
        if (sub_00486E10_IsInNpcPanelRect(nX, nY))
        {
            sub_00455F20(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gnGlobal_007BCE30 && !gdwGlobal_007BCBF0)
    {
        gnGlobal_007BCE30 = 0;
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
        {
            sub_00454150_OpenGoldPanel(1);
        }
    }
    sub_0044DA70();
    if (sub_00483AB0_IsInInvRect(nX, nY) && !sub_00498DC0_MouseMoveMsg(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

static void __stdcall sub_00487230_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gnGlobal_007BCC20 = nBodyLoc;
        gdwGlobal_007BCBE8 = 1;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        return;
    }
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc);
    if ((nBodyLoc == 4 || nBodyLoc == 5) && bTwoHanded)
    {
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!pOther)
        {
            pOther = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 5);
        }
        if (pOther && pItem && !ITEMSIsA(pOther, 0x23) && !ITEMSIsA(pItem, 0x23)
            && !ITEMSIsA(pOther, 0x1B) && !ITEMSIsA(pItem, 0x1B))
        {
            pItem = pOther;
        }
        if (pOther && !pItem && gdwGlobal_007BCBF0 == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gdwGlobal_007BCBE8 = 1;
        if (pItem == gdwGlobal_007BCBF8)
        {
            return;
        }
        const int nLeft = (gaCompGrids_007BCC58[nBodyLoc].rect.nRight + gaCompGrids_007BCC58[nBodyLoc].rect.nLeft) / 2;
        gnGlobal_00721E3C = nLeft;
        gnGlobal_00721E44 = nLeft;
        gdwGlobal_007BCBF4 = pItem;
        gdwGlobal_007BCBF8 = pItem;
        gnGlobal_00721E40 = gaCompGrids_007BCC58[nBodyLoc].rect.nTop;
        gnGlobal_00721E48 = gaCompGrids_007BCC58[nBodyLoc].rect.nBottom;
        return;
    }
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

void __stdcall sub_004873A0_HandleClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnGlobal_00721E34)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_004835B0_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00483AB0_IsInInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gGrid_007BCB88);
            gnGlobal_007BCC20 = 0;
            gnGlobal_00721E38 = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids_007BCC58[nBodyLoc].rect.nLeft && nX <= gaCompGrids_007BCC58[nBodyLoc].rect.nRight && nY >= gaCompGrids_007BCC58[nBodyLoc].rect.nTop && nY <= gaCompGrids_007BCC58[nBodyLoc].rect.nBottom)
            {
                sub_00487230_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gnGlobal_00721E38 = 1;
                return;
            }
        }
        gnGlobal_007BCC20 = 0;
        pMsg->bReturn = 0;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483AE0_IsInGrid7BCB18(nX, nY))
        {
            gnSelectedTab_007BCC04 = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gGrid_007BCB18);
            bHandled = 1;
        }
        else if (sub_00483B10_IsInGrid7BCA30(nX, nY))
        {
            gnSelectedTab_007BCC04 = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gGrid_007BCA30);
            bHandled = 1;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483B40_IsInCubeGrid(nX, nY))
        {
            gnSelectedTab_007BCC04 = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (sub_0044DCC0())
            {
                sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gGrid_007BCA78);
            }
            else
            {
                sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gGrid_007BCB40);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        if (sub_00483BF0_IsInGrid7BCB70(nX, nY))
        {
            gnSelectedTab_007BCC04 = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            sub_00487000_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gGrid_007BCB70);
        }
        else
        {
            pMsg->bReturn = 0;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        gnSelectedTab_007BCC04 = nOldTab;
        gnGlobal_00721E38 = 1;
        return;
    }
    if (sub_004538D0(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
    gnGlobal_00721E38 = 0;
}

int __cdecl sub_00487BE0_ResetButtons()
{
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
    return 1;
}

int __cdecl sub_004888C0_CanUseCursor()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4 || gdwGlobal_007BCBF0 == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall sub_004889D0_TradeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0 || gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnGlobal_007BCA4C = nX;
        gnGlobal_007BCBD8 = nY;
        if (sub_004680A0() && nX >= gRect_007BCBB0.nLeft && nX <= gRect_007BCBB0.nRight && nY >= gRect_007BCBB0.nTop && nY <= gRect_007BCBB0.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gdwGlobal_007BCBF0 && sub_004B3230_GetTickPair(&nUnitId))
        {
            D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gRect_007BCBB0.nLeft && nX <= gRect_007BCBB0.nRight && nY >= gRect_007BCBB0.nTop && nY <= gRect_007BCBB0.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gGrid_007BCB58.nGridLeft && nX <= gGrid_007BCB58.nGridRight && nY >= gGrid_007BCB58.nGridTop && nY <= gGrid_007BCB58.nGridBottom)
                    {
                        sub_00487000_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab_007BCC04, &gGrid_007BCB58);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gnGlobal_00721E38 = 0;
                        return;
                    }
                }
            }
        }
        sub_004873A0_HandleClick(pMsg);
    }
}

static void sub_00488E10_SelectButtonByKey(int nKey)
{
    gaNpcButtons_007BC9E0[0].bActive = gaNpcButtons_007BC9E0[0].nKey == nKey;
    gaNpcButtons_007BC9E0[1].bActive = gaNpcButtons_007BC9E0[1].nKey == nKey;
    gaNpcButtons_007BC9E0[2].bActive = gaNpcButtons_007BC9E0[2].nKey == nKey;
    gaNpcButtons_007BC9E0[3].bActive = gaNpcButtons_007BC9E0[3].nKey == nKey;
}

static int sub_00489430_IsOverButtonA(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0xDF && nX < gnGlobal_007A2858 + 0xFF
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

static int sub_00489480_IsOverButtonB(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x133
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

void __stdcall sub_00489580_StashMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xB)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!sub_00483B10_IsInGrid7BCA30(nX, nY))
    {
        if (sub_00489430_IsOverButtonA(nX, nY))
        {
            if (gnGlobal_007BCE18 && gnGlobal_007BCE20)
            {
                sub_004B9070(0);
            }
            gnGlobal_007BCE9C = 0;
            gnGlobal_007BCE20 = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (sub_00489480_IsOverButtonB(nX, nY))
        {
            if (gnGlobal_007BCE1C && gnGlobal_007BCE24)
            {
                sub_004B8CB0();
                gnGlobal_007BCE1C = 0;
            }
            gnGlobal_007BCE24 = 0;
            gnGlobal_007BCE9C = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
        {
            gnGlobal_007BCE20 = 0;
            gnGlobal_007BCE18 = 0;
            gnGlobal_007BCE9C = 0;
            gnGlobal_007BCE1C = 0;
            return;
        }
        if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
        {
            sub_00454150_OpenGoldPanel(2);
        }
        if (gnGlobal_007BCE9C)
        {
            const int bFlag = gnGlobal_007BCE20;
            gnGlobal_007BCE9C = 0;
            if (bFlag)
            {
                if (gnGlobal_007BCE18 == 1)
                {
                    gnGlobal_007BCE18 = 0;
                    sub_004B90B0_SendState();
                }
            }
            else if (gnGlobal_007BCE24 && gnGlobal_007BCE1C)
            {
                gnGlobal_007BCE1C = 0;
            }
            gnGlobal_007BCE24 = 0;
            gnGlobal_007BCE20 = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gnGlobal_007BCE18)
    {
        sub_004B90B0_SendState();
    }
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE1C = 0;
    gnGlobal_007BCE18 = 0;
}

void __stdcall sub_00489A30_CubeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xC || gdwGlobal_007BCBF0 == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnGlobal_007BCA4C = nX;
        gnGlobal_007BCBD8 = nY;
        if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483B40_IsInCubeGrid(nX, nY))
        {
            sub_004873A0_HandleClick(pMsg);
            return;
        }
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    }
}

void __stdcall sub_00489AC0_CubeClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xC && gdwGlobal_007BCBF0 != 0xD)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if ((!sub_004979E0() || !sub_00498DC0_MouseMoveMsg(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_00455F20(0x19, 1, 0);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        if (gnGlobal_007BCE38)
        {
            gnGlobal_007BCE38 = 0;
            sub_00455F20(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
        }
        gnGlobal_007BCE3C = 0;
        gnGlobal_007BCE9C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gnGlobal_007BCE38 = 0;
    gnGlobal_007BCE3C = 0;
    if (!sub_004979E0() && sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(3);
    }
    if (sub_00489920_IsOverCloseButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(4);
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    gnGlobal_007BCE34 = 0;
    gnGlobal_007BCE30 = 0;
    if (gnGlobal_007BCE9C)
    {
        const int bFlag = gnGlobal_007BCE20;
        gnGlobal_007BCE9C = 0;
        if (bFlag)
        {
            if (gnGlobal_007BCE18 == 1)
            {
                gnGlobal_007BCE18 = 0;
            }
        }
        else if (gnGlobal_007BCE3C && gnGlobal_007BCE38)
        {
            gnGlobal_007BCE38 = 0;
        }
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE38 = 0;
    gnGlobal_007BCE18 = 0;
}

static void sub_004865D0_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gdwGlobal_007BCBF4, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gdwGlobal_007BCBF4, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

static D2UnitStrc* sub_00486770_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
        {
            const unsigned char nPage = ITEMS_GetInvPage(pItem);
            if (nPage == 0 || nPage == 3 || nPage == 4 || nPage == 0xFF)
            {
                const int nNodePage = INVENTORY_GetItemNodePage(pNode);
                if (nNodePage == 1 || nNodePage == 3 || nNodePage == 4)
                {
                    const int nFileIndex = ITEMS_GetFileIndex(pItem);
                    D2SetItemsTxt* pSetItemsTxt = (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nFileIndex] : 0;
                    if (pSetItemsTxt && pSetItemsTxt->wSetItemId == nSetItemId)
                    {
                        return pItem;
                    }
                }
            }
        }
    }
    return 0;
}

void __cdecl sub_00487990_ResetHover()
{
    gnGlobal_00721E3C = -1;
    gnGlobal_00721E40 = -1;
    gnGlobal_00721E44 = -1;
    gnGlobal_00721E48 = -1;
    gnGlobal_00721E4C = -1;
    gnGlobal_00721E50 = -1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

static inline int sub_00488B00_PanelTop()
{
    return gnGlobal_00711470 + gnGlobal_007A285C - 0x6D;
}

// 0x00488B00
void __stdcall sub_00488B00_NpcPanelButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    if (sub_004680A0())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gnGlobal_007BCE9C == 1)
    {
        int bClicked = 0;
        if (nX >= gRect_007BCBB0.nLeft && nX <= gRect_007BCBB0.nRight
            && nY >= sub_00488B00_PanelTop() && nY <= gRect_007BCBB0.nBottom)
        {
            for (int i = 0; i < gnButtonCount_00722160; ++i)
            {
                D2NpcButtonStrc* pButton = &gaNpcButtons_007BC9E0[i];
                if (pButton->nId != 1)
                {
                    continue;
                }

                if (gnGlobal_007BCA4C > gnGlobal_007A2858 + gaButtonY_00722168[gnGlobal_0072215C][i]
                    && gnGlobal_007BCA4C < gnGlobal_007A2858 + gaButtonY_00722168[gnGlobal_0072215C][i] + 0x2D
                    && gnGlobal_007BCBD8 > sub_00488B00_PanelTop()
                    && gnGlobal_007BCBD8 < sub_00488B00_PanelTop() + 0x2C
                    && pButton->bActive == 1)
                {
                    if (pButton->nMode == 9)
                    {
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        sub_00420290_BreakHandlerChain(pMsg);
                        gnGlobal_007BCE9C = 0;
                        D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
                        if (!INVENTORY_GetCursorItem(pPlayerInventory))
                        {
                            sub_00468070_SetCursorItemState(0);
                        }
                        sub_004B3ED0();
                        gnGlobal_007BCA4C = 0;
                        gnGlobal_007BCBD8 = 0;
                        return;
                    }

                    gdwGlobal_007BCBF0 = pButton->nMode;
                    D2_ASSERT(gnGlobal_007BCC05 < 5, 0x22E0);
                    const unsigned short nKey = pButton->nKey;
                    if (nKey == 0x0E)
                    {
                        sub_00487990_ResetHover();
                        bClicked = 0;
                    }
                    else if (nKey == 0x0C)
                    {
                        sub_00487990_ResetHover();
                        bClicked = 0;
                    }
                    else
                    {
                        bClicked = 1;
                        if (nKey == 0x12)
                        {
                            gnGlobal_007BCC48 = 1;
                            sub_004B3870_HandleTradeClick(sub_00463DD0_GetPlayerUnit(), 0, 1, nX, nY, 0, 1, 1);
                            gnGlobal_007BCC48 = 0;
                        }
                        else
                        {
                            sub_00468040(pButton->nArg, 0);
                            gnGlobal_007BCC40 = i;
                            gnGlobal_007BCC44 = pButton->nKey;
                        }
                    }
                }
            }
        }

        if (!bClicked)
        {
            if (sub_004888C0_CanUseCursor())
            {
                D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
                sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
            }

            for (int i = 0; i < gnButtonCount_00722160; ++i)
            {
                if (gaNpcButtons_007BC9E0[i].bActive == 1)
                {
                    gaNpcButtons_007BC9E0[i].bActive = 0;
                }
            }
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE9C = 0;
    }

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
        sub_004B3ED0();
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048BE80
void __cdecl sub_0048BE80_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...)
{
    if (pFormat)
    {
        int nCount;
        Unicode aArgs[10][200];
        nCount = 0;
        va_list args;
        va_start(args, pFormat);
        const Unicode* pArg = va_arg(args, const Unicode*);
        while (pArg)
        {
            sub_005267E0(aArgs[nCount], pArg);
            ++nCount;
            pArg = va_arg(args, const Unicode*);
        }

        const Unicode* pSource;
        Unicode* pColon = Unicode::strchr(pFormat, Unicode(':'));
        if (pColon)
        {
            Unicode wszMs[5] = { '[', 'm', 's', ']', 0 };
            int nA = -1;
            const Unicode* pMark = Unicode::strchr(pFormat, Unicode('a'));
            if (pMark && pMark < pColon)
            {
                nA = pMark[1].wChar - '0';
            }
            int nN = -1;
            pMark = Unicode::strchr(pFormat, Unicode('n'));
            if (pMark && pMark < pColon)
            {
                nN = pMark[1].wChar - '0';
            }

            if (nA != -1)
            {
                if (nN != -1)
                {
                    Unicode wszTemp[5];
                    if (aArgs[nN][0].wChar == '[')
                    {
                        Unicode::strncpy(wszTemp, aArgs[nN], 4);
                        sub_005267E0(aArgs[nN], &aArgs[nN][4]);
                    }
                    else
                    {
                        sub_005267E0(wszTemp, wszMs);
                    }
                    if (aArgs[nA][0].wChar == '[')
                    {
                        sub_0048BE00_CutBracketToken(aArgs[nA], wszTemp);
                    }
                }
                else
                {
                    sub_0048BE00_CutBracketToken(aArgs[nA], wszMs);
                }
            }
            else if (nN != -1)
            {
                sub_005267E0(aArgs[nN], &aArgs[nN][4]);
            }
            pSource = pColon + 1;
        }
        else
        {
            pSource = pFormat;
        }
        sub_005267E0(pDest, pSource);

        for (int i = 0; i < nCount; ++i)
        {
            sub_004834E0_ReplaceToken(pDest, i, aArgs[i]);
        }
    }
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gGrid_007BCB88.nGridLeft) / gGrid_007BCB88.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB88.nGridTop) / gGrid_007BCB88.nGridBoxHeight;
    }
    else if (sub_0044DCC0())
    {
        nGridX = (nX - gGrid_007BCA78.nGridLeft) / gGrid_007BCA78.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCA78.nGridTop) / gGrid_007BCA78.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gGrid_007BCB40.nGridLeft) / gGrid_007BCB40.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB40.nGridTop) / gGrid_007BCB40.nGridBoxHeight;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && ITEMS_GetTransmogrify(pItem))
        {
            if (!sub_004C2240(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0_SetState36(pItem);
                return 1;
            }
        }
        else if (ITEMS_CheckIfUseable(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
            {
                if (sub_004538D0(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gnGlobal_007BCC50 = 1;
                }

                sub_004786D0_SendDwords3(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0_SetState36(pItem);
                sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
                gdwGlobal_007BCBE4 = 0;
                return 1;
            }
        }
        else if (ITEMS_GetUniqueColumnFromItemsTxt(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                sub_0049FF90_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x004917C0
void __stdcall sub_004917C0_OnGridClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPlayer;
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_004835B0_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (sub_00498DC0_MouseMoveMsg(pMsg) || nX < gnGlobal_007BCAA0 || nX >= gnGlobal_007BCAA4 || nY < gnGlobal_007BCAA8 || nY > gnGlobal_007BCAAC)
    {
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
    {
        if (sub_00487740_ClickGridItem(pPlayer, pInventory, nX, nY, 0))
        {
            if (gdwGlobal_007BCBF0 >= 2 && gdwGlobal_007BCBF0 <= 4)
            {
                sub_00487BE0_ResetButtons();
            }
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        pMsg->bReturn = 0;
    }

    if (gdwGlobal_007BCBF0)
    {
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if ((unsigned int)(gdwGlobal_007BCBF0 - 2) <= 2)
        {
            sub_00487BE0_ResetButtons();
        }
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
            return;
        }

        if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
        }
    }
}

static int sub_00483B40_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_00486AE0_GetPanelX()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_007A2858 + 0x113;
    }
    return gnGlobal_007A2858 + 0x110;
}

int __cdecl sub_00486B00_GetPanelY()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x41;
    }
    return gnGlobal_007A285C + gnGlobal_00711470 - 0x40;
}

static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
    {
        return 0;
    }
    if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x57 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x45
        && nX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0xED && nX <= gnGlobal_0071146C - gnGlobal_007A2858 - 0xD9)
    {
        return 1;
    }
    return 0;
}

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E || nX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E)
    {
        return 0;
    }
    if (nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x60 || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 0;
    }
    return 1;
}

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        return;
    }
    if (nY > gnGlobal_00711470 - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
    }
    if (sub_0045AE90() == 3 && gdwGlobal_007BCBF0 == 0 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static int sub_00489920_IsOverCloseButton(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x1C7 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6
            && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x103 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0xF2
        && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
    {
        return 1;
    }
    return 0;
}

static int sub_00489980_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > sub_00486AE0_GetPanelX() && nX < sub_00486AE0_GetPanelX() + 0x28
        && nY > sub_00486B00_GetPanelY() - 0x23 && nY < sub_00486B00_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00492510
void __stdcall sub_00492510_CubeButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xC && gdwGlobal_007BCBF0 != 0xD)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if ((!sub_004979E0() || !sub_00498DC0_MouseMoveMsg(pMsg)) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        gnGlobal_007BCE3C = 1;
        gnGlobal_007BCE38 = 1;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483AB0_IsInInvRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483B40_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483BA0_IsInRect(nX, nY))
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE3C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_00486E60_ClickOutsidePanel(nY, pMsg, nX);
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE3C = 0;
}

static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        return 1;
    }
    return 0;
}

static int sub_0048A000_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x90 && nX < gnGlobal_007A2858 + 0xB8
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0xDF && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x004927C0
void __stdcall sub_004927C0_CubeButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xE)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489FB0_IsOverButtonC(nX, nY))
    {
        gnGlobal_007BCE44 = 1;
        gnGlobal_007BCE40 = 1;
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_0048A000_IsOverCubeButton(nX, nY))
    {
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE40 = 0;
        if (!sub_004680A0())
        {
            gnGlobal_007BCE4C = 1;
            gnGlobal_007BCE48 = 1;
            gnGlobal_007BCE9C = 1;
            pMsg->bReturn = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE4C = 0;
        return;
    }
    if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483BF0_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE48 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE4C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!pMsg->bReturn)
    {
        sub_00486E60_ClickOutsidePanel(nY, pMsg, nX);
    }
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE44 = 0;
    gnGlobal_007BCE4C = 0;
}

#include "gen/data/Source/D2Client/UI/inv_004886C0.inc"
