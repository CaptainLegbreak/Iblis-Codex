#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct UIWidget;
struct SpinnerWrapper;
struct ListBoxWrapper;
struct D2ListBoxEntryStrc;
struct ListBoxImplementation;
struct D2HotspotStrc;
struct D2MsgHandlerEntryStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned int wParam;
        };
        struct
        {
            unsigned char unk_08[0x2];
            short nWParamHi;
        };
    };
    union
    {
        unsigned short nXpos;
        unsigned short nXPos;
    };
    union
    {
        unsigned short nYpos;
        unsigned short nYPos;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct UIWidget
{
    virtual void Slot00();
    virtual void Slot04();
    virtual int Slot08(int nArg);
    virtual int Slot0C(int nArg);
    virtual int Slot10(int nArg);
    virtual int Slot14(int nArg);
    virtual int Slot18(int nArg);
    virtual int Slot1C(int nArg);
    virtual int Slot20(int nArg);
    virtual int Slot24(int nArg);
    virtual int Slot28(int nArg);
    virtual int Slot2C(int nArg);
    virtual int Slot30(int nArg);
    virtual int Slot34(int nArg);
    virtual int Slot38(int nArg);
    virtual int Slot3C(int nArg);
};

struct SpinnerWrapper
{
    virtual void Slot00();
    int unk0x04;
    UIWidget* pImpl;

    int sub_004BC290_ForwardSlot0C(int nArg);
    int sub_004BC2A0_ForwardSlot10(int nArg);
    int sub_004BC2B0_ForwardSlot14(int nArg);
    int sub_004BC2D0_ForwardSlot18(int nArg);
    int sub_004BC2E0_ForwardSlot20(int nArg);
    int sub_004BC2F0_ForwardSlot1C(int nArg);
    int sub_004BC300_ForwardSlot24(int nArg);
    int sub_004BC310_ForwardSlot28(int nArg);
};

struct ListBoxWrapper
{
    virtual void Slot00();
    int unk0x04;
    UIWidget* pImpl;

    int sub_004BED40_ForwardSlot20(int nArg);
    int sub_004BED50_ForwardSlot1C(int nArg);
    int sub_004BED60_ForwardSlot24(int nArg);
    int sub_004BED70_ForwardSlot28(int nArg);
    int sub_004BED80_ForwardSlot0C(int nArg);
    int sub_004BED90_ForwardSlot10(int nArg);
    int sub_004BEDA0_ForwardSlot14(int nArg);
    int sub_004BEDB0_ForwardSlot18(int nArg);
    int sub_004BEDE0_ForwardSlot3C(int nArg);
    int sub_004BEE20_ForwardSlot08(int nArg);
};

struct D2ListBoxEntryStrc
{
    char unk0x0000[0x3006];
    char nData[4];
    char unk0x300A[4];
};

typedef void (__cdecl* ListBoxCallback)();

struct ListBoxImplementation
{
    virtual void Slot00();
    virtual void Slot04();
    virtual int Slot08(SMSGHANDLER_PARAMS* pMsg);
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot1C(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot20(SMSGHANDLER_PARAMS* pMsg);

    D2ListBoxEntryStrc aEntries[0x80];
    char unk0x180704[0x2C];
    int f_180730;
    int unk0x180734;
    int nSelectedIndex;
    char unk0x18073C[0xC];
    unsigned short nEntryCount;
    char pfnCallback[4];
    char f_18074E[4];
    char unk0x180752[8];
    char nX[4];
    char nY[4];
    char f_180762[4];
    char unk0x180766[0xC];
    char nState[4];

    int sub_004BE720_HitTestTopRow(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE770_HitTestBottomRow(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE7C0_HitTestRows(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE860_WheelMsg(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEBC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEC40_GetEntryData(int nIndex);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnGlobal_007C5474; // 0x007C5474
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
int __stdcall sub_00489060_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489060

struct D2HotspotStrc
{
    char unk0x00[0x10];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    char unk0x20[0x04];
    char bFlag0x24;
    char bFlag0x25;
    char unk0x26[0x02];
};

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern D2HotspotStrc gaHotspots_00727902[]; // 0x00727902
extern int gnGlobal_007C5478; // 0x007C5478
extern int gnGlobal_007C547C; // 0x007C547C
extern unsigned long gdwTick_007C5488; // 0x007C5488

struct D2UnitStrc
{
    char unk0x00[0x4];
    unsigned int dwClassId;
    char unk0x08[0x4];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

extern int gnGlobal_007C5480; // 0x007C5480
extern int gnGlobal_007C5470; // 0x007C5470
extern void* gpGlobal_007C5484; // 0x007C5484
extern D2MsgHandlerEntryStrc gaMsgHandlers_00727950[]; // 0x00727950
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall sub_004922A0_ClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004922A0
void __fastcall sub_004BFBC0_HitTestHotspots(int nX, int nY); // 0x004BFBC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __cdecl sub_004B1670(); // 0x004B1670
int __cdecl sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
void __fastcall sub_00467430(void* pRect); // 0x00467430
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue); // 0x0044C860
void __cdecl sub_0044D520(); // 0x0044D520
void __cdecl sub_004C0380_OpenPanel(); // 0x004C0380
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700
void __cdecl sub_004B3FE0(); // 0x004B3FE0

// 0x004BC290
int SpinnerWrapper::sub_004BC290_ForwardSlot0C(int nArg)
{
    return pImpl->Slot0C(nArg);
}

// 0x004BC2A0
int SpinnerWrapper::sub_004BC2A0_ForwardSlot10(int nArg)
{
    return pImpl->Slot10(nArg);
}

// 0x004BC2B0
int SpinnerWrapper::sub_004BC2B0_ForwardSlot14(int nArg)
{
    return pImpl->Slot14(nArg);
}

// 0x004BC2D0
int SpinnerWrapper::sub_004BC2D0_ForwardSlot18(int nArg)
{
    return pImpl->Slot18(nArg);
}

// 0x004BC2E0
int SpinnerWrapper::sub_004BC2E0_ForwardSlot20(int nArg)
{
    return pImpl->Slot20(nArg);
}

// 0x004BC2F0
int SpinnerWrapper::sub_004BC2F0_ForwardSlot1C(int nArg)
{
    return pImpl->Slot1C(nArg);
}

// 0x004BC300
int SpinnerWrapper::sub_004BC300_ForwardSlot24(int nArg)
{
    return pImpl->Slot24(nArg);
}

// 0x004BC310
int SpinnerWrapper::sub_004BC310_ForwardSlot28(int nArg)
{
    return pImpl->Slot28(nArg);
}

// 0x004BE720
int ListBoxImplementation::sub_004BE720_HitTestTopRow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10 && nMouseY > *(int*)nY - 12 && nMouseY < *(int*)nY)
    {
        return 1;
    }
    return 0;
}

// 0x004BE770
int ListBoxImplementation::sub_004BE770_HitTestBottomRow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10)
    {
        const int nBottom = *(int*)nY + *(int*)f_180762 * 12;
        if (nMouseY > nBottom - 12 && nMouseY < nBottom)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004BE7C0
int ListBoxImplementation::sub_004BE7C0_HitTestRows(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10 && nMouseY < *(int*)nY + *(int*)f_180762 * 12 - 12 && nMouseY > *(int*)nY)
    {
        return 1;
    }
    return 0;
}

// 0x004BE860
int ListBoxImplementation::sub_004BE860_WheelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nWParamHi > 0)
    {
        nSelectedIndex = f_180730;
        Slot1C(pMsg);
    }
    else if (pMsg->nWParamHi < 0)
    {
        nSelectedIndex = f_180730 + *(int*)f_18074E - 1;
        Slot20(pMsg);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    return 1;
}

// 0x004BEBC0
int ListBoxImplementation::sub_004BEBC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (*(ListBoxCallback*)pfnCallback)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (*(unsigned int*)nState < 2)
        {
            return 0;
        }
        if (nSelectedIndex != -1 && pMsg->wParam == 0xD)
        {
            (*(ListBoxCallback*)pfnCallback)();
        }
        return 1;
    }
    return 0;
}

// 0x004BEC40
int ListBoxImplementation::sub_004BEC40_GetEntryData(int nIndex)
{
    if (nIndex >= 0 && nIndex < nEntryCount && nIndex < 0x80)
    {
        return *(int*)aEntries[nIndex].nData;
    }
    D2_ASSERT(nEntryCount < 0x80, 0x46C);
    D2_ASSERT(nEntryCount < nIndex, 0x46D);
    D2_ASSERT(nIndex >= 0, 0x46E);
    return 0;
}

// 0x004BED40
int ListBoxWrapper::sub_004BED40_ForwardSlot20(int nArg)
{
    return pImpl->Slot20(nArg);
}

// 0x004BED50
int ListBoxWrapper::sub_004BED50_ForwardSlot1C(int nArg)
{
    return pImpl->Slot1C(nArg);
}

// 0x004BED60
int ListBoxWrapper::sub_004BED60_ForwardSlot24(int nArg)
{
    return pImpl->Slot24(nArg);
}

// 0x004BED70
int ListBoxWrapper::sub_004BED70_ForwardSlot28(int nArg)
{
    return pImpl->Slot28(nArg);
}

// 0x004BED80
int ListBoxWrapper::sub_004BED80_ForwardSlot0C(int nArg)
{
    return pImpl->Slot0C(nArg);
}

// 0x004BED90
int ListBoxWrapper::sub_004BED90_ForwardSlot10(int nArg)
{
    return pImpl->Slot10(nArg);
}

// 0x004BEDA0
int ListBoxWrapper::sub_004BEDA0_ForwardSlot14(int nArg)
{
    return pImpl->Slot14(nArg);
}

// 0x004BEDB0
int ListBoxWrapper::sub_004BEDB0_ForwardSlot18(int nArg)
{
    return pImpl->Slot18(nArg);
}

// 0x004BEDE0
int ListBoxWrapper::sub_004BEDE0_ForwardSlot3C(int nArg)
{
    return pImpl->Slot3C(nArg);
}

// 0x004BEE20
int ListBoxWrapper::sub_004BEE20_ForwardSlot08(int nArg)
{
    return pImpl->Slot08(nArg);
}

// 0x004BFA30
void __stdcall sub_004BFA30_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    sub_00498DC0_MouseMoveMsg(pMsg);
    if (gnGlobal_007C5474 == 1)
    {
        sub_00489060_MouseMoveMsg(pMsg);
    }
}

// 0x004BFDB0
void __stdcall sub_004BFDB0_BreakMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

void* gpCelFile_007C5494; // 0x007C5494

void* gpCelFile_007C5498; // 0x007C5498

// 0x004BF9D0
void __cdecl sub_004BF9D0()
{
    gnGlobal_007C5474 = 0;
    gnGlobal_007C547C = 0;
    gnGlobal_007C5478 = 0;
    gdwTick_007C5488 = 0;
    gpCelFile_007C5494 = sub_004520C0_LoadUiCelFile("menu\\upgrade");
    gpCelFile_007C5498 = sub_004520C0_LoadUiCelFile("menu\\horadricback");
    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        gaHotspots_00727902[i].bFlag0x25 = 0;
        gaHotspots_00727902[i].bFlag0x24 = 0;
    }
}

// 0x004C0100
void __cdecl sub_004C0100()
{
    if (gnGlobal_007C5474)
    {
        sub_004C0090();
    }

    if (gpCelFile_007C5494)
    {
        sub_00478A00(gpCelFile_007C5494);
        gpCelFile_007C5494 = 0;
    }

    if (gpCelFile_007C5498)
    {
        sub_00478A00(gpCelFile_007C5498);
        gpCelFile_007C5498 = 0;
    }
}

unsigned long gdwTick_007C5488; // 0x007C5488

static void sub_004BFA70_ToggleUseMode(D2UnitStrc* pItem)
{
    if (gnGlobal_007C5474 == 1)
    {
        gnGlobal_007C5474 = 2;
        sub_00468070_SetCursorItemState(0);
        if (!pItem)
            return;
        gnGlobal_007C5480 = pItem->dwUnitId;
        sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
        return;
    }
    if (gnGlobal_007C5474 == 2)
    {
        gnGlobal_007C5474 = 1;
        gnGlobal_007C5480 = 0;
        if (pItem)
            sub_00468070_SetCursorItemState(pItem);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

static D2UnitStrc* GetCursorItem_Inline()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return 0;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    return INVENTORY_GetCursorItem(pInventory);
}

// 0x004BFC50
void __stdcall sub_004BFC50_OnClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYPos;
    const int nX = pMsg->nXPos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (GetTickCount() - gdwTick_007C5488 < 0x190)
        return;
    gdwTick_007C5488 = GetTickCount();
    int bHandled;
    if (gnGlobal_007C5474 == 1)
    {
        bHandled = sub_004922A0_ClickMsg(pMsg);
    }
    else if (gnGlobal_007C5474 == 2)
    {
        bHandled = sub_00489190(pMsg);
    }
    else
    {
        goto check_item;
    }
    if (bHandled)
        return;
    sub_004BFBC0_HitTestHotspots(nX, nY);
check_item:
    D2UnitStrc* pItem = GetCursorItem_Inline();
    if (!pItem)
        return;
    if (nX < 0x7B || nX > 0x7B + 0x58 || nY < 0x6A || nY > 0x6A + 0x72)
        return;
    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pTxt)
        return;
    if (ITEMS_CheckItemFlag(pItem, 0x10, 0x210, ".\\UI\\UseItem.cpp"))
    {
        if (gnGlobal_007C5470 == 1)
        {
            if (sub_004B1670() == 0x9A && sub_0062C590(pItem))
                goto use_item;
            if (sub_004B1670() == 0x1FF && sub_0062C770(pItem))
                goto use_item;
            if (sub_004B1670() == 0x200 && sub_0062C6A0(pItem))
                goto use_item;
        }
        else if (!gnGlobal_007C5470 && pTxt->dwCode == 0x20747368)
        {
            goto use_item;
        }
    }
    sub_004B9A00(3, 0, 0, 0, 0);
    return;
use_item:
    sub_004BFA70_ToggleUseMode(pItem);
}

// 0x004C0080
void __cdecl sub_004C0080_Return()
{
}

// 0x004C0D00
void __cdecl sub_004C0D00_Reset()
{
    sub_00477EE0();
    sub_0044B880_SetValue(0);
    sub_0044C860_SetValue(1);
    sub_0044D520();
}

int gnGlobal_007C5470; // 0x007C5470

int gnGlobal_007C5478; // 0x007C5478

int gnGlobal_007C547C; // 0x007C547C

// 0x004C0620
void __fastcall sub_004C0620_OpenPanelMode1(int nValue)
{
    gnGlobal_007C5470 = 1;
    gnGlobal_007C5478 = nValue;
    sub_004C0380_OpenPanel();
}

// 0x004C0150
void __stdcall sub_004C0150_OnPanelClose(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    const int nMode = gnGlobal_007C5474;
    if (nMode != 1)
    {
        if (nMode != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = sub_00463DD0();
        D2InventoryStrc* pInventory = pPlayer ? pPlayer->pInventory : 0;
        sub_00468070_SetCursorItemState(pPlayer ? INVENTORY_GetCursorItem(pInventory) : 0);
    }

    if (!gnGlobal_007C5470)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        const int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
        const int nValue = gnGlobal_007C547C;
        sub_00478700_SendCommand(0x44, nUnitId, nValue, 0, 2);
        sub_004C0090();
    }
    else
    {
        sub_004B3FE0();
        sub_004C0090();
    }
}
