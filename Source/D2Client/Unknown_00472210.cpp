#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct CellResource;
union D2SeedStrc;
struct D2WeatherSplashStrc;
struct D2PeriodLightStrc;
struct D2B10EmitWeatherStrc;

extern "C" double __cdecl fabs(double x);

D2WeatherStrc* __fastcall DATAARRAYS_Create(const char* szName, int nCount, int nRecordSize); // 0x006BCA10
void __fastcall DATAARRAYS_Destroy(void* pBlock); // 0x006BCA90
void __fastcall DATAARRAYS_Initialize(D2WeatherStrc* pArray); // 0x006BCCC0
int __stdcall sub_004726F0(int nArg); // 0x004726F0
extern int gbLightningFlash; // 0x007A896C
extern int gnGlobal_007A8A0C; // 0x007A8A0C
extern int gnLightningFlashFrames; // 0x007A89E8
extern int gaSplashFrames[]; // 0x007A89C8
extern int gaBubbleFrames[]; // 0x007A892C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00473D00_SetPhase(int nPhase); // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern int gbLightningEnabled; // 0x007A8A08
extern int gnLightningCountdown; // 0x007A8968

int __cdecl sub_004F5140(); // 0x004F5140
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634
extern const D2PeriodLightStrc gaPeriodLights[]; // 0x006D6E40
extern unsigned char gabOutdoorLightColors[]; // 0x007A89EC

struct D2B10EmitWeatherStrc
{
    char unk0x00[0x10];
    int nValue;
    char unk0x14[0x10];
    unsigned char nOut2;
};

extern int gScreenWidth; // 0x0071146C
extern CellResource* gHelpBorder;
extern CellResource* gWhiteBullet;
extern CellResource* gYellowBullet;
int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" void __stdcall D2GFX_DrawBox(int x1, int y1, int x2, int y2, int color, int mode); // 0x004F6300
extern "C" int __cdecl ResolutionMode();
extern "C" void __fastcall ReleaseCell(CellResource* resource);
extern "C" CellResource* __fastcall LoadCell(const char* filename);
extern "C" const char gHelpBorder800File[];
extern "C" const char gHelpBorderFile[];
extern "C" const char gWhiteBulletFile[];
extern "C" const char gYellowBulletFile[];
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400
extern unsigned int gnPhaseMax; // 0x007A89C0
extern int gbPhaseActive; // 0x007A8A1C
extern int gbPhaseBusy; // 0x007A8A20
extern int gnPhase; // 0x007A8A24

inline unsigned __int64 SEED_RollRandomNumberInline_00472210(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472210
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollRandomNumberInline_00472210(pSeed) & (nMax - 1);
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472240
int __fastcall sub_00472240_RollMaskOffset(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return (SEED_RollRandomNumberInline(pSeed) & (nRange - 1)) + nOffset;
}

// 0x004722F0
float __stdcall sub_004722F0_AbsFloatStd(float fValue)
{
    return (float)fabs(fValue);
}

// 0x00472310
float __cdecl sub_00472310_AbsFloat(float fValue)
{
    return (float)fabs(fValue);
}

__forceinline unsigned int RNG_RollLimitedRef(D2SeedStrc* pSeed, const int& nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumberInline(pSeed);
    const int nMask = nMax;
    return nRoll & (nMask - 1);
}

// 0x00472280
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return nOffset + RNG_RollLimitedRef(pSeed, nRange);
}

static D2WeatherStrc* gpWeatherParticles; // 0x007A8A04

static D2WeatherStrc* gpWeatherSplashes; // 0x007A89FC

static D2WeatherStrc* gpWeatherBubbles; // 0x007A8A00

int gnBaseWindAngleMin; // 0x007A89DC

int gnBaseWindAngleMax; // 0x007A899C

int gbLightningEnabled; // 0x007A8A08

int gnViewDeltaX; // 0x007A0678

int gnViewDeltaY; // 0x007A067C

// 0x00472320
void __cdecl sub_00472320()
{
    gpWeatherParticles = DATAARRAYS_Create("Environment Particles", 0x100, 0x28);
    DATAARRAYS_Initialize(gpWeatherParticles);
// build: symbol ?gnPhaseLevel@* 0x007A89E0
    gnPhaseLevel = 0;
    gpWeatherSplashes = DATAARRAYS_Create("Environment Splashes", 0x200, 0x18);
    DATAARRAYS_Initialize(gpWeatherSplashes);
    gpWeatherBubbles = DATAARRAYS_Create("Environment Bubbles", 0x80, 0x18);
    DATAARRAYS_Initialize(gpWeatherBubbles);
    gnBaseWindAngleMin = 0x2A;
// build: symbol ?gnWindAngleMin@* 0x007A89D8
    gnWindAngleMin = 0x2A;
    gbLightningFlash = 0;
    gbLightningEnabled = 0;
    gnGlobal_007A8A0C = 0;
    gnBaseWindAngleMax = 0xAA;
// build: symbol ?gnWindAngleMax@* 0x007A8998
    gnWindAngleMax = 0xAA;
}

// 0x004723C0
void __cdecl sub_004723C0()
{
    DATAARRAYS_Destroy(gpWeatherParticles);
    DATAARRAYS_Destroy(gpWeatherSplashes);
    DATAARRAYS_Destroy(gpWeatherBubbles);
}

// 0x00472C20
void __fastcall sub_00472C20_PlayerMoved(int nArg)
{
// build: symbol ?DATAARRAYS_Reset@* 0x006BCAC0
    DATAARRAYS_Reset(gpWeatherSplashes);
    DATAARRAYS_Reset(gpWeatherBubbles);
    if (nArg)
        sub_004726F0(nArg);
}

// 0x00472C50
void __fastcall sub_00472C50(int nArg)
{
    if (!gbLightningEnabled)
    {
        gbLightningEnabled = 1;
        gnLightningFlashFrames = 1;
        gbLightningFlash = 0;
// build: symbol ?gbPlayThunderSound@* 0x00712B4C
        gbPlayThunderSound = nArg;
    }
}

// 0x00472C80
void __fastcall sub_00472C80_StepSplashes(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeatherSplashes->pRecords;
    for (int i = 0; i <= gpWeatherSplashes->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX;
            pSplash->nY -= gnViewDeltaY;
        }

        pSplash->nFrameDelay -= 1;
        if (pSplash->nFrameDelay <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->nFrameDelay = 2;
            if (pSplash->nFrame >= gaSplashFrames[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeatherSplashes, i << 16);
        }
    }
}

// 0x00472D10
void __fastcall sub_00472D10_StepBubbles(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeatherBubbles->pRecords;
    for (int i = 0; i <= gpWeatherBubbles->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX;
            pSplash->nY -= gnViewDeltaY;
        }

        pSplash->nFrameDelay -= 1;
        if (pSplash->nFrameDelay <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->nFrameDelay = 2;
            if (pSplash->nFrame >= gaBubbleFrames[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeatherBubbles, i << 16);
        }
    }
}

int gbWeatherSplash; // 0x007A8A14

int gbSnowWeather; // 0x007A8A18

int gbPhaseActive; // 0x007A8A1C

static inline unsigned __int64 CLIENT_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472590
static void __stdcall sub_00472590_SetSplash(int bForce, int bValue)
{
    if (gbLightningEnabled && bValue)
        gbLightningEnabled = 0;
    if (gbPhaseActive && !bValue)
        gbPhaseActive = bValue;
    if (bValue != gbWeatherSplash || bForce)
    {
        DATAARRAYS_Reset(gpWeatherParticles);
        D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
    }
    gbWeatherSplash = bValue;
}

int __stdcall sub_004726F0(int bForce)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
        return 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        sub_00472590_SetSplash(0, 0);
        sub_00472610();
        return 0;
    }

    sub_00472610();
    int bFlag = 0;
    int nChance = 0;
    switch (nLevelId)
    {
    case LEVEL_HARROGATH:
    case LEVEL_BLOODYFOOTHILLS:
    case LEVEL_ID_ACT5_BARRICADE_1:
    case LEVEL_ARREATPLATEAU:
        gbSnowWeather = 0;
        nChance = 0x19;
        break;
    case LEVEL_ROCKYSUMMIT:
    case LEVEL_NIHLATHAKSTEMPLE:
        bFlag = 1;

    case LEVEL_TUNDRAWASTELANDS:
        gbSnowWeather = 1;
        break;
    }

    const int nRoll = (unsigned int)CLIENT_RollRandomNumberForceInline(&pPlayer->pSeed) % 100;
    if (nRoll < nChance && !bForce)
    {
        sub_00472590_SetSplash(0, 0);
        return 0;
    }

    gbPhaseActive = bFlag;
    if (bFlag)
        sub_00473D00_SetPhase(2);
    sub_00472590_SetSplash(bForce, 1);
    return 0;
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00472610
void __cdecl sub_00472610_InitWindAngle()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2SeedStrc tSeed;
// build: symbol ?gnWindCountdown@* 0x007A89E4
        gnWindCountdown = SEED_RollFromInline(&pPlayer->pSeed, &tSeed) % 375 + 125;
        gnLightningCountdown = SEED_RollLowInline(&tSeed) % 1500 + 500;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pPlayer->pSeed.nHighSeed = tSeed.nHighSeed;
        pPlayer->pSeed.nLowSeed = tSeed.nLowSeed;
        const int nAngle = nRoll % 71 + 92;
// build: symbol ?gnWeatherAngle@* 0x007A89C4
        gnWeatherAngle = nAngle;
// build: symbol ?gnTargetAngle@* 0x007A89F8
        gnTargetAngle = nAngle;
    }
    else
    {
        gnWindCountdown = 0x138;
        gnLightningCountdown = 0x4E2;
        gnWeatherAngle = 0x7F;
        gnTargetAngle = 0x7F;
    }
}

unsigned char gabPeriodLightColors[12]; // 0x007A898C

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

    DUNGEON_GetLevelIdFromRoom(CUNIT_GetPlayerRoom());
    int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x356);

    if (pOut1)
    {
        *pOut1 = gaPeriodLights[nPeriod].nLight;
    }

    if (pOut2)
    {
        int nIndex = nValue * 12 / 8;
        if (bFlag)
        {
            *pOut2 = gabOutdoorLightColors[nIndex];
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
        *pOut2 = gabPeriodLightColors[nIndex];
    }
}

void __cdecl sub_B10_Emit_00472FB0(D2B10EmitWeatherStrc* pWeather, unsigned char* pOut1)
{
    if (pWeather->nValue < 8 && pWeather->nValue >= 0)
    {
        sub_00472FB0_GetPeriodLight(&pWeather->nOut2, pWeather->nValue, pOut1);
    }
}

#include "gen/data/Source/D2Client/Unknown_00472210.inc"
struct D2ActiveRoomStrc;

// 0x004736C0
extern "C" void __cdecl sub_004736C0_DrawPanelShade()
{
    int left = 0;
    int bottom = gnScreenHeight - 47;
    int right = gScreenWidth;
    switch (sub_0045AE90())
    {
    case 1:
        right -= (gScreenWidth / 4) * 2;
        break;
    case 2:
        left = (gScreenWidth / 4) * 2;
        break;
    }
    D2GFX_DrawBox(left, 0, right, bottom, 255, 5);
}

// 0x00473720
static inline void sub_00473720_GetLevelWeather(int* pRain, int* pMud)
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    *pRain = 0;
    *pMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        *pRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        *pMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
}

int __cdecl sub_M112_Emit_00473720()
{
    int nRain;
    int nMud;
    sub_00473720_GetLevelWeather(&nRain, &nMud);
    return nRain + nMud;
}

// 0x00473CA0
void __cdecl sub_00473CA0_Empty()
{
}

// 0x00473CB0
void __cdecl sub_00473CB0_Nop()
{
}

// 0x00473CC0
void __cdecl sub_00473CC0_Nop()
{
}

// 0x00473CD0
void __cdecl sub_00473CD0_Nop()
{
}

// 0x00473D00
void __fastcall sub_00473D00_SetPhase(int nPhase)
{
    D2_ASSERT(nPhase >= 0 && nPhase <= 3, 0x12A);

    if (gbPhaseBusy && nPhase != 0)
    {
        return;
    }

    if (gbPhaseActive && nPhase != 2)
    {
        return;
    }

    gnPhase = nPhase;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x137);

    switch (nPhase)
    {
    case 0:
        gnPhaseLevel = 0;
        break;

    case 1:
        sub_004726F0(0);
        gnPhaseMax = sub_00472280(&pPlayer->pSeed, 0x20, 0xE0);
        break;

    case 2:
        sub_00472400_ResetPhaseState();
        break;

    case 3:
        gbLightningEnabled = 0;
        break;
    }
}

int gbPhaseBusy; // 0x007A8A20

// 0x00473DC0
void __cdecl sub_00473DC0_ToggleWeather()
{
    gbPhaseBusy = !gbPhaseBusy;
    if (gbPhaseBusy)
    {
        gbPhaseActive = 0;
        gnPhase = 0;
        D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0x137);
        gnGlobal_007A89E0 = 0;
        DATAARRAYS_Reset(gpWeatherParticles);
        D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
    }
    else
    {
        sub_004726F0(1);
    }
}
