#include "D2Structs.h"
#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    int nUnitId;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};

struct D2UnitStatPacketStrc
{
    unsigned char nHeader;
    unsigned char nStat;
    int nUnitId;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
    };
};

struct D2PlayerStatPacketStrc
{
    unsigned char nHeader;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
        struct
        {
            unsigned char nStat;
            union
            {
                unsigned char nByte2;
                unsigned short nWord2;
                unsigned int nDword2;
            };
        };
    };
};

struct D2UnitStatPacket2Strc
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nStat;
    int nValue;
};
#pragma pack(pop)


void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg);                                      // 0x004C1BC0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                        // 0x00480E70
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);                                                            // 0x004647D0
void __fastcall sub_0045D3E0_RefreshItemStats(D2UnitStrc* pUnit);                                                            // 0x0045D3E0
void __fastcall sub_004C1C10(D2UnitStrc* pUnit);                                                            // 0x004C1C10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

static void sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit); // 0x0045D3B0
static void __declspec(noinline) sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit);

static void sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2PacketRecord11Strc tPacket;
        tPacket.nHeader = 0x47;
        tPacket.nUnitType = (unsigned char)pUnit->dwUnitType;
        tPacket.nUnitId = pUnit->dwUnitId;
        sub_004C1BC0(&tPacket, 0);
    }
}

// 0x0045D540
void __fastcall sub_0045D540_HandleUnitStatPacket(D2UnitStatPacketStrc* pPacket)
{
    int bAdd = 0;
    int nValue;
    int nStat;
    switch (pPacket->nHeader)
    {
    case 0x9E:
        nValue = pPacket->nByte;
        nStat = pPacket->nStat;
        break;
    case 0xA0:
        nValue = pPacket->nDword;
        nStat = pPacket->nStat;
        break;
    case 0xA1:
        nValue = pPacket->nByte;
        bAdd = 1;
        nStat = pPacket->nStat;
        break;
    case 0xA2:
        bAdd = 1;

    case 0x9F:
        nValue = pPacket->nWord;
        nStat = pPacket->nStat;
        break;
    default:
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 1);
    if (pUnit)
    {
        if (nStat == 0xC)
            sub_0045D3B0_SendUnitStatus(pUnit);

        if (bAdd)
            STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
        else
            STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
    }
}
