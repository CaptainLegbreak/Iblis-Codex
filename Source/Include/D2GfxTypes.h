#pragma once
// D2Gfx: renderer settings, palette view, RGB triple and Smacker movie layouts shared by the render modules

#include "D2Check.h"
#include "D2Structs.h"

struct D2RgbColorStrc;
struct D2GfxSettingsStrc;
struct D2GfxPaletteViewStrc;
struct D2SmackStrc;

struct D2RgbColorStrc
{
    unsigned char nRed; // 0x00
    unsigned char nGreen; // 0x01
    unsigned char nBlue; // 0x02
};

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled; // 0x00
    int bPerspectiveCapable; // 0x04
    int bLowQuality; // 0x08
    int nGamma; // 0x0C
    int bVSync; // 0x10
    int bBlendedShadows; // 0x14
};

struct D2GfxPaletteViewStrc
{
    int unk0x00[0x45]; // 0x00
    unsigned char* pRgbTable; // 0x114
    unsigned char* pRemap; // 0x118
    int unk0x11C; // 0x11C
};

struct D2SmackStrc
{
    int nVersion; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nFrames; // 0x0C
    int unk0x10[22]; // 0x10
    int bNewPalette; // 0x68
    D2RgbColorStrc aPalette[256]; // 0x6C
    int unk0x36C[2]; // 0x36C
    int nFrameNum; // 0x374
};

D2_CHECK_SIZE(D2RgbColorStrc, 0x3);
D2_CHECK_SIZE(D2GfxSettingsStrc, 0x18);
D2_CHECK_SIZE(D2GfxPaletteViewStrc, 0x120);
D2_CHECK_SIZE(D2SmackStrc, 0x378);
