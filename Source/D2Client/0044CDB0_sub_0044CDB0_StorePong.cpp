extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

struct D2PongDataStrc
{
    unsigned long dwData0;
    unsigned long dwData1;
    unsigned long dwData2;
    unsigned long dwData3;
    unsigned long dwTick;
    unsigned long dwData5;
    unsigned long dwData6;
    unsigned long dwData7;
};

#pragma pack(push, 1)
struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    D2PongDataStrc tData;
};
#pragma pack(pop)

unsigned long gdwLastTick_007A04A0;                                                                         // 0x007A04A0
unsigned long gdwPing_007A04A4;                                                                             // 0x007A04A4
unsigned long gdwPingSamples_007A04CC;                                                                      // 0x007A04CC
unsigned long gdwPingAverage_007A04D0;                                                                      // 0x007A04D0
extern D2PongDataStrc gtPongData_007A04D4;                                                                  // 0x007A04D4

// 0x0044CDB0
void __fastcall sub_0044CDB0_StorePong(const D2GSPacketSrv8F* pPacket)
{
    gtPongData_007A04D4.dwData0 = pPacket->tData.dwData0;
    gtPongData_007A04D4.dwData1 = pPacket->tData.dwData1;
    gtPongData_007A04D4.dwData2 = pPacket->tData.dwData2;
    gtPongData_007A04D4.dwData3 = pPacket->tData.dwData3;
    gtPongData_007A04D4.dwTick = pPacket->tData.dwTick;
    gtPongData_007A04D4.dwData5 = pPacket->tData.dwData5;
    gtPongData_007A04D4.dwData6 = pPacket->tData.dwData6;
    gtPongData_007A04D4.dwData7 = pPacket->tData.dwData7;
    gtPongData_007A04D4.dwTick = GetTickCount();
    unsigned long dwPing = GetTickCount() - gdwLastTick_007A04A0;
    gdwPing_007A04A4 = dwPing;
    if (gdwPingSamples_007A04CC < 10)
    {
        dwPing += gdwPingAverage_007A04D0 * gdwPingSamples_007A04CC;
        ++gdwPingSamples_007A04CC;
        gdwPingAverage_007A04D0 = dwPing / gdwPingSamples_007A04CC;
    }
}
