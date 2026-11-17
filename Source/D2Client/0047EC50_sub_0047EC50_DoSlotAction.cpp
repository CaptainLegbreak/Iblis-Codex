struct D2InventoryStrc;

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

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                   // 0x006CC200
void __fastcall sub_004A3FE0(int nMode);                                                                    // 0x004A3FE0
void __fastcall sub_00456300(int nArg1, int nArg2);                                                         // 0x00456300
void __cdecl sub_00453AC0();                                                                                // 0x00453AC0
void __fastcall sub_0047E090(int bSaveState, int nMenu);                                                // 0x0047E090
void __cdecl sub_00453AD0();                                                                                // 0x00453AD0
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __cdecl sub_00468830();                                                                                 // 0x00468830
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __cdecl sub_004979E0();                                                                                 // 0x004979E0
int __cdecl sub_004979F0();                                                                                 // 0x004979F0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall sub_00451F70_GetUnitMode(D2UnitStrc* pUnit);                                                 // 0x00451F70
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
extern int gbSlotClicked_007BC97C;                                                                          // 0x007BC97C
extern int gdwGlobal_007BC978;                                                                              // 0x007BC978
extern int gdwGlobal_007BC970;                                                                              // 0x007BC970
extern int gdwGlobal_007BC974;                                                                              // 0x007BC974
extern int gdwGlobal_007BC968;                                                                              // 0x007BC968
extern int gdwGlobal_007BC96C;                                                                              // 0x007BC96C
extern int gnSlotState_007BC8F8[];                                                                          // 0x007BC8F8
extern int gnSlotX_007BC898[];                                                                              // 0x007BC898
extern int gaSlotKind_007BC8D8[];                                                                           // 0x007BC8D8
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470

// 0x0047EC50
static void sub_0047EC50_DoSlotAction(int nButton)
{
    switch (nButton)
    {
    case 0:
        if (sub_004538D0(2))
            sub_00455F20(2, 1, 0);
        else
            sub_00455F20(2, 2, 0);
        break;
    case 1:
        if (sub_004538D0(1))
            sub_00455F20(1, 1, 0);
        else
            sub_00455F20(1, 2, 0);
        break;
    case 2:
        if (sub_004538D0(4))
            sub_00455F20(4, 1, 0);
        else
            sub_00455F20(4, 2, 0);
        break;
    case 3:
        if (sub_0044DB30())
        {
            if (sub_004538D0(0x16))
                sub_00455F20(0x16, 1, 0);
            else
                sub_00455F20(0x16, 2, 0);
        }
        break;
    case 4:
        if (sub_004538D0(0xA))
            sub_00455F20(0xA, 1, 0);
        else
            sub_00455F20(0xA, 2, 0);
        break;
    case 5:
        if (sub_004538D0(0x1F))
            sub_00455F20(0x1F, 1, 0);
        if (sub_004538D0(0x18))
            sub_00455F20(0x18, 1, 0);
        else
            sub_00455F20(0x18, 2, 0);
        break;
    case 6:
        OutputDebugStringA("Panel quest log toggle\n");
        sub_004A3FE0(0);
        break;
    case 7:
        sub_00456300(0, 0);
        sub_00453AC0();
        sub_0047E090(1, 0);
        sub_00453AD0();
        sub_00453AE0();
        break;
    }
}

void __stdcall sub_0047ED90_SlotsClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!gbSlotClicked_007BC97C)
        return;
    gbSlotClicked_007BC97C = 0;
    if (!pPlayer)
        return;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
        return;
    if (INVENTORY_GetCursorItem(pInventory))
        return;
    if (sub_00468830() != 7)
        sub_00468070_SetCursorItemState(0);
    int nCount = 8;
    if (gdwGlobal_007BC978)
        nCount = 7;
    if (!gdwGlobal_007BC970)
    {
        D2UnitStrc* pUnit = sub_00463DD0();
        const int nX = pMsg->nXPos;
        const int nY = pMsg->nYPos;
        int nOffset = 0;
        for (int i = 0; i < nCount; ++i)
            gnSlotState_007BC8F8[i] = 0;
        if (sub_004979E0() && sub_004979F0() > 1)
            nOffset = -0x76;
        if (gdwGlobal_007BC968)
            nOffset -= 0x76;
        if (gdwGlobal_007BC96C)
            nOffset += 0x77;
        const int nCenter = gnGlobal_0071146C / 2 + nOffset;
        if (nX > nCenter - 0x54 && nX < nCenter + 0x59 && nY > gnGlobal_00711470 - 0x45 && nY < gnGlobal_00711470 - 0x2F)
        {
            for (int i = 0; i < nCount; ++i)
            {
                if (nX > gnSlotX_007BC898[i] && nX < gnSlotX_007BC898[i] + 0x14)
                {
                    const int nButton = gaSlotKind_007BC8D8[i];
                    if (nButton == 7 || (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit) && sub_00451F70_GetUnitMode(pUnit) != 0x11))
                        sub_0047EC50_DoSlotAction(nButton);
                }
            }
            sub_0044DA40();
            sub_0044DA70();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }
        pMsg->bReturn = 0;
    }
    gdwGlobal_007BC974 = 0;
}
