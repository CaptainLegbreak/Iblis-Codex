#include "D2ItemTypes.h"
#include "D2ClientUi.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2Unicode.h"
#include "D2Client.h"

#include "D2ItemsWorld.h"
struct D2InventoryStrc;

struct D2LowQualityItemsTxt
{
    char szName[0x20];
    unsigned short wTblId;
};

struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    char unk0x0E[0x18];
    char szName[0x20];
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" size_t __cdecl strlen(const char* szString);

#pragma intrinsic(memset, strcpy, strcat, strlen)

#pragma pack(push, 1)

struct D2LevelTextStrc
{
    char c00;
    int n01;
    int n05;
    int n09;
    int n0D;
    char c11;
};

#pragma pack(pop)

#define WSZ(a) ((Unicode*)(a))

#define SZ(a) ((char*)(a))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_00403040_ConstructVector(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040

void __fastcall sub_0042F530_ClearUnicode(void* pChar);                                                     // 0x0042F530

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nSize, const char* szFormat, ...);             // 0x00413A40

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit);                               // 0x004521C0

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470

const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString); // 0x004834A0

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

Unicode* __fastcall sub_00526F20(Unicode* pDest, const char* szSource, int nCount);                  // 0x00526F20

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);             // 0x00625480

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefix);                                 // 0x00627EC0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffix);                                 // 0x00627F80

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0

char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340

unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                     // 0x00633EE0

D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId);                                          // 0x00634260

D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nId);                              // 0x006375C0

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                          // 0x0063CD60

static const Unicode* INV_GetClassNameText(unsigned int nClass);                                   // 0x00484A70

static int INV_FormatEarName(D2UnitStrc* pItem, Unicode* pText);                                   // 0x00484C90

static int __stdcall INV_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat); // 0x00484D30

struct D2UnitStrc;

struct Unicode;

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

extern int gbHoverPlayerItem; // 0x00721E38

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

static int gnInvPanelMode; // 0x007BCBF0

static D2UnitStrc* gpHoverItem; // 0x007BCBF4

struct D2BitBufferStrc;

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

D2UnitStrc* __cdecl sub_004680A0(); // 0x004680A0

int __cdecl sub_00468830(); // 0x00468830

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_00478700_SendCommand(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700

int __cdecl sub_00486D10_CheckTick(); // 0x00486D10

void __cdecl sub_004A9DF0_UpdateSkillIcons(); // 0x004A9DF0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem); // 0x004C21F0

int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0

int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

D2InventoryGridInfoStrc gtPlayerInvGrid;        // 0x007BCB88

static int gbNpcTradeClicked; // 0x007BCBEC

static unsigned char gnSelectedTab; // 0x007BCC04

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

int __cdecl INV_IsTradeStateInteractive(); // 0x00486B30

static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);




extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

D2InventoryGridInfoStrc gtTradePage2Grid;        // 0x007BCA30

D2InventoryGridInfoStrc gtBigBankGrid;        // 0x007BCA78

D2InventoryGridInfoStrc gtBankGrid;        // 0x007BCB40

D2InventoryGridInfoStrc gtCubeGrid;        // 0x007BCB70

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

static int gbHoverInGrid; // 0x007BCBE4

static int gbHoverInBodyLoc; // 0x007BCBE8

static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

static int gbInvGoldButtonDown; // 0x007BCE30

static int gbPanelButtonDown; // 0x007BCE90

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __cdecl sub_00463DF0(); // 0x00463DF0

void __cdecl INV_LoadUiRecords(); // 0x004835B0

int __cdecl sub_004979E0(); // 0x004979E0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl sub_0045AE90(); // 0x0045AE90

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0

void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);

extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);

static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY);

static int sub_00486DA0_IsOverGoldButton(int nX, int nY);

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY);

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX);

static const Unicode* INV_GetClassNameText(unsigned int nClass)
{
    if (nClass < 7)
    {
        switch (nClass)
        {
        case 0:
            return D2LANG_GetStringFromTblIndex(0xFAB);
        case 1:
            return D2LANG_GetStringFromTblIndex(0xFAA);
        case 2:
            return D2LANG_GetStringFromTblIndex(0xFA9);
        case 3:
            return D2LANG_GetStringFromTblIndex(0xFA8);
        case 4:
            return D2LANG_GetStringFromTblIndex(0xFA7);
        case 5:
            return D2LANG_GetStringFromTblIndex(0x2771);
        case 6:
            return D2LANG_GetStringFromTblIndex(0x2772);
        }

        return 0;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x69C);
    exit(-1);
}

static int INV_FormatEarName(D2UnitStrc* pItem, Unicode* pText)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        int aFormatted[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aFormatted[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(WSZ(aFormatted), WSZ(aName), pText, 0x200, STRTABLE_GetLanguage());
        sub_005267E0(pText, WSZ(aFormatted));
        return 1;
    }

    return 0;
}

static int __stdcall INV_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, WSZ(aName), pFormat, 0x200, STRTABLE_GetLanguage());
        return 1;
    }

    return 0;
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    return pUnit->dwClassId;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048C060
void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pOut, int nMaxLen)
{
    if (pItem)
    {
        D2ItemsTxt* pItemsTxt;
        const Unicode* pStrF9B;
        const Unicode* pNewLine;
        int nItemType;
        int nLen;

        Unicode aPrefix[0x200];
        Unicode aSuffix[0x200];
        Unicode aLine[0x200];

        pStrF9B = D2LANG_GetStringFromTblIndex(0xF9B);
        pNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
        nLen = 0;
        pItemsTxt = DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem));
        D2_ASSERT(pItemsTxt, 0x732);

        nItemType = ITEMS_GetItemType(pItem);
        if (ITEMS_CheckItemFlag(pItem, 0x4000000, 0x735, ".\\UI\\inv.cpp"))
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(WSZ(aPrefix), INV_SkipBracketTag(WSZ(aName)));
            sub_00526700(WSZ(aPrefix), pNewLine);
            const Unicode* pRuneName = D2LANG_GetStringFromTblIndex(ITEMS_GetPrefixId(pItem, 0));
            if (pRuneName)
            {
                sub_005267E0(WSZ(aSuffix), pRuneName);
            }
            else
            {
                sub_005267E0(WSZ(aSuffix), pStrF9B);
            }
            sub_00526700(WSZ(aLine), WSZ(aSuffix));
            INV_PrefixColorCode(WSZ(aLine), 4);
            sub_00526700(pOut, WSZ(aPrefix));
            sub_00526700(pOut, WSZ(aLine));
        }
        else if (ITEMS_CheckItemFlag(pItem, 0x10, 0x748, ".\\UI\\inv.cpp"))
        {
            switch (ITEMS_GetItemQuality(pItem))
            {
            case ITEMQUAL_INFERIOR:
            {
                D2LowQualityItemsTxt* pLowQuality = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pLowQuality)
                {
                    INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B0), D2LANG_GetStringFromTblIndex(pLowQuality->wTblId), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                }
                break;
            }
            case ITEMQUAL_NORMAL:
            {
                if (!ITEMSIsA(pItem, 0x16) && !ITEMSIsA(pItem, 0x12))
                {
                    if (ITEMSIsA(pItem, 7))
                    {
                        char szLevel[18] = { 0 };
                        Unicode aEarName[0x100];
                        Unicode aLevelText[3];
                        SStrPrintf(szLevel, 3, "%d", ITEMS_GetEarLevel(pItem));
                        sub_00526F20(WSZ(aLevelText), szLevel, 3);
                        Unicode aUnused[0x100];
                        char aName[20];
                        strcpy(SZ(aName), ITEMS_GetEarName(pItem));
                        sub_00526F20(WSZ(aEarName), SZ(aName), 0x100);
                        if (ITEMS_CheckItemFlag(pItem, 0x8000, 0x775, ".\\UI\\inv.cpp"))
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x1406));
                            sub_00526700(pOut, pNewLine);
                            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        else
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        sub_00526700(pOut, WSZ(aLevelText));
                        sub_00526700(pOut, pNewLine);
                        sub_00526700(pOut, INV_GetClassNameText(ITEMS_GetFileIndex(pItem)));
                        sub_00526700(pOut, pNewLine);
                        Unicode aText[100] = { 0 };
                        Unicode aFormat[0x200];
                        sub_005267E0(WSZ(aFormat), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                        sub_005272B0_FormatText(WSZ(aText), WSZ(aEarName), WSZ(aFormat), 100, STRTABLE_GetLanguage());
                        sub_00526700(pOut, WSZ(aText));
                    }
                    else if (ITEMSIsA(pItem, 0x28))
                    {
                        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(pItem));
                        INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B4), D2LANG_GetStringFromTblIndex(pMonStatsTxt->wNameStr), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                    }
                    else
                    {
                        D2InventoryStrc* pInventory = pItem->pInventory;
                        if (ITEMS_CheckItemFlag(pItem, 0x800, 0x799, ".\\UI\\inv.cpp") && pInventory && INVENTORY_GetItemCount(pInventory))
                        {
                            INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B3), D2LANG_GetStringFromTblIndex(0x6C0), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                        }
                        else
                        {
                            Unicode aName[0x200];
                            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                        }
                    }
                }
                else
                {
                    switch (ITEMS_GetSuffixId(pItem, 0))
                    {
                    case 0:
                    {
                        int nString = 0x897;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x898;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    case 1:
                    {
                        int nString = 0x899;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x89A;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    }
                }
                break;
            }
            case ITEMQUAL_SUPERIOR:
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6AF), D2LANG_GetStringFromTblIndex(0x6BF), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                break;
            case ITEMQUAL_RARE:
            case ITEMQUAL_CRAFT:
            case ITEMQUAL_TEMPERED:
            {
                D2RareAffixTxt* pRarePrefix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRarePrefixId(pItem));
                D2RareAffixTxt* pRareSuffix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRareSuffixId(pItem));
                if (pRarePrefix)
                {
                    if (pRarePrefix->wStringId)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRarePrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pRareSuffix)
                {
                    if (pRareSuffix->wStringId)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRareSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        nLen += sub_00526800(WSZ(aTemp));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), WSZ(aTemp));
                        }
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x822);
                D2_ASSERT(nLen < nMaxLen, 0x822);

                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                sub_005267E0(WSZ(aLine), INV_SkipBracketTag(WSZ(aName)));
                sub_00526700(WSZ(aLine), pNewLine);
                Unicode aFormat[200] = { 0 };
                INV_FormatArgs(WSZ(aFormat), D2LANG_GetStringFromTblIndex(0x6B6), WSZ(aPrefix), WSZ(aSuffix), 0);
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aFormat)))
                {
                    sub_00526700(WSZ(aLine), WSZ(aEar));
                }
                else
                {
                    sub_00526700(WSZ(aLine), WSZ(aFormat));
                }
                sub_00526700(pOut, WSZ(aLine));
                break;
            }
            case ITEMQUAL_UNIQUE:
            {
                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                if (ITEMS_GetFileIndex(pItem) < 0)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                D2UniqueItemsTxt* pUniqueItemsTxt = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!pUniqueItemsTxt)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                if (!pItemsTxt->nSkipName)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                }
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex))))
                {
                    sub_00526700(pOut, WSZ(aEar));
                }
                else
                {
                    sub_00526700(pOut, INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex)));
                }
                break;
            }
            case ITEMQUAL_SET:
            {
                D2SetItemsTxt* pSetItemsTxt = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pSetItemsTxt)
                {
                    Unicode aName[0x200];
                    sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                    if (pSetItemsTxt->wTblIndex)
                    {
                        Unicode aEar[0x200];
                        Unicode aSetName[0x200];
                        sub_005267E0(WSZ(aSetName), D2LANG_GetStringFromTblIndex(pSetItemsTxt->wTblIndex));
                        if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aSetName)))
                        {
                            sub_00526700(pOut, WSZ(aEar));
                        }
                        else
                        {
                            Unicode aText[100] = { 0 };
                            INV_FormatArgs(WSZ(aText), D2LANG_GetStringFromTblIndex(0x2769), WSZ(aSetName), 0);
                            sub_00526700(pOut, WSZ(aText));
                        }
                    }
                }
                break;
            }
            case ITEMQUAL_MAGIC:
            {
                D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
                D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
                if (pPrefix)
                {
                    if (pPrefix->wTblIndex)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pPrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pSuffix)
                {
                    if (pSuffix->wTblIndex)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                        sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen += strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B2), WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), WSZ(aSuffix), 0);
                break;
            }
            default:
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x8CE);
                exit(-1);
            }
        }
        else
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
        }

        INV_FormatEarName(pItem, pOut);
        sub_00452170(pOut);
        if (pItemsTxt->nQuest)
        {
            if (pItemsTxt->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) < GAME_GetDifficulty())
            {
                INV_PrefixColorCode(pOut, 1);
            }
            else if (pItemsTxt->dwCode != 0x2067656C)
            {
                INV_PrefixColorCode(pOut, 4);
            }
        }
    }
}

static void __stdcall sub_00486100_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
// build: symbol ?gszFormatLd@* 0x006D9BE8
        SStrPrintf(szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x0048CEA0
static void __stdcall INV_AppendShopPriceText(const Unicode* pSource, Unicode* pText)
{
    Unicode wszName[0x40] = { 0 };
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gnInvPanelMode == 4 && ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        Unicode wszLabel[0x80];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }

    int nSetIndex;
    if (NPCMENU_GetTradeCostText(gpHoverItem, gbHoverPlayerItem, &nSetIndex, wszName, 0x40))
    {
        if (wszName[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, wszName);
        return;
    }

    if (gnInvPanelMode != 4)
    {
        Unicode wszLabel[0x40];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048CFF0
void __cdecl INV_DrawBookTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(gpHoverItem && ITEMS_GetItemType(gpHoverItem) == ITEMTYPE_BOOK, 0xCF1);
    D2_ASSERT(DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId), 0xCF5);

    sub_00486100_AppendStackQuantity(gpHoverItem, wszText);
    if (gnInvPanelMode == 0)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89B));
        sub_00526700(wszText, pColorEnd);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89E));
        sub_00526700(wszText, pColorEnd);
    }

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400];
    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048DB80
void __cdecl INV_DrawTransmogrifyTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (!ITEMS_GetTransmogrify(gpHoverItem))
    {
        return;
    }

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0xE61);
    int nItemId = 0;
    D2ItemsTxt* pBaseTxt = DATATBLS_GetItemRecordFromItemCode(pItemsTxt->dwTransmogrifyType, &nItemId);
    D2_ASSERT(pBaseTxt, 0xE64);

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(pBaseTxt->wNameStr));
    sub_00526700(wszText, pColorEnd);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_00526700(wszText, pColorEnd);

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400] = { 0 };
    if ((unsigned int)(gnInvPanelMode - 1) <= 8)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
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

int __cdecl INV_IsTradeStateInteractive()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid)
{
    D2_ASSERT(pItem, 0x14E8);
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned int nPixelWidth;
    unsigned int nPixelHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004DBEA0(pItem, 0, 0, &nPixelWidth, &nPixelHeight);
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
    *pOutX = nCellX;
    *pOutY = nCellY;
    if (nWidth > 1)
    {
        const int n = *pOutX - nWidth / 2;
        *pOutX = n < 0 ? 0 : n;
    }
    if (nHeight > 1)
    {
        const int n = *pOutY - nHeight / 2;
        *pOutY = n < 0 ? 0 : n;
    }
}

static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870_HandleTradeClick((D2UnitStrc*)nArg1, (D2UnitStrc*)nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x0048FFE0
static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
    int nGridX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nGridY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    int nOutX;
    int nOutY;

    if (sub_00468830() == 6)
    {
        D2UnitStrc* pCursor = sub_004680A0();
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    sub_004C21F0_SetState36(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (sub_00468830() == 8)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!sub_004C2240(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && sub_00486D10_CheckTick())
                {
                    sub_00478680_SendPacket5(0x4C, pHit->dwUnitId);
                    sub_004C21F0_SetState36(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (!pCursorItem)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0_GetPlayerUnit();
            if (INV_IsTradeStateInteractive() && bIsPlayer == 1)
            {
                if (!sub_004C2240(pHit) && sub_00486D10_CheckTick())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (NPCMENU_GetInteractNpcId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), !pNpc ? -1 : pNpc->dwClassId, 1);
                                    sub_00478700_SendCommand(0x33, !pNpc ? -1 : pNpc->dwUnitId, !pHit ? -1 : pHit->dwUnitId, !pHit ? -1 : pHit->dwAnimMode, nCost);
                                }
                                else
                                {
                                    sub_004CB9C0_Request(pUnit, 0x13);
                                }
                            }
                        }
                    }
                    else if ((nFlags & 4) && ITEMS_CheckIfBeltable(pHit) && !ITEMS_GetInvPage(pHit))
                    {
                        sub_00478680_SendPacket5(0x63, pHit->dwUnitId);
                        sub_004B9A00(0xEB, 0, 0, 0, 0);
                    }
                    else
                    {
                        sub_00478680_SendPacket5(0x19, pHit->dwUnitId);
                        gbNpcTradeClicked = 1;
                    }
                    nResult = 1;
                    sub_004C21F0_SetState36(pHit);
                }
            }
            else if (gnInvPanelMode < 0x13)
            {
                INV_ForwardTradeClick((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pBox, nPage, 1);
            if (pBox && DATATBLS_GetItemsTxtRecord((!pBox ? -1 : pBox->dwClassId))->dwCode == 0x20786F62)
            {
                pHit = pBox;
                goto LBL_CUBE;
            }
        }

        if (pHit && nCount == 1)
        {
            if (ITEMS_AreStackablesEqual(pCursorItem, pHit))
            {
                if (!sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gnInvPanelMode != 0xB && nPage != 2)
                {
                    sub_004786A0_SendDwords2(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnHoverCellX >= 0 && gnHoverCellY >= 0)
            {
                if (sub_004843E0_CanSocketInto(pHit, pCursorItem) && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
                {
                    sub_004786A0_SendDwords2(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMSIsA(pCursorItem, 0x16) && ITEMSIsA(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && gnInvPanelMode != 0xB)
                {
                    sub_004A9DF0_UpdateSkillIcons();
                    sub_004786A0_SendDwords2(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (DATATBLS_GetItemsTxtRecord(!pHit ? -1 : pHit->dwClassId)->dwCode == 0x20786F62)
                {
LBL_CUBE:
                    if (!sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
                    {
                        int nFreeX;
                        int nFreeY;
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, GAME_IsExpansion());
                        if (INVENTORY_GetFreePosition(pInventory, pCursorItem, nCubeRecord, &nFreeX, &nFreeY, 3))
                        {
                            sub_004786A0_SendDwords2(0x2A, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                            sub_004C21F0_SetState36(pCursorItem);
                            sub_004B9A00(sub_004C1D60(pHit), 0, 0, 0, 0);
                            nResult = 1;
                        }
                        else
                        {
                            sub_004CB9C0_Request(pUnit, 0x13);
                        }
                        goto LBL_DONE;
                    }
                }

                if (bPlace && INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 0)
                    && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick() && nPage != 2)
                {
                    sub_00478700_SendCommand(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnHoverCellX, gnHoverCellY);
                    sub_004C21F0_SetState36(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
LBL_DONE:
                ;
            }
        }
        else
        {
            if (nPage == 3)
            {
                D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord((!pCursorItem ? -1 : pCursorItem->dwClassId));
                D2_ASSERT(pTxt, 0x163A);
                if (pTxt->dwCode == 0x20786F62)
                {
                    return 1;
                }
            }

            int nCellX;
            int nCellY;
            sub_00486BD0_GetItemCell(nX, nY, &nCellX, &nCellY, pCursorItem, pGrid);
            D2UnitStrc* pExchange;
            unsigned int nExchangeCount;
            if (INVENTORY_CanItemBePlaced(pInventory, pCursorItem, nCellX, nCellY, nRecord, &pExchange, &nExchangeCount, nPage)
                && !sub_004C2240(pCursorItem) && sub_00486D10_CheckTick())
            {
                sub_00478700_SendCommand(0x18, (!pCursorItem ? -1 : pCursorItem->dwUnitId), nCellX, nCellY, nPage);
                sub_004C21F0_SetState36(pCursorItem);
                sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

int __stdcall sub_19F4_Emit_0048FFE0(D2UnitStrc* pUnit, unsigned int nX, unsigned int nY, int nFlags)
{
    return INV_ClickInvGrid(pUnit, pUnit->pInventory, nX, nY, nFlags, &gtPlayerInvGrid, gnSelectedTab);
}

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY)
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

static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
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

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
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

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
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

// 0x004912A0
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || sub_00463DF0()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnScreenWidth) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!sub_004979E0()) {
        if(sub_00486DA0_IsOverGoldButton(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==11 || gnInvPanelMode==12 || gnInvPanelMode==15)) {
            gbInvGoldButtonDown=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(sub_00486E10_IsInNpcPanelRect(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==19)) {
            gbPanelButtonDown=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && sub_00483AB0_IsInInvRect(x,y)) {
        if(sub_00486E10_IsInNpcPanelRect(x,y)) {
            gbPanelButtonDown=1;
            sub_00455F20(1,1,0);
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn=1;
        pMsg->lResult=0;
        int result=0;
        if(x>=gtPlayerInvGrid.nGridLeft && x<=gtPlayerInvGrid.nGridRight && y>=gtPlayerInvGrid.nGridTop && y<=gtPlayerInvGrid.nGridBottom) {
            result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtPlayerInvGrid,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids[bodyloc].rect.nLeft && x<=gaCompGrids[bodyloc].rect.nRight && y>=gaCompGrids[bodyloc].rect.nTop && y<=gaCompGrids[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick[bodyloc](player,inventory,bodyloc);
                    handled=1;
                }
                else {
                    D2UnitStrc* bodyItem=INVENTORY_GetItemFromBodyLoc(inventory,bodyloc);
                    if(!sub_004843E0_CanSocketInto(bodyItem,cursor)) goto USE_BODY_ACTION;
                    if(!sub_004C2240(cursor) && sub_00486D10_CheckTick()) {
                        sub_004786A0_SendDwords2(0x28,!cursor?-1:cursor->dwUnitId,!bodyItem?-1:bodyItem->dwUnitId);
                        sub_004C21F0_SetState36(cursor);
                        sub_004B9A00(sub_004C1D60(bodyItem),0,0,0,0);
                        handled=1;
                    }
                    result=0;
                }
            }
AFTER_BODY:
            if(!handled && GAME_IsExpansion() && sub_00486860_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) UI_CancelCursorItemUse();
            else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gbHoverInGrid=0;
        gbHoverInBodyLoc=0;
        gpHoverItem=0;
        gpLastHoverItem=0;
        if(!handled) sub_00486E60_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gnInvPanelMode) {
    case 14:
        if(x>=gtCubeGrid.nGridLeft && x<=gtCubeGrid.nGridRight && y>=gtCubeGrid.nGridTop && y<=gtCubeGrid.nGridBottom) {
            INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtCubeGrid,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(GAME_IsExpansion()) {
                left=gtBigBankGrid.nGridLeft;right=gtBigBankGrid.nGridRight;top=gtBigBankGrid.nGridTop;bottom=gtBigBankGrid.nGridBottom;
            }
            else {
                left=gtBankGrid.nGridLeft;right=gtBankGrid.nGridRight;top=gtBankGrid.nGridTop;bottom=gtBankGrid.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(GAME_IsExpansion()) INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBigBankGrid,4);
                else INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBankGrid,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gtTradePage2Grid.nGridLeft && x<=gtTradePage2Grid.nGridRight && y>=gtTradePage2Grid.nGridTop && y<=gtTradePage2Grid.nGridBottom) {
            int result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtTradePage2Grid,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    sub_00486E60_ClickOutsidePanel(y,pMsg,x);
}

#include "gen/data/Source/D2Client/UI/inv_0048C060.inc"
