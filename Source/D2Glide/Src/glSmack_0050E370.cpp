#include "D2Glide.h"

struct D2RgbColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};
struct D2SmackStrc
{
    int nVersion;
    int nWidth;
    int nHeight;
    int nFrames;
    unsigned char unk0x10[0x5C];
    D2RgbColorStrc aPalette[256];
    unsigned char unk0x36C[8];
    int f_374;
};
struct D2GlideSmackStrc
{
    D2SmackStrc* f_0;
    unsigned char nType;
    unsigned char unk0x05[3];
    int nX;
    int nY;
};
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

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
void __fastcall sub_005094B0_GlideSetState(int nState);                                                     // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                    // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                      // 0x005095D0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu);                                                 // 0x00509460
void __fastcall sub_0050E040_GlideCloseSmacker(D2GlideSmackStrc* pRecord);                                  // 0x0050E040
void __fastcall sub_0050E070_GlideSetSmackPalette(D2RgbColorStrc* pColors);                                 // 0x0050E070
void __cdecl sub_0050E330_GlideRefresh();                                                                    // 0x0050E330
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                // 0x0087EB8C
void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);        // 0x0087EB98
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
int gnGlideSmackTmu_00880BF4;                                                                               // 0x00880BF4
extern int gnGlideSmackTexAddrA_00880BE8;                                                                   // 0x00880BE8
extern int gnGlideSmackTexAddrB_00880BEC;                                                                   // 0x00880BEC
extern D2GrTexInfoStrc gGlideSmackTexInfoA_0072F680;                                                        // 0x0072F680
extern D2GrTexInfoStrc gGlideSmackTexInfoB_0072F694;                                                        // 0x0072F694
T00508FE0 gaGlideSmackVertices_00880B78[4];                                                         // 0x00880B78
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144

// 0x0050E370
static void __stdcall sub_0050E370_GlideDrawSmackFrame(int nHeight, D2GlideSmackStrc* pRecord, int nWidth)
{
    sub_005094B0_GlideSetState(1);
    sub_00509500_GlideSetCombine(1);
    sub_005095D0_GlideSetDepth(2);
    sub_00509460_GlideSelectTmuState(gnGlideSmackTmu_00880BF4);
    gpfGlideMask_0087EB8C(0);
    int nTop = pRecord->nY - nHeight;
    int nY = pRecord->nY;
    gpfGlideTexSource_0087EB98(gnGlideSmackTmu_00880BF4, gnGlideSmackTexAddrA_00880BE8, 3, &gGlideSmackTexInfoA_0072F680);
    int nX = pRecord->nX;
    int nRight = nX + 0x100;
    int nTexWidth = 0x100;
    if (nWidth <= 0x100)
        nTexWidth = nWidth;
    gaGlideSmackVertices_00880B78[0].x = (float)nX;
    gaGlideSmackVertices_00880B78[0].y = (float)nTop;
    gaGlideSmackVertices_00880B78[0].oow = 1.0f;
    gaGlideSmackVertices_00880B78[0].sow = 0.0f;
    gaGlideSmackVertices_00880B78[0].tow = 0.0f;
    gaGlideSmackVertices_00880B78[1].x = (float)nX;
    gaGlideSmackVertices_00880B78[1].y = (float)nY;
    gaGlideSmackVertices_00880B78[1].oow = 1.0f;
    gaGlideSmackVertices_00880B78[1].sow = 0.0f;
    gaGlideSmackVertices_00880B78[1].tow = (float)nHeight;
    gaGlideSmackVertices_00880B78[2].x = (float)nRight;
    gaGlideSmackVertices_00880B78[2].y = (float)nY;
    gaGlideSmackVertices_00880B78[2].oow = 1.0f;
    gaGlideSmackVertices_00880B78[2].sow = (float)nTexWidth;
    gaGlideSmackVertices_00880B78[2].tow = (float)nHeight;
    gaGlideSmackVertices_00880B78[3].x = (float)nRight;
    gaGlideSmackVertices_00880B78[3].y = (float)nTop;
    gaGlideSmackVertices_00880B78[3].oow = 1.0f;
    gaGlideSmackVertices_00880B78[3].sow = (float)nTexWidth;
    gaGlideSmackVertices_00880B78[3].tow = 0.0f;
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideSmackVertices_00880B78, sizeof(T00508FE0));

    gpfGlideTexSource_0087EB98(gnGlideSmackTmu_00880BF4, gnGlideSmackTexAddrB_00880BEC, 3, &gGlideSmackTexInfoB_0072F694);
    nX = nRight;
    nRight = nX + nWidth - 0x100;
    nTexWidth = nWidth - 0x100;
    gaGlideSmackVertices_00880B78[0].x = (float)nX;
    gaGlideSmackVertices_00880B78[0].y = (float)nTop;
    gaGlideSmackVertices_00880B78[0].oow = 1.0f;
    gaGlideSmackVertices_00880B78[0].sow = 0.0f;
    gaGlideSmackVertices_00880B78[0].tow = 0.0f;
    gaGlideSmackVertices_00880B78[1].x = (float)nX;
    gaGlideSmackVertices_00880B78[1].y = (float)nY;
    gaGlideSmackVertices_00880B78[1].oow = 1.0f;
    gaGlideSmackVertices_00880B78[1].sow = 0.0f;
    gaGlideSmackVertices_00880B78[1].tow = (float)nHeight;
    gaGlideSmackVertices_00880B78[2].x = (float)nRight;
    gaGlideSmackVertices_00880B78[2].y = (float)nY;
    gaGlideSmackVertices_00880B78[2].oow = 1.0f;
    gaGlideSmackVertices_00880B78[2].sow = (float)nTexWidth;
    gaGlideSmackVertices_00880B78[2].tow = (float)nHeight;
    gaGlideSmackVertices_00880B78[3].x = (float)nRight;
    gaGlideSmackVertices_00880B78[3].y = (float)nTop;
    gaGlideSmackVertices_00880B78[3].oow = 1.0f;
    gaGlideSmackVertices_00880B78[3].sow = (float)nTexWidth;
    gaGlideSmackVertices_00880B78[3].tow = 0.0f;
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideSmackVertices_00880B78, sizeof(T00508FE0));
    gpfGlideMask_0087EB8C(1);
}

// 0x0050E7F0
void __fastcall sub_0050E7F0_GlidePlaySmacker(D2GlideSmackStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = pRecord->f_0;
        if (!hSmack)
            return;
        if (!SmackWait(hSmack))
        {
            if (!gbSurfaceActive_007C9140)
                return;
            SmackDoFrame(hSmack);
            if (hSmack->f_374 == hSmack->nFrames)
                sub_0050E040_GlideCloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
            if (gbRenderPaused_007C9144)
                return;
            sub_0050E070_GlideSetSmackPalette(hSmack->aPalette);
            sub_0050E330_GlideRefresh();
        }
        if (gbRenderPaused_007C9144)
            return;
        sub_0050E370_GlideDrawSmackFrame(hSmack->nHeight, pRecord, hSmack->nWidth);
    }
    case 'p':
        if (!gbRenderPaused_007C9144)
            sub_0050E370_GlideDrawSmackFrame(60, pRecord, 468);
        break;
    }
}
