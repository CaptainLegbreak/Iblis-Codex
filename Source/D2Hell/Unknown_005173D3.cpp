typedef void (__stdcall* B27RecordHandler)(int, int, int);
typedef int (__cdecl* B27UIAction)();
extern "C" int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0
extern "C" int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020
extern "C" unsigned int gB27_00726CC1;
extern "C" unsigned short gB27_00726CCB;
extern "C" unsigned int gB27_00726CDB;
extern "C" unsigned int gB27_00726DF9;
extern "C" unsigned short gB27_00726E01;
extern "C" unsigned int gB27_00726E0F;
extern "C" unsigned int gB27_00726E47;
extern "C" unsigned short gB27_00726E4F;
extern "C" unsigned int gB27_00726E5D;
extern "C" unsigned int gB27_00726E95;
extern "C" unsigned short gB27_00726E9D;
extern "C" unsigned int gB27_00726EAB;
extern "C" unsigned int gB27_00726EBC;
extern "C" unsigned short gB27_00726EC2;
extern "C" B27UIAction gB27_00726ECE;
extern "C" unsigned int gB27_00726EE3;
extern "C" unsigned short gB27_00726EE9;
extern "C" B27UIAction gB27_00726EF5;
extern "C" unsigned int gB27_00726F0A;
extern "C" unsigned short gB27_00726F10;
extern "C" B27UIAction gB27_00726F1C;
extern "C" unsigned int gB27_00726F31;
extern "C" unsigned short gB27_00726F37;
extern "C" B27UIAction gB27_00726F43;
extern "C" unsigned int gB27_00726F7F;
extern "C" unsigned short gB27_00726F85;
extern "C" unsigned short gB27_00726F87;
extern "C" unsigned int gB27_00726F91;
extern "C" unsigned int gB27_00726F95;
extern "C" unsigned int gB27_00727216;
extern "C" unsigned short gB27_0072721C;
extern "C" B27UIAction gB27_00727228;
extern "C" unsigned int gB27_0072723D;
extern "C" unsigned short gB27_00727247;
extern "C" unsigned int gB27_00727257;
extern "C" unsigned int gB27_0072728B;
extern "C" unsigned short gB27_00727297;
extern "C" unsigned int gB27_007272A9;
extern "C" unsigned int gB27_007272D9;
extern "C" unsigned short gB27_007272E1;
extern "C" B27UIAction gB27_007272EB;
extern "C" unsigned int gB27_007272EF;
extern "C" int gB27_007BCBF0;
extern "C" int gB27_007BF298;
extern "C" unsigned char gB27_007C025F;
extern "C" unsigned int gB27_007C0265;
extern "C" { B27RecordHandler gpfnRecordHandler; } // 0x00881834
extern "C" unsigned int gB27_00883D70;

// build: symbol _CUNIT_IsInvPanelTradeMode 0x00489840
extern "C" int __cdecl CUNIT_IsInvPanelTradeMode()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

extern "C" void __cdecl TEXT_ResetQuestButtonState(); // 0x004A3000

extern "C" void __fastcall TEXT_SetQuestPacketValue(unsigned int value); // 0x004A3100

// build: symbol _NPCMENU_ResetHandlers 0x004B2250
extern "C" void __cdecl NPCMENU_ResetHandlers()
{
    bool oldAction = (gB27_007272EB == NPCMENU_ResurrectMercWait);
    gB27_00726DF9 = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gB27_00726E47 = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gB27_00726E95 = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gB27_00726CC1 = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gB27_007272D9 = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gB27_007272D9 = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gB27_00726F7F = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gB27_00726F85 = 0;
    gB27_00726F91 = 0;
    gB27_0072723D = 3;
    gB27_0072728B = 4;
    gB27_00726EC2 = 0xfb4;
    gB27_00726ECE = NPCMENU_IdentifyItemsWait;
    gB27_00726EBC = 3;
    gB27_00726EE9 = 0xfb4;
    gB27_00726EF5 = NPCMENU_IdentifyItemsWait;
    gB27_00726EE3 = 3;
    gB27_00726F10 = 0xfb4;
    gB27_00726F1C = NPCMENU_IdentifyItemsWait;
    gB27_00726F0A = 3;
    gB27_00726F37 = 0xfb4;
    gB27_00726F43 = NPCMENU_IdentifyItemsWait;
    gB27_00726F31 = 3;
    gB27_0072721C = 0xfb4;
    gB27_00727228 = NPCMENU_IdentifyItemsWait;
    gB27_00727216 = 3;
}

// 0x005173D3
extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler)
{
    B27RecordHandler previous = gpfnRecordHandler;
    gpfnRecordHandler = handler;
    return previous;
}

// build: symbol @PLAYER_SetVirtualPlayerCount@* 0x00535780
extern "C" void __fastcall PLAYER_SetVirtualPlayerCount(unsigned int count)
{
    if (count <= 8)
        gB27_00883D70 = count;
}
