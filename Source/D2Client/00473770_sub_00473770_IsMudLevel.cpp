struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2WeatherLayerStateStrc;

struct D2WeatherStrc
{
    char unk0x000[0x114];
    int bActive;
};

D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId);                                        // 0x0061DBA0
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId);                                         // 0x0061DC20
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState);                     // 0x00473A70

extern D2WeatherStrc* gpWeather_007A89FC;                                                                   // 0x007A89FC
extern D2WeatherStrc* gpWeather_007A8A00;                                                                   // 0x007A8A00
extern D2WeatherLayerStateStrc gtWeatherLayer_007A89B0;                                                     // 0x007A89B0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A893C;                                                     // 0x007A893C
extern int gbWeatherSplash_007A8A14;                                                                        // 0x007A8A14
extern float gfPhaseLevel_007A89A0;                                                                         // 0x007A89A0
int gnGlobal_007A8A10;                                                                                      // 0x007A8A10

// 0x00473770
int __cdecl sub_00473770_IsMudLevel()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
    int bMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        DATATBLS_GetRainFromLevelsTxt(nLevelId);
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
    return bMud;
}

// 0x00473C00
void __cdecl sub_00473C00_DrawWeatherLayers()
{
    if (gpWeather_007A89FC->bActive)
    {
        sub_00473A70(gpWeather_007A89FC, &gtWeatherLayer_007A89B0);
    }
    if (gpWeather_007A8A00->bActive)
    {
        sub_00473A70(gpWeather_007A8A00, &gtWeatherLayer_007A893C);
    }
}

// 0x00473C40
int __cdecl sub_00473C40_IsRainLevel()
{
    if (gbWeatherSplash_007A8A14)
    {
        return 0;
    }
    D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }
    return bRain;
}

// 0x00473C80
float __cdecl sub_00473C80_GetPhaseLevel()
{
    return gfPhaseLevel_007A89A0;
}

// 0x00473C90
void __fastcall sub_00473C90_SetGlobal(int nValue)
{
    gnGlobal_007A8A10 = nValue;
}

// 0x00473CE0
void __cdecl sub_00473CE0_Nop()
{
}

// 0x00473CF0
void __cdecl sub_00473CF0_Nop()
{
}
