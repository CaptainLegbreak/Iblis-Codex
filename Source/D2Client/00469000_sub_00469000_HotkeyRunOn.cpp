struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_0044BE60_SetFlag(int nValue);                                                           // 0x0044BE60
int __cdecl sub_0044BE90();                                                                                 // 0x0044BE90
void __fastcall sub_0044BE80(int bAlwaysRun);                                                               // 0x0044BE80
void __fastcall sub_0044BEA0_SetValue(int nValue);                                                          // 0x0044BEA0
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode);                                     // 0x00480E70
void __fastcall sub_00478590(char nValue);                                                                  // 0x00478590
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_004B34A0();                                                                                 // 0x004B34A0
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
void __fastcall sub_0047E200(int nArg);                                                                     // 0x0047E200
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2);                                              // 0x00456300
void __fastcall sub_0047E090(int bSaveState, int nMenu);                                                // 0x0047E090
void __fastcall sub_004AA740_CycleHotkey(int nDelta);                                                       // 0x004AA740
void __cdecl sub_0048A730_ResetEquipSounds();                                                               // 0x0048A730
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0

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
