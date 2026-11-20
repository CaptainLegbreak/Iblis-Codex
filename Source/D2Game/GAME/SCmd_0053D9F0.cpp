#include "D2GameRecords.h"
#include "D2GameClient.h"
#pragma pack(push, 1)
struct D2GSPacketSrv83
{
    unsigned char nHeader;
    char szName[4];
    unsigned short f_5;
    unsigned short wSize;
    unsigned short f_9;
    unsigned char pData[0x190];
};

struct D2GSPacketSrv84
{
    unsigned char nHeader;
    unsigned char nArg;
    unsigned char pData[0x190];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
#pragma intrinsic(strcpy)
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

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

// 0x0053D9F0
void __cdecl sub_0053D9F0_AssertFalse()
{
    D2_ASSERT(0, 0xAB4);
}

// 0x0053DC20
void __fastcall sub_0053DC20_SendPacket0x83(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x83;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, wSize + 0x0B, pClient);
}

// 0x0053DCC0
void __fastcall sub_0053DCC0_SendPacket0x84(D2ClientStrc* pClient, unsigned char nArg, unsigned short wSize, const void* pData)
{
    D2GSPacketSrv84 packet;
    packet.nHeader = 0x84;
    packet.nArg = nArg;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, wSize + 2, pClient);
}

// 0x0053DD20
void __fastcall sub_0053DD20_SendPacket0x88(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x88;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, wSize + 0x0B, pClient);
}
