#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
struct D2PacketDataStrc;
struct D2GSPacketSrv21;
struct D2GSPacketSrv7F;
struct D2GSPacketSrv90;
struct D2LifeSyncStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;
struct D2PacketHeaderOnlyStrc;
struct D2PacketSize06Strc;
struct D2PacketSize05Strc;
struct D2PacketTarget3FStrc;

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2PacketDataStrc
{
    int nPacketSize;
    unsigned char packetData[0x200];
    D2PacketDataStrc* pNext;
};

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient); // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData); // 0x00539240

#pragma pack(push, 1)
struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    unsigned int nUnitGUID;
    unsigned short nSkillId;
    unsigned char nSkillLevel;
    unsigned char nBonusSkillLevel;
    unsigned char unk0x0B;
};

#pragma pack(pop)

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    D2LifeSyncStrc tLifeSync;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x98];
    D2LifeSyncStrc* pPartyLifeList;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
static __declspec(noinline) int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc*, D2UnitStrc*, int);
static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer); // 0x0053CC90

#pragma pack(push, 1)
struct D2PacketHeaderOnlyStrc
{
    unsigned char nHeader;
};

struct D2PacketSize06Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2PacketSize05Strc
{
    unsigned char nHeader;
    int nValue;
};

struct D2PacketTarget3FStrc
{
    unsigned char nHeader;
    unsigned char nType;
    int nUnitGUID;
    unsigned short nValue;
};

#pragma pack(pop)

static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient);
static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, int nLifePercentage, D2UnitStrc* pUnit, int nLevelId);

// build: context sub_GetUnitType
static __forceinline int sub_GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}

// 0x0053C4A0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove)
{
    if (!pUnit)
    {
        return;
    }

    if (!pClient && pUnit->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (!pOwner)
        {
            return;
        }

        pClient = UnitGetClient(pOwner, ".\\GAME\\SCmd.cpp", 1298);
    }

    if (pClient)
    {
        D2GSPacketSrv21 packet21;
        packet21.nHeader = 0x21;
        packet21.nUnitType = sub_GetUnitType(pUnit);
        packet21.bRemove = bRemove;
        packet21.nUnitGUID = pUnit->dwUnitId;
        packet21.nSkillId = nSkillId;
        packet21.nSkillLevel = nSkillLevel;
        packet21.nBonusSkillLevel = (unsigned char)SKILLS_GetBonusSkillLevelFromSkillId(pUnit, nSkillId);
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet21, sizeof(packet21), pClient);
    }
}

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

// 0x0053CC90
static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    if (!pGame)
    {
        return 0;
    }
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pPlayer);
    if (nPartyId == 0xFFFF || nPartyId != PARTY_GetPartyIdForUnitOwner(pGame, pUnit))
    {
        return 0;
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pPlayerData->pPartyLifeList;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    int bFound = 0;
    while (!bFound)
    {
        if (!pLifeSync)
        {
            pLifeSync = (D2LifeSyncStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2LifeSyncStrc), ".\\GAME\\SCmd.cpp", 0x6FA, 0);
            if (!pLifeSync)
            {
                return 0;
            }
            *pLifeSync = D2LifeSyncStrc();
            pLifeSync->pNext = pPlayerData->pPartyLifeList;
            pPlayerData->pPartyLifeList = pLifeSync;
            pLifeSync->nUnitGUID = nUnitGUID;
            bFound = 1;
        }
        else if (nUnitGUID == pLifeSync->nUnitGUID)
        {
            bFound = 1;
        }
        else
        {
            pLifeSync = pLifeSync->pNext;
        }
    }

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

    default:
        return 0;
    }
}

// 0x0053B320
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader)
{
    D2PacketHeaderOnlyStrc tPacket;
    tPacket.nHeader = nHeader;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId)
{
    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = dwUnitType;
    tPacket.nUnitGUID = dwUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B400
void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue)
{
    D2PacketSize05Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053D220
void __fastcall sub_0053D220_SendTargetPacket(D2ClientStrc* pClient, D2UnitStrc* pUnit,
    unsigned char nType, int bClear, int nUnused, unsigned short nValue)
{
    D2PacketTarget3FStrc packet = {};
    packet.nHeader = 0x3F;
    if (bClear)
    {
        if (!pUnit)
        {
            packet.nType = 0xFF;
            packet.nUnitGUID = 0;
            goto send;
        }
        packet.nType = 0xFF;
    }
    else
    {
        packet.nType = nType;
        if (!pUnit)
            goto send;
    }
    packet.nUnitGUID = pUnit->dwUnitId;
send:
    packet.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, sizeof(packet), pClient);
}
