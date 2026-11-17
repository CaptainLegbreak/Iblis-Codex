struct D2InventoryStrc;
struct D2ClientDialogStrc;
struct D2UnitStrc { char unk0x00[0x60]; D2InventoryStrc* pInventory; };

int __fastcall sub_004538D0(int nUIVar);                                                   // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar);                                        // 0x00453A90
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                               // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                   // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                     // 0x00463DD0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);     // 0x00478600
void __fastcall sub_00489360_SetTradePanelOpen(int bOpen);                                        // 0x00489360
void __fastcall sub_004897E0_UpdateSound(int nArg1, int nArg2);                                   // 0x004897E0
void __cdecl sub_00489E00_OpenUi();                                                               // 0x00489E00
void __cdecl sub_00489F50_CloseUiArchives();                                                      // 0x00489F50
void __cdecl sub_0048A460_CloseCubePanel();                                                       // 0x0048A460
void __cdecl sub_0048A6E0_SetFlag7BCE28();                                                        // 0x0048A6E0
void __cdecl sub_0048A6F0_Clear();                                                                // 0x0048A6F0
void __fastcall sub_004B8020(void* pRes);                                                         // 0x004B8020
int __cdecl sub_004B85E0();                                                                       // 0x004B85E0
void __fastcall sub_004B8940_CloseWait(int bReopen);                                              // 0x004B8940
int __cdecl sub_004B8AD0_OpenWait();                                                              // 0x004B8AD0
void __cdecl sub_004B8BF0_OpenWait2();                                                            // 0x004B8BF0
void __cdecl sub_004B8CB0();                                                                      // 0x004B8CB0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                // 0x004CB9C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                       // 0x0063C1E0
extern int gnGlobal_007C0E60;                                                                     // 0x007C0E60
extern unsigned long gdwGlobal_007C0E68;                                                          // 0x007C0E68
extern D2ClientDialogStrc* gpDialog_007C0E6C;                                                     // 0x007C0E6C
extern unsigned long gdwTick_007C0E70;                                                            // 0x007C0E70
extern unsigned long gdwGlobal_007C0E78;                                                          // 0x007C0E78
extern int gnGlobal_007C0E7C;                                                                     // 0x007C0E7C

// 0x004B8CF0
void __fastcall sub_004B8CF0_HandleTradePacket(const unsigned char* pPacket)
{
    switch (pPacket[1])
    {
    case 21:
        sub_0048A460_CloseCubePanel();
        return;

    case 16:
        sub_00489E00_OpenUi();
        return;

    case 17:
        sub_00489F50_CloseUiArchives();
        return;

    case 12:
        gnGlobal_007C0E7C = 0;
        sub_004B8940_CloseWait(0);
        return;

    case 13:
        gnGlobal_007C0E7C = 0;
        sub_004B8940_CloseWait(1);
        return;

    case 0:
        if (!gnGlobal_007C0E7C)
        {
            if (!sub_004538D0(0x17))
            {
                if (!sub_00455F20(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                sub_0048A6F0_Clear();
                gdwTick_007C0E70 = 0xFFFFFFFF;
            }

            gnGlobal_007C0E7C = 1;
            sub_004B8BF0_OpenWait2();
            sub_00489360_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 9:
        sub_004CB9C0_Request(sub_00463DD0(), 0x17);
        return;

    case 10:
    {
        D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0E60, 0);
        if (pUnit)
        {
            sub_004CB9C0_Request(pUnit, 0x17);
        }
        return;
    }

    case 1:
        if (!gnGlobal_007C0E7C)
        {
            D2InventoryStrc* const pInventory = sub_00463DD0()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (sub_004B85E0() || !sub_004B8AD0_OpenWait() || sub_004538D0(5))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (!sub_004538D0(0x17))
            {
                if (!sub_00455F20(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                gdwTick_007C0E70 = 0xFFFFFFFF;
            }

            gnGlobal_007C0E7C = 2;
            sub_00489360_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 2:
        sub_004897E0_UpdateSound(0, 0);
        sub_004B8940_CloseWait(0);
        return;

    case 5:
        if (!sub_00453A90_GetUIVarUnchecked(0x17))
        {
            return;
        }

        gdwTick_007C0E70 = 0xFFFFFFFF;
        sub_00489360_SetTradePanelOpen(1);
        switch (gnGlobal_007C0E7C)
        {
        case 3:
            gnGlobal_007C0E7C = 5;
        case 5:
            sub_004897E0_UpdateSound(0, 1);
            return;

        case 4:
            gnGlobal_007C0E7C = 6;
            sub_004897E0_UpdateSound(1, 1);
            return;

        case 6:
        case 7:
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 6:
        if (!sub_00453A90_GetUIVarUnchecked(0x17))
        {
            return;
        }

        sub_00478600_SendShorts(0x4F, 8, (unsigned short)(gdwGlobal_007C0E68 >> 16), (unsigned short)gdwGlobal_007C0E68);
        gdwTick_007C0E70 = 0xFFFFFFFF;
        sub_00489360_SetTradePanelOpen(1);
        switch (gnGlobal_007C0E7C)
        {
        case 7:
            gnGlobal_007C0E7C = 3;
        case 3:
            sub_004897E0_UpdateSound(0, 0);
            return;

        case 4:
        case 5:
        case 6:
            sub_004897E0_UpdateSound(0, 0);
            gnGlobal_007C0E7C = 3;
            return;

        case 1:
            gdwGlobal_007C0E78 = 0;
            sub_004897E0_UpdateSound(0, 0);
            gnGlobal_007C0E7C = 3;
            if (gpDialog_007C0E6C)
            {
                sub_004B8020(gpDialog_007C0E6C);
                gpDialog_007C0E6C = 0;
            }
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 14:
        sub_0048A6E0_SetFlag7BCE28();
        return;

    case 15:
        sub_0048A6F0_Clear();
        return;
    }
}
