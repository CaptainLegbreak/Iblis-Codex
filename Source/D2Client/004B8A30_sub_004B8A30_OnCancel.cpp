struct D2ClientDialogStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

extern D2ClientDialogStrc* gpDialog_007C0E64;                                                               // 0x007C0E64
extern D2ClientDialogStrc* gpDialog_007C0E6C;                                                               // 0x007C0E6C
unsigned long gdwTick_007C0E70;                                                                             // 0x007C0E70
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C

// 0x004B8A30
int __cdecl sub_004B8A30_OnCancel()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E64);
    gpDialog_007C0E64 = 0;
    gnGlobal_007C0E7C = 3;
    sub_00478600_SendShorts(0x4F, 3, 0, 0);
    return 1;
}

// 0x004B8A80
int __cdecl sub_004B8A80_OnClose()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E64);
    gpDialog_007C0E64 = 0;
    gnGlobal_007C0E7C = 7;
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    gdwTick_007C0E70 = GetTickCount();
    return 1;
}

// 0x004B8BA0
int __cdecl sub_004B8BA0_OnClose2()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E6C);
    gpDialog_007C0E6C = 0;
    gnGlobal_007C0E7C = 7;
    gdwTick_007C0E70 = GetTickCount();
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    return 1;
}
