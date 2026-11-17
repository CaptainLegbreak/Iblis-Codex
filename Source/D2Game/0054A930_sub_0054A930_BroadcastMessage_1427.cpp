struct D2GameStrc;
struct D2ClientStrc;
struct D2GSPacketSrv26 {
    unsigned char header, messageType, language, unitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor, nNameColor;
    char name[16];
    char message[256];
};
typedef void (__fastcall *ClientCallback)(D2ClientStrc*, void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __fastcall GAME_ForEachIngameClient(D2GameStrc*, ClientCallback, void*); // 0x0052DED0
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc*, void*); // 0x0054A5C0
// 0x0054A930
void __fastcall sub_0054A930_BroadcastMessage(D2GameStrc* game, const char* message, unsigned char color)
{
    D2GSPacketSrv26 packet;
    packet.header = 0x26;
    packet.messageType = 1;
    packet.unitType = 2;
    packet.dwUnitGUID = 0;
    packet.nMessageColor = color;
    packet.name[0] = 0;
    packet.language = 0;
    memcpy(packet.message, message, sizeof(packet.message));
    GAME_ForEachIngameClient(game, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0, &packet);
}
