#include "D2Direct3D.h"

struct D2QuadSpriteStrc
{
    int unk_00[3];
    int nOffsetX;
    int nOffsetY;
    int nWidth;
    int nHeight;
    int unk_1C;
    float f_20;
    float f_24;
    float f_28;
    float f_2C;
};

extern D2GfxPaletteViewStrc* gpGlideState_007C9150; // 0x007C9150
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpVertexBuffer_00970F3C; // 0x00970F3C
int gnVertexIndex_00970F40;        // 0x00970F40
extern int gnScale_00989748; // 0x00989748

void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830

static __declspec(noinline) void __stdcall sub_006B63F0_DrawQuad(D2QuadSpriteStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette);

// 0x006B63F0
void __stdcall sub_006B63F0_DrawQuad(D2QuadSpriteStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette)
{
    sub_006B1EA0_SetState(1);
    sub_006B2030_SetFilterMode(1);

    D2QuadRectStrc tRect;
    tRect.nX = pSprite->nOffsetX;
    float fU0 = pSprite->f_20;
    float fU1 = pSprite->f_24;
    float fV0 = pSprite->f_28;
    float fV1 = pSprite->f_2C;

    int bPerspective = sub_006B9830_GetPerspective();
    tRect.nWidth = pSprite->nWidth;
    tRect.nHeight = pSprite->nHeight;
    tRect.nY = pSprite->nOffsetY - tRect.nHeight;
    if (bPerspective && gnScale_00989748 != 256)
    {
        tRect.nX = gnScale_00989748 * tRect.nX / 256;
        tRect.nY = gnScale_00989748 * tRect.nY / 256;
        tRect.nWidth = gnScale_00989748 * tRect.nWidth / 256;
        tRect.nHeight = gnScale_00989748 * tRect.nHeight / 256;
    }

    int nLeft = tRect.nX + nX;
    float fX0 = (float)nLeft;
    float fX1 = (float)(nLeft + tRect.nWidth);
    int nTop = tRect.nY + nY;
    float fY0 = (float)nTop;
    float fY1 = (float)(nTop + tRect.nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer_00970F3C->lpVtbl->Lock(gpVertexBuffer_00970F3C, 0x21, (void**)&pVertices, 0))
    {
        return;
    }

    pVertices += gnVertexIndex_00970F40;
    if (!nPaletteIndex && !bPalette)
    {
        sub_006B9780_SetColor(pVertices, nColor, nAlpha);
    }
    else
    {
        pVertices->dwColor = (((unsigned int)nAlpha << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3]) << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3 + 1]) << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3 + 2];
    }

    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    pVertices[0].fX = fX0;
    pVertices[0].fY = fY0;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;

    pVertices[1].fX = fX0;
    pVertices[1].fY = fY1;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;

    pVertices[2].fX = fX1;
    pVertices[2].fY = fY1;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;

    pVertices[3].fX = fX1;
    pVertices[3].fY = fY0;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;

    gpVertexBuffer_00970F3C->lpVtbl->Unlock(gpVertexBuffer_00970F3C);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer_00970F3C, gnVertexIndex_00970F40, 4, 0x1C);
    gnVertexIndex_00970F40 += 4;
    if (gnVertexIndex_00970F40 > 43)
    {
        gnVertexIndex_00970F40 = 0;
    }
}

void __fastcall sub_006B63F0_Emit(int nX, int nY, unsigned int nColor, unsigned char nAlpha)
{
    D2QuadSpriteStrc tSprite;
    tSprite.nOffsetX = nX;
    sub_006B63F0_DrawQuad(&tSprite, nX, nY, nColor, 0, nAlpha, 0);
}
