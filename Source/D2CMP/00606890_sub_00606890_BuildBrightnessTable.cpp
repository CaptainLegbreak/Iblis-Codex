struct D2HslStrc
{
    double f_0;
    double f_8;
    double f_10;
};

struct D2PalRgbaStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

struct D2ColorBlockStrc
{
    unsigned char data[39];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern const D2ColorBlockStrc gtColorBlock_007434D8;                                                        // 0x007434D8
double __stdcall sub_00604FE0_HueToRgb(double n1, double n2, double hue);                                   // 0x00604FE0
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __stdcall sub_00605D20_BuildTintTables(unsigned char* pData);                                          // 0x00605D20
void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData);                                        // 0x00605DE0
void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData);                                       // 0x00605E60
void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize);
void __stdcall sub_00605880_BuildTablesA(unsigned char* pTables);
void __stdcall sub_006059B0_BuildTable(unsigned char* pData);
void __stdcall sub_00605AA0_BuildTablesC(unsigned char* pTables);
void __stdcall sub_00605B70_BuildTablesD(unsigned char* pTables);
void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl);

static __declspec(noinline) void sub_00604DF0_RgbToHsl(const unsigned char* pRgb, D2HslStrc* pHsl)
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

static __declspec(noinline) void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
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

// 0x00606930
void* __stdcall sub_00606930_BuildTables(void* pSource)
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

#include "gen/data/Source/D2CMP/00606890_sub_00606890_BuildBrightnessTable.inc"
