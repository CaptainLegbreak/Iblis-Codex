#include "D2Glide.h"
#include "D2GfxTypes.h"

typedef void (__fastcall* PixelDataFreeCallback)(void* pData);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __cdecl sub_00509650();                                                                                  // 0x00509650
void __fastcall sub_0050A110_GlideFreeCelData(void* pData);                                                 // 0x0050A110
void __stdcall sub_00601A30_StorePixelFreeHandler(PixelDataFreeCallback pfnCallback); // 0x00601A30

extern D2GrTexInfoStrc gGlideSmackTexInfoA_0072F680;                                                        // 0x0072F680
extern D2GrTexInfoStrc gGlideSmackTexInfoB_0072F694;                                                        // 0x0072F694
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);        // 0x0087EAB8
extern int gnGlideTmuCount_0087EFB4;                                                                        // 0x0087EFB4
int gbGlideSpriteFlag_0087EFF0;                                                                             // 0x0087EFF0
int gbGlideMultiTmu_0087EFF4;                                                                               // 0x0087EFF4
extern void* gpGlideSpriteBufferA_0087F0C8;                                                                 // 0x0087F0C8
extern void* gpGlideSpriteBufferB_0087F0CC;                                                                 // 0x0087F0CC
extern unsigned char* gpGlideSmackBufferB_00880B70;                                                          // 0x00880B70
extern unsigned char* gpGlideSmackBufferC_00880B74;                                                          // 0x00880B74
int gnGlideSmackTexAddrA_00880BE8;                                                                          // 0x00880BE8
int gnGlideSmackTexAddrB_00880BEC;                                                                          // 0x00880BEC
extern int gnGlideSmackTmu_00880BF4;                                                                        // 0x00880BF4

// 0x0050B7B0
void __cdecl sub_0050B7B0_GlideInitSprites()
{
    D2_ASSERT(!gpGlideSpriteBufferA_0087F0C8, 0x4A);
    D2_ASSERT(!gpGlideSpriteBufferB_0087F0CC, 0x4B);
    gpGlideSpriteBufferA_0087F0C8 = FOG_Alloc(0x10000, ".\\Src\\glSprite.cpp", 0x4C, 0);
    gpGlideSpriteBufferB_0087F0CC = FOG_Alloc(0x10000, ".\\Src\\glSprite.cpp", 0x4D, 0);
    sub_00601A30_StorePixelFreeHandler(sub_0050A110_GlideFreeCelData);
    gbGlideSpriteFlag_0087EFF0 = 0;
    gbGlideMultiTmu_0087EFF4 = gnGlideTmuCount_0087EFB4 > 1;
    if (gnGlideTmuCount_0087EFB4 > 1 && !sub_00509650())
        gbGlideSpriteFlag_0087EFF0 = 1;
}

// 0x0050BF40
int __cdecl sub_0050BF40_GlideGetBlendedShadows()
{
    return gpGfxSettings_007C9148->bBlendedShadows;
}

// 0x0050DFE0
int __fastcall sub_0050DFE0_GlideSetSmackTexAddresses(int nBase, int nAlign)
{
    int nSize = 0x8000;
    const int nMask = nAlign - 1;
    if (nSize & nMask)
        nSize = (nSize | nMask) + 1;
    if (nBase & nMask)
        nBase = (nBase | nMask) + 1;
    gnGlideSmackTexAddrB_00880BEC = nBase + nSize;
    gnGlideSmackTexAddrA_00880BE8 = nBase;
    gGlideSmackTexInfoA_0072F680.pData = gpGlideSmackBufferB_00880B70;
    gGlideSmackTexInfoB_0072F694.pData = gpGlideSmackBufferC_00880B74;
    return nSize * 2;
}

// 0x0050E330
void __cdecl sub_0050E330_GlideRefresh()
{
    gpfGlideTexDownloadMipMap_0087EAB8(gnGlideSmackTmu_00880BF4, gnGlideSmackTexAddrA_00880BE8, 3, &gGlideSmackTexInfoA_0072F680);
    gpfGlideTexDownloadMipMap_0087EAB8(gnGlideSmackTmu_00880BF4, gnGlideSmackTexAddrB_00880BEC, 3, &gGlideSmackTexInfoB_0072F694);
}

#include "gen/data/Source/D2Glide/Src/glSprite_0050B7B0.inc"
