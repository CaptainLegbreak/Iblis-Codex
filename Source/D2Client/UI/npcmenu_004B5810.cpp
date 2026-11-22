#include "D2Client.h"
#include "D2ClientMenus.h"

void __fastcall sub_004B8020(void* pRes); // 0x004B8020
void __cdecl sub_004B4830_Rebuild(); // 0x004B4830
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern char gbGlobal_007C0C69; // 0x007C0C69

void __cdecl sub_004B5140(); // 0x004B5140
extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59
extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

// 0x004B5810
int __cdecl sub_004B5810()
{
    if (gbGlobal_007C0C69)
    {
        return 0;
    }

    if (gpDialog_007C0D6F)
    {
        sub_004B8020(gpDialog_007C0D6F);
        sub_004B9A00(1, 0, 0, 0, 0);
        gpDialog_007C0D6F = 0;
        sub_004B4830_Rebuild();
    }

    return 1;
}

// 0x004B65F0
int __cdecl sub_004B65F0_Initialize()
{
    gnGlobal_00726E47 = 3;
    gpfnCallback_00726E59 = sub_004B5140;
    gwGlobal_00726E4D = 0xD36;
    return 1;
}

