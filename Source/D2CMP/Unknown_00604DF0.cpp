#include "D2CMP.h"

struct D2HSLStrc
{
    double dHue;
    double dSaturation;
    double dLightness;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static __forceinline double D2_MAX(double a, double b)
{
    return a > b ? a : b;
}

static __forceinline double D2_MIN(double a, double b)
{
    return a < b ? a : b;
}

// 0x00604DF0
void __fastcall sub_00604DF0_PaletteToHSL(D2HSLStrc* pHSL, const unsigned char* pPalette)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        double dLightness;
        const double dRed = pPalette[0] / 255.0;
        const double dGreen = pPalette[1] / 255.0;
        const double dBlue = pPalette[2] / 255.0;
        const double dMax = D2_MAX(dRed, D2_MAX(dGreen, dBlue));
        const double dMin = D2_MIN(dRed, D2_MIN(dGreen, dBlue));
        dLightness = (dMax + dMin) / 2.0;
        D2_ASSERT(dLightness >= 0.0 && dLightness <= 1.0, 63);

        if (dMax == dMin)
        {
            pHSL->dHue = 0.0;
            pHSL->dSaturation = 0.0;
            pHSL->dLightness = dLightness;
        }
        else
        {
            const double dDelta = dMax - dMin;
            double dSaturation;
            if (dLightness <= 0.5)
            {
                dSaturation = dDelta / (dMax + dMin);
            }
            else
            {
                dSaturation = dDelta / (2.0 - (dMax + dMin));
            }

            D2_ASSERT(dSaturation >= 0.0 && dSaturation <= 1.0, 77);

            double dHue;
            if (dRed == dMax)
            {
                dHue = (dGreen - dBlue) / dDelta;
            }
            else if (dGreen == dMax)
            {
                dHue = 2.0 + (dBlue - dRed) / dDelta;
            }
            else
            {
                dHue = 4.0 + (dRed - dGreen) / dDelta;
            }

            dHue *= 60.0;
            if (dHue < 0.0)
            {
                dHue += 360.0;
            }

            D2_ASSERT(dHue >= 0.0 && dHue < 360.0, 92);
            pHSL->dHue = dHue;
            pHSL->dSaturation = dSaturation;
            pHSL->dLightness = dLightness;
        }

        pPalette += 4;
        ++pHSL;
    }
}
