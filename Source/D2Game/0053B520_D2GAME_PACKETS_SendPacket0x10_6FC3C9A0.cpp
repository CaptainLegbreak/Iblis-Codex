#pragma pack(push, 1)
struct D2GSPacketSrv10Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nFlags;
    unsigned char nTargetType;
    int nTargetGUID;
    short nCurrentPosX;
    short nCurrentPosY;
};

struct D2GSPacketSrv0FStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nFlags;
    short nDestPosX;
    short nDestPosY;
    unsigned char nHitClass;
    short nCurrentPosX;
    short nCurrentPosY;
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

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_TYPES_COUNT 6

// 0x0053B280
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

// 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9)
{
    D2GSPacketSrv10Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = a3;
    tPacket.nUnitGUID = a4;
    tPacket.nFlags = a5;
    tPacket.nTargetType = a6;
    tPacket.nTargetGUID = a7;
    tPacket.nCurrentPosX = a8;
    tPacket.nCurrentPosY = a9;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B570
void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10)
{
    D2GSPacketSrv0FStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = bTOU;
    tPacket.nUnitGUID = a4;
    tPacket.nFlags = a5;
    tPacket.nDestPosX = a6;
    tPacket.nDestPosY = a7;
    tPacket.nHitClass = a8;
    tPacket.nCurrentPosX = a9;
    tPacket.nCurrentPosY = a10;
    D2_ASSERT(bTOU < UNIT_TYPES_COUNT, 0x166);
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}
