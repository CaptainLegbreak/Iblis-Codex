#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2ItemsWorld.h"

struct Unicode;
struct UnicodeChar;
struct D2QtyWarnStrc;

struct UnicodeChar
{
    unsigned short wChar;

    UnicodeChar();                                                                                          // 0x0042F530
    UnicodeChar(unsigned short ch) : wChar(ch) {}
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnBeltHover_007BEF94; // 0x007BEF94
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0
D2UnitStrc* __fastcall sub_00463DD0(); // 0x00463DD0
int __cdecl sub_00489840_IsNpcState123(); // 0x00489840
void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060
int __fastcall sub_004B2AD0(D2UnitStrc* pItem, int nArg, int* pOut, UnicodeChar* pName, int nMaxLength); // 0x004B2AD0
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const void* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

struct D2QtyWarnStrc
{
    int nWarnType;
    int nFrame;
    unsigned int nLevel0;
    unsigned int nLevel1;
    unsigned int nLevel2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned char gabSlots_007BEFB4[]; // 0x007BEFB4
extern int gaBodyLocs_00722374[]; // 0x00722374
extern unsigned int gnBodyLocCount_0072237C; // 0x0072237C
extern D2QtyWarnStrc gaQtyWarn_00722380[]; // 0x00722380
extern unsigned int gnQtyWarnCount_007223E4; // 0x007223E4
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
void __stdcall sub_00497C50_DrawSlotIcon(int nFrame); // 0x00497C50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* pItem); // 0x00629800
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C

D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00497A40
void __cdecl sub_00497A40_DrawBeltItemHoverText()
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

    sub_0048C060_BuildItemName(gpBeltItemA_007BEFA8, wszName, 0x80);
    if (ITEMS_GetItemQuality(gpBeltItemA_007BEFA8) != ITEMQUAL_SUPERIOR)
    {
        sub_004E6410_BuildPropText(gpBeltItemA_007BEFA8, wszProps, 0x100, 1, 0);
    }

    sub_005267E0(wszText, sub_004521C0_PrefixLevelText(wszProps, 3));
    sub_00526700(wszText, sub_004521C0_PrefixLevelText(wszName, 0));
    if (gnBeltRectX_00722360 < 0 || gnBeltRectY_00722364 < 0)
    {
        return;
    }

    sub_00452170(wszText);
    if (sub_00489840_IsNpcState123())
    {
        UnicodeChar wszSocket[0x40] = { 0 };
        int nUnused;
        if (sub_004B2AD0(gpBeltItemA_007BEFA8, 1, &nUnused, wszSocket, 0x40) && wszSocket[0].wChar)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText, wszSocket);
        }
    }

    D2Win_10129_DrawFramedText(wszText, gnBeltRectX_00722360, gnBeltRectY_00722364, 0, 1);
}

#include "gen/data/Source/D2Client/UI/panel_00497A40.inc"
struct D2UnitStrc;

// 0x00497E00
void __cdecl sub_00497E00()
{
    memset(gabSlots_007BEFB4, 0, 6);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pRightArm = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArm = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if ((pRightArm && ITEMS_GetAmmoType(pRightArm) && (!pLeftArm || !ITEMSIsA(pLeftArm, ITEMS_GetAmmoType(pRightArm))))
        || (pLeftArm && ITEMS_GetAmmoType(pLeftArm) && (!pRightArm || !ITEMSIsA(pRightArm, ITEMS_GetAmmoType(pLeftArm)))))
    {
        sub_00497C50_DrawSlotIcon(2);
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

            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_00451F60_UnitClassId(pItem));
            unsigned int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            if (!ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
            {
                for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
                {
                    D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pNode);
                    if (pInvItem != pItem && !ITEMS_GetInvPage(pInvItem)
                        && DATATBLS_GetItemsTxtRecord(!pInvItem ? -1 : pInvItem->dwClassId)->dwCode == pItemsTxtRecord->dwCode)
                    {
                        nQuantity += STATLIST_UnitGetStatValue(pInvItem, 0x46, 0);
                    }
                }
            }

            if (nQuantity <= gaQtyWarn_00722380[j].nLevel2)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame + 2);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel1)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame + 1);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel0)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame);
            }
        }
    }
}
