#include "D2CMP.h"

#define PAL_SATURATE(x) ((unsigned int)(x) < 255 ? (x) : 255)

struct D2PalRgba006059B0Strc;
struct D2HslStrc;
struct D2PalRgbaStrc;

unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

struct D2PalRgba006059B0Strc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

// 0x00605880
void __stdcall sub_00605880_BuildTablesA(unsigned char* pTables)
{
    unsigned int n = 0;
    if (3 > n)
    {
        do
        {
            int i = 0;
            int nAlpha;
            switch (n)
            {
            case 0:
                nAlpha = 0xBF;
                break;

            case 1:
                nAlpha = 0x7F;
                break;

            default:
                nAlpha = 0x3F;
                break;
            }

            const int nInverse = 0xFF - nAlpha;
            while (i < 256)
            {
                for (int j = 0; 256 > j; ++j)
                {
                    pTables[0x3500 + (n << 16) + j * 256 + i] = sub_00605210_FindNearestColor(pTables, 256,
                        (unsigned char)((unsigned int)(pTables[j * 4 + 0] * nInverse + pTables[i * 4 + 0] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 1] * nInverse + pTables[i * 4 + 1] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 2] * nInverse + pTables[i * 4 + 2] * nAlpha) / 255));
                }
                ++i;
            }
            ++n;
        } while (n < 3);
    }
}

// 0x006059B0
void __stdcall sub_006059B0_BuildAdditiveTable(unsigned char* pTables)
{
    const D2PalRgba006059B0Strc* pPalette = (const D2PalRgba006059B0Strc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            const unsigned char nR = (unsigned char)PAL_SATURATE(pPalette[j].nRed + pPalette[i].nRed);
            const unsigned char nG = (unsigned char)PAL_SATURATE(pPalette[j].nGreen + pPalette[i].nGreen);
            const unsigned char nB = (unsigned char)PAL_SATURATE(pPalette[j].nBlue + pPalette[i].nBlue);
            pTables[0x33500 + j * 256 + i] = sub_00605210_FindNearestColor(pTables, 256, nR, nG, nB);
        }
    }
}

double __stdcall sub_00604FE0_HueToRgb(double n1, double n2, double hue)
{
    if (hue > 360.0)
        hue -= 360.0;
    if (hue < 0.0)
        hue += 360.0;
    if (hue < 60.0)
        return n1 + (n2 - n1) * hue / 60.0;
    if (hue < 180.0)
        return n2;
    if (hue < 240.0)
        return n1 + (n2 - n1) * (240.0 - hue) / 60.0;
    return n1;
}

static __declspec(noinline) void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char nRed, nGreen, nBlue;
        if (pHsl->f_8 == 0.0)
        {
            nRed = (unsigned char)(pHsl->f_10 * 255.0);
            nGreen = nRed;
            nBlue = nRed;
        }
        else
        {
            double dM2;
            if (pHsl->f_10 <= 0.5)
            {
                dM2 = (pHsl->f_8 + 1.0) * pHsl->f_10;
            }
            else
            {
                dM2 = pHsl->f_10 + pHsl->f_8 - pHsl->f_10 * pHsl->f_8;
            }

            const double dM1 = pHsl->f_10 + pHsl->f_10 - dM2;
            nRed = (unsigned char)(sub_00604FE0_HueToRgb(dM1, dM2, pHsl->f_0 + 120.0) * 255.0);
            nGreen = (unsigned char)(sub_00604FE0_HueToRgb(dM1, dM2, pHsl->f_0) * 255.0);
            nBlue = (unsigned char)(sub_00604FE0_HueToRgb(dM1, dM2, pHsl->f_0 - 120.0) * 255.0);
        }

        pRgb->nRed = nRed;
        pRgb->nGreen = nGreen;
        pRgb->nBlue = nBlue;
        ++pRgb;
        ++pHsl;
    }
}

static __declspec(noinline) void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl)
{
    D2PalRgbaStrc tRgb[256];

    for (int i = 0; i < 256; ++i)
    {
        if (pHsl[i].f_10 != 0.0)
        {
            pHsl[i].f_10 += 0.2f;
            if (pHsl[i].f_10 > 1.0)
            {
                pHsl[i].f_10 = 1.0;
            }
        }
    }

    sub_00605080_HslToRgb(pHsl, tRgb);
    for (unsigned int i = 0; i < 256; ++i)
    {
        pTables[0x3400 + i] = sub_00605210_FindNearestColor(pTables, 256, tRgb[i].nRed, tRgb[i].nGreen, tRgb[i].nBlue);
    }
}

void __cdecl sub_M386_Emit_00606890(int nUnused, unsigned char* pTables, D2HslStrc* pHsl)
{
    sub_00606890_BuildBrightnessTable(pTables, pHsl);
}

// 0x00605F00
void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl)
{
    D2PalRgbaStrc tRgb[256];
    D2HslStrc aHsl[256];
    unsigned int i;
    unsigned int j;
    unsigned int k;

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].f_0 += dShift;
            if (aHsl[j].f_0 > 360.0)
                aHsl[j].f_0 -= 360.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x53500 + 0x100 * i + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].f_0 += dShift;
            if (aHsl[j].f_0 > 360.0)
                aHsl[j].f_0 -= 360.0;
            aHsl[j].f_8 = 0.5;
            aHsl[j].f_10 -= 0.1f;
            if (aHsl[j].f_10 < 0.0)
                aHsl[j].f_10 = 0.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (k = 0; k < 256; ++k)
            pTables[0x54D00 + 0x100 * i + k] = sub_00605210_FindNearestColor(pTables, 256, tRgb[k].nRed, tRgb[k].nGreen, tRgb[k].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].f_0 += dShift;
            if (aHsl[j].f_0 > 360.0)
                aHsl[j].f_0 -= 360.0;
            aHsl[j].f_8 = 0.5;
            aHsl[j].f_10 += 0.2f;
            if (aHsl[j].f_10 > 1.0)
                aHsl[j].f_10 = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x56500 + 0x100 * i + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].f_8 = 0.0;
        aHsl[j].f_10 *= 0.5;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57D00 + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].f_8 = 0.0;
        aHsl[j].f_10 = (aHsl[j].f_10 + 0.2f) / 1.2f;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57E00 + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (i = 0; i < 24; ++i)
    {
        for (j = 0; j < 256; ++j)
        {
            if (pHsl[j].f_0 > 45.0 && pHsl[j].f_0 < 315.0)
            {
                aHsl[j] = pHsl[j];
                aHsl[j].f_0 += (float)i * 15.0;
                if (aHsl[j].f_0 > 360.0)
                    aHsl[j].f_0 -= 360.0;
            }
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x57F00 + 0x100 * i + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 12; ++i)
    {
        const double dHue = (float)i * 30.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].f_0 = dHue;
            aHsl[j].f_8 = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x59800 + 0x100 * i + j] = sub_00605210_FindNearestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (k = 0; k < 256; ++k)
    {
        const unsigned char nGrey = (unsigned char)sqrt((double)(pTables[4 * k + 1] * pTables[4 * k + 1] + pTables[4 * k] * pTables[4 * k] + pTables[4 * k + 2] * pTables[4 * k + 2]));
        pTables[0x5A400 + k] = sub_00605210_FindNearestColor(pTables, 256, nGrey, 0, 0);
        pTables[0x5A500 + k] = sub_00605210_FindNearestColor(pTables, 256, 0, nGrey, 0);
        pTables[0x5A600 + k] = sub_00605210_FindNearestColor(pTables, 256, 0, 0, nGrey);
    }
}
