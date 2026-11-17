struct T00473470
{
    short bActive;
    short unk0x02;
    int nX;
    int nY;
    int nYEnd;
    int nParam;
    int unk0x14[2];
    int bDrop;
    int unk0x20;
    unsigned char nColor;
    unsigned char nAlpha;
    short unk0x26;
};

struct D2WeatherStrc
{
    char unk0x000[0x110];
    int nLastParticle;
    char unk0x114[0x08];
    T00473470* pParticles;
};

struct D2WeatherLineStrc
{
    int nX1;
    int nY1;
    int nX2;
    int nY2;
};

float __stdcall sub_0040B330_Cos(int nAngle);                                                               // 0x0040B330
float __stdcall sub_0040B350_Sin(int nAngle);                                                               // 0x0040B350
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __cdecl sub_004F5210();                                                                                 // 0x004F5210
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380

extern D2WeatherLineStrc gaWeatherLines_006D6E78[];                                                         // 0x006D6E78
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnWeatherAngle_007A89C4;                                                                         // 0x007A89C4
extern D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
extern int gbWeatherSplash_007A8A14;                                                                        // 0x007A8A14

// 0x00473470
void __cdecl sub_00473470()
{
    if (sub_004F5210())
        return;

    int nLeft = 0;
    int nRight = gnGlobal_0071146C;
    int nBottom = gnGlobal_00711470 - 47;
    switch (sub_0045AE90())
    {
    case 1:
        nRight -= gnGlobal_0071146C / 4 * 2;
        break;
    case 2:
        nLeft = gnGlobal_0071146C / 4 * 2;
        break;
    }

    T00473470* pParticle = gpWeather_007A8A04->pParticles;
    for (int i = 0; i <= gpWeather_007A8A04->nLastParticle; ++i, ++pParticle)
    {
        if (!pParticle->bActive)
            continue;

        if (gbWeatherSplash_007A8A14)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom && pParticle->nParam < 8 && pParticle->nParam >= 0)
            {
                const D2WeatherLineStrc* pLine = &gaWeatherLines_006D6E78[pParticle->nParam];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
                pLine = &gaWeatherLines_006D6E78[pParticle->nParam + 1];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
            }
        }
        else if (pParticle->bDrop)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom)
                D2GFX_DrawLine(pParticle->nX, pParticle->nY, pParticle->nX, pParticle->nY, pParticle->nColor, pParticle->nAlpha);
        }
        else
        {
            int nDX = (int)(sub_0040B330_Cos(gnWeatherAngle_007A89C4) * pParticle->nParam);
            int nDY = (int)(sub_0040B350_Sin(gnWeatherAngle_007A89C4) * pParticle->nParam);
            const int nY0 = pParticle->nY;
            const int nRange = pParticle->nYEnd - nY0;
            if (nDY > nRange)
            {
                nDX = nRange * nDX / nDY;
                nDY = nRange;
            }
            const int nX1 = pParticle->nX + nDX;
            const int nY1 = nY0 + nDY;
            if ((pParticle->nX >= nLeft && pParticle->nX < nRight && nY0 >= 0 && nY0 < nBottom)
                || (nX1 >= nLeft && nX1 < nRight && nY1 >= 0 && nY1 < nBottom))
                D2GFX_DrawLine(pParticle->nX, nY0, nX1, nY1, pParticle->nColor, pParticle->nAlpha);
        }
    }
}

#include "gen/data/Source/D2Client/00473470_sub_00473470.inc"
