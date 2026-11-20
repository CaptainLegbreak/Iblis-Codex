#include "D2Structs.h"
#include "D2GameRecords.h"
#include "D2GameClient.h"

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void*, int, D2ClientStrc*); // 0x0053B280
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

#pragma pack(push, 1)
struct D2GSPacketSrv9D { unsigned char nHeader; unsigned char nAction; unsigned char nPacketSize; unsigned char nComponent; int nItemId; unsigned char nUnitType; int nUnitId; unsigned char pBitstream[244]; };
#pragma pack(pop)
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc*, D2UnitStrc*); // 0x00623D60
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc*); // 0x00628110
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc*, unsigned char*, int, int, int, int); // 0x006313E0
int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc*, D2UnitStrc*, int); // 0x0053EA50
static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}
// 0x0053CEF0
void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2GSPacketSrv9D packet;
    packet.nHeader = 0x9D;
    packet.nAction = nAction;
    packet.nComponent = UNITS_GetItemComponentId(pUnit, pItem);
    packet.nItemId = SCMD_GetUnitGUID(pItem);
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    packet.nUnitType = nUnitType;
    packet.nUnitId = SCMD_GetUnitGUID(pUnit);
    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);
    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet.pBitstream, sizeof(packet.pBitstream), 0, 0, bGamble) + 13;
    D2_ASSERT(nLength <= 0xFC, 0x7B4);
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);
    packet.nPacketSize = nLength;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, packet.nPacketSize, pClient);
    sub_0053EA50_SendSocketedItems(pClient, pItem, dwFlag);
}
