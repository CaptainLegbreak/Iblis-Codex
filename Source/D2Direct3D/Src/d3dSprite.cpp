#include "D2Direct3D.h"

#include "D2CelContext.h"

#include "D2D3DTypes.h"

struct D2Direct3D006B7110Strc;

struct D2VertexBufferDescStrc;

struct D2Direct3DVtbl006B7110Strc;

struct D2CelFileStrc;

void __fastcall D3D_SetAlphaBlendMode(int mode); // 0x006B1F40

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2VertexBufferDescStrc
{
    unsigned int dwSize;
    unsigned int dwCaps;
    unsigned int dwFVF;
    unsigned int dwNumVertices;
};

struct D2Direct3DVtbl006B7110Strc
{
    void* unknown0[9];
    long (__stdcall* CreateVertexBuffer)(D2Direct3D006B7110Strc* pThis, D2VertexBufferDescStrc* pDesc, void** ppVertexBuffer, unsigned int dwFlags, void* pUnknown);
};

struct D2Direct3D006B7110Strc
{
    D2Direct3DVtbl006B7110Strc* lpVtbl;
};

typedef void (__fastcall* PixelDataFreeCallback)(void* pData);

void __stdcall CelSetHardwareFreeCallback(PixelDataFreeCallback pfnCallback); // 0x00601A30

int __fastcall D3D_CreateMemoryTexture(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730

void __fastcall sub_006B39B0_ShowD3DError(const char* szText, long nResult); // 0x006B39B0

void __fastcall sub_006B5BB0_FreePixelData(void* pData); // 0x006B5BB0

extern D2Direct3D006B7110Strc* gpDirect3D_00970E64; // 0x00970E64

extern void* gpSpriteBuffer; // 0x00970F34

extern void* gpSpriteOutlineBuffer; // 0x00970F38

extern void* gpVertexBuffer; // 0x00970F3C

extern int gnVertexCount_00970F40; // 0x00970F40

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

extern D2D3DObjStrc* gapSpriteTextures[3]; // 0x00970F1C

extern D2D3DObjStrc* gapSpriteSurfaces[3]; // 0x00970F28

extern D2D3DObjStrc* gpSpriteObject_00970F3C; // 0x00970F3C

int __stdcall sub_006001F0_Prepare(D2CelContextStrc* pContext, int a2, int a3); // 0x006001F0

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920

int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

int __stdcall shim_7(D2CelStrc* pCel, int nWidth, int nHeight, int nMode, int* pArg1, int* pArg2);

int __stdcall shim_6(int nOffsetX, int nOffsetY, int nTextureWidth, int* pX, int* pY, int* pArg3, int* pArg4, int* pArg5, int* pArg6);

static int __stdcall sub_006B5C80_LoadCelInfo(D2CelContextStrc* pContext, D2SpriteInfoStrc* pInfo);

static void __stdcall sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);

static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg1, int nArg2);

static __declspec(noinline) int __stdcall sub_006B63F0_DrawTexture(D2SpriteInfoStrc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6);

void* gpSpriteBuffer; // 0x00970F34

void* gpSpriteOutlineBuffer; // 0x00970F38

// 0x006B5B10
void __cdecl D3D_ReleaseSprites()
{
    if (gpSpriteObject_00970F3C)
    {
        gpSpriteObject_00970F3C->lpVtbl->Release(gpSpriteObject_00970F3C);
        gpSpriteObject_00970F3C = 0;
    }

    if (gpSpriteBuffer)
    {
        FOG_Free(gpSpriteBuffer, ".\\Src\\d3dSprite.cpp", 136, 0);
        gpSpriteBuffer = 0;
    }

    if (gpSpriteOutlineBuffer)
    {
        FOG_Free(gpSpriteOutlineBuffer, ".\\Src\\d3dSprite.cpp", 142, 0);
        gpSpriteOutlineBuffer = 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (gapSpriteTextures[i])
        {
            gapSpriteTextures[i]->lpVtbl->Release(gapSpriteTextures[i]);
            gapSpriteTextures[i] = 0;
        }

        if (gapSpriteSurfaces[i])
        {
            gapSpriteSurfaces[i]->lpVtbl->Release(gapSpriteSurfaces[i]);
            gapSpriteSurfaces[i] = 0;
        }
    }
}

struct D2ResourceEntryStrc { int value0; int value4; int rest[6]; };
struct D2ResourceGroupStrc { D2ResourceEntryStrc* entries; int rest[6]; };
struct D2ResourcePairStrc { int group; int entry; };
struct D2ResourceSetStrc { D2ResourcePairStrc pairs[5]; };
extern D2ResourceGroupStrc gaResourceGroups[]; // 0x00970EE0

// 0x006B5BB0
void __fastcall sub_006B5BB0_ClearResourceEntries(D2ResourceSetStrc* set)
{
    for (int i = 0; i < 5; ++i)
    {
        int group = set->pairs[i].group - 1;
        if (group >= 0)
        {
            int entry = set->pairs[i].entry - 1;
            if (entry >= 0)
                gaResourceGroups[group].entries[entry].value4 = 0;
        }
    }
}

// 0x006B5C80
static int __stdcall sub_006B5C80_LoadCelInfo(D2CelContextStrc* pContext, D2SpriteInfoStrc* pInfo)
{
    if (!sub_006001F0_Prepare(pContext, 0, 1))
    {
        return 0;
    }

    if (!pContext->pCel)
    {
        LOGMANAGER_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", pContext->nType, pContext->nClass, pContext->nMode, pContext->szName);
        return 0;
    }

    pInfo->pContext = pContext;
    pInfo->nWidth = CelGetWidth(pContext->pCel);
    pInfo->nOffsetX = CelGetOffsetX(pContext->pCel);
    pInfo->nHeight = CelGetHeight(pContext->pCel);
    pInfo->nOffsetY = CelGetOffsetY(pContext->pCel);
    return 1;
}

// 0x006B5CF0
static void __stdcall sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo)
{
    int nSize = 0x20;
    if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
    {
        nSize = 0x80;
        if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
        {
            nSize = 0x100;
            if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
            {
                goto done;
            }
        }
    }
    pInfo->nTexWidth = nSize;
    pInfo->nTexHeight = nSize;
done:
    pInfo->nTexSize = pInfo->nTexHeight * pInfo->nTexWidth;
    pInfo->fU0 = 0.0f;
    pInfo->fU1 = 1.0f;
    pInfo->fV0 = 0.0f;
    pInfo->fV1 = 1.0f;
}

static
// 0x006B6680
unsigned char D3D_SetBlendAndAlpha(int mode)
{
    unsigned char alpha = 255;
    switch (mode)
    {
    case 5:
    case 7:
        D3D_SetAlphaBlendMode(1);
        break;
    case 3:
        D3D_SetAlphaBlendMode(2);
        break;
    case 4:
        D3D_SetAlphaBlendMode(3);
        break;
    default:
        D3D_SetAlphaBlendMode(4);
        if (mode == 0)
            alpha = 64;
        else if (mode == 1)
            alpha = 128;
        else if (mode == 2)
            alpha = 192;
        break;
    }
    return alpha;
}

unsigned char __fastcall EmitSetBlendAndAlpha(int mode)
{
    return D3D_SetBlendAndAlpha(mode + 1);
}

// 0x006B6700
static inline int D3D_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
// build: symbol ?gnRenderWidth@* 0x007C9138
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nX > gnRenderWidth || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnRenderHeight)
        return 1;
    return 0;
}

// build: context sub_006B5D40_UploadTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg1, int nArg2)
{
    return shim_7(pInfo->pContext->pCel, pInfo->nWidth, pInfo->nHeight, nMode == 4 ? 1 : nMode, &nArg1, &nArg2);
}

// build: context sub_006B63F0_DrawTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B63F0_DrawTexture(D2SpriteInfoStrc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6)
{
    return shim_6(pInfo->nOffsetX, pInfo->nOffsetY, pInfo->nTexWidth, &nX, &nY, &nArg3, &nArg4, &nArg5, &nArg6);
}

// 0x006B7090
int __fastcall D3D_CelDrawHilight(D2CelContextStrc* pContext, int nX, int nY, int nArg)
{
    D2SpriteInfoStrc tInfo;

    D3D_SetAlphaBlendMode(4);
    int nResult = sub_006B5C80_LoadCelInfo(pContext, &tInfo);
    if (nResult)
    {
        tInfo.nWidth += 2;
        tInfo.nHeight += 2;
        sub_006B5CF0_SetTextureSize(&tInfo);
        nResult = sub_006B5D40_UploadTexture(&tInfo, 3, 0, nArg);
        if (nResult)
        {
            nResult = sub_006B63F0_DrawTexture(&tInfo, nX - 1, nY + 1, -1, 0, 0x40, 1);
        }
    }
    return nResult;
}

// calling-convention shim (not game code)
int __fastcall sub_006B6700_Shim(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = nA * 3;
    n += D3D_IsOutsideScreen(nA, nB, pRect);
    return n;
}

// 0x006B7100
void __cdecl D3D_DebugFillBackBuffer()
{
}

void* gpTexture_00970F1C; // 0x00970F1C

void* gpSpriteTexture128; // 0x00970F20

void* gpSpriteTexture32; // 0x00970F24

void* gpSurface_00970F28; // 0x00970F28

void* gpSpriteSurface128; // 0x00970F2C

void* gpSpriteSurface32; // 0x00970F30

// 0x006B7110
void __cdecl D3D_InitSprites()
{
    D2_ASSERT(!gpSpriteBuffer, 0x55);
    D2_ASSERT(!gpSpriteOutlineBuffer, 0x56);
    gpSpriteBuffer = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x57, 0);
    gpSpriteOutlineBuffer = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x58, 0);
    D2_ASSERT(D3D_CreateMemoryTexture(&gpSurface_00970F28, &gpTexture_00970F1C, 0x100, 0x100), 0x5E);
    D2_ASSERT(D3D_CreateMemoryTexture(&gpSpriteSurface128, &gpSpriteTexture128, 0x80, 0x80), 0x61);
    D2_ASSERT(D3D_CreateMemoryTexture(&gpSpriteSurface32, &gpSpriteTexture32, 0x20, 0x20), 0x64);

    D2VertexBufferDescStrc tDesc = { sizeof(tDesc) };
    tDesc.dwCaps = 0x10800;
    tDesc.dwFVF = 0x1C4;
    tDesc.dwNumVertices = 0x30;
    const long nResult = gpDirect3D_00970E64->lpVtbl->CreateVertexBuffer(gpDirect3D_00970E64, &tDesc, &gpVertexBuffer, 4, 0);
    if (nResult)
    {
        sub_006B39B0_ShowD3DError("CreateVertexBuffer failed!", nResult);
        return;
    }

    gnVertexCount_00970F40 = 0;
    CelSetHardwareFreeCallback(sub_006B5BB0_FreePixelData);
}
