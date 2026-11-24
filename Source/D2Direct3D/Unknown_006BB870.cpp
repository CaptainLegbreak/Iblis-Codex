#include "D2DDrawTypes.h"
#include "D2DrlgMaps.h"

struct D2SurfaceStrc;
struct D2TextureStrc;
struct D2SurfaceStrc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual void __stdcall Unused54() = 0;
    virtual void __stdcall Unused58() = 0;
    virtual void __stdcall Unused5C() = 0;
    virtual void __stdcall Unused60() = 0;
    virtual int __stdcall Lock(void* pRect, D2DDSurfaceDesc2Strc* pDesc, unsigned int dwFlags, void* hEvent) = 0;
    virtual void __stdcall Unused68() = 0;
    virtual void __stdcall Unused6C() = 0;
    virtual void __stdcall Unused70() = 0;
    virtual void __stdcall Unused74() = 0;
    virtual void __stdcall Unused78() = 0;
    virtual void __stdcall Unused7C() = 0;
    virtual int __stdcall Unlock(void* pRect) = 0;
};
struct D2TextureStrc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual int __stdcall Load(D2TextureStrc* pSource) = 0;
};

struct D2DeviceStrc
{
    virtual void __stdcall Unused0() = 0;
    virtual void __stdcall Unused1() = 0;
    virtual void __stdcall Unused2() = 0;
    virtual void __stdcall Unused3() = 0;
    virtual void __stdcall Unused4() = 0;
    virtual void __stdcall Unused5() = 0;
    virtual void __stdcall Unused6() = 0;
    virtual void __stdcall Unused7() = 0;
    virtual void __stdcall Unused8() = 0;
    virtual void __stdcall Unused9() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused11() = 0;
    virtual void __stdcall Unused12() = 0;
    virtual void __stdcall Unused13() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused15() = 0;
    virtual void __stdcall Unused16() = 0;
    virtual void __stdcall Unused17() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused19() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused21() = 0;
    virtual void __stdcall Unused22() = 0;
    virtual void __stdcall Unused23() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused25() = 0;
    virtual void __stdcall Unused26() = 0;
    virtual void __stdcall Unused27() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused29() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused31() = 0;
    virtual void __stdcall Unused32() = 0;
    virtual void __stdcall Unused33() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused35() = 0;
    virtual void __stdcall Unused36() = 0;
    virtual void __stdcall Unused37() = 0;
    virtual int __stdcall SetTexture(unsigned int stage, D2TextureStrc* texture) = 0;
};
struct D2TextureCacheEntryStrc
{
    int unk00;
    D2TileLibraryEntryStrc* pTile;
    D2SurfaceStrc* pSurface;
    D2TextureStrc* pTexture;
    int unk10;
    int unk14;
};
struct D2TextureCacheStrc
{
    int nCount;
    char unk04[0x14];
    D2TextureCacheEntryStrc* pEntries;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
#define D2_ASSERT(expr,line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc*, int, int); // 0x005FDEA0
int __fastcall D3DFLOORCACHE_FloorCacheAdd(D2TextureCacheStrc*); // 0x006BB520
void __fastcall D3DFLOORCACHE_FloorCacheTouch(D2TextureCacheStrc*, int); // 0x006BB2D0
void __stdcall D3DFLOORCACHE_RenderTile(D2TileLibraryEntryStrc*, void*, int); // 0x006BB720
void __fastcall D3DCORE_LogDDrawError(const char*, int); // 0x006B20E0
void __fastcall D3DCORE_CopySurface(D2SurfaceStrc*, D2SurfaceStrc*, void*); // 0x006B38A0
extern D2TextureCacheStrc gTextureCache; // 0x0096FC9C
extern D2SurfaceStrc* gpMemorySurface; // 0x00989BF8
extern D2TextureStrc* gpMemoryTexture; // 0x00989BFC
extern D2DeviceStrc* gpDevice; // 0x00970E78
extern unsigned int gdwCapabilities; // 0x0096F3A8
extern const unsigned int gdwSurfaceCopyMask; // 0x006CE290
extern void* gpCopyContext; // 0x009702B8
extern const char gszLockError[]; // 0x006FC2A4
extern const char gszUnlockError[]; // 0x006FC284

// 0x006BB870
int __fastcall sub_006BB870_BindTileTexture(D2TileLibraryEntryStrc* pTile)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        D2_ASSERT(pTile->nCacheIndex >= 0, 0x191);
        if (pTile->nCacheIndex == 0)
        {
            pTile->nCacheIndex = D3DFLOORCACHE_FloorCacheAdd(&gTextureCache);
            const int nIndex = pTile->nCacheIndex - 1;
            D2_ASSERT(nIndex >= 0, 0x19C);
            D2_ASSERT(nIndex < gTextureCache.nCount, 0x19D);
            D2TextureCacheEntryStrc* pEntry = &gTextureCache.pEntries[pTile->nCacheIndex - 1];
            pEntry->pTile = pTile;
            {
                D2DDSurfaceDesc2Strc desc = { sizeof(D2DDSurfaceDesc2Strc) };
                int nError = gpMemorySurface->Lock(0, &desc, 0x21, 0);
                if (nError) D3DCORE_LogDDrawError(gszLockError, nError);
                D2_ASSERT(desc.dwFlags & 8, 0x1AD);
                D3DFLOORCACHE_RenderTile(pTile, desc.lpSurface, desc.lPitch >> 1);
                nError = gpMemorySurface->Unlock(0);
                if (nError) D3DCORE_LogDDrawError(gszUnlockError, nError);
            }
            if (gdwCapabilities & gdwSurfaceCopyMask)
                D3DCORE_CopySurface(pEntry->pSurface, gpMemorySurface, gpCopyContext);
            else
                pEntry->pTexture->Load(gpMemoryTexture);
            gpDevice->SetTexture(0, pEntry->pTexture);
        }
        else
        {
            D2TextureCacheEntryStrc* pEntry = &gTextureCache.pEntries[pTile->nCacheIndex - 1];
            D3DFLOORCACHE_FloorCacheTouch(&gTextureCache, pTile->nCacheIndex);
            gpDevice->SetTexture(0, pEntry->pTexture);
        }
        nResult = 1;
    }
    return nResult;
}
