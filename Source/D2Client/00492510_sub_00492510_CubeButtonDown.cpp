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

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_0044DCC0();
void __cdecl sub_00453EC0();
int __cdecl sub_0045AE90();
D2UnitStrc* __cdecl sub_00463DD0();
int __cdecl sub_00468830();
int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_004979E0();
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
int __cdecl D2GFX_GetResolutionMode();
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_007BCA68;
extern int gnGlobal_007BCA6C;
extern int gnGlobal_007BCA74;
extern int gnGlobal_007BCA7C;
extern int gnGlobal_007BCA80;
extern int gnGlobal_007BCA84;
extern int gnGlobal_007BCA88;
extern int gnGlobal_007BCAF4;
extern int gnGlobal_007BCAF8;
extern int gnGlobal_007BCB00;
extern int gnGlobal_007BCB44;
extern int gnGlobal_007BCB48;
extern int gnGlobal_007BCB4C;
extern int gnGlobal_007BCB50;
static int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C
static int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8
static int gdwGlobal_007BCBE4;
static int gdwGlobal_007BCBE8;
static int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
static int gnGlobal_007BCE18;                                                                               // 0x007BCE18
static int gnGlobal_007BCE20;                                                                               // 0x007BCE20
static int gnGlobal_007BCE30;                                                                               // 0x007BCE30
static int gnGlobal_007BCE34;                                                                               // 0x007BCE34
static int gnGlobal_007BCE38;                                                                               // 0x007BCE38
static int gnGlobal_007BCE3C;                                                                               // 0x007BCE3C
static int gbGlobal_007BCE90;                                                                               // 0x007BCE90
static int gnGlobal_007BCE9C;                                                                               // 0x007BCE9C

static __declspec(noinline) int sub_00483B40_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_00486AE0_GetPanelX()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_007A2858 + 0x113;
    }
    return gnGlobal_007A2858 + 0x110;
}

int __cdecl sub_00486B00_GetPanelY()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x41;
    }
    return gnGlobal_007A285C + gnGlobal_00711470 - 0x40;
}

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

int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E || nX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E)
    {
        return 0;
    }
    if (nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x60 || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 0;
    }
    return 1;
}

static void __stdcall sub_00486E60_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        return;
    }
    if (nY > gnGlobal_00711470 - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
    }
    if (sub_0045AE90() == 3 && gdwGlobal_007BCBF0 == 0 && nX < gnGlobal_0071146C / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static int sub_00489920_IsOverCloseButton(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x1C7 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6
            && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x103 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0xF2
        && nX >= gnGlobal_007A2858 + 0x49 && nX <= gnGlobal_007A2858 + 0x96)
    {
        return 1;
    }
    return 0;
}

static int sub_00489980_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > sub_00486AE0_GetPanelX() && nX < sub_00486AE0_GetPanelX() + 0x28
        && nY > sub_00486B00_GetPanelY() - 0x23 && nY < sub_00486B00_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00492510
void __stdcall sub_00492510_CubeButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xC && gdwGlobal_007BCBF0 != 0xD)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if ((!sub_004979E0() || !sub_00498DC0_MouseMoveMsg(pMsg)) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00489980_IsOverTransmuteButton(nX, nY))
    {
        gnGlobal_007BCE3C = 1;
        gnGlobal_007BCE38 = 1;
        gnGlobal_007BCE9C = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483AB0_IsInInvRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483B40_IsInRect(nX, nY))
    {
        sub_004912A0_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY))
    {
        gnGlobal_007BCE30 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00489920_IsOverCloseButton(nX, nY))
    {
        gnGlobal_007BCE34 = 1;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE3C = 0;
        return;
    }
    if (sub_00483BA0_IsInRect(nX, nY))
    {
        gnGlobal_007BCE34 = 0;
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE18 = 0;
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE38 = 0;
        gnGlobal_007BCE3C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_00486E60_ClickOutsidePanel(nY, pMsg, nX);
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE3C = 0;
}
