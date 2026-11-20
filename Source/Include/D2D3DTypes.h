#pragma once
// D2Direct3D: Direct3D device, vertex buffer and texture interfaces, TL vertex and sprite info layouts

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelContextStrc;
struct D2TLVertexStrc;
struct D2QuadRectStrc;
struct D2SpriteInfoStrc;
struct D2VertexBufferVtbl;
struct D2VertexBufferStrc;
struct D2D3DTextureVtbl;
struct D2D3DTextureStrc;
struct D2D3DDeviceVtbl;
struct D2D3DDeviceStrc;

struct D2TLVertexStrc
{
    float fX; // 0x00
    float fY; // 0x04
    float fZ; // 0x08
    float fRhw; // 0x0C
    unsigned int dwColor; // 0x10
    unsigned int dwSpecular; // 0x14
    float fU; // 0x18
    float fV; // 0x1C
};

struct D2QuadRectStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int nWidth; // 0x08
    int nHeight; // 0x0C
};

struct D2SpriteInfoStrc
{
    D2CelContextStrc* pContext; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nOffsetX; // 0x0C
    int nOffsetY; // 0x10
    int nTexWidth; // 0x14
    int nTexHeight; // 0x18
    int nTexSize; // 0x1C
    float fU0; // 0x20
    float fU1; // 0x24
    float fV0; // 0x28
    float fV1; // 0x2C
};

struct D2VertexBufferVtbl
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    void* Release; // 0x08
    long (__stdcall* Lock)(D2VertexBufferStrc* pThis, unsigned long dwFlags, void** ppData, unsigned long* pSize); // 0x0C
    long (__stdcall* Unlock)(D2VertexBufferStrc* pThis); // 0x10
    void* ProcessVertices; // 0x14
    void* GetVertexBufferDesc; // 0x18
    void* Optimize; // 0x1C
};

struct D2VertexBufferStrc
{
    D2VertexBufferVtbl* lpVtbl; // 0x00
};

struct D2D3DTextureVtbl
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    unsigned long (__stdcall* Release)(D2D3DTextureStrc* pThis); // 0x08
    void* GetHandle; // 0x0C
    void* PaletteChanged; // 0x10
    long (__stdcall* Load)(D2D3DTextureStrc* pThis, D2D3DTextureStrc* pSource); // 0x14
};

struct D2D3DTextureStrc
{
    D2D3DTextureVtbl* lpVtbl; // 0x00
};

struct D2D3DDeviceVtbl
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    void* Release; // 0x08
    void* GetCaps; // 0x0C
    void* GetStats; // 0x10
    void* AddViewport; // 0x14
    void* DeleteViewport; // 0x18
    void* NextViewport; // 0x1C
    void* EnumTextureFormats; // 0x20
    void* BeginScene; // 0x24
    void* EndScene; // 0x28
    void* GetDirect3D; // 0x2C
    void* SetCurrentViewport; // 0x30
    void* GetCurrentViewport; // 0x34
    void* SetRenderTarget; // 0x38
    void* GetRenderTarget; // 0x3C
    void* Begin; // 0x40
    void* BeginIndexed; // 0x44
    void* Vertex; // 0x48
    void* Index; // 0x4C
    void* End; // 0x50
    void* GetRenderState; // 0x54
    void* SetRenderState; // 0x58
    void* GetLightState; // 0x5C
    void* SetLightState; // 0x60
    void* SetTransform; // 0x64
    void* GetTransform; // 0x68
    void* MultiplyTransform; // 0x6C
    long (__stdcall* DrawPrimitive)(D2D3DDeviceStrc* pThis, int nType, unsigned int dwFVF, void* pVertices, unsigned int nCount, unsigned int dwFlags); // 0x70
    long (__stdcall* DrawIndexedPrimitive)(D2D3DDeviceStrc* pThis, int nType, unsigned int dwFVF, D2TLVertexStrc* pVertices, unsigned int nVertices, unsigned short* pIndices, unsigned int nIndices, unsigned int dwFlags); // 0x74
    void* SetClipStatus; // 0x78
    void* GetClipStatus; // 0x7C
    void* DrawPrimitiveStrided; // 0x80
    void* DrawIndexedPrimitiveStrided; // 0x84
    long (__stdcall* DrawPrimitiveVB)(D2D3DDeviceStrc* pThis, int nType, D2VertexBufferStrc* pBuffer, unsigned long dwStart, unsigned long dwCount, unsigned long dwFlags); // 0x88
    long (__stdcall* DrawIndexedPrimitiveVB)(D2D3DDeviceStrc* pThis, int nType, D2VertexBufferStrc* pBuffer, unsigned short* pIndices, unsigned int nIndices, unsigned int dwFlags); // 0x8C
    void* ComputeSphereVisibility; // 0x90
    void* GetTexture; // 0x94
    long (__stdcall* SetTexture)(D2D3DDeviceStrc* pThis, unsigned int nStage, void* pTexture); // 0x98
};

struct D2D3DDeviceStrc
{
    D2D3DDeviceVtbl* lpVtbl; // 0x00
};

D2_CHECK_SIZE(D2TLVertexStrc, 0x20);
D2_CHECK_SIZE(D2QuadRectStrc, 0x10);
D2_CHECK_SIZE(D2SpriteInfoStrc, 0x30);
D2_CHECK_SIZE(D2VertexBufferVtbl, 0x20);
D2_CHECK_SIZE(D2VertexBufferStrc, 0x4);
D2_CHECK_SIZE(D2D3DTextureVtbl, 0x18);
D2_CHECK_SIZE(D2D3DTextureStrc, 0x4);
D2_CHECK_SIZE(D2D3DDeviceVtbl, 0x9C);
D2_CHECK_SIZE(D2D3DDeviceStrc, 0x4);
