struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
};

struct D2WeatherStrc
{
    char unk0x000[0x114];
    int unk0x114;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004B99A0_MoveSound(int a1, int a2, int a3, int a4);                                     // 0x004B99A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId);                                        // 0x0061DBA0
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId);                                         // 0x0061DC20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
extern "C" void __cdecl sub_004736C0_DrawPanelShade();                                                      // 0x004736C0
void __cdecl sub_00473470();                                                               // 0x00473470

extern D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gnGlobal_00712B4C;                                                                               // 0x00712B4C
int gnGlobal_007A8968;                                                                                      // 0x007A8968
int gnGlobal_007A896C;                                                                                      // 0x007A896C
int gnGlobal_007A89E8;                                                                                      // 0x007A89E8
extern int gnGlobal_007A8A08;                                                                               // 0x007A8A08
extern unsigned int gdwGlobal_007BB390;                                                                     // 0x007BB390

// 0x00473910
void __cdecl sub_00473910_UpdateWeather()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x573);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (gnGlobal_007A8A08 && gnGlobal_007A89E8)
    {
        gnGlobal_007A89E8 -= 1;
        if (!gnGlobal_007A89E8)
        {
            if (!gnGlobal_007A896C)
            {
                gnGlobal_007A8968 = 3;
                gnGlobal_007A896C = 1;
            }
            else
            {
                gnGlobal_007A8968 = sub_00472280(pSeed, 500, 1500);
                gnGlobal_007A896C = 0;
                if (gnGlobal_00712B4C)
                {
                    const int nDelay = sub_00472280(pSeed, 25, 50);
                    const int hSound = sub_004B9A00(0xCA, 0, nDelay, 0, 0);
                    if (hSound)
                    {
                        sub_004B99A0_MoveSound(hSound, sub_00472280(pSeed, -200, 400), sub_00472280(pSeed, -200, 400), 0);
                    }
                }
                else
                {
                    gnGlobal_00712B4C = 1;
                }
            }
        }

        if (gdwGlobal_007BB390 >= 10)
        {
            sub_004736C0_DrawPanelShade();
            return;
        }
    }

    if (bRain && gpWeather_007A8A04->unk0x114)
    {
        sub_00473470();
    }
}

#include "gen/data/Source/D2Client/00473910_sub_00473910_UpdateWeather.inc"
