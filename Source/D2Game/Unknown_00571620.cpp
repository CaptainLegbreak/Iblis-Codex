#include "D2Game.h"

#define UNIT_INVALID 6
struct D2GSPacketSrv26;
struct D2GSPacketSrv2C;
struct D2UnitPacketListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0x5E];
    unsigned short nUpdateType;
    D2UnitStrc* pUpdateUnit;
    unsigned char unk_74[0x30];
    D2HoverTextStrc* pHoverText;
    unsigned char unk_A8[0x44];
    D2UnitPacketListStrc* pMsgFirst;
    D2UnitPacketListStrc* pMsgLast;
};

#pragma pack(push, 1)
struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nChatType;
    unsigned char nLanguage;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[16];
    char szMessage[256];
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc*, D2UnitStrc*, int); // 0x0055B300
unsigned char __stdcall sub_00661220_GetHoverLocale(D2HoverTextStrc*); // 0x00661220
void __stdcall sub_006611E0_CopyHoverText(D2HoverTextStrc*, char*); // 0x006611E0
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc*, D2GSPacketSrv26*); // 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nSoundEvent;
};

#pragma pack(pop)

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket); // 0x0053D780

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

// 0x00571620
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (pUnit && pUnit->pHoverText)
    {
        D2HoverTextStrc* pHoverText = pUnit->pHoverText;
        CLIENTS_GetGame(pClient);
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pPlayer && pUnit->dwUnitType == 0)
        {
            if (PLAYERLIST_CheckFlag(pPlayer, pUnit, 4) || PLAYERLIST_CheckFlag(pUnit, pPlayer, 2))
                return;
        }
        D2GSPacketSrv26 packet;
        packet.nUnitGUID = pUnit ? pUnit->dwUnitId : -1;
        const int nType = pUnit ? pUnit->dwUnitType : 6;
        packet.nHeader = 0x26;
        packet.nUnitType = nType;
        packet.szName[0] = 0;
        packet.nChatType = 5;
        packet.nLanguage = sub_00661220_GetHoverLocale(pHoverText);
        memset(packet.szMessage, 0, 256);
        sub_006611E0_CopyHoverText(pHoverText, packet.szMessage);
        D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, &packet);
    }
    else
    {
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(pClient, 0x76, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    }
}

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }

    return UNIT_INVALID;
}

// 0x00571740
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pUpdateUnit = pUnit->pUpdateUnit;
    if (!pUpdateUnit || CLIENTS_GetPlayerFromClient(pClient, 0) == pUpdateUnit)
    {
        D2GSPacketSrv2C packet2C;
        packet2C.nHeader = 0x2C;
        packet2C.dwUnitGUID = pUnit->dwUnitId;
        packet2C.nUnitType = UNITS_GetUnitTypeInline(pUnit);
        packet2C.nSoundEvent = pUnit->nUpdateType;
        SCMD_SendPacket0x2C(pClient, &packet2C);
    }
}

// 0x00571790
static __forceinline void sub_00571790_AppendUnitMessage(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

void __fastcall sub_M120_Emit_00571790(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    sub_00571790_AppendUnitMessage(pUnit, pMsg);
}
