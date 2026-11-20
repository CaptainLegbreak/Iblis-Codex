#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Primitives.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define MONMODE_SKILL1 8
#define MONMODE_SKILL2 9
#define MONMODE_DEAD 12
#define MONTYPEFLAG_CHAMPION 4
#define MONTYPEFLAG_UNIQUE 8
#define MONTYPEFLAG_MINION 16
#define MONTYPEFLAG_GHOSTLY 64
#define UNITFLAG_ISMERC 0x200
#define ITEMSTATCOSTFLAGINDEX_SEND_OTHER 0
struct D2PacketDataStrc;
struct D2GSPacketSrv4D;
struct D2GSPacketSrv8C;
struct D2GSPacketSrv8D;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2GSPacketSrvAC;

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430


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

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient); // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData); // 0x00539240
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

#pragma pack(push, 1)
struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    int unk0x06;
    unsigned char unk0x0A;
    unsigned short unk0x0B;
    unsigned short unk0x0D;
    unsigned short unk0x0F;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};

struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};

#pragma pack(pop)







#pragma pack(push, 1)
struct D2GSPacketSrvAC
{
    unsigned char nHeader;
    int dwUnitGUID;
    unsigned short nUnitIndex;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char nLifePct;
    unsigned char nPacketLength;
    unsigned char bitstream[0xF4];
};

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __fastcall sub_00573AE0_HasComponents(D2UnitStrc* pUnit); // 0x00573AE0
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
int __fastcall sub_005A0380_HasMonsterFlag(D2UnitStrc* pUnit); // 0x005A0380
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
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

// 0x0053D4D0
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9)
{
    D2GSPacketSrv4D packet;

    packet.nHeader = a9 != 0 ? 0x9Au : 0x4Du;
    packet.unk0x01 = a2;
    packet.unk0x02 = a3;
    packet.unk0x0B = a4;
    packet.unk0x0D = a5;
    packet.unk0x06 = a6;
    packet.unk0x0A = a8;
    packet.unk0x0F = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, sizeof(packet));
}

// 0x0053DDF0
void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBAE), pPacket, sizeof(D2GSPacketSrv8C));
}

// 0x0053DE50
void __fastcall D2GAME_PACKETS_SendPacket0x8C_6FC3F8B0(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState)
{
    D2GSPacketSrv8C packet8C;

    packet8C.nHeader = 0x8C;
    packet8C.dwPlayerGUID1 = dwPlayerId1;
    packet8C.dwPlayerGUID2 = dwPlayerId2;
    packet8C.nFlags = wRelationState;

    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBD0), &packet8C, sizeof(packet8C));
}

// 0x0053DE90
void __fastcall sub_6FC3F930(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBD8), pPacket, sizeof(D2GSPacketSrv8D));
}

// 0x0053DEC0
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    SUNIT_IterateLivingPlayers(pGame, sub_6FC3F930, &packet8D);
}

// 0x0053DF00
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBF6), &packet8D, sizeof(packet8D));
}

// 0x0053DF50
void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBFF), pPacket, 0xA);
}

// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

// build: context Log2Ceil
static __forceinline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : sub_00409000_GetBitWidth(nValue - 1);
}

// build: context sub_0044BE50
static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// build: context sub_00623C60
static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// build: context sub_00451F50
static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// build: context UNITS_IsMerc
static __forceinline int UNITS_IsMerc(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// build: context UNITS_HasStoredOwnerInfo
static __forceinline int UNITS_HasStoredOwnerInfo(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 10) & 1;
}

// build: context CLIENTS_GetUnitX
static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// build: context CLIENTS_GetUnitY
static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context MONSTER_GetComponents
static __forceinline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

// build: context SKILLS_GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0053E2E0
void __fastcall sub_6FC3FC80(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return;
    }

    D2GSPacketSrvAC packetAC;
    packetAC.nHeader = 0xAC;
    packetAC.dwUnitGUID = pUnit->dwUnitId;
    packetAC.nUnitIndex = sub_00623C60(pUnit);
    packetAC.nPosX = CLIENTS_GetUnitX(pUnit);
    packetAC.nPosY = CLIENTS_GetUnitY(pUnit);
    packetAC.nLifePct = MONSTERMODE_GetHpPercent128(pUnit);

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, packetAC.bitstream, sizeof(packetAC.bitstream));

    if (pUnit->dwAnimMode == MONMODE_SKILL1)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_SKILL2)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, MONMODE_NEUTRAL, 4);
    }

    if (sub_00573AE0_HasComponents(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            for (int i = 0; i < 16; ++i)
            {
                const unsigned char nComponent = pComponents[i];
                BITMANIP_Write(&bitBuffer, nComponent, Log2Ceil(D2COMMON_11068_GetCompInfo(pUnit, i)));
            }
        }
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    if (!sub_005A0380_HasMonsterFlag(pUnit) && !UNITS_IsMerc(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        const int nChampion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION);
        BITMANIP_Write(&bitBuffer, nChampion != 0, 1);
        const int nUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE);
        BITMANIP_Write(&bitBuffer, nUnique != 0, 1);
        const int nSuperUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE);
        BITMANIP_Write(&bitBuffer, nSuperUnique != 0, 1);
        const int nMinion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_MINION);
        BITMANIP_Write(&bitBuffer, nMinion != 0, 1);
        const int nGhostly = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_GHOSTLY);
        BITMANIP_Write(&bitBuffer, nGhostly != 0, 1);

        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE))
        {
            BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetBossHcIdx(pUnit), 16);
        }

        const unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
        if (pUMods)
        {
            for (int i = 0; i < 9 && pUMods[i]; ++i)
            {
                BITMANIP_Write(&bitBuffer, pUMods[i], 8);
            }
        }

        BITMANIP_Write(&bitBuffer, 0, 8);

        BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetNameSeed(pUnit), 16);

        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && PLAYERPETS_GetPetTypeFromPetGUID(pOwner, packetAC.dwUnitGUID) == PETTYPE_HIREABLE)
        {
            BITMANIP_Write(&bitBuffer, 1, 1);
            BITMANIP_Write(&bitBuffer, sub_00451F50(pOwner), 32);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    if (UNITS_HasStoredOwnerInfo(pUnit) && pUnit->dwOwnerType == UNIT_PLAYER)
    {
        BITMANIP_Write(&bitBuffer, 1, 1);
        BITMANIP_Write(&bitBuffer, pUnit->dwOwnerGUID & 0x8FFFFFFF, 31);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    int bStatsSent = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
    if (pStatList)
    {
        D2StatStrc stats[16];
        const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
        if (nStatCount > 0)
        {
            for (int i = 0; i < nStatCount; ++i)
            {
                const unsigned short nLayer = stats[i].nLayer;
                const int nStat = stats[i].nStat;
                const int nValue = stats[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(stats[i].nStat);
                if (pItemStatCostTxtRecord)
                {
                    if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SEND_OTHER >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SEND_OTHER & 7] && pItemStatCostTxtRecord->nSendBits > 0)
                    {
                        if (!bStatsSent)
                        {
                            bStatsSent = 1;
                            BITMANIP_Write(&bitBuffer, 1, 1);
                        }

                        BITMANIP_Write(&bitBuffer, nStat, 9);

                        if (pItemStatCostTxtRecord->nSendParamBits)
                        {
                            BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                        }

                        BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                    }
                }
            }

            if (bStatsSent)
            {
                BITMANIP_Write(&bitBuffer, 511, 9);
                goto Send;
            }
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    BITMANIP_Write(&bitBuffer, 0, 1);

Send:
    const int nPacketSize = BITMANIP_GetSize(&bitBuffer) + 13;
    packetAC.nPacketLength = nPacketSize;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetAC, nPacketSize);
}
