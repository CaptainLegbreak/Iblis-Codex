#pragma pack(push, 1)
struct D2UnitUpdateEntry { int nFirst; int nSecond; unsigned char nType; };
struct D2GSPacketSrv16 { unsigned char nHeader; unsigned short nSize; unsigned char nCount; D2UnitUpdateEntry entries[1]; };
#pragma pack(pop)
struct D2ClientStrc { unsigned char pad000[0x1CC]; D2UnitUpdateEntry entries[54]; unsigned char pad3B2[10]; int nCount; };
struct D2PacketDataStrc { int nSize; unsigned char data[1]; };
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc*); // 0x005392E0
// 0x0053E130
void __fastcall sub_0053E130_SendUnitUpdates(D2ClientStrc* pClient)
{
    int nCount = pClient->nCount;
    if (nCount)
    {
        D2PacketDataStrc* pData = CLIENTS_PacketDataList_GetHead(pClient);
        unsigned short nSize = (unsigned short)(sizeof(D2GSPacketSrv16) + sizeof(D2UnitUpdateEntry) * nCount);
        D2GSPacketSrv16* pPacket = (D2GSPacketSrv16*)(pData->data + pData->nSize);
        pPacket->nHeader = 0x16;
        pPacket->nCount = (unsigned char)nCount;
        pPacket->nSize = nSize;
        D2UnitUpdateEntry* pOut = pPacket->entries;
        for (int i = 0; i < nCount; ++i)
        {
            *pOut++ = pClient->entries[i];
        }
        pData->nSize += nSize;
    }
}
