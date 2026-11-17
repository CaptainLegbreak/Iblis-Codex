#define DISPLAYTYPE_GLIDE 4

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

extern unsigned char* gpScreenBuffer_007D5448;                                                              // 0x007D5448
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C
int gnYBufferArg3_007D5450;                                                                                 // 0x007D5450
int gnYBufferArg4_007D5454;                                                                                 // 0x007D5454
int gnYBufferPitch_007D557C;                                                                                // 0x007D557C
int gnViewMatrixAdjust_007C8CC4;                                                                            // 0x007C8CC4
extern int gnViewMatrixAdjustDefault_0072DBFC;                                                              // 0x0072DBFC
extern int gnDisplayType;                                                                                   // 0x007C8CB0
extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall D2GFX_SetGamma(int nGamma);                                                                   // 0x004F5230
int __fastcall D2GFX_SetOption(int nOption, int nValue);                                                    // 0x004F52B0
void __fastcall sub_004F7DA0(int nPitch, int nHeight);                                                      // 0x004F7DA0
void __cdecl sub_004F7E70_InitRowOffsets();                                                                 // 0x004F7E70

// 0x004F8DE0
void __fastcall sub_004F8DE0(unsigned char* a1, int a2, int a3, int a4)
{
    gpScreenBuffer_007D5448 = a1;
    gnScreenPitch_007D544C = a2;
    gnYBufferArg3_007D5450 = a3;
    gnYBufferArg4_007D5454 = a4;

    if (a2 != gnYBufferPitch_007D557C)
    {
        gnScreenPitch_007D544C = a2;
        gnYBufferPitch_007D557C = a2;
        sub_004F7E70_InitRowOffsets();
    }

    if (gnViewMatrixAdjust_007C8CC4 != gnViewMatrixAdjustDefault_0072DBFC)
    {
        sub_004F7DA0(a2, a3);
    }
}

// 0x004F8EA0
void __cdecl sub_004F8EA0()
{
    unsigned long nContrast = gnDisplayType != DISPLAYTYPE_GLIDE ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    D2GFX_SetOption(11, nContrast);

    unsigned long nGamma = 155;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    gGfxSettings.nGamma = nGamma;
    D2GFX_SetGamma(nGamma);
}

#include "gen/data/Source/D2Win/004F8DE0_sub_004F8DE0.inc"
