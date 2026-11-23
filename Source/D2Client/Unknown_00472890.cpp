#pragma function(memcpy)
struct D2CelFileStrc;

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* apCelFiles[4];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType); // 0x00478950
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall sub_004726F0(int nArg);                                                                       // 0x004726F0
void __cdecl sub_00472610_InitWindAngle();                                                                  // 0x00472610

extern "C" const char gszDataGlobalPath[];                                                                  // 0x006D4118
int gbWeatherResetDone;                                                                            // 0x007A8A30
int gaWeatherPhaseOffset[1];                                                                              // 0x007A8970
int gaWeatherPhaseRange[1];                                                                               // 0x007A8958
extern unsigned char gabParticleColorsDay[];                                                            // 0x007A8980
extern unsigned char gabParticleColorsTwilight[];                                                            // 0x007A894C
extern unsigned char gabParticleColorsNight[];                                                            // 0x007A89A4
extern unsigned char gabPeriodLightColors[];                                                              // 0x007A898C
unsigned char gabOutdoorLightColors[12];                                                                  // 0x007A89EC
D2WeatherLayerStateStrc gtSplashCels;                                                            // 0x007A89B0
D2WeatherLayerStateStrc gtBubbleCels;                                                            // 0x007A893C
int gaSplashFrames[4];                                                                             // 0x007A89C8
int gaBubbleFrames[4];                                                                             // 0x007A892C
float gfPhaseLevel;                                                                                // 0x007A89A0

// 0x00472890
void __fastcall sub_00472890_InitWeather(int nLevelId)
{
    sub_004726F0(1);
    if (!gbWeatherResetDone)
    {
        sub_00472610_InitWindAngle();
        gbWeatherResetDone = 1;
    }

    gaWeatherPhaseOffset[0] = 7500;
    gaWeatherPhaseOffset[1] = 250;
    gaWeatherPhaseOffset[2] = 3000;
    gaWeatherPhaseOffset[3] = 125;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 2)
        gaWeatherPhaseOffset[2] *= 3;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 4)
        gaWeatherPhaseOffset[2] *= 3;

    gaWeatherPhaseRange[0] = 7500;
    gaWeatherPhaseRange[1] = 250;
    gaWeatherPhaseRange[2] = 3000;
    gaWeatherPhaseRange[3] = 50;

    unsigned char nColor;
    int i = 0;
    int n80 = 0;
    int n24 = 0;
    for (; i < 12; ++i)
    {
        const int nStep = n80 / 12;
        nColor = 0x62 - nStep;
        gabParticleColorsDay[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 0x19, nColor);
        nColor = 0x2D - i * 40 / 12;
        gabParticleColorsTwilight[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 10, nColor);
        nColor = 0x19 - n24 / 12;
        gabParticleColorsNight[i] = sub_004FB180_FindPaletteIndex(nColor, nColor + 5, nColor);
        nColor = nStep + 0x78;
        gabPeriodLightColors[i] = sub_004FB180_FindPaletteIndex(nColor, nColor, nColor);
        nColor = nStep + 0xAA;
        gabOutdoorLightColors[i] = sub_004FB180_FindPaletteIndex(nColor, nColor, nColor);
        n24 += 24;
        n80 += 80;
    }

    char szPath[0x104];
    unsigned int nFileSize;
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain1", gszDataGlobalPath);
    gtSplashCels.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain2", gszDataGlobalPath);
    gtSplashCels.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain3", gszDataGlobalPath);
    gtSplashCels.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain4", gszDataGlobalPath);
    gtSplashCels.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gaSplashFrames[i] = CelFileGetCelsPerDirection(gtSplashCels.apCelFiles[i]);

    wsprintfA(szPath, "%s\\UncompOverlays\\bubble1", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble2", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble3", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble4", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gaBubbleFrames[i] = CelFileGetCelsPerDirection(gtBubbleCels.apCelFiles[i]);

    gfPhaseLevel = 0.0f;
}
