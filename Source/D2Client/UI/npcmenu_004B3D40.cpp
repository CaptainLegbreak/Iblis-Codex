#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;



#pragma pack(push, 2)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13[0x02];
    char bRefreshed;
};

#pragma pack(pop)
typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __fastcall sub_004B3C20(int nValue); // 0x004B3C20
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);
extern int gdwGlobal_007C0DB0; // 0x007C0DB0
extern D2UnitStrc* gpUnit_007C0DD4; // 0x007C0DD4
extern unsigned short gwGlobal_007C0DD8; // 0x007C0DD8
extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue); // 0x0044C860
void __cdecl sub_0044D520(); // 0x0044D520
void __cdecl sub_0044DA40(); // 0x0044DA40
int __cdecl sub_0044DB30(); // 0x0044DB30
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __cdecl sub_00463DF0(); // 0x00463DF0
int __cdecl sub_004680A0(); // 0x004680A0
void __cdecl sub_00477EE0_SendPacket69(); // 0x00477EE0
void __cdecl sub_0048A630_EnterState1(); // 0x0048A630
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc(); // 0x004B1620
void __cdecl sub_004B2110_FreeResources(); // 0x004B2110
void __cdecl sub_004B2900_CloseDialog(); // 0x004B2900
void __fastcall sub_004B8100(void* pObj);
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
extern D2ClientDialogStrc* gpDialog_007C0D63; // 0x007C0D63
extern D2ClientDialogStrc* gpDialog_007C0D67; // 0x007C0D67

// 0x004B3D40
int __cdecl sub_004B3D40_NpcMenuTradeB()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0D25, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        sub_004B3C20(gnGlobal_007C0D25);
        return 1;
    }

    gnGlobal_007C0C6B = 3;
    gdwGlobal_007C0DB0 = 1;
    sub_00455F20(0xC, 0, 0);
    sub_004786D0_SendDwords3(0x38, 2, gnGlobal_007C0D25, 0);
    gpUnit_007C0DD4 = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B3E10
void __fastcall sub_004B3E10_RefreshNpcEntries(D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;

    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
    {
        if (gaNpcEntries_00726850[i].bSelected == 1)
        {
            gaNpcEntries_00726850[i].bSelected = 0;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0xFAB);
            sub_004B1680(&gaNpcEntries_00726850[i]);
        }
        gaNpcEntries_00726850[i].bRefreshed = 1;
    }

    if (!(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        return;

    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    gnGlobal_007C0D29 = 0;
}

int gnGlobal_007C0DBC; // 0x007C0DBC

int gnGlobal_007C0DC0; // 0x007C0DC0

unsigned long gdwGlobal_007C0DC4; // 0x007C0DC4

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
