struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[4];
    unsigned int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXPos;
    unsigned short nYPos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

int gnGlobal_007C5470;                                                                                      // 0x007C5470
extern int gnGlobal_007C5474;                                                                               // 0x007C5474
int gnGlobal_007C5478;                                                                                      // 0x007C5478
int gnGlobal_007C547C;                                                                                      // 0x007C547C
void __cdecl sub_004C0380_OpenPanel();                                                                      // 0x004C0380
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3);      // 0x00478700
void __cdecl sub_004C0090();                                                                                // 0x004C0090
void __cdecl sub_004B3FE0();                                                                                // 0x004B3FE0

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
