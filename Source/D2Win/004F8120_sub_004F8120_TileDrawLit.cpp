extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

void __fastcall sub_004F71A0_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg);
void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg);
void __fastcall sub_004F7EA0_DrawVisTile(unsigned char* pSrc, int nX, int nY);
void __fastcall sub_004F8050_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight);    // 0x004F8050
extern int gnClipBottom_007C978C;                                                                           // 0x007C978C
extern int gnClipLeft_007C9794;                                                                             // 0x007C9794
extern int gnInnerRight_007C9784;                                                                           // 0x007C9784
extern int gnInnerBottom_007C9790;                                                                          // 0x007C9790
extern int gnRowOffsets_007C97A8[732];                                                                      // 0x007C97A8
#define gnRowOffsets_007C9828 (gnRowOffsets_007C97A8 + 32)
extern int gnInnerTop_007CA31C;                                                                             // 0x007CA31C
extern int gnClipRight_007D2324;                                                                            // 0x007D2324
extern int gnInnerLeft_007D2328;                                                                            // 0x007D2328
extern int gnClipTop_007D232C;                                                                              // 0x007D232C
unsigned char* gpScreenBuffer_007D5448;                                                                     // 0x007D5448
extern int gdwGlobal_0072DA50;                                                                              // 0x0072DA50
int gnLightingOff_007D2340;                                                                                 // 0x007D2340

// 0x004F8120
void __fastcall sub_004F8120_TileDrawLit(unsigned char* pSrc, int nX, int nY, int* pLight)
{
    if (gnLightingOff_007D2340)
    {
        const unsigned char nLight = *(unsigned char*)pLight;
        if ((nLight & 0xF8) == 0xF8)
        {
            sub_004F7EA0_DrawVisTile(pSrc, nX, nY);
            return;
        }

        sub_004F8050_DrawRleVisTile(pSrc, nX, nY, nLight);
        return;
    }

    const int nLightX = pLight[0] << 5;
    const int nLightXStep = pLight[3] - pLight[0];
    const int nLightY = pLight[1] << 5;
    const int nLightYStep = pLight[2] - pLight[1];
    const int nLightDelta = pLight[1] - pLight[0];
    const int nDiff1 = D2_ABS(nLightDelta);
    const int nDiff2 = D2_ABS(nLightXStep);
    const int nDiff3 = D2_ABS(nLightYStep);
    if (!gdwGlobal_0072DA50 && nDiff3 + nDiff2 + nDiff1 >= 10)
    {
        if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        {
            return;
        }

        D2_ASSERT(gpScreenBuffer_007D5448, 958);
        unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
        if (nY >= gnInnerTop_007CA31C && nY < gnInnerBottom_007C9790 && nX >= gnInnerLeft_007D2328 && nX < gnInnerRight_007C9784)
        {
            sub_004F71A0_DrawLitRleRows(pSrc, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0x20, 8);
        }
        else
        {
            sub_004F7850_DrawLitRleRowsClipped(nX, nY, pSrc, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0x20, 8);
        }

        return;
    }

    if ((nLightX >> 8) == 0x1F)
    {
        sub_004F7EA0_DrawVisTile(pSrc, nX, nY);
        return;
    }

    sub_004F8050_DrawRleVisTile(pSrc, nX, nY, *(unsigned char*)pLight);
}
