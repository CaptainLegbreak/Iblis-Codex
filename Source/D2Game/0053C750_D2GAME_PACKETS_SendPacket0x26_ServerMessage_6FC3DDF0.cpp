struct D2PacketDataStrc
{
    int nPacketSize;
    unsigned char packetData[0x200];
    D2PacketDataStrc* pNext;
};

struct D2ClientStrc
{
    char unk0x000[0x1B8];
    D2PacketDataStrc* pPacketDataHead;
    D2PacketDataStrc* pPacketDataTail;
    D2PacketDataStrc* pPacketDataPool;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" const char szSCmdCppFile_006D69E4[];                                                             // 0x006D69E4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void*, int, D2ClientStrc*); // 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient)
{
    int nSize = 0;
    if (!pClient)
    {
        return;
    }

    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetTail(pClient);
    if (pPacketData)
    {
        nSize = pPacketData->nPacketSize;
    }

    if (nPacketSize + nSize > 0x200 || !pPacketData)
    {
        pPacketData = pClient->pPacketDataPool;
        nSize = 0;
        if (pPacketData)
        {
            pClient->pPacketDataPool = pPacketData->pNext;
        }
        else
        {
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), szSCmdCppFile_006D69E4, 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

#pragma pack(push, 1)
struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nChatType;
    unsigned char nLanguage;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[16];
    char szMessage[256];
};
#pragma pack(pop)
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0

// 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket)
{
    int nMessageLength = 0;
    if (strlen(pPacket->szMessage) >= 256)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x5BA);
        exit(-1);
    }
    if (pPacket->szMessage[255])
        pPacket->szMessage[255] = 0;
    D2GSPacketSrv26 packet;
    packet.nHeader = pPacket->nHeader;
    packet.nChatType = pPacket->nChatType;
    packet.nLanguage = pPacket->nLanguage;
    packet.nUnitType = pPacket->nUnitType;
    packet.nUnitGUID = pPacket->nUnitGUID;
    packet.nColor = pPacket->nColor;
    packet.nSubType = pPacket->nSubType;
    char* pText = packet.szName + SStrCopy(packet.szName, pPacket->szName, 16) + 1;
    nMessageLength = SStrCopy(pText, pPacket->szMessage, 256);
    nMessageLength += pText - (char*)&packet + 1;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, nMessageLength, pClient);
}
