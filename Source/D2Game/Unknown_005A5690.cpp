extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    int nUnitGUID;
    unsigned char nEvent;
    char szText[32];
};
#pragma pack(pop)
struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);
};
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850

// 0x005A5690
void D2ClientStrc::PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType)
{
    const unsigned char nEvent = *(unsigned char volatile*)&nType; // volatile only reproduces the original reading nType at entry, before the packet is cleared
    D2GSPacketSrv5A packet;
    memset(&packet, 0, sizeof(packet));
    packet.nUnitGUID = nUnitGUID;
    packet.nHeader = 0x5A;
    packet.nType = 7;
    packet.nColor = 3;
    packet.nEvent = nEvent;
    switch (nEvent)
    {
    case 1:
        packet.nColor = 4;
        break;
    case 2:
        packet.nColor = 4;
        break;
    case 3:
        packet.nColor = 8;
        break;
    case 4:
        packet.nColor = 0;
        break;
    case 5:
        packet.nColor = 2;
        break;
    case 6:
        packet.nColor = 9;
        break;
    case 7:
        packet.nColor = 2;
        break;
    case 8:
        packet.nColor = 2;
        break;
    case 9:
        packet.nColor = 9;
        break;
    case 10:
        packet.nColor = 9;
        break;
    case 11:
        packet.nColor = 9;
        break;
    }
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(this, &packet);
}
