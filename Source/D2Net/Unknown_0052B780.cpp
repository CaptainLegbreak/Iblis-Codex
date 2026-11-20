unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize); // 0x0052B330

struct D2GSPacketSrvAFStrc
{
    unsigned char nHeader;
    unsigned char nCompression;
};

// 0x0052B780
void __fastcall sub_0052B780()
{
    D2GSPacketSrvAFStrc packetAF;
    packetAF.nHeader = 0xAF;
    packetAF.nCompression = 0;
    SERVER_SendPacketToClient(0, 0, &packetAF, sizeof(packetAF));
}
