int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);                  // 0x0052B330

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
    sub_0052B330(0, 0, &packetAF, sizeof(packetAF));
}
