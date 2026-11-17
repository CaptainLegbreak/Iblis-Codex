#include "D2Direct3D.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Direct3D006B7110Strc;
struct D2GlideRectViewStrc;
struct D2VertexBufferDescStrc;
struct D2Direct3DVtbl006B7110Strc;

void __fastcall sub_006B1F40_SetBlendMode(int mode); // 0x006B1F40

struct D2GlideRectViewStrc
{
    int unk0x00;
    int nLeft;
    int nTop;
    int nOffsetX;
    int nOffsetY;
};
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
extern void* gpBuffer_00970F34; // 0x00970F34
extern void* gpBuffer_00970F38; // 0x00970F38
extern void* gpVertexBuffer_00970F3C; // 0x00970F3C
extern int gnVertexCount_00970F40; // 0x00970F40

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
    D2_ASSERT(!gpBuffer_00970F34, 0x55);
    D2_ASSERT(!gpBuffer_00970F38, 0x56);
    gpBuffer_00970F34 = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x57, 0);
    gpBuffer_00970F38 = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x58, 0);
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
