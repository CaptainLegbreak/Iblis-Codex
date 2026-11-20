#include "D2Client.h"

#pragma pack(push, 1)
struct D2GSPacketSrv2A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned int unk0x03;
    unsigned int unk0x07;
    unsigned int unk0x0B;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13;
    char bFlag14;
    char bRefreshed;
};
#pragma pack(pop)

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                       // 0x00455F20
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __cdecl sub_004B1D70_FindNpcEntry();                                                                    // 0x004B1D70
void __stdcall sub_004B5890_OpenNpcPanel(int nStringIndex, int nEntryIndex);                               // 0x004B5890
void __stdcall sub_004B5AD0_OpenConfirmDialog(int nStringIndex);                                            // 0x004B5AD0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __cdecl sub_004B53F0();                                                                                // 0x004B53F0
void __cdecl sub_004B5640_OpenNpcMenu();                                                                                // 0x004B5640
int __cdecl sub_004B51A0_NpcMenuAction4B();                                                                                 // 0x004B51A0
int __cdecl sub_004B5200_NpcMenuAction6D();                                                                                 // 0x004B5200
int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60
int __cdecl sub_004B6D10_OpenConfirm();

extern D2GSPacketSrv2A gPacket2A_007C0D87;                                                                  // 0x007C0D87
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850
extern int gnGlobal_00726C4C;                                                                               // 0x00726C4C
extern short gwGlobal_00726C54;                                                                             // 0x00726C54
extern int (__cdecl* gpfnGlobal_00726C62)();                                                                // 0x00726C62
extern short gwGlobal_00726E9B;                                                                             // 0x00726E9B
extern int (__cdecl* gpfnGlobal_00726EA7)();                                                                // 0x00726EA7
extern short gwGlobal_007272DF;                                                                             // 0x007272DF

// 0x004B6390
void __fastcall sub_004B6390_HandleNpcTransaction(D2GSPacketSrv2A* pPacket)
{
    gPacket2A_007C0D87 = *pPacket;
    gnGlobal_007C0C73 = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), 0xE, 0);
    if (gnGlobal_007C0C6B == 5)
    {
        sub_004B53F0();
        return;
    }
    if (gnGlobal_007C0C6B == 10)
    {
        sub_004B5640_OpenNpcMenu();
        return;
    }
    if (pPacket->unk0x02 == 1)
        sub_004B9A00(0xDD, 0, 0, 0, 0);
}

// 0x004B6620
int __cdecl sub_004B6620_InitHandler()
{
    gnGlobal_00726E95 = 3;
    gpfnGlobal_00726EA7 = sub_004B51A0_NpcMenuAction4B;
    gwGlobal_00726E9B = 0xD38;
    return 1;
}

// 0x004B6650
int __cdecl sub_004B6650_InitHandler()
{
    gnGlobal_007272D9 = 3;
    gpfnGlobal_007272EB = sub_004B5C60_Handler;
    gwGlobal_007272DF = 0xD45;
    return 1;
}

// 0x004B6680
int __cdecl sub_004B6680_InitHandler()
{
    if (sub_0044DCC0())
    {
        gnGlobal_00726F7F = 3;
        gpfnGlobal_00726F91 = sub_004B5200_NpcMenuAction6D;
        gwGlobal_00726F85 = 0x58D2;
    }
    return 1;
}

// 0x004B6C70
int __cdecl sub_004B6C70_OpenNpcMenu()
{
    if (!NPC_GET_INTERACT_UNIT())
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 0;
    }

    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    gnGlobal_007C0C6B = 1;
    int nEntry = sub_004B1D70_FindNpcEntry();
    gpNpcEntry_007C0C7D = &gaNpcEntries_00726850[nEntry];
    sub_004B5890_OpenNpcPanel(0xD35, nEntry);
    return 1;
}

// 0x004B6D10
int __cdecl sub_004B6D10_OpenConfirm()
{
    if (!NPC_GET_INTERACT_UNIT())
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 0;
    }

    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    gnGlobal_007C0C6B = 1;
    sub_004B1D70_FindNpcEntry();
    sub_004B5AD0_OpenConfirmDialog(0x2BA0);
    return 1;
}

// 0x004B6DA0
int __cdecl sub_004B6DA0_InitHandler()
{
    gnGlobal_00726C4C = 4;
    gpfnGlobal_00726C62 = sub_004B6D10_OpenConfirm;
    gwGlobal_00726C54 = 0x2BA0;
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004B6390.inc"
