int __cdecl sub_004B1DD0_OpenTimedDialog62();                                                               // 0x004B1DD0
int __cdecl sub_004B2020_OpenTimedDialog34();                                                               // 0x004B2020
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);                    // 0x004786D0

extern int gnGlobal_00726DF9;                                                                               // 0x00726DF9
extern short gwGlobal_00726E01;                                                                             // 0x00726E01
extern int gnGlobal_00726E0F;                                                                               // 0x00726E0F
extern int gnGlobal_00726E47;                                                                               // 0x00726E47
extern short gwGlobal_00726E4F;                                                                             // 0x00726E4F
extern int gnGlobal_00726E5D;                                                                               // 0x00726E5D
extern int gnGlobal_00726E95;                                                                               // 0x00726E95
extern short gwGlobal_00726E9D;                                                                             // 0x00726E9D
extern int gnGlobal_00726EAB;                                                                               // 0x00726EAB
extern int gnGlobal_00726CC1;                                                                               // 0x00726CC1
extern short gwGlobal_00726CCB;                                                                             // 0x00726CCB
extern int gnGlobal_00726CDB;                                                                               // 0x00726CDB
extern int gnGlobal_007272D9;                                                                               // 0x007272D9
extern short gwGlobal_007272E1;                                                                             // 0x007272E1
extern int gnGlobal_007272EF;                                                                               // 0x007272EF
extern int (__cdecl* gpfnGlobal_007272EB)();                                                                // 0x007272EB
extern short gwGlobal_00727247;                                                                             // 0x00727247
extern int gnGlobal_00727257;                                                                               // 0x00727257
extern short gwGlobal_00727297;                                                                             // 0x00727297
extern int gnGlobal_007272A9;                                                                               // 0x007272A9
extern int gnGlobal_00726F7F;                                                                               // 0x00726F7F
extern short gwGlobal_00726F87;                                                                             // 0x00726F87
extern int gnGlobal_00726F95;                                                                               // 0x00726F95
extern short gwGlobal_00726F85;                                                                             // 0x00726F85
extern int (__cdecl* gpfnGlobal_00726F91)();                                                                // 0x00726F91
extern int gnGlobal_0072723D;                                                                               // 0x0072723D
extern int gnGlobal_0072728B;                                                                               // 0x0072728B
extern short gwGlobal_00726EC2;                                                                             // 0x00726EC2
extern int (__cdecl* gpfnGlobal_00726ECE)();                                                                // 0x00726ECE
extern int gnGlobal_00726EBC;                                                                               // 0x00726EBC
extern short gwGlobal_00726EE9;                                                                             // 0x00726EE9
extern int (__cdecl* gpfnGlobal_00726EF5)();                                                                // 0x00726EF5
extern int gnGlobal_00726EE3;                                                                               // 0x00726EE3
extern short gwGlobal_00726F10;                                                                             // 0x00726F10
extern int (__cdecl* gpfnGlobal_00726F1C)();                                                                // 0x00726F1C
extern int gnGlobal_00726F0A;                                                                               // 0x00726F0A
extern short gwGlobal_00726F37;                                                                             // 0x00726F37
extern int (__cdecl* gpfnGlobal_00726F43)();                                                                // 0x00726F43
extern int gnGlobal_00726F31;                                                                               // 0x00726F31
extern short gwGlobal_0072721C;                                                                             // 0x0072721C
extern int (__cdecl* gpfnGlobal_00727228)();                                                                // 0x00727228
extern int gnGlobal_00727216;                                                                               // 0x00727216
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D96;                                                                               // 0x007C0D96

// 0x004B2250
void __cdecl sub_004B2250_ResetHandlers()
{
    gnGlobal_00726DF9 = 2; gwGlobal_00726E01 = 0; gnGlobal_00726E0F = 0;
    gnGlobal_00726E47 = 2; gwGlobal_00726E4F = 0; gnGlobal_00726E5D = 0;
    gnGlobal_00726E95 = 2; gwGlobal_00726E9D = 0; gnGlobal_00726EAB = 0;
    gnGlobal_00726CC1 = 3; gwGlobal_00726CCB = 0; gnGlobal_00726CDB = 0;
    gnGlobal_007272D9 = 2; gwGlobal_007272E1 = 0; gnGlobal_007272EF = 0;
    if (gpfnGlobal_007272EB == sub_004B1DD0_OpenTimedDialog62)
    {
        gnGlobal_007272D9 = 3;
    }
    gwGlobal_00727247 = 0; gnGlobal_00727257 = 0;
    gwGlobal_00727297 = 0; gnGlobal_007272A9 = 0;
    gnGlobal_00726F7F = 2; gwGlobal_00726F87 = 0; gnGlobal_00726F95 = 0;
    gwGlobal_00726F85 = 0; gpfnGlobal_00726F91 = 0;
    gnGlobal_0072723D = 3;
    gnGlobal_0072728B = 4;
    gwGlobal_00726EC2 = 0xFB4; gpfnGlobal_00726ECE = sub_004B2020_OpenTimedDialog34; gnGlobal_00726EBC = 3;
    gwGlobal_00726EE9 = 0xFB4; gpfnGlobal_00726EF5 = sub_004B2020_OpenTimedDialog34; gnGlobal_00726EE3 = 3;
    gwGlobal_00726F10 = 0xFB4; gpfnGlobal_00726F1C = sub_004B2020_OpenTimedDialog34; gnGlobal_00726F0A = 3;
    gwGlobal_00726F37 = 0xFB4; gpfnGlobal_00726F43 = sub_004B2020_OpenTimedDialog34; gnGlobal_00726F31 = 3;
    gwGlobal_0072721C = 0xFB4; gpfnGlobal_00727228 = sub_004B2020_OpenTimedDialog34; gnGlobal_00727216 = 3;
}

// 0x004B2370
void __fastcall sub_004B2370_SendPacket38(int nArg)
{
    gnGlobal_007C0D96 = 0;
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, nArg);
}

#include "gen/data/Source/D2Client/004B2250_sub_004B2250_ResetHandlers.inc"
