struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
int __fastcall SEED_GetRandomValue(int nValue);                                                             // 0x00650DE0
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __stdcall sub_00476190_ResetStar(int nStar, int bRespawn);

extern D2SeedStrc* gpClientSeed_00712C4C;                                                                   // 0x00712C4C
int gnGlobal_007B8D10;                                                                                      // 0x007B8D10
int gbStarsInit_007B955C;                                                                                   // 0x007B955C
unsigned char gaStarShades_007B8D24[8];                                                                     // 0x007B8D24
int gaStarX_007B8D30[256];                                                                                  // 0x007B8D30
int gaStarY_007B57E8[256];                                                                                  // 0x007B57E8
unsigned char gaStarColor_007B5688[256];                                                                    // 0x007B5688
int gaStarSpeed_007B9130[256];                                                                              // 0x007B9130
unsigned long gdwStarTick_007B57E0;                                                                         // 0x007B57E0

#define STARS_ROLL(pSeed, lSeed) ((lSeed) = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
    (pSeed)->nHighSeed = (unsigned int)((lSeed) >> 32), (pSeed)->nLowSeed = (unsigned int)(lSeed), (unsigned int)(lSeed))

// 0x00476290
void __cdecl sub_00476290_DrawStarfield()
{
    if (!gbStarsInit_007B955C)
    {
        SEED_InitSeed(gpClientSeed_00712C4C);
        SEED_InitLowSeed(gpClientSeed_00712C4C, SEED_GetRandomValue(gnGlobal_007B8D10));

        for (int nShade = 0; nShade < 8; ++nShade)
        {
            const int nBase = nShade * 0x80 / 7 + 0x80;
            D2SeedStrc* pSeed = gpClientSeed_00712C4C;
            unsigned __int64 lSeed;
            int nRed = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nRed > 0xFF)
                nRed = 0xFF;
            int nGreen = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nGreen > 0xFF)
                nGreen = 0xFF;
            int nBlue = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nBlue > 0xFF)
                nBlue = 0xFF;
            gaStarShades_007B8D24[nShade] = sub_004FB180_FindPaletteIndex(nRed, nGreen, nBlue);
        }

        for (int i = 0; i < 256; ++i)
            sub_00476190_ResetStar(i, 0);

        gbStarsInit_007B955C = 1;
    }

    for (int i = 0; i < 256; ++i)
        D2GFX_DrawLine(gaStarX_007B8D30[i], gaStarY_007B57E8[i], gaStarX_007B8D30[i], gaStarY_007B57E8[i], gaStarColor_007B5688[i], 0xFF);

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwStarTick_007B57E0 > 40)
    {
        for (int i = 0; i < 256; ++i)
        {
            gaStarX_007B8D30[i] += gaStarSpeed_007B9130[i];
            if (gaStarX_007B8D30[i] < 0)
                sub_00476190_ResetStar(i, 1);
        }
        gdwStarTick_007B57E0 = dwTick;
    }
}

#include "gen/data/Source/D2Client/00476290_sub_00476290_DrawStarfield.inc"
