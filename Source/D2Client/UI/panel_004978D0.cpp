#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2StaticPathStrc;

struct D2UiRectStrc;

struct D2UiRecordStrc;

struct D2Block1;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB); // 0x0046A530

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0

void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnUiRecordRow_007A5218; // 0x007A5218

extern D2CelFileStrc* gpCellFile_007BEF10; // 0x007BEF10

extern unsigned char gabBeltColors_007BEF6C[4]; // 0x007BEF6C

int gnBeltHover_007BEF94; // 0x007BEF94

extern int gbUiRecordMode_007BEF98; // 0x007BEF98

int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C

extern int gbGlobal_007BEFA0; // 0x007BEFA0

D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C

int __cdecl sub_00468830(); // 0x00468830

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

void __fastcall sub_004C21F0(D2UnitStrc* pItem);

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __cdecl sub_00463DF0(); // 0x00463DF0

int __cdecl GAME_IsLeftClickRepeating(); // 0x0044BFE0

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

extern int gdwGlobal_007A061C; // 0x007A061C

extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0

static void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY);

struct D2QtyWarnStrc;

Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

D2UnitStrc* __fastcall sub_00463DD0(); // 0x00463DD0

int __cdecl sub_00489840_IsNpcState123(); // 0x00489840

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall sub_004B2AD0(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const void* pSource); // 0x00526700

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

struct D2QtyWarnStrc
{
    int nWarnType;
    int nFrame;
    unsigned int nLevel0;
    unsigned int nLevel1;
    unsigned int nLevel2;
};

extern unsigned char gabSlots_007BEFB4[]; // 0x007BEFB4

extern int gaBodyLocs_00722374[]; // 0x00722374

extern unsigned int gnBodyLocCount_0072237C; // 0x0072237C

extern D2QtyWarnStrc gaQtyWarn_00722380[]; // 0x00722380

extern unsigned int gnQtyWarnCount_007223E4; // 0x007223E4

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

void __stdcall INV_DrawWarningIcon(int nFrame); // 0x00497C50

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* pItem); // 0x00629800

int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __cdecl ROSTER_IsAnyoneHostile();                                                                                 // 0x0047A560

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl sub_0045AE90(); // 0x0045AE90

int __cdecl sub_004F5140(); // 0x004F5140

void __cdecl PANEL_DrawBorderFrameLeft(); // 0x00498630

void __cdecl PANEL_DrawBorderFrameRight(); // 0x00498700

void __cdecl PANEL_DrawLifeOrb(); // 0x00496F80

void __cdecl PANEL_DrawManaOrb(); // 0x00497110

void __cdecl PANEL_DrawExperienceBar(); // 0x00498EA0

void __cdecl VIEW_DrawRunButton(); // 0x00497480

void __cdecl PANEL_DrawStaminaBar(); // 0x004975B0

void __cdecl PANEL_DrawMiniPanelButton(); // 0x004977C0

void __cdecl sub_00499040_DrawBelt();

void __cdecl PANEL_ValidateActiveSkills(); // 0x00496CF0

void __cdecl sub_00497A40_DrawPanelText();

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

extern "C" void __cdecl PANEL_UpdateMiniPanelTooltip(); // 0x00498340

extern void* gpBorderFrameCel_007BEF18; // 0x007BEF18

extern int gnLevelTimer_007BEFEC; // 0x007BEFEC

extern int gnLevelId_007BEFF0; // 0x007BEFF0

void* gpCel_007BEF1C; // 0x007BEF1C

void* gpCel_007BEF74; // 0x007BEF74

void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift);

void __fastcall sub_004C21F0_SetState36(D2UnitStrc*); // 0x004C21F0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall sub_004A8CE0_SetValue(int); // 0x004A8CE0

int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90

void __fastcall GAME_SetAlwaysRun(int); // 0x0044BE80

#include "gen/data/Source/D2Client/UI/panel_004978D0/gnGlobal_00722358.inc"

extern int gnGlobal_007BEF84; // 0x007BEF84

extern int gnGlobal_007BEF88; // 0x007BEF88

static int gnGlobal_007BEFA4;        // 0x007BEFA4

static int gnGlobal_007BEFD0;        // 0x007BEFD0

static int gnGlobal_007BEFD4;        // 0x007BEFD4

static int gnGlobal_007BEFD8;        // 0x007BEFD8

void __stdcall PANEL_BeltClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00499D10

// build: symbol ?VIEW_InitBeltColors@@YAXXZ 0x004972B0
void __cdecl VIEW_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x004978D0
static void __stdcall PANEL_DrawBeltBoxFrame(int nBox, int nColor)
{
    VIEW_InitBeltColors();
    if (nColor == 2)
        return;

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
    sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, 0x1D, 0x1D, gabBeltColors_007BEF6C[nColor], 0);
}

// 0x00497920
static void __cdecl PANEL_DrawCursorBeltBox(D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem || !gnBeltHover_007BEF94)
        return;

    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    if (gnBeltBox_0072235C < 0 || gnBeltBox_0072235C >= tRecord.nBoxes)
        return;

    if (!INVENTORY_GetItemFromBeltSlot(pInventory, gnBeltBox_0072235C) && ITEMS_CheckIfBeltable(pItem))
    {
        PANEL_DrawBeltBoxFrame(gnBeltBox_0072235C, 1);
        return;
    }

    int nResult;
    if (sub_0063C830_CanPlaceInBelt(pInventory, pItem, gnBeltBox_0072235C, &nResult))
    {
        PANEL_DrawBeltBoxFrame(gnBeltBox_0072235C, 3);
        return;
    }

    PANEL_DrawBeltBoxFrame(gnBeltBox_0072235C, 0);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00497A40
void __cdecl PANEL_DrawBeltItemHoverText()
{
    Unicode wszProps[0x100] = { 0 };
    Unicode wszName[0x80] = { 0 };
    Unicode wszText[0x180] = { 0 };

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!gnBeltHover_007BEF94 || !gpBeltItemA_007BEFA8)
    {
        return;
    }

    if (INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        return;
    }

    if (gnBeltBox_0072235C > 3 && !gbUiRecordMode_007BEF98 && !gnBeltRecordMode2_007BEF9C)
    {
        return;
    }

    if (!DATATBLS_GetItemsTxtRecord(!gpBeltItemA_007BEFA8 ? -1 : gpBeltItemA_007BEFA8->dwClassId))
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x61D);
        exit(-1);
    }

    INV_BuildItemName(gpBeltItemA_007BEFA8, wszName, 0x80);
    if (ITEMS_GetItemQuality(gpBeltItemA_007BEFA8) != 3)
    {
        sub_004E6410_BuildPropText(gpBeltItemA_007BEFA8, wszProps, 0x100, 1, 0);
    }

    sub_005267E0(wszText, INV_PrefixColorCode(wszProps, 3));
    sub_00526700(wszText, INV_PrefixColorCode(wszName, 0));
    if (gnBeltRectX_00722360 < 0 || gnBeltRectY_00722364 < 0)
    {
        return;
    }

    sub_00452170(wszText);
    if (sub_00489840_IsNpcState123())
    {
        Unicode wszSocket[0x40] = { 0 };
        int nUnused;
        if (sub_004B2AD0(gpBeltItemA_007BEFA8, 1, &nUnused, wszSocket, 0x40) && wszSocket[0].wChar)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText, wszSocket);
        }
    }

    D2Win_10129_DrawFramedText(wszText, gnBeltRectX_00722360, gnBeltRectY_00722364, 0, 1);
}

// 0x00497E00
void __cdecl PANEL_DrawQuantityWarningIcons()
{
    memset(gabSlots_007BEFB4, 0, 6);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pRightArm = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArm = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if ((pRightArm && ITEMS_GetAmmoType(pRightArm) && (!pLeftArm || !ITEMSIsA(pLeftArm, ITEMS_GetAmmoType(pRightArm))))
        || (pLeftArm && ITEMS_GetAmmoType(pLeftArm) && (!pRightArm || !ITEMSIsA(pRightArm, ITEMS_GetAmmoType(pLeftArm)))))
    {
        INV_DrawWarningIcon(2);
    }

    for (unsigned int i = 0; i < gnBodyLocCount_0072237C; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gaBodyLocs_00722374[i]);
        if (!pItem)
        {
            continue;
        }

        const unsigned char nWarnType = ITEMS_GetQtyWarnCount(pItem);
        if (!nWarnType)
        {
            continue;
        }

        for (unsigned int j = 0; j < gnQtyWarnCount_007223E4; ++j)
        {
            if (nWarnType != gaQtyWarn_00722380[j].nWarnType)
            {
                continue;
            }

            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(GAME_GetUnitClassId(pItem));
            unsigned int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
            if (!ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
            {
                for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
                {
                    D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pNode);
                    if (pInvItem != pItem && !ITEMS_GetInvPage(pInvItem)
                        && DATATBLS_GetItemsTxtRecord(!pInvItem ? -1 : pInvItem->dwClassId)->dwCode == pItemsTxtRecord->dwCode)
                    {
                        nQuantity += STATLIST_UnitGetStatValue(pInvItem, STAT_QUANTITY, 0);
                    }
                }
            }

            if (nQuantity <= gaQtyWarn_00722380[j].nLevel2)
            {
                INV_DrawWarningIcon(gaQtyWarn_00722380[j].nFrame + 2);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel1)
            {
                INV_DrawWarningIcon(gaQtyWarn_00722380[j].nFrame + 1);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel0)
            {
                INV_DrawWarningIcon(gaQtyWarn_00722380[j].nFrame);
            }
        }
    }
}

static void __stdcall sub_00497CF0_DrawDurabilityIcon(int nState, int bType, int nQuiverType, int nBodyLoc)
{
    int nFrame = nState * 11;
    switch (nBodyLoc)
    {
    case 1:
        nFrame += 1;
        break;
    case 3:
        nFrame += 4;
        break;
    case 4:
        if (nQuiverType)
            nFrame += 10;
        else if (bType)
            nFrame += 7;
        else
            nFrame += 6;
        break;
    case 5:
        if (nQuiverType)
            nFrame += 9;
        else if (bType)
            nFrame += 5;
        else
            nFrame += 8;
        break;
    case 8:
        nFrame += 2;
        break;
    case 9:
        nFrame += 3;
        break;
    case 10:
        nFrame += 0;
        break;
    }
    int nOffset = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BEF60;
    tContext.nDirection = 0;
    tContext.nFrame = nFrame;
    if (GAME_GetUIVarState(10))
    {
        if (ROSTER_IsAnyoneHostile())
            nOffset = 0x2B;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x3C, nOffset + 0x8C, -1, 1, 0);
    }
    else
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x3C, 0x6E, -1, 1, 0);
}

// 0x00497FE0
void __cdecl PANEL_DrawDurabilityIcons()
{
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    for (int j = 0; j < 7; ++j)
    {
        const int nLoc = gnBodyLocs_007223E8[j];
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nLoc);
        if (!pItem || !ITEMS_HasDurability(pItem) || ITEMS_CheckIfStackable(pItem))
            continue;
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (!nMaxDurability)
            continue;
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability <= 20)
            goto found;
    }
    return;
found:
    for (int i = 0; i < 7; ++i)
    {
        const int nBodyLoc = gnBodyLocs_007223E8[i];
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        int nState = 0;
        int bType = 0;
        int nQuiverType = 0;
        if (pItem)
        {
            if (ITEMS_HasDurability(pItem) && !ITEMS_CheckIfStackable(pItem))
            {
                const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
                bType = ITEMSIsA(pItem, 0x33);
                nQuiverType = ITEMS_GetQuiverType(pItem);
                if (nMaxDurability)
                {
                    const int nPercent = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability;
                    if (nPercent <= 0)
                        nState = 2;
                    else if (nPercent <= 20)
                        nState = 1;
                }
            }
        }
        else if (nBodyLoc == 4 || nBodyLoc == 5)
            continue;
        sub_00497CF0_DrawDurabilityIcon(nState, bType, nQuiverType, nBodyLoc);
    }
}

// 0x004983D0
static void PANEL_DrawControlPanelFrame(int nOffset)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (D2GFX_GetResolutionMode() - 2)
    {
        if (!gpCel_007BEF1C)
        {
            gpCel_007BEF1C = sub_004520C0_LoadUiCelFile("Panel\\CtrlPnl7");
        }
        if (gpCel_007BEF74)
        {
            ARCHIVE_FreeClientCellFile(gpCel_007BEF74);
            gpCel_007BEF74 = 0;
        }
        if (gpBorderFrameCel_007BEF18)
        {
            ARCHIVE_FreeClientCellFile(gpBorderFrameCel_007BEF18);
            gpBorderFrameCel_007BEF18 = 0;
        }
        tContext.pCellFile = gpCel_007BEF1C;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnGlobal_00711470 - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x9B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x1B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x65, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x75, gnGlobal_00711470 - nOffset, -1, 5, 0);
    }
    else
    {
        if (gpCel_007BEF1C)
        {
            ARCHIVE_FreeClientCellFile(gpCel_007BEF1C);
            gpCel_007BEF1C = 0;
        }
        if (!gpCel_007BEF74)
        {
            gpCel_007BEF74 = sub_004520C0_LoadUiCelFile("Panel\\800CtrlPnl7");
        }
        tContext.pCellFile = gpCel_007BEF74;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnGlobal_00711470 - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xEB, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x6B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x15, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x95, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 5;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x75, gnGlobal_00711470 - nOffset, -1, 5, 0);
    }
}

void __cdecl sub_00499040_DrawBelt()
{
    sub_00502EF0(1);
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, 8);
    if (pBelt)
    {
        if (ITEMS_GetItemType(pBelt) == ITEMTYPE_BELT)
        {
            const int nBeltType = UNITS_GetBeltType(pBelt);
            D2_ASSERT(nBeltType >= 0, 0xB07);
            gnUiRecordIndex_00722354 = nBeltType;
        }
    }
    else
    {
        gnUiRecordIndex_00722354 = 2;
    }

    if (!GAME_GetUIVarState(0x1F) && !gnBeltRecordMode2_007BEF9C)
        gbUiRecordMode_007BEF98 = 0;

    if (GAME_GetUIVarState(9))
        gbUiRecordMode_007BEF98 = 0;

    gbGlobal_007BEFA0 = 0;
    if (gbUiRecordMode_007BEF98)
    {
        unsigned char abShow[3];
        abShow[0] = 1;
        abShow[1] = 1;
        abShow[2] = 1;
        switch (gnUiRecordIndex_00722354)
        {
        case 2:
            abShow[0] = 0;
            abShow[1] = 0;
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 0;
            break;
        case 1:
        case 4:
            abShow[1] = 0;
        case 0:
        case 5:
            abShow[2] = 0;
        case 3:
        default:
            gbGlobal_007BEFA0 = 1;
            break;
        }

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        tContext.pCellFile = gpCellFile_007BEF10;
        int nOffset = 0;
        unsigned char* pShow = abShow;
        for (int i = 0; i < 3; ++i)
        {
            if (*pShow)
                sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x15, gnGlobal_00711470 - nOffset - 0x29, -1, 5, 0);

            ++pShow;
            nOffset += 0x20;
        }
    }

    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int nSlot = 0; nSlot < tRecord.nBoxes; ++nSlot)
    {
        if (nSlot > 3 && !gbGlobal_007BEFA0)
            break;

        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
        if (!pItem)
            continue;

        int nBox;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nBox = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
                nBox = PATH_GetXPosition(pItem->pDynamicPath);
            else
                nBox = 0;
            break;
        }

        if (!ITEMS_CheckItemFlag(pItem, 4, 0x5D5, ".\\UI\\panel.cpp") && ITEMS_CheckIfUseable(pItem) && !sub_004C2240(pItem))
        {
            if (pItem == gpBeltItemA_007BEFA8 && gnBeltHover_007BEF94)
                PANEL_DrawBeltBoxFrame(nBox, 1);
            else
                PANEL_DrawBeltBoxFrame(nBox, 2);
        }
        else
        {
            PANEL_DrawBeltBoxFrame(nBox, 0);
        }

        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
        GFX_DrawItemCel(pItem, tRect.nLeft, tRect.nTop);
        if (nSlot < sizeof(gaBeltKeys_00722404) / sizeof(gaBeltKeys_00722404[0]) && ITEMS_CheckIfUseable(pItem))
        {
            Unicode wszKey[100];
            for (int i = 0; i < 100; ++i)
            {
                wszKey[i].wChar = 0;
            }

            if (CUNIT_GetHotkeyBinding(gaBeltKeys_00722404[nSlot], 1) != 0xFFFF || CUNIT_GetHotkeyBinding(gaBeltKeys_00722404[nSlot], 0) != 0xFFFF)
            {
                sub_005267E0(wszKey, CMDTBL_GetKeyName(gaBeltKeys_00722404[nSlot], 1));
                const int nLength = sub_00526800(wszKey);
                if (D2Win_10121_GetTextWidth(wszKey) > 0x1C)
                {
                    Unicode* pEnd = &wszKey[nLength];
                    do
                    {
                        pEnd->wChar = 0;
                        --pEnd;
                    }
                    while (D2Win_10121_GetTextWidth(wszKey) > 0x1C);
                }
                D2Win_10117_DrawText(wszKey, tRect.nLeft + 2, tRect.nBottom - 2, 4, 0);
            }
        }
    }

    if (gnUiRecordIndex_00722354 == 2 || GAME_GetUIVarState(0x1F) || gbUiRecordMode_007BEF98)
        PANEL_DrawCursorBeltBox(pInventory);
}

struct D2UnitStrc;

static int __stdcall sub_004987E0_GetBeltBoxAt(int nY, int nX)
{
    D2UiRecordStrc tRecord;
    int nResult = -1;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int i = 0; i < tRecord.nBoxes; ++i)
    {
        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, i);
        if (nX >= tRect.nLeft && nX <= tRect.nRight && nY >= tRect.nTop && nY <= tRect.nBottom)
        {
            nResult = i;
            break;
        }
    }
    return nResult;
}

static void __stdcall sub_00498870_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox == -1)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    if (sub_00468830() == 6)
    {
        return;
    }

    if (pCursorItem && ITEMS_CheckIfBeltable(pCursorItem))
    {
        const int bBusy = sub_004C2240(pCursorItem);
        if (pBeltItem)
        {
            if (!bBusy)
            {
                sub_004786A0_SendDwords2(0x25, pCursorItem->dwUnitId, pBeltItem->dwUnitId);
                sub_004C21F0(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendDwords2(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            sub_004C21F0(pCursorItem);
        }
        sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !sub_004C2240(pBeltItem))
    {
        sub_00478680_SendPacket5(0x24, pBeltItem->dwUnitId);
        sub_004C21F0(pBeltItem);
    }
}

void __stdcall sub_A11_Emit_00498870(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498870_ClickBeltBox(pPlayer->pInventory, nX, nY);
}

// 0x00498930
static void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox < 0)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (sub_00468830() == 6 || sub_00468830() == 8)
    {
        return;
    }

    if (pCursorItem)
    {
        gnBeltBox_0072235C = nBox;
        gnBeltHover_007BEF94 = 1;
        gpBeltItemA_007BEFA8 = 0;
        gpBeltItemB_007BEFAC = 0;
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    gnBeltBox_0072235C = nBox;
    if (pItem)
    {
        gnBeltHover_007BEF94 = 1;
        if (pItem == gpBeltItemB_007BEFAC)
        {
            return;
        }

        D2UiRectStrc tRect;
        const int nBoxId = CLIENTS_GetUnitX(pItem);
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBoxId);
        gpBeltItemA_007BEFA8 = pItem;
        gpBeltItemB_007BEFAC = pItem;
        gnBeltRectX_00722360 = tRect.nLeft + 0xE;
        gnBeltRectY_00722364 = tRect.nTop;
    }
    else
    {
        gnBeltHover_007BEF94 = 0;
        gpBeltItemA_007BEFA8 = 0;
        gpBeltItemB_007BEFAC = 0;
    }
}

static int __stdcall sub_00498A20_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState)
{
    D2_ASSERT(pState, 0xA3D);
    if (pState->nUnique == 1 || pState->nQuest == 1)
    {
        sub_0049FF90_Close(pItem, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    sub_004CB9C0_Request(pPlayer, 0x14);
    return 0;
}

static void PANEL_BeltHotkey(int nSlot)
{
    if (GAME_IsExitPending() || sub_00463DF0())
    {
        return;
    }

    if (gabBeltHotkey_007BEFB0[nSlot] != 1)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498A90_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

void __cdecl PANEL_BeltHotkeyFirst()
{
    PANEL_BeltHotkey(0);
}

void __cdecl PANEL_BeltHotkeySecond()
{
    PANEL_BeltHotkey(1);
}

void __cdecl PANEL_BeltHotkeyThird()
{
    PANEL_BeltHotkey(2);
}

void __cdecl PANEL_BeltHotkeyFourth()
{
    PANEL_BeltHotkey(3);
}

void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* __restrict pMsg)
{
    if (!gdwGlobal_007A061C || GAME_IsExitPending() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* __restrict pPlayer = sub_00463DD0_GetPlayerUnit();
    if (GAME_IsLeftClickRepeating())
    {
        return;
    }

    if (gbUiRecordMode_007BEF98)
    {
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        {
            if (GAME_GetUIVarState(0x1F))
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
            }
            sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!GAME_GetUIVarState(0x1F))
        {
            pMsg->bReturn = 0;
            gbUiRecordMode_007BEF98 = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        else
        {
            pMsg->bReturn = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (nX < gnGlobal_0071146C / 2 + 0x17 || nX > gnGlobal_0071146C / 2 + 0x91 || nY < gnGlobal_00711470 - 0x27 || nY > gnGlobal_00711470 - 0xA)
    {
        pMsg->bReturn = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (!UI_GetUIVarUnchecked(9))
    {
        gbUiRecordMode_007BEF98 = 1;
        gnBeltRecordMode2_007BEF9C = 1;
        sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x00498A90
static void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift)
{
    if (!GAME_IsExpansion())
    {
        bShift = 0;
    }

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return;
    }

    if (GAME_GetUIVarState(9))
    {
        return;
    }

    D2Block1 tBlock1;
    const int nClass = UNITS_GetInventoryRecordId(pPlayer, 0, GAME_IsExpansion());
    sub_0065C1F0(nClass, gnUiRecordRow_007A5218, &tBlock1);
    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
    if (!pItem)
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxt, 0xA64);
    if (sub_00498A20_CheckState(pPlayer, pItem, pItemsTxt) != 1)
    {
        return;
    }

    if (sub_004C2240(pItem))
    {
        return;
    }

    sub_004786D0_SendDwords3(0x26, pItem->dwUnitId, bShift, 0);
    sub_004C21F0(pItem);
    if (bShift)
    {
        const int nPetId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
        if (nPetId != -1)
        {
            if (ITEMSIsA(pItem, 0x4C) || ITEMSIsA(pItem, 0x51) || ITEMSIsA(pItem, 0x50))
            {
                sub_004CBDE0_PlayEventSound(nPetId, 1, 0x54);
            }
            else
            {
                sub_004CBDE0_PlayEventSound(nPetId, 1, 0x55);
            }
            gnBeltHover_007BEF94 = 0;
            return;
        }

        sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
        gnBeltHover_007BEF94 = 0;
        return;
    }

    sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
    gnBeltHover_007BEF94 = 0;
}

// 0x00499450
void __cdecl PANEL_DrawControlPanel()
{
    int nOffset = 0;
    if (sub_004F5140() == 3)
    {
        nOffset = 1;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (sub_0045AE90() == 2 || sub_0045AE90() == 3)
        {
            PANEL_DrawBorderFrameLeft();
        }
        if (sub_0045AE90() == 1 || sub_0045AE90() == 3)
        {
            PANEL_DrawBorderFrameRight();
        }
    }
    PANEL_DrawControlPanelFrame(nOffset);
    PANEL_DrawLifeOrb();
    PANEL_DrawManaOrb();
    PANEL_DrawExperienceBar();
    VIEW_DrawRunButton();
    PANEL_DrawStaminaBar();
    PANEL_DrawMiniPanelButton();
    sub_00499040_DrawBelt();
    PANEL_ValidateActiveSkills();
    sub_00497A40_DrawPanelText();
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId_007BEFF0 != nLevelId)
        {
            gnLevelId_007BEFF0 = nLevelId;
            gnLevelTimer_007BEFEC = 0x3C;
        }
    }
    PANEL_UpdateMiniPanelTooltip();
}


static __forceinline void CancelCursorMode()
{
    if(sub_00468830()==6) UI_CancelCursorItemUse();
    else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
}

// 0x004996A0
void __stdcall PANEL_BeltMouseReleaseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || sub_00463DF0()) {
        pMsg->bReturn=0;
        return;
    }
    D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
    const int x=pMsg->nXpos;
    const int y=pMsg->nYpos;
    gnGlobal_007BEF88=0;
    gnGlobal_007BEF84=0;
    if(gnGlobal_007BEFA4) {
        if(gbUiRecordMode_007BEF98) {
            if(AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) {
                CancelCursorMode();
                sub_00498870_ClickBeltBox(pPlayer->pInventory,x,y);
                pMsg->bReturn=1;
                pMsg->lResult=0;
                sub_00420290_BreakHandlerChain(pMsg);
            }
            else if(x>=gnGlobal_0071146C/2-8 && x<=gnGlobal_0071146C/2+5 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-13) {
                if(GAME_GetUIVarState(21)) sub_00455F20(21,1,0);
                else sub_00455F20(21,2,0);
            }
            else if(x>=117 && x<=165 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) {
                sub_00455F20(3,2,0);
                sub_004A8CE0_SetValue(1);
            }
            else if(x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) {
                sub_00455F20(3,2,0);
                sub_004A8CE0_SetValue(0);
            }
            else if(x>=gnGlobal_0071146C/2-145 && x<=gnGlobal_0071146C/2-128 && y>=gnGlobal_00711470-28 && y<=gnGlobal_00711470-8) {
                GAME_SetAlwaysRun(!GAME_GetAlwaysRun());
            }
            gnGlobal_007BEFA4=0;
        }
        else if(y>gnGlobal_00711470-48) {
            if(x>=gnGlobal_0071146C/2+23 && x<=gnGlobal_0071146C/2+145 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-10) {
                CancelCursorMode();
                sub_00498870_ClickBeltBox(pPlayer->pInventory,x,y);
            }
            else if(x>=117 && x<=165 && y<=gnGlobal_00711470) {
                CancelCursorMode();
                if(GAME_GetUIVarState(3)) sub_00455F20(3,1,0);
                else sub_00455F20(3,0,0);
                sub_004A8CE0_SetValue(1);
            }
            else if(x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y<=gnGlobal_00711470) {
                CancelCursorMode();
                if(GAME_GetUIVarState(3)) sub_00455F20(3,1,0);
                else sub_00455F20(3,0,0);
                sub_004A8CE0_SetValue(0);
            }
            else if(x>=gnGlobal_0071146C/2-145 && x<=gnGlobal_0071146C/2-128 && y>=gnGlobal_00711470-28 && y<=gnGlobal_00711470-8) {
                GAME_SetAlwaysRun(!GAME_GetAlwaysRun());
            }
            else if(x>=gnGlobal_0071146C/2-8 && x<=gnGlobal_0071146C/2+5 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-13) {
                if(GAME_GetUIVarState(21)) sub_00455F20(21,1,0);
                else sub_00455F20(21,2,0);
                if(gnGlobal_007BEFD0) gnGlobal_007BEFD4=!gnGlobal_007BEFD4;
            }
            gnGlobal_007BEFA4=0;
            gnGlobal_00722358=0;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_00420290_BreakHandlerChain(pMsg);
        }
        else {
            pMsg->bReturn=0;
        }
    }
    else {
        if((x>=117 && x<=165 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) ||
           (x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470)) {
            if(GAME_GetUIVarState(3)) sub_00455F20(3,1,0);
        }
        gnGlobal_007BEFA4=0;
        pMsg->bReturn=0;
    }
    gnGlobal_007BEFD0=0;
    gnGlobal_007BEFD8=0;
}

#include "gen/data/Source/D2Client/UI/panel_004978D0.inc"
