struct D2ClientDialogStrc;

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);                    // 0x004786D0
extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25

// 0x004B5140
int __cdecl sub_004B5140_NpcMenuAction28()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B51A0
int __cdecl sub_004B51A0_NpcMenuAction4B()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x4B);
    return 1;
}

// 0x004B5200
int __cdecl sub_004B5200_NpcMenuAction6D()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x6D);
    return 1;
}

// 0x004B5260
int __cdecl sub_004B5260_NpcMenuAction28b()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B52C0
int __cdecl sub_004B52C0_NpcMenuAction01()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 1);
    return 1;
}
