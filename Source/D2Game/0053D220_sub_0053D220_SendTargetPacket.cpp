#pragma pack(push, 1)
struct D2PacketHeaderOnlyStrc
{
    unsigned char nHeader;
};

struct D2PacketSize06Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2PacketSize05Strc
{
    unsigned char nHeader;
    int nValue;
};
#pragma pack(pop)

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

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient)
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

// 0x0053B320
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader)
{
    D2PacketHeaderOnlyStrc tPacket;
    tPacket.nHeader = nHeader;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId)
{
    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = dwUnitType;
    tPacket.nUnitGUID = dwUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B400
void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue)
{
    D2PacketSize05Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};
#pragma pack(push, 1)
struct D2PacketTarget3FStrc
{
    unsigned char nHeader;
    unsigned char nType;
    int nUnitGUID;
    unsigned short nValue;
};
#pragma pack(pop)

// 0x0053D220
void __fastcall sub_0053D220_SendTargetPacket(D2ClientStrc* pClient, D2UnitStrc* pUnit,
    unsigned char nType, int bClear, int nUnused, unsigned short nValue)
{
    D2PacketTarget3FStrc packet = {};
    packet.nHeader = 0x3F;
    if (bClear)
    {
        if (!pUnit)
        {
            packet.nType = 0xFF;
            packet.nUnitGUID = 0;
            goto send;
        }
        packet.nType = 0xFF;
    }
    else
    {
        packet.nType = nType;
        if (!pUnit)
            goto send;
    }
    packet.nUnitGUID = pUnit->dwUnitId;
send:
    packet.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, sizeof(packet), pClient);
}
