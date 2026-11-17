struct D2GSPacketSrv77;
struct D2GSPacketSrv89;
struct D2GSPacketSrv8F;

void __fastcall sub_004B8CF0(const D2GSPacketSrv77* pPacket);                                  // 0x004B8CF0
void __fastcall sub_004B9330_UniqueEvent(const D2GSPacketSrv89* pPacket);                                  // 0x004B9330
void __fastcall sub_0044CDB0_StorePong(const D2GSPacketSrv8F* pPacket);                                    // 0x0044CDB0

// 0x0045E800
void __fastcall sub_0045E800_Packet77(const D2GSPacketSrv77* pPacket)
{
    sub_004B8CF0(pPacket);
}

// 0x0045EA30
void __fastcall sub_0045EA30_Packet89(const D2GSPacketSrv89* pPacket)
{
    sub_004B9330_UniqueEvent(pPacket);
}

// 0x0045EB00
void __fastcall sub_0045EB00_Packet8F(const D2GSPacketSrv8F* pPacket)
{
    sub_0044CDB0_StorePong(pPacket);
}
