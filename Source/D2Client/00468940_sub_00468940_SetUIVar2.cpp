void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_004A3FE0(int nMode);                                                                    // 0x004A3FE0
void __fastcall sub_00457640(int bForce);                                                                   // 0x00457640
int __cdecl sub_004576C0();                                                                                 // 0x004576C0
void __fastcall sub_004576F0(int nFade);                                                                    // 0x004576F0
int __cdecl sub_004577B0();                                                                                 // 0x004577B0
int __fastcall sub_004577C0_SetValue(int nValue);                                                           // 0x004577C0
int __cdecl sub_004577E0();                                                                                 // 0x004577E0
int __fastcall sub_004577F0_SetValue(int nValue);                                                           // 0x004577F0
int __cdecl sub_00457770();                                                                                 // 0x00457770
int __fastcall sub_00457780_SetValue(int nValue);                                                           // 0x00457780
void __fastcall sub_004A8CE0_SetValue(int nValue);                                                          // 0x004A8CE0
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey);                                                     // 0x004A9E60
void __fastcall sub_004AA030_SelectHotkey(int nSlot);                                                       // 0x004AA030

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
