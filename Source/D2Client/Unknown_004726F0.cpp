#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

static D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gnGlobal_007A8A08;                                                                               // 0x007A8A08
extern int gbWeatherSplash_007A8A14;                                                                        // 0x007A8A14
extern int gnGlobal_007A8A18;                                                                               // 0x007A8A18
extern int gbPhaseActive_007A8A1C;                                                                          // 0x007A8A1C

static __forceinline unsigned __int64 CLIENT_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue); // 0x00472590

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue)
{
    if (gnGlobal_007A8A08 && bValue)
        gnGlobal_007A8A08 = 0;
    if (gbPhaseActive_007A8A1C && !bValue)
        gbPhaseActive_007A8A1C = bValue;
    if (bValue != gbWeatherSplash_007A8A14 || bForce)
    {
        sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        D2_ASSERT(!gpWeather_007A8A04->nCount, 0x15B);
    }
    gbWeatherSplash_007A8A14 = bValue;
}

// 0x004726F0
static int __stdcall sub_004726F0(int bForce)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
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
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x70:
        gnGlobal_007A8A18 = 0;
        nChance = 0x19;
        break;
    case 0x78:
    case 0x79:
        bFlag = 1;
        gnGlobal_007A8A18 = 1;
        nChance = 0;
        break;
    case 0x75:
        gnGlobal_007A8A18 = 1;
        nChance = 0;
        break;
    }

    const int nRoll = (unsigned int)CLIENT_RollRandomNumberForceInline(&pPlayer->pSeed) % 100;
    if (nRoll < nChance && !bForce)
    {
        sub_00472590_SetSplash(0, 0);
        return 0;
    }

    gbPhaseActive_007A8A1C = bFlag;
    if (bFlag)
        sub_00473D00_SetPhase(2);
    sub_00472590_SetSplash(bForce, 1);
    return 0;
}

extern D2WeatherStrc* gpWeather_007A89FC;                                                                   // 0x007A89FC
extern D2WeatherStrc* gpWeather_007A8A00;                                                                   // 0x007A8A00
extern int gbPhaseBusy_007A8A20;                                                                            // 0x007A8A20
extern int gnPhase_007A8A24;                                                                                // 0x007A8A24

// build: context sub_00472C20_PlayerMoved

void __fastcall sub_00472C20_PlayerMoved(int nArg)
{
    sub_006BCAC0_ResetDataArray(gpWeather_007A89FC);
    sub_006BCAC0_ResetDataArray(gpWeather_007A8A00);
    if (nArg)
        sub_004726F0(nArg);
}

// build: context sub_00473DC0_ToggleWeather

void __cdecl sub_00473DC0_ToggleWeather()
{
    gbPhaseBusy_007A8A20 = !gbPhaseBusy_007A8A20;
    if (gbPhaseBusy_007A8A20)
    {
        gbPhaseActive_007A8A1C = 0;
        gnPhase_007A8A24 = 0;
        D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0x137);
        gnGlobal_007A89E0 = 0;
        sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        D2_ASSERT(!gpWeather_007A8A04->nCount, 0x15B);
    }
    else
    {
        sub_004726F0(1);
    }
}

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* apCelFiles[4];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType); // 0x00478950
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0
void __cdecl sub_00472610_InitWindAngle();                                                                  // 0x00472610

extern "C" const char gszDataGlobalPath[];                                                                  // 0x006D4118
extern int gbWeatherResetDone_007A8A30;                                                                            // 0x007A8A30
extern int gnPhaseOffset_007A8970[1];                                                                              // 0x007A8970
extern int gnPhaseRange_007A8958[1];                                                                               // 0x007A8958
extern unsigned char gnParticleColor_007A8980[];                                                            // 0x007A8980
extern unsigned char gnParticleColor_007A894C[];                                                            // 0x007A894C
extern unsigned char gnParticleColor_007A89A4[];                                                            // 0x007A89A4
extern unsigned char gnPeriodLight_007A898C[];                                                              // 0x007A898C
extern unsigned char gnOutdoorLight_007A89EC[12];                                                                  // 0x007A89EC
extern D2WeatherLayerStateStrc gtWeatherLayer_007A89B0;                                                            // 0x007A89B0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A893C;                                                            // 0x007A893C
extern int gnSplashFrames_007A89C8[4];                                                                             // 0x007A89C8
extern int gnBubbleFrames_007A892C[4];                                                                             // 0x007A892C

// build: context sub_00472890_InitWeather

void __fastcall sub_00472890_InitWeather(int nLevelId)
{
    sub_004726F0(1);
    if (!gbWeatherResetDone_007A8A30)
    {
        sub_00472610_InitWindAngle();
        gbWeatherResetDone_007A8A30 = 1;
    }

    gnPhaseOffset_007A8970[0] = 7500;
    gnPhaseOffset_007A8970[1] = 250;
    gnPhaseOffset_007A8970[2] = 3000;
    gnPhaseOffset_007A8970[3] = 125;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 2)
        gnPhaseOffset_007A8970[2] *= 3;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 4)
        gnPhaseOffset_007A8970[2] *= 3;

    gnPhaseRange_007A8958[0] = 7500;
    gnPhaseRange_007A8958[1] = 250;
    gnPhaseRange_007A8958[2] = 3000;
    gnPhaseRange_007A8958[3] = 50;

    unsigned char nColor;
    int i = 0;
    int n80 = 0;
    int n24 = 0;
    for (; i < 12; ++i)
    {
        const int nStep = n80 / 12;
        nColor = 0x62 - nStep;
        gnParticleColor_007A8980[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 0x19, nColor);
        nColor = 0x2D - i * 40 / 12;
        gnParticleColor_007A894C[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 10, nColor);
        nColor = 0x19 - n24 / 12;
        gnParticleColor_007A89A4[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 5, nColor);
        nColor = nStep + 0x78;
        gnPeriodLight_007A898C[i] = sub_004FB180_FindPaletteIndex(nColor, nColor, nColor);
        nColor = nStep + 0xAA;
        gnOutdoorLight_007A89EC[i] = sub_004FB180_FindPaletteIndex(nColor, nColor, nColor);
        n24 += 24;
        n80 += 80;
    }

    char szPath[0x104];
    unsigned int nFileSize;
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain1", gszDataGlobalPath);
    gtWeatherLayer_007A89B0.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain2", gszDataGlobalPath);
    gtWeatherLayer_007A89B0.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain3", gszDataGlobalPath);
    gtWeatherLayer_007A89B0.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain4", gszDataGlobalPath);
    gtWeatherLayer_007A89B0.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gnSplashFrames_007A89C8[i] = CelFileGetCelsPerDirection(gtWeatherLayer_007A89B0.apCelFiles[i]);

    wsprintfA(szPath, "%s\\UncompOverlays\\bubble1", gszDataGlobalPath);
    gtWeatherLayer_007A893C.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble2", gszDataGlobalPath);
    gtWeatherLayer_007A893C.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble3", gszDataGlobalPath);
    gtWeatherLayer_007A893C.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble4", gszDataGlobalPath);
    gtWeatherLayer_007A893C.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gnBubbleFrames_007A892C[i] = CelFileGetCelsPerDirection(gtWeatherLayer_007A893C.apCelFiles[i]);

    gfPhaseLevel_007A89A0 = 0.0f;
}
