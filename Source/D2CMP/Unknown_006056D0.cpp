#include "D2CMP.h"
#include "D2ColorBlock.h"

static void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl);


#define PAL_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HslStrc;

struct D2PalRgbaStrc;

struct D2ColorBlockStrc;

extern unsigned char gaPcxPalette[256 * 4]; // 0x008E9938

typedef unsigned char (__stdcall* MapFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

unsigned char __stdcall Palette24BitTo8BitPixel(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x006056D0

extern int gbPaletteLoaded; // 0x008E9934

unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210


extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern const D2ColorBlockStrc gtColorBlock; // 0x007434D8

double __stdcall PaletteHueToRgb(double n1, double n2, double hue); // 0x00604FE0

void __stdcall PaletteBuildTintTables(unsigned char* pData); // 0x00605D20

void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData); // 0x00605DE0

void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData); // 0x00605E60

void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize);

void __stdcall PaletteBuildAlphaTables(unsigned char* pTables); // 0x00605880

void __stdcall PaletteBuildAdditiveTable(unsigned char* pData); // 0x006059B0

void __stdcall sub_00605AA0_BuildTablesC(unsigned char* pTables);

void __stdcall sub_00605B70_BuildTablesD(unsigned char* pTables);

void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl);

unsigned int gnPaletteStart; // 0x008E9930

unsigned int gnPaletteEnd; // 0x008E902C

int gbTableSet; // 0x008E9D40

unsigned char gabPaletteMask[0x100]; // 0x008E9830

int gbPaletteTestBackground; // 0x008E9028

unsigned int gdwSwappedColor; // 0x008E9D38

int ganSquareTable[511]; // 0x008E9034

int gbDarkTest; // 0x008E9D3C

// 0x00605AA0
void __stdcall sub_00605AA0_BuildMultiplyTable(unsigned char* pTables)
{
    const D2PalRgbaStrc* pPalette = (const D2PalRgbaStrc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            pTables[0x43500 + j * 256 + i] = GetClosestColor(pTables, 256,
                (unsigned char)((unsigned int)(pPalette[j].nRed * pPalette[i].nRed) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nGreen * pPalette[i].nGreen) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nBlue * pPalette[i].nBlue) / 255));
        }
    }
}

// 0x00605B70
void __stdcall sub_00605B70_BuildBlendTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        unsigned char nC0 = pData[i * 4 + 0];
        unsigned char nC1 = pData[i * 4 + 1];
        unsigned char nC2 = pData[i * 4 + 2];

        if (nC0 > 0)
        {
            nC0 += nC0 / -3;
        }

        if (nC2 > 0)
        {
            nC2 += nC2 / -3;
        }

        if (nC1 > 0)
        {
            nC1 += nC1 / -3;
        }

        pData[0x6B500 + i] = GetClosestColor(pData, 256, nC0, nC1, nC2);
    }

    for (unsigned int j = 0; j < 256; ++j)
    {
        const unsigned int nMax = PAL_MAX(PAL_MAX(pData[j * 4 + 0], pData[j * 4 + 1]), pData[j * 4 + 2]);
        const unsigned int nInv = 255 - nMax;
        for (unsigned int k = 0; k < 256; ++k)
        {
            pData[0x5B500 + k * 256 + j] = GetClosestColor(pData, 256,
                (unsigned char)((pData[j * 4 + 0] * nMax + pData[k * 4 + 0] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 1] * nMax + pData[k * 4 + 1] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 2] * nMax + pData[k * 4 + 2] * nInv) / 255));
        }
    }
}

// 0x00605E60
void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 16; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x2400 + i * 256 + j] = GetClosestColor(pData, 256,
                pData[j * 4 + 0] + ((0xFF - pData[j * 4 + 0]) * (i + 1) >> 4),
                pData[j * 4 + 1] + ((0xFF - pData[j * 4 + 1]) * (i + 1) >> 4),
                pData[j * 4 + 2] + ((0xFF - pData[j * 4 + 2]) * (i + 1) >> 4));
        }
    }
}

static void sub_00604DF0_RgbToHsl(const unsigned char* pRgb, D2HslStrc* pHsl)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        const double dRed = pRgb[0] / 255.0;
        const double dGreen = pRgb[1] / 255.0;
        const double dBlue = pRgb[2] / 255.0;
        double dMax = dRed > dGreen ? dRed : dGreen;
        if (dBlue > dMax)
        {
            dMax = dBlue;
        }

        double dMin = dRed < dGreen ? dRed : dGreen;
        if (dBlue < dMin)
        {
            dMin = dBlue;
        }

        const double dLightness = (dMax + dMin) * 0.5;
        double dHue = 0.0;
        double dSaturation = 0.0;
        if (dMax != dMin)
        {
            const double dDelta = dMax - dMin;
            dSaturation = dLightness <= 0.5 ? dDelta / (dMax + dMin) : dDelta / (2.0 - dMax - dMin);
            if (dRed == dMax)
            {
                dHue = (dGreen - dBlue) / dDelta;
            }
            else if (dGreen == dMax)
            {
                dHue = (dBlue - dRed) / dDelta + 2.0;
            }
            else
            {
                dHue = (dRed - dGreen) / dDelta + 4.0;
            }

            dHue *= 60.0;
            if (dHue < 0.0)
            {
                dHue += 360.0;
            }
        }

        pHsl->dHue = dHue;
        pHsl->dSaturation = dSaturation;
        pHsl->dLightness = dLightness;
        pRgb += 4;
        ++pHsl;
    }
}

static void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char nRed, nGreen, nBlue;
        if (pHsl->dSaturation == 0.0)
        {
            nRed = nGreen = nBlue = (unsigned char)(pHsl->dLightness * 255.0);
        }
        else
        {
            double dM2;
            if (pHsl->dLightness <= 0.5)
            {
                dM2 = (pHsl->dSaturation + 1.0) * pHsl->dLightness;
            }
            else
            {
                dM2 = pHsl->dLightness + pHsl->dSaturation - pHsl->dLightness * pHsl->dSaturation;
            }

            const double dM1 = pHsl->dLightness + pHsl->dLightness - dM2;
            nRed = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue + 120.0) * 255.0);
            nGreen = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue) * 255.0);
            nBlue = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue - 120.0) * 255.0);
        }

        pRgb->nRed = nRed;
        pRgb->nGreen = nGreen;
        pRgb->nBlue = nBlue;
        ++pHsl;
        ++pRgb;
    }
}

#define PAL_SATURATE(x) ((unsigned int)(x) < 255 ? (x) : 255)
// build: symbol ?PaletteHueToRgb@* 0x00604FE0
double __stdcall PaletteHueToRgb(double n1, double n2, double hue)
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
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x53500 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
            aHsl[j].dSaturation = 0.5;
            aHsl[j].dLightness -= 0.1f;
            if (aHsl[j].dLightness < 0.0)
                aHsl[j].dLightness = 0.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (k = 0; k < 256; ++k)
            pTables[0x54D00 + 0x100 * i + k] = GetClosestColor(pTables, 256, tRgb[k].nRed, tRgb[k].nGreen, tRgb[k].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
            aHsl[j].dSaturation = 0.5;
            aHsl[j].dLightness += 0.2f;
            if (aHsl[j].dLightness > 1.0)
                aHsl[j].dLightness = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x56500 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].dSaturation = 0.0;
        aHsl[j].dLightness *= 0.5;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57D00 + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].dSaturation = 0.0;
        aHsl[j].dLightness = (aHsl[j].dLightness + 0.2f) / 1.2f;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57E00 + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (i = 0; i < 24; ++i)
    {
        for (j = 0; j < 256; ++j)
        {
            if (pHsl[j].dHue > 45.0 && pHsl[j].dHue < 315.0)
            {
                aHsl[j] = pHsl[j];
                aHsl[j].dHue += (float)i * 15.0;
                if (aHsl[j].dHue > 360.0)
                    aHsl[j].dHue -= 360.0;
            }
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x57F00 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 12; ++i)
    {
        const double dHue = (float)i * 30.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue = dHue;
            aHsl[j].dSaturation = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x59800 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (k = 0; k < 256; ++k)
    {
        const unsigned char nGrey = (unsigned char)sqrt((double)(pTables[4 * k + 1] * pTables[4 * k + 1] + pTables[4 * k] * pTables[4 * k] + pTables[4 * k + 2] * pTables[4 * k + 2]));
        pTables[0x5A400 + k] = GetClosestColor(pTables, 256, nGrey, 0, 0);
        pTables[0x5A500 + k] = GetClosestColor(pTables, 256, 0, nGrey, 0);
        pTables[0x5A600 + k] = GetClosestColor(pTables, 256, 0, 0, nGrey);
    }
}

// 0x00606890
static void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl)
{
    D2PalRgbaStrc tRgb[256];

    for (int i = 0; i < 256; ++i)
    {
        if (pHsl[i].dLightness != 0.0)
        {
            pHsl[i].dLightness += 0.2f;
            if (pHsl[i].dLightness > 1.0)
            {
                pHsl[i].dLightness = 1.0;
            }
        }
    }

    sub_00605080_HslToRgb(pHsl, tRgb);
    for (unsigned int i = 0; i < 256; ++i)
    {
        pTables[0x3400 + i] = GetClosestColor(pTables, 256, tRgb[i].nRed, tRgb[i].nGreen, tRgb[i].nBlue);
    }
}

// 0x00606930
void* __stdcall CreateD2Palette(void* pSource)
{
    D2HslStrc tHsl[256];

    D2_ASSERT(pSource, 683);
    unsigned char* pTables = (unsigned char*)sub_00517993_VirtualAlloc(0x6C327);
    memcpy(pTables, pSource, 0x400);
    sub_00604DF0_RgbToHsl(pTables, tHsl);
    PaletteBuildAlphaTables(pTables);
    sub_00605DE0_BuildDarkenTables(pTables);
    sub_00605E60_BuildLightenTables(pTables);
    PaletteBuildAdditiveTable(pTables);
    sub_00605AA0_BuildTablesC(pTables);
    sub_00605F00_BuildTablesE(pTables, tHsl);
    sub_00606890_BuildBrightnessTable(pTables, tHsl);
    sub_00605B70_BuildTablesD(pTables);
    *(D2ColorBlockStrc*)(pTables + 0x6B600) = gtColorBlock;
    PaletteBuildTintTables(pTables);
    return pTables;
}

#include "gen/data/Source/D2CMP/Unknown_006056D0.inc"
