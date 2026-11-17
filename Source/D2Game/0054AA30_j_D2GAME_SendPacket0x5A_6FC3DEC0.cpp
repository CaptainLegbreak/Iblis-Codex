struct D2ClientStrc;
struct D2GSPacketSrv5A;

void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket);   // 0x0053C850

// 0x0054AA30
void __fastcall j_D2GAME_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, void* pPacket)
{
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(pClient, (D2GSPacketSrv5A*)pPacket);
}
