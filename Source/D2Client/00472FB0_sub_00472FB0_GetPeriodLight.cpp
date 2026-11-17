extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

struct D2PeriodLightStrc
{
    unsigned char nUnused;
    unsigned char nLight;
};

int __cdecl sub_004F5140();                                                                                 // 0x004F5140
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
extern D2DrlgActStrc* gpDrlgAct_007A0634;                                                                   // 0x007A0634
extern const D2PeriodLightStrc gtPeriodLight_006D6E40[];                                                    // 0x006D6E40
extern unsigned char gnOutdoorLight_007A89EC[];                                                             // 0x007A89EC
unsigned char gnPeriodLight_007A898C[12];                                                                   // 0x007A898C

// 0x00472FB0
static void __stdcall sub_00472FB0_GetPeriodLight(unsigned char* pOut2, int nValue, unsigned char* pOut1)
{
    int n = sub_004F5140();
    int bFlag;
    if (n > 0 && (n <= 3 || n == 6))
    {
        bFlag = 0;
    }
    else
    {
        bFlag = 1;
    }

    DUNGEON_GetLevelIdFromRoom(sub_004646A0_GetPlayerRoom());
    int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x356);

    if (pOut1)
    {
        *pOut1 = gtPeriodLight_006D6E40[nPeriod].nLight;
    }

    if (pOut2)
    {
        int nIndex = nValue * 12 / 8;
        if (bFlag)
        {
            *pOut2 = gnOutdoorLight_007A89EC[nIndex];
            return;
        }

        switch (nPeriod)
        {
        case 1:
        case 3:
            nIndex /= 2;
            break;
        case 2:
            nIndex /= 4;
            break;
        }
        *pOut2 = gnPeriodLight_007A898C[nIndex];
    }
}

struct D2B10EmitWeatherStrc
{
    char unk0x00[0x10];
    int nValue;
    char unk0x14[0x10];
    unsigned char nOut2;
};

void __cdecl sub_B10_Emit_00472FB0(D2B10EmitWeatherStrc* pWeather, unsigned char* pOut1)
{
    if (pWeather->nValue < 8 && pWeather->nValue >= 0)
    {
        sub_00472FB0_GetPeriodLight(&pWeather->nOut2, pWeather->nValue, pOut1);
    }
}

#include "gen/data/Source/D2Client/00472FB0_sub_00472FB0_GetPeriodLight.inc"
