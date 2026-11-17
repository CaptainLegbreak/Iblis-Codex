struct T00508FE0
{
    float x;
    float y;
    float unk0x08;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GlideDebugCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nAlpha;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern int gaGlideCrossOffsetX_0072F2C8[8];                                                                 // 0x0072F2C8
extern int gaGlideCrossOffsetY_0072F2E8[8];                                                                 // 0x0072F2E8
extern unsigned int gaGlideLightPalette_0072F308[];                                                         // 0x0072F308
extern void (__stdcall* gpfGlideDrawPoint_0087EAA0)(const T00508FE0* pVertex);                      // 0x0087EAA0
extern void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                // 0x0087EB8C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0
extern unsigned int gaGlideDebugLight_0087F0D0[0x400];                                                      // 0x0087F0D0
extern D2GlideDebugCellStrc** gppGlideDebugBuffer_00880454;                                                 // 0x00880454

// 0x0050BD30
static void sub_0050BD30_GlideDrawPointCross(unsigned int dwColor, int nX, int nY)
{
    gpfGlideConstantColor_0087EFA0(dwColor);
    for (int i = 0; i < 8; ++i)
    {
        T00508FE0 tVertex;
        tVertex.x = (float)(gaGlideCrossOffsetX_0072F2C8[i] + nX);
        tVertex.y = (float)(gaGlideCrossOffsetY_0072F2E8[i] + nY);
        gpfGlideDrawPoint_0087EAA0(&tVertex);
    }
}

void sub_0050BD80_GlideDebugDrawLights()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
    for (int j = 0; j < 32; ++j)
    {
        for (int i = 0; i < 32; ++i)
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette_0072F308[gaGlideDebugLight_0087F0D0[j * 32 + i]], (0x113 - j + i) * 2, (j + i + 50) * 2);
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
    for (int j = 0; j < 48; ++j)
    {
        for (int i = 0; i < 48; ++i)
        {
            const int nX = (i + 50) * 2 - j * 2;
            const int nY = (j + i + 50) * 2;
            unsigned int dwColor;
            if (j == 24 && i == j)
            {
                dwColor = 0;
            }
            else
            {
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer_00880454[j][i];
                dwColor = ((pCell->nRed * (unsigned int)pCell->nAlpha / 256 * 256 + pCell->nGreen * (unsigned int)pCell->nAlpha / 256) * 256 + pCell->nBlue * (unsigned int)pCell->nAlpha / 256) * 256;
            }
            sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
        }
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

#include "gen/data/Source/D2Win/0050BD30_sub_0050BD30_GlideDrawPointCross.inc"
