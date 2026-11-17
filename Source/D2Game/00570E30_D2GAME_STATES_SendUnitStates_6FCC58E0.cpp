struct D2ClientStrc;
struct D2StatListStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pPool; int dwUnitId; };
struct D2BitBufferStrc { unsigned char* pBuffer; int nBits; int nPos; int nPosBits; int bFull; };
struct D2StatStrc { union { struct { unsigned short nLayer; unsigned short nStat; }; int nPackedValue; }; int nValue; };
struct D2StatesTxt { char unk_00[0x10]; unsigned char nStateFlags[8]; char unk_18[0x24]; };
struct D2ItemStatCostTxt { int nStatId; unsigned char dwItemStatFlags[4]; unsigned char nSendBits; unsigned char nSendParamBits; char unk_0A[0x13A]; };
struct D2DataTablesStrc { char unk_00[0xBC]; D2StatesTxt* pStatesTxt; int unk_C0; int nStatesTxtRecordCount; char unk_C8[0xB04]; D2ItemStatCostTxt* pItemStatCostTxt; int unk_BD0; int nItemStatCostTxtRecordCount; };
#pragma pack(push, 1)
struct D2GSPacketSrvAA { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nSize; unsigned char pStream[244]; };
#pragma pack(pop)
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __stdcall BITMANIP_Initialize(D2BitBufferStrc*, unsigned char*, unsigned int); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc*); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc*, unsigned int, int); // 0x00410EB0
int __stdcall FOG_LeadingZeroesCount(unsigned int); // 0x004111A0
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc*); // 0x0063A100
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc*, D2StatStrc*, int); // 0x00625C90
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc*, const void*, int); // 0x0053E8D0
static __forceinline D2StatesTxt* SKILLS_GetStatesTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nStatesTxtRecordCount) return 0; return &sgptDataTables->pStatesTxt[id]; }
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nItemStatCostTxtRecordCount) return 0; return &sgptDataTables->pItemStatCostTxt[id]; }
enum { UNIT_INVALID = 6 };
// build: context sub_GetUnitTypeOrInvalid
static __forceinline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit) { if (!pUnit) return UNIT_INVALID; return pUnit->dwUnitType; }
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
// 0x00570E30
void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2BitBufferStrc bitBuffer;
    unsigned int nFlags[8];
    D2StatStrc stats[16];
    if (!pUnit || !pClient) return;
    unsigned int* pFlags = D2COMMON_10494_STATES_GetStatFlags(pUnit);
    const int nTotalStatFlagCount = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
    memcpy(nFlags, pFlags, sizeof(unsigned int) * nTotalStatFlagCount);
    D2GSPacketSrvAA packetAA;
    packetAA.nHeader = 0xAA;
    packetAA.nUnitType = sub_GetUnitTypeOrInvalid(pUnit);
    packetAA.nUnitId = pUnit->dwUnitId;
    BITMANIP_Initialize(&bitBuffer, packetAA.pStream, 244);
    int i = 0;
    int nStateOffset = 0;
    for (; i < nTotalStatFlagCount; ++i, nStateOffset += 32)
    {
        int nBit = FOG_LeadingZeroesCount(nFlags[i]);
        while (nBit >= 0)
        {
            nFlags[i + (nBit >> 5)] &= gdwInvBitMasks[nBit & 31];
            const int nStateId = nBit + nStateOffset;
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nStateId);
            if (!pStatesTxtRecord) { nBit = FOG_LeadingZeroesCount(nFlags[i]); continue; }
            if (pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[0]) { nBit = FOG_LeadingZeroesCount(nFlags[i]); continue; }
            {
                if (BITMANIP_GetSize(&bitBuffer) + 7 >= 219) break;
                BITMANIP_Write(&bitBuffer, nStateId, 8);
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStateId);
                if (pStatList)
                {
                    const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
                    if (nStatCount > 0)
                    {
                        BITMANIP_Write(&bitBuffer, 1, 1);
                        for (int j = 0; j < nStatCount; ++j)
                        {
                            const int nStatId = (unsigned int)stats[j].nPackedValue >> 16;
                            const unsigned short nLayer = stats[j].nLayer;
                            int nValue = stats[j].nValue;
                            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nSendBits > 0)
                            {
                                if (pItemStatCostTxtRecord->nSendBits < 32)
                                {
                                    if (pItemStatCostTxtRecord->dwItemStatFlags[0] & gdwBitMasks[1])
                                    {
                                        const int nMin = -1 << (pItemStatCostTxtRecord->nSendBits - 1);
                                        nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nSendBits - 1)) - 1);
                                    }
                                    else
                                    {
                                        nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nSendBits) - 1);
                                    }
                                }
                                BITMANIP_Write(&bitBuffer, nStatId, 9);
                                if (pItemStatCostTxtRecord->nSendParamBits)
                                    BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                                BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                            }
                        }
                        BITMANIP_Write(&bitBuffer, 0x1FF, 9);
                    }
                    else BITMANIP_Write(&bitBuffer, 0, 1);
                }
                else BITMANIP_Write(&bitBuffer, 0, 1);
            }
            nBit = FOG_LeadingZeroesCount(nFlags[i]);
        }
    }
    BITMANIP_Write(&bitBuffer, 0xFF, 8);
    const int nSize = BITMANIP_GetSize(&bitBuffer) + 7;
    packetAA.nSize = nSize;
    sub_0053E8D0_SendPacket(pClient, &packetAA, nSize);
}
