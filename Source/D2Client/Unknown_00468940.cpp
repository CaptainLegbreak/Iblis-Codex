#include "D2Client.h"

#define BODYLOC_BELT 8
#define ITEMTYPE_BELT 19
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
int __cdecl sub_0044DB30(); // 0x0044DB30
int __cdecl sub_0044DA30(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
void __fastcall sub_004A3FE0(int nMode); // 0x004A3FE0
void __fastcall sub_00457640(int bForce); // 0x00457640
int __cdecl sub_004576C0(); // 0x004576C0
void __fastcall sub_004576F0(int nFade); // 0x004576F0
int __cdecl sub_004577B0(); // 0x004577B0
int __cdecl sub_004577E0(); // 0x004577E0
int __cdecl sub_00457770(); // 0x00457770
int __fastcall sub_00457780_SetValue(int nValue); // 0x00457780
void __fastcall sub_004A8CE0_SetValue(int nValue); // 0x004A8CE0
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey); // 0x004A9E60
void __fastcall sub_004AA030_SelectHotkey(int nSlot); // 0x004AA030
int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    unsigned char unk_14[0x4C];
    D2InventoryStrc* pInventory;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __fastcall sub_0044BE60_SetFlag(int nValue); // 0x0044BE60
int __cdecl sub_0044BE90(); // 0x0044BE90
void __fastcall sub_0044BE80(int bAlwaysRun); // 0x0044BE80
void __fastcall sub_0044BEA0_SetValue(int nValue); // 0x0044BEA0
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70
void __fastcall sub_00478590(char nValue); // 0x00478590
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __cdecl sub_004B34A0(); // 0x004B34A0
int __cdecl sub_004A0000(); // 0x004A0000
void __fastcall sub_0047E200(int nArg); // 0x0047E200
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __fastcall sub_0047E090(int bSaveState, int nMenu); // 0x0047E090
void __fastcall sub_004AA740_CycleHotkey(int nDelta); // 0x004AA740
void __cdecl sub_0048A730_ResetEquipSounds(); // 0x0048A730
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __cdecl sub_00466FE0(); // 0x00466FE0

// 0x00468940
void __cdecl sub_00468940_SetUIVar2()
{
    sub_00455F20(2, 2, 1);
}

// 0x00468950
void __cdecl sub_00468950_SetUIVar1()
{
    sub_00455F20(1, 2, 1);
}

// 0x00468960
void __cdecl sub_00468960_SetUIVar22()
{
    if (sub_0044DB30())
        sub_00455F20(0x16, 2, 1);
}

// 0x00468980
void __cdecl sub_00468980_SetUIVar24()
{
    sub_00455F20(0x18, 2, 0);
}

// 0x00468990
void __cdecl sub_00468990_OpenMode1()
{
    if (!sub_0044DA30() && !sub_00463DF0())
        sub_004A3FE0(1);
}

// 0x004689B0
void __cdecl sub_004689B0_SetUIVar5()
{
    if (!sub_0044DA30())
        sub_00455F20(5, 2, 0);
}

// 0x00468A30
void __cdecl sub_00468A30_SetUIVar10()
{
    sub_00455F20(0xA, 2, 0);
    if (!sub_004538D0(0xA))
        sub_00457640(0);
}

// 0x00468A60
void __cdecl sub_00468A60_Force()
{
    sub_00457640(1);
}

// 0x00468A70
void __cdecl sub_00468A70_CycleSetting()
{
    sub_004576F0((sub_004576C0() + 1) % 4);
}

// 0x00468A90
void __cdecl sub_00468A90_ToggleSetting()
{
    sub_004577C0_SetValue(!sub_004577B0());
}

// 0x00468AB0
void __cdecl sub_00468AB0_ToggleSetting()
{
    sub_004577F0_SetValue(!sub_004577E0());
}

// 0x00468AD0
void __cdecl sub_00468AD0_ToggleSetting()
{
    sub_00457780_SetValue(!sub_00457770());
}

// 0x00468AF0
void __cdecl sub_00468AF0_SetUIVar4()
{
    sub_00455F20(4, 2, 1);
}

// 0x00468B00
void __cdecl sub_00468B00_SetUIVar3()
{
    sub_00455F20(3, 2, 0);
    sub_004A8CE0_SetValue(0);
}

// 0x00468B90
void __cdecl sub_00468B90_Hotkey0()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(0);
        else
            sub_004AA030_SelectHotkey(0);
    }
}

// 0x00468BC0
void __cdecl sub_00468BC0_Hotkey1()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(1);
        else
            sub_004AA030_SelectHotkey(1);
    }
}

// 0x00468BF0
void __cdecl sub_00468BF0_Hotkey2()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(2);
        else
            sub_004AA030_SelectHotkey(2);
    }
}

// 0x00468C20
void __cdecl sub_00468C20_Hotkey3()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(3);
        else
            sub_004AA030_SelectHotkey(3);
    }
}

// 0x00468C50
void __cdecl sub_00468C50_Hotkey4()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(4);
        else
            sub_004AA030_SelectHotkey(4);
    }
}

// 0x00468C80
void __cdecl sub_00468C80_Hotkey5()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(5);
        else
            sub_004AA030_SelectHotkey(5);
    }
}

// 0x00468CB0
void __cdecl sub_00468CB0_Hotkey6()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(6);
        else
            sub_004AA030_SelectHotkey(6);
    }
}

// 0x00468CE0
void __cdecl sub_00468CE0_Hotkey7()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(7);
        else
            sub_004AA030_SelectHotkey(7);
    }
}

// 0x00468D10
void __cdecl sub_00468D10_Hotkey8()
{
    if (!sub_0044DA30() && !sub_00463DF0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(8);
        else
            sub_004AA030_SelectHotkey(8);
    }
}

// 0x00468D40
void __cdecl sub_00468D40_Hotkey9()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(9);
        else
            sub_004AA030_SelectHotkey(9);
    }
}

// 0x00468D80
void __cdecl sub_00468D80_Hotkey10()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(10);
        else
            sub_004AA030_SelectHotkey(10);
    }
}

// 0x00468DC0
void __cdecl sub_00468DC0_Hotkey11()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(11);
        else
            sub_004AA030_SelectHotkey(11);
    }
}

// 0x00468E00
void __cdecl sub_00468E00_Hotkey12()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(12);
        else
            sub_004AA030_SelectHotkey(12);
    }
}

// 0x00468E40
void __cdecl sub_00468E40_Hotkey13()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(13);
        else
            sub_004AA030_SelectHotkey(13);
    }
}

// 0x00468E80
void __cdecl sub_00468E80_Hotkey14()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(14);
        else
            sub_004AA030_SelectHotkey(14);
    }
}

// 0x00468EC0
void __cdecl sub_00468EC0_Hotkey15()
{
    if (!sub_0044DA30() && !sub_00463DF0() && sub_0044DCC0())
    {
        if (sub_004538D0(3))
            sub_004A9E60_AssignHotkey(15);
        else
            sub_004AA030_SelectHotkey(15);
    }
}

// 0x00468F80
void __cdecl sub_00468F80_Phrase19()
{
    sub_004785B0_SendPacket3(0x3F, 0x19);
}

// 0x00468F90
void __cdecl sub_00468F90_Phrase1A()
{
    sub_004785B0_SendPacket3(0x3F, 0x1A);
}

// 0x00468FA0
void __cdecl sub_00468FA0_Phrase1B()
{
    sub_004785B0_SendPacket3(0x3F, 0x1B);
}

// 0x00468FB0
void __cdecl sub_00468FB0_Phrase1C()
{
    sub_004785B0_SendPacket3(0x3F, 0x1C);
}

// 0x00468FC0
void __cdecl sub_00468FC0_Phrase1D()
{
    sub_004785B0_SendPacket3(0x3F, 0x1D);
}

// 0x00468FD0
void __cdecl sub_00468FD0_Phrase1E()
{
    sub_004785B0_SendPacket3(0x3F, 0x1E);
}

// 0x00468FE0
void __cdecl sub_00468FE0_Phrase1F()
{
    sub_004785B0_SendPacket3(0x3F, 0x1F);
}

// 0x00468FF0
void __cdecl sub_00468FF0_Phrase20()
{
    sub_004785B0_SendPacket3(0x3F, 0x20);
}

void (__cdecl* gpfnCallback_007A6B10)(); // 0x007A6B10

void (__cdecl* gpfnCallback_007A740C)(); // 0x007A740C

void (__cdecl* gpfnCallback_007A7414)(); // 0x007A7414

void (__cdecl* gpfnCallback_007A6B14)(); // 0x007A6B14

void (__cdecl* gpfnCallback_007A7410)(); // 0x007A7410

// 0x00468F00
void __cdecl sub_00468F00()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, BODYLOC_BELT);
        if (pItem && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BELT))
        {
            sub_00455F20(0x1F, 2, 0);
        }
    }
}

// 0x00469230
void __cdecl sub_00469230()
{
    if (gpfnCallback_007A6B10)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A6B10), 0x339);
        gpfnCallback_007A6B10();
    }
}

// 0x00469270
void __cdecl sub_00469270()
{
    if (gpfnCallback_007A740C)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A740C), 0x345);
        gpfnCallback_007A740C();
    }
}

// 0x004692B0
void __cdecl sub_004692B0()
{
    if (gpfnCallback_007A7414)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A7414), 0x350);
        gpfnCallback_007A7414();
    }
}

// 0x004692F0
void __cdecl sub_004692F0()
{
    if (gpfnCallback_007A6B14)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A6B14), 0x35D);
        gpfnCallback_007A6B14();
    }
}

// 0x00469330
void __cdecl sub_00469330()
{
    if (gpfnCallback_007A7410)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A7410), 0x369);
        gpfnCallback_007A7410();
    }
}

// 0x00469000
void __cdecl sub_00469000_HotkeyRunOn()
{
    sub_0044BE60_SetFlag(1);
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;
    if (pPlayer->dwUnitType != 0)
        return;
    if (pPlayer->dwAnimMode != 2)
        return;
    if (!STATLIST_UnitGetStatValue(pPlayer, 10, 0))
        return;
    sub_00480E70_SetUnitMode(pPlayer, 3);
    sub_00478590(0x53);
}

// 0x00469060
void __cdecl sub_00469060_ToggleAlwaysRun()
{
    sub_0044BE80(!sub_0044BE90());
}

// 0x00469080
void __cdecl sub_00469080_HotkeySetValue()
{
    sub_0044BEA0_SetValue(1);
}

// 0x00469090
void __cdecl sub_00469090_HotkeyUiVarOff()
{
    sub_00455F20(0xD, 0, 0);
}

// 0x004690B0
void __cdecl sub_004690B0_HotkeyEscape()
{
    if (sub_004B34A0())
        return;
    if (sub_004A0000())
        return;
    if (sub_004538D0(9))
    {
        sub_0047E200(1);
        return;
    }
    if (sub_00456300_CloseUIVars(0, 1))
        return;
    sub_0047E090(1, 0);
}

// 0x00469100
void __cdecl sub_00469100_HotkeyPrevSkill()
{
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;
    sub_004AA740_CycleHotkey(-1);
}

// 0x00469120
void __cdecl sub_00469120_HotkeyNextSkill()
{
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;
    sub_004AA740_CycleHotkey(1);
}

// 0x00469140
void __cdecl sub_00469140_HotkeyResetSounds()
{
    if (sub_004538D0(0xC))
        return;
    if (sub_004538D0(0x17))
        return;
    if (sub_004538D0(0x19))
        return;
    sub_0048A730_ResetEquipSounds();
}

// 0x00469170
void __cdecl sub_00469170_HotkeyPetUi()
{
    if (!sub_0044DCC0())
        return;
    if (sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0) == -1)
        return;
    if (!sub_00408F20_HasExpansionMpq())
        return;
    sub_00455F20(0x24, 2, 1);
}

// 0x004691C0
void __cdecl sub_004691C0_HotkeyRunOff()
{
    sub_0044BE60_SetFlag(0);
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    if (sub_0044BE90())
        return;
    if (pPlayer->dwUnitType != 0)
        return;
    if (pPlayer->dwAnimMode != 3)
        return;
    sub_00480E70_SetUnitMode(pPlayer, 2);
    sub_00478590(0x54);
}

// 0x00469210
void __cdecl sub_00469210_HotkeyUiVarOn()
{
    sub_00455F20(0xD, 1, 0);
    sub_00466FE0();
}
