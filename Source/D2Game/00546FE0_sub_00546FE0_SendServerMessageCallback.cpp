struct D2ClientStrc;
struct D2GSPacketSrv26;

void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750

// 0x00546FE0
void __fastcall sub_00546FE0_SendServerMessageCallback(D2ClientStrc* pClient, void* pContext)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, *(D2GSPacketSrv26**)pContext);
}
