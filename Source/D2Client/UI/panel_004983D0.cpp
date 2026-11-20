#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2UiRectStrc;
struct D2UiRecordStrc;
struct D2Block1;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl sub_004F5140(); // 0x004F5140
void __cdecl sub_00498630_DrawBorderFrameLeft(); // 0x00498630
void __cdecl sub_00498700_DrawBorderFrameRight(); // 0x00498700
void __cdecl sub_00496F80_DrawLifeOrb(); // 0x00496F80
void __cdecl sub_00497110_DrawManaOrb(); // 0x00497110
void __cdecl sub_00498EA0_DrawExperienceBar(); // 0x00498EA0
void __cdecl sub_00497480_DrawButton(); // 0x00497480
void __cdecl sub_004975B0_DrawStaminaBar(); // 0x004975B0
void __cdecl sub_004977C0_DrawStateButton(); // 0x004977C0
void __cdecl sub_00499040_DrawBelt();
void __cdecl sub_00496CF0_ValidateActiveSkills(); // 0x00496CF0
void __cdecl sub_00497A40_DrawPanelText();
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
extern "C" void __cdecl sub_00498340_UpdateTooltip(); // 0x00498340
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern void* gpBorderFrameCel_007BEF18; // 0x007BEF18
extern int gnLevelTimer_007BEFEC; // 0x007BEFEC
extern int gnLevelId_007BEFF0; // 0x007BEFF0



struct D2UiRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2UiRecordStrc
{
    int unk0x00;
    unsigned char nBoxes;
    unsigned char unk0x05;
    unsigned short unk0x06;
    D2UiRectStrc aRects[16];
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0
int __cdecl sub_00468830(); // 0x00468830
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
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
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gnUiRecordRow_007A5218; // 0x007A5218
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
extern int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C
extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8
extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0

void* gpCel_007BEF1C; // 0x007BEF1C

void* gpCel_007BEF74; // 0x007BEF74

// 0x004983D0
static __declspec(noinline) void sub_004983D0_DrawControlPanelFrame(int nOffset)
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
            sub_00478A00(gpCel_007BEF74);
            gpCel_007BEF74 = 0;
        }
        if (gpBorderFrameCel_007BEF18)
        {
            sub_00478A00(gpBorderFrameCel_007BEF18);
            gpBorderFrameCel_007BEF18 = 0;
        }
        tContext.pCellFile = gpCel_007BEF1C;
        tContext.unk0x40 = 0;
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
            sub_00478A00(gpCel_007BEF1C);
            gpCel_007BEF1C = 0;
        }
        if (!gpCel_007BEF74)
        {
            gpCel_007BEF74 = sub_004520C0_LoadUiCelFile("Panel\\800CtrlPnl7");
        }
        tContext.pCellFile = gpCel_007BEF74;
        tContext.unk0x40 = 0;
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

// 0x00499450
void __cdecl sub_00499450_DrawControlPanel()
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
            sub_00498630_DrawBorderFrameLeft();
        }
        if (sub_0045AE90() == 1 || sub_0045AE90() == 3)
        {
            sub_00498700_DrawBorderFrameRight();
        }
    }
    sub_004983D0_DrawControlPanelFrame(nOffset);
    sub_00496F80_DrawLifeOrb();
    sub_00497110_DrawManaOrb();
    sub_00498EA0_DrawExperienceBar();
    sub_00497480_DrawButton();
    sub_004975B0_DrawStaminaBar();
    sub_004977C0_DrawStateButton();
    sub_00499040_DrawBelt();
    sub_00496CF0_ValidateActiveSkills();
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
    sub_00498340_UpdateTooltip();
}

int gnBeltHover_007BEF94; // 0x007BEF94

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
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498870_ClickBeltBox(pPlayer->pInventory, nX, nY);
}

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
        gpBeltItemB_007BEFAC = 0;
        gpBeltItemA_007BEFA8 = 0;
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    gnBeltBox_0072235C = nBox;
    if (!pItem)
    {
        gnBeltHover_007BEF94 = 0;
        gpBeltItemB_007BEFAC = 0;
        gpBeltItemA_007BEFA8 = 0;
        return;
    }

    gnBeltHover_007BEF94 = 1;
    if (pItem == gpBeltItemB_007BEFAC)
    {
        return;
    }

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, CLIENTS_GetUnitX(pItem));
    gpBeltItemA_007BEFA8 = pItem;
    gpBeltItemB_007BEFAC = pItem;
    gnBeltRectX_00722360 = tRect.nLeft + 0xE;
    gnBeltRectY_00722364 = tRect.nTop;
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

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// build: context sub_00499BB0_BeltMouseMove
void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gdwGlobal_007A061C || sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nY = pMsg->nY;
    const int nX = pMsg->nX;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
            gnBeltHover_007BEF94 = 0;
            return;
        }

        pMsg->bUseResult = 0;
        gnBeltRecordMode2_007BEF9C = 0;
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

void __stdcall sub_00499D10_BeltClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
