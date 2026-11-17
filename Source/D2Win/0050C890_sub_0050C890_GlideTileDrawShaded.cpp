struct D2GlideTileStrc
{
    short nPosX;
    short nPosY;
    char unk0x04[0x10];
};

struct D2TileLibraryEntryStrc
{
    int nLightDirection;
    char unk0x04[0x4C];
    int nBlocks;
    D2GlideTileStrc* pBlocks;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2GlideSpriteVertexStrc
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4];                                                  // 0x00880600
typedef void (__stdcall* GLIDEDRAWVERTEXARRAYCONTIGUOUS)(int nMode, int nCount, void* pVertices, int nStride);
extern GLIDEDRAWVERTEXARRAYCONTIGUOUS gpfGlideDrawVertexArrayContiguous_0087EAC4;                          // 0x0087EAC4

void __fastcall sub_0050DBE0_GlideSetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity); // 0x0050DBE0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile);                                   // 0x0050FBD0

// 0x0050C890

int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels)
{
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnScreenWidth_007C9138;
    tRect.bottom = gnScreenHeight_007C913C - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    if (nScreenPanels == 1)
    {
        tRect.right += -(gnScreenWidth_007C9138 / 2);
    }
    else if (nScreenPanels == 2)
    {
        tRect.left = gnScreenWidth_007C9138 / 2 - 32;
    }

    nPosY += 32;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        int nLeft = nPosX + pTile->pBlocks[i].nPosX;
        int nBottom = pTile->pBlocks[i].nPosY + nPosY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);
            gaGlideTileQuad_00880600[0].x = (float)nLeft;
            gaGlideTileQuad_00880600[0].y = (float)nTop;
            gaGlideTileQuad_00880600[1].x = (float)nLeft;
            gaGlideTileQuad_00880600[1].y = (float)nBottom;
            gaGlideTileQuad_00880600[2].x = (float)nRight;
            gaGlideTileQuad_00880600[2].y = (float)nBottom;
            gaGlideTileQuad_00880600[3].x = (float)nRight;
            gaGlideTileQuad_00880600[3].y = (float)nTop;
            sub_0050DBE0_GlideSetVertexAmbientColor(gaGlideTileQuad_00880600, nShade);
            gaGlideTileQuad_00880600[1].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gaGlideTileQuad_00880600[2].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gaGlideTileQuad_00880600[3].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideTileQuad_00880600, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return bDrawn;
}
