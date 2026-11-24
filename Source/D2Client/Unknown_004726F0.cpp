#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

static D2WeatherStrc* gpWeatherParticles;                                                                   // 0x007A8A04
extern int gbLightningEnabled;                                                                               // 0x007A8A08
extern int gbWeatherSplash;                                                                        // 0x007A8A14
extern int gbSnowWeather;                                                                               // 0x007A8A18
extern int gbPhaseActive;                                                                          // 0x007A8A1C

static inline unsigned __int64 CLIENT_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue); // 0x00472590

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue)
{
    if (gbLightningEnabled && bValue)
        gbLightningEnabled = 0;
    if (gbPhaseActive && !bValue)
        gbPhaseActive = bValue;
    if (bValue != gbWeatherSplash || bForce)
    {
// build: symbol ?DATAARRAYS_Reset@* 0x006BCAC0
        DATAARRAYS_Reset(gpWeatherParticles);
        D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
    }
    gbWeatherSplash = bValue;
}

// 0x004726F0
static int __stdcall sub_004726F0(int bForce)
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
        gbSnowWeather = 1;
        nChance = 0;
        break;
    case LEVEL_TUNDRAWASTELANDS:
        gbSnowWeather = 1;
        nChance = 0;
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

extern D2WeatherStrc* gpWeatherSplashes;                                                                   // 0x007A89FC
extern D2WeatherStrc* gpWeatherBubbles;                                                                   // 0x007A8A00
extern int gbPhaseBusy;                                                                            // 0x007A8A20
extern int gnPhase;                                                                                // 0x007A8A24

// build: context sub_00472C20_PlayerMoved

void __fastcall sub_00472C20_PlayerMoved(int nArg)
{
    DATAARRAYS_Reset(gpWeatherSplashes);
    DATAARRAYS_Reset(gpWeatherBubbles);
    if (nArg)
        sub_004726F0(nArg);
}

void __cdecl sub_00473DC0_ToggleWeather(); // 0x00473DC0

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* apCelFiles[4];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType); // 0x00478950
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0
void __cdecl sub_00472610_InitWindAngle();                                                                  // 0x00472610

extern "C" const char gszDataGlobalPath[];                                                                  // 0x006D4118
extern int gbWeatherResetDone;                                                                            // 0x007A8A30
extern int gaWeatherPhaseOffset[1];                                                                              // 0x007A8970
extern int gaWeatherPhaseRange[1];                                                                               // 0x007A8958
extern unsigned char gabParticleColorsDay[];                                                            // 0x007A8980
extern unsigned char gabParticleColorsTwilight[];                                                            // 0x007A894C
extern unsigned char gabParticleColorsNight[];                                                            // 0x007A89A4
extern unsigned char gabPeriodLightColors[];                                                              // 0x007A898C
extern unsigned char gabOutdoorLightColors[12];                                                                  // 0x007A89EC
extern D2WeatherLayerStateStrc gtSplashCels;                                                            // 0x007A89B0
extern D2WeatherLayerStateStrc gtBubbleCels;                                                            // 0x007A893C
extern int gaSplashFrames[4];                                                                             // 0x007A89C8
extern int gaBubbleFrames[4];                                                                             // 0x007A892C

void __fastcall sub_00472890_InitWeather(int nLevelId); // 0x00472890
