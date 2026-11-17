#pragma pack(push, 1)
struct D2GSPacketSrv42
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv47
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned int nUnitGUID;
    unsigned int unk0x07;
};

struct D2GSPacketSrv48
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned int nUnitGUID;
    unsigned int unk0x07;
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

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

// build: symbol ?D2GAME_PACKETS_SendPacket_6FC3C710@@YGXPBXHPAUD2ClientStrc@@@Z 0x0053B280
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

static inline int SCMD_GetUnitTypeOr6(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->dwUnitType;
}

// 0x0053D2E0
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv42 packet42 = {};

    packet42.nHeader = 0x42u;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet42.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet42.dwUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet42, sizeof(packet42), pClient);
}

// 0x0053D370
void __fastcall D2GAME_SendPacket0x47_6FC3EEE0(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv47 packet47 = {};

    packet47.nHeader = 0x47;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet47.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet47.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet47, sizeof(packet47), pClient);
}

// 0x0053D3C0
void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient, D2UnitStrc* pUnit, int a3)
{
    D2GSPacketSrv48 packet48 = {};

    packet48.unk0x02 = a3;
    packet48.nHeader = 0x48;
    packet48.nUnitType = SCMD_GetUnitTypeOr6(pUnit);
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet48.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet48, sizeof(packet48), pClient);
}
