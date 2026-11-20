#include "D2D3DTypes.h"

struct D2SpriteQuad006B61A0Strc
{
    int unk_00[3];
    int nX;
    int nHalf;
    int nWidth;
    int nHeight;
    int unk_1C;
    float fU0;
    float fU1;
    float fV0;
    float fV1;
};

struct D2VertexBuffer006B61A0Strc;
struct D2VertexBufferVtbl006B61A0Strc
{
    void* unk_00[3];
    long (__stdcall* Lock)(D2VertexBuffer006B61A0Strc* pThis, unsigned long dwFlags, void** ppData, unsigned long* pSize);
    long (__stdcall* Unlock)(D2VertexBuffer006B61A0Strc* pThis);
};
struct D2VertexBuffer006B61A0Strc
{
    D2VertexBufferVtbl006B61A0Strc* lpVtbl;
};

struct D2Device006B61A0Strc;
struct D2DeviceVtbl006B61A0Strc
{
    void* unk_00[34];
    long (__stdcall* DrawPrimitiveVB)(D2Device006B61A0Strc* pThis, int nPrimitiveType, D2VertexBuffer006B61A0Strc* pBuffer, unsigned long dwStart, unsigned long dwCount, unsigned long dwFlags);
};
struct D2Device006B61A0Strc
{
    D2DeviceVtbl006B61A0Strc* lpVtbl;
};

struct D2QuadRect006B61A0Strc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
extern D2Device006B61A0Strc* gpDevice_00970E78; // 0x00970E78
D2VertexBuffer006B61A0Strc* gpVertexBuffer_00970F3C;        // 0x00970F3C
static int gnVertexCount_00970F40; // 0x00970F40
int gnScale_00989748;        // 0x00989748

static __declspec(noinline) void __stdcall sub_006B61A0_DrawQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteQuad006B61A0Strc* pQuad);

// 0x006B61A0
static void __stdcall sub_006B61A0_DrawQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteQuad006B61A0Strc* pQuad)
{
    float fU0 = pQuad->fU0;
    float fU1 = pQuad->fU1;
    float fV0 = pQuad->fV0;
    float fV1 = pQuad->fV1;
    int bPerspective = sub_006B9830_GetPerspective();

    D2QuadRect006B61A0Strc tRect;
    tRect.nHeight = pQuad->nHeight >> 1;
    pQuad->nHalf >>= 1;
    tRect.nWidth = pQuad->nWidth;
    tRect.nX = pQuad->nX + pQuad->nHalf;
    tRect.nY = pQuad->nHalf - tRect.nHeight;

    if (bPerspective && gnScale_00989748 != 256)
    {
        tRect.nX = gnScale_00989748 * tRect.nX / 256;
        tRect.nY = gnScale_00989748 * tRect.nY / 256;
        tRect.nWidth = gnScale_00989748 * tRect.nWidth / 256;
        tRect.nHeight = gnScale_00989748 * tRect.nHeight / 256;
    }

    int nX = tRect.nX + nOffsetX;
    int nY = tRect.nY + nOffsetY;
    int nWidth = tRect.nWidth;
    int nHeight = tRect.nHeight;
    float fTop = (float)nY;
    float fBottom = (float)(nY + nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer_00970F3C->lpVtbl->Lock(gpVertexBuffer_00970F3C, 0x21, (void**)&pVertices, 0))
        return;

    pVertices += gnVertexCount_00970F40;
    int nLeft = nX - nHeight;
    pVertices[0].fX = (float)nLeft;
    pVertices[0].fY = fTop;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;
    pVertices[1].fX = (float)nX;
    pVertices[1].fY = fBottom;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;
    pVertices[2].fX = (float)(nX + nWidth);
    pVertices[2].fY = fBottom;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;
    pVertices[3].fX = (float)(nLeft + nWidth);
    pVertices[3].fY = fTop;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;
    pVertices[0].dwColor = (unsigned int)nAlpha << 24;
    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    gpVertexBuffer_00970F3C->lpVtbl->Unlock(gpVertexBuffer_00970F3C);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer_00970F3C, gnVertexCount_00970F40, 4, 0x1C);

    gnVertexCount_00970F40 += 4;
    if (gnVertexCount_00970F40 > 0x2B)
        gnVertexCount_00970F40 = 0;
}

void __fastcall sub_006B61A0_EmitDrawQuad(D2SpriteQuad006B61A0Strc* pQuad, int nX, int nY, unsigned char nAlpha)
{
    sub_006B61A0_DrawQuad(nX, nY, nAlpha, pQuad);
}
