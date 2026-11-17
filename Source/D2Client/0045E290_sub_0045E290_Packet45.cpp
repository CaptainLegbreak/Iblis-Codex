struct D2GSPacketSrv45;
struct D2GSPacketSrv4F;
struct D2GSPacketSrv54;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv66;

void __cdecl sub_00473CA0_Empty();                                                                          // 0x00473CA0
void __cdecl sub_004B3290_ResetSlots();                                                                     // 0x004B3290
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket);                               // 0x004B92B0

// 0x0045E290
void __fastcall sub_0045E290_Packet45(const D2GSPacketSrv45* pPacket)
{
}

// 0x0045E3B0
void __fastcall sub_0045E3B0_Packet54(const D2GSPacketSrv54* pPacket)
{
    sub_00473CA0_Empty();
}

// 0x0045E3C0
void __fastcall sub_0045E3C0_Packet4F(const D2GSPacketSrv4F* pPacket)
{
    sub_004B3290_ResetSlots();
}

// 0x0045E570
void __fastcall sub_0045E570_Packet5E(const D2GSPacketSrv5E* pPacket)
{
    sub_004B92B0_StorePacketText(pPacket);
}

// 0x0045E6C0
void __fastcall sub_0045E6C0_Packet66(const D2GSPacketSrv66* pPacket)
{
}
