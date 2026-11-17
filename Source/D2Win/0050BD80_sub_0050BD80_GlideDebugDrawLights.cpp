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

// 0x0050BD80
void sub_0050BD80_GlideDebugDrawLights()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
    struct Row { int remaining; int yBase; int j; } row;
    row.j=0;
    unsigned int* light=gaGlideDebugLight_0087F0D0;
    for (row.yBase=100;row.yBase<164;row.yBase+=2,++row.j)
    {
        struct Coordinates { int x; int y; } coordinates;
        coordinates.x=(0x113-row.j)*2;
        coordinates.y=row.yBase;
        row.remaining=32;
        do {
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette_0072F308[*light],coordinates.x,coordinates.y);
            ++light;
            coordinates.y+=2;
            coordinates.x+=2;
        } while (--row.remaining);
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
