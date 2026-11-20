#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct Unicode
{
    unsigned short wChar;
};



struct D2UiRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2UiRecordStrc
{
    char unk0x00[4];
    unsigned char nBoxes;
    unsigned char unk0x05;
    unsigned short unk0x06;
    D2UiRectStrc aRects[16];
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44[1];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                          // 0x0046A530
int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall sub_004C2240(D2UnitStrc* pItem);                                                             // 0x004C2240
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0
int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                              // 0x00628C20
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId);              // 0x0063C7F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord);                    // 0x00660CB0
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnUiRecordRow_007A5218;                                                                          // 0x007A5218
extern D2CelFileStrc* gpCellFile_007BEF10;                                                                  // 0x007BEF10
unsigned char gabBeltColors_007BEF6C[4];                                                                    // 0x007BEF6C
extern int gnBeltHover_007BEF94;                                                                            // 0x007BEF94
int gbUiRecordMode_007BEF98;                                                                                // 0x007BEF98
extern int gnBeltRecordMode2_007BEF9C;                                                                      // 0x007BEF9C
int gbGlobal_007BEFA0;                                                                                      // 0x007BEFA0
extern D2UnitStrc* gpBeltItemA_007BEFA8;                                                                    // 0x007BEFA8

void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

static void __stdcall sub_004978D0_DrawBeltBoxFrame(int nBox, int nColor)
{
    sub_004972B0_InitBeltColors();
    if (nColor == 2)
        return;

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
    sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, 0x1D, 0x1D, gabBeltColors_007BEF6C[nColor], 0);
}

static void __cdecl sub_00497920_DrawCursorBeltBox(D2InventoryStrc* pInventory)
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
        sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 1);
        return;
    }

    int nResult;
    if (sub_0063C830_CanPlaceInBelt(pInventory, pItem, gnBeltBox_0072235C, &nResult))
    {
        sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 3);
        return;
    }

    sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 0);
}

void __cdecl sub_004972B0_InitBeltColors(); // 0x004972B0
static void __stdcall sub_004978D0_DrawBeltBoxFrame(int nBox, int nColor); // 0x004978D0
static void __cdecl sub_00497920_DrawCursorBeltBox(D2InventoryStrc* pInventory); // 0x00497920

// 0x00499040
void __cdecl sub_00499040_DrawBelt()
{
    sub_00502EF0(1);
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, 8);
    if (pBelt)
    {
        if (ITEMS_GetItemType(pBelt) == 0x13)
        {
            const int nBeltType = UNITS_GetBeltType(pBelt);
            if (nBeltType >= 0)
            {
                gnUiRecordIndex_00722354 = nBeltType;
            }
            else
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xB07);
                exit(-1);
            }
        }
    }
    else
    {
        gnUiRecordIndex_00722354 = 2;
    }

    if (!sub_004538D0(0x1F) && !gnBeltRecordMode2_007BEF9C)
        gbUiRecordMode_007BEF98 = 0;

    if (sub_004538D0(9))
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
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 1;
            break;
        case 0:
        case 5:
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 1;
            break;
        case 3:
        default:
            gbGlobal_007BEFA0 = 1;
            break;
        }

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.unk0x40 = 0;
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
        case 2:
        case 4:
        case 5:
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
                sub_004978D0_DrawBeltBoxFrame(nBox, 1);
            else
                sub_004978D0_DrawBeltBoxFrame(nBox, 2);
        }
        else
        {
            sub_004978D0_DrawBeltBoxFrame(nBox, 0);
        }

        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
        sub_0046EE80_DrawItemCel(pItem, tRect.nLeft, tRect.nTop);
        if (nSlot < sizeof(gaBeltKeys_00722404) / sizeof(gaBeltKeys_00722404[0]) && ITEMS_CheckIfUseable(pItem))
        {
            Unicode wszKey[100];
            for (int i = 0; i < 100; ++i)
            {
                wszKey[i].wChar = 0;
            }

            if (sub_00469AA0(gaBeltKeys_00722404[nSlot], 1) != 0xFFFF || sub_00469AA0(gaBeltKeys_00722404[nSlot], 0) != 0xFFFF)
            {
                sub_005267E0(wszKey, sub_0046A530_GetKeyName(gaBeltKeys_00722404[nSlot], 1));
                const int nLength = sub_00526800(wszKey);
                if (sub_00501820(wszKey) > 0x1C)
                {
                    Unicode* pEnd = &wszKey[nLength];
                    do
                    {
                        pEnd->wChar = 0;
                        --pEnd;
                    }
                    while (sub_00501820(wszKey) > 0x1C);
                }
                sub_00502320(wszKey, tRect.nLeft + 2, tRect.nBottom - 2, 4, 0);
            }
        }
    }

    if (gnUiRecordIndex_00722354 == 2 || sub_004538D0(0x1F) || gbUiRecordMode_007BEF98)
        sub_00497920_DrawCursorBeltBox(pInventory);
}

#include "gen/data/Source/D2Client/UI/panel_00499040.inc"
struct D2UnitStrc;
