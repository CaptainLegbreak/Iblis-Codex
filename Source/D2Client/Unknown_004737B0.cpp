#include "D2Client.h"
#include "D2Structs.h"



struct D2WeatherStrc
{
    char unk0x000[0x110];
    int nLastParticle;
    int nCount;
    char unk0x118[0x04];
    T00473470* pParticles;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" double __cdecl fabs(double x);

int __cdecl sub_004F5140();                                                                                 // 0x004F5140
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall sub_006BCB40(D2WeatherStrc* pArray);                                             // 0x006BCB40
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
unsigned int __cdecl sub_0044DB00();                                                                        // 0x0044DB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_00472C80_StepSplashes(int nUnused);                                                     // 0x00472C80
void __fastcall sub_00472D10_StepBubbles(int nUnused);                                                      // 0x00472D10
void __stdcall sub_00473E50_StepPhase(D2SeedStrc* pSeed);                                                   // 0x00473E50
extern D2DrlgActStrc* gpDrlgAct_007A0634;                                                                   // 0x007A0634
extern const D2PeriodLightStrc gtPeriodLight_006D6E40[];                                                    // 0x006D6E40
extern unsigned char gnOutdoorLight_007A89EC[];                                                             // 0x007A89EC
extern unsigned char gnPeriodLight_007A898C[];                                                              // 0x007A898C
unsigned char gnParticleColor_007A894C[12];                                                                 // 0x007A894C
unsigned char gnParticleColor_007A8980[12];                                                                 // 0x007A8980
unsigned char gnParticleColor_007A89A4[12];                                                                 // 0x007A89A4
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
D2WeatherStrc* gpWeather_007A8A04;                                                                          // 0x007A8A04
extern D2WeatherStrc* gpWeather_007A89FC;                                                                   // 0x007A89FC
extern D2WeatherStrc* gpWeather_007A8A00;                                                                   // 0x007A8A00
static int gbWeatherSplash_007A8A14;                                                                        // 0x007A8A14
static int gnGlobal_007A8A18;                                                                               // 0x007A8A18
extern int gnViewDeltaX_007A0678;                                                                           // 0x007A0678
extern int gnViewDeltaY_007A067C;                                                                           // 0x007A067C
unsigned int gnWeatherTick_007A8A34;                                                                        // 0x007A8A34
extern int gnGlobal_007A8A08;                                                                               // 0x007A8A08
extern int gnGlobal_007A8968;                                                                               // 0x007A8968
extern int gnGlobal_007A89E8;                                                                               // 0x007A89E8
extern unsigned int gnLastTick_007A8A0C;                                                                    // 0x007A8A0C
extern int gbRainActive_007A8A44;                                                                           // 0x007A8A44
extern int gbMudActive_007A8A40;                                                                            // 0x007A8A40

// build: context sub_U01_RollSeedInline
static __forceinline unsigned __int64 sub_U01_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

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

static __declspec(noinline) void sub_00473090_InitParticle(D2SeedStrc* pSeed);

// 0x00473090
static void sub_00473090_InitParticle(D2SeedStrc* pSeed)
{
    const int nRecord = sub_006BCB40(gpWeather_007A8A04);
    if (nRecord == -1)
    {
        return;
    }

    T00473470* pParticle = &gpWeather_007A8A04->pParticles[(short)(nRecord >> 0x10)];
    pParticle->bDrop = 0;
    pParticle->nX = sub_00472280(pSeed, 0, gnGlobal_0071146C);
    pParticle->nYEnd = sub_00472280(pSeed, 0x28, gnGlobal_00711470 - 0x57);
    pParticle->nY = sub_00472280(pSeed, -0x14, pParticle->nYEnd + 0x14);
    pParticle->nFrame = (unsigned int)sub_U01_RollSeedInline(pSeed) & 0x1FF;

    const float fRatio = (float)(pParticle->nYEnd - 0x28) / (gnGlobal_00711470 - 0x57);
    if (gbWeatherSplash_007A8A14)
    {
        pParticle->nAlpha = 0xFF;
        unsigned char* pAlpha = &pParticle->nAlpha;
        sub_U01_RollSeedInline(pSeed);
        pParticle->nType = 1;
        pParticle->nParam2 = 8 - (int)(fRatio * -28.0);
        pParticle->nParam = 7 * (pParticle->nYEnd - 0x28) / (gnGlobal_00711470 - 0x57);
        if (gnGlobal_007A8A18)
        {
            ++pParticle->nParam;
        }

        D2_ASSERT(pParticle->nParam < 8 && pParticle->nParam >= 0, 0x390);
        sub_00472FB0_GetPeriodLight(&pParticle->nColor, pParticle->nParam, pAlpha);
        return;
    }

    const unsigned int nColor = (unsigned int)sub_U01_RollSeedInline(pSeed) % 12;
    switch (ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0))
    {
    case 2:
        pParticle->nColor = gnParticleColor_007A89A4[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 1:
    case 3:
        pParticle->nColor = gnParticleColor_007A894C[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 0:
        pParticle->nColor = gnParticleColor_007A8980[nColor];
        pParticle->nAlpha = 0x7F;
        break;
    }

    pParticle->nParam = 4 - (int)(fRatio * -8.0);
    pParticle->nParam2 = 0xF - (int)(fRatio * -15.0);
    pParticle->nType = 3;
}

void __stdcall sub_004732C0_StepParticles(D2SeedStrc* pSeed);                                              // 0x004732C0

// 0x004737B0
static void sub_004737B0_StepWind(D2SeedStrc* pSeed)
{
    while (gpWeather_007A8A04->nCount < gnPhaseLevel_007A89E0)
    {
        sub_00473090_InitParticle(pSeed);
    }

    const int nTarget = gnTargetAngle_007A89F8;
    int nAngle = gnWeatherAngle_007A89C4;
    const int bSplash = gbWeatherSplash_007A8A14;
    const int nStep = bSplash ? 1 : 2;
    if (nTarget < nAngle)
    {
        nAngle -= nStep;
        if (nTarget > nAngle)
            gnWeatherAngle_007A89C4 = nTarget;
        else
            gnWeatherAngle_007A89C4 = nAngle;
    }
    else if (nTarget > nAngle)
    {
        const int nNew = nAngle + nStep;
        gnWeatherAngle_007A89C4 = nTarget;
        if (nTarget >= nNew)
            gnWeatherAngle_007A89C4 = nNew;
    }

    if (!--gnWindCountdown_007A89E4)
    {
        if (bSplash)
        {
            gnWindCountdown_007A89E4 = (unsigned int)sub_U01_RollSeedInline(pSeed) % 875 + 250;
            gnTargetAngle_007A89F8 = sub_00472280(pSeed, gnGlobal_007A89D8, gnGlobal_007A8998);
        }
        else
        {
            unsigned __int64 lSeed1 = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
            gnWindCountdown_007A89E4 = (unsigned int)lSeed1 % 375 + 125;
            unsigned __int64 lSeed2 = (lSeed1 >> 32) + 0x6AC690C5i64 * (unsigned int)lSeed1;
            pSeed->nHighSeed = (unsigned int)(lSeed2 >> 32);
            pSeed->nLowSeed = (unsigned int)lSeed2;
            gnTargetAngle_007A89F8 = (unsigned int)lSeed2 % 71 + 92;
        }
    }

    if (gnGlobal_007A8A08 && !--gnGlobal_007A8968)
    {
        gnGlobal_007A89E8 = 1;
    }
}

// 0x00473F50

void __cdecl sub_00473F50_UpdateWeather()
{
    int nLevelId;
    int bRain;
    int bMud;
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetPlayerUnit();
    bRain = 0;
    bMud = 0;
    if (pStoredUnit)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pStoredUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }

    if (!bRain && gbRainActive_007A8A44)
    {
        if (gpWeather_007A8A04->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        }

        if (gpWeather_007A89FC->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A89FC);
        }
    }

    if (!bMud && gbMudActive_007A8A40)
    {
        if (gpWeather_007A8A00->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A8A00);
        }
    }

    gbRainActive_007A8A44 = bRain;
    gbMudActive_007A8A40 = bMud;

    const unsigned int nTick = sub_0044DB00();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x547);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (nTick <= gnLastTick_007A8A0C)
    {
        return;
    }

    gnLastTick_007A8A0C = nTick;
    if (bRain)
    {
        if (gpWeather_007A8A04->nCount)
        {
            sub_004732C0_StepParticles(pSeed);
        }

        sub_00472C80_StepSplashes((int)pSeed);
        sub_00473E50_StepPhase(pSeed);
        sub_004737B0_StepWind(pSeed);
    }
    else
    {
        gfPhaseLevel_007A89A0 = 0.0f;
    }

    if (bMud)
    {
        sub_00472D10_StepBubbles((int)pSeed);
    }
}
