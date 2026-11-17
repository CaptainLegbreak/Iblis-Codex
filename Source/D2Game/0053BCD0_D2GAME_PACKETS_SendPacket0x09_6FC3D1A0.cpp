#pragma pack(push, 1)
struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nClassId;
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv51
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nObject;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char nObjectParam;
    unsigned char nInteractType;
};
#pragma pack(pop)

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

struct D2GameStrc;
struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

// build: symbol ?D2GAME_PACKETS_SendPacket_6FC3C710@@YGXPBXHPAUD2ClientStrc@@@Z 0x0053B280
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
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), ".\\GAME\\SCmd.cpp", 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

// 0x0053BCD0
void __fastcall D2GAME_PACKETS_SendPacket0x09_6FC3D1A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, unsigned int nUnitGUID, unsigned char nClassId, unsigned short nPosX, unsigned short nPosY)
{
    D2GSPacketSrv09 packet09;
    packet09.nHeader = nHeader;
    packet09.nUnitType = nUnitType;
    packet09.dwUnitGUID = nUnitGUID;
    packet09.nClassId = nClassId;
    packet09.nPosX = nPosX;
    packet09.nPosY = nPosY;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet09, sizeof(packet09), pClient);
}

// 0x0053BD10
void __fastcall D2GAME_PACKETS_SendPacket0x51_6FC3D300(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nObjectId, unsigned short nX, unsigned short nY, unsigned char nAnimMode, unsigned char nInteractType)
{
    D2_ASSERT(SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID), 0x341);

    D2GSPacketSrv51 packet51;
    packet51.nHeader = nHeader;
    packet51.nUnitType = nUnitType;
    packet51.dwUnitGUID = nUnitGUID;
    packet51.nObject = nObjectId;
    packet51.nPosX = nX;
    packet51.nPosY = nY;
    packet51.nObjectParam = nAnimMode;
    packet51.nInteractType = nInteractType;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet51, sizeof(packet51), pClient);
}
