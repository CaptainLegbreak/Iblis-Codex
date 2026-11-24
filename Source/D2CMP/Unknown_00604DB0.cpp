#include "D2CMP.h"

struct T00604DB0;
struct D2HslStrc;
struct D2PalRgbaStrc;
struct D2PcxRgbStrc;
struct D2PcxPaletteStrc;

struct T00604DB0 { double value[1]; };

enum { VALUE_SLOT_INDEX = 0 };

unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
extern int ganSquareTable[511]; // 0x008E9034
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned char gaPcxPalette[256 * 4]; // 0x008E9938

struct D2PcxRgbStrc
{
    unsigned char nR;
    unsigned char nG;
    unsigned char nB;
};

struct D2PcxPaletteStrc
{
    unsigned char f_0;
    D2PcxRgbStrc aColors[256];
};

// 0x00604DB0
double __stdcall sub_00604DB0(T00604DB0 a,T00604DB0 b)
{
    return a.value[VALUE_SLOT_INDEX]>b.value[VALUE_SLOT_INDEX] ? a.value[VALUE_SLOT_INDEX] : b.value[VALUE_SLOT_INDEX];
}

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

// 0x00605080
static void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char nRed, nGreen, nBlue;
        if (pHsl->dSaturation == 0.0)
        {
            nRed = (unsigned char)(pHsl->dLightness * 255.0);
            nGreen = nRed;
            nBlue = nRed;
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
        ++pRgb;
        ++pHsl;
    }
}

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

void __cdecl sub_M386_Emit_00606890(int nUnused, unsigned char* pTables, D2HslStrc* pHsl)
{
    sub_00606890_BuildBrightnessTable(pTables, pHsl);
}

// 0x00605210
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2)
{
    unsigned int nBestDistance = 0xFFFFFFFF;
    unsigned int nBest = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int nDelta0 = pPalette[i * 4 + 0] - nC0;
        const int nDelta1 = pPalette[i * 4 + 1] - nC1;
        const int nDelta2 = pPalette[i * 4 + 2] - nC2;
        const unsigned int nDistance = nDelta2 * nDelta2 + nDelta1 * nDelta1 + nDelta0 * nDelta0;
        if (nDistance < nBestDistance)
        {
            nBest = i;
            nBestDistance = nDistance;
        }
    }
    return (unsigned char)nBest;
}

// 0x00605280
unsigned char __stdcall GetFurthestColor(unsigned char* pPalette, unsigned int nCount, int nRed, int nGreen, int nBlue)
{
    unsigned int nBest = 0;
    unsigned int nBestIndex = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int d0 = pPalette[i * 4 + 0] - nRed;
        const int d1 = pPalette[i * 4 + 1] - nGreen;
        const int d2 = pPalette[i * 4 + 2] - nBlue;
        const unsigned int nDist = d0 * d0 + d1 * d1 + d2 * d2;
        if (nDist > nBest)
        {
            nBestIndex = i;
            nBest = nDist;
        }
    }
    return (unsigned char)nBestIndex;
}

// 0x006052F0
void __cdecl sub_006052F0_InitSquareTable()
{
    for (int i = -256; i < 256; ++i)
        gnSquareTableCenter_008E9430[i] = i * i;
}

// 0x00605340
int __fastcall sub_00605340_LoadPcxPalette(const char* szFileName)
{
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        OutputDebugStringA("Unable to open ");
        OutputDebugStringA(szFileName);
// build: symbol ?gszNewline@* 0x006FFCB0
        OutputDebugStringA(gszNewline);
        return 0;
    }

    unsigned char header[128];
    memset(header, 0, sizeof(header));
    unsigned long nRead = 0;
    ReadFile(hFile, header, sizeof(header), &nRead, 0);
    if (nRead != sizeof(header) || header[0] != 0x0A || header[1] != 5 || header[3] != 8)
    {
        OutputDebugStringA("File is not a valid 256-color PCX file.\n");
        CloseHandle(hFile);
        return 0;
    }

    D2PcxPaletteStrc palette;
    memset(&palette, 0, sizeof(palette));
    SetFilePointer(hFile, -(long)sizeof(palette), 0, 2);
    ReadFile(hFile, &palette, sizeof(palette), &nRead, 0);
    if (nRead != sizeof(palette) || palette.f_0 != 0x0C)
    {
        OutputDebugStringA("Unable to extract palette from\n");
        CloseHandle(hFile);
        return 0;
    }

    for (unsigned int i = 0; i < 256; ++i)
    {
        gaPcxPalette[i * 4 + 0] = palette.aColors[i].nR;
        gaPcxPalette[i * 4 + 1] = palette.aColors[i].nG;
        gaPcxPalette[i * 4 + 2] = palette.aColors[i].nB;
    }

    CloseHandle(hFile);
    return 1;
}

// 0x00605DE0
void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 32; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x400 + i * 256 + j] = GetClosestColor(pData, 256,
                pData[j * 4 + 0] * (i + 1) >> 5,
                pData[j * 4 + 1] * (i + 1) >> 5,
                pData[j * 4 + 2] * (i + 1) >> 5);
        }
    }
}
