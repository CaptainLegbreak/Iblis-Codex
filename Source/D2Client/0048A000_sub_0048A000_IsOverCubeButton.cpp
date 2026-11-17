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
    unsigned int wParam[1];
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int dwCommandSource;
    unsigned int dwArg[1];
    int bReturn;
    int lResult;
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __fastcall sub_00454150_OpenGoldPanel(int nMode);                                                      // 0x00454150
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY);                                               // 0x00486E10
void __cdecl sub_0048A050_CloseQuestPanel();                                                                // 0x0048A050
int __cdecl sub_004979E0();                                                                                 // 0x004979E0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
static int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C
static int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8
static int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
static int gnGlobal_007BCE18;                                                                               // 0x007BCE18
static int gnGlobal_007BCE20;                                                                               // 0x007BCE20
static int gnGlobal_007BCE2C;                                                                               // 0x007BCE2C
static int gnGlobal_007BCE30;                                                                               // 0x007BCE30
static int gnGlobal_007BCE40;                                                                               // 0x007BCE40
static int gnGlobal_007BCE44;                                                                               // 0x007BCE44
static int gnGlobal_007BCE48;                                                                               // 0x007BCE48
static int gnGlobal_007BCE4C;                                                                               // 0x007BCE4C
static int gbGlobal_007BCE90;                                                                               // 0x007BCE90
static int gnGlobal_007BCE94;                                                                               // 0x007BCE94
static int gnGlobal_007BCE9C;                                                                               // 0x007BCE9C

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

// 0x0048A000
static int sub_0048A000_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x90 && nX < gnGlobal_007A2858 + 0xB8
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0xDF && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x0048A190
void __stdcall sub_0048A190_CubeMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xE)
    {
        gnGlobal_007BCE9C = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbGlobal_007BCE90 = 0;
    gnGlobal_007BCE94 = 0;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    if (!sub_004979E0() && !INVENTORY_GetCursorItem(pInventory) && sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        sub_00455F20(0x1A, 1, 0);
        return;
    }
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        if (gnGlobal_007BCE40)
        {
            gnGlobal_007BCE40 = 0;
            sub_0048A050_CloseQuestPanel();
        }
        gnGlobal_007BCE9C = 0;
        gnGlobal_007BCE44 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (sub_0048A000_IsOverCubeButton(nX, nY))
    {
        if (gnGlobal_007BCE48)
        {
            gnGlobal_007BCE48 = 0;
            sub_00478600_SendShorts(0x4F, 0x18, 0, 0);
        }
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE9C = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gnGlobal_007BCE40 = 0;
    gnGlobal_007BCE44 = 0;
    gnGlobal_007BCE48 = 0;
    gnGlobal_007BCE4C = 0;
    if (sub_00498DC0_MouseMoveMsg(pMsg) == 1)
    {
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE4C = 0;
        return;
    }
    if (sub_00486DA0_IsOverGoldButton(nX, nY) && !gnGlobal_007BCE2C)
    {
        sub_00454150_OpenGoldPanel(1);
    }
    gnGlobal_007BCE30 = 0;
    if (gnGlobal_007BCE9C)
    {
        const int bFlag = gnGlobal_007BCE20;
        gnGlobal_007BCE9C = 0;
        if (bFlag)
        {
            if (gnGlobal_007BCE18)
                gnGlobal_007BCE18 = 0;
        }
        else if (gnGlobal_007BCE44)
        {
            if (gnGlobal_007BCE40)
                gnGlobal_007BCE40 = 0;
        }
        else if (gnGlobal_007BCE4C && gnGlobal_007BCE48)
        {
            gnGlobal_007BCE48 = 0;
        }
        gnGlobal_007BCE20 = 0;
        gnGlobal_007BCE4C = 0;
        gnGlobal_007BCE44 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE40 = 0;
    gnGlobal_007BCE48 = 0;
    gnGlobal_007BCE18 = 0;
}
