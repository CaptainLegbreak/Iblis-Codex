#include "D2CMP.h"

#define PAL_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HslStrc;
struct D2PalRgbaStrc;
struct D2ColorBlockStrc;

extern unsigned char gaPcxPalette_008E9938[256 * 4]; // 0x008E9938

typedef unsigned char (__stdcall* MapFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

unsigned char __stdcall Palette24BitTo8BitPixel(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x006056D0
extern int gbPaletteLoaded_008E9934; // 0x008E9934

unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

struct D2ColorBlockStrc
{
    unsigned char data[39];
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern const D2ColorBlockStrc gtColorBlock_007434D8; // 0x007434D8
double __stdcall sub_00604FE0_HueToRgb(double n1, double n2, double hue); // 0x00604FE0
void __stdcall sub_00605D20_BuildTintTables(unsigned char* pData); // 0x00605D20
void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData); // 0x00605DE0
void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData); // 0x00605E60
void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize);
void __stdcall sub_00605880_BuildTablesA(unsigned char* pTables);
void __stdcall sub_006059B0_BuildTable(unsigned char* pData);
void __stdcall sub_00605AA0_BuildTablesC(unsigned char* pTables);
void __stdcall sub_00605B70_BuildTablesD(unsigned char* pTables);
void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl);

unsigned int gnPaletteStart_008E9930; // 0x008E9930

unsigned int gnPaletteEnd_008E902C; // 0x008E902C

int gbTableSet_008E9D40; // 0x008E9D40

unsigned char gaTable_008E9830[0x100]; // 0x008E9830

int gnGlobal_008E9028; // 0x008E9028

unsigned int gdwSwappedColor_008E9D38; // 0x008E9D38

int gnSquareTable_008E9034[511]; // 0x008E9034

// 0x006056D0
unsigned char __stdcall Palette24BitTo8BitPixel(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    unsigned int nBestDistance = 0x7FFFFFFF;
    unsigned int nBestIndex = 0;
    for (unsigned int i = gnPaletteStart_008E9930; i <= gnPaletteEnd_008E902C; ++i)
    {
        if (gbTableSet_008E9D40 && !gaTable_008E9830[i])
        {
            continue;
        }

        if (gnGlobal_008E9028 && gdwSwappedColor_008E9D38 == ((((nRed << 8) | nGreen) << 8) | nBlue))
        {
            nBestIndex = 0;
            break;
        }

        unsigned int nDistance = gnSquareTable_008E9034[nRed - gaPcxPalette_008E9938[i * 4 + 2] + 255]
            + gnSquareTable_008E9034[nGreen - gaPcxPalette_008E9938[i * 4 + 1] + 255]
            + gnSquareTable_008E9034[nBlue - gaPcxPalette_008E9938[i * 4] + 255];
        if (nDistance < nBestDistance)
        {
            nBestDistance = nDistance;
            nBestIndex = i;
        }
    }

    return (unsigned char)nBestIndex;
}

int gbDarkTest_008E9D3C; // 0x008E9D3C

// 0x006057A0
int __stdcall Palette24BitTo8BitImage(const unsigned char* pSource, unsigned char* pDest, unsigned int nCount, MapFn pfnMap)
{
    const unsigned char* pSrc = pSource;
    unsigned char* pDst = pDest;
    if (gbPaletteLoaded_008E9934)
    {
        MapFn pfn = !pfnMap ? Palette24BitTo8BitPixel : pfnMap;

        for (unsigned int i = 0; i < nCount; ++i)
        {
            unsigned char nRed = *pSrc++;
            unsigned char nGreen = *pSrc++;
            unsigned char nBlue = *pSrc++;
            if (gbDarkTest_008E9D3C && nRed <= 10 && nGreen <= 10 && nBlue <= 10)
            {
                nRed = 4;
                nBlue = 0;
                nGreen = 0;
            }

            *pDst++ = pfn(nRed, nGreen, nBlue);
        }
    }

    return 0;
}

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

        pHsl->f_0 = dHue;
        pHsl->f_8 = dSaturation;
        pHsl->f_10 = dLightness;
        pRgb += 4;
        ++pHsl;
    }
}

static void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char nRed, nGreen, nBlue;
        if (pHsl->f_8 == 0.0)
        {
            nRed = nGreen = nBlue = (unsigned char)(pHsl->f_10 * 255.0);
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
        ++pHsl;
        ++pRgb;
    }
}

// 0x00606890
static void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl)
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
    sub_00605880_BuildTablesA(pTables);
    sub_00605DE0_BuildDarkenTables(pTables);
    sub_00605E60_BuildLightenTables(pTables);
    sub_006059B0_BuildTable(pTables);
    sub_00605AA0_BuildTablesC(pTables);
    sub_00605F00_BuildTablesE(pTables, tHsl);
    sub_00606890_BuildBrightnessTable(pTables, tHsl);
    sub_00605B70_BuildTablesD(pTables);
    *(D2ColorBlockStrc*)(pTables + 0x6B600) = gtColorBlock_007434D8;
    sub_00605D20_BuildTintTables(pTables);
    return pTables;
}

#include "gen/data/Source/D2CMP/Unknown_006056D0.inc"
