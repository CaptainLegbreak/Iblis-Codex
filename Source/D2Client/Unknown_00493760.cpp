#include "D2Client.h"
#include "D2Structs.h"


struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
int __stdcall sub_004934D0_CheckBoxAction(int nArg); // 0x004934D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __stdcall sub_K04_EmitUse(int nValue);

static int gnGlobal_007BEECC; // 0x007BEECC

static int gnPopupX_007BEED4; // 0x007BEED4

static int gbPopupShown_007BEEDC; // 0x007BEEDC

static int gnGlobal_007BEEE0; // 0x007BEEE0

static int gdwPopupTick_007BEEE8; // 0x007BEEE8

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x00493760
void __stdcall sub_00493760_HirelingIconHoverMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0044DCC0())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    gnGlobal_007BEEE0 = 0;
    const int bHit = gnGlobal_007BEECC != 2 && InBox(nX, nY, gnPopupX_007BEED4, gnPopupX_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gbPopupShown_007BEEDC = 0;
        gdwPopupTick_007BEEE8 = 0;
        return;
    }
    if (!gdwPopupTick_007BEEE8)
    {
        gdwPopupTick_007BEEE8 = GetTickCount();
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pCursorItem = pPlayer ? INVENTORY_GetCursorItem(pPlayer->pInventory) : 0;
    if (!pCursorItem)
    {
        if (sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) != -1)
        {
            gnGlobal_007BEEE0 = 1;
            if (GetTickCount() - gdwPopupTick_007BEEE8 >= 700)
            {
                gbPopupShown_007BEEDC = 1;
            }
        }
    }
    if (sub_004934D0_CheckBoxAction(0))
    {
        gbPopupShown_007BEEDC = 1;
    }
}

// 0x004938E0
void __stdcall sub_004938E0_HirelingIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0044DCC0())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnGlobal_007BEECC != 2 && InBox(nX, nY, gnPopupX_007BEED4, gnPopupX_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gdwPopupTick_007BEEE8 = 0;
        return;
    }
    if (!gdwPopupTick_007BEEE8)
    {
        gdwPopupTick_007BEEE8 = GetTickCount();
    }
    if (GetTickCount() - gdwPopupTick_007BEEE8 >= 700)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_004538D0(0x23) || sub_004538D0(0x24) || sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1)
        {
            return;
        }
        sub_00455F20(0x24, 0, 0);
    }
    gdwPopupTick_007BEEE8 = 0;
}

// 0x00494300
static __forceinline void sub_00494300_SetHelpMenuSetting(unsigned long dwValue)
{
    gdwHelpMenu_00722310 = dwValue;
    SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
}

void __fastcall sub_M115_Emit_00494300(unsigned long dwValue)
{
    sub_00494300_SetHelpMenuSetting(dwValue);
}

// 0x00494FF0
static int __stdcall sub_00494FF0_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// build: context sub_K04_EmitIsMouseInBox
void __fastcall sub_K04_EmitIsMouseInBox(int nX, int nY)
{
    sub_K04_EmitUse(sub_00494FF0_IsMouseInBox(nX + 0x31, nY - 0x27, 0x23, 0x25));
}

// 0x004967E0
void __cdecl sub_004967E0_Empty()
{
}

// 0x00496980
void __cdecl sub_00496980_Empty()
{
}
