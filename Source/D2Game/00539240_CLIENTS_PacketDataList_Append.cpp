struct D2PacketDataStrc
{
    char unk0x000[0x204];
    D2PacketDataStrc* pNext;
};

struct D2ClientStrc
{
    char unk0x000[0x1B8];
    D2PacketDataStrc* pPacketDataHead;
    D2PacketDataStrc* pPacketDataTail;
};

// 0x00539240
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData)
{
    pPacketData->pNext = 0;

    if (!pClient->pPacketDataTail)
    {
        pClient->pPacketDataHead = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
    else
    {
        pClient->pPacketDataTail->pNext = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
}

// 0x00539270
void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pSinglePacketData)
{
    pSinglePacketData->pNext = 0;

    if (!pClient->pPacketDataHead)
    {
        pSinglePacketData->pNext = 0;
        pClient->pPacketDataHead = pSinglePacketData;
    }
    else
    {
        pClient->pPacketDataTail = pSinglePacketData;
        pClient->pPacketDataHead = pSinglePacketData;
    }
}
