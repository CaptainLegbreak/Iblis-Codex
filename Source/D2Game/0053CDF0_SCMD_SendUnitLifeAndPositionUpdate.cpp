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

struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

#pragma pack(push, 1)
struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};

struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};
union D2GSPacketSrv7F90
{
    D2GSPacketSrv7F packet7F;
    D2GSPacketSrv90 packet90;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int a2);                           // 0x00537860
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

__declspec(noinline) static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient);

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

int __stdcall UNITS_GetDistanceToOtherUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x006416D0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

__declspec(noinline) static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId);
static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId)
{
    sub_00408A60((const char*)nLifePercentage, (const char*)pPlayer, (int)pUnit);
    return UNITS_GetCurrentLifePercentage((D2UnitStrc*)nLevelId);
}

// 0x0053CDF0
void __fastcall SCMD_SendUnitLifeAndPositionUpdate(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x72A);

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    D2GSPacketSrv7F90 tPacket;
    const D2GSPacketSrv7F tZero7F = {};
    tPacket.packet7F = tZero7F;
    tPacket.packet7F.nHeader = 0x7F;

    if (pUnit->dwUnitType == 0)
    {
        tPacket.packet7F.bIsPlayer = 1;
    }

    tPacket.packet7F.nUnitGUID = pUnit->dwUnitId;
    tPacket.packet7F.nLifePercentage = nLifePercentage;
    if (nLifePercentage >= 0xFFFF)
    {
        tPacket.packet7F.nLifePercentage = 0xFFFF;
    }

    tPacket.packet7F.nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));

    if (sub_0053CD80_ShouldSendLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), pUnit, nLifePercentage, tPacket.packet7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket.packet7F, sizeof(tPacket.packet7F), pClient);
    }

    if (tPacket.packet7F.bIsPlayer)
    {
        D2UnitStrc* pClientPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (UNITS_GetDistanceToOtherUnit(pClientPlayer, pUnit) > 50)
        {
            const D2GSPacketSrv90 tZero90 = {};
            tPacket.packet90 = tZero90;
            tPacket.packet90.nHeader = 0x90;
            tPacket.packet90.dwGUID = pUnit->dwUnitId;
            tPacket.packet90.dwPosX = CLIENTS_GetUnitX(pUnit);
            tPacket.packet90.dwPosY = CLIENTS_GetUnitY(pUnit);
            D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket.packet90, sizeof(tPacket.packet90), pClient);

        }
    }
}
