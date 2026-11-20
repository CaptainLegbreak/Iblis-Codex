#include "D2Direct3D.h"

struct D2Direct3D006B7110Strc;
struct D2VertexBufferDescStrc;
struct D2Direct3DVtbl006B7110Strc;
struct D2ComObjectStrc;
struct D2ComVtblStrc;
struct D2CellFileStrc;
struct D2CelContext006B7090Strc;
struct D2TextureInfo006B7090Strc;

void __fastcall sub_006B1F40_SetBlendMode(int mode); // 0x006B1F40

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

void __stdcall sub_00601A30_StorePixelFreeHandler(PixelDataFreeCallback pfnCallback); // 0x00601A30
int __fastcall sub_006B3730_CreateSurface(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730
void __fastcall sub_006B39B0_ShowD3DError(const char* szText, long nResult); // 0x006B39B0
void __fastcall sub_006B5BB0_FreePixelData(void* pData); // 0x006B5BB0
extern D2Direct3D006B7110Strc* gpDirect3D_00970E64; // 0x00970E64
extern void* gpSpriteBuffer_00970F34; // 0x00970F34
extern void* gpSpriteBuffer_00970F38; // 0x00970F38
extern void* gpVertexBuffer_00970F3C; // 0x00970F3C
extern int gnVertexCount_00970F40; // 0x00970F40

struct D2ComVtblStrc
{
    long (__stdcall* QueryInterface)(D2ComObjectStrc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObjectStrc* pThis);
    unsigned long (__stdcall* Release)(D2ComObjectStrc* pThis);
};

struct D2ComObjectStrc
{
    D2ComVtblStrc* lpVtbl;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern D2ComObjectStrc* gpSpriteTextures_00970F1C[3]; // 0x00970F1C
extern D2ComObjectStrc* gpSpriteSurfaces_00970F28[3]; // 0x00970F28
extern D2ComObjectStrc* gpSpriteObject_00970F3C; // 0x00970F3C

struct D2CelContext006B7090Strc
{
    unsigned char unk_00[0x08];
    int nUnitType;
    int nClass;
    int nMode;
    unsigned char unk_14[0x18];
    const char* szName;
    unsigned char unk_30[0x0C];
    D2CellFileStrc* pCelFile;
};

struct D2TextureInfo006B7090Strc
{
    D2CelContext006B7090Strc* pContext;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int nTextureWidth;
    int nTextureHeight;
    int nTextureSize;
    float fU0;
    float fU1;
    float fV0;
    float fV1;
};
int __stdcall sub_006001F0_Prepare(D2CelContext006B7090Strc* pContext, int a2, int a3); // 0x006001F0
int __stdcall sub_006018C0_CelGetWidth(D2CellFileStrc* pCelFile); // 0x006018C0
int __stdcall sub_006018F0_CelGetHeight(D2CellFileStrc* pCelFile); // 0x006018F0
int __stdcall sub_00601920_CelGetOffsetX(D2CellFileStrc* pCelFile); // 0x00601920
int __stdcall sub_00601950_CelGetOffsetY(D2CellFileStrc* pCelFile); // 0x00601950
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
int __stdcall shim_7(D2CellFileStrc* pCelFile, int nWidth, int nHeight, int nMode, int* pArg1, int* pArg2);
int __stdcall shim_6(int nOffsetX, int nOffsetY, int nTextureWidth, int* pX, int* pY, int* pArg3, int* pArg4, int* pArg5, int* pArg6);
static __declspec(noinline) int __stdcall sub_006B5C80_LoadCelInfo(D2CelContext006B7090Strc* pContext, D2TextureInfo006B7090Strc* pInfo);
static __declspec(noinline) void __stdcall sub_006B5CF0_SetTextureSize(D2TextureInfo006B7090Strc* pInfo);
static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2TextureInfo006B7090Strc* pInfo, int nMode, int nArg1, int nArg2);
static __declspec(noinline) int __stdcall sub_006B63F0_DrawTexture(D2TextureInfo006B7090Strc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6);

void* gpSpriteBuffer_00970F34; // 0x00970F34

void* gpSpriteBuffer_00970F38; // 0x00970F38

// 0x006B5B10
void __cdecl sub_006B5B10_ReleaseSprites()
{
    if (gpSpriteObject_00970F3C)
    {
        gpSpriteObject_00970F3C->lpVtbl->Release(gpSpriteObject_00970F3C);
        gpSpriteObject_00970F3C = 0;
    }

    if (gpSpriteBuffer_00970F34)
    {
        FOG_Free(gpSpriteBuffer_00970F34, ".\\Src\\d3dSprite.cpp", 136, 0);
        gpSpriteBuffer_00970F34 = 0;
    }

    if (gpSpriteBuffer_00970F38)
    {
        FOG_Free(gpSpriteBuffer_00970F38, ".\\Src\\d3dSprite.cpp", 142, 0);
        gpSpriteBuffer_00970F38 = 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (gpSpriteTextures_00970F1C[i])
        {
            gpSpriteTextures_00970F1C[i]->lpVtbl->Release(gpSpriteTextures_00970F1C[i]);
            gpSpriteTextures_00970F1C[i] = 0;
        }

        if (gpSpriteSurfaces_00970F28[i])
        {
            gpSpriteSurfaces_00970F28[i]->lpVtbl->Release(gpSpriteSurfaces_00970F28[i]);
            gpSpriteSurfaces_00970F28[i] = 0;
        }
    }
}

// 0x006B5C80
static int __stdcall sub_006B5C80_LoadCelInfo(D2CelContext006B7090Strc* pContext, D2TextureInfo006B7090Strc* pInfo)
{
    if (!sub_006001F0_Prepare(pContext, 0, 1))
    {
        return 0;
    }

    if (!pContext->pCelFile)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", pContext->nUnitType, pContext->nClass, pContext->nMode, pContext->szName);
        return 0;
    }

    pInfo->pContext = pContext;
    pInfo->nWidth = sub_006018C0_CelGetWidth(pContext->pCelFile);
    pInfo->nOffsetX = sub_00601920_CelGetOffsetX(pContext->pCelFile);
    pInfo->nHeight = sub_006018F0_CelGetHeight(pContext->pCelFile);
    pInfo->nOffsetY = sub_00601950_CelGetOffsetY(pContext->pCelFile);
    return 1;
}

// 0x006B5CF0
static void __stdcall sub_006B5CF0_SetTextureSize(D2TextureInfo006B7090Strc* pInfo)
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
    pInfo->nTextureWidth = nSize;
    pInfo->nTextureHeight = nSize;
done:
    pInfo->nTextureSize = pInfo->nTextureHeight * pInfo->nTextureWidth;
    pInfo->fU0 = 0.0f;
    pInfo->fU1 = 1.0f;
    pInfo->fV0 = 0.0f;
    pInfo->fV1 = 1.0f;
}

static __declspec(noinline)
// 0x006B6680
unsigned char sub_006B6680_SetBlendAndAlpha(int mode)
{
    unsigned char alpha = 255;
    switch (mode)
    {
    case 5:
    case 7:
        sub_006B1F40_SetBlendMode(1);
        break;
    case 3:
        sub_006B1F40_SetBlendMode(2);
        break;
    case 4:
        sub_006B1F40_SetBlendMode(3);
        break;
    default:
        sub_006B1F40_SetBlendMode(4);
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
    return sub_006B6680_SetBlendAndAlpha(mode + 1);
}

// 0x006B6700
static __forceinline int sub_006B6700_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
    if (nX > gnScreenWidth_007C9138 || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnScreenHeight_007C913C)
        return 1;
    return 0;
}

// build: context sub_006B5D40_UploadTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B5D40_UploadTexture(D2TextureInfo006B7090Strc* pInfo, int nMode, int nArg1, int nArg2)
{
    return shim_7(pInfo->pContext->pCelFile, pInfo->nWidth, pInfo->nHeight, nMode == 4 ? 1 : nMode, &nArg1, &nArg2);
}

// build: context sub_006B63F0_DrawTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B63F0_DrawTexture(D2TextureInfo006B7090Strc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6)
{
    return shim_6(pInfo->nOffsetX, pInfo->nOffsetY, pInfo->nTextureWidth, &nX, &nY, &nArg3, &nArg4, &nArg5, &nArg6);
}

// 0x006B7090
int __fastcall sub_006B7090_DrawCel(D2CelContext006B7090Strc* pContext, int nX, int nY, int nArg)
{
    D2TextureInfo006B7090Strc tInfo;

    sub_006B1F40_SetBlendMode(4);
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
    n += sub_006B6700_IsOutsideScreen(nA, nB, pRect);
    return n;
}

// 0x006B7100
void __cdecl sub_006B7100_Nop()
{
}

void* gpTexture_00970F1C; // 0x00970F1C

void* gpTexture_00970F20; // 0x00970F20

void* gpTexture_00970F24; // 0x00970F24

void* gpSurface_00970F28; // 0x00970F28

void* gpSurface_00970F2C; // 0x00970F2C

void* gpSurface_00970F30; // 0x00970F30

// 0x006B7110
void __cdecl sub_006B7110_InitSprites()
{
    D2_ASSERT(!gpSpriteBuffer_00970F34, 0x55);
    D2_ASSERT(!gpSpriteBuffer_00970F38, 0x56);
    gpSpriteBuffer_00970F34 = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x57, 0);
    gpSpriteBuffer_00970F38 = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x58, 0);
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00970F28, &gpTexture_00970F1C, 0x100, 0x100), 0x5E);
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00970F2C, &gpTexture_00970F20, 0x80, 0x80), 0x61);
    D2_ASSERT(sub_006B3730_CreateSurface(&gpSurface_00970F30, &gpTexture_00970F24, 0x20, 0x20), 0x64);

    D2VertexBufferDescStrc tDesc = { sizeof(tDesc) };
    tDesc.dwCaps = 0x10800;
    tDesc.dwFVF = 0x1C4;
    tDesc.dwNumVertices = 0x30;
    const long nResult = gpDirect3D_00970E64->lpVtbl->CreateVertexBuffer(gpDirect3D_00970E64, &tDesc, &gpVertexBuffer_00970F3C, 4, 0);
    if (nResult)
    {
        sub_006B39B0_ShowD3DError("CreateVertexBuffer failed!", nResult);
        return;
    }

    gnVertexCount_00970F40 = 0;
    sub_00601A30_StorePixelFreeHandler(sub_006B5BB0_FreePixelData);
}
