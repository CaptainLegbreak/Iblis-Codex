extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PacketDataStrc
{
    int nPacketSize;
    unsigned char packetData[0x200];
    D2PacketDataStrc* pNext;
};

struct D2ClientStrc
{
    char unk0x000[0x1B8];
    D2PacketDataStrc* pPacketDataHead;
    D2PacketDataStrc* pPacketDataTail;
    D2PacketDataStrc* pPacketDataPool;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    int nSize = 0;
    if (!pClient)
    {
        return;
    }

    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetTail(pClient);
    if (pPacketData)
    {
        nSize = pPacketData->nPacketSize;
    }

    if (nPacketSize + nSize > 0x200 || !pPacketData)
    {
        pPacketData = pClient->pPacketDataPool;
        nSize = 0;
        if (pPacketData)
        {
            pClient->pPacketDataPool = pPacketData->pNext;
        }
        else
        {
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), ".\\GAME\\SCmd.cpp", 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

#pragma pack(push, 1)
struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    int unk0x06;
    unsigned char unk0x0A;
    unsigned short unk0x0B;
    unsigned short unk0x0D;
    unsigned short unk0x0F;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};

struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};
#pragma pack(pop)

// 0x0053D4D0
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9)
{
    D2GSPacketSrv4D packet;

    packet.nHeader = a9 != 0 ? 0x9Au : 0x4Du;
    packet.unk0x01 = a2;
    packet.unk0x02 = a3;
    packet.unk0x0B = a4;
    packet.unk0x0D = a5;
    packet.unk0x06 = a6;
    packet.unk0x0A = a8;
    packet.unk0x0F = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, sizeof(packet));
}

// 0x0053DDF0
void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 0xBAE), pPacket, sizeof(D2GSPacketSrv8C));
}

// 0x0053DE50
void __fastcall D2GAME_PACKETS_SendPacket0x8C_6FC3F8B0(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState)
{
    D2GSPacketSrv8C packet8C;

    packet8C.nHeader = 0x8C;
    packet8C.dwPlayerGUID1 = dwPlayerId1;
    packet8C.dwPlayerGUID2 = dwPlayerId2;
    packet8C.nFlags = wRelationState;

    D2GAME_PACKETS_SendPacket_6FC3C710(SUNIT_GetClientFromPlayer(pUnit, ".\\GAME\\SCmd.cpp", 0xBD0), &packet8C, sizeof(packet8C));
}

// 0x0053DE90
void __fastcall sub_6FC3F930(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 0xBD8), pPacket, sizeof(D2GSPacketSrv8D));
}

// 0x0053DEC0
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    SUNIT_IterateLivingPlayers(pGame, sub_6FC3F930, &packet8D);
}

// 0x0053DF00
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(SUNIT_GetClientFromPlayer(pUnit, ".\\GAME\\SCmd.cpp", 0xBF6), &packet8D, sizeof(packet8D));
}

// 0x0053DF50
void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 0xBFF), pPacket, 0xA);
}
