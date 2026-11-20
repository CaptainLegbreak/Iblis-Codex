#include "D2Game.h"
#include "D2Structs.h"

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430


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

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                  // 0x00537860
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

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

#pragma pack(push, 1)
struct D2GSPacketSrv4C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short wSkill;
    unsigned char nSkillLevel;
    unsigned char nTargetType;
    int dwTargetGUID;
    unsigned short unk0x0E;
};

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
#pragma pack(pop)

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

// 0x0053D530
void __fastcall sub_0053D530(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned char nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9)
{
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    if (!pUnit)
    {
        D2GSPacketSrv4C packet4C;

        packet4C.nHeader = a9 != 0 ? 0x99u : 0x4Cu;
        packet4C.nUnitType = a2;
        packet4C.dwUnitGUID = a3;
        packet4C.nTargetType = nUnitType;
        packet4C.dwTargetGUID = nUnitGUID;
        packet4C.wSkill = a6;
        packet4C.nSkillLevel = a8;
        packet4C.unk0x0E = a7;

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet4C, sizeof(packet4C));
        return;
    }

    D2ActiveRoomStrc* pClientRoom = UNITS_GetRoom(CLIENTS_GetPlayerFromClient(pClient, 0));
    if (pClientRoom)
    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        for (int i = 0; i < nNumRooms; ++i)
        {
            if (pRoom == ppRoomList[i])
            {
                D2GSPacketSrv4C packet4C;

                packet4C.nHeader = a9 != 0 ? 0x99u : 0x4Cu;
                packet4C.nUnitType = a2;
                packet4C.dwUnitGUID = a3;
                packet4C.nTargetType = nUnitType;
                packet4C.dwTargetGUID = nUnitGUID;
                packet4C.wSkill = a6;
                packet4C.nSkillLevel = a8;
                packet4C.unk0x0E = a7;

                D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet4C, sizeof(packet4C));
                return;
            }
        }
    }

    sub_6FC3F060(pClient, a2, a3, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), a6, a7, a8, a9);
}
