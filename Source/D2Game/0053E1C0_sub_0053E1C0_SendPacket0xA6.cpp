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

struct D2GSPacketSrvA6
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned short nPacketSize;
    short wArg;
    unsigned char data[0x1000];
};

#pragma pack(push, 1)
struct D2GSPacketSrvAE
{
    unsigned char nHeader;
    unsigned short nSize;
    unsigned char data[0x1FD];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

// 0x0053E1C0
void __fastcall sub_0053E1C0_SendPacket0xA6(D2ClientStrc* pClient, unsigned char nType, short wArg, int nSize, const void* pData)
{
    D2GSPacketSrvA6 packet;
    packet.nHeader = 0xA6;
    packet.nType = nType;
    packet.wArg = wArg;
    const int nPacketSize = nSize + 6;
    D2_ASSERT(nPacketSize < 0xFFFF, 0xD0D);
    packet.nPacketSize = nPacketSize;
    memcpy(packet.data, pData, nSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, nPacketSize, pClient);
}

// 0x0053E840
int __fastcall sub_0053E840_SendPacket0xAE(D2ClientStrc* pClient, const void* pData, unsigned int nSize)
{
    D2GSPacketSrvAE packet;
    if (nSize <= 0x1FD)
    {
        packet.nHeader = 0xAE;
        packet.nSize = nSize;
        memcpy(packet.data, pData, nSize);
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet, nSize + 3, pClient);
        return 1;
    }
    D2_ASSERT(nSize <= 0x1FD, 0xE38);
}
