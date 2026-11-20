#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2StatesTxt { char pad00[0x10]; unsigned char nFlags; char pad11[0x2B]; };
struct D2ItemStatCostTxt { char pad00[4]; unsigned char nFlags; char pad05[3]; unsigned char nSendBits; unsigned char nSendParamBits; char pad0A[0x13A]; };
struct D2BitBufferStrc { unsigned char* pBuffer; int nBits; int nPos; int nPosBits; int bFull; };
#pragma pack(push, 1)
struct D2GSPacketSrvA8 { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nSize; unsigned char nState; unsigned char pData[244]; };
#pragma pack(pop)
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[32]; // 0x006CE2E8
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
unsigned int* __stdcall STATES_GetGfxStateFlags(D2UnitStrc* pUnit); // 0x00639F70
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue); // 0x004111A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize); // 0x0053E8D0
void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState); // 0x0053E260
void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff_6FC3FC50(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState); // 0x0053E290
#define D2_MIN(a,b) (((a)<(b))?(a):(b))
#define D2_MAX(a,b) (((a)>(b))?(a):(b))
static __forceinline D2StatesTxt* GetStatesRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount) return &sgptDataTables->pStatesTxt[nState];
    return 0;
}
static __forceinline D2ItemStatCostTxt* GetStatCostRecord(int nStat)
{
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}
// 0x005711D0
void __fastcall D2GAME_STATES_SendUnitStateUpdates_6FCC5BE0(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (!pUnit || !pClient) return;
    unsigned int dwFlags[8];
    unsigned int* pGfxFlags = STATES_GetGfxStateFlags(pUnit);
    int nWords = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
    memcpy(dwFlags, pGfxFlags, nWords * sizeof(unsigned int));
    int nUnitType = pUnit->dwUnitType;
    int nUnitId = pUnit->dwUnitId;
    int i = 0;
    int nStateBase = 0;
    for (; i < nWords; ++i, nStateBase += 32)
    {
        int nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
        while (nBit >= 0)
        {
            dwFlags[i + (nBit >> 5)] &= gdwInvBitMasks[nBit & 31];
            int nState = nStateBase + nBit;
            D2StatesTxt* pStates = GetStatesRecord(nState);
            if (pStates)
            {
                if (pStates->nFlags & gdwBitMasks[0])
                {
                    nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
                    continue;
                }
                if (STATES_CheckState(pUnit, nState))
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
                    if (pStatList)
                    {
                        D2StatStrc stats[16];
                        int nStats = STATLIST_GetBaseStatsData(pStatList, stats, 16);
                        if (nStats > 0)
                        {
                            D2GSPacketSrvA8 packet;
                            D2BitBufferStrc bitBuffer;
                            packet.nHeader = 0xA8;
                            packet.nUnitType = (unsigned char)nUnitType;
                            packet.nUnitId = nUnitId;
                            packet.nState = (unsigned char)nState;
                            BITMANIP_Initialize(&bitBuffer, packet.pData, sizeof(packet.pData));
                            for (int j = 0; j < nStats; ++j)
                            {
                                const int nStatId = (unsigned int)stats[j].nPackedValue >> 16;
                                const unsigned short nLayer = stats[j].nLayer;
                                int nValue = stats[j].nValue;
                                D2ItemStatCostTxt* pCost = GetStatCostRecord(nStatId);
                                if (pCost && pCost->nSendBits > 0)
                                {
                                    if (pCost->nSendBits < 32)
                                    {
                                        if (pCost->nFlags & gdwBitMasks[1])
                                        {
                                            const int nMin = -1 << (pCost->nSendBits - 1);
                                            nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pCost->nSendBits - 1)) - 1);
                                        }
                                        else
                                        {
                                            nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pCost->nSendBits) - 1);
                                        }
                                    }
                                    BITMANIP_Write(&bitBuffer, nStatId, 9);
                                    if (pCost->nSendParamBits)
                                        BITMANIP_Write(&bitBuffer, nLayer, pCost->nSendParamBits);
                                    BITMANIP_Write(&bitBuffer, nValue, pCost->nSendBits);
                                }
                            }
                            BITMANIP_Write(&bitBuffer, 511, 9);
                            int nPacketSize = BITMANIP_GetSize(&bitBuffer) + 8;
                            packet.nSize = (unsigned char)nPacketSize;
                            sub_0053E8D0_SendPacket(pClient, &packet, nPacketSize);
                        }
                        else D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState);
                    }
                    else D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState);
                }
                else D2GAME_PACKETS_SendPacket0xA9_StateOff_6FC3FC50(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState);
            }
            nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
        }
    }
}
