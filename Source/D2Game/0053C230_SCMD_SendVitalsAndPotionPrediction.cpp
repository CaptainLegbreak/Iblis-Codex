struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
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

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90

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

// 0x0053C230
void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[15];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x18, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPotionLifePercent, 7);
    BITMANIP_Write(&bitBuffer, nPotionManaPercent, 7);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}

// 0x0053C320
void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[13];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x95, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}

// 0x0053C3F0
void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[9];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x96, 8);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}
