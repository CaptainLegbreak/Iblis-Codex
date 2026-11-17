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

unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex);                                  // 0x005093F0
void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern void (__stdcall* gpfGlideDrawLine_0087E978)(const T00508FE0* pStart, const T00508FE0* pEnd); // 0x0087E978
extern void (__stdcall* gpfGlideDrawPoint_0087EAA0)(const T00508FE0* pVertex);                      // 0x0087EAA0
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                 // 0x0087EB8C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0

// 0x0050C270
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha)
{
    if (nXEnd < 0 && nXStart < 0)
    {
        return;
    }
    if (nXEnd > gnScreenWidth_007C9138 && nXStart > gnScreenWidth_007C9138)
    {
        return;
    }
    if (nYEnd < 0 && nYStart < 0)
    {
        return;
    }
    if (nYEnd > gnScreenHeight_007C913C && nYStart > gnScreenHeight_007C913C)
    {
        return;
    }

    unsigned int dwColor = sub_005093F0_GlidePaletteColor(nColor);
    sub_005094B0_GlideSetState(2);
    if (nAlpha == 0xFF)
    {
        sub_00509500_GlideSetCombine(1);
    }
    else
    {
        sub_00509500_GlideSetCombine(4);
        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }
    gpfGlideMask_0087EB8C(0);
    gpfGlideConstantColor_0087EFA0(dwColor);

    if (nXStart == nXEnd && nYStart == nYEnd)
    {
        T00508FE0 tVertex;
        tVertex.x = (float)nXStart;
        tVertex.y = (float)nYStart;
        tVertex.oow = 1.0f;
        tVertex.sow = 0.0f;
        tVertex.tow = 0.0f;
        gpfGlideDrawPoint_0087EAA0(&tVertex);
    }
    else
    {
        T00508FE0 tStart;
        T00508FE0 tEnd;
        tStart.x = (float)nXStart;
        tStart.y = (float)nYStart;
        tStart.oow = 1.0f;
        tStart.sow = 0.0f;
        tStart.tow = 0.0f;
        tEnd.x = (float)nXEnd;
        tEnd.y = (float)nYEnd;
        tEnd.oow = 1.0f;
        tEnd.sow = 0.0f;
        tEnd.tow = 0.0f;
        gpfGlideDrawLine_0087E978(&tStart, &tEnd);
    }
    gpfGlideMask_0087EB8C(1);
}
