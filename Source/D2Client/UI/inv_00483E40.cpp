#include "D2Client.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2Primitives.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2ItemsWorld.h"

struct D2ClientCacheEntryStrc
{
    unsigned char unk0x00[0x4C];
    unsigned char bLocked;
    unsigned char unk0x4D[0x2F];
    unsigned char dwLastUse[4];
    unsigned char unk0x80[0x0A];
    unsigned char nRefCount[4];
};

struct D2ClientStateStrc
{
    char unk0x00[0x11D];
    unsigned char bFlag0x11D;
    char unk0x11E[0x0B];
    unsigned char bFlag0x129;
    unsigned char bFlag0x12A;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290

void __cdecl GAME_ResetMouseButtons();                                                                                // 0x0044DA70

int __fastcall UI_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070

int __cdecl sub_00468730();                                                                                 // 0x00468730

int __cdecl sub_00468740();                                                                                 // 0x00468740

int __cdecl ROSTER_IsAnyoneHostile();                                                                                 // 0x0047A560

void __fastcall SOUNDHDR_ReleaseCacheEntry(int nId);                                                    // 0x004823E0

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004873A0

void __cdecl INV_ResetHover();                                                                     // 0x00487990

void __fastcall sub_0049FF90_Close(int nArg, D2ClientStateStrc* pState);                                    // 0x0049FF90

int __cdecl NPCMENU_IsAnyDialogOpen();                                                                                 // 0x004B34A0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId);                                                // 0x004B3230

void __cdecl NPCMENU_CloseNpcShop();                                                                                // 0x004B3ED0

void __fastcall UNITSND_PlayPlayerSpeech(int nArg, int nId);                                                    // 0x004CB9C0

int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970

extern int gnScreenWidth;                                                                               // 0x0071146C

extern int gnScreenHeight;                                                                               // 0x00711470

extern D2ClientTabStrc gaNpcTabStates[];                                                                   // 0x0072211A

extern int gnHoverTopX;                                                                               // 0x00721E3C

extern int gnHoverTopY;                                                                               // 0x00721E40

extern int gnHoverBottomX;                                                                               // 0x00721E44

extern int gnHoverBottomY;                                                                               // 0x00721E48

extern int gnHoverCellX;                                                                               // 0x00721E4C

extern int gnHoverCellY;                                                                               // 0x00721E50

extern D2ClientCacheEntryStrc* sgptSoundHeaderTable;                                                     // 0x007BC9A0

extern int gnCacheEntries_007BC9A4;                                                                         // 0x007BC9A4

extern D2ClientCacheNodeStrc* gpCacheList;                                                         // 0x007BC9B8

unsigned int gdwSoundTick; // 0x007BC9BC

extern unsigned int gdwCacheUsed;                                                                  // 0x007BC9D0

int gnInvMouseX;                                                                                      // 0x007BCA4C

D2InvRectStrc gtPlayerInvRect;                                                                            // 0x007BCAA0

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

extern D2InventoryGridInfoStrc gtTradePage2Grid;                                                              // 0x007BCA30

#define gnGlobal_007BCA34 (gtTradePage2Grid.nGridLeft)

#define gnGlobal_007BCA38 (gtTradePage2Grid.nGridRight)

#define gnGlobal_007BCA3C (gtTradePage2Grid.nGridTop)

#define gnGlobal_007BCA40 (gtTradePage2Grid.nGridBottom)

D2InventoryGridInfoStrc gtTradePage1Grid;                                                                     // 0x007BCB18

extern D2InventoryGridInfoStrc gtCubeGrid;                                                              // 0x007BCB70

#define gnGlobal_007BCB74 (gtCubeGrid.nGridLeft)

#define gnGlobal_007BCB78 (gtCubeGrid.nGridRight)

#define gnGlobal_007BCB7C (gtCubeGrid.nGridTop)

#define gnGlobal_007BCB80 (gtCubeGrid.nGridBottom)

int gnInvMouseY;                                                                                      // 0x007BCBD8

extern int gbNpcUiRecordsLoaded;                                                                               // 0x007BCBE0

static int gbHoverInGrid; // 0x007BCBE4

static int gbHoverInBodyLoc; // 0x007BCBE8

static int gnInvPanelMode; // 0x007BCBF0

static D2UnitStrc* gpHoverItem; // 0x007BCBF4

static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

static unsigned char gnSelectedTab; // 0x007BCC04

unsigned char gnMaxTab;                                                                            // 0x007BCC05

int gdwNpcPanelDelayTick;                                                                                      // 0x007BCC08

int gbPanelButtonClicked;                                                                                      // 0x007BCE9C

unsigned char gabSlots[4];                                                                         // 0x007BEFB4

#define gnGlobal_007BCA68 (gtBankRect.nLeft)

#define gnGlobal_007BCA6C (gtBankRect.nRight)

#define gnGlobal_007BCA74 (gtBankRect.nBottom)

#define gnGlobal_007BCA7C (gtBigBankGrid.nGridLeft)

#define gnGlobal_007BCA80 (gtBigBankGrid.nGridRight)

#define gnGlobal_007BCA84 (gtBigBankGrid.nGridTop)

#define gnGlobal_007BCA88 (gtBigBankGrid.nGridBottom)

#define gnGlobal_007BCAF4 (gtBigBankRect.nLeft)

#define gnGlobal_007BCAF8 (gtBigBankRect.nRight)

#define gnGlobal_007BCB00 (gtBigBankRect.nBottom)

#define gnGlobal_007BCB44 (gtBankGrid.nGridLeft)

#define gnGlobal_007BCB48 (gtBankGrid.nGridRight)

#define gnGlobal_007BCB4C (gtBankGrid.nGridTop)

#define gnGlobal_007BCB50 (gtBankGrid.nGridBottom)

struct Unicode;

struct D2InvRectStrc;

struct D2InventoryGridInfoStrc;

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

void __fastcall SOUNDHDR_UpdateCache(unsigned int nTick); // 0x00482B40

void __fastcall sub_004BA020(unsigned int nTick); // 0x004BA020

void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int nTick); // 0x004DCAA0

int __cdecl sub_004DF870(); // 0x004DF870

void __cdecl sub_004DF890(); // 0x004DF890

void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int nTick); // 0x004E42E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern char gbCinematicStop; // 0x007BC9D4

extern char gbCinematicWide; // 0x007BC9D6

extern char gbCinematicBusy; // 0x007BC9D7

extern char gbCinematicChain; // 0x007BC9D8

static unsigned char INV_GetFlagIndex(unsigned char nFlags);

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

extern D2InvRectStrc gtBankRect; // 0x007BCA68

extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78

extern D2InvRectStrc gtBigBankRect; // 0x007BCAF4

extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40

D2InvRectStrc gtCubeRect; // 0x007BCB30

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

struct D2CelFileStrc;

struct D2StaticPathStrc;

struct D2SetItemsTxt;

struct D2InvCompGridStrc;

struct D2NpcButtonStrc;

struct D2ItemFormulaRecordStrc;

struct D2PanelButtonStrc;

extern const D2CoordStrc gSocketLayouts[][6]; // 0x006D91E8

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_GetDimensions(D2UnitStrc*, unsigned char*, unsigned char*, const char*, int); // 0x006286C0

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

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

int __cdecl GAME_IsExitPending(); // 0x0044DA30

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

void __fastcall UI_OpenGoldPanel(int nMode); // 0x00454150

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __cdecl sub_0045AE90(); // 0x0045AE90

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040

int __cdecl CURSOR_GetCursorItem(); // 0x004680A0

int __cdecl sub_00468830(); // 0x00468830

void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0

void __cdecl INV_LoadUiRecords(); // 0x004835B0

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ClientTextDataStrc* pTextData); // 0x0049FF90

void __cdecl sub_004B8CB0(); // 0x004B8CB0

void __fastcall sub_004B9070(int nArg); // 0x004B9070

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem); // 0x004C21F0

int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem); // 0x004C2240

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem); // 0x00628C70

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __stdcall INV_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y); // 0x00483E40

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50

int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern "C" const char gszCmnItemsH[]; // 0x006D9B90

extern "C" const char gszInvCpp[]; // 0x006D9BC0

extern int gnDialogState; // 0x00721E34

extern int gbHoverPlayerItem; // 0x00721E38

extern int gnButtonCount; // 0x00722160

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern D2NpcButtonStrc gaNpcButtons[4]; // 0x007BC9E0

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58

extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88

extern D2InvRectStrc gtNpcInvRect; // 0x007BCBB0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

// build: symbol ?INV_DrawGridCells@* 0x004839D0
__declspec(noinline) void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight, int nColor);

char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem); // 0x00628340

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

struct D2ItemFormulaRecordStrc
{
    char unk0x00[0x9E];
    short nStat;
    char unk0xA0[0x04];
    unsigned int nCalc;
    char unk0xA8[0x0C];
    unsigned char nDescType;
    char unk0xB5;
    unsigned short wStringId;
};

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A620

static void __stdcall INV_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY);

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

int __cdecl MONSTER_IsGambleShop(); // 0x004B3500

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0

static void INV_SetBuyButton(int nButton); // 0x00487E20

static void INV_SetSellButton(int nButton); // 0x00487E60

static void INV_ClearButton(int nButton); // 0x00487EA0

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

extern D2CelFileStrc* gpTorsoCell_007BCE68; // 0x007BCE68

extern D2CelFileStrc* gpHeadCell_007BCE74; // 0x007BCE74

extern D2CelFileStrc* gpArmCell_007BCE7C; // 0x007BCE7C

extern int gnRectHeadLeft; // 0x007BCD4C

extern int gnRectHeadBottom; // 0x007BCD58

extern int gnRectTorsoLeft; // 0x007BCD74

extern int gnRectTorsoBottom; // 0x007BCD80

extern int gnRectRArmLeft; // 0x007BCD88

extern int gnRectRArmBottom; // 0x007BCD94

extern int gnRectLArmLeft; // 0x007BCD9C

extern int gnRectLArmBottom; // 0x007BCDA8

extern int gnOffsetTorsoX_007220B0; // 0x007220B0

extern int gnOffsetTorsoY_007220B4; // 0x007220B4

extern int gnOffsetHeadX_007220C8; // 0x007220C8

extern int gnOffsetHeadY_007220CC; // 0x007220CC

extern int gnOffsetRArmX_007220F0; // 0x007220F0

extern int gnOffsetRArmY_007220F4; // 0x007220F4

extern int gnOffsetLArmX_007220F8; // 0x007220F8

extern int gnOffsetLArmY_007220FC; // 0x007220FC

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0



static int gnHoverBodyLoc; // 0x007BCC20

static int gnSelectedShopButton; // 0x007BCC40

static int gnSelectedShopButtonKey; // 0x007BCC44

static int gbCubeItemClicked; // 0x007BCC50

static int gbTradeAccepted; // 0x007BCE18

static int gbTradeCancelClicked; // 0x007BCE1C

static int gbTradeAcceptButtonDown; // 0x007BCE20

static int gbTradeCancelButtonDown; // 0x007BCE24

static int gbGoldButtonDisabled; // 0x007BCE2C

static int gbInvGoldButtonDown; // 0x007BCE30

static int gbStashGoldButtonDown; // 0x007BCE34

static int gbStashButtonDown; // 0x007BCE38

static int gbStashButtonClicked; // 0x007BCE3C

static int gbPanelButtonDown; // 0x007BCE90

static int gnGlobal_007BCE94; // 0x007BCE94


// 0x00480780
int __fastcall INV_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitId)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitId, nUnitType);
    PATH_SetTargetUnit(pPath, pTarget);
    if (!pTarget)
    {
        return 0;
    }
    return D2Common_10142(pPath, pUnit, 0);
}

// 0x004824A0
int __stdcall INV_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge)
{
    const unsigned int nTarget = gdwCacheUsed - nFree;
    const unsigned int dwNow = gdwSoundTick;
    while (gdwCacheUsed > nTarget)
    {
        int bFreed = 0;
        int nPass = 0;
        do
        {
            for (D2ClientCacheNodeStrc* pNode = gpCacheList; pNode; pNode = pNode->pNext)
            {
                const int nId = pNode->nId;
                D2ClientCacheEntryStrc* pEntry = (sgptSoundHeaderTable && nId >= 0 && nId < gnCacheEntries_007BC9A4) ? &sgptSoundHeaderTable[nId] : 0;
                if (nPass == 0 && (*(int*)pEntry->nRefCount || pEntry->bLocked))
                {
                    continue;
                }
                if (bCheckAge && dwNow - *(unsigned int*)pEntry->dwLastUse < 750)
                {
                    continue;
                }
                if (!sub_004DF9D0_CheckCacheEntry(nId))
                {
                    SOUNDHDR_ReleaseCacheEntry(nId);
                    bFreed = 1;
                    break;
                }
            }
            if (!bTwoPasses)
            {
                break;
            }
            ++nPass;
        }
        while (nPass <= 1);

        if (!bFreed)
        {
            return 0;
        }
    }
    return 1;
}

// 0x00482C20
void __cdecl INV_TickSound()
{
    if (sub_004DF870())
    {
        SKILLDESC_UpdateEnvironSounds(gdwSoundTick);
        sub_004DCAA0_UpdateLevelSong(gdwSoundTick);
        SOUNDHDR_UpdateCache(gdwSoundTick);
        sub_004BA020(gdwSoundTick);
        sub_004DF890();
        ++gdwSoundTick;
        Sleep(0);
    }
}

// 0x00482C70
static unsigned char INV_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

// 0x00483310
void __cdecl INV_ResetCinematicFlags()
{
    gbCinematicStop = 0;
    gbCinematicWide = !sub_0040EB10();
    gbCinematicChain = 0;
    gbCinematicBusy = 0;
}

// 0x00483350
unsigned char __cdecl INV_IsCinematicBusy()
{
    return gbCinematicBusy;
}

// 0x004834A0
const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString)
{
    int n = sub_00526800(pString);
    for (; n > 0; --n)
    {
        if (pString[n].wChar == ']')
        {
            break;
        }
    }
    if (pString[n].wChar == ']' && n >= 3 && pString[n - 3].wChar == '[')
    {
        return &pString[n + 1];
    }
    return pString;
}

// calling-convention shim (not game code)
int __fastcall sub_00482C70_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += INV_GetFlagIndex(pFlags[i]);
    return nSum;
}

// 0x00483AE0
static int INV_IsInTradeOtherGrid(int nX, int nY)
{
    if (nX > gnGlobal_007BCB1C && nX < gnGlobal_007BCB20 && nY >= gnGlobal_007BCB24 && nY <= gnGlobal_007BCB28)
    {
        return 1;
    }
    return 0;
}

// 0x00483B10
static int INV_IsInTradeGrid(int nX, int nY)
{
    if (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
    {
        return 1;
    }
    return 0;
}

// 0x00483B40
static int sub_00483B40_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
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

// 0x00483BA0
static int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
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

// 0x00483BF0
static int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_E04_Emit_00483AE0(int nX, int nY)
{
    return INV_IsInTradeOtherGrid(nX, nY);
}

int __cdecl sub_E04_Emit_00483B10(int nX, int nY)
{
    return INV_IsInTradeGrid(nX, nY);
}

int __cdecl sub_E04_Emit_00483B40(int nX, int nY)
{
    return sub_00483B40_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BA0(int nX, int nY)
{
    return sub_00483BA0_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BF0(int nX, int nY)
{
    return sub_00483BF0_IsInRect(nX, nY);
}

// 0x00483C20
static int INV_IsInSidePanelRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        return 1;
    }
    return 0;
}

// 0x00483E10
int __cdecl INV_IsNpcStateIdle()
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        return 1;
    }
    return 0;
}

// 0x00483E40
void __stdcall INV_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y)
{
    if (!ITEMS_CheckItemFlag(item, 0x10, 1120, ".\\UI\\inv.cpp"))
        return;
    unsigned char width, height;
    D2InventoryStrc* pInventory = item->pInventory;
    D2UnitStrc* socketItem = INVENTORY_GetFirstItem(pInventory);
    ITEMS_GetDimensions(item, &width, &height, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 1756);
    const unsigned char socketCount = ITEMS_GetSockets(item);
    const D2CoordStrc* offsets = gSocketLayouts[(2 * socketCount + width) * 4 + height - 13];
    for (unsigned int i = 0; i < ITEMS_GetSockets(item); ++i)
    {
        int drawX = (offsets[i].nX - 1) * grid->nGridBoxWidth / 2 + x;
        int drawY = (offsets[i].nY + 1) * grid->nGridBoxHeight / 2 + y;
        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.pCellFile = gpCellFile_007BEF14;
        context.nDirection = 0;
        context.nFrame = 0;
        sub_004F6480(&context, drawX - 1, drawY, -1, 0, 0);
        if (socketItem)
        {
            D2UnitStrc* checked = INVENTORY_UnitIsItem(socketItem);
            GFX_DrawItemCel(checked, drawX, drawY - grid->nGridBoxHeight);
            socketItem = INVENTORY_GetNextItem(socketItem);
        }
    }
}

struct D2ClientTextDataStrc;

struct D2InventoryStrc;

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
{
    if (nX > gtTradePage1Grid.nGridLeft && nX < gtTradePage1Grid.nGridRight && nY >= gtTradePage1Grid.nGridTop && nY <= gtTradePage1Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B10_IsInGrid7BCA30(int nX, int nY)
{
    if (nX > gtTradePage2Grid.nGridLeft && nX < gtTradePage2Grid.nGridRight && nY >= gtTradePage2Grid.nGridTop && nY <= gtTradePage2Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B40_IsInCubeGrid(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX > gtBigBankGrid.nGridLeft && nX <= gtBigBankGrid.nGridRight && nY >= gtBigBankGrid.nGridTop && nY <= gtBigBankGrid.nGridBottom)
        {
            return 1;
        }
        return 0;
    }
    if (nX > gtBankGrid.nGridLeft && nX <= gtBankGrid.nGridRight && nY >= gtBankGrid.nGridTop && nY <= gtBankGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BF0_IsInGrid7BCB70(int nX, int nY)
{
    if (nX >= gtCubeGrid.nGridLeft && nX < gtCubeGrid.nGridRight && nY >= gtCubeGrid.nGridTop && nY <= gtCubeGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

// build: context INV_DrawGridCells
// calling-convention shim (not game code)
static void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight, int nColor)
{
    gnHoverCellX = nY;
    sub_00468040(nHeight, nWidth);
    sub_00468040(pGrid->nGridLeft + nX, pGrid->nGridTop + nColor);
}

void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70

static void __stdcall sub_00483C50_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem)
{
    if (nPage == 0xFF)
    {
        return;
    }
    D2UnitStrc* pOther = 0;
    if (!pCursorItem || !gbHoverInGrid)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    if (gnHoverCellX < 0 || gnHoverCellY < 0)
    {
        return;
    }
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (gnInvPanelMode == 0x13 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &nOutX, &nOutY, nPage))
    {
        INV_DrawGridCells(pGrid, gnHoverCellX, gnHoverCellY, nWidth, nHeight, 1);
        return;
    }
    else
    {
        if (!INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 1)
            && (!pOther || DATATBLS_GetItemsTxtRecord(!pOther ? -1 : pOther->dwClassId)->dwCode != 0x20786F62))
        {
            INV_DrawGridCells(pGrid, gnHoverCellX, gnHoverCellY, nWidth, nHeight, 0);
            return;
        }
        unsigned char nOtherWidth;
        unsigned char nOtherHeight;
        ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, gszCmnItemsH, 0x6DC);
        INV_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), CLIENTS_GetUnitY(pOther), nOtherWidth, nOtherHeight, 3);
    }
}

// build: symbol ?INV_IsUnusableQuestBook@* 0x00483F80
static int INV_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 8) || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00483FF0
void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit)
{
    INV_LoadUiRecords();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = !pUnit ? 6 : pUnit->dwUnitType;
    switch (nType)
    {
    case 1:
        pGrid = &gtNpcInvGrid;
        break;
    case 0:
        switch (gnSelectedTab)
        {
        case 1:
            pGrid = &gtTradePage1Grid;
            break;
        case 2:
            pGrid = &gtTradePage2Grid;
            break;
        case 4:
            pGrid = GAME_IsExpansion() ? &gtBigBankGrid : &gtBankGrid;
            break;
        case 3:
            pGrid = &gtCubeGrid;
            break;
        default:
            pGrid = &gtPlayerInvGrid;
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
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab, GAME_IsExpansion());
    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory);
    while (pNode)
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (!pItem || INVENTORY_GetItemNodePage(pNode) != 1)
        {
            goto Next;
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
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab)
        {
            pNode = INVENTORY_GetNextItem(pNode);
            continue;
        }
        if (pItem == gpHoverItem && gbHoverInGrid)
        {
            if (sub_00468830() != 8 || ITEMS_GetTransmogrify(gpHoverItem))
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 1);
            }
            else
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 0);
            }
            GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, gszInvCpp))
            {
                INV_DrawItemSockets(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            goto Next;
        }
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, gszInvCpp)
            && !ITEM_IsItemActionBlocked(pItem) && ITEMS_CanBeEquipped(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, gszInvCpp))
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 4);
            }
            else
            {
                const int nClassId = pItem->dwClassId;
                D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
                int nColor = 2;
                if (pItemsTxt->nQuest && INV_IsUnusableQuestBook(pItemsTxt))
                {
                    nColor = 0;
                }
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, nColor);
            }
        }
        else
        {
            INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 0);
        }
        GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
    Next:
        pNode = INVENTORY_GetNextItem(pNode);
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
    switch (gnInvPanelMode)
    {
    case 0xB:
        if (gnSelectedTab == 1)
        {
            return;
        }
        if (gnSelectedTab == 2)
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
        if (gnSelectedTab == 4)
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
        if (gnSelectedTab == 3)
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
    }
    sub_00483C50_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab, pCursorItem);
}

// build: symbol ?INV_CanSocketInto@* 0x004843E0
static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gnInvPanelMode == 0xA || gnInvPanelMode == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, gszInvCpp))
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
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, gszInvCpp))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, gszInvCpp))
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


// build: symbol ?INV_IsOverWeaponSwapTab@* 0x00486860
static int INV_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids[5].rect.nLeft && nX <= gaCompGrids[5].rect.nRight && nY >= gaCompGrids[5].rect.nTop - 0x18 && nY < gaCompGrids[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids[4].rect.nLeft && nX <= gaCompGrids[4].rect.nRight && nY >= gaCompGrids[4].rect.nTop - 0x18 && nY < gaCompGrids[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

int __cdecl INV_GetPanelX()
{
    if (!GAME_IsExpansion())
    {
        return gnPanelOffsetX + 0x113;
    }
    return gnPanelOffsetX + 0x110;
}

// build: symbol ?INV_GetPanelY@* 0x00486B00
int __cdecl INV_GetPanelY()
{
    if (!GAME_IsExpansion())
    {
        return gnScreenHeight + gnPanelOffsetY - 0x41;
    }
    return gnPanelOffsetY + gnScreenHeight - 0x40;
}

// build: symbol ?INV_IsOverGoldButton@* 0x00486DA0
static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnScreenHeight + gnPanelOffsetY - 0x57 && nY <= gnScreenHeight + gnPanelOffsetY - 0x45
        && nX >= gnScreenWidth - gnPanelOffsetX - 0xED && nX <= gnScreenWidth - gnPanelOffsetX - 0xD9)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?INV_IsInNpcPanelRect@* 0x00486E10
int __fastcall INV_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnScreenWidth - gnPanelOffsetX - 0x12E || nX > gnScreenWidth - gnPanelOffsetX - 0x10E)
    {
        return 0;
    }
    if (nY < gnScreenHeight + gnPanelOffsetY - 0x60 || nY > gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 0;
    }
    return 1;
}

// build: symbol ?INV_ClickOutsidePanel@* 0x00486E60
static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        return;
    }
    if (nY > gnScreenHeight - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    if (sub_0045AE90() == 3 && gnInvPanelMode == 0 && nX < gnScreenWidth / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg); // 0x00486E60

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        if (INV_IsInNpcPanelRect(nX, nY))
        {
            UI_SetUIVar(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gbInvGoldButtonDown && !gnInvPanelMode)
    {
        gbInvGoldButtonDown = 0;
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(1);
        }
    }
    GAME_ResetMouseButtons();
    if (sub_00483AB0_IsInInvRect(nX, nY) && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

static void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    if (pCursorItem)
    {
        unsigned char nWidth;
        unsigned char nHeight;
        unsigned int nPixelWidth;
        unsigned int nPixelHeight;
        ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        sub_004DBEA0(pCursorItem, 0, 0, &nPixelWidth, &nPixelHeight);
        if (nWidth % 2 == 0)
        {
            nCellX = ((nPixelWidth >> 2) - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
        }
        if (nWidth == pGrid->nGridX)
        {
            nCellX = pGrid->nGridX / 2;
        }
        if (nHeight % 2 == 0)
        {
            nCellY = ((nPixelHeight >> 2) - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
        }
        if (nHeight == pGrid->nGridY)
        {
            nCellY = pGrid->nGridY / 2;
        }
        if (nWidth > 1)
        {
            nCellX -= nWidth / 2;
            if (nCellX < 0)
            {
                nCellX = 0;
            }
            if (nWidth + nCellX > pGrid->nGridX)
            {
                return;
            }
        }
        if (nHeight > 1)
        {
            nCellY -= nHeight / 2;
            if (nCellY < 0)
            {
                nCellY = 0;
            }
            if (nHeight + nCellY > pGrid->nGridY)
            {
                return;
            }
        }
        gnHoverCellY = nCellY;
        gnHoverCellX = nCellX;
        gbHoverInGrid = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        return;
    }

    int nOutX;
    int nOutY;
    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nCellX, nCellY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        gbHoverInGrid = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        unsigned char nItemWidth;
        unsigned char nItemHeight;
        ITEMS_GetDimensions(pItem, &nItemWidth, &nItemHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        const int nItemX = CLIENTS_GetUnitX(pItem);
        const int nItemY = CLIENTS_GetUnitY(pItem);
        const int nLeft = nItemWidth * pGrid->nGridBoxWidth / 2 + pGrid->nGridBoxWidth * nItemX + pGrid->nGridLeft;
        const int nBoxHeight = pGrid->nGridBoxHeight;
        const int nGridTop = pGrid->nGridTop;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = nBoxHeight * nItemY + nGridTop;
        gnHoverBottomY = nBoxHeight * (nItemY + nItemHeight) + nGridTop;
        return;
    }
    gbHoverInGrid = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gnHoverBodyLoc = nBodyLoc;
        gbHoverInBodyLoc = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
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
        if (pOther && !pItem && gnInvPanelMode == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gbHoverInBodyLoc = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        const int nLeft = (gaCompGrids[nBodyLoc].rect.nRight + gaCompGrids[nBodyLoc].rect.nLeft) / 2;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = gaCompGrids[nBodyLoc].rect.nTop;
        gnHoverBottomY = gaCompGrids[nBodyLoc].rect.nBottom;
        return;
    }
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnDialogState)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && sub_00483AB0_IsInInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gtPlayerInvGrid);
            gnHoverBodyLoc = 0;
            gbHoverPlayerItem = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids[nBodyLoc].rect.nLeft && nX <= gaCompGrids[nBodyLoc].rect.nRight && nY >= gaCompGrids[nBodyLoc].rect.nTop && nY <= gaCompGrids[nBodyLoc].rect.nBottom)
            {
                INV_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gbHoverPlayerItem = 1;
                return;
            }
        }
        gnHoverBodyLoc = 0;
        pMsg->bReturn = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483AE0_IsInGrid7BCB18(nX, nY))
        {
            gnSelectedTab = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gtTradePage1Grid);
            bHandled = 1;
        }
        else if (sub_00483B10_IsInGrid7BCA30(nX, nY))
        {
            gnSelectedTab = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gtTradePage2Grid);
            bHandled = 1;
        }
        gnSelectedTab = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483B40_IsInCubeGrid(nX, nY))
        {
            gnSelectedTab = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (GAME_IsExpansion())
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBigBankGrid);
            }
            else
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBankGrid);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483BF0_IsInGrid7BCB70(nX, nY))
        {
            gnSelectedTab = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gtCubeGrid);
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (GAME_GetUIVarState(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
    gbHoverPlayerItem = 0;
}

int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
    return 1;
}

// build: symbol ?INV_CanUseCursor@* 0x004888C0
int __cdecl INV_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
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

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (CURSOR_GetCursorItem() && nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gnInvPanelMode && NPCMENU_GetInteractNpcId(&nUnitId))
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
                    {
                        INV_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gbHoverPlayerItem = 0;
                        return;
                    }
                }
            }
        }
        INV_UpdateInventoryHover(pMsg);
    }
}

static void INV_SelectButtonByKey(int nKey)
{
    gaNpcButtons[0].bActive = gaNpcButtons[0].nKey == nKey;
    gaNpcButtons[1].bActive = gaNpcButtons[1].nKey == nKey;
    gaNpcButtons[2].bActive = gaNpcButtons[2].nKey == nKey;
    gaNpcButtons[3].bActive = gaNpcButtons[3].nKey == nKey;
}

void __cdecl INV_RestoreSelectedShopButton(); // 0x00488F10

static int INV_IsOverTradeButtonLeft(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0xDF && nX < gnPanelOffsetX + 0xFF
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTradeButtonRight(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x133
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!sub_00483B10_IsInGrid7BCA30(nX, nY))
    {
        if (INV_IsOverTradeButtonLeft(nX, nY))
        {
            if (gbTradeAccepted && gbTradeAcceptButtonDown)
            {
                sub_004B9070(0);
            }
            gbPanelButtonClicked = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (INV_IsOverTradeButtonRight(nX, nY))
        {
            if (gbTradeCancelClicked && gbTradeCancelButtonDown)
            {
                sub_004B8CB0();
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbPanelButtonClicked = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
        {
            gbTradeAcceptButtonDown = 0;
            gbTradeAccepted = 0;
            gbPanelButtonClicked = 0;
            gbTradeCancelClicked = 0;
            return;
        }
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(2);
        }
        if (gbPanelButtonClicked)
        {
            const int bFlag = gbTradeAcceptButtonDown;
            gbPanelButtonClicked = 0;
            if (bFlag)
            {
                if (gbTradeAccepted == 1)
                {
                    gbTradeAccepted = 0;
                    sub_004B90B0_SendState();
                }
            }
            else if (gbTradeCancelButtonDown && gbTradeCancelClicked)
            {
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gbTradeAccepted)
    {
        sub_004B90B0_SendState();
    }
    gbPanelButtonClicked = 0;
    gbTradeCancelClicked = 0;
    gbTradeAccepted = 0;
}

// build: symbol ?INV_IsOverCloseButton@* 0x00489920
static int INV_IsOverCloseButton(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nY >= gnScreenHeight + gnPanelOffsetY - 0x1C7 && nY <= gnScreenHeight + gnPanelOffsetY - 0x1B6
            && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnScreenHeight + gnPanelOffsetY - 0x103 && nY <= gnScreenHeight + gnPanelOffsetY - 0xF2
        && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?INV_IsOverTransmuteButton@* 0x00489980
static int INV_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > INV_GetPanelX() && nX < INV_GetPanelX() + 0x28
        && nY > INV_GetPanelY() - 0x23 && nY < INV_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC || gnInvPanelMode == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (sub_00483AB0_IsInInvRect(nX, nY) || sub_00483B40_IsInCubeGrid(nX, nY))
        {
            INV_UpdateInventoryHover(pMsg);
            return;
        }
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    }
}

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xC && gnInvPanelMode != 0xD)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if ((!HIREABLES_AreBeltRowsShown() || !AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        UI_SetUIVar(0x19, 1, 0);
        return;
    }
    if (INV_IsOverTransmuteButton(nX, nY))
    {
        if (gbStashButtonDown)
        {
            gbStashButtonDown = 0;
            UI_SetUIVar(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
        }
        gbStashButtonClicked = 0;
        gbPanelButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbStashButtonDown = 0;
    gbStashButtonClicked = 0;
    if (!HIREABLES_AreBeltRowsShown() && INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(3);
    }
    if (INV_IsOverCloseButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(4);
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    gbStashGoldButtonDown = 0;
    gbInvGoldButtonDown = 0;
    if (gbPanelButtonClicked)
    {
        const int bFlag = gbTradeAcceptButtonDown;
        gbPanelButtonClicked = 0;
        if (bFlag)
        {
            if (gbTradeAccepted == 1)
            {
                gbTradeAccepted = 0;
            }
        }
        else if (gbStashButtonClicked && gbStashButtonDown)
        {
            gbStashButtonDown = 0;
        }
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbPanelButtonClicked = 0;
    gbStashButtonDown = 0;
    gbTradeAccepted = 0;
}

static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        return 1;
    }
    return 0;
}

static void INV_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gpHoverItem, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gpHoverItem, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

// build: symbol ?INV_FindSetItem@* 0x00486770
static D2UnitStrc* INV_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, gszInvCpp))
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

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId); // 0x004844A0

int __cdecl sub_E05_Emit_00486860(); // 0x00486860

int __cdecl sub_E05_Emit_00489FB0(int nX, int nY); // 0x00489FB0

// 0x00484C90
static int INV_FormatEarName(Unicode* pText, D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        Unicode wszName[0x200];
        Unicode wszFormatted[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(wszFormatted, wszName, pText, 0x200, STRTABLE_GetLanguage());
        Unicode::strcpy(pText, wszFormatted);
        return 1;
    }

    return 0;
}

// 0x00484D30
static int __stdcall INV_FormatEarNameTo(Unicode* pOut, const Unicode* pFormat, D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        Unicode wszName[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, wszName, pFormat, 0x200, STRTABLE_GetLanguage());
        return 1;
    }

    return 0;
}

int __fastcall sub_A15_Emit_00484C90(Unicode* pText, D2UnitStrc* pItem)
{
    return INV_FormatEarName(pText, pItem);
}

int __fastcall sub_A15_Emit_00484D30(Unicode* pOut, const Unicode* pFormat, D2UnitStrc* pItem)
{
    return INV_FormatEarNameTo(pOut, pFormat, pItem);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00486370
static void __stdcall INV_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemFormulaRecordStrc* pRecord, Unicode* pBuffer)
{
    if (!pItem || !pRecord || !pRecord->nDescType)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || pRecord->wStringId == 0x1506)
    {
        return;
    }

    const Unicode* pSeparator = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pLineEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    switch (pRecord->nDescType)
    {
    case 1:
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        sub_00526700(pBuffer, pLineEnd);
        break;

    case 2:
    {
        char szValue[10];
        Unicode wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        switch (pRecord->nStat)
        {
        case 6:
        case 74:
            nValue = ITEMS_GetBonusLifeBasedOnClass(pPlayer, nValue);
            break;
        case 8:
        case 26:
            nValue = ITEMS_GetBonusManaBasedOnClass(pPlayer, nValue);
            break;
        }
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
// build: symbol ?gszFormatLd@* 0x006D9BE8
        SStrPrintf(szValue, 10, gszFormatLd, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 3:
    {
        char szValue[10];
        Unicode wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf(szValue, 10, gszFormatLd, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 4:
    {
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        Unicode wszText[0x200];
        sub_005269D0(0x200, wszText, D2LANG_GetStringFromTblIndex(pRecord->wStringId), nValue);
        sub_00526700(pBuffer, wszText);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }
    }
}

// 0x00486670
static void __stdcall INV_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return;
    }
    Unicode wszLetter[6];
    int bAny = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pGem = INVENTORY_UnitIsItem(pNode);
        if (!pGem)
        {
            break;
        }
        if (ITEMSIsA(pGem, 0x4A))
        {
            const int nClassId = pGem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            const int nGemOffset = pItemsTxtRecord->dwGemOffset;
            if (nGemOffset > 0)
            {
                D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(nGemOffset);
                if (pGemsTxtRecord)
                {
                    if (!bAny)
                    {
                        bAny = 1;
                        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x501A));
                    }
                    sub_00526320_ToUnicode(wszLetter, pGemsTxtRecord->szLetter, 6);
                    sub_00526700(pText, wszLetter);
                }
            }
        }
    }
    if (bAny)
    {
// build: symbol ?gszQuote@* 0x006D9BF4
        sub_00526320_ToUnicode(wszLetter, gszQuote, 5);
        sub_00526700(pText, wszLetter);
        sub_00526700(pText, pColorEnd);
    }
}

void __stdcall sub_Q05_Emit_00486370(D2ItemFormulaRecordStrc* pRecord, Unicode* pOut)
{
    Unicode wszBuffer[0x400];
    INV_AppendItemFormulaText(gpHoverItem, pRecord, wszBuffer);
    sub_005267E0(pOut, wszBuffer);
}

// 0x00486BD0
static void __stdcall INV_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    D2_ASSERT(pItem, 0x14E8);

    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);

    unsigned int nCelWidth;
    unsigned int nCelHeight;
    sub_004DBEA0(pItem, 0, 0, &nCelWidth, &nCelHeight);

    if (!(nWidth % 2))
    {
        nCellX = (nCelWidth / 4 - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }

    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX >> 1;
    }

    if (!(nHeight % 2))
    {
        nCellY = (nCelHeight / 4 - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }

    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY >> 1;
    }

    *pCellX = nCellX;
    *pCellY = nCellY;

    if (nWidth > 1)
    {
        nWidth >>= 1;
        *pCellX = D2_MAX(0, *pCellX - nWidth);
    }

    if (nHeight > 1)
    {
        nHeight >>= 1;
        *pCellY = D2_MAX(0, *pCellY - nHeight);
    }
}

// 0x00487A10
void __stdcall INV_SelectItemPageTab(unsigned char nTab)
{
    if (nTab >= 5)
    {
        nTab = 0;
    }
    if (gdwNpcPanelDelayTick)
    {
        return;
    }
    int nUnitId;
    if (!NPCMENU_GetInteractNpcId(&nUnitId))
    {
        return;
    }
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    int anCounts[5] = {};
    for (; pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        const unsigned char nPage = ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem));
        if (nPage < 5)
        {
            ++anCounts[nPage];
        }
    }

    int nTries = 0;
    gnSelectedTab = nTab;
// build: symbol ?gnNpcTabCount@* 0x00722158
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        *(int*)gaNpcTabStates[i].bSelected = 0;
        *(int*)gaNpcTabStates[i].bEnabled = anCounts[i] != 0;
    }

    if (!anCounts[nTab])
    {
        do
        {
            ++gnSelectedTab;
            ++nTries;
            if (gnSelectedTab > gnMaxTab || gnSelectedTab == 0xFF)
            {
                gnSelectedTab = 0;
            }
            if (anCounts[gnSelectedTab])
            {
                break;
            }
        }
        while (nTries < 4);
    }
    *(int*)gaNpcTabStates[gnSelectedTab].bSelected = 1;
}

void __stdcall sub_00486BD0_Emit(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    INV_GetPlacementCell(pItem, pGrid, nX, nY, pCellX, pCellY);
}

static void INV_SetBuyButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD07;
    gaPanelButtons_007BC9E0[nButton].nCel = 2;
    gaPanelButtons_007BC9E0[nButton].nType = 3;
    gaPanelButtons_007BC9E0[nButton].nFrame = 2;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

static void INV_SetSellButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD08;
    gaPanelButtons_007BC9E0[nButton].nCel = 3;
    gaPanelButtons_007BC9E0[nButton].nType = 4;
    gaPanelButtons_007BC9E0[nButton].nFrame = 4;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

static __declspec(noinline) void INV_ClearButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0;
    gaPanelButtons_007BC9E0[nButton].bActive = 0;
}

// build: context sub_00623C60
static int sub_00623C60(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x00487ED0
void __cdecl INV_SetupPanelButtons()
{
    const int bValue = MONSTER_IsGambleShop();
    int nUnitId;
    if (!NPCMENU_GetInteractNpcId(&nUnitId))
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit)
        return;
    int bButton3Set = 0;
    if (bValue)
    {
        gnMaxTab = 1;
        INV_SetBuyButton(0);
        INV_SetSellButton(1);
        gaPanelButtons_007BC9E0[2].nString = 0;
        gaPanelButtons_007BC9E0[2].nCel = 1;
        gaPanelButtons_007BC9E0[2].nType = 1;
        gaPanelButtons_007BC9E0[2].nFrame = 0;
        gaPanelButtons_007BC9E0[2].bActive = 0;
    }
    else
    {
        switch (sub_00623C60(pUnit))
        {
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            INV_ClearButton(2);
            break;

        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            gaPanelButtons_007BC9E0[2].nString = 0xD0A;
            gaPanelButtons_007BC9E0[2].nCel = 4;
            gaPanelButtons_007BC9E0[2].nType = 1;
            gaPanelButtons_007BC9E0[2].nFrame = 6;
            gaPanelButtons_007BC9E0[2].bActive = 1;
            gaPanelButtons_007BC9E0[3].nString = 0x276F;
            gaPanelButtons_007BC9E0[3].nCel = 1;
            gaPanelButtons_007BC9E0[3].nType = 8;
            gaPanelButtons_007BC9E0[3].nFrame = 0x12;
            gnButtonCount = 4;
            bButton3Set = 1;
            break;

        default:
            gnButtonCount = 0;
            return;
        }
    }

    if (!bButton3Set)
    {
        gaPanelButtons_007BC9E0[3].nString = 0x1030;
        gaPanelButtons_007BC9E0[3].nCel = 9;
        gaPanelButtons_007BC9E0[3].nFrame = 0xA;
        gnButtonCount = 4;
    }

    gaPanelButtons_007BC9E0[3].bActive = 1;
// build: symbol ?gnButtonRow@* 0x0072215C
    gnButtonRow = 3;
    gaPanelButtons_007BC9E0[0].nValue = 0;
    gaPanelButtons_007BC9E0[1].nValue = 0;
    gaPanelButtons_007BC9E0[2].nValue = 0;
    gaPanelButtons_007BC9E0[3].nValue = 0;
}

// 0x00488910
void __stdcall INV_ResetShopCursorMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4 || gnInvPanelMode == 9)
        && !UI_GetUIVarUnchecked(5))
    {
        gbNpcUiRecordsLoaded = 0;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gbPanelButtonClicked = 0;
        NPCMENU_CloseNpcShop();
        gnInvMouseX = 0;
        gnInvMouseY = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gnHoverTopX = -1;
        gnHoverTopY = -1;
        gnHoverBottomX = -1;
        gnHoverBottomY = -1;
        gnHoverCellX = -1;
        gnHoverCellY = -1;
    }
}

// 0x00488E70
void __stdcall INV_OpenChatKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (UI_GetUIVarUnchecked(5) || NPCMENU_IsAnyDialogOpen())
    {
        return;
    }
    if (!(pMsg->lParam & 0x40000000))
    {
        UI_SetUIVar(5, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00489060
int __stdcall INV_InvRectClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        INV_UpdateInventoryHover(pMsg);
        return 1;
    }
    return 0;
}

// 0x004894D0
void __stdcall INV_TradeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if ((nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
        || (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
        || (nX > gnGlobal_007BCB1C && nX < gnGlobal_007BCB20 && nY >= gnGlobal_007BCB24 && nY <= gnGlobal_007BCB28))
    {
        INV_UpdateInventoryHover(pMsg);
        return;
    }
    INV_ResetHover();
    sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
}

static inline int InRect(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX < nRight && nY >= nTop && nY <= nBottom;
}

// 0x0048A0F0
void __stdcall INV_CubeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xE)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (InRect(nX, nY, gnGlobal_007BCAA0, gnGlobal_007BCAA4, gnGlobal_007BCAA8, gnGlobal_007BCAAC)
        || InRect(nX, nY, gnGlobal_007BCB74, gnGlobal_007BCB78, gnGlobal_007BCB7C, gnGlobal_007BCB80))
    {
        INV_UpdateInventoryHover(pMsg);
    }
    else
    {
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    }
}

// 0x0048B0A0
void __stdcall INV_DrawMercEmptyBodyLocs(D2UnitStrc* pUnit)
{
    D2GfxDataStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 3))
    {
        tGfx.pCellFile = gpTorsoCell_007BCE68;
        tGfx.nFrame = 0;
        TEXTURE_CelDraw(&tGfx, gnRectTorsoLeft + gnOffsetTorsoX_007220B0, gnRectTorsoBottom + gnOffsetTorsoY_007220B4, -1, 5, 0);
    }

    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 1))
    {
        tGfx.pCellFile = gpHeadCell_007BCE74;
        tGfx.nFrame = 1;
        TEXTURE_CelDraw(&tGfx, gnRectHeadLeft + gnOffsetHeadX_007220C8, gnRectHeadBottom + gnOffsetHeadY_007220CC, -1, 5, 0);
    }

    D2UnitStrc* pRightItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 4) : 0;
    D2UnitStrc* pLeftItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 5) : 0;
    int bTwoHanded = pInventory ? INVENTORY_GetWieldType(pUnit, pInventory) == 2 : 0;

    if (!pLeftItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pRightItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectLArmLeft + gnOffsetLArmX_007220F8, gnRectLArmBottom + gnOffsetLArmY_007220FC, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectLArmLeft + gnOffsetLArmX_007220F8, gnRectLArmBottom + gnOffsetLArmY_007220FC, -1, 5, 0);
        }
    }

    if (!pRightItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pLeftItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectRArmLeft + gnOffsetRArmX_007220F0, gnRectRArmBottom + gnOffsetRArmY_007220F4, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectRArmLeft + gnOffsetRArmX_007220F0, gnRectRArmBottom + gnOffsetRArmY_007220F4, -1, 5, 0);
        }
    }
}

// 0x0048BD80
void __stdcall INV_CloseRecipeScrollClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMaxY = gnScreenHeight - 0x31;
    const int nHalfWidth = gnScreenWidth / 2;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= 0 && nX <= nHalfWidth && nY >= 0 && nY <= nMaxY)
    {
        UI_SetUIVar(0x25, 1, 0);
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00497C50
void __stdcall INV_DrawWarningIcon(int nFrame)
{
    int nX = gnScreenWidth - 0x37;
    int nY = 0x9B;
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (!gabSlots[i])
        {
            gabSlots[i] = 1;
            nX -= 0x28 * i;
            break;
        }
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BEF24;
    tContext.nDirection = 0;
    tContext.nFrame = nFrame;
    if (GAME_GetUIVarState(0xA))
    {
        if (ROSTER_IsAnyoneHostile())
        {
            nY = 0xC6;
        }
        nY += 0x1E;
    }
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x00498A20
int __fastcall sub_00498A20_CheckState(int nUnused, D2ClientStateStrc* pState, int nArg1, int nArg2)
{
    D2_ASSERT(pState, 2621);
    if (pState->bFlag0x129 == 1 || pState->bFlag0x12A == 1)
    {
        sub_0049FF90_Close(nArg2, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    UNITSND_PlayPlayerSpeech(nArg1, 0x14);
    return 0;
}

struct D2UnitStrc;

int __cdecl sub_M133_Emit_00483C20(int nX, int nY)
{
    return INV_IsInSidePanelRect(nX, nY);
}

void __stdcall sub_P09_Emit_00486670(Unicode* pText)
{
    INV_AppendSocketedGemLetters(pText, gpHoverItem);
}

#include "gen/data/Source/D2Client/UI/inv_00483E40.inc"
