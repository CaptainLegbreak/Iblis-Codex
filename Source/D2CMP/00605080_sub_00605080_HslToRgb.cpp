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

unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

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

// 0x00605080
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
