struct D2InventoryStrc;
struct D2ClientDialogStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    char unk0x28[0x38];
    D2InventoryStrc* pInventory;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860
void __cdecl sub_0044D520();                                                                                // 0x0044D520
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                       // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
int __cdecl sub_00463DF0();                                                                    // 0x00463DF0
int __cdecl sub_004680A0();                                                                       // 0x004680A0
void __cdecl sub_00477EE0_SendPacket69();                                                                   // 0x00477EE0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __cdecl sub_0048A630_EnterState1();                                                                    // 0x0048A630
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620
void __cdecl sub_004B2110_FreeResources();                                                                  // 0x004B2110
void __cdecl sub_004B2900_CloseDialog();                                                                    // 0x004B2900
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __fastcall sub_004B8100(void* pObj);
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern unsigned long gdwGlobal_007C0D53;                                                                    // 0x007C0D53
extern int gnGlobal_007C0D57;                                                                               // 0x007C0D57
extern D2ClientDialogStrc* gpDialog_007C0D5F;                                                               // 0x007C0D5F
extern D2ClientDialogStrc* gpDialog_007C0D63;                                                               // 0x007C0D63
extern D2ClientDialogStrc* gpDialog_007C0D67;                                                               // 0x007C0D67
extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
extern D2ClientDialogStrc* gpDialog_007C0D6F;                                                               // 0x007C0D6F
extern D2ClientDialogStrc* gpDialog_007C0D73;                                                               // 0x007C0D73
extern D2ClientDialogStrc* gpDialog_007C0D77;                                                               // 0x007C0D77
extern D2ClientDialogStrc* gpDialog_007C0D7B;                                                               // 0x007C0D7B
int gnGlobal_007C0DBC;                                                                                      // 0x007C0DBC
int gnGlobal_007C0DC0;                                                                                      // 0x007C0DC0
unsigned long gdwGlobal_007C0DC4;                                                                           // 0x007C0DC4
extern int gnGlobal_007C0DE9;                                                                               // 0x007C0DE9
extern int gnGlobal_007C0DED;                                                                               // 0x007C0DED

#define NPC_GET_INTERACT_UNIT() (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0)

// 0x004B4380
void __cdecl sub_004B4380_UpdateNpcInteract()
{
    D2UnitStrc* pNpc;
    if (sub_00463DF0() || (NPC_GET_INTERACT_UNIT() && (pNpc = NPC_GET_INTERACT_UNIT()) != 0 && pNpc->dwAnimMode == 12) || !NPC_GET_INTERACT_UNIT())
    {
        sub_004B2110_FreeResources();
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }

    if (gpDialog_007C0D6F)
    {
        sub_004B8100(gpDialog_007C0D6F);
        return;
    }

    if (gpDialog_007C0D73)
    {
        sub_004B8100(gpDialog_007C0D73);
        return;
    }

    if (gpDialog_007C0D6B)
    {
        sub_0044DA40();
        sub_004B8100(gpDialog_007C0D6B);
        return;
    }

    if (gpDialog_007C0D63)
    {
        sub_004B8100(gpDialog_007C0D63);
        return;
    }

    if (gpDialog_007C0D67)
    {
        D2UnitStrc* pInteract;
        if (sub_004B1620_GetInteractNpc() && (pInteract = sub_004B1620_GetInteractNpc()) != 0 && pInteract->dwClassId == 0x202 && !gnGlobal_007C0DBC)
        {
            if (!gnGlobal_007C0DC0)
            {
                gnGlobal_007C0DC0 = 1;
                gdwGlobal_007C0DC4 = (ITEMS_RollLimitedRandomNumber(&sub_00463DD0_GetPlayerUnit()->pSeed, 30) + 120) * 1000 + GetTickCount();
            }

            if (gdwGlobal_007C0DC4 > GetTickCount())
            {
                gnGlobal_007C0DBC = 1;
                sub_004B9A00(0x11D0, 0, 0, 0, 0);
            }
        }

        if (sub_0044DB30() && gnGlobal_007C0D57 && gnGlobal_007C0D57 < GetTickCount())
        {
            sub_004B2900_CloseDialog();
            return;
        }

        if (gdwGlobal_007C0D53 < GetTickCount())
        {
            sub_00477EE0_SendPacket69();
            sub_0044B880_SetValue(0);
            sub_0044C860_SetValue(1);
            sub_0044D520();
        }
        return;
    }

    if (gpDialog_007C0D5F)
    {
        if (!INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory) && !sub_004680A0())
        {
            sub_004B8100(gpDialog_007C0D5F);
            return;
        }

        gnGlobal_007C0C6B = 3;
        sub_0048A630_EnterState1();
        gnGlobal_007C0DE9 = GetTickCount();
        gnGlobal_007C0DED += 1;
        sub_004B8020(gpDialog_007C0D5F);
        gpDialog_007C0D5F = 0;
        return;
    }

    if (gpDialog_007C0D77)
    {
        sub_004B8100(gpDialog_007C0D77);
        return;
    }

    if (gpDialog_007C0D7B)
    {
        sub_004B8100(gpDialog_007C0D7B);
    }
}
