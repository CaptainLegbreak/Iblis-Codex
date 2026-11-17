struct D2TexturedVertexStrc
{
    float nX, nY, nZ, nRhw;
    unsigned int nDiffuse, nSpecular;
    float nU, nV;
};

struct D2D3DDeviceStrc;
struct D2D3DDeviceVtbl
{
    char unk0x00[0x70];
    int (__stdcall* DrawPrimitive)(D2D3DDeviceStrc* pThis, int nType, unsigned int dwFVF, void* pVertices, unsigned int nCount, unsigned int dwFlags);
    char unk0x74[0x98 - 0x74];
    int (__stdcall* SetTexture)(D2D3DDeviceStrc* pThis, unsigned int nStage, void* pTexture);
};
struct D2D3DDeviceStrc { D2D3DDeviceVtbl* pVtbl; };

extern D2D3DDeviceStrc* gpD3DDevice_00970E78;                                                               // 0x00970E78
extern D2TexturedVertexStrc gaVertices_00970F48[4];                                                         // 0x00970F48
extern int gaGlyphWidths_00970FC8[];                                                                        // 0x00970FC8
extern void* gapGlyphTextures_009712D0[];                                                                   // 0x009712D0

__declspec(noinline) static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar);

// 0x006B7530
static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar)
{
    if (nX > 640)
    {
        return 0;
    }

    if (nX < 0)
    {
        return gaGlyphWidths_00970FC8[nChar];
    }

    if ((unsigned char)(nChar - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaVertices_00970F48[0].nX = (float)nX;
        gaVertices_00970F48[0].nY = (float)nY;
        gaVertices_00970F48[1].nX = (float)nX;
        gaVertices_00970F48[1].nY = (float)nBottom;
        gaVertices_00970F48[2].nX = (float)nRight;
        gaVertices_00970F48[2].nY = (float)nBottom;
        gaVertices_00970F48[3].nX = (float)nRight;
        gaVertices_00970F48[3].nY = (float)nY;

        nChar -= 0x20;
        gpD3DDevice_00970E78->pVtbl->SetTexture(gpD3DDevice_00970E78, 0, gapGlyphTextures_009712D0[nChar]);
        gpD3DDevice_00970E78->pVtbl->DrawPrimitive(gpD3DDevice_00970E78, 6, 0x1C4, gaVertices_00970F48, 4, 0x1C);
        return gaGlyphWidths_00970FC8[nChar];
    }

    return gaGlyphWidths_00970FC8[0];
}

int __fastcall sub_Emit_006B7530(const char* szText, int nX, int nY)
{
    int nWidth = 0;
    while (*szText)
    {
        nWidth += sub_006B7530_DrawGlyph(nX + nWidth, nY, *szText++);
    }
    return nWidth;
}
