#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2GameRecords.h"
#include "D2GameClient.h"
#pragma pack(push, 1)
struct D2GSPacketSrv5B
{
    unsigned char nHeader;
    unsigned short nPacketLen;
    unsigned int nUnitGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nLevel;
    unsigned short nPartyId;
    unsigned short unk0x1C;
    unsigned short nPartyFlags;
    unsigned short nGuildFlags;
    char szGuildTag[0x100];
};
#pragma pack(pop)

#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))
#define STAT_LEVEL 12
#define UNIT_PLAYER 0

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" unsigned int __cdecl strlen(const char* szString);
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pUnit);                                                       // 0x00554630
extern "C" unsigned short __fastcall sub_00539110(D2ClientStrc* pClient);                                 // 0x00539110
extern "C" void __fastcall sub_00539130(D2ClientStrc* pClient, unsigned int* pOut);                       // 0x00539130
extern "C" void __fastcall sub_00539150(D2ClientStrc* pClient, char* pDst);                               // 0x00539150
void __fastcall sub_00574F80(D2ClientStrc* pClient, D2UnitStrc* pPlayer);               // 0x00574F80

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

static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0053C940
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc* pClient1, D2UnitStrc* pPlayer, D2ClientStrc* pClient2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2GSPacketSrv5B packet5B;
    memset(&packet5B, 0, sizeof(packet5B));

    packet5B.nHeader = 0x5B;
    packet5B.nUnitGUID = SCMD_GetUnitGUID(pPlayer);
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    packet5B.nClass = nClass;
    packet5B.nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    packet5B.nPartyId = SUNIT_GetPartyId(pPlayer);
    packet5B.unk0x1C = 0;
    packet5B.nPartyFlags = 0;
    packet5B.nGuildFlags = sub_00539110(pClient2);

    SStrCopy(packet5B.szName, pPlayerData->szName, 0x7FFFFFFF);

    sub_00539130(pClient2, (unsigned int*)packet5B.szGuildTag);

    const int nLength = strlen(packet5B.szGuildTag) + 1;

    char* szString = &packet5B.szGuildTag[nLength];
    sub_00539150(pClient2, szString);

    const int nPacketLen = strlen(szString) + 1 + (szString - packet5B.szGuildTag) + offsetof(D2GSPacketSrv5B, szGuildTag);
    packet5B.nPacketLen = nPacketLen;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5B, nPacketLen, pClient1);

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        sub_00574F80(pClient1, pPlayer);
    }
}
