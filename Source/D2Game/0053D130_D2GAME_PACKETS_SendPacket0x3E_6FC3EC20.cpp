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

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GSPacketSrv3E
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned char pBuffer[32];
};

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90
void __fastcall sub_0053B0E0_WriteVarLength(D2BitBufferStrc* pBuffer, unsigned int nValue);                 // 0x0053B0E0

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

// 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6)
{
    D2BitBufferStrc tBitBuffer;
    D2GSPacketSrv3E tPacket = {};

    tPacket.nHeader = 0x3E;
    BITMANIP_Initialize(&tBitBuffer, tPacket.pBuffer, sizeof(tPacket.pBuffer));
    sub_0053B0E0_WriteVarLength(&tBitBuffer, !pItem ? -1 : pItem->dwUnitId);
    BITMANIP_Write(&tBitBuffer, a3 != 0, 1);
    BITMANIP_Write(&tBitBuffer, nStatId, 9);
    sub_0053B0E0_WriteVarLength(&tBitBuffer, nValue);
    if (a6 < 0x100)
    {
        BITMANIP_Write(&tBitBuffer, 0, 1);
        BITMANIP_Write(&tBitBuffer, a6, 8);
    }
    else
    {
        BITMANIP_Write(&tBitBuffer, 1, 1);
        BITMANIP_Write(&tBitBuffer, a6, 16);
    }
    tPacket.nSize = BITMANIP_GetSize(&tBitBuffer) + 2;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}
