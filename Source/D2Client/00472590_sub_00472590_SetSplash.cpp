extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc tSeed;
};

struct D2WeatherStrc
{
    char unk0x000[0x114];
    int unk0x114;
};

struct D2ActiveRoomStrc;

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __cdecl sub_00472610();                                                                                // 0x00472610
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_006BCAC0_ResetDataArray(D2WeatherStrc* pArray);                                         // 0x006BCAC0

static D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gnGlobal_007A8A08;                                                                               // 0x007A8A08
int gbWeatherSplash_007A8A14;                                                                               // 0x007A8A14
int gnGlobal_007A8A18;                                                                                      // 0x007A8A18
int gbPhaseActive_007A8A1C;                                                                                 // 0x007A8A1C

static __forceinline unsigned __int64 CLIENT_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472590
static void __stdcall sub_00472590_SetSplash(int bForce, int bValue)
{
    if (gnGlobal_007A8A08 && bValue)
        gnGlobal_007A8A08 = 0;
    if (gbPhaseActive_007A8A1C && !bValue)
        gbPhaseActive_007A8A1C = bValue;
    if (bValue != gbWeatherSplash_007A8A14 || bForce)
    {
        sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        D2_ASSERT(!gpWeather_007A8A04->unk0x114, 0x15B);
    }
    gbWeatherSplash_007A8A14 = bValue;
}

int __stdcall sub_004726F0(int bForce)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
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

    case 0x75:
        gnGlobal_007A8A18 = 1;
        break;
    }

    const int nRoll = (unsigned int)CLIENT_RollRandomNumberForceInline(&pPlayer->tSeed) % 100;
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
