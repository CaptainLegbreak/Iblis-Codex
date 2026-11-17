struct D2ClipRectStrc { int left,top,right,bottom; };
struct D2TilePartStrc { short x,y; char unknown004[16]; };
struct D2TileContextStrc { char unknown000[0x50]; int count; D2TilePartStrc* parts; };
struct D2QuadVertexStrc { float x,y,z,rhw; unsigned int color,specular; float s,t; };
struct D2DrawDeviceStrc;
struct D2DrawVtableStrc { void* unknown000[28]; int (__stdcall* DrawPrimitive)(D2DrawDeviceStrc*,int,unsigned int,void*,unsigned int,unsigned int); };
struct D2DrawDeviceStrc { D2DrawVtableStrc* vtable; };
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern D2QuadVertexStrc gaQuadVertices[4]; // 0x00971630
extern D2DrawDeviceStrc* gpDrawDevice; // 0x00970E78
void __fastcall sub_006BBA00_BindTilePart(D2TilePartStrc*); // 0x006BBA00
void __fastcall sub_006B9730_SetQuadColor(D2QuadVertexStrc*,unsigned char,int); // 0x006B9730
// 0x006B8220
int __fastcall sub_006B8220_DrawTileParts(D2TileContextStrc* pTile, int nX, int nY, int nLight, int nColorMode, int nViewMode)
{
    D2ClipRectStrc tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnScreenWidth_007C9138;
    tRect.bottom = gnScreenHeight_007C913C - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    switch (nViewMode)
    {
    case 1:
        tRect.right -= gnScreenWidth_007C9138 / 2;
        break;
    case 2:
        tRect.left += gnScreenWidth_007C9138 / 2;
        break;
    }

    nY += 32;
    for (int i = 0; i < pTile->count; ++i)
    {
        int nLeft = pTile->parts[i].x + nX;
        int nBottom = pTile->parts[i].y + nY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            sub_006BBA00_BindTilePart(&pTile->parts[i]);
            gaQuadVertices[0].x = (float)nLeft;
            gaQuadVertices[0].y = (float)nTop;
            gaQuadVertices[1].x = (float)nLeft;
            gaQuadVertices[1].y = (float)nBottom;
            gaQuadVertices[2].x = (float)nRight;
            gaQuadVertices[2].y = (float)nBottom;
            gaQuadVertices[3].x = (float)nRight;
            gaQuadVertices[3].y = (float)nTop;
            sub_006B9730_SetQuadColor(gaQuadVertices, (unsigned char)nLight, nColorMode);
            gaQuadVertices[1].color = gaQuadVertices[0].color;
            gaQuadVertices[2].color = gaQuadVertices[0].color;
            gaQuadVertices[3].color = gaQuadVertices[0].color;
            gpDrawDevice->vtable->DrawPrimitive(gpDrawDevice, 6, 0x1C4, gaQuadVertices, 4, 0x1C);
        }
    }

    return bDrawn;
}
