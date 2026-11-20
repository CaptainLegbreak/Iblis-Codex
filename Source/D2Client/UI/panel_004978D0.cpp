#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2StaticPathStrc;
struct D2UiRectStrc;
struct D2UiRecordStrc;
struct D2Block1;

struct Unicode
{
    unsigned short wChar;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB); // 0x0046A530
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall sub_00628C20(D2UnitStrc* pItem); // 0x00628C20
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
extern int gnBeltHover_007BEF94; // 0x007BEF94
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
extern int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C
extern int gbGlobal_007BEFA0; // 0x007BEFA0
extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8

struct D2ItemsTxt
{
    char unk0x000[0x11D];
    unsigned char bFlag0x11D;
    char unk0x11E[0x0B];
    unsigned char bFlag0x129;
    unsigned char bFlag0x12A;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nX;
    unsigned short nY;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bUseResult;
    int lResult;
};

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0
void __fastcall sub_004C21F0(D2UnitStrc* pItem);
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __cdecl sub_0044DA30(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
int __cdecl sub_0044BFE0(); // 0x0044BFE0
void __cdecl sub_00453EC0(); // 0x00453EC0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gdwGlobal_007A061C; // 0x007A061C
extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0
static __declspec(noinline) void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY);

// build: symbol ?sub_004972B0_InitBeltColors@@YAXXZ 0x004972B0
void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x004978D0
static void __stdcall sub_004978D0_DrawBeltBoxFrame(int nBox, int nColor)
{
    sub_004972B0_InitBeltColors();
    if (nColor == 2)
        return;

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
    sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, 0x1D, 0x1D, gabBeltColors_007BEF6C[nColor], 0);
}

// 0x00497920
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

void __cdecl sub_00499040_DrawBelt()
{
    sub_00502EF0(1);
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, 8);
    if (pBelt)
    {
        if (ITEMS_GetItemType(pBelt) == 0x13)
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

        if (!ITEMS_CheckItemFlag(pItem, 4, 0x5D5, ".\\UI\\panel.cpp") && sub_00628C20(pItem) && !sub_004C2240(pItem))
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
        sub_0046EE80_DrawCursorItem(pItem, tRect.nLeft, tRect.nTop);
        if (nSlot < sizeof(gaBeltKeys_00722404) / sizeof(gaBeltKeys_00722404[0]) && sub_00628C20(pItem))
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

#include "gen/data/Source/D2Client/UI/panel_004978D0.inc"

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
                sub_004786A0_SendIntInt(0x25, pCursorItem->dwUnitId, pBeltItem->dwUnitId);
                sub_004C21F0(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendIntInt(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
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
    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* pPlayer = sub_00463DD0();
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
    if (pState->bFlag0x129 == 1 || pState->bFlag0x12A == 1)
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

// 0x00498A90
static void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift)
{
    if (!sub_0044DCC0())
    {
        bShift = 0;
    }

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return;
    }

    if (sub_004538D0(9))
    {
        return;
    }

    D2Block1 tBlock1;
    const int nClass = UNITS_GetInventoryRecordId(pPlayer, 0, sub_0044DCC0());
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
            if (ITEMS_CheckItemTypeId(pItem, 0x4C) || ITEMS_CheckItemTypeId(pItem, 0x51) || ITEMS_CheckItemTypeId(pItem, 0x50))
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

        sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
        gnBeltHover_007BEF94 = 0;
        return;
    }

    sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
    gnBeltHover_007BEF94 = 0;
}

static void sub_00498C10_BeltHotkey(int nSlot)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        return;
    }

    if (gabBeltHotkey_007BEFB0[nSlot] != 1)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    sub_00498A90_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

void __cdecl sub_00498C50_BeltHotkey0()
{
    sub_00498C10_BeltHotkey(0);
}

void __cdecl sub_00498C90_BeltHotkey1()
{
    sub_00498C10_BeltHotkey(1);
}

void __cdecl sub_00498CD0_BeltHotkey2()
{
    sub_00498C10_BeltHotkey(2);
}

void __cdecl sub_00498D10_BeltHotkey3()
{
    sub_00498C10_BeltHotkey(3);
}

// 0x00499BB0
void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* __restrict pMsg)
{
    if (!gdwGlobal_007A061C || sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* __restrict pPlayer = sub_00463DD0();
    if (sub_0044BFE0())
    {
        return;
    }

    if (gbUiRecordMode_007BEF98)
    {
        if (sub_00498DC0_MouseMoveMsg(pMsg))
        {
            if (sub_004538D0(0x1F))
            {
                pMsg->bUseResult = 1;
                pMsg->lResult = 0;
            }
            sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!sub_004538D0(0x1F))
        {
            pMsg->bUseResult = 0;
            gbUiRecordMode_007BEF98 = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        else
        {
            pMsg->bUseResult = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (nX < gnGlobal_0071146C / 2 + 0x17 || nX > gnGlobal_0071146C / 2 + 0x91 || nY < gnGlobal_00711470 - 0x27 || nY > gnGlobal_00711470 - 0xA)
    {
        pMsg->bUseResult = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (!sub_00453A90_GetUIVarUnchecked(9))
    {
        gbUiRecordMode_007BEF98 = 1;
        gnBeltRecordMode2_007BEF9C = 1;
        sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

// build: context sub_00499D10_BeltClick
void __stdcall sub_00499D10_BeltClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
        }
        else if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
        }

        const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
        if (nBox < 0)
        {
            pMsg->bUseResult = 0;
            return;
        }

        sub_00498A90_UseBeltSlot(nBox, pPlayer, pPlayer->pInventory, (pMsg->wParam >> 2) & 1);
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    pMsg->bUseResult = 0;
    gnBeltHover_007BEF94 = 0;
}
