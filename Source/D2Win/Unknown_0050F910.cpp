#include "D2Win.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DDrawSurfaceStrc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu); // 0x00509460
void __fastcall sub_0050F0F0_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F0F0
short __fastcall sub_0050F2B0_TileCacheAdd(D2GlideTileCacheStrc* pCache); // 0x0050F2B0
extern D2GrTexInfoStrc gGlideTileTexInfo_0072F6A8; // 0x0072F6A8
extern D2GlideTileCacheStrc gGlideTileCache_0087EB48; // 0x0087EB48
extern int gnGlideTileTmu_00880BF8; // 0x00880BF8
extern unsigned char* gpGlideTileDecodeBuffer_00880BFC; // 0x00880BFC

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags); // 0x006CC5B8
extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink); // 0x006CC5C8
extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink); // 0x006CC5CC
extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDrawSurfaceStrc* pSurface); // 0x006CC5D0
extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam); // 0x006CC5D4
extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam); // 0x006CC5D8
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
void __cdecl sub_0050FD10_GlideDrawVideoFrame(); // 0x0050FD10
void __cdecl sub_005136F0_BlitBinkFrame(); // 0x005136F0
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume); // 0x00515CE0
extern int gnScreenHeight_007C913C; // 0x007C913C
extern unsigned int gnGlideBinkY_00880C04; // 0x00880C04
extern unsigned int gnGlideBinkFlags_00880C14; // 0x00880C14
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881278; // 0x00881278
extern unsigned int gnDDrawBinkY_008816B8; // 0x008816B8
extern unsigned int gnDDrawBinkFlags_008816C8; // 0x008816C8

void __fastcall sub_00510160_DDrawSetPalette(tagPALETTEENTRY* pPalette); // 0x00510160
extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150
extern tagPALETTEENTRY gaDDrawSavedPalette_00880D40[256]; // 0x00880D40

// 0x0050F910
static void sub_0050F910_DecodeTileRuns(const unsigned char* pData, unsigned char* pDst)
{
    int nRows = 0x20;
    unsigned char* pRow = pDst;
    unsigned char* p = pDst;
    const unsigned char* pSrc = pData;
    memset(pDst, 0, 0x400);

    do
    {
        const unsigned char nGap = *pSrc++;
        unsigned char nCount = *pSrc++;
        if (!nGap && !nCount)
        {
            --nRows;
            pRow += 0x20;
            p = pRow;
        }
        else
        {
            p += nGap;
            while (nCount--)
            {
                *p++ = *pSrc++;
            }
        }
    }
    while (nRows);
}

D2GlideTileCacheStrc gGlideTileCache_0087EB48; // 0x0087EB48

int gnGlideTileTmu_00880BF8; // 0x00880BF8

// 0x0050FBD0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile)
{
    D2_ASSERT(pTile->nCacheIndex >= 0, 0x105);

    int nTexAddress;
    if (pTile->nCacheIndex == 0)
    {
        sub_0050F910_DecodeTileRuns(pTile->pData, gpGlideTileDecodeBuffer_00880BFC);
        pTile->nCacheIndex = sub_0050F2B0_TileCacheAdd(&gGlideTileCache_0087EB48);
        const int nEntry = pTile->nCacheIndex - 1;
        D2_ASSERT(nEntry >= 0, 0x112);
        D2_ASSERT(nEntry < gGlideTileCache_0087EB48.nCount, 0x113);
        gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].pTile = pTile;
        nTexAddress = gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].nAddress;
        gpfGlideTexDownloadMipMap_0087EAB8(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideTileTexInfo_0072F6A8);
    }
    else
    {
        sub_0050F0F0_TileCacheTouch(&gGlideTileCache_0087EB48, pTile->nCacheIndex);
        nTexAddress = gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].nAddress;
    }

    gpfGlideTexSource_0087EB98(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideTileTexInfo_0072F6A8);
    sub_00509460_GlideSelectTmuState(gnGlideTileTmu_00880BF8);
}

#include "gen/data/Source/D2Win/Unknown_0050F910.inc"

unsigned int gnGlideBinkX_00880C08; // 0x00880C08

D2BinkStrc* gpGlideBink_00880C0C; // 0x00880C0C

int gbGlideBinkDone_00880C18; // 0x00880C18

unsigned long gdwGlideBinkAbortTick_00880C1C; // 0x00880C1C

unsigned int gnDDrawBinkX_008816BC; // 0x008816BC

D2BinkStrc* gpDDrawBink_008816C0; // 0x008816C0

int gbDDrawBinkDone_008816CC; // 0x008816CC

int gbDDrawBinkQuit_008816D0; // 0x008816D0

unsigned long gdwDDrawBinkAbortTick_008816D4; // 0x008816D4

// 0x0050FDF0
void __fastcall sub_0050FDF0_GlidePlayVideoFile(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbGlideBinkDone_00880C18 = 0;
    if (gpGlideBink_00880C0C)
    {
        return;
    }
    if (gbRenderPaused_007C9144)
    {
        return;
    }

    gnGlideBinkFlags_00880C14 = 2;
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (sub_00406D20())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto LABEL_FAIL;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpGlideBink_00880C0C = BinkOpen(hFile, nFlags);
    if (!gpGlideBink_00880C0C)
    {
        CloseHandle(hFile);
LABEL_FAIL:
        if (gpGlideBink_00880C0C)
        {
            BinkClose(gpGlideBink_00880C0C);
            gpGlideBink_00880C0C = 0;
        }
        return;
    }

    gnGlideBinkX_00880C08 = (gnScreenWidth_007C9138 - gpGlideBink_00880C0C->nWidth) >> 1;
    if (gnGlideBinkX_00880C08 & 3)
    {
        gnGlideBinkX_00880C08 = (gnGlideBinkX_00880C08 | 3) + 1;
    }
    gnGlideBinkY_00880C04 = (gnScreenHeight_007C913C - gpGlideBink_00880C0C->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbGlideBinkDone_00880C18 && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused_007C9144)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbGlideBinkDone_00880C18 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwGlideBinkAbortTick_00880C1C = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpGlideBink_00880C0C))
            {
                sub_0050FD10_GlideDrawVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpGlideBink_00880C0C)
    {
        sub_00515CE0_SetMasterVolume(0);
        BinkClose(gpGlideBink_00880C0C);
        CloseHandle(hFile);
        sub_00515CE0_SetMasterVolume(0xFF);
        gpGlideBink_00880C0C = 0;
    }
}

// 0x005137E0
void __fastcall sub_005137E0_PlayBinkMovie(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbDDrawBinkDone_008816CC = 0;
    if (gpDDrawBink_008816C0)
    {
        return;
    }
    if (gbRenderPaused_007C9144)
    {
        return;
    }

    gnDDrawBinkFlags_008816C8 = BinkDDSurfaceType(gpDDrawSurface_00881278);
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (sub_00406D20())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto LABEL_FAIL;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpDDrawBink_008816C0 = BinkOpen(hFile, nFlags);
    if (!gpDDrawBink_008816C0)
    {
        CloseHandle(hFile);
LABEL_FAIL:
        if (gpDDrawBink_008816C0)
        {
            BinkClose(gpDDrawBink_008816C0);
            gpDDrawBink_008816C0 = 0;
        }
        return;
    }

    gnDDrawBinkX_008816BC = (gnScreenWidth_007C9138 - gpDDrawBink_008816C0->nWidth) >> 1;
    if (gnDDrawBinkX_008816BC & 3)
    {
        gnDDrawBinkX_008816BC = (gnDDrawBinkX_008816BC | 3) + 1;
    }
    gnDDrawBinkY_008816B8 = (gnScreenHeight_007C913C - gpDDrawBink_008816C0->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbDDrawBinkDone_008816CC && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused_007C9144)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbDDrawBinkDone_008816CC = 1;
                    gbDDrawBinkQuit_008816D0 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwDDrawBinkAbortTick_008816D4 = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpDDrawBink_008816C0))
            {
                sub_005136F0_BlitBinkFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpDDrawBink_008816C0)
    {
        sub_00515CE0_SetMasterVolume(0);
        BinkClose(gpDDrawBink_008816C0);
        CloseHandle(hFile);
        sub_00515CE0_SetMasterVolume(0xFF);
        gpDDrawBink_008816C0 = 0;
    }
    if (gbDDrawBinkQuit_008816D0)
    {
        exit(-1);
    }
}

// 0x00510130
void __fastcall sub_00510130_DDrawNop()
{
}

// 0x005102F0
void __fastcall sub_005102F0_DDrawNop()
{
}

// 0x00510330
void __fastcall sub_00510330_DDrawNop()
{
}

// 0x00510340
void __fastcall sub_00510340_DDrawStub5(int a1, int a2, int a3, int a4, int a5)
{
}

// 0x00510350
void __fastcall sub_00510350_DDrawStub6(int a1, int a2, int a3, int a4, int a5, int a6)
{
}

// 0x00510360
void __fastcall sub_00510360_DDrawNop()
{
}

D2PaletteTableStrc gtDDrawPaletteView_00880C20; // 0x00880C20

// 0x00510150
void __fastcall sub_00510150_DDrawGetScreenSize(int* pWidth, int* pHeight)
{
    *pWidth = gnScreenWidth_007C9138;
    *pHeight = gnScreenHeight_007C913C;
}

// 0x005102D0
void __fastcall sub_005102D0_DDrawSetPaletteView(D2PaletteTableStrc* pSource)
{
    gtDDrawPaletteView_00880C20 = *pSource;
    gpGfxPaletteView_007C9150 = &gtDDrawPaletteView_00880C20;
}

// 0x00510300
void __fastcall sub_00510300_DDrawSetGamma(int nGamma)
{
    gnDDrawGamma_0072F7CC = nGamma;
    sub_00510160_DDrawSetPalette(gaDDrawSavedPalette_00880D40);
}

// 0x00510390
int __fastcall sub_00510390_DDrawSetOption(int nOption, int nValue)
{
    switch (nOption)
    {
    case 11:
        gnDDrawGammaScale_0072F7C8 = nValue;
        return 1;
    }
    return 0;
}

// 0x005103B0
void __fastcall sub_005103B0_DDrawLogError(const char* szWhere, int hResult)
{
    if (hResult == (int)0x887601AE || hResult == (int)0x887601C2)
    {
        return;
    }

    const char* szError;
    switch (hResult)
    {
    case (int)0x80004005: szError = "DDERR_GENERIC"; break;
    case (int)0x80004001: szError = "DDERR_UNSUPPORTED"; break;
    case (int)0x800401F0: szError = "DDERR_NOTINITIALIZED"; break;
    case (int)0x80070057: szError = "DDERR_INVALIDPARAMS"; break;
    case (int)0x8007000E: szError = "DDERR_OUTOFMEMORY"; break;
    case (int)0x88760005: szError = "DDERR_ALREADYINITIALIZED"; break;
    case (int)0x8876000A: szError = "DDERR_CANNOTATTACHSURFACE"; break;
    case (int)0x88760014: szError = "DDERR_CANNOTDETACHSURFACE"; break;
    case (int)0x88760028: szError = "DDERR_CURRENTLYNOTAVAIL"; break;
    case (int)0x88760037: szError = "DDERR_EXCEPTION"; break;
    case (int)0x8876005A: szError = "DDERR_HEIGHTALIGN"; break;
    case (int)0x8876005F: szError = "DDERR_INCOMPATIBLEPRIMARY"; break;
    case (int)0x88760064: szError = "DDERR_INVALIDCAPS"; break;
    case (int)0x8876006E: szError = "DDERR_INVALIDCLIPLIST"; break;
    case (int)0x88760078: szError = "DDERR_INVALIDMODE"; break;
    case (int)0x88760082: szError = "DDERR_INVALIDOBJECT"; break;
    case (int)0x88760091: szError = "DDERR_INVALIDPIXELFORMAT"; break;
    case (int)0x88760096: szError = "DDERR_INVALIDRECT"; break;
    case (int)0x887600A0: szError = "DDERR_LOCKEDSURFACES"; break;
    case (int)0x887600AA: szError = "DDERR_NO3D"; break;
    case (int)0x887600B4: szError = "DDERR_NOALPHAHW"; break;
    case (int)0x887600CD: szError = "DDERR_NOCLIPLIST"; break;
    case (int)0x887600D2: szError = "DDERR_NOCOLORCONVHW"; break;
    case (int)0x887600D4: szError = "DDERR_NOCOOPERATIVELEVELSET"; break;
    case (int)0x887600D7: szError = "DDERR_NOCOLORKEY"; break;
    case (int)0x887600DC: szError = "DDERR_NOCOLORKEYHW"; break;
    case (int)0x887600DE: szError = "DDERR_NODIRECTDRAWSUPPORT"; break;
    case (int)0x887600E1: szError = "DDERR_NOEXCLUSIVEMODE"; break;
    case (int)0x887600E6: szError = "DDERR_NOFLIPHW"; break;
    case (int)0x887600F0: szError = "DDERR_NOGDI"; break;
    case (int)0x887600FA: szError = "DDERR_NOMIRRORHW"; break;
    case (int)0x887600FF: szError = "DDERR_NOTFOUND"; break;
    case (int)0x88760104: szError = "DDERR_NOOVERLAYHW"; break;
    case (int)0x88760118: szError = "DDERR_NORASTEROPHW"; break;
    case (int)0x88760122: szError = "DDERR_NOROTATIONHW"; break;
    case (int)0x88760136: szError = "DDERR_NOSTRETCHHW"; break;
    case (int)0x8876013C: szError = "DDERR_NOT4BITCOLOR"; break;
    case (int)0x8876013D: szError = "DDERR_NOT4BITCOLORINDEX"; break;
    case (int)0x88760140: szError = "DDERR_NOT8BITCOLOR"; break;
    case (int)0x8876014A: szError = "DDERR_NOTEXTUREHW"; break;
    case (int)0x8876014F: szError = "DDERR_NOVSYNCHW"; break;
    case (int)0x88760154: szError = "DDERR_NOZBUFFERHW"; break;
    case (int)0x8876015E: szError = "DDERR_NOZOVERLAYHW"; break;
    case (int)0x88760168: szError = "DDERR_OUTOFCAPS"; break;
    case (int)0x8876017C: szError = "DDERR_OUTOFVIDEOMEMORY"; break;
    case (int)0x8876017E: szError = "DDERR_OVERLAYCANTCLIP"; break;
    case (int)0x88760180: szError = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE"; break;
    case (int)0x88760183: szError = "DDERR_PALETTEBUSY"; break;
    case (int)0x88760190: szError = "DDERR_COLORKEYNOTSET"; break;
    case (int)0x8876019A: szError = "DDERR_SURFACEALREADYATTACHED"; break;
    case (int)0x887601A4: szError = "DDERR_SURFACEALREADYDEPENDENT"; break;
    case (int)0x887601AE: szError = "DDERR_SURFACEBUSY"; break;
    case (int)0x887601B3: szError = "DDERR_CANTLOCKSURFACE"; break;
    case (int)0x887601B8: szError = "DDERR_SURFACEISOBSCURED"; break;
    case (int)0x887601C2: szError = "DDERR_SURFACELOST"; break;
    case (int)0x887601CC: szError = "DDERR_SURFACENOTATTACHED"; break;
    case (int)0x887601D6: szError = "DDERR_TOOBIGHEIGHT"; break;
    case (int)0x887601E0: szError = "DDERR_TOOBIGSIZE"; break;
    case (int)0x887601EA: szError = "DDERR_TOOBIGWIDTH"; break;
    case (int)0x887601FE: szError = "DDERR_UNSUPPORTEDFORMAT"; break;
    case (int)0x88760208: szError = "DDERR_UNSUPPORTEDMASK"; break;
    case (int)0x88760219: szError = "DDERR_VERTICALBLANKINPROGRESS"; break;
    case (int)0x8876021C: szError = "DDERR_WASSTILLDRAWING"; break;
    case (int)0x88760230: szError = "DDERR_XALIGN"; break;
    case (int)0x88760231: szError = "DDERR_INVALIDDIRECTDRAWGUID"; break;
    case (int)0x88760232: szError = "DDERR_DIRECTDRAWALREADYCREATED"; break;
    case (int)0x88760233: szError = "DDERR_NODIRECTDRAWHW"; break;
    case (int)0x88760234: szError = "DDERR_PRIMARYSURFACEALREADYEXISTS"; break;
    case (int)0x88760235: szError = "DDERR_NOEMULATION"; break;
    case (int)0x88760236: szError = "DDERR_REGIONTOOSMALL"; break;
    case (int)0x88760237: szError = "DDERR_CLIPPERISUSINGHWND"; break;
    case (int)0x88760238: szError = "DDERR_NOCLIPPERATTACHED"; break;
    case (int)0x88760239: szError = "DDERR_NOHWND"; break;
    case (int)0x8876023A: szError = "DDERR_HWNDSUBCLASSED"; break;
    case (int)0x8876023B: szError = "DDERR_HWNDALREADYSET"; break;
    case (int)0x8876023C: szError = "DDERR_NOPALETTEATTACHED"; break;
    case (int)0x8876023D: szError = "DDERR_NOPALETTEHW"; break;
    case (int)0x8876023E: szError = "DDERR_BLTFASTCANTCLIP"; break;
    case (int)0x8876023F: szError = "DDERR_NOBLTHW"; break;
    case (int)0x88760240: szError = "DDERR_NODDROPSHW"; break;
    case (int)0x88760241: szError = "DDERR_OVERLAYNOTVISIBLE"; break;
    case (int)0x88760242: szError = "DDERR_NOOVERLAYDEST"; break;
    case (int)0x88760243: szError = "DDERR_INVALIDPOSITION"; break;
    case (int)0x88760244: szError = "DDERR_NOTAOVERLAYSURFACE"; break;
    case (int)0x88760245: szError = "DDERR_EXCLUSIVEMODEALREADYSET"; break;
    case (int)0x88760246: szError = "DDERR_NOTFLIPPABLE"; break;
    case (int)0x88760247: szError = "DDERR_CANTDUPLICATE"; break;
    case (int)0x88760248: szError = "DDERR_NOTLOCKED"; break;
    case (int)0x88760249: szError = "DDERR_CANTCREATEDC"; break;
    case (int)0x8876024A: szError = "DDERR_NODC"; break;
    case (int)0x8876024B: szError = "DDERR_WRONGMODE"; break;
    case (int)0x8876024C: szError = "DDERR_IMPLICITLYCREATED"; break;
    case (int)0x8876024D: szError = "DDERR_NOTPALETTIZED"; break;
    case (int)0x8876024E: szError = "DDERR_UNSUPPORTEDMODE"; break;
    case (int)0x8876024F: szError = "DDERR_NOMIPMAPHW"; break;
    case (int)0x88760250: szError = "DDERR_INVALIDSURFACETYPE"; break;
    case (int)0x88760258: szError = "DDERR_NOOPTIMIZEHW"; break;
    case (int)0x88760259: szError = "DDERR_NOTLOADED"; break;
    case (int)0x8876026C: szError = "DDERR_DCALREADYCREATED"; break;
    case (int)0x88760276: szError = "DDERR_NONONLOCALVIDMEM"; break;
    case (int)0x88760280: szError = "DDERR_CANTPAGELOCK"; break;
    case (int)0x88760294: szError = "DDERR_CANTPAGEUNLOCK"; break;
    case (int)0x887602A8: szError = "DDERR_NOTPAGELOCKED"; break;
    case (int)0x887602B2: szError = "DDERR_MOREDATA"; break;
    case (int)0x887602B7: szError = "DDERR_VIDEONOTACTIVE"; break;
    case (int)0x887602BB: szError = "DDERR_DEVICEDOESNTOWNSURFACE"; break;
    case (int)0x00000000: szError = "DD_OK"; break;
    default: szError = "< unknown >"; break;
    }

    sub_00410610_WriteLogLine("***** DirectDraw error: %s - %s (0x%x)", szWhere, szError, hResult);
}

// 0x00510310
int __cdecl sub_00510310_ReturnOne()
{
    return 1;
}
