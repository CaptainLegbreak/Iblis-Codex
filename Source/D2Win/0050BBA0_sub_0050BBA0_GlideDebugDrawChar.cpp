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

struct D2GrTexInfoStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
};

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern T00508FE0 gaGlideDebugFontVertices_00880258[4];                                              // 0x00880258
int gaGlideDebugFontCharWidths_008802C8[96];                                                                // 0x008802C8
extern int gaGlideDebugFontTexAddr_008800D8[96];                                                            // 0x008800D8
int gnGlideDebugFontTmu_00880450;                                                                           // 0x00880450
extern D2GrTexInfoStrc gGlideDebugFontTexInfo_0072F2B4;                                                     // 0x0072F2B4
void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                       // 0x005095D0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu);                                                  // 0x00509460

// 0x0050BBA0
static int __stdcall sub_0050BBA0_GlideDebugDrawChar(char ch, int nX, int nY)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaGlideDebugFontCharWidths_008802C8[ch];

    if ((unsigned char)(ch - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaGlideDebugFontVertices_00880258[0].x = (float)nX;
        gaGlideDebugFontVertices_00880258[0].y = (float)nY;
        gaGlideDebugFontVertices_00880258[1].x = (float)nX;
        gaGlideDebugFontVertices_00880258[1].y = (float)nBottom;
        gaGlideDebugFontVertices_00880258[2].x = (float)nRight;
        gaGlideDebugFontVertices_00880258[2].y = (float)nBottom;
        gaGlideDebugFontVertices_00880258[3].x = (float)nRight;
        gaGlideDebugFontVertices_00880258[3].y = (float)nY;

        ch -= 0x20;
        gpfGlideTexSource_0087EB98(gnGlideDebugFontTmu_00880450, gaGlideDebugFontTexAddr_008800D8[ch], 3, &gGlideDebugFontTexInfo_0072F2B4);
        gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideDebugFontVertices_00880258, sizeof(T00508FE0));
        return gaGlideDebugFontCharWidths_008802C8[ch];
    }

    return gaGlideDebugFontCharWidths_008802C8[0];
}

// 0x0050BC90
void __fastcall sub_0050BC90_GlideDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    sub_005094B0_GlideSetState(1);
    sub_00509500_GlideSetCombine(1);
    sub_005095D0_GlideSetDepth(1);
    sub_00509460_GlideSelectTmuState(gnGlideDebugFontTmu_00880450);

    for (int i = 0; i < nLength; ++i)
    {
        nX += sub_0050BBA0_GlideDebugDrawChar(szText[i], nX, nY);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 12;
        }
    }
}
