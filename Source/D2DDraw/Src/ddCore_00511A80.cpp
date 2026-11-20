#include "D2DDraw.h"
#include "D2DDrawTypes.h"

int __fastcall sub_00511870_EndScene();                                                                     // 0x00511870
void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0
extern int gaDDrawCapsTypes_0072F7D0[7];                                                                    // 0x0072F7D0
D2GfxPaletteViewStrc* gpDDrawCaps_007C9150;                                                                      // 0x007C9150
extern int gbDDrawReady_00881264;                                                                           // 0x00881264
extern int gbDDrawReady2_00881268;                                                                          // 0x00881268
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881278;                                                       // 0x00881278
extern D2DDrawSurfaceStrc* gpDDrawBackSurface_0088127C;                                                   // 0x0088127C
D2DDrawSurfaceStrc* gpDDrawSurface_00881280;                                                              // 0x00881280
void* gpDDrawSmackBuffer_008816B0;                                                                          // 0x008816B0

// 0x00511A80
void __cdecl sub_00511A80_DDrawReleaseSurfaces()
{
    if (gbDDrawReady_00881264)
    {
        for (int i = 0; i < 3; ++i)
        {
            sub_00512ED0_ClearScreen(0);
            sub_00511870_EndScene();
        }
        if (gpDDrawSurface_00881280)
        {
            gpDDrawSurface_00881280->lpVtbl->Release(gpDDrawSurface_00881280);
            gpDDrawSurface_00881280 = 0;
        }
        if (gpDDrawBackSurface_0088127C)
        {
            gpDDrawBackSurface_0088127C->lpVtbl->Release(gpDDrawBackSurface_0088127C);
            gpDDrawBackSurface_0088127C = 0;
        }
        if (gpDDrawSurface_00881278)
        {
            gpDDrawSurface_00881278->lpVtbl->Release(gpDDrawSurface_00881278);
            gpDDrawSurface_00881278 = 0;
        }
        gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
        gbDDrawReady_00881264 = 0;
        gbDDrawReady2_00881268 = 0;
    }
}

// 0x00511D70
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType)
{
    *pType = gaDDrawCapsTypes_0072F7D0[nIndex];
    switch (nIndex)
    {
    case 0:
        return gpDDrawCaps_007C9150->nValue08;
    case 1:
        return gpDDrawCaps_007C9150->nValue04;
    case 2:
        return gpDDrawCaps_007C9150->nValue00;
    case 3:
        return gpDDrawCaps_007C9150->nValue104;
    case 4:
        return gpDDrawCaps_007C9150->nValue108;
    case 6:
        return gpDDrawCaps_007C9150->nValue10C;
    }
    return 0;
}

// 0x00512700
int __cdecl sub_00512700_DDrawGetBlendedShadows()
{
    return gpGfxSettings_007C9148->bBlendedShadows;
}

// 0x00513330
void __fastcall sub_00513330_DDrawCloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (gpDDrawSmackBuffer_008816B0)
    {
        FOG_Free(gpDDrawSmackBuffer_008816B0, szDDSmackFile_006DE20C, 0xF0, 0);
        gpDDrawSmackBuffer_008816B0 = 0;
    }
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
}

#include "gen/data/Source/D2DDraw/Src/ddCore_00511A80.inc"
