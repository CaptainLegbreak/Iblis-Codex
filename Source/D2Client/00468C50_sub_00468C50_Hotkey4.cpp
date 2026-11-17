int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey);                                                     // 0x004A9E60
void __fastcall sub_004AA030_SelectHotkey(int nSlot);                                                       // 0x004AA030
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0

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
