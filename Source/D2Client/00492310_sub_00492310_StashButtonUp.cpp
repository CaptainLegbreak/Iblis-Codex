struct D2InventoryStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};
struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};
void __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY); // 0x00486E10
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0
void __cdecl sub_004B90B0(); // 0x004B90B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
static int sub_00483B10_IsInRect(int nX, int nY); // 0x00483B10
static int sub_00486DA0_IsOverGoldButton(int nX, int nY); // 0x00486DA0
static int sub_00489430_IsOverButtonA(int nX, int nY); // 0x00489430
static int sub_00489480_IsOverButtonB(int nX, int nY); // 0x00489480
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_007BCA34; // 0x007BCA34
extern int gnGlobal_007BCA38; // 0x007BCA38
extern int gnGlobal_007BCA3C; // 0x007BCA3C
extern int gnGlobal_007BCA40; // 0x007BCA40
extern int gnGlobal_007BCA4C; // 0x007BCA4C
extern int gnGlobal_007BCAA0; // 0x007BCAA0
extern int gnGlobal_007BCAA4; // 0x007BCAA4
extern int gnGlobal_007BCAA8; // 0x007BCAA8
extern int gnGlobal_007BCAAC; // 0x007BCAAC
extern int gnGlobal_007BCBD8; // 0x007BCBD8
extern int gnGlobal_007BCBF0; // 0x007BCBF0
extern int gnGlobal_007BCE18; // 0x007BCE18
extern int gnGlobal_007BCE1C; // 0x007BCE1C
extern int gnGlobal_007BCE20; // 0x007BCE20
extern int gnGlobal_007BCE24; // 0x007BCE24
extern int gnGlobal_007BCE30; // 0x007BCE30
extern int gnGlobal_007BCE90; // 0x007BCE90
extern int gnGlobal_007BCE9C; // 0x007BCE9C

// 0x00483B10
static __declspec(noinline) int sub_00483B10_IsInRect(int nX, int nY)
{
    if (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
    {
        return 1;
    }
    return 0;
}

// 0x00486DA0
static int sub_00486DA0_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
    {
        return 0;
    }
    if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x57 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x45
        && nX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0xED && nX <= gnGlobal_0071146C - gnGlobal_007A2858 - 0xD9)
    {
        return 1;
    }
    return 0;
}

// 0x00489430
static int sub_00489430_IsOverButtonA(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0xDF && nX < gnGlobal_007A2858 + 0xFF
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00489480
static int sub_00489480_IsOverButtonB(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x133
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00492310
void __stdcall sub_00492310_StashButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BCBF0 != 0xB)
        return;
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if (!sub_00498DC0_MouseMoveMsg(pMsg) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gnGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
        return;
    if ((nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4
        && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
        || sub_00483B10_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        return;
    }
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE1C = 0;
        sub_004B90B0();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489430_IsOverButtonA(nX, nY))
    {
        gnGlobal_007BCE20 = 1;
        if (gnGlobal_007BCE18 == 1)
        {
            gnGlobal_007BCE18 = 0;
            sub_004B90B0();
        }
        else
        {
            gnGlobal_007BCE18 = 1;
            gnGlobal_007BCE9C = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489480_IsOverButtonB(nX, nY))
    {
        gnGlobal_007BCE24 = 1;
        gnGlobal_007BCE1C = 1;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE1C = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE1C = 0;
        gnGlobal_007BCE20 = 0;
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gnGlobal_007BCE24 = 0;
    gnGlobal_007BCE20 = 0;
}
