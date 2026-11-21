#include "D2Game.h"
#include "D2GameClient.h"
#include "D2GameRecords.h"

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" const char szSCmdCppFile_006D69E4[];
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);


D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);

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
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), szSCmdCppFile_006D69E4, 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

#pragma pack(push, 1)
struct D2GSPacketSrvA3
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned short unk0x04;
    unsigned char unk0x06;
    unsigned int unk0x07;
    unsigned char unk0x0B;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    unsigned int unk0x14;
};
struct D2GSPacketSrvAB
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nLife;
};
struct D2GSPacketSrvA5
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned short unk0x06;
};
struct D2GSPacketSrv22
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    int nUnitGUID;
    unsigned short nSkillId;
    unsigned char nQuantity;
    unsigned char unk0x0A;
    unsigned char bIsCorpse;
};
struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    unsigned int dwPlayerGUID;
};
struct D2GSPacketSrv77
{
    unsigned char nHeader;
    unsigned char nAction;
};
struct D2GSPacketSrv78
{
    unsigned char nHeader;
    char szName[16];
    unsigned int dwPlayerGUID;
};
struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    unsigned int unk0x05;
    unsigned int unk0x09;
};
struct D2GSPacketSrv81
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned int unk0x04;
    unsigned int unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
};
#pragma pack(pop)
struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};
struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char nCycleIndex;
    unsigned char nCycleIndex1;
    unsigned char nCycleIndex2;
    unsigned char nCycleIndex3;
    unsigned char nTicks;
    unsigned char nTicks1;
    unsigned char nTicks2;
    unsigned char nTicks3;
    unsigned char nEclipse;
};
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char abParam[4];
    unsigned char nParam;
    char szText[32];
};
struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

void __fastcall D2GAME_PACKETS_SendPacket0xA3_6FC3D730(D2ClientStrc* pClient, unsigned char a2, unsigned short a3, unsigned short a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    D2GSPacketSrvA3 packetA3 = {};

    packetA3.nHeader = 0xA3;
    packetA3.unk0x01 = a2;
    packetA3.unk0x02 = a3;
    packetA3.unk0x04 = a4;
    packetA3.unk0x06 = a5;
    packetA3.unk0x07 = a6;
    packetA3.unk0x0B = a7;
    packetA3.unk0x0C = a8;
    packetA3.unk0x10 = a9;
    packetA3.unk0x14 = a10;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA3, sizeof(packetA3), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife)
{
    D2GSPacketSrvAB packetAB = {};

    packetAB.nHeader = 0xAB;
    packetAB.nUnitType = nUnitType;
    packetAB.dwUnitGUID = dwUnitId;
    packetAB.nLife = nUnitLife;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetAB, sizeof(packetAB), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4)
{
    D2GSPacketSrvA5 packetA5 = {};

    packetA5.nHeader = 0xA5;
    packetA5.unk0x01 = a2;
    packetA5.unk0x02 = a3;
    packetA5.unk0x06 = a4;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA5, sizeof(packetA5), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity)
{
    D2GSPacketSrv22 packet22;

    packet22.nHeader = 0x22;
    packet22.nUnitType = nUnitType;
    packet22.nUnitGUID = nUnitGUID;
    packet22.nSkillId = nSkillId;
    packet22.nQuantity = nQuantity;

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    packet22.bIsCorpse = pUnit && STATES_CheckState(pUnit, 7);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet22, sizeof(packet22), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket)
{
    D2_ASSERT(strlen(pPacket->szText) < 16, 1498);

    D2GSPacketSrv5A packet5A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5A, sizeof(packet5A), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket)
{
    D2GSPacketSrv27 packet27 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet27, sizeof(packet27), pClient);
}

void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket)
{
    D2GSPacketSrv53 packet53 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet53, sizeof(packet53), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID)
{
    D2GSPacketSrv5C packet5C;
    packet5C.nHeader = 0x5C;
    packet5C.dwPlayerGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5C, sizeof(packet5C), pClient);
}

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo)
{
    D2GSPacketSrv77 packet77;
    packet77.nHeader = 0x77;
    packet77.nAction = nUiNo;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet77, sizeof(packet77), pClient);
}

// 0x0053D960
void __fastcall sub_0053CAD0_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet78, sizeof(packet78), pClient);
}

// 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass)
{
    D2GSPacketSrv7A packet7A = {};

    packet7A.nHeader = 0x7A;
    packet7A.unk0x01 = a2;
    packet7A.unk0x02 = nPetType;
    packet7A.unk0x03 = nPetClass;
    packet7A.unk0x09 = nPetGUID;
    packet7A.unk0x05 = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7A, sizeof(packet7A), pClient);
}

// 0x0053CB80
void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName)
{
    D2GSPacketSrv81 packet81 = {};

    packet81.nHeader = 0x81;
    packet81.unk0x01 = nPetType;
    packet81.unk0x08 = nPetGUID;
    packet81.unk0x04 = nUnitGUID;
    packet81.unk0x02 = nPetClass;
    packet81.unk0x0C = nSeed;
    packet81.unk0x10 = nName;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet81, sizeof(packet81), pClient);
}
