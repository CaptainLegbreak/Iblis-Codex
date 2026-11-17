struct D2BigPowModStrc;

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    void sub_005285A0_Init(int nSize1, const unsigned char* pData1, int nSize2, const unsigned char* pData2); // 0x005285A0
    void sub_00528620_Seed(unsigned long nSeedTicks);                                                        // 0x00528620
    void sub_00528630_Clear();                                                                               // 0x00528630
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern const unsigned char gabSrpData1_00730164[];                                                          // 0x00730164
extern int gnSrpSize1_00730168;                                                                             // 0x00730168
extern const unsigned char gabSrpData2_0073016C[];                                                          // 0x0073016C
extern int gnSrpSize2_0073018C;                                                                             // 0x0073018C
extern D2BigPairStrc gtBigPair_0088273C;                                                                    // 0x0088273C

// 0x00521B50
void __cdecl sub_00521B50_ReseedLogin()
{
    gtBigPair_0088273C.sub_005285A0_Init(gnSrpSize1_00730168, gabSrpData1_00730164, gnSrpSize2_0073018C, gabSrpData2_0073016C);
    gtBigPair_0088273C.sub_00528620_Seed(GetTickCount());
}

// 0x00521B90
void __cdecl sub_00521B90_ClearSrpState()
{
    gtBigPair_0088273C.sub_00528630_Clear();
}

#include "gen/data/Source/Bnclient/00521B50_sub_00521B50_ReseedLogin.inc"
