#include "D2Client.h"
#include "D2Structs.h"
#include "D2StormTypes.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
int __stdcall HIREABLES_CanEquipHirelingItem(int nArg); // 0x004934D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __stdcall sub_K04_EmitUse(int nValue);

static int gnPetIconPopupState; // 0x007BEECC

static int gnPopupX; // 0x007BEED4

static int gbPopupShown; // 0x007BEEDC

static int gbPopupPending; // 0x007BEEE0

static int gdwPopupTick; // 0x007BEEE8

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x00493760
void __stdcall sub_00493760_HirelingIconHoverMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!GAME_IsExpansion())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    gbPopupPending = 0;
    const int bHit = gnPetIconPopupState != 2 && InBox(nX, nY, gnPopupX, gnPopupX + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gbPopupShown = 0;
        gdwPopupTick = 0;
        return;
    }
    if (!gdwPopupTick)
    {
        gdwPopupTick = GetTickCount();
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pCursorItem = pPlayer ? INVENTORY_GetCursorItem(pPlayer->pInventory) : 0;
    if (!pCursorItem)
    {
        if (sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) != -1)
        {
            gbPopupPending = 1;
            if (GetTickCount() - gdwPopupTick >= 700)
            {
                gbPopupShown = 1;
            }
        }
    }
    if (HIREABLES_CanEquipHirelingItem(0))
    {
        gbPopupShown = 1;
    }
}

// 0x004938E0
void __stdcall sub_004938E0_HirelingIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!GAME_IsExpansion())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnPetIconPopupState != 2 && InBox(nX, nY, gnPopupX, gnPopupX + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gdwPopupTick = 0;
        return;
    }
    if (!gdwPopupTick)
    {
        gdwPopupTick = GetTickCount();
    }
    if (GetTickCount() - gdwPopupTick >= 700)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        if (!GAME_GetUIVarState(0x23) || GAME_GetUIVarState(0x24) || sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1)
        {
            return;
        }
        UI_SetUIVar(0x24, 0, 0);
    }
    gdwPopupTick = 0;
}

// 0x00494300
static inline void sub_00494300_SetHelpMenuSetting(unsigned long dwValue)
{
// build: symbol ?gdwHelpMenu@* 0x00722310
    gdwHelpMenu = dwValue;
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
