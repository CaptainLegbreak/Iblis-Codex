#include "D2Client.h"
#include "D2Structs.h"
#include "D2StormTypes.h"

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_0045AE90(); // 0x0045AE90
void __cdecl sub_00466FF0(); // 0x00466FF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gdwGlobal_007A0650; // 0x007A0650
extern int gdwGlobal_007A0654; // 0x007A0654
extern int gdwGlobal_007A0658; // 0x007A0658
extern int gdwGlobal_007A065C; // 0x007A065C
extern int gdwGlobal_007A0660; // 0x007A0660
extern int gdwGlobal_007A0664; // 0x007A0664
extern int gdwGlobal_007A066C; // 0x007A066C
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnAutomapHeight_007A521C; // 0x007A521C
void __cdecl sub_0044C060_Refresh(); // 0x0044C060
int __stdcall D2GFX_Release(); // 0x004F5050
int __stdcall WINDOW_Destroy(); // 0x004F5900

static __declspec(noinline) unsigned short __cdecl sub_0044BEC0_GetClickFlags_static()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044C000
void __cdecl sub_0044C000_StartClick()
{
    gdwGlobal_0070F234 = 8;
    if (gdwGlobal_007A061C && gdwGlobal_007A0650 && !gdwGlobal_007A0658)
    {
        gdwGlobal_007A066C = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = sub_0044BEC0_GetClickFlags_static();
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            sub_00462D00(1, sub_00468730(), sub_00468740(), nFlags);
        }
    }
}

// 0x0044C180
void __stdcall sub_0044C180_OnClickUp(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F2BC = 4;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (!gdwGlobal_007A061C || sub_0045AE90() == 3)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnGlobal_0071146C / 2 && nY > 0 && nY < gnGlobal_00711470 - 0x2F)
    {
        bLeftPanel = 1;
    }
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnGlobal_0071146C / 2 && nX < gnGlobal_0071146C && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    if (bLeftPanel || bRightPanel)
    {
        pMsg->bReturn = 0;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gdwGlobal_007A0654 = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nFlags = sub_0044BEC0_GetClickFlags_static();
    if (pPlayer && pPlayer->dwUnitType == 0)
    {
        gdwGlobal_007A0654 = sub_00462D00(3, pMsg->nXpos, pMsg->nYpos, nFlags);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044C0F0
void __stdcall sub_0044C0F0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0044C060_Refresh();
}

// 0x0044C850
void __stdcall sub_0044C850(int nArg1, int nArg2, int nArg3)
{
    WINDOW_Destroy();
    D2GFX_Release();
}
