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

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1

struct D2ActiveRoomStrc;

struct D2LifeSyncStrc
{
    int nUnitGUID;
    int nLifePercentage;
    int nLevelId;
    unsigned char nUpdateCount;
    D2LifeSyncStrc* pNext;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    D2LifeSyncStrc tLifeSync;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x98];
    D2LifeSyncStrc* pPartyLifeList;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                       // 0x0058F0D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);               // 0x00540710
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                        // 0x006416D0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

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

// 0x0053CC10
static int SCMD_ShouldSendLifeUpdate(int nLifePercentage, D2LifeSyncStrc* pLifeSync)
{
    int nDiff = nLifePercentage - pLifeSync->nLifePercentage;
    if (nDiff)
    {
        if (nDiff < 0)
        {
            nDiff = -nDiff;
        }
        if (nDiff > 8)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
        if (++pLifeSync->nUpdateCount > 6)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
    }
    return 0;
}

// build: context GetMonsterLifeSync
static D2LifeSyncStrc* GetMonsterLifeSync(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return &pUnit->pMonsterData->tLifeSync;
    }
    return 0;
}

static __declspec(noinline) int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc*, D2UnitStrc*, int);
// 0x0053CC40
static int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nLifePercentage)
{
    if (AIGENERAL_GetMinionOwner(pUnit) != pPlayer)
    {
        return 0;
    }
    const int bTest = !pUnit || pUnit->dwUnitType != UNIT_MONSTER;
    if (!bTest)
    {
        pUnit = (D2UnitStrc*)pUnit->pMonsterData;
    }
    if (bTest)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pUnit ? &((D2MonsterDataStrc*)pUnit)->tLifeSync : 0;
    if (!pLifeSync)
    {
        return 0;
    }
    if (pLifeSync->nLifePercentage == nLifePercentage)
    {
        return 0;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer); // 0x0053CC90

// build: context SCMD_ShouldSendPartyLifeUpdate
static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    if (!pGame)
    {
        return 0;
    }
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pPlayer);
    if (nPartyId == 0xFFFF || PARTY_GetPartyIdForUnitOwner(pGame, pUnit) != nPartyId)
    {
        return 0;
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    D2LifeSyncStrc* pLifeSync = pPlayerData->pPartyLifeList;
    while (pLifeSync)
    {
        if (pLifeSync->nUnitGUID == nUnitGUID)
        {
            goto found;
        }
        pLifeSync = pLifeSync->pNext;
    }
    pLifeSync = (D2LifeSyncStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2LifeSyncStrc), ".\\GAME\\SCmd.cpp", 0x6FA, 0);
    if (!pLifeSync)
    {
        return 0;
    }
    *pLifeSync = D2LifeSyncStrc();
    pLifeSync->pNext = pPlayerData->pPartyLifeList;
    pPlayerData->pPartyLifeList = pLifeSync;
    pLifeSync->nUnitGUID = nUnitGUID;
found:
    if (pLifeSync->nLevelId != nLevelId)
    {
        pLifeSync->nLifePercentage = nLifePercentage;
        pLifeSync->nLevelId = nLevelId;
        return 1;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

// 0x0053CD80
static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, int nLifePercentage, D2UnitStrc* pUnit, int nLevelId)
{
    D2_ASSERT(pPlayer, 0x712);
    D2_ASSERT(pUnit, 0x713);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SCMD_ShouldSendPartyLifeUpdate(pUnit, nLifePercentage, nLevelId, pPlayer);
    case UNIT_MONSTER:
        return sub_0053CC40_ShouldSendMinionLifeUpdate(pUnit, pPlayer, nLifePercentage);
    }
    return 0;
}

// build: context sub_6FC3E200
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x72A);
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    D2GSPacketSrv7F tPacket7F = {};
    tPacket7F.nHeader = 0x7F;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        tPacket7F.bIsPlayer = 1;
    }
    tPacket7F.nUnitGUID = pUnit->dwUnitId;
    tPacket7F.nLifePercentage = nLifePercentage;
    if (nLifePercentage >= 0xFFFF)
    {
        tPacket7F.nLifePercentage = 0xFFFF;
    }
    tPacket7F.nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (sub_0053CD80_ShouldSendLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), nLifePercentage, pUnit, tPacket7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket7F, sizeof(tPacket7F), pClient);
    }
    if (tPacket7F.bIsPlayer && sub_006416D0_UnitEdgeDistance(CLIENTS_GetPlayerFromClient(pClient, 0), pUnit) > 50)
    {
        D2GSPacketSrv90 tPacket90 = {};
        tPacket90.nHeader = 0x90;
        tPacket90.dwGUID = pUnit->dwUnitId;
        tPacket90.dwPosX = CLIENTS_GetUnitX(pUnit);
        tPacket90.dwPosY = CLIENTS_GetUnitY(pUnit);
        D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket90, sizeof(tPacket90), pClient);
    }
}
