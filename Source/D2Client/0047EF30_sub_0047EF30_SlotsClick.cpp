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
    int dwUnitType;
    char unk0x04[0xC];
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
};

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __cdecl sub_004979E0();                                                                                 // 0x004979E0
int __cdecl sub_004979F0();                                                                                 // 0x004979F0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30

extern int gdwGlobal_007BC978;                                                                              // 0x007BC978
extern int gdwGlobal_007BC970;                                                                              // 0x007BC970
extern int gdwGlobal_007BC968;                                                                              // 0x007BC968
extern int gdwGlobal_007BC96C;                                                                              // 0x007BC96C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gaSlotX_007BC898[];                                                                              // 0x007BC898
extern int gaSlotKind_007BC8D8[];                                                                           // 0x007BC8D8
int gaSlotState_007BC8F8[8];                                                                                // 0x007BC8F8
static int gbSlotClicked_007BC97C;                                                                          // 0x007BC97C

// 0x0047EF30
void __stdcall sub_0047EF30_SlotsClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nSlots = 8;
    if (gdwGlobal_007BC978)
    {
        nSlots = 7;
    }
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || !pPlayer->pInventory || INVENTORY_GetCursorItem(pPlayer->pInventory) || gdwGlobal_007BC970)
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00463DD0();
    if (!pUnit)
    {
        return;
    }
    int nY = pMsg->nYPos;
    int nX = pMsg->nXPos;
    int nOffset = 0;
    if (sub_004979E0() && sub_004979F0() > 1)
    {
        nOffset = -0x76;
    }
    if (gdwGlobal_007BC968)
    {
        nOffset -= 0x76;
    }
    if (gdwGlobal_007BC96C)
    {
        nOffset += 0x77;
    }
    int nCenter = gnGlobal_0071146C / 2 + nOffset;
    if (nX <= nCenter - 0x54 || nX >= nCenter + 0x59 || nY <= gnGlobal_00711470 - 0x45 || nY >= gnGlobal_00711470 - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nX > gaSlotX_007BC898[i] && nX < gaSlotX_007BC898[i] + 0x14)
        {
            if (gaSlotKind_007BC8D8[i] == 7)
            {
                gaSlotState_007BC8F8[i] = 1;
            }
            else if (pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11)
            {
                if (!sub_004538D0(9))
                {
                    gaSlotState_007BC8F8[i] = 1;
                }
                else if (!sub_0044DB30())
                {
                    if (i >= 4)
                    {
                        gaSlotState_007BC8F8[i] = 1;
                    }
                }
                else
                {
                    if (i >= 5)
                    {
                        gaSlotState_007BC8F8[i] = 1;
                    }
                }
            }
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSlotClicked_007BC97C = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }
    }
}
