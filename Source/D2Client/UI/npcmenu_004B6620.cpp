#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientMenus.h"

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __cdecl NPCMENU_TravelToKurastDocks();                                                                                 // 0x004B51A0
int __cdecl NPCMENU_TravelToHarrogath();                                                                                 // 0x004B5200

extern int (__cdecl* gpfnGlobal_00726C62)();                                                                // 0x00726C62
extern short gwGlobal_00726E9B;                                                                             // 0x00726E9B
extern int (__cdecl* gpfnGlobal_00726EA7)();                                                                // 0x00726EA7

// 0x004B6620
int __cdecl NPCMENU_InitTravelKurastDocksHandler()
{
    gnGlobal_00726E95 = 3;
    gpfnGlobal_00726EA7 = NPCMENU_TravelToKurastDocks;
    gwGlobal_00726E9B = 0xD38;
    return 1;
}

// 0x004B6680
int __cdecl NPCMENU_InitTravelHarrogathHandler()
{
    if (sub_0044DCC0())
    {
        gnGlobal_00726F7F = 3;
        gpfnGlobal_00726F91 = NPCMENU_TravelToHarrogath;
        gwGlobal_00726F85 = 0x58D2;
    }
    return 1;
}

