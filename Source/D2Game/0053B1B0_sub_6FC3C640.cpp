#pragma pack(push, 1)
struct D2GSPacketSrvB1
{
    unsigned char nHeader;
    char szGameName[48];
    unsigned short nClientCount;
    unsigned short nGameId;
};
#pragma pack(pop)

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);                  // 0x0052B330

// 0x0053B1B0
int __fastcall sub_6FC3C640(int nClientId, short nGameId, short nClientCount, const char* szGameName)
{
    D2GSPacketSrvB1 packetB1;

    packetB1.nHeader = 0xB2;
    packetB1.nGameId = nGameId;
    packetB1.nClientCount = nClientCount;

    SStrCopy(packetB1.szGameName, szGameName, 0x10);

    return sub_0052B330(0, nClientId, &packetB1, sizeof(packetB1));
}
